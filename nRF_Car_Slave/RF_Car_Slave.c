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
 ****************************************************
P1.1 -> CSN
P1.2 -> MOSI
P1.3 -> IRQ
P1.4 -> MISO
P1.5 -> CLK
P1.6 -> CE
 **************************************************** */

#include <msp430g2553.h>
#include "LCD.h"
#include "Basic_config.h"
#include "NRF24L01.h"
#include "Motor.h"
#include "UART.h"

#define  STRAIGHT 0x00
#define  LEFT     0x01
#define  RIGHT    0x02
#define  BACK     0x04
//Connect to PORT1
#define CSN BIT1
#define MOSI BIT2
#define IRQ BIT3
#define MISO BIT4
#define CLK BIT5
#define CE BIT6

void read_bin(unsigned char data)
{
	int i;
	for(i=7;i>=0;i--)
	{
		if (data&(1<<i)) lcd_put_num(1, 0, 0);
			else lcd_put_num(0, 0, 0);
	}
}

void main(void)
{
	int i,j;
	int count=0,start=0;
	unsigned char DATA[1], STORE[1];
	unsigned char ACK[1]={'1'};
	unsigned char NONE[1]={'0'};

	Config_stop_WDT(); // stop WDT, see description in Basic_config.c
	Config_Clocks();
	RF_init();
	Motor_Init();
	P1DIR |= BIT0; //+ BIT3;
	//P1OUT &= ~BIT3;
	general_config(1);
	delay_ms(10);

	Turn(STRAIGHT,0,0);
	while(1)
	{
		P1OUT |= BIT0;
		delay_ms(1);
		count++;
		if(start==0)
		{
			receive_config_continuous();
			start=1;
			receive(DATA,1);
		}
		switch (DATA[0])
	   	{
	   	  case 'W':
	   		  Turn(STRAIGHT,800,730);
	   		  break;
	   	  case 'X':
	   		  Turn(BACK,800,730);
	   		  break;
	   	  case 'A':
	   		  Turn(LEFT,800,800);
	   		  break;
	   	  case 'D':
	   		  Turn(RIGHT,800,800);
	   		  break;
	   	  case 'S':
	   		  Turn(STRAIGHT,0,0);
	   		  break;
	   	  default:
	   		  Turn(STRAIGHT,0,0);
	   		  break;
		}
		transmit_config_continuous();
		delay_ms(150);
		transmit(DATA,1);

		receive_ACKencorder(DATA,1,500);
	}
}
