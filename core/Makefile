CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -static
LDLIBS = -lssl -lcrypto    

TARGET = build/revis
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

all: prepare $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

prepare:
	mkdir -p build

.PHONY: all clean prepare