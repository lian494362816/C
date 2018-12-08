
C_FILES:=$(wildcard *.c) 
S_FILES:=$(wildcard *.s) 
S_FILES+=$(wildcard *.S) 
OBJS:= $(patsubst %.S, %.o, $(S_FILES))
OBJS+= $(patsubst %.s, %.o, $(S_FILES))
OBJS+= $(patsubst %.c, %.o, $(C_FILES))
DEP_FILES:= $(patsubst %, .%.d, $(OBJS))
DEP_FILES:= $(wildcard $(DEP_FILES))

all:$(OBJS)
	
%.o:%.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

%.o:%.s
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $@ $<

%.o:%.S
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $@ $<


clean:
	$(RM) $(OBJS) $(DEP_FILES)

.PHONY: clean all
