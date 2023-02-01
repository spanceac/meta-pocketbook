setenv fdtfile sun5i-a13-pocketbook-touch-lux-3.dtb
load mmc 1:1 $kernel_addr_r uImage
load mmc 1:1 $fdt_addr_r $fdtfile
setenv bootargs root=/dev/mmcblk0p2 rw rootwait
bootm $kernel_addr_r - $fdt_addr_r
