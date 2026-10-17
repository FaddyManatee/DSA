# Variables.
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = list
OBJS = main.o list.o

# Default rule (build the final executable).
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files.
main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# Delete the compiled files.
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
