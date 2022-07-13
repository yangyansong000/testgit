#include "ht_gpio.h"

void GPIO_Config(HT_GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOOutput_TypeDef GPIO_Output_Mode,GPIOInput_TypeDef GPIO_Input_Mode)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode 			= GPIO_Mode;
	GPIO_InitStruct.GPIO_Pin 			= GPIO_Pin;
	GPIO_InitStruct.GPIO_OutputStruct 	= GPIO_Output_Mode;
	GPIO_InitStruct.GPIO_InputStruct 	= GPIO_Input_Mode;
	GPIO_InitStruct.GPIO_InputFilter 	= DISABLE;
	HT_GPIO_Init(GPIOx, &GPIO_InitStruct); 
}

void AF_GPIO_Config(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t GPIO_AFMode, GPIOOutput_TypeDef GPIO_Output_Mode, GPIOInput_TypeDef GPIO_Input_Mode)
{
	GPIO_InitAFTypeDef  GPIO_InitAFStructure;
	GPIO_InitAFStructure.GPIO_AFMode 			= GPIO_AFMode;
	GPIO_InitAFStructure.GPIO_Pin 				= GPIO_Pin;
	GPIO_InitAFStructure.GPIO_OutputStruct	 	= GPIO_Output_Mode;
	GPIO_InitAFStructure.GPIO_InputStruct 		= GPIO_Input_Mode;
	GPIO_InitAFStructure.GPIO_InputFilter 		= DISABLE;
	HT_GPIO_AFInit(GPIOx, &GPIO_InitAFStructure); 
}

void GPIO_Init(void)
{
	GPIO_Config(HT_GPIOE, GPIO_Pin_0, GPIO_Mode_IOOUT, GPIO_Output_PP, GPIO_Input_Floating);
}
