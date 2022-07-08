/*
============================================================================
 Name        : mystm32f401.h
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC memory map bases and offsets
 ============================================================================
*/



#ifndef INC_MYSTM32F401_H_
#define INC_MYSTM32F401_H_
#include <stdint.h>


/*RCC*/
#define RCC 			((0x40023800U)) /*RCC Base*/
#define RCC_APB1ENR		((0x40U))		/*RCC_APB1ENR Offset*/
#define RCC_APB2ENR		((0x44U))		/*RCC_APB2ENR Offset*/
#define RCC_AHB1ENR		((0x30U))
#define RCC_AHB1RSTR    ((0x10U))		/*AHB1RSTR offset this register has DMA1 and DMA2 reset bits*/

/*RCC registers definition macro*/
#define RCC_REG(REG_ID) 		   (*((uint32_t*)(RCC+ REG_ID)))

/*##############################################*/



/*##############    GPIO   ####################*/

/*GPIO memory map*/

#define GPIOA 				((0x40020000U))
#define GPIOB 				((0x40020400U))
#define GPIOC 				((0x40020800U))

/*##############################################*/

/*GPIO registers offsets */

#define GPIO_MODER  		 (0x00U)
#define GPIO_OTYPER  		((0x04U))
#define GPIO_OSPEEDR  		((0x08U))
#define GPIO_PUPDR 			((0x0CU))
#define GPIO_IDR 			((0x10U))
#define GPIO_ODR  			((0x14U))
#define GPIO_LCKR 			((0x1CU))
#define GPIO_AFRL 			((0x20U))
#define GPIO_AFRH 			((0x24U))

/*##############################################*/



/*############   UART  #################*/

#define USART2		(0x40004400)	/*USART2 Base*/

/*USART registers offsets*/
#define USART_SR	((0x00U))
#define USART_DR	((0x04U))
#define USART_BRR	((0x08U))
#define USART_CR1	((0x0CU))
#define USART_CR2	((0x10U))
/*##############################################*/



/*############   DMA  #################*/

/*bases*/
#define DMA1	((0x40026000U))	/*DMA1 Base */
#define DMA2	((0x40026400U))	/*DMA2 Base*/

/*DMA registers offsets*/

#define DMA_LISR	((0x0000U))
#define DMA_HISR	((0x0004U))
#define DMA_LIFCR	((0x0008U))
#define DMA_HIFCR	((0x000CU))
#define DMA_S0CR	((0x0010U))
#define DMA_S0NDTR	((0x0014U))
#define DMA_S0PAR	((0x0018U))
#define DMA_S0M0AR	((0x001CU))
#define DMA_S0M1AR	((0x0020U))
#define DMA_S0FCR	((0x0024U))
#define DMA_S1CR	((0x0028U))
#define DMA_S1NDTR	((0x002CU))
#define DMA_S1PAR	((0x0030U))
#define DMA_S1M0AR	((0x0034U))
#define DMA_S1M1AR	((0x0038U))
#define DMA_S1FCR	((0x003CU))
#define DMA_S2CR	((0x0040U))
#define DMA_S2NDTR	((0x0044U))
#define DMA_S2PAR	((0x0048U))
#define DMA_S2M0AR	((0x004CU))
#define DMA_S2M1AR	((0x0050U))
#define DMA_S2FCR	((0x0054U))
#define DMA_S3CR	((0x0058U))
#define DMA_S3NDTR	((0x005CU))
#define DMA_S3PAR	((0x0060U))
#define DMA_S3M0AR	((0x0064U))
#define DMA_S3M1AR	((0x0068U))
#define DMA_S3FCR	((0x006CU))
#define DMA_S4CR	((0x0070U))
#define DMA_S4NDTR	((0x0074U))
#define DMA_S4PAR	((0x0078U))
#define DMA_S4M0AR	((0x007CU))
#define DMA_S4M1AR	((0x0080U))
#define DMA_S4FCR	((0x0084U))
#define DMA_S5CR	((0x0088U))
#define DMA_S5NDTR	((0x008CU))
#define DMA_S5PAR	((0x0090U))
#define DMA_S5M0AR	((0x0094U))
#define DMA_S5M1AR	((0x0098U))
#define DMA_S5FCR	((0x009CU))
#define DMA_S6CR	((0x00A0U))
#define DMA_S6NDTR	((0x00A4U))
#define DMA_S6PAR	((0x00A8U))
#define DMA_S6M0AR	((0x00ACU))
#define DMA_S6M1AR	((0x00B0U))
#define DMA_S6FCR	((0x00B4U))
#define DMA_S7CR	((0x00B8U))
#define DMA_S7NDTR	((0x00BCU))
#define DMA_S7PAR	((0x00C0U))
#define DMA_S7M0AR	((0x00C4U))
#define DMA_S7M1AR	((0x00C8U))
#define DMA_S7FCR	((0x00CCU))
/*##############################################*/



/*############   NVIC  #################*/

#define NVIC			((0xE000E100U))	/*Nested Vector Interrupt Controller Base*/
#define NVIC_ISER0		((0x00U))
#define NVIC_ISER1		((0x04U))
#define NVIC_ISER2		((0x08U))
#define NVIC_ICER0		((0x180U))
#define NVIC_ICER1		((0x184U))
#define NVIC_ICER2		((0x188U))



#define TIM2			((0x40000000U))		/* Timer 2 base*/

/*  TIM2 to TIM5 register map   */

#define TIMx_CR1	((0x00U))
#define TIMx_CR2	((0x04U))
#define TIMx_SMCR	((0x08U))
#define TIMx_DIER	((0x0CU))
#define TIMx_SR 	((0x10U))
#define TIMx_EGR	((0x14U))
#define TIMx_CCMR1	((0x18U))
#define TIMx_CCMR2	((0x1CU))
#define TIMx_CCER	((0x20U))
#define TIMx_CNT	((0x24U))
#define TIMx_PSC	((0x28U))
#define TIMx_ARR	((0x2CU))
#define TIMx_CCR1	((0x34U))
#define TIMx_CCR2	((0x38U))
#define TIMx_CCR3	((0x3CU))
#define TIMx_CCR4	((0x40U))
#define TIMx_DCR	((0x48U))
#define TIMx_DMAR	((0x4CU))
#define TIM2_OR		((0x50U))
#define TIM5_OR		((0x50U))


#endif /* INC_MYSTM32F401_H_ */
