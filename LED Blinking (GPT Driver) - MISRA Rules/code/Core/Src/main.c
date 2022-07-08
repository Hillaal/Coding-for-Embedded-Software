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
#include <stdint.h>

uint32_t toggle = 0U;
int32_t main(void);

int32_t main(void) {

INT_NVIC_ENABLE ((uint8_t)28); /* TIM2 global interrupt enable in NVIC*/

GPIO_EnableClock(A);	/*Enable Port A clock*/
GPIO_Init(A,(uint8_t)0,OUTPUT,PUSH_PULL); /*GPIO A Pin 0 configuration*/

TIM_Init(UP_COUNT,(uint8_t)1000); /*initialize timer in upcount mode and prescaler value 16000*/

TIM_Start();	/* enable timer interrupt */

  while (1) {

	  	  /*loop forever*/
	  }

}



void TIM2_IRQHandler(void){

	/*Timer 2 interrupt service routine*/

	/* check the update interrupt flag*/
	if ((TIM_REG(TIM2,TIMx_SR)) & ((uint32_t)0x01 << 0U)){

		toggle = toggle ^ 0x01U;
		GPIO_WritePin(A, 0U ,toggle);		/*toggle the pin*/


		TIM_REG(TIM2,TIMx_SR) &= ~((uint32_t) 0x01 << 0);	/*clear the update interrupt flag*/
	}


}

