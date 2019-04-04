/* 
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr.edu
* Lab Section: 024
* Assignment: Lab #2 Exercise #Challenge
* Exercise Description: [optional - include for your own benefit]
* An amusement park kid ride cart has three seats, with 8-bit weight sensors connected to ports A, B, and C (measuring from 0-255 kilograms). Set PD0 to 1 if the cart's total passenger weight exceeds the maximum of 140 kg. Also, the cart must be balanced: Set port PD1 to 1 if the difference between A and C exceeds 80 kg. Can you also devise a way to inform the ride operator of the approximate weight using the remaining bits on D?
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRB = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char totalWeight = 0x00;
	unsigned char DiffAandC = 0x00;

    /* Replace with your application code */
    while (1) 
    {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		
		if(tmpA + tmpB + tmpC > 140)
		{
			totalWeight = 0x01;
		}
		else
		{
			totalWeight = 0x00;
		}
		
		if(tmpA > tmpC)
		{
			if(tmpA-tmpC > 80)
			{
				DiffAandC = 0x02;
			}
			else
			{
				DiffAandC = 0x00;
			}
		}
		else
		{
			if(tmpC-tmpA > 80)
			{
				DiffAandC = 0x02;
			}
			else
			{
				DiffAandC = 0x00;
			}
		}
		
		if(totalWeight == 0x01)
		{
			PORTD = PORTD | 0x01;
		}
		else
		{
			PORTD = PORTD & 0xFE;
		}
		
		if(DiffAandC == 0x02)
		{
			PORTD = PORTD | 0x02;
		}
		else
		{
			PORTD = PORTD & 0xFD;
		}
    }
}

