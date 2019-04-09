/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #4 Challenge
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpAFirstHalf = 0x00;
	unsigned char tmpASecondHalf = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		tmpAFirstHalf = (PINA & 0x0F) << 4;
		tmpASecondHalf = (PINA & 0xF0) >> 4;
		
		tmpB = tmpASecondHalf;
		tmpC = tmpAFirstHalf;
		
		PORTB = tmpB;
		PORTC = tmpC;
    }
}

