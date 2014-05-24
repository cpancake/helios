#include "screen.h"
#include "lib/hstd/string.h"

extern "C" 
int kernel()
{
	kscrn_clear_screen();
	kscrn_write_string("239 in hex: ");
	unsigned char buf[5];
	stribase(239, buf, 16);
	kscrn_write_string((const char *)buf);
	kscrn_write_string("\n239 in decimal: ");
	unsigned char buf2[5];
	stri(239, buf2);
	kscrn_write_string((const char *)buf2);
	return 0;
}