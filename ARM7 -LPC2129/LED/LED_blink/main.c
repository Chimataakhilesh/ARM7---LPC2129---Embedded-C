#include<LPC21XX.H>

void delay_seconds(unsigned int seconds);
void delay_ms(unsigned int ms);
void delay_us(unsigned int us);
int main(){
int k;
 PINSEL0 = 0;
IODIR0 = 0X080FF;
while(1){
for(k=1;k<256;k=k*2+1){
IOSET0 = k;
delay_ms(100);
IOCLR0 = k;
delay_ms(100);
}
for(k=256;k>=1;k=k/2){
IOSET0 = k-1;
delay_ms(100);
IOCLR0 = k-1;
delay_ms(100);
}
}
}

