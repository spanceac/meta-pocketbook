# Yocto build for Pocketbook Basic 3

Currently the only tested hw is `Pocketbook Basic 3`. This model was produced in 2017 and it seems discontinued now.
Not even mentioned anymore on producer's website, even though older models are still mentioned.

Given that the build uses the `Pocketbook Touch Lux 3` kernel device tree, it's very likely that this device works too with the build.
... and probably other Allwinner A13 SoC based models(https://linux-sunxi.org/PocketBook)

Build is based on Kirkstone branch of meta-sunxi, poky, meta-openembedded.
Board runs mainline Linux kernel v6.1.

## Clone repo and build

```
git clone https://github.com/spanceac/meta-pocketbook.git
cd meta-pocketbook
git submodule init
git submodule update
source poky/oe-init-build-env
bitbake-layers add-layer ../meta-openembedded/meta-oe
bitbake-layers add-layer ../meta-openembedded/meta-python/
bitbake-layers add-layer ../meta-sunxi/
MACHINE=pocketbook-basic3-a13 bitbake core-image-base
```

## Flash the image on SD card

```
sudo dd if=deploy/images/pocketbook-basic3-a13/core-image-base-pocketbook-basic3-a13.sunxi-sdimg of=/dev/sda bs=1M oflag=sync
```

Board is set to boot from internal SD card slot.

## Status

### What doesn't work:
- e-ink display :sad

### What works:
- Wi-Fi (RTL8188EUS)
- internal SD card slot
- external SD card slot
- USB host mode through microUSB connector(with USB OTG cable)
- buttons
- serial console

## Misc stuff
Serial UART header is easy to find on the left side of the PCB with clearly marked pins(TX, RX, GND).

Extra info about hw, kernel and u-boot forks for using with this device: https://linux-sunxi.org/PocketBook_Touch_Lux_3

