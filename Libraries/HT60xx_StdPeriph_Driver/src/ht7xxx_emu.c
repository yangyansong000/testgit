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
* File         : ht7xxx_emu.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : Only support for chips used EMU Function.
*********************************************************************************************************
*/

#define  __HT7XXX_EMU_C

#include <string.h>
#include <math.h>
#include "ht6xxx_lib.h"



#if defined  HT762x ||  defined  HT772x                          /* This File Only support HT7xxx */

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
void HT_EMU_WPReg_Restore(uint32_t old_data);
void HT_EMU_PowerSrcCFG1_Set(uint32_t Channel,uint32_t select);
void HT_EMU_PowerSrcCFG1_Set(uint32_t Channel,uint32_t select);
void HT_EMU_CFCFG1_Set(uint32_t Channel,uint32_t select);
void HT_EMU_CFCFG2_Set(uint32_t Channel,uint32_t select);


/**
********************************************************************************************************
*                                      Restore EMU WP REGISTER
*
* @brief: Restore EMU module write protect Register 
*
* @param: old_data:metering Register write protect 
*  		  This parameter can be one of the following values:
*                                 @arg 1:0xA55A,emu,ewu,pll Register close write protect
*                                 @arg 2:0xA5BC,filter Register close write protect
*                                 @arg other: enable write protect
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_WPReg_Restore(uint32_t old_data)
{
	uint32_t ulProtect = 0U;
	
	switch(old_data)
	{
		case 1:
			ulProtect = EMU_WPREG_Unprotected;
			break;
		case 2:
			ulProtect = EMUFILTER_WPREG_Unprotected;
			break;
		default:
			ulProtect = EMU_WPREG_Protected;
			break;
	}		
	HT_EMUECA->EMUWPREG = ulProtect;
}

/**
********************************************************************************************************
*                                      Read EMU METERING REGISTER
*
* @brief: Read EMU module metering Register 
* @param: addr:metering Register offset address 
*  		  This parameter can be one of the following values:
*                                 @arg EPR_SPL_Ua(If support) 
*                                 @arg EPR_SPL_Ub(If support) 
*                                 @arg EPR_SPL_Uc(If support)
*
*                                 @arg EPR_SPL_U (If support) 
*                                 @arg EPR_SPL_I1(If support) 
*                                 @arg EPR_SPL_I2(If support) 
*                                 @arg ...		 (If support) 
*
*                                 @arg EPR_P90_Power        
*                                 @arg EPR_SignalStatus     
*                                 @arg EPR_PeakSagIntIovStau 
*
* @retval: The offset address of register data.
*
* @note  : diffrent chip use diffrent offset addr Global macro
**********************************************************************************************************/
uint32_t HT_EMU_EPReg_Read(uint32_t addr)
{
	uint32_t *ptr; 

	assert_param(IS_HT_EMU_EPReg_ADDR(addr));  /*  assert_param  */
	ptr = (uint32_t*)(HT_EMU_EPA_BASE + addr);    
    return ((*ptr) & 0xffffffffU);
}

/**
********************************************************************************************************
*                                      Read EMU Calibration Register 
* @brief : Read EMU module Calibration Register  
* @param : addr:  Calibration Register  offset address 
*  		  This parameter can be one of the following values:
*                                 @arg ECR_DecShift_UaH    (If support) 
*                                 @arg ECR_DecShift_UaL    (If support) 
*                                 @arg ECR_DecShift_UbH	   (If support) 
*
*                                 @arg ECR_DecShift_UH     (If support) 
*                                 @arg ECR_DecShift_UL     (If support) 
*                                 @arg ECR_DecShift_UH_BAK (If support) 
*                                 @arg ...			       (If support)  
*
*                                 @arg ECR_Lock_THO  
*                                 @arg ECR_AMP_THO 
*                                 @arg ECR_TED_Amnt 			
*
* @retval: The offset address of register data.
*
* @note  : diffrent chip use diffrent offset addr Global macro
**********************************************************************************************************/
uint32_t HT_EMU_ECReg_Read(uint32_t addr)
{
    uint32_t *ptr;
     
    assert_param(IS_HT_EMU_ECReg_ADDR(addr)); /*  assert_param  */
    ptr = (uint32_t*)(HT_EMU_ECA_BASE + addr);
    return ((*ptr)&0xffffffffU);
}

/**
********************************************************************************************************
*                                      Write EMU Calibration Register 
* @brief : Write EMU module Calibration Register  
* @param : addr: Calibration Register  offset address 
*  		  This parameter can be one of the following values:
*                                 @arg ECR_DecShift_UaH    (If support) 
*                                 @arg ECR_DecShift_UaL    (If support) 
*                                 @arg ECR_DecShift_UbH	   (If support) 
*
*                                 @arg ECR_DecShift_UH     (If support) 
*                                 @arg ECR_DecShift_UL     (If support) 
*                                 @arg ECR_DecShift_UH_BAK (If support) 
*                                 @arg ...			       (If support) 
*
*                                 @arg ECR_Lock_THO  
*                                 @arg ECR_AMP_THO 
*                                 @arg ECR_TED_Amnt 			
*
* @param : data: write to Calibration Register data
*
* @retval: none
*
* @note  : diffrent chip use diffrent offset addr Global macro
**********************************************************************************************************/
void HT_EMU_ECReg_Write(uint32_t addr, uint32_t data)
{	
	uint32_t *ptr;
  	uint32_t ulProtect = HT_EMUECA->EMUWPREG;             /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_ECReg_ADDR(addr));             /*  assert_param  */
	
	if((ECR_FILTER_START <= addr) &&(addr < ECR_EWUIE))
	{
		HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);  /* close write protect */
	}
	else
	{
		HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);       /* close write protect */
	}	
	ptr = (uint32_t*)(HT_EMU_ECA_BASE + addr);
	*ptr = data;	
	HT_EMU_WPReg_Restore(ulProtect);                       /* Restore write protect register*/
}

/**
*********************************************************************************************************
*                                       GET EMU NOLOAD STATUS
*
* @brief : Get EMU NOLOAD Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*                        @arg NoLoad_HarPc  (If support)  
*                        @arg NoLoad_HarPb  (If support) 
*                        @arg NoLoad_HarPa  (If support)  
*                        @arg NoLoad_FundSc (If support)  
*                        @arg NoLoad_FundSb (If support)  
*                        @arg NoLoad_FundSa (If support) 
*                        @arg NoLoad_FundQc (If support) 
*                        @arg NoLoad_FundQb (If support)  
*                        @arg NoLoad_FundQa (If support)  
*                        @arg NoLoad_FundPc (If support) 
*                        @arg NoLoad_FundPb (If support)  
*                        @arg NoLoad_FundPa (If support)  
*                        @arg NoLoad_AllSc  (If support)  
*                        @arg NoLoad_AllSb  (If support)  
*                        @arg NoLoad_AllSa  (If support)  
*                        @arg NoLoad_AllQc  (If support)  
*                        @arg NoLoad_AllQb  (If support)  
*                        @arg NoLoad_AllQa  (If support) 
*                        @arg NoLoad_AllPc  (If support)  
*                        @arg NoLoad_AllPb  (If support)  
*                        @arg NoLoad_AllPa  (If support) 
*
*                        @arg NoLoad_HarP2  (If support)
*                        @arg NoLoad_HarP1  (If support) 
*                        @arg NoLoad_FundS2 (If support) 
*                        @arg NoLoad_FundS1 (If support) 
*                        @arg NoLoad_FundQ2 (If support) 
*                        @arg NoLoad_FundQ1 (If support) 
*                        @arg NoLoad_FundP2 (If support) 
*                        @arg NoLoad_FundP1 (If support) 
*                        @arg NoLoad_AllS2  (If support) 
*                        @arg NoLoad_AllS1  (If support) 
*                        @arg NoLoad_AllQ2  (If support) 
*                        @arg NoLoad_AllQ1  (If support)
*                        @arg NoLoad_AllP2  (If support) 
*                        @arg NoLoad_AllP1  (If support) 
*
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_Noload_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
    assert_param(IS_HT_EMU_NOLOAD_STATUS(ulStatus)); /*  assert_param  */
	
    if(HT_EMUEPA->Noload & ulStatus)
    {
        flag = SET;                                  /*!< EMU noload status is set   */
    }
    else
    {
        flag = RESET;                                /*!< EMU noload status is reset */
    }
    return flag;
}

/**
*********************************************************************************************************
*                                       GET EMU RevPower STATUS
*
* @brief : Get EMU RevPower Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*                        @arg REV_Power_HarPt  
*                        @arg REV_Power_HarPc  (If support) 
*                        @arg REV_Power_HarPb  (If support) 
*                        @arg REV_Power_HarPa  (If support) 
*                        @arg REV_Power_FundQt 
*                        @arg REV_Power_FundQc (If support)
*                        @arg REV_Power_FundQb (If support)
*                        @arg REV_Power_FundQa (If support) 
*                        @arg REV_Power_FundPt  
*                        @arg REV_Power_FundPc (If support) 
*                        @arg REV_Power_FundPb (If support) 
*                        @arg REV_Power_FundPa (If support) 
*                        @arg REV_Power_AllQt  
*                        @arg REV_Power_AllQc  (If support) 
*                        @arg REV_Power_AllQb  (If support) 
*                        @arg REV_Power_AllQa  (If support) 
*                        @arg REV_Power_AllPt   
*                        @arg REV_Power_AllPc  (If support) 
*                        @arg REV_Power_AllPb  (If support)
*                        @arg REV_Power_AllPa  (If support) 
*
*                        @arg REV_Power_HarP2  (If support) 
*                        @arg REV_Power_HarP1  (If support) 
*                        @arg REV_Power_FundQ2 (If support)
*                        @arg REV_Power_FundQ1 (If support) 
*                        @arg REV_Power_FundP2 (If support) 
*                        @arg REV_Power_FundP1 (If support) 
*                        @arg REV_Power_AllQ2  (If support) 
*                        @arg REV_Power_AllQ1  (If support) 
*                        @arg REV_Power_AllP2  (If support)
*                        @arg REV_Power_AllP1  (If support) 
*
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_RevPower_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
	
    assert_param(IS_HT_EMU_REVPOWER_STATUS(ulStatus)); /*  assert_param  */
	
    if(HT_EMUEPA->REV_Power & ulStatus)
    {
        flag = SET;                                    /*!< EMU RevPower status is set   */
    }
    else
    {
        flag = RESET;                                  /*!< EMU RevPower status is reset */
    }
    return flag;

}
/**
*********************************************************************************************************
*                                       GET EMU RevEnergy STATUS 
*
* @brief : Get EMU RevEnergy Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*                        @arg REV_Energy_HarEPt  
*                        @arg REV_Energy_HarEPc  (If support)  
*                        @arg REV_Energy_HarEPb  (If support)  
*                        @arg REV_Energy_HarEPa  (If support)  
*                        @arg REV_Energy_FundEQt  
*                        @arg REV_Energy_FundEQc (If support)  
*                        @arg REV_Energy_FundEQb (If support)  
*                        @arg REV_Energy_FundEQa (If support)
*                        @arg REV_Energy_FundEPt   
*                        @arg REV_Energy_FundEPc (If support)  
*                        @arg REV_Energy_FundEPb (If support)  
*                        @arg REV_Energy_FundEPa (If support)  
*                        @arg REV_Energy_ESt     
*                        @arg REV_Energy_ESc     (If support)  
*                        @arg REV_Energy_ESb     (If support)
*                        @arg REV_Energy_ESa     (If support)  
*                        @arg REV_Energy_AllEQt    
*                        @arg REV_Energy_AllEQc  (If support)  
*                        @arg REV_Energy_AllEQb  (If support)  
*                        @arg REV_Energy_AllEQa  (If support)  
*                        @arg REV_Energy_AllEPt    
*                        @arg REV_Energy_AllEPc  (If support)
*                        @arg REV_Energy_AllEPb  (If support)  
*                        @arg REV_Energy_AllEPa  (If support)  
*
*                        @arg REV_Energy_HarEP2  (If support)  
*                        @arg REV_Energy_HarEP1  (If support)  
*                        @arg REV_Energy_FundEQ2 (If support)  
*                        @arg REV_Energy_FundEQ1 (If support)
*                        @arg REV_Energy_FundEP2 (If support)  
*                        @arg REV_Energy_FundEP1 (If support)  
*                        @arg REV_Energy_ES2     (If support)
*                        @arg REV_Energy_ES1     (If support)  
*                        @arg REV_Energy_AllEQ2  (If support)  
*                        @arg REV_Energy_AllEQ1  (If support)  
*                        @arg REV_Energy_AllEP2  (If support) 
*                        @arg REV_Energy_AllEP1  (If support)  
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_RevEnergy_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
	
    assert_param(IS_HT_EMU_REVENERGY_STATUS(ulStatus));  /*  assert_param  */
	
    if(HT_EMUEPA->REV_Energy & ulStatus)
    {
        flag = SET;                                      /*!< EMU RevEnergy status is set   */
    }
    else
    {
        flag = RESET;                                    /*!< EMU RevEnergy status is reset */
    }
    return flag;
}
/**
*********************************************************************************************************
*                                       GET EMU P90Power STATUS
*
* @brief : Get EMU P90Power Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*                        @arg P90_Power_FundEQt  
*                        @arg P90_Power_FundEQc  (If support)
*                        @arg P90_Power_FundEQb  (If support)
*                        @arg P90_Power_FundEQa  (If support)
*                        @arg P90_Power_FundEPt  
*                        @arg P90_Power_FundEPc  (If support)
*                        @arg P90_Power_FundEPb  (If support)
*                        @arg P90_Power_FundEPa  (If support)
*                        @arg P90_Power_AllEQt   
*                        @arg P90_Power_AllEQc   (If support)
*                        @arg P90_Power_AllEQb   (If support)
*                        @arg P90_Power_AllEQa   (If support)
*                        @arg P90_Power_AllEPt   
*                        @arg P90_Power_AllEPc   (If support)
*                        @arg P90_Power_AllEPb   (If support)
*                        @arg P90_Power_AllEPa   (If support)
*
*                        @arg P90_Power_FundEQ2  (If support)
*                        @arg P90_Power_FundEQ1  (If support)
*                        @arg P90_Power_FundEP2  (If support)
*                        @arg P90_Power_FundEP1  (If support)
*                        @arg P90_Power_AllEQ2   (If support)
*                        @arg P90_Power_AllEQ1   (If support)
*                        @arg P90_Power_AllEP2   (If support)
*                        @arg P90_Power_AllEP1   (If support)
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_P90Power_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
    assert_param(IS_HT_EMU_P90POWER_STATUS(ulStatus)); /*  assert_param  */
	
    if(HT_EMUEPA->P90_Power & ulStatus)
    {
        flag = SET;                                     /*!< EMU P90Power status is set   */
    }
    else
    {
        flag = RESET;                                   /*!< EMU P90Power status is reset */
    }
    return flag;
}

/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU STATUS FLAG
*
* @brief : Get EMUSR Flag Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*
*                        @arg SignalStatus_AngleBaseFlag  
*                        @arg SignalStatus_ZCValid_In    (If support)  
*                        @arg SignalStatus_ZCValid_Ic    (If support)  
*                        @arg SignalStatus_ZCValid_Ib    (If support) 
*                        @arg SignalStatus_ZCValid_Ia    (If support) 
*                        @arg SignalStatus_ZCValid_Uc    (If support)  
*                        @arg SignalStatus_ZCValid_Ub    (If support) 
*                        @arg SignalStatus_ZCValid_Ua    (If support)  
*                        @arg SignalStatus_RegionIc      (If support) 
*                        @arg SignalStatus_RegionIb      (If support)  
*                        @arg SignalStatus_RegionIa      (If support)  
*                        @arg SignalStatus_UOrder        (If support)  
*                        @arg SignalStatus_IOrder        (If support)  
*                        @arg SignalStatus_Mod3P3Status  (If support) 
*                        @arg SignalStatus_VoltageFailC  (If support)  
*                        @arg SignalStatus_VoltageFailB  (If support)  
*                        @arg SignalStatus_VoltageFailA  (If support)  
*                        @arg SignalStatus_CMPC          (If support)  
*                        @arg SignalStatus_CMPB          (If support)  
*                        @arg SignalStatus_CMPA          (If support) 
*                        @arg SignalStatus_CMPDone       (If support)
*
*                        @arg SignalStatus_ZCValid_I2    (If support)  
*                        @arg SignalStatus_ZCValid_I1    (If support)  
*                        @arg SignalStatus_ZCValid_U     (If support)       
*                        @arg SignalStatus_RegionI2      (If support)  
*                        @arg SignalStatus_RegionI1      (If support)    
*                        @arg SignalStatus_VoltageFail   (If support) 
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_Signal_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
	
    assert_param(IS_HT_EMU_SIGNAL_STATUS(ulStatus)); /*  assert_param  */
	
    if(HT_EMUEPA->SignalStatus & ulStatus)
    {
        flag = SET;                                  /*!< EMU Signal status is set   */
    }
    else
    {
        flag = RESET;                                /*!< EMU Signal status is reset */
    }
    return flag;
}
/**
*********************************************************************************************************
*                                       GET EMU PeakSagIntIov STATUS
*
* @brief : Get EMU Peak Sag Int Iov Status  
* @param : ulStatus:status bit define
*  		  This parameter can be one of the following values:
*                        @arg PeakSagIntIovStau_OVIN   (If support)
*                        @arg PeakSagIntIovStau_OVIC   (If support) 
*                        @arg PeakSagIntIovStau_OVIB   (If support) 
*                        @arg PeakSagIntIovStau_OVIA   (If support) 
*                        @arg PeakSagIntIovStau_UINTUC (If support) 
*                        @arg PeakSagIntIovStau_UINTUB (If support)
*                        @arg PeakSagIntIovStau_UINTUA (If support)
*                        @arg PeakSagIntIovStau_SagUC  (If support) 
*                        @arg PeakSagIntIovStau_SagUB  (If support) 
*                        @arg PeakSagIntIovStau_SagUA  (If support) 
*                        @arg PeakSagIntIovStau_PeakUC (If support) 
*                        @arg PeakSagIntIovStau_PeakUB (If support) 
*                        @arg PeakSagIntIovStau_PeakUA (If support)  
*
*                        @arg PeakSagIntIovStau_OVI2   (If support)
*                        @arg PeakSagIntIovStau_OVI1   (If support)
*                        @arg PeakSagIntIovStau_UINTU  (If support)
*                        @arg PeakSagIntIovStau_SagU   (If support)
*                        @arg PeakSagIntIovStau_PeakU  (If support)
*
* @retval: ITStatus   	   = SET£º      status is set 
*                          = RESET£º    status is not set 
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_PeakSagIntIov_StatusGet(uint32_t ulStatus)
{
    ITStatus flag;
	
    assert_param(IS_HT_EMU_PEAKSAG_STATUS(ulStatus)); /*  assert_param  */
	
    if(HT_EMUEPA->PeakSagIntIovStau & ulStatus)
    {
        flag = SET;                                  /*!< EMU PeakSagIntIov Status is set   */
    }
    else
    {
        flag = RESET;                                 /*!< EMU PeakSagIntIov Status is reset */
    }
    return flag;
}

/**
********************************************************************************************************
*                                      Set EMU Interrupt CONFIG
* @brief : Set EMU Interrupt Enable Config   
* @param : ITEn:interruput flag enable bit define
*  		  This parameter can be one or a combination of the following values:
*                        @arg EMUIE1_RMSItOVIE     
*                        @arg EMUIE1_RMSUtOVIE     (If support)  
*                        @arg EMUIE1_RMSTUpdateIE  
*                        @arg EMUIE1_RMSUpdateIE   
*                        @arg EMUIE1_PowerUpdateIE 
*                        @arg EMUIE1_SPLUpdateIE   
*                        @arg EMUIE1_EnergyOVIE    
*                        @arg EMUIE1_ZCUcLostIE    (If support) 
*                        @arg EMUIE1_ZCUbLostIE    (If support) 
*                        @arg EMUIE1_ZCUaLostIE    (If support)
*                        @arg EMUIE1_CMPcIE        (If support) 
*                        @arg EMUIE1_CMPbIE        (If support) 
*                        @arg EMUIE1_CMPaIE        (If support) 
*                        @arg EMUIE1_ZCInIE        (If support)
*                        @arg EMUIE1_ZCIcIE        (If support) 		
*                        @arg EMUIE1_ZCIbIE        (If support) 
*                        @arg EMUIE1_ZCIaIE        (If support) 
*                        @arg EMUIE1_ZCUcIE        (If support) 
*                        @arg EMUIE1_ZCUbIE        (If support) 
*                        @arg EMUIE1_ZCUaIE        (If support)
*                        @arg EMUIE1_HarP_NegCFIE  
*                        @arg EMUIE1_FundQ_NegCFIE 
*                        @arg EMUIE1_FundP_NegCFIE 
*                        @arg EMUIE1_S_NegCFIE     
*                        @arg EMUIE1_AllQ_NegCFIE  
*                        @arg EMUIE1_AllP_NegCFIE  
*                        @arg EMUIE1_HarP_PosCFIE  
*                        @arg EMUIE1_FundQ_PosCFIE 
*                        @arg EMUIE1_FundP_PosCFIE 
*                        @arg EMUIE1_S_PosCFIE     		
*                        @arg EMUIE1_AllQ_PosCFIE  
*                        @arg EMUIE1_AllP_PosCFIE  
*
*                        @arg EMUIE1_ZCULostIE     (If support)
*                        @arg EMUIE1_ZCI2IE        (If support) 
*                        @arg EMUIE1_ZCI1IE        (If support) 
*                        @arg EMUIE1_ZCUIE         (If support)
*
* @param: NewState        = ENABLE£º  Interrupt enable  
*                         = DISABLE£º Interrupt disable
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMUIE1_Config(uint32_t ITEn, FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
	
	assert_param(IS_HT_EMUIE1_CONFIG(ITEn));      /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));  /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    if(NewState != DISABLE)
    {
        HT_EMUECA->EMUIE1 |= ITEn;                /*!< enable EMU interrupt          */
    }
    else
    {
        HT_EMUECA->EMUIE1 &= ~ITEn;               /*!< Disable EMU interrupt       */
    }
	
	HT_EMU_WPReg_Restore(ulProtect);              /* Restore write protect register*/
}
/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU INTERRUPT FLAG STATUS
*
* @brief : get EMU module Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EMUIF1_RMSItOVIF      
*                        @arg EMUIF1_RMSUtOVIF      (If support)
*                        @arg EMUIF1_RMSTUpdateIF   
*                        @arg EMUIF1_RMSUpdateIF    
*                        @arg EMUIF1_PowerUpdateIF  
*                        @arg EMUIF1_SPLUpdateIF    
*                        @arg EMUIF1_EnergyOVIF     
*                        @arg EMUIF1_ZCUcLostIF     (If support)
*                        @arg EMUIF1_ZCUbLostIF     (If support)
*                        @arg EMUIF1_ZCUaLostIF     (If support)
*                        @arg EMUIF1_CMPcIF         (If support)
*                        @arg EMUIF1_CMPbIF         (If support)
*                        @arg EMUIF1_CMPaIF         (If support)
*                        @arg EMUIF1_ZCInIF         (If support)
*                        @arg EMUIF1_ZCIcIF         (If support)
*                        @arg EMUIF1_ZCIbIF         (If support)
*                        @arg EMUIF1_ZCIaIF         (If support)
*                        @arg EMUIF1_ZCUcIF         (If support)
*                        @arg EMUIF1_ZCUbIF         (If support)
*                        @arg EMUIF1_ZCUaIF         (If support)
*                        @arg EMUIF1_HarP_NegCFIF   
*                        @arg EMUIF1_FundQ_NegCFIF  
*                        @arg EMUIF1_FundP_NegCFIF  
*                        @arg EMUIF1_S_NegCFIF      
*                        @arg EMUIF1_AllQ_NegCFIF   
*                        @arg EMUIF1_AllP_NegCFIF   
*                        @arg EMUIF1_HarP_PosCFIF   
*                        @arg EMUIF1_FundQ_PosCFIF  
*                        @arg EMUIF1_FundP_PosCFIF  
*                        @arg EMUIF1_S_PosCFIF      
*                        @arg EMUIF1_AllQ_PosCFIF   
*                        @arg EMUIF1_AllP_PosCFIF   
*
*                        @arg EMUIF1_ZCULostIF      (If support)
*                        @arg EMUIF1_ZCI2IF         (If support)
*                        @arg EMUIF1_ZCI1IF         (If support)
*                        @arg EMUIF1_ZCUIF          (If support)
*
*
* @retval: ITStatus    = SET£º      flag is set
                       = RESET£º    flag is not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMUIF1_FlagStatusGet(uint32_t ITFlag)
{
	ITStatus flag;
	
	assert_param(IS_HT_EMUIF1_CONFIG(ITFlag));    /*  assert_param  */
    if(HT_EMUECA->EMUIF1 & ITFlag)
    {
        flag = SET;                               /*!< EMU Interrupt Flag is set   */
    }
    else
    {
        flag = RESET;                             /*!< EMU Interrupt Flag is reset */
    }
	return flag;
}

/**
*********************************************************************************************************
*                                       CLEAR EMU INTERRUPT FLAG
*
* @brief : clear EMU module Interrupt flag
*
* @param : ITFlag This parameter can be one or a combination of the following values:
*                        @arg EMUIF1_RMSItOVIF      
*                        @arg EMUIF1_RMSUtOVIF      (If support)
*                        @arg EMUIF1_RMSTUpdateIF   
*                        @arg EMUIF1_RMSUpdateIF    
*                        @arg EMUIF1_PowerUpdateIF  
*                        @arg EMUIF1_SPLUpdateIF    
*                        @arg EMUIF1_EnergyOVIF     
*                        @arg EMUIF1_ZCUcLostIF     (If support)
*                        @arg EMUIF1_ZCUbLostIF     (If support)
*                        @arg EMUIF1_ZCUaLostIF     (If support)
*                        @arg EMUIF1_CMPcIF         (If support)
*                        @arg EMUIF1_CMPbIF         (If support)
*                        @arg EMUIF1_CMPaIF         (If support)
*                        @arg EMUIF1_ZCInIF         (If support)
*                        @arg EMUIF1_ZCIcIF         (If support)
*                        @arg EMUIF1_ZCIbIF         (If support)
*                        @arg EMUIF1_ZCIaIF         (If support)
*                        @arg EMUIF1_ZCUcIF         (If support)
*                        @arg EMUIF1_ZCUbIF         (If support)
*                        @arg EMUIF1_ZCUaIF         (If support)
*                        @arg EMUIF1_HarP_NegCFIF   
*                        @arg EMUIF1_FundQ_NegCFIF  
*                        @arg EMUIF1_FundP_NegCFIF  
*                        @arg EMUIF1_S_NegCFIF      
*                        @arg EMUIF1_AllQ_NegCFIF   
*                        @arg EMUIF1_AllP_NegCFIF   
*                        @arg EMUIF1_HarP_PosCFIF   
*                        @arg EMUIF1_FundQ_PosCFIF  
*                        @arg EMUIF1_FundP_PosCFIF  
*                        @arg EMUIF1_S_PosCFIF      
*                        @arg EMUIF1_AllQ_PosCFIF   
*                        @arg EMUIF1_AllP_PosCFIF   
*
*                        @arg EMUIF1_ZCULostIF      (If support)
*                        @arg EMUIF1_ZCI2IF         (If support)
*                        @arg EMUIF1_ZCI1IF         (If support)
*                        @arg EMUIF1_ZCUIF          (If support)
*
*
* @retval: none
*
* @note  : 32 bit
*********************************************************************************************************
*/
void HT_EMUIF1_PendingBitClear(uint32_t ITFlag)
{	
#ifdef  USE_FULL_ASSERT
	uint32_t ultemp = (uint32_t)(~EMUIF1_ALL);
	uint8_t Flag = 0U;
   
	if((0U == (ITFlag & ultemp)) && (ITFlag != 0U)) /* combination judge */
    {
        Flag = 1U;
    }

	assert_param((IS_HT_EMUIF1_CONFIG(ITFlag)||(Flag == 1U)));    /*  assert_param  */
#endif
    HT_EMUECA->EMUIF1   = (uint32_t)ITFlag;                        /*!< write 1£¬Clear EMU Interrupt Flag>! */
}

/**
********************************************************************************************************
*                                      Set EMU Interrupt CONFIG
* @brief : Set EMU Interrupt Enable Config   
* @param : ITEn:interruput flag enable bit define
*  		  This parameter can be one or a combination of the following values:
*                        @arg EMUIE2_VpupdInIE  (If support)
*                        @arg EMUIE2_VpupdIcIE  (If support)
*                        @arg EMUIE2_VpupdIbIE  (If support)
*                        @arg EMUIE2_VpupdIaIE  (If support)
*                        @arg EMUIE2_VpupdUcIE  (If support)
*                        @arg EMUIE2_VpupdUbIE  (If support)
*                        @arg EMUIE2_VpupdUaIE  (If support)
*                        @arg EMUIE2_InOVEndIE  (If support)
*                        @arg EMUIE2_IcOVEndIE  (If support)
*                        @arg EMUIE2_IbOVEndIE  (If support)
*                        @arg EMUIE2_IaOVEndIE  (If support)
*                        @arg EMUIE2_InOVIE     (If support)
*                        @arg EMUIE2_IcOVIE     (If support)
*                        @arg EMUIE2_IbOVIE     (If support)
*                        @arg EMUIE2_IaOVIE     (If support)
*                        @arg EMUIE2_UcINTEndIE (If support)
*                        @arg EMUIE2_UbINTEndIE (If support)
*                        @arg EMUIE2_UaINTEndIE (If support)
*                        @arg EMUIE2_INTUIE     
*                        @arg EMUIE2_INTUcIE    (If support)
*                        @arg EMUIE2_INTUbIE    (If support)
*                        @arg EMUIE2_INTUaIE    (If support)
*                        @arg EMUIE2_UcEndIE    (If support)
*                        @arg EMUIE2_UbEndIE    (If support)
*                        @arg EMUIE2_UaEndIE    (If support)
*                        @arg EMUIE2_SagUcIE    (If support)
*                        @arg EMUIE2_SagUbIE    (If support)
*                        @arg EMUIE2_SagUaIE    (If support)
*                        @arg EMUIE2_PeakUcIE   (If support)
*                        @arg EMUIE2_PeakUbIE   (If support)		
*                        @arg EMUIE2_PeakUaIE   (If support)
*
*                        @arg EMUIE2_VpupdI2IE  (If support)
*                        @arg EMUIE2_VpupdI1IE  (If support)
*                        @arg EMUIE2_VpupdUIE   (If support)
*                        @arg EMUIE2_I2OVEndIE  (If support)
*                        @arg EMUIE2_I1OVEndIE  (If support)
*                        @arg EMUIE2_I2OVIE     (If support)
*                        @arg EMUIE2_I1OVIE     (If support)
*                        @arg EMUIE2_UINTEndIE  (If support)
*                        @arg EMUIE2_UEndIE     (If support)
*                        @arg EMUIE2_SagUIE     (If support)
*                        @arg EMUIE2_PeakUIE    (If support)
*
* @param: NewState        = ENABLE£º  Interrupt enable  
*                         = DISABLE£º Interrupt disable
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMUIE2_Config(uint32_t ITEn, FunctionalState NewState)
{   
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;      /* Get Write Protect */ 

	assert_param(IS_HT_EMUIE2_CONFIG(ITEn));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);    /* Close write protect*/

    if(NewState != DISABLE)
    {
        HT_EMUECA->EMUIE2 |= ITEn;                  /*!< enable EMU interrupt  */
    }
    else
    {
        HT_EMUECA->EMUIE2 &= ~ITEn;                 /*!< Disable EMU interrupt  */
    }

	HT_EMU_WPReg_Restore(ulProtect);                /* Restore write protect register*/
}
/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU INTERRUPT FLAG STATUS
*
* @brief : get EMU module Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EMUIF2_VpupdInIF  (If support)
*                        @arg EMUIF2_VpupdIcIF  (If support)
*                        @arg EMUIF2_VpupdIbIF  (If support)
*                        @arg EMUIF2_VpupdIaIF  (If support)
*                        @arg EMUIF2_VpupdUcIF  (If support)
*                        @arg EMUIF2_VpupdUbIF  (If support)
*                        @arg EMUIF2_VpupdUaIF  (If support)
*                        @arg EMUIF2_InOVEndIF  (If support)
*                        @arg EMUIF2_IcOVEndIF  (If support)
*                        @arg EMUIF2_IbOVEndIF  (If support)
*                        @arg EMUIF2_IaOVEndIF  (If support)
*                        @arg EMUIF2_InOVIF     (If support)
*                        @arg EMUIF2_IcOVIF     (If support)
*                        @arg EMUIF2_IbOVIF     (If support)
*                        @arg EMUIF2_IaOVIF     (If support)
*                        @arg EMUIF2_UcINTEndIF (If support)
*                        @arg EMUIF2_UbINTEndIF (If support)
*                        @arg EMUIF2_UaINTEndIF (If support)
*                        @arg EMUIF2_INTUIF     
*                        @arg EMUIF2_INTUcIF    (If support)
*                        @arg EMUIF2_INTUbIF    (If support)
*                        @arg EMUIF2_INTUaIF    (If support)
*                        @arg EMUIF2_UcEndIF    (If support)
*                        @arg EMUIF2_UbEndIF    (If support)
*                        @arg EMUIF2_UaEndIF    (If support)
*                        @arg EMUIF2_SagUcIF    (If support)
*                        @arg EMUIF2_SagUbIF    (If support)
*                        @arg EMUIF2_SagUaIF    (If support)
*                        @arg EMUIF2_PeakUcIF   (If support)
*                        @arg EMUIF2_PeakUbIF   (If support)
*                        @arg EMUIF2_PeakUaIF   (If support)
*
*                        @arg EMUIF2_VpupdI2IF  (If support)
*                        @arg EMUIF2_VpupdI1IF  (If support)
*                        @arg EMUIF2_VpupdUIF   (If support)
*                        @arg EMUIF2_I2OVEndIF  (If support)
*                        @arg EMUIF2_I1OVEndIF  (If support)
*                        @arg EMUIF2_I2OVIF     (If support)
*                        @arg EMUIF2_I1OVIF     (If support)
*                        @arg EMUIF2_UINTEndIF  (If support)
*                        @arg EMUIF2_UEndIF     (If support)
*                        @arg EMUIF2_SagUIF     (If support)
*                        @arg EMUIF2_PeakUIF    (If support)
*
*
* @retval: ITStatus    = SET£º      flag is set
                       = RESET£º    flag is not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMUIF2_FlagStatusGet(uint32_t ITFlag)
{
	ITStatus flag;
	
	assert_param(IS_HT_EMUIF2_CONFIG(ITFlag));/*  assert_param  */
	
    if(HT_EMUECA->EMUIF2 & ITFlag)
    {
        flag = SET;                        /*!< EMU Interrupt Flag is set   */
    }
    else
    {
        flag = RESET;                      /*!< EMU Interrupt Flag is reset */
    }
	return flag;
}

/**
*********************************************************************************************************
*                                       CLEAR EMU INTERRUPT FLAG
*
* @brief : clear EMU module Interrupt flag
*
* @param : ITFlag This parameter can be one or a combination of the following values:
*                        @arg EMUIF2_VpupdInIF  (If support)
*                        @arg EMUIF2_VpupdIcIF  (If support)
*                        @arg EMUIF2_VpupdIbIF  (If support)
*                        @arg EMUIF2_VpupdIaIF  (If support)
*                        @arg EMUIF2_VpupdUcIF  (If support)
*                        @arg EMUIF2_VpupdUbIF  (If support)
*                        @arg EMUIF2_VpupdUaIF  (If support)
*                        @arg EMUIF2_InOVEndIF  (If support)
*                        @arg EMUIF2_IcOVEndIF  (If support)
*                        @arg EMUIF2_IbOVEndIF  (If support)
*                        @arg EMUIF2_IaOVEndIF  (If support)
*                        @arg EMUIF2_InOVIF     (If support)
*                        @arg EMUIF2_IcOVIF     (If support)
*                        @arg EMUIF2_IbOVIF     (If support)
*                        @arg EMUIF2_IaOVIF     (If support)
*                        @arg EMUIF2_UcINTEndIF (If support)
*                        @arg EMUIF2_UbINTEndIF (If support)
*                        @arg EMUIF2_UaINTEndIF (If support)
*                        @arg EMUIF2_INTUIF     
*                        @arg EMUIF2_INTUcIF    (If support)
*                        @arg EMUIF2_INTUbIF    (If support)
*                        @arg EMUIF2_INTUaIF    (If support)
*                        @arg EMUIF2_UcEndIF    (If support)
*                        @arg EMUIF2_UbEndIF    (If support)
*                        @arg EMUIF2_UaEndIF    (If support)
*                        @arg EMUIF2_SagUcIF    (If support)
*                        @arg EMUIF2_SagUbIF    (If support)
*                        @arg EMUIF2_SagUaIF    (If support)
*                        @arg EMUIF2_PeakUcIF   (If support)
*                        @arg EMUIF2_PeakUbIF   (If support)
*                        @arg EMUIF2_PeakUaIF   (If support)
*
*                        @arg EMUIF2_VpupdI2IF  (If support)
*                        @arg EMUIF2_VpupdI1IF  (If support)
*                        @arg EMUIF2_VpupdUIF   (If support)
*                        @arg EMUIF2_I2OVEndIF  (If support)
*                        @arg EMUIF2_I1OVEndIF  (If support)
*                        @arg EMUIF2_I2OVIF     (If support)
*                        @arg EMUIF2_I1OVIF     (If support)
*                        @arg EMUIF2_UINTEndIF  (If support)
*                        @arg EMUIF2_UEndIF     (If support)
*                        @arg EMUIF2_SagUIF     (If support)
*                        @arg EMUIF2_PeakUIF    (If support)
*
* @retval: none
*
* @note  : none
*********************************************************************************************************
*/
void HT_EMUIF2_PendingBitClear(uint32_t ITFlag)
{
#ifdef  USE_FULL_ASSERT
	uint32_t ultemp = (uint32_t)(~EMUIF2_ALL);
	uint8_t Flag = 0U;

	if((0U == (ITFlag & ultemp)) && (ITFlag != 0U)) /* combination judge */
    {
        Flag = 1U;
    }

	assert_param((IS_HT_EMUIF2_CONFIG(ITFlag)||(Flag == 1U)));        /*  assert_param  */
#endif
    HT_EMUECA->EMUIF2   = ((uint32_t)ITFlag);                          /*!< write 1£¬Clear EMU Interrupt Flag       */
}

/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU INTERRUPT FLAG STATUS
*
* @brief : get EMU module Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EMUIF_EnergyPOVIF_HarEPt 
*                        @arg EMUIF_EnergyPOVIF_HarEPc (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEPb (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEPa (If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQt
*                        @arg EMUIF_EnergyPOVIF_FundEQc(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQb(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQa(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPt
*                        @arg EMUIF_EnergyPOVIF_FundEPc(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPb(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPa(If support)
*                        @arg EMUIF_EnergyPOVIF_ESt    
*                        @arg EMUIF_EnergyPOVIF_ESc    (If support)
*                        @arg EMUIF_EnergyPOVIF_ESb    (If support)
*                        @arg EMUIF_EnergyPOVIF_ESa    (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQt 
*                        @arg EMUIF_EnergyPOVIF_AllEQc (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQb (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQa (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPt 
*                        @arg EMUIF_EnergyPOVIF_AllEPc (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPb (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPa (If support)
*
*                        @arg EMUIF_EnergyPOVIF_HarEP2 (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEP1 (If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQ2(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQ1(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEP2(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEP1(If support)
*                        @arg EMUIF_EnergyPOVIF_ES2    (If support)
*                        @arg EMUIF_EnergyPOVIF_ES1    (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQ2 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQ1 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEP2 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEP1 (If support)
*
*
* @retval: ITStatus    = SET£º      flag set
                       = RESET£º    flag not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_EnergyPOVIF_FlagStatusGet(uint32_t ITFlag)
{
	ITStatus Staus;
	
	assert_param(IS_HT_EMU_ENERGYPOVIF_CONFIG(ITFlag));     /*  assert_param  */
	
    if(HT_EMUECA->EMUIF_EnergyPOVIF & ITFlag)
    {
        Staus = SET;                        				/*!< EMU Interrupt Flag is set   */
    }
    else
    {
        Staus = RESET;                      				/*!< EMU Interrupt Flag is reset */
    }
	return Staus;
}

/**
*********************************************************************************************************
*                                       CLEAR EMU INTERRUPT FLAG
*
* @brief : clear EMU module Interrupt flag
*
* @param : ITFlag This parameter can be one or a combination of the following values:
*                        @arg EMUIF_EnergyPOVIF_HarEPt 
*                        @arg EMUIF_EnergyPOVIF_HarEPc (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEPb (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEPa (If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQt
*                        @arg EMUIF_EnergyPOVIF_FundEQc(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQb(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQa(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPt
*                        @arg EMUIF_EnergyPOVIF_FundEPc(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPb(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEPa(If support)
*                        @arg EMUIF_EnergyPOVIF_ESt    
*                        @arg EMUIF_EnergyPOVIF_ESc    (If support)
*                        @arg EMUIF_EnergyPOVIF_ESb    (If support)
*                        @arg EMUIF_EnergyPOVIF_ESa    (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQt 
*                        @arg EMUIF_EnergyPOVIF_AllEQc (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQb (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQa (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPt 
*                        @arg EMUIF_EnergyPOVIF_AllEPc (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPb (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEPa (If support)
*
*                        @arg EMUIF_EnergyPOVIF_HarEP2 (If support)
*                        @arg EMUIF_EnergyPOVIF_HarEP1 (If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQ2(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEQ1(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEP2(If support)
*                        @arg EMUIF_EnergyPOVIF_FundEP1(If support)
*                        @arg EMUIF_EnergyPOVIF_ES2    (If support)
*                        @arg EMUIF_EnergyPOVIF_ES1    (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQ2 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEQ1 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEP2 (If support)
*                        @arg EMUIF_EnergyPOVIF_AllEP1 (If support)
* @retval: none
*
* @note  : none
*********************************************************************************************************
*/
void HT_EMU_EnergyPOVIF_PendingBitClear(uint32_t ITFlag)
{
#ifdef  USE_FULL_ASSERT
	uint8_t Flag = 0U;
	uint32_t ultemp = (uint32_t)(~EMUIF_EnergyPOVIF_ALL);
    
	if((0U == (ITFlag & ultemp)) && (ITFlag != 0U)) /* combination judge */
    {
		Flag = 1U;
    }
	
	assert_param((IS_HT_EMU_ENERGYPOVIF_CONFIG(ITFlag)||(Flag == 1U)));    /*  assert_param  */
#endif
    HT_EMUECA->EMUIF_EnergyPOVIF   = ((uint32_t)ITFlag);                    /*!< write 1£¬Clear EMU Interrupt Flag  */
}
/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU INTERRUPT FLAG STATUS
*
* @brief : get EMU module Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EMUIF_EnergyNOVIF_HarEPt 
*                        @arg EMUIF_EnergyNOVIF_HarEPc (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEPb (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEPa (If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQt
*                        @arg EMUIF_EnergyNOVIF_FundEQc(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQb(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQa(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPt
*                        @arg EMUIF_EnergyNOVIF_FundEPc(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPb(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPa(If support)
*                        @arg EMUIF_EnergyNOVIF_ESt    
*                        @arg EMUIF_EnergyNOVIF_ESc    (If support)
*                        @arg EMUIF_EnergyNOVIF_ESb    (If support)
*                        @arg EMUIF_EnergyNOVIF_ESa    (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQt 
*                        @arg EMUIF_EnergyNOVIF_AllEQc (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQb (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQa (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPt 
*                        @arg EMUIF_EnergyNOVIF_AllEPc (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPb (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPa (If support)
*
*                        @arg EMUIF_EnergyNOVIF_HarEP2 (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEP1 (If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQ2(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQ1(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEP2(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEP1(If support)
*                        @arg EMUIF_EnergyNOVIF_ES2    (If support)
*                        @arg EMUIF_EnergyNOVIF_ES1    (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQ2 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQ1 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEP2 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEP1 (If support)
*
*
* @retval: ITStatus    = SET£º      flag set
                       = RESET£º    flag not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_EnergyNOVIF_FlagStatusGet(uint32_t ITFlag)
{
	ITStatus flag;
	
	assert_param(IS_HT_EMU_ENERGYNOVIF_CONFIG(ITFlag));    /*  assert_param  */
	
    if(HT_EMUECA->EMUIF_EnergyNOVIF & ITFlag)
    {
        flag = SET;                        /*!< EMU Interrupt Flag is set   */
    }
    else
    {
        flag = RESET;                      /*!< EMU Interrupt Flag is reset */
    }
	return flag;
}

/**
*********************************************************************************************************
*                                       CLEAR EMU INTERRUPT FLAG
*
* @brief : clear EMU module Interrupt flag
*
* @param : ITFlag This parameter can be one or a combination of the following values:
*                        @arg EMUIF_EnergyNOVIF_HarEPt 
*                        @arg EMUIF_EnergyNOVIF_HarEPc (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEPb (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEPa (If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQt
*                        @arg EMUIF_EnergyNOVIF_FundEQc(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQb(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQa(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPt
*                        @arg EMUIF_EnergyNOVIF_FundEPc(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPb(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEPa(If support)
*                        @arg EMUIF_EnergyNOVIF_ESt    
*                        @arg EMUIF_EnergyNOVIF_ESc    (If support)
*                        @arg EMUIF_EnergyNOVIF_ESb    (If support)
*                        @arg EMUIF_EnergyNOVIF_ESa    (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQt 
*                        @arg EMUIF_EnergyNOVIF_AllEQc (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQb (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQa (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPt 
*                        @arg EMUIF_EnergyNOVIF_AllEPc (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPb (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEPa (If support)
*
*                        @arg EMUIF_EnergyNOVIF_HarEP2 (If support)
*                        @arg EMUIF_EnergyNOVIF_HarEP1 (If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQ2(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEQ1(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEP2(If support)
*                        @arg EMUIF_EnergyNOVIF_FundEP1(If support)
*                        @arg EMUIF_EnergyNOVIF_ES2    (If support)
*                        @arg EMUIF_EnergyNOVIF_ES1    (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQ2 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEQ1 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEP2 (If support)
*                        @arg EMUIF_EnergyNOVIF_AllEP1 (If support)
*
* @retval: none
*
* @note  : none
*********************************************************************************************************
*/
void HT_EMU_EnergyNOVIF_PendingBitClear(uint32_t ITFlag)
{
#ifdef  USE_FULL_ASSERT
	uint8_t Flag = 0U;
	uint32_t ultemp = (uint32_t)(~EMUIF_EnergyNOVIF_ALL);
    
	if((0U == (ITFlag & ultemp)) && (ITFlag != 0U)) /* combination judge */
    {
		Flag = 1U;
    }
	
	assert_param((IS_HT_EMU_ENERGYNOVIF_CONFIG(ITFlag)||(Flag == 1U)));   /*  assert_param  */
#endif	
    HT_EMUECA->EMUIF_EnergyNOVIF   = ((uint32_t)ITFlag);                  /*!< write 1£¬Clear EMU Interrupt Flag       */
}
/**
********************************************************************************************************
*                                      Set EWU Interrupt CONFIG
* @brief : Set EWU Interrupt Enable Config   
* @param : ITEn:interruput flag enable
*  		  This parameter can be one or a combination of the following values:
*                        @arg EWUIE_FlickerUpdIE		
*                        @arg EWUIE_SyncDftUpdIE 	
*                        @arg EWUIE_HpRmsIE     	 
*
* @param: NewState        = ENABLE£º  Interrupt enable  
*                         = DISABLE£º Interrupt disable
*
* @retval: none 
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EWUIE_Config(uint32_t ITEn, FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 

	assert_param(IS_HT_EWUIE_CONFIG(ITEn));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));   /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/

    if(NewState != DISABLE)
    {
        HT_EWUECA->EWUIE |= ITEn;                  /*!< enable EMU interrupt  */
    }
    else
    {
        HT_EWUECA->EWUIE &= ~ITEn;                 /*!< Disable EMU interrupt  */
    }
	HT_EMU_WPReg_Restore(ulProtect);        		/* Restore write protect register*/
}
/**
*********************************************************************************************************
*                                       GET SPECIFIED EWU INTERRUPT FLAG STATUS
*
* @brief : get EMU module EWU Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EWUIF_FlickerUpdIF
*                        @arg EWUIF_SyncDftUpdIF 
*                        @arg EWUIF_HpRmsIF     	 
*
* @retval: ITStatus    = SET£º      flag set
                       = RESET£º    flag not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_EWUIF_FlagStatusGet(uint32_t ITFlag)
{
	ITStatus flag;

	assert_param(IS_HT_EWUIF_CONFIG(ITFlag));/*  assert_param  */
	
    if(HT_EWUECA->EWUIF & ITFlag)
    {
        flag = SET;                        /*!< EWU Interrupt Flag is set   */
    }
    else
    {
        flag = RESET;                      /*!< EWU Interrupt Flag is reset */
    }
	return flag;
}

/**
*********************************************************************************************************
*                                       CLEAR EWU INTERRUPT FLAG
*
* @brief : clear EMU module EWU Interrupt flag
*
* @param : ITFlag This parameter can be one of the following values:
*                        @arg EWUIF_FlickerUpdIF
*                        @arg EWUIF_SyncDftUpdIF 
*                        @arg EWUIF_HpRmsIF     	 
*
* @retval: none
*
* @note  : none
*********************************************************************************************************
*/
void HT_EMU_EWUIF_PendingBitClear(uint32_t ITFlag)
{
#ifdef  USE_FULL_ASSERT
	uint8_t Flag = 0U;
	uint32_t ultemp = (uint32_t)(~EWUIF_ALL);
    
    if((0U == (ITFlag & ultemp)) && (ITFlag != 0U))
    {
		Flag = 1U;
    }
	
	assert_param((IS_HT_EWUIF_CONFIG(ITFlag)||(Flag == 1U)));	/*  assert_param  */
#endif
    HT_EWUECA->EWUIF   = ((uint32_t)ITFlag);                    /*!< write 1£¬Clear EWU Interrupt Flag */
}
/**
********************************************************************************************************
*                                      Set EMU DEC Shift_High Phase Correction
* @brief : Set EMU Module DEC Shift High Phase correction 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_DecShift_UaH	(If support)
*               @arg ECR_DecShift_UbH	(If support)
*               @arg ECR_DecShift_UcH	(If support)
*               @arg ECR_DecShift_IaH	(If support)	
*               @arg ECR_DecShift_IbH	(If support)
*               @arg ECR_DecShift_IcH	(If support)
*               @arg ECR_DecShift_InH	(If support)
*	
*               @arg ECR_DecShift_UH	(If support)
*               @arg ECR_DecShift_I1H	(If support)
*               @arg ECR_DecShift_I2H	(If support)
*
* @param : Area
*  		  This parameter can be one of the following values:
*               @arg DECShift_High_Area2	
*               @arg DECShift_High_Area1
*               @arg DECShift_High_Area0
*
* @param: data: 
*               limits: 4BIT,(uint)data<= 0x9
*							
*								
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_DEC_ShiftHSet(uint32_t Channel, uint32_t Area, uint32_t data)
{
	uint32_t ultemp = 0U,uldata = 0U;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get WP status */
	
	assert_param(IS_HT_EMU_DEC_ShiftH_CHANNEL_SEL(Channel));    /*  assert_Channel */
    assert_param(IS_HT_EMU_DEC_ShiftH_AREA_SEL(Area));          /*  assert_Area 0~2 */
    assert_param(IS_HT_EMU_DEC_ShiftH_LIMIT(data));             /*  assert_data Limit  */	
    switch(Area)                                                /* Judge Area 0 1 2 */
    {
        case DECShift_High_Area2:
			uldata = data << 8U;
            break;
        case DECShift_High_Area1:
			uldata = data << 4U;
            break;
        case DECShift_High_Area0:
			uldata = data;
            break;
        default:
            break;
    }
	
    HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);           /* Close WP */
	switch(Channel)                         			  /* Write data */
	{
	#if defined  HT762x
		case ECR_DecShift_UaH:
            ultemp = HT_EMUECA->DECShift_UaH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UaH = ultemp;
            break;
        case ECR_DecShift_UbH:
            ultemp = HT_EMUECA->DECShift_UbH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UbH = ultemp;
            break;
        case ECR_DecShift_UcH:
            ultemp = HT_EMUECA->DECShift_UcH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UcH = ultemp;
            break;
        case ECR_DecShift_IaH:
            ultemp = HT_EMUECA->DECShift_IaH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IaH = ultemp;
            break;
        case ECR_DecShift_IbH:
            ultemp = HT_EMUECA->DECShift_IbH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IbH = ultemp;
            break;
        case ECR_DecShift_IcH:
            ultemp = HT_EMUECA->DECShift_IcH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IcH = ultemp;
            break;
        case ECR_DecShift_InH:
            ultemp = HT_EMUECA->DECShift_InH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_InH = ultemp;
            break;
	#else
		case ECR_DecShift_UH:
            ultemp = HT_EMUECA->DECShift_UH;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UH = ultemp;
			HT_EMUECA->DECShift_UH_BAK = ultemp;
            break;
        case ECR_DecShift_I1H:
            ultemp = HT_EMUECA->DECShift_I1H;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_I1H = ultemp;
            break;
        case ECR_DecShift_I2H:
            ultemp = HT_EMUECA->DECShift_I2H;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_I2H = ultemp;
            break;
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);   /* Restore write protect register */
}

/**
********************************************************************************************************
*                                      Get EMU DEC Shift_High Reg data
* @brief : Get EMU Module DEC Shift High Area data
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_DecShift_UaH	(If support)
*               @arg ECR_DecShift_UbH	(If support)
*               @arg ECR_DecShift_UcH	(If support)
*               @arg ECR_DecShift_IaH	(If support)	
*               @arg ECR_DecShift_IbH	(If support)
*               @arg ECR_DecShift_IcH	(If support)
*               @arg ECR_DecShift_InH	(If support)
*	
*               @arg ECR_DecShift_UH	(If support)
*               @arg ECR_DecShift_I1H	(If support)
*               @arg ECR_DecShift_I2H	(If support)
* @param : Area
*  		  This parameter can be one of the following values:
*               @arg DECShift_High_Area2	
*               @arg DECShift_High_Area1
*               @arg DECShift_High_Area0
*							
* @retval: Dec_Shift Areax data,32 bit unsigned, 4BIT valid				
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_DEC_ShiftHGet(uint32_t Channel, uint32_t Area)
{
	uint32_t ultemp = 0U;
    uint8_t ushift = 0U;
	assert_param(IS_HT_EMU_DEC_ShiftH_CHANNEL_SEL(Channel));    /*  assert_Channel */
    assert_param(IS_HT_EMU_DEC_ShiftH_AREA_SEL(Area));          /*  assert_Area 0~2 */
    switch(Area)                                                /* Judge Area 0 1 2 */
    {
        case DECShift_High_Area2:
            ushift = 8U;
            break;
        case DECShift_High_Area1:
            ushift = 4U;
            break;
        case DECShift_High_Area0:
            ushift = 0U;
            break;
        default:
            break;
    }
	switch(Channel)                         					
	{
	#if defined  HT762x
		case ECR_DecShift_UaH:
            ultemp = HT_EMUECA->DECShift_UaH;
            break;
        case ECR_DecShift_UbH:
            ultemp = HT_EMUECA->DECShift_UbH;
            break;
        case ECR_DecShift_UcH:
            ultemp = HT_EMUECA->DECShift_UcH;
            break;
        case ECR_DecShift_IaH:
            ultemp = HT_EMUECA->DECShift_IaH;
            break;
        case ECR_DecShift_IbH:
            ultemp = HT_EMUECA->DECShift_IbH;
            break;
        case ECR_DecShift_IcH:
            ultemp = HT_EMUECA->DECShift_IcH;
            break;
        case ECR_DecShift_InH:
            ultemp = HT_EMUECA->DECShift_InH;
            break;
	#else
		case ECR_DecShift_UH:
			 ultemp = HT_EMUECA->DECShift_UH;
            break;
        case ECR_DecShift_I1H:
            ultemp = HT_EMUECA->DECShift_I1H;
            break;
        case ECR_DecShift_I2H:
            ultemp = HT_EMUECA->DECShift_I2H;
            break;
	#endif
		default:
			break;	
	}
    ultemp &= Area;
    ultemp >>= ushift;
	return ultemp;
}

/**
********************************************************************************************************
*                                      Set EMU DEC Shift_Low Phase correction
* @brief : set EMU Module DEC Shift Low Phase correction 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_DecShift_UaL	(If support)
*               @arg ECR_DecShift_UbL	(If support)
*               @arg ECR_DecShift_UcL	(If support)
*               @arg ECR_DecShift_IaL	(If support)	
*               @arg ECR_DecShift_IbL	(If support)
*               @arg ECR_DecShift_IcL	(If support)
*               @arg ECR_DecShift_InL	(If support)
*	
*               @arg ECR_DecShift_UL	(If support)
*               @arg ECR_DecShift_I1L	(If support)
*               @arg ECR_DecShift_I2L	(If support)
*
* @param : Area
*  		  This parameter can be one of the following values:
*               @arg DECShift_Low_Area2	
*               @arg DECShift_Low_Area1
*               @arg DECShift_Low_Area0
*
* @param: data: 
*               limits: 7BIT,(int)data< 0x128(OSR128); (int)data< 0x64(OSR64)
*							
*								
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_DEC_ShiftLSet(uint32_t Channel, uint32_t Area, uint32_t data)
{
	uint32_t ultemp = 0U,uldata = 0U;
    uint32_t ulProtect = HT_EMUECA->EMUWPREG;                  /* Get WP status */
	
	assert_param(IS_HT_EMU_DEC_ShiftL_CHANNEL_SEL(Channel));    /*  assert_Channel */
    assert_param(IS_HT_EMU_DEC_ShiftL_AREA_SEL(Area));          /*  assert_Area 0~2 */
    assert_param(IS_HT_EMU_DEC_ShiftL_LIMIT(data));             /*  assert_data Limit  */	
    switch(Area)                                                /* Judge Area 0 1 2*/
    {
        case DECShift_Low_Area2:
			uldata = data << 14U;
            break;
        case DECShift_Low_Area1:
			uldata = data << 7U;
            break;
        case DECShift_Low_Area0:
			uldata = data;
            break;
        default:
            break;
    }
    HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);           /* Close WP */
	switch(Channel)                                       /*Write data*/
	{
	#if defined  HT762x
		case ECR_DecShift_UaL:
            ultemp = HT_EMUECA->DECShift_UaL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UaL = ultemp;
            break;
        case ECR_DecShift_UbL:
            ultemp = HT_EMUECA->DECShift_UbL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UbL = ultemp;
            break;
        case ECR_DecShift_UcL:
            ultemp = HT_EMUECA->DECShift_UcL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UcL = ultemp;
            break;
        case ECR_DecShift_IaL:
            ultemp = HT_EMUECA->DECShift_IaL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IaL = ultemp;
            break;
        case ECR_DecShift_IbL:
            ultemp = HT_EMUECA->DECShift_IbL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IbL = ultemp;
            break;
        case ECR_DecShift_IcL:
            ultemp = HT_EMUECA->DECShift_IcL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_IcL = ultemp;
            break;
        case ECR_DecShift_InL:
            ultemp = HT_EMUECA->DECShift_InL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_InL = ultemp;
            break;
	#else
		case ECR_DecShift_UL:
            ultemp = HT_EMUECA->DECShift_UL;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_UL = ultemp;
			HT_EMUECA->DECShift_UL_BAK = ultemp;
            break;
        case ECR_DecShift_I1L:
            ultemp = HT_EMUECA->DECShift_I1L;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_I1L = ultemp;
            break;
        case ECR_DecShift_I2L:
            ultemp = HT_EMUECA->DECShift_I2L;
            ultemp &= (~Area);
            ultemp |= uldata;
            HT_EMUECA->DECShift_I2L = ultemp;
            break;	
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);/* write protect restore */
}

/**
********************************************************************************************************
*                                      Get EMU DEC Shift_Low Reg data
* @brief : Get EMU Module DEC Shift Low Area data
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_DecShift_UaL	(If support)
*               @arg ECR_DecShift_UbL	(If support)
*               @arg ECR_DecShift_UcL	(If support)
*               @arg ECR_DecShift_IaL	(If support)	
*               @arg ECR_DecShift_IbL	(If support)
*               @arg ECR_DecShift_IcL	(If support)
*               @arg ECR_DecShift_InL	(If support)
*	
*               @arg ECR_DecShift_UL	(If support)
*               @arg ECR_DecShift_I1L	(If support)
*               @arg ECR_DecShift_I2L	(If support)
*
* @param : Area
*  		  This parameter can be one of the following values:
*               @arg DECShift_Low_Area2	
*               @arg DECShift_Low_Area1
*               @arg DECShift_Low_Area0
*							
* @retval: Dec_Shift Areax data,32 bit unsigned, 7BIT valid					
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_DEC_ShiftLGet(uint32_t Channel, uint32_t Area)
{
	uint32_t ultemp = 0U;
    uint8_t ushift = 0U;
	assert_param(IS_HT_EMU_DEC_ShiftL_CHANNEL_SEL(Channel));    /*  assert_Channel  */
    assert_param(IS_HT_EMU_DEC_ShiftL_AREA_SEL(Area));    		/*  assert_Area 0~2 */
    switch(Area)                            					/* Judge Area 0 1 2*/
    {
        case DECShift_Low_Area2:
            ushift = 14U;
            break;
        case DECShift_Low_Area1:
            ushift = 7U;
            break;
        case DECShift_Low_Area0:
            ushift = 0U;
            break;
        default:
            break;
    }
	switch(Channel)                         
	{
	#if defined  HT762x
		case ECR_DecShift_UaL:
            ultemp = HT_EMUECA->DECShift_UaL;
            break;
        case ECR_DecShift_UbL:
            ultemp = HT_EMUECA->DECShift_UbL;
            break;
        case ECR_DecShift_UcL:
            ultemp = HT_EMUECA->DECShift_UcL;
            break;
        case ECR_DecShift_IaL:
            ultemp = HT_EMUECA->DECShift_IaL;
            break;
        case ECR_DecShift_IbL:
            ultemp = HT_EMUECA->DECShift_IbL;
            break;
        case ECR_DecShift_IcL:
            ultemp = HT_EMUECA->DECShift_IcL;
            break;
        case ECR_DecShift_InL:
            ultemp = HT_EMUECA->DECShift_InL;
            break;
	#else
		case ECR_DecShift_UL:
            ultemp = HT_EMUECA->DECShift_UL;
            break;
        case ECR_DecShift_I1L:
            ultemp = HT_EMUECA->DECShift_I1L;
            break;
        case ECR_DecShift_I2L:
            ultemp = HT_EMUECA->DECShift_I2L;
            break;
	#endif
		default:
			break;	
	}
    ultemp &= Area;
    ultemp >>= ushift;
	return ultemp;
}

/**
********************************************************************************************************
*                                      Set ADCOffset correction
* @brief : set EMU Module ADCOffset correction 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_ADCOffset_Ua	(If support)
*               @arg ECR_ADCOffset_Ub	(If support)
*               @arg ECR_ADCOffset_Uc	(If support)
*               @arg ECR_ADCOffset_Ia	(If support)
*               @arg ECR_ADCOffset_Ib	(If support)
*               @arg ECR_ADCOffset_Ic	(If support)
*               @arg ECR_ADCOffset_In	(If support)
*
*               @arg ECR_ADCOffset_U	(If support)
*               @arg ECR_ADCOffset_I1	(If support)
*               @arg ECR_ADCOffset_I2	(If support)
*
* @param: data: 
*               limits: signed, symbol bits are bit31~21, data bits are bit20~0
*							
*								
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCOffsetSet(uint32_t Channel, int32_t data)
{
    uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get WP status */
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ADCOffset_CHANNEL_SEL(Channel));     /*  assert_Channel  */
    assert_param(IS_HT_EMU_ADCOffset_LIMIT(data));              /*  assert_data Limit signed */	

    HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                 /* Close WP */
	
	ultemp = (uint32_t)data;
	ultemp &= ECR_22BIT_DATA;
	
	switch(Channel)                                             /*Write data*/
	{
	#if defined  HT762x
		case ECR_ADCOffset_Ua:
            HT_EMUECA->ADCOffset_Ua = ultemp;
            break;
        case ECR_ADCOffset_Ub:
            HT_EMUECA->ADCOffset_Ub = ultemp;
            break;
        case ECR_ADCOffset_Uc:
            HT_EMUECA->ADCOffset_Uc = ultemp;
            break;
        case ECR_ADCOffset_Ia:
            HT_EMUECA->ADCOffset_Ia = ultemp;
            break;
        case ECR_ADCOffset_Ib:
            HT_EMUECA->ADCOffset_Ib = ultemp;
            break;
        case ECR_ADCOffset_Ic:
            HT_EMUECA->ADCOffset_Ic = ultemp;
            break;
        case ECR_ADCOffset_In:
            HT_EMUECA->ADCOffset_In = ultemp;
            break;
	#else
		case ECR_ADCOffset_U:
            HT_EMUECA->ADCOffset_U = ultemp;
			HT_EMUECA->ADCOffset_U_BAK = ultemp;
            break;
        case ECR_ADCOffset_I1:
            HT_EMUECA->ADCOffset_I1 = ultemp;
            break;
        case ECR_ADCOffset_I2:
            HT_EMUECA->ADCOffset_I2 = ultemp;
            break;
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);				 /* restore write protect */
}

/**
********************************************************************************************************
*                                      Get ADCOffset data
* @brief : set EMU Module ADCOffset correction 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_ADCOffset_Ua	(If support)
*               @arg ECR_ADCOffset_Ub	(If support)
*               @arg ECR_ADCOffset_Uc	(If support)
*               @arg ECR_ADCOffset_Ia	(If support)
*               @arg ECR_ADCOffset_Ib	(If support)
*               @arg ECR_ADCOffset_Ic	(If support)
*               @arg ECR_ADCOffset_In	(If support)
*
*               @arg ECR_ADCOffset_U	(If support)
*               @arg ECR_ADCOffset_I1	(If support)
*               @arg ECR_ADCOffset_I2	(If support)
*
*							
* @retval: ADCOffsetx data, signed, symbol bits are bit31~21, data bits are bit20~0								
*
* @note  : none
**********************************************************************************************************/
int32_t HT_EMU_ADCOffsetGet(uint32_t Channel)
{
    uint32_t ultemp;
	assert_param(IS_HT_EMU_ADCOffset_CHANNEL_SEL(Channel));    /*  assert_Channel 0~7 */

	switch(Channel)                         					/*Read data*/
	{
	#if defined  HT762x
		case ECR_ADCOffset_Ua:
            ultemp = HT_EMUECA->ADCOffset_Ua;
            break;
        case ECR_ADCOffset_Ub:
            ultemp = HT_EMUECA->ADCOffset_Ub;
            break;
        case ECR_ADCOffset_Uc:
            ultemp = HT_EMUECA->ADCOffset_Uc;
            break;
        case ECR_ADCOffset_Ia:
            ultemp = HT_EMUECA->ADCOffset_Ia;
            break;
        case ECR_ADCOffset_Ib:
            ultemp = HT_EMUECA->ADCOffset_Ib;
            break;
        case ECR_ADCOffset_Ic:
            ultemp = HT_EMUECA->ADCOffset_Ic;
            break;
        case ECR_ADCOffset_In:
            ultemp = HT_EMUECA->ADCOffset_In;
            break;
	#else
		case ECR_ADCOffset_U:
            ultemp = HT_EMUECA->ADCOffset_U;
            break;
        case ECR_ADCOffset_I1:
            ultemp = HT_EMUECA->ADCOffset_I1;
            break;
        case ECR_ADCOffset_I2:
            ultemp = HT_EMUECA->ADCOffset_I2;
            break;	
	#endif
		default:
			break;
	}
	
	ultemp &= ECR_22BIT_DATA;
    if(ultemp & ECR_EMU_ADCOffset_Symbol)
    {
        ultemp |= ECR_EMU_ADCOffset_Signed;
    }
        
	return ((int32_t)ultemp);
}

/**
********************************************************************************************************
*                                      Set EMU Digital Gain SELECT
* @brief : set EMU module Channel Digital Gain select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg Digtal_gain_DGUa	(If support)
*               @arg Digtal_gain_DGUb	(If support)
*               @arg Digtal_gain_DGUc	(If support)
*               @arg Digtal_gain_DGIa	(If support)
*               @arg Digtal_gain_DGIb	(If support)
*               @arg Digtal_gain_DGIc	(If support)
*               @arg Digtal_gain_DGIn	(If support)
*
*               @arg Digtal_gain_DGU	(If support)
*               @arg Digtal_gain_DGI1	(If support)
*               @arg Digtal_gain_DGI2	(If support)
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				Channel = Digtal_gain_DGUx(x=a,b,c or none): voltage channel Digital gain
*								@arg Digtal_gain_DGUx_1
*								@arg Digtal_gain_DGUx_2
*								@arg Digtal_gain_DGUx_4
*								@arg Digtal_gain_DGUx_8
*								
*				Channel = Digtal_gain_DGIx(x=a,b,c,n or 1,2): current channel Digital gain
*								@arg Digtal_gain_DGIx_1
*								@arg Digtal_gain_DGIx_2
*								@arg Digtal_gain_DGIx_4
*								@arg Digtal_gain_DGIx_8
*								
* @retval: none					
*
*								
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_Digital_GainSet(uint32_t Channel,uint32_t select)
{
	uint32_t ultemp = 0U,ultemp2 = 0U;
    uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get WP status */
	
	assert_param(IS_HT_EMU_DigGain_CHANNEL_SEL(Channel));   /*  assert_param  */
	
	ultemp = HT_EMUECA->Digtal_gain;
	
	switch(Channel)
	{
	#if defined  HT762x
		case Digtal_gain_DGUa:
			assert_param(IS_HT_EMU_DigGainUA_SEL(select));    /*  assert_param  */	
			break;
		case Digtal_gain_DGUb:
			assert_param(IS_HT_EMU_DigGainUB_SEL(select));    /*  assert_param  */	
			break;
		case Digtal_gain_DGUc:
			assert_param(IS_HT_EMU_DigGainUC_SEL(select));    /*  assert_param  */	
			break;
		case Digtal_gain_DGIa:
			assert_param(IS_HT_EMU_DigGainIA_SEL(select));    /*  assert_param  */	
			break;
		case Digtal_gain_DGIb:
			assert_param(IS_HT_EMU_DigGainIB_SEL(select));    /*  assert_param  */	
			break;
        case Digtal_gain_DGIc:
			assert_param(IS_HT_EMU_DigGainIC_SEL(select));    /*  assert_param  */	
			break;
        case Digtal_gain_DGIn:
			assert_param(IS_HT_EMU_DigGainIN_SEL(select));    /*  assert_param  */	
			break;
	#else
		case Digtal_gain_DGU:
			assert_param(IS_HT_EMU_DigGainU_SEL(select));    /*  assert_param  */
			ultemp &= (~Digtal_gain_DGU_BAK); 
			ultemp2 = select << 2U ;
			break;
		case Digtal_gain_DGI1:
			assert_param(IS_HT_EMU_DigGainI1_SEL(select));    /*  assert_param  */	
			break;
		case Digtal_gain_DGI2:
			assert_param(IS_HT_EMU_DigGainI2_SEL(select));    /*  assert_param  */	
			break;
	#endif
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);              /* Close WP */
	ultemp &= (~Channel); 
    ultemp |= (select|ultemp2);
    HT_EMUECA->Digtal_gain = ultemp;
	
    HT_EMU_WPReg_Restore(ulProtect);                           /* restore write protect */
}

/**
********************************************************************************************************
*                                      Set EMU Temperature Gain
* @brief : set EMU module Channel Temperature Gain
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_Tgain_U	
*               @arg ECR_Tgain_I
*               @arg ECR_Tgain_In (If support)
*
*
* @param: data: tgain,16bit				
*
* @retval: none					
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_TGainSet(uint32_t Channel, int16_t data)
{
    uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get WP status */
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_TGain_CHANNEL_SEL(Channel));        /*  assert_param  */
   
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                /* Close WP */

	ultemp = (uint32_t)data;
	ultemp &= ECR_16BIT_DATA;
	
	switch(Channel)
	{
		case ECR_Tgain_U:
            HT_EMUECA->Tgain_U = ultemp;
			break;
		case ECR_Tgain_I:
			HT_EMUECA->Tgain_I = ultemp;
			break;
	#if defined  HT762x
		case ECR_Tgain_In:
			HT_EMUECA->Tgain_In = ultemp;
			break;
	#endif
		default:
			break;	
	}
    
    HT_EMU_WPReg_Restore(ulProtect);                           /* restore write proyect */
    
}

/**
********************************************************************************************************
*                                      Get EMU Temperature Gain
* @brief : Get EMU module Channel Temperature Gain
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_Tgain_U	
*               @arg ECR_Tgain_I
*               @arg ECR_Tgain_In (If support)
*
* @retval: data: tgain,16bit					
*
*
* @note  : none
**********************************************************************************************************/
int16_t HT_EMU_TGainGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	assert_param(IS_HT_EMU_TGain_CHANNEL_SEL(Channel));    /*  assert_param  */

	switch(Channel)
	{
		case ECR_Tgain_U:
            ultemp = HT_EMUECA->Tgain_U;
			break;
		case ECR_Tgain_I:
			ultemp = HT_EMUECA->Tgain_I;
			break;
	#if defined  HT762x
		case ECR_Tgain_In:
			ultemp = HT_EMUECA->Tgain_In;
			break;
	#endif
		default:
			break;	
	}
    
    ultemp &= ECR_16BIT_DATA;
	
    return ((int16_t)ultemp);
    
}

/**
********************************************************************************************************
*                                      Set EMU Channel Gain
* @brief : set EMU module Channel Temperature Gain
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_Gain_Ua	(If support)
*               @arg ECR_Gain_Ub	(If support)
*               @arg ECR_Gain_Uc	(If support)
*               @arg ECR_Gain_Ia	(If support)
*               @arg ECR_Gain_Ib	(If support)
*               @arg ECR_Gain_Ic	(If support)
*               @arg ECR_Gain_In	(If support)
*
*               @arg ECR_Gain_U 	(If support)
*               @arg ECR_Gain_I1	(If support)
*               @arg ECR_Gain_I2	(If support)
*
* @param: data: 16bit signed valid						
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_GainSet(uint32_t Channel, int16_t data)
{
    uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get WP status */
	uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_Gain_CHANNEL_SEL(Channel));         /*  assert_param  */
   
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                /* Close WP */
	
	ultemp = (uint32_t)data;
	ultemp &= ECR_16BIT_DATA;

	switch(Channel)
	{
	#if defined  HT762x
		case ECR_Gain_Ua:
            HT_EMUECA->Gain_Ua = ultemp;
			break;
		case ECR_Gain_Ub:
			HT_EMUECA->Gain_Ub = ultemp;
			break;
		case ECR_Gain_Uc:
			HT_EMUECA->Gain_Uc = ultemp;
			break;
        case ECR_Gain_Ia:
            HT_EMUECA->Gain_Ia = ultemp;
			break;
        case ECR_Gain_Ib:
            HT_EMUECA->Gain_Ib = ultemp;
			break;
        case ECR_Gain_Ic:
            HT_EMUECA->Gain_Ic = ultemp;
			break;
        case ECR_Gain_In:
            HT_EMUECA->Gain_In = ultemp;
			break;
	#else
		case ECR_Gain_U:
            HT_EMUECA->Gain_U = ultemp;
			HT_EMUECA->Gain_U_BAK = ultemp;
			break;
        case ECR_Gain_I1:
            HT_EMUECA->Gain_I1 = ultemp;
			break;
        case ECR_Gain_I2:
            HT_EMUECA->Gain_I2 = ultemp;
			break;	
	#endif
		default:
			break;	
	}
    
    HT_EMU_WPReg_Restore(ulProtect);					 /* restore write proyect */
    
}

/**
********************************************************************************************************
*                                      Get EMU Channel Gain
* @brief : Get EMU module Channel Temperature Gain
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ECR_Gain_Ua	(If support)
*               @arg ECR_Gain_Ub	(If support)
*               @arg ECR_Gain_Uc	(If support)
*               @arg ECR_Gain_Ia	(If support)
*               @arg ECR_Gain_Ib	(If support)
*               @arg ECR_Gain_Ic	(If support)
*               @arg ECR_Gain_In	(If support)
*
*               @arg ECR_Gain_U 	(If support)
*               @arg ECR_Gain_I1	(If support)
*               @arg ECR_Gain_I2	(If support)
*
*
* @retval: data: 16bit						
*
*
* @note  : none
**********************************************************************************************************/
int16_t HT_EMU_GainGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	assert_param(IS_HT_EMU_Gain_CHANNEL_SEL(Channel));    /*  assert_param  */

	switch(Channel)
	{
	#if defined  HT762x
		case ECR_Gain_Ua:
            ultemp = HT_EMUECA->Gain_Ua;
			break;
		case ECR_Gain_Ub:
			ultemp = HT_EMUECA->Gain_Ub;
			break;
		case ECR_Gain_Uc:
			ultemp = HT_EMUECA->Gain_Uc;
			break;
        case ECR_Gain_Ia:
            ultemp = HT_EMUECA->Gain_Ia;
			break;
        case ECR_Gain_Ib:
            ultemp = HT_EMUECA->Gain_Ib;
			break;
        case ECR_Gain_Ic:
            ultemp = HT_EMUECA->Gain_Ic;
			break;
        case ECR_Gain_In:
            ultemp = HT_EMUECA->Gain_In;
			break;
	#else
		case ECR_Gain_U:
            ultemp = HT_EMUECA->Gain_U;
			break;
        case ECR_Gain_I1:
            ultemp = HT_EMUECA->Gain_I1;
			break;
        case ECR_Gain_I2:
            ultemp = HT_EMUECA->Gain_I2;
			break;	
	#endif
		default:
			break;	
	}
    
    ultemp &= ECR_16BIT_DATA;
	
    return ((int16_t)ultemp);
    
}
/**
*********************************************************************************************************
*                                       SET EMU PowerGain
*
* @brief : set EMU module all/fund/total har wave power Gain 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_GPa	(If support)
*                        @arg ECR_All_GPb	(If support)
*                        @arg ECR_All_GPc   (If support) 	 
*                        @arg ECR_All_GQa	(If support)
*                        @arg ECR_All_GQb	(If support)
*                        @arg ECR_All_GQc   (If support)
*                        @arg ECR_All_GSa	(If support)
*                        @arg ECR_All_GSb	(If support)
*                        @arg ECR_All_GSc 	(If support)
*                        @arg ECR_Fund_GPa	(If support)
*                        @arg ECR_Fund_GPb	(If support)
*                        @arg ECR_Fund_GPc	(If support)
*                        @arg ECR_Fund_GQa 	(If support)
*                        @arg ECR_Fund_GQb	(If support)
*                        @arg ECR_Fund_GQc	(If support)
*                        @arg ECR_Fund_GSa	(If support)
*                        @arg ECR_Fund_GSb	(If support)
*                        @arg ECR_Fund_GSc	(If support)
*                        @arg ECR_Har_GPa	(If support)
*                        @arg ECR_Har_GPb	(If support)
*                        @arg ECR_Har_GPc	(If support)
*
*                        @arg ECR_All_GP1	(If support)
*                        @arg ECR_All_GP2	(If support)
*                        @arg ECR_All_GQ1	(If support)
*                        @arg ECR_All_GQ2	(If support)
*                        @arg ECR_All_GS1	(If support)
*                        @arg ECR_All_GS2	(If support)
*                        @arg ECR_Fund_GP1	(If support)
*                        @arg ECR_Fund_GP2	(If support)
*                        @arg ECR_Fund_GQ1 	(If support)
*                        @arg ECR_Fund_GQ2	(If support)
*                        @arg ECR_Fund_GS1	(If support)
*                        @arg ECR_Fund_GS2	(If support)
*                        @arg ECR_Har_GP1	(If support)
*                        @arg ECR_Har_GP2	(If support)
*
* @param : data:power gain data,16bit

* @retval: none
*
* @note  : used to calibrate power for all/fund/total har wave
*********************************************************************************************************
*/
void HT_EMU_PowerGainSet(uint32_t Channel,int16_t data)
{		
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					/* GET Write Protect */ 
		
	assert_param(IS_HT_EMU_POWERGAIN_SEL(Channel));             /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				/* Close write protect*/
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_GPa:
			HT_EMUECA->All_GPa = data;
			break;
		case ECR_All_GPb:
			HT_EMUECA->All_GPb = data;
			break;
		case ECR_All_GPc:
			HT_EMUECA->All_GPc = data;
			break;
		case ECR_All_GQa:
			HT_EMUECA->All_GQa = data;
			break;
		case ECR_All_GQb:
			HT_EMUECA->All_GQb = data;
			break;
		case ECR_All_GQc:
			HT_EMUECA->All_GQc = data;
			break;
		case ECR_All_GSa:
			HT_EMUECA->All_GSa = data;
			break;
		case ECR_All_GSb:
			HT_EMUECA->All_GSb = data;
			break;
		case ECR_All_GSc:
			HT_EMUECA->All_GSc = data;
			break;		
		case ECR_Fund_GPa:
			HT_EMUECA->Fund_GPa = data;
			break;
		case ECR_Fund_GPb:
			HT_EMUECA->Fund_GPb = data;
			break;
		case ECR_Fund_GPc:
			HT_EMUECA->Fund_GPc = data;
			break;
		case ECR_Fund_GQa:
			HT_EMUECA->Fund_GQa = data;
			break;
		case ECR_Fund_GQb:
			HT_EMUECA->Fund_GQb = data;
			break;
		case ECR_Fund_GQc:
			HT_EMUECA->Fund_GQc = data;
			break;
		case ECR_Fund_GSa:
			HT_EMUECA->Fund_GSa = data;
			break;
		case ECR_Fund_GSb:
			HT_EMUECA->Fund_GSb = data;
			break;
		case ECR_Fund_GSc:
			HT_EMUECA->Fund_GSc = data;
			break;	
		case ECR_Har_GPa:
			HT_EMUECA->Har_GPa = data;
			break;
		case ECR_Har_GPb:
			HT_EMUECA->Har_GPb = data;
			break;
		case ECR_Har_GPc:
			HT_EMUECA->Har_GPc = data;
			break;	
	#else
		case ECR_All_GP1:
			HT_EMUECA->All_GP1 = data;
			break;
		case ECR_All_GP2:
			HT_EMUECA->All_GP2 = data;
			break;
		case ECR_All_GQ1:
			HT_EMUECA->All_GQ1 = data;
			break;
		case ECR_All_GQ2:
			HT_EMUECA->All_GQ2 = data;
			break;
		case ECR_All_GS1:
			HT_EMUECA->All_GS1 = data;
			break;
		case ECR_All_GS2:
			HT_EMUECA->All_GS2 = data;
			break;		
		case ECR_Fund_GP1:
			HT_EMUECA->Fund_GP1 = data;
			break;
		case ECR_Fund_GP2:
			HT_EMUECA->Fund_GP2 = data;
			break;
		case ECR_Fund_GQ1:
			HT_EMUECA->Fund_GQ1 = data;
			break;
		case ECR_Fund_GQ2:
			HT_EMUECA->Fund_GQ2 = data;
			break;
		case ECR_Fund_GS1:
			HT_EMUECA->Fund_GS1 = data;
			break;
		case ECR_Fund_GS2:
			HT_EMUECA->Fund_GS2 = data;
			break;
		case ECR_Har_GP1:
			HT_EMUECA->Har_GP1 = data;
			break;
		case ECR_Har_GP2:
			HT_EMUECA->Har_GP2 = data;
			break;
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore write protect register*/
}

/**
*********************************************************************************************************
*                                       GET EMU PowerGain
*
* @brief : get EMU module all/fund/total har power Gain 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_GPa	(If support)
*                        @arg ECR_All_GPb	(If support)
*                        @arg ECR_All_GPc   (If support) 	 
*                        @arg ECR_All_GQa	(If support)
*                        @arg ECR_All_GQb	(If support)
*                        @arg ECR_All_GQc   (If support)
*                        @arg ECR_All_GSa	(If support)
*                        @arg ECR_All_GSb	(If support)
*                        @arg ECR_All_GSc 	(If support)
*                        @arg ECR_Fund_GPa	(If support)
*                        @arg ECR_Fund_GPb	(If support)
*                        @arg ECR_Fund_GPc	(If support)
*                        @arg ECR_Fund_GQa 	(If support)
*                        @arg ECR_Fund_GQb	(If support)
*                        @arg ECR_Fund_GQc	(If support)
*                        @arg ECR_Fund_GSa	(If support)
*                        @arg ECR_Fund_GSb	(If support)
*                        @arg ECR_Fund_GSc	(If support)
*                        @arg ECR_Har_GPa	(If support)
*                        @arg ECR_Har_GPb	(If support)
*                        @arg ECR_Har_GPc	(If support)
*
*                        @arg ECR_All_GP1	(If support)
*                        @arg ECR_All_GP2	(If support)
*                        @arg ECR_All_GQ1	(If support)
*                        @arg ECR_All_GQ2	(If support)
*                        @arg ECR_All_GS1	(If support)
*                        @arg ECR_All_GS2	(If support)
*                        @arg ECR_Fund_GP1	(If support)
*                        @arg ECR_Fund_GP2	(If support)
*                        @arg ECR_Fund_GQ1 	(If support)
*                        @arg ECR_Fund_GQ2	(If support)
*                        @arg ECR_Fund_GS1	(If support)
*                        @arg ECR_Fund_GS2	(If support)
*                        @arg ECR_Har_GP1	(If support)
*                        @arg ECR_Har_GP2	(If support)
*
* @retval: power gain data,16bit
*
* @note  : used to calibrate power for all/fund/total har wave
*********************************************************************************************************
*/
int16_t HT_EMU_PowerGainGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERGAIN_SEL(Channel));      /*  assert_param  */
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_GPa:
			ultemp=HT_EMUECA->All_GPa;
			break;
		case ECR_All_GPb:
			ultemp=HT_EMUECA->All_GPb;
			break;
		case ECR_All_GPc:
			ultemp=HT_EMUECA->All_GPc;
			break;
		case ECR_All_GQa:
			ultemp=HT_EMUECA->All_GQa;
			break;
		case ECR_All_GQb:
			ultemp=HT_EMUECA->All_GQb;
			break;
		case ECR_All_GQc:
			ultemp=HT_EMUECA->All_GQc;
			break;
		case ECR_All_GSa:
			ultemp=HT_EMUECA->All_GSa;
			break;
		case ECR_All_GSb:
			ultemp=HT_EMUECA->All_GSb;
			break;
		case ECR_All_GSc:
			ultemp=HT_EMUECA->All_GSc;
			break;		
		case ECR_Fund_GPa:
			ultemp=HT_EMUECA->Fund_GPa;
			break;
		case ECR_Fund_GPb:
			ultemp=HT_EMUECA->Fund_GPb;
			break;
		case ECR_Fund_GPc:
			ultemp=HT_EMUECA->Fund_GPc;
			break;
		case ECR_Fund_GQa:
			ultemp=HT_EMUECA->Fund_GQa;
			break;
		case ECR_Fund_GQb:
			ultemp=HT_EMUECA->Fund_GQb;
			break;
		case ECR_Fund_GQc:
			ultemp=HT_EMUECA->Fund_GQc;
			break;
		case ECR_Fund_GSa:
			ultemp=HT_EMUECA->Fund_GSa;
			break;
		case ECR_Fund_GSb:
			ultemp=HT_EMUECA->Fund_GSb;
			break;
		case ECR_Fund_GSc:
			ultemp=HT_EMUECA->Fund_GSc;
			break;	
		case ECR_Har_GPa:
			ultemp=HT_EMUECA->Har_GPa;
			break;
		case ECR_Har_GPb:
			ultemp=HT_EMUECA->Har_GPb;
			break;
		case ECR_Har_GPc:
			ultemp=HT_EMUECA->Har_GPc;
			break;	
	#else
		case ECR_All_GP1:
			ultemp=HT_EMUECA->All_GP1;
			break;
		case ECR_All_GP2:
			ultemp=HT_EMUECA->All_GP2;
			break;
		case ECR_All_GQ1:
			ultemp=HT_EMUECA->All_GQ1;
			break;
		case ECR_All_GQ2:
			ultemp=HT_EMUECA->All_GQ2;
			break;
		case ECR_All_GS1:
			ultemp=HT_EMUECA->All_GS1;
			break;
		case ECR_All_GS2:
			ultemp=HT_EMUECA->All_GS2;
			break;		
		case ECR_Fund_GP1:
			ultemp=HT_EMUECA->Fund_GP1;
			break;
		case ECR_Fund_GP2:
			ultemp=HT_EMUECA->Fund_GP2;
			break;
		case ECR_Fund_GQ1:
			ultemp=HT_EMUECA->Fund_GQ1;
			break;
		case ECR_Fund_GQ2:
			ultemp=HT_EMUECA->Fund_GQ2;
			break;
		case ECR_Fund_GS1:
			ultemp=HT_EMUECA->Fund_GS1;
			break;
		case ECR_Fund_GS2:
			ultemp=HT_EMUECA->Fund_GS2;
			break;
		case ECR_Har_GP1:
			ultemp=HT_EMUECA->Har_GP1;
			break;
		case ECR_Har_GP2:
			ultemp=HT_EMUECA->Har_GP2;
			break;	
	#endif
		default:
			break;	
	}
	
	ultemp &= ECR_16BIT_DATA;	
	return ultemp;
}
/**
*********************************************************************************************************
*                                       SET EMU Phase Gain
*
* @brief : set EMU module all/fund wave phase gain 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_GphsA0 (If support)
*                        @arg ECR_All_GphsA1 (If support)
*                        @arg ECR_All_GphsA2 (If support)
*                        @arg ECR_All_GphsB0 (If support)
*                        @arg ECR_All_GphsB1 (If support)
*                        @arg ECR_All_GphsB2 (If support)
*                        @arg ECR_All_GphsC0 (If support)
*                        @arg ECR_All_GphsC1 (If support)
*                        @arg ECR_All_GphsC2 (If support)
*                        @arg ECR_Fund_GphsA0(If support)
*                        @arg ECR_Fund_GphsA1(If support)
*                        @arg ECR_Fund_GphsA2(If support)
*                        @arg ECR_Fund_GphsB0(If support)
*                        @arg ECR_Fund_GphsB1(If support)
*                        @arg ECR_Fund_GphsB2(If support)
*                        @arg ECR_Fund_GphsC0(If support)
*                        @arg ECR_Fund_GphsC1(If support)
*                        @arg ECR_Fund_GphsC2(If support)
*
*                        @arg ECR_All_Gphs10 (If support)
*                        @arg ECR_All_Gphs11 (If support)
*                        @arg ECR_All_Gphs12 (If support)
*                        @arg ECR_All_Gphs20 (If support)
*                        @arg ECR_All_Gphs21 (If support)
*                        @arg ECR_All_Gphs22 (If support)
*                        @arg ECR_Fund_Gphs10(If support)
*                        @arg ECR_Fund_Gphs11(If support)
*                        @arg ECR_Fund_Gphs12(If support)
*                        @arg ECR_Fund_Gphs20(If support)
*                        @arg ECR_Fund_Gphs21(If support)
*                        @arg ECR_Fund_Gphs22(If support)
*
* @param : data:phase gain data,16bit

* @retval: none
*
* @note  : used to calibrate phase for all/fund wave
*********************************************************************************************************
*/
void HT_EMU_PhaseGainSet(uint32_t Channel,int16_t data)
{		
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					/* GET Write Protect */ 	

	assert_param(IS_HT_EMU_PHASEGAIN_SEL(Channel));            /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				/* Close write protect*/
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_GphsA0:
			HT_EMUECA->All_GphsA0 = data;
			break;
		case ECR_All_GphsA1:
			HT_EMUECA->All_GphsA1 = data;
			break;
		case ECR_All_GphsA2:
			HT_EMUECA->All_GphsA2 = data;
			break;
		case ECR_All_GphsB0:
			HT_EMUECA->All_GphsB0 = data;
			break;
		case ECR_All_GphsB1:
			HT_EMUECA->All_GphsB1 = data;
			break;
		case ECR_All_GphsB2:
			HT_EMUECA->All_GphsB2 = data;
			break;
		case ECR_All_GphsC0:
			HT_EMUECA->All_GphsC0 = data;
			break;
		case ECR_All_GphsC1:
			HT_EMUECA->All_GphsC1 = data;
			break;
		case ECR_All_GphsC2:
			HT_EMUECA->All_GphsC2 = data;
			break;		
		case ECR_Fund_GphsA0:
			HT_EMUECA->Fund_GphsA0 = data;
			break;
		case ECR_Fund_GphsA1:
			HT_EMUECA->Fund_GphsA1 = data;
			break;
		case ECR_Fund_GphsA2:
			HT_EMUECA->Fund_GphsA2 = data;
			break;
		case ECR_Fund_GphsB0:
			HT_EMUECA->Fund_GphsB0 = data;
			break;
		case ECR_Fund_GphsB1:
			HT_EMUECA->Fund_GphsB1 = data;
			break;
		case ECR_Fund_GphsB2:
			HT_EMUECA->Fund_GphsB2 = data;
			break;
		case ECR_Fund_GphsC0:
			HT_EMUECA->Fund_GphsC0 = data;
			break;
		case ECR_Fund_GphsC1:
			HT_EMUECA->Fund_GphsC1 = data;
			break;
		case ECR_Fund_GphsC2:
			HT_EMUECA->Fund_GphsC2 = data;
			break;
	#else
		case ECR_All_Gphs10:
			HT_EMUECA->All_Gphs10 = data;
			break;
		case ECR_All_Gphs11:
			HT_EMUECA->All_Gphs11 = data;
			break;
		case ECR_All_Gphs12:
			HT_EMUECA->All_Gphs12 = data;
			break;
		case ECR_All_Gphs20:
			HT_EMUECA->All_Gphs20 = data;
			break;
		case ECR_All_Gphs21:
			HT_EMUECA->All_Gphs21 = data;
			break;
		case ECR_All_Gphs22:
			HT_EMUECA->All_Gphs22 = data;
			break;
		case ECR_Fund_Gphs10:
			HT_EMUECA->Fund_Gphs10 = data;
			break;
		case ECR_Fund_Gphs11:
			HT_EMUECA->Fund_Gphs11 = data;
			break;
		case ECR_Fund_Gphs12:
			HT_EMUECA->Fund_Gphs12 = data;
			break;
		case ECR_Fund_Gphs20:
			HT_EMUECA->Fund_Gphs20 = data;
			break;
		case ECR_Fund_Gphs21:
			HT_EMUECA->Fund_Gphs21 = data;
			break;
		case ECR_Fund_Gphs22:
			HT_EMUECA->Fund_Gphs22 = data;
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore write protect register*/
}


/**
*********************************************************************************************************
*                                       GET EMU PhaseGain
*
* @brief : get EMU module all/fund wave phase gain 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_GphsA0 (If support)
*                        @arg ECR_All_GphsA1 (If support)
*                        @arg ECR_All_GphsA2 (If support)
*                        @arg ECR_All_GphsB0 (If support)
*                        @arg ECR_All_GphsB1 (If support)
*                        @arg ECR_All_GphsB2 (If support)
*                        @arg ECR_All_GphsC0 (If support)
*                        @arg ECR_All_GphsC1 (If support)
*                        @arg ECR_All_GphsC2 (If support)
*                        @arg ECR_Fund_GphsA0(If support)
*                        @arg ECR_Fund_GphsA1(If support)
*                        @arg ECR_Fund_GphsA2(If support)
*                        @arg ECR_Fund_GphsB0(If support)
*                        @arg ECR_Fund_GphsB1(If support)
*                        @arg ECR_Fund_GphsB2(If support)
*                        @arg ECR_Fund_GphsC0(If support)
*                        @arg ECR_Fund_GphsC1(If support)
*                        @arg ECR_Fund_GphsC2(If support)
*
*                        @arg ECR_All_Gphs10 (If support)
*                        @arg ECR_All_Gphs11 (If support)
*                        @arg ECR_All_Gphs12 (If support)
*                        @arg ECR_All_Gphs20 (If support)
*                        @arg ECR_All_Gphs21 (If support)
*                        @arg ECR_All_Gphs22 (If support)
*                        @arg ECR_Fund_Gphs10(If support)
*                        @arg ECR_Fund_Gphs11(If support)
*                        @arg ECR_Fund_Gphs12(If support)
*                        @arg ECR_Fund_Gphs20(If support)
*                        @arg ECR_Fund_Gphs21(If support)
*                        @arg ECR_Fund_Gphs22(If support)
*
* @retval: phase gain data,16bit
*
* @note  : none
*********************************************************************************************************
*/
int16_t HT_EMU_PhaseGainGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PHASEGAIN_SEL(Channel));      /*  assert_param  */
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_GphsA0:
			ultemp=HT_EMUECA->All_GphsA0;
			break;
		case ECR_All_GphsA1:
			ultemp=HT_EMUECA->All_GphsA1;
			break;
		case ECR_All_GphsA2:
			ultemp=HT_EMUECA->All_GphsA2;
			break;
		case ECR_All_GphsB0:
			ultemp=HT_EMUECA->All_GphsB0;
			break;
		case ECR_All_GphsB1:
			ultemp=HT_EMUECA->All_GphsB1;
			break;
		case ECR_All_GphsB2:
			ultemp=HT_EMUECA->All_GphsB2;
			break;
		case ECR_All_GphsC0:
			ultemp=HT_EMUECA->All_GphsC0;
			break;
		case ECR_All_GphsC1:
			ultemp=HT_EMUECA->All_GphsC1;
			break;
		case ECR_All_GphsC2:
			ultemp=HT_EMUECA->All_GphsC2;
			break;		
		case ECR_Fund_GphsA0:
			ultemp=HT_EMUECA->Fund_GphsA0;
			break;
		case ECR_Fund_GphsA1:
			ultemp=HT_EMUECA->Fund_GphsA1;
			break;
		case ECR_Fund_GphsA2:
			ultemp=HT_EMUECA->Fund_GphsA2;
			break;
		case ECR_Fund_GphsB0:
			ultemp=HT_EMUECA->Fund_GphsB0;
			break;
		case ECR_Fund_GphsB1:
			ultemp=HT_EMUECA->Fund_GphsB1;
			break;
		case ECR_Fund_GphsB2:
			ultemp=HT_EMUECA->Fund_GphsB2;
			break;
		case ECR_Fund_GphsC0:
			ultemp=HT_EMUECA->Fund_GphsC0;
			break;
		case ECR_Fund_GphsC1:
			ultemp=HT_EMUECA->Fund_GphsC1;
			break;
		case ECR_Fund_GphsC2:
			ultemp=HT_EMUECA->Fund_GphsC2;
			break;	
	#else
		case ECR_All_Gphs10:
			ultemp = HT_EMUECA->All_Gphs10;
			break;
		case ECR_All_Gphs11:
			ultemp = HT_EMUECA->All_Gphs11;
			break;
		case ECR_All_Gphs12:
			ultemp = HT_EMUECA->All_Gphs12;
			break;
		case ECR_All_Gphs20:
			ultemp = HT_EMUECA->All_Gphs20;
			break;
		case ECR_All_Gphs21:
			ultemp = HT_EMUECA->All_Gphs21;
			break;
		case ECR_All_Gphs22:
			ultemp = HT_EMUECA->All_Gphs22;
			break;
		case ECR_Fund_Gphs10:
			ultemp = HT_EMUECA->Fund_Gphs10;
			break;
		case ECR_Fund_Gphs11:
			ultemp = HT_EMUECA->Fund_Gphs11;
			break;
		case ECR_Fund_Gphs12:
			ultemp = HT_EMUECA->Fund_Gphs12;
			break;
		case ECR_Fund_Gphs20:
			ultemp = HT_EMUECA->Fund_Gphs20;
			break;
		case ECR_Fund_Gphs21:
			ultemp = HT_EMUECA->Fund_Gphs21;
			break;
		case ECR_Fund_Gphs22:
			ultemp = HT_EMUECA->Fund_Gphs22;
			break;	
	#endif
		default:
			break;	
	}
	
	ultemp &= ECR_16BIT_DATA;	
	return ultemp;
}
/**
*********************************************************************************************************
*                                       SET EMU PowerOffset
*
* @brief : set EMU module all/fund/total har power offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_PowerOffset_Pa (If support)
*                        @arg ECR_All_PowerOffset_Pb (If support)
*                        @arg ECR_All_PowerOffset_Pc (If support)
*                        @arg ECR_All_PowerOffset_Qa (If support)
*                        @arg ECR_All_PowerOffset_Qb (If support)
*                        @arg ECR_All_PowerOffset_Qc (If support)
*                        @arg ECR_Fund_PowerOffset_Pa(If support)
*                        @arg ECR_Fund_PowerOffset_Pb(If support)
*                        @arg ECR_Fund_PowerOffset_Pc(If support)
*                        @arg ECR_Fund_PowerOffset_Qa(If support)
*                        @arg ECR_Fund_PowerOffset_Qb(If support)
*                        @arg ECR_Fund_PowerOffset_Qc(If support)
*                        @arg ECR_Har_PowerOffset_Pa (If support)
*                        @arg ECR_Har_PowerOffset_Pb (If support)
*                        @arg ECR_Har_PowerOffset_Pc (If support)
*
*                        @arg ECR_All_PowerOffset_P1 (If support)
*                        @arg ECR_All_PowerOffset_P2 (If support)
*                        @arg ECR_All_PowerOffset_Q1 (If support)
*                        @arg ECR_All_PowerOffset_Q2 (If support)
*                        @arg ECR_Fund_PowerOffset_P1(If support)
*                        @arg ECR_Fund_PowerOffset_P2(If support)
*                        @arg ECR_Fund_PowerOffset_Q1(If support)
*                        @arg ECR_Fund_PowerOffset_Q2(If support)
*                        @arg ECR_Har_PowerOffset_P1 (If support)
*                        @arg ECR_Har_PowerOffset_P2 (If support)
*
* @param : data: power offset data, limits: signed, symbol bits are bit31~23, data bits are bit22~0

* @retval: none
*
* @note  : used to calibrate offset for all/fund/total har wave power
*********************************************************************************************************
*/
void HT_EMU_PowerOffsetSet(uint32_t Channel, int32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  									/* Get Write Protect */ 	
	uint32_t ultemp = 0U;
	assert_param(IS_HT_EMU_POWEROFFSET_SEL(Channel));                           /*  assert_param  */
	assert_param(IS_HT_EMU_POWEROFFSET_LIMIT(data));
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  								/* Close write protect*/
	
	ultemp = (uint32_t)data;
	ultemp &= ECR_24BIT_DATA;
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_PowerOffset_Pa:
			HT_EMUECA->All_PowerOffset_Pa = ultemp;
			break;
		case ECR_All_PowerOffset_Pb:
			HT_EMUECA->All_PowerOffset_Pb = ultemp;
			break;
		case ECR_All_PowerOffset_Pc:
			HT_EMUECA->All_PowerOffset_Pc = ultemp;
			break;
		case ECR_All_PowerOffset_Qa:
			HT_EMUECA->All_PowerOffset_Qa = ultemp;
			break;
		case ECR_All_PowerOffset_Qb:
			HT_EMUECA->All_PowerOffset_Qb = ultemp;
			break;
		case ECR_All_PowerOffset_Qc:
			HT_EMUECA->All_PowerOffset_Qc = ultemp;
			break;
		case ECR_Fund_PowerOffset_Pa:
			HT_EMUECA->Fund_PowerOffset_Pa = ultemp;
			break;
		case ECR_Fund_PowerOffset_Pb:
			HT_EMUECA->Fund_PowerOffset_Pb = ultemp;
			break;
		case ECR_Fund_PowerOffset_Pc:
			HT_EMUECA->Fund_PowerOffset_Pc = ultemp;
			break;		
		case ECR_Fund_PowerOffset_Qa:
			HT_EMUECA->Fund_PowerOffset_Qa = ultemp;
			break;
		case ECR_Fund_PowerOffset_Qb:
			HT_EMUECA->Fund_PowerOffset_Qb = ultemp;
			break;
		case ECR_Fund_PowerOffset_Qc:
			HT_EMUECA->Fund_PowerOffset_Qc = ultemp;
			break;
		case ECR_Har_PowerOffset_Pa:
			HT_EMUECA->Har_PowerOffset_Pa = ultemp;
			break;
		case ECR_Har_PowerOffset_Pb:
			HT_EMUECA->Har_PowerOffset_Pb = ultemp;
			break;
		case ECR_Har_PowerOffset_Pc:
			HT_EMUECA->Har_PowerOffset_Pc = ultemp;
			break;
	#else
		case ECR_All_PowerOffset_P1:
			HT_EMUECA->All_PowerOffset_P1 = ultemp;
			break;
		case ECR_All_PowerOffset_P2:
			HT_EMUECA->All_PowerOffset_P2 = ultemp;
			break;
		case ECR_All_PowerOffset_Q1:
			HT_EMUECA->All_PowerOffset_Q1 = ultemp;
			break;
		case ECR_All_PowerOffset_Q2:
			HT_EMUECA->All_PowerOffset_Q2 = ultemp;
			break;
		case ECR_Fund_PowerOffset_P1:
			HT_EMUECA->Fund_PowerOffset_P1 = ultemp;
			break;
		case ECR_Fund_PowerOffset_P2:
			HT_EMUECA->Fund_PowerOffset_P2 = ultemp;
			break;		
		case ECR_Fund_PowerOffset_Q1:
			HT_EMUECA->Fund_PowerOffset_Q1 = ultemp;
			break;
		case ECR_Fund_PowerOffset_Q2:
			HT_EMUECA->Fund_PowerOffset_Q2 = ultemp;
			break;
		case ECR_Har_PowerOffset_P1:
			HT_EMUECA->Har_PowerOffset_P1 = ultemp;
			break;
		case ECR_Har_PowerOffset_P2:
			HT_EMUECA->Har_PowerOffset_P2 = ultemp;
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */

}
/**
*********************************************************************************************************
*                                       GET EMU PowerOffset
*
* @brief : get EMU module power offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_PowerOffset_Pa (If support)
*                        @arg ECR_All_PowerOffset_Pb (If support)
*                        @arg ECR_All_PowerOffset_Pc (If support)
*                        @arg ECR_All_PowerOffset_Qa (If support)
*                        @arg ECR_All_PowerOffset_Qb (If support)
*                        @arg ECR_All_PowerOffset_Qc (If support)
*                        @arg ECR_Fund_PowerOffset_Pa(If support)
*                        @arg ECR_Fund_PowerOffset_Pb(If support)
*                        @arg ECR_Fund_PowerOffset_Pc(If support)
*                        @arg ECR_Fund_PowerOffset_Qa(If support)
*                        @arg ECR_Fund_PowerOffset_Qb(If support)
*                        @arg ECR_Fund_PowerOffset_Qc(If support)
*                        @arg ECR_Har_PowerOffset_Pa (If support)
*                        @arg ECR_Har_PowerOffset_Pb (If support)
*                        @arg ECR_Har_PowerOffset_Pc (If support)
*
*                        @arg ECR_All_PowerOffset_P1 (If support)
*                        @arg ECR_All_PowerOffset_P2 (If support)
*                        @arg ECR_All_PowerOffset_Q1 (If support)
*                        @arg ECR_All_PowerOffset_Q2 (If support)
*                        @arg ECR_Fund_PowerOffset_P1(If support)
*                        @arg ECR_Fund_PowerOffset_P2(If support)
*                        @arg ECR_Fund_PowerOffset_Q1(If support)
*                        @arg ECR_Fund_PowerOffset_Q2(If support)
*                        @arg ECR_Har_PowerOffset_P1 (If support)
*                        @arg ECR_Har_PowerOffset_P2 (If support)

* @retval: power offset data, limits: signed, symbol bits are bit31~23, data bits are bit22~0
*
* @note  : 
*********************************************************************************************************
*/
int32_t HT_EMU_PowerOffsetGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWEROFFSET_SEL(Channel));          /*  assert_param  */

	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_PowerOffset_Pa:
			ultemp=HT_EMUECA->All_PowerOffset_Pa ;
			break;
		case ECR_All_PowerOffset_Pb:
			ultemp=HT_EMUECA->All_PowerOffset_Pb ;
			break;
		case ECR_All_PowerOffset_Pc:
			ultemp=HT_EMUECA->All_PowerOffset_Pc ;
			break;
		case ECR_All_PowerOffset_Qa:
			ultemp=HT_EMUECA->All_PowerOffset_Qa ;
			break;
		case ECR_All_PowerOffset_Qb:
			ultemp=HT_EMUECA->All_PowerOffset_Qb ;
			break;
		case ECR_All_PowerOffset_Qc:
			ultemp=HT_EMUECA->All_PowerOffset_Qc ;
			break;
		case ECR_Fund_PowerOffset_Pa:
			ultemp=HT_EMUECA->Fund_PowerOffset_Pa;
			break;
		case ECR_Fund_PowerOffset_Pb:
			ultemp=HT_EMUECA->Fund_PowerOffset_Pb;
			break;
		case ECR_Fund_PowerOffset_Pc:
			ultemp=HT_EMUECA->Fund_PowerOffset_Pc;
			break;		
		case ECR_Fund_PowerOffset_Qa:
			ultemp=HT_EMUECA->Fund_PowerOffset_Qa;
			break;
		case ECR_Fund_PowerOffset_Qb:
			ultemp=HT_EMUECA->Fund_PowerOffset_Qb;
			break;
		case ECR_Fund_PowerOffset_Qc:
			ultemp=HT_EMUECA->Fund_PowerOffset_Qc;
			break;
		case ECR_Har_PowerOffset_Pa:
			ultemp=HT_EMUECA->Har_PowerOffset_Pa;
			break;
		case ECR_Har_PowerOffset_Pb:
			ultemp=HT_EMUECA->Har_PowerOffset_Pb;
			break;
		case ECR_Har_PowerOffset_Pc:
			ultemp=HT_EMUECA->Har_PowerOffset_Pc;
			break;
	#else
		case ECR_All_PowerOffset_P1:
			ultemp = HT_EMUECA->All_PowerOffset_P1;
			break;
		case ECR_All_PowerOffset_P2:
			ultemp = HT_EMUECA->All_PowerOffset_P2;
			break;
		case ECR_All_PowerOffset_Q1:
			ultemp = HT_EMUECA->All_PowerOffset_Q1;
			break;
		case ECR_All_PowerOffset_Q2:
			ultemp = HT_EMUECA->All_PowerOffset_Q2;
			break;
		case ECR_Fund_PowerOffset_P1:
			ultemp = HT_EMUECA->Fund_PowerOffset_P1;
			break;
		case ECR_Fund_PowerOffset_P2:
			ultemp = HT_EMUECA->Fund_PowerOffset_P2;
			break;		
		case ECR_Fund_PowerOffset_Q1:
			ultemp = HT_EMUECA->Fund_PowerOffset_Q1;
			break;
		case ECR_Fund_PowerOffset_Q2:
			ultemp = HT_EMUECA->Fund_PowerOffset_Q2;
			break;
		case ECR_Har_PowerOffset_P1:
			ultemp = HT_EMUECA->Har_PowerOffset_P1;
			break;
		case ECR_Har_PowerOffset_P2:
			ultemp = HT_EMUECA->Har_PowerOffset_P2;
			break;	
	#endif		
		default:
			break;	
	}

	ultemp &= ECR_24BIT_DATA;
	if(ultemp & ECR_EMU_PowerOffset_Symbol)
	{
		ultemp |= ECR_EMU_PowerOffset_Signed;
	
	}
	
	return ((int32_t)ultemp);

}
/**
*********************************************************************************************************
*                                       SET EMU RMSOffset
*
* @brief : set EMU module all/fund/total har rms offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_RmsOffset_Ua (If support)
*                        @arg ECR_All_RmsOffset_Ub (If support)
*                        @arg ECR_All_RmsOffset_Uc (If support)
*                        @arg ECR_All_RmsOffset_Ia (If support)
*                        @arg ECR_All_RmsOffset_Ib (If support)
*                        @arg ECR_All_RmsOffset_Ic (If support)
*                        @arg ECR_All_RmsOffset_In (If support)
*                        @arg ECR_RMSOffset_Ut     (If support)
*                        @arg ECR_RMSOffset_It     
*                        @arg ECR_Fund_RmsOffset_Ua(If support)
*                        @arg ECR_Fund_RmsOffset_Ub(If support)
*                        @arg ECR_Fund_RmsOffset_Uc(If support)
*                        @arg ECR_Fund_RmsOffset_Ia(If support)
*                        @arg ECR_Fund_RmsOffset_Ib(If support)
*                        @arg ECR_Fund_RmsOffset_Ic(If support)
*                        @arg ECR_Fund_RmsOffset_In(If support)
*                        @arg ECR_Har_RmsOffset_Ua (If support)
*                        @arg ECR_Har_RmsOffset_Ub (If support)
*                        @arg ECR_Har_RmsOffset_Uc (If support)
*                        @arg ECR_Har_RmsOffset_Ia (If support)
*                        @arg ECR_Har_RmsOffset_Ib (If support)
*                        @arg ECR_Har_RmsOffset_Ic (If support)
*                        @arg ECR_Har_RmsOffset_In (If support)
*
*                        @arg ECR_All_RmsOffset_U  (If support)
*                        @arg ECR_All_RmsOffset_I1 (If support)
*                        @arg ECR_All_RmsOffset_I2 (If support)
*                        @arg ECR_Fund_RmsOffset_U (If support)
*                        @arg ECR_Fund_RmsOffset_I1(If support)
*                        @arg ECR_Fund_RmsOffset_I2(If support)
*                        @arg ECR_Har_RmsOffset_U  (If support)
*                        @arg ECR_Har_RmsOffset_I1 (If support)
*                        @arg ECR_Har_RmsOffset_I2 (If support)
*
* @param : data: rms offset data, 24bits,unsigned, limits<=0xffffff
*
* @retval: none
*
* @note  : used to calibrate offset for all/fund/total har wave power
*********************************************************************************************************
*/
void HT_EMU_RMSOffsetSet(uint32_t Channel,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  									/* Get Write Protect */ 	

	assert_param(IS_HT_EMU_RMSOFFSET_SEL(Channel));          					/*  assert_param  */
	assert_param(IS_HT_EMU_RMSOFFSET_LIMIT(data));
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  								/* Close write protect*/
	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_RmsOffset_Ua:
			HT_EMUECA->All_RmsOffset_Ua = data;
			break;
		case ECR_All_RmsOffset_Ub:
			HT_EMUECA->All_RmsOffset_Ub = data;
			break;
		case ECR_All_RmsOffset_Uc:
			HT_EMUECA->All_RmsOffset_Uc = data;
			break;
		case ECR_All_RmsOffset_Ia:
			HT_EMUECA->All_RmsOffset_Ia = data;
			break;
		case ECR_All_RmsOffset_Ib:
			HT_EMUECA->All_RmsOffset_Ib = data;
			break;
		case ECR_All_RmsOffset_Ic:
			HT_EMUECA->All_RmsOffset_Ic = data;
			break;
		case ECR_All_RmsOffset_In:
			HT_EMUECA->All_RmsOffset_In = data;
			break;
		case ECR_RMSOffset_Ut:
			HT_EMUECA->RMSOffset_Ut = data;
			break;
		case ECR_RMSOffset_It:
			HT_EMUECA->RMSOffset_It = data;
			break;
		case ECR_Fund_RmsOffset_Ua:
			HT_EMUECA->Fund_RmsOffset_Ua = data;
			break;
		case ECR_Fund_RmsOffset_Ub:
			HT_EMUECA->Fund_RmsOffset_Ub = data;
			break;
		case ECR_Fund_RmsOffset_Uc:
			HT_EMUECA->Fund_RmsOffset_Uc = data;
			break;
		case ECR_Fund_RmsOffset_Ia:
			HT_EMUECA->Fund_RmsOffset_Ia = data;
			break;
		case ECR_Fund_RmsOffset_Ib:
			HT_EMUECA->Fund_RmsOffset_Ib = data;
			break;
		case ECR_Fund_RmsOffset_Ic:
			HT_EMUECA->Fund_RmsOffset_Ic = data;
			break;
		case ECR_Fund_RmsOffset_In:
			HT_EMUECA->Fund_RmsOffset_In = data;
			break;
		case ECR_Har_RmsOffset_Ua:
			HT_EMUECA->Har_RmsOffset_Ua = data;
			break;
		case ECR_Har_RmsOffset_Ub:
			HT_EMUECA->Har_RmsOffset_Ub = data;
			break;		
		case ECR_Har_RmsOffset_Uc:
			HT_EMUECA->Har_RmsOffset_Uc = data;
			break;	
		case ECR_Har_RmsOffset_Ia:
			HT_EMUECA->Har_RmsOffset_Ia = data;
			break;
		case ECR_Har_RmsOffset_Ib:
			HT_EMUECA->Har_RmsOffset_Ib = data;
			break;
		case ECR_Har_RmsOffset_Ic:
			HT_EMUECA->Har_RmsOffset_Ic = data;
			break;	
		case ECR_Har_RmsOffset_In:
			HT_EMUECA->Har_RmsOffset_In = data;
			break;
	#else
		case ECR_All_RmsOffset_U:
			HT_EMUECA->All_RmsOffset_U = data;
			break;
		case ECR_All_RmsOffset_I1:
			HT_EMUECA->All_RmsOffset_I1 = data;
			break;
		case ECR_All_RmsOffset_I2:
			HT_EMUECA->All_RmsOffset_I2 = data;
			break;
		case ECR_RMSOffset_It:
			HT_EMUECA->RMSOffset_It = data;
			break;
		case ECR_Fund_RmsOffset_U:
			HT_EMUECA->Fund_RmsOffset_U = data;
			break;
		case ECR_Fund_RmsOffset_I1:
			HT_EMUECA->Fund_RmsOffset_I1 = data;
			break;
		case ECR_Fund_RmsOffset_I2:
			HT_EMUECA->Fund_RmsOffset_I2 = data;
			break;
		case ECR_Har_RmsOffset_U:
			HT_EMUECA->Har_RmsOffset_U = data;
			break;	
		case ECR_Har_RmsOffset_I1:
			HT_EMUECA->Har_RmsOffset_I1 = data;
			break;
		case ECR_Har_RmsOffset_I2:
			HT_EMUECA->Har_RmsOffset_I2 = data;
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
	
	

}
/**
*********************************************************************************************************
*                                       GET EMU RMSOffset
*
* @brief : get EMU module all/fund/total har rms offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_All_RmsOffset_Ua (If support)
*                        @arg ECR_All_RmsOffset_Ub (If support)
*                        @arg ECR_All_RmsOffset_Uc (If support)
*                        @arg ECR_All_RmsOffset_Ia (If support)
*                        @arg ECR_All_RmsOffset_Ib (If support)
*                        @arg ECR_All_RmsOffset_Ic (If support)
*                        @arg ECR_All_RmsOffset_In (If support)
*                        @arg ECR_RMSOffset_Ut     (If support)
*                        @arg ECR_RMSOffset_It     
*                        @arg ECR_Fund_RmsOffset_Ua(If support)
*                        @arg ECR_Fund_RmsOffset_Ub(If support)
*                        @arg ECR_Fund_RmsOffset_Uc(If support)
*                        @arg ECR_Fund_RmsOffset_Ia(If support)
*                        @arg ECR_Fund_RmsOffset_Ib(If support)
*                        @arg ECR_Fund_RmsOffset_Ic(If support)
*                        @arg ECR_Fund_RmsOffset_In(If support)
*                        @arg ECR_Har_RmsOffset_Ua (If support)
*                        @arg ECR_Har_RmsOffset_Ub (If support)
*                        @arg ECR_Har_RmsOffset_Uc (If support)
*                        @arg ECR_Har_RmsOffset_Ia (If support)
*                        @arg ECR_Har_RmsOffset_Ib (If support)
*                        @arg ECR_Har_RmsOffset_Ic (If support)
*                        @arg ECR_Har_RmsOffset_In (If support)
*
*                        @arg ECR_All_RmsOffset_U  (If support)
*                        @arg ECR_All_RmsOffset_I1 (If support)
*                        @arg ECR_All_RmsOffset_I2 (If support)
*                        @arg ECR_Fund_RmsOffset_U (If support)
*                        @arg ECR_Fund_RmsOffset_I1(If support)
*                        @arg ECR_Fund_RmsOffset_I2(If support)
*                        @arg ECR_Har_RmsOffset_U  (If support)
*                        @arg ECR_Har_RmsOffset_I1 (If support)
*                        @arg ECR_Har_RmsOffset_I2 (If support)
*
* @retval: rms offset data, 24bits,unsigned, limits<=0xffffff
*
* @note  : used to calibrate offset for all/fund/total har wave power
*********************************************************************************************************
*/
uint32_t HT_EMU_RMSOffsetGet(uint32_t Channel)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_RMSOFFSET_SEL(Channel));          /*  assert_param  */

	switch(Channel)
	{
	#if defined  HT762x
		case ECR_All_RmsOffset_Ua:
			ultemp=HT_EMUECA->All_RmsOffset_Ua ;
			break;
		case ECR_All_RmsOffset_Ub:
			ultemp=HT_EMUECA->All_RmsOffset_Ub ;
			break;
		case ECR_All_RmsOffset_Uc:
			ultemp=HT_EMUECA->All_RmsOffset_Uc ;
			break;
		case ECR_All_RmsOffset_Ia:
			ultemp=HT_EMUECA->All_RmsOffset_Ia ;
			break;
		case ECR_All_RmsOffset_Ib:
			ultemp=HT_EMUECA->All_RmsOffset_Ib ;
			break;
		case ECR_All_RmsOffset_Ic:
			ultemp=HT_EMUECA->All_RmsOffset_Ic ;
			break;
		case ECR_All_RmsOffset_In:
			ultemp=HT_EMUECA->All_RmsOffset_In;
			break;
		case ECR_RMSOffset_Ut:
			ultemp=HT_EMUECA->RMSOffset_Ut;
			break;
		case ECR_RMSOffset_It:
			ultemp=HT_EMUECA->RMSOffset_It;
			break;		
		case ECR_Fund_RmsOffset_Ua:
			ultemp=HT_EMUECA->Fund_RmsOffset_Ua;
			break;
		case ECR_Fund_RmsOffset_Ub:
			ultemp=HT_EMUECA->Fund_RmsOffset_Ub;
			break;
		case ECR_Fund_RmsOffset_Uc:
			ultemp=HT_EMUECA->Fund_RmsOffset_Uc;
			break;
		case ECR_Fund_RmsOffset_Ia:
			ultemp=HT_EMUECA->Fund_RmsOffset_Ia;
			break;
		case ECR_Fund_RmsOffset_Ib:
			ultemp=HT_EMUECA->Fund_RmsOffset_Ib;
			break;
		case ECR_Fund_RmsOffset_Ic:
			ultemp=HT_EMUECA->Fund_RmsOffset_Ic;
			break;
		case ECR_Fund_RmsOffset_In:
			ultemp=HT_EMUECA->Fund_RmsOffset_In;
			break;		
		case ECR_Har_RmsOffset_Ua:
			ultemp=HT_EMUECA->Har_RmsOffset_Ua;
			break;		
		case ECR_Har_RmsOffset_Ub:
			ultemp=HT_EMUECA->Har_RmsOffset_Ub;
			break;			
		case ECR_Har_RmsOffset_Uc:
			ultemp=HT_EMUECA->Har_RmsOffset_Uc;
			break;
		case ECR_Har_RmsOffset_Ia:
			ultemp=HT_EMUECA->Har_RmsOffset_Ia;
			break;
		case ECR_Har_RmsOffset_Ib:
			ultemp=HT_EMUECA->Har_RmsOffset_Ib;
			break;		
		case ECR_Har_RmsOffset_Ic:
			ultemp=HT_EMUECA->Har_RmsOffset_Ic;
			break;			
		case ECR_Har_RmsOffset_In:
			ultemp=HT_EMUECA->Har_RmsOffset_In;
			break;
	#else
		case ECR_All_RmsOffset_U:
			ultemp = HT_EMUECA->All_RmsOffset_U;
			break;
		case ECR_All_RmsOffset_I1:
			ultemp = HT_EMUECA->All_RmsOffset_I1;
			break;
		case ECR_All_RmsOffset_I2:
			ultemp = HT_EMUECA->All_RmsOffset_I2;
			break;
		case ECR_RMSOffset_It:
			ultemp = HT_EMUECA->RMSOffset_It;
			break;
		case ECR_Fund_RmsOffset_U:
			ultemp = HT_EMUECA->Fund_RmsOffset_U;
			break;
		case ECR_Fund_RmsOffset_I1:
			ultemp = HT_EMUECA->Fund_RmsOffset_I1;
			break;
		case ECR_Fund_RmsOffset_I2:
			ultemp = HT_EMUECA->Fund_RmsOffset_I2;
			break;
		case ECR_Har_RmsOffset_U:
			ultemp = HT_EMUECA->Har_RmsOffset_U;
			break;	
		case ECR_Har_RmsOffset_I1:
			ultemp = HT_EMUECA->Har_RmsOffset_I1;
			break;
		case ECR_Har_RmsOffset_I2:
			ultemp = HT_EMUECA->Har_RmsOffset_I2;
			break;	
	#endif
		default:
			break;	
	}
	ultemp &=ECR_24BIT_DATA;
	
	return ultemp;
}
/**
*********************************************************************************************************
*                                       SET EMU PowerConst
*
* @brief : set EMU module Energy channel Power Const 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_PowerConst_All_Pa  (If support)
*                        @arg ECR_PowerConst_All_Pb  (If support)
*                        @arg ECR_PowerConst_All_Pc  (If support)   	 
*                        @arg ECR_PowerConst_All_Pt  
*                        @arg ECR_PowerConst_All_Qa  (If support)
*                        @arg ECR_PowerConst_All_Qb  (If support)
*                        @arg ECR_PowerConst_All_Qc  (If support)
*                        @arg ECR_PowerConst_All_Qt  
*                        @arg ECR_PowerConst_Sa      (If support)
*                        @arg ECR_PowerConst_Sb      (If support)
*                        @arg ECR_PowerConst_Sc      (If support)
*                        @arg ECR_PowerConst_St       
*                        @arg ECR_PowerConst_Fund_Pa (If support)
*                        @arg ECR_PowerConst_Fund_Pb (If support)
*                        @arg ECR_PowerConst_Fund_Pc (If support)
*                        @arg ECR_PowerConst_Fund_Pt 
*                        @arg ECR_PowerConst_Fund_Qa (If support)
*                        @arg ECR_PowerConst_Fund_Qb (If support)
*                        @arg ECR_PowerConst_Fund_Qc (If support) 
*                        @arg ECR_PowerConst_Fund_Qt 
*                        @arg ECR_PowerConst_Har_Pa  (If support)
*                        @arg ECR_PowerConst_Har_Pb  (If support)
*                        @arg ECR_PowerConst_Har_Pc  (If support)
*                        @arg ECR_PowerConst_Har_Pt  
*                        
*                        @arg ECR_PowerConst_All_P1  (If support)
*                        @arg ECR_PowerConst_All_P2  (If support)
*                        @arg ECR_PowerConst_All_Q1  (If support)
*                        @arg ECR_PowerConst_All_Q2  (If support)
*                        @arg ECR_PowerConst_S1      (If support)
*                        @arg ECR_PowerConst_S2      (If support)
*                        @arg ECR_PowerConst_Fund_P1 (If support)
*                        @arg ECR_PowerConst_Fund_P2 (If support)
*                        @arg ECR_PowerConst_Fund_Q1 (If support)
*                        @arg ECR_PowerConst_Fund_Q2 (If support)
*                        @arg ECR_PowerConst_Har_P1  (If support)
*                        @arg ECR_PowerConst_Har_P2  (If support)
*                        
*                                               
* @param : data:power gain data,32bit
*
* @retval: none
*
* @note  : used to calibrate power for all/fund/total har wave
*********************************************************************************************************
*/
void HT_EMU_PowerConstSet(uint32_t Channel,int32_t data)
{		
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					   /* Get Write Protect */ 
	uint32_t ultemp = 0U;  					 
	
	assert_param(IS_HT_EMU_POWERCONST_CHNNEL_SEL(Channel));        /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				   /* Close write protect*/
	
	ultemp = (uint32_t)data;  
	switch(Channel)
	{
		case ECR_PowerConst_All_Pt:
			HT_EMUECA->PowerConst_All_Pt = ultemp;
			break;
		case ECR_PowerConst_All_Qt:
			HT_EMUECA->PowerConst_All_Qt = ultemp;
			break;
		case ECR_PowerConst_St:
			HT_EMUECA->PowerConst_St = ultemp;
			break;		
		case ECR_PowerConst_Fund_Pt:
			HT_EMUECA->PowerConst_Fund_Pt = ultemp;
			break;
		case ECR_PowerConst_Fund_Qt:
			HT_EMUECA->PowerConst_Fund_Qt = ultemp;
			break;
		case ECR_PowerConst_Har_Pt:
			HT_EMUECA->PowerConst_Har_Pt = ultemp;
			break;	

	#if defined  HT762x
		case ECR_PowerConst_All_Pa:
			HT_EMUECA->PowerConst_All_Pa = ultemp;
			break;
		case ECR_PowerConst_All_Pb:
			HT_EMUECA->PowerConst_All_Pb = ultemp;
			break;
		case ECR_PowerConst_All_Pc:
			HT_EMUECA->PowerConst_All_Pc = ultemp;
			break;
		case ECR_PowerConst_All_Qa:
			HT_EMUECA->PowerConst_All_Qa = ultemp;
			break;
		case ECR_PowerConst_All_Qb:
			HT_EMUECA->PowerConst_All_Qb = ultemp;
			break;
		case ECR_PowerConst_All_Qc:
			HT_EMUECA->PowerConst_All_Qc = ultemp;
			break;
		case ECR_PowerConst_Sa:
			HT_EMUECA->PowerConst_Sa = ultemp;
			break;
		case ECR_PowerConst_Sb:
			HT_EMUECA->PowerConst_Sb = ultemp;
			break;
		case ECR_PowerConst_Sc:
			HT_EMUECA->PowerConst_Sc = ultemp;
			break;		
		case ECR_PowerConst_Fund_Pa:
			HT_EMUECA->PowerConst_Fund_Pa = ultemp;
			break;
		case ECR_PowerConst_Fund_Pb:
			HT_EMUECA->PowerConst_Fund_Pb = ultemp;
			break;
		case ECR_PowerConst_Fund_Pc:
			HT_EMUECA->PowerConst_Fund_Pc = ultemp;
			break;
		case ECR_PowerConst_Fund_Qa:
			HT_EMUECA->PowerConst_Fund_Qa = ultemp;
			break;
		case ECR_PowerConst_Fund_Qb:
			HT_EMUECA->PowerConst_Fund_Qb = ultemp;
			break;
		case ECR_PowerConst_Fund_Qc:
			HT_EMUECA->PowerConst_Fund_Qc = ultemp;
			break;
		case ECR_PowerConst_Har_Pa:
			HT_EMUECA->PowerConst_Har_Pa = ultemp;
			break;	
		case ECR_PowerConst_Har_Pb:
			HT_EMUECA->PowerConst_Har_Pb = ultemp;
			break;
		case ECR_PowerConst_Har_Pc:
			HT_EMUECA->PowerConst_Har_Pc = ultemp;
			break;
	#else
		case ECR_PowerConst_All_P1:
			HT_EMUECA->PowerConst_All_P1 = ultemp;
			break;
		case ECR_PowerConst_All_P2:
			HT_EMUECA->PowerConst_All_P2 = ultemp;
			break;
		case ECR_PowerConst_All_Q1:
			HT_EMUECA->PowerConst_All_Q1 = ultemp;
			break;
		case ECR_PowerConst_All_Q2:
			HT_EMUECA->PowerConst_All_Q2 = ultemp;
			break;
		case ECR_PowerConst_S1:
			HT_EMUECA->PowerConst_S1 = ultemp;
			break;
		case ECR_PowerConst_S2:
			HT_EMUECA->PowerConst_S2 = ultemp;
			break;
		case ECR_PowerConst_Fund_P1:
			HT_EMUECA->PowerConst_Fund_P1 = ultemp;
			break;
		case ECR_PowerConst_Fund_P2:
			HT_EMUECA->PowerConst_Fund_P2 = ultemp;
			break;
		case ECR_PowerConst_Fund_Q1:
			HT_EMUECA->PowerConst_Fund_Q1 = ultemp;
			break;
		case ECR_PowerConst_Fund_Q2:
			HT_EMUECA->PowerConst_Fund_Q2 = ultemp;
			break;
		case ECR_PowerConst_Har_P1:
			HT_EMUECA->PowerConst_Har_P1 = ultemp;
			break;	
		case ECR_PowerConst_Har_P2:
			HT_EMUECA->PowerConst_Har_P2 = ultemp;
			break;
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
*********************************************************************************************************
*                                       GET EMU PowerConst
*
* @brief : Get EMU module 24 channel Energy Power Const
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_PowerConst_All_Pa  (If support)
*                        @arg ECR_PowerConst_All_Pb  (If support)
*                        @arg ECR_PowerConst_All_Pc  (If support)   	 
*                        @arg ECR_PowerConst_All_Pt  
*                        @arg ECR_PowerConst_All_Qa  (If support)
*                        @arg ECR_PowerConst_All_Qb  (If support)
*                        @arg ECR_PowerConst_All_Qc  (If support)
*                        @arg ECR_PowerConst_All_Qt  
*                        @arg ECR_PowerConst_Sa      (If support)
*                        @arg ECR_PowerConst_Sb      (If support)
*                        @arg ECR_PowerConst_Sc      (If support)
*                        @arg ECR_PowerConst_St       
*                        @arg ECR_PowerConst_Fund_Pa (If support)
*                        @arg ECR_PowerConst_Fund_Pb (If support)
*                        @arg ECR_PowerConst_Fund_Pc (If support)
*                        @arg ECR_PowerConst_Fund_Pt 
*                        @arg ECR_PowerConst_Fund_Qa (If support)
*                        @arg ECR_PowerConst_Fund_Qb (If support)
*                        @arg ECR_PowerConst_Fund_Qc (If support) 
*                        @arg ECR_PowerConst_Fund_Qt 
*                        @arg ECR_PowerConst_Har_Pa  (If support)
*                        @arg ECR_PowerConst_Har_Pb  (If support)
*                        @arg ECR_PowerConst_Har_Pc  (If support)
*                        @arg ECR_PowerConst_Har_Pt  
*                        
*                        @arg ECR_PowerConst_All_P1  (If support)
*                        @arg ECR_PowerConst_All_P2  (If support)
*                        @arg ECR_PowerConst_All_Q1  (If support)
*                        @arg ECR_PowerConst_All_Q2  (If support)
*                        @arg ECR_PowerConst_S1      (If support)
*                        @arg ECR_PowerConst_S2      (If support)
*                        @arg ECR_PowerConst_Fund_P1 (If support)
*                        @arg ECR_PowerConst_Fund_P2 (If support)
*                        @arg ECR_PowerConst_Fund_Q1 (If support)
*                        @arg ECR_PowerConst_Fund_Q2 (If support)
*                        @arg ECR_PowerConst_Har_P1  (If support)
*                        @arg ECR_PowerConst_Har_P2  (If support)
*                        
*
* @retval: data:power Const data,32bit
*
* @note  : used to calibrate 24 0r 18 channel self-define energy
*********************************************************************************************************
*/
int32_t HT_EMU_PowerConstGet(uint32_t Channel)
{		
	uint32_t ultemp = 0U;  					 
		
	assert_param(IS_HT_EMU_POWERCONST_CHNNEL_SEL(Channel));        /*  assert_param  */
		
	switch(Channel)
	{
		case ECR_PowerConst_All_Pt:
			ultemp = HT_EMUECA->PowerConst_All_Pt;
			break;
		case ECR_PowerConst_All_Qt:
			ultemp = HT_EMUECA->PowerConst_All_Qt;
			break;
		case ECR_PowerConst_St:
			ultemp = HT_EMUECA->PowerConst_St;
			break;		
		case ECR_PowerConst_Fund_Pt:
			ultemp = HT_EMUECA->PowerConst_Fund_Pt;
			break;
		case ECR_PowerConst_Fund_Qt:
			ultemp = HT_EMUECA->PowerConst_Fund_Qt;
			break;
		case ECR_PowerConst_Har_Pt:
			ultemp = HT_EMUECA->PowerConst_Har_Pt;
			break;
	
	#if defined  HT762x
		case ECR_PowerConst_All_Pa:
			ultemp = HT_EMUECA->PowerConst_All_Pa;
			break;
		case ECR_PowerConst_All_Pb:
			ultemp = HT_EMUECA->PowerConst_All_Pb;
			break;
		case ECR_PowerConst_All_Pc:
			ultemp = HT_EMUECA->PowerConst_All_Pc;
			break;
		case ECR_PowerConst_All_Qa:
			ultemp = HT_EMUECA->PowerConst_All_Qa;
			break;
		case ECR_PowerConst_All_Qb:
			ultemp = HT_EMUECA->PowerConst_All_Qb;
			break;
		case ECR_PowerConst_All_Qc:
			ultemp = HT_EMUECA->PowerConst_All_Qc;
			break;
		case ECR_PowerConst_Sa:
			ultemp = HT_EMUECA->PowerConst_Sa;
			break;
		case ECR_PowerConst_Sb:
			ultemp = HT_EMUECA->PowerConst_Sb;
			break;
		case ECR_PowerConst_Sc:
			ultemp = HT_EMUECA->PowerConst_Sc;
			break;		
		case ECR_PowerConst_Fund_Pa:
			ultemp = HT_EMUECA->PowerConst_Fund_Pa;
			break;
		case ECR_PowerConst_Fund_Pb:
			ultemp = HT_EMUECA->PowerConst_Fund_Pb;
			break;
		case ECR_PowerConst_Fund_Pc:
			ultemp = HT_EMUECA->PowerConst_Fund_Pc;
			break;
		case ECR_PowerConst_Fund_Qa:
			ultemp = HT_EMUECA->PowerConst_Fund_Qa;
			break;
		case ECR_PowerConst_Fund_Qb:
			ultemp = HT_EMUECA->PowerConst_Fund_Qb;
			break;
		case ECR_PowerConst_Fund_Qc:
			ultemp = HT_EMUECA->PowerConst_Fund_Qc;
			break;
		case ECR_PowerConst_Har_Pa:
			ultemp = HT_EMUECA->PowerConst_Har_Pa;
			break;	
		case ECR_PowerConst_Har_Pb:
			ultemp = HT_EMUECA->PowerConst_Har_Pb;
			break;
		case ECR_PowerConst_Har_Pc:
			ultemp = HT_EMUECA->PowerConst_Har_Pc;
			break;
	#else
		case ECR_PowerConst_All_P1:
			ultemp = HT_EMUECA->PowerConst_All_P1;
			break;
		case ECR_PowerConst_All_P2:
			ultemp = HT_EMUECA->PowerConst_All_P2;
			break;
		case ECR_PowerConst_All_Q1:
			ultemp = HT_EMUECA->PowerConst_All_Q1;
			break;
		case ECR_PowerConst_All_Q2:
			ultemp = HT_EMUECA->PowerConst_All_Q2;
			break;
		case ECR_PowerConst_S1:
			ultemp = HT_EMUECA->PowerConst_S1;
			break;
		case ECR_PowerConst_S2:
			ultemp = HT_EMUECA->PowerConst_S2;
			break;
		case ECR_PowerConst_Fund_P1:
			ultemp = HT_EMUECA->PowerConst_Fund_P1;
			break;
		case ECR_PowerConst_Fund_P2:
			ultemp = HT_EMUECA->PowerConst_Fund_P2;
			break;
		case ECR_PowerConst_Fund_Q1:
			ultemp = HT_EMUECA->PowerConst_Fund_Q1;
			break;
		case ECR_PowerConst_Fund_Q2:
			ultemp = HT_EMUECA->PowerConst_Fund_Q2;
			break;
		case ECR_PowerConst_Har_P1:
			ultemp = HT_EMUECA->PowerConst_Har_P1;
			break;	
		case ECR_PowerConst_Har_P2:
			ultemp = HT_EMUECA->PowerConst_Har_P2;
			break;
	#endif			
		default:
			break;	
	}

	return((int32_t)ultemp);
}
/**
*********************************************************************************************************
*                                       SET EMU HarAccuOffset
*
* @brief : set EMU module total har Energy positive and negitive channel offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_AccuOffset_Har_Pa_Pos(If support)
*                        @arg ECR_AccuOffset_Har_Pa_Neg(If support)
*                        @arg ECR_AccuOffset_Har_Pb_Pos(If support)    	 
*                        @arg ECR_AccuOffset_Har_Pb_Neg(If support)
*                        @arg ECR_AccuOffset_Har_Pc_Pos(If support)
*                        @arg ECR_AccuOffset_Har_Pc_Neg(If support)  
*                        @arg ECR_AccuOffset_Har_Pt_Pos
*                        @arg ECR_AccuOffset_Har_Pt_Neg
*
*                        @arg ECR_AccuOffset_Har_P1_Pos(If support)
*                        @arg ECR_AccuOffset_Har_P1_Neg(If support)
*                        @arg ECR_AccuOffset_Har_P2_Pos(If support)    	 
*                        @arg ECR_AccuOffset_Har_P2_Neg(If support)
*
* @param : data:total har energy offset data,32bit

* @retval: none
*
* @note  : used to calibrate total har Energy positive and negitive channel offset 
*          xxx_pos :data need >=0;xxxx_Neg:data need <=0
*********************************************************************************************************
*/
void HT_EMU_HarAccuOffsetSet(uint32_t Channel,int32_t data)
{		
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					      /* Get Write Protect */ 
	uint32_t ultemp = 0U;  					 
		
	assert_param(IS_HT_EMU_HARACCUOFFSET_CHNNEL_SEL(Channel));        /*  assert_param  */
			
	ultemp = (uint32_t)data;	
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_AccuOffset_Har_Pa_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pa_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_Pa_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pa_Neg = ultemp;
			break;
		case ECR_AccuOffset_Har_Pb_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pb_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_Pb_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pb_Neg = ultemp;
			break;
		case ECR_AccuOffset_Har_Pc_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pc_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_Pc_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pc_Neg = ultemp;
			break;
	#else
		case ECR_AccuOffset_Har_P1_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_P1_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_P1_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_P1_Neg = ultemp;
			break;
		case ECR_AccuOffset_Har_P2_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_P2_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_P2_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_P2_Neg = ultemp;
			break;	
	#endif
		case ECR_AccuOffset_Har_Pt_Pos:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pt_Pos = ultemp;
			break;
		case ECR_AccuOffset_Har_Pt_Neg:
			assert_param(IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(data));
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  				      /* Close write protect*/
			HT_EMUECA->AccuOffset_Har_Pt_Neg = ultemp;
			break;
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
*********************************************************************************************************
*                                       SET EMU HarAccuOffset
*
* @brief : set EMU module total har Energy positive and negitive channel offset 
*
* @param : Channel, This parameter can be one of the following values:
*                        @arg ECR_AccuOffset_Har_Pa_Pos(If support)
*                        @arg ECR_AccuOffset_Har_Pa_Neg(If support)
*                        @arg ECR_AccuOffset_Har_Pb_Pos(If support)    	 
*                        @arg ECR_AccuOffset_Har_Pb_Neg(If support)
*                        @arg ECR_AccuOffset_Har_Pc_Pos(If support)
*                        @arg ECR_AccuOffset_Har_Pc_Neg(If support)  
*                        @arg ECR_AccuOffset_Har_Pt_Pos
*                        @arg ECR_AccuOffset_Har_Pt_Neg
*
*                        @arg ECR_AccuOffset_Har_P1_Pos(If support)
*                        @arg ECR_AccuOffset_Har_P1_Neg(If support)
*                        @arg ECR_AccuOffset_Har_P2_Pos(If support)    	 
*                        @arg ECR_AccuOffset_Har_P2_Neg(If support)
*
*
* @retval: total har energy offset data,32bit
*
* @note  : used to calibrate total har Energy positive and negitive channel offset 
*********************************************************************************************************
*/
int32_t HT_EMU_HarAccuOffsetGet(uint32_t Channel)
{		
	uint32_t ultemp = 0U;  					 
		
	assert_param(IS_HT_EMU_HARACCUOFFSET_CHNNEL_SEL(Channel));        /*  assert_param  */
		
	switch(Channel)
	{
	#if defined  HT762x
		case ECR_AccuOffset_Har_Pa_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_Pa_Pos;
			break;
		case ECR_AccuOffset_Har_Pa_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_Pa_Neg;
			break;
		case ECR_AccuOffset_Har_Pb_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_Pb_Pos;
			break;
		case ECR_AccuOffset_Har_Pb_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_Pb_Neg;
			break;
		case ECR_AccuOffset_Har_Pc_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_Pc_Pos;
			break;
		case ECR_AccuOffset_Har_Pc_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_Pc_Neg;
			break;
	#else
		case ECR_AccuOffset_Har_P1_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_P1_Pos;
			break;
		case ECR_AccuOffset_Har_P1_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_P1_Neg;
			break;
		case ECR_AccuOffset_Har_P2_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_P2_Pos;
			break;
		case ECR_AccuOffset_Har_P2_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_P2_Neg;
			break;	
	#endif
		case ECR_AccuOffset_Har_Pt_Pos:
			ultemp = HT_EMUECA->AccuOffset_Har_Pt_Pos;
			break;
		case ECR_AccuOffset_Har_Pt_Neg:
			ultemp = HT_EMUECA->AccuOffset_Har_Pt_Neg;
			break;
		default:
			break;	
	}

	return((int32_t)ultemp);
}
/**
*********************************************************************************************************
*                                       READ  EMU ECR REGISTER CHKSUM REGISTER
*
* @brief: read emu module checksum
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg EPR_Checksum1	
*                        @arg EPR_Checksum2
*                        @arg EPR_Checksum3 		

*
* @retval: checksum,32 bit unsigned
*
* @note  : none
*********************************************************************************************************
*/
uint32_t HT_EMU_ChecksumGet(uint32_t Chanel)
{
  	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_CHECHSUM_CHANNEL_SEL(Chanel));       /*  assert_param  */

	switch(Chanel)
	{
		case EPR_Checksum1:
			ultemp = HT_EMUEPA->Chksum1;
			break;
		case EPR_Checksum2:
			ultemp = HT_EMUEPA->Chksum2;
			break;
		case EPR_Checksum3:
			ultemp = HT_EMUEPA->Chksum3;
			break;
		default:
			break;	
	}	
	return ultemp;

}


/**
********************************************************************************************************
*                                      Set EMU UCONST
* @brief : Set EMU Module voltage channel Constant   
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg ECR_UconstA(If support)	
*                        @arg ECR_UconstB(If support)
*                        @arg ECR_UconstC(If support) 		
*
*                        @arg ECR_Uconst (If support)
*
* @param : data:voltage Const data,23bit,limit <=0x7fffff
*
* @retval: none
*
* @note  : commonly used in low power mode,instead of all wave voltage rms to calculate apparent power
**********************************************************************************************************/
void HT_EMU_UConstSet(uint32_t Chanel,uint32_t data)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  				/* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_UCONST_CHANNEL_SEL(Chanel));     /*  assert_param  */
	assert_param(IS_HT_EMU_UCONST_LIMIT(data));             /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   			/* Close write protect*/
	
	switch(Chanel)
	{
	#if defined  HT762x
		case ECR_UconstA:
			HT_EMUECA->UconstA = data;
			break;
		case ECR_UconstB:
			HT_EMUECA->UconstB = data;
			break;
		case ECR_UconstC:
			HT_EMUECA->UconstC = data;
			break;
	#else
		case ECR_Uconst:
			HT_EMUECA->Uconst = data;
			HT_EMUECA->Uconst_BAK = data;
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Get EMU UCONST
* @brief : Get EMU Module voltage channel Constant   
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg ECR_UconstA(If support)	
*                        @arg ECR_UconstB(If support)
*                        @arg ECR_UconstC(If support) 		
*
*                        @arg ECR_Uconst (If support)
*
*
* @retval: voltage constant data,23bit,limit <=0x7fffff
*
* @note  : commonly used in low power mode,instead of all wave voltage rms to calculate apparent power
**********************************************************************************************************/
uint32_t HT_EMU_UConstGet(uint32_t Chanel)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_UCONST_CHANNEL_SEL(Chanel));       /*  assert_param  */

	switch(Chanel)
	{
	#if defined  HT762x
		case ECR_UconstA:
			ultemp = HT_EMUECA->UconstA;
			break;
		case ECR_UconstB:
			ultemp = HT_EMUECA->UconstB;
			break;
		case ECR_UconstC:
			ultemp = HT_EMUECA->UconstC;
			break;
	#else
		case ECR_Uconst:
			ultemp = HT_EMUECA->Uconst;
			break;	
	#endif
		default:
			break;	
	}
	
	ultemp &= ECR_23BIT_DATA;	
	return ultemp;
}

/**
********************************************************************************************************
*                                      Set EMU ZERO CROSS NUMBER
* @brief : set EMU module zero-cross max number
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ZXLostCFG_NumFund	
*               @arg ZXLostCFG_ZCNumMin
*               @arg ZXLostCFG_ZCNumMax 		
*
* @param: data: recommended data in user's manual book can be used£¬diffrent type select one of the 
*				Type = ZXLostCFG_ZCNumMax: zerocross max num data,9bit,limit <=0x1ff
*               Type = ZXLostCFG_ZCNumMin: zerocross min num data,9bit,limit <=0x1ff
*               Type = ZXLostCFG_NumFund:  fund wave zerocross valid num data,6bit,limit <= 0x3f
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ZxLostCFG_NumSet(uint32_t Type,uint32_t data)
{
	uint32_t ultemp = 0U;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  				/* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_ZXLOSTCFG_TYPE_SEL(Type));    	/*  assert_param  */
	
	
	ultemp = HT_EMUECA->ZXLostCFG;
	ultemp &= (~Type);
	switch(Type)
	{
		case ZXLostCFG_ZCNumMax:
			assert_param(IS_HT_EMU_ZCNUMMAX_LIMIT(data));    /*  assert_param  */				
			ultemp |= data;
			break;
		case ZXLostCFG_ZCNumMin:
			assert_param(IS_HT_EMU_ZCNUMMIN_LIMIT(data));    /*  assert_param  */	
			ultemp |= (data << 9U);
			break;
		case ZXLostCFG_NumFund:
			assert_param(IS_HT_EMU_ZCNUMFUND_LIMIT(data));    /*  assert_param  */
			ultemp |= (data << 18U);
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	HT_EMUECA->ZXLostCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        	  /* Restore Write Protect register */

}
/**
********************************************************************************************************
*                                      Set EMU POWER START
* @brief : set EMU module power start
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_PStart  
*               @arg ECR_QStart  
*               @arg ECR_HarStart 		
*
* @param : data: power start data 16bit,limit <=0xffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerStartSet(uint32_t Type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			  /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_POWERSTART_TYPE_SEL(Type));    /*  assert_param  */
	assert_param(IS_HT_EMU_POWERSTART_LIMIT(data));       /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		  /* Close write protect*/

	switch(Type)
	{
		case ECR_PStart:
			HT_EMUECA->PStart = data;
			break;
		case ECR_QStart:
			HT_EMUECA->QStart = data;
			break;
		case ECR_HarStart:
			HT_EMUECA->HarStart = data;
			break;
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */

}
/**
********************************************************************************************************
*                                      Get EMU POWER START
* @brief : Get EMU module power start
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_PStart  
*               @arg ECR_QStart  
*               @arg ECR_HarStart 		
*
*
* @retval: power start data 16bit,limit <=0xffff
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_PowerStartGet(uint32_t Type)
{	
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERSTART_TYPE_SEL(Type));    /*  assert_param  */
	
	switch(Type)
	{
		case ECR_PStart:
			ultemp = HT_EMUECA->PStart;
			break;
		case ECR_QStart:
			ultemp = HT_EMUECA->QStart;
			break;
		case ECR_HarStart:
			ultemp = HT_EMUECA->HarStart;
			break;
		default:
			break;	
	}
	
	ultemp &= ECR_16BIT_DATA;
	return ultemp;
}

/**
********************************************************************************************************
*                                      Set EMU AVG NUM
* @brief : set EMU module average module points
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_AVG_Energy  
*               @arg ECR_AVG_PowerREG
*               @arg ECR_AVG_RMS      		
*               @arg ECR_AVG_RMST     		
*
* @param : data: average pionts data 14bit,0x002d =< limit <= 0x2c88
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_AvgNumSet(uint32_t Type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  		  /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_AVGNUM_TYPE_SEL(Type));    /*  assert_param  */
	assert_param(IS_HT_EMU_AVGNUM_LIMIT(data));       /*  assert_param  */				
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   	  /* Close write protect*/
	
	switch(Type)
	{
		case ECR_AVG_Energy:
			HT_EMUECA->AVG_Energy = data;
			break;
		case ECR_AVG_PowerREG:
			HT_EMUECA->AVG_PowerREG = data;
			break;
		case ECR_AVG_RMS:
			HT_EMUECA->AVG_RMS = data;
			break;
		case ECR_AVG_RMST:
			HT_EMUECA->AVG_RMST = data;
			break;
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Get EMU AVG NUM
* @brief : Get EMU module average module points
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_AVG_Energy  
*               @arg ECR_AVG_PowerREG
*               @arg ECR_AVG_RMS      		
*               @arg ECR_AVG_RMST     		
*
*
* @retval: average pionts data 14bit,0x002d =< limit <= 0x2c88
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_AvgNumGet(uint32_t Type)
{	
	uint32_t ultemp = 0U;
	assert_param(IS_HT_EMU_AVGNUM_TYPE_SEL(Type));    /*  assert_param  */			
	
	switch(Type)
	{
		case ECR_AVG_Energy:
			ultemp = HT_EMUECA->AVG_Energy;
			break;
		case ECR_AVG_PowerREG:
			ultemp = HT_EMUECA->AVG_PowerREG;
			break;
		case ECR_AVG_RMS:
			ultemp = HT_EMUECA->AVG_RMS;
			break;
		case ECR_AVG_RMST:
			ultemp = HT_EMUECA->AVG_RMST;
			break;
		default:
			break;	
	}
	
	ultemp &= ECR_14BIT_DATA;
	return ultemp;

}
/**
********************************************************************************************************
*                                      Set EMU HFCONST
* @brief : set EMU module HFConst
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_HFConstAF 
*               @arg ECR_HFConstHar
*
* @param : data: HFConst data 20bit,0x0002 =< limit <= 0xfffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_HFConstSet(uint32_t Type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_HFCONST_TYPE_SEL(Type));    /*  assert_param  */
	assert_param(IS_HT_EMU_HFCONST_LIMIT(data));       /*  assert_param  */	
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/	
	
	switch(Type)
	{
		case ECR_HFConstAF:
			HT_EMUECA->HFConstAF = data;
			break;
		case ECR_HFConstHar:
			HT_EMUECA->HFConstHar = data;
			break;
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Get EMU HFCONST
* @brief : Get EMU module HFConst
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_HFConstAF 
*               @arg ECR_HFConstHar
*
*
* @retval: HFConst data 20bit,0x0002 =< limit <= 0xfffff
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_HFConstGet(uint32_t Type)
{	
	uint32_t ultemp = 0U;
	assert_param(IS_HT_EMU_HFCONST_TYPE_SEL(Type));    /*  assert_param  */
	
	switch(Type)
	{
		case ECR_HFConstAF:
			ultemp = HT_EMUECA->HFConstAF;
			break;
		case ECR_HFConstHar:
			ultemp = HT_EMUECA->HFConstHar;
			break;
		default:
			break;	
	}

	ultemp &= ECR_20BIT_DATA;
	return ultemp;
}
/**
********************************************************************************************************
*                                      Set EMU AFDIV
* @brief : set EMU module AFDIV
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_AFDIV 
*               @arg ECR_HarDIV
*
* @param: data: AFDIV data 15bit,0x0001 =< limit <= 0x7fff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_AFDIVSet(uint32_t Type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;        /* Get Write Protect */ 

	assert_param(IS_HT_EMU_AFDIV_TYPE_SEL(Type));    /*  assert_param  */
	assert_param(IS_HT_EMU_AFDIV_LIMIT(data));       /*  assert_param  */				

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);      /* Close write protect*/	
		
	switch(Type)
	{
		case ECR_AFDIV:
			HT_EMUECA->AFDIV = data;
			break;
		case ECR_HarDIV:
			HT_EMUECA->HarDIV = data;
			break;
		default:
			break;	
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Get EMU AFDIV
* @brief : Get EMU module AFDIV
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ECR_AFDIV 
*               @arg ECR_HarDIV
*
*
* @retval: AFDIV data 15bit,0x0001 =< limit <= 0x7fff
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_AFDIVGet(uint32_t Type)
{
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_AFDIV_TYPE_SEL(Type));    /*  assert_param  */
	
	switch(Type)
	{
		case ECR_AFDIV:
			ultemp = HT_EMUECA->AFDIV;
			break;
		case ECR_HarDIV:
			ultemp = HT_EMUECA->HarDIV;
			break;
		default:
			break;	
	}
	
	ultemp &= ECR_15BIT_DATA;
	return ultemp;
}       
#if defined  HT762x      
/**
********************************************************************************************************
*                                      Set EMU ANSI MODE
* @brief : set EMU module ANSI MODE
*
* @param : select
*  		  This parameter can be one of the following values:
*               @arg ChannelSel_ANSI_Mode_NoChange  
*               @arg ChannelSel_ANSI_Mode_UbChange1 
*               @arg ChannelSel_ANSI_Mode_UbChange2 
*               @arg ChannelSel_ANSI_Mode_UbUcChange
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ChnSel_AnsiModeSet(uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 

	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ANSIMODE_SEL(select));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);      /* Close write protect*/
	
	ultemp = HT_EMUECA->ChannelSel;
	ultemp &= (~ChannelSel_ANSI_Mode);	
	ultemp |= select;
	
	HT_EMUECA->ChannelSel = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}  
#endif
/**
********************************************************************************************************
*                                      Set EMU CHANNEL SELECT
* @brief : set EMU module chennel select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ChannelSel_UaSel (If support)	
*               @arg ChannelSel_UbSel (If support)
*               @arg ChannelSel_UcSel (If support)	
*               @arg ChannelSel_IaSel (If support)
*               @arg ChannelSel_IbSel (If support)
*               @arg ChannelSel_IcSel (If support)		
*               @arg ChannelSel_InSel (If support)	
*
*               @arg ChannelSel_USel  (If support)
*               @arg ChannelSel_I1Sel (If support)
*               @arg ChannelSel_I2Sel (If support)
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values
*				Channel = ChannelSel_UaSel: 
*								@arg ChannelSel_UaSel_Ua
*								@arg ChannelSel_UaSel_Ub
*								@arg ChannelSel_UaSel_Uc
*								
*				Channel = ChannelSel_UbSel: 
*								@arg ChannelSel_UbSel_Ua
*								@arg ChannelSel_UbSel_Ub
*								@arg ChannelSel_UbSel_Uc
*								
*				Channel = ChannelSel_UcSel: 
*								@arg ChannelSel_UcSel_Ua
*								@arg ChannelSel_UcSel_Ub
*								@arg ChannelSel_UcSel_Uc
*								
*				Channel = ChannelSel_IaSel: 
*								@arg ChannelSel_IaSel_Ia
*								@arg ChannelSel_IaSel_Ib
*								@arg ChannelSel_IaSel_Ic
*								@arg ChannelSel_IaSel_In
*								
*				Channel = ChannelSel_IbSel: 
*								@arg ChannelSel_IbSel_Ia
*								@arg ChannelSel_IbSel_Ib
*								@arg ChannelSel_IbSel_Ic
*								@arg ChannelSel_IbSel_In
*								
*				Channel = ChannelSel_IcSel: 
*								@arg ChannelSel_IcSel_Ia
*								@arg ChannelSel_IcSel_Ib
*								@arg ChannelSel_IcSel_Ic
*								@arg ChannelSel_IcSel_In
*								
*				Channel = ChannelSel_InSel: 
*								@arg ChannelSel_InSel_Ia
*								@arg ChannelSel_InSel_Ib
*								@arg ChannelSel_InSel_Ic
*								@arg ChannelSel_InSel_In
*								
*				Channel = ChannelSel_USel: 
*								@arg ChannelSel_USel_U
*
*				Channel = ChannelSel_I1Sel: 
*								@arg ChannelSel_I1Sel_I1
*								@arg ChannelSel_I1Sel_I2
*								
*				Channel = ChannelSel_I2Sel: 
*								@arg ChannelSel_I2Sel_I1
*								@arg ChannelSel_I2Sel_I2
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ChnSel_ChnSelSet(uint32_t Channel,uint32_t select)
{
	uint32_t ultemp = 0U;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_CHNSEL_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->ChannelSel;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
	#if defined  HT762x
		case ChannelSel_UaSel:
			assert_param(IS_HT_EMU_CHNSEL_UA_SEL(select));    /*  assert_param  */				
			break;
		case ChannelSel_UbSel:
			assert_param(IS_HT_EMU_CHNSEL_UB_SEL(select));    /*  assert_param  */	
			break;
		case ChannelSel_UcSel:
			assert_param(IS_HT_EMU_CHNSEL_UC_SEL(select));    /*  assert_param  */
			break;
		case ChannelSel_IaSel:
			assert_param(IS_HT_EMU_CHNSEL_IA_SEL(select));    /*  assert_param  */				
			break;
		case ChannelSel_IbSel:
			assert_param(IS_HT_EMU_CHNSEL_IB_SEL(select));    /*  assert_param  */	
			break;
		case ChannelSel_IcSel:
			assert_param(IS_HT_EMU_CHNSEL_IC_SEL(select));    /*  assert_param  */
			break;
		case ChannelSel_InSel:
			assert_param(IS_HT_EMU_CHNSEL_IN_SEL(select));    /*  assert_param  */
			break;
	#else
		case ChannelSel_USel:
			assert_param(IS_HT_EMU_CHNSEL_U_SEL(select));    /*  assert_param  */
			ultemp &= (~ChannelSel_UBakSel);
			ultemp |= ChannelSel_UBakSel_U;			
			break;
		case ChannelSel_I1Sel:
			assert_param(IS_HT_EMU_CHNSEL_I1_SEL(select));    /*  assert_param  */				
			break;
		case ChannelSel_I2Sel:
			assert_param(IS_HT_EMU_CHNSEL_I2_SEL(select));    /*  assert_param  */	
			break;

	#endif
		default:
			break;	
	}
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);              /* Close write protect*/
	ultemp |= select;
	HT_EMUECA->ChannelSel = ultemp;
	
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU UCONST
* @brief : Set EMU Module voltage channel Constant   
*
* @param : Chanel
*  		  This parameter can be one or a combination of the following values:
*                        @arg ChannelSel_UcRev_EN(If support)	
*                        @arg ChannelSel_UbRev_EN(If support)
*                        @arg ChannelSel_UaRev_EN(If support) 		
*                        @arg ChannelSel_InRev_EN(If support)	
*                        @arg ChannelSel_IcRev_EN(If support)
*                        @arg ChannelSel_IbRev_EN(If support) 		
*                        @arg ChannelSel_IaRev_EN(If support)	
*
*                        @arg ChannelSel_URev_EN (If support) 		
*                        @arg ChannelSel_I1Rev_EN(If support)	
*                        @arg ChannelSel_I2Rev_EN(If support)
*
* @param: NewState        = ENABLE£º  channel REV enable  
*                         = DISABLE£º channel REV disable
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ChnSel_ChnRevEnSet(uint32_t Chanel,FunctionalState NewState)
{
	uint32_t ultemp = Chanel;  					
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					/* Get Write Protect */ 

	assert_param(IS_HT_EMU_CHNREV_CHANNEL_SEL(Chanel));         /*  assert_param  */	
	assert_param(IS_FUNCTIONAL_STATE(NewState));   				/*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   				/* Close write protect*/
	
	#if defined  HT772x
	if(ChannelSel_URev_EN & Chanel)
	{
		ultemp |= ChannelSel_UBakRev_EN;
	}
	#endif	
    if(NewState != DISABLE)
    {
        HT_EMUECA->ChannelSel |= ultemp;               			/*!< enable EMU channel REV */
    }
    else
    {
        HT_EMUECA->ChannelSel &= (~ultemp);          			/*!< Disable EMU channel REV  */
    }
	HT_EMU_WPReg_Restore(ulProtect);        					/* Restore Write Protect register */
}


/**
********************************************************************************************************
*                                      Set EMU CHANNEL PGA SELECT
* @brief : set EMU module ADC Channel PGA select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg PGACON_PGAU	
*               @arg PGACON_PGAIa	(If support)
*               @arg PGACON_PGAIb 	(If support)
*               @arg PGACON_PGAIc	(If support)
*               @arg PGACON_PGAIn	(If support)
*
*               @arg PGACON_PGAI1	(If support)
*               @arg PGACON_PGAI2 	(If support)
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				Channel = PGACON_PGAU: voltage channel analog gain
*								@arg PGACON_PGAU_1
*								@arg PGACON_PGAU_2
*								@arg PGACON_PGAU_8
*								
*				Channel = PGACON_PGAIa: a phase current analog gain
*								@arg PGACON_PGAIa_1
*								@arg PGACON_PGAIa_2
*								@arg PGACON_PGAIa_8
*								@arg PGACON_PGAIa_16
*								
*				Channel = PGACON_PGAIb: b phase current analog gain
*								@arg PGACON_PGAIb_1
*								@arg PGACON_PGAIb_2
*								@arg PGACON_PGAIb_8
*								@arg PGACON_PGAIb_16
*								
*				Channel = PGACON_PGAIc: c phase current analog gain
*								@arg PGACON_PGAIc_1
*								@arg PGACON_PGAIc_2
*								@arg PGACON_PGAIc_8
*								@arg PGACON_PGAIc_16
*								
*				Channel = PGACON_PGAIn: n channel current analog gain
*								@arg PGACON_PGAIn_1
*								@arg PGACON_PGAIn_2
*								@arg PGACON_PGAIn_4
*								@arg PGACON_PGAIn_8								
*								@arg PGACON_PGAIn_16
*								@arg PGACON_PGAIn_24
*								@arg PGACON_PGAIn_32
*								
*				Channel = PGACON_PGAI2: channel 2 current analog gain
*								@arg PGACON_PGAI2_1
*								@arg PGACON_PGAI2_2
*								@arg PGACON_PGAI2_8
*								@arg PGACON_PGAI2_16
*								
*				Channel = PGACON_PGAI1: channel 1 current analog gain
*								@arg PGACON_PGAI1_1
*								@arg PGACON_PGAI1_2
*								@arg PGACON_PGAI1_4
*								@arg PGACON_PGAI1_8								
*								@arg PGACON_PGAI1_16
*								@arg PGACON_PGAI1_24
*								@arg PGACON_PGAI1_32
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PGACON_PGASet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;   		/* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PGA_CHANNEL_SEL(Channel));    /*  assert_param  */


	ultemp = HT_EMUECA->PGACON;
	ultemp &= (~Channel);
	switch(Channel)
	{
		case PGACON_PGAU:
			assert_param(IS_HT_EMU_CHNU_PGA_SEL(select));    /*  assert_param  */				
			break;
	#if defined  HT762x
		case PGACON_PGAIa:
			assert_param(IS_HT_EMU_CHNIA_PGA_SEL(select));    /*  assert_param  */	
			break;
		case PGACON_PGAIb:
			assert_param(IS_HT_EMU_CHNIB_PGA_SEL(select));    /*  assert_param  */
			break;
		case PGACON_PGAIc:
			assert_param(IS_HT_EMU_CHNIC_PGA_SEL(select));    /*  assert_param  */				
			break;
		case PGACON_PGAIn:
			assert_param(IS_HT_EMU_CHNIN_PGA_SEL(select));    /*  assert_param  */	
			break;
	#else
		case PGACON_PGAI1:
			assert_param(IS_HT_EMU_CHNI1_PGA_SEL(select));    /*  assert_param  */	
			break;
		case PGACON_PGAI2:
			assert_param(IS_HT_EMU_CHNI2_PGA_SEL(select));    /*  assert_param  */
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		 /* Close write protect*/
	
	ultemp |= select;
	HT_EMUECA->PGACON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU HPF ENABLE
* @brief : set EMU module HPF enable or disable 
*
* @param : Chanel
*  		  This parameter can be one or a combination of the following values:
*                        @arg ADCCFG_HPFON_U	
*                        @arg ADCCFG_HPFON_I
*                        @arg ADCCFG_HPFON_In 	(If support)	
*
* @param: NewState        = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_HpfEnSet(uint32_t Chanel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 

	assert_param(IS_HT_EMU_HPF_CHANNEL_SEL(Chanel));    /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));   		/*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= Chanel;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~Chanel);
	}
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU OSR Select
* @brief : set EMU module OSR select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_OSR_SEL_64	
*                        @arg ADCCFG_OSR_SEL_128
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_OSRSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_OSR_TYPE_SEL(Type));	  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_OSR_SEL);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU DEC COMPENSATION ENABLE
* @brief : set EMU module DEC compensation enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_DecCompEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_Deccomp_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_Deccomp_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU CLK Select
* @brief : set EMU module CLK select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_EMUClk_SEL_819K2
*                        @arg ADCCFG_EMUClk_SEL_1638K4
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_EmuClkSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_CLK_TYPE_SEL(Type));	  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_EMUClk_SEL);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU zero Cross Interrupt Source Select
* @brief : set EMU module zero Cross Interrupt Source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_ZCINTSrc_SEL_AfterHPF 
*                        @arg ADCCFG_ZCINTSrc_SEL_BeforeHPF
*                        @arg ADCCFG_ZCINTSrc_SEL_Fund     
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_ZcIntSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_ZCINTSRC_SEL(Type));	  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_ZCINTSrc_SEL);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU SPL Update Rate Select
* @brief : set EMU module SPL Update rate select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_SPL_1k6 
*                        @arg ADCCFG_SPL_3k2 
*                        @arg ADCCFG_SPL_6k4 
*                        @arg ADCCFG_SPL_12k8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_SplUpdateSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;    /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_SPLUPD_SEL(Type));	  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_SPL);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU Zero Cross Interupt Way Select
* @brief : set EMU module  Zero Cross Interupt way select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_ZCd_P  
*                        @arg ADCCFG_ZCd_N  
*                        @arg ADCCFG_ZCd_PN 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_ZcdSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;    /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ZCD_TYPE_SEL(Type));  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_ZCd);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU SPL Update Rate Select
* @brief : set EMU module SPL Update rate select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_WaveSel_BeforeHPF
*                        @arg ADCCFG_WaveSel_AfterHPF 
*                        @arg ADCCFG_WaveSel_AfterGain
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_SplWaveSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_SPLWAVE_SEL(Type));  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_WaveSel);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU AUTO TEMPERATURE COMPENSATION ENABLE
* @brief : set EMU module Automatic temperature compensation enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_AutoTCEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_Auto_Tc_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_Auto_Tc_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU DMA SOURCE Select
* @brief : set EMU module DMA source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_DMASrc_Sel_SPL        
*                        @arg ADCCFG_DMASrc_Sel_QuartRmsIns
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_DmaSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_DMASRC_SEL(Type));     /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_DMASrc_Sel);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU MODE 3P3 ENABLE
* @brief : set EMU module mode 3p3 enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_Mode3p3EnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  		   /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_MODE3P3_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_MODE3P3_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU System FREQ Select
* @brief : set EMU module system frequency select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_FreqSel_50Hz
*                        @arg ADCCFG_FreqSel_60Hz
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_SysFreqSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_SYSFREQ_SEL(Type));	  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_FreqSel);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU Zero Cross Source Select
* @brief : set EMU module  zero cross source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCFG_ZcSrSel_All 
*                        @arg ADCCFG_ZcSrSel_Fund
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCFG_ZcSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ZCSRC_SEL(Type));      /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCFG;
	ultemp &=(~ADCCFG_ZcSrSel);
	ultemp |= Type;
	
	HT_EMUECA->ADCCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU DIGTAL AND ANALOG CHANNEL ADC ENABLE
* @brief : set EMU module digtal and analog channel adc enable or disable 
*
* @param : DChn:digtal adc channel
*  		  This parameter can be one or a combination of the following values:
*                        @arg ADCCON_ADC_En_Ua (If support)
*                        @arg ADCCON_ADC_En_Ub (If support)
*                        @arg ADCCON_ADC_En_Uc (If support)
*                        @arg ADCCON_ADC_En_Ia (If support)
*                        @arg ADCCON_ADC_En_Ib (If support)
*                        @arg ADCCON_ADC_En_Ic (If support)
*                        @arg ADCCON_ADC_En_In (If support)
*
*                        @arg ADCCON_ADC_En_U  (If support)
*                        @arg ADCCON_ADC_En_I1 (If support)
*                        @arg ADCCON_ADC_En_I2 (If support)
*
* @param : AChn:analog adc channel
*  		  This parameter can be one or a combination of the following values:
*                        @arg ADCCON_ADCEn_ANA_Ua (If support)
*                        @arg ADCCON_ADCEn_ANA_Ub (If support)
*                        @arg ADCCON_ADCEn_ANA_Uc (If support)
*                        @arg ADCCON_ADCEn_ANA_Ia (If support)
*                        @arg ADCCON_ADCEn_ANA_Ib (If support)
*                        @arg ADCCON_ADCEn_ANA_Ic (If support)
*                        @arg ADCCON_ADCEn_ANA_In (If support)
*
*                        @arg ADCCON_ADCEn_ANA_U  (If support)
*                        @arg ADCCON_ADCEn_ANA_I1 (If support)
*                        @arg ADCCON_ADCEn_ANA_I2 (If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_AdcChnEnSet(uint32_t DChn,uint32_t AChn,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_DIGADC_CHANNEL_SEL(DChn));       /*  assert_param  */
	assert_param(IS_HT_EMU_ANAADC_CHANNEL_SEL(AChn));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));            /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   			/* Close write protect*/

	ultemp = DChn|AChn;
	#if defined  HT772x
	if(ADCCON_ADC_En_U == DChn)
	{
		ultemp |= ADCCON_ADC_En_UBak;
	}	
	#endif
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ultemp;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ultemp);
	}
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU DIGTAL CHANNEL ADC ENABLE
* @brief : set EMU module digtal channel adc enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination of the following values:
*                        @arg ADCCON_ADC_En_Ua (If support)
*                        @arg ADCCON_ADC_En_Ub (If support)
*                        @arg ADCCON_ADC_En_Uc (If support)
*                        @arg ADCCON_ADC_En_Ia (If support)
*                        @arg ADCCON_ADC_En_Ib (If support)
*                        @arg ADCCON_ADC_En_Ic (If support)
*                        @arg ADCCON_ADC_En_In (If support)
*
*                        @arg ADCCON_ADC_En_U  (If support)
*                        @arg ADCCON_ADC_En_I1 (If support)
*                        @arg ADCCON_ADC_En_I2 (If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_DigADCEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ultemp = Channel;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                  /* Get Write Protect */ 

	assert_param(IS_HT_EMU_DIGADC_CHANNEL_SEL(Channel));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));               /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   				/* Close write protect*/
#if defined  HT772x
	if(ADCCON_ADC_En_U == Channel)
	{
		ultemp |= ADCCON_ADC_En_UBak;
	}	
#endif
	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ultemp;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ultemp);
	}
	HT_EMU_WPReg_Restore(ulProtect);        					/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU ANALOG CHANNEL ADC ENABLE
* @brief : set EMU module analog channel adc enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg ADCCON_ADCEn_ANA_Ua (If support)
*                        @arg ADCCON_ADCEn_ANA_Ub (If support)
*                        @arg ADCCON_ADCEn_ANA_Uc (If support)
*                        @arg ADCCON_ADCEn_ANA_Ia (If support)
*                        @arg ADCCON_ADCEn_ANA_Ib (If support)
*                        @arg ADCCON_ADCEn_ANA_Ic (If support)
*                        @arg ADCCON_ADCEn_ANA_In (If support)
*
*                        @arg ADCCON_ADCEn_ANA_U  (If support)
*                        @arg ADCCON_ADCEn_ANA_I1 (If support)
*                        @arg ADCCON_ADCEn_ANA_I2 (If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_AnaADCEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  					/* Get Write Protect */ 

	assert_param(IS_HT_EMU_ANAADC_CHANNEL_SEL(Channel));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));               /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   				/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= Channel;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~Channel);
	}
	HT_EMU_WPReg_Restore(ulProtect);        					/* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU CT2 ENABLE
* @brief : set EMU module CT2 enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_CT2EnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));        /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ADCCON_CTdetEn;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ADCCON_CTdetEn);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU CT2 OSR Select
* @brief : set EMU module CT2 osr select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCON_CT2_OSR_16 
*                        @arg ADCCON_CT2_OSR_32
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_CT2OsrSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;

	assert_param(IS_HT_EMU_CT2OSR_SEL(Type));  /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect */
	
    ultemp = HT_EMUECA->ADCCON;
	ultemp &=(~ADCCON_CT2_OSR);
	ultemp |= Type;
	
	HT_EMUECA->ADCCON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU Phase Segement Source Select
* @brief : set EMU module Phase Segement Source  select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCON_Phase_Sel_All 
*                        @arg ADCCON_Phase_Sel_Fund
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_PhaseSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PHASESRC_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCON;
	ultemp &=(~ADCCON_Phase_Sel);
	ultemp |= Type;
	
	HT_EMUECA->ADCCON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU VOLTAGE PEAK ENABLE
* @brief : set EMU module voltage peak enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_UPeakEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;          /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);        /* Close write protect */

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ADCCON_PeakEn;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ADCCON_PeakEn);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU VOLTAGE SAG ENABLE
* @brief : set EMU module voltage sag enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_USagEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       	/*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);  		 /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ADCCON_SagEn;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ADCCON_SagEn);
	}
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU VOLTAGE INT ENABLE
* @brief : set EMU module voltage interrupt enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_UIntEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ADCCON_IntEn;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ADCCON_IntEn);
	}
	HT_EMU_WPReg_Restore(ulProtect);       				/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Current OverFlow ENABLE
* @brief : set EMU module Current OverFlow enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_IovEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;          /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCON |= ADCCON_IovEn;
	}
	else
	{
		HT_EMUECA->ADCCON &=(~ADCCON_IovEn);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Peak Sag INT IOV Source Select
* @brief : set EMU module Peak Sag INT IOV Source  select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ADCCON_PeakSagSrc_HVp 
*                        @arg ADCCON_PeakSagSrc_HRms
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ADCCON_PeakSagSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PEAKSAGSRC_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
    ultemp = HT_EMUECA->ADCCON;
	ultemp &=(~ADCCON_PeakSagSrc);
	ultemp |= Type;
	
	HT_EMUECA->ADCCON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU FUND CURRENT VECTOR RMS ENABLE
* @brief : set EMU module fund current vector rms enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_ItFundRmsEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG |= EMUCFG_ItFund_En;
	}
	else
	{
		HT_EMUECA->EMUCFG &=(~EMUCFG_ItFund_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU  FUND VOLTAGE VECTOR RMS ENABLE
* @brief : set EMU module fund voltage vector rms  sag enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_UtFundRmsEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG |= EMUCFG_UtFund_En;
	}
	else
	{
		HT_EMUECA->EMUCFG &=(~EMUCFG_UtFund_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU FUND LINE VOLTAGE RMS ENABLE
* @brief : set EMU module fund line voltage rms enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_UFundLRmsEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* GET Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));        /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);          /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG |= EMUCFG_FundLineU_En;
	}
	else
	{
		HT_EMUECA->EMUCFG &=(~EMUCFG_FundLineU_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU Power S Calculate Way Select
* @brief : set EMU module Power S Calculate Way select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EMUCFG_PowerSCal_Sel_PQS
*                        @arg EMUCFG_PowerSCal_Sel_RMS
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_PowerSCalSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;    /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERSCAL_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EMUCFG;
	ultemp &=(~EMUCFG_PowerSCal_Sel);
	ultemp |= Type;
	
	HT_EMUECA->EMUCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU 3P3 Mode UB RMS Calculate Way Select
* @brief : set EMU module 3p3 mode ub rms Calculate Way select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EMUCFG_UacSel_Ub     
*                        @arg EMUCFG_UacSel_UaSubUc
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_3P3UbRmsCalSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_3P3UBRMSCAL_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
    ultemp = HT_EMUECA->EMUCFG;
	ultemp &=(~EMUCFG_UacSel);
	ultemp |= Type;
	
	HT_EMUECA->EMUCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU CURRENT VECTOR SUM CHANNEL CONFIGUR
* @brief : set EMU module current vector sum channel configure 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg EMUCFG_ItCfgA (If support)
*                        @arg EMUCFG_ItCfgB (If support)
*                        @arg EMUCFG_ItCfgC (If support)
*                        @arg EMUCFG_ItCfgN (If support)
*
*                        @arg EMUCFG_ItCfg1 (If support)
*                        @arg EMUCFG_ItCfg2 (If support)
*
* @param: NewState       = ENABLE  : part in
*                        = DISABLE : not part in
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_ItCfgSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  				/* Get Write Protect */ 

	assert_param(IS_HT_EMU_ITCFG_CHANNEL_SEL(Channel));     /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));            /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		    /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG &=(~Channel);  					 /* 0: part in*/
	}
	else
	{
		HT_EMUECA->EMUCFG |= Channel;  						 /* 1: not part in*/
	}
	HT_EMU_WPReg_Restore(ulProtect);       					 /* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU VOLTAGE VECTOR SUM CHANNEL CONFIGUR
* @brief : set EMU module voltage vector sum channel configure 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg EMUCFG_UtCfgA 
*                        @arg EMUCFG_UtCfgB
*                        @arg EMUCFG_UtCfgC 
*
* @param: NewState       = ENABLE  :part in
*                        = DISABLE : not part in
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_UtCfgSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get Write Protect */ 

	assert_param(IS_HT_EMU_UTCFG_CHANNEL_SEL(Channel));         /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));                /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   				/* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG &=(~Channel);  /* 0: part in*/
	}
	else
	{
		HT_EMUECA->EMUCFG |= Channel;    /* 1: not part in*/
	}
	HT_EMU_WPReg_Restore(ulProtect);     /* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU EMU POWER VECTOR SUM CHANNEL CONFIGUR
* @brief : set EMU module ADC Channel PGA select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg EMUCFG_PtCfgA	(If support)
*               @arg EMUCFG_PtCfgB  (If support)
*               @arg EMUCFG_PtCfgC 	(If support)
*
*               @arg EMUCFG_PtCfg1	(If support)
*               @arg EMUCFG_PtCfg2  (If support)
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				Channel = EMUCFG_PtCfgA: 
*								@arg EMUCFG_PtCfgA_PartIn   
*								@arg EMUCFG_PtCfgA_RevPartIn
*								@arg EMUCFG_PtCfgA_NoPartIn 
*								
*				Channel = EMUCFG_PtCfgB: 
*								@arg EMUCFG_PtCfgB_PartIn   
*								@arg EMUCFG_PtCfgB_RevPartIn
*								@arg EMUCFG_PtCfgB_NoPartIn 
*								
*				Channel = EMUCFG_PtCfgC: 
*								@arg EMUCFG_PtCfgC_PartIn   
*								@arg EMUCFG_PtCfgC_RevPartIn
*								@arg EMUCFG_PtCfgC_NoPartIn 
*																
*				Channel = EMUCFG_PtCfg1: 
*								@arg EMUCFG_PtCfg1_PartIn   
*								@arg EMUCFG_PtCfg1_RevPartIn
*								@arg EMUCFG_PtCfg1_NoPartIn 
*								
*				Channel = EMUCFG_PtCfg2: 
*								@arg EMUCFG_PtCfg2_PartIn   
*								@arg EMUCFG_PtCfg2_RevPartIn
*								@arg EMUCFG_PtCfg2_NoPartIn 
*								
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_PtCfgSet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* GET Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PTCFG_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->EMUCFG;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
	#if defined  HT762x
		case EMUCFG_PtCfgA:
			assert_param(IS_HT_EMU_PTCFGA_SEL(select));    /*  assert_param  */				
			break;
		case EMUCFG_PtCfgB:
			assert_param(IS_HT_EMU_PTCFGB_SEL(select));    /*  assert_param  */	
			break;
		case EMUCFG_PtCfgC:
			assert_param(IS_HT_EMU_PTCFGC_SEL(select));    /*  assert_param  */
			break;
	#else
		case EMUCFG_PtCfg1:
			assert_param(IS_HT_EMU_PTCFG1_SEL(select));    /*  assert_param  */				
			break;
		case EMUCFG_PtCfg2:
			assert_param(IS_HT_EMU_PTCFG2_SEL(select));    /*  assert_param  */	
			break;	
	#endif
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/	
	
	ultemp |= select;
	HT_EMUECA->EMUCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU Automatic Angle Base Change ENABLE
* @brief : set EMU module  Automatic Angle Base Change enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_AutoAngBaseEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCFG |= EMUCFG_AutoAngBase_EN;  
	}
	else
	{
		HT_EMUECA->EMUCFG &=(~EMUCFG_AutoAngBase_EN);  
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU Angle Base Select
* @brief : set EMU module Angle Base select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EMUCFG_AngleBaseSel_Ua(If support)
*                        @arg EMUCFG_AngleBaseSel_Ub(If support)
*                        @arg EMUCFG_AngleBaseSel_Uc(If support)
*                        @arg EMUCFG_AngleBaseSel_Ia(If support)
*                        @arg EMUCFG_AngleBaseSel_Ib(If support)
*                        @arg EMUCFG_AngleBaseSel_Ic(If support)
*                        @arg EMUCFG_AngleBaseSel_In(If support)
*                        
*                        @arg EMUCFG_AngleBaseSel_U (If support)
*                        @arg EMUCFG_AngleBaseSel_I1(If support)
*                        @arg EMUCFG_AngleBaseSel_I2(If support)
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_AngBaseSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ANGBASE_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EMUCFG;
	ultemp &=(~EMUCFG_AngleBaseSel);
	ultemp |= Type;
	
	HT_EMUECA->EMUCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Square Rms Source Select
* @brief : set EMU module square rms source  select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EMUCFG_SQRMS_Src_All 
*                        @arg EMUCFG_SQRMS_Src_Fund
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EMUCFG_SqRmsSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_SQRMSSRC_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EMUCFG;
	ultemp &=(~EMUCFG_SQRMS_Src);
	ultemp |= Type;
	
	HT_EMUECA->EMUCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        	/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU CURRENT Rosi ENABLE
* @brief : set EMU module Current rosi enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg FilterCon_Rosi_En_In(If support)
*                        @arg FilterCon_Rosi_En_Ic(If support)
*                        @arg FilterCon_Rosi_En_Ib(If support)
*                        @arg FilterCon_Rosi_En_Ia(If support)
*
*                        @arg FilterCon_Rosi_En_I1(If support)
*                        @arg FilterCon_Rosi_En_I2(If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCon_IRosiEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 

	assert_param(IS_HT_EMU_ROSI_CHANNEL_SEL(Channel));         /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));               /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->FilterCon |= Channel;  
	}
	else
	{
		HT_EMUECA->FilterCon &=(~Channel); 
	}
	HT_EMU_WPReg_Restore(ulProtect);        				/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Rosi Shift Select
* @brief : set EMU module Rosi Shift select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FilterCon_RosiShift_1
*                        @arg FilterCon_RosiShift_2
*                        @arg FilterCon_RosiShift_4
*                        @arg FilterCon_RosiShift_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCon_RosiShiftSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ROSISHIFT_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->FilterCon;
	ultemp &=(~FilterCon_RosiShift);
	ultemp |= Type;
	
	HT_EMUECA->FilterCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU LPF ENABLE
* @brief : set EMU module rms and power Lpf enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg FilterCon_RmsLpf_En
*                        @arg FilterCon_PowerLpf_En
*
* @param: NewState       = ENABLE 
*                        = DISABLE
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCon_LpfEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 

	assert_param(IS_HT_EMU_LPF_CHANNEL_SEL(Channel));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));            /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->FilterCon |= Channel;  
	}
	else
	{
		HT_EMUECA->FilterCon &=(~Channel); 
	}
	HT_EMU_WPReg_Restore(ulProtect);        				/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU VOLTAGE Const ENABLE
* @brief : set EMU module voltage const enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination  of the following values:
*                        @arg FilterCon_UconstA_En(If support)
*                        @arg FilterCon_UconstB_En(If support)
*                        @arg FilterCon_UconstC_En(If support)
*
*                        @arg FilterCon_Uconst_En(If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCon_UConstEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ultemp = Channel;  						
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  						/* Get Write Protect */ 

	assert_param(IS_HT_EMU_UCONSTEN_CHANNEL_SEL(Channel));          /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));                    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   					/* Close write protect*/
#if defined  HT772x
	ultemp |= FilterCon_UconstBAK_En;
#endif
	if(ENABLE == NewState)
	{
		HT_EMUECA->FilterCon |= ultemp;  
	}
	else
	{
		HT_EMUECA->FilterCon &=(~ultemp); 
	}
	HT_EMU_WPReg_Restore(ulProtect);        						/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Fund ZeroCross Delay Points Select
* @brief : set EMU module Fund ZeroCross Delay Points select 
*
* @param : data:recommended data in user's manual book can be used 
*				fund zerocross delay num data,9bit,limit <=0x1ff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCon_FundZcDelaySet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_FUNDZCDELAY_LIMIT(data));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
	
    ultemp = HT_EMUECA->FilterCon;
	ultemp &=(~FilterCon_FundZCDelay);
	ultemp |= (data<<12U);
	
	HT_EMUECA->FilterCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU CHANNEL PGA SELECT
* @brief : set EMU module ADC Channel PGA select
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg FilterCFG_HpfCtrl	
*               @arg FilterCFG_RosiCtrl
*               @arg FilterCFG_LPFCtrl 	
*               @arg FilterCFG_PH90Ctrl 	
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Type = FilterCFG_HpfCtrl:  3bit,limit <=0x07
*								
*				  Type = FilterCFG_RosiCtrl: 2bit,limit <=0x03
*								
*				  Type = FilterCFG_LPFCtrl:  12bit,limit <=0xfff
*																
*				  Type = FilterCFG_PH90Ctrl: 2bit,limit <=0x03
*																
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FilterCFG_Set(uint32_t Type,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_FILTERCFG_TYPE_SEL(Type));    /*  assert_param  */
	
	ultemp = HT_EMUECA->FilterCFG;
	ultemp &= (~Type);
	
	switch(Type)
	{
		case FilterCFG_HpfCtrl:
			assert_param(IS_HT_EMU_HPFCTRL_LIMIT(select));    /*  assert_param  */
			ultemp |= select;
			break;
		case FilterCFG_RosiCtrl:
			assert_param(IS_HT_EMU_ROSICTRL_LIMIT(select));    /*  assert_param  */	
			ultemp |= (select << 3U);
			break;
		case FilterCFG_LPFCtrl:
			assert_param(IS_HT_EMU_LPFCTRL_LIMIT(select));    /*  assert_param  */
			ultemp |= (select << 5U);
			break;
		case FilterCFG_PH90Ctrl:
			assert_param(IS_HT_EMU_PH90CTRL_LIMIT(select));    /*  assert_param  */
			ultemp |= (select << 17U);
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);          /* Close write protect*/
	HT_EMUECA->FilterCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU CHANNEL PGA SELECT
* @brief : set EMU module ADC Channel PGA select
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg StartCFG_Start_CFG	
*               @arg StartCFG_StartSrc_CFG
*               @arg StartCFG_HarStart_CFG 	
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent type select one of the
*                 following values 
*				  Type = StartCFG_Start_CFG:all and fudamental wave power start way select
*               			@arg StartCFG_Start_CFG_POWER1
*               			@arg StartCFG_Start_CFG_POWER2
*               			@arg StartCFG_Start_CFG_RMS1  	
*               			@arg StartCFG_Start_CFG_RMS2   	
*								
*				  Type = StartCFG_StartSrc_CFG:all and fudamental wave power type in power1 or power2 way start
*               			@arg StartCFG_StartSrc_CFG_AvgPower 	
*               			@arg StartCFG_StartSrc_CFG_InsPower 
*
*								
*				  Type = StartCFG_HarStart_CFG:  harmonic wave power start way select
*               			@arg StartCFG_HarStart_CFG_POWER
*               			@arg StartCFG_HarStart_CFG_RMS  
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_StartCFG_Set(uint32_t Type,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_STARTCFG_TYPE_SEL(Type));    /*  assert_param  */
	
	ultemp = HT_EMUECA->StartCFG;
	ultemp &= (~Type);
	
	switch(Type)
	{
		case StartCFG_Start_CFG:
			assert_param(IS_HT_EMU_STARTWAY_SEL(select));    /*  assert_param  */			
			break;
		case StartCFG_StartSrc_CFG:
			assert_param(IS_HT_EMU_STARTSRC_SEL(select));    /*  assert_param  */	
			break;
		case StartCFG_HarStart_CFG:
			assert_param(IS_HT_EMU_HARSTARTWAY_SEL(select));  /*  assert_param  */
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	ultemp |= select;
	HT_EMUECA->StartCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog ADC Bais Set
* @brief : set EMU module Analog ADC Bais select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg ANACFG1_UADC_BIAS
*               @arg ANACFG1_IADC_BIAS
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = ANACFG1_UADC_BIAS:
*               			@arg ANACFG1_UADC_BIAS_4uA 
*               			@arg ANACFG1_UADC_BIAS_6uA 
*               			@arg ANACFG1_UADC_BIAS_8uA 
*               			@arg ANACFG1_UADC_BIAS_10uA 	
*               			@arg ANACFG1_UADC_BIAS_12uA 
*               			
*								
*				  Channel = ANACFG1_IADC_BIAS:
*               			@arg ANACFG1_IADC_BIAS_4uA  	
*               			@arg ANACFG1_IADC_BIAS_6uA  	
*               			@arg ANACFG1_IADC_BIAS_8uA  
*               			@arg ANACFG1_IADC_BIAS_10uA 	
*               			@arg ANACFG1_IADC_BIAS_12uA 
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG1_AdcBasiSet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ADCBASI_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->ANACFG1;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
		case ANACFG1_UADC_BIAS:
			assert_param(IS_HT_EMU_UADCBAIS_SEL(select));    /*  assert_param  */			
			break;
		case ANACFG1_IADC_BIAS:
			assert_param(IS_HT_EMU_IADCBAIS_SEL(select));    /*  assert_param  */	
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/

	ultemp |= select;
	HT_EMUECA->ANACFG1 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog PGA Bais Set
* @brief : set EMU module Analog PAG Bais select
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ANACFG1_PGA_BIAS_5uA 
*               @arg ANACFG1_PGA_BIAS_10uA
*               @arg ANACFG1_PGA_BIAS_15uA
*               @arg ANACFG1_PGA_BIAS_20uA
*               @arg ANACFG1_PGA_BIAS_25uA
*
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG1_PgaBasiSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;      /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PGABASI_SEL(Type));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ANACFG1;
	ultemp &= (~ANACFG1_PGA_BIAS);	
	ultemp |= Type;
	HT_EMUECA->ANACFG1 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog CLK CFG Set
* @brief : set EMU module Analog clk configure
*
* @param : data:clck configure data ,5bit limit<=0x1f
*  		  
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG1_ClkCfgSet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_CLKCFG_LIMIT(data));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ANACFG1;
	ultemp &= (~ANACFG1_CLKCfg);	
	ultemp |= (data<<13U);
	HT_EMUECA->ANACFG1 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU LDO ENABLE
* @brief : set EMU module ldo enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG1_EmuLdoEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ANACFG1 |= ANACFG1_Emu_Ldo_En;
	}
	else
	{
		HT_EMUECA->ANACFG1 &=(~ANACFG1_Emu_Ldo_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU VREF ENABLE
* @brief : set EMU module Vref enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG1_VrefEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ANACFG1 |= ANACFG1_Vref_En;
	}
	else
	{
		HT_EMUECA->ANACFG1 &=(~ANACFG1_Vref_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog Chop ENABLE
* @brief : set EMU module Analog chopper enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination of the following values:
*               @arg ANACFG2_VrefChop_En 
*               @arg ANACFG2_InChop_En   
*               @arg ANACFG2_IChop_En    
*               @arg ANACFG2_UChop_En    
*               @arg ANACFG2_AMPChop_En  
*              
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG2_ChopEnSet(uint32_t Channel,FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));            /*  assert_param  */
	assert_param(IS_HT_EMU_CHOP_CHNNEL_SEL(Channel));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->ANACFG2 |= Channel;
	}
	else
	{
		HT_EMUECA->ANACFG2 &=(~Channel);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU VREF Second Temperature Compensation ENABLE
* @brief : set EMU module Vref Second temperature Compensation enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG2_TC2NdEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ANACFG2 |= ANACFG2_TC2ND_EN;
	}
	else
	{
		HT_EMUECA->ANACFG2 &=(~ANACFG2_TC2ND_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Current VREF ENABLE
* @brief : set EMU module Current High precision Vref enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG2_IRefEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ANACFG2 |= ANACFG2_Iref_En;
	}
	else
	{
		HT_EMUECA->ANACFG2 &=(~ANACFG2_Iref_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog Vref TC Set
* @brief : set EMU module Vref temperature Compensation 
*
* @param : data:clck configure data ,3bit limit<=0x07
*  		  
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ANACFG2_VrefCrtlSet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;          /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_VREFCTRL_LIMIT(data));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ANACFG2;
	ultemp &= (~ANACFG2_Vref_Ctrl);	
	ultemp |= (data<<5U);
	HT_EMUECA->ANACFG2 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
#if defined  HT762x
/**
********************************************************************************************************
*                                      Set EMU Voltage Lost Comparator ENABLE
* @brief : set EMU module Voltage Lost Comparator enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostCMPCFG_CmpEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ULostCMPCFG |= ULostCMPCFG_CMP_EN;
	}
	else
	{
		HT_EMUECA->ULostCMPCFG &=(~ULostCMPCFG_CMP_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Voltage Lost Compare Cycle Num Set
* @brief : set EMU module Voltage Lost compare cycle num  
*
* @param : data:clck configure data ,4bit limit<=0x0f
*  		  
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostCMPCFG_VolNumSet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_VOLNUM_LIMIT(data));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ULostCMPCFG;
	ultemp &= (~ULostCMPCFG_VOLNUM);	
	ultemp |= (data<<1U);
	HT_EMUECA->ULostCMPCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Voltage Lost Compare voltage gear Select
* @brief : set EMU module  Voltage Lost compare voltage gear
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ULostCMPCFG_VcmpLVL_0mV942
*               @arg ULostCMPCFG_VcmpLVL_1mV414
*               @arg ULostCMPCFG_VcmpLVL_1mV791
*               @arg ULostCMPCFG_VcmpLVL_3mV140
*               @arg ULostCMPCFG_VcmpLVL_4mV488
*               @arg ULostCMPCFG_VcmpLVL_5mV837
*               @arg ULostCMPCFG_VcmpLVL_7mV185
*               @arg ULostCMPCFG_VcmpLVL_9mV542
*
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostCMPCFG_LvlSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_VCMPLVL_SEL(Type));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ULostCMPCFG;
	ultemp &= (~ULostCMPCFG_VcmpLVL);	
	ultemp |= Type;
	HT_EMUECA->ULostCMPCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Voltage Lost DUTY Set
* @brief : set EMU module Voltage Lost Minimum effective Pluse Width time coefficient  
*
* @param : data:clck configure data ,7bit limit<=0x7f
*  		  
*
* @retval: none
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostCMPCFG_DutySet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_DUTY_LIMIT(data));    /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->ULostCMPCFG;
	ultemp &= (~ULostCMPCFG_DUTY);	
	ultemp |= (data<<8U);
	HT_EMUECA->ULostCMPCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Voltage Lost Comparator Continuous Mode ENABLE
* @brief : set EMU module Voltage Lost Comparator Continuous Mode enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostCMPCFG_CmpPrdEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->ULostCMPCFG |= ULostCMPCFG_CMP_PRD_EN;
	}
	else
	{
		HT_EMUECA->ULostCMPCFG &=(~ULostCMPCFG_CMP_PRD_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Analog ADC Bais Set
* @brief : set EMU module Analog ADC Bais select
*
* @param : Type
*  		  This parameter can be one of the following values:
*               @arg ULostPRDCFG_CMPPRD
*               @arg ULostPRDCFG_CMPRunTime
*               @arg ULostPRDCFG_STBTime
*
*
* @param: data: recommended data in user's manual book can be used£¬diffrent type select one of the
*                 following values 
*				  Type = ULostPRDCFG_CMPPRD:comparator detect period time,8bit,limit <=0xff 
*				  Type = ULostPRDCFG_CMPRunTime: comparator run time ,8bit,limit <=0xff								
*				  Type = ULostPRDCFG_STBTime:comparator stand by time,6bit,limit <=0x3f
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ULostPRDCFG_Set(uint32_t Type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PRDCFG_CHANNEL_SEL(Type));    /*  assert_param  */

	ultemp = HT_EMUECA->ULostPRDCFG;
	ultemp &= (~Type);
	
	switch(Type)
	{
		case ULostPRDCFG_CMPPRD:
			assert_param(IS_HT_EMU_LOSTPRD_LIMIT(data));        /*  assert_param  */	
			ultemp |= data;
			break;
		case ULostPRDCFG_CMPRunTime:
			assert_param(IS_HT_EMU_LOSTRUNTIME_LIMIT(data));    /*  assert_param  */
			ultemp |= (data<<8U);
			break;
		case ULostPRDCFG_STBTime:
			assert_param(IS_HT_EMU_LOSTSTBTIME_LIMIT(data));    /*  assert_param  */
			ultemp |= (data<<16U);
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
	
	HT_EMUECA->ULostPRDCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        			/* Restore Write Protect register */
}
#endif
/**
********************************************************************************************************
*                                      Set EMU FailVoltage
* @brief : set EMU module FailVoltage
*
* @param : data:  data 16bit,limit <= 0xffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FailVoltageSet(uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 

	assert_param(IS_HT_EMU_FAILVOLTAGE_LIMIT(data));       /*  assert_param  */				

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	HT_EMUECA->FailVoltage = data;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */

}
/**
********************************************************************************************************
*                                      Get EMU FailVoltage
* @brief : Get EMU module FailVoltage
*
* @param : none
*
* @retval: 16bit,limit <= 0xffff
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_EMU_FailVoltageGet(void)
{	

	uint32_t ultemp = 0U;
	
	ultemp = HT_EMUECA->FailVoltage;
	ultemp &= ECR_16BIT_DATA;
	
	return ultemp;
}
/**
********************************************************************************************************
*                                      Set EMU Low Power Mode ENABLE
* @brief : set EMU module Low Power Mode enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_LPModeCON_LpModeEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));        /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->LPModeCON |= LPModeCON_LPMode_EN;
	}
	else
	{
		HT_EMUECA->LPModeCON &=(~LPModeCON_LPMode_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Low Power Mode CLK Select
* @brief : set EMU module Low Power Mode CLK select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LPModeCON_EMUCLK_LPSel_204K8
*                        @arg LPModeCON_EMUCLK_LPSel_32K  
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_LPModeCON_LpClkSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_LPCLK_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->LPModeCON;
	ultemp &=(~LPModeCON_EMUCLK_LPSel);
	ultemp |= Type;
	
	HT_EMUECA->LPModeCON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Low Power Vref ENABLE
* @brief : set EMU module Low Power vref enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_LPModeCON_LpVrefEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->LPModeCON |= LPModeCON_LP_VREF_EN;
	}
	else
	{
		HT_EMUECA->LPModeCON &=(~LPModeCON_LP_VREF_EN);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Low Power Mode CLK Select
* @brief : set EMU module Low Power Mode CLK select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LPModeCON_StandByTime_0   
*                        @arg LPModeCON_StandByTime_4   
*                        @arg LPModeCON_StandByTime_8   
*                        @arg LPModeCON_StandByTime_16  
*                        @arg LPModeCON_StandByTime_32  
*                        @arg LPModeCON_StandByTime_64  
*                        @arg LPModeCON_StandByTime_128 
*                        @arg LPModeCON_StandByTime_256 
*                        @arg LPModeCON_StandByTime_512 
*                        @arg LPModeCON_StandByTime_1024
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_LPModeCON_STBTimeSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_LPSTBTIME_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->LPModeCON;
	ultemp &=(~LPModeCON_StandByTime);
	ultemp |= Type;
	
	HT_EMUECA->LPModeCON = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU ENERGY CHANNEL ENABLE
* @brief : set EMU module energy run enable or disable 
*
* @param : Channel
*  		  This parameter can be one or a combination of the following values:
*                        @arg CFxRun_Har_Pt_EN  
*                        @arg CFxRun_Har_Pc_EN  (If support)
*                        @arg CFxRun_Har_Pb_EN  (If support)
*                        @arg CFxRun_Har_Pa_EN  (If support)
*                        @arg CFxRun_Fund_Qt_EN 
*                        @arg CFxRun_Fund_Qc_EN (If support)
*                        @arg CFxRun_Fund_Qb_EN (If support)
*                        @arg CFxRun_Fund_Qa_EN (If support)
*                        @arg CFxRun_Fund_Pt_EN 
*                        @arg CFxRun_Fund_Pc_EN (If support)
*                        @arg CFxRun_Fund_Pb_EN (If support)
*                        @arg CFxRun_Fund_Pa_EN (If support)
*                        @arg CFxRun_St_EN      
*                        @arg CFxRun_Sc_EN      (If support)
*                        @arg CFxRun_Sb_EN      (If support)
*                        @arg CFxRun_Sa_EN      (If support)
*                        @arg CFxRun_All_Qt_EN  
*                        @arg CFxRun_All_Qc_EN  (If support)
*                        @arg CFxRun_All_Qb_EN  (If support)
*                        @arg CFxRun_All_Qa_EN  (If support)
*                        @arg CFxRun_All_Pt_EN  
*                        @arg CFxRun_All_Pc_EN  (If support)
*                        @arg CFxRun_All_Pb_EN  (If support)
*                        @arg CFxRun_All_Pa_EN  (If support)
*
*                        @arg CFxRun_All_P1_EN  (If support)
*                        @arg CFxRun_All_P2_EN  (If support)
*                        @arg CFxRun_All_Q1_EN  (If support)
*                        @arg CFxRun_All_Q2_EN  (If support)
*                        @arg CFxRun_S1_EN      (If support)
*                        @arg CFxRun_S2_EN      (If support)
*                        @arg CFxRun_Fund_P1_EN (If support)
*                        @arg CFxRun_Fund_P2_EN (If support)
*                        @arg CFxRun_Fund_Q1_EN (If support)
*                        @arg CFxRun_Fund_Q2_EN (If support)
*                        @arg CFxRun_Har_P1_EN  (If support)
*                        @arg CFxRun_Har_P2_EN  (If support)
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_CFxRun_ChnEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get Write Protect */ 

	assert_param(IS_HT_EMU_CFXRUN_CHANNEL_SEL(Channel));       /*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));               /*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   			   /* Close write protect */
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->CFxRun |= Channel;
	}
	else
	{
		HT_EMUECA->CFxRun &=(~Channel);
	}
	HT_EMU_WPReg_Restore(ulProtect);        					/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy Power Shift Select
* @brief : set EMU module  Energy Power Shift select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyCon_Power_Shift_1 
*                        @arg EnergyCon_Power_Shift_2 
*                        @arg EnergyCon_Power_Shift_4 
*                        @arg EnergyCon_Power_Shift_8 
*                        @arg EnergyCon_Power_Shift_16
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_PowerShiftSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERSHIFT_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EnergyCon;
	ultemp &=(~EnergyCon_Power_Shift);
	ultemp |= Type;
	
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy CF Pluse Width Select
* @brief : set EMU module Energy CF Pluse Width select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyCon_CFP_80  
*                        @arg EnergyCon_CFP_40  
*                        @arg EnergyCon_CFP_20  
*                        @arg EnergyCon_CFP_160 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_CFPSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_CFP_SEL(Type));        /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EnergyCon;
	ultemp &=(~EnergyCon_CFP);
	ultemp |= Type;
	
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy CF PLUSE Valid Level Select
* @brief : set EMU module Energy CF PLUSE Valid Level select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyCon_POS_High 
*                        @arg EnergyCon_POS_Low  
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_PosSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POS_SEL(Type));          /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
    ultemp = HT_EMUECA->EnergyCon;
	ultemp &=(~EnergyCon_POS);
	ultemp |= Type;
	
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Vector Sum Power Way Select
* @brief : set EMU module vector sum Power way select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyCon_PtAddMode_ALG 
*                        @arg EnergyCon_PtAddMode_ABS 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_PtAddModeSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PTADDMODE_SEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_EMUECA->EnergyCon;
	ultemp &=(~EnergyCon_PtAddMode);
	ultemp |= Type;
	
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy Read Clear ENABLE
* @brief : set EMU module Energy Read Clear enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_EnergyRCEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_FUNCTIONAL_STATE(NewState));       /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->EnergyCon |= EnergyCon_EnergyRC_En;
	}
	else
	{
		HT_EMUECA->EnergyCon &=(~EnergyCon_EnergyRC_En);
	}
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy S Source Select
* @brief : set EMU module Energy S source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyCon_EnergySSrc_Sel_All  
*                        @arg EnergyCon_EnergySSrc_Sel_Fund 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_EnergySSrcSet(uint32_t Type)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ENERGYS_SRCSEL(Type));   /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
    ultemp = HT_EMUECA->EnergyCon;
	ultemp &=(~EnergyCon_EnergySSrc_Sel);
	ultemp |= Type;
	
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);                /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy Channel Pass Mode Select
* @brief : set EMU module Energy Channel Pass Mode select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg EnergyCon_PassMode_All_P
*               @arg EnergyCon_PassMode_All_Q
*               @arg EnergyCon_PassMode_S
*               @arg EnergyCon_PassMode_Fund_P
*               @arg EnergyCon_PassMode_Fund_Q
*               @arg EnergyCon_PassMode_Har_P
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = EnergyCon_PassMode_All_P:
*               			@arg EnergyCon_PassMode_All_P_All 
*               			@arg EnergyCon_PassMode_All_P_POS 
*               			@arg EnergyCon_PassMode_All_P_NEG                			
*								
*				  Channel = EnergyCon_PassMode_All_Q:
*               			@arg EnergyCon_PassMode_All_Q_All  	
*               			@arg EnergyCon_PassMode_All_Q_POS  	
*               			@arg EnergyCon_PassMode_All_Q_NEG  
*
*				  Channel = EnergyCon_PassMode_S:
*               			@arg EnergyCon_PassMode_S_All  
*               			@arg EnergyCon_PassMode_S_POS  
*               			@arg EnergyCon_PassMode_S_NEG  
*
*				  Channel = EnergyCon_PassMode_Fund_P:
*               			@arg EnergyCon_PassMode_Fund_P_All 
*               			@arg EnergyCon_PassMode_Fund_P_POS 
*               			@arg EnergyCon_PassMode_Fund_P_NEG 
*
*				  Channel = EnergyCon_PassMode_Fund_Q:
*               			@arg EnergyCon_PassMode_Fund_Q_All 
*               			@arg EnergyCon_PassMode_Fund_Q_POS 
*               			@arg EnergyCon_PassMode_Fund_Q_NEG 
*               										
*				  Channel = EnergyCon_PassMode_Har_P:
*               			@arg EnergyCon_PassMode_Har_P_All 
*               			@arg EnergyCon_PassMode_Har_P_POS 
*               			@arg EnergyCon_PassMode_Har_P_NEG 
*               										
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_EnergyCon_PassModeSet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                 /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_PASSMODE_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->EnergyCon;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
		case EnergyCon_PassMode_All_P:
			assert_param(IS_HT_EMU_PASSMODE_ALLP_SEL(select));    /*  assert_param  */			
			break;
		case EnergyCon_PassMode_All_Q:
			assert_param(IS_HT_EMU_PASSMODE_ALLQ_SEL(select));    /*  assert_param  */	
			break;
		case EnergyCon_PassMode_S:
			assert_param(IS_HT_EMU_PASSMODE_S_SEL(select));       /*  assert_param  */			
			break;
		case EnergyCon_PassMode_Fund_P:
			assert_param(IS_HT_EMU_PASSMODE_FUNDP_SEL(select));    /*  assert_param  */	
			break;
		case EnergyCon_PassMode_Fund_Q:
			assert_param(IS_HT_EMU_PASSMODE_FUNDQ_SEL(select));    /*  assert_param  */			
			break;
		case EnergyCon_PassMode_Har_P:
			assert_param(IS_HT_EMU_PASSMODE_HARP_SEL(select));     /*  assert_param  */	
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             		/* Close write protect*/

	ultemp |= select;
	HT_EMUECA->EnergyCon = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       					 		/* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy Channel Power Source  CFG1 Select
* @brief : set EMU module Energy Channel Power Source  CFG1 Select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg PowerSrcCFG1_All_Pa(If support)
*               @arg PowerSrcCFG1_All_Pb(If support)
*               @arg PowerSrcCFG1_All_Pc(If support)
*               @arg PowerSrcCFG1_All_Pt
*               @arg PowerSrcCFG1_All_Qa(If support)
*               @arg PowerSrcCFG1_All_Qb(If support)
*               @arg PowerSrcCFG1_All_Qc(If support)
*               @arg PowerSrcCFG1_All_Qt
*               @arg PowerSrcCFG1_Sa	(If support)
*               @arg PowerSrcCFG1_Sb	(If support)
*               @arg PowerSrcCFG1_Sc	(If support)
*               @arg PowerSrcCFG1_St	
*
*               @arg PowerSrcCFG1_All_P1(If support)
*               @arg PowerSrcCFG1_All_P2(If support)
*               @arg PowerSrcCFG1_All_Q1(If support)
*               @arg PowerSrcCFG1_All_Q2(If support)
*               @arg PowerSrcCFG1_S1	(If support)
*               @arg PowerSrcCFG1_S2	(If support)
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = PowerSrcCFG1_All_Pa:
*               			@arg PowerSrcCFG1_All_Pa_AvgPower   
*               			@arg PowerSrcCFG1_All_Pa_InsPower   
*               			@arg PowerSrcCFG1_All_Pa_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_Pb:
*               			@arg PowerSrcCFG1_All_Pb_AvgPower    	
*               			@arg PowerSrcCFG1_All_Pb_InsPower    	
*               			@arg PowerSrcCFG1_All_Pb_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Pc:
*               			@arg PowerSrcCFG1_All_Pc_AvgPower    
*               			@arg PowerSrcCFG1_All_Pc_InsPower    
*               			@arg PowerSrcCFG1_All_Pc_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Pt:
*               			@arg PowerSrcCFG1_All_Pt_AvgPower   
*               			@arg PowerSrcCFG1_All_Pt_InsPower   
*               			@arg PowerSrcCFG1_All_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG1_All_Qa:
*               			@arg PowerSrcCFG1_All_Qa_AvgPower   
*               			@arg PowerSrcCFG1_All_Qa_InsPower   
*               			@arg PowerSrcCFG1_All_Qa_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Qb:
*               			@arg PowerSrcCFG1_All_Qb_AvgPower   
*               			@arg PowerSrcCFG1_All_Qb_InsPower   
*               			@arg PowerSrcCFG1_All_Qb_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Qc:
*               			@arg PowerSrcCFG1_All_Qc_AvgPower   
*               			@arg PowerSrcCFG1_All_Qc_InsPower   
*               			@arg PowerSrcCFG1_All_Qc_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_Qt:
*               			@arg PowerSrcCFG1_All_Qt_AvgPower    	
*               			@arg PowerSrcCFG1_All_Qt_InsPower    	
*               			@arg PowerSrcCFG1_All_Qt_ConstPower  
*
*				  Channel = PowerSrcCFG1_Sa:
*               			@arg PowerSrcCFG1_Sa_AvgPower    
*               			@arg PowerSrcCFG1_Sa_InsPower    
*               			@arg PowerSrcCFG1_Sa_ConstPower  
*
*				  Channel = PowerSrcCFG1_Sb:
*               			@arg PowerSrcCFG1_Sb_AvgPower   
*               			@arg PowerSrcCFG1_Sb_InsPower   
*               			@arg PowerSrcCFG1_Sb_ConstPower 
*
*				  Channel = PowerSrcCFG1_Sc:
*               			@arg PowerSrcCFG1_Sc_AvgPower  
*               			@arg PowerSrcCFG1_Sc_InsPower  
*               			@arg PowerSrcCFG1_Sc_ConstPower
*               										
*				  Channel = PowerSrcCFG1_St:
*               			@arg PowerSrcCFG1_St_AvgPower   
*               			@arg PowerSrcCFG1_St_InsPower   
*               			@arg PowerSrcCFG1_St_ConstPower 
*
*				  Channel = PowerSrcCFG1_All_P1:
*               			@arg PowerSrcCFG1_All_P1_AvgPower   
*               			@arg PowerSrcCFG1_All_P1_InsPower   
*               			@arg PowerSrcCFG1_All_P1_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_P2:
*               			@arg PowerSrcCFG1_All_P2_AvgPower    	
*               			@arg PowerSrcCFG1_All_P2_InsPower    	
*               			@arg PowerSrcCFG1_All_P2_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Q1:
*               			@arg PowerSrcCFG1_All_Q1_AvgPower   
*               			@arg PowerSrcCFG1_All_Q1_InsPower   
*               			@arg PowerSrcCFG1_All_Q1_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Q2:
*               			@arg PowerSrcCFG1_All_Q2_AvgPower   
*               			@arg PowerSrcCFG1_All_Q2_InsPower   
*               			@arg PowerSrcCFG1_All_Q2_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_S1:
*               			@arg PowerSrcCFG1_S1_AvgPower    
*               			@arg PowerSrcCFG1_S1_InsPower    
*               			@arg PowerSrcCFG1_S1_ConstPower  
*
*				  Channel = PowerSrcCFG1_S2:
*               			@arg PowerSrcCFG1_S2_AvgPower   
*               			@arg PowerSrcCFG1_S2_InsPower   
*               			@arg PowerSrcCFG1_S2_ConstPower 
*
*
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerSrcCFG1_Set(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERCFG1_CHANNEL_SEL(Channel));    /*  assert_param  */
		
	switch(Channel)
	{
		case PowerSrcCFG1_All_Pt:
			assert_param(IS_HT_EMU_POWERSRC_ALLPT_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_All_Qt:
			assert_param(IS_HT_EMU_POWERSRC_ALLQT_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_St:
			assert_param(IS_HT_EMU_POWERSRC_ST_SEL(select));    	/*  assert_param  */	
			break;
	#if defined  HT762x
		case PowerSrcCFG1_All_Pa:
			assert_param(IS_HT_EMU_POWERSRC_ALLPA_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_All_Pb:
			assert_param(IS_HT_EMU_POWERSRC_ALLPB_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_All_Pc:
			assert_param(IS_HT_EMU_POWERSRC_ALLPC_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_All_Qa:
			assert_param(IS_HT_EMU_POWERSRC_ALLQA_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_All_Qb:
			assert_param(IS_HT_EMU_POWERSRC_ALLQB_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_All_Qc:
			assert_param(IS_HT_EMU_POWERSRC_ALLQC_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_Sa:
			assert_param(IS_HT_EMU_POWERSRC_SA_SEL(select));       /*  assert_param  */			
			break;
		case PowerSrcCFG1_Sb:
			assert_param(IS_HT_EMU_POWERSRC_SB_SEL(select));    	/*  assert_param  */	
			break;
		case PowerSrcCFG1_Sc:
			assert_param(IS_HT_EMU_POWERSRC_SC_SEL(select));    	/*  assert_param  */			
			break;
	#else
		case PowerSrcCFG1_All_P1:
			assert_param(IS_HT_EMU_POWERSRC_ALLP1_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_All_P2:
			assert_param(IS_HT_EMU_POWERSRC_ALLP2_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_All_Q1:
			assert_param(IS_HT_EMU_POWERSRC_ALLQ1_SEL(select));    /*  assert_param  */			
			break;
		case PowerSrcCFG1_All_Q2:
			assert_param(IS_HT_EMU_POWERSRC_ALLQ2_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG1_S1:
			assert_param(IS_HT_EMU_POWERSRC_S1_SEL(select));       /*  assert_param  */			
			break;
		case PowerSrcCFG1_S2:
			assert_param(IS_HT_EMU_POWERSRC_S2_SEL(select));    	/*  assert_param  */	
			break;
	#endif
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                 /* Close write protect*/
	
	ultemp = HT_EMUECA->PowerSrcCFG1;
	ultemp &= (~Channel);
	ultemp |= select;
	HT_EMUECA->PowerSrcCFG1 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       						/* Restore Write Protect register */

}
/**
********************************************************************************************************
*                                      Set EMU Energy Channel Power Source CFG2 Select
* @brief : set EMU module Energy Channel Power Source CFG2 Select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg PowerSrcCFG2_Fund_Pa(If support)
*               @arg PowerSrcCFG2_Fund_Pb(If support)
*               @arg PowerSrcCFG2_Fund_Pc(If support)
*               @arg PowerSrcCFG2_Fund_Pt
*               @arg PowerSrcCFG2_Fund_Qa(If support)
*               @arg PowerSrcCFG2_Fund_Qb(If support)
*               @arg PowerSrcCFG2_Fund_Qc(If support)
*               @arg PowerSrcCFG2_Fund_Qt
*               @arg PowerSrcCFG2_Har_Pa(If support)
*               @arg PowerSrcCFG2_Har_Pb(If support)
*               @arg PowerSrcCFG2_Har_Pc(If support)
*               @arg PowerSrcCFG2_Har_Pt
*
*               @arg PowerSrcCFG2_Fund_P1(If support)
*               @arg PowerSrcCFG2_Fund_P2(If support)
*               @arg PowerSrcCFG2_Fund_Q1(If support)
*               @arg PowerSrcCFG2_Fund_Q2(If support)
*               @arg PowerSrcCFG2_Har_P1(If support)
*               @arg PowerSrcCFG2_Har_P2(If support)
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*
*				  Channel = PowerSrcCFG2_Fund_Pa:
*               			@arg PowerSrcCFG2_Fund_Pa_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Pa_InsPower   
*               			@arg PowerSrcCFG2_Fund_Pa_ConstPower                			
*								
*				  Channel = PowerSrcCFG2_Fund_Pb:
*               			@arg PowerSrcCFG2_Fund_Pb_AvgPower    	
*               			@arg PowerSrcCFG2_Fund_Pb_InsPower    	
*               			@arg PowerSrcCFG2_Fund_Pb_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_Pc:
*               			@arg PowerSrcCFG2_Fund_Pc_AvgPower    
*               			@arg PowerSrcCFG2_Fund_Pc_InsPower    
*               			@arg PowerSrcCFG2_Fund_Pc_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_Pt:
*               			@arg PowerSrcCFG2_Fund_Pt_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Pt_InsPower   
*               			@arg PowerSrcCFG2_Fund_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Qa:
*               			@arg PowerSrcCFG2_Fund_Qa_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qa_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qa_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Qb:
*               			@arg PowerSrcCFG2_Fund_Qb_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qb_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qb_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Qc:
*               			@arg PowerSrcCFG2_Fund_Qc_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qc_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qc_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Qt:
*               			@arg PowerSrcCFG2_Fund_Qt_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qt_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qt_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pa:
*               			@arg PowerSrcCFG2_Har_Pa_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pa_InsPower   
*               			@arg PowerSrcCFG2_Har_Pa_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pb:
*               			@arg PowerSrcCFG2_Har_Pb_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pb_InsPower   
*               			@arg PowerSrcCFG2_Har_Pb_ConstPower 
*
*				  Channel = PowerSrcCFG2_Har_Pc:
*               			@arg PowerSrcCFG2_Har_Pc_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pc_InsPower   
*               			@arg PowerSrcCFG2_Har_Pc_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pt:
*               			@arg PowerSrcCFG2_Har_Pt_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pt_InsPower   
*               			@arg PowerSrcCFG2_Har_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_P1:
*               			@arg PowerSrcCFG2_Fund_P1_AvgPower    
*               			@arg PowerSrcCFG2_Fund_P1_InsPower    
*               			@arg PowerSrcCFG2_Fund_P1_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_P2:
*               			@arg PowerSrcCFG2_Fund_P2_AvgPower   
*               			@arg PowerSrcCFG2_Fund_P2_InsPower   
*               			@arg PowerSrcCFG2_Fund_P2_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Q1:
*               			@arg PowerSrcCFG2_Fund_Q1_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Q1_InsPower   
*               			@arg PowerSrcCFG2_Fund_Q1_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Q2:
*               			@arg PowerSrcCFG2_Fund_Q2_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Q2_InsPower   
*               			@arg PowerSrcCFG2_Fund_Q2_ConstPower 
*
*				  Channel = PowerSrcCFG2_Har_P1:
*               			@arg PowerSrcCFG2_Har_P1_AvgPower   
*               			@arg PowerSrcCFG2_Har_P1_InsPower   
*               			@arg PowerSrcCFG2_Har_P1_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_P2:
*               			@arg PowerSrcCFG2_Har_P2_AvgPower   
*               			@arg PowerSrcCFG2_Har_P2_InsPower   
*               			@arg PowerSrcCFG2_Har_P2_ConstPower 
*
*
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerSrcCFG2_Set(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWERCFG2_CHANNEL_SEL(Channel));    /*  assert_param  */
		
	switch(Channel)
	{
		case PowerSrcCFG2_Fund_Pt:
			assert_param(IS_HT_EMU_POWERSRC_FUNDPT_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Qt:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQT_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Har_Pt:
			assert_param(IS_HT_EMU_POWERSRC_HARPT_SEL(select));    /*  assert_param  */	
			break;

	#if defined  HT762x
		case PowerSrcCFG2_Fund_Pa:
			assert_param(IS_HT_EMU_POWERSRC_FUNDPA_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Pb:
			assert_param(IS_HT_EMU_POWERSRC_FUNDPB_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Pc:
			assert_param(IS_HT_EMU_POWERSRC_FUNDPC_SEL(select));     /*  assert_param  */	
			break;
		case PowerSrcCFG2_Fund_Qa:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQA_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Qb:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQB_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Qc:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQC_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Har_Pa:
			assert_param(IS_HT_EMU_POWERSRC_HARPA_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Har_Pb:
			assert_param(IS_HT_EMU_POWERSRC_HARPB_SEL(select));    /*  assert_param  */	
			break;
		case PowerSrcCFG2_Har_Pc:
			assert_param(IS_HT_EMU_POWERSRC_HARPC_SEL(select));    /*  assert_param  */
			break;
	#else
		case PowerSrcCFG2_Fund_P1:
			assert_param(IS_HT_EMU_POWERSRC_FUNDP1_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_P2:
			assert_param(IS_HT_EMU_POWERSRC_FUNDP2_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Q1:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQ1_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Fund_Q2:
			assert_param(IS_HT_EMU_POWERSRC_FUNDQ2_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Har_P1:
			assert_param(IS_HT_EMU_POWERSRC_HARP1_SEL(select));    /*  assert_param  */
			break;
		case PowerSrcCFG2_Har_P2:
			assert_param(IS_HT_EMU_POWERSRC_HARP2_SEL(select));    /*  assert_param  */	
			break;
	
	#endif
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                 /* Close write protect*/
	
	ultemp = HT_EMUECA->PowerSrcCFG2;
	ultemp &= (~Channel);
	ultemp |= select;
	HT_EMUECA->PowerSrcCFG2 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */

}
/**
********************************************************************************************************
*                                      Set EMU Energy Channel Power Source Select
* @brief : set EMU module Energy Channel Power Source Select
*
* @param : SrcChnl
*  		  This parameter can be one of the following values:
*               @arg ECR_PowerSrcCFG1
*               @arg ECR_PowerSrcCFG2
*
* @param : Channel
*  		  This parameter can be one of the following values:
*
*		SrcChnl = ECR_PowerSrcCFG1:
*               @arg PowerSrcCFG1_All_Pa(If support)
*               @arg PowerSrcCFG1_All_Pb(If support)
*               @arg PowerSrcCFG1_All_Pc(If support)
*               @arg PowerSrcCFG1_All_Pt
*               @arg PowerSrcCFG1_All_Qa(If support)
*               @arg PowerSrcCFG1_All_Qb(If support)
*               @arg PowerSrcCFG1_All_Qc(If support)
*               @arg PowerSrcCFG1_All_Qt
*               @arg PowerSrcCFG1_Sa	(If support)
*               @arg PowerSrcCFG1_Sb	(If support)
*               @arg PowerSrcCFG1_Sc	(If support)
*               @arg PowerSrcCFG1_St	
*
*               @arg PowerSrcCFG1_All_P1(If support)
*               @arg PowerSrcCFG1_All_P2(If support)
*               @arg PowerSrcCFG1_All_Q1(If support)
*               @arg PowerSrcCFG1_All_Q2(If support)
*               @arg PowerSrcCFG1_S1	(If support)
*               @arg PowerSrcCFG1_S2	(If support)
*
*
*		SrcChnl = ECR_PowerSrcCFG2:
*               @arg PowerSrcCFG2_Fund_Pa(If support)
*               @arg PowerSrcCFG2_Fund_Pb(If support)
*               @arg PowerSrcCFG2_Fund_Pc(If support)
*               @arg PowerSrcCFG2_Fund_Pt
*               @arg PowerSrcCFG2_Fund_Qa(If support)
*               @arg PowerSrcCFG2_Fund_Qb(If support)
*               @arg PowerSrcCFG2_Fund_Qc(If support)
*               @arg PowerSrcCFG2_Fund_Qt
*               @arg PowerSrcCFG2_Har_Pa(If support)
*               @arg PowerSrcCFG2_Har_Pb(If support)
*               @arg PowerSrcCFG2_Har_Pc(If support)
*               @arg PowerSrcCFG2_Har_Pt
*
*               @arg PowerSrcCFG2_Fund_P1(If support)
*               @arg PowerSrcCFG2_Fund_P2(If support)
*               @arg PowerSrcCFG2_Fund_Q1(If support)
*               @arg PowerSrcCFG2_Fund_Q2(If support)
*               @arg PowerSrcCFG2_Har_P1(If support)
*               @arg PowerSrcCFG2_Har_P2(If support)
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = PowerSrcCFG1_All_Pa:
*               			@arg PowerSrcCFG1_All_Pa_AvgPower   
*               			@arg PowerSrcCFG1_All_Pa_InsPower   
*               			@arg PowerSrcCFG1_All_Pa_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_Pb:
*               			@arg PowerSrcCFG1_All_Pb_AvgPower    	
*               			@arg PowerSrcCFG1_All_Pb_InsPower    	
*               			@arg PowerSrcCFG1_All_Pb_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Pc:
*               			@arg PowerSrcCFG1_All_Pc_AvgPower    
*               			@arg PowerSrcCFG1_All_Pc_InsPower    
*               			@arg PowerSrcCFG1_All_Pc_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Pt:
*               			@arg PowerSrcCFG1_All_Pt_AvgPower   
*               			@arg PowerSrcCFG1_All_Pt_InsPower   
*               			@arg PowerSrcCFG1_All_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG1_All_Qa:
*               			@arg PowerSrcCFG1_All_Qa_AvgPower   
*               			@arg PowerSrcCFG1_All_Qa_InsPower   
*               			@arg PowerSrcCFG1_All_Qa_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Qb:
*               			@arg PowerSrcCFG1_All_Qb_AvgPower   
*               			@arg PowerSrcCFG1_All_Qb_InsPower   
*               			@arg PowerSrcCFG1_All_Qb_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Qc:
*               			@arg PowerSrcCFG1_All_Qc_AvgPower   
*               			@arg PowerSrcCFG1_All_Qc_InsPower   
*               			@arg PowerSrcCFG1_All_Qc_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_Qt:
*               			@arg PowerSrcCFG1_All_Qt_AvgPower    	
*               			@arg PowerSrcCFG1_All_Qt_InsPower    	
*               			@arg PowerSrcCFG1_All_Qt_ConstPower  
*
*				  Channel = PowerSrcCFG1_Sa:
*               			@arg PowerSrcCFG1_Sa_AvgPower    
*               			@arg PowerSrcCFG1_Sa_InsPower    
*               			@arg PowerSrcCFG1_Sa_ConstPower  
*
*				  Channel = PowerSrcCFG1_Sb:
*               			@arg PowerSrcCFG1_Sb_AvgPower   
*               			@arg PowerSrcCFG1_Sb_InsPower   
*               			@arg PowerSrcCFG1_Sb_ConstPower 
*
*				  Channel = PowerSrcCFG1_Sc:
*               			@arg PowerSrcCFG1_Sc_AvgPower  
*               			@arg PowerSrcCFG1_Sc_InsPower  
*               			@arg PowerSrcCFG1_Sc_ConstPower
*               										
*				  Channel = PowerSrcCFG1_St:
*               			@arg PowerSrcCFG1_St_AvgPower   
*               			@arg PowerSrcCFG1_St_InsPower   
*               			@arg PowerSrcCFG1_St_ConstPower 
*
*				  Channel = PowerSrcCFG1_All_P1:
*               			@arg PowerSrcCFG1_All_P1_AvgPower   
*               			@arg PowerSrcCFG1_All_P1_InsPower   
*               			@arg PowerSrcCFG1_All_P1_ConstPower                			
*								
*				  Channel = PowerSrcCFG1_All_P2:
*               			@arg PowerSrcCFG1_All_P2_AvgPower    	
*               			@arg PowerSrcCFG1_All_P2_InsPower    	
*               			@arg PowerSrcCFG1_All_P2_ConstPower  
*
*				  Channel = PowerSrcCFG1_All_Q1:
*               			@arg PowerSrcCFG1_All_Q1_AvgPower   
*               			@arg PowerSrcCFG1_All_Q1_InsPower   
*               			@arg PowerSrcCFG1_All_Q1_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_All_Q2:
*               			@arg PowerSrcCFG1_All_Q2_AvgPower   
*               			@arg PowerSrcCFG1_All_Q2_InsPower   
*               			@arg PowerSrcCFG1_All_Q2_ConstPower 
*               										
*				  Channel = PowerSrcCFG1_S1:
*               			@arg PowerSrcCFG1_S1_AvgPower    
*               			@arg PowerSrcCFG1_S1_InsPower    
*               			@arg PowerSrcCFG1_S1_ConstPower  
*
*				  Channel = PowerSrcCFG1_S2:
*               			@arg PowerSrcCFG1_S2_AvgPower   
*               			@arg PowerSrcCFG1_S2_InsPower   
*               			@arg PowerSrcCFG1_S2_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Pa:
*               			@arg PowerSrcCFG2_Fund_Pa_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Pa_InsPower   
*               			@arg PowerSrcCFG2_Fund_Pa_ConstPower                			
*								
*				  Channel = PowerSrcCFG2_Fund_Pb:
*               			@arg PowerSrcCFG2_Fund_Pb_AvgPower    	
*               			@arg PowerSrcCFG2_Fund_Pb_InsPower    	
*               			@arg PowerSrcCFG2_Fund_Pb_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_Pc:
*               			@arg PowerSrcCFG2_Fund_Pc_AvgPower    
*               			@arg PowerSrcCFG2_Fund_Pc_InsPower    
*               			@arg PowerSrcCFG2_Fund_Pc_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_Pt:
*               			@arg PowerSrcCFG2_Fund_Pt_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Pt_InsPower   
*               			@arg PowerSrcCFG2_Fund_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Qa:
*               			@arg PowerSrcCFG2_Fund_Qa_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qa_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qa_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Qb:
*               			@arg PowerSrcCFG2_Fund_Qb_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qb_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qb_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Qc:
*               			@arg PowerSrcCFG2_Fund_Qc_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qc_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qc_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Qt:
*               			@arg PowerSrcCFG2_Fund_Qt_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Qt_InsPower   
*               			@arg PowerSrcCFG2_Fund_Qt_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pa:
*               			@arg PowerSrcCFG2_Har_Pa_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pa_InsPower   
*               			@arg PowerSrcCFG2_Har_Pa_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pb:
*               			@arg PowerSrcCFG2_Har_Pb_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pb_InsPower   
*               			@arg PowerSrcCFG2_Har_Pb_ConstPower 
*
*				  Channel = PowerSrcCFG2_Har_Pc:
*               			@arg PowerSrcCFG2_Har_Pc_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pc_InsPower   
*               			@arg PowerSrcCFG2_Har_Pc_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_Pt:
*               			@arg PowerSrcCFG2_Har_Pt_AvgPower   
*               			@arg PowerSrcCFG2_Har_Pt_InsPower   
*               			@arg PowerSrcCFG2_Har_Pt_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_P1:
*               			@arg PowerSrcCFG2_Fund_P1_AvgPower    
*               			@arg PowerSrcCFG2_Fund_P1_InsPower    
*               			@arg PowerSrcCFG2_Fund_P1_ConstPower  
*
*				  Channel = PowerSrcCFG2_Fund_P2:
*               			@arg PowerSrcCFG2_Fund_P2_AvgPower   
*               			@arg PowerSrcCFG2_Fund_P2_InsPower   
*               			@arg PowerSrcCFG2_Fund_P2_ConstPower 
*
*				  Channel = PowerSrcCFG2_Fund_Q1:
*               			@arg PowerSrcCFG2_Fund_Q1_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Q1_InsPower   
*               			@arg PowerSrcCFG2_Fund_Q1_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Fund_Q2:
*               			@arg PowerSrcCFG2_Fund_Q2_AvgPower   
*               			@arg PowerSrcCFG2_Fund_Q2_InsPower   
*               			@arg PowerSrcCFG2_Fund_Q2_ConstPower 
*
*				  Channel = PowerSrcCFG2_Har_P1:
*               			@arg PowerSrcCFG2_Har_P1_AvgPower   
*               			@arg PowerSrcCFG2_Har_P1_InsPower   
*               			@arg PowerSrcCFG2_Har_P1_ConstPower 
*               										
*				  Channel = PowerSrcCFG2_Har_P2:
*               			@arg PowerSrcCFG2_Har_P2_AvgPower   
*               			@arg PowerSrcCFG2_Har_P2_InsPower   
*               			@arg PowerSrcCFG2_Har_P2_ConstPower 
*
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerSrcCFG_Set(uint32_t SrcChnl,uint32_t Channel,uint32_t select)
{	
	assert_param(IS_HT_EMU_POWERCFG_CHANNEL_SEL(SrcChnl));    /*  assert_param  */
    
	if(ECR_PowerSrcCFG1 == SrcChnl)
	{
		HT_EMU_PowerSrcCFG1_Set(Channel,select);
	}
	else if(ECR_PowerSrcCFG2 == SrcChnl)
	{
		HT_EMU_PowerSrcCFG2_Set(Channel,select);
	}
	else
	{
		;
	}
}
/**
********************************************************************************************************
*                                      Set EMU Energy Cumulative Mode Select
* @brief : set EMU module Energy Cumulative Mode select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg PowerModeCFG_AccuMode_AllP
*               @arg PowerModeCFG_AccuMode_AllQ
*               @arg PowerModeCFG_AccuMode_S
*               @arg PowerModeCFG_AccuMode_FundP
*               @arg PowerModeCFG_AccuMode_FundQ
*               @arg PowerModeCFG_AccuMode_HarP
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = PowerModeCFG_AccuMode_AllP:
*               			@arg PowerModeCFG_AccuMode_AllP_0 
*               			@arg PowerModeCFG_AccuMode_AllP_1 
*               			@arg PowerModeCFG_AccuMode_AllP_2                			
*               			@arg PowerModeCFG_AccuMode_AllP_3                			
*								
*				  Channel = PowerModeCFG_AccuMode_AllQ:
*               			@arg PowerModeCFG_AccuMode_AllQ_0  	
*               			@arg PowerModeCFG_AccuMode_AllQ_1  	
*               			@arg PowerModeCFG_AccuMode_AllQ_2  
*               			@arg PowerModeCFG_AccuMode_AllQ_3  
*
*				  Channel = PowerModeCFG_AccuMode_S:
*               			@arg PowerModeCFG_AccuMode_S_0  
*               			@arg PowerModeCFG_AccuMode_S_1  
*               			@arg PowerModeCFG_AccuMode_S_2  
*               			@arg PowerModeCFG_AccuMode_S_3  
*
*				  Channel = PowerModeCFG_AccuMode_FundP:
*               			@arg PowerModeCFG_AccuMode_FundP_0 
*               			@arg PowerModeCFG_AccuMode_FundP_1 
*               			@arg PowerModeCFG_AccuMode_FundP_2 
*               			@arg PowerModeCFG_AccuMode_FundP_3 
*
*				  Channel = PowerModeCFG_AccuMode_FundQ:
*               			@arg PowerModeCFG_AccuMode_FundQ_0 
*               			@arg PowerModeCFG_AccuMode_FundQ_1 
*               			@arg PowerModeCFG_AccuMode_FundQ_2 
*               			@arg PowerModeCFG_AccuMode_FundQ_3 
*               										
*				  Channel = PowerModeCFG_AccuMode_HarP:
*               			@arg PowerModeCFG_AccuMode_HarP_0 
*               			@arg PowerModeCFG_AccuMode_HarP_1 
*               			@arg PowerModeCFG_AccuMode_HarP_2 
*               			@arg PowerModeCFG_AccuMode_HarP_3 
*               										
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerModeCFG_AccuModeSet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                 /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_ACCUMODE_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->PowerModeCFG;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
		case PowerModeCFG_AccuMode_AllP:
			assert_param(IS_HT_EMU_ACCUMODE_ALLP_SEL(select));    /*  assert_param  */			
			break;
		case PowerModeCFG_AccuMode_AllQ:
			assert_param(IS_HT_EMU_ACCUMODE_ALLQ_SEL(select));    /*  assert_param  */	
			break;
		case PowerModeCFG_AccuMode_S:
			assert_param(IS_HT_EMU_ACCUMODE_S_SEL(select));       /*  assert_param  */			
			break;
		case PowerModeCFG_AccuMode_FundP:
			assert_param(IS_HT_EMU_ACCUMODE_FUNDP_SEL(select));    /*  assert_param  */	
			break;
		case PowerModeCFG_AccuMode_FundQ:
			assert_param(IS_HT_EMU_ACCUMODE_FUNDQ_SEL(select));    /*  assert_param  */			
			break;
		case PowerModeCFG_AccuMode_HarP:
			assert_param(IS_HT_EMU_ACCUMODE_HARP_SEL(select));    /*  assert_param  */	
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);               /* Close write protect*/

	ultemp |= select;
	HT_EMUECA->PowerModeCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Negitive Energy  Overflow To Channel Select
* @brief : set EMU module Negitive Energy  Overflow To Channel select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg PowerModeCFG_PowerOVSel_AllP
*               @arg PowerModeCFG_PowerOVSel_AllQ
*               @arg PowerModeCFG_PowerOVSel_S
*               @arg PowerModeCFG_PowerOVSel_FundP
*               @arg PowerModeCFG_PowerOVSel_FundQ
*               @arg PowerModeCFG_PowerOVSel_HarP
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = PowerModeCFG_PowerOVSel_AllP:
*               			@arg PowerModeCFG_PowerOVSel_AllP_P 
*               			@arg PowerModeCFG_PowerOVSel_AllP_PN  
*								
*				  Channel = PowerModeCFG_PowerOVSele_AllQ:
*               			@arg PowerModeCFG_PowerOVSel_AllQ_P  	
*               			@arg PowerModeCFG_PowerOVSel_AllQ_PN   	
*
*				  Channel = PowerModeCFG_PowerOVSel_S:
*               			@arg PowerModeCFG_PowerOVSel_S_P 
*               			@arg PowerModeCFG_PowerOVSel_S_PN  
*
*				  Channel = PowerModeCFG_PowerOVSel_FundP:
*               			@arg PowerModeCFG_PowerOVSel_FundP_P 
*               			@arg PowerModeCFG_PowerOVSel_FundP_PN  
*
*				  Channel = PowerModeCFG_PowerOVSel_FundQ:
*               			@arg PowerModeCFG_PowerOVSel_FundQ_P 
*               			@arg PowerModeCFG_PowerOVSel_FundQ_PN  
*               										
*				  Channel = PowerModeCFG_PowerOVSel_HarP:
*               			@arg PowerModeCFG_PowerOVSel_HarP_P 
*               			@arg PowerModeCFG_PowerOVSel_HarP_PN  
*               										
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerModeCFG_OvSelSet(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                   /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_POWEROVSEL_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	ultemp = HT_EMUECA->PowerModeCFG;
	ultemp &= (~Channel);
	
	switch(Channel)
	{
		case PowerModeCFG_PowerOVSel_AllP:
			assert_param(IS_HT_EMU_POWEROVSEL_ALLP_SEL(select));    /*  assert_param  */			
			break;
		case PowerModeCFG_PowerOVSel_AllQ:
			assert_param(IS_HT_EMU_POWEROVSEL_ALLQ_SEL(select));    /*  assert_param  */	
			break;
		case PowerModeCFG_PowerOVSel_S:
			assert_param(IS_HT_EMU_POWEROVSEL_S_SEL(select));       /*  assert_param  */			
			break;
		case PowerModeCFG_PowerOVSel_FundP:
			assert_param(IS_HT_EMU_POWEROVSEL_FUNDP_SEL(select));    /*  assert_param  */	
			break;
		case PowerModeCFG_PowerOVSel_FundQ:
			assert_param(IS_HT_EMU_POWEROVSEL_FUNDQ_SEL(select));    /*  assert_param  */			
			break;
		case PowerModeCFG_PowerOVSel_HarP:
			assert_param(IS_HT_EMU_POWEROVSEL_HARP_SEL(select));    /*  assert_param  */	
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);                 /* Close write protect*/

	ultemp |= select;
	HT_EMUECA->PowerModeCFG = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy Cumulative Mode Select
* @brief : set EMU module Energy Cumulative Mode select
*
* @param : Channel
*  		  This parameter can be one or a combination of the following values:
*               @arg PowerModeCFG_JudgeEn_HarP  
*               @arg PowerModeCFG_JudgeEn_FundQ 
*               @arg PowerModeCFG_JudgeEn_FundP 
*               @arg PowerModeCFG_JudgeEn_S     
*               @arg PowerModeCFG_JudgeEn_AllQ  
*               @arg PowerModeCFG_JudgeEn_AllP  
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerModeCFG_JudgeEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                 /* Get Write Protect */ 

	assert_param(IS_HT_EMU_JUDGEEN_CHANNEL_SEL(Channel));     /*  assert_param  */	
	assert_param(IS_FUNCTIONAL_STATE(NewState));              /*  assert_param  */

	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);               /* Close write protect*/

	if(ENABLE == NewState)
	{
		HT_EMUECA->PowerModeCFG |= Channel;
	}
	else
	{
		HT_EMUECA->PowerModeCFG &=(~Channel);
	}
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */	
}
/**
********************************************************************************************************
*                                      Set EMU Energy CFCFG1 Channel Select
* @brief : set EMU module Energy CFCFG1 Channel select
*
* @param : Channel
*  		  This parameter can be one of the following values:
*               @arg CFCFG1_IO0
*               @arg CFCFG1_IO1
*               @arg CFCFG1_IO2
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = CFCFG1_IO0:
*               			@arg CFCFG1_IO0_PN1  
*               			@arg CFCFG1_IO0_P1   
*               			@arg CFCFG1_IO0_N1   
*               			@arg CFCFG1_IO0_PN2  
*               			@arg CFCFG1_IO0_P2   
*               			@arg CFCFG1_IO0_N2   
*               			@arg CFCFG1_IO0_PN3  
*               			@arg CFCFG1_IO0_P3   
*               			@arg CFCFG1_IO0_N3   
*               			@arg CFCFG1_IO0_PN4  
*               			@arg CFCFG1_IO0_P4   
*               			@arg CFCFG1_IO0_N4   
*               			@arg CFCFG1_IO0_PN5  
*               			@arg CFCFG1_IO0_P5   
*               			@arg CFCFG1_IO0_N5   
*               			@arg CFCFG1_IO0_PN6  
*               			@arg CFCFG1_IO0_P6   
*               			@arg CFCFG1_IO0_N6   
*								
*				  Channel = CFCFG1_IO1:
*               			@arg CFCFG1_IO1_PN2  
*               			@arg CFCFG1_IO1_P2   
*               			@arg CFCFG1_IO1_N2   
*               			@arg CFCFG1_IO1_PN1  
*               			@arg CFCFG1_IO1_P1   
*               			@arg CFCFG1_IO1_N1   
*               			@arg CFCFG1_IO1_PN3  
*               			@arg CFCFG1_IO1_P3   
*               			@arg CFCFG1_IO1_N3   
*               			@arg CFCFG1_IO1_PN4  
*               			@arg CFCFG1_IO1_P4   
*               			@arg CFCFG1_IO1_N4   
*               			@arg CFCFG1_IO1_PN5  
*               			@arg CFCFG1_IO1_P5   
*               			@arg CFCFG1_IO1_N5   
*               			@arg CFCFG1_IO1_PN6  
*               			@arg CFCFG1_IO1_P6   
*               			@arg CFCFG1_IO1_N6   
*
*				  Channel = CFCFG1_IO2:
*               			@arg CFCFG1_IO2_PN4 
*               			@arg CFCFG1_IO2_P4  
*               			@arg CFCFG1_IO2_N4  
*               			@arg CFCFG1_IO2_PN1 
*               			@arg CFCFG1_IO2_P1  
*               			@arg CFCFG1_IO2_N1  
*               			@arg CFCFG1_IO2_PN2 
*               			@arg CFCFG1_IO2_P2  
*               			@arg CFCFG1_IO2_N2  
*               			@arg CFCFG1_IO2_PN3 
*               			@arg CFCFG1_IO2_P3  
*               			@arg CFCFG1_IO2_N3  
*               			@arg CFCFG1_IO2_PN5 
*               			@arg CFCFG1_IO2_P5  
*               			@arg CFCFG1_IO2_N5  
*               			@arg CFCFG1_IO2_PN6 
*               			@arg CFCFG1_IO2_P6  
*               			@arg CFCFG1_IO2_N6  
*
*               										              										
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_CFCFG1_Set(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_CFCFG1_CHANNEL_SEL(Channel));    /*  assert_param  */


	switch(Channel)
	{
		case CFCFG1_IO0:
			assert_param(IS_HT_EMU_CFCFG_IO0_SEL(select));    /*  assert_param  */			
			break;
		case CFCFG1_IO1:
			assert_param(IS_HT_EMU_CFCFG_IO1_SEL(select));    /*  assert_param  */	
			break;
		case CFCFG1_IO2:
			assert_param(IS_HT_EMU_CFCFG_IO2_SEL(select));    /*  assert_param  */			
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	ultemp = HT_EMUECA->CFCFG1;
	ultemp &= (~Channel);
	ultemp |= select;
	HT_EMUECA->CFCFG1 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy CFCFG2 Channel Select
* @brief : set EMU module Energy CFCFG2 Channel select
*
*
* @param : Channel
*  		  This parameter can be one of the following values:
*
*               @arg CFCFG2_IO3
*               @arg CFCFG2_IO4
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = CFCFG2_IO3:
*               			@arg CFCFG2_IO3_P6  
*               			@arg CFCFG2_IO3_PN6 
*               			@arg CFCFG2_IO3_N6  
*               			@arg CFCFG2_IO3_PN1 
*               			@arg CFCFG2_IO3_P1  
*               			@arg CFCFG2_IO3_N1  
*               			@arg CFCFG2_IO3_PN2 
*               			@arg CFCFG2_IO3_P2  
*               			@arg CFCFG2_IO3_N2  
*               			@arg CFCFG2_IO3_PN3 
*               			@arg CFCFG2_IO3_P3  
*               			@arg CFCFG2_IO3_N3  
*               			@arg CFCFG2_IO3_PN4 
*               			@arg CFCFG2_IO3_P4  
*               			@arg CFCFG2_IO3_N4  
*               			@arg CFCFG2_IO3_PN5 
*               			@arg CFCFG2_IO3_P5  
*               			@arg CFCFG2_IO3_N5  
*
*				  Channel = CFCFG2_IO4:
*               			@arg CFCFG2_IO4_N6  
*               			@arg CFCFG2_IO4_PN6 
*               			@arg CFCFG2_IO4_P6  
*               			@arg CFCFG2_IO4_PN1 
*               			@arg CFCFG2_IO4_P1  
*               			@arg CFCFG2_IO4_N1  
*               			@arg CFCFG2_IO4_PN2 
*               			@arg CFCFG2_IO4_P2  
*               			@arg CFCFG2_IO4_N2  
*               			@arg CFCFG2_IO4_PN3 
*               			@arg CFCFG2_IO4_P3  
*               			@arg CFCFG2_IO4_N3  
*               			@arg CFCFG2_IO4_PN4 
*               			@arg CFCFG2_IO4_P4  
*               			@arg CFCFG2_IO4_N4  
*               			@arg CFCFG2_IO4_PN5 
*               			@arg CFCFG2_IO4_P5  
*               			@arg CFCFG2_IO4_N5  
*               										              										
*               										
* @retval: none
*
*
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_CFCFG2_Set(uint32_t Channel,uint32_t select)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	uint32_t ultemp = 0U;
	
	assert_param(IS_HT_EMU_CFCFG2_CHANNEL_SEL(Channel));    /*  assert_param  */
	
	switch(Channel)
	{
		case CFCFG2_IO3:
			assert_param(IS_HT_EMU_CFCFG_IO3_SEL(select));    /*  assert_param  */	
			break;
		case CFCFG2_IO4:
			assert_param(IS_HT_EMU_CFCFG_IO4_SEL(select));    /*  assert_param  */
			break;
		default:
			break;	
	}
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	ultemp = HT_EMUECA->CFCFG2;
	ultemp &= (~Channel);
	ultemp |= select;
	HT_EMUECA->CFCFG2 = ultemp;
	HT_EMU_WPReg_Restore(ulProtect);        /* Restore Write Protect register */
}
/**
********************************************************************************************************
*                                      Set EMU Energy CF Channel Select
* @brief : set EMU module Energy CF Channel select
*
* @param : CfCfgChnl
*  		  This parameter can be one of the following values:
*               @arg ECR_CFCFG1
*               @arg ECR_CFCFG2
*
* @param : Channel
*  		  This parameter can be one of the following values:
*
*    	 CfCfgChnl = ECR_CFCFG1:
*               @arg CFCFG1_IO0
*               @arg CFCFG1_IO1
*               @arg CFCFG1_IO2
*
*        CfCfgChnl = ECR_CFCFG2:
*               @arg CFCFG2_IO3
*               @arg CFCFG2_IO4
*
*
* @param: select: recommended data in user's manual book can be used£¬diffrent channel select one of the
*                 following values 
*				  Channel = CFCFG1_IO0:
*               			@arg CFCFG1_IO0_PN1  
*               			@arg CFCFG1_IO0_P1   
*               			@arg CFCFG1_IO0_N1   
*               			@arg CFCFG1_IO0_PN2  
*               			@arg CFCFG1_IO0_P2   
*               			@arg CFCFG1_IO0_N2   
*               			@arg CFCFG1_IO0_PN3  
*               			@arg CFCFG1_IO0_P3   
*               			@arg CFCFG1_IO0_N3   
*               			@arg CFCFG1_IO0_PN4  
*               			@arg CFCFG1_IO0_P4   
*               			@arg CFCFG1_IO0_N4   
*               			@arg CFCFG1_IO0_PN5  
*               			@arg CFCFG1_IO0_P5   
*               			@arg CFCFG1_IO0_N5   
*               			@arg CFCFG1_IO0_PN6  
*               			@arg CFCFG1_IO0_P6   
*               			@arg CFCFG1_IO0_N6   
*								
*				  Channel = CFCFG1_IO1:
*               			@arg CFCFG1_IO1_PN2  
*               			@arg CFCFG1_IO1_P2   
*               			@arg CFCFG1_IO1_N2   
*               			@arg CFCFG1_IO1_PN1  
*               			@arg CFCFG1_IO1_P1   
*               			@arg CFCFG1_IO1_N1   
*               			@arg CFCFG1_IO1_PN3  
*               			@arg CFCFG1_IO1_P3   
*               			@arg CFCFG1_IO1_N3   
*               			@arg CFCFG1_IO1_PN4  
*               			@arg CFCFG1_IO1_P4   
*               			@arg CFCFG1_IO1_N4   
*               			@arg CFCFG1_IO1_PN5  
*               			@arg CFCFG1_IO1_P5   
*               			@arg CFCFG1_IO1_N5   
*               			@arg CFCFG1_IO1_PN6  
*               			@arg CFCFG1_IO1_P6   
*               			@arg CFCFG1_IO1_N6   
*
*				  Channel = CFCFG1_IO2:
*               			@arg CFCFG1_IO2_PN4 
*               			@arg CFCFG1_IO2_P4  
*               			@arg CFCFG1_IO2_N4  
*               			@arg CFCFG1_IO2_PN1 
*               			@arg CFCFG1_IO2_P1  
*               			@arg CFCFG1_IO2_N1  
*               			@arg CFCFG1_IO2_PN2 
*               			@arg CFCFG1_IO2_P2  
*               			@arg CFCFG1_IO2_N2  
*               			@arg CFCFG1_IO2_PN3 
*               			@arg CFCFG1_IO2_P3  
*               			@arg CFCFG1_IO2_N3  
*               			@arg CFCFG1_IO2_PN5 
*               			@arg CFCFG1_IO2_P5  
*               			@arg CFCFG1_IO2_N5  
*               			@arg CFCFG1_IO2_PN6 
*               			@arg CFCFG1_IO2_P6  
*               			@arg CFCFG1_IO2_N6  
*
*				  Channel = CFCFG2_IO3:
*               			@arg CFCFG2_IO3_P6  
*               			@arg CFCFG2_IO3_PN6 
*               			@arg CFCFG2_IO3_N6  
*               			@arg CFCFG2_IO3_PN1 
*               			@arg CFCFG2_IO3_P1  
*               			@arg CFCFG2_IO3_N1  
*               			@arg CFCFG2_IO3_PN2 
*               			@arg CFCFG2_IO3_P2  
*               			@arg CFCFG2_IO3_N2  
*               			@arg CFCFG2_IO3_PN3 
*               			@arg CFCFG2_IO3_P3  
*               			@arg CFCFG2_IO3_N3  
*               			@arg CFCFG2_IO3_PN4 
*               			@arg CFCFG2_IO3_P4  
*               			@arg CFCFG2_IO3_N4  
*               			@arg CFCFG2_IO3_PN5 
*               			@arg CFCFG2_IO3_P5  
*               			@arg CFCFG2_IO3_N5  
*
*				  Channel = CFCFG2_IO4:
*               			@arg CFCFG2_IO4_N6  
*               			@arg CFCFG2_IO4_PN6 
*               			@arg CFCFG2_IO4_P6  
*               			@arg CFCFG2_IO4_PN1 
*               			@arg CFCFG2_IO4_P1  
*               			@arg CFCFG2_IO4_N1  
*               			@arg CFCFG2_IO4_PN2 
*               			@arg CFCFG2_IO4_P2  
*               			@arg CFCFG2_IO4_N2  
*               			@arg CFCFG2_IO4_PN3 
*               			@arg CFCFG2_IO4_P3  
*               			@arg CFCFG2_IO4_N3  
*               			@arg CFCFG2_IO4_PN4 
*               			@arg CFCFG2_IO4_P4  
*               			@arg CFCFG2_IO4_N4  
*               			@arg CFCFG2_IO4_PN5 
*               			@arg CFCFG2_IO4_P5  
*               			@arg CFCFG2_IO4_N5  
*               										              										
*               										
* @retval: none
*
*
*
* @note  : CFCFG1_IO0 = CFCFG2_IO3,CFCFG1_IO1 = CFCFG4_IO4
**********************************************************************************************************/
void HT_EMU_CFCFG_Set(uint32_t CfCfgChnl,uint32_t Channel,uint32_t select)
{
	assert_param(IS_HT_EMU_CFCFG_CHANNEL_SEL(CfCfgChnl));    /*  assert_param  */

	if(ECR_CFCFG1 == CfCfgChnl)
	{
		HT_EMU_CFCFG1_Set(Channel,select);
	}
	else if(ECR_CFCFG2 == CfCfgChnl)
	{
		HT_EMU_CFCFG2_Set(Channel,select);
	}
	else
	{
		;
	}
}
/**
********************************************************************************************************
*                                      Set EMU SyncSys ENABLE
* @brief : set EMU module SyncSys Filter enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncSysEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
	
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG|= SYNC_CFG_SYNCSys_En;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~SYNC_CFG_SYNCSys_En);
	}
	
	HT_EMU_WPReg_Restore(ulProtect);       /* Restore Write Protect register */
}


/**
********************************************************************************************************
*                                      Set EMU reset Sync
*
* @brief : set EMU module Reset Sync
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncReset(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    HT_SYNCECA->SYNC_CFG |= SYNC_CFG_SYNC_Reset;    
		
	HT_EMU_WPReg_Restore(ulProtect);              /* Restore Write Protect register */
}

/**
********************************************************************************************************
*                                      Set EMU Sync Channel ENABLE
* @brief : set EMU Sync Channel enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*                         @arg SYNC_CFG_SYNC_InEn (If support)                                    
*   					  @arg SYNC_CFG_SYNC_IcEn (If support)                                 
*   					  @arg SYNC_CFG_SYNC_IbEn (If support)                                   
*  						  @arg SYNC_CFG_SYNC_IaEn (If support)                                    	
*  						  @arg SYNC_CFG_SYNC_UcEn (If support)                                    		
*   					  @arg SYNC_CFG_SYNC_UbEn (If support)                                    		
*  						  @arg SYNC_CFG_SYNC_UaEn (If support) 
*
*   					  @arg SYNC_CFG_SYNC_I1En (If support)                                   
*  						  @arg SYNC_CFG_SYNC_I2En (If support)                                    	
*  						  @arg SYNC_CFG_SYNC_UEn  (If support)                                    		
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_Sync_ChannelEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;          /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));	    /*  assert_param  */
	assert_param(IS_HT_EMU_SYNC_CHANNEL_SEL(Channel));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG |= Channel;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~Channel);
	}
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU SyncOut ENABLE
* @brief : set EMU module Sync result to FFT enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncOutEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG|= SYNC_CFG_SYNCOUT_En;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~SYNC_CFG_SYNCOUT_En);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Sync to FFT Rate Select
* @brief :  sync system output to FFT rate select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SYNC_CFG_SYNC_Rate_256_1C	  
*                        @arg SYNC_CFG_SYNC_Rate_128_1C
*                        @arg SYNC_CFG_SYNC_Rate_1024_10C	
*                        @arg SYNC_CFG_SYNC_Rate_1024_12C	
*                 
*                                  
* @retval: none
*
* @note  : 1 cycle 256 points 
		   1 cycle 128 points 
		   10 cycle 1024 points 
           12 cycle 1024 points 
**********************************************************************************************************/
void HT_EMU_SyncToFFTRateSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 
	assert_param(IS_HT_EMU_SYNC_FFTRate_SEL(Type));  	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   		/* Close write protect*/
	
	ultemp = HT_SYNCECA->SYNC_CFG;
	ultemp &=(~ SYNC_CFG_SYNC_Rate );
	ultemp |= Type;
	HT_SYNCECA->SYNC_CFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Set EMU SyncSys DFT Output ENABLE
* @brief : set EMU Sync system dft output enable
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncDFTEnSet(FunctionalState NewState)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG |= SYNC_CFG_SYNC_DFTEn;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~SYNC_CFG_SYNC_DFTEn);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Sync Lpf ENABLE
* @brief : set EMU Sync system Lpf enable
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncLpfEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(DISABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG |= SYNC_CFG_SYNC_DisLpf;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~SYNC_CFG_SYNC_DisLpf);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Sync SFO ENABLE
* @brief : set EMU Sync SFO enable
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SfoEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->SYNC_CFG |= SYNC_CFG_SFO_En;
	}
	else
	{
		HT_SYNCECA->SYNC_CFG &=(~SYNC_CFG_SFO_En);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU RmsUpdHp Select
* @brief :  sync system RmsUpdHp Select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SYNC_CFG_RmsUpdHp_HALF	
*                        @arg SYNC_CFG_RmsUpdHp_ONE
*                 
*                                  
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RmsUpdHpSel(uint32_t Type)
{
    uint32_t ultemp; 
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	assert_param(IS_HT_EMU_RMSUpdHp_SEL(Type));  /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_SYNCECA->SYNC_CFG;
	ultemp &=(~SYNC_CFG_RmsUpdHp);	
	ultemp |= Type;
	HT_SYNCECA->SYNC_CFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Sync DMA_BW_MODE Select
* @brief :  sync system output to EMU InterFace bit width select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_16	
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_24
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_32
*                 
*                                  
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncToInterfaceBwSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	assert_param(IS_HT_EMU_SYNC_Interface_BWSEL(Type));  /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    ultemp = HT_SYNCECA->SYNC_CFG;
	ultemp &=(~SYNC_CFG_Sync_DMA_bw_mode);	
	ultemp |= Type;
	HT_SYNCECA->SYNC_CFG =ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Record capture mode ENABLE
* @brief :  Set EMU Record capture mode ENABLE
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RecEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->REC_CFG |= REC_CFG_REC_enable;
	}
	else
	{
		HT_SYNCECA->REC_CFG &=(~REC_CFG_REC_enable);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Set EMU Reset Non-invasive Module
*
* @brief :  Set EMU Reset Non-invasive Moudle
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RecReset(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
    HT_SYNCECA->REC_CFG |= REC_CFG_REC_reset;                                            /*!< reset flicker module */
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Non-invasive Channel Set
* @brief : set EMU Non-invasive Channel enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*                         @arg REC_CFG_REC_InEn  (If support)                                   
*   					  @arg REC_CFG_REC_IcEn  (If support)                                
*   					  @arg REC_CFG_REC_IbEn  (If support)                                  
*  						  @arg REC_CFG_REC_IaEn  (If support)                                   	
*  						  @arg REC_CFG_REC_UcEn  (If support)                                   		
*   					  @arg REC_CFG_REC_UbEn  (If support)                                   		
*  						  @arg REC_CFG_REC_UaEn  (If support)	
*
*   					  @arg REC_CFG_REC_I1En  (If support)                                  
*  						  @arg REC_CFG_REC_I2En  (If support)                                   	
*  						  @arg REC_CFG_REC_UEn   (If support)                                   		
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RecChannelEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));	    /*  assert_param  */
	assert_param(IS_HT_EMU_REC_CHANNEL_SEL(Channel));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->REC_CFG |= Channel;
	}
	else
	{
		HT_SYNCECA->REC_CFG &=(~Channel);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Record Rate Select
* @brief :  Set EMU Record Rate Select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg REC_CFG_REC_RateSelect_256	  
*                        @arg REC_CFG_REC_RateSelect_128
*                        @arg REC_CFG_REC_RateSelect_64	
*                        @arg REC_CFG_REC_RateSelect_32	
*                 
*                                  
* @retval: none
*
* @note  : 1 cycle 32 points 
		   1 cycle 64 points 
		   1 cycle 128 points 
           1 cycle 256 points
**********************************************************************************************************/
void HT_EMU_RecRateSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	assert_param(IS_HT_EMU_RECRate_SEL(Type)); /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_SYNCECA->REC_CFG;
	ultemp &= (~REC_CFG_REC_RateSelect );	
	ultemp |= Type;
	HT_SYNCECA->REC_CFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Record SignalSrc Select
* @brief :   Set EMU Record SignalSrc Select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg REC_CFG_REC_signalSrc_Sync	  
*                        @arg REC_CFG_REC_signalSrc_Gain
*                 
*                                  
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RecSignalSrcSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_RECSignalSrc_SEL(Type)); /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	ultemp = HT_SYNCECA->REC_CFG;
	ultemp &= (~REC_CFG_REC_signalSrc );	
	ultemp |= Type;
	HT_SYNCECA->REC_CFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Set EMU Record Lpf ENABLE
* @brief :  Set EMU Non-invasive module lpf enable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : REC_CFG = REC_CFG_REC_RateSelect_32,64,128 This LPF is forcibly turned on
**********************************************************************************************************/
void HT_EMU_RecLpfEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;      /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->REC_CFG |= REC_CFG_REC_lpfEn;
	}
	else
	{
		HT_SYNCECA->REC_CFG &=(~REC_CFG_REC_lpfEn);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU DFT Lpf Coefficient
* @brief : Set EMU DFT Lpf Coefficient
* @param : Type
*  		  This parameter can be one of the following values:	
*                        @arg DFT_CFG_DFT_LPF_U
*                        @arg DFT_CFG_DFT_LPF_I	
*
* @param : data:Set DFT LPF Coefficient data 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_DFTLpfCoeffSet(uint32_t Type, uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_DFTLPF_LIMIT(data));	/*  assert_param  */
	assert_param(IS_HT_EMU_DFTLPF_SEL(Type));   /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_SYNCECA->DFT_CFG;
	data &= ECR_3BIT_DATA;
	ultemp &= (~Type);
	if(Type == DFT_CFG_DFT_LPF_U)
	{
		ultemp |= data;
	}
	else 
	{
		ultemp |= (data<<4U);
	}
	HT_SYNCECA->DFT_CFG = ultemp;	
	
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU Sync DMA Right Shift
* @brief : Set EMU Sync DMA Right Shift
* @param : Type
*  		  This parameter can be one of the following values:	
*                        @arg SYNC_DMA_rShift_Ua(If support)
*                        @arg SYNC_DMA_rShift_Ub(If support)	
*                        @arg SYNC_DMA_rShift_Uc(If support)	
*                        @arg SYNC_DMA_rShift_Ia(If support)	
*                        @arg SYNC_DMA_rShift_Ib(If support)	
*                        @arg SYNC_DMA_rShift_Ic(If support)	
*                        @arg SYNC_DMA_rShift_In(If support)	
*
*                        @arg SYNC_DMA_rShift_U (If support)	
*                        @arg SYNC_DMA_rShift_I1(If support)	
*                        @arg SYNC_DMA_rShift_I2(If support)	
*
* @param : data:Set DMA Right Shift number
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_SyncDmaRShiftSet(uint32_t Type, uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;         /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_SYNCRSHIFT_LIMIT(data));	  /*  assert_param  */
	assert_param(IS_HT_EMU_SYNC_DMARSHIFT_SEL(Type)); /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);       /* Close write protect*/
	
	ultemp = HT_SYNCECA->SYNC_DMA_rShift;
	data &= ECR_4BIT_DATA;
	ultemp &= (~Type);
	switch(Type)
	{
	#if defined  HT762x
		case SYNC_DMA_rShift_Ua:
			ultemp |= data;
			break;
		case SYNC_DMA_rShift_Ub:
			ultemp |= (data<<4U);
			break;
		case SYNC_DMA_rShift_Uc:
			ultemp |= (data<<8U);
			break;
		case SYNC_DMA_rShift_Ia:
			ultemp |= (data<<12U);
			break;
		case SYNC_DMA_rShift_Ib:
			ultemp |= (data<<16U);
			break;
		case SYNC_DMA_rShift_Ic:
			ultemp |= (data<<20U);
			break;
		case SYNC_DMA_rShift_In:
			ultemp |= (data<<24U);
		break;
	#else
		case SYNC_DMA_rShift_U:
			ultemp |= data;
			break;
		case SYNC_DMA_rShift_I1:
			ultemp |= (data<<12U);
			break;
		case SYNC_DMA_rShift_I2:
			ultemp |= (data<<16U);
			break;	
	#endif
		default:
			break;	
	}
	HT_SYNCECA->SYNC_DMA_rShift = ultemp;	
	
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU HpRMS U Channel En Set
* @brief : Set EMU HpRMS U Channel enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*                         @arg HpRMS_Ctl_U_UaEnable(If support)                                     
*   					  @arg HpRMS_Ctl_U_UbEnable(If support)                                  
*   					  @arg HpRMS_Ctl_U_UcEnable(If support)  
*
*                         @arg HpRMS_Ctl_U_UEnable(If support)                                     
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_HpRmsUChannelEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));	        /*  assert_param  */
	assert_param(IS_HT_EMU_HpRMS_U_CHANNEL_SEL(Channel));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->HpRMS_Ctl_U |= Channel;
	}
	else
	{
		HT_SYNCECA->HpRMS_Ctl_U &=(~Channel);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU HpRMS I Channel En Set
* @brief : Set EMU HpRMS I Channel enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*                         @arg HpRMS_Ctl_I_IaEnable (If support)                                    
*   					  @arg HpRMS_Ctl_I_IbEnable (If support)                                 
*   					  @arg HpRMS_Ctl_I_IcEnable (If support)
*   					  @arg HpRMS_Ctl_I_InEnable (If support) 
*
*                         @arg HpRMS_Ctl_I_I1Enable (If support)                                    
*   					  @arg HpRMS_Ctl_I_I2Enable (If support)                                 
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_HpRmsIChannelEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	
	assert_param(IS_FUNCTIONAL_STATE(NewState));	        /*  assert_param  */
	assert_param(IS_HT_EMU_HpRMS_I_CHANNEL_SEL(Channel));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_SYNCECA->HpRMS_Ctl_I |= Channel;
	}
	else
	{
		HT_SYNCECA->HpRMS_Ctl_I &=(~Channel);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU HpRMS Offset U Channel Set
* @brief : EMU HpRMS Offset U Channel Set
* @param : Type
*  		  This parameter can be one of the following values:	
*                        @arg HpRMS_Ctl_U_Offset_Ua(If support)
*                        @arg HpRMS_Ctl_U_Offset_Ub(If support)	
*                        @arg HpRMS_Ctl_U_Offset_Uc(If support)	
*
*                        @arg HpRMS_Ctl_U_Offset_U (If support)
*
* @param : data:Set EMU HpRMS Offset U number
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_HpRmsOffsetUSet(uint32_t Type, uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;                /* Get Write Protect */ 
    
	assert_param(IS_HT_EMU_HpRMSOFFSET_LIMIT(data));	     /*  assert_param  */
	assert_param(IS_HT_EMU_HpRMSOFFSET_U_CHANNEL_SEL(Type)); /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);              /* Close write protect*/
	
	ultemp = HT_SYNCECA->HpRMS_Ctl_U;
	data &= ECR_6BIT_DATA;
	ultemp &= (~Type);
	switch(Type)
	{
	#if defined  HT762x
		case HpRMS_Ctl_U_Offset_Ua:
			ultemp |= (data<<1U);
			break;
		case HpRMS_Ctl_U_Offset_Ub:
			ultemp |= (data<<9U);
			break;
		case HpRMS_Ctl_U_Offset_Uc:
			ultemp |= (data<<17U);
			break;
	#else
		case HpRMS_Ctl_U_Offset_U:
			ultemp |= (data<<1U);
			break;
	#endif
		default:
			break;	
	}
	HT_SYNCECA->HpRMS_Ctl_U = ultemp;
	
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU HpRMS Offset I Channel Set
* @brief : EMU HpRMS Offset I Channel Set
* @param : Type
*  		  This parameter can be one of the following values:	
*                        @arg HpRMS_Ctl_I_Offset_Ia(If support)
*                        @arg HpRMS_Ctl_I_Offset_Ib(If support)	
*                        @arg HpRMS_Ctl_I_Offset_Ic(If support)	
*                        @arg HpRMS_Ctl_I_Offset_In(If support)	
*
*                        @arg HpRMS_Ctl_I_Offset_I1(If support)
*                        @arg HpRMS_Ctl_I_Offset_I2(If support)	
*
* @param : data:Set HpRMS Offset I number
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_HpRmsOffsetISet(uint32_t Type, uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
    
	assert_param(IS_HT_EMU_HpRMSOFFSET_LIMIT(data));	     /*  assert_param  */
	assert_param(IS_HT_EMU_HpRMSOFFSET_I_CHANNEL_SEL(Type)); /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);              /* Close write protect*/
	
	ultemp = HT_SYNCECA->HpRMS_Ctl_I;
	data &= ECR_6BIT_DATA;
	ultemp &= (~Type);
	switch(Type)
	{
	#if defined  HT762x
		case HpRMS_Ctl_I_Offset_Ia:
			ultemp |= (data<<1U);
			break;
		case HpRMS_Ctl_I_Offset_Ib:
			ultemp |= (data<<9U);
			break;
		case HpRMS_Ctl_I_Offset_Ic:
			ultemp |= (data<<17U);
			break;
		case HpRMS_Ctl_I_Offset_In:
			ultemp |= (data<<25U);
			break;
	#else
		case HpRMS_Ctl_I_Offset_I1:
			ultemp |= (data<<1U);
			break;
		case HpRMS_Ctl_I_Offset_I2:
			ultemp |= (data<<9U);
			break;	
	#endif
		default:
			break;	
	}
	HT_SYNCECA->HpRMS_Ctl_I = ultemp;	
	
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU PLL ENABLE
* @brief : set EMU module PLL enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_ADCPLLECA->PLL_CTRL |= PLL_CTRL_PLL_enable;
	}
	else
	{
		HT_ADCPLLECA->PLL_CTRL &=(~PLL_CTRL_PLL_enable);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU PLL Freeze ENABLE
* @brief : set EMU module PLL Freeze enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLFreezeSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_ADCPLLECA->PLL_CTRL |= PLL_CTRL_PLL_freeze;
	}
	else
	{
		HT_ADCPLLECA->PLL_CTRL &=(~PLL_CTRL_PLL_freeze);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Set EMU reset PLL
*
* @brief : set EMU module Reset PLL
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLReset(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;      /* Get Write Protect */ 
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    HT_ADCPLLECA->PLL_CTRL |= PLL_CTRL_PLL_reset;     
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Config EMU PLL Manual Or AUTO SFO 
* @brief : set EMU module PLL SFO AUTO or MANUAL 
*
* @param: NewState     = AUTO 
*                      = MANUAL 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLManualSfo_Config(AccessState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_ACCESS_STATE(NewState));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	if(MANUAL == NewState)
	{
		HT_ADCPLLECA->PLL_CTRL |= PLL_CTRL_PLL_manual_sfo_EN;
	}
	else
	{
		HT_ADCPLLECA->PLL_CTRL &=(~PLL_CTRL_PLL_manual_sfo_EN);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Set EMU PLL Source Select
* @brief : set EMU PLL Source select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PLL_CTRL_PLL_source_Ua(If support)	
*                        @arg PLL_CTRL_PLL_source_Ub(If support)
*                        @arg PLL_CTRL_PLL_source_Uc(If support)	
*                 
*                        @arg PLL_CTRL_PLL_source_U (If support)	
*                                  
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLSourceSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	
	assert_param(IS_HT_EMU_PLL_SOURCE_SEL(Type));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	ultemp = HT_ADCPLLECA->PLL_CTRL;
	ultemp &=(~PLL_CTRL_PLL_source);	
	ultemp |= Type;
	HT_ADCPLLECA->PLL_CTRL = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
*********************************************************************************************************
*                                       GET EMU PLL FLAG STATUS
*
* @brief : get EMU module EMU PLL LOCK & Freeze FLAG 
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg PLL_CTRL_PLL_locked_flag      
*                        @arg PLL_CTRL_PLL_freeze  
*
* @retval: ITStatus    = SET:     flag set
*                      = RESET:   flag not set
*
* @note  : none
**********************************************************************************************************/
ITStatus HT_EMU_PLLFlagStatusGet(uint32_t ITFlag)
{
	ITStatus flag;
	
	assert_param(IS_HT_EMU_PLLFLAG_CONFIG(ITFlag));    /*  assert_param  */
			
    if(HT_ADCPLLECA->PLL_CTRL & ITFlag)
    {
        flag = SET;                       
    }
    else
    {
        flag = RESET;                     
    }
	return flag;	
}
/**
********************************************************************************************************
*                                      Set EMU PLL Manual SFO Value
* @brief : Set EMU PLL Manual SFO Value
*
* @param : data:Set SFO Value data 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PLLSfoSet(uint32_t data)
{	
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
	assert_param(IS_HT_EMU_SFO_LIMIT(data));	  /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	data &= ECR_24BIT_DATA;
	HT_SYNCECA->SFO_Value = data ;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU PLL Parameters
* @brief : Set EMU PLL Parameters
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_PLL_Gain	
*                        @arg ECR_Lock_THO 			
*                        @arg ECR_AMP_THO
*                        @arg ECR_TED_Amnt
* @param : data:Set Parameters data
*
* @retval: none
*
* @note  : ECR_PLL_Gain:Recommended configuration is 0x40003000 
*		   ECR_Lock_THO:Recommended configuration is 0x00FA0 
*		   ECR_AMP_THO: Recommended configuration is 0x000064 
*		   ECR_TED_Amnt:Recommended configuration is 0x04 
**********************************************************************************************************/
void HT_EMU_PLLParameterSet(uint32_t type,uint32_t data)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	assert_param(IS_HT_EMU_PLLPARAMETER_ADDR(type));	/*  assert_param  */
			
	switch(type)
	{
		case ECR_PLL_Gain:
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
			HT_ADCPLLECA->PLL_Gain = data;
			break;
		case ECR_Lock_THO:
			assert_param(IS_HT_PLL_LockTHO_LIMIT(data));		/*  assert_param  */
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
			HT_ADCPLLECA->Lock_THO = data;
			break;
		case ECR_AMP_THO:
			assert_param(IS_HT_PLL_AmpTHO_LIMIT(data));	   		 /*  assert_param  */
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);          /* Close write protect*/
			HT_ADCPLLECA->Amp_THO = data;
			break;
		case ECR_TED_Amnt:
			assert_param(IS_HT_PLL_TEDAmnt_LIMIT(data));		/*  assert_param  */
			HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
			HT_ADCPLLECA->TED_Amnt = data;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU PowerConst Load
*
* @brief : Set EMU PowerConst Load
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PowerConstLoad(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    HT_EMUECA->PowerConstLoad = ECR_EMU_PowerConst_Load;    
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                     Set EMU UPeakUSagUIntIOV Cycle Value
* @brief : Set EMU UPeakUSagUIntIOV Cycle Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_UPeakSagCyc	
*                        @arg ECR_UIntCyc
*                        @arg ECR_IOVCyc 			
*
* @param : data:Set EMU UPeakUSagUIntIOV Cycle Value
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PeakSagIntIovCycSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UPeakSagIntIOVCyc_ADDR(type));	/*  assert_param  */
	assert_param(IS_HT_EMU_UPeakSagIntIOV_LIMIT(data));	    /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_16BIT_DATA;
	switch(type)
	{
		case ECR_UPeakSagCyc:
			HT_EMUECA->UPeakSagCyc = ulRegData;
			break;
		case ECR_UIntCyc:
			HT_EMUECA->UIntCyc = ulRegData;
			break;
		case ECR_IOVCyc:
			HT_EMUECA->IOVCyc = ulRegData;
			break;
		default:
			break;	
	}	
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                     Set EMU UPeakUSagUIntIOV Level Value
* @brief : Set EMU UPeakUSagUIntIOV Level Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_PeakLVL	
*                        @arg ECR_SagLVL 
*                        @arg ECR_IntLVL			
*                        @arg ECR_IOVLVL 	
*
* @param : data:Set EMU UPeakUSagUIntIOV Level Value
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PeakSagIntIovLvlSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UPeakSagIntIOVLVL_ADDR(type));	/*  assert_param  */
	assert_param(IS_HT_EMU_UPeakSagIntIOV_LIMIT(data));	    /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_16BIT_DATA;
	switch(type)
	{
		case ECR_PeakLVL:
			HT_EMUECA->PeakLVL = ulRegData;
			break;
		case ECR_SagLVL:
			HT_EMUECA->SagLVL = ulRegData;
			break;
		case ECR_IntLVL:
			HT_EMUECA->IntLVL = ulRegData;
			break;
		case ECR_IOVLVL:
			HT_EMUECA->IOVLVL = ulRegData;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                     Set EMU UPeakUSagUIntIOV Level Hysteresis Value
* @brief : Set EMU UPeakUSagUIntIOV Level Hysteresis Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_PeakLVLHys	
*                        @arg ECR_SagLVLHys
*                        @arg ECR_IntLVLHys			
*                        @arg ECR_IOVLVLHys 			
* @param : data:Set EMU UPeakUSagUIntIOV Level Hysteresis Value,16bit,limit<=0xffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_PeakSagIntIovHysSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UPeakSagIntIOVHys_ADDR(type));	/*  assert_param  */
	assert_param(IS_HT_EMU_UPeakSagIntIOV_LIMIT(data));	    /*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_16BIT_DATA;
	switch(type)
	{
		case ECR_PeakLVLHys:
			HT_EMUECA->PeakLVLHys = ulRegData;
			break;
		case ECR_SagLVLHys:
			HT_EMUECA->SagLVLHys = ulRegData;
			break;
		case ECR_IntLVLHys:
			HT_EMUECA->IntLVLHys = ulRegData;
			break;
		case ECR_IOVLVLHys:
			HT_EMUECA->IOVLVLHys = ulRegData;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                     Set EMU UZC_IZC Level Value
* @brief : Set EMU UZC_IZC Level Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_UZCLVL	
*                        @arg ECR_IZCLVL	
*
* @param : data:Set EMU UZC_IZC Level Value,21bit,limit<=0x1fffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ZCLvlSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UIZCLVL_ADDR(type));	    /*  assert_param  */
	assert_param(IS_HT_EMU_UIZCLVL_LIMIT(data));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_21BIT_DATA;
	switch(type)
	{
		case ECR_UZCLVL:
			HT_EMUECA->UZCLVL = ulRegData;
			break;
		case ECR_IZCLVL:
			HT_EMUECA->IZCLVL = ulRegData;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}


/**
********************************************************************************************************
*                         Set EMU UI Channel Temperature Compensate Coefficient Value
* @brief : Set EMU UI Channel Temperature Compensate Coefficient Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_TU_CCOFF_A	
*                        @arg ECR_TU_CCOFF_B
*                        @arg ECR_TU_CCOFF_C			
*                        @arg ECR_TI_CCOFF_A	
*                        @arg ECR_TI_CCOFF_B
*                        @arg ECR_TI_CCOFF_C
*                        @arg ECR_TIn_CCOFF_A(If support)	
*                        @arg ECR_TIn_CCOFF_B(If support)
*                        @arg ECR_TIn_CCOFF_C(If support)
*
* @param : data:EMU UI Channel Temperature Compensate Coefficient Value
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_AutoTcCoffSet(uint32_t type,int16_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UITCCOFF_ADDR(type));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ulRegData = (uint32_t)data;
	ulRegData &= ECR_16BIT_DATA;
	switch(type)
	{
		case ECR_TU_CCOFF_A:
			HT_EMUECA->TU_CCOFF_A = ulRegData;
			break;
		case ECR_TU_CCOFF_B:
			HT_EMUECA->TU_CCOFF_B = ulRegData;
			break;
		case ECR_TU_CCOFF_C:
			HT_EMUECA->TU_CCOFF_C = ulRegData;
			break;
		case ECR_TI_CCOFF_A:
			HT_EMUECA->TI_CCOFF_A = ulRegData;
			break;
		case ECR_TI_CCOFF_B:
			HT_EMUECA->TI_CCOFF_B = ulRegData;
			break;
		case ECR_TI_CCOFF_C:
			HT_EMUECA->TI_CCOFF_C = ulRegData;
			break;
	#if defined  HT762x
		case ECR_TIn_CCOFF_A:
			HT_EMUECA->TIn_CCOFF_A = ulRegData;
			break;
		case ECR_TIn_CCOFF_B:
			HT_EMUECA->TIn_CCOFF_B = ulRegData;
			break;
		case ECR_TIn_CCOFF_C:
			HT_EMUECA->TIn_CCOFF_C = ulRegData;
			break;
	#endif
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                   Set EMU I Channel region0_1 Level and Hysteresis Value
* @brief :  Set EMU I Channel region0_1 Level and Hysteresis Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_Iregion0	
*                        @arg ECR_Iregion1	
*                        @arg ECR_Iregion0Hys	
*                        @arg ECR_Iregion1Hys	
*
* @param : data: EMU I Channel region0_1 Level and Hysteresis Value
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RegionHysLvlSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  			/* Get Write Protect */ 
	assert_param(IS_HT_EMU_IregionLVLHys_LIMIT(data));	/*  assert_param  */
	assert_param(IS_HT_EMU_IregionLVLHys_ADDR(type));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_23BIT_DATA;
	switch(type)
	{
		case ECR_Iregion0:
			HT_EMUECA->Iregion0 = ulRegData;
			break;
		case ECR_Iregion1:
			HT_EMUECA->Iregion1 = ulRegData;
			break;
		case ECR_Iregion0Hys:
			HT_EMUECA->Iregion0Hys = ulRegData;
			break;
		case ECR_Iregion1Hys:
			HT_EMUECA->Iregion1Hys = ulRegData;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      Set EMU reset DEC Filter
*
* @brief : set EMU module Reset DEC Filter
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_DecReset(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;     /* Get Write Protect */ 
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
    HT_EMUECA->DECReset = ECR_EMU_DEC_Reset;         
		
	HT_EMU_WPReg_Restore(ulProtect);           /* Restore write protect */
}

/**
********************************************************************************************************
*                                      Set Write protection
* @brief :  Set Write protection
*
* @param: NewState       = EMU_WPREG_Unprotected 
*                        = EMUFILTER_WPREG_Unprotected
*                        = EMU_WPREG_Protected
*
* @retval: none
*
* @note  : EMU_WPREG_Unprotected: EMU & PLL write enable
*          EMUFILTER_WPREG_Unprotected:  Deccomp & FundFilter & HarFilter write enable
*		   EMU_WPREG_Protected: Write Protection enable
**********************************************************************************************************/
void HT_EMU_EMUWPREG_Set(uint32_t NewState)
{
	assert_param(IS_HT_EMUWPREG_STATE(NewState));	/*  assert_param  */
	HT_EMUECA->EMUWPREG = NewState;
}

/**
********************************************************************************************************
*                                      Set EMU module Software reset
* @brief :  Set EMU module Software reset
*
* @param : none
* @retval: none
*
* @note  : 
**********************************************************************************************************/
void HT_EMU_SRSTREG_EMUModule_Reset(void)
{
	HT_EMUECA->SRSTREG = ECR_EMU_Moudle_Reset;
}

/**
********************************************************************************************************
*                                      Set EMU EC Registers Software reset
* @brief :  Set EC Registers Software reset
*
* @param : none
* @retval: none
*
* @note  : 
**********************************************************************************************************/
void HT_EMU_SRSTREG_EMUECR_Reset(void)
{
	HT_EMUECA->SRSTREG = ECR_EMU_CReg_Reset;
}


/**
********************************************************************************************************
*                                      EMU Flicker U Channel En Set
* @brief :  Set EMU Flicker U Channel enable or disable 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
* @param : Channel
*  		  This parameter can be one of the following values:
*                         @arg FlickerCfg_FlickerUaEn (If support)                                    
*   					  @arg FlickerCfg_FlickerUbEn (If support)                                 
*   					  @arg FlickerCfg_FlickerUcEn (If support) 
*
*                         @arg FlickerCfg_FlickerUEn  (If support)                                    
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FlickerUEnSet(uint32_t Channel,FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;               /* Get Write Protect */ 
    
	assert_param(IS_FUNCTIONAL_STATE(NewState));	        /*  assert_param  */
	assert_param(IS_HT_EMU_Flicker_U_CHANNEL_SEL(Channel));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);             /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->FlickerCfg |= Channel;
	}
	else
	{
		HT_EMUECA->FlickerCfg &=(~Channel);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU Flicker Update Rate Set
* @brief : EMU Flicker Update Rate Set
* @param : data:Flicker Update Rate
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FlickerUpRateSet(uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 

	assert_param(IS_HT_EMU_FlickerUpRate_LIMIT(data));	/*  assert_param  */
		
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);         /* Close write protect*/
	
	ultemp = HT_EMUECA->FlickerCfg;
	data &= ECR_5BIT_DATA;
	ultemp &= (~FlickerCfg_UpdRate);
	ultemp |= (data<<3);
	HT_EMUECA->FlickerCfg = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                     EMU Flicker Filter left shift Value Set
* @brief : EMU Flicker Filter left shift Value Set
* @param : Type
*  		  This parameter can be one of the following values:	
*                        @arg FlickerCfg_bpf_lshift
*                        @arg FlickerCfg_hpf_lshift	
* @param : data: voltage flicker first and second filter left shift Value
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FlickerLShiftSet(uint32_t Type, uint32_t data)
{	
	uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;  /* GET Write Protect */ 
	assert_param(IS_HT_EMU_FlickerFiltershift_LIMIT(data));	/*  assert_param  */
	assert_param(IS_HT_EMU_FlickerFiltershift_SEL(Type)); /*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_EMUECA->FlickerCfg;
	data &= ECR_3BIT_DATA;
	switch(Type)
	{
		case FlickerCfg_hpf_lshift:
			ultemp &= (~Type);
			ultemp |= (data<<8U);
			HT_EMUECA->FlickerCfg = ultemp;
			break;
		case FlickerCfg_bpf_lshift:
			ultemp &= (~Type);
			ultemp |= (data<<11U);
			HT_EMUECA->FlickerCfg = ultemp;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
/**
********************************************************************************************************
*                                      Reset EMU Flicker
*
* @brief : set EMU module Reset Flicker
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FlickerReset(void)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
			
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);        /* Close write protect*/
	
    HT_EMUECA->FlickerReset = ECR_EMU_Flicker_Reset;  /*!< reset flicker module */
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                   Set EMU UI Channel RMSIt Level Value
* @brief :  Set EMU UI Channel RMSIt Level Value
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg ECR_RMSUt_THO	
*                        @arg ECR_RMSIt_THO	
* @param : data: EMU U or I Channel RMSIt Level,23bit ,limit<=0x7ffffff
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_RmsThoSet(uint32_t type,uint32_t data)
{
	uint32_t ulRegData;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_UIRMSItLVL_LIMIT(data));	/*  assert_param  */
	assert_param(IS_HT_EMU_UIRMSItLVL_ADDR(type));	/*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMU_WPREG_Unprotected);     /* Close write protect*/
	
	ulRegData = data;
	ulRegData &= ECR_23BIT_DATA;
	switch(type)
	{
	#if defined  HT762x
		case ECR_RMSUt_THO:
			HT_EMUECA->RMSUt_THO = ulRegData;
			break;
	#endif
		case ECR_RMSIt_THO:
			HT_EMUECA->RMSIt_THO = ulRegData;
			break;
		default:
			break;	
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU Fundamental & Harmonic Wave Function En Set
* @brief : set EMU Fund Har Function En
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_FundHarFuncEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
      
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_FILTERECA->FundHarCFG |= FundHarCFG_FundHar_Func_En;
	}
	else
	{
		HT_FILTERECA->FundHarCFG &=(~FundHarCFG_FundHar_Func_En);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                      EMU All Wave Function En Set
* @brief : set EMU All Wave Function En
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_AllFuncEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
    
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_FILTERECA->FundHarCFG |= FundHarCFG_All_En;
	}
	else
	{
		HT_FILTERECA->FundHarCFG &=(~FundHarCFG_All_En);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                    Set EMU Harmonic Wave Algorithm Mode Select
* @brief : Set EMU Har Wave Algorithm Mode Select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FundHarCFG_Har_AlgMode0	
*                        @arg FundHarCFG_Har_AlgMode1	
*                 
*                                  
* @retval: none
*
* @note  : FundHarCFG_Har_AlgMode0: har = all - fund
*          FundHarCFG_Har_AlgMode1: harmonic filter
**********************************************************************************************************/
void HT_EMU_HarAlgModeSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;           /* Get Write Protect */ 
	assert_param(IS_HT_EMU_HarAlgMode_SEL(Type));	    /*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_FILTERECA->FundHarCFG;
	ultemp &=(~FundHarCFG_Har_AlgMode);	
	ultemp |= Type;
	HT_FILTERECA->FundHarCFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                  Set EMU UA~IC Channel Harmonic Filter Shift Select
* @brief :  Set EMU UA~IC Channel HarFilter Shift Select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FundHarCFG_HarFilter_Shift_1	  
*                        @arg FundHarCFG_HarFilter_Shift_2
*                        @arg FundHarCFG_HarFilter_Shift_4	
*                        @arg FundHarCFG_HarFilter_Shift_8	
*                        @arg FundHarCFG_HarFilter_Shift_16	
*                        @arg FundHarCFG_HarFilter_Shift_32	
*                        @arg FundHarCFG_HarFilter_Shift_64	
*                        @arg FundHarCFG_HarFilter_Shift_128	
*                 
*                                  
* @retval: none
*
* @note  :  1 times 
*			2 times 
*			4 times 
*			8 times 
*			16 times 
*			32 times ,Har_AlgMode select Har_AlgMode0,not surport 
*			64 times ,Har_AlgMode select Har_AlgMode0,not surport 
*			128 times ,Har_AlgMode select Har_AlgMode0,not surport 
**********************************************************************************************************/
void HT_EMU_HarFilterShiftSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_HarFilShift_SEL(Type));  /*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_FILTERECA->FundHarCFG;
	ultemp &= (~FundHarCFG_HarFilter_Shift);	
	ultemp |= Type;
	HT_FILTERECA->FundHarCFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
#if defined  HT762x
/**
********************************************************************************************************
*                               Set EMU In Channel  Har Filter multifunction Select
* @brief : Set EMU In Channel  Har Filter multifunction Select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FundHarCFG_InMultiFuncSel_HAR	
*                        @arg FundHarCFG_InMultiFuncSel_OTHER	
*                 
*                                  
* @retval: none
*
* @note  : FundHarCFG_InMultiFuncSel_HAR: calculate harmonic data 
*          FundHarCFG_InMultiFuncSel_OTHER: multi-function or other function 
**********************************************************************************************************/
void HT_EMU_InMultiFuncSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_InMultiFunc_SEL(Type));	/*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_FILTERECA->FundHarCFG;
	ultemp &=(~FundHarCFG_InMultiFuncSel);	
	ultemp |= Type;
	HT_FILTERECA->FundHarCFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                    EMU Har Filter multifunction En Set
* @brief : set EMU Har Filter multifunction En 
*
* @param: NewState       = ENABLE 
*                        = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_InMultiFuncEnSet(FunctionalState NewState)
{
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_FUNCTIONAL_STATE(NewState));	/*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	if(ENABLE == NewState)
	{
		HT_FILTERECA->FundHarCFG |= FundHarCFG_InMultiFunc_En;
	}
	else
	{
		HT_FILTERECA->FundHarCFG &=(~FundHarCFG_InMultiFunc_En);
	}
		
	HT_EMU_WPReg_Restore(ulProtect);  
}

/**
********************************************************************************************************
*                                  Set EMU In Channel Harmonic Filter Shift Select
* @brief :  Set EMU In Channel HarFilter Shift Select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FundHarCFG_InHarFilterShift_1	  
*                        @arg FundHarCFG_InHarFilterShift_2
*                        @arg FundHarCFG_InHarFilterShift_4	
*                        @arg FundHarCFG_InHarFilterShift_8	
*                        @arg FundHarCFG_InHarFilterShift_16	
*                        @arg FundHarCFG_InHarFilterShift_32	
*                        @arg FundHarCFG_InHarFilterShift_64	
*                        @arg FundHarCFG_InHarFilterShift_128	
*                 
*                                  
* @retval: none
*
* @note  :  1 times 
*			2 times 
*			4 times 
*			8 times 
*			16 times 
*			32 times ,Har_AlgMode select Har_AlgMode0,not surport 
*			64 times ,Har_AlgMode select Har_AlgMode0,not surport 
*			128 times ,Har_AlgMode select Har_AlgMode0,not surport 
**********************************************************************************************************/
void HT_EMU_InHarFilterShiftSel(uint32_t Type)
{
    uint32_t ultemp;
	uint32_t ulProtect = HT_EMUECA->EMUWPREG;       /* Get Write Protect */ 
	assert_param(IS_HT_EMU_InHarFilShift_SEL(Type)); /*  assert_param  */
			
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	ultemp = HT_FILTERECA->FundHarCFG;
	ultemp &= (~FundHarCFG_InHarFilterShift);	
	ultemp |= Type;
	HT_FILTERECA->FundHarCFG = ultemp;
		
	HT_EMU_WPReg_Restore(ulProtect);  
}
#endif
/**
********************************************************************************************************
*                                      Set EMU SyncPLL init
*
* @brief : set EMU module SyncPLL init
*
* @param: SyncPLLInit
*
*         SyncPLLInit->PLL_manual_sfo
*                        @arg AUTO 
*                        @arg MANUAL 
*
*         SyncPLLInit->PLL_SourceSel:
*                        @arg PLL_CTRL_PLL_source_Ua(If support)	
*                        @arg PLL_CTRL_PLL_source_Ub(If support)
*                        @arg PLL_CTRL_PLL_source_Uc(If support)	
*                 
*                        @arg PLL_CTRL_PLL_source_U (If support)	
* 
*
*         SyncPLLInit->SyncSys_En,SyncDFT_En,SyncdisLpf_En,SyncSfo_En,Freeze_En,PLL_En:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*         SyncPLLInit->DFT_LPF_UCoeff,DFT_LPF_ICoeff:3bit,limit<=0x00000007
*
*         SyncPLLInit->PLL_Gain:32bit,limit<=0xffffffff
*
*         SyncPLLInit->Lock_THO:23bit,limit<=0xfffff
*
*         SyncPLLInit->AMP_THO:25bit,limit<=0xffffff
*
*         SyncPLLInit->TED_Amnt:8bit,limit<=0xff
*
*         SyncPLLInit->Sfo_Value:24bit,limit<=0xffffff
*         SyncPLLInit->SyncDMARshift_Ua,SyncDMARshift_Ub,SyncDMARshift_Uc,
*					   SyncDMARshift_U:
*					   		4bit,limit<=0xf
*         SyncPLLInit->SyncDMARshift_Ia,SyncDMARshift_Ib,SyncDMARshift_Ic,SyncDMARshift_In,
*                      SyncDMARshift_I1,SyncDMARshift_I2:
*                           4bit,limit<=0xf
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_SyncPLL_Init(SyncPLL_InitTypeDef *SyncPLLInit)
{
	HT_EMU_PLLEnSet(DISABLE);
	HT_EMU_SyncReset();/* reset Sync module  */
	
	if(MANUAL == SyncPLLInit->PLL_manual_sfo)
	{
		HT_EMU_PLLSfoSet(SyncPLLInit->Sfo_Value);
	}
#if defined  HT762x
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Ua,SyncPLLInit->SyncDMARshift_Ua);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Ub,SyncPLLInit->SyncDMARshift_Ub);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Uc,SyncPLLInit->SyncDMARshift_Uc);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Ia,SyncPLLInit->SyncDMARshift_Ia);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Ib,SyncPLLInit->SyncDMARshift_Ib);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_Ic,SyncPLLInit->SyncDMARshift_Ic);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_In,SyncPLLInit->SyncDMARshift_In);
#else
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_U,SyncPLLInit->SyncDMARshift_U);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_I1,SyncPLLInit->SyncDMARshift_I1);
	HT_EMU_SyncDmaRShiftSet(SYNC_DMA_rShift_I2,SyncPLLInit->SyncDMARshift_I2);
#endif
	HT_EMU_PLLManualSfo_Config(SyncPLLInit->PLL_manual_sfo);
	HT_EMU_PLLSourceSel(SyncPLLInit->PLL_SourceSel);
	HT_EMU_PLLParameterSet(ECR_PLL_Gain,SyncPLLInit->PLL_Gain);
	HT_EMU_PLLParameterSet(ECR_Lock_THO,SyncPLLInit->Lock_THO);
	HT_EMU_PLLParameterSet(ECR_AMP_THO,SyncPLLInit->AMP_THO);
	HT_EMU_PLLParameterSet(ECR_TED_Amnt,SyncPLLInit->TED_Amnt);
	HT_EMU_DFTLpfCoeffSet(DFT_CFG_DFT_LPF_U,SyncPLLInit->DFT_LPF_UCoeff);
	HT_EMU_DFTLpfCoeffSet(DFT_CFG_DFT_LPF_I,SyncPLLInit->DFT_LPF_ICoeff);
	HT_EMU_SyncSysEnSet(SyncPLLInit->SyncSys_En);
	HT_EMU_SyncDFTEnSet(SyncPLLInit->SyncDFT_En);
	HT_EMU_SyncLpfEnSet(SyncPLLInit->SyncdisLpf_En);	
	HT_EMU_SfoEnSet(SyncPLLInit->SyncSfo_En);
	HT_EMU_PLLFreezeSet(SyncPLLInit->Freeze_En);
	HT_EMU_PLLEnSet(SyncPLLInit->PLL_En);
}

/**
********************************************************************************************************
*                                      Set EMU HALF cycle Rms init
*
* @brief : Set EMU HALF cycle Rms init
*
* @param: HpRmsInit
*
*         HpRmsInit->HpRMS_Ctl_UaEnable,HpRMS_Ctl_UbEnable,HpRMS_Ctl_UcEnable,
*                    HpRMS_Ctl_UEnable:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*         HpRmsInit->HpRMS_Ctl_IaEnabl,HpRMS_Ctl_IbEnablee,HpRMS_Ctl_IcEnable,HpRMS_Ctl_InEnable,
*					 HpRMS_Ctl_I1Enable,HpRMS_Ctl_I2Enable:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*         HpRmsInit->HpRMSOffset_Ua,HpRMSOffset_Ub,HpRMSOffset_Uc,
*                    HpRMSOffset_U:
*                         6bit,limit<=0x0000003f
*
*         HpRmsInit->HpRMSOffset_Ia,HpRMSOffset_Ib,HpRMSOffset_Ic,HpRMSOffset_In,
*                    HpRMSOffset_I1,HpRMSOffset_I2:
*                    	  6bit,limit<=0x0000003f
*
* @retval: none
*
* @note  : need config other :adc_en,HT_EMU_SyncPLL_Init...
**********************************************************************************************************/
void HT_EMU_HpRms_Init(HpRms_InitTypeDef* HpRmsInit)
{
	HT_EMU_RmsUpdHpSel(HpRmsInit->HpRmsSel);
#if defined  HT762x	
	HT_EMU_HpRmsUChannelEnSet(HpRMS_Ctl_U_UaEnable,HpRmsInit->HpRMS_Ctl_UaEnable);
	HT_EMU_HpRmsUChannelEnSet(HpRMS_Ctl_U_UbEnable,HpRmsInit->HpRMS_Ctl_UbEnable);
	HT_EMU_HpRmsUChannelEnSet(HpRMS_Ctl_U_UcEnable,HpRmsInit->HpRMS_Ctl_UcEnable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_IaEnable,HpRmsInit->HpRMS_Ctl_IaEnable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_IbEnable,HpRmsInit->HpRMS_Ctl_IbEnable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_IcEnable,HpRmsInit->HpRMS_Ctl_IcEnable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_InEnable,HpRmsInit->HpRMS_Ctl_InEnable);
	
	HT_EMU_HpRmsOffsetUSet(HpRMS_Ctl_U_Offset_Ua,HpRmsInit->HpRMSOffset_Ua);
	HT_EMU_HpRmsOffsetUSet(HpRMS_Ctl_U_Offset_Ub,HpRmsInit->HpRMSOffset_Ub);
	HT_EMU_HpRmsOffsetUSet(HpRMS_Ctl_U_Offset_Uc,HpRmsInit->HpRMSOffset_Uc);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_Ia,HpRmsInit->HpRMSOffset_Ia);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_Ib,HpRmsInit->HpRMSOffset_Ib);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_Ic,HpRmsInit->HpRMSOffset_Ic);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_In,HpRmsInit->HpRMSOffset_In); 
#else
	HT_EMU_HpRmsUChannelEnSet(HpRMS_Ctl_U_UEnable,HpRmsInit->HpRMS_Ctl_UEnable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_I1Enable,HpRmsInit->HpRMS_Ctl_I1Enable);
	HT_EMU_HpRmsIChannelEnSet(HpRMS_Ctl_I_I2Enable,HpRmsInit->HpRMS_Ctl_I2Enable);

	HT_EMU_HpRmsOffsetUSet(HpRMS_Ctl_U_Offset_U,HpRmsInit->HpRMSOffset_U);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_I1,HpRmsInit->HpRMSOffset_I1);
	HT_EMU_HpRmsOffsetISet(HpRMS_Ctl_I_Offset_I2,HpRmsInit->HpRMSOffset_I2);

#endif
}
/**
********************************************************************************************************
*                                      Set EMU Record init
*
* @brief : Set EMU Record init
*
* @param: RECInit
*
*          RECInit->REC_ChannelEnState,REC_LpfEn,REC_En:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*          RECInit->REC_RateSel:
* 	                     @arg REC_RateSelect_32 
* 						 @arg REC_RateSelect_64 
* 						 @arg REC_RateSelect_128  
* 						 @arg REC_RateSelect_256  
*
*          RECInit->REC_ChannelEn:
* 	                     @arg REC_CFG_REC_UaEn (If support)
* 						 @arg REC_CFG_REC_UbEn (If support)
* 						 @arg REC_CFG_REC_UcEn (If support) 
* 						 @arg REC_CFG_REC_IaEn (If support)
* 						 @arg REC_CFG_REC_IbEn (If support)
* 						 @arg REC_CFG_REC_IcEn (If support)
* 						 @arg REC_CFG_REC_InEn (If support)

* 						 @arg REC_CFG_REC_UEn  (If support) 
* 						 @arg REC_CFG_REC_I1En (If support)
* 						 @arg REC_CFG_REC_I2En (If support)
*
*          RECInit->REC_signalSrc:
*                        @arg REC_CFG_REC_signalSrc_Sync 
*                        @arg REC_CFG_REC_signalSrc_Gain 
*
* @retval: none
*
* @note  : need config other :adc_en,HT_EMU_SyncPLL_Init...
**********************************************************************************************************/
void HT_EMU_REC_Init(REC_InitTypeDef *RECInit)
{
	HT_EMU_RecEnSet(DISABLE);
	HT_EMU_RecChannelEnSet(RECInit->REC_ChannelEn,RECInit->REC_ChannelEnState);
	HT_EMU_RecRateSel(RECInit->REC_RateSel);
	HT_EMU_RecSignalSrcSel(RECInit->REC_signalSrc);
	HT_EMU_RecLpfEnSet(RECInit->REC_LpfEn);
	HT_EMU_RecEnSet(RECInit->REC_En);
}
/**
********************************************************************************************************
*                                      Set EMU SyncFFT init
*
* @brief : Set EMU SyncFFT init
*
* @param : SyncFFTInit
*          SyncFFTInit->SyncFFT_ChannelEnState,SyncOut_En:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*          SyncFFTInit->FFT_RateSel:
*                        @arg SYNC_CFG_SYNC_Rate_256_1C	  
*                        @arg SYNC_CFG_SYNC_Rate_128_1C
*                        @arg SYNC_CFG_SYNC_Rate_1024_10C	
*                        @arg SYNC_CFG_SYNC_Rate_1024_12C	
*
*          SyncFFTInit->FFT_BWSel:
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_16	
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_24
*                        @arg SYNC_CFG_Sync_DMA_bw_mode_32
*                 
* @retval: none
*
* @note  : need config other :adc_en,HT_EMU_SyncPLL_Init...
**********************************************************************************************************/
void HT_EMU_SyncFFT_Init(SyncFFT_InitTypeDef *SyncFFTInit)
{
	HT_EMU_Sync_ChannelEnSet(SyncFFTInit->SyncFFT_ChannelEn,SyncFFTInit->SyncFFT_ChannelEnState);
	HT_EMU_SyncOutEnSet(SyncFFTInit->SyncOut_En);
	HT_EMU_SyncToFFTRateSel(SyncFFTInit->FFT_RateSel);
	HT_EMU_SyncToInterfaceBwSel(SyncFFTInit->FFT_BWSel);
}
/**
********************************************************************************************************
*                                      Set EMU DecComp init
*
* @brief : set EMU module Dec Compensation init
*
* @param : DecCompInit
*         DecCompInit->DecCompEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_DecComp_Init(DecComp_InitTypeDef *DecCompInit)
{
	uint32_t i;
	uint32_t ulProtect = 0U;
	
	if(ENABLE == DecCompInit->DecCompEn)
	{
		ulProtect = HT_EMUECA->EMUWPREG;          			/* Get Write Protect */
		HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
		for(i=0U;i<5U;i++)
		{
			*(uint32_t*)(0x4001c700U+i*4U) = (DecCompInit->DecCompCoff[i]);
		}
		HT_EMU_WPReg_Restore(ulProtect);                    /* Restore Write Protect Register*/
		
		HT_EMU_DecReset();
	}
		
	HT_EMU_ADCCFG_DecCompEnSet(DecCompInit->DecCompEn);  /* DEC compensation enable contrl*/
}
/**
********************************************************************************************************
*                                      Set EMU RMS init
*
* @brief : set EMU module Rms init
*
* @param: RmsInit
*
*         RmsInit->ItFundRmsEn,UtFundRmsEn,UFundLineRmsEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*         RmsInit->ItCfgIaEn,ItCfgIbEn,ItCfgIcEn,ItCfgInEn,UtCfgUaEn,UtCfgUbEn,UtCfgUcEn,
*                  ItCfgI1En,ItCfgI2En:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*         RmsInit->UbRms3P3Cal:
*                        @arg EMUCFG_UacSel_Ub     
*                        @arg EMUCFG_UacSel_UaSubUc
*
*         RmsInit->RmsTAvgNum,RmsAvgNum:14bit, 0x002D <= limit <= 0x2C88
*
*         RmsInit->UtRmsTho,ItRmsTho:23bit,limit<=0x7fffff
*
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Rms_Init(Rms_InitTypeDef *RmsInit)
{
	
	HT_EMU_EMUCFG_ItFundRmsEnSet(RmsInit->ItFundRmsEn);
#if defined  HT762x
	HT_EMU_EMUCFG_UtFundRmsEnSet(RmsInit->UtFundRmsEn);
	HT_EMU_EMUCFG_UFundLRmsEnSet(RmsInit->UFundLineRmsEn);

	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfgA,RmsInit->ItCfgIaEn);
	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfgB,RmsInit->ItCfgIbEn);
	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfgC,RmsInit->ItCfgIcEn);
	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfgN,RmsInit->ItCfgInEn);
	
	HT_EMU_EMUCFG_UtCfgSet(EMUCFG_UtCfgA,RmsInit->UtCfgUaEn);
	HT_EMU_EMUCFG_UtCfgSet(EMUCFG_UtCfgB,RmsInit->UtCfgUbEn);
	HT_EMU_EMUCFG_UtCfgSet(EMUCFG_UtCfgC,RmsInit->UtCfgUcEn);
#else
	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfg1,RmsInit->ItCfgI1En);
	HT_EMU_EMUCFG_ItCfgSet(EMUCFG_ItCfg2,RmsInit->ItCfgI2En);

#endif
	
	HT_EMU_AvgNumSet(ECR_AVG_RMST,RmsInit->RmsTAvgNum);
	HT_EMU_AvgNumSet(ECR_AVG_RMS,RmsInit->RmsAvgNum);
	
	HT_EMU_RmsThoSet(ECR_RMSIt_THO,RmsInit->ItRmsTho);
#if defined  HT762x
	HT_EMU_RmsThoSet(ECR_RMSUt_THO,RmsInit->UtRmsTho);
	
	HT_EMU_EMUCFG_3P3UbRmsCalSet(RmsInit->UbRms3P3Cal);
#endif
}
/**
********************************************************************************************************
*                                      Set EMU ZeroCross init
*
* @brief : set EMU module ZeroCross init
*
* @param : ZCInit
*
*          ZCInit->ZcIntSrcSel:
*                        @arg ADCCFG_ZCINTSrc_SEL_AfterHPF 
*                        @arg ADCCFG_ZCINTSrc_SEL_BeforeHPF
*                        @arg ADCCFG_ZCINTSrc_SEL_Fund     
*    
*          ZCInit->ZcIntWaySel:
*                        @arg ADCCFG_ZCd_P  
*                        @arg ADCCFG_ZCd_N  
*                        @arg ADCCFG_ZCd_PN 
*    
*          ZCInit->ZcSrcSel:
*                        @arg ADCCFG_ZcSrSel_All 
*                        @arg ADCCFG_ZcSrSel_Fund
*    
*          ZCInit->FundZcValidNum:6bit,limit<=0x3f
*
*          ZCInit->FundZcDelyNum,ZcLostMaxNum,ZcLostMinNum:9bit,limit <=0x1ff
*
*          ZCInit->UZcLvl,IZcLvl:21bit,limit<=0x1fffff
*    
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_ZC_Init(ZeroCross_InitTypeDef *ZCInit)
{
	HT_EMU_ADCCFG_ZcIntSrcSet(ZCInit->ZcIntSrcSel);
	HT_EMU_ADCCFG_ZcdSet(ZCInit->ZcIntWaySel);
	HT_EMU_ADCCFG_ZcSrcSet(ZCInit->ZcSrcSel);
	
	HT_EMU_FilterCon_FundZcDelaySet(ZCInit->FundZcDelyNum);	
	HT_EMU_ZxLostCFG_NumSet(ZXLostCFG_ZCNumMax,ZCInit->ZcLostMaxNum);
	HT_EMU_ZxLostCFG_NumSet(ZXLostCFG_ZCNumMin,ZCInit->ZcLostMinNum);
	HT_EMU_ZxLostCFG_NumSet(ZXLostCFG_NumFund,ZCInit->FundZcValidNum);

	HT_EMU_ZCLvlSet(ECR_UZCLVL, ZCInit->UZcLvl);
	HT_EMU_ZCLvlSet(ECR_IZCLVL, ZCInit->IZcLvl);

}
/**
********************************************************************************************************
*                                      Set EMU SagPeakIntIov init
*
* @brief : set EMU module peak/sag/INT/iov init
*
* @param : SagPeakIntIovInit
*          SagPeakIntIovInit->SrcSel:This parameter can be one of the following values,
*                        @arg ADCCON_PeakSagSrc_HVp 
*                        @arg ADCCON_PeakSagSrc_HRms          
*          
*          SagPeakIntIovInit->USagEn,UPeakEn,UIntEn,IovEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*          SagPeakIntIovInit->UPeakSagHCyc,UIntHCyc,IovHCyc:16bit,limit<=0xffff
*
*          SagPeakIntIovInit->USagLvl,UPeakLvl,UIntLvl,IovLvl:16bit,limit<=0xffff
*    
*          SagPeakIntIovInit->USagLvlHys,UPeakLvlHys,UIntLvlHys,IovLvlHys:16bit,limit<=0xffff
*
*
*
* @retval: none
*
* @note  : need config other :adc_en,zc_init...
**********************************************************************************************************/
void HT_EMU_SagPeakIntIov_Init(SagPeakIntIov_InitTypeDef *SagPeakIntIovInit)
{
	HT_EMU_PeakSagIntIovCycSet(ECR_UPeakSagCyc,SagPeakIntIovInit->UPeakSagHCyc);
	HT_EMU_PeakSagIntIovCycSet(ECR_UIntCyc,SagPeakIntIovInit->UIntHCyc);
	HT_EMU_PeakSagIntIovCycSet(ECR_IOVCyc,SagPeakIntIovInit->IovHCyc);

	HT_EMU_PeakSagIntIovLvlSet(ECR_SagLVL,SagPeakIntIovInit->USagLvl);
	HT_EMU_PeakSagIntIovLvlSet(ECR_PeakLVL,SagPeakIntIovInit->UPeakLvl);
	HT_EMU_PeakSagIntIovLvlSet(ECR_IntLVL,SagPeakIntIovInit->UIntLvl);
	HT_EMU_PeakSagIntIovLvlSet(ECR_IOVLVL,SagPeakIntIovInit->IovLvl);
	
	HT_EMU_PeakSagIntIovHysSet(ECR_SagLVLHys,SagPeakIntIovInit->USagLvlHys);
	HT_EMU_PeakSagIntIovHysSet(ECR_PeakLVLHys,SagPeakIntIovInit->UPeakLvlHys);
	HT_EMU_PeakSagIntIovHysSet(ECR_IntLVLHys,SagPeakIntIovInit->UIntLvlHys);
	HT_EMU_PeakSagIntIovHysSet(ECR_IOVLVLHys,SagPeakIntIovInit->IovLvlHys);

	HT_EMU_ADCCON_PeakSagSrcSet(SagPeakIntIovInit->SrcSel);

	HT_EMU_ADCCON_USagEnSet(SagPeakIntIovInit->USagEn);
	HT_EMU_ADCCON_UPeakEnSet(SagPeakIntIovInit->UPeakEn);
	HT_EMU_ADCCON_UIntEnSet(SagPeakIntIovInit->UIntEn);
	HT_EMU_ADCCON_IovEnSet(SagPeakIntIovInit->IovEn);	
}
/**
********************************************************************************************************
*                                      Set EMU ANGLE init
*
* @brief : set EMU module Angle init
*
* @param : AngInit
*         AngInit->AngBaseSel:This parameter can be one of the following values,
*                        @arg EMUCFG_AngleBaseSel_Ua(If support)
*                        @arg EMUCFG_AngleBaseSel_Ub(If support)
*                        @arg EMUCFG_AngleBaseSel_Uc(If support)
*                        @arg EMUCFG_AngleBaseSel_Ia(If support)
*                        @arg EMUCFG_AngleBaseSel_Ib(If support)
*                        @arg EMUCFG_AngleBaseSel_Ic(If support)
*                        @arg EMUCFG_AngleBaseSel_In(If support)
*                        
*                        @arg EMUCFG_AngleBaseSel_U (If support)
*                        @arg EMUCFG_AngleBaseSel_I1(If support)
*                        @arg EMUCFG_AngleBaseSel_I2(If support)
*
*         AngInit->AutoAngBaseEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Ang_Init(Ang_InitTypeDef *AngInit)
{
	HT_EMU_EMUCFG_AngBaseSet(AngInit->AngBaseSel);
	HT_EMU_EMUCFG_AutoAngBaseEnSet(AngInit->AutoAngBaseEn);
}
/**
********************************************************************************************************
*                                      Set EMU UConst init
*
* @brief : set EMU module Voltage Const init
*
* @param : UConstInit
*         UConstInit->UaConstEn,UbConstEn,UcConstEn,UConstEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*
*          UConstInit->UaConst,UbConst,UcConst,UConst:23bit,limit<=0x7fffff
*
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_UConst_Init(UConst_InitTypeDef *UConstInit)
{
#if defined  HT762x
	if(ENABLE == UConstInit->UaConstEn)
	{
		HT_EMU_UConstSet(ECR_UconstA,UConstInit->UaConst);
	}
	if(ENABLE == UConstInit->UbConstEn)
	{
		HT_EMU_UConstSet(ECR_UconstB,UConstInit->UbConst);
	}

	if(ENABLE == UConstInit->UcConstEn)
	{
		HT_EMU_UConstSet(ECR_UconstC,UConstInit->UcConst);
	}
	
	HT_EMU_FilterCon_UConstEnSet(FilterCon_UconstA_En,UConstInit->UaConstEn);
	HT_EMU_FilterCon_UConstEnSet(FilterCon_UconstB_En,UConstInit->UbConstEn);
	HT_EMU_FilterCon_UConstEnSet(FilterCon_UconstC_En,UConstInit->UcConstEn);
#else
	if(ENABLE == UConstInit->UConstEn)
	{
		HT_EMU_UConstSet(ECR_Uconst,UConstInit->UConst);
	}
	HT_EMU_FilterCon_UConstEnSet(FilterCon_Uconst_En,UConstInit->UConstEn);

#endif
}
/**
********************************************************************************************************
*                                      Set EMU MultiFilter Init
*
* @brief : set EMU module Multi-Filter Init
*
* @param : MultiFilterInit
*          MultiFilterInit->FlickerUpdRate:5bit,limit<=0x1f
*
*          MultiFilterInit->FlickerShift[1],FlickerShift[2]:3bit,limit<=0x07
*
*          MultiFilterInit->InFilterShift:        
*  		          This parameter can be one of the following values:
*                        @arg FundHarCFG_InHarFilterShift_1	  
*                        @arg FundHarCFG_InHarFilterShift_2
*                        @arg FundHarCFG_InHarFilterShift_4	
*                        @arg FundHarCFG_InHarFilterShift_8	
*                        @arg FundHarCFG_InHarFilterShift_16	
*                        @arg FundHarCFG_InHarFilterShift_32	
*                        @arg FundHarCFG_InHarFilterShift_64	
*                        @arg FundHarCFG_InHarFilterShift_128	
*
*          MultiFilterInit->FlickerShift[0]:        
*  		          This parameter can be one of the following values:
*                        @arg FundHarCFG_HarFilter_Shift_1	  
*                        @arg FundHarCFG_HarFilter_Shift_2
*                        @arg FundHarCFG_HarFilter_Shift_4	
*                        @arg FundHarCFG_HarFilter_Shift_8	
*                        @arg FundHarCFG_HarFilter_Shift_16	
*                        @arg FundHarCFG_HarFilter_Shift_32	
*                        @arg FundHarCFG_HarFilter_Shift_64	
*                        @arg FundHarCFG_HarFilter_Shift_128	
*          
*          MultiFilterInit->UaFlickerEn,UbFlickerEn,UcFlickerEn,UFlickerEn,InMultiFuncEn:
*                        @arg ENABLE 
*                        @arg DISABLE 
*    
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_MultiFilter_Init(MultiFilter_InitTypeDef *MultiFilterInit)
{
	uint32_t i,ulProtect;
	Bool UFlickerEn = FALSE;
#if defined  HT762x
	if(ENABLE == MultiFilterInit->UaFlickerEn)
	{
		UFlickerEn = TRUE;
	}
	if(ENABLE == MultiFilterInit->UbFlickerEn)
	{
		UFlickerEn = TRUE;
	}
	if(ENABLE == MultiFilterInit->UcFlickerEn)
	{
		UFlickerEn = TRUE;
	}
#else
	if(ENABLE == MultiFilterInit->UFlickerEn)
	{
		UFlickerEn = TRUE;
	}
#endif
	ulProtect = HT_EMUECA->EMUWPREG;                    /* Get Write Protect */
	HT_EMU_EMUWPREG_Set(EMUFILTER_WPREG_Unprotected);   /* Close write protect*/
	
	for(i=0U;i<16U;i++)
	{
		*(uint32_t*)(0x4001c7a0U+i*4U) = (MultiFilterInit->FilterCoff[i]);	
		if(TRUE == UFlickerEn)
		{
			*(uint32_t*)(0x4001c800U+i*4U) = (MultiFilterInit->FilterCoff[i+16]);			
		}
	#if defined  HT762x
		*(uint32_t*)(0x4001c840U+i*4U) = (MultiFilterInit->InFilterCoff[i]);
	#endif
	}
	HT_EMU_WPReg_Restore(ulProtect);                    /* Restore Write Protect Register*/
	
	if(TRUE == UFlickerEn)
	{
		HT_EMU_FlickerUpRateSet(MultiFilterInit->FlickerUpdRate);
		
		HT_EMU_HarFilterShiftSel(MultiFilterInit->FlickerShift[0]);
		
		HT_EMU_FlickerLShiftSet(FlickerCfg_hpf_lshift, MultiFilterInit->FlickerShift[1]);
		HT_EMU_FlickerLShiftSet(FlickerCfg_bpf_lshift, MultiFilterInit->FlickerShift[2]);
		HT_EMU_FlickerReset();
	}
	else
	{
		HT_EMU_HarFilterShiftSel(MultiFilterInit->HarFilterShift);
	}
#if defined  HT762x
	if(ENABLE == MultiFilterInit->InMultiFuncEn)
	{
		
		HT_EMU_InMultiFuncSel(FundHarCFG_InMultiFuncSel_OTHER);
	}
	HT_EMU_InHarFilterShiftSel(MultiFilterInit->InFilterShift);

	HT_EMU_InMultiFuncEnSet(MultiFilterInit->InMultiFuncEn);	
	HT_EMU_FlickerUEnSet(FlickerCfg_FlickerUaEn,MultiFilterInit->UaFlickerEn);
	HT_EMU_FlickerUEnSet(FlickerCfg_FlickerUbEn,MultiFilterInit->UbFlickerEn);
	HT_EMU_FlickerUEnSet(FlickerCfg_FlickerUcEn,MultiFilterInit->UcFlickerEn);
#else
	HT_EMU_FlickerUEnSet(FlickerCfg_FlickerUEn,MultiFilterInit->UFlickerEn);

#endif
	
}
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/**
**********************************************************************************************
* @brief : Register a User EMU Callback
*         To be used instead of the weak predefined callback
* @param : EMU_InitStruct EMU handle
*
* @param : pCallback pointer to the Callback function
*
* @retval: status
*
* @Note  : None
* @note: when USE_HT_EMU_REGISTER_CALLBACKS == 1U,this function shoud be called if  
*		 user want to register himself defined callback function.
************************************************************************************************
*/
StatusTypeDef HT_EMU_RegisterCallback(EMU_InitTypeDef *EMU_InitStruct, pEMU_CallbackTypeDef pCallback)
{
	StatusTypeDef status = OK;

	if (pCallback == NULL)
	{
		/* Update the error code */
		EMU_InitStruct->ErrorCode |= EMU_ERROR_INVALID_CALLBACK;

		status = ERROR;
	}
    else
    {
      	EMU_InitStruct->EmuCallback = pCallback;
        status = OK;
    }


  return status;
}

/**
*********************************************************************************************************
*                                         EMU CALLBACK
*
* @brief: EMU completed callbacks.
*
* @param: EMU_InitStruct  Pointer to a EMU_InitTypeDef structure that contains
*                the configuration information for the specified EMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_EMU_CpltCallback(EMU_InitTypeDef *EMU_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(EMU_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_EMU_CpltCallback could be implemented in the user file
   */
  
}

/**
*********************************************************************************************************
*                                         INITIAL EMU CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: EMU_InitStruct Pointer to a EMU_InitTypeDef structure that contains
*               the configuration information for the specified EMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_EMU_InitCallbacksToDefault(EMU_InitTypeDef *EMU_InitStruct)
{
	/* Init the EMU Callback settings */
	EMU_InitStruct->EmuCallback = HT_EMU_CpltCallback;            /* Legacy weak HT_EMU_Callback            */
}

/**
*********************************************************************************************************
*                                         EMU IRQ HANDLER
*
* @brief: This function handles EMU interrupt request.
*
* @param: EMU_InitStruct  Pointer to a EMU_InitTypeDef structure that contains
*                the configuration information for the specified EMU module.
* @retval: StatusTypeDef
*
* @Note: None
*********************************************************************************************************
*/
void HT_EMU_IRQHandler(EMU_InitTypeDef *EMU_InitStruct)
{
  	 /*Call registered EMU complete callback*/
	 if(EMU_InitStruct->EmuCallback != NULL)
	 {
		EMU_InitStruct->EmuCallback(EMU_InitStruct);
	 }
}
/**
******************************************************************************************
* @brief : Register a User EWU Callback
*         To be used instead of the weak predefined callback
* @param : EWU_InitStruct EWU handle
*
* @param : pCallback pointer to the Callback function
*
* @retval: status
*
* @Note  : None
* @note: when USE_HT_EWU_REGISTER_CALLBACKS == 1U,this function shoud be called if 
*		 user want to register himself defined callback function.
******************************************************************************************
*/
StatusTypeDef HT_EWU_RegisterCallback(EWU_InitTypeDef *EWU_InitStruct, pEWU_CallbackTypeDef pCallback)
{
	StatusTypeDef status = OK;

	if (pCallback == NULL)
	{
		/* Update the error code */
		EWU_InitStruct->ErrorCode |= EWU_ERROR_INVALID_CALLBACK;

		status = ERROR;
	}
    else
    {
      	EWU_InitStruct->EwuCallback = pCallback;
        status = OK;
    }


  return status;
}

/**
*********************************************************************************************************
*                                         EWU CALLBACK
*
* @brief: EWU completed callbacks.
*
* @param: EWU_InitStruct  Pointer to a EWU_InitTypeDef structure that contains
*                the configuration information for the specified EWU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_EWU_CpltCallback(EWU_InitTypeDef *EWU_InitStruct)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(EWU_InitStruct);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HT_EWU_CpltCallback could be implemented in the user file
   */
  
}

/**
*********************************************************************************************************
*                                         INITIAL EWU CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: EWU_InitStruct Pointer to a EWU_InitTypeDef structure that contains
*               the configuration information for the specified EWU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_EWU_InitCallbacksToDefault(EWU_InitTypeDef *EWU_InitStruct)
{
	/* Init the EWU Callback settings */
	EWU_InitStruct->EwuCallback = HT_EWU_CpltCallback;            /* Legacy weak HT_EWU_Callback            */
}

/**
*********************************************************************************************************
*                                         EWU IRQ HANDLER
*
* @brief: This function handles EWU interrupt request.
*
* @param: EWU_InitStruct  Pointer to a EWU_InitTypeDef structure that contains
*                the configuration information for the specified EWU module.
* @retval: StatusTypeDef
*
* @Note: None
*********************************************************************************************************
*/
void HT_EWU_IRQHandler(EWU_InitTypeDef *EWU_InitStruct)
{
  	 /*Call registered EMU complete callback*/
	 if(EWU_InitStruct->EwuCallback != NULL)
	 {
		EWU_InitStruct->EwuCallback(EWU_InitStruct);
	 }
}
#endif /* USE_HT_EMU_REGISTER_CALLBACKS */


#endif
