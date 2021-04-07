/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 ******************************************************************************/

/******************************************************************************
 *
 * TI LAUNCH PAD CODING
 *
 ******************************************************************************/

/******************************************************************************
 *
 *    Module       : NRF24L01.C
 *    Description  : This file describes functions that support you to
 *                   communicate with nRF24L01.
 *
 *  Tool           : CCS 5.3
 *  Chip           : MSP430G2553
 *  History        : 18-10-2013
 *  Version        : 1.0
 *
 *  Author         : Nguyen Dinh Khoa (khoanguyen1563@gmail.com)
 *  Notes          :
 *      To apply these functions, you must include the header file NRF24L01.h and
 *      Basic_config.h & Basic_config.c and add this code file to your project.
 *
 *      For hardware connecting, see "PINS MAPPING" below.
 *
 *      These functions use normally communication through pins to retrieve or send
 *      info to nRF24L01. NOT using ACK and check pipe or error
 *
******************************************************************************/

 /****************************************************************************
 * IMPORT
******************************************************************************/
#include <msp430.h>
#include "Basic_config.h"
#include "NRF24L01.h"

/****************************************************************************
 * DECLARATIONS (also PIN Mapping)
******************************************************************************/
//Connect to PORT1
#define MISO BIT0
#define MOSI BIT3
#define CLK BIT4
#define CE BIT5
#define CSN BIT6
#define IRQ BIT7

/*****************************************************************************
 Create pulse
*****************************************************************************/
void CSN_HIGH ()
{ P1OUT |= CSN; }
void CSN_LOW ()
{ P1OUT &= ~CSN; }

void CE_HIGH()
{ P1OUT |= CE; }
void CE_LOW()
{ P1OUT &= ~CE; }

void clock_up()
{ P1OUT &= ~CLK;
  P1OUT |= CLK; }
void clock_down()
{ P1OUT |= CLK;
  P1OUT &= ~CLK; }
/*****************************************************************************
 Send a byte serially to nRF
*****************************************************************************/
void send_byte(unsigned char data)
{
	int i;
	for (i=7;i>=0;i--)//MSBit first
	{
		if (data & (0x01<<i))
			P1OUT |= MOSI;
		else
			P1OUT &= ~MOSI;
		clock_down();
	}
}
/*****************************************************************************
 Send command
*****************************************************************************/
void send_command(unsigned char command)
{
	//Every command MUST be started with a high to low transition on CSN
	CSN_HIGH();
	CSN_LOW();
	send_byte(command);
}
 /****************************************************************************
* MODULE PUPLIC FUNCTIONS:
* void RF_init(void)
* void send_data(unsigned char *data, unsigned int numbyte)
* unsigned char read_data(unsigned int numbyte)
* void receive_config(unsigned int receive_numbyte)
* void transmit_config(void)
* void receive(unsigned char *data, unsigned int length)
* void transmit(unsigned char *data, unsigned int length)
******************************************************************************/
void RF_init()
{
	P1DIR |= CE + MOSI + CLK + CSN;	//output
	P1DIR &= ~(MISO + IRQ);			//input
	P1OUT &= ~(CE + MOSI + CLK);
	P1OUT |= CSN;
}
/*****************************************************************************
 Send data(1byte) numbyte times
 Getting value: numbyte 's also the position of byte you want to read
 (send every bit to get every bit from nRF)
*****************************************************************************/
void send_data(unsigned char *data, unsigned int numbyte)
{
	int i;
	for (i=0;i<numbyte;i++)
		send_byte(*(data+i));
	CSN_HIGH();
}
/*****************************************************************************
 Return byte NO.numbyte of the register
*****************************************************************************/
unsigned char read_data(unsigned int numbyte)
{
	int i,j;
	unsigned char data;
	for (i=0;i<=numbyte;i++)
	{
		for (j=7;j>=0;j--)
		{
			//dummy bit
			clock_up();
			//read
			if (P1IN & MISO)
				data |= (0x01<<j);
			else data &= ~(0x01<<j);
		}
	}
	CSN_HIGH();
	return data;
}
/*****************************************************************************
 Configure Receiver:
*****************************************************************************/
void receive_config(unsigned int receive_numbyte)
{
	CE_LOW();
	//Config reg: IRQ reflect RX_DR, enable CRC, power down, PRIM_RX
	send_command(W_REGISTER + CONFIG);
	send_byte(MASK_TX_DS + MASK_MAX_RT + EN_CRC + PRIM_RX);//0011 1001

	//Disable all auto ack
	send_command(W_REGISTER + EN_AA);
	send_byte(0x00);

	//Enable RX addr: pipe 0,1(default)
	//Addr width: 5 byte(default)

	//RF channel:2.4GHz + 2*0x01MHz
	send_command(W_REGISTER + RF_CH);
	send_byte(0x01);

	//1Mbps,0dBm
	send_command(W_REGISTER + RF_SETUP);
	send_byte(0x07);//0000 0111

	//Number of bytes in RX payload in pipe 0 (1-32 bytes)
	send_command(W_REGISTER + RX_PW_P0);
	send_byte(receive_numbyte);

	//Power up
	send_command(W_REGISTER + CONFIG);
	send_byte(0x0039 + PWR_UP);

	CSN_HIGH();
	delay_ms(2);
	CE_HIGH();
	//delay_us(200);
}
/*****************************************************************************
 Configure Transmitter:
*****************************************************************************/
void transmit_config(void)
{
	CE_LOW();
	//CONFIG:IRQ reflect TX_DR, enable CRC, power down, PRIM_RX=0
	send_command(W_REGISTER + CONFIG);
	send_byte(MASK_RX_DR + MASK_MAX_RT + EN_CRC);//0101 1000

	//addr width=5 bytes
	//disable auto ack
	send_command(W_REGISTER + EN_AA);
	send_byte(0x00);

	//disable retransmit
	send_command(W_REGISTER + SETUP_RETR);
	send_byte(0x00);

	//RF channel:2.4GHz+2*0x01MHz
	send_command(W_REGISTER + RF_CH);
	send_byte(0x01);

	//1Mbps,0dBm
	send_command(W_REGISTER + RF_SETUP);
	send_byte(0x07);//0000 0111
	//transmit addr:default
	CSN_HIGH();
}
/*****************************************************************************
 Receive on air data (pipe stores up to 2 packet), store to *data
 If no data are sent, the function is stuck
*****************************************************************************/
void receive(unsigned char *data, unsigned int length) 	//length MUST = receive_numbyte
{
	int i,j;
	while (P1IN & IRQ);
	CE_LOW();
	//clear RX_DR
	send_command(W_REGISTER + STATUS);
	send_byte(RX_DR + TX_DS + MAX_RT);
	//read payload
	send_command(R_RX_PAYLOAD);
	for (i=0;i<length;i++)	//LSByte first
	{
		*(data+i)=0;
		for (j=7;j>=0;j--)	//MSBit first
		{
			//dummy bit
			clock_up();
			//read
			if (P1IN & MISO)
				*(data+i) |= (0x01<<j);
		}
	}
	//flush RX
	send_command(FLUSH_RX);
	CSN_HIGH();
	CE_HIGH();
}
/*****************************************************************************
 Transmit on air data (pipe stores up to 2 packet), send *data away
*****************************************************************************/
void transmit(unsigned char *data, unsigned int length)		//length MUST = receive_numbyte
{
	CE_LOW();
	do
	{
		//power up
		send_command(W_REGISTER + CONFIG);
		send_byte(MASK_RX_DR + MASK_MAX_RT + EN_CRC + PWR_UP);//0101 1010
		delay_ms(2);
		//flush TX
		send_command(FLUSH_TX);
		//send payload:LSByte first, MSbit first
		send_command(W_TX_PAYLOAD);

		send_data(data,length);
		CE_HIGH();
		delay_us(100);
		CE_LOW();
	}
	while (P1IN & IRQ);
	//clear TX_DS
	send_command(W_REGISTER + STATUS);
	send_byte(RX_DR + TX_DS + MAX_RT);
	//power down
	send_command(W_REGISTER + CONFIG);
	send_byte(MASK_RX_DR + MASK_MAX_RT + EN_CRC);//0101 1000
	CSN_HIGH();
	delay_ms(150);	//wait for receiver retrieving data
}

/******************************************************************************
 ******************************************************************************
 * TRANSMIT AND RECEIVE CONSTANTLY WITH RETRANSMISSION
 ******************************************************************************
 ******************************************************************************/
void general_config(unsigned int receive_numbyte)
{
	CE_LOW();
	//Disable all auto ack
	send_command(W_REGISTER + EN_AA);
	send_byte(0x00);

	//Disable retransmit
	send_command(W_REGISTER + SETUP_RETR);
	send_byte(0x00);

	//Enable RX addr: pipe 0,1(default)
	//Addr width: 5 byte(default)

	//RF channel:2.4GHz + 2*0x01MHz
	send_command(W_REGISTER + RF_CH);
	send_byte(0x01);

	//1Mbps,0dBm
	send_command(W_REGISTER + RF_SETUP);
	send_byte(0x07);//0000 0111

	//Number of bytes in RX payload in pipe 0 (1-32 bytes)
	send_command(W_REGISTER + RX_PW_P0);
	send_byte(receive_numbyte);

	CSN_HIGH();
	delay_ms(2);
	CE_HIGH();
	delay_us(200);
}
/*****************************************************************************
 Configure Receiver:
*****************************************************************************/
void receive_config_continuous()
{
	CE_LOW();
	//Config reg: IRQ reflect RX_DR, enable CRC, power down, PRIM_RX
	send_command(W_REGISTER + CONFIG);
	send_byte(MASK_TX_DS + MASK_MAX_RT + EN_CRC + PRIM_RX);//0011 1001

	//Power up
	send_command(W_REGISTER + CONFIG);
	send_byte(0x0039 + PWR_UP);

	CSN_HIGH();
	delay_ms(2);
	CE_HIGH();
	//delay_us(200);
}
/*****************************************************************************
 Configure Transmitter:
*****************************************************************************/
void transmit_config_continuous(void)
{
	CE_LOW();
	//CONFIG:IRQ reflect TX_DR, enable CRC, power down, PRIM_RX=0
	send_command(W_REGISTER + CONFIG);
	send_byte(MASK_RX_DR + MASK_MAX_RT + EN_CRC);//0101 1000

	CSN_HIGH();
}
/*****************************************************************************
 For Master
 Transmit on air data (pipe stores up to 2 packet), send *data away
 Wait for receiving ACK = exact *data sent
 Retransmit in timeout [ms]
*****************************************************************************/
void transmit_idleRQ(unsigned char *data, unsigned int length, int timeout_ms) 	//length MUST = receive_numbyte
{
	//**********Transmit************
	transmit(data,length);

	//**********Receive************
	receive_config_continuous();
	int count=0;
	while (P1IN & IRQ)
	{
		count++;
		delay_us(1);
		if(count==(timeout_ms*1000))
		{
			transmit_config_continuous();
			transmit(data,length);
			count=0;
			receive_config_continuous();
		}
	}
	receive(data,length);
}

/*****************************************************************************
 For Slave
 Wait for receiving the next *data
 After ACK_ms, send an ACK represent an encoder signal
*****************************************************************************/
void receive_ACKencorder(unsigned char *data, unsigned int length, int ACK_ms) 	//length MUST = receive_numbyte
{
	unsigned char ACK[1]={'1'};
	static int count=0;

	receive_config_continuous();
	while (P1IN & IRQ)
	{
		count++;
		delay_us(1);
		if(count==(ACK_ms*1000))
		{
			transmit_config_continuous();
			transmit(ACK,length);
			count=0;
			receive_config_continuous();
		}
	}
	receive(data,length);
}
/******************************************************************************
 * END OF RF.C
*******************************************************************************/
