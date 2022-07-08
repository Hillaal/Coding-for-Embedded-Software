#include "device.h"
#include <stdio.h>

void (*functions_ptr[MAX_NUM_CLIENTS])(float);
float data;

void Device_Init(void){

for (int i = 0; i < MAX_NUM_CLIENTS; i++){

	functions_ptr[i] = NULL;

	}
}


void Get_Data(void)
{
	data = 100.0;
	notify();

}


void notify(void)
{
	unsigned char function_ID;
	for (function_ID = 0; function_ID < MAX_NUM_CLIENTS; function_ID++){
		if(functions_ptr[function_ID] != NULL)
		{
			(*functions_ptr[function_ID])(data);
		}
		else{
			/*do nothing*/
		}

	}

}


unsigned char subscribe(void (*ptr)(float))
{
	unsigned char function_ID;
	for (function_ID = 0; function_ID < MAX_NUM_CLIENTS; function_ID++){

		if(functions_ptr[function_ID] == NULL){
			functions_ptr[function_ID] = ptr;
			return function_ID;
		}

		else{
			/*do nothing*/
		}

	}
	return -1;
}

void unsubscribe(unsigned char function_ID)
{	if ((function_ID < MAX_NUM_CLIENTS) && (function_ID >= 0U)) /*check if the indexing is valid*/
	{
	functions_ptr[function_ID] = NULL;
	}

}
