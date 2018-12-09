SOC_FAMILY ??= ""
include conf/machine/include/soc-family.inc

# Sub-architecture support
MACHINE_SOCARCH_SUFFIX ?= ""
MACHINE_SOCARCH_SUFFIX_sun4i = "-sun4i"

PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"
XSERVER = "xserver-xorg \
           xf86-video-fbturbo \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-input-keyboard"

UBOOT_LOCALVERSION = "-g${@d.getVar('SRCPV', True).partition('+')[2][0:7]}"

UBOOT_ENTRYPOINT ?= "0x40008000"

SERIAL_CONSOLE ?= "115200 ttyS0"
MACHINE_FEATURES ?= "alsa apm keyboard rtc serial screen usbgadget usbhost vfat"
