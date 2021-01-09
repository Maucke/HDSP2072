/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */

typedef struct
{
	uint8_t fonttype;
	uint8_t motiontype;
	uint8_t single;
	uint8_t speed;
	char displaystr[20];
	uint8_t rand;
} DIS_CMD;
typedef struct
{
	uint16_t cputemp;
	uint16_t cpuclock;
	uint16_t cpuload;
	uint16_t cpufan;
	uint16_t cpupower;

	uint16_t gputemp;
	uint16_t gpuclock;
	uint16_t gpuload;
	uint16_t gpufan;

	uint16_t maintemp;
	uint16_t mainfan;
	uint16_t mainvoltage;

	uint16_t ramload;
	uint16_t ramusrdata;

	uint16_t hddload;
	uint16_t hddtemp;

	uint16_t uartyear;
	uint16_t uartmonth;
	uint16_t uartday;
	uint16_t uartweek;
	uint16_t uarthour;
	uint16_t uartminute;
	uint16_t uartsecond;

	char cpuname[40];
	char gpuname[40];
	char mainname[40];
}DEVICE_MSG;


#define Uart_Max_Length 250
#define Uart_FFT_Length 192
extern uint8_t Uart_Recv1_Buf[];
extern uint8_t Uart_Overflow1_Flag;
extern uint16_t Uart_Recv1_Length;
extern DIS_CMD dis_cmd;
extern DEVICE_MSG Device_Msg;
void AnalysisCommand(uint8_t *Buf);
void AnalysisComputermsg(uint8_t *Buf);

#define CPU_Temp 						0x1
#define CPU_Clock 					0x2
#define CPU_Load 						0x3
#define CPU_Fan 						0x4

#define GPU_Temp 						0x11
#define GPU_Clock 					0x12
#define GPU_Load 						0x13
#define GPU_Fan 						0x14

#define Main_Temp 					0x21
#define Main_Fan 						0x22
#define Main_Vol						0x23

#define RAM_Load 	  				0x31
#define RAM_Data 						0x32

#define HDD_Load 	  				0x41
#define HDD_Temp 						0x42

#define Uart_Year 	 			 	0x201
#define Uart_Month 					0x202
#define Uart_Day 	  				0x203
#define Uart_Week 					0x204
#define Uart_Hour 	  			0x205
#define Uart_Minute 				0x206
#define Uart_Second 	  		0x207
#define CPU_POWER 	  			0x208

#define CPU_NAME 	 		 		0x101
#define GPU_NAME 	 		 		0x102
#define Main_NAME 	 		 	0x103
#define Uart_END	 	  		0x55AA

#define Command_Mode      0x8001
#define Command_Motion    0x8002
#define Command_Style     0x8003
#define Command_Speed     0x8004
#define Command_Brightness 0x8005
#define Command_Set       0x8006
#define Command_RGBMode   0x8007
#define Command_RGBColor  0x8008
#define Command_RGBBrightness 0x8009

#define Command_TOPTHEME 	0x800A
#define Command_LOGOTHEME 0x800B
#define Command_GAMETYPE 0x800C
#define Command_DEVICENAME 0x400A

#define End_Frame_ADDR 0x55AA
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
