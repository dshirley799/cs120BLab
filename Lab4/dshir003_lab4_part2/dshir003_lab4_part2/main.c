/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #4 Exercise #2
* Exercise Description: [optional - include for your own benefit]
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

#define A0 (PINA&0x01)
#define A1 ((PINA&0x02) >> 1)

enum States { Start, Increment, IncrementWait, Decrement, DecrementWait, Reset} state;

unsigned char tmpC;

void sm(){
	switch(state)
	{
		case Start:
			if(A0 && A1)
			{
				state = Reset;
			}
			else if(A0)
			{
				state = Increment;
			}
			else if(A1)
			{
				state = Decrement;
			}
			else
			{
				state = Start;
			}
			break;
			
		case Increment:
			if(A0 && A1)
			{
				state = Reset;
			}
			else if(A0)
			{
				state = IncrementWait;
			}
			else if(!A0)
			{
				state = Start;
			}
			break;
			
		case IncrementWait:
			if(A0 && A1)
			{
				state = Reset;
			}
			else if(A0)
			{
				state = IncrementWait;
			}
			else if(!A0)
			{
				state = Start;
			}
			break;
			
		case Decrement:
			if(A0 && A1)
			{
				state = Reset;
			}
			else if(A1)
			{
				state = DecrementWait;
			}
			else if(!A1)
			{
				state = Start;
			}
			break;
			
		case DecrementWait:
			if(A0 && A1)
			{
				state = Reset;
			}
			else if(A1)
			{
				state = DecrementWait;
			}
			else if(!A1)
			{
				state = Start;
			}
			break;
			
		case Reset:
			if(!(A0 && A1))
			{
				state = Start;
			}
			else
			{
				state = Reset;
			}
			break;
			
		default:
			state = Start;
			break;
	}
	
	switch(state)
	{
		case Start:
			//intentionally left blank
			break;
			
		case Increment:
			if(tmpC<9)
			{
				tmpC = tmpC+1;
			}
			break;
			
		case IncrementWait:
			//intentionally left blank
			break;
			
		case Decrement:
			if(tmpC>0)
			{
				tmpC = tmpC-1;
			}
			break;
			
		case DecrementWait:
			//intentionally left blank
			break;
			
		case Reset:
			tmpC = 0x00;
			break;
			
	}
	PORTC = tmpC;
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	
	state = Start;
	tmpC = 0x07;
	
    /* Replace with your application code */
    while (1) 
    {
		sm(tmpC);
    }
}

