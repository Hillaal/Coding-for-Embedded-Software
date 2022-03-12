#include "TIMER.h"



void TIM_Init(unsigned char counterMode,unsigned short prescaler){

	RCC_REG(RCC_APB1ENR) |= 0x01; /*Enable Timer 2 clock*/

	TIM_REG(TIM2,TIMx_PSC) = prescaler - 1;		/*setting the prescaler value*/
 
	TIM_REG(TIM2,TIMx_ARR) = 16000;		/*setting the autoReload value */

	TIM_REG(TIM2,TIMx_CR1) &= ~(0x02 << 5);		/*Edge-aligned mode. The counter counts up or down
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 depending on the direction bit (DIR).*/

	TIM_REG(TIM2,TIMx_CR1) &= ~(0x01 << 4); /* clearing DIR bit before inserting the new value*/
	TIM_REG(TIM2,TIMx_CR1) |= (counterMode << 4); /* setting DIR bit*/


	TIM_REG(TIM2,TIMx_CR1) |= (0x01 << 0);		/*Enable Counter*/
	while ( !(TIM_REG(TIM2,TIMx_SR) & (0x01 << 0)) ); /*waiting for update flag to be set*/
	TIM_REG(TIM2,TIMx_SR) &= ~(0x01 << 0); /*set flag to zero*/
}


void TIM_Start(void){

	TIM_REG(TIM2,TIMx_DIER) |= (0x01 << 0);		/*Update interrupt enable*/

}


void TIM_Stop(void){

	TIM_REG(TIM2,TIMx_DIER) &= ~(0x01 << 0);		/*Update interrupt disable*/

}
