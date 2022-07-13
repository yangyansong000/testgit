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
* File         : ht7x2x_emuiface.h
* By           : Hitrendtech_SD
* Version      : V1.0.0
* Description  :
**********************************************************************************************************
*/

#ifndef __HT7X2X_EMUIFACE_H__
#define __HT7X2X_EMUIFACE_H__

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

#define EMUIFACE_FFTRST          ((uint32_t)EI_EICON_EI_FFTRST)
  
#define EMUIFACE_FFTHA_LSB       ((uint32_t)EI_EICON_EI_FFTHA_LOW)
#define EMUIFACE_FFTHA_MSB       ((uint32_t)EI_EICON_EI_FFTHA_HIGH)  
  
#define EMUIFACE_NISHA_LSB       ((uint32_t)EI_EICON_EI_NISHA_LOW)
#define EMUIFACE_NISHA_MSB       ((uint32_t)EI_EICON_EI_NISHA_HIGH)
	
#define EMUIFACE_FFTEN_ENABLE    ((uint32_t)EI_EICON_EI_FFTEN)
#define EMUIFACE_NISEN_ENABLE    ((uint32_t)EI_EICON_EI_NISEN)
	
#define EMUIFACE_FFT_CH0_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL0_CH0)
#define EMUIFACE_FFT_CH0_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL0_CH1)
#define EMUIFACE_FFT_CH0_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL0_CH2)
#define EMUIFACE_FFT_CH0_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL0_CH3)
#define EMUIFACE_FFT_CH0_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL0_CH4)
#define EMUIFACE_FFT_CH0_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL0_CH5)
#define EMUIFACE_FFT_CH0_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL0_CH6)

#define EMUIFACE_FFT_CH1_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL1_CH0)
#define EMUIFACE_FFT_CH1_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL1_CH1)
#define EMUIFACE_FFT_CH1_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL1_CH2)
#define EMUIFACE_FFT_CH1_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL1_CH3)
#define EMUIFACE_FFT_CH1_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL1_CH4)
#define EMUIFACE_FFT_CH1_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL1_CH5)
#define EMUIFACE_FFT_CH1_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL1_CH6)

#define EMUIFACE_FFT_CH2_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL2_CH0)
#define EMUIFACE_FFT_CH2_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL2_CH1)
#define EMUIFACE_FFT_CH2_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL2_CH2)
#define EMUIFACE_FFT_CH2_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL2_CH3)
#define EMUIFACE_FFT_CH2_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL2_CH4)
#define EMUIFACE_FFT_CH2_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL2_CH5)
#define EMUIFACE_FFT_CH2_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL2_CH6)

#define EMUIFACE_FFT_CH3_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL3_CH0)
#define EMUIFACE_FFT_CH3_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL3_CH1)
#define EMUIFACE_FFT_CH3_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL3_CH2)
#define EMUIFACE_FFT_CH3_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL3_CH3)
#define EMUIFACE_FFT_CH3_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL3_CH4)
#define EMUIFACE_FFT_CH3_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL3_CH5)
#define EMUIFACE_FFT_CH3_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL3_CH6)

#define EMUIFACE_FFT_CH4_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL4_CH0)
#define EMUIFACE_FFT_CH4_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL4_CH1)
#define EMUIFACE_FFT_CH4_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL4_CH2)
#define EMUIFACE_FFT_CH4_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL4_CH3)
#define EMUIFACE_FFT_CH4_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL4_CH4)
#define EMUIFACE_FFT_CH4_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL4_CH5)
#define EMUIFACE_FFT_CH4_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL4_CH6)

#define EMUIFACE_FFT_CH5_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL5_CH0)
#define EMUIFACE_FFT_CH5_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL5_CH1)
#define EMUIFACE_FFT_CH5_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL5_CH2)
#define EMUIFACE_FFT_CH5_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL5_CH3)
#define EMUIFACE_FFT_CH5_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL5_CH4)
#define EMUIFACE_FFT_CH5_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL5_CH5)
#define EMUIFACE_FFT_CH5_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL5_CH6)

#define EMUIFACE_FFT_CH6_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL6_CH0)
#define EMUIFACE_FFT_CH6_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL6_CH1)
#define EMUIFACE_FFT_CH6_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL6_CH2)
#define EMUIFACE_FFT_CH6_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL6_CH3)
#define EMUIFACE_FFT_CH6_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL6_CH4)
#define EMUIFACE_FFT_CH6_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL6_CH5)
#define EMUIFACE_FFT_CH6_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL6_CH6) 
 
#define EMUIFACE_NIS_CH0_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL0_CH0)
#define EMUIFACE_NIS_CH0_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL0_CH1)
#define EMUIFACE_NIS_CH0_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL0_CH2)
#define EMUIFACE_NIS_CH0_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL0_CH3)
#define EMUIFACE_NIS_CH0_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL0_CH4)
#define EMUIFACE_NIS_CH0_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL0_CH5)
#define EMUIFACE_NIS_CH0_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL0_CH6)

#define EMUIFACE_NIS_CH1_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL1_CH0)
#define EMUIFACE_NIS_CH1_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL1_CH1)
#define EMUIFACE_NIS_CH1_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL1_CH2)
#define EMUIFACE_NIS_CH1_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL1_CH3)
#define EMUIFACE_NIS_CH1_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL1_CH4)
#define EMUIFACE_NIS_CH1_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL1_CH5)
#define EMUIFACE_NIS_CH1_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL1_CH6)

#define EMUIFACE_NIS_CH2_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL2_CH0)
#define EMUIFACE_NIS_CH2_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL2_CH1)
#define EMUIFACE_NIS_CH2_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL2_CH2)
#define EMUIFACE_NIS_CH2_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL2_CH3)
#define EMUIFACE_NIS_CH2_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL2_CH4)
#define EMUIFACE_NIS_CH2_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL2_CH5)
#define EMUIFACE_NIS_CH2_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL2_CH6)

#define EMUIFACE_NIS_CH3_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL3_CH0)
#define EMUIFACE_NIS_CH3_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL3_CH1)
#define EMUIFACE_NIS_CH3_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL3_CH2)
#define EMUIFACE_NIS_CH3_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL3_CH3)
#define EMUIFACE_NIS_CH3_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL3_CH4)
#define EMUIFACE_NIS_CH3_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL3_CH5)
#define EMUIFACE_NIS_CH3_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL3_CH6)

#define EMUIFACE_NIS_CH4_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL4_CH0)
#define EMUIFACE_NIS_CH4_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL4_CH1)
#define EMUIFACE_NIS_CH4_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL4_CH2)
#define EMUIFACE_NIS_CH4_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL4_CH3)
#define EMUIFACE_NIS_CH4_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL4_CH4)
#define EMUIFACE_NIS_CH4_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL4_CH5)
#define EMUIFACE_NIS_CH4_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL4_CH6)

#define EMUIFACE_NIS_CH5_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL5_CH0)
#define EMUIFACE_NIS_CH5_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL5_CH1)
#define EMUIFACE_NIS_CH5_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL5_CH2)
#define EMUIFACE_NIS_CH5_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL5_CH3)
#define EMUIFACE_NIS_CH5_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL5_CH4)
#define EMUIFACE_NIS_CH5_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL5_CH5)
#define EMUIFACE_NIS_CH5_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL5_CH6)

#define EMUIFACE_NIS_CH6_SEL0    ((uint32_t)EI_EI_CFG_CHNSEL6_CH0)
#define EMUIFACE_NIS_CH6_SEL1    ((uint32_t)EI_EI_CFG_CHNSEL6_CH1)
#define EMUIFACE_NIS_CH6_SEL2    ((uint32_t)EI_EI_CFG_CHNSEL6_CH2)
#define EMUIFACE_NIS_CH6_SEL3    ((uint32_t)EI_EI_CFG_CHNSEL6_CH3)
#define EMUIFACE_NIS_CH6_SEL4    ((uint32_t)EI_EI_CFG_CHNSEL6_CH4)
#define EMUIFACE_NIS_CH6_SEL5    ((uint32_t)EI_EI_CFG_CHNSEL6_CH5)
#define EMUIFACE_NIS_CH6_SEL6    ((uint32_t)EI_EI_CFG_CHNSEL6_CH6)

#define EMUIFACE_FFT_IE          ((uint32_t)EI_EIIE_EI_FFTIE)
#define EMUIFACE_FFT_IF          ((uint32_t)EI_EIIF_EI_FFTIF)

#define EMUIFACE_NIS_IE          ((uint32_t)EI_EIIE_EI_NISIE)
#define EMUIFACE_NIS_IF          ((uint32_t)EI_EIIF_EI_NISIF)
 
#define EMUIFACE_FFT_EN          ((uint32_t)EI_EICON_EI_FFTEN)

/**
* @brief  NIS align enumeration definition
*/
typedef enum
{
  FFT_Align_LSB = EMUIFACE_FFTHA_LSB, 
  FFT_Align_MSB = EMUIFACE_FFTHA_MSB,
}FFT_Align_TypeDef;


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
* @brief  FFT channel0 select enumeration definition
*/
typedef enum
{
  FFT_Channel0_Sel0 = EMUIFACE_FFT_CH0_SEL0, 
  FFT_Channel0_Sel1 = EMUIFACE_FFT_CH0_SEL1, 
  FFT_Channel0_Sel2 = EMUIFACE_FFT_CH0_SEL2, 
  FFT_Channel0_Sel3 = EMUIFACE_FFT_CH0_SEL3, 
  FFT_Channel0_Sel4 = EMUIFACE_FFT_CH0_SEL4, 
  FFT_Channel0_Sel5 = EMUIFACE_FFT_CH0_SEL5, 
  FFT_Channel0_Sel6 = EMUIFACE_FFT_CH0_SEL6, 
}FFT_Chn0Sel_TypeDef;

/**
* @brief  FFT channel1 select enumeration definition
*/
typedef enum
{
  FFT_Channel1_Sel0 = EMUIFACE_FFT_CH1_SEL0, 
  FFT_Channel1_Sel1 = EMUIFACE_FFT_CH1_SEL1, 
  FFT_Channel1_Sel2 = EMUIFACE_FFT_CH1_SEL2, 
  FFT_Channel1_Sel3 = EMUIFACE_FFT_CH1_SEL3, 
  FFT_Channel1_Sel4 = EMUIFACE_FFT_CH1_SEL4, 
  FFT_Channel1_Sel5 = EMUIFACE_FFT_CH1_SEL5, 
  FFT_Channel1_Sel6 = EMUIFACE_FFT_CH1_SEL6, 
}FFT_Chn1Sel_TypeDef;

/**
* @brief  FFT channel2 select enumeration definition
*/
typedef enum
{
  FFT_Channel2_Sel0 = EMUIFACE_FFT_CH2_SEL0, 
  FFT_Channel2_Sel1 = EMUIFACE_FFT_CH2_SEL1, 
  FFT_Channel2_Sel2 = EMUIFACE_FFT_CH2_SEL2, 
  FFT_Channel2_Sel3 = EMUIFACE_FFT_CH2_SEL3, 
  FFT_Channel2_Sel4 = EMUIFACE_FFT_CH2_SEL4, 
  FFT_Channel2_Sel5 = EMUIFACE_FFT_CH2_SEL5, 
  FFT_Channel2_Sel6 = EMUIFACE_FFT_CH2_SEL6, 
}FFT_Chn2Sel_TypeDef;

/**
* @brief  FFT channel3 select enumeration definition
*/
typedef enum
{
  FFT_Channel3_Sel0 = EMUIFACE_FFT_CH3_SEL0, 
  FFT_Channel3_Sel1 = EMUIFACE_FFT_CH3_SEL1, 
  FFT_Channel3_Sel2 = EMUIFACE_FFT_CH3_SEL2, 
  FFT_Channel3_Sel3 = EMUIFACE_FFT_CH3_SEL3, 
  FFT_Channel3_Sel4 = EMUIFACE_FFT_CH3_SEL4, 
  FFT_Channel3_Sel5 = EMUIFACE_FFT_CH3_SEL5, 
  FFT_Channel3_Sel6 = EMUIFACE_FFT_CH3_SEL6, 
}FFT_Chn3Sel_TypeDef;

/**
* @brief  FFT channel4 select enumeration definition
*/
typedef enum
{
  FFT_Channel4_Sel0 = EMUIFACE_FFT_CH4_SEL0, 
  FFT_Channel4_Sel1 = EMUIFACE_FFT_CH4_SEL1, 
  FFT_Channel4_Sel2 = EMUIFACE_FFT_CH4_SEL2, 
  FFT_Channel4_Sel3 = EMUIFACE_FFT_CH4_SEL3, 
  FFT_Channel4_Sel4 = EMUIFACE_FFT_CH4_SEL4, 
  FFT_Channel4_Sel5 = EMUIFACE_FFT_CH4_SEL5, 
  FFT_Channel4_Sel6 = EMUIFACE_FFT_CH4_SEL6, 
}FFT_Chn4Sel_TypeDef;

/**
* @brief  FFT channel5 select enumeration definition
*/
typedef enum
{
  FFT_Channel5_Sel0 = EMUIFACE_FFT_CH5_SEL0, 
  FFT_Channel5_Sel1 = EMUIFACE_FFT_CH5_SEL1, 
  FFT_Channel5_Sel2 = EMUIFACE_FFT_CH5_SEL2, 
  FFT_Channel5_Sel3 = EMUIFACE_FFT_CH5_SEL3, 
  FFT_Channel5_Sel4 = EMUIFACE_FFT_CH5_SEL4, 
  FFT_Channel5_Sel5 = EMUIFACE_FFT_CH5_SEL5, 
  FFT_Channel5_Sel6 = EMUIFACE_FFT_CH5_SEL6, 
}FFT_Chn5Sel_TypeDef;

/**
* @brief  FFT channel6 select enumeration definition
*/
typedef enum
{
  FFT_Channel6_Sel0 = EMUIFACE_FFT_CH6_SEL0, 
  FFT_Channel6_Sel1 = EMUIFACE_FFT_CH6_SEL1, 
  FFT_Channel6_Sel2 = EMUIFACE_FFT_CH6_SEL2, 
  FFT_Channel6_Sel3 = EMUIFACE_FFT_CH6_SEL3, 
  FFT_Channel6_Sel4 = EMUIFACE_FFT_CH6_SEL4, 
  FFT_Channel6_Sel5 = EMUIFACE_FFT_CH6_SEL5, 
  FFT_Channel6_Sel6 = EMUIFACE_FFT_CH6_SEL6, 
}FFT_Chn6Sel_TypeDef;

/**
* @brief  NIS channel0 select enumeration definition
*/
typedef enum
{
  NIS_Channel0_Sel0 = EMUIFACE_NIS_CH0_SEL0, 
  NIS_Channel0_Sel1 = EMUIFACE_NIS_CH0_SEL1, 
  NIS_Channel0_Sel2 = EMUIFACE_NIS_CH0_SEL2, 
  NIS_Channel0_Sel3 = EMUIFACE_NIS_CH0_SEL3, 
  NIS_Channel0_Sel4 = EMUIFACE_NIS_CH0_SEL4, 
  NIS_Channel0_Sel5 = EMUIFACE_NIS_CH0_SEL5, 
  NIS_Channel0_Sel6 = EMUIFACE_NIS_CH0_SEL6, 
}NIS_Chn0Sel_TypeDef;

/**
* @brief  NIS channel1 select enumeration definition
*/
typedef enum
{
  NIS_Channel1_Sel0 = EMUIFACE_NIS_CH1_SEL0, 
  NIS_Channel1_Sel1 = EMUIFACE_NIS_CH1_SEL1, 
  NIS_Channel1_Sel2 = EMUIFACE_NIS_CH1_SEL2, 
  NIS_Channel1_Sel3 = EMUIFACE_NIS_CH1_SEL3, 
  NIS_Channel1_Sel4 = EMUIFACE_NIS_CH1_SEL4, 
  NIS_Channel1_Sel5 = EMUIFACE_NIS_CH1_SEL5, 
  NIS_Channel1_Sel6 = EMUIFACE_NIS_CH1_SEL6, 
}NIS_Chn1Sel_TypeDef;

/**
* @brief  NIS channel2 select enumeration definition
*/
typedef enum
{
  NIS_Channel2_Sel0 = EMUIFACE_NIS_CH2_SEL0, 
  NIS_Channel2_Sel1 = EMUIFACE_NIS_CH2_SEL1, 
  NIS_Channel2_Sel2 = EMUIFACE_NIS_CH2_SEL2, 
  NIS_Channel2_Sel3 = EMUIFACE_NIS_CH2_SEL3, 
  NIS_Channel2_Sel4 = EMUIFACE_NIS_CH2_SEL4, 
  NIS_Channel2_Sel5 = EMUIFACE_NIS_CH2_SEL5, 
  NIS_Channel2_Sel6 = EMUIFACE_NIS_CH2_SEL6, 
}NIS_Chn2Sel_TypeDef;

/**
* @brief  NIS channel3 select enumeration definition
*/
typedef enum
{
  NIS_Channel3_Sel0 = EMUIFACE_NIS_CH3_SEL0, 
  NIS_Channel3_Sel1 = EMUIFACE_NIS_CH3_SEL1, 
  NIS_Channel3_Sel2 = EMUIFACE_NIS_CH3_SEL2, 
  NIS_Channel3_Sel3 = EMUIFACE_NIS_CH3_SEL3, 
  NIS_Channel3_Sel4 = EMUIFACE_NIS_CH3_SEL4, 
  NIS_Channel3_Sel5 = EMUIFACE_NIS_CH3_SEL5, 
  NIS_Channel3_Sel6 = EMUIFACE_NIS_CH3_SEL6, 
}NIS_Chn3Sel_TypeDef;

/**
* @brief  NIS channel4 select enumeration definition
*/
typedef enum
{
  NIS_Channel4_Sel0 = EMUIFACE_NIS_CH4_SEL0, 
  NIS_Channel4_Sel1 = EMUIFACE_NIS_CH4_SEL1, 
  NIS_Channel4_Sel2 = EMUIFACE_NIS_CH4_SEL2, 
  NIS_Channel4_Sel3 = EMUIFACE_NIS_CH4_SEL3, 
  NIS_Channel4_Sel4 = EMUIFACE_NIS_CH4_SEL4, 
  NIS_Channel4_Sel5 = EMUIFACE_NIS_CH4_SEL5, 
  NIS_Channel4_Sel6 = EMUIFACE_NIS_CH4_SEL6, 
}NIS_Chn4Sel_TypeDef;

/**
* @brief  NIS channel5 select enumeration definition
*/
typedef enum
{
  NIS_Channel5_Sel0 = EMUIFACE_NIS_CH5_SEL0, 
  NIS_Channel5_Sel1 = EMUIFACE_NIS_CH5_SEL1, 
  NIS_Channel5_Sel2 = EMUIFACE_NIS_CH5_SEL2, 
  NIS_Channel5_Sel3 = EMUIFACE_NIS_CH5_SEL3, 
  NIS_Channel5_Sel4 = EMUIFACE_NIS_CH5_SEL4, 
  NIS_Channel5_Sel5 = EMUIFACE_NIS_CH5_SEL5, 
  NIS_Channel5_Sel6 = EMUIFACE_NIS_CH5_SEL6, 
}NIS_Chn5Sel_TypeDef;

/**
* @brief  NIS channel6 select enumeration definition
*/
typedef enum
{
  NIS_Channel6_Sel0 = EMUIFACE_NIS_CH6_SEL0, 
  NIS_Channel6_Sel1 = EMUIFACE_NIS_CH6_SEL1, 
  NIS_Channel6_Sel2 = EMUIFACE_NIS_CH6_SEL2, 
  NIS_Channel6_Sel3 = EMUIFACE_NIS_CH6_SEL3, 
  NIS_Channel6_Sel4 = EMUIFACE_NIS_CH6_SEL4, 
  NIS_Channel6_Sel5 = EMUIFACE_NIS_CH6_SEL5, 
  NIS_Channel6_Sel6 = EMUIFACE_NIS_CH6_SEL6, 
}NIS_Chn6Sel_TypeDef;

/**
* @brief  EMUIFACE module initalizes the structure definition
*/
typedef struct  __EMUIFACE_InitTypeDef
{
  FunctionalState       NIS_Enable;
  NIS_Align_TypeDef     NIS_Align;                /*!< EMUIFACE LSB    or MSB            */
  NIS_BitWide_TypeDef   NIS_BitWide;              /*!< EMUIFACE 16/24/32 bits            */
    
  NIS_Chn0Sel_TypeDef   NIS_Chn0Sel;
  NIS_Chn1Sel_TypeDef   NIS_Chn1Sel;
  NIS_Chn2Sel_TypeDef   NIS_Chn2Sel;
  NIS_Chn3Sel_TypeDef   NIS_Chn3Sel;
  NIS_Chn4Sel_TypeDef   NIS_Chn4Sel;
  NIS_Chn5Sel_TypeDef   NIS_Chn5Sel;
  NIS_Chn6Sel_TypeDef   NIS_Chn6Sel;
  
  FunctionalState       FFT_Enable;
  FFT_Align_TypeDef     FFT_Align;
  
  FFT_Chn0Sel_TypeDef   FFT_Chn0Sel;
  FFT_Chn1Sel_TypeDef   FFT_Chn1Sel;
  FFT_Chn2Sel_TypeDef   FFT_Chn2Sel;
  FFT_Chn3Sel_TypeDef   FFT_Chn3Sel;
  FFT_Chn4Sel_TypeDef   FFT_Chn4Sel;
  FFT_Chn5Sel_TypeDef   FFT_Chn5Sel;
  FFT_Chn6Sel_TypeDef   FFT_Chn6Sel;
    
#if (USE_HT_EMUIFACE_REGISTER_CALLBACKS == 1U)
  HT_EMU_Interface_TypeDef *Instance;             /*!< EMUIFACE registers base address  */
  __IO uint32_t    ErrorCode;                     /*!< EMUIFACE Error code                    */
  void (* EmuIfaceNisCpltCallback)(struct __EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);            /*!< EMUIFACE NIS Complete Callback             */
  void (* EmuIfaceFftCpltCallback)(struct __EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);            /*!< EMUIFACE FFT Complete Callback             */
#endif  
}EMUIFACE_InitTypeDef;                 /*!< end of group EMUIF_InitTypeDef*/

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
  EMUIFACE_FFT_COMPLETE_CB_ID              = (uint32_t)0x02,    	 /*!< EMUIFACE Complete Callback ID             */
} EMUIFACE_CallbackIDTypeDef;
/**
* @brief  EMUIFACE Callback pointer definition
*/
typedef  void (*pEMUIFACE_CallbackTypeDef)(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);  /*!< pointer to an EMUIFACE callback function */

#endif

/**
* @brief  EMUIFACE NIS MODE
*/
#define IS_HT_EMUIFACE_NISBIT(bitwide)    (((bitwide) == EMUIFACE_NISMODE_16BITS) ||\
                                           ((bitwide) == EMUIFACE_NISMODE_24BITS) ||\
                                           ((bitwide) == EMUIFACE_NISMODE_32BITS) )
/**
* @brief  EMUIFACE NIS HA
*/
#define IS_HT_EMUIFACE_NISHA(align)          (((align) == EMUIFACE_NISHA_LSB) || ((align) == EMUIFACE_NISHA_MSB))

/**
* @brief  EMUIFACE FFT HA
*/
#define IS_HT_EMUIFACE_FFTHA(align)          (((align) == EMUIFACE_FFTHA_LSB) || ((align) == EMUIFACE_FFTHA_MSB))

/**
* @brief  EMUIFACE NIS CHANNEL SELECT
*/
#define IS_HT_EMUIFACE_NIS_CHN0SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH0_SEL0) || ((chnsel) == EMUIFACE_NIS_CH0_SEL1) || ((chnsel) == EMUIFACE_NIS_CH0_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH0_SEL3) || ((chnsel) == EMUIFACE_NIS_CH0_SEL4) || ((chnsel) == EMUIFACE_NIS_CH0_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH0_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL0)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN1SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH1_SEL0) || ((chnsel) == EMUIFACE_NIS_CH1_SEL1) || ((chnsel) == EMUIFACE_NIS_CH1_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH1_SEL3) || ((chnsel) == EMUIFACE_NIS_CH1_SEL4) || ((chnsel) == EMUIFACE_NIS_CH1_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH1_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL1)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN2SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH2_SEL0) || ((chnsel) == EMUIFACE_NIS_CH2_SEL1) || ((chnsel) == EMUIFACE_NIS_CH2_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH2_SEL3) || ((chnsel) == EMUIFACE_NIS_CH2_SEL4) || ((chnsel) == EMUIFACE_NIS_CH2_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH2_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL2)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN3SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH3_SEL0) || ((chnsel) == EMUIFACE_NIS_CH3_SEL1) || ((chnsel) == EMUIFACE_NIS_CH3_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH3_SEL3) || ((chnsel) == EMUIFACE_NIS_CH3_SEL4) || ((chnsel) == EMUIFACE_NIS_CH3_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH3_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL3)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN4SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH4_SEL0) || ((chnsel) == EMUIFACE_NIS_CH4_SEL1) || ((chnsel) == EMUIFACE_NIS_CH4_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH4_SEL3) || ((chnsel) == EMUIFACE_NIS_CH4_SEL4) || ((chnsel) == EMUIFACE_NIS_CH4_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH4_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL4)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN5SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH5_SEL0) || ((chnsel) == EMUIFACE_NIS_CH5_SEL1) || ((chnsel) == EMUIFACE_NIS_CH5_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH5_SEL3) || ((chnsel) == EMUIFACE_NIS_CH5_SEL4) || ((chnsel) == EMUIFACE_NIS_CH5_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH5_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL5)) == 0x00) && ((chnsel) != 0x00)) )
#define IS_HT_EMUIFACE_NIS_CHN6SEL(chnsel)       (((chnsel) == EMUIFACE_NIS_CH6_SEL0) || ((chnsel) == EMUIFACE_NIS_CH6_SEL1) || ((chnsel) == EMUIFACE_NIS_CH6_SEL2) || \
                                               ((chnsel) == EMUIFACE_NIS_CH6_SEL3) || ((chnsel) == EMUIFACE_NIS_CH6_SEL4) || ((chnsel) == EMUIFACE_NIS_CH6_SEL6) || \
                                               ((chnsel) == EMUIFACE_NIS_CH6_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL6)) == 0x00) && ((chnsel) != 0x00)) )

/**
* @brief  EMUIFACE FFT CHANNEL SELECT
*/
#define IS_HT_EMUIFACE_FFT_CHN0SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH0_SEL0) || ((chnsel) == EMUIFACE_FFT_CH0_SEL1) || ((chnsel) == EMUIFACE_FFT_CH0_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH0_SEL3) || ((chnsel) == EMUIFACE_FFT_CH0_SEL4) || ((chnsel) == EMUIFACE_FFT_CH0_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH0_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL0)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN1SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH1_SEL0) || ((chnsel) == EMUIFACE_FFT_CH1_SEL1) || ((chnsel) == EMUIFACE_FFT_CH1_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH1_SEL3) || ((chnsel) == EMUIFACE_FFT_CH1_SEL4) || ((chnsel) == EMUIFACE_FFT_CH1_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH1_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL1)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN2SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH2_SEL0) || ((chnsel) == EMUIFACE_FFT_CH2_SEL1) || ((chnsel) == EMUIFACE_FFT_CH2_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH2_SEL3) || ((chnsel) == EMUIFACE_FFT_CH2_SEL4) || ((chnsel) == EMUIFACE_FFT_CH2_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH2_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL2)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN3SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH3_SEL0) || ((chnsel) == EMUIFACE_FFT_CH3_SEL1) || ((chnsel) == EMUIFACE_FFT_CH3_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH3_SEL3) || ((chnsel) == EMUIFACE_FFT_CH3_SEL4) || ((chnsel) == EMUIFACE_FFT_CH3_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH3_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL3)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN4SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH4_SEL0) || ((chnsel) == EMUIFACE_FFT_CH4_SEL1) || ((chnsel) == EMUIFACE_FFT_CH4_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH4_SEL3) || ((chnsel) == EMUIFACE_FFT_CH4_SEL4) || ((chnsel) == EMUIFACE_FFT_CH4_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH4_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL4)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN5SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH5_SEL0) || ((chnsel) == EMUIFACE_FFT_CH5_SEL1) || ((chnsel) == EMUIFACE_FFT_CH5_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH5_SEL3) || ((chnsel) == EMUIFACE_FFT_CH5_SEL4) || ((chnsel) == EMUIFACE_FFT_CH5_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH5_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL5)) == 0x00) && ((chnsel) != 0x00)))
#define IS_HT_EMUIFACE_FFT_CHN6SEL(chnsel)       (((chnsel) == EMUIFACE_FFT_CH6_SEL0) || ((chnsel) == EMUIFACE_FFT_CH6_SEL1) || ((chnsel) == EMUIFACE_FFT_CH6_SEL2) || \
                                               ((chnsel) == EMUIFACE_FFT_CH6_SEL3) || ((chnsel) == EMUIFACE_FFT_CH6_SEL4) || ((chnsel) == EMUIFACE_FFT_CH6_SEL6) || \
                                               ((chnsel) == EMUIFACE_FFT_CH6_SEL6) ||  ((((chnsel) & (uint32_t)(~EI_EI_CFG_CHNSEL6)) == 0x00) && ((chnsel) != 0x00)))
 
/**
* @brief  EMUIFACE IE
*/
#define IS_HT_EMUIFACE_IE(ie)                (((ie) == EMUIFACE_NIS_IE) || ((ie) == EMUIFACE_FFT_IE) || \
                                          ((((ie) & (uint32_t)(~EI_EIIE)) == 0x00) && ((ie) != 0x00)))		

/**
* @brief  EMUIFACE IF
*/
#define IS_HT_EMUIFACE_IF(itflag)            (((itflag) == EMUIFACE_NIS_IF) || ((itflag) == EMUIFACE_FFT_IF) || \
                                          ((((itflag) & (uint32_t)(~EI_EIIF)) == 0x00) && ((itflag) != 0x00)))

/**
* @brief  EMUIFACE NIS ENABLE/DISABLE
*/
#define HT_EMUIFACE_NIS_ENBALE()        (HT_EMUIFACE->EICON |= EMUIFACE_NISEN_ENABLE)
#define HT_EMUIFACE_NIS_DISBALE()       (HT_EMUIFACE->EICON &= ~EMUIFACE_NISEN_ENABLE)

/**
* @brief  EMUIFACE FFT ENABLE/DISABLE
*/
#define HT_EMUIFACE_FFT_ENBALE()        (HT_EMUIFACE->EICON |=  EMUIFACE_FFTEN_ENABLE)
#define HT_EMUIFACE_FFT_DISBALE()       (HT_EMUIFACE->EICON &= ~EMUIFACE_FFTEN_ENABLE)

/**
* @brief  EMUIFACE FFT RESET
*/
#define HT_EMUIFACE_FFT_RESET()         (HT_EMUIFACE->EICON |=  EMUIFACE_FFTRST)

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
void HT_EMUIFACE_FftCpltCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct);
StatusTypeDef HT_EMUIFACE_RegisterCallback(EMUIFACE_InitTypeDef *EMUIFACE_InitStruct, EMUIFACE_CallbackIDTypeDef CallbackID, pEMUIFACE_CallbackTypeDef pCallback);
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT7X2X_EMUIFACE_H__ */
