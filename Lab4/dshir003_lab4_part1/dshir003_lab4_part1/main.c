/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #4 Exercise #1
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

#define A0 PINA&0x01;

enum States{Start, On, PressedOff, Off, PressedOn} state;
unsigned char tmpB;

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
	state = Start;
	tmpB = 0x00;
	
    while (1) 
    {
		sm();
    }
}

void sm() {
	switch(state)//transitions
	{
		case On:
			if(A0)
			{
				state = PressedOff;
			}
			break;
		case PressedOff:
			if(!A0)
			{
				state = Off;
			}
			break;
		case Off:
			if(A0)
			{				
				state = PressedOn;
			}
			break;
		case PressedOn:
			if(!A0)
			{
				state = On;
			}
			break;
		default:
			state = On;
			break;
	}
	
	switch(state)//Actions
	{
		case On:
			tmpB = 0x01;
			break;
		case PressedOff:
			tmpB = 0x02;
			break;
		case Off:
			tmpB = 0x02;
			break;
		case PressedOn:
			tmpB = 0x01;
			break;
	}
	
	PORTB = tmpB;
}