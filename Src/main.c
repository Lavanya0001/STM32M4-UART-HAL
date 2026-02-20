/* @brief: This Project, implementing UART in LOW LEVEL
*/
#include <stdio.h>
#include "led.h"
#include "uart.h"

int main()
{
	//LED Initialization
	Led_Init();

	//UART Initialization
	m_uart_init(USART1);

	char *Test_data = "UART Blocking mode is working\n";


	while(1)
	{
		m_uart_transmit_blocking(Test_data);
		Led_Toggle(ON_BOARD_LED_BLUE);
	}
}



