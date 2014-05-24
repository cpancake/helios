#include "util.h"

// http://inportb.com/inportb/

unsigned char kutil_inportb(unsigned short port) 
{
	unsigned char ret;
	asm volatile ("inb %%dx,%%al":"=a"(ret):"d"(port));
	return ret;
}

void kutil_outportb(unsigned short port, unsigned char value) 
{
	asm volatile ("outb %%al,%%dx": :"d"(port),"a"(value));
}

// AND I HOPE THIS IS THE ONLY INLINE ASSEMBLY I'LL EVER HAVE TO USE HERE