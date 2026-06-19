CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m3 -mthumb -O2 -Wall
LDFLAGS=

all: main.elf

main.elf: main.c comms.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f main.elf
