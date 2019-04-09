/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #3
* Exercise Description: [optional - include for your own benefit]
* A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full). A series of LEDs connected to PC5..PC0 should light to graphically indicate the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4, PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or less.  (The example below shows the display for a fuel level of 3).
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>


int main(void)
{
	
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char seatBeltCheck = 0x00;
	unsigned char tmpC = 0x00;
	
	/* Replace with your application code */
	while (1)
	{
		//Get Inputs
		tmpA = PINA & 0x0F;
		seatBeltCheck = (PINA & 0x70) >> 4;
		tmpC = 0x00;
		
		//Computations for variables
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
		
		if(seatBeltCheck == 3) tmpC = tmpC | 0x80;
		
		//Set Ouptuts
		PORTC = tmpC;
	}
}

