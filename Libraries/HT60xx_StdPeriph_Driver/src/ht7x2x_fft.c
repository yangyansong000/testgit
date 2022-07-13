/*
*********************************************************************************************************
*                                              HT7X2X
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT7x2x
* File         : ht7x2x_fft.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_FFT_C

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
#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
static void FFT_InitCallbacksToDefault(FFT_InitTypeDef *FFT_InitStruct);
static void FFT_SINGLE_IT(FFT_InitTypeDef *FFT_InitStruct);
static void FFT_DONE_IT(FFT_InitTypeDef *FFT_InitStruct);
#endif



/**
*********************************************************************************************************
*                                         INITIAL FFT MODULE
* @brief:   FFT initial
*
* @param:   FFT_InitStruct      pointer to the Initial structure 
*                               
*                               
*                               
*
* @retval:  Status
*
*********************************************************************************************************
*/
StatusTypeDef HT_FFT_Init(FFT_InitTypeDef *FFT_InitStruct)
{
	StatusTypeDef status = OK;
	
	if(FFT_InitStruct == NULL)
	{
		status = ERROR;
	}
	else
	{		
    HT_FFT_ABORT();
    assert_param(IS_HT_FFT_SOFTMODE(FFT_InitStruct->SoftMode));
    assert_param(IS_HT_FFT_FFTMODE(FFT_InitStruct->FFT_Point));
    assert_param(IS_HT_FFT_IODTYPE(FFT_InitStruct->IodMode));
    assert_param(IS_HT_FFT_NORTYPE(FFT_InitStruct->NorMode));
    assert_param(IS_HT_FFT_NUMBER(FFT_InitStruct->FFT_Number));
    assert_param(IS_HT_FFT_INVTYPE(FFT_InitStruct->InvMode));
    HT_FFT->FFTCFG = ((uint32_t)(FFT_InitStruct->SoftMode) | (FFT_InitStruct->InvMode) |\
                      ((FFT_InitStruct->FFT_Number<<5)&FFT_FFTCFG_NUM_FFTS) | (FFT_InitStruct->NorMode) |\
                      (FFT_InitStruct->IodMode) | (FFT_InitStruct->FFT_Point));
    
    assert_param(IS_HT_FFT_SRC_BW(FFT_InitStruct->SourceBitWidth));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel0));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel1));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel2));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel3));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel4));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel5));
    assert_param(IS_HT_FFT_RSHIFT(FFT_InitStruct->R_Shift_channel6));
    HT_FFT->FFT_SRC_DMA_CTL = ((FFT_InitStruct->SourceBitWidth) | ((FFT_InitStruct->R_Shift_channel6)<<FFT_CH6) |\
                              ((FFT_InitStruct->R_Shift_channel5)<<FFT_CH5) | ((FFT_InitStruct->R_Shift_channel4)<<FFT_CH4) |\
                              ((FFT_InitStruct->R_Shift_channel3)<<FFT_CH3) | ((FFT_InitStruct->R_Shift_channel2)<<FFT_CH2) |\
                              ((FFT_InitStruct->R_Shift_channel1)<<FFT_CH1) | ((FFT_InitStruct->R_Shift_channel0)<<FFT_CH0) );
    HT_FFT->FFT_SRC_DMA_ADDR = FFT_InitStruct->SourceBaseAddress;
    HT_FFT->FFT_START_OFFSET = FFT_InitStruct->SourceStartOffset;
    HT_FFT->FFT_BUFLEN = FFT_InitStruct->BufferLength;
    
    assert_param(IS_HT_FFT_FUNDIDX(FFT_InitStruct->FundIdex));
    assert_param(IS_HT_FFT_SCALE(FFT_InitStruct->Scale));
    assert_param(IS_HT_FFT_DST_BW(FFT_InitStruct->DestBitWidth));
    HT_FFT->FFT_DST_DMA_CTL = ((FFT_InitStruct->FundIdex)<<FUNDIDX_SHIFT)|(FFT_InitStruct->Scale)|(FFT_InitStruct->DestBitWidth);
    
    HT_FFT->FFT_DST_DMA_ADDR = FFT_InitStruct->DestBaseAddress;
    
	#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
		FFT_InitCallbacksToDefault(FFT_InitStruct);
		FFT_InitStruct->Instance = HT_FFT;
	#endif

	}
	return status;
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE FFT INTERRUPT
*
* @brief:   enable or disable FFT interrupt
*
* @param:   ITEn       FFT interrupt set, it can be one or a combination of the following parameters:
*                      @arg FFT_FFTIE_FFT_IE
*                      @arg FFT_FFTIE_FFT_DONE_IE 
*
*           NewState   = ENABLE: enable interrupt
*                      = DISABLE:disable interrupt
* @retval:  none
*
*********************************************************************************************************
*/
void HT_FFT_ITConfig(uint32_t ITEn,FunctionalState NewState)
{
	assert_param(IS_HT_FFT_IE(ITEn));
	if(NewState != DISABLE)
	{
		HT_FFT->FFTIE |= (ITEn & FFT_FFTIE);
	}
	else
	{
		HT_FFT->FFTIE &= ~ITEn;
	}
}

/**
*********************************************************************************************************
*                            GET SPECIFIED FFT INTERRUPT FLAG STATUS
*
* @brief:   get FFT interrupt flag status
*
* @param:   ITFlag     FFT interrupt flag check, it can be one or a combination of the following parameters:
*                      @arg FFT_FFTIF_FFT_IF
*                      @arg FFT_FFTIF_FFT_DONE_IF
*
* @retval:  ITStatus    = SET:  the interrupt flag produced
*                       = RESET:the interrupt flag not produced
*
*********************************************************************************************************
*/
ITStatus HT_FFT_ITFlagStatusGet(uint32_t ITFlag)
{
	FlagStatus status = RESET;
	assert_param(IS_HT_FFT_IF(ITFlag));
	if (HT_FFT->FFTIF & ITFlag)
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
*                                CLEAR FFT INTERRUPT FLAG
*
* @brief:   clear FFT interrupt flag
*
* @param:   ITFlag     FFT interrupt flag clear,It can be a combination of the following parameters:
*                      @arg FFT_FFTIF_FFT_IF
*                      @arg FFT_FFTIF_FFT_DONE_IF
*
* @retval:  none
*
* @note:    if FFTERR is not 0, FFTERR must be cleared first
*********************************************************************************************************
*/
void HT_FFT_ClearITPendingBit(uint32_t ITFlag)
{
  /*  assert_param  */
  assert_param(IS_HT_FFT_IF(ITFlag));
  HT_FFT->FFTIF  = ITFlag;              
}

/**
*********************************************************************************************************
*                            GET SPECIFIED FFT ERROR STATUS
*
* @brief:   get FFT error status
*
* @param:   ErrFlag    FFT error flag check, it can be one or a combination of the following parameters:
*                      @arg FFT_FFTERR_CLIPE
*                      @arg FFT_FFTERR_CLIPIN
*                      @arg FFT_FFTERR_CLIPOUT
*
* @retval:  ErrStatus   = SET:  the error flag produced
*                       = RESET:the error flag not produced
*
*********************************************************************************************************
*/
ITStatus HT_FFT_ErrStatusGet(uint32_t ErrFlag)
{
	FlagStatus status = RESET;
	assert_param(IS_HT_FFT_ERR(ErrFlag));
	if (HT_FFT->FFTERR & ErrFlag)
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
*                                CLEAR FFT ERROR FLAG
*
* @brief:   clear FFT error flag
*
* @param:   ErrFlag    FFT error flag clear,It can be a combination of the following parameters:
*                      @arg FFT_FFTERR_CLIPE
*                      @arg FFT_FFTERR_CLIPIN
*                      @arg FFT_FFTERR_CLIPOUT
*
* @retval:  none
*
*********************************************************************************************************
*/
void HT_FFT_ClearErrPendingBit(uint32_t ErrFlag)
{
  /*  assert_param  */
  assert_param(IS_HT_FFT_ERR(ErrFlag));
  HT_FFT->FFTERR = ErrFlag;             
}

/**
*********************************************************************************************************
*                            GET FFT NUMBER STATUS
*
* @brief:   get FFT number flag status
*
* @param:   none
*
* @retval:  number    
*
*********************************************************************************************************
*/
uint32_t HT_FFT_NumberStatusGet(void)
{
	return (HT_FFT->FFT_NUMS);
}

/**
*********************************************************************************************************
*                          GET FFT FUND SHIFT STATUS
*
* @brief:   get FFT fundamental wave shift status
*
* @param:   FFT_Channel_TypeDef    FFT channel select,It can be one or a combination of the following parameters:
*                                  @arg Chn_0  (FFT_CH0)
*                                  @arg Chn_1  (FFT_CH1)
*                                  @arg Chn_2  (FFT_CH2)
*                                  @arg Chn_3  (FFT_CH3)
*                                  @arg Chn_4  (FFT_CH4)
*                                  @arg Chn_5  (FFT_CH5)
*                                  @arg Chn_6  (FFT_CH6)
*
* @retval:  number    
*
*********************************************************************************************************
*/
uint32_t HT_FFT_FunShiftStatusGet(FFT_Channel_TypeDef channel)
{
  assert_param(IS_HT_FFT_CHANNEL(channel));
	return (((HT_FFT->FFT_DST_FUNDSCALE)>>channel)&SHIFT_Mask);
}

/**
*********************************************************************************************************
*                          GET FFT NONFUND SHIFT STATUS
*
* @brief:   get FFT non fundamental wave shift status
*
* @param:   FFT_Channel_TypeDef    FFT channel select,It can be one or a combination of the following parameters:
*                                  @arg Chn_0  (FFT_CH0)
*                                  @arg Chn_1  (FFT_CH1)
*                                  @arg Chn_2  (FFT_CH2)
*                                  @arg Chn_3  (FFT_CH3)
*                                  @arg Chn_4  (FFT_CH4)
*                                  @arg Chn_5  (FFT_CH5)
*                                  @arg Chn_6  (FFT_CH6)
*
* @retval:  number    
*
*********************************************************************************************************
*/
uint32_t HT_FFT_NonFunShiftStatusGet(FFT_Channel_TypeDef channel)
{
  assert_param(IS_HT_FFT_CHANNEL(channel));
	return (((HT_FFT->FFT_DST_NONFUNDSCALE)>>channel)&SHIFT_Mask);
}

#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)

/**
* @brief  Register a User FFT Callback
*         To be used instead of the weak predefined callback
* @param  FFT_InitStruct FFT handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*         @arg @ref FFT_SINGLE_COMPLETE_CB_ID 
*         @arg @ref FFT_DONE_COMPLETE_CB_ID 
* @param  pCallback pointer to the Callback function
* @retval status
*/
StatusTypeDef HT_FFT_RegisterCallback(FFT_InitTypeDef *FFT_InitStruct, FFT_CallbackIDTypeDef CallbackID, pFFT_CallbackTypeDef pCallback)
{
	StatusTypeDef status = OK;

	if (pCallback == NULL)
	{
		/* Update the error code */
		FFT_InitStruct->ErrorCode |= FFT_ERROR_INVALID_CALLBACK;
		/* return status;*/
		status = ERROR;
	}
	else
	{
		switch (CallbackID)
		{
			case FFT_SINGLE_COMPLETE_CB_ID :
				FFT_InitStruct->FftSingleCpltCallback = pCallback;
			break;
      case FFT_DONE_COMPLETE_CB_ID :
				FFT_InitStruct->FftDoneCpltCallback = pCallback;
			break;
			default :
				/* Update the error code */
				FFT_InitStruct->ErrorCode |= FFT_ERROR_INVALID_CALLBACK;
				/* Return error status */
				status =  ERROR;
			break;
		}
	}
	return status;
}

/**
*********************************************************************************************************
*                                       INITIAL FFT CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: FFT_InitStruct Pointer to a FFT_InitTypeDef structure that contains
*               the configuration information for the specified FFT module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FFT_InitCallbacksToDefault(FFT_InitTypeDef *FFT_InitStruct)
{
	FFT_InitStruct->FftSingleCpltCallback = HT_FFT_SingleCpltCallback;
    FFT_InitStruct->FftDoneCpltCallback   = HT_FFT_DoneCpltCallback;
}

/**
*********************************************************************************************************
*                                       FFT SINGLE IT HANDLER
*
* @brief: This function handles FFT SINGLE interrupt request
*
* @param: FFT_InitStruct Pointer to a FFT_InitTypeDef structure that contains
*               the configuration information for the specified FFT module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FFT_SINGLE_IT(FFT_InitTypeDef *FFT_InitStruct)
{
	if(FFT_InitStruct->FftSingleCpltCallback != NULL)
	{
		FFT_InitStruct->FftSingleCpltCallback(FFT_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                       FFT DONE IT HANDLER
*
* @brief: This function handles FFT DONE interrupt request
*
* @param: FFT_InitStruct Pointer to a FFT_InitTypeDef structure that contains
*               the configuration information for the specified FFT module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void FFT_DONE_IT(FFT_InitTypeDef *FFT_InitStruct)
{
	if(FFT_InitStruct->FftDoneCpltCallback != NULL)
	{
		FFT_InitStruct->FftDoneCpltCallback(FFT_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                   FFT IRQ HANDLER
*
* @brief: This function handles FRAMPACK interrupt request.
*
* @param: FFT_InitStruct  Pointer to a FFT_InitTypeDef structure that contains
*                the configuration information for the specified FFT module.
* @retval: None
*
* @note:    if FFTERR is not 0, FFTERR must be cleared first
*********************************************************************************************************
*/
void HT_FFT_IRQHandler(FFT_InitTypeDef *FFT_InitStruct)
{
	uint32_t isrflags   = READ_REG(FFT_InitStruct->Instance->FFTIF);
	uint32_t cr1its     = READ_REG(FFT_InitStruct->Instance->FFTIE);
	
	if(((isrflags & FFT_FFTIF_FFT_IF) != RESET) && ((cr1its & FFT_FFTIE_FFT_IE) != RESET))
	{
		FFT_SINGLE_IT(FFT_InitStruct);
        HT_FFT_ClearErrPendingBit(FFT_FFTERR_CLIPE);
        HT_FFT_ClearErrPendingBit(FFT_FFTERR_CLIPIN);
        HT_FFT_ClearErrPendingBit(FFT_FFTERR_CLIPOUT);
		HT_FFT_ClearITPendingBit(FFT_FFTIF_FFT_IF);
	}
  if(((isrflags & FFT_FFTIF_FFT_IF) != RESET) && ((cr1its & FFT_FFTIE_FFT_DONE_IE) != RESET))
	{
		FFT_DONE_IT(FFT_InitStruct);
		HT_FFT_ClearITPendingBit(FFT_FFTIF_FFT_DONE_IF);
	}
}

/**
*********************************************************************************************************
*                                     FFT SINGLE COMPLETE CALLBACK
*
* @brief: FFT single completed callbacks.
*
* @param: FFT  Pointer to a FFT_InitTypeDef structure that contains
*                the configuration information for the specified FFT module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FFT_SingleCpltCallback(FFT_InitTypeDef *FFT_InitStruct)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(FFT_InitStruct);
	/* NOTE: This function should not be modified, when the callback is needed,
		the HT_FFT_SingleCpltCallback could be implemented in the user file
	*/
}

/**
*********************************************************************************************************
*                                     FFT DONE COMPLETE CALLBACK
*
* @brief: FFT DONE completed callbacks.
*
* @param: FFT  Pointer to a FFT_InitTypeDef structure that contains
*                the configuration information for the specified FFT module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_FFT_DoneCpltCallback(FFT_InitTypeDef *FFT_InitStruct)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(FFT_InitStruct);
	/* NOTE: This function should not be modified, when the callback is needed,
		the HT_FFT_DoneCpltCallback could be implemented in the user file
	*/
}

#endif
