#设置库的名字
LIB_NAME ?= test

PWD := $(shell pwd)
BUILD_PATH:=$(PWD)/C_File

STATIC_NAME ?= lib$(LIB_NAME).a
SHARE_NAME  ?= lib$(LIB_NAME).so

#生成库的路径
TARGET_PATH := $(PWD)/lib
STATIC_TARGET := $(TARGET_PATH)/$(STATIC_NAME)
SHARE_TARGET := $(TARGET_PATH)/$(SHARE_NAME)

SOURCE :=$(wildcard $(BUILD_PATH)/*.c)
OBJS := $(patsubst %.c, %.o, $(SOURCE))

#设置编译器
CC:=gcc

all:$(STATIC_TARGET) $(SHARE_TARGET)
	@echo "OBJS=$(OBJS)"
	@echo "SOURCE=$(SOURCE)"

#生成静态库
$(STATIC_TARGET):$(OBJS)
	ar -rc $(STATIC_TARGET) $(OBJS)

#生成动态库
$(SHARE_TARGET):$(OBJS)
	$(CC) -shared -fPIC -o $(SHARE_TARGET) $(SOURCE)

#生成二进制文件(*.o)
# $(OBJS): $(SOURCE)
	# $(CC) -c $< -o $@

%.o:%.c
	$(CC) -c $< -o $@



clean:
	rm -rf $(BUILD_PATH)/*.o $(TARGET_PATH)/*

.PHONY: all clean

