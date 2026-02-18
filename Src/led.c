
#include "led.h"

void Led_Init(void)
{
	/* BLUE LED */
	/* Enable clock access to led port (port B)*/
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	/* Set led pin as output*/
	GPIOB->MODER |= GPIO_MODER_MODE5_0;
	GPIOB->MODER &= ~(GPIO_MODER_MODE5_1);

}

void Led_Set(uint32_t gpio)
{
//	/* Set led pin HIGH (GPIO)*/
	GPIOB->ODR |= gpio;
}

void Led_Clear(uint32_t gpio)
{
	/* Set led pin LOW (GPIO)*/
	GPIOB->ODR &= ~(gpio);

}

void Led_Toggle(uint32_t gpio){
	/* TOGGLE led pin (GPIO) */
	GPIOB->ODR ^= gpio;
	for(uint16_t i = 0; i < 40000; i++){

	}
}
