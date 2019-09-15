
TOP_DIR:=$(shell pwd)
TARGET:=$(TOP_DIR)/bin/test
LIB_PATH:=$(TOP_DIR)/lib
MODULES:=$(shell find $(TOP_DIR)/module -type d)
LIBS:=$(shell ls $(LIB_PATH))
LINK_FILE:=$(TOP_DIR)/module/test.lds

INCLUDE_PATH += \
				-I$(TOP_DIR)/include \

OBJS:=$(shell find . -type f)
OBJS:=$(filter %.c %.s %S, $(OBJS))
OBJS:=$(patsubst %.c, %.o, $(OBJS))
OBJS:=$(patsubst %.s, %.o, $(OBJS))
OBJS:=$(patsubst %.S, %.o, $(OBJS))

CROSS_COMPILE=arm-linux-
CFLAGS = -Werror $(INCLUDE_PATH) -fno-builtin
RM= rm -f

hdr:=IH_ARCH_ARM

export CROSS_COMPILE LIB_PATH CFLAGS MODULES RM

all: build 

build:
	@make -C module all
	$(CROSS_COMPILE)ld  -T $(LINK_FILE) $(OBJS) -o $(TARGET).elf
	# $(CROSS_COMPILE)ld  -T $(LINK_FILE) $(OBJS) -L$(LIB_PATH) -lc -lm -o $(TARGET).elf
	$(CROSS_COMPILE)objcopy -O binary $(TARGET).elf $(TARGET).bin
	$(CROSS_COMPILE)objdump -D $(TARGET).elf > $(TARGET).dis

clean:
	@make -C module clean
	$(RM) $(TARGET).elf  $(TARGET).bin $(TARGET).dis

.PHONY:  all clean build
