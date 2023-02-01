SUMMARY = "Realtek out-of-tree kernel driver for rtl8182eus"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://include/autoconf.h;startline=1;endline=14;md5=d1415c223f48d77507154f01e7fa002f"

inherit module

SRC_URI = "git://github.com/aircrack-ng/rtl8188eus;branch=v5.3.9;protocol=https \
	   file://0001-Fix-Makefile-for-Pocketbook-build.patch \
	   file://0001-Add-modules_install-rule.patch \
	   file://fix-build-v6.1.patch \
"

SRCREV = "f8ead579311f7eb800e769a7fd216d0c5cb0c4a3"

S = "${WORKDIR}/git"

EXTRA_OEMAKE += " \
    KSRC=${STAGING_KERNEL_DIR} \
"

KERNEL_MODULE_AUTOLOAD:pocketbook-basic3-a13 += "$PN"
