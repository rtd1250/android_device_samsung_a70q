/*
 * Copyright (C) 2019 The LineageOS Project
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

#define LOG_TAG "vendor.samsung.hardware.biometrics.fingerprint@2.1-service.a70q"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include <utils/Errors.h>

#include "BiometricsFingerprint.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using vendor::samsung::hardware::biometrics::fingerprint::V2_1::ISecBiometricsFingerprint;
using vendor::samsung::hardware::biometrics::fingerprint::V2_1::implementation::SecBiometricsFingerprint;

using android::OK;
using android::sp;

int main() {
    android::sp<ISecBiometricsFingerprint> bio = SecBiometricsFingerprint::getInstance();

    configureRpcThreadpool(1, true);

    if (bio == nullptr || bio->registerAsService() != OK) {
        LOG(ERROR) << "Could not register service for Fingerprint HAL";
        goto shutdown;
    }

    LOG(INFO) << "Fingerprint HAL service is Ready.";
    joinRpcThreadpool();

shutdown:
    // In normal operation, we don't expect the thread pool to shutdown
    LOG(ERROR) << "Fingerprint HAL failed to join thread pool.";
    return 1;
}
