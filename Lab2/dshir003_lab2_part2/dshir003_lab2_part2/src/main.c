/* 
* Partner 1 Name & E-mail: Daniel Shirley dshir003@ucr.edu
* Partner 2 Name & E-mail: Ivan Lorna ilorn001@ucr..edu
* Lab Section: 024
* Assignment: Lab #2 Exercise #2
* Exercise Description: [optional - include for your own benefit]
*Port A's pins 3 to 0, each connect to a parking space sensor, 1 meaning a car is parked in the space, of a four-space parking lot. Write a program that outputs in binary on port C the number of available spaces (Hint: declare a variable "unsigned char cntavail"; you can assign a number to a port as follows:
* PORTC = cntavail;).
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	while(1)
	{
		// 1) Read input
		tmpA = PINA & 0x01;
		tmpB = (PINA & 0x02)>>1; //shifts put the wanted bits in least significant bit
		tmpC = (PINA & 0x04)>>2;
		tmpD = (PINA & 0x08)>>3;
		// 2) Perform computation
		cntavail = 0x04 - (tmpA + tmpB + tmpC + tmpD); //subtracts the number of spots taken from those available
		// 3) Write output
		PORTC = cntavail;
	}
	return 0;
}
