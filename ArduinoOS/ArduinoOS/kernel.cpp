/*
 * ArduinoOS.cpp
 *
 * Created: 12/16/2019 3:15:57 AM
 * Author : Luke Lukeson
 */ 

#define F_CPU 16000000L // Specify oscillator frequency

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>


void initInterrupts()
{
	cli();
	TCCR4B |= (1 << CS40); // Sets timer 4 clock to on
	TIMSK4 |=  (1 << TOIE4); // Enable Timer 4 Interrupts
	DDRB |= (1 << PORTB7); // PORTB7 direction = out
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

void createTask()
{
	// Creates task to be called by scheduler
}

void scheduleTask()
{
	// Selects which task runs next using a queue
}

void runTask()
{
	// Puts task into CPU
}

void swapTasks()
{
	// Switch tasks when an interrupt is called
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
	cli();
	defaultTask();
	sei();
	TCCR4B |= (1 << CS40); // Sets timer 4 clock to on

}

ISR(TIMER4_OVF_vect, ISR_BLOCK)
{
	TCCR4B &= ~(1 << CS40); // Sets timer 4 clock to off
	PORTB |= (1 << PORTB7); // set 7th bit to HIGH
	_delay_ms(2000);
	PORTB &= ~(1 << PORTB7); // set 7th bit to LOW
	_delay_ms(2000);
	
}