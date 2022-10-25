/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    servo_motor_outputs.h
  * @brief   This file contains all the function prototypes for
  *          the servo_motor_outputs.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SERVO_MOTOR_OUTPUTS_H__
#define __SERVO_MOTOR_OUTPUTS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

typedef enum {
	DO_SERVO1_M1,
	DO_SERVO1_M2,
	DO_SERVO1_M3,
	DO_SERVO1_M4,
	DO_SERVO2_M1,
	DO_SERVO2_M2,
	DO_SERVO2_SPARE1,
	DO_SERVO_TOTAL
}ServoOutput_t;

typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}SERVO_Motor_t;

void SERVO_Motor_Init(void);
void SERVO_Motor_Loop(void);

void SERVO_Motor_ON(ServoOutput_t pin);
void SERVO_Motor_OFF(ServoOutput_t pin);

uint8_t SERVO_Motor_CHECK(ServoOutput_t pin);

void SERVO_Motor_All_High(void);
void SERVO_Motor_All_Low(void);

void SERVO_Motor_OneSecondCall(void);

#ifdef __cplusplus
}
#endif
#endif /*__SERVO_MOTOR_OUTPUTS_H__ */

