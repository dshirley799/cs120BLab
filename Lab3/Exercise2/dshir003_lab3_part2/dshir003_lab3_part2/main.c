/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #2
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
	/* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		tmpA = PINA & 0x0F;
		tmpC = 0x00;
		
		switch(tmpA)
		{
			case 0:
				tmpC = tmpC | 0x40;
				break;
			case 1:
			case 2:
				tmpC = tmpC | 0x20;
				tmpC = tmpC | 0x40;
				break;
			case 3:
			case 4:
				tmpC = tmpC | 0x30;
				tmpC = tmpC | 0x40;
				break;
			case 5:
			case 6:
				tmpC = tmpC | 0x38;
				break;
			case 7:
			case 8:
			case 9:
				tmpC = tmpC | 0x3C;
				break;
			case 10:
			case 11:
			case 12:
				tmpC = tmpC | 0x3E;
				break;
			case 13:
			case 14:
			case 15:
				tmpC = tmpC | 0x3F;
				break;
		}
    }
}

