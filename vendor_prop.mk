# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    af.fast_track_multiplier=1 \
    audio.deep_buffer.media=true \
    audio.offload.buffer.size.kb=32 \
    audio.offload.gapless.enabled=true \
    av.offload.enable=true \
    vendor.audio.offload.buffer.size.kb=32 \
    vendor.audio.offload.gapless.enabled=true \
    vendor.audio_hal.in_period_size=144 \
    vendor.audio_hal.period_multiplier=4 \
    vendor.audio_hal.period_size=192 \
    ro.qc.sdk.audio.ssr=false \
    ro.vendor.audio.sdk.ssr=false \
    tunnel.audio.encode=true \
    qcom.hw.aac.encoder=true \
    ro.config.vc_call_vol_steps=7 \
    vendor.audio.feature.compr_voip.enable=true \
    vendor.audio.feature.deepbuffer_as_primary.enable=true \
    vendor.audio.feature.fm.enable=true \
    vendor.audio.feature.incall_music.enable=true \
    vendor.audio.feature.multi_voice_session.enable=true \
    vendor.audio.feature.usb_offload.enable=true \
    vendor.dedicated.device.for.voip=true \
    use.dedicated.device.for.voip=true

# AudioFlinger client heap size
PRODUCT_PROPERTY_OVERRIDES += \
    ro.af.client_heap_size_kbyte=7168

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
    ro.bluetooth.library_name=libbluetooth_qti.so

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
    camera.aux.packagelist=com.android.camera \
    camera.disable_zsl_mode=1 \
    vendor.camera.aux.packagelist=com.android.camera

# Charger
PRODUCT_PROPERTY_OVERRIDES += \
    ro.charger.enable_suspend=true

# Chipset
PRODUCT_PROPERTY_OVERRIDES += \
    ro.soc.manufacturer=Qualcomm \
    ro.soc.model=SM6150

# Crypto
 PRODUCT_PROPERTY_OVERRIDES += \
    ro.crypto.allow_encrypt_override=true \
    ro.crypto.volume.filenames_mode=aes-256-cts

# Dalvik VM
PRODUCT_PROPERTY_OVERRIDES += \
    dalvik.vm.heapstartsize=8m \
    dalvik.vm.heapmaxfree=8m \
    dalvik.vm.heapminfree=2m \
    dalvik.vm.heapsize=512m \
    dalvik.vm.heaptargetutilization=0.75 \
    ro.dalvik.vm.native.bridge=0

# Display
PRODUCT_PROPERTY_OVERRIDES += \
    persist.sys.sf.color_saturation=1.0 \
    debug.sf.hw=1 \
    debug.egl.hw=0 \
    debug.hwui.renderer=skiavk \
    debug.sf.early_phase_offset_ns=100000 \
    debug.sf.early_app_phase_offset_ns=100000 \
    debug.sf.early_gl_phase_offset_ns=100000 \
    debug.sf.early_gl_app_phase_offset_ns=100000 \
    debug.sf.high_fps_early_phase_offset_ns=100000 \
    debug.sf.high_fps_early_gl_phase_offset_ns=100000 \
    debug.sf.high_fps_late_app_phase_offset_ns=100000 \
    debug.sf.high_fps_late_sf_phase_offset_ns=100000 \
    debug.sf.latch_unsignaled=1 \
    debug.mdpcomp.logs=1 \
    ro.vendor.display.cabl=2 \
    vendor.gralloc.disable_ubwc=0 \
    vendor.display.disable_scaler=0 \
    vendor.display.disable_inline_rotator=1 \
    vendor.display.disable_decimation=1 \
    vendor.display.disable_excl_rect_partial_fb=1 \
    vendor.display.disable_ext_anim=1 \
    vendor.display.enable_null_display=0 \
    vendor.display.disable_excl_rect=0 \
    vendor.display.comp_mask=0 \
    vendor.display.enable_default_color_mode=1 \
    vendor.display.dataspace_saturation_matrix=1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0 \
    vendor.display.idle_time=0 \
    vendor.display.idle_time_inactive=0 \
    vendor.display.disable_dynamic_fps=1 \
    ro.sf.lcd_density=420 \
    ro.opengles.version=196610 \
    ro.hardware.vulkan=adreno \
    ro.hardware.egl=adreno \
    ro.gfx.driver.1=com.qualcomm.qti.gpudrivers.sm6150.api30

# DRM
PRODUCT_PROPERTY_OVERRIDES += \
    drm.service.enabled=true

# Enable stm-events
PRODUCT_PROPERTY_OVERRIDES += \
    persist.debug.coresight.config=stm-events

# fastbootd
PRODUCT_PROPERTY_OVERRIDES += \
    ro.fastbootd.available=true

# FM
PRODUCT_PROPERTY_OVERRIDES += \
    vendor.hw.fm.init=0

# Factory Reset Protection
PRODUCT_PROPERTY_OVERRIDES += \
    ro.frp.pst=/dev/block/persistent

# Fluence/Audio Proccessing
PRODUCT_PROPERTY_OVERRIDES += \
    persist.audio.fluence.speaker=true \
    persist.audio.fluence.voicecall=true \
    persist.audio.fluence.voicerec=false \
    persist.vendor.audio.fluence.speaker=true \
    persist.vendor.audio.fluence.voicecall=true \
    persist.vendor.audio.fluence.voicerec=false \
    ro.qc.sdk.audio.fluencetype=none \
    ro.vendor.audio.sdk.fluencetype=none

# Gatekeeper
PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.gatekeeper=mdfpp

# GPS/GNSS
PRODUCT_PROPERTY_OVERRIDES += \
    sys.qca1530=detect

# IO CGroup
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.iocgrp.config=1

# Keymaster
PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.keystore=mdfpp

# Light
PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.lights=qcom

# Media
PRODUCT_PROPERTY_OVERRIDES += \
    audio.offload.video=true

# Misc
PRODUCT_PROPERTY_OVERRIDES += \
    sys.vendor.shutdown.waittime=500 # ro.kernel.qemu.gles=0

# NFC
PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.nfc_nci=nqx.default

# Perf Stack
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.extension_library=libqti-perfd-client.so \
    vendor.perf.gestureflingboost.enable=true

# Qualcomm System Daemon
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.qcomsysd.enabled=1

# Radio/RIL
 PRODUCT_PROPERTY_OVERRIDES += \
    vendor.voice.path.for.pcm.voip=true \
    persist.vendor.radio.atfwd.start=true \
    persist.vendor.radio.apm_sim_not_pwdn=1 \
    persist.vendor.radio.custom_ecc=1 \
    persist.vendor.radio.data_con_rprt=1 \
    persist.vendor.radio.sib16_support=1 \
    persist.radio.multisim.config=dsds \
    vendor.sec.rild.libpath=/vendor/lib64/libsec-ril.so \
    vendor.sec.rild.libpath2=/vendor/lib64/libsec-ril-dsds.so \
    ro.vendor.sec.radio.def_network=9 \
    ro.telephony.default_network=9,9 \
    telephony.lteOnCdmaDevice=1 \
    keyguard.no_require_sim=true \
    persist.vendor.data.mode=concurrent \
    ro.vendor.use_data_netmgrd=false
