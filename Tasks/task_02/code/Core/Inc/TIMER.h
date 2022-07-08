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

#define UP_COUNT ((uint32_t)0x00)
#define DOWN_COUNT ((uint32_t)0x01)
#define UPDATE_FLAG    ((TIM_REG(TIM2, TIMx_SR)) & (((uint32_t) 0x01 << 0U)))

/* functions declarations*/

void TIM_Init(uint32_t Mode,uint32_t Prescalar);

void TIM_Start(void);

void TIM_Stop(void);

void TIM2_IRQHandler(void);

/* macro for timer registers configuration*/

#define TIM_REG(TIM_ID,REG_ID) 		   (*((uint32_t*)((TIM_ID) + (REG_ID))))

#endif /* SRC_TIMER_H_ */
