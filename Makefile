# Shazam algorithm in "baremetal" C!
#
# Copyright (C) 2025 Noah Sedlik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
CC = gcc
CFLAGS = -g -ggdb

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text
DEPENDS := $(patsubst %.c,%.h,$(SOURCES))

EXE := main.out

all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS)

%.o: %.c %.h Makefile
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all clean
clean:
	rm -rf $(OBJECTS) $(EXE) *.wav
