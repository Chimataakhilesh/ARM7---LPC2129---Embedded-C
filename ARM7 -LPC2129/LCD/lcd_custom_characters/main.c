#include<LPC21XX.H>
#include "lcd_header.h"

unsigned char cgram_lut[] = {0x17,0x14,0x14,0x1F,0x05,0x05,0x1D,0x00,0x11,0x15,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
void cgram_write(void);
int main()
{
	LCD_INIT();
	cgram_write();
	LCD_COMMAND(0x80);
	LCD_DATA(0);
	LCD_DATA(1);
}
void cgram_write(void)
{
	char i=0;
	LCD_COMMAND(0x40);
	for(i=0;i<16;i++)
	LCD_DATA(cgram_lut[i]);
}

