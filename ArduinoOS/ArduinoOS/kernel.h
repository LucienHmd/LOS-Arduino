#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

const int MAX_PROGRAMS = 3;
void (*prgms[MAX_PROGRAMS])( void );
int freeSlotPointer = 1;
int currentProgram = 1;
int interuptCounter = 0;

#define ADDRESSING(r, address) uint8_t * r = (uint8_t *)address;

#define POP(task, r, rp) task.r = *task.rp;
#define REPLACE(task, r, rp) *task.rp = task.r;