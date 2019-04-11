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

#define A (PINA)
#define L ((PINA&0x80)>>7)

enum States {Locked, Check, Pass, Unlocked} state;

unsigned char tmpA;
unsigned char tmpB;
unsigned char i;

const unsigned char code[] = {4, 1, 2, 1};

void sm(){
	switch(state)
	{
		case Locked:
			if(A > 0) 
			{ 
				state = Check; 
			}
			else 
			{ 
				state = Locked; 
			}
			if(A>127)
			{
				state = Locked;
			}
			break;
		
		case Check:
			if(i == 4)
			{
				if(tmpB == 0x00)
				{
					state = Unlocked;
				}
				else
				{
					state = Locked;
				}
			}
			else if(A!=0)
			{
				if(code[i] == A)
				{
					state = Pass;
				}
				else
				{
					if(tmpB == 0x00)
					{
						state = Locked;
					}
					else
					{
						state = Unlocked;
					}
				}
			}
			else
			{
				state = Check;
			}
			if(A>127)
			{
				state = Locked;
			}
			break;
		
		case Pass:
			if(A!=0)
			{
				state = Pass;
			}
			else
			{
				state = Check;
				i = i + 1;
			}
			if(A>127)
			{
				state = Locked;
			}
			break;
		
		case Unlocked:
			if(!A)
			{
				state = Check;
			}
			else
			{
				state = Unlocked;
			}
			if(A>127)
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
			i = 0;
			break;
		case Check:
			//intentionally left blank
			break;
		case Pass:
			//intentionally left blank
			break;
		case Unlocked:
			tmpB = 1;
			i = 0;
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
	i = 0;
	
	/* Replace with your application code */
	while (1)
	{
		sm();
	}
}

