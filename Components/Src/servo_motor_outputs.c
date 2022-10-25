/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    servo_motor_outputs.c
  * @brief   This file provides code for the configuration
  *          of all used Servo Motor Outputs pins.
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
#include "gpio.h"
#include "cmsis_os.h"


// DEFINES
#define DI_DEBAUNCE_DELAY_MS 30

#define DO_ON(byte, nbit)	((byte) |=  (1<<(nbit)))	// DO - Digital Output
#define DO_OFF(byte, nbit)	((byte) &= ~(1<<(nbit)))
#define DO_CHECK(byte,nbit) ((byte) &   (1<<(nbit)))

/*
 * Goal:
 * Mustered Pump 1 is OFF (Line - LOW)
 *
 * We have turn it ON when any Micro-Switch turns ON
 *
 */


// GLOBLAS
static uint16_t DO_SERVO_GDT = 0; // Digital Output - Global Data Table

static SERVO_Motor_t servo_motor_output_array[DO_SERVO_TOTAL] = {
		{.GPIOx = SERVO1_M1_GPIO_Port, 		.GPIO_Pin = SERVO1_M1_Pin},		// SERVO1_M1
		{.GPIOx = SERVO1_M2_GPIO_Port, 		.GPIO_Pin = SERVO1_M2_Pin},		// SERVO1_M2
		{.GPIOx = SERVO1_M3_GPIO_Port, 		.GPIO_Pin = SERVO1_M3_Pin},		// SERVO1_M3
		{.GPIOx = SERVO1_M4_GPIO_Port, 		.GPIO_Pin = SERVO1_M4_Pin},		// SERVO1_M4
		{.GPIOx = SERVO2_M1_GPIO_Port, 		.GPIO_Pin = SERVO2_M1_Pin},		// SERVO2_M1
		{.GPIOx = SERVO2_M2_GPIO_Port, 		.GPIO_Pin = SERVO2_M2_Pin},		// SERVO2_M1
		{.GPIOx = SERVO2SPARE1_GPIO_Port, 	.GPIO_Pin = SERVO2SPARE1_Pin}	// SERVO2SPARE1
};

static volatile uint8_t is_timout = 0;


// FUNCTIONS PROTOTYPE
static void _servo_outputs_refresh_all(void);
static void _165_inputs_scan(void);
static uint8_t _inputs_read_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState *status);


// FUNCTIONS
void SERVO_Motor_Init(void)
{
	for(int i=0; i<DO_SERVO_TOTAL; i++)
	{
		DO_OFF(DO_SERVO_GDT, i);
	}
}

void SERVO_Motor_Loop(void)
{
	static uint8_t TikTok = 0;

	_servo_outputs_refresh_all();

	if(is_timout && !TikTok)
	{
		is_timout = 0;
		TikTok = 1;
		SERVO_Motor_All_High();
	}
	else if(is_timout && TikTok)
	{
		is_timout = 0;
		TikTok = 0;
		SERVO_Motor_All_Low();
	}

	_165_inputs_scan();
}

void SERVO_Motor_OneSecondCall(void)
{
	is_timout = 1;
}

void SERVO_Motor_ON(ServoOutput_t pin)
{
	DO_ON(DO_SERVO_GDT, pin);
}

void SERVO_Motor_OFF(ServoOutput_t pin)
{
	DO_OFF(DO_SERVO_GDT, pin);
}

uint8_t SERVO_Motor_CHECK(ServoOutput_t pin)
{
	return DO_CHECK(DO_SERVO_GDT, pin);
}

void SERVO_Motor_All_High(void)
{
	for(int i=0; i<DO_SERVO_TOTAL; i++)
	{
		DO_ON(DO_SERVO_GDT, i);
	}
}

void SERVO_Motor_All_Low(void)
{
	for(int i=0; i<DO_SERVO_TOTAL; i++)
	{
		DO_OFF(DO_SERVO_GDT, i);
	}
}

static void _servo_outputs_refresh_all(void)
{

	for(int i=0; i<DO_SERVO_TOTAL; i++)
	{
		HAL_GPIO_WritePin(servo_motor_output_array[i].GPIOx, servo_motor_output_array[i].GPIO_Pin, DO_CHECK(DO_SERVO_GDT, i));
	}
}

static void _165_inputs_scan(void)
{
	GPIO_PinState status;

	if( _inputs_read_pin(EXT_PR__5V_GPIO_Port, EXT_PR__5V_Pin, &status) == 0 )
	{
		// If pin 160 Low
		if(status == GPIO_PIN_RESET)
		{
			// pin 165 goes High
			HAL_GPIO_WritePin(SAUCEPUMP3_GPIO_Port, SAUCEPUMP3_Pin, GPIO_PIN_SET);
		}
		else
		{
			// pin 165 goes low
			HAL_GPIO_WritePin(SAUCEPUMP3_GPIO_Port, SAUCEPUMP3_Pin, GPIO_PIN_RESET);
		}
	}
}

static uint8_t _inputs_read_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState *status)
{
	GPIO_PinState status1 = GPIO_PIN_RESET;
	GPIO_PinState status2 = GPIO_PIN_RESET;

	if(GPIOx != NULL && status != NULL)
	{
		status1 = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

		osDelay(DI_DEBAUNCE_DELAY_MS);

		status2 = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

		if( status1 == status2 )
		{
			*status = status1;
			return 0;
		}
	}

	return 1;
}

