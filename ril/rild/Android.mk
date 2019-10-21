# Copyright 2006 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	rild.c

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libdl \
	liblog \
	libril_a70q \
	libril

# Temporary hack for broken vendor RILs.
LOCAL_WHOLE_STATIC_LIBRARIES := \
	librilutils

LOCAL_CFLAGS := -DRIL_SHLIB
LOCAL_CFLAGS += -Wall -Wextra -Werror

LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE:= rild

include $(BUILD_EXECUTABLE)
