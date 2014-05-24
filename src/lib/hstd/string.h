#ifndef HSTD_STRING_H
#define HSTD_STRING_H

#include "export.h"

EXPORT int strlen(const char *str);
EXPORT const char *strrev(const char *str);
EXPORT void stribase(int num, unsigned char *output, int base);
EXPORT void stri(int num, unsigned char *output);

#endif