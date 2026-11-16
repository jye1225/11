CC = gcc
CFLAGS = -std=c17 -g -Wall -Wextra
TARGETS = test01.exe test02.exe test03.exe test04.exe test05.exe

.PHONY: all clean
all: $(TARGETS)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)
