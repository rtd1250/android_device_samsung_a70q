/*
 * Copyright (C) 2015 The CyanogenMod Project
 *               2017-2019 The LineageOS Project
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

package org.lineageos.settings.doze;

import android.content.Context;
import android.content.Intent;
import android.hardware.display.AmbientDisplayConfiguration;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.UserHandle;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.NullPointerException;
import java.lang.SecurityException;
import java.util.List;

public final class Utils {

    private static final String TAG = "DozeUtils";
    private static final boolean DEBUG = false;

    private static final String DOZE_INTENT = "com.android.systemui.doze.pulse";

    static final String ALWAYS_ON_DISPLAY = "always_on_display";
    static final String GESTURE_PICK_UP_KEY = "gesture_pick_up";

    private static final String TSP_CMD_PATH = "/sys/class/sec/tsp/cmd";

    static void startService(Context context) {
        if (DEBUG) Log.d(TAG, "Starting service");
        context.startServiceAsUser(new Intent(context, DozeService.class),
                UserHandle.CURRENT);
    }

    static void stopService(Context context) {
        if (DEBUG) Log.d(TAG, "Stopping service");
        context.stopServiceAsUser(new Intent(context, DozeService.class),
                UserHandle.CURRENT);
    }

    static void checkDozeService(Context context) {
        if (isDozeEnabled(context) && (isAlwaysOnEnabled(context))) {
            startService(context);
        } else {
            stopService(context);
        }
    }

    static boolean isDozeEnabled(Context context) {
        return new AmbientDisplayConfiguration(context)
                .pulseOnNotificationEnabled(UserHandle.USER_CURRENT);
    }

    static boolean enableAlwaysOn(Context context, boolean enable) {
        return Settings.Secure.putIntForUser(context.getContentResolver(),
                Settings.Secure.DOZE_ALWAYS_ON, enable ? 1 : 0, UserHandle.USER_CURRENT);
    }

    static boolean isAlwaysOnEnabled(Context context) {
        return new AmbientDisplayConfiguration(context)
                .alwaysOnEnabled(UserHandle.USER_CURRENT);
    }

    private static boolean writeLine(String fileName, String value) {
        BufferedWriter writer = null;

        try {
            writer = new BufferedWriter(new FileWriter(fileName));
            writer.write(value);
        } catch (FileNotFoundException e) {
            Log.w(TAG, "No such file " + fileName + " for writing", e);
            return false;
        } catch (IOException e) {
            Log.e(TAG, "Could not write to file " + fileName, e);
            return false;
        } finally {
            try {
                if (writer != null) {
                    writer.close();
                }
            } catch (IOException e) {
                // Ignored, not much we can do anyway
            }
        }

        return true;
    }

    static void enableAOD(boolean enable) {
        if (enable) {
            writeLine(TSP_CMD_PATH, "aod_enable,1");
            writeLine(TSP_CMD_PATH, "set_aod_rect,872,849,78,579");
        } else {
            writeLine(TSP_CMD_PATH, "set_aod_rect,0,0,0,0");
            writeLine(TSP_CMD_PATH, "aod_enable,0");
        }
    }
}
