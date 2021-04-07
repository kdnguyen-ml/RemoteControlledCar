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
 *    Module       : NRF24L01.H
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
 *      To apply these functions, you must include this header file and add
 *      the NRF24L01.c file to your project.
 *
 *      For hardware connecting, see "PINS MAPPING" in NRF24L01.c.
 *
 *      These functions use normally communication through pins to retrieve or send
 *      info to nRF24L01. NOT using ACK and check pipe or error
 *
******************************************************************************/
#include <msp430g2553.h>

#ifndef NRF24L01_H_
#define NRF24L01_H_

/****************************************************************************
 * USER DEFINITIONS
******************************************************************************/

/* Memory Map */
#define CONFIG 			0x00
#define EN_AA 			0x01
#define EN_RXADDR 		0x02
#define SETUP_AW 		0x03
#define SETUP_RETR 		0x04
#define RF_CH 			0x05
#define RF_SETUP 		0x06
#define STATUS 			0x07
#define OBSERVE_TX 		0x08
#define CD 				0x09
#define RX_ADDR_P0 		0x0A
#define RX_ADDR_P1 		0x0B
#define RX_ADDR_P2 		0x0C
#define RX_ADDR_P3 		0x0D
#define RX_ADDR_P4		0x0E
#define RX_ADDR_P5 		0x0F
#define TX_ADDR 		0x10
#define RX_PW_P0 		0x11
#define RX_PW_P1 		0x12
#define RX_PW_P2 		0x13
#define RX_PW_P3 		0x14
#define RX_PW_P4 		0x15
#define RX_PW_P5 		0x16
#define FIFO_STATUS 	0x17
#define DYNPD 			0x1C
#define FEATURE 		0x1D

/* Bit Mnemonics */
#define MASK_RX_DR BIT6
#define MASK_TX_DS BIT5
#define MASK_MAX_RT BIT4
#define EN_CRC BIT3
#define CRCO BIT2
#define PWR_UP BIT1
#define PRIM_RX BIT0
#define ENAA_P5 BIT5
#define ENAA_P4 BIT4
#define ENAA_P3 BIT3
#define ENAA_P2 BIT2
#define ENAA_P1 BIT1
#define ENAA_P0 BIT0
#define ERX_P5 BIT5
#define ERX_P4 BIT4
#define ERX_P3 BIT3
#define ERX_P2 BIT2
#define ERX_P1 BIT1
#define ERX_P0 BIT0
#define AW 	BIT0
#define ARD BIT4
#define ARC BIT0
#define PLL_LOCK BIT4
#define RF_DR BIT3
#define RF_PWR BIT6
#define RX_DR BIT6
#define TX_DS BIT5
#define MAX_RT BIT4
#define RX_P_NO BIT1
#define TX_FULL BIT0
#define PLOS_CNT BIT4
#define ARC_CNT BIT0
#define TX_REUSE BIT6
#define FIFO_FULL BIT5
#define TX_EMPTY BIT4
#define RX_FULL BIT1
#define RX_EMPTY BIT0
#define DPL_P5 BIT5
#define DPL_P4 BIT4
#define DPL_P3 BIT3
#define DPL_P2 BIT2
#define DPL_P1 BIT1
#define DPL_P0 BIT0
#define EN_DPL BIT2
#define EN_ACK_PAY BIT1
#define EN_DYN_ACK BIT0

/* Instruction Mnemonics */
#define R_REGISTER 		0x00
#define W_REGISTER 		0x20
#define REGISTER_MASK 	0x1F
#define ACTIVATE 		0x50
#define R_RX_PL_WID 	0x60
#define R_RX_PAYLOAD 	0x61
#define W_TX_PAYLOAD	0xA0
#define W_ACK_PAYLOAD 	0xA8
#define FLUSH_TX 		0xE1
#define FLUSH_RX 		0xE2
#define REUSE_TX_PL		0xE3
#define NOP 			0xFF

/* Non-P omissions */
#define LNA_HCURR BIT0

/* P model memory Map */
#define RPD 0x09

/* P model bit Mnemonics */
#define RF_DR_LOW BIT5
#define RF_DR_HIGH BIT3
#define RF_PWR_LOW BIT1
#define RF_PWR_HIGH BIT2

/****************************************************************************
* FUNCTIONS 'S PROTOTYPES
******************************************************************************/
// For further description, see nRF24L01.c
void RF_init(void);
void send_byte(unsigned char data);
void send_command (unsigned char command);
void send_data(unsigned char *data, unsigned int numbyte);
unsigned char read_data(unsigned int numbyte);

void transmit_config(void);
void transmit(unsigned char *data, unsigned int length);	//length MUST equal receive_numbyte
void receive_config(unsigned int receive_numbyte);
void receive(unsigned char *data, unsigned int length);

void general_config(unsigned int receive_numbyte);
void transmit_config_continuous(void);
void receive_config_continuous();
void transmit_idleRQ(unsigned char *data, unsigned int length, int timeout_ms);
void receive_ACKencorder(unsigned char *data, unsigned int length, int ACK_ms);
/*****************************************************************************
 Create pulse
*****************************************************************************/
void CSN_HIGH ();
void CSN_LOW ();
void CE_HIGH();
void CE_LOW();
void clock_up();
void clock_down();
#endif /* NRF24L01_H_ */

/******************************************************************************
 * END OF standard NRF24L01.H
*******************************************************************************/
