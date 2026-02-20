//Upgrade develop for UART - Polling,ISR,DMA.
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "string.h"

static void m_set_uart_baudrate(uint32_t periph_clk, uint32_t baudrate);
static uint32_t m_compute_baudarate(uint32_t periph_clk, uint32_t baudrate);
static void m_uart_write(int ch);

//By Keeping this in __io_putchar, you can use printf() with UART
int __io_putchar(int ch)
{
	m_uart_write(ch);
	return ch;
}

void m_uart_init(USART_TypeDef* USART)
{
	/* Enable clock access to GPIOA */
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN_Msk;

	/* Set PA9 mode to alternate function mode */
	GPIOA->MODER &= ~(3U << 18);
	GPIOA->MODER |=  (1U << 19);

	/* Set alternate function type to AF7 (USART1_TX)*/
	GPIOA->AFR[1] &= ~(0xFU << 4);
	GPIOA->AFR[1] |=  (7U << 4);

	/* Enable clock access to USART */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;

	/* Configure BAUDRATE */
	m_set_uart_baudrate(APB2_CLK, UART_BAUDRATE);

	/* Configure transfer direction */
	USART->CR1 = (USART_CR1_TE_Msk | USART_CR1_RE_Msk);

	/* Enable UART module */
	USART->CR1 |= USART_CR1_UE;

}

static void m_uart_write(int ch){
	/* Make sure the transmit data register is empty*/
	while(!(USART1->ISR & USART_ISR_TXE)){}

	/* Write to transmit data register*/
	USART1->TDR = ch & (0xFF);
}

int m_uart_transmit_blocking(char* ptr)
{
	int DataIdx = 0;
	size_t len = strlen(ptr);
	for(DataIdx; DataIdx < len; DataIdx++){

		m_uart_write(*ptr++);
	}

	return (DataIdx + 1);
}

static void m_set_uart_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART1->BRR = m_compute_baudarate(periph_clk, baudrate);
}

static uint32_t m_compute_baudarate(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}
