/*
============================================================================
 Name        : TIMER.h
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC general purpose TIMER simple driver header file
 ============================================================================
*/


#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include "mySTM32F401.h"

/*masks*/

#define UP_COUNT (0)
#define DOWN_COUNT (1)


/* functions declarations*/

void TIM_Init(unsigned char Mode,unsigned short Prescalar);

void TIM_Start(void);

void TIM_Stop(void);

/* macro for timer registers configuration*/

#define TIM_REG(TIM_ID,REG_ID) 		   *((unsigned int*)(TIM_ID + REG_ID))

#endif /* SRC_TIMER_H_ */
