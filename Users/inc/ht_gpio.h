
#ifndef __HT_GPIO_H__
#define __HT_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif
	
#include "ht_include.h"

void GPIO_Config(HT_GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOOutput_TypeDef GPIO_Output_Mode,GPIOInput_TypeDef GPIO_Input_Mode);
void AF_GPIO_Config(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t GPIO_AFMode, GPIOOutput_TypeDef GPIO_Output_Mode, GPIOInput_TypeDef GPIO_Input_Mode);
void GPIO_Init(void);

	#ifdef __cplusplus
}
#endif

#endif /* __HT_GPIO_H__ */
