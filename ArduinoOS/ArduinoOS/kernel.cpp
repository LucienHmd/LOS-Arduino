/*
 * ArduinoOS.cpp
 *
 * Created: 12/16/2019 3:15:57 AM
 * Author : Luke Lukeson
 */ 

//#define F_CPU 16000000L // Specify oscillator frequency


#include "kernel.h"


// A structure created for each Task which contains a pointer to each
// register and a variable which the registers value gets assigned to

struct Task {
	
	ADDRESSING(r1p, 0x00); // Each ADDRESSING macro contains "volatile uint8_t * rX = (volatile uint8_t *)Y"
	volatile uint8_t r1;
	ADDRESSING(r2p, 0x01);
	volatile uint8_t r2;
	ADDRESSING(r3p, 0x02);
	volatile uint8_t r3;
	ADDRESSING(r4p, 0x03);
	volatile uint8_t r4;
	ADDRESSING(r5p, 0x04);
	volatile uint8_t r5;
	ADDRESSING(r6p, 0x05);
	volatile uint8_t r6;
	ADDRESSING(r7p, 0x06);
	volatile uint8_t r7;
	ADDRESSING(r8p, 0x07);
	volatile uint8_t r8;
	ADDRESSING(r9p, 0x08);
	volatile uint8_t r9;
	ADDRESSING(r10p, 0x09);
	volatile uint8_t r10;
	ADDRESSING(r11p, 0x0A);
	volatile uint8_t r11;
	ADDRESSING(r12p, 0x0B);
	volatile uint8_t r12;
	ADDRESSING(r13p, 0x0C);
	volatile uint8_t r13;
	ADDRESSING(r14p, 0x0D);
	volatile uint8_t r14;
	ADDRESSING(r15p, 0x0E);
	volatile uint8_t r15;
	ADDRESSING(r16p, 0x0F);
	volatile uint8_t r16;
	ADDRESSING(r17p, 0x10);
	volatile uint8_t r17;
	ADDRESSING(r18p, 0x11);
	volatile uint8_t r18;
	ADDRESSING(r19p, 0x12);
	volatile uint8_t r19;
	ADDRESSING(r20p, 0x13);
	volatile uint8_t r20;
	ADDRESSING(r21p, 0x14);
	volatile uint8_t r21;
	ADDRESSING(r22p, 0x15);
	volatile uint8_t r22;
	ADDRESSING(r23p, 0x16);
	volatile uint8_t r23;
	ADDRESSING(r24p, 0x17);
	volatile uint8_t r24;
	ADDRESSING(r25p, 0x18);
	volatile uint8_t r25;
	ADDRESSING(r26p, 0x19);
	volatile uint8_t r26;
	ADDRESSING(r27p, 0x1A);
	volatile uint8_t r27;
	ADDRESSING(r28p, 0x1B);
	volatile uint8_t r28;
	ADDRESSING(r29p, 0x1C);
	volatile uint8_t r29;
	ADDRESSING(r30p, 0x1D);
	volatile uint8_t r30;
	ADDRESSING(r31p, 0x1E);
	volatile uint8_t r31;
	ADDRESSING(r32p, 0x1F);
	volatile uint8_t r32;
};

// Initializes two structs for taskOne and taskTwo
struct Task taskOne;
struct Task taskTwo;

void init()
{
	cli();
	DDRB |= (1 << PORTB7); // PORTB7 direction = out
	DDRB |= (1 << PORTB6);
	DDRB |= (1 << PORTB5);
	
	TCCR4B |= (1 << CS40); // Sets timer 4 clock to on
	TIMSK4 |=  (1 << TOIE4); // Enable Timer 4 Interrupts
	sei();
}


	
// Pushes all 32 multi purpose registers into memory
void popRegisters() {
	cli();
	
	if (currentProgram == 1) {
		// Each POP takes the current value of the registers and puts it into a variable
		POP(taskOne, r1, r1p);
		POP(taskOne, r2, r2p);
		POP(taskOne, r3, r3p);
		POP(taskOne, r4, r4p);
		POP(taskOne, r5, r5p);
		POP(taskOne, r6, r6p);
		POP(taskOne, r7, r7p);
		POP(taskOne, r8, r8p);
		POP(taskOne, r9, r9p);
		POP(taskOne, r10, r10p);
		POP(taskOne, r11, r11p);
		POP(taskOne, r12, r12p);
		POP(taskOne, r13, r13p);
		POP(taskOne, r14, r14p);
		POP(taskOne, r15, r15p);
		POP(taskOne, r16, r16p);
		POP(taskOne, r17, r17p);
		POP(taskOne, r18, r18p);
		POP(taskOne, r19, r19p);
		POP(taskOne, r20, r20p);
		POP(taskOne, r21, r21p);
		POP(taskOne, r22, r22p);
		POP(taskOne, r23, r23p);
		POP(taskOne, r24, r24p);
		POP(taskOne, r25, r25p);
		POP(taskOne, r26, r26p);
		POP(taskOne, r27, r27p);
		POP(taskOne, r28, r28p);
		POP(taskOne, r29, r29p);
		POP(taskOne, r30, r30p);
		POP(taskOne, r31, r31p);
		POP(taskOne, r32, r32p);
		
	} else if (currentProgram == 2) {
		// Each POP takes the current value of the registers and puts it into a variable
		POP(taskTwo, r1, r1p);
		POP(taskTwo, r2, r2p);
		POP(taskTwo, r3, r3p);
		POP(taskTwo, r4, r4p);
		POP(taskTwo, r5, r5p);
		POP(taskTwo, r6, r6p);
		POP(taskTwo, r7, r7p);
		POP(taskTwo, r8, r8p);
		POP(taskTwo, r9, r9p);
		POP(taskTwo, r10, r10p);
		POP(taskTwo, r11, r11p);
		POP(taskTwo, r12, r12p);
		POP(taskTwo, r13, r13p);
		POP(taskTwo, r14, r14p);
		POP(taskTwo, r15, r15p);
		POP(taskTwo, r16, r16p);
		POP(taskTwo, r17, r17p);
		POP(taskTwo, r18, r18p);
		POP(taskTwo, r19, r19p);
		POP(taskTwo, r20, r20p);
		POP(taskTwo, r21, r21p);
		POP(taskTwo, r22, r22p);
		POP(taskTwo, r23, r23p);
		POP(taskTwo, r24, r24p);
		POP(taskTwo, r25, r25p);
		POP(taskTwo, r26, r26p);
		POP(taskTwo, r27, r27p);
		POP(taskTwo, r28, r28p);
		POP(taskTwo, r29, r29p);
		POP(taskTwo, r30, r30p);
		POP(taskTwo, r31, r31p);
		POP(taskTwo, r32, r32p);
	}
	sei();
}

// Pulls all 32 multi purpose registers from memory and puts them back into the correct registers
void replaceRegisters() {

	cli();
	if (currentProgram == 1) {
		
		// Each REPLACE takes the current value of a stored variable and puts it into a register
		REPLACE(taskOne, r1, r1p);
		REPLACE(taskOne, r2, r2p);
		REPLACE(taskOne, r3, r3p);
		REPLACE(taskOne, r4, r4p);
		REPLACE(taskOne, r5, r5p);
		REPLACE(taskOne, r6, r6p);
		REPLACE(taskOne, r7, r7p);
		REPLACE(taskOne, r8, r8p);
		REPLACE(taskOne, r9, r9p);
		REPLACE(taskOne, r10, r10p);
		REPLACE(taskOne, r11, r11p);
		REPLACE(taskOne, r12, r12p);
		REPLACE(taskOne, r13, r13p);
		REPLACE(taskOne, r14, r14p);
		REPLACE(taskOne, r15, r15p);
		REPLACE(taskOne, r16, r16p);
		REPLACE(taskOne, r17, r17p);
		REPLACE(taskOne, r18, r18p);
		REPLACE(taskOne, r19, r19p);
		REPLACE(taskOne, r20, r20p);
		REPLACE(taskOne, r21, r21p);
		REPLACE(taskOne, r22, r22p);
		REPLACE(taskOne, r23, r23p);
		REPLACE(taskOne, r24, r24p);
		REPLACE(taskOne, r25, r25p);
		REPLACE(taskOne, r26, r26p);
		REPLACE(taskOne, r27, r27p);
		REPLACE(taskOne, r28, r28p);
		REPLACE(taskOne, r29, r29p);
		REPLACE(taskOne, r30, r30p);
		REPLACE(taskOne, r31, r31p);
		REPLACE(taskOne, r32, r32p);
		
		} else if (currentProgram == 2) {
			
		// Each REPLACE takes the current value of a stored variable and puts it into a register
		REPLACE(taskTwo, r1, r1p);
		REPLACE(taskTwo, r2, r2p);
		REPLACE(taskTwo, r3, r3p);
		REPLACE(taskTwo, r4, r4p);
		REPLACE(taskTwo, r5, r5p);
		REPLACE(taskTwo, r6, r6p);
		REPLACE(taskTwo, r7, r7p);
		REPLACE(taskTwo, r8, r8p);
		REPLACE(taskTwo, r9, r9p);
		REPLACE(taskTwo, r10, r10p);
		REPLACE(taskTwo, r11, r11p);
		REPLACE(taskTwo, r12, r12p);
		REPLACE(taskTwo, r13, r13p);
		REPLACE(taskTwo, r14, r14p);
		REPLACE(taskTwo, r15, r15p);
		REPLACE(taskTwo, r16, r16p);
		REPLACE(taskTwo, r17, r17p);
		REPLACE(taskTwo, r18, r18p);
		REPLACE(taskTwo, r19, r19p);
		REPLACE(taskTwo, r20, r20p);
		REPLACE(taskTwo, r21, r21p);
		REPLACE(taskTwo, r22, r22p);
		REPLACE(taskTwo, r23, r23p);
		REPLACE(taskTwo, r24, r24p);
		REPLACE(taskTwo, r25, r25p);
		REPLACE(taskTwo, r26, r26p);
		REPLACE(taskTwo, r27, r27p);
		REPLACE(taskTwo, r28, r28p);
		REPLACE(taskTwo, r29, r29p);
		REPLACE(taskTwo, r30, r30p);
		REPLACE(taskTwo, r31, r31p);
		REPLACE(taskTwo, r32, r32p);
}

sei();

}

// Creates a task for the scheduler
void createTask(void (*task)()) {
	
	cli();
	
	// Takes the function created by the user and passes the pointer to the function into an array for use by the scheduler
		if (freeSlotPointer == 1) {
			prgms[1] = task;
			freeSlotPointer = 2;
		} else if (freeSlotPointer == 2) {
			prgms[2] = task;
			// freeSlotPointer is changed to 0 so that any further functions passed in aren't used the by OS
			freeSlotPointer = 0;
		} 
		
	sei();
}


// Puts task into CPU to run
// This is to be run in the loop function of an arduino sketch
void runTask() {
	
	if(currentProgram == 1) {
		(*prgms[1])();
		currentProgram = 2;
	} else if(currentProgram == 2) {
		(*prgms[2])();
		currentProgram = 1;
		
}
	
	
}

// Used for testing purposes
void defaultTask()
{
	PORTB = 0b10000000; // set 7th bit to LOW
	_delay_ms(10000);
	PORTB = 0b00000000; // set 7th bit to HIGH
	_delay_ms(10000);
	
}

// runTask() with a built in while loop
void runOS()
{
	init();
	
	while(true) {
		runTask();
	}
	
}

// This defines the interrupt to stop whats currently running 
ISR(TIMER4_OVF_vect, ISR_BLOCK)
{
	cli();
	// Interrupt executes so quickly so a counter was placed to execute tasks slower
	if (interuptCounter == 10) {
		interuptCounter = 0;
		
		if(currentProgram == 0) {
			popRegisters();
			currentProgram = 1;
			replaceRegisters();
		} else if(currentProgram == 1) {
			popRegisters();
			currentProgram = 2;
			replaceRegisters();
		} else if(currentProgram == 2) {
			popRegisters();
			currentProgram = 1;
			replaceRegisters();
		}
		
	} else {
		interuptCounter++;
	}

	sei();
}