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
* File         : ht6xxx_tbs.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_TBS_H__
#define __HT6XXX_TBS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
typedef enum
{
	TBS_TMP_COMPLETE_CB_ID                   =0x01U,
	TBS_VBAT_COMPLETE_CB_ID                  =0x02U,
	TBS_VDD_COMPLETE_CB_ID                   =0x03U,
	TBS_ADC0_COMPLETE_CB_ID                  =0x04U,
	TBS_ADC1_COMPLETE_CB_ID                  =0x05U,
	TBS_ADC2_COMPLETE_CB_ID                  =0x06U,
	TBS_ADC3_COMPLETE_CB_ID                  =0x07U,
	TBS_VBATCMP_COMPLETE_CB_ID               =0x08U,
	TBS_ADC0CMP_COMPLETE_CB_ID               =0x09U,
	TBS_ADC1CMP_COMPLETE_CB_ID               =0x10U,
	TBS_ADC4_COMPLETE_CB_ID                  =0x11U,
	TBS_ADC5_COMPLETE_CB_ID                  =0x12U,
	TBS_ADC6_COMPLETE_CB_ID                  =0x13U,
    TBS_ADC7_COMPLETE_CB_ID                  =0x14U,
    TBS_ADC8_COMPLETE_CB_ID                  =0x15U,
    TBS_ADC9_COMPLETE_CB_ID                  =0x16U,
	TBS_TDVREF_COMPLETE_CB_ID                =0x21U,
	TBS_TDVREFCMP_COMPLETE_CB_ID             =0x22U,
	TBS_VREF_COMPLETE_CB_ID                  =0x23U,
	TBS_VTP0_COMPLETE_CB_ID                  =0x24U,
	TBS_VTP1_COMPLETE_CB_ID                  =0x25U,
	TBS_VTP2_COMPLETE_CB_ID                  =0x26U,
	TBS_VTP3_COMPLETE_CB_ID                  =0x27U,
	TBS_VTP4_COMPLETE_CB_ID                  =0x28U,
	TBS_VTP5_COMPLETE_CB_ID                  =0x29U,
	TBS_VTP6_COMPLETE_CB_ID                  =0x30U,
	TBS_VTP7_COMPLETE_CB_ID                  =0x31U,
}TBS_CallbackIDTypeDef;

#define IS_HT_TBS_FILCNTCONFIG(FilterVal)                                  (((FilterVal) == TBS_ADCFilterCnt_1) || \
																			((FilterVal) == TBS_ADCFilterCnt_2) || \
																			((FilterVal) == TBS_ADCFilterCnt_4) || \
																			((FilterVal) == TBS_ADCFilterCnt_8))

#if defined HT501x  ||  defined  HT502x

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC2PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) ==  TMPPRD) || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD)   || \
																														 ((PRDModule) == ADC2PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_ADC2IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC0CMPIE|TBS_TBSIE_ADC1CMPIE)

#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC2IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1CMPIE) || \
																 ((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_PERIOD(Period)				 	(((Period) == TBS_TBSPRD_TMPPRD_1S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_8S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_32S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_125mS) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_4S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_32S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_4S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_32S))

#define	TBS_TBSCON_ALLEn		(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC0CMPEn|TBS_TBSCON_ADC1CMPEn|TBS_TBSCON_VBATCMPEn \
													|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_ADC2En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule)	              (((TBS_SubModule) == TBS_TBSCON_TMPEn) || \
																																((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																																((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																																((TBS_SubModule) == TBS_TBSCON_ADC0CMPEn) || \
																																((TBS_SubModule) == TBS_TBSCON_ADC1CMPEn) || \
																																((TBS_SubModule) == TBS_TBSCON_VBATCMPEn) || \
																																((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																																((TBS_SubModule) == TBS_TBSCON_VCCEn) || \
																																((TBS_SubModule) == TBS_TBSCON_ADC2En) || \
																																((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)                  (((CmpReg) == CMP_VBAT) || \
																   ((CmpReg) == CMP_ADC0) || \
																   ((CmpReg) == CMP_ADC1))

#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)                  (((SubModule) == TBS_TMP)|| \
																   ((SubModule) == TBS_VBAT)|| \
                                                                   ((SubModule) == TBS_VCC) || \
																   ((SubModule) == TBS_ADC0)|| \
																   ((SubModule) == TBS_ADC1)|| \
																   ((SubModule) == TBS_ADC2))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC2IF|TBS_TBSIF_ADC0CMPIF \
																	 |TBS_TBSIF_ADC1CMPIF))
#define IS_HT_TBS_ITFLAG(ITFlag)								  (((ITFlag) == TBS_TBSIF_TMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC2IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1CMPIF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))


#endif

#if defined HT503x 

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC2PRD|ADC3PRD|ADC4PRD|ADC5PRD|ADC6PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule)                    (((PRDModule) ==  TMPPRD) || \
																																		 ((PRDModule) == VBATPRD) || \
																																		 ((PRDModule) == ADC0PRD) || \
																																		 ((PRDModule) == ADC1PRD) || \
																																		 ((PRDModule) == VCCPRD)  || \
																																		 ((PRDModule) == ADC2PRD) || \
																																		 ((PRDModule) == ADC3PRD) || \
																																		 ((PRDModule) == ADC4PRD) || \
																																		 ((PRDModule) == ADC5PRD) || \
																																		 ((PRDModule) == ADC6PRD) || \
																																		 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_ADC2IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC0CMPIE\
                         |TBS_TBSIE_ADC1CMPIE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE|TBS_TBSIE_ADC6IE)
#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC2IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC6IE) || \
                                   								((((ITEn) & TBS_TBSIE_ALLIE) == 0x00) && ((ITEn) != 0x00)))
																												 
#define IS_HT_TBS_PERIODSET_PERIOD(Period)                  (((Period) == TBS_TBSPRD_TMPPRD_1S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_8S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_32S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_125mS) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_4S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_32S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_4S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC2PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_32S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_4S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_32S))

#define	TBS_TBSCON_ALLEn		(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_ADC0CMPEn|TBS_TBSCON_ADC1CMPEn|TBS_TBSCON_VBATCMPEn|TBS_TBSCON_VCCEn \
													|TBS_TBSCON_ADC2En|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En|TBS_TBSCON_ADC5En|TBS_TBSCON_ADC6En)
#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule)                    (((TBS_SubModule) == TBS_TBSCON_TMPEn)  || \
																																			((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
                                                                      ((TBS_SubModule) == TBS_TBSCON_ADC0CMPEn) || \
                                                                      ((TBS_SubModule) == TBS_TBSCON_ADC1CMPEn) || \
                                                                      ((TBS_SubModule) == TBS_TBSCON_VBATCMPEn) || \
																																			((TBS_SubModule) == TBS_TBSCON_VCCEn)  || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC2En) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
																																			((TBS_SubModule) == TBS_TBSCON_ADC6En) || \
																																			((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)		 (((CmpReg) == CMP_VBAT) || \
														  ((CmpReg) == CMP_ADC0) || \
														  ((CmpReg) == CMP_ADC1))

#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule) 			(((SubModule) == TBS_TMP) || \
															 ((SubModule) == TBS_VBAT)|| \
                                                             ((SubModule) == TBS_VCC) || \
															 ((SubModule) == TBS_ADC0)|| \
															 ((SubModule) == TBS_ADC1)|| \
															 ((SubModule) == TBS_ADC2)|| \
                                                             ((SubModule) == TBS_ADC3)|| \
                                                             ((SubModule) == TBS_ADC4)|| \
                                                             ((SubModule) == TBS_ADC5)|| \
                                                             ((SubModule) == TBS_ADC6))

#define IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel)		(((ClkSel) == TBS_CLKSEL_OSC)   || \
													 ((ClkSel) == TBS_CLKSEL_LRC) || \
													 ((ClkSel) == TBS_CLKSEL_LSTBSCLK_10) || \
													 ((ClkSel) == TBS_CLKSEL_LSTBSCLK_11))
													 
													 

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC2IF|TBS_TBSIF_ADC0CMPIF \
																	 |TBS_TBSIF_ADC1CMPIF|TBS_TBSIF_ADC3IF|TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF|TBS_TBSIF_ADC6IF))
#define IS_HT_TBS_ITFLAG(ITFlag)                                  (((ITFlag) == TBS_TBSIF_TMPIF) || \
																   ((ITFlag) == TBS_TBSIF_VBATIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF) || \
																   ((ITFlag) == TBS_TBSIF_ADC2IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC5IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC6IF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))

#define IS_HT_TBS_ADCTRISAMPLE(TriChn)                      (((TriChn) == TBS_TRI_TMP)  || \
															 ((TriChn) == TBS_TRI_VBAT) || \
															 ((TriChn) == TBS_TRI_ADC0) || \
															 ((TriChn) == TBS_TRI_VDD)  || \
															 ((TriChn) == TBS_TRI_ADC1) || \
															 ((TriChn) == TBS_TRI_ADC2) || \
															 ((TriChn) == TBS_TRI_ADC3) || \
															 ((TriChn) == TBS_TRI_ADC4) || \
															 ((TriChn) == TBS_TRI_ADC5) || \
															 ((TriChn) == TBS_TRI_ADC6))

#define IS_HT_TBS_ADCINJECTSAMPLE(InjectChn)            (((InjectChn) == TBS_INJECT_TMP)  || \
														 ((InjectChn) == TBS_INJECT_ADC0) || \
														 ((InjectChn) == TBS_INJECT_ADC1) || \
														 ((InjectChn) == TBS_INJECT_ADC2) || \
														 ((InjectChn) == TBS_INJECT_ADC3) || \
														 ((InjectChn) == TBS_INJECT_ADC4) || \
														 ((InjectChn) == TBS_INJECT_ADC5) || \
														 ((InjectChn) == TBS_INJECT_ADC6) || \
														 ((InjectChn) == TBS_INJECT_VDD)  || \
														 ((InjectChn) == TBS_INJECT_VBAT))
#endif

#if defined HT6x1x 

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) ==  TMPPRD) || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_VBATCMPIE)
#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE) || \
																((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_PERIOD(Period) 					(((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS)|| \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_2S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_16S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S))

#define	TBS_TBSCON_ALLEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn)
#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule) 					 (((TBS_SubModule) == TBS_TBSCON_TMPEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																															((TBS_SubModule) == TBS_TBSCON_VCCEn) || \
																															((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)		(((CmpReg) == CMP_VBAT))

#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)			(((SubModule) == TBS_TMP) || \
															 ((SubModule) == TBS_VBAT)|| \
															 ((SubModule) == TBS_ADC0)|| \
															 ((SubModule) == TBS_ADC1))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF))
#define IS_HT_TBS_ITFLAG(ITFlag)								  (((ITFlag) == TBS_TBSIF_TMPIF)    || \
																   ((ITFlag) == TBS_TBSIF_VBATIF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)   || \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))
																					   
#endif

#if defined HT6x2x

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC3PRD|ADC4PRD|ADC5PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) == TMPPRD)  || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD)  || \
																														 ((PRDModule) == ADC3PRD) || \
																														 ((PRDModule) == ADC4PRD) || \
																														 ((PRDModule) == ADC5PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC0CMPIE|TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE)
#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE) || \
																((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_PERIOD(Period)					(((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_16S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_16S))

#define	TBS_TBSCON_ALLEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En|TBS_TBSCON_ADC5En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule) 					 (((TBS_SubModule) == TBS_TBSCON_TMPEn) || \
																															((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																															((TBS_SubModule) == TBS_TBSCON_VCCEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
																															((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)				(((CmpReg) == CMP_VBAT) || \
																 ((CmpReg) == CMP_ADC0))
																							  
#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)					(((SubModule) == TBS_TMP) || \
																	 ((SubModule) == TBS_VBAT)|| \
																	 ((SubModule) == TBS_ADC0)|| \
																	 ((SubModule) == TBS_ADC1)|| \
                                                                     ((SubModule) == TBS_ADC3)|| \
                                                                     ((SubModule) == TBS_ADC4)|| \
                                                                     ((SubModule) == TBS_ADC5))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC0CMPIF|TBS_TBSIF_ADC3IF \
																	 |TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF))
#define IS_HT_TBS_ITFLAG(ITFlag)								  (((ITFlag) == TBS_TBSIF_TMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC5IF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))
#endif

#if defined HT6x2xK

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC3PRD|ADC4PRD|ADC5PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) == TMPPRD)  || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD)  || \
																														 ((PRDModule) == ADC3PRD) || \
																														 ((PRDModule) == ADC4PRD) || \
																														 ((PRDModule) == ADC5PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC0CMPIE|TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE)
#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE) || \
																 ((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_PERIOD(Period)					(((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_16S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_16S))

#define	TBS_TBSCON_ALLEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En|TBS_TBSCON_ADC5En|TBS_TBSCON_TBS_NEWREG_En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule) 					 (((TBS_SubModule) == TBS_TBSCON_TMPEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																															((TBS_SubModule) == TBS_TBSCON_VCCEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
                                                              ((TBS_SubModule) == TBS_TBSCON_TBS_NEWREG_En) || \
																															((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)				(((CmpReg) == CMP_VBAT) || \
																 ((CmpReg) == CMP_ADC0))
																							  
#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)					(((SubModule) == TBS_TMP)|| \
																	 ((SubModule) == TBS_VBAT)|| \
																	 ((SubModule) == TBS_ADC0)|| \
																	 ((SubModule) == TBS_ADC1)|| \
                                                                     ((SubModule) == TBS_ADC3)|| \
                                                                     ((SubModule) == TBS_ADC4)|| \
                                                                     ((SubModule) == TBS_ADC5))

#define IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel)		(((ClkSel) == TBS_CLKSEL_OSC)   || \
													 ((ClkSel) == TBS_CLKSEL_PLLDIV))

#define IS_HT_TBS_ADCTRISAMPLE(TriChn)                      (((TriChn) == TBS_TRI_TMP)  || \
															 ((TriChn) == TBS_TRI_VBAT) || \
															 ((TriChn) == TBS_TRI_ADC0) || \
															 ((TriChn) == TBS_TRI_VCC)  || \
															 ((TriChn) == TBS_TRI_ADC1) || \
															 ((TriChn) == TBS_TRI_ADC3) || \
															 ((TriChn) == TBS_TRI_ADC4) || \
															 ((TriChn) == TBS_TRI_ADC5))

#define IS_HT_TBS_ADCINJECTSAMPLE(InjectChn)            (((InjectChn) == TBS_INJECT_TMP)  || \
														 ((InjectChn) == TBS_INJECT_ADC0) || \
														 ((InjectChn) == TBS_INJECT_ADC1) || \
														 ((InjectChn) == TBS_INJECT_ADC3) || \
														 ((InjectChn) == TBS_INJECT_ADC4) || \
														 ((InjectChn) == TBS_INJECT_ADC5) || \
														 ((InjectChn) == TBS_INJECT_VCC)  || \
														 ((InjectChn) == TBS_INJECT_VBAT))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC0CMPIF|TBS_TBSIF_ADC3IF \
																	 |TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF))
#define IS_HT_TBS_ITFLAG(ITFlag)								  (((ITFlag) == TBS_TBSIF_TMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC5IF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))
                                                                   
#define IS_HT_TBS_INJECTCLKCFG(InjectClkSel)                ((InjectClkSel) <= (TBS_INJECTCLK_SEL_END>>8))
#endif

#if defined HT6x3x

#define	PRD_ALL	(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC3PRD|ADC4PRD|ADC5PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) ==  TMPPRD) || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD)  || \
																														 ((PRDModule) == ADC3PRD) || \
																														 ((PRDModule) == ADC4PRD) || \
																														 ((PRDModule) == ADC5PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC0CMPIE|TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE)
#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE) || \
																 ((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_PERIOD(Period)				    (((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS)|| \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_2S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S)  || \
															 ((Period) == TBS_TBSPRD_VBATPRD_16S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_16S))

#define	TBS_TBSCON_ALLEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En|TBS_TBSCON_ADC5En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule)						 (((TBS_SubModule) == TBS_TBSCON_TMPEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																															((TBS_SubModule) == TBS_TBSCON_VCCEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
																															((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)			(((CmpReg) == CMP_VBAT) || \
															 ((CmpReg) == CMP_ADC0))

#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)				(((SubModule) == TBS_TMP) || \
																 ((SubModule) == TBS_VBAT)|| \
																 ((SubModule) == TBS_ADC0)|| \
																 ((SubModule) == TBS_ADC1)|| \
                                                                 ((SubModule) == TBS_VCC)|| \
                                                                 ((SubModule) == TBS_ADC3)|| \
                                                                 ((SubModule) == TBS_ADC4)|| \
                                                                 ((SubModule) == TBS_ADC5))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC0CMPIF|TBS_TBSIF_ADC3IF \
																	 |TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF))
#define IS_HT_TBS_ITFLAG(ITFlag)                                  (((ITFlag) == TBS_TBSIF_TMPIF)    || \
																   ((ITFlag) == TBS_TBSIF_VBATIF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)   || \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)    || \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)   || \
																   ((ITFlag) == TBS_TBSIF_ADC5IF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))

#define IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel)		(((ClkSel) == TBS_CLKSEL_OSC)   || \
													 ((ClkSel) == TBS_CLKSEL_PLLDIV))

#define IS_HT_TBS_ADCTRISAMPLE(TriChn)                      (((TriChn) == TBS_TRI_TMP)  || \
															 ((TriChn) == TBS_TRI_VBAT) || \
															 ((TriChn) == TBS_TRI_ADC0) || \
															 ((TriChn) == TBS_TRI_VCC)  || \
															 ((TriChn) == TBS_TRI_ADC1) || \
															 ((TriChn) == TBS_TRI_ADC3) || \
															 ((TriChn) == TBS_TRI_ADC4) || \
															 ((TriChn) == TBS_TRI_ADC5))
#endif

#if defined HT762x ||  defined  HT772x 

#define	PRD_ALL	(TMPPRD|TDVREFPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC3PRD|ADC4PRD|ADC5PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule)            (((PRDModule) ==  TMPPRD)  || \
																														 ((PRDModule) == TDVREFPRD)|| \
																														 ((PRDModule) == ADC0PRD)  || \
																														 ((PRDModule) == ADC1PRD)  || \
																														 ((PRDModule) == VCCPRD)   || \
																														 ((PRDModule) == ADC3PRD)  || \
																														 ((PRDModule) == ADC4PRD)  || \
																														 ((PRDModule) == ADC5PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_TDVREFIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_TDVREFCMPIE|TBS_TBSIE_ADC0CMPIE\
                         |TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE|TBS_TBSIE_VTP0IE|TBS_TBSIE_VTP1IE|TBS_TBSIE_VTP2IE|TBS_TBSIE_VTP3IE\
                         |TBS_TBSIE_VTP4IE|TBS_TBSIE_VTP5IE|TBS_TBSIE_VTP6IE|TBS_TBSIE_VTP7IE)

#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_TDVREFIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_TDVREFCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP2IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP5IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP6IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VTP7IE) || \
																 ((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))

#define IS_HT_TBS_PERIODSET_VTPPRDMODULE(VTPPRDModule)                  (((VTPPRDModule) == VTP0PRD)  || \
																		 ((VTPPRDModule) == VTP1PRD)  || \
																		 ((VTPPRDModule) == VTP2PRD)  || \
																		 ((VTPPRDModule) == VTP3PRD)  || \
																		 ((VTPPRDModule) == VTP4PRD)  || \
																		 ((VTPPRDModule) == VTP5PRD)  || \
																		 ((VTPPRDModule) == VTP6PRD)  || \
																		 ((VTPPRDModule) == VTP7PRD))
                                                                         
#define IS_HT_TBS_PERIODSET_VTPPERIOD(VTPPeriod)                  (((VTPPeriod) == TBS_VTPPRD_VTP0PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP0PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP0PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP0PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP1PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP1PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP1PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP1PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP2PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP2PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP2PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP2PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP3PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP3PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP3PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP3PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP4PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP4PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP4PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP4PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP5PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP5PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP5PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP5PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP6PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP6PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP6PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP6PRD_16S) || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP7PRD_1S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP7PRD_2S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP7PRD_8S)  || \
                                                                   ((VTPPeriod) == TBS_VTPPRD_VTP7PRD_16S))
																												 
#define IS_HT_TBS_PERIODSET_PERIOD(Period)                  (((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S)    || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S)  || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS)|| \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS)  || \
															 ((Period) == TBS_TBSPRD_TDVREFPRD_1S) || \
															 ((Period) == TBS_TBSPRD_TDVREFPRD_2S) || \
															 ((Period) == TBS_TBSPRD_TDVREFPRD_8S) || \
															 ((Period) == TBS_TBSPRD_TDVREFPRD_16S)|| \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S)   || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_2S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S)  || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_16S))

#define	TBS_TBSCON_ALLTBSEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_TDVREFEn|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En|TBS_TBSCON_ADC5En)

#define TBS_TBSCON_ALLVTPEn (TBS_TBSCON_PGA_En|TBS_TBSCON_PGA_SEL|TBS_TBSCON_VTP0En|TBS_TBSCON_VTP1En|TBS_TBSCON_VTP2En|TBS_TBSCON_VTP3En|TBS_TBSCON_VTP4En|TBS_TBSCON_VTP5En \
							|TBS_TBSCON_VTP6En|TBS_TBSCON_VTP7En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule)                      (((TBS_SubModule) == TBS_TBSCON_TMPEn)    || \
																																				((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																																				((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VCCEn)  || \
																																				((TBS_SubModule) == TBS_TBSCON_TDVREFEn) || \
																																				((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																																				((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																																				((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
																																				((TBS_SubModule) == TBS_TBSCON_PGA_En) || \
                                                                        ((TBS_SubModule) == TBS_TBSCON_PGA_SEL)|| \
																																				((TBS_SubModule) == TBS_TBSCON_VTP0En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP1En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP2En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP3En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP4En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP5En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP6En) || \
																																				((TBS_SubModule) == TBS_TBSCON_VTP7En) || \
																																				((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLTBSEn)) == 0x00) && ((TBS_SubModule) != 0x00)) || \
                                                                                                                                                ((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLVTPEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)	(((CmpReg) == CMP_TDVREF) || \
													 ((CmpReg) == CMP_ADC0))

#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule) 	  (((SubModule) == TBS_TMP) || \
													   ((SubModule) == TBS_TDVREF)|| \
													   ((SubModule) == TBS_ADC0)|| \
													   ((SubModule) == TBS_ADC1)|| \
                                                       ((SubModule) == TBS_VCC) || \
                                                       ((SubModule) == TBS_ADC3)|| \
                                                       ((SubModule) == TBS_ADC4)|| \
                                                       ((SubModule) == TBS_ADC5)|| \
													   ((SubModule) == TBS_VTP0)|| \
													   ((SubModule) == TBS_VTP1)|| \
													   ((SubModule) == TBS_VTP2)|| \
													   ((SubModule) == TBS_VTP3)|| \
													   ((SubModule) == TBS_VTP4)|| \
													   ((SubModule) == TBS_VTP5)|| \
													   ((SubModule) == TBS_VTP6)|| \
													   ((SubModule) == TBS_VTP7))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_TDVREFIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_TDVREFCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC0CMPIF|TBS_TBSIF_ADC3IF \
																	 |TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF|TBS_TBSIF_VTP0IF|TBS_TBSIF_VTP1IF|TBS_TBSIF_VTP2IF \
																	 |TBS_TBSIF_VTP3IF|TBS_TBSIF_VTP4IF|TBS_TBSIF_VTP5IF|TBS_TBSIF_VTP6IF|TBS_TBSIF_VTP7IF))

#define IS_HT_TBS_ITFLAG(ITFlag)                                  (((ITFlag) == TBS_TBSIF_TMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_TDVREFIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_TDVREFCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC5IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP0IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP2IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP3IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP4IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP5IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP6IF)|| \
																   ((ITFlag) == TBS_TBSIF_VTP7IF) || \
                                   ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))

#define IS_HT_TBS_ADCTRISAMPLE(TriChn)                      (((TriChn) == TBS_TRI_TMP)    || \
															 ((TriChn) == TBS_TRI_TDVREF) || \
															 ((TriChn) == TBS_TRI_ADC0)   || \
															 ((TriChn) == TBS_TRI_VCC)    || \
															 ((TriChn) == TBS_TRI_ADC1)   || \
															 ((TriChn) == TBS_TRI_ADC3)   || \
															 ((TriChn) == TBS_TRI_ADC4)   || \
															 ((TriChn) == TBS_TRI_ADC5)   || \
															 ((TriChn) == TBS_TRI_VTP0)   || \
															 ((TriChn) == TBS_TRI_VTP1)   || \
															 ((TriChn) == TBS_TRI_VTP2)   || \
															 ((TriChn) == TBS_TRI_VTP3)   || \
															 ((TriChn) == TBS_TRI_VTP4)   || \
															 ((TriChn) == TBS_TRI_VTP5)   || \
															 ((TriChn) == TBS_TRI_VTP6)   || \
															 ((TriChn) == TBS_TRI_VTP7))

#define IS_HT_TBS_ADCINJECTSAMPLE(InjectChn)            (((InjectChn) == TBS_INJECT_TMP)    || \
														 ((InjectChn) == TBS_INJECT_ADC0)   || \
														 ((InjectChn) == TBS_INJECT_ADC1)   || \
														 ((InjectChn) == TBS_INJECT_ADC3)   || \
														 ((InjectChn) == TBS_INJECT_ADC4)   || \
														 ((InjectChn) == TBS_INJECT_ADC5)   || \
														 ((InjectChn) == TBS_INJECT_TDVREF) || \
														 ((InjectChn) == TBS_INJECT_VCC))

#define IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel)		(((ClkSel) == TBS_CLKSEL_OSC)|| \
													 ((ClkSel) == TBS_CLKSEL_PLLDIV))
                                                     
#define IS_HT_TBS_TPGACONFIG(TPGAVal)                                      (((TPGAVal) == TBS_TPGACnt_2) || \
																			((TPGAVal) == TBS_TPGACnt_4) || \
																			((TPGAVal) == TBS_TPGACnt_8) || \
																			((TPGAVal) == TBS_TPGACnt_16))
                                                                            
#define IS_HT_TBS_INJECTCLKCFG(InjectClkSel)                ((InjectClkSel) <= (TBS_INJECTCLK_SEL_END>>8))
#endif

#if defined HT633x ||  defined  HT633xH
#define	PRD_ALL		(TMPPRD|VBATPRD|ADC0PRD|ADC1PRD|VCCPRD|ADC3PRD|ADC4PRD|ADC5PRD|ADC6PRD|ADC7PRD|ADC8PRD|ADC9PRD)

#define IS_HT_TBS_PERIODSET_PRDMODULE(PRDModule) 						(((PRDModule) == TMPPRD)  || \
																														 ((PRDModule) == VBATPRD) || \
																														 ((PRDModule) == ADC0PRD) || \
																														 ((PRDModule) == ADC1PRD) || \
																														 ((PRDModule) == VCCPRD)  || \
																														 ((PRDModule) == ADC3PRD) || \
																														 ((PRDModule) == ADC4PRD) || \
																														 ((PRDModule) == ADC5PRD) || \
																														 ((PRDModule) == ADC6PRD) || \
																														 ((PRDModule) == ADC7PRD) || \
																														 ((PRDModule) == ADC8PRD) || \
																														 ((PRDModule) == ADC9PRD) || \
																														 ((((PRDModule) & (uint32_t)(~PRD_ALL)) == 0x00) && ((PRDModule) != 0x00)))

#define	TBS_TBSIE_ALLIE	(TBS_TBSIE_TMPIE|TBS_TBSIE_VBATIE|TBS_TBSIE_VCCIE|TBS_TBSIE_ADC0IE|TBS_TBSIE_ADC1IE|TBS_TBSIE_VBATCMPIE|TBS_TBSIE_ADC0CMPIE\
                         |TBS_TBSIE_ADC3IE|TBS_TBSIE_ADC4IE|TBS_TBSIE_ADC5IE|TBS_TBSIE_ADC6IE|TBS_TBSIE_ADC7IE|TBS_TBSIE_ADC8IE|TBS_TBSIE_ADC9IE)

#define IS_HT_TBS_ITCONFIG_ITEN(ITEn)                           (((ITEn) == TBS_TBSIE_TMPIE) || \
                                                                 ((ITEn) == TBS_TBSIE_VBATIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VCCIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC1IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_VBATCMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC0CMPIE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC3IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC4IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC5IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC6IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC7IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC8IE)|| \
                                                                 ((ITEn) == TBS_TBSIE_ADC9IE) || \
																 ((((ITEn) & (uint32_t)(~TBS_TBSIE_ALLIE)) == 0x00) && ((ITEn) != 0x00)))                                                                         

#define IS_HT_TBS_PERIODSET_PERIOD(Period)					(((Period) == TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC1S_MEM4S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC2S_MEM2S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC4S_MEM1S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS) || \
															 ((Period) == TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VBATPRD_16S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_1S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_2S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_8S) || \
															 ((Period) == TBS_TBSPRD_VCCPRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC0PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC1PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC3PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC4PRD_16S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC5PRD_16S)|| \
                                                             ((Period) == TBS_TBSPRD_ADC6PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC6PRD_16S)|| \
                                                             ((Period) == TBS_TBSPRD_ADC7PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC7PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC7PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC7PRD_16S)|| \
                                                             ((Period) == TBS_TBSPRD_ADC8PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC8PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC8PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC8PRD_16S)|| \
                                                             ((Period) == TBS_TBSPRD_ADC9PRD_1S) || \
															 ((Period) == TBS_TBSPRD_ADC9PRD_2S) || \
															 ((Period) == TBS_TBSPRD_ADC9PRD_8S) || \
															 ((Period) == TBS_TBSPRD_ADC9PRD_16S))

#define	TBS_TBSCON_ALLEn	(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En|TBS_TBSCON_VCCEn|TBS_TBSCON_ADC3En|TBS_TBSCON_ADC4En \
												|TBS_TBSCON_ADC5En|TBS_TBSCON_ADC6En|TBS_TBSCON_ADC7En|TBS_TBSCON_ADC8En|TBS_TBSCON_ADC9En)

#define IS_TBS_TBSCONFIG_SUBMODULE(TBS_SubModule) 					 (((TBS_SubModule) == TBS_TBSCON_TMPEn) || \
																															((TBS_SubModule) == TBS_TBSCON_VBATEn) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC0En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC1En) || \
																															((TBS_SubModule) == TBS_TBSCON_VCCEn)  || \
																															((TBS_SubModule) == TBS_TBSCON_ADC3En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC4En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC5En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC6En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC7En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC8En) || \
																															((TBS_SubModule) == TBS_TBSCON_ADC9En) || \
																															((((TBS_SubModule) & (uint32_t)(~TBS_TBSCON_ALLEn)) == 0x00) && ((TBS_SubModule) != 0x00)))

#define IS_HT_TBS_CMPTHRESHOLDSET_CMPREG(CmpReg)				(((CmpReg) == CMP_VBAT) || \
																 ((CmpReg) == CMP_ADC0))
																							  
#define IS_HT_TBS_VALUEREAD_SUBMODULE(SubModule)					(((SubModule) == TBS_TMP) || \
																	 ((SubModule) == TBS_VBAT)|| \
																	 ((SubModule) == TBS_ADC0)|| \
																	 ((SubModule) == TBS_ADC1)|| \
                                                                     ((SubModule) == TBS_VCC) || \
                                                                     ((SubModule) == TBS_ADC3)|| \
                                                                     ((SubModule) == TBS_ADC4)|| \
                                                                     ((SubModule) == TBS_ADC5)|| \
                                                                     ((SubModule) == TBS_ADC6)|| \
                                                                     ((SubModule) == TBS_ADC7)|| \
                                                                     ((SubModule) == TBS_ADC8)|| \
                                                                     ((SubModule) == TBS_ADC9))

#define IS_HT_TBS_CLKSELCONFIG_CLKSEL(ClkSel)		(((ClkSel) == TBS_CLKSEL_OSC)   || \
													 ((ClkSel) == TBS_CLKSEL_LRC) || \
													 ((ClkSel) == TBS_CLKSEL_LSTBSCLK_10) || \
													 ((ClkSel) == TBS_CLKSEL_LSTBSCLK_11))
                                                     
#define IS_HT_TBS_ADCTRISAMPLE(TriChn)                      (((TriChn) == TBS_TRI_TMP)  || \
															 ((TriChn) == TBS_TRI_VBAT) || \
															 ((TriChn) == TBS_TRI_ADC0) || \
															 ((TriChn) == TBS_TRI_VCC)  || \
															 ((TriChn) == TBS_TRI_ADC1) || \
															 ((TriChn) == TBS_TRI_ADC3) || \
															 ((TriChn) == TBS_TRI_ADC4) || \
															 ((TriChn) == TBS_TRI_ADC5) || \
                                                             ((TriChn) == TBS_TRI_ADC6) || \
                                                             ((TriChn) == TBS_TRI_ADC7) || \
                                                             ((TriChn) == TBS_TRI_ADC8) || \
                                                             ((TriChn) == TBS_TRI_ADC9))

#define IS_HT_TBS_ADCINJECTSAMPLE(InjectChn)            (((InjectChn) == TBS_INJECT_TMP)  || \
														 ((InjectChn) == TBS_INJECT_ADC0) || \
														 ((InjectChn) == TBS_INJECT_ADC1) || \
														 ((InjectChn) == TBS_INJECT_ADC3) || \
														 ((InjectChn) == TBS_INJECT_ADC4) || \
														 ((InjectChn) == TBS_INJECT_ADC5) || \
														 ((InjectChn) == TBS_INJECT_VCC)  || \
														 ((InjectChn) == TBS_INJECT_VBAT) || \
                                                         ((InjectChn) == TBS_INJECT_ADC6) || \
                                                         ((InjectChn) == TBS_INJECT_ADC7) || \
                                                         ((InjectChn) == TBS_INJECT_ADC8) || \
                                                         ((InjectChn) == TBS_INJECT_ADC9))

#define	TBS_ITFLAG_MASK	(uint32_t)(~(TBS_TBSIF_TMPIF|TBS_TBSIF_VBATIF|TBS_TBSIF_ADC0IF|TBS_TBSIF_ADC1IF \
																	 |TBS_TBSIF_VBATCMPIF|TBS_TBSIF_VCCIF|TBS_TBSIF_ADC0CMPIF|TBS_TBSIF_ADC3IF \
																	 |TBS_TBSIF_ADC4IF|TBS_TBSIF_ADC5IF|TBS_TBSIF_ADC6IF|TBS_TBSIF_ADC7IF \
																	 |TBS_TBSIF_ADC8IF|TBS_TBSIF_ADC9IF))

#define IS_HT_TBS_ITFLAG(ITFlag)								  (((ITFlag) == TBS_TBSIF_TMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC1IF)|| \
																   ((ITFlag) == TBS_TBSIF_VBATCMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_VCCIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC0CMPIF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC3IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC4IF)|| \
																   ((ITFlag) == TBS_TBSIF_ADC5IF)|| \
																	 ((ITFlag) == TBS_TBSIF_ADC6IF)|| \
																	 ((ITFlag) == TBS_TBSIF_ADC7IF)|| \
																	 ((ITFlag) == TBS_TBSIF_ADC8IF)|| \
																	 ((ITFlag) == TBS_TBSIF_ADC9IF)|| \
																	 ((((ITFlag) & TBS_ITFLAG_MASK) == 0x00) && ((ITFlag) != 0x00)))
                                                                   
#define IS_HT_CMU_TBSSourceCFG_ClkDiv(HSTBSDiv)                  (((HSTBSDiv>>8)<= HSTBSDIV_END))
                                                                  
#define IS_HT_TBS_CMUClkSelCFG_ClkSel(HSTBSClkSel)               (((HSTBSClkSel) == HSTBSCLKSEL_PLLX2)|| \
                                                                  ((HSTBSClkSel) == HSTBSCLKSEL_HRC))
#endif

#if defined CMU_TBSCLKCFG
typedef enum
{
    HSTBSCLKSEL_PLLX2  = CMU_TBSCLKCFG_HSTBSCLKSEL_PLLX2,
    HSTBSCLKSEL_HRC = CMU_TBSCLKCFG_HSTBSCLKSEL_HRC,
}TBS_CMUClkSelectTypeDef;

#define CMU_TBSCLKCFG_HSTBSDIV_END     ((uint32_t)0x000000ff)
typedef enum
{
    HSTBSDIV_END = CMU_TBSCLKCFG_HSTBSDIV_END,
}TBS_CMUSourceClkTypeDef;
#endif

typedef enum
{
    TMPPRD  = TBS_TBSPRD_TMPPRD,         /*!< Temperature                    */
#if !defined  USE_TBS_TBSPRD_TDVREFPRD
    VBATPRD = TBS_TBSPRD_VBATPRD,        /*!< Battery Voltage                */
#else
    TDVREFPRD = TBS_TBSPRD_TDVREFPRD,    /*!< TDVREF                         */
#endif	
    ADC0PRD = TBS_TBSPRD_ADC0PRD,        /*!< ADC0                           */
    ADC1PRD = TBS_TBSPRD_ADC1PRD,        /*!< ADC1                           */
    VCCPRD  = TBS_TBSPRD_VCCPRD,         /*!< VCC                            */
#if  defined  USE_TBS_SOC
    ADC2PRD = TBS_TBSPRD_ADC2PRD,        /*!< ADC2                           */
#endif
#if  defined  USE_TBS_TBSPRD_ADC3PRD
    ADC3PRD = TBS_TBSPRD_ADC3PRD,        /*!< ADC3                           */
#endif
#if  defined  USE_TBS_TBSPRD_ADC4PRD
    ADC4PRD = TBS_TBSPRD_ADC4PRD,        /*!< ADC4                           */
#endif
#if  defined  USE_TBS_TBSPRD_ADC5PRD
    ADC5PRD = TBS_TBSPRD_ADC5PRD,        /*!< ADC5                           */
#endif
#if  defined  USE_TBS_TBSPRD_ADC6PRD
	  ADC6PRD = TBS_TBSPRD_ADC6PRD,         /*!< ADC6                         */
#endif
#if  defined  USE_TBS_TBSPRD_ADC7PRD
	  ADC7PRD = TBS_TBSPRD_ADC7PRD,         /*!< ADC7                         */
#endif
#if  defined  USE_TBS_TBSPRD_ADC8PRD
	  ADC8PRD = TBS_TBSPRD_ADC8PRD,         /*!< ADC8                         */
#endif
#if  defined  USE_TBS_TBSPRD_ADC9PRD
	  ADC9PRD = TBS_TBSPRD_ADC9PRD,         /*!< ADC9                         */
#endif
}TBS_PeriodTypeDef;                      /*!< end of group TBS_PeriodTypeDef */

#if defined  USE_TBS_VTPPRD
typedef enum
{
    VTP0PRD = TBS_VTPPRD_VTP0PRD,
    VTP1PRD = TBS_VTPPRD_VTP1PRD,
    VTP2PRD = TBS_VTPPRD_VTP2PRD,
    VTP3PRD = TBS_VTPPRD_VTP3PRD,
    VTP4PRD = TBS_VTPPRD_VTP4PRD,
    VTP5PRD = TBS_VTPPRD_VTP5PRD,
    VTP6PRD = TBS_VTPPRD_VTP6PRD,
    VTP7PRD = TBS_VTPPRD_VTP7PRD,
}TBS_VTPPeriodTypeDef;
#endif

typedef enum
{
    TBS_TMP  = 0,                        /*!< Temperature                    */
#if  !defined  USE_TBS_TDVREFDAT
	TBS_VBAT,                           /*!< VBAT                            */
#else
    TBS_TDVREF,
#endif
    TBS_ADC0 ,                           /*!< ADC0                           */
    TBS_ADC1 ,                           /*!< ADC1                           */
    TBS_VCC  ,                           /*!< VCC                            */
#if  defined  USE_TBS_ADC2DAT
    TBS_ADC2 ,                           /*!< ADC2                           */
#endif
#if  defined  USE_TBS_ADC3DAT
	TBS_ADC3,	
#endif
#if  defined  USE_TBS_ADC4DAT
	TBS_ADC4,
#endif
#if  defined  USE_TBS_ADC5DAT
	TBS_ADC5,
#endif
#if defined USE_TBS_ADC6DAT
	TBS_ADC6,
#endif
#if defined USE_TBS_ADC7DAT
	TBS_ADC7,
#endif
#if defined USE_TBS_ADC8DAT
	TBS_ADC8,
#endif
#if defined USE_TBS_ADC9DAT
	TBS_ADC9,
#endif
#if defined USE_TBS_VTP
	TBS_VTP0,
	TBS_VTP1,
	TBS_VTP2,
	TBS_VTP3,
	TBS_VTP4,
	TBS_VTP5,
	TBS_VTP6,
	TBS_VTP7,
#endif
}TBS_SubModuleTypeDef;                   /*!< end of group TBS_SubModuleTypeDef   */

typedef enum
{
#if  defined  USE_TBS_TDVREFCMP
    CMP_TDVREF,
#else
    CMP_VBAT,                         /*!< Battery voltage                     */
#endif
#if  defined  USE_TBS_ADC0CMP
    CMP_ADC0 ,                           /*!< ADC0                                */
#endif
#if  defined  USE_TBS_SOC
    CMP_ADC1 ,                           /*!< ADC1                                */
#endif
}TBS_CMPRegTypeDef;                      /*!< end of group TBS_CMPRegTypeDef      */

typedef enum                             /* Only for temperature measurement now  */
{
    TBS_ADCFilterCnt_1 = TBS_TBSCON_FILTER_1,         /*!< ADCOutput  1 time filter                  */
    TBS_ADCFilterCnt_2 = TBS_TBSCON_FILTER_2,         /*!< ADCOutput  2 times filter                 */
    TBS_ADCFilterCnt_4 = TBS_TBSCON_FILTER_4,         /*!< ADCOutput  4 times filter                 */
    TBS_ADCFilterCnt_8 = TBS_TBSCON_FILTER_8,         /*!< ADCOutput  8 times filter                 */
}TBS_ADCFilterCntTypeDef;                /*!< end of group TBS_ADCFilterCntTypeDef */

#if defined USE_TBS_TPGA
typedef enum
{
    TBS_TPGACnt_2 = TBS_TBSCON_TPGA_2,
    TBS_TPGACnt_4 = TBS_TBSCON_TPGA_4,
    TBS_TPGACnt_8 = TBS_TBSCON_TPGA_8,
    TBS_TPGACnt_16 = TBS_TBSCON_TPGA_16,
}TBS_TPGACntTypeDef;
#endif

#if  defined  USE_TBS_TBSCON_TBSCLKSEL   
typedef enum
{
#if defined USE_TBS_MCU & !defined USE_TBS_TBSCON_TBSCLKSEL_2BIT
	TBS_CLKSEL_OSC    = TBS_TBSCON_TBSCLKSEL_OSC,              		 /*!< Clock source select OSC                        */
    TBS_CLKSEL_PLLDIV = TBS_TBSCON_TBSCLKSEL_PLLDIV,         		 /*!< Clock source select PLLDIV                    */
#elif defined USE_TBS_MCU & defined USE_TBS_TBSCON_TBSCLKSEL_2BIT
    TBS_CLKSEL_OSC    = TBS_TBSCON_TBSCLKSEL_OSC,              		 /*!< Clock source select OSC                        */
	TBS_CLKSEL_LRC = TBS_TBSCON_TBSCLKSEL_LRC,							 /*!< Clock source select LRC		                    */
	TBS_CLKSEL_LSTBSCLK_10 = TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10,	 /*!< Clock source select LSTBSCLK               */
	TBS_CLKSEL_LSTBSCLK_11 = TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11,	 /*!< Clock source select LSTBSCLK               */
#endif
    
#if defined USE_TBS_SOC
	TBS_CLKSEL_OSC    = TBS_TBSCON_TBSCLKSEL_OSC,              		 /*!< Clock source select OSC                        */
	TBS_CLKSEL_LRC = TBS_TBSCON_TBSCLKSEL_LRC,							 /*!< Clock source select LRC		                    */
	TBS_CLKSEL_LSTBSCLK_10 = TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10,	 /*!< Clock source select LSTBSCLK               */
	TBS_CLKSEL_LSTBSCLK_11 = TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11,	 /*!< Clock source select LSTBSCLK               */
#endif
    
}TBS_ClkSelectTypeDef;                   /*!< end of group TBS_ClkSelectTypeDef   */
#endif

#if  defined  USE_TBS_TRIREQ
typedef enum
{
#if  defined  USE_TBS_SOC
	TBS_TRI_TMP  = TBS_TRIREQ_TMPTRI,    /*!< Fast trigger temperature measurement                     */
	TBS_TRI_VBAT = TBS_TRIREQ_VBATTRI,   /*!< Fast trigger Vbat measurement                     */
	TBS_TRI_ADC0 = TBS_TRIREQ_ADC0TRI,   /*!<  Fast trigger ADC0 measurement                     */
	TBS_TRI_ADC1 = TBS_TRIREQ_ADC1TRI,   /*!< Fast trigger ADC1 measurement                     */
	TBS_TRI_VDD  = TBS_TRIREQ_VDDTRI,    /*!< Fast trigger VDD measurement                   */
	TBS_TRI_ADC2 = TBS_TRIREQ_ADC2TRI,   /*!< Fast trigger ADC2 measurement                   */
	TBS_TRI_ADC3 = TBS_TRIREQ_ADC3TRI,   /*!< Fast trigger ADC3 measurement                     */
    TBS_TRI_ADC4 = TBS_TRIREQ_ADC4TRI,   /*!< Fast trigger ADC4 measurement                     */
    TBS_TRI_ADC5 = TBS_TRIREQ_ADC5TRI,   /*!< Fast trigger ADC5 measurement                     */
	TBS_TRI_ADC6 = TBS_TRIREQ_ADC6TRI,   /*!< Fast trigger ADC6 measurement                   */
#endif
	
#if  defined  USE_TBS_MCU
	TBS_TRI_TMP  = TBS_TRIREQ_TMPTRI,    /*!< Fast trigger temperature measurement                     */
	
#if !defined  USE_TBS_TRIREQ_TDVREFTRI
    TBS_TRI_VBAT = TBS_TRIREQ_VBATTRI,   /*!< Fast trigger Vbat measurement                     */
#elif  defined USE_TBS_TRIREQ_TDVREFTRI
	TBS_TRI_TDVREF = TBS_TRIREQ_TDVREFTRI,
#endif
	
	TBS_TRI_ADC0 = TBS_TRIREQ_ADC0TRI,   /*!<  Fast trigger ADC0 measurement                     */
	TBS_TRI_ADC1 = TBS_TRIREQ_ADC1TRI,   /*!< Fast trigger ADC1 measurement                     */
	TBS_TRI_VCC  = TBS_TRIREQ_VCCTRI,    /*!< Fast trigger VDD measurement                   */
	TBS_TRI_ADC3 = TBS_TRIREQ_ADC3TRI,   /*!< Fast trigger ADC3 measurement                     */
    TBS_TRI_ADC4 = TBS_TRIREQ_ADC4TRI,   /*!< Fast trigger ADC4 measurement                     */
    TBS_TRI_ADC5 = TBS_TRIREQ_ADC5TRI,   /*!< Fast trigger ADC5 measurement                   */
	
#if defined  USE_TBS_ADC6TRI
    TBS_TRI_ADC6 = TBS_TRIREQ_ADC6TRI,   /*!< Fast trigger ADC6 measurement                   */
#endif

#if defined  USE_TBS_ADC7TRI
    TBS_TRI_ADC7 = TBS_TRIREQ_ADC7TRI,   /*!< Fast trigger ADC7 measurement                   */
#endif
    
#if defined  USE_TBS_ADC8TRI
    TBS_TRI_ADC8 = TBS_TRIREQ_ADC8TRI,   /*!< Fast trigger ADC8 measurement                   */
#endif
    
#if defined  USE_TBS_ADC9TRI
    TBS_TRI_ADC9 = TBS_TRIREQ_ADC9TRI,   /*!< Fast trigger ADC9 measurement                   */
#endif
    
#if  defined USE_TBS_VTP
	TBS_TRI_VTP0 = TBS_TRIREQ_VTP0TRI,
	TBS_TRI_VTP1 = TBS_TRIREQ_VTP1TRI,
	TBS_TRI_VTP2 = TBS_TRIREQ_VTP2TRI,
	TBS_TRI_VTP3 = TBS_TRIREQ_VTP3TRI,
	TBS_TRI_VTP4 = TBS_TRIREQ_VTP4TRI,
	TBS_TRI_VTP5 = TBS_TRIREQ_VTP5TRI,
	TBS_TRI_VTP6 = TBS_TRIREQ_VTP6TRI,
	TBS_TRI_VTP7 = TBS_TRIREQ_VTP7TRI,
#endif
	
#endif
}TBS_TriChnTypeDef;                      /*!< end of group TBS_TriChnTypeDef      */
#endif

#if defined USE_TBS_TBSINJECTCTRL
typedef enum
{
#if defined USE_TBS_MCU
	TBS_INJECT_TMP = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TMP,
	
#if  defined  USE_TBS_INJECTCTRL_TDVREF
	TBS_INJECT_TDVREF = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TDVREF,
#else
	TBS_INJECT_VBAT = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VBAT,
#endif
	
	TBS_INJECT_ADC0 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC0,
	TBS_INJECT_ADC1 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC1,
	TBS_INJECT_VCC = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VCC,
	TBS_INJECT_ADC3 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC3,
	TBS_INJECT_ADC4 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC4,
	TBS_INJECT_ADC5 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC5,
    
#if  defined  USE_TBS_INJECTCHEL_SEL_4BIT
    TBS_INJECT_ADC6 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC6,
    TBS_INJECT_ADC7 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC7,
    TBS_INJECT_ADC8 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC8,
    TBS_INJECT_ADC9 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC9,
#endif

#endif
	
#if defined USE_TBS_SOC
	TBS_INJECT_TMP = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TMP,
	TBS_INJECT_ADC0 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC0,
	TBS_INJECT_ADC1 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC1,
	TBS_INJECT_ADC2 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC2,
	TBS_INJECT_ADC3 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC3,
	TBS_INJECT_ADC4 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC4,
	TBS_INJECT_ADC5 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC5,
	TBS_INJECT_ADC6 = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC6,
	TBS_INJECT_VBAT = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VBAT,
	TBS_INJECT_VDD = TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VDD,
#endif
}TBS_InjectChnTypeDef;
#endif

#if defined USE_TBS_TBSCON_TBSCLKSEL
typedef enum
{
    TBS_CLKSEL_SUCC       = 0,           /*!< TBS clock select succeed                   */
    TBS_CLKSEL_PARA_ERR   = -1,          /*!<  TBS clock select failed : Input parameter error     */
    TBS_CLKSEL_PLL_EN_ERR = -2,          /*!< TBS clock select or change failed : PLL not open        */
}TBS_ClkSelReturnTypeDef;                /*!< end of group TBS_ClkSelReturnTypeDef*/
#endif

#if  (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
typedef struct __TBS_InitTypeDef
{

	HT_TBS_TypeDef  *Instance;
	__IO uint32_t    ErrorCode;
	void (* TMPCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VBATCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VDDCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC0CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC1CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC2CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC3CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VBATCMPCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC0CMPCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC1CMPCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC4CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC5CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* ADC6CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
    void (* ADC7CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
    void (* ADC8CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
    void (* ADC9CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* TDVREFCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* TDVREFCMPCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VREFCpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP0CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP1CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP2CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP3CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP4CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP5CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP6CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);
	void (* VTP7CpltCallback)(struct __TBS_InitTypeDef *TBS_InitStruct);

}TBS_InitTypeDef;

typedef void(*pTBS_CallbackTypeDef)(TBS_InitTypeDef *TBS_InitStruct);

#define TBS_ERROR_NONE                 0x00000000U
#define TBS_ERROR_INVALID_CALLBACK     0x00000020U


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
void HT_TBSConfig(uint32_t TBS_SubModule, FunctionalState NewState);
void HT_TBS_PeriodSet(TBS_PeriodTypeDef PRDModule, uint32_t Period);
void HT_TBS_CMPThresholdSet(TBS_CMPRegTypeDef CmpReg, int16_t Threshold);
int16_t HT_TBS_ValueRead(TBS_SubModuleTypeDef SubModule);
void HT_TBS_ITConfig(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_TBS_ITFlagStatusGet(uint32_t ITFlag);
void HT_TBS_ClearITPendingBit(uint32_t ITFlag);
void HT_TBS_FilCntConfig(TBS_ADCFilterCntTypeDef FilterVal);
void HT_TBS_TBSReset(void);

#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
void HT_TBS_Init(TBS_InitTypeDef *TBS_InitStruct);
StatusTypeDef HT_TBS_RegisterCallback(TBS_InitTypeDef *TBS_InitStruct,TBS_CallbackIDTypeDef CallbackID,pTBS_CallbackTypeDef pCallback);
void HT_TBS_TMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VBATCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VDDCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC0CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC1CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC2CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VBATCMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC3CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC0CMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC1CMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC4CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC5CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC6CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC7CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC8CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_ADC9CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VREFCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_TDVREFCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_TDVREFCMPCpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP0CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP1CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP2CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP3CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP4CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP5CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP6CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
void HT_TBS_VTP7CpltCallback(TBS_InitTypeDef *TBS_InitStruct);
#endif

#if  defined  USE_TBS_VTPPRD
void HT_TBS_VTPPeriodSet(TBS_VTPPeriodTypeDef VTPPRDModule, uint32_t VTPPeriod);
void HT_TBS_TPGAConfig(TBS_TPGACntTypeDef TPGAVal);
#endif

#if  defined  USE_TBS_TRIREQ
TBS_ClkSelReturnTypeDef HT_TBS_ClkSelConfig(TBS_ClkSelectTypeDef ClkSel);
void HT_TBS_ADCTriSample(TBS_TriChnTypeDef TriChn);
#endif

#if defined USE_TBS_TBSINJECTCTRL
void HT_TBS_ADCInjectSample(TBS_InjectChnTypeDef InjectChn);
void HT_TBS_ADCInjectConfig(FunctionalState NewState);
#endif

#if defined USE_TBS_TBSINJECTCTRL_INJECTCLK
void HT_TBS_InjectClkConfig(uint32_t InjectClkSel,FunctionalState NewState);
#endif

#if  defined  CMU_TBSCLKCFG
void HT_TBS_CMUClkConfig(TBS_CMUSourceClkTypeDef HSTBSDiv, TBS_CMUClkSelectTypeDef HSTBSClkSel);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_TBS_H__ */
