#pragma once

#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include "stm32wb55xx.h"

#define GPIOB_GPIO_ODR_OD5	GPIO_ODR_OD5
#define ON_BOARD_LED_BLUE  	GPIOB_GPIO_ODR_OD5

void Led_Init(void);
void Led_Set(uint32_t gpio);
void Led_Clear(uint32_t gpio);
void Led_Toggle(uint32_t gpio);

#endif /* LED_H_ */
