[AID_VENDOR_QTI_DIAG]
value:2901

[AID_VENDOR_QDSS]
value:2902

[AID_VENDOR_RFS]
value:2903

[AID_VENDOR_RFS_SHARED]
value:2904

[AID_VENDOR_ADPL_ODL]
value:2905

[AID_VENDOR_QRTR]
value:2906

[AID_VENDOR_SECDIR]
value:5050

[AID_VENDOR_LOD]
value:5202

[AID_VENDOR_KNOXCORE]
value:5250

[AID_VENDOR_SPASS]
value:5278

[AID_VENDOR_REMOTEDISPLAY]
value:5386

[AID_VENDOR_AUDIT]
value:5555

[AID_VENDOR_SYSTEM_RESERVED_STORAGE]
value:5678

[vendor/bin/wcnss_filter]
mode: 0755
user: AID_BLUETOOTH
group: AID_BLUETOOTH
caps: BLOCK_SUSPEND

[system/vendor/bin/wcnss_filter]
mode: 0755
user: AID_BLUETOOTH
group: AID_BLUETOOTH
caps: BLOCK_SUSPEND

[vendor/bin/hw/android.hardware.bluetooth@1.0-service-qti]
mode: 0755
user: AID_BLUETOOTH
group: AID_BLUETOOTH
caps: BLOCK_SUSPEND NET_ADMIN

[system/vendor/bin/hw/android.hardware.bluetooth@1.0-service-qti]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: BLOCK_SUSPEND NET_ADMIN

[system/bin/cnss-daemon]
mode: 0755
user: AID_BLUETOOTH
group: AID_BLUETOOTH
caps: NET_BIND_SERVICE

[vendor/bin/pm-service]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/vendor/bin/pm-service]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/bin/pm-service]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[vendor/bin/pd-mapper]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/vendor/bin/pd-mapper]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/bin/pd-mapper]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[vendor/bin/imsdatadaemon]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[system/vendor/bin/imsdatadaemon]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[vendor/bin/ims_rtp_daemon]
mode: 0755
user: AID_SYSTEM
group: AID_RADIO
caps: NET_BIND_SERVICE

[system/vendor/bin/ims_rtp_daemon]
mode: 0755
user: AID_SYSTEM
group: AID_RADIO
caps: NET_BIND_SERVICE

[vendor/bin/imsrcsd]
mode: 0755
user: AID_SYSTEM
group: AID_RADIO
caps: NET_BIND_SERVICE BLOCK_SUSPEND WAKE_ALARM

[system/vendor/bin/imsrcsd]
mode: 0755
user: AID_SYSTEM
group: AID_RADIO
caps: NET_BIND_SERVICE BLOCK_SUSPEND WAKE_ALARM

[vendor/bin/cnd]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE BLOCK_SUSPEND NET_ADMIN

[system/vendor/bin/cnd]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE BLOCK_SUSPEND NET_ADMIN

[vendor/bin/slim_daemon]
mode: 0755
user:  AID_GPS
group: AID_GPS
caps: NET_BIND_SERVICE

[system/vendor/bin/slim_daemon]
mode: 0755
user:  AID_GPS
group: AID_GPS
caps: NET_BIND_SERVICE

[vendor/bin/loc_launcher]
mode: 0755
user:  AID_GPS
group: AID_GPS
caps: SETUID SETGID

[system/vendor/bin/loc_launcher]
mode: 0755
user:  AID_GPS
group: AID_GPS
caps: SETUID SETGID

[vendor/bin/xtwifi-client]
mode: 0755
user:  AID_GPS
group: AID_GPS
caps: NET_BIND_SERVICE BLOCK_SUSPEND WAKE_ALARM

[vendor/bin/sensors.qti]
mode: 0755
user: AID_SYSTEM
group: AID_SYSTEM
caps: NET_BIND_SERVICE

[firmware/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[firmware/image/*]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[vendor/firmware_mnt/image/*]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[bt_firmware/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[persist/]
mode: 0771
user: AID_SYSTEM
group: AID_SYSTEM
caps: 0

[dsp/]
mode: 0771
user: AID_MEDIA
group: AID_MEDIA
caps: 0
