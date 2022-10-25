/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EXT_PR__5V_Pin GPIO_PIN_1
#define EXT_PR__5V_GPIO_Port GPIOA
#define SERVO2_M2_Pin GPIO_PIN_8
#define SERVO2_M2_GPIO_Port GPIOE
#define SERVO2_M1_Pin GPIO_PIN_9
#define SERVO2_M1_GPIO_Port GPIOE
#define SERVO1_M4_Pin GPIO_PIN_10
#define SERVO1_M4_GPIO_Port GPIOE
#define SERVO1_M3_Pin GPIO_PIN_11
#define SERVO1_M3_GPIO_Port GPIOE
#define SERVO1_M2_Pin GPIO_PIN_12
#define SERVO1_M2_GPIO_Port GPIOE
#define SERVO1_M1_Pin GPIO_PIN_13
#define SERVO1_M1_GPIO_Port GPIOE
#define SERVO2SPARE1_Pin GPIO_PIN_14
#define SERVO2SPARE1_GPIO_Port GPIOE
#define SAUCEPUMP3_Pin GPIO_PIN_15
#define SAUCEPUMP3_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
