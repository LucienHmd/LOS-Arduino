

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "kernel.cpp"

#define F_CPU 16000000L // Specify oscillator frequency




int main(void)
{
	initInterrupts();
	PORTB = 0b10000000;
	
	while (1)
	{
		
		runOS();
		
		/*
		// 1 pulse
		PORTB |= (1 << PORTB7); // PORTB7 hi = LED L on
		_delay_ms(10000); // 0.5 sec
		PORTB &= ~(1 << PORTB7); // PORTB7 hi = LED L off
		_delay_ms(10000); // 2 sec
		
		if(x == 1) {
			PORTB |= (1 << PORTB7); // PORTB7 hi = LED L on
			_delay_ms(10000);
		} else {
			PORTB |= ~(1 << PORTB7); // PORTB7 hi = LED L off
			_delay_ms(10000);
		}
		*/
	}
	
}

