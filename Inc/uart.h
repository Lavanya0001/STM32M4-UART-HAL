#pragma once

#ifndef UART_H_
#define UART_H_

#include "stm32wb55xx.h"

#define SYS_FREQ		(4000000)
#define APB2_CLK		SYS_FREQ
#define UART_BAUDRATE	(115200)
#define CR1_RE			(1U << 2)

#define USART1_TX		(1U << 9)  //PA9(Tx) - 19
#define USART1_RX		(1U << 10) //PA10(Rx)- 31

void m_uart_init(USART_TypeDef* USART);
void m_uart_write(int ch);
int16_t m_uart_read(uint32_t Timeout);
int m_uart_transmit_blocking( char* ptr);

#endif /* UART_H_ */
