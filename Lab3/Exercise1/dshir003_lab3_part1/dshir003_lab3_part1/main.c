/*
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #3 Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	
	unsigned char count;
	
    while (1) 
    {
		count = 0x00;
		//Get inputs
		tmpA = PINA;
		tmpB = PINB;
		
		//computations made here
		while(tmpA > 0)
		{
			if(tmpA%2 == 1)	count++;
			tmpA = tmpA/2;
		}
		
		while(tmpB > 0)
		{
			if(tmpB%2 == 1) count++;
			tmpB = tmpB/2;
		}
		
		tmpC = count;
		
		//Set outputs
		PORTC = tmpC;
    }
}

