/*
*********************************************************************************************************
*                                              HT5X3X
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT5x3x
* File         : ht5x3x_emuiface.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_EMUIFACE_C

#include <stdio.h>
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
#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
static void EMUIFACE_InitCallbacksToDefault(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);
static void EMUIFACE_NIS_IT(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);
#endif



/**
*********************************************************************************************************
*                                         INITIAL EMUIFACE MODULE
* @brief:   EMUIFACE initial
*
* @param:   EMUIFACE_InitStruct    pointer to the Initial structure 
*                               1) EMUIFACE_NIS_State      : EMUIFACE NIS Port state,		ENABLE/DISABLE
*                               2) EMUIFACE_NIS_Align      : EMUIFACE NIS Port Align,   LSB/MSB
*                               3) EMUIFACE_NIS_BitWide    : EMUIFACE NIS Port BitWide, 16/24/32bits
*
* @retval:  None
*
*********************************************************************************************************
*/
StatusTypeDef HT_EMUIFACE_Init(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct)
{
	StatusTypeDef status = OK;
	
	if(EMUIFACE_InitStruct == NULL)
	{
		status = ERROR;
	}
	else
	{		
    HT_EMUIFACE_NIS_DISBALE();
    
    assert_param(IS_HT_EMUIFACE_CHN0SEL(EMUIFACE_InitStruct->NIS_Chn0Sel));
		assert_param(IS_HT_EMUIFACE_CHN1SEL(EMUIFACE_InitStruct->NIS_Chn1Sel));
		assert_param(IS_HT_EMUIFACE_CHN2SEL(EMUIFACE_InitStruct->NIS_Chn2Sel));
		
		HT_EMUIFACE->EI_NISCFG = (((uint32_t)EMUIFACE_InitStruct->NIS_Chn0Sel)|((uint32_t)EMUIFACE_InitStruct->NIS_Chn1Sel)|((uint32_t)EMUIFACE_InitStruct->NIS_Chn2Sel));
		
		assert_param(IS_HT_EMUIFACE_NISBIT(EMUIFACE_InitStruct->NIS_BitWide));
		assert_param(IS_HT_EMUIFACE_NISHA(EMUIFACE_InitStruct->NIS_Align));
		
		HT_EMUIFACE->EICON = (((uint32_t)EMUIFACE_InitStruct->NIS_BitWide)|((uint32_t)EMUIFACE_InitStruct->NIS_Align));	

	#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
		EMUIFACE_InitCallbacksToDefault(EMUIFACE_InitStruct);
		EMUIFACE_InitStruct->Instance = HT_EMUIFACE;
	#endif
    
    HT_EMUIFACE_NIS_ENBALE();
	}
	return status;
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE EMUIFACE INTERRUPT
*
* @brief:   enable or disable EMUIFACE interrupt
*
* @param:   ITEn       EMUIFACE interrupt set, it can be one or a combination of the following parameters:
*                      @arg EMUIFACE_NIS_IE
*
*           NewState   = ENABLE: enable interrupt
*                      = DISABLE:disable interrupt
* @retval:  none
*
*********************************************************************************************************
*/
void HT_EMUIFACE_ITConfig(uint32_t ITEn,FunctionalState NewState)
{
	assert_param(IS_HT_EMUIFACE_IE(ITEn));
	if(NewState != DISABLE)
	{
		HT_EMUIFACE->EIIE |= (ITEn & EI_EIIE);
	}
	else
	{
		HT_EMUIFACE->EIIE &= ~ITEn;
	}
}

/**
*********************************************************************************************************
*                            GET SPECIFIED EMUIFACE INTERRUPT FLAG STATUS
*
* @brief:   get EMUIFACE interrupt flag status
*
* @param:   ITFlag     EMUIFACE interrupt flag check, it can be the following parameters:
*                      @arg EMUIFACE_NIS_IF
*
* @retval:  ITStatus    = SET:  the interrupt flag produced
*                       = RESET:the interrupt flag not produced
*
*********************************************************************************************************
*/
ITStatus HT_EMUIFACE_ITFlagStatusGet(uint32_t ITFlag)
{
	FlagStatus status = RESET;
	assert_param(IS_HT_EMUIFACE_IF(ITFlag));
	if (HT_EMUIFACE->EIIF & ITFlag)
	{
		status = SET;                       
	}
	else
	{
		status = RESET;                     
	}
	return status;
}

/**
*********************************************************************************************************
*                                CLEAR EMUIFACE INTERRUPT FLAG
*
* @brief:   clear EMUIFACE interrupt flag
*
* @param:   ITFlag     EMUIFACE interrupt flag clear,It can be one or a combination of the following parameters:
*                      @arg EMUIFACE_NIS_IF
*
* @retval:  none
*
*********************************************************************************************************
*/
void HT_EMUIFACE_ClearITPendingBit(uint32_t ITFlag)
{
  /*  assert_param  */
  assert_param(IS_HT_EMUIFACE_IF(ITFlag));
  HT_EMUIFACE->EIIF  = ~ITFlag;                  /*!< Clear EMUIFACE Interrupt Flag    */
}


#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)

/**
* @brief  Register a User EMUIFACE Callback
*         To be used instead of the weak predefined callback
* @param  EMUIFACE_InitStruct EMUIFACE handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*         @arg @ref EMUIFACE_NIS_COMPLETE_CB_ID EMUIFACE NIS port Complete Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
*/
StatusTypeDef HT_EMUIFACE_RegisterCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct, EMUIFACE_CallbackIDTypeDef CallbackID, pEMUIFACE_CallbackTypeDef pCallback)
{
	StatusTypeDef status = OK;

	if (pCallback == NULL)
	{
		/* Update the error code */
		EMUIFACE_InitStruct->ErrorCode |= EMUIFACE_ERROR_INVALID_CALLBACK;
		/* return status;*/
		status = ERROR;
	}
	else
	{
		switch (CallbackID)
		{
			case EMUIFACE_NIS_COMPLETE_CB_ID :
				EMUIFACE_InitStruct->EmuIfaceNisCpltCallback = pCallback;
			break;
			default :
				/* Update the error code */
				EMUIFACE_InitStruct->ErrorCode |= EMUIFACE_ERROR_INVALID_CALLBACK;
				/* Return error status */
				status =  ERROR;
			break;
		}
	}
	return status;
}

/**
*********************************************************************************************************
*                                       INITIAL EMUIFACE CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: EMUIFACE_InitStruct Pointer to a EMUIFACE_InitTypeDef structure that contains
*               the configuration information for the specified EMUIFACE module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void EMUIFACE_InitCallbacksToDefault(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct)
{
	EMUIFACE_InitStruct->EmuIfaceNisCpltCallback = HT_EMUIFACE_NisCpltCallback;
}

/**
*********************************************************************************************************
*                                       EMUIFACE NIS IT HANDLER
*
* @brief: This function handles NIS interrupt request
*
* @param: EMUIFACE_InitStruct Pointer to a EMUIFACE_InitTypeDef structure that contains
*               the configuration information for the specified EMUIFACE module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void EMUIFACE_NIS_IT(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct)
{
	if(EMUIFACE_InitStruct->EmuIfaceNisCpltCallback != NULL)
	{
		EMUIFACE_InitStruct->EmuIfaceNisCpltCallback(EMUIFACE_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                   EMUIFACE IRQ HANDLER
*
* @brief: This function handles FRAMPACK interrupt request.
*
* @param: EMUIFACE_InitStruct  Pointer to a EMUIFACE_InitTypeDef structure that contains
*                the configuration information for the specified EMUIFACE module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_EMUIFACE_IRQHandler(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct)
{
	uint32_t isrflags   = READ_REG(EMUIFACE_InitStruct->Instance->EIIF);
	uint32_t cr1its     = READ_REG(EMUIFACE_InitStruct->Instance->EIIE);
	
	if(((isrflags & EMUIFACE_NIS_IF) != RESET) && ((cr1its & EMUIFACE_NIS_IE) != RESET))
	{
		EMUIFACE_NIS_IT(EMUIFACE_InitStruct);
		HT_EMUIFACE_ClearITPendingBit(EMUIFACE_NIS_IF);
	}
}

/**
*********************************************************************************************************
*                                     EMUIFACE COMPLETE CALLBACK
*
* @brief: EMUIFACE completed callbacks.
*
* @param: EMUIFACE  Pointer to a EMUIFACE_InitTypeDef structure that contains
*                the configuration information for the specified EMUIFACE module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_EMUIFACE_NisCpltCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(EMUIFACE_InitStruct);
	/* NOTE: This function should not be modified, when the callback is needed,
		the HT_EMUIFACE_NisCpltCallback could be implemented in the user file
	*/
}


#endif
