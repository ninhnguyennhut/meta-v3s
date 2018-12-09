DESCRIPTION = "Linux Kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

INC_PR = "r0"

inherit kernel siteinfo

# Enable OABI compat for people stuck with obsolete userspace
#ARM_KEEP_OABI ?= "0"

# Set the verbosity of kernel messages during runtime
# You can define CMDLINE_DEBUG in your local.conf or distro.conf to override this behaviour
#CMDLINE_DEBUG ?= "loglevel=3"

# Kernel bootlogo is distro-specific (default is OE logo).
# Logo resolution (qvga, vga, ...) is machine-specific.
#LOGO_SIZE ?= '${@base_conditional("MACHINE_GUI_CLASS", "bigscreen", "vga", "qvga", d)}'
# To use this, add file://${LOGO_SIZE}/logo_linux_clut224.ppm.bz2 or similar
# to your kernel recipe, and then structure your logos for each resolution
# accordingly.

LOCALVERSION ?= ""

do_configure(){
	oe_runmake v3s_defconfig -C ${S} O=${B}
}
do_compile(){
	oe_runmake zImage
}

PACKAGES =+ "kernel-headers"
FILES_kernel-headers = "${exec_prefix}/src/linux*"
