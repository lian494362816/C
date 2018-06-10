
TARGET=test
OBJS+= test.o basedevice.o rtc.o string.o
CROSS_COMPILE=arm-linux-
CCFLAG= -fno-builtin
LINK_SCRIPT=test.lds

${TARGET}.bin:${TARGET}
	${CROSS_COMPILE}objcopy -O binary $^ $@

${TARGET}:${OBJS}
	${CROSS_COMPILE}ld -T${LINK_SCRIPT} $^ -o $@

%.o:%.c
	${CROSS_COMPILE}cc -c $^ -o $@ ${CCFLAG}

clean:
	rm -f ${TARGET} ${OBJS} ${TARGET}.bin


# all:
	# arm-linux-gcc -c test.c -o test.o -fno-builtin
	# arm-linux-gcc -c basedevice.c -o basedevic.o -fno-builtin
	# arm-linux-gcc -c string.c -o string.o -fno-builtin
	# arm-linux-gcc -c rtc.c -o rtc.o -fno-builtin
	# arm-linux-ld -Ttest.lds *.o -o test
	# arm-linux-objcopy -O binary test test.bin
# clean:
	# rm test *.bin *.o 
