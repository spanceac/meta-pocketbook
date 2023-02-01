FILESEXTRAPATHS:prepend:sunxi := "${THISDIR}/files:"

SRC_URI:append:pocketbook-basic3-a13 = " \
	file://Enable-MMC2-for-Pocketbook-Basic3.patch \
	file://0001-Enable-Pocketbook-power-LED.patch \
	file://pocketbook-boot.cmd \
"

do_compile:prepend:pocketbook-basic3-a13() {
    mv ${WORKDIR}/pocketbook-boot.cmd ${WORKDIR}/boot.cmd
}

