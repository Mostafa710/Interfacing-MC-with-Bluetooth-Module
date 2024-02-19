#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART.h"
#include "LCD.h"

int main(void)
{
	unsigned char counter=0,data;
	LCD_init();
	_delay_ms(3000);
	USART_init(9600);
    while(1)
    {
		data = USART_receive_data();
		counter++;
		if(counter == 17)
		{
			LCD_move_cursor(2,1);
		}
		else if(counter == 33)
		{
			counter = 1;
			LCD_clear_screen();
		}
		LCD_send_char(data);
    }
}