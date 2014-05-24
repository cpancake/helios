#ifndef HSTD_MEMORY_H
#define HSTD_MEMORY_H

#include "export.h"

EXPORT unsigned char *memcpy(unsigned const char *src, unsigned char *dest, int count);
EXPORT unsigned char *memset(unsigned char *dest, unsigned char val, int count);
EXPORT unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

#endif