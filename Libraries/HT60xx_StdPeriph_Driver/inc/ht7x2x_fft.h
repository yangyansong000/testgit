/*
*********************************************************************************************************
*                                              HT7X2X
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT7x2x
* File         : ht7x2x_fft.h
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
**********************************************************************************************************
*/

#ifndef __HT7X2X_FFT_H__
#define __HT7X2X_FFT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/**
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

#define FFT_CH0   0U
#define FFT_CH1   4U
#define FFT_CH2   8U
#define FFT_CH3  12U
#define FFT_CH4  16U
#define FFT_CH5  20U  
#define FFT_CH6  24U
#define FFT_CH_ALL  (FFT_CH0 |   FFT_CH1 |   FFT_CH2 |   FFT_CH3 |   FFT_CH4 |   FFT_CH5 |   FFT_CH6)

#define FUNDIDX_SHIFT 16U  
#define SHIFT_Mask    0xFU
  
/**
* @brief  FFT channel enumeration definition
*/
typedef enum
{
  Chn_0 = FFT_CH0,
  Chn_1 = FFT_CH1,
  Chn_2 = FFT_CH2,
  Chn_3 = FFT_CH3,
  Chn_4 = FFT_CH4,
  Chn_5 = FFT_CH5,
  Chn_6 = FFT_CH6,
}FFT_Channel_TypeDef;  
  
/**
* @brief  FFT mode enumeration definition
*/
typedef enum
{
  Point_Mode_64  = FFT_FFTCFG_FFTMODE_64, 
  Point_Mode_128 = FFT_FFTCFG_FFTMODE_128,
  Point_Mode_256 = FFT_FFTCFG_FFTMODE_256,
  Point_Mode_512 = FFT_FFTCFG_FFTMODE_512,
}FFT_Mode_TypeDef;

/**
* @brief  FFT iod enumeration definition
*/
typedef enum
{
  Iod_CC = FFT_FFTCFG_IODTYPE_C_C, 
  Iod_RC = FFT_FFTCFG_IODTYPE_R_C,
}FFT_IOD_TypeDef;

/**
* @brief  FFT Normalization factor enumeration definition
*/
typedef enum
{
  Nor_N     = FFT_FFTCFG_NOR_SQRTN_N, 
  Nor_SQR_N = FFT_FFTCFG_NOR_SQRTN_SQRT,
}FFT_NOR_TypeDef;

/**
* @brief  FFT INV enumeration definition
*/
typedef enum
{
  Inv_FFT  = FFT_FFTCFG_INV_FFT, 
  Inv_IFFT = FFT_FFTCFG_INV_IFFT,
}FFT_INV_TypeDef;

/**
* @brief  FFT software/hardware enumeration definition
*/
typedef enum
{
  HardwareMode = ((uint32_t)0x0000),  
  SoftwareMode = FFT_FFTCFG_SOFT_EN,
}FFT_Soft_TypeDef;


/**
* @brief  FFT source bit width enumeration definition
*/
typedef enum
{
  SourceWidth_16bit = FFT_SRC_DMA_CTRL_SRC_BW_16BITS,  
  SourceWidth_24bit = FFT_SRC_DMA_CTRL_SRC_BW_24BITS,
  SourceWidth_32bit = FFT_SRC_DMA_CTRL_SRC_BW_32BITS,
}FFT_SrcBW_TypeDef;

/**
* @brief  FFT Destination bit width enumeration definition
*/
typedef enum
{
  DestWidth_16bit = FFT_DST_DMA_CTL_DST_BW_16BITS,  
  DestWidth_32bit = FFT_DST_DMA_CTL_DST_BW_32BITS,
}FFT_DestBW_TypeDef;

/**
* @brief  FFT auto scale enumeration definition
*/
typedef enum
{
  ScaleDisable = ((uint32_t)0x0000),  
  ScaleEnable  = FFT_DST_DMA_CTL_SCALE_EN,
}FFT_Scale_TypeDef;

/**
* @brief  FFT module initalizes the structure definition
*/
typedef struct  __FFT_InitTypeDef
{
  FFT_Soft_TypeDef      SoftMode;
  FFT_INV_TypeDef       InvMode;
  uint32_t              FFT_Number;
  FFT_NOR_TypeDef       NorMode;
  FFT_IOD_TypeDef       IodMode;
  FFT_Mode_TypeDef      FFT_Point;
  
  FFT_SrcBW_TypeDef     SourceBitWidth;
  uint32_t              R_Shift_channel0;
  uint32_t              R_Shift_channel1;
  uint32_t              R_Shift_channel2;
  uint32_t              R_Shift_channel3;
  uint32_t              R_Shift_channel4;
  uint32_t              R_Shift_channel5;
  uint32_t              R_Shift_channel6;
  uint32_t              SourceBaseAddress;
  uint32_t              BufferLength;
  uint32_t              SourceStartOffset;
  
  uint32_t              FundIdex;
  FFT_Scale_TypeDef     Scale;
  FFT_DestBW_TypeDef    DestBitWidth;
  uint32_t              DestBaseAddress;
  
    
#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
  HT_FFT_TypeDef *Instance;             /*!< FFT registers base address  */
  __IO uint32_t    ErrorCode;                     /*!< FFT Error code                    */
  void (* FftSingleCpltCallback)(struct __FFT_InitTypeDef *FFT_InitStruct);           
  void (* FftDoneCpltCallback)(struct __FFT_InitTypeDef *FFT_InitStruct); 
#endif  
}FFT_InitTypeDef;                 /*!< end of group FFT_InitTypeDef*/

#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)

/**
* @brief  FFT Error Code
*/
#define FFT_ERROR_INVALID_CALLBACK  0x00010000U   /*!< Invalid Callback error  */

/**
* @brief  FFT Callback ID enumeration definition
*/
typedef enum
{
  FFT_SINGLE_COMPLETE_CB_ID     = (uint32_t)0x01,    	 /*!< FFT Single Complete Callback ID             */
  FFT_DONE_COMPLETE_CB_ID       = (uint32_t)0x02,    	 /*!< FFT Done Complete Callback ID             */
} FFT_CallbackIDTypeDef;

/**
* @brief  FFT Callback pointer definition
*/
typedef  void (*pFFT_CallbackTypeDef)(FFT_InitTypeDef *FFT_InitStruct);  /*!< pointer to an FFT callback function */

#endif

/**
* @brief  FFT soft mode
*/
#define IS_HT_FFT_SOFTMODE(mode)       (((mode) == 0U)||((mode) == FFT_FFTCFG_SOFT_EN))

/**
* @brief  FFT MODE(point)
*/
#define IS_HT_FFT_FFTMODE(mode)       (((mode) == FFT_FFTCFG_FFTMODE_64)  || ((mode) == FFT_FFTCFG_FFTMODE_128) ||\
                                       ((mode) == FFT_FFTCFG_FFTMODE_256) || ((mode) == FFT_FFTCFG_FFTMODE_512) )
/**
* @brief  FFT IOD TYPE
*/
#define IS_HT_FFT_IODTYPE(type)       (((type) == FFT_FFTCFG_IODTYPE_C_C)  || ((type) == FFT_FFTCFG_IODTYPE_R_C))

/**
* @brief  FFT NOR TYPE
*/
#define IS_HT_FFT_NORTYPE(type)       (((type) == FFT_FFTCFG_NOR_SQRTN_N)  || ((type) == FFT_FFTCFG_NOR_SQRTN_SQRT))

/**
* @brief  FFT number
*/
#define IS_HT_FFT_NUMBER(num)         ((num) <= 7U)

/**
* @brief  FFT INV TYPE
*/
#define IS_HT_FFT_INVTYPE(type)       (((type) == FFT_FFTCFG_INV_FFT)  || ((type) == FFT_FFTCFG_INV_IFFT))

/**
* @brief  FFT number
*/
#define IS_HT_FFT_RSHIFT(num)         ((num) <= 15U)

/**
* @brief  FFT Fundamental wave IDEX
*/
#define IS_HT_FFT_FUNDIDX(num)         ((num) <= 0x3FFU)

/**
* @brief  FFT scale
*/
#define IS_HT_FFT_SCALE(type)         (((type) == 0U)||((type) == FFT_DST_DMA_CTL_SCALE_EN))

/**
* @brief  FFT SOURCE BIT WIDTH
*/
#define IS_HT_FFT_SRC_BW(type)       (((type) == FFT_SRC_DMA_CTRL_SRC_BW_16BITS) || ((type) == FFT_SRC_DMA_CTRL_SRC_BW_24BITS) || ((type) == FFT_SRC_DMA_CTRL_SRC_BW_32BITS))
/**
* @brief  FFT DEST BIT WIDTH
*/
#define IS_HT_FFT_DST_BW(type)       (((type) == FFT_DST_DMA_CTL_DST_BW_16BITS) || ((type) == FFT_DST_DMA_CTL_DST_BW_32BITS))

/**
* @brief  FFT interrupt 
*/
#define IS_HT_FFT_IE(it)       (((it) == FFT_FFTIE_FFT_IE) || ((it) == FFT_FFTIE_FFT_DONE_IE) || \
                                        ((((it) & (uint32_t)(~FFT_FFTIE)) == 0x00) && ((it) != 0x00)))
/**
* @brief  FFT interrupt flag
*/
#define IS_HT_FFT_IF(itflag)       (((itflag) == FFT_FFTIF_FFT_IF) || ((itflag) == FFT_FFTIF_FFT_DONE_IF) || \
                                        ((((itflag) & (uint32_t)(~FFT_FFTIF)) == 0x00) && ((itflag) != 0x00)))
/**
* @brief  FFT error flag
*/
#define IS_HT_FFT_ERR(itflag)       (((itflag) == FFT_FFTERR_CLIPE) || ((itflag) == FFT_FFTERR_CLIPIN) || ((itflag) == FFT_FFTERR_CLIPOUT) || \
                                        ((((itflag) & (uint32_t)(~FFT_FFTERR)) == 0x00) && ((itflag) != 0x00)))

/**
* @brief  FFT error flag
*/
#define IS_HT_FFT_CHANNEL(ch)       (((ch) == FFT_CH0) || ((ch) == FFT_CH1) || ((ch) == FFT_CH2) || ((ch) == FFT_CH3) ||\
                                     ((ch) == FFT_CH4) || ((ch) == FFT_CH5) || ((ch) == FFT_CH6) || \
                                        ((((ch) & (uint32_t)(~FFT_CH_ALL)) == 0x00) && ((ch) != 0x00)))


/**
* @brief  FFT SOFT START
*/
#define HT_FFT_SOFT_START()         (HT_FFT->FFTCFG |=  FFT_FFTCFG_SOFT_EN)
#define HT_FFT_SOFT_STOP()          (HT_FFT->FFTCFG &= ~FFT_FFTCFG_SOFT_EN)
/**
* @brief  FFT ABORT
*/
#define HT_FFT_ABORT()              (HT_FFT->FFTCFG |=  FFT_FFTCFG_ABORT)


/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
StatusTypeDef HT_FFT_Init(FFT_InitTypeDef *FFT_InitStruct);
void HT_FFT_ITConfig(uint32_t ITEn,FunctionalState NewState);
ITStatus HT_FFT_ITFlagStatusGet(uint32_t ITFlag);
void HT_FFT_ClearITPendingBit(uint32_t ITFlag);

ITStatus HT_FFT_ErrStatusGet(uint32_t ErrFlag);
void HT_FFT_ClearErrPendingBit(uint32_t ErrFlag);

uint32_t HT_FFT_NumberStatusGet(void);
uint32_t HT_FFT_FunShiftStatusGet(FFT_Channel_TypeDef channel);
uint32_t HT_FFT_NonFunShiftStatusGet(FFT_Channel_TypeDef channel);

#if (USE_HT_FFT_REGISTER_CALLBACKS == 1U)
void HT_FFT_SingleCpltCallback(FFT_InitTypeDef *FFT_InitStruct);
void HT_FFT_DoneCpltCallback(FFT_InitTypeDef *FFT_InitStruct);
StatusTypeDef HT_FFT_RegisterCallback(FFT_InitTypeDef *FFT_InitStruct, FFT_CallbackIDTypeDef CallbackID, pFFT_CallbackTypeDef pCallback);
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT5X3X_EMUIFACE_H__ */
