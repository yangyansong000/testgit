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
* File         : ht6xxx_pmu.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_PMU_H__
#define __HT6XXX_PMU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/**
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

/**
* @brief  LVDIN state
*/
typedef enum
{
#if  defined USE_LVDIN_QR 
    LVDINEnable_QR = ((PMU_LVDINQR_LVD_QR0<<4)|PMU_PMUCON_LVD0DETEN), /*!< LVDIN Enable, Open fast startup mode      */
#endif
    LVDINEnable    = PMU_PMUCON_LVD0DETEN,                            /*!< LVDIN Enable                        */
    LVDINDisable = 0x0000U,                                           /*!< LVDIN Disable                        */
}LVDINState_TypeDef;                       /*!< end of group LVDIN_StateTypeDef  */

/**
* @brief  BOR state
*/
typedef enum
{
    BORDisable   = 0x0000U,                                       /*!< BOR Disable                          */
    BORReset     = (PMU_PMUCON_BORRST|PMU_PMUCON_BORDETEN),       /*!< BOR Enable，reset                    */
    BORInterrupt = ((~PMU_PMUCON_BORRST)&PMU_PMUCON_BORDETEN),    /*!< BOR Enable，interrupt                */
}BORState_TypeDef;                        /*!< end of group BOR_StateTypeDef    */

/**
* @brief  VCC Detection threshold
*/
typedef enum
{
#if defined USE_VCCLVL_633x
    VccLVL_1V8 = PMU_VDETCFG_VCCLVL_1V8,  /*!< Vcc Detection threshold = 1.8V               */
    VccLVL_1V95= PMU_VDETCFG_VCCLVL_1V95, /*!< Vcc Detection threshold = 1.95V              */
    VccLVL_2V1 = PMU_VDETCFG_VCCLVL_2V1,  /*!< Vcc Detection threshold = 2.1V               */
    VccLVL_2V25= PMU_VDETCFG_VCCLVL_2V25, /*!< Vcc Detection threshold = 2.25V              */
    VccLVL_2V4 = PMU_VDETCFG_VCCLVL_2V4,  /*!< Vcc Detection threshold = 2.4V               */
    VccLVL_2V55= PMU_VDETCFG_VCCLVL_2V55, /*!< Vcc Detection threshold = 2.55V              */
    VccLVL_2V7 = PMU_VDETCFG_VCCLVL_2V7,  /*!< Vcc Detection threshold = 2.7V               */
    VccLVL_2V85= PMU_VDETCFG_VCCLVL_2V85, /*!< Vcc Detection threshold = 2.85V              */
    VccLVL_3V0 = PMU_VDETCFG_VCCLVL_3V0,  /*!< Vcc Detection threshold = 3.0V               */
    VccLVL_3V15= PMU_VDETCFG_VCCLVL_3V15, /*!< Vcc Detection threshold = 3.15V              */
    VccLVL_3V3 = PMU_VDETCFG_VCCLVL_3V3,  /*!< Vcc Detection threshold = 3.3V               */
#else    
    VccLVL_2V4 = PMU_VDETCFG_VCCLVL_2V4,  /*!< Vcc Detection threshold = 2.4V               */
    VccLVL_2V6 = PMU_VDETCFG_VCCLVL_2V6,  /*!< Vcc Detection threshold = 2.6V               */
    VccLVL_2V8 = PMU_VDETCFG_VCCLVL_2V8,  /*!< Vcc Detection threshold = 2.8V               */
    VccLVL_3V0 = PMU_VDETCFG_VCCLVL_3V0,  /*!< Vcc Detection threshold = 3.0V               */
	#ifndef USE_VCCLVL_501x
    VccLVL_3V2 = PMU_VDETCFG_VCCLVL_3V2,  /*!< Vcc Detection threshold = 3.2V               */
    VccLVL_3V4 = PMU_VDETCFG_VCCLVL_3V4,  /*!< Vcc Detection threshold = 3.4V               */
    VccLVL_3V6 = PMU_VDETCFG_VCCLVL_3V6,  /*!< Vcc Detection threshold = 3.6V               */
    VccLVL_3V8 = PMU_VDETCFG_VCCLVL_3V8,  /*!< Vcc Detection threshold = 3.8V               */
    VccLVL_4V0 = PMU_VDETCFG_VCCLVL_4V0,  /*!< Vcc Detection threshold = 4.0V               */
    VccLVL_4V2 = PMU_VDETCFG_VCCLVL_4V2,  /*!< Vcc Detection threshold = 4.2V               */
    VccLVL_4V4 = PMU_VDETCFG_VCCLVL_4V4,  /*!< Vcc Detection threshold = 4.4V               */
    VccLVL_4V6 = PMU_VDETCFG_VCCLVL_4V6,  /*!< Vcc Detection threshold = 4.6V               */
    VccLVL_4V8 = PMU_VDETCFG_VCCLVL_4V8,  /*!< Vcc Detection threshold = 4.8V               */
    VccLVL_5V0 = PMU_VDETCFG_VCCLVL_5V0,  /*!< Vcc Detection threshold = 5.0V               */
	#endif
#endif    
}VCCLVL_TypeDef;                          /*!< end of group VCCLVL_TypeDef      */

/**
* @brief  BOR Detection threshold
*/
typedef enum
{
#if defined USE_BOR_SOC 
    BORLVL_2V2 = PMU_VDETCFG_BORLVL_2V2,  /*!< BOR Detection threshold = 2.2V               */
    BORLVL_2V4 = PMU_VDETCFG_BORLVL_2V4,  /*!< BOR Detection threshold = 2.4V               */
    BORLVL_2V6 = PMU_VDETCFG_BORLVL_2V6,  /*!< BOR Detection threshold = 2.6V               */
    BORLVL_2V8 = PMU_VDETCFG_BORLVL_2V8,  /*!< BOR Detection threshold = 2.8V               */
#elif  defined USE_BOR_MCU 
    BORLVL_2V0 = PMU_VDETCFG_BORLVL_2V0,  /*!< BOR Detection threshold = 2.0V               */
    BORLVL_2V2 = PMU_VDETCFG_BORLVL_2V2,  /*!< BOR Detection threshold = 2.2V               */
    BORLVL_2V6 = PMU_VDETCFG_BORLVL_2V6,  /*!< BOR Detection threshold = 2.6V               */
    BORLVL_2V8 = PMU_VDETCFG_BORLVL_2V8,  /*!< BOR Detection threshold = 2.8V               */
#else
    BORLVL_1V65= PMU_VDETCFG_BORLVL_1V65, /*!< BOR Detection threshold = 1.65V              */
    BORLVL_2V0 = PMU_VDETCFG_BORLVL_2V0,  /*!< BOR Detection threshold = 2.0V               */
    BORLVL_2V4 = PMU_VDETCFG_BORLVL_2V4,  /*!< BOR Detection threshold = 2.4V               */
    BORLVL_2V8 = PMU_VDETCFG_BORLVL_2V8,  /*!< BOR Detection threshold = 2.8V               */
#endif
}BORLVL_TypeDef;                          /*!< end of group BORLVL_TypeDef      */

/*
* @brief  VCC_DET,BOR_DET  Time-sharing detection time
*/
typedef enum
{
#if defined USE_DETTIM_ONLY_1068US || defined USE_DETTIM_TYPE_2
    DETTIM_1068uS = PMU_VDETPCFG_VDETTIME_LVL3,
#endif
#if defined USE_DETTIM_TYPE_1
    DETTIM_300uS = PMU_VDETPCFG_VDETTIME_LVL0,    
    DETTIM_360uS = PMU_VDETPCFG_VDETTIME_LVL1,    
    DETTIM_480uS = PMU_VDETPCFG_VDETTIME_LVL2,    
  #if defined USE_DETTIM_560US
    DETTIM_560uS = PMU_VDETPCFG_VDETTIME_LVL3,
  #elif defined USE_DETTIM_1120US
    DETTIM_1120uS = PMU_VDETPCFG_VDETTIME_LVL3,
  #endif
#elif defined USE_DETTIM_TYPE_2
    DETTIM_336uS = PMU_VDETPCFG_VDETTIME_LVL0,    
    DETTIM_397uS = PMU_VDETPCFG_VDETTIME_LVL1,    
    DETTIM_519uS = PMU_VDETPCFG_VDETTIME_LVL2,    
#endif
#if defined USE_DETTIM_TYPE_3 
    DETTIM_427uS  = PMU_VDETPCFG_VDETTIME_LVL1,  
    DETTIM_519uS  = PMU_VDETPCFG_VDETTIME_LVL2, 
    DETTIM_1120uS = PMU_VDETPCFG_VDETTIME_LVL3, 
#endif
}DETTIM_TypeDef;                                 /*!< end of group DETTIM_TypeDef */

/**
* @brief  VCC_DET,BOR_DETTime-sharing detection cycle
*/
typedef enum
{
    DETPRD_16P5mS = PMU_VDETPCFG_VDETPRD_16P5mS, /*!< Time-sharing detection cycle = 16.5ms       */
    DETPRD_33mS   = PMU_VDETPCFG_VDETPRD_33mS,   /*!< Time-sharing detection cycle = 33ms         */
    DETPRD_67mS   = PMU_VDETPCFG_VDETPRD_67mS,   /*!< Time-sharing detection cycle = 67ms         */
    DETPRD_134mS  = PMU_VDETPCFG_VDETPRD_134mS,  /*!< Time-sharing detection cycle = 134ms        */
    DETPRD_268mS  = PMU_VDETPCFG_VDETPRD_268mS,  /*!< Time-sharing detection cycle = 268ms        */
    DETPRD_536mS  = PMU_VDETPCFG_VDETPRD_536mS,  /*!< Time-sharing detection cycle = 536ms        */
    DETPRD_1072mS = PMU_VDETPCFG_VDETPRD_1072mS, /*!< Time-sharing detection cycle = 1072ms       */
    DETPRD_2144mS = PMU_VDETPCFG_VDETPRD_2144mS, /*!< Time-sharing detection cycle = 2144ms       */
}DETPRD_TypeDef;                                 /*!< end of group DETPRD_TypeDef */

/**
* @brief  DISCharge mode
*/
#if  defined USE_DISCHARGE 
typedef enum
{
    DisCharge0mA   = 0U,                          /*!<  Disable Battery protection against passivation             */
    DisCharge1mA   = ((PMU_VDETCFG_DisChargeCTRL_1mA<<4)|PMU_PMUCON_DisChargeEN),   /*!< Battery protection against passivation Enable，Current 1mA         */
    DisCharge2mA   = ((PMU_VDETCFG_DisChargeCTRL_2mA<<4)|PMU_PMUCON_DisChargeEN),   /*!< Battery protection against passivation Enable，Current 2mA         */
#if  defined USE_DISCHARGE_MCU 
    DisCharge50uA  = ((PMU_VDETCFG_DisChargeCTRL_50uA<<4)|PMU_PMUCON_DisChargeEN),  /*!< Battery protection against passivation Enable，电流50uA        */
    DisCharge100uA = ((PMU_VDETCFG_DisChargeCTRL_100uA<<4)|PMU_PMUCON_DisChargeEN), /*!< Battery protection against passivation Enable，电流100uA       */
#endif
}DISCharge_TypeDef;                             /*!< end of group DISCharge_TypeDef*/
#endif


#if  defined USE_POWDET 
/**
* @brief  POWDET state 
*/
typedef enum
{
    POWEnable  = PMU_PMUCON_POWDETEN,           /*!< POW_DET Enable                        */
    POWDisable = 0x00U,                          /*!< POW_DET Disable                        */
}POWState_TypeDef;                              /*!< end of group POWState_TypeDef      */

/**
* @brief  power detection filter
*/
typedef enum
{
    POWFilter_1s  = 0U,                          /*!< Low power detection filter time 1s               */
    POWFilter_2s  = 1U,                          /*!< Low power detection filter time 2s               */
    POWFilter_3s  = 2U,                          /*!< Low power detection filter time 3s               */
    POWFilter_4s  = 3U,                          /*!< Low power detection filter time 4s               */
    POWFilter_5s  = 4U,                          /*!< Low power detection filter time 5s               */
    POWFilter_6s  = 5U,                          /*!< Low power detection filter time 6s               */
    POWFilter_7s  = 6U,                          /*!< Low power detection filter time 7s               */
    POWFilter_8s  = 7U,                          /*!< Low power detection filter time 8s               */
    POWFilter_9s  = 8U,                          /*!< Low power detection filter time 9s               */
    POWFilter_10s = 9U,                          /*!< Low power detection filter time 10s              */
    POWFilter_11s = 10U,                         /*!< Low power detection filter time 11s              */
    POWFilter_12s = 11U,                         /*!< Low power detection filter time 12s              */
    POWFilter_13s = 12U,                         /*!< Low power detection filter time 13s              */
    POWFilter_14s = 13U,                         /*!< Low power detection filter time 14s              */
    POWFilter_15s = 14U,                         /*!< Low power detection filter time 15s              */
    POWFilter_16s = 15U,                         /*!< Low power detection filter time 16s              */
}POWFliter_TypeDef;                             /*!< end of group POWFliter_TypeDef     */
#endif

#if defined USE_LVDIN_SEL
typedef enum
{
    LVDSEL_INSIDE  = ((uint32_t)0x0),
    LVDSEL_OUTSIDE = ((uint32_t)0x1), 
}LVDSel_TypeDef;
#endif

#if defined USE_LPCFG   
/**
* @brief  LDO output voltage config
*/
typedef enum
{
    LDOSVL_0 = PMU_LPMCFG_LDOSVL_0,     /*!< LDO output voltage = level0             */
    LDOSVL_1 = PMU_LPMCFG_LDOSVL_1,     /*!< LDO output voltage = level1             */
    LDOSVL_2 = PMU_LPMCFG_LDOSVL_2,     /*!< LDO output voltage = level2             */
    LDOSVL_3 = PMU_LPMCFG_LDOSVL_3,     /*!< LDO output voltage = level3             */
}LDOSVL_TypeDef;                        /*!< end of group LDOSVL_TypeDef             */
#endif

#if defined USE_LDOVREF   
/**
* @brief  LDO output voltage config
*/
typedef enum
{
    LDOSVL_0 = PMU_LDOVREFCFG_LDOSVL_0,     /*!< LDO output voltage = level0         */
    LDOSVL_1 = PMU_LDOVREFCFG_LDOSVL_1,     /*!< LDO output voltage = level1         */
    LDOSVL_2 = PMU_LDOVREFCFG_LDOSVL_2,     /*!< LDO output voltage = level2         */
    LDOSVL_3 = PMU_LDOVREFCFG_LDOSVL_3,     /*!< LDO output voltage = level3         */
}LDOSVL_TypeDef;                        /*!< end of group LDOSVL_TypeDef             */
#endif

/**
* @brief  PMU module initalizes the structure definition
*/
typedef struct  __PMU_InitTypeDef
{
    LVDINState_TypeDef Lvdin0State;              /*!< LVDIN0 state              */
    
#if defined USE_LVDIN1 
    LVDINState_TypeDef Lvdin1State;              /*!< LVDIN1 state              */
#endif
    
#if  defined USE_LVDIN2 
    LVDINState_TypeDef Lvdin2State;              /*!< LVDIN2 state              */
#endif
    
#if  defined USE_POWDET 
  POWState_TypeDef POWState;                     /*!< POW state                	*/
  uint32_t  POWFilter;                           /*!< POW digital filter        */
#endif
    
#if defined USE_LVDIN_SEL
    LVDSel_TypeDef Lvdin0Sel;
    LVDSel_TypeDef Lvdin1Sel;
    LVDSel_TypeDef Lvdin2Sel;
#endif
    
    BORState_TypeDef BorState;                   /*!< BOR state                 */
    VCCLVL_TypeDef VccLvlSet;                    /*!< Vcc Detection threshold   */
    BORLVL_TypeDef BorLvlSet;                    /*!< BOR Detection threshold   */
    DETTIM_TypeDef VccBorDetTime;                /*!< Vcc and Bor detection time  */
    DETPRD_TypeDef VccBorDetPeriod;              /*!< Vcc and Bor detection cycle */
#if	(USE_HT_PMU_REGISTER_CALLBACKS == 1U)
	HT_PMU_TypeDef *Instance;											 /*!< PMU registers base address  */
	__IO uint32_t    ErrorCode;        						 /*!< PMU Error code                    */
	void (* PmuVccCpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);            /*!< PMU VCCDET Complete Callback             */
	void (* PmuBorCpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);            /*!< PMU BORDET Complete Callback             */
	void (* PmuLvd0CpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);           /*!< PMU LVDIN0 Complete Callback             */
#ifdef USE_LVDIN1
	void (* PmuLvd1CpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);           /*!< PMU LVDIN1 Complete Callback             */
#endif
#ifdef USE_LVDIN2
	void (* PmuLvd2CpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);           /*!< PMU LVDIN2 Complete Callback             */
#endif
#ifdef USE_POWDET
	void (* PmuPowCpltCallback)(struct __PMU_InitTypeDef *PMU_InitStruct);            /*!< PMU POWDET Complete Callback             */
#endif
#endif		
}PMU_InitTypeDef;                                /*!< end of group PMU_InitTypeDef*/

/**
* @brief  PMU config mask
*/
#define PMU_CFG_MASK    0x00008010U

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
/**
* @brief  PMU Error Code
*/
#define PMU_ERROR_INVALID_CALLBACK  0x00010000U   /*!< Invalid Callback error  */

/**
* @brief  PMU Callback ID enumeration definition
*/
typedef enum
{
  PMU_VCC_COMPLETE_CB_ID              = (uint32_t)0x01,    	 /*!< PMU Complete Callback ID             */
  PMU_BOR_COMPLETE_CB_ID              = (uint32_t)0x02,    	 /*!< PMU Complete Callback ID             */
  PMU_LVD0_COMPLETE_CB_ID             = (uint32_t)0x03,    	 /*!< PMU Complete Callback ID             */
#ifdef USE_LVDIN1	
  PMU_LVD1_COMPLETE_CB_ID             = (uint32_t)0x04,    	 /*!< PMU Complete Callback ID             */
#endif
#ifdef USE_LVDIN1	
  PMU_LVD2_COMPLETE_CB_ID             = (uint32_t)0x05,    	 /*!< PMU Complete Callback ID             */
#endif
#ifdef USE_POWDET	
  PMU_POW_COMPLETE_CB_ID              = (uint32_t)0x06,    	 /*!< PMU Complete Callback ID             */
#endif
} PMU_CallbackIDTypeDef;

/**
* @brief  PMU Callback pointer definition
*/
typedef  void (*pPMU_CallbackTypeDef)(PMU_InitTypeDef *PMU_InitStruct);  /*!< pointer to an PMU callback function */

#endif

#define HT_BOR_CONFIG(temp,PMU_Init)       ((temp) = ((((PMU_Init)->BorState) & (uint32_t)0x0003)|(temp & 0xFFFFFFFCU)))

/**
*@brief  LVDIN Config
*/
#if defined USE_LVDIN2 
#define HT_LVDIN_CONFIG(temp,PMU_Init)       ((temp) = ((((PMU_Init)->Lvdin0State) & (uint32_t)0x000F)|((((PMU_Init)->Lvdin1State) & (uint32_t)0x000F)<<1)|\
																											 ((((PMU_Init)->Lvdin2State) & (uint32_t)0x000F)<<4)|(temp & 0xFFFFFFB3U)))  
#elif defined USE_LVDIN1 
#define HT_LVDIN_CONFIG(temp,PMU_Init)       ((temp) = ((((PMU_Init)->Lvdin0State) & (uint32_t)0x000F)|((((PMU_Init)->Lvdin1State) & (uint32_t)0x000F)<<1)|(temp & 0xFFFFFFF3U)))
#else
#define HT_LVDIN_CONFIG(temp,PMU_Init)       ((temp) = ((((PMU_Init)->Lvdin0State) & (uint32_t)0x000F)|(temp & 0xFFFFFFFBU)))
#endif

/**
*@brief  PowerDET 
*/
#if defined USE_POWDET 

#define IS_HT_PDTFLT(filter)    (  ((filter) == POWFilter_1s)  || ((filter) == POWFilter_2s)  || ((filter) == POWFilter_3s)   || ((filter) == POWFilter_4s) \
                                || ((filter) == POWFilter_5s)  || ((filter) == POWFilter_6s)  || ((filter) == POWFilter_7s)   || ((filter) == POWFilter_8s) \
                                || ((filter) == POWFilter_9s)  || ((filter) == POWFilter_10s) || ((filter) == POWFilter_11s)  || ((filter) == POWFilter_12s) \
                                || ((filter) == POWFilter_13s) || ((filter) == POWFilter_14s) || ((filter) == POWFilter_15s)  || ((filter) == POWFilter_16s) )
#define   HT_POWDET_SET(temp,PMU_Init)       ((temp) = (((PMU_Init)->POWState)|(temp & 0xFFFFFFDFU)))
#define   HT_PDTFLT_SET(PMU_Init)            ((HT_PMU->PDTFLT)  = ((PMU_Init)->POWFilter)& (uint32_t)0x000F)

#endif

/**
*@brief  LVDIN_QR Config
*/
#if  defined USE_LVDIN_QR 
  #define HT_LVDINQR_SET(PMU_Init)  ((HT_PMU->LVDINQR) =  (((((PMU_Init)->Lvdin0State) & (uint32_t)0x00F0)>>4) \
                                                         | ((((PMU_Init)->Lvdin1State) & (uint32_t)0x00F0)>>3) \
                                                         | ((((PMU_Init)->Lvdin2State) & (uint32_t)0x00F0)>>2)))
#endif

/**
*@brief  LVDIN_SEL Config
*/
#if defined USE_LVDIN_SEL
  #define  HT_LVDINSEL_SET(PMU_Init)       ((HT_PMU->LVDINSEL) =  (((uint32_t)((PMU_Init)->Lvdin0Sel)) | ((uint32_t)((PMU_Init)->Lvdin1Sel)<<2) | ((uint32_t)((PMU_Init)->Lvdin2Sel)<<4)))        
#endif

/**
*@brief  DISCHARGE Config
*/
#if defined USE_DISCHARGE 
#define HT_DISCHARGE_ENABLE(chargemode)      (HT_PMU->PMUCON  = ((HT_PMU->PMUCON & 0xFFFF7FFFU)|((chargemode)&0x8000U))) 
#define HT_DISCHARGE_CFG(chargemode)         (HT_PMU->VDETCFG = ((HT_PMU->VDETCFG & 0x3FFFU)|(((chargemode)>>4) & 0xC000U)))   
#endif


#if defined USE_LPCFG
/**
*@brief  LDO VREF Config
*/
#define  PMU_LDOVREF_TRIM_VREF_MASK			((uint32_t)0x7)
#define  PMU_LDOVREF_LVREF_TC_MASK			((uint32_t)0xF)
#define  PMU_LDOVREF_LVREF_TV_MASK			((uint32_t)0x1F)

#define  PMU_LDOVREF_TRIM_VREF_POS      	((uint32_t)12)
#define  PMU_LDOVREF_LVREF_TC_POS       	((uint32_t)8)
#define  PMU_LDOVREF_LVREF_TV_POS       	((uint32_t)0)

#define HT_NORMAL_VREF_TC_SET(norVref)      ((HT_PMU->LDOVREF) = (((HT_PMU->LDOVREF) & (~PMU_LDOVREF_TRIM_VREF)) | (((uint32_t)norVref & PMU_LDOVREF_TRIM_VREF_MASK)<<PMU_LDOVREF_TRIM_VREF_POS) | PMU_LDOVREF_LDOVREF_WP))
#define HT_LP_VREF_TC_SET(lpVref)           ((HT_PMU->LDOVREF) = (((HT_PMU->LDOVREF) & (~PMU_LDOVREF_LVREF_TC)) | (((uint32_t)lpVref & PMU_LDOVREF_LVREF_TC_MASK)<<PMU_LDOVREF_LVREF_TC_POS ) | PMU_LDOVREF_LDOVREF_WP))
#define HT_LP_VREF_TV_SET(lpVref)           ((HT_PMU->LDOVREF) = (((HT_PMU->LDOVREF) & (~PMU_LDOVREF_LVREF_TV)) | (((uint32_t)lpVref & PMU_LDOVREF_LVREF_TV_MASK)<<PMU_LDOVREF_LVREF_TV_POS ) | PMU_LDOVREF_LDOVREF_WP))

#define HT_NORMAL_VREF_TC_GET()             (((HT_PMU->LDOVREF) & PMU_LDOVREF_TRIM_VREF)>>PMU_LDOVREF_TRIM_VREF_POS)
#define HT_LP_VREF_TC_GET()                	(((HT_PMU->LDOVREF) & PMU_LDOVREF_LVREF_TC)>>PMU_LDOVREF_LVREF_TC_POS)
#define HT_LP_VREF_TV_GET()                 (((HT_PMU->LDOVREF) & PMU_LDOVREF_LVREF_TV))

/**
*@brief  LDO Volt Config
**/
#define PMU_LPMCFG_LDOSVL_POS               ((uint32_t)4)
#define PMU_LPMCFG_LDOSVL_MASK              ((uint32_t)3)

#define HT_LDO_LP_SET(c_ldo_lp)             ((HT_PMU->LPMCFG) = ((HT_PMU->LPMCFG) & (~PMU_LPMCFG_LDOSVL)) | ((((uint32_t)c_ldo_lp)&PMU_LPMCFG_LDOSVL_MASK)<<PMU_LPMCFG_LDOSVL_POS))
#define HT_LDO_LP_GET()                     (((HT_PMU->LPMCFG)&PMU_LPMCFG_LDOSVL)>>PMU_LPMCFG_LDOSVL_POS)
#define IS_HT_C_LDO_LP(c_ldo_lp)            (((uint32_t)c_ldo_lp)<=PMU_LPMCFG_LDOSVL_MASK)


/**
*@brief  OSC POWER ADJ Config
*/
#define HT_OSCPWRADJ_SET(osc_adj)           ((HT_PMU->OSCPWRADJ) = ((uint32_t)osc_adj&0x7U) | 0xA500U)
#define HT_OSCPWRADJ_GET()                  ((HT_PMU->OSCPWRADJ) & 0x7U)
#endif

#if defined USE_LDOVREF
#define HT_LDO_LP_SET(c_ldo_lp)             ((HT_PMU->LDOVREFCFG) = ((((uint32_t)c_ldo_lp)&3U)<<6U))  
#define HT_LDO_LP_GET()                     (((HT_PMU->LDOVREFCFG)&0xC0U)>>6) 
#define IS_HT_C_LDO_LP(c_ldo_lp)			      (((uint32_t)c_ldo_lp)<=3U)
#endif

/**
*@brief  
*/
#define IS_HT_PMUIF(Flag)       ((((Flag) & (uint32_t)(~PMU_PMUIF)) == 0x00)  && ((Flag)!= 0x00))
#define IS_HT_PMUIE(en)         ((((en)   & (uint32_t)(~PMU_PMUIE)) == 0x00)  && ((en)  != 0x00)) 
#define IS_HT_PMUSTA(sta)       ((((sta)  & (uint32_t)(~PMU_PMUSTA)) == 0x00) && ((sta) != 0x00)) 
#if defined USE_LPCFG
#define IS_HT_PMU_NORVREF_TRIM(value)  ((value)<=PMU_LDOVREF_TRIM_VREF_MASK)
#define IS_HT_PMU_LPVREF_TC(value)     ((value)<=PMU_LDOVREF_LVREF_TC_MASK)
#define IS_HT_PMU_LPVREF_TV(value)     ((value)<=PMU_LDOVREF_LVREF_TV_MASK)
#endif
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
void HT_PMU_Init(PMU_InitTypeDef *PMU_InitStruct);
void HT_PMU_HoldLDOConfig(FunctionalState NewState);

#if defined USE_LPCFG
void HT_PMU_HoldVrefConfig(FunctionalState NewState);
void HT_PMU_HoldSram0Config(FunctionalState NewState);
void HT_PMU_HoldSram1Config(FunctionalState NewState);
void HT_PMU_HoldSram2Config(FunctionalState NewState);
void HT_PMU_FlashDPDConfig(FunctionalState NewState);

void HT_PMU_LPRunConfig(FunctionalState NewState);
void HT_PMU_QuickWkpConfig(FunctionalState NewState);  
void HT_PMU_HFProtConfig(FunctionalState NewState);

void HT_PMU_NormalVrefConfig(uint32_t VrefValue);
void HT_PMU_LowpowerVrefConfig(uint32_t VrefValue);

FlagStatus HT_LPRUN_StatusGet(void);

#endif

#if defined USE_LDOVREF || defined USE_LPCFG
void HT_LDO_LP_VoltConfig(uint32_t VoltLvl);
#endif

FlagStatus HT_PMUState_FlagStatusGet(uint32_t STAFlag);
void HT_PMU_ITConfig(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_PMU_ITFlagStatusGet(uint32_t ITFlag);
void HT_PMU_ClearITPendingBit(uint32_t ITFlag);
#if  defined USE_DISCHARGE 
void HT_PMU_DisChargeConfig(DISCharge_TypeDef ChargeMode);
#endif

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
void HT_PMU_VccCpltCallback(PMU_InitTypeDef *PMU_InitStruct);
void HT_PMU_BorCpltCallback(PMU_InitTypeDef *PMU_InitStruct);
void HT_PMU_Lvd0CpltCallback(PMU_InitTypeDef *PMU_InitStruct);
#ifdef USE_LVDIN1
void HT_PMU_Lvd1CpltCallback(PMU_InitTypeDef *PMU_InitStruct);
#endif
#ifdef USE_LVDIN2
void HT_PMU_Lvd2CpltCallback(PMU_InitTypeDef *PMU_InitStruct);
#endif
#ifdef USE_POWDET
void HT_PMU_PowCpltCallback(PMU_InitTypeDef *PMU_InitStruct);
#endif
StatusTypeDef HT_PMU_RegisterCallback(PMU_InitTypeDef *PMU_InitStruct, PMU_CallbackIDTypeDef CallbackID, pPMU_CallbackTypeDef pCallback);
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_PMU_H__ */
