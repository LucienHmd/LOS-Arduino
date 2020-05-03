

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "kernel.cpp"

#define F_CPU 16000000L // Specify oscillator frequency

// Creates a task which blinks a light out of pin 12
void task1(){
	
	PORTB |= (1 << PORTB6);
	_delay_ms(10000);
	PORTB &= ~(1 << PORTB6);
	_delay_ms(10000);
		
}

// Creates a task which blinks a light out of pin 11
void task2(){
	
	PORTB &= ~(1 << PORTB5); // PORTB7 hi = LED L off
	_delay_ms(5000);
	PORTB |= (1 << PORTB5);
	_delay_ms(5000);
}

int main(void)
{
	// Function for creating the two tasks
	createTask(task1);
	createTask(task2);
	

while(true){
	
	// Runs OS
		runOS();

	
}
}
		

