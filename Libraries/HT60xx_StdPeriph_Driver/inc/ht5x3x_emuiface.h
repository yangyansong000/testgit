/*
*********************************************************************************************************
*                                              HT5X3X
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT5x3x
* File         : ht5x3x_emuiface.h
* By           : Hitrendtech_SD
* Version      : V1.0.0
* Description  :
**********************************************************************************************************
*/

#ifndef __HT5X3X_EMUIFACE_H__
#define __HT5X3X_EMUIFACE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/**
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

#define HT_EMUIFACE              HT_EMU_INTERFACE	

#define EMUIFACE_NISMODE_16BITS  ((uint32_t)EI_EICON_EI_NISMODE_16BITS)
#define EMUIFACE_NISMODE_24BITS  ((uint32_t)EI_EICON_EI_NISMODE_24BITS)
#define EMUIFACE_NISMODE_32BITS  ((uint32_t)EI_EICON_EI_NISMODE_32BITS)

#define EMUIFACE_NISHA_LSB       ((uint32_t)EI_EICON_EI_NISHA_LOW)
#define EMUIFACE_NISHA_MSB       ((uint32_t)EI_EICON_EI_NISHA_HIGH)
	
#define EMUIFACE_NISEN_DISABLE   ((uint32_t)EI_EICON_EI_NISEN_DISABLE)
#define EMUIFACE_NISEN_ENABLE    ((uint32_t)EI_EICON_EI_NISEN_ENABLE)
	
#define EMUIFACE_NIS_CH0_SEL0    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL0_CH0)
#define EMUIFACE_NIS_CH0_SEL1    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL0_CH1)
#define EMUIFACE_NIS_CH0_SEL2    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL0_CH2)
#define EMUIFACE_NIS_CH1_SEL0    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL1_CH0)
#define EMUIFACE_NIS_CH1_SEL1    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL1_CH1)
#define EMUIFACE_NIS_CH1_SEL2    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL1_CH2)
#define EMUIFACE_NIS_CH2_SEL0    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL2_CH0)
#define EMUIFACE_NIS_CH2_SEL1    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL2_CH1)
#define EMUIFACE_NIS_CH2_SEL2    ((uint32_t)EI_EI_NISCFG_NIS_CHNSEL2_CH2)

#define EMUIFACE_NIS_IE          ((uint32_t)EI_EIIE_EI_NISIE)
#define EMUIFACE_NIS_IF          ((uint32_t)EI_EIIF_EI_NISIF)
                 
/**
* @brief  NIS align enumeration definition
*/
typedef enum
{
  NIS_Align_LSB = EMUIFACE_NISHA_LSB, 
  NIS_Align_MSB = EMUIFACE_NISHA_MSB,
}NIS_Align_TypeDef;

/**
* @brief  NIS bitwide enumeration definition
*/
typedef enum
{
  NIS_BitWide_16bits = EMUIFACE_NISMODE_16BITS, 
  NIS_BitWide_24bits = EMUIFACE_NISMODE_24BITS, 
  NIS_BitWide_32bits = EMUIFACE_NISMODE_32BITS, 
}NIS_BitWide_TypeDef;

/**
* @brief  NIS channel0 select enumeration definition
*/
typedef enum
{
  NIS_Channel0_Sel0 = EMUIFACE_NIS_CH0_SEL0, 
  NIS_Channel0_Sel1 = EMUIFACE_NIS_CH0_SEL1, 
  NIS_Channel0_Sel2 = EMUIFACE_NIS_CH0_SEL2, 
}NIS_Chn0Sel_TypeDef;

/**
* @brief  NIS channel1 select enumeration definition
*/
typedef enum
{
  NIS_Channel1_Sel0 = EMUIFACE_NIS_CH1_SEL0, 
  NIS_Channel1_Sel1 = EMUIFACE_NIS_CH1_SEL1, 
  NIS_Channel1_Sel2 = EMUIFACE_NIS_CH1_SEL2, 
}NIS_Chn1Sel_TypeDef;

/**
* @brief  NIS channel2 select enumeration definition
*/
typedef enum
{
  NIS_Channel2_Sel0 = EMUIFACE_NIS_CH2_SEL0, 
  NIS_Channel2_Sel1 = EMUIFACE_NIS_CH2_SEL1, 
  NIS_Channel2_Sel2 = EMUIFACE_NIS_CH2_SEL2, 
}NIS_Chn2Sel_TypeDef;


/**
* @brief  EMUIFACE module initalizes the structure definition
*/
typedef struct  __EMUIFACE_InitTypeDef
{
  NIS_Align_TypeDef     NIS_Align;                /*!< EMUIFACE LSB    or MSB            */
  NIS_BitWide_TypeDef   NIS_BitWide;              /*!< EMUIFACE 16/24/32 bits            */
    
  NIS_Chn0Sel_TypeDef   NIS_Chn0Sel;
  NIS_Chn1Sel_TypeDef   NIS_Chn1Sel;
  NIS_Chn2Sel_TypeDef   NIS_Chn2Sel;
    
#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
  HT_EMU_Interface_TypeDef *Instance;             /*!< EMUIFACE registers base address  */
  __IO uint32_t    ErrorCode;                     /*!< EMUIFACE Error code                    */
  void (* EmuIfaceNisCpltCallback)(struct __EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);            /*!< EMUIFACE Complete Callback             */
#endif  
}EMUIFACE_InitTypeDef;                 /*!< end of group EMUIFACE_InitTypeDef*/

#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)

/**
* @brief  EMUIFACE Error Code
*/
#define EMUIFACE_ERROR_INVALID_CALLBACK  0x00010000U   /*!< Invalid Callback error  */

/**
* @brief  EMUIFACE Callback ID enumeration definition
*/
typedef enum
{
  EMUIFACE_NIS_COMPLETE_CB_ID              = (uint32_t)0x01,    	 /*!< EMUIFACE Complete Callback ID             */
} EMUIFACE_CallbackIDTypeDef;
/**
* @brief  EMUIFACE Callback pointer definition
*/
typedef  void (*pEMUIFACE_CallbackTypeDef)(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);  /*!< pointer to an EMUIFACE callback function */

#endif

/**
* @brief  EMUIFACE NIS MODE
*/
#define IS_HT_EMUIFACE_NISBIT(bitwide)       (((bitwide) == EMUIFACE_NISMODE_16BITS) ||\
                                           ((bitwide) == EMUIFACE_NISMODE_24BITS) ||\
                                           ((bitwide) == EMUIFACE_NISMODE_32BITS) )
/**
* @brief  EMUIFACE NIS HA
*/
#define IS_HT_EMUIFACE_NISHA(align)          (((align) == EMUIFACE_NISHA_LSB) || ((align) == EMUIFACE_NISHA_MSB))

/**
* @brief  EMUIFACE NIS CHANNEL SELECT
*/
#define IS_HT_EMUIFACE_CHN0SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH0_SEL0) || ((chnsel) == EMUIFACE_NIS_CH0_SEL1) || ((chnsel) == EMUIFACE_NIS_CH0_SEL2))
#define IS_HT_EMUIFACE_CHN1SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH1_SEL0) || ((chnsel) == EMUIFACE_NIS_CH1_SEL1) || ((chnsel) == EMUIFACE_NIS_CH1_SEL2))
#define IS_HT_EMUIFACE_CHN2SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH2_SEL0) || ((chnsel) == EMUIFACE_NIS_CH2_SEL1) || ((chnsel) == EMUIFACE_NIS_CH2_SEL2))

/**
* @brief  EMUIFACE NIS IE
*/
#define IS_HT_EMUIFACE_IE(ie)                ((ie) == EMUIFACE_NIS_IE)		

/**
* @brief  EMUIFACE NIS IF
*/
#define IS_HT_EMUIFACE_IF(itflag)            ((itflag) == EMUIFACE_NIS_IF)

/**
* @brief  EMUIFACE NIS ENABLE/DISABLE
*/
#define HT_EMUIFACE_NIS_ENBALE()        (HT_EMUIFACE->EICON |= EMUIFACE_NISEN_ENABLE)
#define HT_EMUIFACE_NIS_DISBALE()       (HT_EMUIFACE->EICON &= ~EMUIFACE_NISEN_ENABLE)

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
StatusTypeDef HT_EMUIFACE_Init(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);
void HT_EMUIFACE_ITConfig(uint32_t ITEn,FunctionalState NewState);
ITStatus HT_EMUIFACE_ITFlagStatusGet(uint32_t ITFlag);
void HT_EMUIFACE_ClearITPendingBit(uint32_t ITFlag);

#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
void HT_EMUIFACE_NisCpltCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);
StatusTypeDef HT_EMUIFACE_RegisterCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct, EMUIFACE_CallbackIDTypeDef CallbackID, pEMUIFACE_CallbackTypeDef pCallback);
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT5X3X_EMUIFACE_H__ */
