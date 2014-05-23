OBJS=main.o boot.o
OUT=kernel.bin

all: objects kernel
	rm -rf *.o
	mv kernel.bin ../disk/files/boot

objects: $(OBJS)

%.o: %.asm
	nasm -felf $< -o $@

%.o: %.c
	i386-elf-g++ -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -c $<

kernel: 
	i386-elf-ld -T link.ld -o kernel.bin $(OBJS)

clean: 
	rm -rf $(OBJS)
	rm -rf ../disk/files/boot/kernel.bin

iso:
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 --boot-info-table -V HELIOS -quiet -o ../disk/helios.iso ../disk/files