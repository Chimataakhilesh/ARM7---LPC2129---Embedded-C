#include<LPC21XX.H>
#include "lcd_header.h"

void LCD_STRING(unsigned char *);
int main(){
	LCD_INIT();
	LCD_COMMAND(0x80);
	LCD_STRING("CHIMATA AKHILESH");
}
void LCD_STRING(unsigned char *s)
{
	char i=0;
	while(*s){
		LCD_DATA(*s++);
		i++;
		if(i==16)
		LCD_COMMAND(0xc0);

}
}
