

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "kernel.cpp"
#include "SerialPort.cpp"

#define F_CPU 16000000L // Specify oscillator frequency


void task1(){

	PORTB &= ~(1 << PORTB7); // PORTB7 hi = LED L off
		
}

void task2(){
	
	PORTB &= ~(1 << PORTB7); // PORTB7 hi = LED L off
	
}

int main(void)
{
	initInterrupts();
	initLED();
	PORTB = 0b10000000;
	
	
	createTask(1, task1);
	
	
	
	while(true){
		//runTask();'
		SendData();
	}
	
	
		
		
		//runOS();
		
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

