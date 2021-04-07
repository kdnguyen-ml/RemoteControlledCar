/*
 MSP430G2553:
 P1.1 -> UCA0SOMI
 P1.2 -> UCA0SIMO
 P1.4 -> UCA0CLK
 P1.6 -> UCB0SOMI
 P1.7 -> UCB0SIMO
 P1.5 -> UCB0CLK
 */
/****************************************************
 *  NOTE: NRF24L01.c has a pin mapping different
 ****************************************************/
//Connect to PORT1
#define MISO BIT0
#define MOSI BIT3
#define CLK BIT4
#define CE BIT5
#define CSN BIT6
#define IRQ BIT7

#include <msp430g2553.h>
#include "LCD.h"
#include "Basic_config.h"
#include "NRF24L01.h"
#include "UART.h"

int start=0;
/*char uart_get()
{
	int count = 0;
	while(!(IFG2&UCA0RXIFG))
	{
		if(start==1)
		{
			count++;
			delay_ms(10);
			P2OUT |= BIT1;
			if(count==10)
			{
				count=0;
				break;
			}
		}
	}
	return UCA0RXBUF;
}*/
char uart_get(unsigned char *data)
{
	while(!(IFG2&UCA0RXIFG))
	{
		if(!(P1IN & IRQ))
		{
			receive(data,1);
			if(data[0] == '1')
			{
				uart_putc(data[0]);
				uart_putc('\n');
			}
		}
	}
	return UCA0RXBUF;
}

void main(void)
{
	int i;
	unsigned char DATA[1];

	Config_stop_WDT(); // stop WDT, see description in Basic_config.c
	Config_Clocks();
	uart_init();
	RF_init();
	P2DIR |= BIT0 + BIT1;
	P2OUT &= ~(BIT0 + BIT1);
	general_config(1);

	unsigned char c;
	while(1)
	{
		P2OUT &= ~(BIT0 + BIT1);
		receive_config_continuous();
		c=uart_get(DATA);
		DATA[0]=c;
		P2OUT |= BIT0;
		transmit_config_continuous();
		transmit_idleRQ(DATA,1,10);

		uart_putc(DATA[0]);
		uart_putc('\n');
		if(start==0)
			start=1;
	}
	/*while(1)
	{
		transmit_config();
		c=uart_get();
		DATA[0]=c;
		transmit(DATA,1);
		P2OUT |= BIT0;

		receive_config(1);
		receive(DATA,1);
		P2OUT &= ~(BIT0 + BIT1);
			uart_putc(DATA[0]);
			uart_putc('\n');
		if(start==0)
			start=1;
		delay_ms(800);
	}*/
}
