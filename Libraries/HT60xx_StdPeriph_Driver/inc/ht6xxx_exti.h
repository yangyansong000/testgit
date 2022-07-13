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
* File         : ht6xxx_exti.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_EXTI_H__
#define __HT6XXX_EXTI_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
										Local Macro/Structure
*********************************************************************************************************
*/

#define INT_EXTIF2_FIF_ALL      ((uint32_t)0x00FF)
#define INT_EXTIF2_RIF_ALL      ((uint32_t)0xFF00)

#define INT_EXTIE2_FIE_ALL      ((uint32_t)0x00FF)
#define INT_EXTIE2_RIE_ALL      ((uint32_t)0xFF00)
/*
*********************************************************************************************************
											Local Variables
*********************************************************************************************************
*/


#define IS_EXTIE_RISE_LINE0_6(LINE) (((LINE) == INT_EXTIE_RIE_INT0) || \
								((LINE) == INT_EXTIE_RIE_INT1) || \
								((LINE) == INT_EXTIE_RIE_INT2) || \
								((LINE) == INT_EXTIE_RIE_INT3) || \
								((LINE) == INT_EXTIE_RIE_INT4) || \
								((LINE) == INT_EXTIE_RIE_INT5) || \
								((LINE) == INT_EXTIE_RIE_INT6) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE_RIE)) == 0x00) && ((LINE) != 0x00)))

#define IS_EXTIE_RISE_LINE7_9(LINE) (((LINE) == INT_EXTIE2_RIE_INT7) || \
								((LINE) == INT_EXTIE2_RIE_INT8) || \
								((LINE) == INT_EXTIE2_RIE_INT9) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE2_RIE)) == 0x00) && ((LINE) != 0x00)))


#define IS_EXTIE_RISE_LINE10_14(LINE) (((LINE) == INT_EXTIE2_RIE_INT10) || \
								((LINE) == INT_EXTIE2_RIE_INT11) || \
								((LINE) == INT_EXTIE2_RIE_INT12) || \
                                ((LINE) == INT_EXTIE2_RIE_INT13) || \
                                ((LINE) == INT_EXTIE2_RIE_INT14) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE2_RIE)) == 0x00) && ((LINE) != 0x00)))


#define IS_EXTIE_FALL_LINE0_6(LINE) (((LINE) == INT_EXTIE_FIE_INT0) || \
								((LINE) == INT_EXTIE_FIE_INT1) || \
								((LINE) == INT_EXTIE_FIE_INT2) || \
								((LINE) == INT_EXTIE_FIE_INT3) || \
								((LINE) == INT_EXTIE_FIE_INT4) || \
								((LINE) == INT_EXTIE_FIE_INT5) || \
								((LINE) == INT_EXTIE_FIE_INT6) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE_FIE)) == 0x00) && ((LINE) != 0x00)))

#define IS_EXTIE_FALL_LINE7_9(LINE) (((LINE) == INT_EXTIE2_FIE_INT7) || \
								((LINE) == INT_EXTIE2_FIE_INT8) || \
								((LINE) == INT_EXTIE2_FIE_INT9) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE2_FIE)) == 0x00) && ((LINE) != 0x00)))

#define IS_EXTIE_FALL_LINE10_14(LINE) (((LINE) == INT_EXTIE2_FIE_INT10) || \
								((LINE) == INT_EXTIE2_FIE_INT11) || \
								((LINE) == INT_EXTIE2_FIE_INT12) || \
								((LINE) == INT_EXTIE2_FIE_INT13) || \
								((LINE) == INT_EXTIE2_FIE_INT14) || \
                                ((((LINE) & (uint32_t)(~INT_EXTIE2_FIE)) == 0x00) && ((LINE) != 0x00)))



#define IS_EXTI_GET_RISE_ITFlag0_6(ITFlag) (((ITFlag) == INT_EXTIF_RIF_INT0) || \
								((ITFlag) == INT_EXTIF_RIF_INT1) || \
								((ITFlag) == INT_EXTIF_RIF_INT2) || \
								((ITFlag) == INT_EXTIF_RIF_INT3) || \
								((ITFlag) == INT_EXTIF_RIF_INT4) || \
								((ITFlag) == INT_EXTIF_RIF_INT5) || \
								((ITFlag) == INT_EXTIF_RIF_INT6) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF_RIF)) == 0x00) && ((ITFlag) != 0x00)))



#define IS_EXTI_GET_RISE_ITFlag7_9(ITFlag) (((ITFlag) == INT_EXTIF2_RIF_INT7) || \
								((ITFlag) == INT_EXTIF2_RIF_INT8) || \
								((ITFlag) == INT_EXTIF2_RIF_INT9) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF2_RIF)) == 0x00) && ((ITFlag) != 0x00)))


#define IS_EXTI_GET_RISE_ITFlag10_14(ITFlag) (((ITFlag) == INT_EXTIF2_RIF_INT10) || \
								((ITFlag) == INT_EXTIF2_RIF_INT11) || \
								((ITFlag) == INT_EXTIF2_RIF_INT12) || \
                                ((ITFlag) == INT_EXTIF2_RIF_INT13) || \
                                ((ITFlag) == INT_EXTIF2_RIF_INT14) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF2_RIF)) == 0x00) && ((ITFlag) != 0x00)))


#define IS_EXTI_GET_FALL_ITFlag0_6(ITFlag) (((ITFlag) == INT_EXTIF_FIF_INT0) || \
								((ITFlag) == INT_EXTIF_FIF_INT1) || \
								((ITFlag) == INT_EXTIF_FIF_INT2) || \
								((ITFlag) == INT_EXTIF_FIF_INT3) || \
								((ITFlag) == INT_EXTIF_FIF_INT4) || \
								((ITFlag) == INT_EXTIF_FIF_INT5) || \
								((ITFlag) == INT_EXTIF_FIF_INT6) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF_FIF)) == 0x00) && ((ITFlag) != 0x00)))

#define IS_EXTI_GET_FALL_ITFlag7_9(ITFlag) (((ITFlag) == INT_EXTIF2_FIF_INT7) || \
								((ITFlag) == INT_EXTIF2_FIF_INT8) || \
								((ITFlag) == INT_EXTIF2_FIF_INT9) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF2_FIF)) == 0x00) && ((ITFlag) != 0x00)))

#define IS_EXTI_GET_FALL_ITFlag10_14(ITFlag) (((ITFlag) == INT_EXTIF2_FIF_INT10) || \
								((ITFlag) == INT_EXTIF2_FIF_INT11) || \
								((ITFlag) == INT_EXTIF2_FIF_INT12) || \
                                ((ITFlag) == INT_EXTIF2_FIF_INT13) || \
                                ((ITFlag) == INT_EXTIF2_FIF_INT14) || \
                                ((((ITFlag) & (uint32_t)(~INT_EXTIF2_FIF)) == 0x00) && ((ITFlag) != 0x00)))



#define IS_EXTI_INTFLT_LINE0_6(LINE) (((LINE) == INT_PINFLT_INTFLT_INT0) || \
								((LINE) == INT_PINFLT_INTFLT_INT1) || \
								((LINE) == INT_PINFLT_INTFLT_INT2) || \
								((LINE) == INT_PINFLT_INTFLT_INT3) || \
								((LINE) == INT_PINFLT_INTFLT_INT4) || \
								((LINE) == INT_PINFLT_INTFLT_INT5) || \
								((LINE) == INT_PINFLT_INTFLT_INT6)|| \
                                ((((LINE) & (uint32_t)(~INT_PINFLT_INTFLT)) == 0x00) && ((LINE) != 0x00)))

#define IS_EXTI_INTFLT_LINE7_9(LINE) (((LINE) == INT_PINFLT2_INTFLT_INT7) || \
								((LINE) == INT_PINFLT2_INTFLT_INT8) || \
								((LINE) == INT_PINFLT2_INTFLT_INT9)|| \
                                ((((LINE) & (uint32_t)(~INT_PINFLT2_INTFLT)) == 0x00) && ((LINE) != 0x00)))


#define IS_EXTI_INTFLT_LINE10_14(LINE) (((LINE) == INT_PINFLT2_INTFLT_INT10) || \
								((LINE) == INT_PINFLT2_INTFLT_INT11) || \
								((LINE) == INT_PINFLT2_INTFLT_INT12) || \
								((LINE) == INT_PINFLT2_INTFLT_INT13) || \
								((LINE) == INT_PINFLT2_INTFLT_INT14)|| \
                                ((((LINE) & (uint32_t)(~INT_PINFLT2_INTFLT)) == 0x00) && ((LINE) != 0x00)))


#define IS_EXTI_EWKUPIE_LINE1_2(LINE)  (((LINE) == INT_EWKUPIE_EWKUP1) || \
                                       ((LINE) == INT_EWKUPIE_EWKUP2)|| \
                                       ((((LINE) & (uint32_t)(~INT_EWKUPIE)) == 0x00) && ((LINE) != 0x00)))


#define IS_EXTI_GET_EWKUP_ITFlag1_2(ITFlag)  (((ITFlag) == INT_EWKUPIF_EWKUP1) || \
                                       ((ITFlag) == INT_EWKUPIF_EWKUP2)|| \
                                       ((((ITFlag) & (uint32_t)(~INT_EWKUPIF)) == 0x00) && ((ITFlag) != 0x00)))



#if (USE_HT_EXTI_REGISTER_CALLBACKS ==1U)

#define EXTI_ERROR_INVALID_CALLBACK  0x00000050U   /*!< Invalid Callback error  */

typedef struct __EXTI_TypeDef
{
    HT_INT_TypeDef *Instance;                  /*!< INT(EXTI) registers base address        */
    __IO uint32_t  ErrorCode;        		  /*!< INT(EXTI) Error code                    */
    void (* RiseCallback)(struct __EXTI_TypeDef *EXTI_Struct);            /*!< Rising edge detection  Callback             */
    void (* FallCallback)(struct __EXTI_TypeDef *EXTI_Struct);            /*!< Falling edge detection Callback             */
    
    void (* EWKUPCallback)(struct __EXTI_TypeDef *EXTI_Struct);            /*!< wake up  Interrupt Callback             */ 
    

} EXTI_TypeDef;                              /*!< end of group EXTI_TypeDef   */

/**
* @brief  INT(EXTI) Callback ID enumeration definition
*/
typedef enum
{
    Exti_Rise_CB_ID             = 0x01U,    	 /*!< Rising edge detection Callback ID             */
    Exti_Fall_CB_ID             = 0x02U,    	 /*!< Falling edge detection Callback ID             */
    Exti_EWKUP_CB_ID            = 0x03U,    	 /*!< wake up  Interrupt Callback ID             */
} EXTI_CallbackIDTypeDef;

/**
* @brief  INT(EXTI) Callback pointer definition
*/
typedef  void (*pEXTI_CallbackTypeDef)(EXTI_TypeDef *ExtiStruct);  /*!< pointer to an INT(EXTI) callback function */

#endif



/*
*********************************************************************************************************
										Local Function Declaration
*********************************************************************************************************
*/

void HT_EXTIRise_ITConfig(uint32_t ITEn, FunctionalState NewState);
void HT_EXTIFall_ITConfig(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_EXTIRise_ITFlagStatusGet(uint32_t ITFlag);
ITStatus HT_EXTIFall_ITFlagStatusGet(uint32_t ITFlag);
void HT_EXTIRise_ClearITPendingBit(uint32_t ITFlag);
void HT_EXTIFall_ClearITPendingBit(uint32_t ITFlag);
void HT_EXTI_FilterConfig(uint32_t ITFLTEn,FunctionalState NewState);

#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1U)
void EXTI_InitCallbacksToDefault(EXTI_TypeDef *ExtiStruct);
void HT_EXTI_InitCallback(EXTI_TypeDef *ExtiStruct);
void HT_EXTI_FallCallback(EXTI_TypeDef *ExtiStruct);
void HT_EXTI_RiseCallback(EXTI_TypeDef *ExtiStruct);

StatusTypeDef HT_EXTI_RegisterCallback(EXTI_TypeDef *ExtiStruct, EXTI_CallbackIDTypeDef Exti_CallbackID, pEXTI_CallbackTypeDef pCallback);
#endif /* USE_HT_EXTI_REGISTER_CALLBACKS */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_EXTI_H__ */
