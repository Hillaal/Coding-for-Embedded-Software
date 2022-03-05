/*
============================================================================
 Name        : INT.h
 Author      : Ahmed Khaled Hilal
 Description : interrupts header file
 ============================================================================
*/



#ifndef INT_H
#define INT_H

#include "mySTM32F401.h"

#define INT_REG(BASE,OFFSET) 		   *((unsigned int*)(BASE + OFFSET))


void INT_NVIC_ENABLE (unsigned char pos);

void INT_NVIC_DISABLE (unsigned char pos);

#endif
