/*
*********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : systerm_ht6xxx.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
*********************************************************************************************************
*/

#ifndef __SYSTERM_HT6XXX_H
#define __SYSTERM_HT6XXX_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)

/** @defgroup TICK_FREQ Tick Frequency
* @{
*/
typedef enum
{
  TICK_FREQ_1HZ          = 1000U,
  TICK_FREQ_10HZ         = 100U,
  TICK_FREQ_100HZ        = 10U,
  TICK_FREQ_1KHZ         = 1U,
  TICK_FREQ_DEFAULT      = TICK_FREQ_1KHZ
} TickFreqTypeDef;

/**
* @brief  SYSTICK Error Code
*/
#define SYSTICK_ERROR_NONE              0x00000000U   /*!< No error            */
#define SYSTICK_ERROR_INVALID_CALLBACK  0x00000001U   /*!< Invalid Callback error  */

typedef struct __SysTick_InitTypeDef
{
    SysTick_Type  *Instance;        				  /*!< SysTick registers base address    */
	__IO uint32_t ErrorCode;        			      /*!< SysTick Error code                    */
	void (* SystickCallback)(struct __SysTick_InitTypeDef *Systick_InitStruct);
}SysTick_InitTypeDef;                               /*!< end of group SysTick_InitTypeDef        */

/**
* @brief  SysTick Callback pointer definition
*/
typedef  void (*pSysTick_CallbackTypeDef)(SysTick_InitTypeDef *SysTick_InitStruct);  /*!< pointer to an SysTick callback function */

#endif	/* USE_HT_SYSTICK_REGISTER_CALLBACKS	*/

/*
*********************************************************************************************************
*                                             Global Variables
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                            Global Function Declaration
*********************************************************************************************************
*/

void SystemInit(void);                 /*!< microcontroller system Initialize       */

#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)
void SysTick_Init(SysTick_Type *SYSTICKx,SysTick_InitTypeDef *SysTick_InitStruct);
void SysTick_Callback(SysTick_InitTypeDef *SysTick_InitStruct);
StatusTypeDef SysTick_RegisterCallback(SysTick_InitTypeDef *SysTick_InitStruct, pSysTick_CallbackTypeDef pCallback);
#endif	/* USE_HT_SYSTICK_REGISTER_CALLBACKS	*/


#ifdef __cplusplus
}
#endif

#endif  /* __SYSTERM_HT60XX_H */
