# Use cross compiler if provided, otherwise use native gcc
CC := $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS := -Wall -Werror

# Default target
all: writer

# Build writer
writer: writer.o
	$(CC) $(CFLAGS) writer.o -o writer

# Compile writer.c into writer.o
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c -o writer.o

# Clean build artifacts
clean:
	rm -f writer writer.o

.PHONY: all clean

