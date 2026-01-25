#include<LPC21XX.H>
#include "lcd_header.h"
unsigned char display_text[]="EMBEDDED SYSTEM ";
void LCD_NameScroll(unsigned char *);
void scroll_right(unsigned char *);
void scroll_left(unsigned char *);
int main()
{
	LCD_INIT();
	while(1){
		LCD_NameScroll(display_text);
		scroll_left(display_text);
		delay_ms(20);
		/*scroll_right(display_text);
		delay_ms(100);*/
	}
}
void LCD_NameScroll(unsigned char *s)
{
	LCD_COMMAND(0x80);
	while(*s)
	{
		LCD_DATA(*s++);
	}
}
void scroll_right(unsigned char *arr)
{
	int i;
	char last = arr[15];
	for(i=15;i>0;i--)
	arr[i]=arr[i-1];
	arr[0] = last; 
}
void scroll_left(unsigned char *arr)
{
	int i;
	char first = arr[0];
	for(i=0;i<15;i++)
	arr[i]=arr[i+1];
	arr[15] = first;
}

