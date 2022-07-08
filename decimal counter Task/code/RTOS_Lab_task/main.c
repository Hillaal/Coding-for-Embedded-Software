/*
 * decimal counter.c
 *
 * Created: 7/6/2022 7:35:35 PM
 * Author : Ahmed Khaled
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


void Task1_Func(void *parameters);
TaskHandle_t task1ptr;

void Task2_Func(void *parameters);
TaskHandle_t task2ptr;

SemaphoreHandle_t xSemaphore = NULL;

unsigned char counter = 0;

const unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void)
{	
	
	DDRA  &= ~((1 << PA0) | (1 << PA1)); // configure pin 4 in PORTD as input pin
	DDRC |= 0x7F; // configure first four pins of PORTC as output pins
	
	// initialize the 7-segment
	PORTC |= ((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3)| (1<<PC4)| (1<<PC5)| (1<<PC6));
	
	xSemaphore =   xSemaphoreCreateBinary();
	
	
    xTaskCreate(Task1_Func,"first",configMINIMAL_STACK_SIZE,NULL,1,&task1ptr);		/*polling buttons task creation*/
    xTaskCreate(Task2_Func,"second",configMINIMAL_STACK_SIZE,NULL,1,&task2ptr);		/*display on seven segment task creation*/
	
	xSemaphoreGive( xSemaphore );
	
	vTaskStartScheduler();
	
	
    while (1) 
    {
    }
}



void Task1_Func(void *parameters)
{	
	
	while(1)
	{
			/*take the semaphore*/
			xSemaphoreTake( xSemaphore, ( TickType_t ) 10) ;	
					 
			if( PINA & (1<<PA0) )	
			{
				vTaskDelay(10);
				//second check due to switch bouncing
				if( PINA & (1<<PA0) )
				{
					while( PINA & (1<<PA0) ){} // wait until switch is released
						
							if(counter == 9)
							{
								// if overflow occurs
								counter = 0;
							}
							
							else
							{
								// increment
								counter = counter + 1;
								
							}
				
					}

			}
		

			else if( PINA & (1<<PA1) )
			{
				vTaskDelay(10);
				//second check due to switch bouncing
				if( PINA & (1<<PA1) )
				{
					while( PINA & (1<<PA1) ){} // wait until switch is released

							if(counter == 0)
							{
								// if underflow occurs
								counter = 9;
							}
							
							else
							{
								// decrement
								counter = counter - 1;
								
							}
		
				
				}
				
				

			}
			
				
		/*release semaphore*/
		xSemaphoreGive( xSemaphore );	
		vTaskDelay(1);
	}
}



void Task2_Func(void *parameters)
{
	unsigned char counterCopy = 0;
	
	while(1)
	{
		/*take the semaphore*/
		xSemaphoreTake( xSemaphore, ( TickType_t ) 10);
        {
				/*change seven segment counter*/
            	counterCopy = counter;	
        }
		/*release the semaphore*/
		xSemaphoreGive( xSemaphore );	
		
		/*Display on seven segment*/
		PORTC = ~(sevenSegHex[counterCopy]);
		vTaskDelay(1);
		
	}
}
