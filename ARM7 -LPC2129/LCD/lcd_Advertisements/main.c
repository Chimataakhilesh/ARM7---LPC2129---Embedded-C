#include<LPC21XX.H>
#include "lcd_header.h"
unsigned char cgram_lut[]={0x1F,0x11,0x11,0x1F,0x0E,0x1F,0x00,0x00};
char *msg ="ALL SERVICES AVAILABLE PH - 0930930850";
void LCD_NameScroll(unsigned char *);
void cgram_write(void);
int main()
{
	int i,j;
	LCD_INIT();
	cgram_write();
	LCD_COMMAND(0x80);
	LCD_NameScroll("ABC COMPUTERS ");
	LCD_DATA(0);
	LCD_COMMAND(0xC0);
	LCD_NameScroll("ALL SERVICES AVAILABLE PH - 0930930850          ");
	while(1) {
        for(i = 0; msg[i] != '\0'; i++) {
            LCD_COMMAND(0xC0); // Move to start of 2nd line
            
            // Print a 16-character window starting from index 'i'
            for(j = 0; j < 16; j++) {
                if(msg[i + j] != '\0'){
                    LCD_DATA(msg[i + j]);
								}
                else{
                    LCD_DATA(' ');
								}
						}
            
            delay_ms(200); // Control scroll speed
            
            // If the loop reaches the end of the message, reset
            if(i >= 38) i = 0; 
        }
			}
}
void LCD_NameScroll(unsigned char *M)
{
	while(*M)
	{
		LCD_DATA(*M++);
	}
}
void cgram_write(void)
{
	char i=0;
	LCD_COMMAND(0x40);
	for(i=0;i<8;i++)
	LCD_DATA(cgram_lut[i]);
}

