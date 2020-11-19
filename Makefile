TARGET=syshear
AUXC=read_intr
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -pedantic

all: $(TARGET).c $(AUXC).c
	$(CC) $(CFLAGS) -o $(AUXC) $(AUXC).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run: $(TARGET) $(AUXC)
	./$(AUXC) | grep intr | cut -d' ' -f2-37 | ./$(TARGET) | aplay

clean:
	rm -f $(TARGET) $(AUXC)

.PHONY: clean all
