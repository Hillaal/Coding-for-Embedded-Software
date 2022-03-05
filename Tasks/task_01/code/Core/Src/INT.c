#include "INT.h"

void INT_NVIC_ENABLE (unsigned char pos){

	if (pos<32){
		INT_REG(NVIC,NVIC_ISER0) |= (1<<pos);
	}

	else if(pos>=32 && pos<63){
		INT_REG(NVIC,NVIC_ISER1) |= (1<< (pos - 32));
	}

	else{
		INT_REG(NVIC,NVIC_ISER2) |= (1<< (pos - 64));
	}

}

void INT_NVIC_DISABLE (unsigned char pos){

	if (pos<32){
		INT_REG(NVIC,NVIC_ICER0) |= (1 << pos);
	}

	else if(pos>=32 && pos<63){
		INT_REG(NVIC,NVIC_ICER1) |= (1<< (pos - 32));
	}

	else{
		INT_REG(NVIC,NVIC_ICER2) |= (1<< (pos - 64));
	}

}
