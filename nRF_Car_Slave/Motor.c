/*
 * Motor.c
 *
 *  Created on: Nov 11, 2013
 *      Author: Win7-64 SP1
 */
#include <msp430.h>


/********************************DEFINE PINS**********************************/
#define   INA  BIT1  //can not be changed
#define   INB  BIT2
#define   INC  BIT3
#define   IND  BIT4  //can not be changed
/*****************************************************************************/
//
/*******************************DEFINE PORTS**********************************/
#define PWMPORT P2OUT
//
/*****************************************************************************/
//
#define MAXSPEED 1000
//
/**********************************DIRECTION**********************************/
#define  STRAIGHT 0x00
#define  LEFT     0x01
#define  RIGHT    0x02
#define  BACK     0x04
/*****************************************************************************/
//
//*****************************DEFINE MOTOR**********************************/
#define MOTOR1   BIT0
#define MOTOR2   BIT1
/*****************************************************************************/

void Motor_Init()
{
	TA1CTL=TASSEL_2 + MC_1; //SMCLK=1MHz, Up Mode
	TA1CCR0=MAXSPEED;
	//INA chuc nang TA1.1 (P2.1)
		P2DIR |= INA;   //TA1.1 must have DIR=1, SEL=1, SEL2=0
		P2SEL |= INA;   //chuc nang TA1.1
		P2SEL2 &=~INA;

	//IND chuc nang TA1.2 (P2.4)
		P2DIR |= IND;   //TA1.2 must have DIR=1, SEL=1, SEL2=0
		P2SEL |= IND;   //chuc nang TA1.2
		P2SEL2 &=~IND;

	//INB, INC chuc nang OUTPUT thong thuong de chon chieu quay, 1:thuan, 0: nghich
		P2DIR |= INB+INC;   //OUTPUT must have DIR=1, SEL=0, SEL2=0
		P2SEL &=~(INB+INC);
		P2SEL2 &=~(INB+INC);
}

/*Turn direction
 *
 *Note: Speed must be less than MAXSPEED
 */
void Turn(char Direction, unsigned int SpeedLeft, unsigned int SpeedRight)
{
	TA1CCR2=SpeedRight;
	TA1CCR1=SpeedLeft;
	switch (Direction)
	{
		case RIGHT:
			TA1CCTL1=OUTMOD_3;
			TA1CCTL2=OUTMOD_7;
			PWMPORT |=INB;
			PWMPORT &=~INC;
			break;
		case LEFT:
			TA1CCTL1=OUTMOD_7;
			TA1CCTL2=OUTMOD_3;
			PWMPORT &=~INB;
			PWMPORT |=INC;
			break;
		case BACK:
			TA1CCTL1=OUTMOD_3;
			TA1CCTL2=OUTMOD_3;
			PWMPORT |=INB;
			PWMPORT |=INC;
			break;
		default:
			TA1CCTL1=OUTMOD_7;
			TA1CCTL2=OUTMOD_7;
			PWMPORT &=~INB;
			PWMPORT &=~INC;
			break;

	}
}
void EnableMotor(char MOTOR)
{
	if(MOTOR & MOTOR1) //enable motor1
		TA1CCTL1 |=OUTMOD_7;//1-0
	else //disable motor1
	{
		TA1CCTL1 |=OUTMOD_5;//reset mode
		PWMPORT &=~INB;
	}

	if(MOTOR & MOTOR2) //enable motor2
		TA1CCTL2 |=OUTMOD_7;//1-0
	else //disable motor2
	{
		TA1CCTL2 |=OUTMOD_5;//reset mode
		PWMPORT &=~IND;
	}
}



