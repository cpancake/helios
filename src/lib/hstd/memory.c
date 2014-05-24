#include "memory.h"

/*
memcpy
Copy count bytes from src to dest, and return dest.
*/
EXPORT unsigned char *memcpy(unsigned const char *src, unsigned char *dest, int count)
{
	unsigned const char *src_pointer = (unsigned const char *)src;
	unsigned char *dest_pointer = (unsigned char *)dest;
	for(;count>0;count--)
		*dest_pointer++ = *src_pointer++;
	return dest;
}

/*
memset
Set count bytes in dest to val, and return dest.
*/
EXPORT unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
	unsigned char *dest_pointer = (unsigned char *)dest;
	for(;count>0;count--)
		*dest_pointer++ = val;
	return dest;
}

/*
memsetw
Set count bytes in dest to val, and return dest (but 16 bit this time).
*/
EXPORT unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
	unsigned short *dest_pointer = (unsigned short *)dest;
	for(;count>0;count--)
		*dest_pointer++ = val;
	return dest;
}