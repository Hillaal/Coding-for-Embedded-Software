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
#include <stdint.h>

#define INT_REG(BASE,OFFSET) 		   (*((uint32_t*)((BASE) + (OFFSET))))


void INT_NVIC_ENABLE (uint32_t pos);

void INT_NVIC_DISABLE (uint32_t pos);

#endif
