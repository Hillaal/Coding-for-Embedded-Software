#include "INT.h"

void INT_NVIC_ENABLE (uint32_t pos){

	if (pos < (uint32_t) 32 ){
		INT_REG(NVIC,NVIC_ISER0) |=  (uint32_t) ((uint32_t) 1 << pos);

	}

	else if((pos >= 32U) && (pos < 63U)){

		INT_REG(NVIC,NVIC_ISER1) |=  (uint32_t) ((uint32_t) 1 << (pos - (uint32_t) 32));
	}

	else{
		INT_REG(NVIC,NVIC_ISER2) |= (uint32_t) ((uint32_t) 1<< (pos - (uint32_t) 64));
	}

}

void INT_NVIC_DISABLE (uint32_t pos){

	if (pos < 32U){
		INT_REG(NVIC,NVIC_ICER0) |= (uint32_t) ((uint32_t) 1 << pos);
	}

	else if((pos >= 32U) && (pos<63U)){
		INT_REG(NVIC,NVIC_ICER1) |= (uint32_t) ((uint32_t) 1U<< ((uint32_t) pos - 32U));
	}

	else{
		INT_REG(NVIC,NVIC_ICER2) |= (uint32_t) ((uint32_t) 1<< (pos - (uint32_t) 64U));
	}

}
