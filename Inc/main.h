/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define D1_1_Pin GPIO_PIN_0
#define D1_1_GPIO_Port GPIOA
#define D3_1_Pin GPIO_PIN_1
#define D3_1_GPIO_Port GPIOA
#define D5_1_Pin GPIO_PIN_2
#define D5_1_GPIO_Port GPIOA
#define DSSDA_Pin GPIO_PIN_3
#define DSSDA_GPIO_Port GPIOA
#define DSSCL_Pin GPIO_PIN_4
#define DSSCL_GPIO_Port GPIOA
#define DAT1_Pin GPIO_PIN_5
#define DAT1_GPIO_Port GPIOA
#define D2_2_Pin GPIO_PIN_6
#define D2_2_GPIO_Port GPIOA
#define D4_2_Pin GPIO_PIN_7
#define D4_2_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_0
#define EN1_GPIO_Port GPIOB
#define D4_1_Pin GPIO_PIN_1
#define D4_1_GPIO_Port GPIOB
#define D2_1_Pin GPIO_PIN_2
#define D2_1_GPIO_Port GPIOB
#define DAT2_Pin GPIO_PIN_11
#define DAT2_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_12
#define EN2_GPIO_Port GPIOA
#define D1_2_Pin GPIO_PIN_3
#define D1_2_GPIO_Port GPIOB
#define CLK2_Pin GPIO_PIN_4
#define CLK2_GPIO_Port GPIOB
#define D5_2_Pin GPIO_PIN_5
#define D5_2_GPIO_Port GPIOB
#define D3_2_Pin GPIO_PIN_6
#define D3_2_GPIO_Port GPIOB
#define CLK1_Pin GPIO_PIN_7
#define CLK1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
