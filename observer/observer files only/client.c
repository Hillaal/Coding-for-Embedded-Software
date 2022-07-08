
#include "client.h"
#include "device.h"
#include "stm32f4xx.h"

static float temp;
static unsigned char function_ID;

void init(void){
	function_ID = subscribe(update);
}


void update(float data){

 temp = data;

}



void Handle_data(void)
{
	if(temp>900.0)
	{
		GPIOA->ODR |= (1u<<5);
	}
	else
	{
		GPIOA->ODR &= ~(1u<<5);
	}
}



