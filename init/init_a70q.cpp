/*
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (C) 2017-2019, The LineageOS Project
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_a70q.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_quad(char const system_prop[], char const vendor_prop[], char const product_prop[], char const odm_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
    property_override(product_prop, value);
    property_override(odm_prop, value);
}

void vendor_load_properties()
{
    const std::string bootloader = android::base::GetProperty("ro.bootloader", "");

    std::string bl_model;
    std::string bl_build;
    
    if (bootloader.length() == 13) {
        bl_model = bootloader.substr(0, 5);
        bl_build = bootloader.substr(5);
    } else if (bootloader.length() == 14) {
        bl_model = bootloader.substr(0, 6);
        bl_build = bootloader.substr(6);
    } else {
        LOG(ERROR) << "Could not detect model, defaulting to A705FN";
        bl_model = "A705FN";
        bl_build = "XXU5DWB4";
    }
    
    std::string model;
    std::string device;
    std::string name;

    model = "SM-" + bl_model;

    for (size_t i = 0; i < VARIANT_MAX; i++) {
        std::string model_ = all_variants[i]->model;
        if (model.compare(model_) == 0) {
            device = all_variants[i]->codename;
            break;
        }
    }
    if (device.size() == 0) {
        LOG(ERROR) << "Could not detect device, forcing a70q";
        device = "a70q";
    }

    name = device + "xx";

    LOG(INFO) << "Found bootloader:";
    LOG(INFO) << bootloader.c_str();
    LOG(INFO) << "Setting ro.product.model:";
    LOG(INFO) << model.c_str();
    LOG(INFO) << "Setting ro.product.device:";
    LOG(INFO) << device.c_str();
    LOG(INFO) << "Setting ro.product.name:";
    LOG(INFO) << name.c_str();
    LOG(INFO) << "Setting ro.build.product:";
    LOG(INFO) << device.c_str();

    property_override_quad("ro.product.model", "ro.product.vendor.model", "ro.product.product.model", "ro.product.odm.model", model.c_str());
    property_override_quad("ro.product.device", "ro.product.vendor.device", "ro.product.product.device", "ro.product.odm.device", device.c_str());
    property_override_quad("ro.product.name", "ro.product.vendor.name", "ro.product.product.name", "ro.product.odm.name", name.c_str());
    property_override("ro.build.product", device.c_str());
}
