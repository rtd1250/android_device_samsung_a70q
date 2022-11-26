/*
 * Copyright (c) 2022 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.hardware.display;

import android.app.Service;
import android.content.Intent;
import android.hardware.display.ColorDisplayManager;
import android.os.SystemProperties;
import android.os.IBinder;
import android.util.Log;
import android.os.Handler;

public class SamsungUdfpsHandlerService extends Service {
    private static final String TAG = "SamsungUdfpsHandler";
    private static final boolean DEBUG = false;

    private int mNightDisplayTemp = 0;
    private boolean mExtraDimActive = false;

    private ColorDisplayManager mColorDisplayManager;
    private Handler mHandler;
    private static Runnable mRunnable;

    private void disable() {
        if (DEBUG) Log.d(TAG, "Finger down, set NightDisplay and ExtraDim off");

        mNightDisplayTemp = mColorDisplayManager.getNightDisplayColorTemperature();

        if (mColorDisplayManager.isNightDisplayActivated()) {
            // 6500 Kelvin is AOSP's default white balance value
            mColorDisplayManager.setNightDisplayColorTemperature(6500);
        }

        if (mColorDisplayManager.isReduceBrightColorsActivated()) {
            mExtraDimActive = true;
            mColorDisplayManager.setReduceBrightColorsActivated(false);
        }

        SystemProperties.set("vendor.finger.down", "0");
    }

    private void enable() {
        if (DEBUG) Log.d(TAG, "Finger up, reset NightDisplay and ExtraDim to previous state");

        SystemProperties.set("vendor.finger.down", "-1");

        mColorDisplayManager.setNightDisplayColorTemperature(mNightDisplayTemp);
        mColorDisplayManager.setReduceBrightColorsActivated(mExtraDimActive);

        mExtraDimActive = false;
    }

    @Override
    public void onCreate() {
        if (DEBUG) Log.d(TAG, "SamsungUdfpsHandler Started");
        mColorDisplayManager = getSystemService(ColorDisplayManager.class);

        SystemProperties.set("vendor.finger.down", "-1");

        mHandler = new Handler();
        mRunnable = new Runnable() {
            public void run() {
                if (DEBUG) Log.d(TAG, "onCreate: " + TAG + " is running");

                if (SystemProperties.get("vendor.finger.down").equals("1")) {
                    disable();
                    try {
                        Thread.sleep(2000);
                    }
                    catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                } else if (SystemProperties.get("vendor.finger.down").equals("0")) {
                    enable();
                }
                mHandler.postDelayed(mRunnable, 100);
            }
        };

        mHandler.postDelayed(mRunnable, 0);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (DEBUG) Log.d(TAG, "Starting service");
        return START_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
