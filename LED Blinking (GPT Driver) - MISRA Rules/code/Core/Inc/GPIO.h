/*
============================================================================
 Name    : GPIO.h
 Author   : Ahmed Khaled Hilal
 Description : stm32f401CC GPIO driver header file
 ============================================================================
*/



#ifndef GPIO_H
#define GPIO_H

#include "mySTM32F401.h"

#define A (0x00U)
#define B (0x01U)

/*masks*/

#define _OUTTYPE_MASK (0x01U)
#define _OUTTYPE_SHIFT (0x00U)

#define _PUPD_MASK (0x06U)
#define _PUPD_SHIFT (0x01U)

/*##############################################*/

/* Result Status*/
#define OK (0x00U)
#define NOK (0x01U)

/*##############################################*/

/* Mode Types */
#define INPUT (0x00U)
#define OUTPUT (0x01U)
#define ALTERNATE_FUN (0x02U)
#define ANALOG (0x03U)

/*##############################################*/

/* Output modes*/
#define PUSH_PULL (0x00U)
#define OPEN_DRAIN (0x01U)

/*##############################################*/

/* Resistor modes */
#define NO_PULL_UP_DOWN (0x00U)
#define PULL_UP (0x02U)
#define PULL_DOWN (0x04U)

/*##############################################*/

/*functions declarations*/

void GPIO_EnableClock(uint32_t PortNo);

void GPIO_Init(uint32_t PortNo, uint32_t PinNum, uint32_t PinMode,uint32_t DefaultState);


uint32_t GPIO_WritePin(uint32_t PortNo, uint32_t PinNum,uint32_t Data);

uint32_t GPIO_ReadPin(uint32_t PortNo, uint32_t PinNum);

/*##############################################*/

/*GPIO registers definition macro*/

#define GPIO_REG(PORT_ID, REG_ID) 		  (*((uint32_t*)((PORT_ID) + (REG_ID))))

/*##############################################*/

#endif /* GPIO_H */
