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
* File         : ht501x_keyscan.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used keyscan Function.
**********************************************************************************************************
*/

#ifndef __HT511X_KEYSCAN_H__
#define __HT511X_KEYSCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

#if defined USE_KEYSCAN

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

/**
* @brief  KEY PERIPH
*/
#define IS_HT_KEY_PERIPH(PERIPH)        ((PERIPH) == HT_KEY)

/**
* @brief  KEY IF
*/
#define IS_HT_KEY_IF(itflag)            ((itflag) == KEY_KEYIF)

#if defined USE_CMU_KEYCLKCFG	

/**
* @brief HT_RTC_RTCCLKCFG
*/
#define IS_HT_KEY_KEYCLKSEL(KEYCLKSEL) (((KEYCLKSEL)==CMU_KEYCLKCFG_KEYCLKSEL_OSC) || \
                                        ((KEYCLKSEL)==CMU_KEYCLKCFG_KEYCLKSEL_LRC))

/**
* @brief  KEY clock select enumeration definition
*/
typedef enum
{
    KeyClkOsc = CMU_KEYCLKCFG_KEYCLKSEL_OSC,     /*!<Key module clock select OSC       */
    KeyClkLrc = CMU_KEYCLKCFG_KEYCLKSEL_LRC,     /*!<Key module clock select LRC       */
}KEYClkCfg_TypeDef;                              /*!< end of group KEYClkCfg_TypeDef 	 */

#endif

/**
* @brief  KEY Callback ID enumeration definition
*/
typedef enum
{
  KEY_CB_ID             = 0x01U,    	 /*!< KEY Callback ID             */
} KEY_CallbackIDTypeDef;


#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
typedef struct __KEY_InitTypeDef{
	 HT_KEY_TypeDef  *Instance;        								        /*!< KEY registers base address    */
   __IO uint32_t    ErrorCode;        								        /*!< KEY Error code                */
	 void (* KeyCallback)(struct __KEY_InitTypeDef *KEY_InitStruct);            /*!< KEY call back                 */
	
}KEY_InitTypeDef;

/**
* @brief  KEY Callback pointer definition
*/
typedef  void (*pKEY_CallbackTypeDef)(KEY_InitTypeDef *KEY_InitStruct);  /*!< pointer to an KEY callback function */

/**
* @brief  KEY Error Code
*/
#define KEY_ERROR_NONE              0x00000000U   /*!< No error            */
#define KEY_ERROR_INVALID_CALLBACK  0x00000020U   /*!< Invalid Callback error  */

#endif

/*
*********************************************************************************************************
*                                             Global Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
uint32_t HT_KEY_ScanStatusGet(void);
void HT_KEY_ClearScanStatus(void);
ITStatus HT_KEY_ITFlagStatusGet(uint8_t ITFlag);
void HT_KEY_ClearITPendingBit(uint8_t ITFlag);
#if defined USE_CMU_KEYCLKCFG
void HT_KEY_ClkConfig(KEYClkCfg_TypeDef KeyClkSel);
#endif
#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
void HT_KEY_KeyCallback(KEY_InitTypeDef *KEY_InitStruct);
void HT_KEY_Init(HT_KEY_TypeDef *KEYSCANx,KEY_InitTypeDef *KEY_InitStruct);
StatusTypeDef HT_KEY_RegisterCallback(KEY_InitTypeDef *KEY_InitStruct, KEY_CallbackIDTypeDef CallbackID, pKEY_CallbackTypeDef pCallback);
#endif

#endif                                               /* This File Only support HT501x, HT502x and HYT503x */

#ifdef __cplusplus
}
#endif

#endif /* __HT511X_KEYSCAN_H__ */
