## Configure to nsh or usbnsh

Use the following command
$ make distclean
$ ./tools/configure.sh -l stm32f407-robomaster-dev-a:nsh (or usbnsh)
$ make -j12 (where replace 12 with the number of cores you have)

To flash
$ dfu-util -a 0 --dfuse-address 0x08000000 -D nuttx.bin