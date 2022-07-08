/*
============================================================================
 Name        : GPIO.h
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC GPIO driver header file
 ============================================================================
*/



#ifndef GPIO_H
#define GPIO_H

#include "mySTM32F401.h"

#define A (0)
#define B (1)

/*masks*/

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

/*##############################################*/

/* Result Status*/
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

/*##############################################*/

/* Mode Types */
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

/*##############################################*/

/* Output modes*/
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

/*##############################################*/

/* Resistor modes */
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

/*##############################################*/

/*functions declarations*/

void GPIO_EnableClock(char PortNo);

void GPIO_Init(unsigned char PortNo, unsigned char PinNum, unsigned char PinDir,unsigned char DefaultState);

unsigned char GPIO_WritePin(unsigned char PortNo, unsigned char PinNum,unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortNo, unsigned char PinNum);

/*##############################################*/

/*GPIO registers definition macro*/

#define GPIO_REG(PORT_ID,REG_ID) 		   *((unsigned int*)(PORT_ID + REG_ID))

/*##############################################*/

#endif /* GPIO_H */
