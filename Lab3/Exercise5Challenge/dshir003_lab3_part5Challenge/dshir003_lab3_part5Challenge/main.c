/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #5Challenge
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;
	
	unsigned short weight = 0x00;
	unsigned char tmpB = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		tmpB = 0x00;
		
		weight = (PIND & 0x00FF) << 1;
		weight = weight | (PINB & 0x0001);
		
		if(weight >= 70)
		{
			tmpB = tmpB | 0x02;
		}
		else if(weight > 5)
		{
			tmpB = tmpB | 0x04;
		}
		
		PORTB = tmpB;
    }
}

