OBJS=util.o screen.o main.o boot.o
LIBS=libhstd.a
CC=i386-elf-g++
LD=i386-elf-ld
OUT=kernel.bin
CC=i386-elf-g++
LD=i386-elf-ld

all: objects libs kernel
	rm -rf *.o
	mv kernel.bin ../disk/files/boot

objects: $(OBJS)

libs:
	cd lib/hstd && make && mv libhstd.a ../../

%.o: %.asm
	nasm -felf $< -o $@

%.o: %.c
	$(CC) -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fpermissive -fno-rtti -c $<

kernel: 
	$(LD) -T link.ld -o kernel.bin $(OBJS) $(LIBS)

clean: 
	rm -rf $(OBJS)
	rm -rf $(LIBS)
	rm -rf ../disk/files/boot/kernel.bin

iso:
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -V HELIOS -quiet -o ../disk/helios.iso ../disk/files
