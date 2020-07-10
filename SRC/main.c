/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

const unsigned char VFD_Fonts[][91*5]=
{
{0x00,0x00,0x00,0x00,0x00,/*" ",0*/

0x00,0x00,0x5F,0x00,0x00,/*"!",1*/

0x01,0x00,0x00,0x01,0x00,/*""",2*/

0x7C,0x17,0x14,0x7C,0x17,/*"#",3*/

0x22,0x45,0x7F,0x4B,0x32,/*"$",4*/

0x49,0x37,0x0C,0x72,0x49,/*"%",5*/

0x4F,0x59,0x67,0x78,0x48,/*"&",6*/

0x00,0x01,0x00,0x00,0x00,/*"'",7*/

0x00,0x00,0x3E,0x41,0x00,/*"(",8*/

0x00,0x61,0x1E,0x00,0x00,/*")",9*/

0x14,0x0C,0x3E,0x0C,0x14,/*"*",10*/

0x08,0x08,0x3E,0x08,0x08,/*"+",11*/

0x40,0x40,0x00,0x00,0x00,/*",",12*/

0x08,0x08,0x08,0x08,0x08,/*"-",13*/

0x40,0x40,0x00,0x00,0x00,/*".",14*/

0x40,0x30,0x08,0x06,0x01,/*"/",15*/

0x3E,0x51,0x49,0x45,0x3E,/*"0",16*/

0x00,0x00,0x02,0x7F,0x00,/*"1",17*/

0x42,0x61,0x51,0x49,0x46,/*"2",18*/

0x21,0x41,0x45,0x4B,0x31,/*"3",19*/

0x18,0x14,0x12,0x7F,0x10,/*"4",20*/

0x2F,0x45,0x45,0x45,0x39,/*"5",21*/

0x3E,0x49,0x49,0x49,0x31,/*"6",22*/

0x01,0x01,0x79,0x05,0x03,/*"7",23*/

0x36,0x49,0x49,0x49,0x36,/*"8",24*/

0x26,0x49,0x49,0x49,0x3E,/*"9",25*/

0x00,0x00,0x24,0x00,0x00,/*":",26*/

0x00,0x00,0x44,0x00,0x00,/*";",27*/

0x08,0x14,0x22,0x22,0x41,/*"<",28*/

0x14,0x14,0x14,0x14,0x14,/*"=",29*/

0x41,0x22,0x22,0x14,0x08,/*">",30*/

0x07,0x01,0x51,0x09,0x07,/*"?",31*/

0x3E,0x5D,0x63,0x5F,0x61,/*"@",32*/

0x60,0x1C,0x13,0x1C,0x60,/*"A",33*/

0x7F,0x49,0x49,0x49,0x76,/*"B",34*/

0x3f,0x41,0x41,0x41,0x22,/*"C",35*/

0x7F,0x41,0x41,0x41,0x3E,/*"D",36*/

0x7F,0x49,0x49,0x49,0x41,/*"E",37*/

0x7F,0x09,0x09,0x09,0x01,/*"F",38*/

0x3E,0x41,0x41,0x51,0x32,/*"G",39*/

0x7F,0x08,0x08,0x08,0x7F,/*"H",40*/

0x00,0x41,0x7F,0x41,0x00,/*"I",41*/

0x20,0x40,0x41,0x3F,0x01,/*"J",42*/

0x7F,0x08,0x0C,0x32,0x41,/*"K",43*/

0x7F,0x40,0x40,0x40,0x40,/*"L",44*/

0x7F,0x0C,0x30,0x0C,0x7F,/*"M",45*/

0x7F,0x02,0x0C,0x10,0x7F,/*"N",46*/

0x3E,0x41,0x41,0x41,0x3E,/*"O",47*/

0x7F,0x09,0x09,0x09,0x06,/*"P",48*/

0x3E,0x41,0x41,0x61,0x7E,/*"Q",49*/

0x7F,0x09,0x09,0x39,0x46,/*"R",50*/

0x46,0x49,0x49,0x49,0x31,/*"S",51*/

0x01,0x01,0x7F,0x01,0x01,/*"T",52*/

0x3F,0x40,0x40,0x40,0x3F,/*"U",53*/

0x03,0x1C,0x60,0x1C,0x03,/*"V",54*/

0x1F,0x60,0x1F,0x60,0x1F,/*"W",55*/

0x41,0x36,0x08,0x36,0x41,/*"X",56*/

0x03,0x04,0x78,0x04,0x03,/*"Y",57*/

0x61,0x51,0x49,0x45,0x43,/*"Z",58*/

0x00,0x00,0x7F,0x00,0x00,/*"[",59*/

0x01,0x06,0x08,0x30,0x40,/*"\",60*/

0x00,0x00,0x7F,0x00,0x00,/*"]",61*/

0x00,0x00,0x00,0x00,0x00,/*"^",62*/

0x08,0x08,0x08,0x08,0x08,/*"-",63*/

0x00,0x01,0x00,0x00,0x00,/*"'",64*/

0x68,0x54,0x54,0x54,0x78,/*"a",65*/

0x7F,0x48,0x44,0x44,0x38,/*"b",66*/

0x38,0x44,0x44,0x44,0x48,/*"c",67*/

0x38,0x44,0x44,0x44,0x7F,/*"d",68*/

0x38,0x54,0x54,0x54,0x18,/*"e",69*/

0x04,0x7E,0x45,0x05,0x05,/*"f",70*/

0x78,0x24,0x24,0x54,0x48,/*"g",71*/

0x7F,0x04,0x04,0x04,0x78,/*"h",72*/

0x04,0x44,0x7D,0x40,0x00,/*"i",73*/

0x00,0x00,0x04,0x05,0x79,/*"j",74*/

0x7F,0x10,0x10,0x2C,0x44,/*"k",75*/

0x00,0x41,0x7F,0x40,0x00,/*"l",76*/

0x78,0x04,0x7C,0x04,0x04,/*"m",77*/

0x7C,0x08,0x04,0x04,0x78,/*"n",78*/

0x38,0x44,0x44,0x44,0x38,/*"o",79*/

0x7C,0x44,0x44,0x44,0x38,/*"p",80*/

0x38,0x44,0x44,0x44,0x7C,/*"q",81*/

0x44,0x7C,0x08,0x04,0x04,/*"r",82*/

0x68,0x54,0x54,0x54,0x6C,/*"s",83*/

0x04,0x3C,0x44,0x44,0x40,/*"t",84*/

0x3C,0x40,0x40,0x44,0x7C,/*"u",85*/

0x0C,0x34,0x40,0x34,0x0C,/*"v",86*/

0x3C,0x60,0x1C,0x60,0x1C,/*"w",87*/

0x44,0x2C,0x10,0x2C,0x44,/*"x",88*/

0x04,0x1C,0x60,0x1C,0x04,/*"y",89*/

0x44,0x64,0x54,0x4C,0x44},/*"z",90*/
{
0x00,0x00,0x00,0x00,0x00,/*" ",0*/

0x00,0x00,0x5F,0x5F,0x00,/*"!",1*/

0x00,0x00,0x01,0x01,0x00,/*""",2*/

0x30,0x3E,0x7E,0x7E,0x10,/*"#",3*/

0x00,0x47,0x7F,0x79,0x00,/*"$",4*/

0x0F,0x3F,0x7F,0x72,0x70,/*"%",5*/

0x36,0x7F,0x7F,0x7A,0x40,/*"&",6*/

0x00,0x01,0x01,0x00,0x00,/*"'",7*/

0x00,0x00,0x7F,0x7F,0x00,/*"(",8*/

0x00,0x77,0x77,0x00,0x00,/*")",9*/

0x14,0x1C,0x1C,0x1C,0x14,/*"*",10*/

0x08,0x08,0x1C,0x1C,0x08,/*"+",11*/

0x00,0x40,0x40,0x00,0x00,/*",",12*/

0x00,0x08,0x08,0x08,0x00,/*"-",13*/

0x00,0x40,0x40,0x00,0x00,/*".",14*/

0x40,0x78,0x3E,0x07,0x01,/*"/",15*/

0x3E,0x7F,0x41,0x41,0x3E,/*"0",16*/

0x00,0x06,0x7F,0x7F,0x00,/*"1",17*/

0x62,0x73,0x79,0x6F,0x66,/*"2",18*/

0x21,0x61,0x4D,0x7F,0x33,/*"3",19*/

0x1C,0x12,0x7F,0x7F,0x10,/*"4",20*/

0x26,0x67,0x45,0x7D,0x38,/*"5",21*/

0x3E,0x7F,0x4D,0x7D,0x38,/*"6",22*/

0x01,0x71,0x7F,0x0F,0x03,/*"7",23*/

0x36,0x7F,0xc9,0x49,0x36,/*"8",24*/

0x0E,0x5B,0x79,0x7F,0x1E,/*"9",25*/

0x00,0x00,0x00,0x00,0x00,/*":",26*/

0x00,0x00,0x44,0x44,0x00,/*";",27*/

0x08,0x1C,0x36,0x22,0x00,/*"<",28*/

0x14,0x14,0x14,0x14,0x14,/*"=",29*/

0x00,0x22,0x36,0x1C,0x08,/*">",30*/

0x02,0x03,0x09,0x0F,0x06,/*"?",31*/

0x3E,0x7F,0x5F,0x7F,0x3E,/*"@",32*/

0x7E,0x7F,0x09,0x09,0x7E,/*"A",33*/

0x7F,0x7F,0x49,0x4F,0x70,/*"B",33*/

0x3E,0x7F,0x41,0x63,0x62,/*"C",35*/

0x7F,0x7F,0x41,0x41,0x3E,/*"D",36*/

0x7F,0x7F,0x49,0x49,0x41,/*"E",37*/

0x7F,0x7F,0x09,0x09,0x01,/*"F",38*/

0x3E,0x7F,0x41,0x53,0x32,/*"G",39*/

0x7F,0x7F,0x08,0x08,0x7F,/*"H",40*/

0x41,0x7F,0x7F,0x41,0x00,/*"I",40*/
	
0x61,0x41,0x7F,0x7F,0x01,/*"J",40*/

0x7F,0x7F,0x1C,0x36,0x63,/*"K",40*/

0x7F,0x7F,0x40,0x40,0x40,/*"L",44*/

0x7F,0x0F,0x3C,0x0F,0x7F,/*"M",45*/

0x7F,0x7F,0x04,0x08,0x7F,/*"N",45*/

0x3E,0x7F,0x41,0x41,0x3E,/*"O",45*/

0x7F,0x7F,0x09,0x0F,0x06,/*"P",48*/

0x3E,0x7F,0x41,0x61,0x7E,/*"Q",45*/

0x7F,0x7F,0x09,0x79,0x4E,/*"R",45*/

0x66,0x6F,0x49,0x79,0x32,/*"S",51*/

0x01,0x7F,0x7F,0x01,0x01,/*"T",52*/

0x3F,0x7F,0x40,0x40,0x3F,/*"U",53*/

0x7F,0x7F,0x30,0x0C,0x03,/*"V",45*/

0x3F,0x78,0x1E,0x78,0x3F,/*"W",45*/
	
0x71,0x19,0x7F,0x4C,0x47,/*"X",45*/
	
0x07,0x0F,0x78,0x0C,0x07,/*"Y",45*/
	
0x63,0x73,0x49,0x45,0x63,/*"Z",45*/

0x00,0x00,0x7F,0x7F,0x00,/*"[",59*/

0x00,0x0E,0x7E,0x70,0x00,/*"\",60*/

0x00,0x00,0x00,0x00,0x00,/*"]",61*/

0x00,0x00,0x00,0x00,0x00,/*"^",62*/

0x08,0x08,0x08,0x08,0x08,/*"-",63*/

0x00,0x01,0x01,0x00,0x00,/*"'",64*/

0x68,0x7C,0x7C,0x7C,0x40,/*"a",65*/

0x3F,0x7F,0x44,0x7C,0x38,/*"b",66*/

0x38,0x7C,0x44,0x44,0x00,/*"c",67*/

0x38,0x7C,0x44,0x7F,0x7F,/*"d",68*/

0x28,0x7C,0x54,0x5C,0x18,/*"e",69*/

0x04,0x7E,0x7F,0x05,0x01,/*"f",70*/

0x78,0x7C,0x7C,0x5C,0x04,/*"g",71*/

0x7F,0x7F,0x44,0x7C,0x78,/*"h",72*/

0x00,0x7C,0x7C,0x00,0x00,/*"i",73*/

0x00,0x00,0x7D,0x7D,0x00,/*"j",74*/

0x6F,0x7F,0x7C,0x6C,0x44,/*"k",75*/

0x00,0x7F,0x7F,0x00,0x00,/*"l",76*/

0x7C,0x7C,0x7C,0x78,0x78,/*"m",77*/

0x7C,0x7C,0x44,0x7C,0x78,/*"n",78*/

0x38,0x7C,0x44,0x7C,0x38,/*"o",79*/

0x3C,0x7C,0x44,0x7C,0x38,/*"p",80*/

0x38,0x7C,0x44,0x7C,0x38,/*"q",81*/

0x04,0x7C,0x7C,0x04,0x00,/*"r",82*/

0x00,0x7C,0x7C,0x54,0x00,/*"s",83*/

0x04,0x7C,0x7C,0x44,0x00,/*"t",84*/

0x3C,0x7C,0x44,0x7C,0x78,/*"u",85*/

0x04,0x3C,0x3C,0x1C,0x04,/*"v",86*/

0x1C,0x3C,0x7C,0x7C,0x14,/*"w",87*/

0x44,0x6C,0x7C,0x7C,0x04,/*"x",88*/

0x04,0x1C,0x7C,0x7C,0x04,/*"y",89*/

0x00,0x74,0x7C,0x4C,0x00,}/*"z",90*/
};

char displaystr[20];

//graphic
unsigned char gram[][5] = 
{
	//第1个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
	
	//第2个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
};
//target
unsigned char tram[][5] = 
{
	//第1个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
	
	//第2个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
};
//before
unsigned char bram[][5] = 
{
	//第1个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
	
	//第2个数码管
	0x00,0x00,0x00,0x00,0x00,//第1个字符
	0x00,0x00,0x00,0x00,0x00,//第2个字符
	0x00,0x00,0x00,0x00,0x00,//第3个字符
	0x00,0x00,0x00,0x00,0x00,//第4个字符
	0x00,0x00,0x00,0x00,0x00,//第5个字符
	0x00,0x00,0x00,0x00,0x00,//第6个字符
	0x00,0x00,0x00,0x00,0x00,//第7个字符
	0x00,0x00,0x00,0x00,0x00,//第8个字符
};

void ChoicePos(int index)
{
	HAL_GPIO_WritePin(GPIOA, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, D5_Pin, GPIO_PIN_RESET);
	switch(index)
	{
		case 0:HAL_GPIO_WritePin(GPIOA, D1_Pin, GPIO_PIN_SET);break;
		case 1:HAL_GPIO_WritePin(GPIOA, D2_Pin, GPIO_PIN_SET);break;
		case 2:HAL_GPIO_WritePin(GPIOA, D3_Pin, GPIO_PIN_SET);break;
		case 3:HAL_GPIO_WritePin(GPIOA, D4_Pin, GPIO_PIN_SET);break;
		case 4:HAL_GPIO_WritePin(GPIOA, D5_Pin, GPIO_PIN_SET);break;
	}
}

unsigned char checkdiff(unsigned char* array1,unsigned char* array2,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(array1[i]!=array2[i])
			return 0;
	}
	return 1;
}

void Animotion(char* ch,int motion,int font)
{
	int i,k,j;
	static int animotionstep[20]={0};
	
	for(k=0;k<5;k++)
		for(i=0;i<8;i++)
			tram[i][k] = VFD_Fonts[font][(ch[i]-' ')*5+k];
	for(k=0;k<8;k++)
	{
		if(checkdiff(gram[k],tram[k],5)==0)
		{
			switch(motion)
			{
				case 0:
				switch(animotionstep[k])
				{
					case 0:for(i=0;i<5;i++) bram[k][i] = gram[k][i];break;
					case 1:gram[k][2] &= ~0x8;break;
					case 2:gram[k][1] &= ~0x8;gram[k][2] &= ~0x1C;gram[k][3] &= ~0x8;break;
					case 3:gram[k][0] &= ~0x8;gram[k][1] &= ~0x1C;gram[k][2] &= ~0x3E;gram[k][3] &= ~0x1C;gram[k][4] &= ~0x8;break;
					case 4:gram[k][0] &= ~0x1C;gram[k][1] &= ~0x3E;gram[k][2] = tram[k][2]&0x8;gram[k][3] &= ~0x3E;gram[k][4] &= ~0x1C;break;
					case 5:gram[k][0] &= ~0x3E;gram[k][1] = tram[k][1]&0x8;gram[k][2] = tram[k][2]&0x1C;gram[k][3] = tram[k][3]&0x8;gram[k][4] &= ~0x3E;break;
					case 6:gram[k][0] = tram[k][0]&0x8;gram[k][1] = tram[k][1]&0x1C;gram[k][2] = tram[k][2]&0x3E;gram[k][3] = tram[k][3]&0x1C;gram[k][4] = tram[k][4]&0x8;break;
					case 7:gram[k][0] = tram[k][0]&0x1C;gram[k][1] = tram[k][1]&0x3E;gram[k][2] = tram[k][2];gram[k][3] = tram[k][3]&0x3E;gram[k][4] = tram[k][4]&0x1C;break;
					case 8:gram[k][0] = tram[k][0]&0x3E;gram[k][1] = tram[k][1];gram[k][2] = tram[k][2];gram[k][3] = tram[k][3];gram[k][4] = tram[k][4]&0x3E;break;
					case 9:for(i=0;i<5;i++) gram[k][i] = tram[k][i];animotionstep[k]=0;break;
					default:animotionstep[k]=0;break;
				}break;
				case 1:
				switch(animotionstep[k])
				{
					case 0:for(i=0;i<5;i++) bram[k][i] = gram[k][i];break;
					case 1:gram[k][4] &= ~0x40;break;
					case 2:gram[k][4] &= ~0x60;gram[k][3] &= ~0x40;break;
					case 3:gram[k][4] &= ~0x70;gram[k][3] &= ~0x60;gram[k][2] &= ~0x40;break;
					case 4:gram[k][4] &= ~0x78;gram[k][3] &= ~0x70;gram[k][2] &= ~0x60;gram[k][1] &= ~0x40;
					gram[k][4] |= tram[k][4]&0x40;break;
					case 5:gram[k][4] &= ~0x7C;gram[k][3] &= ~0x78;gram[k][2] &= ~0x70;gram[k][1] &= ~0x60;gram[k][0] &= ~0x40;
					gram[k][4] |= tram[k][4]&0x60;gram[k][3] |= tram[k][3]&0x40;break;
					case 6:gram[k][4] &= ~0x7E;gram[k][3] &= ~0x7C;gram[k][2] &= ~0x78;gram[k][1] &= ~0x70;gram[k][0] &= ~0x60;
					gram[k][4] |= tram[k][4]&0x70;gram[k][3] |= tram[k][3]&0x60;gram[k][2] |= tram[k][2]&0x40;break;
					case 7:gram[k][3] &= ~0x7E;gram[k][2] &= ~0x7C;gram[k][1] &= ~0x78;gram[k][0] &= ~0x70;
					gram[k][4] = tram[k][4]&0x78;gram[k][3] |= tram[k][3]&0x70;gram[k][2] |= tram[k][2]&0x60;gram[k][1] |= tram[k][1]&0x40;break;
					case 8:gram[k][2] &= ~0x7E;gram[k][1] &= ~0x7C;gram[k][0] &= ~0x78;
					gram[k][4] = tram[k][4]&0x7C;gram[k][3] = tram[k][3]&0x78;gram[k][2] |= tram[k][2]&0x70;gram[k][1] |= tram[k][1]&0x60;gram[k][0] |= tram[k][0]&0x40;break;
					case 9:gram[k][1] &= ~0x7E;gram[k][0] &= ~0x7C;
					gram[k][4] = tram[k][4]&0x7E;gram[k][3] = tram[k][3]&0x7C;gram[k][2] = tram[k][2]&0x78;gram[k][1] |= tram[k][1]&0x70;gram[k][0] |= tram[k][0]&0x60;break;
					case 10:gram[k][0] &= ~0x7E;
					gram[k][4] = tram[k][4];gram[k][3] = tram[k][3]&0x7E;gram[k][2] = tram[k][2]&0x7C;gram[k][1] = tram[k][1]&0x78;gram[k][0] |= tram[k][0]&0x70;break;
					case 11:
					gram[k][4] = tram[k][4];gram[k][3] = tram[k][3];gram[k][2] |= tram[k][2]&0x7E;gram[k][1] |= tram[k][1]&0x7C;gram[k][0] |= tram[k][0]&0x78;break;
					case 12:
					gram[k][4] = tram[k][4];gram[k][3] = tram[k][3];gram[k][2] = tram[k][2];gram[k][1] |= tram[k][1]&0x7E;gram[k][0] |= tram[k][0]&0x7C;break;
					case 13:
					gram[k][4] = tram[k][4];gram[k][3] = tram[k][3];gram[k][2] = tram[k][2];gram[k][1] = tram[k][1];gram[k][0] |= tram[k][0]&0x7E;break;
					case 14:
					gram[k][4] = tram[k][4];gram[k][3] = tram[k][3];gram[k][2] = tram[k][2];gram[k][1] = tram[k][1];gram[k][0] = tram[k][0];break;
					default:animotionstep[k]=0;break;
				}break;
				case 2:
				switch(animotionstep[k])
				{
					case 0:for(i=0;i<5;i++) bram[k][i] = gram[k][i];break;
					case 1:gram[k][0] &= ~0x40;break;
					case 2:gram[k][0] &= ~0x60;gram[k][1] &= ~0x40;break;
					case 3:gram[k][0] &= ~0x70;gram[k][1] &= ~0x60;gram[k][2] &= ~0x40;break;
					case 4:gram[k][0] &= ~0x78;gram[k][1] &= ~0x70;gram[k][2] &= ~0x60;gram[k][3] &= ~0x40;
					gram[k][0] |= tram[k][0]&0x40;break;
					case 5:gram[k][0] &= ~0x7C;gram[k][1] &= ~0x78;gram[k][2] &= ~0x70;gram[k][3] &= ~0x60;gram[k][4] &= ~0x40;
					gram[k][0] |= tram[k][0]&0x60;gram[k][1] |= tram[k][1]&0x40;break;
					case 6:gram[k][0] &= ~0x7E;gram[k][1] &= ~0x7C;gram[k][2] &= ~0x78;gram[k][3] &= ~0x70;gram[k][4] &= ~0x60;
					gram[k][0] |= tram[k][0]&0x70;gram[k][1] |= tram[k][1]&0x60;gram[k][2] |= tram[k][2]&0x40;break;
					case 7:gram[k][1] &= ~0x7E;gram[k][2] &= ~0x7C;gram[k][3] &= ~0x78;gram[k][4] &= ~0x70;
					gram[k][0] = tram[k][0]&0x78;gram[k][1] |= tram[k][1]&0x70;gram[k][2] |= tram[k][2]&0x60;gram[k][3] |= tram[k][3]&0x40;break;
					case 8:gram[k][2] &= ~0x7E;gram[k][3] &= ~0x7C;gram[k][4] &= ~0x78;
					gram[k][0] = tram[k][0]&0x7C;gram[k][1] = tram[k][1]&0x78;gram[k][2] |= tram[k][2]&0x70;gram[k][3] |= tram[k][3]&0x60;gram[k][4] |= tram[k][4]&0x40;break;
					case 9:gram[k][3] &= ~0x7E;gram[k][4] &= ~0x7C;
					gram[k][0] = tram[k][0]&0x7E;gram[k][1] = tram[k][1]&0x7C;gram[k][2] = tram[k][2]&0x78;gram[k][3] |= tram[k][3]&0x70;gram[k][4] |= tram[k][4]&0x60;break;
					case 10:gram[k][4] &= ~0x7E;
					gram[k][0] = tram[k][0];gram[k][1] = tram[k][1]&0x7E;gram[k][2] = tram[k][2]&0x7C;gram[k][3] = tram[k][3]&0x78;gram[k][4] |= tram[k][4]&0x70;break;
					case 11:
					gram[k][0] = tram[k][0];gram[k][1] = tram[k][1];gram[k][2] |= tram[k][2]&0x7E;gram[k][3] |= tram[k][3]&0x7C;gram[k][4] |= tram[k][4]&0x78;break;
					case 12:
					gram[k][0] = tram[k][0];gram[k][1] = tram[k][1];gram[k][2] = tram[k][2];gram[k][3] |= tram[k][3]&0x7E;gram[k][4] |= tram[k][4]&0x7C;break;
					case 13:
					gram[k][0] = tram[k][0];gram[k][1] = tram[k][1];gram[k][2] = tram[k][2];gram[k][3] = tram[k][3];gram[k][4] |= tram[k][4]&0x7E;break;
					case 14:
					gram[k][0] = tram[k][0];gram[k][1] = tram[k][1];gram[k][2] = tram[k][2];gram[k][3] = tram[k][3];gram[k][4] = tram[k][4];break;
					default:animotionstep[k]=0;break;
				}break;
				case 3://从上往下
				for(i=0;i<5;i++) 
				{
					gram[k][i]<<=1;
					gram[k][i]|=(tram[k][i]>>(7-animotionstep[k]))&1;
				}break;
				case 4://从下往上
				for(i=0;i<5;i++) 
				{
					gram[k][i]>>=1;
					gram[k][i]|=(tram[k][i]<<(7-animotionstep[k]))&0x80;
				}break;
				case 5://从右往左
				for(i=0;i<4;i++) 
				{
					gram[k][i]=gram[k][i+1];
				}
				if(animotionstep[k]>0)
					gram[k][4]=tram[k][animotionstep[k]-1];
				else
					gram[k][4]=0;
				break;
				case 6://从左往右
				for(i=4;i>0;i--) 
				{
					gram[k][i]=gram[k][i-1];
				}
				if(animotionstep[k]>0)
					gram[k][0]=tram[k][4-animotionstep[k]+1];
				else
					gram[k][0]=0;
				break;
				case 7://从上往下
				for(i=0;i<5;i++) 
				{
					if(i<=animotionstep[k])
					{
						if(animotionstep[k]-i<=7)
						{
							gram[k][i]<<=1;
							gram[k][i]|=(tram[k][i]>>(7-(animotionstep[k]-i)))&1;
						}
					}
				}break;
				case 8://从下往上
				for(i=0;i<5;i++) 
				{
					if(i<=animotionstep[k])
					{
						if(animotionstep[k]-i<=7)
						{
							gram[k][4-i]<<=1;
							gram[k][4-i]|=(tram[k][4-i]>>(7-(animotionstep[k]-i)))&1;
						}
					}
				}break;
			}
			animotionstep[k]++;
		}
		else
			animotionstep[k] = 0;
	}
}

void RefrashScren(void)
{
	int i,j,k;
	for(k=0;k<5;k++)
	{
		ChoicePos(k);
		HAL_GPIO_WritePin(GPIOA, EN_Pin, GPIO_PIN_RESET);
		for(i=0;i<8;i++) 
		{
			for(j=0;j<7;j++)
			{
				HAL_GPIO_WritePin(GPIOA, CLK_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, DATA_Pin, (gram[7-i][k]>>(6-j))&1);
				HAL_GPIO_WritePin(GPIOA, CLK_Pin, GPIO_PIN_RESET);
			}
		}
		HAL_GPIO_WritePin(GPIOA, EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int runcount=0;
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	sprintf(displaystr," T%06d",runcount/20);
	Animotion(displaystr,7,runcount/200%2);
		
		runcount++;
	RefrashScren();
	RefrashScren();
	RefrashScren();
	RefrashScren();
	RefrashScren();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
