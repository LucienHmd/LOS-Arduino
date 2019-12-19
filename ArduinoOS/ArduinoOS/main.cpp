

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000L // Specify oscillator frequency


int x = 0;



int main(void)
{
	
	sei();
	TCCR4B |= (1 << CS40); // Sets timer 4 clock
	TIMSK4 |=  (1 << TOIE4); // Enable Timer 4 Interrupts
	DDRB |= (1 << PORTB7); // PORTB7 direction = out
	
	
	while (1)
	{
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

ISR(TIMER4_OVF_vect, ISR_BLOCK)
{
	x = 1;
	PORTB |= (1 << PORTB7); // set 7th bit to HIGH
	_delay_ms(10000);
	PORTB &= ~(1 << PORTB7); // set 7th bit to LOW
	_delay_ms(10000);
	
}