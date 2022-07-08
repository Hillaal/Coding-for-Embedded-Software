/*
============================================================================
 Name        : GPIO.c
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC GPIO driver source file
 ============================================================================
*/

#include "GPIO.h"

static uint32_t Port[3]={GPIOA, GPIOB, GPIOC}; 	/*array of ports addresses*/

/*static because it will be used only in this file and doesn't want any other file to use it */


void GPIO_EnableClock(uint32_t PortNo)
{

	RCC_REG (RCC_AHB1ENR)  |= (uint32_t) ((uint32_t) 0x01 << PortNo);  /*Enable clock for the port that will be used*/

}

/* GPIO initialize function, takes arguments (port number, pin number, pin mode, pin default state)*/

void GPIO_Init(uint32_t PortNo, uint32_t PinNum, uint32_t PinMode, uint32_t DefaultState)
{

  GPIO_REG(Port[PortNo], GPIO_MODER) &= (uint32_t)  (~ (uint32_t)((uint32_t) 0x03U << ( 2U * PinNum)));
  GPIO_REG(Port[PortNo], GPIO_MODER) |= (uint32_t) (PinMode << ((uint32_t) 2 * PinNum));

  GPIO_REG(Port[PortNo],GPIO_OTYPER) &= (uint32_t) ~((uint32_t) 1 << PinNum);

  GPIO_REG(Port[PortNo],GPIO_OTYPER)|= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << (PinNum);

  GPIO_REG(Port[PortNo],GPIO_PUPDR) &= (uint32_t) ~((uint32_t) 0x03 << ((uint32_t) 2 * PinNum));

  GPIO_REG(Port[PortNo],GPIO_PUPDR) |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << ((uint32_t) 2 * PinNum);

}

/*function to write GPIO pin takes arguments(port number,pin number, the data to be written 0 or 1)*/

uint32_t GPIO_WritePin(uint32_t PortNo, uint32_t PinNum,uint32_t Data)
{

    uint32_t result;

      if (((GPIO_REG(Port[PortNo],GPIO_MODER) & (uint32_t) ((uint32_t) 0x03 << (uint32_t) 2 * PinNum)) >> ((uint32_t) 2 * PinNum)) == (uint32_t) 1) {
        if (Data) {
        	GPIO_REG(Port[PortNo],GPIO_ODR) |= (uint32_t) ((uint32_t) 1 << PinNum);
        } else {
        	GPIO_REG(Port[PortNo],GPIO_ODR) &= (uint32_t) ~((uint32_t) 1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

/*function to read GPIO pin takes arguments(port number,pin number) and return data 0 or 1 */

uint32_t GPIO_ReadPin(uint32_t PortNo, uint32_t PinNum) {
	uint32_t data = 0;

	data = (GPIO_REG(Port[PortNo],GPIO_IDR) & (uint32_t) ((uint32_t) 1 << PinNum)) >> PinNum;

  return data;
}
