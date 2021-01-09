/**
  ******************************************************************************
  * File Name          : USART.c
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "stdio.h"
#include "string.h"
#include "ds3231.h"
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA1_Channel5;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1_TX Init */
    hdma_usart1_tx.Instance = DMA1_Channel4;
    hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart1_tx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
	return 1;
}

uint8_t Uart_Recv1_Buf[Uart_Max_Length] = {0};
uint16_t Uart_Recv1_Length = 0;
uint8_t Uart_Overflow1_Flag = 0;

DIS_CMD dis_cmd = {1,0,0,5,"               "};
void AnalysisCommand(uint8_t *Buf)
{
	int i;
	if(Buf[0] == 0xFF &&Buf[1] == 0x55)
	{
		dis_cmd.speed = (Buf[2]&0xF0)>>4;
		dis_cmd.motiontype = (Buf[2]&0xF);
		dis_cmd.fonttype = (Buf[3]&0xF0)>>4;
		dis_cmd.single = (Buf[3]&0xF);
		dis_cmd.rand = 0;
		for(i=0;i<Buf[4];i++) dis_cmd.displaystr[i] = Buf[i + 5];
	}
	else if(Buf[0] == 0xEE &&Buf[1] == 0x55)
	{
		dis_cmd.rand = 1;
	}
}
char Device_Name[20] = "HDSP2072\0\0\0\0\0\0";

#define MAKEWORD(low, high)		(((uint8_t)(low)) | (((uint8_t)(high)) << 8))
uint8_t ReponseID[40]={0xFF,0x55,'O','K'};

int cont_str(char *s)
{
	int i = 0;      
	while ( s[++i] != '\0')   ;
	return i;
} 
DEVICE_MSG Device_Msg;
void AnalysisComputermsg(uint8_t *Buf)
{
//	static uint8_t Timefix = 0;
	int i;
	if(Buf[0] == 0xFF &&Buf[1] == 0x55)
	{
		if(Buf[4] == 0x2)
		{
			switch (MAKEWORD(Buf[3], Buf[2]))
			{
			case CPU_Temp:
				Device_Msg.cputemp = MAKEWORD(Buf[6],Buf[5]);
				break;
			case CPU_Clock:
				Device_Msg.cpuclock = MAKEWORD(Buf[6],Buf[5]);
				break;
			case CPU_Load:
				Device_Msg.cpuload = MAKEWORD(Buf[6],Buf[5]);
				break;
			case CPU_Fan:
				Device_Msg.cpufan = MAKEWORD(Buf[6],Buf[5]);
				break;
			case CPU_POWER:
				Device_Msg.cpupower = MAKEWORD(Buf[6],Buf[5]);
				break;

			case GPU_Temp:
				Device_Msg.gputemp = MAKEWORD(Buf[6],Buf[5]);
				break;
			case GPU_Clock:
				Device_Msg.gpuclock = MAKEWORD(Buf[6],Buf[5]);
				break;
			case GPU_Load:
				Device_Msg.gpuload = MAKEWORD(Buf[6],Buf[5]);
				break;
			case GPU_Fan:
				Device_Msg.gpufan = MAKEWORD(Buf[6],Buf[5]);
				break;


			case Main_Temp:
				Device_Msg.maintemp = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Main_Fan:
				Device_Msg.mainfan = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Main_Vol:
				Device_Msg.mainvoltage = MAKEWORD(Buf[6],Buf[5]);
				break;

			case RAM_Load:
				Device_Msg.ramload = MAKEWORD(Buf[6],Buf[5]);
				break;
			case RAM_Data:
				Device_Msg.ramusrdata = MAKEWORD(Buf[6],Buf[5]);
				break;

			case HDD_Load:
				Device_Msg.hddload = MAKEWORD(Buf[6],Buf[5]);
				break;
			case HDD_Temp:
				Device_Msg.hddtemp = MAKEWORD(Buf[6],Buf[5]);
				break;

			case Uart_Year:
				Device_Msg.uartyear = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Month:
				Device_Msg.uartmonth = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Day:
				Device_Msg.uartday = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Week:
				Device_Msg.uartweek = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Hour:
				Device_Msg.uarthour = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Minute:
				Device_Msg.uartminute = MAKEWORD(Buf[6],Buf[5]);
				break;
			case Uart_Second:
				Device_Msg.uartsecond = MAKEWORD(Buf[6],Buf[5]);
				DS3231_SetUart();
				break;
			case End_Frame_ADDR:
				if(MAKEWORD(Buf[6],Buf[5]) == 0x5A5A)
				{
					Uart_Overflow1_Flag = 1;
				}break;
			case 0x3F3F:
//				STMFLASH_Read(FLASH_NAME_ADDR,(uint16_t*)Device_Name,20);
				ReponseID[2] = (Buf[5] & 0x5A) | (Buf[6] & 0xA5);
				ReponseID[3] = (Buf[5] ^ 0x57) | (Buf[6] & 0x57);
				ReponseID[4] = cont_str(Device_Name);
				for(i=0;i<ReponseID[4];i++)
					ReponseID[5+i] = Device_Name[i];
				HAL_UART_Transmit(&huart1,ReponseID,ReponseID[4]+5,0xffff);

				break;
			}
		}
	}
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
