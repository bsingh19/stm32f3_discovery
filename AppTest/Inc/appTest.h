/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    appTest.h
  * @brief   This file contains all the function prototypes for
  *          the appTest.c file
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
#ifndef __APP_TEST_H__
#define __APP_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"



void AppTest_Init(void);
void AppTest_Loop(void);
void AppTest_CallEachSecond(void);



#ifdef __cplusplus
}
#endif
#endif /*__APP_TEST_H__ */

