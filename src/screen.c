#include "screen.h"
#include "util.h"
#include "lib/hstd/memory.h"
#include "lib/hstd/string.h"

#define VIDEO_MEM 0xb8000

int cursor_x = 0, cursor_y = 0;

/*
kscrn_move_cursor
Move the hardware cursor to x, y.
*/
void kscrn_move_cursor(int x, int y)
{
	int position = x + y * 80;

	/*
	Since this is protected mode, we can't use a BIOS interrupt to move the cursor.
	Instead, we tell the VGA controller directly.
	*/
	kutil_outportb(0x3d4, 14);
	kutil_outportb(0x3d5, position >> 8);
	kutil_outportb(0x3d4, 15);
	kutil_outportb(0x3d5, position);

	cursor_x = x;
	cursor_y = y;
}

/*
kscrn_scroll
Move the window up a line if cursor_y > 25
*/
void kscrn_scroll()
{
	short unsigned int blank = 0x20 | (0x07 << 8);
	if(cursor_y < 25) return;
	unsigned char *video = (unsigned char*)VIDEO_MEM;
	// same as 25 - (cursor_y - 25 + 1) * 80 * 2
	int bottom = cursor_y - 24;
	int count = (25 - bottom) * 80 * 2;
	memcpy(video + bottom * 80, video, count);
	memset(video + (25 - bottom) * 80, blank, 80);
	cursor_y = 24;
	kscrn_move_cursor(cursor_x, cursor_y);
}

/*
kscrn_write_char
Write a character to the screen at the cursor.
*/
void kscrn_write_char(char c)
{
	if(c == 0x08) // backspace
	{
		// decrease cursor_x by one; if end of line, go to previous line; if first line, don't do anything
		if(cursor_x == 0 && cursor_y != 0)
		{
			cursor_x = 79;
			cursor_y--;
		}
		else if(cursor_x > 0)
			cursor_x--;
	}
	else if(c == 0x09) // tab
		cursor_x = (cursor_x + 4) & ~(4 - 1); // increase to a multiple of four i.e. the next tab stop
	else if(c == '\r') // carriage return
		cursor_x = 0; // go to the start of the line
	else if(c == '\n') // newline
	{
		cursor_x = 0; // go to the start of the line (\r)
		cursor_y++; // go to the next lien
	}
	else if(c >= 0x20) // space or higher; valid character
	{
		unsigned short *video = (unsigned short*)VIDEO_MEM;
		// navigate to cursor position
		video += cursor_x + cursor_y * 80;
		*video++ = c | 0x07 << 8;
		cursor_x++;
	}

	if(cursor_x >= 80) // go to the next line if we've written past this one
	{
		cursor_x = 0;
		cursor_y++;
	}
	kscrn_move_cursor(cursor_x, cursor_y);
	kscrn_scroll();
}

/*
kscrn_clear_screen
Wipe everything displayed on the screen.
*/
void kscrn_clear_screen()
{
	unsigned short *video = (unsigned short *)VIDEO_MEM;
	// set the video memory to blank
	memsetw(video, 0x00, 80 * 25);
	kscrn_move_cursor(0, 0);
}

/*
kscrn_write_string
Write a string to the screen.
*/
void kscrn_write_string(const char *str)
{
	for(int i=0;i<strlen(str);i++)
		kscrn_write_char(str[i]);
}