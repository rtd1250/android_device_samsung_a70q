# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    ro.config.vc_call_vol_steps=7 \
    audio.offload.gapless.enabled=true

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.btstack.enable.splita2dp=true \
    persist.vendor.btstack.a2dp_offload_cap=sbc-aptx-aptxtws-aptxhd-aac-ldac

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
   vendor.camera.aux.packagelist="org.codeaurora.snapcam,com.android.camera"

# CNE and DPM
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.cne.feature=1

# Display post-processing
PRODUCT_PROPERTY_OVERRIDES += \
    ro.qualcomm.cabl=0 \
    ro.vendor.display.cabl=0 \
    ro.vendor.display.ad=1

# FM Radio/BT
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
    vendor.bluetooth.soc=cherokee

# Fluence/Audio Proccessing
PRODUCT_PROPERTY_OVERRIDES += \
   ro.qc.sdk.audio.fluencetype=fluence \
   persist.audio.fluence.voicecall=true \
   persist.audio.fluence.voicerec=false \
   persist.audio.fluence.speaker=true

# Graphics
PRODUCT_PROPERTY_OVERRIDES += \
    sdm.debug.disable_inline_rotator=1 \
    sdm.debug.disable_inline_rotator_secure=1

# Media
PRODUCT_PROPERTY_OVERRIDES += \
    persist.mm.enable.prefetch=true

# Memory optimizations
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.qti.sys.fw.bservice_enable=true

# Netflix custom property
PRODUCT_PROPERTY_OVERRIDES += \
    ro.netflix.bsp_rev=Q6150-17263-1

# Netmgr
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.data.mode=concurrent \
    ro.vendor.use_data_netmgrd=false

# Perf
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.qti.core_ctl_min_cpu=2 \
    ro.vendor.qti.core_ctl_max_cpu=4 \
    vendor.iop.enable_prefetch_ofr=0 \
    vendor.iop.enable_uxe=1 \
    vendor.perf.gestureflingboost.enable=true \
    vendor.perf.workloadclassifier.enable=true

# IMS
PRODUCT_PROPERTY_OVERRIDES += \
    persist.dbg.volte_avail_ovr=1 \
    persist.dbg.vt_avail_ovr=1  \
    persist.dbg.wfc_avail_ovr=1

# RIL
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.radio.bar_fake_gcell=1 \
    persist.vendor.radio.data_con_rprt=1 \
    persist.vendor.radio.data_ltd_sys_ind=1 \
    persist.vendor.radio.force_on_dc=true \
    persist.vendor.radio.ignore_dom_time=10 \
    ro.telephony.default_network=22,22 \
    persist.vendor.radio.data_con_rprt=1

# SSR
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.ssr.enable_ramdumps=0 \
    persist.vendor.ssr.restart_level=ALL_ENABLE

# Time
PRODUCT_PROPERTY_OVERRIDES += \
    persist.timed.enable=true
