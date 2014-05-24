OBJS=memory.o string.o
CC=i386-elf-g++
LD=i386-elf-ld
AR=i386-elf-ar

all: libhstd.a

libhstd.a: $(OBJS)
	$(AR) rcs libhstd.a $(OBJS)

%.o: %.c
	$(CC) -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fpermissive -fno-rtti -c $<

clean:
	rm -rf *.o