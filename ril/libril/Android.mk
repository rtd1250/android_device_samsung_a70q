LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_VENDOR_MODULE := true

LOCAL_SRC_FILES := \
    ril.cpp

LOCAL_SHARED_LIBRARIES := \
    libutils \
    libhidlbase  \
    libhidltransport \
    libhwbinder

LOCAL_C_INCLUDES := hardware/ril/include
LOCAL_EXPORT_C_INCLUDE_DIRS := hardware/ril/include

LOCAL_MODULE := libril_a70q

include $(BUILD_SHARED_LIBRARY)
