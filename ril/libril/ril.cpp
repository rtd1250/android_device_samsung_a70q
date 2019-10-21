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

#include <hidl/HidlTransportSupport.h>
#include <hwbinder/ProcessState.h>

// Set hwbinder buffer size to 512KB
#define HW_BINDER_MMAP_SIZE 524288

extern "C" void
initWithMmapSize() {
    android::hardware::ProcessState::initWithMmapSize((size_t)(HW_BINDER_MMAP_SIZE));
}

extern "C" void
configure_thread_pool() {
    android::hardware::configureRpcThreadpool(1, true);
}
