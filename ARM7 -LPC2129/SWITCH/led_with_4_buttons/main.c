#include <LPC21XX.H>
int main() {
	unsigned int Switch; 	
  IODIR0 = 0x0F000;
    while (1) {
        Switch = ((IOPIN0 >> 5) & (15));
        switch (Switch){
          case 0x0E: IOCLR0 = 0x01000; break;
          case 0x0D: IOCLR0 = 0x02000; break;
          case 0x0B: IOCLR0 = 0x04000; break;
          case 0x07: IOCLR0 = 0x08000; break;
          default: IOSET0 = 0x0F000;
					break;
        }
    }
}


