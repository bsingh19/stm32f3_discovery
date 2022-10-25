/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    appTest.c
  * @brief   This file provides code for the configuration
  *          of all used Test App.
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

/* Includes ------------------------------------------------------------------*/
#include <servo_motor_outputs.h>


void AppTest_Init(void)
{
	SERVO_Motor_Init();
}

void AppTest_Loop(void)
{
	SERVO_Motor_Loop();
}

void AppTest_CallEachSecond(void)
{
	SERVO_Motor_OneSecondCall();
}
