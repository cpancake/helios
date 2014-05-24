#ifndef KERN_SCREEN_H
#define KERN_SCREEN_H

void kscrn_clear_screen();
void kscrn_write_string(const char *str);
void kscrn_write_char(char c, int x, int y, int page);
void kscrn_scroll();
void kscrn_move_cursor(int x, int y);

#endif