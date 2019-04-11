/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #4 Exercise #3
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

#define X (PINA&0x01)
#define Y ((PINA&0x02)>>1)
#define P ((PINA&0x04)>>2)
#define L ((PINA&0x80)>>7)

enum States {Locked, PoundPressed, PoundReleased, Unlocked} state;
	
unsigned char tmpB;

void sm(){
	switch(state)
	{
		case Locked:
			if(P && !X && !Y && !L)
			{
				state = PoundPressed;
			}
			else
			{
				state = Locked;
			}
			if(L)
			{
				state = Locked;
			}
			break;
			
		case PoundPressed:
			if(P && !X && !Y && !L)
			{
				state = PoundPressed;
			}
			else if((X || Y || L))
			{
				state = Locked;
			}
			else
			{
				state = PoundReleased;
			}
			if(L)
			{
				state = Locked;
			}
			break;
			
		case PoundReleased:
			if(!P && !X && Y && !L)
			{
				state = Unlocked;
			}
			else if((X || P || L))
			{
				state = Locked;
			}
			else
			{
				state = PoundReleased;
			}
			if(L)
			{
				state = Locked;
			}
			break;
			
		case Unlocked:
			if(L)
			{
				state = Locked;
			}
			break;
			
		default:
			state = Locked;
			break;
	}
	
	switch(state)
	{
		case Locked:
			tmpB = 0;
			break;
		case PoundPressed:
			//intentionally left blank
			break;
		case PoundReleased:
			//intentionally left blank
			break;
		case Unlocked:
			tmpB = 1;
			break;
	}
	
	PORTC = state;
	PORTB = tmpB;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	state = Locked;
	tmpB = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		sm();
    }
}

