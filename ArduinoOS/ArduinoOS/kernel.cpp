/*
 * ArduinoOS.cpp
 *
 * Created: 12/16/2019 3:15:57 AM
 * Author : Luke Lukeson
 */ 

//#define F_CPU 16000000L // Specify oscillator frequency

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>


const int MAX_PROGRAMS = 2;
void (*prgms[MAX_PROGRAMS])( void );
bool freeSlotPointer = 0;

int interuptCounter = 0;

void initLED()
{
	cli();
	DDRB |= (1 << PORTB7); // PORTB7 direction = out
	sei();
}

void initInterrupts()
{
	cli();
	TCCR4B |= (1 << CS40); // Sets timer 4 clock to on
	TIMSK4 |=  (1 << TOIE4); // Enable Timer 4 Interrupts
	sei();
}
	

void pushRegisters()
{
	// Pushes all 32 multi purpose registers into memory
}

void pullRegisters()
{
	// Pulls all 32 multi purpose registers from memory and puts them back into the correct registers
}

void createTask(bool loop, void (*task)())
{
	// Creates task to be called by scheduler
	
		if (freeSlotPointer == 0) {
			prgms[freeSlotPointer] = task;
			freeSlotPointer = 1;
		} else if (freeSlotPointer == 1) {
			prgms[freeSlotPointer] = task;
			freeSlotPointer = 0;
		} 
		
		
	
	}

void scheduleTask()
{
	// Selects which task runs next using a queue
}

void runTask()
{
	// Puts task into CPU
	(*prgms[0])();
	
}

void swapTasks()
{
	// Switch tasks when an interrupt is called using a queue
}

void defaultTask()
{
	PORTB = 0b10000000; // set 7th bit to LOW
	_delay_ms(10000);
	PORTB = 0b00000000; // set 7th bit to HIGH
	_delay_ms(10000);
	
}

void runOS()
{
	/*
	runOS() should be called in the main file after createTask() was run and it should call functions scheduleTask() and runTask() to begin the tasks
	
	*/
	cli();
	runTask();
	sei();
	

}

ISR(TIMER4_OVF_vect, ISR_BLOCK)
{
	// This interrupt should call swapTask() 
	//TCCR4B &= ~(1 << CS40); // Sets timer 4 clock to off
	if (interuptCounter == 10) {
		interuptCounter = 0;
		TCCR4B &= ~(1 << CS40); // Sets timer 4 clock to off
		PORTB |= (1 << PORTB7);
		_delay_ms(2000);
		TCCR4B |= (1 << CS40); // Sets timer 4 clock to on
	} else {
		interuptCounter++;
	}

	// PORTB |= (1 << PORTB7); // set 7th bit to HIGH
	//_delay_ms(2000);
	//PORTB &= ~(1 << PORTB7); // set 7th bit to LOW
	//_delay_ms(5000);
	
}