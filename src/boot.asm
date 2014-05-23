;
; Kernel's entry point. 
; This is what GRUB calls when it hands control to the OS
;
[BITS 32]
global start
start:
    mov esp, _sys_stack ; Set the stack pointer to point to the top of our stack.
    jmp stublet

; The multiboot header. GRUB looks for this before it boots the OS.
ALIGN 4
mboot:
    MULTIBOOT_PAGE_ALIGN	equ 1<<0
    MULTIBOOT_MEMORY_INFO	equ 1<<1
    MULTIBOOT_HEADER_MAGIC	equ 0x1BADB002
    MULTIBOOT_HEADER_FLAGS	equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
    MULTIBOOT_CHECKSUM	equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_FLAGS
    dd MULTIBOOT_CHECKSUM
    
; Call the kernel, then enter an infinite loop.
stublet:
 	extern kernel
 	call kernel
	jmp $

SECTION .bss
    resb 8192
_sys_stack: