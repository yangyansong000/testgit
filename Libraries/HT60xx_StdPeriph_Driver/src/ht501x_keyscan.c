/*
*********************************************************************************************************
*                                              HT6XXXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht501x_keyscan.c
* By           : Hitrendtech_SD
* Version      : V2.0.5
* Description  : Only support for chips used keyscan Function.
*********************************************************************************************************
*/

#define  __HT511X_KEYSCAN_C

#include "ht6xxx_lib.h"



#if defined USE_KEYSCAN

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
#if defined USE_CMU_KEYCLKCFG
static const uint32_t RegisterWriteProtect[2]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};
#endif


/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
static void KEY_InitCallbacksToDefault(KEY_InitTypeDef *KEY_InitStruct);
static void KEY_PRESS_IT(KEY_InitTypeDef *KEY_InitStruct);
#endif


#if defined USE_CMU_KEYCLKCFG
/**
*********************************************************************************************************
*                                   GET KEY SCAN STATUS
*
* @brief: Gets the KEY scan status
*
* @param: None
*
* @retval: KEYSTA   ：KEY scan status
*
* @Note: None
*********************************************************************************************************
*/
void HT_KEY_ClkConfig(KEYClkCfg_TypeDef KeyClkSel)
{
    /*  assert_param  */
	assert_param(IS_HT_KEY_KEYCLKSEL(KeyClkSel));
		
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< save write protect status    */
		
    if(KeyClkSel == CMU_KEYCLKCFG_KEYCLKSEL_LRC)
    {
        HT_CMU->KEYCLKCFG = CMU_KEYCLKCFG_KEYCLKSEL_LRC;
    }
    else
    {
        HT_CMU->KEYCLKCFG = CMU_KEYCLKCFG_KEYCLKSEL_OSC;
    }

    HT_CMU->WPREG = writeProtect;                                          /*!< restores the previous value  */
}
#endif


#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)

/**
*********************************************************************************************************
*                                         INITIAL KEY MODULE
*
* @brief: Initializes the KEY peripheral according to the specified
*         parameters in the KEY_InitStruct . 
*
* @param: KEY_InitStruct: pointer to a KEY_InitTypeDef structure
*   that contains the configuration information for the specified KEY 
*   peripheral.which consists of severn parameters:
*                               1) Instance       : pointer to HT_KEY
*                               2) ErrorCode      : error information
*
* @retval: None
*
* @Note: when USE_HT_KEY_REGISTER_CALLBACKS == 1U,this function shoud be called by user.
*********************************************************************************************************
*/
void HT_KEY_Init(HT_KEY_TypeDef *KEYSCANx,KEY_InitTypeDef *KEY_InitStruct)
{
		/*  assert_param  */
		assert_param(IS_HT_KEY_PERIPH(KEYSCANx));
		
			KEY_InitCallbacksToDefault(KEY_InitStruct);
			KEY_InitStruct->Instance = KEYSCANx;
}

/**
*********************************************************************************************************
*                                         INITIAL KEY CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: KEY_InitStruct Pointer to a KEY_InitTypeDef structure that contains
*               the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void KEY_InitCallbacksToDefault(KEY_InitTypeDef *KEY_InitStruct)
{
  /* Init the KEY Callback settings */
    KEY_InitStruct->KeyCallback = HT_KEY_KeyCallback;            /* Legacy weak KeyCallback            */
}

/**
*********************************************************************************************************
*                                         KEY CALLBACK
*
* @brief: KEY callbacks.
*
* @param: KEY_InitStruct  Pointer to a KEY_InitTypeDef structure that contains
*                the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_KEY_KeyCallback(KEY_InitTypeDef *KEY_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(KEY_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_KEY_KeyCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
* @brief  Register a User KEY Callback
*         To be used instead of the weak predefined callback
* @param  KEY_InitStruct KEY handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref KEY_CB_ID KEY Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_KEY_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
*********************************************************************************************************
*/
StatusTypeDef HT_KEY_RegisterCallback(KEY_InitTypeDef *KEY_InitStruct, KEY_CallbackIDTypeDef CallbackID, pKEY_CallbackTypeDef pCallback)
{
  StatusTypeDef status = OK;

	if (pCallback == NULL)
	{
		/* Update the error code */
		KEY_InitStruct->ErrorCode |= KEY_ERROR_INVALID_CALLBACK;
		
		/* Return error status */
		status =  ERROR;
	}
	else
	{
		switch (CallbackID)
		{
			case KEY_CB_ID :
				KEY_InitStruct->KeyCallback = pCallback;
				break;

			default :
				/* Update the error code */
				KEY_InitStruct->ErrorCode |= KEY_ERROR_INVALID_CALLBACK;

				/* Return error status */
				status =  ERROR;
				break;
		}
	}
  return status;
}

/**
*********************************************************************************************************
*                                         KEY IRQ HANDLER
*
* @brief: This function handles KEY interrupt request.
*
* @param: KEY_InitStruct  Pointer to a KEY_InitTypeDef structure that contains
*                the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_KEY_IRQHandler(KEY_InitTypeDef *KEY_InitStruct)
{
    uint32_t isrflags   = READ_REG(KEY_InitStruct->Instance->KEYSTA);
    uint32_t cr1its     = READ_REG(KEY_InitStruct->Instance->KEYIF);

	/* KEY is pressed */
	if (((isrflags & KEY_KEYSTA) != RESET) && ((cr1its & KEY_KEYIF) != RESET))
	{
		KEY_PRESS_IT(KEY_InitStruct);
		HT_KEY_ClearITPendingBit(KEY_KEYIF);             /*!< clear interrupt flag          */
	}
}

/**
*********************************************************************************************************
*                                         KEY Press IT HANDLER
*
* @brief: the main process when Key is pressed
*
* @param: KEY_InitStruct Pointer to a KEY_InitTypeDef structure that contains
*               the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void KEY_PRESS_IT(KEY_InitTypeDef *KEY_InitStruct)
{
	 /*Call registered Key callback*/
	 if(KEY_InitStruct->KeyCallback != NULL)
	 {
			KEY_InitStruct->KeyCallback(KEY_InitStruct);
	 }
}
#endif

/**
*********************************************************************************************************
*                                   GET KEY SCAN STATUS
*
* @brief: Gets the KEY scan status
*
* @param: None
*
* @retval: KEYSTA   ：KEY scan status
*
* @Note: None
*********************************************************************************************************
*/
uint32_t HT_KEY_ScanStatusGet(void)
{
    /*  assert_param  */

    return (HT_KEY->KEYSTA);
}

/**
*********************************************************************************************************
*                                   CLEAR KEY SCAN STATUS
*
* @brief: Clears the key scan status
*
* @param: None
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_KEY_ClearScanStatus(void)
{
    /*  assert_param  */

    HT_KEY->KEYSTA = 0;
}



/**
*********************************************************************************************************
*                            GET SPECIFIED KEY INTERRUPT FLAG STATUS
*
* @brief: Get the specified KEY interrupt flag status
*
* @param: ITFlag     One of the KEY scan interrupts to check,this parameter can be one of the following values:
                       @arg KEY_KEYIF
*
* @retval: ITStatus    = SET：  The interrupt flag is set
*                       = RESET：The interrupt flag is not set
*
* @Note: None
*********************************************************************************************************
*/
ITStatus HT_KEY_ITFlagStatusGet(uint8_t ITFlag)
{
	FlagStatus status;
    /*  assert_param  */
	assert_param(IS_HT_KEY_IF(ITFlag));
	
    if (HT_KEY->KEYIF & ITFlag)
    {
        status = SET;                                  /*!< Interrupt Flag is set      */
    }
    else
    {
        status = RESET;                                /*!< Interrupt Flag is reset    */
    }
	return status;
}

/**
*********************************************************************************************************
*                                   CLEAR KEY SCAN INTERRUPT FLAG
*
* @brief: Clear the KEY scan interrupt flag
*
* @param: ITFlag     One of the KEY scan interrupts to clear,this parameter can be one or a combination of
*						the following values:
*                        @arg KEY_KEYIF
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_KEY_ClearITPendingBit(uint8_t ITFlag)
{
    /*  assert_param  */
		assert_param(IS_HT_KEY_IF(ITFlag));

    HT_KEY->KEYIF   = ~((uint32_t)ITFlag);           /*!< Clear  Interrupt Flag       */

}

#endif                                               /* This File Only support for chips used keyscan Function. */
