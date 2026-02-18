//Upgrade develop for UART - Polling,ISR,DMA.
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "stm32wb55xx.h"

#define SYS_FREQ		(4000000)
#define APB2_CLK		SYS_FREQ
#define UART_BAUDRATE	(115200)
#define CR1_RE			(1U << 2)

#define USART1_TX		(1U << 9)  //PA9
#define USART1_RX		(1U << 10) //PA10


static void set_uart_baudrate(uint32_t periph_clk, uint32_t baudrate);
static uint32_t compute_baudarate(uint32_t periph_clk, uint32_t baudrate);
static void uart_write(int ch);

int __io_putchar(int ch)
{
	uart_write(ch);
	return ch;
}
void uart_tx_init(void)
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

	/* Configure baudrate */
	set_uart_baudrate(APB2_CLK, UART_BAUDRATE);

	/* Configure transfer direction */
	USART1->CR1 = USART_CR1_TE_Msk;

	/* Enable UART module */
	USART1->CR1 |= USART_CR1_UE;

}
static void uart_write(int ch){
	/* Make sure the transmit data register is empty*/
	while(!(USART1->ISR & USART_ISR_TXE)){}

	/* Write to transmit data register*/
	USART1->TDR = ch & (0xFF);
}
static void set_uart_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART1->BRR = compute_baudarate(periph_clk, baudrate);
}

static uint32_t compute_baudarate(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}
