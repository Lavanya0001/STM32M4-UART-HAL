/* @brief: This Project, implementing UART in LOW LEVEL
*/
#include <stdio.h>
#include "led.h"
#include "uart.h"

int main()
{
	Led_Init();

	while(1)
	{
		Led_Toggle(ON_BOARD_LED_BLUE);
	}
}



