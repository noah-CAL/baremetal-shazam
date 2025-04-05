CC = gcc
CFLAGS = -g -ggdb

SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text
DEPENDS := $(patsubst %.c,%.h,$(SOURCES))

EXE := main

all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS)

%.o: %.c %.h Makefile
	$(CC) -c $< $(CFLAGS)

.PHONY: all clean
clean:
	rm -rf $(OBJECTS) $(EXE) *.wav
