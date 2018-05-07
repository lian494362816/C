
obj-m:=test.o

KERNEL_DIR=/home/black/disk/A9/Kernel/linux-3.5
MAKE=arm-linux-gcc

default:
	make -C ${KERNEL_DIR} M=`pwd` modules

clean:
	make -C ${KERNEL_DIR} M=`pwd` modules clean
