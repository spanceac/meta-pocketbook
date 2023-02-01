SECTION = "kernel"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"
COMPATIBLE_MACHINE = "(sun4i|sun5i|sun7i|sun8i|sun50i)"

inherit kernel

require linux.inc

FILESEXTRAPATHS:prepend:sunxi := "${THISDIR}/files:"

# Since we're not using git, this doesn't make a difference, but we need to fill
# in something or kernel-yocto.bbclass will fail.
KBRANCH ?= "master"

DEPENDS += "rsync-native"

# Pull in the devicetree files into the rootfs
RDEPENDS_${KERNEL_PACKAGE_NAME}-base += "kernel-devicetree"

KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

SRC_URI:pocketbook-basic3-a13 = "https://www.kernel.org/pub/linux/kernel/v6.x/linux-${PV}.tar.xz \
	file://usb_otg_as_host.patch \
"

do_configure:prepend:pocketbook-basic3-a13() {
	kernel_conf_variable WIRELESS y
	kernel_conf_variable WLAN y
	kernel_conf_variable CFG80211 m
	kernel_conf_variable USB_STORAGE m
	kernel_conf_variable RFKILL m
}

S = "${WORKDIR}/linux-${PV}"

FILES_${KERNEL_PACKAGE_NAME}-base:append = " ${nonarch_base_libdir}/modules/${KERNEL_VERSION}/modules.builtin.modinfo"
