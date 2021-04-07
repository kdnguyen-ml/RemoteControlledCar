/*
 * Motor.h
 *
 *  Created on: Nov 11, 2013
 *      Author: Win7-64 SP1
 */

#ifndef MOTOR_H_
#define MOTOR_H_


void Motor_Init();
void Turn(char Direction,unsigned int SpeedLeft,unsigned int SpeedRight);
void EnableMotor(char MOTOR);

#endif /* MOTOR_H_ */
