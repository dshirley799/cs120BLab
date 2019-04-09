/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #5Challenge
* Exercise Description: [optional - include for your own benefit]
* (Challenge): A car's passenger-seat weight sensor outputs a 9-bit value (ranging from 0 to 511) and connects to input PD7..PD0PB0 on the microcontroller. If the weight is equal to or above 70 pounds, the airbag should be enabled by setting PB1 to 1. If the weight is above 5 but below 70, the airbag should be disabled and an "Airbag disabled" icon should light by setting PB2 to 1. (Neither B1 nor B2 should be set if the weight is 5 or less, as there is no passenger).
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

