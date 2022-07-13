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
* File         : ht6xxx_tbs.c
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_TBS_C
#include <stdio.h>
#include <stdbool.h>
#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                           Local Macro/Struct
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                             Local Variable
*********************************************************************************************************
*/

#define  TBS_TBSCON_MEMS_CONFIG                  (uint32_t)0x00006d60 
/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
static void TBS_InitCallbacksToDefault(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_TMP_IT(TBS_InitTypeDef *TBS_InitStruct);

#if !defined USE_TBS_VTPPRD
static void TBS_VBAT_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

static void TBS_VDD_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_ADC0_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_ADC1_IT(TBS_InitTypeDef *TBS_InitStruct);

#if defined USE_TBS_ADC2DAT
static void TBS_ADC2_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC0CMP && !defined USE_TBS_VTPPRD
static void TBS_VBATCMP_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined  USE_TBS_ADC0CMP
static void TBS_ADC0CMP_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_SOC
static void TBS_ADC1CMP_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC3DAT
static void TBS_ADC3_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC4DAT
static void TBS_ADC4_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC5DAT
static void TBS_ADC5_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC6DAT
static void TBS_ADC6_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC7DAT
static void TBS_ADC7_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC8DAT
static void TBS_ADC8_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_ADC9DAT
static void TBS_ADC9_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_VREFDAT
static void TBS_VREF_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if defined USE_TBS_VTPPRD
static void TBS_TDVREF_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_TDVREFCMP_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP0_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP1_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP2_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP3_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP4_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP5_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP6_IT(TBS_InitTypeDef *TBS_InitStruct);
static void TBS_VTP7_IT(TBS_InitTypeDef *TBS_InitStruct);
#endif

__weak void HT_TBS_TMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}	

__weak void HT_TBS_VBATCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VDDCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC0CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC1CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC2CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VBATCMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC3CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC0CMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC1CMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC4CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC5CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC6CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC7CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC8CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_ADC9CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VREFCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_TDVREFCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_TDVREFCMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP0CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP1CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP2CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP3CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP4CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP5CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP6CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

__weak void HT_TBS_VTP7CpltCallback(TBS_InitTypeDef *TBS_InitStruct)
{
	UNUSED(TBS_InitStruct);
}

static void TBS_InitCallbacksToDefault(TBS_InitTypeDef *TBS_InitStruct)
{
    TBS_InitStruct->ADC0CMPCpltCallback = HT_TBS_ADC0CMPCpltCallback;
	TBS_InitStruct->ADC0CpltCallback = HT_TBS_ADC0CpltCallback;
	TBS_InitStruct->ADC1CMPCpltCallback = HT_TBS_ADC1CMPCpltCallback;
	TBS_InitStruct->ADC1CpltCallback = HT_TBS_ADC1CpltCallback;
	TBS_InitStruct->ADC2CpltCallback = HT_TBS_ADC2CpltCallback;
	TBS_InitStruct->ADC3CpltCallback = HT_TBS_ADC3CpltCallback;
	TBS_InitStruct->ADC4CpltCallback = HT_TBS_ADC4CpltCallback;
	TBS_InitStruct->ADC5CpltCallback = HT_TBS_ADC5CpltCallback;
	TBS_InitStruct->ADC6CpltCallback = HT_TBS_ADC6CpltCallback;
    TBS_InitStruct->ADC7CpltCallback = HT_TBS_ADC6CpltCallback;
    TBS_InitStruct->ADC8CpltCallback = HT_TBS_ADC6CpltCallback;
    TBS_InitStruct->ADC9CpltCallback = HT_TBS_ADC6CpltCallback;
	TBS_InitStruct->TDVREFCMPCpltCallback = HT_TBS_TDVREFCMPCpltCallback;
	TBS_InitStruct->TDVREFCpltCallback = HT_TBS_TDVREFCpltCallback;
	TBS_InitStruct->TMPCpltCallback = HT_TBS_TMPCpltCallback;
	TBS_InitStruct->VBATCMPCpltCallback = HT_TBS_VBATCMPCpltCallback;
	TBS_InitStruct->VBATCpltCallback = HT_TBS_VBATCpltCallback;
	TBS_InitStruct->VDDCpltCallback = HT_TBS_VDDCpltCallback;
	TBS_InitStruct->VREFCpltCallback = HT_TBS_VREFCpltCallback;
	TBS_InitStruct->VTP0CpltCallback = HT_TBS_VTP0CpltCallback;
	TBS_InitStruct->VTP1CpltCallback = HT_TBS_VTP1CpltCallback;
	TBS_InitStruct->VTP2CpltCallback = HT_TBS_VTP2CpltCallback;
	TBS_InitStruct->VTP3CpltCallback = HT_TBS_VTP3CpltCallback;
	TBS_InitStruct->VTP4CpltCallback = HT_TBS_VTP4CpltCallback;
	TBS_InitStruct->VTP5CpltCallback = HT_TBS_VTP5CpltCallback;
	TBS_InitStruct->VTP6CpltCallback = HT_TBS_VTP6CpltCallback;
	TBS_InitStruct->VTP7CpltCallback = HT_TBS_VTP7CpltCallback;
}


/**
*********************************************************************************************************
*                                     REGISTER TBS CALLBACK
*
* @brief: Register a User TBS Callback
*         To be used instead of the weak predefined callback
* @param: TBS_InitStruct TBS handle
* @param: CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref TBS_TMP_COMPLETE_CB_ID TMP Complete Callback ID
*           @arg @ref TBS_VBAT_COMPLETE_CB_ID VBAT Complete Callback ID
*           @arg @ref TBS_VDD_COMPLETE_CB_ID VDD Complete Callback ID
*           @arg @ref TBS_ADC0_COMPLETE_CB_ID ADC0 Complete Callback ID
*           @arg @ref TBS_ADC1_COMPLETE_CB_ID ADC1 Complete Callback ID
*           @arg @ref TBS_ADC2_COMPLETE_CB_ID ADC2 Complete Callback ID
*           @arg @ref TBS_ADC3_COMPLETE_CB_ID ADC3 Complete Callback ID
*           @arg @ref TBS_VBATCMP_COMPLETE_CB_ID VBATCMP Complete Callback ID
*           @arg @ref TBS_ADC0CMP_COMPLETE_CB_ID ADC0CMP Complete Callback ID
*           @arg @ref TBS_ADC1CMP_COMPLETE_CB_ID ADC1CMP Complete Callback ID
*           @arg @ref TBS_ADC4_COMPLETE_CB_ID ADC4 Complete Callback ID
*           @arg @ref TBS_ADC5_COMPLETE_CB_ID ADC5 Complete Callback ID
*           @arg @ref TBS_ADC6_COMPLETE_CB_ID ADC6 Complete Callback ID
*           @arg @ref TBS_ADC7_COMPLETE_CB_ID ADC7 Complete Callback ID
*           @arg @ref TBS_ADC8_COMPLETE_CB_ID ADC8 Complete Callback ID
*           @arg @ref TBS_ADC9_COMPLETE_CB_ID ADC9 Complete Callback ID
*           @arg @ref TBS_TDVREF_COMPLETE_CB_ID TDVREF Complete Callback ID
*           @arg @ref TBS_TDVREFCMP_COMPLETE_CB_ID TDVREFCMP Complete Callback ID
*           @arg @ref TBS_VREF_COMPLETE_CB_ID VREF Complete Callback ID
*           @arg @ref TBS_VTP0_COMPLETE_CB_ID VTP0 Complete Callback ID
*           @arg @ref TBS_VTP1_COMPLETE_CB_ID VTP1 Complete Callback ID
*           @arg @ref TBS_VTP2_COMPLETE_CB_ID VTP2 Complete Callback ID
*           @arg @ref TBS_VTP3_COMPLETE_CB_ID VTP3 Complete Callback ID
*           @arg @ref TBS_VTP4_COMPLETE_CB_ID VTP4 Complete Callback ID
*           @arg @ref TBS_VTP5_COMPLETE_CB_ID VTP5 Complete Callback ID
*           @arg @ref TBS_VTP6_COMPLETE_CB_ID VTP6 Complete Callback ID
*           @arg @ref TBS_VTP7_COMPLETE_CB_ID VTP7 Complete Callback ID
* @param: pCallback pointer to the Callback function
* @retval:status
*/
StatusTypeDef HT_TBS_RegisterCallback(TBS_InitTypeDef *TBS_InitStruct,TBS_CallbackIDTypeDef CallbackID,pTBS_CallbackTypeDef pCallback)
{
	StatusTypeDef status = OK;
	if (pCallback == NULL)
	{
		/* Update the error code*/
		TBS_InitStruct->ErrorCode |= TBS_ERROR_INVALID_CALLBACK;
		status = ERROR;
	}
        
	if (status != ERROR)
    {
        switch (CallbackID)
        {
            case TBS_TMP_COMPLETE_CB_ID:
                TBS_InitStruct->TMPCpltCallback = pCallback;
            break;
		
            case TBS_VBAT_COMPLETE_CB_ID:
                TBS_InitStruct->VBATCpltCallback = pCallback;
            break;
		
            case TBS_VDD_COMPLETE_CB_ID:
                TBS_InitStruct->VDDCpltCallback = pCallback;
            break;
            
            case TBS_ADC0_COMPLETE_CB_ID:
                TBS_InitStruct->ADC0CpltCallback = pCallback;
            break;
            
            case TBS_ADC1_COMPLETE_CB_ID:
                TBS_InitStruct->ADC1CpltCallback = pCallback;
            break;
            
            case TBS_ADC2_COMPLETE_CB_ID:
                TBS_InitStruct->ADC2CpltCallback = pCallback;
            break;
            
            case TBS_ADC3_COMPLETE_CB_ID:
                TBS_InitStruct->ADC3CpltCallback = pCallback;
            break;
            
            case TBS_VBATCMP_COMPLETE_CB_ID:
                TBS_InitStruct->VBATCMPCpltCallback = pCallback;
            break;
            
            case TBS_ADC0CMP_COMPLETE_CB_ID:
                TBS_InitStruct->ADC0CMPCpltCallback = pCallback;
            break;
            
            case TBS_ADC1CMP_COMPLETE_CB_ID:
                TBS_InitStruct->ADC1CMPCpltCallback = pCallback;
            break;
            
            case TBS_ADC4_COMPLETE_CB_ID:
                TBS_InitStruct->ADC4CpltCallback = pCallback;
            break;
            
            case TBS_ADC5_COMPLETE_CB_ID:
                TBS_InitStruct->ADC5CpltCallback = pCallback;
            break;
            
            case TBS_ADC6_COMPLETE_CB_ID:
                TBS_InitStruct->ADC6CpltCallback = pCallback;
            break;
            
            case TBS_ADC7_COMPLETE_CB_ID:
                TBS_InitStruct->ADC7CpltCallback = pCallback;
            break;
            
            case TBS_ADC8_COMPLETE_CB_ID:
                TBS_InitStruct->ADC8CpltCallback = pCallback;
            break;
            
            case TBS_ADC9_COMPLETE_CB_ID:
                TBS_InitStruct->ADC9CpltCallback = pCallback;
            break;
            
            case TBS_TDVREF_COMPLETE_CB_ID:
                TBS_InitStruct->TDVREFCpltCallback = pCallback;
            break;
            
            case TBS_TDVREFCMP_COMPLETE_CB_ID:
                TBS_InitStruct->TDVREFCMPCpltCallback = pCallback;
            break;
            
            case TBS_VREF_COMPLETE_CB_ID:
                TBS_InitStruct->VREFCpltCallback = pCallback;
            break;
            
            case TBS_VTP0_COMPLETE_CB_ID:
                TBS_InitStruct->VTP0CpltCallback = pCallback;
            break;
            
            case TBS_VTP1_COMPLETE_CB_ID:
                TBS_InitStruct->VTP1CpltCallback = pCallback;
            break;
            
            case TBS_VTP2_COMPLETE_CB_ID:
                TBS_InitStruct->VTP2CpltCallback = pCallback;
            break;
            
            case TBS_VTP3_COMPLETE_CB_ID:
                TBS_InitStruct->VTP3CpltCallback = pCallback;
            break;
            
            case TBS_VTP4_COMPLETE_CB_ID:
                TBS_InitStruct->VTP4CpltCallback = pCallback;
            break;
            
            case TBS_VTP5_COMPLETE_CB_ID:
                TBS_InitStruct->VTP5CpltCallback = pCallback;
            break;
            
            case TBS_VTP6_COMPLETE_CB_ID:
                TBS_InitStruct->VTP6CpltCallback = pCallback;
            break;
            
            case TBS_VTP7_COMPLETE_CB_ID:
                TBS_InitStruct->VTP7CpltCallback = pCallback;
            break;
            
            default:
              /* Update the error code */
              TBS_InitStruct->ErrorCode |= TBS_ERROR_INVALID_CALLBACK;
              
              /* Return error status */
              status = ERROR;
              break;
         }
    }
	return status;
}

/**
*********************************************************************************************************
*                                     INIT TBS TYPEDEF
*
* @brief: Init TBS TypeDef
*
* @param: TBS_InitTypeDef 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/

void HT_TBS_Init(TBS_InitTypeDef *TBS_InitStruct)
{
	TBS_InitCallbacksToDefault(TBS_InitStruct);
    TBS_InitStruct->Instance = HT_TBS;
}


/**
*********************************************************************************************************
*                                     TBS IRQ HANDLER
*
* @brief: This function handles TBS interrupt request
*
* @param: htbs  Pointer to a TBS_HandleTypeDef structure that contains the configuration information for the specified TBS module
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_IRQHandler(TBS_InitTypeDef *TBS_InitStruct)
{
	uint32_t TBSflags  =  READ_REG(TBS_InitStruct->Instance->TBSIF);
	uint32_t cr1its       =  READ_REG(TBS_InitStruct->Instance->TBSIE);

		if (((TBSflags & TBS_TBSIF_TMPIF)!=RESET)&&((cr1its&TBS_TBSIE_TMPIE)!=RESET))
		{
			TBS_TMP_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_TMPIF);
		}
        
#if defined USE_TBS_VREFDAT
		if (((TBSflags & TBS_TBSIF_VREFIF)!=RESET)&&((cr1its&TBS_TBSIE_VREFIE)!=RESET))
		{
			TBS_VREF_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VREFIF);
		}
#endif
        
#if !defined USE_TBS_VTPPRD
		if (((TBSflags & TBS_TBSIF_VBATIF)!=RESET)&&((cr1its&TBS_TBSIE_VBATIE)!=RESET))
		{
			TBS_VBAT_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VBATIF);
		}
#endif
		
		if (((TBSflags & TBS_TBSIF_VCCIF)!=RESET)&&((cr1its&TBS_TBSIE_VCCIE)!=RESET))
		{
			TBS_VDD_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VCCIF);
		}

		if (((TBSflags & TBS_TBSIF_ADC0IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC0IE)!=RESET))
		{
			TBS_ADC0_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC0IF);
		}

		if (((TBSflags & TBS_TBSIF_ADC1IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC1IE)!=RESET))
		{
			TBS_ADC1_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC1IF);
		}
        
#if defined USE_TBS_ADC2DAT
		if (((TBSflags & TBS_TBSIF_ADC2IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC2IE)!=RESET))
		{
			TBS_ADC2_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC2IF);
		}
#endif
        
#if !defined USE_TBS_TDVREFCMP && defined USE_TBS_ADC0CMP
		if (((TBSflags & TBS_TBSIF_VBATCMPIF)!=RESET)&&((cr1its&TBS_TBSIE_VBATCMPIE)!=RESET))
		{
			TBS_VBATCMP_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VBATCMPIF);
		}
#endif
        
#if defined USE_TBS_ADC3DAT
		if (((TBSflags & TBS_TBSIF_ADC3IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC3IE)!=RESET))
		{
			TBS_ADC3_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC3IF);
		}
#endif
        
#if defined USE_TBS_ADC0CMP
		if (((TBSflags & TBS_TBSIF_ADC0CMPIF)!=RESET)&&((cr1its&TBS_TBSIE_ADC0CMPIE)!=RESET))
		{
			TBS_ADC0CMP_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC0CMPIF);
		}
#endif
        
#if defined USE_TBS_SOC
		if (((TBSflags & TBS_TBSIF_ADC1CMPIF)!=RESET)&&((cr1its&TBS_TBSIE_ADC1CMPIE)!=RESET))
		{
			TBS_ADC1CMP_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC1CMPIF);
		}
#endif
        
#if defined USE_TBS_ADC4DAT
		if (((TBSflags & TBS_TBSIF_ADC4IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC4IE)!=RESET))
		{
			TBS_ADC4_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC4IF);
		}
#endif
        
#if defined USE_TBS_ADC5DAT
		if (((TBSflags & TBS_TBSIF_ADC5IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC5IE)!=RESET))
		{
			TBS_ADC5_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC5IF);
		}
#endif
        
#if defined USE_TBS_ADC6DAT
		if (((TBSflags & TBS_TBSIF_ADC6IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC6IE)!=RESET))
		{
			TBS_ADC6_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC6IF);
		}
#endif
     
#if defined USE_TBS_ADC7DAT
		if (((TBSflags & TBS_TBSIF_ADC7IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC7IE)!=RESET))
		{
			TBS_ADC7_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC7IF);
		}
#endif
        
#if defined USE_TBS_ADC8DAT
		if (((TBSflags & TBS_TBSIF_ADC8IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC8IE)!=RESET))
		{
			TBS_ADC8_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC8IF);
		}
#endif

#if defined USE_TBS_ADC9DAT
		if (((TBSflags & TBS_TBSIF_ADC9IF)!=RESET)&&((cr1its&TBS_TBSIE_ADC9IE)!=RESET))
		{
			TBS_ADC9_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_ADC9IF);
		}
#endif
        
#if defined USE_TBS_VTPPRD
		if (((TBSflags & TBS_TBSIF_TDVREFIF)!=RESET)&&((cr1its&TBS_TBSIE_TDVREFIE)!=RESET))
		{
			TBS_TDVREF_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_TDVREFIF);
		}
		if (((TBSflags & TBS_TBSIF_TDVREFCMPIF)!=RESET)&&((cr1its&TBS_TBSIE_TDVREFCMPIE)!=RESET))
		{
			TBS_TDVREFCMP_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_TDVREFCMPIF);
		}
		if (((TBSflags & TBS_TBSIF_VTP0IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP0IE)!=RESET))
		{
			TBS_VTP0_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP0IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP1IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP1IE)!=RESET))
		{
			TBS_VTP1_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP1IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP2IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP2IE)!=RESET))
		{
			TBS_VTP2_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP2IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP3IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP3IE)!=RESET))
		{
			TBS_VTP3_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP3IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP4IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP4IE)!=RESET))
		{
			TBS_VTP4_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP4IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP5IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP5IE)!=RESET))
		{
			TBS_VTP5_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP5IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP6IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP6IE)!=RESET))
		{
			TBS_VTP6_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP6IF);
		}
		if (((TBSflags & TBS_TBSIF_VTP7IF)!=RESET)&&((cr1its&TBS_TBSIE_VTP7IE)!=RESET))
		{
			TBS_VTP7_IT(TBS_InitStruct);
			HT_TBS_ClearITPendingBit(TBS_TBSIF_VTP7IF);
		}
#endif	
	}



/**
*********************************************************************************************************
*                                     TBS TMP IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_TMP_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered TMPIF complete callback*/
	if(TBS_InitStruct->TMPCpltCallback != NULL)
	{
		TBS_InitStruct->TMPCpltCallback(TBS_InitStruct);
	}
}
#if !defined USE_TBS_VTPPRD
/**
*********************************************************************************************************
*                                     TBS VBAT IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VBAT_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VBATIF complete callback*/
	if(TBS_InitStruct->VBATCpltCallback != NULL)
	{
		TBS_InitStruct->VBATCpltCallback(TBS_InitStruct);
	}
}
#endif
/**
*********************************************************************************************************
*                                     TBS VDD IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VDD_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VDDIF complete callback*/
	if(TBS_InitStruct->VDDCpltCallback != NULL)
	{
		TBS_InitStruct->VDDCpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS ADC0 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC0_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC0IF complete callback*/
	if(TBS_InitStruct->ADC0CpltCallback != NULL)
	{
		TBS_InitStruct->ADC0CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS ADC1 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC1_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC1IF complete callback*/
	if(TBS_InitStruct->ADC1CpltCallback != NULL)
	{
		TBS_InitStruct->ADC1CpltCallback(TBS_InitStruct);
	}
}

#if defined USE_TBS_SOC
/**
*********************************************************************************************************
*                                     TBS ADC2 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC2_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC2IF complete callback*/
	if(TBS_InitStruct->ADC2CpltCallback != NULL)
	{
		TBS_InitStruct->ADC2CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC0CMP && !defined USE_TBS_VTPPRD
/**
*********************************************************************************************************
*                                     TBS VBATCMP IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VBATCMP_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VBATCMPIF complete callback*/
	if(TBS_InitStruct->VBATCMPCpltCallback != NULL)
	{
		TBS_InitStruct->VBATCMPCpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC0CMP
/**
*********************************************************************************************************
*                                     TBS ADC0CMP IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC0CMP_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC0CMPIF complete callback*/
	if(TBS_InitStruct->ADC0CMPCpltCallback != NULL)
	{
		TBS_InitStruct->ADC0CMPCpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_SOC
/**
*********************************************************************************************************
*                                     TBS ADC1 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC1CMP_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC1CMPIF complete callback*/
	if(TBS_InitStruct->ADC1CMPCpltCallback != NULL)
	{
		TBS_InitStruct->ADC1CMPCpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC3DAT
/**
*********************************************************************************************************
*                                     TBS ADC3 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC3_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC3IF complete callback*/
	if(TBS_InitStruct->ADC3CpltCallback != NULL)
	{
		TBS_InitStruct->ADC3CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS ADC4 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC4_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC4IF complete callback*/
	if(TBS_InitStruct->ADC4CpltCallback != NULL)
	{
		TBS_InitStruct->ADC4CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS ADC5 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC5_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC5IF complete callback*/
	if(TBS_InitStruct->ADC5CpltCallback != NULL)
	{
		TBS_InitStruct->ADC5CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC6DAT
/**
*********************************************************************************************************
*                                     TBS ADC6 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC6_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC6IF complete callback*/
	if(TBS_InitStruct->ADC6CpltCallback != NULL)
	{
		TBS_InitStruct->ADC6CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC7DAT
/**
*********************************************************************************************************
*                                     TBS ADC7 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC7_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC7IF complete callback*/
	if(TBS_InitStruct->ADC7CpltCallback != NULL)
	{
		TBS_InitStruct->ADC7CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC8DAT
/**
*********************************************************************************************************
*                                     TBS ADC8 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC8_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC8IF complete callback*/
	if(TBS_InitStruct->ADC8CpltCallback != NULL)
	{
		TBS_InitStruct->ADC8CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_ADC9DAT
/**
*********************************************************************************************************
*                                     TBS ADC9 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_ADC9_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered ADC9IF complete callback*/
	if(TBS_InitStruct->ADC9CpltCallback != NULL)
	{
		TBS_InitStruct->ADC9CpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_VREFDAT
/**
*********************************************************************************************************
*                                     TBS VREF IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VREF_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VREF1IF complete callback*/
	if(TBS_InitStruct->VREFCpltCallback != NULL)
	{
		TBS_InitStruct->VREFCpltCallback(TBS_InitStruct);
	}
}
#endif

#if defined USE_TBS_VTPPRD
/**
*********************************************************************************************************
*                                     TBS TDVREFCMP IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_TDVREFCMP_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered TDVREFIF complete callback*/
	if(TBS_InitStruct->TDVREFCMPCpltCallback != NULL)
	{
		TBS_InitStruct->TDVREFCMPCpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS TDVREF IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_TDVREF_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered TDVREFIF complete callback*/
	if(TBS_InitStruct->TDVREFCpltCallback != NULL)
	{
		TBS_InitStruct->TDVREFCpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP0 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP0_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP0IF complete callback*/
	if(TBS_InitStruct->VTP0CpltCallback != NULL)
	{
		TBS_InitStruct->VTP0CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP1 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP1_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP1IF complete callback*/
	if(TBS_InitStruct->VTP1CpltCallback != NULL)
	{
		TBS_InitStruct->VTP1CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP2 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP2_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP2IF complete callback*/
	if(TBS_InitStruct->VTP2CpltCallback != NULL)
	{
		TBS_InitStruct->VTP2CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP3 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP3_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP3IF complete callback*/
	if(TBS_InitStruct->VTP3CpltCallback != NULL)
	{
		TBS_InitStruct->VTP3CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP4 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP4_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP4IF complete callback*/
	if(TBS_InitStruct->VTP4CpltCallback != NULL)
	{
		TBS_InitStruct->VTP4CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP5 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP5_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP5IF complete callback*/
	if(TBS_InitStruct->VTP5CpltCallback != NULL)
	{
		TBS_InitStruct->VTP5CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP6 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP6_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP6IF complete callback*/
	if(TBS_InitStruct->VTP6CpltCallback != NULL)
	{
		TBS_InitStruct->VTP6CpltCallback(TBS_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                     TBS VTP7 IT HANDLER
*
* @brief: 
*
* @param: 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
static void TBS_VTP7_IT(TBS_InitTypeDef *TBS_InitStruct)
{
	/*Call registered VTP7IF complete callback*/
	if(TBS_InitStruct->VTP7CpltCallback != NULL)
	{
		TBS_InitStruct->VTP7CpltCallback(TBS_InitStruct);
	}
}
#endif
#endif /* USE_HT_TBS_REGISTER_CALLBACKS */


#if  defined  CMU_TBSCLKCFG
/**
*********************************************************************************************************
*                            CONFIGUE TBS SOURCE CLOCK MODULE
*
* @brief: Config TBS source clock module
*
* @param: HSTBSDIV    This parameter can be one of the following values: 0x0000-0xff00
*         HSTBSClkSel This parameter can be one of the following values: @arg CMU_TBSCLKCFG_PLLX2 @arg CMU_TBSCLKCFG_HRC11M
* @retval: None
*
* @note: It is needed to open the corresponding source clock before setting HSTBSClkSel.
*********************************************************************************************************
*/
void HT_TBS_CMUClkConfig(TBS_CMUSourceClkTypeDef HSTBSDiv, TBS_CMUClkSelectTypeDef HSTBSClkSel)
{
    /*  assert_param  */
    assert_param(IS_HT_CMU_TBSSourceCFG_ClkDiv(HSTBSDiv));
	assert_param(IS_HT_TBS_CMUClkSelCFG_ClkSel(HSTBSClkSel));
    
    HT_CMU->TBSCLKCFG &= ~CMU_TBSCLKCFG;
    HT_CMU->TBSCLKCFG |= ((CMU_TBSCLKCFG & HSTBSClkSel) | (CMU_TBSCLKCFG & (HSTBSDiv & CMU_TBSCLKCFG_HSTBSDIV)));
}
#endif

/**
*********************************************************************************************************
*                                     CONFIGUE TBS MODULE
*
* @brief: Config TBS submodule
*
* @param: TBS_SubModule    This parameter can be one of the following values:
*                             @arg TBS_TBSCON_TMPEn          : Temperature measurement module       
*                             @arg TBS_TBSCON_VBATEn         : Battery voltage(VBAT) measurement module       (If support)
*                             @arg TBS_TBSCON_ADC0En         : ADC0 measurement module       
*                             @arg TBS_TBSCON_ADC1En         : ADC1 measurement module       
*                             @arg TBS_TBSCON_VCCEn          : VCC measurement module        
*                             @arg TBS_TBSCON_ADC2En         : ADC2 measurement module      (If support)
*                             @arg TBS_TBSCON_VBATCMPEn      : VBAT compare module          (If support)
*                             @arg TBS_TBSCON_TDVREFEn       : TDVref measurement module   	(If support)
*                             @arg TBS_TBSCON_ADC0CMPEn      : ADC0 compare module          (If support)
*                             @arg TBS_TBSCON_ADC1CMPEn      : ADC1 compare module          (If support)
*                             @arg TBS_TBSCON_ADC3En         : ADC3 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC4En         : ADC4 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC5En         : ADC5 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC6En         : ADC6 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC7En         : ADC7 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC8En         : ADC8 measurement module      (If support)
*                             @arg TBS_TBSCON_ADC9En         : ADC9 measurement module      (If support)
*                             @arg TBS_TBSCON_VTP0En         : VTP0 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP1En         : VTP1 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP2En         : VTP2 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP3En         : VTP3 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP4En         : VTP4 measurement module      (If support) 
*                             @arg TBS_TBSCON_VTP5En         : VTP5 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP6En         : VTP6 measurement module      (If support)  
*                             @arg TBS_TBSCON_VTP7En         : VTP7 measurement module      (If support) 
*                             @arg TBS_TBSCON_PGA_SEL        : PGA select control           (If support)
*                             @arg TBS_TBSCON_PGA_En         : PGA measurement module       (If support)  
*                             @arg TBS_TBSCON_TBS_NEWREG_En  : TBS new regisiters module    (If support)
*                             @arg TBS_TBSCON_ALLTBSEn       : Enable all TBS module        (If support)
*                             @arg TBS_TBSCON_ALLVTPEn       : Enable all VTP module        (If support)
*                             @arg TBS_TBSCON_ALLEn          : Enable all module            (If support)
*
*           NewState         = ENABLE : Enable module
*                            = DISABLE : Disable module
*
* @retval: None
*
* @note: 1) Considering that RTC compesation relates temperature sensors,it is not suggested to turn off the temperature sensor module.
*        2) It is recommended to call the function of HT_TBS_BatCmpThresholdSet() to set the battery voltage comparison threshold before enabling battery voltage comparison.
*        3) It is needed to enable the battery voltage measurement module if the battery voltage comparison function performed correctly.
*        4) This function should be used before HT_TBS_FilCntConfig and HT_TBS_ClkSelConfig, otherwise HT_TBS_FilCntConfig or HT_TBS_ClkSelConfig would invalid.
*        5) TBS_TBSCON_PGA_SEL = DISABLE , choose Buffer; TBS_TBSCON_PGA_SEL = ENABLE , choose TPGA.
*        6) It is needed to DISABLE all submodule except VTPxEn and PGA_SEL if you want to enable PGA_En.
*        7) Better not to enable TBS_NEWREG_En in this module.
*********************************************************************************************************
*/
void HT_TBSConfig(uint32_t TBS_SubModule, FunctionalState NewState)
{
    /*  assert_param  */
	assert_param(IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule));
    uint32_t tempreg;
    uint32_t tempfunc;

    tempreg = HT_TBS->TBSCON & TBS_TBSCON_xEn;
    tempfunc = HT_TBS->TBSCON & (~TBS_TBSCON_xEn);
    
#if defined USE_TBS_MEMS
    if(HT_CMU->CLKSTA & CMU_CLKSTA_LFSEL)
    {
		tempreg |= TBS_TBSCON_MEMS_CONFIG;                       
    }
    else
    {
    }
#endif
    
    TBS_SubModule &= TBS_TBSCON_xEn;
    if (NewState != DISABLE)
    {
        tempreg |= (uint32_t)TBS_SubModule;      /*!< Enable TBS module                 */
    }
    else
    {
        tempreg &= ~(uint32_t)TBS_SubModule;     /*!< Disable TBS module                 */
    }

    HT_TBS->TBSCON = (tempreg | tempfunc);       /*!< Write register                    */

}

/**
*********************************************************************************************************
*                                 SET SubModule OPEN PERIOD
*
* @brief: Set submodule to open frequence period
*
* @param: PRDModule    : This parameter means submodule period control and can be one of the following values: 
*                            @arg TMPPRD      : Temperature measurement period        
*                            @arg VBATPRD     : Battery voltage(VBAT) measurement period       (If support)
*                            @arg TDVREFPRD   : TDVREF measurement period  (If support)
*                            @arg ADC0PRD     : ADC0 measurement period        
*                            @arg ADC1PRD     : ADC1 measurement period        
*                            @arg VCCPRD      : VCC measurement period        
*                            @arg ADC2PRD     : ADC2 measurement period    (If support)
*                            @arg VREFPRD     : VREF measurement period    (If support)
*                            @arg ADC3PRD     : ADC3 measurement period    (If support)
*                            @arg ADC4PRD     : ADC4 measurement period    (If support)
*                            @arg ADC5PRD     : ADC5 measurement period    (If support)
*                            @arg ADC6PRD     : ADC6 measurement period    (If support)
*                            @arg ADC7PRD     : ADC7 measurement period    (If support)
*                            @arg ADC8PRD     : ADC8 measurement period    (If support)
*                            @arg ADC9PRD     : ADC9 measurement period    (If support)
*
*           Period       : Due to differient chips, period setting can be one of the following values:
*                             HT501x  HT502x  HT503x              HT6x1x  HT6x2x  HT6x3x  HT6x2xK  HT762x HT772x  HT633x  HT633xH
*                                 TMPPRD:                         TMPPRD:
*                            @arg TBS_TBSPRD_TMPPRD_1S            @arg  TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S
*                            @arg TBS_TBSPRD_TMPPRD_8S            @arg  TBS_TBSPRD_TMPPRD_OSC1S_MEM4S
*                            @arg TBS_TBSPRD_TMPPRD_32S        	  @arg  TBS_TBSPRD_TMPPRD_OSC2S_MEM2S
*                            @arg TBS_TBSPRD_TMPPRD_125mS    	  @arg  TBS_TBSPRD_TMPPRD_OSC4S_MEM1S
*                                                                 @arg  TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S
*                                 VBATPRD:                        @arg  TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS
*                            @arg TBS_TBSPRD_VBATPRD_1S           @arg  TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS
*                            @arg TBS_TBSPRD_VBATPRD_4S           @arg  TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS
*                            @arg TBS_TBSPRD_VBATPRD_8S
*                            @arg TBS_TBSPRD_VBATPRD_32S            VBATPRD:
*                                                                 @arg  TBS_TBSPRD_VBATPRD_1S
*                                 VCCPRD:                         @arg  TBS_TBSPRD_VBATPRD_2S
*                            @arg TBS_TBSPRD_VCCPRD_1S            @arg   TBS_TBSPRD_VBATPRD_8S
*                            @arg TBS_TBSPRD_VCCPRD_4S            @arg   TBS_TBSPRD_VBATPRD_16S
*                            @arg TBS_TBSPRD_VCCPRD_8S
*                            @arg TBS_TBSPRD_VCCPRD_32S             ADC0PRD:
*                                                                 @arg  TBS_TBSPRD_ADC0PRD_1S
*                                 ADC0PRD:                        @arg  TBS_TBSPRD_ADC0PRD_2S
*                            @arg TBS_TBSPRD_ADC0PRD_1S           @arg  TBS_TBSPRD_ADC0PRD_8S
*                            @arg TBS_TBSPRD_ADC0PRD_4S           @arg  TBS_TBSPRD_ADC0PRD_16S
*                            @arg TBS_TBSPRD_ADC0PRD_8S
*                            @arg TBS_TBSPRD_ADC0PRD_32S            ADC1PRD:
*                                                                 @arg  TBS_TBSPRD_ADC1PRD_1S
*                                 ADC1PRD:                        @arg  TBS_TBSPRD_ADC1PRD_2S
*                            @arg TBS_TBSPRD_ADC1PRD_1S           @arg  TBS_TBSPRD_ADC1PRD_8S
*                            @arg TBS_TBSPRD_ADC1PRD_4S           @arg  TBS_TBSPRD_ADC1PRD_16S
*                            @arg TBS_TBSPRD_ADC1PRD_8S
*                            @arg TBS_TBSPRD_ADC1PRD_32S            VCCPRD:
*                                                              	  @arg  TBS_TBSPRD_VCCPRD_1S
*                                 ADC2PRD:                    	  @arg  TBS_TBSPRD_VCCPRD_2S
*                            @arg TBS_TBSPRD_ADC2PRD_1S      	  @arg  TBS_TBSPRD_VCCPRD_8S
*                            @arg TBS_TBSPRD_ADC2PRD_4S       	  @arg  TBS_TBSPRD_VCCPRD_16S
*                            @arg TBS_TBSPRD_ADC2PRD_8S
*                            @arg TBS_TBSPRD_ADC2PRD_32S            ADC3PRD:(If support)
*                                                            	  @arg  TBS_TBSPRD_ADC3PRD_1S
*                                 VREFPRD: (If support)       	  @arg  TBS_TBSPRD_ADC3PRD_2S
*                            @arg TBS_TBSPRD_VREFPRD_1S       	  @arg  TBS_TBSPRD_ADC3PRD_8S
*                            @arg TBS_TBSPRD_VREFPRD_4S      	  @arg  TBS_TBSPRD_ADC3PRD_16S
*                            @arg TBS_TBSPRD_VREFPRD_8S
*                            @arg TBS_TBSPRD_VREFPRD_32S            ADC4PRD:(If support)
*                                                              	  @arg  TBS_TBSPRD_ADC4PRD_1S
*                                 ADC3PRD: (If support)           @arg  TBS_TBSPRD_ADC4PRD_2S
*                            @arg TBS_TBSPRD_ADC3PRD_1S        	  @arg  TBS_TBSPRD_ADC4PRD_8S
*                            @arg TBS_TBSPRD_ADC3PRD_4S        	  @arg  TBS_TBSPRD_ADC4PRD_16S
*                            @arg TBS_TBSPRD_ADC3PRD_8S
*                            @arg TBS_TBSPRD_ADC3PRD_32S            ADC5PRD:(If support)
*                                                                 @arg  TBS_TBSPRD_ADC5PRD_1S
*                                 ADC4PRD: (If support)           @arg  TBS_TBSPRD_ADC5PRD_2S
*                            @arg TBS_TBSPRD_ADC4PRD_1S           @arg  TBS_TBSPRD_ADC5PRD_8S
*                            @arg TBS_TBSPRD_ADC4PRD_4S           @arg  TBS_TBSPRD_ADC5PRD_16S
*                            @arg TBS_TBSPRD_ADC4PRD_8S
*                            @arg TBS_TBSPRD_ADC4PRD_32S            ADC6PRD:(If support)
*                                                                 @arg  TBS_TBSPRD_ADC6PRD_1S
*                                 ADC5PRD:(If support)            @arg  TBS_TBSPRD_ADC6PRD_2S
*                            @arg TBS_TBSPRD_ADC5PRD_1S           @arg  TBS_TBSPRD_ADC6PRD_8S
*                            @arg TBS_TBSPRD_ADC5PRD_4S           @arg  TBS_TBSPRD_ADC6PRD_16S
*                            @arg TBS_TBSPRD_ADC5PRD_8S
*                            @arg TBS_TBSPRD_ADC5PRD_32S            ADC7PRD:(If support)
*                                                                 @arg  TBS_TBSPRD_ADC7PRD_1S
*                                 ADC6PRD:(If support)            @arg  TBS_TBSPRD_ADC7PRD_2S
*                            @arg TBS_TBSPRD_ADC6PRD_1S           @arg  TBS_TBSPRD_ADC7PRD_8S
*                            @arg TBS_TBSPRD_ADC6PRD_4S           @arg  TBS_TBSPRD_ADC7PRD_16S
*                            @arg TBS_TBSPRD_ADC6PRD_8S
*                            @arg TBS_TBSPRD_ADC6PRD_32S            ADC8PRD:(If support)
*                                                                 @arg  TBS_TBSPRD_ADC8PRD_1S
*                               TDVREFPRD:(If support)            @arg  TBS_TBSPRD_ADC8PRD_2S
*                            @arg TBS_TBSPRD_TDVREFPRD_1S         @arg  TBS_TBSPRD_ADC8PRD_8S
*                            @arg TBS_TBSPRD_TDVREFPRD_2S         @arg  TBS_TBSPRD_ADC8PRD_16S
*                            @arg TBS_TBSPRD_TDVREFPRD_8S         
*                            @arg TBS_TBSPRD_TDVREFPRD_16S          ADC9PRD:(If support)
*                                                                 @arg  TBS_TBSPRD_ADC9PRD_1S
*                                                                 @arg  TBS_TBSPRD_ADC9PRD_2S
*                                                                 @arg  TBS_TBSPRD_ADC9PRD_8S
*                                                                 @arg  TBS_TBSPRD_ADC9PRD_16S
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_PeriodSet(TBS_PeriodTypeDef PRDModule, uint32_t Period)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule));
	assert_param(IS_HT_TBS_PERIODSET_PERIOD(Period));
    uint32_t tempreg = (HT_TBS->TBSPRD & (~(uint32_t)PRDModule));
    tempreg |= Period;
    HT_TBS->TBSPRD = tempreg;                             /*!< Config measure period           */
}
#if defined USE_TBS_VTPPRD
/**
*********************************************************************************************************
*                                     SET VTP OPEN PERIOD
*
* @brief: Set VTPx Open Period
*
* @param: period setting can be one of the following values
*                    VTPx = VTP0-VTP7
*                    @arg  TBS_VTPPRD_VTPxPRD_1S
*                    @arg  TBS_VTPPRD_VTPxPRD_2S
*                    @arg  TBS_VTPPRD_VTPxPRD_8S
*                    @arg  TBS_VTPPRD_VTPxPRD_16S
*         VTPPRDModule setting can be one of the following values
*                    @arg  VTP0PRD
*                    @arg  VTP1PRD
*                    @arg  VTP2PRD
*                    @arg  VTP3PRD
*                    @arg  VTP4PRD
*                    @arg  VTP5PRD
*                    @arg  VTP6PRD
*                    @arg  VTP7PRD
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_VTPPeriodSet(TBS_VTPPeriodTypeDef VTPPRDModule, uint32_t VTPPeriod)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_PERIODSET_VTPPRDMODULE(VTPPRDModule));
	assert_param(IS_HT_TBS_PERIODSET_VTPPERIOD(VTPPeriod));
    uint32_t tempreg = (HT_TBS->VTPPRD & (~(uint32_t)VTPPRDModule));
    tempreg |= VTPPeriod;
    HT_TBS->VTPPRD = tempreg;                             /*!< Config VTP measure period           */
}

/**
*********************************************************************************************************
*                                 SET TPGA GEAR VALUE CNT
*
* @brief: Set TPGA gear value counts
*
* @param: TPGAVal    : TPGA gear value counts
*                          @arg TBS_TPGACnt_2
*                          @arg TBS_TPGACnt_4
*                          @arg TBS_TPGACnt_8
*                          @arg TBS_TPGACnt_16
*
* @retval: None
*
* @note: This function can only be effective after PGA_EN enable.
*********************************************************************************************************
*/
void HT_TBS_TPGAConfig(TBS_TPGACntTypeDef TPGAVal)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_TPGACONFIG(TPGAVal));
    HT_TBS->TBSCON &= (~TBS_TBSCON_TPGA);
    HT_TBS->TBSCON |= ((uint32_t)TPGAVal & (uint32_t)TBS_TBSCON_TPGA);                 /*!< Set TPGA gear value cnt  */
}
#endif

/**
*********************************************************************************************************
*                                     SET COMPARE THRESHOLD
*
* @brief: Set comparison threshold
*
* @param: CmpReg   : This parameter means compare register and can be one of the following values:
*                       @arg CMP_VBAT     : Battery voltage(Vbat) compare register    (If support)
*                       @arg CMP_ADC0     : ADC0 compare register      (If support)
*                       @arg CMP_ADC1     : ADC1 compare register      (If support)
*                       @arg CMP_TDVREF   : TDVREF compare register    (If support)
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_CMPThresholdSet(TBS_CMPRegTypeDef CmpReg, int16_t Threshold)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg));
#if  !defined  USE_TBS_TDVREFCMP
    if(CmpReg == CMP_VBAT)
    {
    HT_TBS->VBATCMP = (uint32_t)Threshold;                /*!< Config battery voltage compare threshold           */
    }
    else
    {
    }
#endif
    
#if  defined  USE_TBS_TDVREFCMP
    if(CmpReg == CMP_TDVREF)
    {
        HT_TBS->TDVREFCMP = (uint32_t)Threshold;                /*!< Config TDVREF compare threshold               */
    }
    else
    {
    }
#endif
    
#if  defined  USE_TBS_ADC0CMP
    if(CmpReg == CMP_ADC0)
    {
        HT_TBS->ADC0CMP = (uint32_t)Threshold;                /*!< Config ADC0 compare threshold               */
    }
    else
    {
    }
#endif
    
#if  defined  USE_TBS_SOC
    if(CmpReg == CMP_ADC1)
    {
        HT_TBS->ADC1CMP = (uint32_t)Threshold;                /*!< Config ADC1 compare threshold               */
    }
    else
    {
    }
#endif
    
}

/**
*********************************************************************************************************
*                                     GET MEASURED VALUES
*
* @brief: Get measured values
*
* @param: SubModule    : Submodule selected, like @arg TBS_TMP
*
* @retval: The return value,which means measured value of selected submodule,is 16-bits signed number.
*
* @note: None
*********************************************************************************************************
*/
int16_t HT_TBS_ValueRead(TBS_SubModuleTypeDef SubModule)
{
    int16_t TBSDAT;
    
    /*  assert_param  */
	assert_param(IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule));
    
    switch(SubModule)
    {
        case TBS_TMP:
            TBSDAT = (int16_t)HT_TBS->TMPDAT;       /*!< Return temperature measured value     */
        	break;
        case TBS_VCC:
            TBSDAT = (int16_t)HT_TBS->VCCDAT;
        	break;
        
#if !defined USE_TBS_TDVREFDAT
        case TBS_VBAT:

            TBSDAT = (int16_t)HT_TBS->VBATDAT;      /*!< Return battery voltage measured value       */
#else
        case TBS_TDVREF:
            TBSDAT = (int16_t)HT_TBS->TDVREFDAT;
#endif
            break;
        case TBS_ADC0:
            TBSDAT = (int16_t)HT_TBS->ADC0DAT;      /*!< Return ADC0 measured value           */
            break;
        case TBS_ADC1:
            TBSDAT = (int16_t)HT_TBS->ADC1DAT;      /*!< Return ADC1 measured value           */
            break;
#if defined USE_TBS_ADC2DAT
        case TBS_ADC2:
            TBSDAT = (int16_t)HT_TBS->ADC2DAT;      /*!< Return ADC2 measured value           */
            break;
#endif
#if defined USE_TBS_ADC3DAT
		case TBS_ADC3:
			TBSDAT = (int16_t)HT_TBS->ADC3DAT;      /*!< Return ADC3 measured value           */
            break;
#endif
#if defined USE_TBS_ADC4DAT
		case TBS_ADC4:
			TBSDAT = (int16_t)HT_TBS->ADC4DAT;      /*!< Return ADC4 measured value           */
            break;
#endif
#if defined USE_TBS_ADC5DAT
		case TBS_ADC5:
			TBSDAT = (int16_t)HT_TBS->ADC5DAT;      /*!< Return ADC5 measured value           */
            break;
#endif
#if defined USE_TBS_ADC6DAT
		case TBS_ADC6:
			TBSDAT = (int16_t)HT_TBS->ADC6DAT;      /*!< Return ADC6 measured value           */
            break;
#endif
#if defined USE_TBS_ADC7DAT
		case TBS_ADC7:
			TBSDAT = (int16_t)HT_TBS->ADC7DAT;      /*!< Return ADC7 measured value           */
            break;
#endif
#if defined USE_TBS_ADC8DAT
		case TBS_ADC8:
			TBSDAT = (int16_t)HT_TBS->ADC8DAT;      /*!< Return ADC8 measured value           */
            break;
#endif
#if defined USE_TBS_ADC9DAT
		case TBS_ADC9:
			TBSDAT = (int16_t)HT_TBS->ADC9DAT;      /*!< Return ADC9 measured value           */
            break;
#endif
#if defined USE_TBS_VTPPRD
		case TBS_VTP0:
			TBSDAT = (int16_t)HT_TBS->VTP0DAT;      /*!< Return VTP0 measured value           */
            break;
		case TBS_VTP1:
			TBSDAT = (int16_t)HT_TBS->VTP1DAT;      /*!< Return VTP1 measured value           */
            break;
		case TBS_VTP2:
			TBSDAT = (int16_t)HT_TBS->VTP2DAT;      /*!< Return VTP2 measured value           */
            break;
		case TBS_VTP3:
			TBSDAT = (int16_t)HT_TBS->VTP3DAT;      /*!< Return VTP3 measured value           */
            break;
		case TBS_VTP4:
			TBSDAT = (int16_t)HT_TBS->VTP4DAT;      /*!< Return VTP4 measured value           */
            break;
		case TBS_VTP5:
			TBSDAT = (int16_t)HT_TBS->VTP5DAT;      /*!< Return VTP5 measured value           */
            break;
		case TBS_VTP6:
			TBSDAT = (int16_t)HT_TBS->VTP6DAT;      /*!< Return VTP6 measured value           */
            break;
		case TBS_VTP7:
			TBSDAT = (int16_t)HT_TBS->VTP7DAT;      /*!< Return VTP7 measured value           */
            break;
#endif
        default:
            TBSDAT = (int16_t)HT_TBS->VCCDAT;       /*!< Return VCC measured value            */
            break;
    }
    return TBSDAT;
}
/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE TBS INTERRUPT
*
* @brief: Enable or disble TBS interrupt
*
* @param: ITEn       This parameter means enable or disable TBS interrupt and can be one or a combination of the following values:
*                        @arg TBS_TBSIE_TMPIE
*                        @arg TBS_TBSIE_VBATIE
*                        @arg TBS_TBSIE_ADC0IE
*                        @arg TBS_TBSIE_ADC1IE
*                        @arg TBS_TBSIE_VBATCMPIE
*                        @arg TBS_TBSIE_TDVREFIE
*                        @arg TBS_TBSIE_TDVREFCMPIE
*                        @arg TBS_TBSIE_VCCIE
*                        @arg TBS_TBSIE_ADC2IE        (If support)
*                        @arg TBS_TBSIE_ADC0CMPIE     (If support)
*                        @arg TBS_TBSIE_ADC1CMPIE     (If support)
*                        @arg TBS_TBSIE_ADC3IE        (If support)
*                        @arg TBS_TBSIE_ADC4IE        (If support)
*                        @arg TBS_TBSIE_ADC5IE        (If support)
*                        @arg TBS_TBSIE_ADC6IE        (If support)
*                        @arg TBS_TBSIE_ADC7IE        (If support)
*                        @arg TBS_TBSIE_ADC8IE        (If support)
*                        @arg TBS_TBSIE_ADC9IE        (If support)
*                        @arg TBS_TBSIE_VTP0IE        (If support)
*                        @arg TBS_TBSIE_VTP1IE        (If support)
*                        @arg TBS_TBSIE_VTP2IE        (If support)
*                        @arg TBS_TBSIE_VTP3IE        (If support)
*                        @arg TBS_TBSIE_VTP4IE        (If support)
*                        @arg TBS_TBSIE_VTP5IE        (If support)
*                        @arg TBS_TBSIE_VTP6IE        (If support)
*                        @arg TBS_TBSIE_VTP7IE        (If support)
*                        @arg TBS_TBSIE_ALLIE
*
*           NewState   = ENABLE : Enable interrupt
*                      = DISABLE : Disable interrupt
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */
    assert_param (IS_HT_TBS_ITCONFIG_ITEN(ITEn));
    if (NewState != DISABLE)
    {
        HT_TBS->TBSIE |= (uint32_t)ITEn;            /*!< Enable TBS interrupt           */
    }
    else
    {
        HT_TBS->TBSIE &= ~(uint32_t)ITEn;           /*!< Disable TBS interrupt           */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED TBS INTERRUPT FLAG STATUS
*
* @brief: Get specified TBS interrupt flag status
*
* @param: ITFlag     This parameter is used to examine one of the specific TBS interrupts and can be one of the following values:
*                        @arg TBS_TBSIF_TMPIF				 
*                        @arg TBS_TBSIF_VBATIF				(If support)
*                        @arg TBS_TBSIF_ADC0IF				 
*                        @arg TBS_TBSIF_ADC1IF				 
*                        @arg TBS_TBSIF_VBATCMPIF			 
*                        @arg TBS_TBSIF_VCCIF				 
*                        @arg TBS_TBSIF_ADC2IF        		(If support)
*                        @arg TBS_TBSIF_ADC0CMPIF           (If support)
*                        @arg TBS_TBSIF_ADC1CMPIF           (If support)
*                        @arg TBS_TBSIF_ADC3IF        		(If support)
*                        @arg TBS_TBSIF_ADC4IF       		(If support)
*                        @arg TBS_TBSIF_ADC5IF        		(If support)
*                        @arg TBS_TBSIF_ADC6IF        		(If support)
*                        @arg TBS_TBSIF_ADC7IF       		(If support)
*                        @arg TBS_TBSIF_ADC8IF        		(If support)
*                        @arg TBS_TBSIF_ADC9IF        		(If support)
*                        @arg TBS_TBSIF_TDVREFIF         	(If support)
*                        @arg TBS_TBSIF_TDVREFCMPIF 		(If support)
*                        @arg TBS_TBSIF_VTP0IF				(If support)
*                        @arg TBS_TBSIF_VTP1IF				(If support)
*                        @arg TBS_TBSIF_VTP2IF				(If support)
*                        @arg TBS_TBSIF_VTP3IF				(If support)
*                        @arg TBS_TBSIF_VTP4IF				(If support)
*                        @arg TBS_TBSIF_VTP5IF				(If support)
*                        @arg TBS_TBSIF_VTP6IF				(If support)
*                        @arg TBS_TBSIF_VTP7IF				(If support)
*
* @reval: ITStatus    = SET : Corresponding interrupt flag set
*                       = RESET : Corresponding interrupt flag reset
*
* @note: None
*********************************************************************************************************
*/
ITStatus HT_TBS_ITFlagStatusGet(uint32_t ITFlag)
{
	ITStatus SETSTATUS;
	
    /*  assert_param  */
	assert_param (IS_HT_TBS_ITFLAG(ITFlag));
        
    if (HT_TBS->TBSIF & ITFlag)
    {
        SETSTATUS = SET;                        /*!< TBS Interrupt Flag is set   */
    }
    else
    {
        SETSTATUS = RESET;                      /*!< TBS Interrupt Flag is reset */
    }
    return SETSTATUS;
}

/**
*********************************************************************************************************
*                                   CLEAR TBS INTERRUPT FLAG
*
* @brief: Clear TBS interrupt flag
*
* @param: ITFlag     This parameter is used to clear one of the specific TBS interrupts and can be one or
*						a combination of the following values.
*                        @arg TBS_TBSIF_TMPIF				  
*                        @arg TBS_TBSIF_VBATIF				 (If support)
*                        @arg TBS_TBSIF_ADC0IF				  
*                        @arg TBS_TBSIF_ADC1IF				 (If support)
*                        @arg TBS_TBSIF_VBATCMPIF			 (If support)
*                        @arg TBS_TBSIF_VCCIF				  
*                        @arg TBS_TBSIF_ADC2IF       		 (If support)
*                        @arg TBS_TBSIF_ADC0CMPIF            (If support)
*                        @arg TBS_TBSIF_ADC1CMPIF            (If support)
*                        @arg TBS_TBSIF_ADC3IF        		 (If support)
*                        @arg TBS_TBSIF_ADC4IF        		 (If support)
*                        @arg TBS_TBSIF_ADC5IF        		 (If support)
*                        @arg TBS_TBSIF_ADC6IF       		 (If support)
*                        @arg TBS_TBSIF_ADC7IF        		 (If support)
*                        @arg TBS_TBSIF_ADC8IF        		 (If support)
*                        @arg TBS_TBSIF_ADC9IF       		 (If support)
*                        @arg TBS_TBSIF_TDVREFIF        	 (If support)
*                        @arg TBS_TBSIF_TDVREFCMPIF 		 (If support)
*                        @arg TBS_TBSIF_VTP0IF				 (If support)
*                        @arg TBS_TBSIF_VTP1IF				 (If support)
*                        @arg TBS_TBSIF_VTP2IF				 (If support)
*                        @arg TBS_TBSIF_VTP3IF				 (If support)
*                        @arg TBS_TBSIF_VTP4IF				 (If support)
*                        @arg TBS_TBSIF_VTP5IF				 (If support)
*                        @arg TBS_TBSIF_VTP6IF				 (If support)
*                        @arg TBS_TBSIF_VTP7IF				 (If support)
*
* @reval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_ClearITPendingBit(uint32_t ITFlag)
{
    /*  assert_param  */
	assert_param (IS_HT_TBS_ITFLAG(ITFlag));
    HT_TBS->TBSIF   = ~((uint32_t)ITFlag);                  /*!< Clear TBS Interrupt Flag       */
}

/**
*********************************************************************************************************
*                                 SET TBS FILTER VALUE CNT
*
* @brief: Set TBS fillter value counts
*
* @param: FilterVal    : Filter counts
*                          @arg TBS_ADCFilterCnt_1
*                          @arg TBS_ADCFilterCnt_2
*                          @arg TBS_ADCFilterCnt_4
*                          @arg TBS_ADCFilterCnt_8
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
void HT_TBS_FilCntConfig(TBS_ADCFilterCntTypeDef FilterVal)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_FILCNTCONFIG(FilterVal));
    HT_TBS->TBSCON &= (~TBS_TBSCON_FILTER);
    HT_TBS->TBSCON |= ((uint32_t)FilterVal & (uint32_t)TBS_TBSCON_FILTER);                 /*!< Set TBS filter value cnt  */
}

#if  defined  USE_TBS_TBSCON_TBSCLKSEL
/**
*********************************************************************************************************
*                                 SELECT TBS CLOCK
*
* @brief: Select TBS clock
*
* @param: ClkSel    : TBS clock source select
*                        @arg TBS_CLKSEL_OSC          (If support)
*                        @arg TBS_CLKSEL_PLLDIV       (If support)
*                        @arg TBS_CLKSEL_LRC		  (If support)
*                        @arg TBS_CLKSEL_LSTBSCLK_10  (If support)
*                        @arg TBS_CLKSEL_LSTBSCLK_11  (If support)
*
* @retval: result    : Result of TBS clock select
*                       TBS_CLKSEL_SUCC       TBS clock switch succeed
*                       TBS_CLKSEL_PARA_ERR   The input parameter is wrong when this function is called
*                       TBS_CLKSEL_PLL_EN_ERR Request to switch to PLL clock when PLL clock abnormal work
*
* @note: Recommend to configure with HT_TBSConfig
*********************************************************************************************************
*/
TBS_ClkSelReturnTypeDef HT_TBS_ClkSelConfig(TBS_ClkSelectTypeDef ClkSel)
{
    TBS_ClkSelReturnTypeDef result = TBS_CLKSEL_SUCC;
    FlagStatus Errflag = RESET;

    /*  assert_param  */
	assert_param (IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel));
    switch (ClkSel)
    {
		case TBS_CLKSEL_OSC:
            HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
            HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
            break;
#if defined USE_TBS_MCU
#if !defined USE_TBS_TBSCON_TBSCLKSEL_2BIT
        case TBS_CLKSEL_PLLDIV:
            if (ClkSel == TBS_CLKSEL_PLLDIV)
            {
	              if ((HT_CMU->CLKCTRL0 & CMU_CLKCTRL0_PLLEN) != CMU_CLKCTRL0_PLLEN)
	              {
	               Errflag = SET;
	              }
	              if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLLOCK) != CMU_CLKSTA_PLLLOCK)
	              {
	                Errflag = SET;
	              }
	              if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLFLAG) == CMU_CLKSTA_PLLFLAG)
	              {
	                Errflag = SET;
	              }
	              if (Errflag == SET)
	              {
	                  HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                      HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
	                  result = TBS_CLKSEL_PLL_EN_ERR;
	              }
	              else
	              {
                      HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                      HT_TBS->TBSCON |= TBS_CLKSEL_PLLDIV;
	                  result = TBS_CLKSEL_SUCC;                          
	              }
	        }
	        else
	        {
	              HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                  HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
	              result = TBS_CLKSEL_SUCC;
	        }
	        break;
#elif defined USE_TBS_TBSCON_TBSCLKSEL_2BIT
        case TBS_CLKSEL_LRC:
            HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
            HT_TBS->TBSCON |= TBS_CLKSEL_LRC;
            break;
        case TBS_CLKSEL_LSTBSCLK_10:
                if (ClkSel == TBS_CLKSEL_LSTBSCLK_10)
                  {
                      if ((HT_CMU->CLKCTRL0 & CMU_CLKCTRL0_PLLEN) != CMU_CLKCTRL0_PLLEN)
                      {
                       Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLLOCK) != CMU_CLKSTA_PLLLOCK)
                      {
                        Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLFLAG) == CMU_CLKSTA_PLLFLAG)
                      {
                        Errflag = SET;
                      }
                      if (Errflag == SET)
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                          result = TBS_CLKSEL_PLL_EN_ERR;
                      }
                      else
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_LSTBSCLK_10;
                          result = TBS_CLKSEL_SUCC;
                          
                      }
                  }
                  else
                  {
                    HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                    HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                    result = TBS_CLKSEL_PLL_EN_ERR;
                  }
            break;
		case TBS_CLKSEL_LSTBSCLK_11:
                if (ClkSel == TBS_CLKSEL_LSTBSCLK_11)
                  {
                      if ((HT_CMU->CLKCTRL0 & CMU_CLKCTRL0_PLLEN) != CMU_CLKCTRL0_PLLEN)
                      {
                       Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLLOCK) != CMU_CLKSTA_PLLLOCK)
                      {
                        Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLFLAG) == CMU_CLKSTA_PLLFLAG)
                      {
                        Errflag = SET;
                      }
                      if (Errflag == SET)
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                          result = TBS_CLKSEL_PLL_EN_ERR;
                      }
                      else
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_LSTBSCLK_11;
                          result = TBS_CLKSEL_SUCC;
                      }
                  }
#endif
#elif defined USE_TBS_SOC
        case TBS_CLKSEL_LRC:
            HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
            HT_TBS->TBSCON |= TBS_CLKSEL_LRC;
            break;
        case TBS_CLKSEL_LSTBSCLK_10:
                if (ClkSel == TBS_CLKSEL_LSTBSCLK_10)
                  {
                      if ((HT_CMU->CLKCTRL0 & CMU_CLKCTRL0_PLLEN) != CMU_CLKCTRL0_PLLEN)
                      {
                       Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLLOCK) != CMU_CLKSTA_PLLLOCK)
                      {
                        Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLFLAG) == CMU_CLKSTA_PLLFLAG)
                      {
                        Errflag = SET;
                      }
                      if (Errflag == SET)
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                          result = TBS_CLKSEL_PLL_EN_ERR;
                      }
                      else
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_LSTBSCLK_10;
                          result = TBS_CLKSEL_SUCC;
                          
                      }
                  }
                  else
                  {
                    HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                    HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                    result = TBS_CLKSEL_PLL_EN_ERR;
                  }
            break;
		case TBS_CLKSEL_LSTBSCLK_11:
                if (ClkSel == TBS_CLKSEL_LSTBSCLK_11)
                  {
                      if ((HT_CMU->CLKCTRL0 & CMU_CLKCTRL0_PLLEN) != CMU_CLKCTRL0_PLLEN)
                      {
                       Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLLOCK) != CMU_CLKSTA_PLLLOCK)
                      {
                        Errflag = SET;
                      }
                      if ((HT_CMU->CLKSTA & CMU_CLKSTA_PLLFLAG) == CMU_CLKSTA_PLLFLAG)
                      {
                        Errflag = SET;
                      }
                      if (Errflag == SET)
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                          result = TBS_CLKSEL_PLL_EN_ERR;
                      }
                      else
                      {
                          HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                          HT_TBS->TBSCON |= TBS_CLKSEL_LSTBSCLK_11;
                          result = TBS_CLKSEL_SUCC;
                          
                      }
                  }
              else
              {
                HT_TBS->TBSCON &= ~TBS_TBSCON_TBSCLKSEL;
                HT_TBS->TBSCON |= TBS_CLKSEL_OSC;
                result = TBS_CLKSEL_SUCC;
              }
              break;
		#endif
        default:
            result = TBS_CLKSEL_PARA_ERR;
            break;
    }

    return result;
}

/**
*********************************************************************************************************
*                                   Quick trigger TBS sampling(only one time,auto clear after finished)
*
* @brief:  Quick trigger TBS sampling
*
* @param: TriChn     Trigger channel:
*                      @arg TBS_TRI_TMP                  (If support)
*                      @arg TBS_TRI_VBAT                 (If support)
*                      @arg TBS_TRI_ADC0                 (If support)
*                      @arg TBS_TRI_ADC1                 (If support)
*                      @arg TBS_TRI_VCC                  (If support)
*                      @arg TBS_TRI_VDD                  (If support)
*                      @arg TBS_TRI_ADC3                 (If support)
*                      @arg TBS_TRI_ADC4                 (If support)
*                      @arg TBS_TRI_ADC5                 (If support)
*                      @arg TBS_TRI_ADC6                 (If support)
*                      @arg TBS_TRI_ADC7                 (If support)
*                      @arg TBS_TRI_ADC8                 (If support)
*                      @arg TBS_TRI_ADC9                 (If support)
*                      @arg TBS_TRI_TDVREF               (If support)
*                      @arg TBS_TRI_VTP0                 (If support)
*                      @arg TBS_TRI_VTP1                 (If support)
*                      @arg TBS_TRI_VTP2                 (If support)
*                      @arg TBS_TRI_VTP3                 (If support)
*                      @arg TBS_TRI_VTP4                 (If support)
*                      @arg TBS_TRI_VTP5                 (If support)
*                      @arg TBS_TRI_VTP6                 (If support)
*                      @arg TBS_TRI_VTP7                 (If support)
* @retval: None
*
* @note: Attention ! Need to enable TBS_NEWREG_En first of HT6x2xK.
*********************************************************************************************************
*/
void HT_TBS_ADCTriSample(TBS_TriChnTypeDef TriChn)
{
    /*  assert_param  */
	assert_param(IS_HT_TBS_ADCTRISAMPLE(TriChn));
    HT_TBS->TRIREQ &= ~TBS_TRIREQ;
    HT_TBS->TRIREQ |= ((uint32_t)TriChn & (uint32_t)TBS_TRIREQ);                /*!< Set TBS quick trigger mode  */
}
#endif

#if defined USE_TBS_TBSINJECTCTRL
/**
*********************************************************************************************************
*                                                    Injection TBS sampling
* @brief:  Injection TBS sampling
*
* @param: InjectChn     Inject channel:
*                      @arg TBS_INJECT_TMP             (If support)
*                      @arg TBS_INJECT_VBAT            (If support)
*                      @arg TBS_INJECT_ADC0            (If support)
*                      @arg TBS_INJECT_ADC1            (If support)
*                      @arg TBS_INJECT_VCC             (If support)
*                      @arg TBS_INJECT_VDD             (If support)
*                      @arg TBS_INJECT_ADC2            (If support)
*                      @arg TBS_INJECT_ADC3            (If support)
*                      @arg TBS_INJECT_ADC4            (If support)
*                      @arg TBS_INJECT_ADC5            (If support)
*                      @arg TBS_INJECT_ADC6            (If support)
*                      @arg TBS_INJECT_ADC7            (If support)
*                      @arg TBS_INJECT_ADC8            (If support)
*                      @arg TBS_INJECT_ADC9            (If support)
*                      @arg TBS_INJECT_TDVREF          (If support)
* @retval: None
*
* @note: Attention ! Need to enable TBS_NEWREG_En first of HT6x2xK.
*********************************************************************************************************
*/
void HT_TBS_ADCInjectSample(TBS_InjectChnTypeDef InjectChn)
{
	/*	assert_param  */
	assert_param(IS_HT_TBS_ADCINJECTSAMPLE(InjectChn));
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON |= TBS_TBSCON_TBS_NEWREG_En;
#endif
	HT_TBS->TBSINJECTCTRL &= ~TBS_TBSINJECTCTRL_INJECTCHEL_SEL;
	HT_TBS->TBSINJECTCTRL |= (InjectChn & TBS_TBSINJECTCTRL);                                              /*!< Set TBS injection channel  */
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON &= ~TBS_TBSCON_TBS_NEWREG_En;
#endif
}

#if  defined  TBS_TBSINJECTCTRL_INJECTCLK_EN
/**
*********************************************************************************************************
*                                                  TBS  Injection  Clock Control  Config
* @brief:  Injection TBS clock control enable
*
* @param:   INJECTClkSel : can choose from 0 to 7.     
*			NewState   = ENABLE : Enable interrupt
*                      = DISABLE : Disable interrupt                 
*
* @note:   InjectClkSel will only be effective when NewState = ENABLE.
*********************************************************************************************************
*/
void HT_TBS_InjectClkConfig(uint32_t InjectClkSel,FunctionalState NewState)
{
	/*	assert_param  */
    assert_param(IS_HT_TBS_INJECTCLKCFG(InjectClkSel));
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON |= TBS_TBSCON_TBS_NEWREG_En;
#endif
	if (NewState != DISABLE)
    {
        HT_TBS->TBSINJECTCTRL &= ~(TBS_TBSINJECTCTRL_INJECTCLK_EN | TBS_TBSINJECTCTRL_INJECTCLK_SEL);
		HT_TBS->TBSINJECTCTRL |= TBS_TBSINJECTCTRL_INJECTCLK_EN;              /*!< Enable TBS injection clock control   */
        HT_TBS->TBSINJECTCTRL |= ((((uint32_t)InjectClkSel<<8) & TBS_TBSINJECTCTRL_INJECTCLK_SEL) & TBS_TBSINJECTCTRL);
    }
	else
    {
		HT_TBS->TBSINJECTCTRL &= ~TBS_TBSINJECTCTRL_INJECTCLK_EN;            /*!< Disable TBS injection clock control   */
    }
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON &= ~TBS_TBSCON_TBS_NEWREG_En;
#endif
}
#endif

/**
*********************************************************************************************************
*                                                  TBS  Injection  Mode  Config
* @brief:  Injection TBS enable
*
* @param:        NewState   = ENABLE : Enable interrupt
*                      = DISABLE : Disable interrupt
*
* @note: Recommand to Enable injection mode before set the injection channel
*********************************************************************************************************
*/
void HT_TBS_ADCInjectConfig(FunctionalState NewState)
{
	/*	assert_param  */
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON |= TBS_TBSCON_TBS_NEWREG_En;
#endif
	if (NewState != DISABLE)
    {
		HT_TBS->TBSINJECTCTRL |= TBS_TBSINJECTCTRL_INJECTMODE_EN;              /*!< Enable TBS injection mode   */
#if defined TBS_TBSINJECTCTRL_EN
        HT_TBS->TBSINJECTCTRL |= TBS_TBSINJECTCTRL_EN;
#endif
    }
	else
    {
		HT_TBS->TBSINJECTCTRL &= ~TBS_TBSINJECTCTRL_INJECTMODE_EN;          /*!< Disable TBS injection mode   */
    }
#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON &= ~TBS_TBSCON_TBS_NEWREG_En;
#endif
}
#endif



/**
*********************************************************************************************************
*                                                  Reset TBS Module
* @brief:  Reset TBS module to initial state
*
* @param:        NewState   = RESET : Reset TBS module
*                      = SET : No change
*
* @note: Reset all registers to default value but data registers.
*********************************************************************************************************
*/
void HT_TBS_TBSReset(void)
{
    /*	assert_param  */

#if defined TBS_TBSCON_TBS_NEWREG_En
    HT_TBS->TBSCON |= TBS_TBSCON_TBS_NEWREG_En;
#endif
        HT_TBS->TBSPRD = RESET;
        HT_TBS->TBSIE  = RESET;
        HT_TBS->TBSIF  = TBS_TBSIF_TMPIF;
        
#if  defined  TBS_ADC0CMP
        HT_TBS->ADC0CMP = RESET;
#endif
        
#if  defined  TBS_ADC1CMP
        HT_TBS->ADC1CMP = RESET;
#endif
        
#if  defined  TBS_TDVREFCMP
        HT_TBS->TDVREFCMP = RESET;
#endif
        
#if  defined  TBS_VBATCMP
        HT_TBS->VBATCMP = RESET;
#endif
        
#if  defined  TBS_TRIREQ
        HT_TBS->TRIREQ = RESET;
#endif
        
#if  defined  TBS_TBSINJECTCTRL
        HT_TBS->TBSINJECTCTRL = RESET;
#if  defined  USE_TBS_MCU
        HT_TBS->TBSINJECTCTRL = TBS_TBSINJECTCTRL_DEFAULT;
#endif
#endif
        
#if  defined  TBS_VTPPRD
        HT_TBS->VTPPRD = RESET;
#endif
        HT_TBS->TBSCON = TBS_TBSCON_OSC_CONFIG | TBS_TBSCON_TMPEn;

}


