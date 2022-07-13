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
* File         : ht6xxx_wdt.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_WDT_H__
#define __HT6XXX_WDT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
*********************************************************************************************************
*                                           Includes
*********************************************************************************************************
*/

#include "stddef.h"
#include "ht6xxx_lib.h"
	
	
/*
*********************************************************************************************************
*                                          Exported constants
*********************************************************************************************************
*/
#define WDT_FREEDOG_DEFAULT 0xAA40U



/*
*********************************************************************************************************
*                                           Exported types
*********************************************************************************************************
*/
#if  defined  USE_WDTCFG_LPOVT
typedef enum
{
    LPOVT_CTR_Dis  = ((uint32_t)WDT_WDTCFG_LPOVT_CTR_S),
    LPOVT_CTR_En   = ((uint32_t)WDT_WDTCFG_LPOVT_CTR_L), 
}LPOVTSet_TypeDef;
#endif

/**
  * @brief  WDT Init structure definition
  */
typedef struct __WDT_InitTypeDef
{
	HT_WDT_TypeDef    *Instance;    /*!< Register base address    */																						
	uint32_t Reload;                /*!< Specifies the WDT counter reload value.
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF */
	double  OveRstTimeMs;         /*!< Specifies the WDT overflow reset time.
                                       This parameter must be a number between Min_Data = 62.5(ms) and Max_Data = 16000(ms)	
									   or must be a number between Min_Data = 8(s) and Max_Data = 2048(s) when under sleep/hold/hold_lp and set bit of LPOVT_CTR(If support)*/
#if  defined  USE_WDTCFG_LPOVT
    LPOVTSet_TypeDef LpovtCtr;
#endif
#ifdef USE_HT_WDT_REGISTER_CALLBACKS
#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
  void (* OveCallback)(struct __WDT_InitTypeDef *WDT_InitStruct);                  /*!< WDT Overflow Interrupt callback */
#endif /* USE_HT_WDT_REGISTER_CALLBACKS */
#endif
} WDT_InitTypeDef; 




#ifdef USE_HT_WDT_REGISTER_CALLBACKS
#if  (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
/**
  * @brief  WDT common Callback ID enumeration definition
  */
typedef enum
{
  WDT_OVEINT_ID          = 0x00U,    /*!< WDT EWI callback ID */
} WDT_CallbackIDTypeDef; 

/**
  * @brief  WDT Callback pointer definition
  */
typedef void (*pWDT_CallbackTypeDef)(WDT_InitTypeDef *hppp);  /*!< pointer to a WDT common callback functions */

#endif /* USE_HT_WDT_REGISTER_CALLBACKS */
#endif

/*
*********************************************************************************************************
*                                          Exported macros
*********************************************************************************************************
*/
#if defined USE_HT_WDT_REGISTER_CALLBACKS
/*******************  Bit definition for WDT_WDTCFG register  ********************/
#define WDT_WDTCFG_INT_RST_Pos        (0U)                                           
#define WDT_WDTCFG_INT_RST_Msk        (0x1UL << WDT_WDTCFG_INT_RST_Pos)                     /*!< 0x00000001 */
#define WDT_WDTCFG_INT_RST            WDT_WDTCFG_INT_RST_Msk                               /*!<Overflow Interrupt Flag */
#endif /* USE_HT_WDT_REGISTER_CALLBACKS */
/*******************  Bit definition for WDT_WDTCLR register  ********************/
#define WDT_WDTCLR_SET_Pos     (0U)                                               
#define WDT_WDTCLR_SET_Msk     (0xFFUL << WDT_WDTCLR_SET_Pos)                          /*!< 0x000000FF */
#define WDT_WDTCLR_SET         WDT_WDTCLR_SET_Msk                                    /*!<Watchdog overflow reset time value update      */
#define WDT_WDTCLR_CLR_Pos     (8U)                                               
#define WDT_WDTCLR_CLR_Msk     (0xAAUL << WDT_WDTCLR_CLR_Pos)                          /*!< 0x0000AA00 */
#define WDT_WDTCLR_CLR         WDT_WDTCLR_CLR_Msk                                    /*!<Watchdog counter reload value update */



#ifdef USE_HT_WDT_REGISTER_CALLBACKS
#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U) 
/** @brief  Check whether the specified WDT interrupt source is enabled or not.
  * @param  __HANDLE__  WDT Handle.
  * @param  __INTERRUPT__  specifies the WDT interrupt source to check.
  * @retval state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HT_WDT_GET_IT_STATUS(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->WDTCFG\
                                                              & (__INTERRUPT__)) == (__INTERRUPT__))																														
/**
  * @}
  */																															
#endif
#endif
/**
  * @}
  */
/*
*********************************************************************************************************
*                                          Exported functions
*********************************************************************************************************
*/
void HT_FreeDog(void);
StatusTypeDef HT_FreeDog_WithPara(WDT_InitTypeDef *WDT_InitStruct);
StatusTypeDef HT_SHModeDogConfigure(FunctionalState NewState);
#if defined USE_HT_WDT_REGISTER_CALLBACKS || defined USE_WDTCFG_LPOVT
StatusTypeDef HT_WDT_Init(WDT_InitTypeDef *WDT_InitStruct);
#endif
#ifdef USE_HT_WDT_REGISTER_CALLBACKS
#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
__weak void HT_WDT_OveCallback(WDT_InitTypeDef *WDT_InitStruct);
StatusTypeDef HT_WDT_RegisterCallback(WDT_InitTypeDef *WDT_InitStruct, WDT_CallbackIDTypeDef CallbackID,
                                            pWDT_CallbackTypeDef pCallback);
static void WDT_InitCallbacksToDefault(WDT_InitTypeDef *WDT_InitStruct);

#endif  /* USE_HT_WDT_REGISTER_CALLBACKS */
#endif


/*
*********************************************************************************************************
*                                          Private constants
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          Private macros
*********************************************************************************************************
*/
#define IS_WDT_ALL_INSTANCE(INSTANCE) ((INSTANCE) == (HT_WDT))

#define WDTDIV                                  (32U)
#define WDT_OVETIMESET_MIN                      (0U)
#define WDT_OVETIMESET_MAX                      (255U) 

#define __HT_WDT_OVERFLOWTIME(SETVALUE)         (uint32_t)(64.0 * 1000.0 * 10.0 * (1 + SETVALUE) * WDTDIV / (LRC_FREQUENCY))
#define WDT_OVETIME_MIN                         (__HT_WDT_OVERFLOWTIME(WDT_OVETIMESET_MIN))
#define WDT_OVETIME_MAX                         (__HT_WDT_OVERFLOWTIME(WDT_OVETIMESET_MAX))
#define IS_WDT_OveRstTimeMs_CORRECT(TIMEMS)     (((TIMEMS) >= (WDT_OVETIME_MIN)) && ((TIMEMS) <= (WDT_OVETIME_MAX)))

#define IS_WDT_RELOAD_ENABLE(ENABLE) ((ENABLE) == (WDT_WDTCLR_CLR >> 8))

#if defined USE_WDTCFG_LPOVT

#define LONG_WDTDIV  (4096U)
#define __HT_WDT_LONG_OVERFLOWTIME(SETVALUE)  (uint32_t)(64.0 * 1000.0 * 10.0 * (1 + SETVALUE) * LONG_WDTDIV / (LRC_FREQUENCY))
#define WDT_LONG_OVETIME_MIN  (__HT_WDT_LONG_OVERFLOWTIME(WDT_OVETIMESET_MIN))
#define WDT_LONG_OVETIME_MAX  (__HT_WDT_LONG_OVERFLOWTIME(WDT_OVETIMESET_MAX))
#define IS_WDT_LongOveRstTimeMs_CORRECT(TIMEMS) (((TIMEMS) >= WDT_LONG_OVETIME_MIN) && ((TIMEMS) <= WDT_LONG_OVETIME_MAX))

#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6xxx_CMU_H__ */
