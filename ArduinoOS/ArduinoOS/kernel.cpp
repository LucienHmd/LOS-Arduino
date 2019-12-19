/*
 * ArduinoOS.cpp
 *
 * Created: 12/16/2019 3:15:57 AM
 * Author : Luke Lukeson
 */ 


#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 16000000L // Specify oscillator frequency
#include <stdio.h>
#include <util/delay.h>


#define DDRB = 0b10000000; // configure pin 7 of PORTB as output (digital pin 13 on the Arduino Mega2560)
volatile unsigned long ticks = 0;
volatile unsigned long x = 0;


ISR(TIMER4_OVF_vect, ISR_BLOCK)
{
	ticks++;
	
	
}

unsigned long OSticks()
{
	return ticks;
}


void runOS()
{
	printf("w");
	x = OSticks();
	if (x > 10000) {
		cli();
		PORTB = 0b10000000; // set 7th bit to HIGH
		_delay_ms(1000);
		PORTB = 0b00000000; // set 7th bit to LOW
		_delay_ms(1000);
		x = 0;
		sei();
	}
}