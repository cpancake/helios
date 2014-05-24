#include "string.h"

/*
strlen
Measure length of str.
*/
EXPORT int strlen(const char *str)
{
	int i = 0;
	while(str[i] != 0) i++;
	return i;
}

/*
strrev
Return a reversed representation of the string.
http://www8.cs.umu.se/~isak/snippets/strrev.c
*/
EXPORT const char *strrev(const char *str)
{
	unsigned char *p1, *p2;

	if (! str || ! *str)
		return str;
	for (p1 = (unsigned char*)str, p2 = (unsigned char*)str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

// Internally used for the next two functions
void strtobase(int num, unsigned char *output, int base)
{
	const char *digits = "0123456789ABCDEF";
	if(num < 0)
	{
		*output++ = '-';
		num *= -1;
	}
	do {
		// get each digit in the base we want it in - note that num % base returns the last digit, 
		// which is why we have to reverse the string.
		*output++ = digits[num % base];
		num = num / base;
	} while(num > 0);
	output += '\0';
}


/*
stribase
Return a string from the given integer in the given base (up to base 16) to output.
*/
EXPORT void stribase(int num, unsigned char *output, int base)
{
	strtobase(num, output, base);
	output = strrev((const char *)output);
}

/*
stri
Return a string from the given integer to output.
*/
EXPORT void stri(int num, unsigned char *output)
{
	strtobase(num, output, 10);
	output = strrev((const char *)output);
}