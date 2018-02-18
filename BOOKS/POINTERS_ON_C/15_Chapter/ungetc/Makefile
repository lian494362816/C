TARGET=test
CC=gcc
CFLAGS = -Wall -O -g  

SOURCES = $(wildcard *.c )  
OBJS = $(patsubst %.c,%.o,$(SOURCES))
INCLUDE_PATH= -I ./
INCLUDE=  my_type.h\
		  list.h\
		  my_error.h\
		  my_func.h

all:$(TARGET)

$(TARGET):$(OBJS)  
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(INCLUDE) $^ -o $@

%.o:%c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(INCLUDE)  -c $< -o $@

clean:  
	rm -rf *.o $(TARGET) *.h.gch
