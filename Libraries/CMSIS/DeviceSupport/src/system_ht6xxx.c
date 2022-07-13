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
* File         : systerm_ht6xxx.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __SYSTEM_HT6XXX_C

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             Local Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)
static void SysTick_InitCallbacksToDefault(SysTick_InitTypeDef *SysTick_InitStruct);
#endif

/**
*********************************************************************************************************
*                                        INITIAL THE SYSTERM
*
* @brief  Setup the microcontroller system
*         Initialize the FPU setting, vector table location and External memory 
*         configuration.
* @param  None
* @retval None
*
*********************************************************************************************************
*/
void SystemInit (void)
{

}

/**
*********************************************************************************************************
*                                        IAR Whether the variable is initialized after power-on
*
* @brief	Only used by the IAR compiler（Modifying the return value determines the initialization option）
*
* @param	None
*
* @retval 	Returning 0 means that RAM is not initialized，returning 1 means that RAM is initialized
*
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )

int __low_level_init(void)
{
    return 1;
}
#endif

#if (USE_HT_SYSTICK_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                                         INITIAL SYSTICK MODULE
*
* @brief: Initializes the SysTick peripheral according to the specified
*         parameters in the SysTick_InitStruct . 
*
* @param: SysTick_InitStruct: pointer to a SysTick_InitTypeDef structure
*   that contains the configuration information for the specified SysTick 
*   module.which consists of severn parameters:
*                               1) Instance       : pointer to SysTick
*                               2) ErrorCode      : error information
*
* @retval: None
*
* @Note: Only when USE_HT_KEY_REGISTER_CALLBACKS == 1U,this function could be called by user.
*********************************************************************************************************
*/
void SysTick_Init(SysTick_Type *SYSTICKx,SysTick_InitTypeDef *SysTick_InitStruct)
{
		/*  assert_param  */
		SysTick_InitCallbacksToDefault(SysTick_InitStruct);
		SysTick_InitStruct->Instance = SYSTICKx;
}

/**
*********************************************************************************************************
*                                         INITIAL SYSTICK CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: SysTick_InitStruct Pointer to a SysTick_InitTypeDef structure that contains
*               the configuration information for the specified SysTick module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SysTick_InitCallbacksToDefault(SysTick_InitTypeDef *SysTick_InitStruct)
{
  /* Init the SysTick Callback settings */
    SysTick_InitStruct->SystickCallback = SysTick_Callback;            /* Legacy weak SysTickCallback            */
}

/**
*********************************************************************************************************
*                                        System tick handler
*
* @brief	System tick handler
*
* @param    None
*
* @retval   None
*
*********************************************************************************************************
*/
void SysTick_IRQHandler(SysTick_InitTypeDef *SysTick_InitStruct)
{
    if(SysTick_InitStruct->SystickCallback !=NULL)
    {
        SysTick_InitStruct->SystickCallback(SysTick_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SysTick CALLBACK
*
* @brief: SysTick callbacks.
*
* @param: SysTick_InitStruct  Pointer to a SysTick_InitTypeDef structure that contains
*                the configuration information for the specified SysTick module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void SysTick_Callback(SysTick_InitTypeDef *SysTick_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(SysTick_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the SysTick_Callback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
* @brief  Register a User SysTick Callback
*         To be used instead of the weak predefined callback
* @param  SysTick_InitStruct SysTick handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref SYSTICK_CB_ID SysTick Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
*********************************************************************************************************
*/
StatusTypeDef SysTick_RegisterCallback(SysTick_InitTypeDef *SysTick_InitStruct, pSysTick_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        SysTick_InitStruct->ErrorCode |= SYSTICK_ERROR_INVALID_CALLBACK;

        status = ERROR;
    }
    else
    {
        SysTick_InitStruct->SystickCallback = pCallback;
    }
    return status;
}
#endif
