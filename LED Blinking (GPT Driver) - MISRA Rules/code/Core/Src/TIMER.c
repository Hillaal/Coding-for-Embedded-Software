#include "TIMER.h"



void TIM_Init(uint32_t counterMode, uint32_t prescaler){

	RCC_REG(RCC_APB1ENR) |= 0x01U; /*Enable Timer 2 clock*/

	TIM_REG(TIM2,TIMx_PSC) |=  (prescaler -  1U);		/*setting the prescaler value*/
 
	TIM_REG(TIM2,TIMx_ARR) = 16000U;		/*setting the autoReload value */

	TIM_REG(TIM2,TIMx_CR1) &=  ~((uint32_t) 0x02 << 5U);		/*Edge-aligned mode. The counter counts up or down
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 depending on the direction bit (DIR).*/

	TIM_REG(TIM2,TIMx_CR1) &= (~((uint32_t) 0x01 << 4U)); /* clearing DIR bit before inserting the new value*/
	TIM_REG(TIM2,TIMx_CR1) |= (counterMode << 4U); /* setting DIR bit*/


	TIM_REG(TIM2,TIMx_CR1) |= ( (uint32_t) 0x01 << 0U);		/*Enable Counter*/
	while ( ! UPDATE_FLAG ){} /*waiting for update flag to be set*/
	TIM_REG(TIM2,TIMx_SR) &= ~((uint32_t) 0x01 << 0U); /*set flag to zero*/
}


void TIM_Start(void){

	TIM_REG(TIM2,TIMx_DIER) |= ((uint32_t) 0x01 << 0U);		/*Update interrupt enable*/

}


void TIM_Stop(void){

	TIM_REG(TIM2,TIMx_DIER) &= ~(0x01 << 0);		/*Update interrupt disable*/

}
