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
* File         : ht501x_emu.c
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used EMU Function.
*********************************************************************************************************
*/

#define  __HT50XX_EMU_C

#include <string.h>
#include <math.h>
#include "ht6xxx_lib.h"



#if defined  HT501x  ||  defined  HT502x ||  defined  HT503x                          /* This File Only support HT50xx */

/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/
#define DELAY_1MS_ADJ   ((uint32_t)11)

/*
*********************************************************************************************************
*                                             Local Variables
*********************************************************************************************************
*/

static const uint32_t RegisterWriteProtect[2]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};

/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/

#if (USE_HT_EMU_REGISTER_CALLBACKS != 1U)
#if  defined  HT501x ||defined  HT502x
/**
*********************************************************************************************************
*                                       DELAY EXAMPLES
*
* @brief: Delay function used by examples
*
* @param: mSec  number of 1 ms delay
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
static void Delay_ms(uint32_t mSec)
{
    uint32_t delay;
	
    if(mSec != 0)
    {
	    /*!< Get current system clock */
	    delay = HT_CMU_CPUClkGet();

	    /*!< delay = 1ms * mSec */
	    delay = (delay*mSec)>>DELAY_1MS_ADJ;

	    /*!< wait N ms */
	    while(delay--){}
	}
}
#endif
#endif

/**
********************************************************************************************************
*                                      ENABLE EMU MODULE
*
* @brief : Enable EMU module  
* @param : none 			
*
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Enable_emu_module(void)
{
    /*  assert_param  */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< save write protect status    */

    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< close write protect          */

    HT_CMU->CLKCTRL0 |= CMU_CLKCTRL0_EMUEN;                                /*!< open EMU module clk          */

    HT_CMU->WPREG = writeProtect;                                          /*!< restores the previous value  */
}

/**
********************************************************************************************************
*                                      ENABLE EMU MODULE

* @brief : Enable EMU module  
* @param : none 			

* @retval: none

* @note  : none
**********************************************************************************************************/
void Disable_emu_module(void)
{
    /*  assert_param  */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< save write protect status    */

    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                  /*!< close write protect          */

    HT_CMU->CLKCTRL0 &=~CMU_CLKCTRL0_EMUEN;                                 /*!< close EMU module clk         */

    HT_CMU->WPREG = writeProtect;                                           /*!< restores the previous value  */
}

/**
********************************************************************************************************
*                                      Open EMU Ldo ENABLE
* @brief : Open EMU module LDO and vref

* @param : none

* @retval: none

* @note  : none
**********************************************************************************************************/
void Open_emu_LDO(void)
{
    /*  assert_param  */
#if defined  HT503x
	HT_Set_EMU_LDO_En(ENABLE);		/*!< Enable EMU LDO        */
	HT_Set_EMU_VrefEn(ENABLE);		/*!< Enable EMU VREF       */
#else
    HT_EMUECA->ANACTRL |= 0x8000;    /*!< Enable EMU LDO        */
    HT_EMUECA->ADCCFG |= 0x2000;     /*!< Enable EMU VREF       */
#endif
	
}

/**
********************************************************************************************************
*                                      Close EMU Ldo ENABLE
* @brief : Close EMU module LDO 
*
* @param : none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Close_emu_LDO(void)
{
    /*  assert_param  */
#if defined  HT503x
	HT_Set_EMU_LDO_En(DISABLE);
#else
    HT_EMUECA->ANACTRL &= ~0x8000;                                        /*!< Close EMU LDO        */
#endif
}

/**
********************************************************************************************************
*                                      Reset EMU callibration registers
* @brief : reset EMU module callibration registers
*
*
* @param : none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Reset_EMU_ECA_Regs(void)
{
    /*  assert_param  */
    HT_EMUECA->SRSTREG = ECR_EMU_CReg_Reset;                                            /*!< reset ECA registers     */
}

/**
********************************************************************************************************
*                                      Reset EMU Module
* @brief : reset EMU module 
*
*
* @param : none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Reset_EMU_Module(void)
{
    /*  assert_param  */
    HT_EMUECA->SRSTREG = ECR_EMU_MODULE_Reset;                                            /*!< reset EMU module         */

}

#if defined  HT501x  ||  defined  HT502x
/**
********************************************************************************************************
*                                      SET EMU REACTIVE PHASE GAIN
* @brief : set EMU reactive phase gain
*
* @param : Freq
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Set_EMU_Reactive_Phase_Gain(uint32_t Freq)
{
    /*  assert_param  */
	
    if( Freq < 55U )
    {
        HT_EMUECA->QPHSCAL = QPHSCAL_50Hz;
    }
    else
    {
        HT_EMUECA->QPHSCAL = QPHSCAL_60Hz;
    }
}
#endif

/**
*********************************************************************************************************
*                                       GET SPECIFIED EMU STATUS FLAG
*
* @brief : Get EMUSR Flag Status  
* @param : ITFlag:status flag
*  		  This parameter can be one of the following values:
*                        @arg EMUSR_SFOF(If support)  
*                        @arg EMUSR_PEOF(If support)   
*                        @arg EMUSR_QEOF(If support)    
*                        @arg EMUSR_CHSTS(If support)   
*                        @arg EMUSR_TAMP  
*                        @arg EMUSR_I2GTI1(If support)
*                        @arg EMUSR_G2GTI1(If support) 
*                        @arg EMUSR_NOQLD2(If support)  
*                        @arg EMUSR_NOPLD2(If support)  
*                        @arg EMUSR_NOQLD1(If support)  
*                        @arg EMUSR_NOPLD1(If support)  
*                        @arg EMUSR_REV_CF1(If support) 			
*                        @arg EMUSR_REV_CF2(If support) 			
*                        @arg EMUSR_NOLOAD_ALLP1(If support) 		
*                        @arg EMUSR_NOLOAD_ALLQ1(If support) 		
*                        @arg EMUSR_NOLOAD_ALLP2(If support) 		
*                        @arg EMUSR_NOLOAD_ALLQ2(If support) 					
*                        @arg EMUSR_CHANELSTATUS(If support) 		
*                        @arg EMUSR_OV_ENERGYPOS_CF1(If support) 
*                        @arg EMUSR_OV_ENERGYPOS_CF2(If support) 
*                        @arg EMUSR_OV_ENERGYPOS_CF3(If support) 
*                        @arg EMUSR_OV_ENERGYNEG_CF1(If support) 
*                        @arg EMUSR_OV_ENERGYNEG_CF2(If support) 
*                        @arg EMUSR_OV_ENERGYNEG_CF3(If support) 
*                        @arg EMUSR_NOLOAD_FUNDP1(If support) 		
*                        @arg EMUSR_NOLOAD_FUNDP2(If support) 		
*                        @arg EMUSR_REV_CF3(If support) 			
*                        @arg EMUSR_ZCVALID_U(If support) 			
*                        @arg EMUSR_ZCVALID_I1(If support) 		
*                        @arg EMUSR_ZCVALID_I2(If support) 		
*                        @arg EMUSR_PEAK_STATUS(If support) 		
*                        @arg EMUSR_SAG_STATUS(If support) 		
*                        @arg EMUSR_ADC_OV_U(If support) 			
*                        @arg EMUSR_ADC_OV_I1(If support) 			
*                        @arg EMUSR_ADC_OV_I2(If support) 		
*
* @retval: ITStatus   	   = SET£º      set flag
*                          = RESET£º    not set flag
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMUSR_FlagStatusGet(uint32_t ITFlag)
{
    /*  assert_param  */
    ITStatus flag;
    assert_param(IS_HT_EMUSR_STATUS(ITFlag));
	
    if(HT_EMUECA->EMUSR & ITFlag)
    {
        flag= SET;                        /*!< EMU Interrupt Flag is set   */
    }
    else
    {
        flag= RESET;                      /*!< EMU Interrupt Flag is reset */
    }
    return flag;
}

#if defined  HT503x
/**
********************************************************************************************************
*                                      Clear EMUSR Flag BIT
* @brief : Clear EMUSR Flag Bit  
* @param : ITFlag:status flag
*  		  This parameter can be one or a combination of the following values:
*                        @arg EMUSR_OV_ENERGYPOS_CF1
*                        @arg EMUSR_OV_ENERGYPOS_CF2
*                        @arg EMUSR_OV_ENERGYPOS_CF3
*                        @arg EMUSR_OV_ENERGYNEG_CF1
*                        @arg EMUSR_OV_ENERGYNEG_CF2
*                        @arg EMUSR_OV_ENERGYNEG_CF3
*                        @arg EMUSR_ADC_OV_U			
*                        @arg EMUSR_ADC_OV_I1			
*                        @arg EMUSR_ADC_OV_I2		
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Clear_EMUSR_PendingBit(uint32_t ITFlag)
{
	/*  assert_param  */
	assert_param(IS_HT_EMUSR_STATUS_CLEAR(ITFlag));

    HT_EMUECA->EMUIF   = (uint32_t)(~ITFlag);                  /*!< Clear EMU status Flag */
}

#endif

/**
********************************************************************************************************
*                                      Set EMU Interrupt CONFIG
* @brief : Set EMU Interrupt Enable Config   
* @param : ITEn:interruput flag enable
*  		  This parameter can be one or a combination of the following values:
*                        @arg EMUIE_SAG_START	(If support) 	
*                        @arg EMUIE_PEAK_START	(If support) 
*                        @arg EMUIE_IOV_I1	(If support) 		
*                        @arg EMUIE_ZC_U	(If support) 			
*                        @arg EMUIE_SPL_UPD	(If support) 		
*                        @arg EMUIE_CF3	(If support) 			
*                        @arg EMUIE_CF2	(If support) 		
*                        @arg EMUIE_CF1	(If support) 		
*                        @arg EMUIE_IOV_I2(If support) 			
*                        @arg EMUIE_ZC_I1(If support) 			
*                        @arg EMUIE_ZC_I2(If support) 			
*                        @arg EMUIE_FASTRMS_UPD	(If support) 
*                        @arg EMUIE_SLOWRMS_UPD	(If support) 
*                        @arg EMUIE_DCAVG_UPD(If support) 		
*                        @arg EMUIE_TAMP(If support) 			
*                        @arg EMUIE_PEAK_END(If support) 			
*                        @arg EMUIE_SAG_END	(If support) 		
*                        @arg EMUIE_ZCLOST_U(If support) 		
*                        @arg EMUIE_SYNC_UPD(If support) 		
*                        @arg EMUIE_LPRMS_OV(If support) 		
*                        @arg EMUIE_RMSIT_OV(If support) 		
*                        @arg EMUIE_FUND_PRMS_UPD(If support) 	
*                        @arg EMUIE_FLICKER_UPD	(If support) 	
*                        @arg EMUIE_HCYCVP_U_UPD(If support) 		
*                        @arg EMUIE_HCYCRMS_UPD	(If support) 
*                        @arg EMUIE_CYCRMS_UPD	(If support) 
*                        @arg EMUIE_ZXLOST(If support) 
*                        @arg EMUIE_BUFFULL(If support) 
*                        @arg EMUIE_UDET(If support) 
*                        @arg EMUIE_DCUPDATE(If support) 
*                        @arg EMUIE_SRMS(If support) 
*                        @arg EMUIE_FRMS(If support) 
*                        @arg EMUIE_ZXI2(If support) 
*                        @arg EMUIE_ZXI1(If support) 
*                        @arg EMUIE_I2OV(If support) 
*                        @arg EMUIE_PF(If support) 
*                        @arg EMUIE_QF(If support) 
*                        @arg EMUIE_SF(If support) 
*                        @arg EMUIE_SPL(If support) 
*                        @arg EMUIE_ZXU(If support) 
*                        @arg EMUIE_I1OV(If support) 
*                        @arg EMUIE_UOV(If support) 
*                        @arg EMUIE_SAG(If support) 
*
* @param: NewState        = ENABLE£º  Interrupt enable  
*                         = DISABLE£º Interrupt disable
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */
	assert_param(IS_HT_EMUIE_CONFIG(ITEn));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        HT_EMUECA->EMUIE |= ITEn;            /*!< enable EMU interrupt          */
    }
    else
    {
        HT_EMUECA->EMUIE &= ~ITEn;           /*!< Disable EMU interrupt       */
    }
}
/*
*********************************************************************************************************
*                                       GET SPECIFIED EMU INTERRUPT FLAG STATUS
*
* @brief : get EMU module Interrupt flag
*
* @param : ITFlag ,This parameter can be one of the following values:   
*                        @arg EMUIF_ZXLOST(If support)
*                        @arg EMUIF_BUFFULL(If support)
*                        @arg EMUIF_UEND(If support)
*                        @arg EMUIF_USTART(If support)
*                        @arg EMUIF_DCUPDATE(If support)
*                        @arg EMUIF_SRMS(If support)
*                        @arg EMUIF_FRMS(If support)
*                        @arg EMUIF_ZXI2(If support)
*                        @arg EMUIF_ZXI1(If support)
*                        @arg EMUIF_I2OV(If support)
*                        @arg EMUIF_PF(If support)
*                        @arg EMUIF_QF(If support)
*                        @arg EMUIF_SF(If support)
*                        @arg EMUIF_SPL(If support)
*                        @arg EMUIF_ZXU(If support)
*                        @arg EMUIF_I1OV(If support)
*                        @arg EMUIF_UOV(If support)
*                        @arg EMUIF_SAG(If support)
*
*                        @arg EMUIF_SAG_START	(If support) 	
*                        @arg EMUIF_PEAK_START	(If support) 
*                        @arg EMUIF_IOV_I1	(If support) 		
*                        @arg EMUIF_ZC_U	(If support) 			
*                        @arg EMUIF_SPL_UPD	(If support) 		
*                        @arg EMUIF_CF3	(If support) 			
*                        @arg EMUIF_CF2	(If support) 		
*                        @arg EMUIF_CF1	(If support) 		
*                        @arg EMUIF_IOV_I2(If support) 			
*                        @arg EMUIF_ZC_I1(If support) 			
*                        @arg EMUIF_ZC_I2(If support) 			
*                        @arg EMUIF_FASTRMS_UPD	(If support) 
*                        @arg EMUIF_SLOWRMS_UPD	(If support) 
*                        @arg EMUIF_DCAVG_UPD(If support) 		
*                        @arg EMUIF_TAMP(If support) 			
*                        @arg EMUIF_PEAK_END(If support) 			
*                        @arg EMUIF_SAG_END	(If support) 		
*                        @arg EMUIF_ZCLOST_U(If support) 		
*                        @arg EMUIF_SYNC_UPD(If support) 		
*                        @arg EMUIF_LPRMS_OV(If support) 		
*                        @arg EMUIF_RMSIT_OV(If support) 		
*                        @arg EMUIF_FUND_PRMS_UPD(If support) 	
*                        @arg EMUIF_FLICKER_UPD	(If support) 	
*                        @arg EMUIF_HCYCVP_U_UPD(If support) 		
*                        @arg EMUIF_HCYCRMS_UPD	(If support) 
*                        @arg EMUIF_CYCRMS_UPD	(If support) 
*
* @retval: ITStatus    = SET£º      flag set
                       = RESET£º    flag not set
*
* @note  : none
*********************************************************************************************************
*/
ITStatus HT_EMU_ITFlagStatusGet(uint32_t ITFlag)
{
    /*  assert_param  */
	ITStatus flag;
	assert_param(IS_HT_EMUIF_CONFIG(ITFlag));
    if (HT_EMUECA->EMUIF & ITFlag)
    {
        flag = SET;                        /*!< EMU Interrupt Flag is set   */
    }
    else
    {
        flag = RESET;                      /*!< EMU Interrupt Flag is reset */
    }
	return flag;
}

/*
*********************************************************************************************************
*                                       CLEAR EMU INTERRUPT FLAG
*
* @brief : clear EMU module Interrupt flag
*
* @param : ITFlag This parameter can be one or a combination of the following values:
*                        @arg EMUIF_ZXLOST(If support)
*                        @arg EMUIF_BUFFULL(If support)
*                        @arg EMUIF_UEND(If support)
*                        @arg EMUIF_USTART(If support)
*                        @arg EMUIF_DCUPDATE(If support)
*                        @arg EMUIF_SRMS(If support)
*                        @arg EMUIF_FRMS(If support)
*                        @arg EMUIF_ZXI2(If support)
*                        @arg EMUIF_ZXI1(If support)
*                        @arg EMUIF_I2OV(If support)
*                        @arg EMUIF_PF(If support)
*                        @arg EMUIF_QF(If support)
*                        @arg EMUIF_SF(If support)
*                        @arg EMUIF_SPL(If support)
*                        @arg EMUIF_ZXU(If support)
*                        @arg EMUIF_I1OV(If support)
*                        @arg EMUIF_UOV(If support)
*                        @arg EMUIF_SAG(If support)
*
*                        @arg EMUIF_SAG_START	(If support)	
*                        @arg EMUIF_PEAK_START	(If support) 
*                        @arg EMUIF_IOV_I1	(If support)		
*                        @arg EMUIF_ZC_U	(If support) 			
*                        @arg EMUIF_SPL_UPD	(If support) 		
*                        @arg EMUIF_CF3	(If support)			
*                        @arg EMUIF_CF2	(If support)		
*                        @arg EMUIF_CF1	(If support) 		
*                        @arg EMUIF_IOV_I2(If support)			
*                        @arg EMUIF_ZC_I1(If support) 			
*                        @arg EMUIF_ZC_I2(If support)			
*                        @arg EMUIF_FASTRMS_UPD	(If support) 
*                        @arg EMUIF_SLOWRMS_UPD	(If support) 
*                        @arg EMUIF_DCAVG_UPD(If support) 		
*                        @arg EMUIF_TAMP(If support) 			
*                        @arg EMUIF_PEAK_END(If support)			
*                        @arg EMUIF_SAG_END	(If support) 		
*                        @arg EMUIF_ZCLOST_U(If support)		
*                        @arg EMUIF_SYNC_UPD(If support)		
*                        @arg EMUIF_LPRMS_OV(If support)		
*                        @arg EMUIF_RMSIT_OV(If support) 		
*                        @arg EMUIF_FUND_PRMS_UPD(If support) 	
*                        @arg EMUIF_FLICKER_UPD	(If support) 	
*                        @arg EMUIF_HCYCVP_U_UPD(If support)		
*                        @arg EMUIF_HCYCRMS_UPD	(If support) 
*                        @arg EMUIF_CYCRMS_UPD	(If support) 
*
* @retval: none
*
* @note  : none
*********************************************************************************************************
*/
void HT_EMU_ClearITPendingBit(uint32_t ITFlag)
{
#ifdef  USE_FULL_ASSERT
	uint8_t Flag = 0U;
	uint32_t ultemp = (uint32_t)(~EMUIF_ALL);
	
	if((0U == (ITFlag & ultemp)) && (ITFlag != 0U))
    {
      Flag = 1U;
    }

    /*  assert_param  */
	assert_param((IS_HT_EMUIF_CONFIG(ITFlag)||(Flag == 1U)));
#endif	
    HT_EMUECA->EMUIF   = ~((uint32_t)ITFlag);                  /*!< Clear EMU Interrupt Flag       */
}
#if defined HT503x
/**
*********************************************************************************************************
*                                       READ  EMU ECR REGISTER CHKSUM1 REGISTER
*
* @brief: read emu module checksum1
*
* @param: none
*
* @retval: checksum1,32 bit unsigned
*
*
* @note  : none
*********************************************************************************************************
*/
uint32_t Read_ECR_Chksum1_Reg(void)
{
  /*  assert_param  */
    return (HT_EMUEPA->CheckSum1);
}

/**
*********************************************************************************************************
*                                       READ  EMU ECR REGISTER CHKSUM2 REGISTER
*
* @brief: read emu module checksum2
*
* @param: none
*
* @retval: checksum2,32 bit unsigned
*
* @note  : none
*********************************************************************************************************
*/
uint32_t Read_ECR_Chksum2_Reg(void)
{
  /*  assert_param  */
    return (HT_EMUEPA->CheckSum2);
}
#else

/**
*********************************************************************************************************
*                                       READ  EMU ECR REGISTER CHKSUM REGISTER
*
* @brief: read emu module checksum
*
* @param: none
*
* @retval: checksum,24 bit unsigned
*
* @note  : none
*********************************************************************************************************
*/
uint32_t Read_ECR_ChksumReg(void)
{
  /*  assert_param  */
    return (HT_EMUEPA->CHECKSUM);
}
#endif

/**
********************************************************************************************************
*                                      Read EMU METERING REGISTER
*
* @brief: Read EMU module metering Register 
* @param: address:metering Register offset address 
*  		  This parameter can be one of the following values:
*                                 @arg EPR_SPLI1
*                                 @arg EPR_SPLI2
*                                 @arg EPR_SPLU
*                                 @arg ...
*                                 @arg EPR_CycRms_I1
*                                 @arg EPR_CycRms_I2
*                                 @arg EPR_CheckSum2 			
*
* @retval: The offset address of register data.
*
* @note  : none
**********************************************************************************************************/
uint32_t Read_EPR_Reg(uint32_t address)
{
	uint32_t *ptr; 
        /*  assert_param  */
	assert_param(IS_HT_EMU_EPReg_ADDR(address));
	  
	ptr = (uint32_t*)(HT_EMU_EPA_BASE + address);    
    return ((*ptr) & 0xffffffffU);
}

/**
********************************************************************************************************
*                                      Read EMU Calibration Register 
* @brief : Read EMU module Calibration Register  
* @param : address:Calibration Register  offset address 
*  		  This parameter can be one of the following values:
*                                 @arg ECR_EMUSR
*                                 @arg ECR_EMUIE
*                                 @arg ECR_EMUIF
*                                 @arg ...
*                                 @arg ECR_FundCFG  
*                                 @arg ECR_ZCNumCFG 
*                                 @arg ECR_CycRmsNum 			
*
* @retval: The offset address of register data.
*
* @note  : none
**********************************************************************************************************/
uint32_t Read_ECR_Reg(uint32_t address)
{
 
    uint32_t *ptr;
     /*  assert_param  */
    assert_param(IS_HT_EMU_ECReg_ADDR(address));
    ptr = (uint32_t*)(HT_EMU_ECA_BASE + address);
    return ((*ptr)&0xffffffffU);
}

/**
********************************************************************************************************
*                                      Write EMU Calibration Register 
* @brief : Write EMU module Calibration Register  
* @param : address:Calibration Register  offset address 
*  		  This parameter can be one of the following values:
*                                 @arg ECR_EMUSR
*                                 @arg ECR_EMUIE
*                                 @arg ECR_EMUIF
*                                 @arg ...
*                                 @arg ECR_FundCFG  
*                                 @arg ECR_ZCNumCFG 
*                                 @arg ECR_CycRmsNum 			
*
* @param : data: write to Calibration Register data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void Write_ECR_Reg(uint32_t address, uint32_t data)
{	
	uint32_t *ptr;
        /*  assert_param  */
	assert_param(IS_HT_EMU_ECReg_ADDR(address));
	ptr = (uint32_t*)(HT_EMU_ECA_BASE + address);
	*ptr = data;
}

#if  defined  HT501x ||defined  HT502x
/**
*********************************************************************************************************
*                                       SET PULSE PORT
*
* @brief : set pulse port
*
* @param : Port         PFPort typedef£º
*                           @arg PF.0, PF.1, PF.2
*           Type         PFType typedef£º
*                           @arg PFout, QFout, SFout
*           PulseWidth   PFWide typedef£º
*                           @P80ms, P40ms, P20ms, P10ms
*
* @retval: none
*
* @note  : none
*                
*********************************************************************************************************
*/
void Select_Pulse_Port(PFPort Port, PFType Type, PFWide PulseWidth)
{

  /*  assert_param  */
    HT_GPIOF->IOCFG |=  Port;          /*! < PF.0 as PFOUT, PF.1 as QFOUT (default configuration)  */
    HT_GPIOF->AFCFG &= ~Port;      /*! < default                                               */

    switch (Port)
    {
        case PF0:
          HT_EMUECA->EMCON&=~EMCON_CF1CFG;                                /*! < default: P pulse  */
          if(Type==QFout){HT_EMUECA->EMCON|=EMCON_CF1CFG_Q;}
          else if(Type==SFout){HT_EMUECA->EMCON|=EMCON_CF1CFG_S;}
          break;
        case PF1:
          HT_EMUECA->EMCON&=~EMCON_CF2CFG;                                /*! < P pulse         */
          if(Type==QFout){HT_EMUECA->EMCON|=EMCON_CF2CFG_Q;}              /*! < default           */
          else if(Type==SFout){HT_EMUECA->EMCON|=EMCON_CF2CFG_S;}
          break;
        case PF2:
          HT_EMUECA->EMCON&=~EMCON_CF3CFG; /*! < P pulse  */
          if(Type==QFout){HT_EMUECA->EMCON|=EMCON_CF3CFG_Q;}
          else if(Type==SFout){HT_EMUECA->EMCON|=EMCON_CF3CFG_S;}         /*! < default          */
          break;
        default:
          break;
    }

    HT_EMUECA->ADCCON&=~ADCCON_CFP;
    switch(PulseWidth)
    {
        case P80ms:
          HT_EMUECA->ADCCON|=ADCCON_CFP_80MS;
          break;
        case P40ms:
          HT_EMUECA->ADCCON|=ADCCON_CFP_40MS;
          break;
        case P20ms:
          HT_EMUECA->ADCCON|=ADCCON_CFP_20MS;
          break;
        case P10ms:
          HT_EMUECA->ADCCON|=ADCCON_CFP_10MS;
          break;
        default:
          break;
    }
}

/**
*********************************************************************************************************
*                                       SET VALID CHANNEL
*
* @brief : open adcEn and analog gain
*
*  @param :   ChOn    :
*               @arg EMUCTRL_AdcUon
*               @arg EMUCTRL_AdcI1on
*               @arg EMUCTRL_AdcI2on
*             ChGain  :
*               @arg  ADCCON_ANAU_1
*               @arg  ADCCON_ANAU_2
*               @arg  ADCCON_ANAU_4
*               @arg  ADCCON_ANAU_8
*               @arg  ADCCON_ANAI1_1
*               @arg  ADCCON_ANAI1_2
*               @arg  ADCCON_ANAI1_8
*               @arg  ADCCON_ANAI1_16
*               @arg  ADCCON_ANAI2_1
*               @arg  ADCCON_ANAI2_2
*               @arg  ADCCON_ANAI2_8
*               @arg  ADCCON_ANAI2_16
*
* @retval: none
*
* @note  : default U/I1/I2 adc  close,analog pga =1
*********************************************************************************************************
*/
void Set_Valid_Channel(uint32_t ChOn, uint32_t ChGain )
{
  /*  assert_param  */  
    HT_EMUECA->EMUCTRL |= ChOn;
    HT_EMUECA->ADCCON  |= ChGain;
}
#endif

#if  defined  HT502x
/**
*********************************************************************************************************
*                                       START ADCBUFF
*
* @brief : set ADC buff,save data to buff
*
* @param : none
*
* @retval: none
*
* @note  :  1. set ADC spl after hpf,update rate is 3.2kHz
*           2. read freq_u
*           3. ADC freq
*           4. write ECR_BufferCoff
*           5. set ECR_BufferStart is 0xCCC0 start save data
*
*           ADC buffer full need 46ms,flag is EMUIF.bit17
*********************************************************************************************************
*/
void Start_AdcBuff(void)
{
  /*  assert_param  */
    uint16_t Tmp16;
    uint32_t Tmp32;

    HT_EMUECA->ADCCFG&=~ADCCFG_SPL;
    HT_EMUECA->ADCCFG|=(ADCCFG_WaveSel_HPF|ADCCFG_SPL_3K2);

    Tmp32=HT_EMUEPA->FREQU;                                    /*! < read current frequency of U channel         */
	/*i =409600/Tmp;                                             
  	Tmp=12800/i;*/
    Tmp16=(uint16_t)(Tmp32/32);
    Write_ECR_Reg(ECR_BufferCoff,Tmp16);                       /*! < write coefficient register         */
    Write_ECR_Reg(ECR_BufferStart,0xCCC0);                     /*! < write start ADC buffer         */

/*  delay(0x30000); */                                           /*! < delay 50ms         */
/*  while(0==(HT_EMUECA->EMUIF&0x020000)); */                    /*! < wait for buffer full, it happened interrupt and clear this flag, this instructure will fail. */
}
#endif


#if  defined  HT502x 
/**
*********************************************************************************************************
*                                       HT EMU SAG PEAK INITIAL
*
* @brief : Sag\Peak enable Level init
*
* @param : SagPeakInit  SagPeak_InitTypeDef pointer
*
* @retval: none
*
* @note  : 1. set U Sag peak,or enable Ipeak
*          2. set U sag level,peak level,set detection cycle
*          3. set I peak level,set detection cycle
*          4. read after clear sag peak flag
*********************************************************************************************************
*/
void HT_EMU_Sag_Peak_init(SagPeak_InitTypeDef *SagPeakInit)
{
  /*  assert_param  */
    if(ENABLE==SagPeakInit->UdetEn)
    {
        HT_EMUECA->CHNLCR|=CHNLCR_Udet_En;
    }
    if(ENABLE==SagPeakInit->IpeakEn)
    {
        HT_EMUECA->CHNLCR|=CHNLCR_Ipeak_En;
    }

    HT_EMUECA->USAGLVL  = SagPeakInit->USagLvl;
    HT_EMUECA->UOVLVL = SagPeakInit->UPeakLvl;
    HT_EMUECA->OVCyc  = SagPeakInit->OVCyc;
    HT_EMUECA->IOVLVL = SagPeakInit->IPeakLvl;
    HT_EMUECA->IPEAKCYC= SagPeakInit->IDetCyc;
}
#endif

#if  defined  HT501x || defined  HT502x 
/*
*********************************************************************************************************
*                                       GET_HFCONST_VALUE_CT
*
* @brief :  CT HFConst
*
* @param : meter_EC  imp/KWh
*             U_R1      U channel sample resistor, the big one
*             U_R2      U channel sample resistor, the small one
*             U_apga    Analog gain configured in register ADCCON
*             I_R       I channel sample resistor for CT
*             CT_ratio  CT transmission rate xxxx:1, use xxxx, example: 2500:1, CT_ratio=2500
*             I_aPga    Analog gain configured in register ADCCON
*
* @retval: HFconst value,  uint32_t
*
* @note  : none
*********************************************************************************************************
*/
uint32_t Get_HFConst_value_ct(uint32_t meter_EC, uint32_t U_R1, uint32_t U_R2, uint32_t U_apga, uint32_t I_R, uint32_t CT_ratio, uint32_t I_aPga)
{
    /*  assert_param  */
    uint32_t ratio_U, ratio_I, tmp;

    ratio_U = (U_R1+U_R2)/U_R2*U_apga;
    ratio_I = CT_ratio/I_R/I_aPga;
    tmp=2332000/meter_EC*1000/ratio_U/ratio_I;
    return tmp;
}

/*
*********************************************************************************************************
*                                       GET_HFCONST_VALUE_SHUNT
*
* @brief : get shunt HFConst
*
* @param : meter_EC  imp/KWh
*             U_R1    U channel sample resistor, the big one
*             U_R2    U channel sample resistor, the small one
*             U_apga  Analog gain configured in register ADCCON
*             I_R     I channel shunt resistor, unit: ohm*10^6, example : 250uohm, I_R=250
*             APga    Analog gain configured in register ADCCON
*
* @retval: HFconst value,  uint32_t
*
* @note  : none
*********************************************************************************************************
*/
uint32_t Get_HFConst_value_Shunt(uint32_t meter_EC, uint32_t U_R1, uint32_t U_R2, uint32_t U_apga, uint32_t I_R, uint32_t I_aPga)
{
    /*  assert_param  */
    uint32_t ratio_U, ratio_I, tmp;

    ratio_U = (U_R1+U_R2)/U_R2*U_apga;
    ratio_I = 1000000/I_R/I_aPga;
    tmp=2332000/meter_EC*1000/ratio_U/ratio_I;
    return tmp;
}
#endif

#if  defined  HT503x

/**
********************************************************************************************************
*                                      Set EMU Power Gain
* @brief : Set EMU Module power gain   
* @param : type
  		  This parameter can be one of the following values:
*                        @arg AllGP1 		
*                        @arg AllGQ1 	
*                        @arg GS1 		
*                        @arg AllGP2 		
*                        @arg AllGQ2 	
*                        @arg GS2 		
*                        @arg FundGP1
*                        @arg FundGP2	
*
* @param : data:set power gain data

* @retval: none

* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerGain(PowerGP_AddrTypeDef type,int16_t data)
{
	uint32_t ulRegData;

	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERGAIN_ADDR(type));

	ulRegData = (uint32_t)data;
	ulRegData &= ECR_16BIT_DATA;
	switch(type)
	{
		case AllGP1:
			HT_EMUECA->All_GP1 = ulRegData;
			break;
		case AllGQ1:
			HT_EMUECA->All_GQ1 = ulRegData;
			break;
		case GS1:
			HT_EMUECA->GS1 = ulRegData;
			break;
		case AllGP2:
			HT_EMUECA->All_GP2 = ulRegData;
			break;
		case AllGQ2:
			HT_EMUECA->All_GQ2 = ulRegData;
			break;
		case GS2:
			HT_EMUECA->GS2 = ulRegData;
			break;		
		case FundGP1:
			HT_EMUECA->Fund_GP1 = ulRegData;
			break;
		case FundGP2:
			HT_EMUECA->Fund_GP2 = ulRegData;
			break;
		default:
			break;			
	}
}

/**
********************************************************************************************************
*                                      Get EMU Power Gain
* @brief : Get EMU Module power gain   
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllGP1 		
*                        @arg AllGQ1 	
*                        @arg GS1 		
*                        @arg AllGP2 		
*                        @arg AllGQ2 	
*                        @arg GS2 		
*                        @arg FundGP1
*                        @arg FundGP2	
*
* @param : *data: Get power gain data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_PowerGain(PowerGP_AddrTypeDef type,int16_t *data)
{
	uint32_t ulRegData = 0U;
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERGAIN_ADDR(type));

	switch(type)
	{
		case AllGP1:
			ulRegData = HT_EMUECA->All_GP1;
			break;
		case AllGQ1:
			ulRegData = HT_EMUECA->All_GQ1;
			break;
		case GS1:			
			ulRegData = HT_EMUECA->GS1;
			break;
		case AllGP2:
			ulRegData = HT_EMUECA->All_GP2;
			break;
		case AllGQ2:
			ulRegData = HT_EMUECA->All_GQ2;
			break;
		case GS2:
			ulRegData = HT_EMUECA->GS2;
			break;		
		case FundGP1:
			ulRegData = HT_EMUECA->Fund_GP1;
			break;
		case FundGP2:
			ulRegData = HT_EMUECA->Fund_GP2;
			break;
		default:
			break;			
	}
    ulRegData &= ECR_16BIT_DATA;
	*data = (int16_t)(ulRegData);
}

/**
********************************************************************************************************
*                                      Set EMU Power Phase correction
* @brief : Set EMU Module power Phase correction   
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllGphs1 		
*                        @arg AllGphs2 	
*                        @arg AllQPhsCal 		
*
* @param : data:set power phase data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerGphs(PowerGphs_AddrTypeDef type,int16_t data)
{
	uint32_t ulRegData;

	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERPHASE_ADDR(type));

	
	ulRegData = (uint32_t)data;
	ulRegData &= ECR_16BIT_DATA;
	
	switch(type)
	{
		case AllGphs1:
			HT_EMUECA->All_GPhs1 = ulRegData;
			break;
		case AllGphs2:
			HT_EMUECA->All_GPhs2 = ulRegData;
			break;
		case AllQPhsCal:
			HT_EMUECA->All_QPhsCal = ulRegData;
			break;
		default:
			break;			
	}
}

/**
********************************************************************************************************
*                                      Get EMU Power Phase correction
* @brief : Get EMU Module power Phase correction   
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllGphs1 		
*                        @arg AllGphs2 	
*                        @arg AllQPhsCal 		
*
* @param : *data:Get power phase data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_PowerGphs(PowerGphs_AddrTypeDef type,int16_t *data)
{
	uint32_t ulRegData=0U;

	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERPHASE_ADDR(type));

	switch(type)
	{
		case AllGphs1:
			ulRegData = HT_EMUECA->All_GPhs1;
			break;
		case AllGphs2:
			ulRegData = HT_EMUECA->All_GPhs2;
			break;
		case AllQPhsCal:
			ulRegData = HT_EMUECA->All_QPhsCal;
			break;
		default:
			break;			
	}
    ulRegData &= ECR_16BIT_DATA;
	*data = (int16_t)(ulRegData);
	
}

/**
********************************************************************************************************
*                                      Set EMU DEC Shift Phase correction
* @brief: Set EMU Module DEC Shift Phase correction   
* @param: DecShiftStruct:the structure of The EMU module initializes which consists of three main parameters:
*                               1) DecShiftU   : voltage channel dec shift phase correction data
*                               2) DecShiftI1  : current changnel 1 dec shift phase correction data
*                               3) DecShiftI2  : current changnel 2 dec shift phase correction data
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_DECShift(DECShift_TypeDef *DecShiftStruct)
{
	uint32_t ultemp = 0U;
	
	/*  assert_param  */
	assert_param(IS_HT_EMU_DECShift(DecShiftStruct->DecShiftU));
	assert_param(IS_HT_EMU_DECShift(DecShiftStruct->DecShiftI1));
	assert_param(IS_HT_EMU_DECShift(DecShiftStruct->DecShiftI2));

	ultemp |= (DecShiftStruct->DecShiftI2);
	ultemp <<= 8;
	ultemp |= (DecShiftStruct->DecShiftI1);
	ultemp <<= 8;
	ultemp |= (DecShiftStruct->DecShiftU);
	
	HT_EMUECA->DEC_Shift = ultemp;
}

/**
********************************************************************************************************
*                                      Get EMU DEC Shift Phase correction
* @brief: Get EMU Module DEC Shift Phase correction   
* @param: DecShiftStruct:the structure of The EMU module initializes which consists of three main parameters:
*                               1) DecShiftU   : voltage channel dec shift phase correction data
*                               2) DecShiftI1  : current changnel 1 dec shift phase correction data
*                               3) DecShiftI2  : current changnel 2 dec shift phase correction data
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_DECShift(DECShift_TypeDef *DecShiftStruct)
{
	DecShiftStruct->DecShiftU  = (uint8_t)(HT_EMUECA->DEC_Shift&ECR_7BIT_DATA);
	DecShiftStruct->DecShiftI1 = (uint8_t)((HT_EMUECA->DEC_Shift>>8)&ECR_7BIT_DATA);
	DecShiftStruct->DecShiftI2 = (uint8_t)((HT_EMUECA->DEC_Shift>>16)&ECR_7BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU ADC OFFSET correction
* @brief: Set EMU Module adc small singal offset correction   
* @param: type
*  		  This parameter can be one of the following values:
*                        @arg UOff 		
*                        @arg I1Off 	
*                        @arg I2Off 		
*
* @param: data:Set ADC offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_ADCOffset(ADCOffset_AddrTypeDef type,int16_t data)
{
	uint32_t ulRegData = 0U;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ADCOFFSET_ADDR(type));
	
	ulRegData = (uint32_t)data;
	ulRegData &= ECR_16BIT_DATA;
	
	switch(type)
	{
		case UOff:
			HT_EMUECA->ADCOffset_U = ulRegData;
			break;
		case I1Off:
			HT_EMUECA->ADCOffset_I1 = ulRegData;
			break;
		case I2Off:
			HT_EMUECA->ADCOffset_I2 = ulRegData;
			break;
		default:
			break;			
	}
}

/**
********************************************************************************************************
*                                      Get EMU ADC OFFSET correction
* @brief: Get EMU Module adc small singal offset correction   
* @param: type
*  		  This parameter can be one of the following values:
*                        @arg UOff 		
*                        @arg I1Off 	
*                        @arg I2Off 		
*
* @param: *data:Get ADC offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_ADCOffset(ADCOffset_AddrTypeDef type,int16_t *data)
{
	uint32_t ulRegData = 0U;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ADCOFFSET_ADDR(type));

	switch(type)
	{
		case UOff:
			ulRegData= HT_EMUECA->ADCOffset_U;
			break;
		case I1Off:
			ulRegData= HT_EMUECA->ADCOffset_I1;
			break;
		case I2Off:
			ulRegData= HT_EMUECA->ADCOffset_I2;
			break;
		default:
			break;			
	}
    ulRegData &= ECR_16BIT_DATA;
	*data = (int16_t)(ulRegData);
}

/**
********************************************************************************************************
*                                      Set EMU CURRENT CHANNEL 2 Gain
* @brief: Set EMU Module current channel 2 gain   
*
* @param: data:Set gain data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_I2Gain(int16_t data)
{
	HT_EMUECA->Gain_I2 = ((uint32_t)data)&ECR_16BIT_DATA;
}

/**
********************************************************************************************************
*                                      Get EMU CURRENT CHANNEL 2 Gain
* @brief: Get EMU Module current channel 2 gain   
*
* @param: data:Get gain data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_I2Gain(int16_t *data)
{
    uint32_t ultemp;
    ultemp = HT_EMUECA->Gain_I2&ECR_16BIT_DATA;
	*data = (int16_t)(ultemp);
}

/**
********************************************************************************************************
*                                      Set EMU HFCONST
* @brief: Set EMU Module HFConst   
*
* @param: data:Set HFConst data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_HFConst(uint32_t data)
{
	/*  assert_param  */
	assert_param(IS_HT_EMU_HFCONST(data));
	HT_EMUECA->HFConst = data&ECR_21BIT_DATA;
}

/**
********************************************************************************************************
*                                      Get EMU HFCONST
* @brief : Get EMU Module HFConst   
*
* @param : none
*
* @retval: hfconst data
*
* @note  : none
**********************************************************************************************************/
uint32_t HT_Get_EMU_HFConst(void)
{
	return (HT_EMUECA->HFConst);
}

/**
********************************************************************************************************
*                                      Set EMU UCONST
* @brief : Set EMU Module voltage channel Constant   
*
* @param : data:Set UConst data
*
* @retval: none
*
* @note  : commonly used in low power mode
**********************************************************************************************************/
void HT_Set_EMU_UConst(uint16_t data)
{	
	HT_EMUECA->UConst = (uint32_t)data;
}

/**
********************************************************************************************************
*                                      Get EMU UCONST
* @brief : Get EMU Module voltage channel Constant   
*
* @param : none
*
* @retval: voltage constant data
*
* @note  : commonly used in low power mode
**********************************************************************************************************/
uint32_t HT_Get_EMU_UConst(void)
{
	return (HT_EMUECA->UConst&ECR_16BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU IPTAMP
* @brief : set EMU module stealing electricity detection threshold  
*
* @param : data:Set IPtamp data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_IPTamp(uint16_t data)
{	
	HT_EMUECA->IPTAMP = (uint32_t)data;
}

/**
********************************************************************************************************
*                                      Set EMU ICHK
* @brief : set EMU module stealing electricity threshold  
*
* @param : data:Set ICHK data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_ICHK(uint8_t data)
{	
	HT_EMUECA->ICHK = (uint32_t)data;
}

/**
********************************************************************************************************
*                                      Set EMU Low Power Mode Idle Time
* @brief : Set EMU Low Power Mode Idle Time  
*
* @param : data:Set time data
*
* @retval: none
*
* @note  : commonly used in low power mode
**********************************************************************************************************/
void HT_Set_EMU_LpIdleTime(uint16_t data)
{
	/*  assert_param  */
	assert_param(IS_HT_EMU_LPIDLETIME(data));
	HT_EMUECA->LpIdleTime = (uint32_t)(data&ECR_10BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU AFDIV
* @brief : Set EMU module power pulse rate   
*
* @param : data:Set rate data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_AFDIV(uint16_t data)
{	
	assert_param(IS_HT_EMU_AFDIV(data));
	HT_EMUECA->AFDIV = (uint32_t)(data&ECR_15BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU Power RMS AVG NUM
* @brief : Set EMU module power and RMS average points  
*
* @param : data:Set points data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerRmsAvgNum(uint16_t data)
{
	/*  assert_param  */
	assert_param(IS_HT_EMU_PRMS_AVGNUM(data));
	HT_EMUECA->AVG_PowerRMS = (uint32_t)(data&ECR_14BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU Low Power Mode RMS THRESHOLD 
* @brief : Set EMU module low power mode rms threshold 
*
* @param : data:Set threshold data
*
* @retval: none
*
* @note  : commonly used in low power mode
**********************************************************************************************************/
void HT_Set_EMU_LpRmsTHO(uint16_t data)
{	
	HT_EMUECA->LpRMS_THO = (uint32_t)(data);
}

/**
********************************************************************************************************
*                                      Set EMU Current RMS VECTOR THRESHOLD
* @brief : Set EMU module current rms vector threshold
*
* @param : data:Set threshold data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_RmsItTHO(uint16_t data)
{	
	HT_EMUECA->RMSIt_THO = (uint32_t)(data);
}

/**
********************************************************************************************************
*                                      Set EMU CFXCNT
* @brief : Set EMU module fast pulse counter
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg CF1Cnt	
*                        @arg CF2Cnt
*                        @arg CF3Cnt 		
*                        @arg CF1CntN	
*                        @arg CF2CntN
*                        @arg CF3CntN 		
*
* @param : data:Set counter data
*
* @retval: none
*
* @note  : 1)EMUCON2->bit4=1:bit21 is sign ,bit20~0 is data bit,EMUCON2->bit4=1:bit15 is sign,bit14~0 is data bit
*          2)set data need abs(cfxcnt)<HFCONST
**********************************************************************************************************/
void HT_Set_EMU_CFxCnt(CFxCnt_AddrTypeDef type,uint32_t data)
{	
	/*  assert_param  */
	assert_param(IS_HT_EMU_CFXCNT_ADDR(type));
	assert_param(IS_HT_EMU_CFXCNT_NUM(data));
	
	data &= ECR_22BIT_DATA;
	
	switch(type)
	{
		case CF1Cnt:
			HT_EMUECA->CF1Cnt = data;
			break;
		case CF2Cnt:
			HT_EMUECA->CF2Cnt = data;
			break;
		case CF3Cnt:
			HT_EMUECA->CF3Cnt = data;
			break;
		case CF1CntN:
			HT_EMUECA->CF1CntN = data;
			break;
		case CF2CntN:
			HT_EMUECA->CF2CntN = data;
			break;
		case CF3CntN:
			HT_EMUECA->CF3CntN = data;
			break;
		default:
			break;	
	}
}

/**
********************************************************************************************************
*                                      Get EMU CFXCNT
* @brief : Get EMU module fast pulse counter
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg CF1Cnt	
*                        @arg CF2Cnt
*                        @arg CF3Cnt 		
*                        @arg CF1CntN	
*                        @arg CF2CntN
*                        @arg CF3CntN 		
*
* @param : data:Get counter data
*
* @retval: none
*
* @note  :  1)EMUCON2->bit4=1:bit21 is sign,bit20~0 is data bit,EMUCON2->bit4=1:bit15 is sign,bit14~0 is data bit
**********************************************************************************************************/
void HT_Get_EMU_CFxCnt(CFxCnt_AddrTypeDef type,uint32_t *data)
{
	uint32_t ulRegData = 0U;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CFXCNT_ADDR(type));
	
	switch(type)
	{
		case CF1Cnt:
			ulRegData = HT_EMUECA->CF1Cnt;
			break;
		case CF2Cnt:
			ulRegData = HT_EMUECA->CF2Cnt;
			break;
		case CF3Cnt:
			ulRegData = HT_EMUECA->CF3Cnt;
			break;
		case CF1CntN:
			ulRegData = HT_EMUECA->CF1CntN;
			break;
		case CF2CntN:
			ulRegData = HT_EMUECA->CF2CntN;
			break;
		case CF3CntN:
			ulRegData = HT_EMUECA->CF3CntN;
			break;
		default:
			break;	
	}	
    ulRegData &=ECR_22BIT_DATA;
	*data =(uint32_t)(ulRegData);
}

/**
********************************************************************************************************
*                                      Set EMU Power Offset
* @brief : Set EMU module power offset
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllP1Off	
*                        @arg AllQ1Off
*                        @arg AllP2Off 		
*                        @arg AllQ2Off	
*                        @arg FundP1Off
*                        @arg FundP2Off 		
*
* @param : data:Set offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerOffset(PowerOffset_AddrTypeDef type,int16_t data)
{
	uint32_t ulRegData;
	
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWEROFFSET_ADDR(type));
	
	
	ulRegData = (uint32_t)data;
	ulRegData &= ECR_16BIT_DATA;
	
	switch(type)
	{
		case AllP1Off:
			HT_EMUECA->All_PowerOffset_P1 = ulRegData;
			break;
		case AllQ1Off:
			HT_EMUECA->All_PowerOffset_Q1 = ulRegData;
			break;
		case AllP2Off:
			HT_EMUECA->All_PowerOffset_P2 = ulRegData;
			break;
		case AllQ2Off:
			HT_EMUECA->All_PowerOffset_Q2 = ulRegData;
			break;
		case FundP1Off:
			HT_EMUECA->Fund_PowerOffset_P1 = ulRegData;
			break;
		case FundP2Off:
			HT_EMUECA->Fund_PowerOffset_P2 = ulRegData;
			break;
		default:
			break;	
	}
}

/**
********************************************************************************************************
*                                      Get EMU Power Offset
* @brief : Get EMU module power offset
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllP1Off	
*                        @arg AllQ1Off
*                        @arg AllP2Off 		
*                        @arg AllQ2Off	
*                        @arg FundP1Off
*                        @arg FundP2Off 		
*
* @param : data:Get offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_PowerOffset(PowerOffset_AddrTypeDef type,int16_t *data)
{
	uint32_t ulRegData;
	
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWEROFFSET_ADDR(type));

	switch(type)
	{
		case AllP1Off:
			ulRegData = HT_EMUECA->All_PowerOffset_P1;
			break;
		case AllQ1Off:
			ulRegData = HT_EMUECA->All_PowerOffset_Q1;
			break;
		case AllP2Off:
			ulRegData = HT_EMUECA->All_PowerOffset_P2;
			break;
		case AllQ2Off:
			ulRegData = HT_EMUECA->All_PowerOffset_Q2;
			break;
		case FundP1Off:
			ulRegData = HT_EMUECA->Fund_PowerOffset_P1;
			break;
		case FundP2Off:
			ulRegData = HT_EMUECA->Fund_PowerOffset_P2;
			break;
		default:
			break;	
	}
    ulRegData &= ECR_16BIT_DATA;
	*data = (int16_t)(ulRegData);
}

/**
********************************************************************************************************
*                                      Set EMU RMS Offset
* @brief : Set EMU module RMS offset
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllRmsUoff	
*                        @arg AllRmsI1off
*                        @arg AllRmsI2off 		
*                        @arg FundRmsUoff	
*                        @arg FundRmsI1off
*                        @arg FundRmsI2off 		
*
* @param : data:Set offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_RmsOffset(RmsOffset_AddrTypeDef type,uint16_t data)
{
	uint32_t ulRegData;

	/*  assert_param  */
	assert_param(IS_HT_EMU_RMSOFFSET_ADDR(type));
	
	ulRegData = (uint32_t)data;
	
	switch(type)
	{
		case AllRmsUoff:
			HT_EMUECA->All_RmsOffset_U = ulRegData;
			break;
		case AllRmsI1off:
			HT_EMUECA->All_RmsOffset_I1 = ulRegData;
			break;
		case AllRmsI2off:
			HT_EMUECA->All_RmsOffset_I2 = ulRegData;
			break;
		case FundRmsUoff:
			HT_EMUECA->Fund_RmsOffset_U = ulRegData;
			break;
		case FundRmsI1off:
			HT_EMUECA->Fund_RmsOffset_I1 = ulRegData;
			break;
		case FundRmsI2off:
			HT_EMUECA->Fund_RmsOffset_I2 = ulRegData;
			break;
		default:
			break;	
	}

}

/**
********************************************************************************************************
*                                      Get EMU RMS Offset
* @brief : Get EMU module RMS offset
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg AllRmsUoff	
*                        @arg AllRmsI1off
*                        @arg AllRmsI2off 		
*                        @arg FundRmsUoff	
*                        @arg FundRmsI1off
*                        @arg FundRmsI2off 		
*
* @param : data:Get offset data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Get_EMU_RmsOffset(RmsOffset_AddrTypeDef type,uint16_t *data)
{
	uint32_t ulRegData;
	/*  assert_param  */
	assert_param(IS_HT_EMU_RMSOFFSET_ADDR(type));

	switch(type)
	{
		case AllRmsUoff:
			ulRegData = HT_EMUECA->All_RmsOffset_U;
			break;
		case AllRmsI1off:
			ulRegData = HT_EMUECA->All_RmsOffset_I1;
			break;
		case AllRmsI2off:
			ulRegData = HT_EMUECA->All_RmsOffset_I2;
			break;
		case FundRmsUoff:
			ulRegData = HT_EMUECA->Fund_RmsOffset_U;
			break;
		case FundRmsI1off:
			ulRegData = HT_EMUECA->Fund_RmsOffset_I1;
			break;
		case FundRmsI2off:
			ulRegData = HT_EMUECA->Fund_RmsOffset_I2;
			break;
		default:
			break;	
	}
    ulRegData &= ECR_16BIT_DATA;
	*data = (uint16_t)(ulRegData);
}

/**
********************************************************************************************************
*                                      Set EMU ONE CYCLE RMS NUM
* @brief : Set EMU module ONE CYCLE RMS points  
*
* @param : data:Set points data
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_OneCycRmsNum(uint16_t data)
{
	/*  assert_param  */
	assert_param(IS_HT_EMU_ONECYC_RMSNUM(data));
	HT_EMUECA->CycRmsNum = (uint32_t)(data&ECR_10BIT_DATA);
}

/**
********************************************************************************************************
*                                      Set EMU Half Cycle RMS Current channel 2 ENABLE
* @brief : set EMU module current channel Channel 2 half cycle RMS enable or disable
*
* @param: NewState       = ENABLE 
*                         = DISABLE
*
*
* @retval: none
*
* @note  : current half cycle rms only one channel
**********************************************************************************************************/
void HT_Set_EMU_HCycleRMS_I2En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_HCYCLERMS_I2_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_HCYCLERMS_I2_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Half Cycle RMS Update wave select
* @brief : set EMU module half cycle rms update wave select 
*
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg HCycRms_Half	
*                        @arg HCycRms_One
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_HCycRms_UpdSel(HCycRms_UpdSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_HCYCRMS_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_HCYCLERMS_SEL);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU Half Cycle RMS ENABLE
* @brief : EMU module half rms enable or disable 
*
* @param: NewState        = ENABLE: 
*                         = DISABLE:
*
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_HCycleRms_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_HCYCLERMS_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_HCYCLERMS_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU CURRENT RMS vector ADD MODE SELECT
* @brief : set EMU module Current RMS vector add mode select 
*
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg RmsItAddMode_add	
*                        @arg RmsItAddMode_sub
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_RmsIt_AddMode(RmsIt_AddModeTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_RMSIT_ADDMODE(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_RMSIT_ADDMODE);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU Fund Current RMS VECTOR ENABLE
* @brief : EMU module fund current rms vector enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FundIt_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_FUNDIT_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_FUNDIT_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Current RMS VECTOR ENABLE
* @brief : EMU module current rms vector enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_RMSIt_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_RMSIT_EN;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_RMSIT_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU DMA SOURCE SELECT
* @brief : set EMU module dma source select
*
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg DMA_SPL	
*                        @arg DMA_SYNC
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_DMA_SrcSel(DMA_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_DMA_SRCSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_DMA_SRCSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU apparent power start SELECT
* @brief : set EMU module apparent power start SELECT
*
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg SStartSelSStart	
*                        @arg SStartSelPOrQ
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SSart_CFG(SStart_CfgTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SSTART_SRCSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_SSTART_CFG);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU POWER start SPEED SELECT
* @brief : set EMU module power start speed select 
*
* @param : type
*  		  This parameter can be one of the following values:
*                        @arg PStartFast	
*                        @arg PStartSlow
*                        @arg PStartInst
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PStart_SpeedSel(PowerStart_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_PSTART_SPEEDSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_PQSStartSourceSel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU vref ENABLE
* @brief : EMU module vref enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_VrefEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_VrefEn;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_VrefEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU CIADD ADD MODE SELECT
* @brief : set EMU module Single-phase three-wire power add mode select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CiaddAbs	
*                        @arg CiaddAdd
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CIADD_AddMode(CIADD_AddModeTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CIADD_ADDMODE(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_AddCIADD);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU SPL WAVE SOURCE SELECT
* @brief : set EMU module spl wave source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg Wave_dec	
*                        @arg Wave_hpf
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Wave_SrcSel(Wave_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_WAVE_SRCSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_WaveSel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU IPTAMP SOURCE SPEED SELECT
* @brief : set EMU module stealing electricity detection threshold speed source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg IpTampSlow	
*                        @arg IpTampFast
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_IPTamp_SrcSpeedSel(IpTamp_SrcSpeedSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_IPTAMP_SPEEDSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_IPTampSource_Sel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU TAMP SOURCE SPEED SELECT
* @brief : set EMU module stealing electricity threshold speed source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg TampSlow	
*                        @arg TampFast
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Tamp_SrcSpeedSel(Tamp_SrcSpeedSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_TAMP_SPEEDSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_TampSourceSel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CHNNEL FIXED SELECT
* @brief : set EMU module meter channel fixed select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ChnFix_ch1	
*                        @arg ChnFix_beforeCh
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CHNFix_Sel(CHNFix_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CHNFIX_SRCSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_CHNFix);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU IPTAMP SOURCE SELECT
* @brief : set EMU module stealing electricity detection threshold source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg IpTampRms	
*                        @arg IpTampPower
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_IPTamp_SrcSel(IpTamp_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_IPTAMP_SRCSEL(Type));

	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_IPTampSel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU TAMP SOURCE SELECT
* @brief : set EMU module stealing electricity threshold source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg TampRms	
*                        @arg TampPower
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Tamp_SrcSel(Tamp_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_TAMP_SRCSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_TampSel);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU Automatic stealing electricity judge ENABLE
* @brief : set EMU module Automatic stealing electricity judge enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FltonEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_FLTON;
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_FLTON);
	}
}

/**
********************************************************************************************************
*                                      Set EMU METER CHANNEL SELECT
* @brief : set EMU module meter channel select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg MeterCh1	
*                        @arg MeterCh2
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_MeterChanel_Sel(Chanel_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_METER_CHNSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_CHNSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CIADD ENABLE
* @brief : set EMU module Single-phase three-wire power add enable or disable
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CIADDEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ADCCFG |= ADCCFG_CIADD;/* power add */
	}
	else
	{
		HT_EMUECA->ADCCFG &=(~ADCCFG_CIADD);/* one channel */
	}
}

/**
********************************************************************************************************
*                                      Set EMU WAVE UPDATE RATE SELECT
* @brief : set EMU module sampling wave update rate select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg WaveUpd_8	
*                        @arg WaveUpd_4
*                        @arg WaveUpd_2	
*                        @arg WaveUpd_1
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Wave_Upd(Wave_UpdTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_WAVE_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCFG;
	ultempReg &=(~ADCCFG_SPL);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCFG = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU HPF ENABLE
* @brief : set EMU module HPF enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg HpfChanel_U	
*                        @arg HpfChanel_I1
*                        @arg HpfChanel_I2 		
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_HpfEn(Hpf_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_HPF_CHNSEL(Chanel));
   ultemp = (uint32_t)Chanel; 
	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= ultemp;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU LOW POWER CF1 AND CF3 SELECT
* @brief : set EMU module low power mode cf1 and cf3 output select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LpCF1P_CF3S	
*                        @arg LpCF1S_CF3P
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpCF1CF3_Sel(LpCF1OR3_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_LPCF1CF3_CHNSEL(Type));
	
	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_PSSel);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU UConst ENABLE
* @brief : set EMU module voltage Constant enable or disable  
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_UConstEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_UconstEn;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_UconstEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU LOW POWER EMUCLK SELECT
* @brief : set EMU module low power mode emuclk select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LpEmuclk_32k	
*                        @arg LpEmuclk_204k
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpEmuClk_Sel(LpEmuclk_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_LPEMUCLK_SRCSEL(Type));
	
	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_LPFreqSel);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU CF POS SELECT
* @brief : set EMU module pulse valid electrical level select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CFPos_High	
*                        @arg CFPos_Low
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CF_POS_Sel(CFPos_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CF_POS(Type));
	
	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_POS);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU LOW POWER MODE ENABLE
* @brief : set EMU module low power mode enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpModeEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_LPMode;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_LPMode);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Constant Energy clk SELECT
* @brief : set EMU module constant energy add clk select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyConstClk_32K	
*                        @arg EnergyConstClk_BS
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_EnergyConstClk_Sel(EnergyConstClk_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CONSTENERGY_CLKSEL(Type));

	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_Add_DataCP);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU POWER LPF ENABLE
* @brief : set EMU module power lpf enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PQLpfEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_PQLpfEn;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_PQLpfEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU RMS LPF ENABLE
* @brief : set EMU module RMS LPF enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_RmsLpfEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_RmsLpfEn;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_RmsLpfEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU PEAK ENABLE
* @brief : set EMU module voltage peak enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_UPeakEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_PEAK_EN;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_PEAK_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU IOV ENABLE
* @brief : set EMU module current overflow enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_IOVEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_IOV_EN;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_IOV_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Power Constant ENABLE
* @brief : set EMU module Power Constant enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg PowerConstS	
*                        @arg PowerConstQ
*                        @arg PowerConstP
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerConstEn(PowerConst_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_PowerConst_CHNSEL(Chanel));
	ultemp = (uint32_t)Chanel;
	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= ultemp;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU sag ENABLE
* @brief : set EMU voltage sag enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_USagEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_SAG_EN;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_SAG_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU U PEAK SAG SOURCE SELECT
* @brief : set EMU module voltage peak and sag detection source select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PeakSagHalfVP	
*                        @arg PeakSagHalfRms
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_UPeakSag_SrcSel(PeakSag_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_UPEAKSAG_SRCSEL(Type));

	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_PEAKSAG_SRCSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU ONE CYCLE RMS ENABLE
* @brief : set EMU module one cycle rms enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_OneCycRmsEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->CHNLCR |= CHNLCR_ONECYCRMS_EN;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_ONECYCRMS_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Low Power Process SELECT
* @brief : set EMU module low power process select  
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LpProcSelNormal	
*                        @arg LpProcSelOneCyc
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpProc_Sel(LpProc_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_LPPROC_CHNSEL(Type));

	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_LPPROC_SEL);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;
	
}

/**
********************************************************************************************************
*                                      Set EMU I HALF Cycle VP Zerocross Select
* @brief : set EMU module current half cycle peak value zerocross source select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg IHvpZCSel_I	
*                        @arg IHvpZCSel_U
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_IHCycVp_ZCSel(IHvpZCSel_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_IHCYCVP_ZCSEL(Type));

	ultempReg = HT_EMUECA->CHNLCR;
	ultempReg &=(~CHNLCR_IHAIFVP_ZCSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->CHNLCR = ultempReg;
	
}

/**
********************************************************************************************************
*                                      Set EMU Energy 1 AccuMode Select
* @brief : set EMU module the first energy channel add mode select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CF1AccuModeAdd	
*                        @arg CF1AccuModePos
*                        @arg CF1AccuModeAbs	
*                        @arg CF1AccuModePN 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Energy1AccuMode(CF1_AccuMode_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ENERGY1_ACCMODESEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMCON_PMOD);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;
	
}

/**
********************************************************************************************************
*                                      Set EMU Energy 2 AccuMode Select
* @brief : set EMU module the SECOND energy channel add mode select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CF2AccuModeAdd	
*                        @arg CF2AccuModePos
*                        @arg CF2AccuModeAbs	
*                        @arg CF2AccuModePN 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Energy2AccuMode(CF2_AccuMode_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ENERGY2_ACCMODESEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMCON_QMOD);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;
	
}

/**
********************************************************************************************************
*                                      Set EMU ENERGY RUN ENABLE
* @brief : set EMU module Energy Run enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg CF1Run	
*                        @arg CF2Run
*                        @arg CF3Run	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_EnergyRunEn(EnergyRun_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_ENERGYRUN_CHNSEL(Chanel));

    ultemp = (uint32_t)Chanel;
	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCON |= ultemp;
	}
	else
	{
		HT_EMUECA->EMUCON &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU OSR Select
* @brief : set EMU module OSR select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg OSR128	
*                        @arg OSR64
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_OSR(EmuOsr_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_OSRSEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMUCON_OSR_SEL);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU Average power source Select
* @brief : set EMU module Average power source Select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg AvgPowerSelFast	
*                        @arg AvgPowerSelSlow
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_AvgPower_SrcSel(AvgPower_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_AVGPOWER_SCRSEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMCON_AverPowerSource);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CF1 OUTPUT Select
* @brief : set EMU module CF1 Output select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CF1OutSelCF1PN	
*                        @arg CF1OutSelCF2PN
*                        @arg CF1OutSelCF3PN	
*                        @arg CF1OutSelCF1P 
*                        @arg CF1OutSelCF1N 	
*                        @arg CF1OutSelCF2P 
*                        @arg CF1OutSelCF2N 	
*                        @arg CF1OutSelCF3P 
*                        @arg CF1OutSelCF3N 	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CF1_OutSel(CF1_OutSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CF1_OUTSEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMUCON_CF1CFG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CF2 OUTPUT Select
* @brief : set EMU module CF2 Output select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CF2OutSelCF1PN	
*                        @arg CF2OutSelCF2PN
*                        @arg CF2OutSelCF3PN	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CF2_OutSel(CF2_OutSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CF2_OUTSEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMUCON_CF2CFG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CF3 OUTPUT Select
* @brief : set EMU module CF3 Output select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CF3OutSelCF1PN	
*                        @arg CF3OutSelCF2PN
*                        @arg CF3OutSelCF3PN	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CF3_OutSel(CF3_OutSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CF3_OUTSEL(Type));

	ultempReg = HT_EMUECA->EMUCON;
	ultempReg &=(~EMUCON_CF3CFG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU U PGA Select
* @brief : set EMU module voltage channel PGA select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg UPGA_1	
*                        @arg UPGA_2
*                        @arg UPGA_4	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_UPGA(UPGA_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_UPGA_SEL(Type));

	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_ANAU);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU I1 PGA Select
* @brief : set EMU module Current channel 1 PGA select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg I1PGA_1	
*                        @arg I1PGA_2
*                        @arg I1PGA_8	
*                        @arg I1PGA_16
*                        @arg I1PGA_24	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_I1PGA(I1PGA_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_I1PGA_SEL(Type));

	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~(ADCCON_ANAI1|ADCCON_PGAI1_24));
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU I2 PGA Select
* @brief : set EMU module Current channel 2 PGA select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg I2PGA_1	
*                        @arg I2PGA_2
*                        @arg I2PGA_8	
*                        @arg I2PGA_16
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_I2PGA(I2PGA_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_I2PGA_SEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_ANAI2);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU CF Width Select
* @brief : set EMU module CF width select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg CFP_80ms	
*                        @arg CFP_40ms
*                        @arg CFP_20ms	
*                        @arg CFP_10ms
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_CFP(CFP_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_CFP_SCRSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_CFP);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU U DG Select
* @brief : set EMU module voltage digital Gain select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg UDG_1	
*                        @arg UDG_2
*                        @arg UDG_4	
*                        @arg UDG_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_UDG(UDG_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_UDG_SCRSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_DGU);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU I1 DG Select
* @brief : set EMU module current channel 1 digital Gain select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg I1DG_1	
*                        @arg I1DG_2
*                        @arg I1DG_4	
*                        @arg I1DG_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_I1DG(I1DG_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_I1DG_SCRSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_DGI1);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU I2 DG Select
* @brief : set EMU module current channel 2 digital Gain select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg I2DG_1	
*                        @arg I2DG_2
*                        @arg I2DG_4	
*                        @arg I2DG_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_I2DG(I2DG_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_I2DG_SCRSEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_DGI2);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU Power Shift Select
* @brief : set EMU module cf double select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PowerShift_1	
*                        @arg PowerShift_2
*                        @arg PowerShift_4	
*                        @arg PowerShift_8
*                        @arg PowerShift_16
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerShift(PowerShift_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERSHIFT_SEL(Type));
	
	ultempReg = HT_EMUECA->ADCCON;
	ultempReg &=(~ADCCON_POWER_SHIFT);
	ultempReg |=(ultemp);
	HT_EMUECA->ADCCON = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU Fast Power Rms Update Select
* @brief : set EMU module fast rms and power update Rate select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FastPRMS_UpdSel_1	
*                        @arg FastPRMS_UpdSel_2
*                        @arg FastPRMS_UpdSel_4	
*                        @arg FastPRMS_UpdSel_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FastPRMS_UpdSel(FastPRMS_UpdSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_FASTPRMS_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_PRFCFG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU ZEROCROSS INTERRUPT Select
* @brief : set EMU module zerocross interrupt way select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ZCdSel_P	
*                        @arg ZCdSel_N
*                        @arg ZCdSel_PN	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_ZCd_Sel(ZCd_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ZCD_SEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_Zxd);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU ADC ENABLE
* @brief : set EMU module ADC channel enable or disable 
*
* @param : Chanel
*  		  This parameter can be one or a combination of the following values:
*                        @arg EMUCTRL_AdcUon 
*                        @arg EMUCTRL_AdcI1on
*                        @arg EMUCTRL_AdcI2on	
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_ADCEn(uint32_t Chanel,FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_ADC_CHNSEL(Chanel));

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCTRL |= Chanel;
	}
	else
	{
		HT_EMUECA->EMUCTRL &=(~Chanel);
	}
}

/**
********************************************************************************************************
*                                      Set EMU slow RMS power Update Select
* @brief : set EMU module slow RMS and power updata rate select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SlowPRMS_UpdSel_2	
*                        @arg SlowPRMS_UpdSel_4
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SlowPRMS_UpdSel(SlowPRMS_UpdSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SLOW_PRMS_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_SlowPRMS);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU DC Update Select
* @brief : set EMU module DC updata rate select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg DC_UpdSel_1	
*                        @arg DC_UpdSel_2
*                        @arg DC_UpdSel_4	
*                        @arg DC_UpdSel_8
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_DCUpdSel(DC_UpdSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_DC_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_DCPRFCFG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;
	
}

/**
********************************************************************************************************
*                                      Set EMU Normal EMUCLK Select
* @brief : set EMU module normal mode clk select 
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg Normal_EmuClkSel_409K 	
*                        @arg Normal_EmuClkSel_819K 
*                        @arg Normal_EmuClkSel_1638K	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_NormalEmuClk_Sel(Normal_EmuClkSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_NORMAL_EMUCLK_SEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~(EMUCTRL_EMUClkCtrl|EMUCTRL_NORMAL_EMUCLK_SEL_1638K));
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU Energy 2 source Select
* @brief : set EMU module the second energy source select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg Energy2SrcSel_Q 	
*                        @arg Energy2SrcSel_FundP 
*                        @arg Energy2SrcSel_AllP2	
*                        @arg Energy2SrcSel_PConst	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_Energy2_SrcSel(Energy2_SrcSelTypeDef Type)
{
	/*  assert_param  */
	assert_param(IS_HT_EMU_ENERGY2_SRCSEL(Type));
	
	switch(Type)
	{
		case Energy2SrcSel_Q:
			HT_Set_EMU_PowerConstEn(PowerConstQ,DISABLE);
			HT_EMUECA->EMUCTRL &=(~EMUCTRL_P2EN);	
			HT_EMUECA->EMUCON2 &=(~EMUCON2_ENERGY2_SRCSEL);
			break;
		case Energy2SrcSel_FundP:
			HT_Set_EMU_PowerConstEn(PowerConstQ,DISABLE);
			HT_EMUECA->EMUCTRL &=(~EMUCTRL_P2EN);	
			HT_EMUECA->EMUCON2 |=(EMUCON2_ENERGY2_SRCSEL);
			break;
		case Energy2SrcSel_AllP2:
			HT_Set_EMU_PowerConstEn(PowerConstQ,DISABLE);
			HT_EMUECA->EMUCTRL |=(EMUCTRL_P2EN);	
			break;
		case Energy2SrcSel_PConst:
			HT_Set_EMU_PowerConstEn(PowerConstQ,ENABLE);
			break;
		default:
			break;
	}
}

/**
********************************************************************************************************
*                                      Set EMU low power mode Vref ENABLE
* @brief : set EMU module low power mode Vref enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpVrefEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCTRL |= EMUCTRL_VrefLPEn;
	}
	else
	{
		HT_EMUECA->EMUCTRL &=(~EMUCTRL_VrefLPEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU PQ START Select
* @brief : set EMU module active power and reactive power start Mode select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PQStartSel_PQ 	
*                        @arg PQStartSel_PORQ 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PQStartSel(PQStart_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_PQSTART_SRCSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_StartSel);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU FUND UPDATE RATE Select
* @brief : set EMU module Fund Update rate select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg FundUpd_1 	
*                        @arg FundUpd_2 
*                        @arg FundUpd_4	
*                        @arg FundUpd_8	
*                        @arg FundUpd_16	
*                        @arg FundUpd_32	
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FundUpdSel(FundUpd_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_FUND_UPDSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_FUND_UPD);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU PowerS source Select
* @brief : set EMU module apparent power source select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PowerSSrcSel_All 	
*                        @arg PowerSSrcSel_Fund 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerS_SrcSel(PowerS_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERS_SRCSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_POWERS_SRCSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU PowerQ source Select
* @brief : set EMU module reactive power source select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg PowerQSrcSel_All 	
*                        @arg PowerQSrcSel_Fund 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerQ_SrcSel(PowerQ_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_POWERQ_SRCSEL(Type));
	
	ultempReg = HT_EMUECA->EMUCTRL;
	ultempReg &=(~EMUCTRL_POWERQ_SRCSEL);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU I ROSI ENABLE
* @brief : set EMU module current rosi enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg RosiI1 	
*                        @arg RosiI2 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/

void HT_Set_EMU_IRosiEn(Rosi_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_IROSI_CHNSEL(Chanel));
    ultemp = (uint32_t)Chanel;
	if(ENABLE == NewState)
	{
		HT_EMUECA->RosiCtrl |= ultemp;
	}
	else
	{
		HT_EMUECA->RosiCtrl &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Low Power Mode StandByTime Select
* @brief : set EMU module low power mode stand by time select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg LpStandByTime_4  	
*                        @arg LpStandByTime_8   
*                        @arg LpStandByTime_16 	
*                        @arg LpStandByTime_32  
*                        @arg LpStandByTime_64 	
*                        @arg LpStandByTime_128 
*                        @arg LpStandByTime_256	
*                        @arg LpStandByTime_512 
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpStandByTime(LpStandByTime_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_LPSTANDBYTIME_SEL(Type));
	
	ultempReg = HT_EMUECA->RosiCtrl;
	ultempReg &=(~ROSICTRL_STANDBYTIME);
	ultempReg |=(ultemp);
	HT_EMUECA->RosiCtrl = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU Low Power Mode Idle ENABLE
*
* @brief : set EMU module Low Power Mode Idle enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LpIdle_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->RosiCtrl |= ROSICTRL_LpIdleEn;
	}
	else
	{
		HT_EMUECA->RosiCtrl &=(~ROSICTRL_LpIdleEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU System FREQ Select
* @brief : set EMU module init system frequence select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SysFreq50Hz  	
*                        @arg SysFreq60Hz   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SysFreq_Sel(SysFreq_SelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SYSFREQ_SEL(Type));

	ultempReg = HT_EMUECA->RosiCtrl;
	ultempReg &=(~ROSICTRL_XboFiter);
	ultempReg |=(ultemp);
	HT_EMUECA->RosiCtrl = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU PowerS DC ENABLE
*
* @brief : set EMU module DC to calculate apparent power enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerS_DCEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->RosiCtrl |= ROSICTRL_DCSEn;
	}
	else
	{
		HT_EMUECA->RosiCtrl &=(~ROSICTRL_DCSEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU DC ENABLE
* @brief : set EMU module DC enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_DC_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->RosiCtrl |= ROSICTRL_DCEn;
	}
	else
	{
		HT_EMUECA->RosiCtrl &=(~ROSICTRL_DCEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Automatic temperature compensation ENABLE
* @brief : set EMU module Automatic temperature compensation enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_AutoTC_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->RosiCtrl |= ROSICTRL_AutoTcEN;
	}
	else
	{
		HT_EMUECA->RosiCtrl &=(~ROSICTRL_AutoTcEN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Ldo ENABLE
* @brief : set EMU module LDO enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_LDO_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->ANA_CTRL |= ANACTRL_ldoEmuEn;
	}
	else
	{
		HT_EMUECA->ANA_CTRL &=(~ANACTRL_ldoEmuEn);
	}
}

/**
********************************************************************************************************
*                                      Set EMU ZEROCROSS SOURCE Select
* @brief : set EMU module zerocross interrupt source select
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg ZXSrcSel_AfterHPF  	
*                        @arg ZXSrcSel_AfterRosi   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_ZXSrcSel(ZXSrcSel_TypeDef Type)
{	
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ZCINT_SRCSEL(Type));

	ultempReg = HT_EMUECA->FilterCTRL;
	ultempReg &=(~FilterCtrl_ZXsourceSel);
	ultempReg |=(ultemp);
	HT_EMUECA->FilterCTRL = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU SYNC ENABLE
*
* @brief : set EMU module sync module channel enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg SyncU_En  	
*                        @arg SyncI_En   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SyncEn(Sync_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_SYNC_CHNEN(Chanel));
	
    ultemp  = (uint32_t)Chanel;
	if(ENABLE == NewState)
	{
		HT_EMUECA->SyncStart |= ultemp;
	}
	else
	{
		HT_EMUECA->SyncStart &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU SYNC I SELECT
*
* @brief : set EMU module sync module CURRENT channel SELECT
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg SyncISel_I1  	
*                        @arg SyncISel_I2   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SyncISrcSel(SyncISel_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SYNCI_CHNSEL(Type));

	ultempReg = HT_EMUECA->SyncStart;
	ultempReg &=(~SYNCSTART_I_SEL);
	ultempReg |=(ultemp);
	HT_EMUECA->SyncStart = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU SYNC U GAIN SELECT
*
* @brief : set EMU module sync module voltage channel Gain SELECT
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SyncGainU_1     	
*                        @arg SyncGainU_2      
*                        @arg SyncGainU_4     	
*                        @arg SyncGainU_8      
*                        @arg SyncGainU_16    	
*                        @arg SyncGainU_32     
*                        @arg SyncGainU_64    	
*                        @arg SyncGainU_128    
*                        @arg SyncGainU_256   	
*                        @arg SyncGainU_512    
*                        @arg SyncGainU_1024  	
*                        @arg SyncGainU_2048   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SyncUGain(SyncUGain_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SYNCU_GAINSEL(Type));

	ultempReg = HT_EMUECA->SyncStart;
	ultempReg &=(~SYNCSTART_GAIN_U);
	ultempReg |=(ultemp);
	HT_EMUECA->SyncStart = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU SYNC I GAIN SELECT
*
* @brief : set EMU module sync module CURRENT channel Gain SELECT
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg SyncGainI_1     	
*                        @arg SyncGainI_2      
*                        @arg SyncGainI_4     	
*                        @arg SyncGainI_8      
*                        @arg SyncGainI_16    	
*                        @arg SyncGainI_32     
*                        @arg SyncGainI_64    	
*                        @arg SyncGainI_128    
*                        @arg SyncGainI_256   	
*                        @arg SyncGainI_512    
*                        @arg SyncGainI_1024  	
*                        @arg SyncGainI_2048   
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_SyncIGain(SyncIGain_TypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_SYNCI_GAINSEL(Type));

	ultempReg = HT_EMUECA->SyncStart;
	ultempReg &=(~SYNCSTART_GAIN_I);
	ultempReg |=(ultemp);
	HT_EMUECA->SyncStart = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU POWER OV PN ENABLE
*
* @brief : set EMU module positive and negitive power overflow enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
* @param : Chanel
*  		  This parameter can be one of the following values:
*                        @arg PowerOV_CF1     	
*                        @arg PowerOV_CF2      
*                        @arg PowerOV_CF3     	
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_PowerOV_PNEn(PowerOV_ChanelTypeDef Chanel,FunctionalState NewState)
{
    uint32_t ultemp;
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_HT_EMU_POWEROV_PNEN(Chanel));

    ultemp = Chanel;
	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCON2 |= ultemp;
	}
	else
	{
		HT_EMUECA->EMUCON2 &=(~ultemp);
	}
}

/**
********************************************************************************************************
*                                      Set EMU ENERGY ACCU ALG SELECT
*
* @brief : set EMU module energy module pfcnt add mode SELECT
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyAccuAlgOld     	
*                        @arg EnergyAccuAlgNew      
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_EnergyAccuAlg(Energy_AccuAlgTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ENERGY_ACCUALG_SEL(Type));

	ultempReg = HT_EMUECA->EMUCON2;
	ultempReg &=(~EMUCON2_ENERGY_ACCUALG);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON2 = ultempReg;

}

/**
********************************************************************************************************
*                                      Set EMU ENERGY INPUT SOURCE SELECT
*
* @brief : set EMU module energy input source SELECT
*
* @param : Type
*  		  This parameter can be one of the following values:
*                        @arg EnergyInAvg     	
*                        @arg EnergyInIns     
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_EnergyInSrcSel(EnergyIn_SrcSelTypeDef Type)
{
    uint32_t ultemp,ultempReg = 0U;
    ultemp = (uint32_t)Type;
	/*  assert_param  */
	assert_param(IS_HT_EMU_ENERGYIN_SRCSEL(Type));

	ultempReg = HT_EMUECA->EMUCON2;
	ultempReg &=(~EMUCON2_ENERGY_INSSRC);
	ultempReg |=(ultemp);
	HT_EMUECA->EMUCON2 = ultempReg;
}

/**
********************************************************************************************************
*                                      Set EMU READ ENERGY NOT CLEAR ENABLE
*
* @brief : set EMU module after read energy ,then not clear energy enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_EnergyReadNotClr_En(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->EMUCON2 |= EMUCON2_ENERGY_RKEN;
	}
	else
	{
		HT_EMUECA->EMUCON2 &=(~EMUCON2_ENERGY_RKEN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU Flicker ENABLE
* @brief : set EMU module Flicker enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FlickerEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->FlickerCFG |= FLICKERCFG_EN;
	}
	else
	{
		HT_EMUECA->FlickerCFG &=(~FLICKERCFG_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU flicker update offset ENABLE
*
* @brief : set EMU module flicker update offset enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FlickerSetOffsetEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->FlickerCFG |= FLICKERCFG_SET_OFFSET;
	}
	else
	{
		HT_EMUECA->FlickerCFG &=(~FLICKERCFG_SET_OFFSET);
	}
}

/**
********************************************************************************************************
*                                      Set EMU fund function ENABLE
*
* @brief : set EMU module fund function enable or disable 
*
* @param: NewState       = ENABLE 
*                         = DISABLE 
*
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Set_EMU_FundEn(FunctionalState NewState)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(ENABLE == NewState)
	{
		HT_EMUECA->Fund_CFG |= FUNDCFG_EN;
	}
	else
	{
		HT_EMUECA->Fund_CFG &=(~FUNDCFG_EN);
	}
}

/**
********************************************************************************************************
*                                      Set EMU reset Flicker
*
* @brief : set EMU module Reset Flicker
*
* @param: none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_Reset_EMU_Flicker(void)
{
    HT_EMUECA->FlickerReset = ECR_Flicker_Reset;                                            /*!< reset flicker module */
}

/**
********************************************************************************************************
*                                      Set EMU power start init
*
* @brief : set EMU module power start init
*
* @param: StartInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_PowerStart_Init(PowerStart_InitTypeDef *StartInit)
{
	HT_Set_EMU_PStart_SpeedSel(StartInit->StartSrcSel);
	HT_Set_EMU_SSart_CFG(StartInit->S_StartCFG);
	HT_Set_EMU_PQStartSel(StartInit->PQ_StartCFG);

	HT_EMUECA->PStart = (uint32_t)StartInit->PStart;
	HT_EMUECA->QStart = (uint32_t)StartInit->QStart;
	HT_EMUECA->SStart = (uint32_t)StartInit->SStart;
}

/**
********************************************************************************************************
*                                      Set EMU power Constant init
*
* @brief : set EMU module power Constant init
*
* @param : PowerConstInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_PowerConst_Init(PowerConst_InitTypeDef *PowerConstInit)
{
	uint8_t ucflag = 0U;
	uint32_t ultemp = 0U;

	HT_Set_EMU_EnergyConstClk_Sel(PowerConstInit->PowerConstClk);/*clk select*/
	
	if(PowerConstInit->PConstEn==ENABLE)
	{
		ultemp = (uint32_t)PowerConstInit->PConst;
		HT_EMUECA->CHNLCR |= CHNLCR_PDatacpEn;
		HT_EMUECA->PowerConst_PL = (uint32_t)((ultemp)&ECR_16BIT_DATA);
		HT_EMUECA->PowerConst_PH = (uint32_t)((ultemp>>16U)&ECR_16BIT_DATA);
		ucflag |= 1U;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_PDatacpEn);
	}
	if(PowerConstInit->QConstEn==ENABLE)
	{
		ultemp = (uint32_t)PowerConstInit->QConst;
		HT_EMUECA->CHNLCR |= CHNLCR_QDatacpEn;
		HT_EMUECA->PowerConst_QL = (uint32_t)((ultemp)&ECR_16BIT_DATA);
		HT_EMUECA->PowerConst_QH = (uint32_t)((ultemp>>16U)&ECR_16BIT_DATA);
		ucflag |= 2U;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_QDatacpEn);
	}

	if(PowerConstInit->SConstEn==ENABLE)
	{
		ultemp = (uint32_t)PowerConstInit->SConst;
		HT_EMUECA->CHNLCR |= CHNLCR_SDatacpEn;
		HT_EMUECA->PowerConst_SL = (uint32_t)((ultemp)&ECR_16BIT_DATA);
		HT_EMUECA->PowerConst_SH = (uint32_t)((ultemp>>16U)&ECR_16BIT_DATA);
		ucflag |= 4U;
	}
	else
	{
		HT_EMUECA->CHNLCR &=(~CHNLCR_SDatacpEn);
	}

	if(ucflag)
	{
		HT_EMUECA->PowerConstLoad = ECR_PowerConst_Load;/*load const power */
	}

}

/**
********************************************************************************************************
*                                      Set EMU CIADD init
*
* @brief : set EMU module singel_phase three_wire  init
*
* @param : CiaddInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_CIADD_Init(CIADD_TypeDef *CiaddInit)
{
	HT_Set_EMU_CIADDEn(CiaddInit->CIADD_En);
	HT_Set_EMU_CIADD_AddMode(CiaddInit->CIADD_AddMode);
}

/**
********************************************************************************************************
*                                      Set EMU TAMP init
*
* @brief : set EMU module stealing electricity init
*
* @param : TampInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Tamp_Init(Tamp_InitTypeDef *TampInit)
{
	HT_EMUECA->IPTAMP = (uint32_t)(TampInit->IpTampLVL);
	HT_EMUECA->ICHK = (uint32_t)(TampInit->ICHK);
	
	HT_Set_EMU_MeterChanel_Sel(TampInit->ChanelSel);
	
	HT_Set_EMU_IPTamp_SrcSpeedSel(TampInit->IpTampSrcSpeedSel);
	HT_Set_EMU_IPTamp_SrcSel(TampInit->IpTampSrcSel);
	
	HT_Set_EMU_Tamp_SrcSpeedSel(TampInit->TampSrcSpeedSel);
	HT_Set_EMU_Tamp_SrcSel(TampInit->TampSrcSel);
	
	HT_Set_EMU_CHNFix_Sel(TampInit->ChanelFix);
	HT_Set_EMU_FltonEn(TampInit->FLTON);
}

/**
********************************************************************************************************
*                                      Set EMU SagPeakIOV init
*
* @brief : set EMU module peak/sag/iov init
*
* @param : SagPeakIOVInit
*
* @retval: none
*
* @note  : need config other :adc_en,zc_init...
**********************************************************************************************************/
void HT_EMU_SagPeakIOV_Init(SagPeakIOV_InitTypeDef *SagPeakIOVInit)
{
	HT_EMUECA->USagLVL 	   = (uint32_t)(SagPeakIOVInit->USagLvl);
	HT_EMUECA->UPeakLVL    = (uint32_t)(SagPeakIOVInit->UPeakLvl);
	HT_EMUECA->SagLVLHys   = (uint32_t)(SagPeakIOVInit->USagLvlHys);
	HT_EMUECA->PeakLVLHys  = (uint32_t)(SagPeakIOVInit->UPeakLvlHys);
	HT_EMUECA->IOVLVL      = (uint32_t)(SagPeakIOVInit->IovLvl);
	HT_EMUECA->IOVHCyc     = (uint32_t)(SagPeakIOVInit->IovHCyc);
	HT_EMUECA->PeakSagHCyc = (uint32_t)(SagPeakIOVInit->PeakSagHCyc);

	HT_Set_EMU_UPeakSag_SrcSel(SagPeakIOVInit->PeakSagSrcSel);

	HT_Set_EMU_USagEn(SagPeakIOVInit->USagEn);
	HT_Set_EMU_UPeakEn(SagPeakIOVInit->UPeakEn);
	HT_Set_EMU_IOVEn(SagPeakIOVInit->IovEn);	
}

/**
********************************************************************************************************
*                                      Set EMU Temperature compensation init
*
* @brief : set EMU module Temperature compensation init
*
* @param : TempCompInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_TempComp_Init(TempComp_InitTypeDef *TempCompInit)
{
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(TempCompInit->AutoTcEn));

	if(ENABLE == TempCompInit->AutoTcEn)
	{
		HT_EMUECA->TCOFF_UA   = (uint32_t)(TempCompInit->TCOFFA_U);
		HT_EMUECA->TCOFF_UB   = (uint32_t)(TempCompInit->TCOFFB_U);
		HT_EMUECA->TCOFF_UC   = (uint32_t)(TempCompInit->TCOFFC_U);
		
		HT_EMUECA->TCOFF_I1A   = (uint32_t)(TempCompInit->TCOFFA_I1);
		HT_EMUECA->TCOFF_I1B   = (uint32_t)(TempCompInit->TCOFFB_I1);
		HT_EMUECA->TCOFF_I1C   = (uint32_t)(TempCompInit->TCOFFC_I1);
		
		HT_EMUECA->TCOFF_I2A   = (uint32_t)(TempCompInit->TCOFFA_I2);
		HT_EMUECA->TCOFF_I2B   = (uint32_t)(TempCompInit->TCOFFB_I2);
		HT_EMUECA->TCOFF_I2C   = (uint32_t)(TempCompInit->TCOFFC_I2);

		HT_Set_EMU_AutoTC_En(ENABLE);
	}
	else
	{
		HT_EMUECA->Tgain_U 	 = (uint32_t)(TempCompInit->TGain_U);
		HT_EMUECA->Tgain_I1  = (uint32_t)(TempCompInit->TGain_I1);
		HT_EMUECA->Tgain_I2  = (uint32_t)(TempCompInit->TGain_I2);
		HT_Set_EMU_AutoTC_En(DISABLE);
	}		
}

/**
********************************************************************************************************
*                                      Set EMU ZeroCross init
*
* @brief : set EMU module ZeroCross init
*
* @param : ZCInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_ZC_Init(ZC_InitTypeDef *ZCInit)
{
	uint32_t ultemp = 0U;
	
	HT_EMUECA->UZCLVL = (uint32_t)(ZCInit->UZCLvl);
	HT_EMUECA->IZCLVL = (uint32_t)(ZCInit->IZCLvl);

	HT_Set_EMU_ZXSrcSel(ZCInit->ZXSrcSel);
	HT_Set_EMU_ZCd_Sel(ZCInit->ZC_IntSel);
	
	ultemp = (ZCInit->ZC_Delay_U&ECR_9BIT_DATA);
	ultemp <<= 9U;
	ultemp |= (ZCInit->ZCNumMax_U&ECR_9BIT_DATA);
	HT_EMUECA->ZCNumCFG = ultemp;
	
	HT_Set_EMU_IHCycVp_ZCSel(ZCInit->IHvpZCSel);			
}

/**
********************************************************************************************************
*                                      Set EMU Half Cycle RMS init
*
* @brief : set EMU module Half Cycle RMS init
*
* @param : HCycRmsInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_HCycRms_Init(HCycRms_InitTypeDef *HCycRmsInit)
{
	HT_EMUECA->HCycleRMS_dPHFix = (HCycRmsInit->dPHfix&ECR_19BIT_DATA);
	
	HT_Set_EMU_HCycRms_UpdSel(HCycRmsInit->HCycRms_UpdSel);
	HT_Set_EMU_HCycleRMS_I2En(HCycRmsInit->HCycleRmsI2En);
	HT_Set_EMU_HCycleRms_En(HCycRmsInit->HCycleRmsEn);	
}

/**
********************************************************************************************************
*                                      Set EMU SYNC init
*
* @brief : set EMU module SYNC init
*
* @param : SyncInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Sync_Init(Sync_InitTypeDef *SyncInit)
{	
	HT_EMUECA->SyncCoff = (uint32_t)(SyncInit->SyncCoff&ECR_9BIT_DATA);

	HT_Set_EMU_SyncISrcSel(SyncInit->SyncISel);
	HT_Set_EMU_SyncUGain(SyncInit->SyncUGain);
	HT_Set_EMU_SyncIGain(SyncInit->SyncIGain);
	HT_Set_EMU_SyncEn(SyncU_En,SyncInit->SyncUEn);
	HT_Set_EMU_SyncEn(SyncI_En,SyncInit->SyncIEn);		
}

/**
********************************************************************************************************
*                                      Set EMU Fund init
*
* @brief : set EMU module Fund init
*
* @param : FundInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Fund_Init(Fund_InitTypeDef *FundInit)
{
	uint32_t i;
	/*disable flicker and one cycle rms*/
	HT_Set_EMU_OneCycRmsEn(DISABLE);
	HT_Set_EMU_FlickerEn(DISABLE);
	
	for(i=0U;i<16U;i++)
	{
		*(uint32_t*)(0x40013A00U+i*4U) = (uint32_t)(FundInit->FundCoff[i]);
		*(uint32_t*)(0x40013A40U+i*4U) = (uint32_t)(FundInit->FundCoff[i]);
	}

	HT_Set_EMU_FundUpdSel(FundInit->FundUpdCFG);
	HT_Set_EMU_PowerQ_SrcSel(FundInit->PowerQSrcSel);
	HT_Set_EMU_PowerS_SrcSel(FundInit->PowerEnergySSrcSel);
	
	/*  assert_param  */
	assert_param(IS_FUNCTIONAL_STATE(FundInit->FundEnergyPEn));

	if(ENABLE == FundInit->FundEnergyPEn)
	{	
		HT_Set_EMU_Energy2_SrcSel(Energy2SrcSel_FundP);
	}
	else
	{
		HT_EMUECA->EMUCON2 &=(~EMUCON2_ENERGY2_SRCSEL);
	}		
	
	HT_Set_EMU_FundEn(FundInit->FundEn);
}

/**
********************************************************************************************************
*                                      Set EMU RMSIT init
*
* @brief : set EMU module rms vector init
*
* @param : RmsItInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_RmsIt_Init(RmsIt_InitTypeDef *RmsItInit)
{
	HT_Set_EMU_RmsItTHO(RmsItInit->RmsItTHO);
	HT_Set_EMU_RmsIt_AddMode(RmsItInit->AddMode);
	HT_Set_EMU_FundIt_En(RmsItInit->FundItEn);
	HT_Set_EMU_RMSIt_En(RmsItInit->RmsItEn);
}

/**
********************************************************************************************************
*                                      Set EMU Flicker init
*
* @brief : set EMU module Flicker init
*
* @param : FlickerInit
*
* @retval: none
*
* @note  : need config other :adc_en...
**********************************************************************************************************/
void HT_EMU_Flicker_Init(Flicker_InitTypeDef *FlickerInit)
{
	uint32_t ultemp=0U;
	uint32_t i;

	HT_Reset_EMU_Flicker();/* reset flicker module  */
    
	ultemp = (uint32_t)FlickerInit->SqrOffset;
	HT_EMUECA->FlickerSqrOffset = (ultemp&ECR_30BIT_DATA);/*init offset */

	for(i=0U;i<16U;i++)
	{
		*(uint32_t*)(0x40013A00U+i*4U) = (uint32_t)(FlickerInit->LpfCoff[i]);
		*(uint32_t*)(0x40013A40U+i*4U) = (uint32_t)(FlickerInit->BpfCoff[i]);
	}

	if(FlickerInit->LpfLshift<=ECR_3BIT_DATA)
	{
		ultemp =(uint32_t)(FlickerInit->LpfLshift&ECR_3BIT_DATA);
		HT_EMUECA->Fund_CFG &=(~FUNDCFG_FLICKER_LPFSHIFT);
		HT_EMUECA->Fund_CFG |=(ultemp<<1U);
	}
	
	if(FlickerInit->BpfLshift<=ECR_3BIT_DATA)
	{
		ultemp =(uint32_t)(FlickerInit->BpfLshift);	
		ultemp <<=9U;
		HT_EMUECA->FlickerCFG &=(~(FLICKERCFG_BPF_LSHIFT));
		HT_EMUECA->FlickerCFG |= ultemp;
	}
		
	if(FlickerInit->HpfLshift<=ECR_3BIT_DATA)
	{
		ultemp = (uint32_t)FlickerInit->HpfLshift;
		ultemp <<=6U;
		HT_EMUECA->FlickerCFG &=(~(FLICKERCFG_HPF_LSHIFT));
		HT_EMUECA->FlickerCFG |= ultemp;
	}
	
	if(FlickerInit->UpdRate<=ECR_5BIT_DATA)
	{
		ultemp = (uint32_t)FlickerInit->UpdRate;
		ultemp <<=1U;
		HT_EMUECA->FlickerCFG &=(~(FLICKERCFG_UPDRATE));
		HT_EMUECA->FlickerCFG |= ultemp;
	}

	HT_Set_EMU_FlickerSetOffsetEn(FlickerInit->SetOffset_En);
	HT_Set_EMU_FlickerEn(FlickerInit->Flicker_En);
	
}

/**
********************************************************************************************************
*                                      Set EMU One Cycle Rms init
*
* @brief : set EMU module One Cycle Rms init
*
* @param : CycRmsInit
*
* @retval: none
*
* @note  : need config other :adc_en...,used to low power mode
**********************************************************************************************************/
void HT_EMU_OneCycRms_Init(CycRms_InitTypeDef *CycRmsInit)
{
	uint32_t i;
	/*disable flicker*/
	HT_Set_EMU_FlickerEn(DISABLE);
	
	
	for(i=0U;i<16U;i++)
	{
		*(uint32_t*)(0x40013A00U+i*4U) = (uint32_t)(CycRmsInit->OneCycCoff[i]);
		*(uint32_t*)(0x40013A40U+i*4U) = (uint32_t)(CycRmsInit->OneCycCoff[i]);
	}
	
	HT_Set_EMU_OneCycRmsNum(CycRmsInit->OneCycNum);	
	HT_Set_EMU_OneCycRmsEn(CycRmsInit->OneCyc_En);	
}

/**
********************************************************************************************************
*                                      Set EMU low power mode init
*
* @brief : set EMU module low power mode init
*
* @param : FundInit
*
* @retval: none
*
* @note  :  1.LPVREF->vref£¬vref need delay 1ms
			2.other low power config for down power
**********************************************************************************************************/
void HT_EMU_LpMode_Init(LpMode_InitTypeDef *LpModeInit)
{
	CycRms_InitTypeDef CycRmsInit;
	uint8_t i;
	
	HT_Set_EMU_LpRmsTHO(LpModeInit->LpIRmsTHO);
	HT_Set_EMU_LpIdleTime(LpModeInit->IdleTime);
	HT_Set_EMU_UConst(LpModeInit->UConst);

	HT_Set_EMU_LpIdle_En(LpModeInit->LpIdle_En);
	HT_Set_EMU_LpStandByTime(LpModeInit->StandByTime);
	
	HT_Set_EMU_UConstEn(LpModeInit->UConst_En);

	if(ENABLE == LpModeInit->LpVref_En)
	{
		HT_Set_EMU_LpVrefEn(ENABLE);
		HT_Set_EMU_VrefEn(DISABLE);
	}
	
	HT_Set_EMU_LpCF1CF3_Sel(LpModeInit->LpCF1OR3);
	HT_Set_EMU_LpEmuClk_Sel(LpModeInit->LpEmuclk);
	HT_Set_EMU_LpProc_Sel(LpModeInit->LpProc);

	if(LpProcSelOneCyc == LpModeInit->LpProc)
	{
		CycRmsInit.OneCyc_En = ENABLE;
		CycRmsInit.OneCycNum = LpModeInit->OneCycNum; /*ONE CYCLE POINTS*/
		for(i=0U;i<16U;i++)
		{
			CycRmsInit.OneCycCoff[i] = LpModeInit->OneCycCoff[i];
		}
		HT_EMU_OneCycRms_Init(&CycRmsInit);
	}
	
	HT_Set_EMU_LpModeEn(LpModeInit->LpMode_En);
}

#endif

#if (USE_HT_EMU_REGISTER_CALLBACKS != 1U)
#if  defined  HT501x ||defined  HT502x
/**
********************************************************************************************************
*                                      Set EMU Module init
*
* @brief : set EMU module init
*
* @param : none
*
* @retval: none
*
* @note  : none
**********************************************************************************************************/
void HT_EMU_Init(void)
{
  /*  assert_param  */
    Enable_emu_module();
    Reset_EMU_Module();	
    Select_Pulse_Port(PF0, PFout, P80ms);
    Select_Pulse_Port(PF1, QFout, P80ms);
	Open_emu_LDO();
	
	/*** delay 10ms wait 2p8 stable,user can adjust***/
	Delay_ms(10);
	
    Set_Valid_Channel((EMUCTRL_AdcUon|EMUCTRL_AdcI1on),(ADCCON_ANAI1_16|ADCCON_ANAU_1));
    
    Set_EMU_Reactive_Phase_Gain(50U);

}
#endif
#endif

#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/****************************************************************************
* @brief : Register a User EMU Callback
*         To be used instead of the weak predefined callback
* @param : EMU_InitStruct EMU handle
*
* @param : pCallback pointer to the Callback function
*
* @retval: status
*
* @Note  : None
* @note: when USE_HT_EMU_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
********************************************************************************/
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

#endif /* USE_HT_EMU_REGISTER_CALLBACKS */

#endif


