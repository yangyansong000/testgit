/*
*********************************************************************************************************
*                                              HT6XXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : HT6xxx_cmu.c
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_WDT_C

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/

#define __HT_WDT_RELOAD_COUNTER(HANDLE)       WRITE_REG((HANDLE)->Instance->WDTCLR, (HANDLE)->Reload)
#define __HT_WDT_OVERFLOWTIME_SET(TIMEMS)     (0xAA00 | (uint8_t)((TIMEMS*(LRC_FREQUENCY)/(64.0 * 1000.0 * WDTDIV))-1))

#if defined USE_WDTCFG_LPOVT 
#define __HT_WDT_LONG_OVERFLOWTIME_SET(TIMEMS) (0xAA00 | (uint8_t)((TIMEMS*(LRC_FREQUENCY)/(64.0 * 1000.0 * LONG_WDTDIV))-1))
#endif

/*
*********************************************************************************************************
*                                          Local Variables
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                          Local Function Declaration
*********************************************************************************************************
*/



/**
*********************************************************************************************************
*                                         FREE DOG
* @brief  Refresh the WDT according to the fixed value
* @param  None
* @retval None
* @note   The WDT overflow reset time is set to about 4 seconds, which can be changed according to actual 
*         requirements. The WDT overflow time is calculated as follows:
*         64ms * (1+WDTCLR[7:0])     
*********************************************************************************************************
*/
void HT_FreeDog(void)
{
#ifdef USE_HT_WDT_REGISTER_CALLBACKS
	  HT_WDT->WDTCFG =  WDT_WDTCFG_RST;                                      
#endif
    HT_WDT->WDTCLR = WDT_FREEDOG_DEFAULT;                                        /*!< Free dog */
}

/**
*********************************************************************************************************
*                                       FREE DOG with FORMAL PARAMETER
* @brief  Refresh the WDT according to the incoming parameters
* @param  WDT_InitStruct  pointer to a WDT_InitTypeDef structure that contains
*         the configuration information for the specified WDT module
* @retval Status
*********************************************************************************************************
*/
StatusTypeDef HT_FreeDog_WithPara(WDT_InitTypeDef *WDT_InitStruct)
{
#ifdef  USE_FULL_ASSERT
	uint8_t bit_clr;
#endif
	/* Prevent unused argument(s) compilation warning */
        
    assert_param(IS_WDT_ALL_INSTANCE(WDT_InitStruct->Instance));         /*!< Check the parameters */
    
#if defined USE_WDTCFG_LPOVT   
    if(WDT_WDTCFG_LPOVT_CTR_L == (WDT_InitStruct->Instance->WDTCFG & WDT_WDTCFG_LPOVT_CTR))   
    {
        assert_param(IS_WDT_LongOveRstTimeMs_CORRECT((uint32_t)(WDT_InitStruct->OveRstTimeMs * 10)));     /*!< Check the parameters */
        WDT_InitStruct->Reload  = __HT_WDT_LONG_OVERFLOWTIME_SET(WDT_InitStruct->OveRstTimeMs);           /*!< config only valid under SLEEP/HOLD/HOLD_LP mode */
    }
    else
    {
        assert_param(IS_WDT_OveRstTimeMs_CORRECT((uint32_t)(WDT_InitStruct->OveRstTimeMs * 10)));         /*!< Check the parameters */
        WDT_InitStruct->Reload  = __HT_WDT_OVERFLOWTIME_SET(WDT_InitStruct->OveRstTimeMs);
    }
#else
    assert_param(IS_WDT_OveRstTimeMs_CORRECT((uint32_t)(WDT_InitStruct->OveRstTimeMs * 10)));         /*!< Check the parameters */
    WDT_InitStruct->Reload  = __HT_WDT_OVERFLOWTIME_SET(WDT_InitStruct->OveRstTimeMs);
#endif  
#ifdef  USE_FULL_ASSERT
    bit_clr = (uint8_t)(WDT_InitStruct->Reload >> 8);
    assert_param(IS_WDT_RELOAD_ENABLE(bit_clr));                         /*!< Check the parameters */
#endif
    __HT_WDT_RELOAD_COUNTER(WDT_InitStruct);                             /*!< Reload WDT counter with value defined in the reload register */

    /* Return function status */
    return OK;
}


/**
*********************************************************************************************************
*                                    WATCHDOG CONFIGURE ON SLEEP/HOLD MODE
* @brief  Config enable or disable the WatchDog in Hold/Sleep mode according to the specified
*         parameters in the NewState and create the associated handle
* @param  NewState  
*          @arg ENABLE: Enable WatchDog
*          @arg DISABLE: Disable WatchDog
* @note   The function involves CLKCTRL0 register configuration, user should guarantee not modify the  
          control bit CMU_CLKCTRL0_WDTEN if user need to configure CLKCTRL0 registers after calling the 
          function.The function only play a role in HT6x1x.
* @retval Status
* 
*********************************************************************************************************
*/
StatusTypeDef HT_SHModeDogConfigure(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {            
#ifdef USE_HT_WDT_REGISTER_CALLBACKS 
        HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_WDTEN, ENABLE);           /*!< Enable WatchDog in Hold/Sleep mode */
#endif
    }
    else
    {   
#ifdef USE_HT_WDT_REGISTER_CALLBACKS 
        HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_WDTEN, DISABLE);          /*!< Disable WatchDog in Hold/Sleep mode */
#endif
    }
		return OK;
}

#if defined USE_HT_WDT_REGISTER_CALLBACKS || defined USE_WDTCFG_LPOVT 

/**
*********************************************************************************************************
*                                         INITIAL WDT MODULE
*
* @brief Initializes the WDT peripheral according to the specified value of
*         macro constants USE_HT_WDT_REGISTER_CALLBACKS, which is defined in ht6xxx_lib.h.

* @param WDT_InitStruct  pointer to a WDT_InitTypeDef structure that contains
*         the configuration information for the specified WDT module
* @retval Status
*
* @note  The function only play a role in HT6x1x.
*********************************************************************************************************
*/
StatusTypeDef HT_WDT_Init(WDT_InitTypeDef *WDT_InitStruct)
{   
#if defined USE_HT_WDT_REGISTER_CALLBACKS    
    
#ifdef  USE_FULL_ASSERT
    uint8_t bit_clr;

    /* Prevent unused argument(s) compilation warning */
    bit_clr = (uint8_t)(WDT_InitStruct->Reload >> 8);
    assert_param(IS_WDT_ALL_INSTANCE(WDT_InitStruct->Instance));         /*!< Check the parameters */
    assert_param(IS_WDT_RELOAD_ENABLE(bit_clr));
#endif
    
    #if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
            HT_WDT->WDTCFG = WDT_WDTCFG_INT;
            WDT_InitCallbacksToDefault(WDT_InitStruct);
    #else
            HT_WDT->WDTCFG = WDT_WDTCFG_RST;  
            
    #endif
#endif

#if defined USE_WDTCFG_LPOVT
    if(LPOVT_CTR_En == WDT_InitStruct->LpovtCtr)
    {
        WDT_InitStruct->Instance->WDTCFG |= WDT_WDTCFG_LPOVT_CTR;
    }
    else
    {
        WDT_InitStruct->Instance->WDTCFG &= ~WDT_WDTCFG_LPOVT_CTR;
    }
#endif    
    
	return OK;
}

#endif



 
#ifdef USE_HT_WDT_REGISTER_CALLBACKS
#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                                         WDT Interrupt Handler
  * @brief  Handle WDT interrupt request.
  * @param  WDT_InitStruct  pointer to a WDT_InitTypeDef structure that contains
  *                the configuration information for the specified WDT module.
  * @note   The function is only for HT6x1x, and only take action when 
            USE_HT_WDT_REGISTER_CALLBACKS is equal to 1 .
  * @retval None
*********************************************************************************************************
  */
void HT_WDT_IRQHandler(WDT_InitTypeDef *WDT_InitStruct)
{
  /* Check if Overflow Interrupt is enable */
  if (__HT_WDT_GET_IT_STATUS(WDT_InitStruct, WDT_WDTCFG_INT) != RESET)
  {
     /* Overflow registered callback */
      WDT_InitStruct->OveCallback(WDT_InitStruct);
  }
}

/**
*********************************************************************************************************
*                                         WDT Overflow Callback
  * @brief  WDT Overflow callback.
  * @param  WDT_InitStruct  pointer to a WDT_InitTypeDef structure that contains
  *                the configuration information for the specified WDT module.
  * @note   The function is only for HT6x1x, and only take action when 
            USE_HT_WDT_REGISTER_CALLBACKS is equal to 1 .
  * @retval None
*********************************************************************************************************
  */
__weak void HT_WDT_OveCallback(WDT_InitTypeDef *WDT_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(WDT_InitStruct);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_WDT_OveCallback could be implemented in the user file
   */
}



/**
*********************************************************************************************************
*                                         WDT Register Callback
  * @brief  Register a User WDT Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param  WDT_InitStruct pointer to a WDT_InitTypeDef structure that contains
  *                the configuration information for the specified WDT module.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be the following values:
  *           @arg @ref WDT_OVEINT_ID Overflow Interrupt Callback ID
  * @param  pCallback pointer to the Callback function
  * @note   The function is only for HT6x1x, and only take action when 
            USE_HT_WDT_REGISTER_CALLBACKS is equal to 1 .
  * @retval status
*********************************************************************************************************
  */
StatusTypeDef HT_WDT_RegisterCallback(WDT_InitTypeDef *WDT_InitStruct, WDT_CallbackIDTypeDef CallbackID,
                                            pWDT_CallbackTypeDef pCallback)
{
  StatusTypeDef status = OK;

  if (pCallback == NULL)
  {
    status = ERROR;
  }
  else
  {
    switch (CallbackID)
    {
      case WDT_OVEINT_ID:
			  WDT_InitStruct->OveCallback = pCallback;
        break;

      default:
        status = ERROR;
        break;
    }
  }

  return status;
}


/**
*********************************************************************************************************
*                                         INITIAL WDT CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: WDT_InitStruct pointer to a WDT_InitTypeDef structure that contains
*                the configuration information for the specified WDT module.
* @note   The function is only for HT6x1x, and only take action when 
            USE_HT_WDT_REGISTER_CALLBACKS is equal to 1 .
* @retval: None
*********************************************************************************************************
*/


static void WDT_InitCallbacksToDefault(WDT_InitTypeDef *WDT_InitStruct)
{
    /* Init the WDT Callback settings */
    WDT_InitStruct->OveCallback = HT_WDT_OveCallback;
}
#endif  /* USE_HT_WDT_REGISTER_CALLBACKS */
#endif

