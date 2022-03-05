/*
============================================================================
 Name        : mystm32f401.h
 Author      : Ahmed Khaled Hilal
 Description : stm32f401CC memory map bases and offsets
 ============================================================================
*/



#ifndef INC_MYSTM32F401_H_
#define INC_MYSTM32F401_H_


/*RCC*/
#define RCC 			(0x40023800) /*RCC Base*/
#define RCC_APB1ENR		(0x40)		/*RCC_APB1ENR Offset*/
#define RCC_APB2ENR		(0x44)		/*RCC_APB2ENR Offset*/
#define RCC_AHB1ENR		(0x30)
#define RCC_AHB1RSTR		 (0x10)		/*AHB1RSTR offset this register has DMA1 and DMA2 reset bits*/

/*RCC registers definition macro*/
#define RCC_REG(REG_ID) 		   *((unsigned int*)(RCC+ REG_ID))

/*##############################################*/



/*##############    GPIO   ####################*/

/*GPIO memory map*/

#define GPIOA 				(0x40020000)
#define GPIOB 				(0x40020400)
#define GPIOC 				(0x40020800)

/*##############################################*/

/*GPIO registers offsets */

#define GPIO_MODER  		(0x00)
#define GPIO_OTYPER  		(0x04)
#define GPIO_OSPEEDR  		(0x08)
#define GPIO_PUPDR 			(0x0C)
#define GPIO_IDR 			(0x10)
#define GPIO_ODR  			(0x14)
#define GPIO_LCKR 			(0x1C)
#define GPIO_AFRL 			(0x20)
#define GPIO_AFRH 			(0x24)

/*##############################################*/



/*############   UART  #################*/

#define USART2		(0x40004400)	/*USART2 Base*/

/*USART registers offsets*/
#define USART_SR	(0x00)
#define USART_DR	(0x04)
#define USART_BRR	(0x08)
#define USART_CR1	(0x0C)
#define USART_CR2	(0x10)
/*##############################################*/



/*############   DMA  #################*/

/*bases*/
#define DMA1	(0x40026000)	/*DMA1 Base */
#define DMA2	(0x40026400)	/*DMA2 Base*/

/*DMA registers offsets*/

#define DMA_LISR	(0x0000)
#define DMA_HISR	(0x0004)
#define DMA_LIFCR	(0x0008)
#define DMA_HIFCR	(0x000C)
#define DMA_S0CR	(0x0010)
#define DMA_S0NDTR	(0x0014)
#define DMA_S0PAR	(0x0018)
#define DMA_S0M0AR	(0x001C)
#define DMA_S0M1AR	(0x0020)
#define DMA_S0FCR	(0x0024)
#define DMA_S1CR	(0x0028)
#define DMA_S1NDTR	(0x002C)
#define DMA_S1PAR	(0x0030)
#define DMA_S1M0AR	(0x0034)
#define DMA_S1M1AR	(0x0038)
#define DMA_S1FCR	(0x003C)
#define DMA_S2CR	(0x0040)
#define DMA_S2NDTR	(0x0044)
#define DMA_S2PAR	(0x0048)
#define DMA_S2M0AR	(0x004C)
#define DMA_S2M1AR	(0x0050)
#define DMA_S2FCR	(0x0054)
#define DMA_S3CR	(0x0058)
#define DMA_S3NDTR	(0x005C)
#define DMA_S3PAR	(0x0060)
#define DMA_S3M0AR	(0x0064)
#define DMA_S3M1AR	(0x0068)
#define DMA_S3FCR	(0x006C)
#define DMA_S4CR	(0x0070)
#define DMA_S4NDTR	(0x0074)
#define DMA_S4PAR	(0x0078)
#define DMA_S4M0AR	(0x007C)
#define DMA_S4M1AR	(0x0080)
#define DMA_S4FCR	(0x0084)
#define DMA_S5CR	(0x0088)
#define DMA_S5NDTR	(0x008C)
#define DMA_S5PAR	(0x0090)
#define DMA_S5M0AR	(0x0094)
#define DMA_S5M1AR	(0x0098)
#define DMA_S5FCR	(0x009C)
#define DMA_S6CR	(0x00A0)
#define DMA_S6NDTR	(0x00A4)
#define DMA_S6PAR	(0x00A8)
#define DMA_S6M0AR	(0x00AC)
#define DMA_S6M1AR	(0x00B0)
#define DMA_S6FCR	(0x00B4)
#define DMA_S7CR	(0x00B8)
#define DMA_S7NDTR	(0x00BC)
#define DMA_S7PAR	(0x00C0)
#define DMA_S7M0AR	(0x00C4)
#define DMA_S7M1AR	(0x00C8)
#define DMA_S7FCR	(0x00CC)
/*##############################################*/



/*############   NVIC  #################*/

#define NVIC			(0xE000E100)	/*Nested Vector Interrupt Controller Base*/
#define NVIC_ISER0		(0x00)
#define NVIC_ISER1		(0x04)
#define NVIC_ISER2		(0x08)
#define NVIC_ICER0		(0x180)
#define NVIC_ICER1		(0x184)
#define NVIC_ICER2		(0x188)



#define TIM2			(0x40000000)		/* Timer 2 base*/

/*  TIM2 to TIM5 register map   */

#define TIMx_CR1	(0x00)
#define TIMx_CR2	(0x04)
#define TIMx_SMCR	(0x08)
#define TIMx_DIER	(0x0C)
#define TIMx_SR 	(0x10)
#define TIMx_EGR	(0x14)
#define TIMx_CCMR1	(0x18)
#define TIMx_CCMR2	(0x1C)
#define TIMx_CCER	(0x20)
#define TIMx_CNT	(0x24)
#define TIMx_PSC	(0x28)
#define TIMx_ARR	(0x2C)
#define TIMx_CCR1	(0x34)
#define TIMx_CCR2	(0x38)
#define TIMx_CCR3	(0x3C)
#define TIMx_CCR4	(0x40)
#define TIMx_DCR	(0x48)
#define TIMx_DMAR	(0x4C)
#define TIM2_OR		(0x50)
#define TIM5_OR		(0x50)


#endif /* INC_MYSTM32F401_H_ */
