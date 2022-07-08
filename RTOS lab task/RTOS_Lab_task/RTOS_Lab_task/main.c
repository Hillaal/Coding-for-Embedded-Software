/*
 * RTOS_Lab_task.c
 *
 * Created: 6/6/2022 9:35:35 PM
 * Author : ahmed khaled
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"


void Task1_Func(void *parameters);
TaskHandle_t task1ptr;

void Task2_Func(void *parameters);
TaskHandle_t task2ptr;

void Task3_Func(void *parameters);
TaskHandle_t task3ptr;



int main(void)
{
    DDRA |= (0x07<<0); // configure pins 0,1,2 in PORTA as output pins for the LEDs
    PORTA &= ~(0x07<<0); // LEDs OFF
    
    xTaskCreate(Task1_Func,"first",configMINIMAL_STACK_SIZE,NULL,1,&task1ptr);
    xTaskCreate(Task2_Func,"second",configMINIMAL_STACK_SIZE,NULL,1,&task2ptr);
    xTaskCreate(Task3_Func,"third",configMINIMAL_STACK_SIZE,NULL,1,&task3ptr);

    vTaskStartScheduler();
	
    while (1) 
    {
    }
}



void Task1_Func(void *parameters)
{
	TickType_t task1_xLastWakeTime;
	const TickType_t task1_xFrequency = 50;		/*50 ticks*/
	// Initialize the xLastWakeTime variable with the current time.
	task1_xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil(&task1_xLastWakeTime, task1_xFrequency );
		PORTA ^= (0x01<<0);		/*toggle led Red*/
	
	}
}


void Task2_Func(void *parameters)
{
	TickType_t task2_xLastWakeTime;
	const TickType_t task2_xFrequency = 100;	/*100 ticks*/
	// Initialize the xLastWakeTime variable with the current time.
	task2_xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil(&task2_xLastWakeTime, task2_xFrequency );
		PORTA ^= (0x01<<1);		/*toggle led Green*/
		
	}
}


void Task3_Func(void *parameters)
{
	TickType_t task3_xLastWakeTime;
	const TickType_t task3_xFrequency = 200;	/*200 ticks*/
	// Initialize the xLastWakeTime variable with the current time.
	task3_xLastWakeTime = xTaskGetTickCount();
	
	while(1)
	{
		vTaskDelayUntil(&task3_xLastWakeTime, task3_xFrequency );
		PORTA ^= (0x01<<2);		/*toggle led Yellow*/
		
	}
}