/*
============================================================================
 Name        : Timers driver test
 Author      : Ahmed Khaled Hilal
 Description : blink led using timer ISR
 ============================================================================
*/


#include "GPIO.h"
#include "INT.h"
#include "TIMER.h"

unsigned char toggle = 0;

int main(void) {

INT_NVIC_ENABLE (28); /* TIM2 global interrupt enable in NVIC*/

GPIO_EnableClock(A);	/*Enable Port A clock*/
GPIO_Init(A,0,OUTPUT,PUSH_PULL); /*GPIO A Pin 0 configuration*/

TIM_Init(UP_COUNT,1000); /*initialize timer in upcount mode and prescaler value 16000*/

TIM_Start();	/* enable timer interrupt */

  while (1) {


	  }

  return 0;
}

void TIM2_IRQHandler(void){

	if (TIM_REG(TIM2,TIMx_CR1) & (0x01 << 0)){

		toggle = toggle ^ 1;
		GPIO_WritePin(A,0,toggle);

	}

	TIM_REG(TIM2,TIMx_SR) &= ~(0x01 << 0);
}

