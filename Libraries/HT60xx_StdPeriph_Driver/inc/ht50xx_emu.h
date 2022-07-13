/*
**********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*                                         
*
* Project      : HT6xxx
* File         : ht50xx_emu.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used EMU Function.
**********************************************************************************************************
*/

#ifndef __HT50XX_EMU_H__
#define __HT50XX_EMU_H__

#ifdef __cplusplus
extern "C" {
#endif 
    
#include "ht6xxx_lib.h"
    
#if defined  HT501x  ||  defined  HT502x  ||  defined  HT503x                       /* This File Only support HT50xx */
    
/*
*********************************************************************************************************
*                                          Global macro / structure
*********************************************************************************************************
*/
#define	HT50XX_LIB_VERSION_NUM                  	"HT50xx_StdPeriphLib_Emu_V00.00.002"

/****EPR register offset address, or Energy metering Parameters Registers offset address define, base address: 0x40013000,(read only)****************/
#define   EPR_SPLI1                   ((uint32_t)0x0000)
#define   EPR_SPLI2                   ((uint32_t)0x0004)
#define   EPR_SPLU                    ((uint32_t)0x0008)
#if defined  HT503x
#define   EPR_ALL_SPL_P               ((uint32_t)0x000C)
#define   EPR_ALL_SPL_Q               ((uint32_t)0x0010)
#define   EPR_ALL_FastRMSI1           ((uint32_t)0x0014)
#define   EPR_ALL_FastRMSI2           ((uint32_t)0x0018)
#define   EPR_ALL_FastRMSU            ((uint32_t)0x001C)
#else
#define   EPR_SPLP                    ((uint32_t)0x000C)
#define   EPR_SPLQ                    ((uint32_t)0x0010)
#define   EPR_FastRMSI1               ((uint32_t)0x0014)
#define   EPR_FastRMSI2               ((uint32_t)0x0018)
#define   EPR_FastRMSU                ((uint32_t)0x001C)
#endif
#define   EPR_FreqU                   ((uint32_t)0x0020)
#if defined  HT503x
#define   EPR_ALL_FastPowerP1         ((uint32_t)0x0024)
#define   EPR_ALL_FastPowerQ1         ((uint32_t)0x0028)
#define   EPR_ALL_FastPowerP2         ((uint32_t)0x002C)
#define   EPR_ALL_FastPowerQ2         ((uint32_t)0x0030)
#else
#define   EPR_FastPowerP1             ((uint32_t)0x0024)
#define   EPR_FastPowerQ1             ((uint32_t)0x0028)
#define   EPR_FastPowerP2             ((uint32_t)0x002C)
#define   EPR_FastPowerQ2             ((uint32_t)0x0030)
#endif
#define   EPR_FastPowerS1             ((uint32_t)0x0034)
#define   EPR_FastPowerS2             ((uint32_t)0x0038)
#if defined  HT503x
#define   EPR_ALL_SlowRMSI1           ((uint32_t)0x003C)
#define   EPR_ALL_SlowRMSI2           ((uint32_t)0x0040)
#define   EPR_ALL_SlowRMSU            ((uint32_t)0x0044)
#define   EPR_ALL_SlowPowerP1         ((uint32_t)0x0048)
#define   EPR_ALL_SlowPowerQ1         ((uint32_t)0x004C)
#define   EPR_ALL_SlowPowerP2         ((uint32_t)0x0050)
#define   EPR_ALL_SlowPowerQ2         ((uint32_t)0x0054)
#define   EPR_SlowPowerS1             ((uint32_t)0x0058)
#define   EPR_SlowPowerS2             ((uint32_t)0x005C)
#define   EPR_EnergyNegCF1            ((uint32_t)0x0060)
#define   EPR_EnergyNegCF2            ((uint32_t)0x0064)
#define   EPR_EnergyNegCF3            ((uint32_t)0x0068)
#define   EPR_EnergyCF1               ((uint32_t)0x006C)
#define   EPR_EnergyCF2               ((uint32_t)0x0070)
#define   EPR_EnergyCF3               ((uint32_t)0x0074)
#define   EPR_DCAVGU             	  ((uint32_t)0x0078)
#define   EPR_DCAVGI1                 ((uint32_t)0x007C)
#define   EPR_DCAVGI2                 ((uint32_t)0x0080)
#define   EPR_Checksum1               ((uint32_t)0x0084)
#define   EPR_HCycleVp_U              ((uint32_t)0x0088)
#define   EPR_HCycleVp_I1             ((uint32_t)0x008C)
#define   EPR_HCycleVp_I2             ((uint32_t)0x0090)
#define   EPR_HCycleRMS_U             ((uint32_t)0x0094)
#define   EPR_HCycleRMS_I             ((uint32_t)0x0098)

#define   EPR_AutoTgain_U             ((uint32_t)0x00A0)
#define   EPR_AutoTgain_I1            ((uint32_t)0x00A4)
#define   EPR_AutoTgain_I2            ((uint32_t)0x00A8)

#define   EPR_PeakCnt                 ((uint32_t)0x00B8)
#define   EPR_PeakVp                  ((uint32_t)0x00BC)
#define   EPR_SagCnt                  ((uint32_t)0x00C0)
#define   EPR_SagVp                   ((uint32_t)0x00C4)
#define   EPR_FlickerPinst            ((uint32_t)0x00C8)
#define   EPR_ADCSync_U               ((uint32_t)0x00CC)
#define   EPR_ADCSync_I               ((uint32_t)0x00D0)
#define   EPR_FundRMS_U               ((uint32_t)0x00D4)
#define   EPR_FundRMS_I1              ((uint32_t)0x00D8)
#define   EPR_FundRMS_I2              ((uint32_t)0x00DC)
#define   EPR_FundPower_P1            ((uint32_t)0x00E0)
#define   EPR_FundPower_P2            ((uint32_t)0x00E4)

#define   EPR_CycRms_U                ((uint32_t)0x00EC)
#define   EPR_CycRms_I1               ((uint32_t)0x00F0)
#define   EPR_CycRms_I2               ((uint32_t)0x00F4)
#define   EPR_CheckSum2               ((uint32_t)0x00F8)
#else
#define   EPR_RMSI1                   ((uint32_t)0x003C)
#define   EPR_RMSI2                   ((uint32_t)0x0040)
#define   EPR_RMSU                    ((uint32_t)0x0044)
#define   EPR_PowerP1                 ((uint32_t)0x0048)
#define   EPR_PowerQ1                 ((uint32_t)0x004C)
#define   EPR_PowerP2                 ((uint32_t)0x0050)
#define   EPR_PowerQ2                 ((uint32_t)0x0054)

#define   EPR_PowerS1                 ((uint32_t)0x0058)
#define   EPR_PowerS2                 ((uint32_t)0x005C)

#define   EPR_EnergyP                 ((uint32_t)0x0060)
#define   EPR_EnergyQ                 ((uint32_t)0x0064)
#define   EPR_EnergyS                 ((uint32_t)0x0068)
#define   EPR_EnergyPC                ((uint32_t)0x006C)
#define   EPR_EnergyQC                ((uint32_t)0x0070)
#define   EPR_EnergySC                ((uint32_t)0x0074)
#define   EPR_DC_UAverage             ((uint32_t)0x0078)
#define   EPR_DC_I1Average            ((uint32_t)0x007C)
#define   EPR_DC_I2Average            ((uint32_t)0x0080)
#define   EPR_Checksum                ((uint32_t)0x0084)
#if defined HT502x
#define   EPR_Upd_Half                ((uint32_t)0x0088)
#define   EPR_I1pd_Half               ((uint32_t)0x008C)
#define   EPR_I2pd_Half               ((uint32_t)0x0090)
#else                                 
#define   EPR_Upeak                   ((uint32_t)0x0088)
#define   EPR_I1peak                  ((uint32_t)0x008C)
#define   EPR_I2peak                  ((uint32_t)0x0090)
#endif
#define   EPR_PFCNT_Photo             ((uint32_t)0x0094)
#define   EPR_QFCNT_Photo             ((uint32_t)0x0098)
#define   EPR_SFCNT_Photo             ((uint32_t)0x009C)
#define   EPR_AutoUgain               ((uint32_t)0x00A0)
#define   EPR_AutoI1gain              ((uint32_t)0x00A4)
#define   EPR_AutoI2gain              ((uint32_t)0x00A8)
#if defined HT502x
#define   EPR_R_Buffer                ((uint32_t)0x00AC)
#define   EPR_UdetCNT                 ((uint32_t)0x00B8)
#endif
#endif

/*******ECR register offset address, or Energy Calibration Registers offset address define, base address: 0x40013800, (write & read enable )*****************/  
#define   ECR_EMUSR                   ((uint32_t)0x0000)
#define   ECR_EMUIE                   ((uint32_t)0x0004)
#define   ECR_EMUIF                   ((uint32_t)0x0008)

#if defined HT503x
#define   ECR_ALL_GP1                 ((uint32_t)0x000C)
#define   ECR_ALL_GQ1                 ((uint32_t)0x0010)
#define   ECR_GS1                     ((uint32_t)0x0014)
#define   ECR_ALL_GPhs1               ((uint32_t)0x0018)
#define   ECR_ALL_GP2                 ((uint32_t)0x001C)
#define   ECR_ALL_GQ2                 ((uint32_t)0x0020)
#define   ECR_GS2                     ((uint32_t)0x0024)
#define   ECR_ALL_GPhs2               ((uint32_t)0x0028)
#define   ECR_ALL_QPhsCal             ((uint32_t)0x002C)
#else 
#define   ECR_GP1                     ((uint32_t)0x000C)
#define   ECR_GPhs1                   ((uint32_t)0x0018)
#define   ECR_GP2                     ((uint32_t)0x001C)
#define   ECR_GPhs2                   ((uint32_t)0x0028)
#define   ECR_QPhsCal                 ((uint32_t)0x002C)
#if defined HT501x
#define   ECR_GQ1                     ((uint32_t)0x0010)
#define   ECR_GS1                     ((uint32_t)0x0014)
#define   ECR_GQ2                     ((uint32_t)0x0020)
#define   ECR_GS2                     ((uint32_t)0x0024)
#endif
#endif
#define   ECR_I2Gain                  ((uint32_t)0x0030)
#define   ECR_I1Off                   ((uint32_t)0x0034)
#define   ECR_I2Off                   ((uint32_t)0x0038)
#define   ECR_UOff                    ((uint32_t)0x003C)
#define   ECR_PStart                  ((uint32_t)0x0040)
#define   ECR_QStart                  ((uint32_t)0x0044)
#define   ECR_SStart                  ((uint32_t)0x0048)
#define   ECR_HFconst                 ((uint32_t)0x004C)
#define   ECR_ADCCFG                  ((uint32_t)0x0050)
#define   ECR_CHNLCR                  ((uint32_t)0x0054)
#define   ECR_EMCON                   ((uint32_t)0x0058)
#if defined HT503x
#define   ECR_CF1Cnt                  ((uint32_t)0x005C)
#define   ECR_CF2Cnt                  ((uint32_t)0x0060)
#define   ECR_CF3Cnt                  ((uint32_t)0x0064)
#else
#define   ECR_PFCnt                   ((uint32_t)0x005C)
#define   ECR_QFCnt                   ((uint32_t)0x0060)
#define   ECR_SFCnt                   ((uint32_t)0x0064)
#endif
#define   ECR_ADCCON                  ((uint32_t)0x0068)
#define   ECR_IPTAMP                  ((uint32_t)0x006C)
#define   ECR_ICHK                    ((uint32_t)0x0070)
#define   ECR_EMUCTRL                 ((uint32_t)0x0074)
#if defined HT503x
#define   ECR_ALL_P1Offset            ((uint32_t)0x0078)
#define   ECR_ALL_P2Offset            ((uint32_t)0x007C)
#define   ECR_ALL_Q1Offset            ((uint32_t)0x0080)
#define   ECR_ALL_Q2Offset            ((uint32_t)0x0084)
#define   ECR_ALL_I1RMSOffset         ((uint32_t)0x0088)
#define   ECR_ALL_I2RMSOffset         ((uint32_t)0x008C)
#define   ECR_ALL_URMSOffset          ((uint32_t)0x0090)
#else
#define   ECR_P1OFFSET                ((uint32_t)0x0078)
#define   ECR_P2OFFSET                ((uint32_t)0x007C)
#define   ECR_Q1OFFSET                ((uint32_t)0x0080)
#define   ECR_Q2OFFSET                ((uint32_t)0x0084)
#define   ECR_I1RMSOFFSET             ((uint32_t)0x0088)
#define   ECR_I2RMSOFFSET             ((uint32_t)0x008C)
#define   ECR_URMSOFFSET              ((uint32_t)0x0090)
#endif
#define   ECR_RosiCtrl                ((uint32_t)0x0094)
#define   ECR_ANA_control             ((uint32_t)0x0098)
#define   ECR_UCONST                  ((uint32_t)0x009C)
#define   ECR_LpIdleTime              ((uint32_t)0x00A0)
#define   ECR_USAGLVL                 ((uint32_t)0x00A4)

#if defined HT503x
#define   ECR_IOVHCyc                 ((uint32_t)0x00A8)
#define   ECR_UPeakLVL                ((uint32_t)0x00AC)
#define   ECR_PeakSagHCyc             ((uint32_t)0x00B0)
#elif defined HT502x
#define   ECR_IpeakCyc                ((uint32_t)0x00A8)
#define   ECR_UOVLVL                  ((uint32_t)0x00AC)
#define   ECR_UdetCyc                 ((uint32_t)0x00B0)
#elif defined HT501x
#define   ECR_USagCyc                 ((uint32_t)0x00A8)
#define   ECR_UOVLVL                  ((uint32_t)0x00AC)
#define   ECR_OvCyc                   ((uint32_t)0x00B0)
#endif

#define   ECR_IOVLVL                  ((uint32_t)0x00B4)
#define   ECR_ZXILVL                  ((uint32_t)0x00B8)
#define   ECR_PDataCpH                ((uint32_t)0x00BC)
#define   ECR_PDataCpL                ((uint32_t)0x00C0)
#define   ECR_QDataCpH                ((uint32_t)0x00C4)
#define   ECR_QDataCpL                ((uint32_t)0x00C8)
#define   ECR_SDataCpH                ((uint32_t)0x00CC)
#define   ECR_SDataCpL                ((uint32_t)0x00D0)
#define   ECR_FilterCtrl              ((uint32_t)0x00D4)
#define   ECR_TUgain                  ((uint32_t)0x00D8)
#define   ECR_TI1gain                 ((uint32_t)0x00DC)
#define   ECR_TI2gain                 ((uint32_t)0x00E0)
#define   ECR_UTCcoffA                ((uint32_t)0x00E4)
#define   ECR_UTCcoffB                ((uint32_t)0x00E8)
#define   ECR_UTCcoffC                ((uint32_t)0x00EC)
#define   ECR_I1TCcoffA               ((uint32_t)0x00F0)
#define   ECR_I1TCcoffB               ((uint32_t)0x00F4)
#define   ECR_I1TCcoffC               ((uint32_t)0x00F8)
#define   ECR_I2TCcoffA               ((uint32_t)0x00FC)
#define   ECR_I2TCcoffB               ((uint32_t)0x0100)
#define   ECR_I2TCcoffC               ((uint32_t)0x0104)
#define   ECR_LoadDataCp              ((uint32_t)0x0108)
#define   ECR_SRSTREG                 ((uint32_t)0x0114)
#if defined HT502x
#define   ECR_BufferStart             ((uint32_t)0x010C)
#define   ECR_BufferCoff              ((uint32_t)0x0110)
#define   ECR_PFCntN                  ((uint32_t)0x0118)
#define   ECR_QFCntN                  ((uint32_t)0x011C)
#elif defined HT503x
#define   ECR_SyncCoff                ((uint32_t)0x0110)
#define   ECR_CF1CntN             	  ((uint32_t)0x0118)
#define   ECR_CF2CntN                 ((uint32_t)0x011C)
#define   ECR_CF3CntN                 ((uint32_t)0x0120)
#define   ECR_SyncStart               ((uint32_t)0x0124)
#define   ECR_HCycleRMS_DphFix        ((uint32_t)0x0128)
#define   ECR_EMUCON2                 ((uint32_t)0x012C)
#define   ECR_DECShift                ((uint32_t)0x0130)
#define   ECR_AVG_PRMS                ((uint32_t)0x0134)
#define   ECR_AFDIV                   ((uint32_t)0x0138)
#define   ECR_LpRMS_THO               ((uint32_t)0x013C)
#define   ECR_PeakLVLHys              ((uint32_t)0x0140)
#define   ECR_SagLVLHys               ((uint32_t)0x0144)
#define   ECR_UZCLVL             	  ((uint32_t)0x0148)
#define   ECR_RMSIt_THO               ((uint32_t)0x014C)
#define   ECR_Fund_GP1                ((uint32_t)0x0150)
#define   ECR_Fund_GP2                ((uint32_t)0x0154)
#define   ECR_Fund_P1Offset           ((uint32_t)0x0158)
#define   ECR_Fund_P2Offset           ((uint32_t)0x015C)
#define   ECR_Fund_I1RMSOffset        ((uint32_t)0x0160)
#define   ECR_Fund_I2RMSOffset        ((uint32_t)0x0164)
#define   ECR_Fund_URMSOffset         ((uint32_t)0x0168)
#define   ECR_FlickerCFG              ((uint32_t)0x016C)
#define   ECR_FlickerSqrOffset        ((uint32_t)0x0170)
#define   ECR_FlickerReset            ((uint32_t)0x0174)
#define   ECR_FundCFG                 ((uint32_t)0x0178)
#define   ECR_ZCNumCFG                ((uint32_t)0x017C)
#define   ECR_CycRmsNum               ((uint32_t)0x0180)
#endif

/**************************************************************************
*                         BIT DEFINE
***************************************************************************/

#define   ECR_PowerConst_Load          ((uint32_t)0x000000BC)
#define   ECR_Flicker_Reset            ((uint32_t)0x00000069)
#define   ECR_EMU_CReg_Reset           ((uint32_t)0x00000055)
#define   ECR_EMU_MODULE_Reset         ((uint32_t)0x000000AA)

#define   ECR_EMU_HFConst_LLimit       ((uint32_t)0x00000002)
#define   ECR_EMU_AVGNUM_HLimit        ((uint32_t)0x00002C88)
#define   ECR_EMU_AVGNUM_LLimit        ((uint32_t)0x0000002d)
#define   ECR_EMU_OneCycNUM_LLimit     ((uint32_t)0x00000006)


#define   EPR_32BIT_DATA               ((uint32_t)0xffffffff)

#define   ECR_3BIT_DATA                ((uint32_t)0x00000007)
#define   ECR_5BIT_DATA                ((uint32_t)0x0000001f)
#define   ECR_7BIT_DATA                ((uint32_t)0x0000007f)
#define   ECR_8BIT_DATA                ((uint32_t)0x000000ff)
#define   ECR_9BIT_DATA                ((uint32_t)0x000001ff)
#define   ECR_10BIT_DATA               ((uint32_t)0x000003ff)
#define   ECR_14BIT_DATA               ((uint32_t)0x00003fff)
#define   ECR_15BIT_DATA               ((uint32_t)0x00007fff)
#define   ECR_16BIT_DATA               ((uint32_t)0x0000ffff)
#define   ECR_19BIT_DATA               ((uint32_t)0x0007ffff)
#define   ECR_21BIT_DATA               ((uint32_t)0x001fffff)
#define   ECR_22BIT_DATA               ((uint32_t)0x003fffff)
#define   ECR_24BIT_DATA               ((uint32_t)0x00ffffff)
#define   ECR_30BIT_DATA               ((uint32_t)0x3fffffff)
#define   ECR_32BIT_DATA               ((uint32_t)0xffffffff)



/**************************  Bit definition for EMUSR register  ********************************/
#if defined HT503x
#define EMUSR_REV_CF1				((uint32_t)(1UL<<0))
#define EMUSR_REV_CF2				((uint32_t)(1UL<<1))
#define EMUSR_NOLOAD_ALLP1			((uint32_t)(1UL<<2))
#define EMUSR_NOLOAD_ALLQ1			((uint32_t)(1UL<<3))
#define EMUSR_NOLOAD_ALLP2			((uint32_t)(1UL<<4))
#define EMUSR_NOLOAD_ALLQ2			((uint32_t)(1UL<<5))
#define EMUSR_I2GTI1				((uint32_t)(1UL<<6))
#define EMUSR_TAMP					((uint32_t)(1UL<<7))
#define EMUSR_CHANELSTATUS			((uint32_t)(1UL<<8))
#define EMUSR_OV_ENERGYPOS_CF1		((uint32_t)(1UL<<9))
#define EMUSR_OV_ENERGYPOS_CF2		((uint32_t)(1UL<<10))
#define EMUSR_OV_ENERGYPOS_CF3		((uint32_t)(1UL<<11))
#define EMUSR_OV_ENERGYNEG_CF1		((uint32_t)(1UL<<12))
#define EMUSR_OV_ENERGYNEG_CF2		((uint32_t)(1UL<<13))
#define EMUSR_OV_ENERGYNEG_CF3		((uint32_t)(1UL<<14))
#define EMUSR_NOLOAD_FUNDP1			((uint32_t)(1UL<<15))
#define EMUSR_NOLOAD_FUNDP2			((uint32_t)(1UL<<16))
#define EMUSR_REV_CF3				((uint32_t)(1UL<<17))
#define EMUSR_ZCVALID_U				((uint32_t)(1UL<<18))
#define EMUSR_ZCVALID_I1			((uint32_t)(1UL<<19))
#define EMUSR_ZCVALID_I2			((uint32_t)(1UL<<20))
#define EMUSR_PEAK_STATUS			((uint32_t)(1UL<<21))
#define EMUSR_SAG_STATUS			((uint32_t)(1UL<<22))
#define EMUSR_ADC_OV_U				((uint32_t)(1UL<<23))
#define EMUSR_ADC_OV_I1				((uint32_t)(1UL<<24))
#define EMUSR_ADC_OV_I2				((uint32_t)(1UL<<25))
#define EMUSR_CLEAR                 ((uint32_t)0x3807E00)
#else
#define EMUSR_SFOF              	((uint32_t)(1UL<<11))    /*<apparent energy register overflow >*/
#define EMUSR_PEOF              	((uint32_t)(1UL<<10))    /*<active energy register overflow >*/
#define EMUSR_QEOF              	((uint32_t)(1UL<<9))    /*<reactive energy register overflow >*/
#define EMUSR_CHSTS             	((uint32_t)(1UL<<8))    /*<valid energy channel flag>*/
#define EMUSR_TAMP              	((uint32_t)(1UL<<7))    /*<Anti-tamper flag>*/
#define EMUSR_G2GTI1            	((uint32_t)(1UL<<6))    /*<current or energy power of I2 upper I1 flag >*/
#define EMUSR_NOQLD2            	((uint32_t)(1UL<<5))    /*<channle 2 reactive power creeping flag>*/
#define EMUSR_NOPLD2            	((uint32_t)(1UL<<4))    /*<channle 2 active power creeping flag>*/
#define EMUSR_NOQLD1            	((uint32_t)(1UL<<3))    /*<channle 1 reactive power creeping flag>*/
#define EMUSR_NOPLD1            	((uint32_t)(1UL<<2))    /*<channle 1 active power creeping flag>*/
#define EMUSR_ALL                   ((uint32_t)0xFFC)
#endif

/**************************  Bit definition for EMUIE register  ********************************/
#if defined HT503x
#define EMUIE_SAG_START				((uint32_t)(1UL<<0))
#define EMUIE_PEAK_START			((uint32_t)(1UL<<1))
#define EMUIE_IOV_I1				((uint32_t)(1UL<<2))
#define EMUIE_ZC_U					((uint32_t)(1UL<<3))
#define EMUIE_SPL_UPD				((uint32_t)(1UL<<4))
#define EMUIE_CF3					((uint32_t)(1UL<<5))
#define EMUIE_CF2					((uint32_t)(1UL<<6))
#define EMUIE_CF1					((uint32_t)(1UL<<7))
#define EMUIE_IOV_I2				((uint32_t)(1UL<<8))
#define EMUIE_ZC_I1					((uint32_t)(1UL<<9))
#define EMUIE_ZC_I2					((uint32_t)(1UL<<10))
#define EMUIE_FASTRMS_UPD			((uint32_t)(1UL<<11))
#define EMUIE_SLOWRMS_UPD			((uint32_t)(1UL<<12))
#define EMUIE_DCAVG_UPD				((uint32_t)(1UL<<13))
#define EMUIE_TAMP					((uint32_t)(1UL<<14))
#define EMUIE_PEAK_END				((uint32_t)(1UL<<15))
#define EMUIE_SAG_END				((uint32_t)(1UL<<16))
#define EMUIE_ZCLOST_U				((uint32_t)(1UL<<17))

#define EMUIE_SYNC_UPD				((uint32_t)(1UL<<19))
#define EMUIE_LPRMS_OV				((uint32_t)(1UL<<20))
#define EMUIE_RMSIT_OV				((uint32_t)(1UL<<21))
#define EMUIE_FUND_PRMS_UPD			((uint32_t)(1UL<<22))
#define EMUIE_FLICKER_UPD			((uint32_t)(1UL<<23))
#define EMUIE_HCYCVP_U_UPD			((uint32_t)(1UL<<24))
#define EMUIE_HCYCRMS_UPD			((uint32_t)(1UL<<25))
#define EMUIE_CYCRMS_UPD			((uint32_t)(1UL<<26))
#define EMUIE_ALL                   ((uint32_t)0x7FBFFFF)
#else

    #if defined HT502x
#define   EMUIE_ZXLOST            ((uint32_t)(1UL<<17))
#define   EMUIE_BUFFULL           ((uint32_t)(1UL<<16))
#define   EMUIE_UDET              ((uint32_t)(1UL<<15))
    #endif
#define   EMUIE_TAMP              ((uint32_t)(1UL<<14))
#define   EMUIE_DCUPDATE          ((uint32_t)(1UL<<13))
#define   EMUIE_SRMS              ((uint32_t)(1UL<<12))
#define   EMUIE_FRMS              ((uint32_t)(1UL<<11))
#define   EMUIE_ZXI2              ((uint32_t)(1UL<<10))
#define   EMUIE_ZXI1              ((uint32_t)(1UL<<9))
#define   EMUIE_I2OV              ((uint32_t)(1UL<<8))
#define   EMUIE_PF                ((uint32_t)(1UL<<7))
#define   EMUIE_QF                ((uint32_t)(1UL<<6))
#define   EMUIE_SF                ((uint32_t)(1UL<<5))
#define   EMUIE_SPL               ((uint32_t)(1UL<<4))
#define   EMUIE_ZXU               ((uint32_t)(1UL<<3))
#define   EMUIE_I1OV              ((uint32_t)(1UL<<2))
#define   EMUIE_UOV               ((uint32_t)(1UL<<1))
#define   EMUIE_SAG               ((uint32_t)(1UL<<0))

    #if defined HT502x
#define   EMUIE_ALL               ((uint32_t)0x3FFFF)
    #else
#define   EMUIE_ALL               ((uint32_t)0x7FFF)
    #endif 
#endif 
/**************************  Bit definition for EMUIF register  ********************************/
#if defined HT501x ||defined HT502x
#if defined HT502x
#define   EMUIF_ZXLOST            ((uint32_t)(1UL<<18))
#define   EMUIF_BUFFULL           ((uint32_t)(1UL<<17))
#define   EMUIF_UEND              ((uint32_t)(1UL<<16))
#define   EMUIF_USTART            ((uint32_t)(1UL<<15))
#endif                            
#define   EMUIF_TAMP              ((uint32_t)(1UL<<14))
#define   EMUIF_DCUPDATE          ((uint32_t)(1UL<<13))
#define   EMUIF_SRMS              ((uint32_t)(1UL<<12))
#define   EMUIF_FRMS              ((uint32_t)(1UL<<11))
#define   EMUIF_ZXI2              ((uint32_t)(1UL<<10))
#define   EMUIF_ZXI1              ((uint32_t)(1UL<<9))
#define   EMUIF_I2OV              ((uint32_t)(1UL<<8))
#define   EMUIF_PF                ((uint32_t)(1UL<<7))
#define   EMUIF_QF                ((uint32_t)(1UL<<6))
#define   EMUIF_SF                ((uint32_t)(1UL<<5))
#define   EMUIF_SPL               ((uint32_t)(1UL<<4))
#define   EMUIF_ZXU               ((uint32_t)(1UL<<3))
#define   EMUIF_I1OV              ((uint32_t)(1UL<<2))
#define   EMUIF_UOV               ((uint32_t)(1UL<<1))
#define   EMUIF_SAG               ((uint32_t)(1UL<<0))

    #if defined HT502x
#define   EMUIF_ALL               ((uint32_t)0x7FFFF)
    #else
#define   EMUIF_ALL               ((uint32_t)0x7FFF)
    #endif

#elif defined HT503x
#define EMUIF_SAG_START				((uint32_t)(1UL<<0))
#define EMUIF_PEAK_START			((uint32_t)(1UL<<1))
#define EMUIF_IOV_I1				((uint32_t)(1UL<<2))
#define EMUIF_ZC_U					((uint32_t)(1UL<<3))
#define EMUIF_SPL_UPD				((uint32_t)(1UL<<4))
#define EMUIF_CF3					((uint32_t)(1UL<<5))
#define EMUIF_CF2					((uint32_t)(1UL<<6))
#define EMUIF_CF1					((uint32_t)(1UL<<7))
#define EMUIF_IOV_I2				((uint32_t)(1UL<<8))
#define EMUIF_ZC_I1					((uint32_t)(1UL<<9))
#define EMUIF_ZC_I2					((uint32_t)(1UL<<10))
#define EMUIF_FASTRMS_UPD			((uint32_t)(1UL<<11))
#define EMUIF_SLOWRMS_UPD			((uint32_t)(1UL<<12))
#define EMUIF_DCAVG_UPD				((uint32_t)(1UL<<13))
#define EMUIF_TAMP					((uint32_t)(1UL<<14))
#define EMUIF_PEAK_END				((uint32_t)(1UL<<15))
#define EMUIF_SAG_END				((uint32_t)(1UL<<16))
#define EMUIF_ZCLOST_U				((uint32_t)(1UL<<17))

#define EMUIF_SYNC_UPD				((uint32_t)(1UL<<19))
#define EMUIF_LPRMS_OV				((uint32_t)(1UL<<20))
#define EMUIF_RMSIT_OV				((uint32_t)(1UL<<21))
#define EMUIF_FUND_PRMS_UPD			((uint32_t)(1UL<<22))
#define EMUIF_FLICKER_UPD			((uint32_t)(1UL<<23))
#define EMUIF_HCYCVP_U_UPD			((uint32_t)(1UL<<24))
#define EMUIF_HCYCRMS_UPD			((uint32_t)(1UL<<25))
#define EMUIF_CYCRMS_UPD			((uint32_t)(1UL<<26))
#define   EMUIF_ALL               ((uint32_t)0x7FBFFFF)

#endif
/**************************  50Hz or 60Hz selection for QPHSCal register  **************************************************************/
#if defined HT501x ||defined HT502x
#define   QPHSCAL_50Hz            ((uint32_t)0x005e)      /*<Reactive power phase compensation register value>*/
#define   QPHSCAL_60Hz            ((uint32_t)0x0044)      /*<Reactive power phase compensation register value>*/
#endif
/**************************  Bit definition for ADCCFG register  ***********************************************************************/
#if defined HT503x
#define ADCCFG_HCYCLERMS_I2_EN		((uint32_t)(1UL<<23))	

#define ADCCFG_HCYCLERMS_SEL		((uint32_t)(1UL<<22))		
#define ADCCFG_HCYCLERMS_SEL_HALF	((uint32_t)(0UL<<22))		
#define ADCCFG_HCYCLERMS_SEL_ONE	((uint32_t)(1UL<<22))

#define ADCCFG_HCYCLERMS_EN			((uint32_t)(1UL<<21))
#define ADCCFG_RMSIT_ADDMODE		((uint32_t)(1UL<<20))		
#define ADCCFG_RMSIT_ADDMODE_SUB	((uint32_t)(0UL<<20))		
#define ADCCFG_RMSIT_ADDMODE_ADD	((uint32_t)(1UL<<20))

#define ADCCFG_FUNDIT_EN			((uint32_t)(1UL<<19))
#define ADCCFG_RMSIT_EN				((uint32_t)(1UL<<18))

#define ADCCFG_DMA_SRCSEL			((uint32_t)(1UL<<17))		
#define ADCCFG_DMA_SRCSEL_SPL		((uint32_t)(0UL<<17))		
#define ADCCFG_DMA_SRCSEL_SYNC		((uint32_t)(1UL<<17))

#define ADCCFG_SSTART_CFG			((uint32_t)(1UL<<16))		
#define ADCCFG_SSTART_CFG_SSTART	((uint32_t)(0UL<<16))		
#define ADCCFG_SSTART_CFG_PORQ		((uint32_t)(1UL<<16))		
#endif
#define ADCCFG_PQSStartSourceSel                  ((uint32_t)(3UL<<14))      /*<PQS start and creep compare source control bits>*/
#define ADCCFG_PQSStartSourceSel_FastPower        ((uint32_t)(0UL<<14))      /*<PQS start creep source select Fast Power>*/
#define ADCCFG_PQSStartSourceSel_SlowPower        ((uint32_t)(1UL<<14))      /*<PQS start and creep source select Slow Power>*/
#define ADCCFG_PQSStartSourceSel_InstantPower     ((uint32_t)(2UL<<14))      /*<PQS start creep source select Instantaneous Power>*/

#define ADCCFG_VrefEn           	((uint32_t)(1UL<<13))      /*<Vref enable control bit>*/

#define ADCCFG_AddCIADD         	((uint32_t)(1UL<<12))      /*<Accumulation mode control bit in Single-phase three-wire mode>*/
#define ADCCFG_ADD_CIADD_ABS		((uint32_t)(0UL<<12))		
#define ADCCFG_ADD_CIADD_ADD		((uint32_t)(1UL<<12))		

#define ADCCFG_WaveSel          	((uint32_t)(1UL<<11))      /*<ADC waveform sampled data source selection bit>*/
#define ADCCFG_WaveSel_Origi    	((uint32_t)(0UL<<11))      /*<ADC waveform sampled data source selection original data>*/
#define ADCCFG_WaveSel_HPF     		((uint32_t)(1UL<<11))      /*<ADC waveform sampled data source selection by high pass filter data>*/


#define ADCCFG_TampSourceSel    	((uint32_t)(1UL<<10))      /*<Power stealing auto-prevention channel interchannel compare source selection bit>*/
#define ADCCFG_TAMP_SRCSEL_SLOW		((uint32_t)(0UL<<10))		
#define ADCCFG_TAMP_SRCSEL_FAST		((uint32_t)(1UL<<10))	

#define ADCCFG_IPTampSource_Sel 	((uint32_t)(1UL<<9))      /*<Power stealing auto-prevention threshold judgement source fast/slow selection bit>*/
#define ADCCFG_IPTAMP_SRCSEL_SLOW	((uint32_t)(0UL<<9))
#define ADCCFG_IPTAMP_SRCSEL_FAST	((uint32_t)(1UL<<9))

#define ADCCFG_CHNFix           	((uint32_t)(1UL<<8))      /*<Power stealing auto-prevention small signal channel switch configuration bit>*/
#define ADCCFG_CHNFIX_CH1			((uint32_t)(0UL<<8))		
#define ADCCFG_CHNFIX_BEFORECH		((uint32_t)(1UL<<8))		

#define ADCCFG_IPTampSel        	((uint32_t)(1UL<<7))     /*<Power stealing auto-prevention threshold judgement basis selection bit>*/
#define ADCCFG_IPTAMP_SEL_RMS		((uint32_t)(0UL<<7))
#define ADCCFG_IPTAMP_SEL_POWER		((uint32_t)(1UL<<7))

#define ADCCFG_TampSel          	((uint32_t)(1UL<<6))      /*<Power stealing prevention comparisonmethod selection bit>*/
#define ADCCFG_TAMP_SEL_RMS			((uint32_t)(0UL<<6))		
#define ADCCFG_TAMP_SEL_POWER		((uint32_t)(1UL<<6))		

#define ADCCFG_FLTON				((uint32_t)(1UL<<5))      /*<Power stealing auto-prevention module enable bit>*/
#define ADCCFG_CHNSEL				((uint32_t)(1UL<<4))      /*<Select the channel to measure channel selection bit>*/
#define ADCCFG_CHNSEL_1				((uint32_t)(0UL<<4))		
#define ADCCFG_CHNSEL_2				((uint32_t)(1UL<<4))		

#define ADCCFG_CIADD				((uint32_t)(1UL<<3))      /*<Single-phase three-wire accumulation mode selection bit>*/

#define ADCCFG_SPL 					((uint32_t)(7UL<<0))		/*SPL Update£¬fs div*/
#define ADCCFG_SPL_1K6          	((uint32_t)(0UL<<0))      /*<Waveform sample frequency is 1.6KHz>*/
#define ADCCFG_SPL_3K2          	((uint32_t)(1UL<<0))      /*<Waveform sample frequency is 3.2KHz>*/
#define ADCCFG_SPL_6K4          	((uint32_t)(2UL<<0))      /*<Waveform sample frequency is 6.4KHz>*/
#define ADCCFG_SPL_12K8         	((uint32_t)(3UL<<0))      /*<Waveform sample frequency is 12.8KHz>*/

/**************************  Bit definition for CHNLCR register  ***********************************************************************/
#if defined HT503x
#define CHNLCR_IHAIFVP_ZCSEL		((uint32_t)(1UL<<20))		
#define CHNLCR_IHAIFVP_ZCSEL_I		((uint32_t)(0UL<<20))		
#define CHNLCR_IHAIFVP_ZCSEL_U		((uint32_t)(1UL<<20))

#define CHNLCR_LPPROC_SEL			((uint32_t)(1UL<<19))		
#define CHNLCR_LPPROC_SEL_NORMAL	((uint32_t)(0UL<<19))		
#define CHNLCR_LPPROC_SEL_ONECYC	((uint32_t)(1UL<<19))

#define CHNLCR_ONECYCRMS_EN			((uint32_t)(1UL<<18))				

#define CHNLCR_PEAKSAG_SRCSEL		((uint32_t)(1UL<<17))		
#define CHNLCR_PEAKSAG_SRCSEL_HVP	((uint32_t)(0UL<<17))		
#define CHNLCR_PEAKSAG_SRCSEL_HRMS	((uint32_t)(1UL<<17))		

#define CHNLCR_SAG_EN				((uint32_t)(1UL<<16))		/*<Voltage SAG function enable control bit>*/
#endif

#define CHNLCR_PDatacpEn        	((uint32_t)(1UL<<15))      /*<Active power constant calculation enable bit>*/
#define CHNLCR_QDatacpEn        	((uint32_t)(1UL<<14))      /*<Reactive power constant calculation enable bit>*/
#define CHNLCR_SDatacpEn        	((uint32_t)(1UL<<13))      /*<Apparent power constant calculation enable bit>*/
#if defined HT503x
#define CHNLCR_IOV_EN				((uint32_t)(1UL<<12))		
#define CHNLCR_PEAK_EN				((uint32_t)(1UL<<11))		/*<Voltage peak function enable control bit>*/
#else
#define CHNLCR_Ipeak_En         	((uint32_t)(1UL<<12))      /*<Over-voltage over-current enable control bit>*/
#define CHNLCR_Udet_En          	((uint32_t)(1UL<<11))      /*<Voltage SAG/peak function enable control bit>*/
#endif
#define CHNLCR_RmsLpfEn         	((uint32_t)(1UL<<10))      /*<RmsLpf enable control bit>*/
#define CHNLCR_PQLpfEn          	((uint32_t)(1UL<<9))      /*<PQLpf enable control bit>*/
#define CHNLCR_Add_DataCP       	((uint32_t)(1UL<<8))      /*<Energy accumulation rate selection bit during constant calculation bit>*/
#define CHNLCR_ENERGY_CLKSEL_32K	((uint32_t)(0UL<<8))		
#define CHNLCR_ENERGY_CLKSEL_BS		((uint32_t)(1UL<<8))		

#define CHNLCR_LPMode           	((uint32_t)(1UL<<7))      /*<Low power consumption mode enable control bit>*/

#define CHNLCR_POS              	((uint32_t)(1UL<<6))      /*<Pulse significant level selection bit>*/
#define CHNLCR_POS_HIGH				((uint32_t)(0UL<<6))		
#define CHNLCR_POS_LOW				((uint32_t)(1UL<<6))		

#define CHNLCR_LPFreqSel        	((uint32_t)(1UL<<5))      /*<Low power consumption mode clock selection bit>*/
#define CHNLCR_LP_EMUCLK_SEL_32K	((uint32_t)(0UL<<5))		
#define CHNLCR_LP_EMUCLK_SEL_204K	((uint32_t)(1UL<<5))		

#define CHNLCR_UconstEn         	((uint32_t)(1UL<<4))      /*<Low power consumption mode apparent power voltage source selection bit>*/

#define CHNLCR_PSSel            	((uint32_t)(1UL<<3))      /*<Output Pulse type selection bit>*/
#define CHNLCR_PSCF_SEL_CF1PCF3S	((uint32_t)(0UL<<3))		
#define CHNLCR_PSCF_SEL_CF1SCF3P	((uint32_t)(1UL<<3))

#define CHNLCR_HPFON            	((uint32_t)(7UL<<0))      /*<Voltage channel &Current channel2 &Current channel1 high pass filter switches bits>*/
#define CHNLCR_HPFEN_U				((uint32_t)(1UL<<0))		/*<U/I1/I2 HPF need all open for normal metering >*/		
#define CHNLCR_HPFEN_I1				((uint32_t)(1UL<<1))		
#define CHNLCR_HPFEN_I2				((uint32_t)(1UL<<2))	
/**************************  Bit definition for EMCON register  ***********************************************************************/
#if defined HT503x
#define EMUCON_CF1CFG				((uint32_t)(0xfUL<<14))		
#define EMUCON_CF1CFG_CF1PN			((uint32_t)(0UL<<14))
#define EMUCON_CF1CFG_CF2PN			((uint32_t)(1UL<<14))
#define EMUCON_CF1CFG_CF3PN			((uint32_t)(2UL<<14))
#define EMUCON_CF1CFG_CF1P			((uint32_t)(4UL<<14))
#define EMUCON_CF1CFG_CF1N			((uint32_t)(5UL<<14))
#define EMUCON_CF1CFG_CF2P			((uint32_t)(6UL<<14))
#define EMUCON_CF1CFG_CF2N			((uint32_t)(7UL<<14))
#define EMUCON_CF1CFG_CF3P			((uint32_t)(8UL<<14))
#define EMUCON_CF1CFG_CF3N			((uint32_t)(9UL<<14))

#define EMUCON_CF2CFG				((uint32_t)(3UL<<12))		
#define EMUCON_CF2CFG_CF1PN			((uint32_t)(0UL<<12))
#define EMUCON_CF2CFG_CF2PN			((uint32_t)(1UL<<12))
#define EMUCON_CF2CFG_CF3PN			((uint32_t)(2UL<<12))

#define EMUCON_CF3CFG				((uint32_t)(3UL<<10))		
#define EMUCON_CF3CFG_CF1PN			((uint32_t)(0UL<<10))
#define EMUCON_CF3CFG_CF2PN			((uint32_t)(1UL<<10))
#define EMUCON_CF3CFG_CF3PN			((uint32_t)(2UL<<10))
#else
#define EMCON_CF1CFG            	((uint32_t)(3UL<<14))      /*<CF1 interface output configuration control bits>*/
#define EMCON_CF1CFG_P          	((uint32_t)(0UL<<14))      /*<CF1 interface output P pulse>*/
#define EMCON_CF1CFG_Q          	((uint32_t)(1UL<<14))      /*<CF1 interface output Q pulse>*/
#define EMCON_CF1CFG_S          	((uint32_t)(2UL<<14))      /*<CF1 interface output S pulse>*/
                                
#define EMCON_CF2CFG            	((uint32_t)(3UL<<12))      /*<CF2 interface output configuration control bits>*/
#define EMCON_CF2CFG_P          	((uint32_t)(0UL<<12))      /*<CF2 interface output P pulse>*/
#define EMCON_CF2CFG_Q          	((uint32_t)(1UL<<12))      /*<CF2 interface output Q pulse>*/
#define EMCON_CF2CFG_S          	((uint32_t)(2UL<<12))      /*<CF2 interface output S pulse>*/
                                
#define EMCON_CF3CFG            	((uint32_t)(3UL<<10))      /*<CF3 interface output configuration control bits>*/
#define EMCON_CF3CFG_P          	((uint32_t)(0UL<<10))      /*<CF3 interface output P pulse>*/
#define EMCON_CF3CFG_Q          	((uint32_t)(1UL<<10))      /*<CF3 interface output Q pulse>*/
#define EMCON_CF3CFG_S          	((uint32_t)(2UL<<10))      /*<CF3 interface output S pulse>*/
#endif
#if defined HT501x ||defined HT502x
#define EMCON_AverPowerCal      	((uint32_t)(1UL<<9))       /*<Energy accumulation source selection bit>*/
#endif
				
#define EMCON_AverPowerSource   	((uint32_t)(1UL<<8))       /*<If AverPowerCal =1, average power source selection bit>*/
#define EMUCON_POWERAVG_SRCSEL_FAST	((uint32_t)(0UL<<8))		
#define EMUCON_POWERAVG_SRCSEL_SLOW	((uint32_t)(1UL<<8))

#define EMUCON_OSR_SEL				((uint32_t)(1UL<<7))		/*<OSR selection bit of normal calculation mode selection bit>*/
#define EMUCON_OSR64				((uint32_t)(0UL<<7))		
#define EMCON_OSR128            	((uint32_t)(1UL<<7))      

#define EMCON_SRun              	((uint32_t)(1UL<<6))      /*<Apparent energy accumulation enable bit>*/
#define EMCON_QRun              	((uint32_t)(1UL<<5))      /*<Reactive energy accumulation enable bit>*/
#define EMCON_PRun              	((uint32_t)(1UL<<4))      /*<Active energy accumulation enable bit>*/

#define EMCON_QMOD              	((uint32_t)(3UL<<2))     /*<Reactive energy accumulation method selection>*/
#define EMCON_QMOD_Algebraic    	((uint32_t)(0UL<<2))     /*<Accumulate reactive power in algebraic addition way>*/
#define EMCON_QMOD_Positive     	((uint32_t)(1UL<<2))     /*<only accumulate the positive reactive power>*/
#define EMCON_QMOD_Absolute     	((uint32_t)(2UL<<2))     /*<accumulate reactive power in absolute value format>*/
#if defined HT503x
#define EMUCON_ACCUNODE_CF2_PN		((uint32_t)(3UL<<2))
#endif

#define EMCON_PMOD              	((uint32_t)(3UL<<0))      /*<Active energy accumulation method selection>*/
#define EMCON_PMOD_Algebraic    	((uint32_t)(0UL<<0))      /*<Accumulate active power in algebraic addition way>*/
#define EMCON_PMOD_Positive     	((uint32_t)(1UL<<0))      /*<only accumulate the positive active power>*/
#define EMCON_PMOD_Absolute     	((uint32_t)(2UL<<0))      /*<accumulate active power in absolute value format>*/
#if defined HT503x
#define EMUCON_ACCUNODE_CF1_PN		((uint32_t)(3UL<<0))		
#endif
/**************************  Bit definition for ADCCON register  *******************************************************************/
#if defined HT503x
#define   ADCCON_POWER_SHIFT		((uint32_t)(7UL<<16))		
#define   ADCCON_POWER_SHIFT_1		((uint32_t)(0UL<<16))
#define   ADCCON_POWER_SHIFT_2		((uint32_t)(1UL<<16))
#define   ADCCON_POWER_SHIFT_4		((uint32_t)(2UL<<16))
#define   ADCCON_POWER_SHIFT_8		((uint32_t)(3UL<<16))
#define   ADCCON_POWER_SHIFT_16		((uint32_t)(4UL<<16))

#define   ADCCON_PGAI1_24		  ((uint32_t)(1UL<<14))	
#endif
#define   ADCCON_DGI2             ((uint32_t)(3UL<<12))      /*<I2 channel digital gain setting>*/
#define   ADCCON_DGI2_1           ((uint32_t)(0UL<<12))      /*<I2 channel digital gain is 1>*/
#define   ADCCON_DGI2_2           ((uint32_t)(1UL<<12))      /*<I2 channel digital gain is 2>*/
#define   ADCCON_DGI2_4           ((uint32_t)(2UL<<12))      /*<I2 channel digital gain is 4>*/
#define   ADCCON_DGI2_8           ((uint32_t)(3UL<<12))      /*<I2 channel digital gain is 8>*/
                                  
#define   ADCCON_DGI1             ((uint32_t)(3UL<<10))      /*<I1 channel digital gain setting>*/
#define   ADCCON_DGI1_1           ((uint32_t)(0UL<<10))      /*<I1 channel digital gain is 1>*/
#define   ADCCON_DGI1_2           ((uint32_t)(1UL<<10))      /*<I1 channel digital gain is 2>*/
#define   ADCCON_DGI1_4           ((uint32_t)(2UL<<10))      /*<I1 channel digital gain is 4>*/
#define   ADCCON_DGI1_8           ((uint32_t)(3UL<<10))      /*<I1 channel digital gain is 8>*/
                                  
#define   ADCCON_DGU              ((uint32_t)(3UL<<8))      /*<U channel digital gain setting>*/
#define   ADCCON_DGU_1            ((uint32_t)(0UL<<8))      /*<U channel digital gain is 1>*/
#define   ADCCON_DGU_2            ((uint32_t)(1UL<<8))      /*<U channel digital gain is 2>*/
#define   ADCCON_DGU_4            ((uint32_t)(2UL<<8))      /*<U channel digital gain is 4>*/
#define   ADCCON_DGU_8            ((uint32_t)(3UL<<8))      /*<U channel digital gain is 8>*/
                                  
#define   ADCCON_CFP              ((uint32_t)(3UL<<6))      /*<pulse width setting>*/
#define   ADCCON_CFP_80MS         ((uint32_t)(0UL<<6))      /*<pulse width is 80ms>*/
#define   ADCCON_CFP_40MS         ((uint32_t)(1UL<<6))      /*<pulse width is 40ms>*/
#define   ADCCON_CFP_20MS         ((uint32_t)(2UL<<6))      /*<pulse width is 20ms>*/
#define   ADCCON_CFP_10MS         ((uint32_t)(3UL<<6))      /*<pulse width is 10ms>*/

#define   ADCCON_ANAI2            ((uint32_t)(3UL<<4))      /*<I2 channel analogl gain setting>*/
#define   ADCCON_ANAI2_1          ((uint32_t)(0UL<<4))      /*<I2 channel analogl gain is 1>*/
#define   ADCCON_ANAI2_2          ((uint32_t)(1UL<<4))      /*<I2 channel analogl gain is 2>*/
#define   ADCCON_ANAI2_8          ((uint32_t)(2UL<<4))      /*<I2 channel analogl gain is 8>*/
#define   ADCCON_ANAI2_16         ((uint32_t)(3UL<<4))      /*<I2 channel analogl gain is 16>*/
                                  
#define   ADCCON_ANAI1            ((uint32_t)(3UL<<2))      /*<I2 channel analogl gain setting>*/
#define   ADCCON_ANAI1_1          ((uint32_t)(0UL<<2))      /*<I2 channel analogl gain is 1>*/
#define   ADCCON_ANAI1_2          ((uint32_t)(1UL<<2))      /*<I2 channel analogl gain is 2>*/
#define   ADCCON_ANAI1_8          ((uint32_t)(2UL<<2))      /*<I2 channel analogl gain is 8>*/
#define   ADCCON_ANAI1_16         ((uint32_t)(3UL<<2))      /*<I2 channel analogl gain is 16>*/
                                  
#define   ADCCON_ANAU             ((uint32_t)(3UL<<0))      /*<U channel analogl gain setting>*/
#define   ADCCON_ANAU_1           ((uint32_t)(0UL<<0))      /*<U channel analogl gain is 1>*/
#define   ADCCON_ANAU_2           ((uint32_t)(1UL<<0))      /*<U channel analogl gain is 2>*/
#define   ADCCON_ANAU_4           ((uint32_t)(2UL<<0))      /*<U channel analogl gain is 4>*/
#if defined HT501x ||defined HT502x
#define   ADCCON_ANAU_8           ((uint32_t)(3UL<<0))      /*<U channel analogl gain is 8>*/
#endif
/**************************  Bit definition for EMUCTRL register  ***********************************************************************/
#if defined HT503x
#define   EMUCTRL_POWERQ_SRCSEL			((uint32_t)(1UL<<19))		
#define   EMUCTRL_POWERQ_SRCSEL_ALL		((uint32_t)(0UL<<19))		
#define   EMUCTRL_POWERQ_SRCSEL_FUND	((uint32_t)(1UL<<19))

#define   EMUCTRL_POWERS_SRCSEL			((uint32_t)(1UL<<18))		
#define   EMUCTRL_POWERS_SRCSEL_ALL		((uint32_t)(0UL<<18))		
#define   EMUCTRL_POWERS_SRCSEL_FUND	((uint32_t)(1UL<<18))		

#define   EMUCTRL_FUND_UPD				((uint32_t)(7UL<<15))		
#define   EMUCTRL_FUND_UPD_1			((uint32_t)(0UL<<15))
#define   EMUCTRL_FUND_UPD_2			((uint32_t)(1UL<<15))
#define   EMUCTRL_FUND_UPD_4			((uint32_t)(2UL<<15))
#define   EMUCTRL_FUND_UPD_8			((uint32_t)(3UL<<15))
#define   EMUCTRL_FUND_UPD_16			((uint32_t)(4UL<<15))
#define   EMUCTRL_FUND_UPD_32			((uint32_t)(5UL<<15))

#define   EMUCTRL_NORMAL_EMUCLK_SEL_1638K	((uint32_t)(1UL<<14))		
#endif

#define   EMUCTRL_StartSel        ((uint32_t)(1UL<<13))      /*<Anti creep mode selection bit>*/
#define   EMUCTRL_StartSel_PQResp ((uint32_t)(0UL<<13))      /*<Anti creep mode selection bit=0, P, Q judgment respectively; >*/
#define   EMUCTRL_StartSel_PorQ   ((uint32_t)(1UL<<13))      /*<Anti creep mode selection bit=1, P&Q joint judgment mode; >*/

#define   EMUCTRL_VrefLPEn        ((uint32_t)(1UL<<12))     /*<In low power mode, Lvref involve calculation control bit>*/
#define   EMUCTRL_P2EN            ((uint32_t)(1UL<<11))      /*<P2 replace Q1 metering channel enable select bit>*/
#define   EMUCTRL_ENERGY2_SRCSEL_OTHER ((uint32_t)(0UL<<11))		
#define   EMUCTRL_ENERGY2_SRCSEL_ALLP2 ((uint32_t)(1UL<<11))		

#define   EMUCTRL_EMUClkCtrl      ((uint32_t)(1UL<<10))      /*<EMU clock control bit>*/
#define   EMUCTRL_NORMAL_EMUCLK_SEL_819K	((uint32_t)(0UL<<10))		/*<819200Hz>*/
#define   EMUCTRL_NORMAL_EMUCLK_SEL_409K	((uint32_t)(1UL<<10))		/*<409600Hz>*/

#define   EMUCTRL_DCPRFCFG        ((uint32_t)(3UL<<8))      /*<DC average update frequency control bits>*/
#define   EMUCTRL_DCPRFCFG_25Hz   ((uint32_t)(0UL<<8))      /*<DC average update frequency is 25Hz>*/
#define   EMUCTRL_DCPRFCFG_12Hz5  ((uint32_t)(1UL<<8))      /*<DC average update frequency is 12.5Hz>*/
#define   EMUCTRL_DCPRFCFG_6Hz25  ((uint32_t)(2UL<<8))      /*<DC average update frequency is 6.25Hz>*/
#define   EMUCTRL_DCPRFCFG_3Hz125 ((uint32_t)(3UL<<8))      /*<DC average update frequency is 3.125Hz>*/

#define   EMUCTRL_SlowPRMS        	((uint32_t)(1UL<<7))      /*<Slow Rms power update frequency control bit>*/
#define   EMUCTRL_SLOW_PRMS_UPD_2	((uint32_t)(0UL<<7))
#define   EMUCTRL_SLOW_PRMS_UPD_4	((uint32_t)(1UL<<7))

#define   EMUCTRL_AdcOn           ((uint32_t)(0x70UL))      /*<ADC enable bit>*/
#define   EMUCTRL_AdcI1on         ((uint32_t)(1UL<<6))      /*<I1_ADC enable bit>*/
#define   EMUCTRL_AdcI2on         ((uint32_t)(1UL<<5))      /*<I2_ADC enable bit>*/
#define   EMUCTRL_AdcUon          ((uint32_t)(1UL<<4))      /*<U_ADC enable bit>*/

#define   EMUCTRL_Zxd             ((uint32_t)(3UL<<2))      /*<Voltage current zero crossing interrupt method select control bits>*/
#define   EMUCTRL_Zxd_Pos         ((uint32_t)(0UL<<2))      /*<Voltage current zero crossing interrupt method select Positive zero crossing>*/
#define   EMUCTRL_Zxd_Neg         ((uint32_t)(1UL<<2))      /*<Voltage current zero crossing interrupt method select Negative zero crossing>*/
#define   EMUCTRL_Zxd_Bidir       ((uint32_t)(2UL<<2))      /*<Voltage current zero crossing interrupt method select Bidirectional zero crossing>*/

#define   EMUCTRL_PRFCFG          ((uint32_t)(3UL<<0))      /*<Fast Rms power update frequency control bits>*/
#define   EMUCTRL_PRFCFG_20Hz     ((uint32_t)(0UL<<0))      /*<Rms update frequency is 20Hz>*/
#define   EMUCTRL_PRFCFG_10Hz     ((uint32_t)(1UL<<0))      /*<Rms update frequency is 10Hz>*/
#define   EMUCTRL_PRFCFG_5Hz      ((uint32_t)(2UL<<0))      /*<Rms update frequency is 5Hz>*/
#define   EMUCTRL_PRFCFG_2Hz5     ((uint32_t)(3UL<<0))      /*<Rms update frequency is 2.5Hz>*/
/**************************  Bit definition for ROSICTRL register  ***********************************************************************/
#define   ROSICTRL_AutoTcEN       ((uint32_t)(1UL<<15))      /*<Temperature auto compensation control bit>*/

#define   ROSICTRL_Clkdelay       ((uint32_t)(7UL<<12))      /*<Clk delay between Analog digital>*/
#define   ROSICTRL_Clkdelay_100   ((uint32_t)(4UL<<12))      /*<Clk delay selection bits:100>*/

#define   ROSICTRL_AdciCtr        ((uint32_t)(3UL<<9))      /*<ADC operation current control bits>*/
#define   ROSICTRL_AdciCtr_10uA   ((uint32_t)(0UL<<9))      /*<ADC operation current is 10uA>*/
#define   ROSICTRL_AdciCtr_1uA5   ((uint32_t)(1UL<<9))      /*<ADC operation current is 1.5uA>*/
#define   ROSICTRL_AdciCtr_3uA    ((uint32_t)(2UL<<9))      /*<ADC operation current is 3uA>*/
#define   ROSICTRL_AdciCtr_5uA    ((uint32_t)(3UL<<9))      /*<ADC operation current is 5uA>*/

#define   ROSICTRL_DCEn           ((uint32_t)(1UL<<8))      /*<DC average function enable bit>*/
#define   ROSICTRL_DCSEn          ((uint32_t)(1UL<<7))      /*<apparent power energy enable control bit>*/

#define   ROSICTRL_XboFiter       		((uint32_t)(1UL<<6))      /*<= 0 , notch filter center frequency is 50Hz; = 1, notch filter center frequency is 60Hz>*/
#define   ROSICTRL_SYSFREQ_SEL_50HZ		((uint32_t)(0UL<<6))		
#define   ROSICTRL_SYSFREQ_SEL_60HZ		((uint32_t)(1UL<<6))

#define   ROSICTRL_LpIdleEn       		((uint32_t)(1UL<<5))      /*<Open Low power calculation in time division enable control bit>*/

#if defined HT503x
#define ROSICTRL_STANDBYTIME			((uint32_t)(7UL<<2))		
#define ROSICTRL_STANDBYTIME_4			((uint32_t)(0UL<<2))
#define ROSICTRL_STANDBYTIME_8			((uint32_t)(1UL<<2))
#define ROSICTRL_STANDBYTIME_16			((uint32_t)(2UL<<2))
#define ROSICTRL_STANDBYTIME_32			((uint32_t)(3UL<<2))
#define ROSICTRL_STANDBYTIME_64			((uint32_t)(4UL<<2))
#define ROSICTRL_STANDBYTIME_128		((uint32_t)(5UL<<2))
#define ROSICTRL_STANDBYTIME_256		((uint32_t)(6UL<<2))
#define ROSICTRL_STANDBYTIME_512		((uint32_t)(7UL<<2))
#else
#define   ROSICTRL_LpStaCtrl      ((uint32_t)(1UL<<4))      /*<In Low power calculation mode, steady points num control bit: = 0 fixed 512 points;= 1 fixed 1024 points>*/

#define   ROSICTRL_LpCtrl         ((uint32_t)(3UL<<2))      /*<average time control bit in Low power calculation mode>*/
#define   ROSICTRL_LpCtrl_0s5     ((uint32_t)(0UL<<2))      /*<average time is 0.5s>*/
#define   ROSICTRL_LpCtrl_1s      ((uint32_t)(1UL<<2))      /*<average time is 1s>*/
#define   ROSICTRL_LpCtrl_2s      ((uint32_t)(2UL<<2))      /*<average time is 2s>*/
#define   ROSICTRL_LpCtrl_4s      ((uint32_t)(3UL<<2))      /*<average time is 4s>*/
#endif
#define   ROSICTRL_RosiI2En       ((uint32_t)(1UL<<1))      /*<Rogowski coil of current channel2 enable bit>*/
#define   ROSICTRL_RosiI1En       ((uint32_t)(1UL<<0))      /*<Rogowski coil of current channel1 enable bit>*/

/**************************  Bit definition for ANACTRL register  ***********************************************************************/
#define   ANACTRL_ldoEmuEn        ((uint32_t)(1UL<<15))      /*<EMU Analog supply LDO enable control bit>*/

#define   ANACTRL_VrefCtrl        ((uint32_t)(7UL<<11))      /*<Vref TC peak adjust code>*/
#define   ANACTRL_VrefCtrl_100    ((uint32_t)(4UL<<11))      /*<Vref TC peak adjust code selection bits:100>*/

#define   ANACTRL_ChopVrefEn      ((uint32_t)(1UL<<10))      /*<Vref chop control bit>*/
#define   ANACTRL_REVbit9Set      ((uint32_t)(1UL<<9))      /*<Reserve bit9, default:1>*/

#define   ANACTRL_AdcChopEn       ((uint32_t)(1UL<<8))      /*<Adc chop control bit>*/
#define   ANACTRL_UchopEn         ((uint32_t)(1UL<<7))      /*<Voltage channel chop control bit>*/

#define   ANACTRL_REVbit62        	((uint32_t)(0x1f<<2))      /*<Reserve bit6~2>*/
#define   ANACTRL_REVbit62_Default  ((uint32_t)(9UL<<2))      /*<Reserve bit6~2 selection default bits: 01001>*/

#define   ANACTRL_VrefChopBufEn   ((uint32_t)(1UL<<1))      /*<Vref chop buf enable control bit>*/
#define   ANACTRL_lowVrefIsel     ((uint32_t)(1UL<<0))      /*<Lvref offset current control bit,= 0,Offset current is 10ua;= 1,Offset current is 5ua>*/

/**************************  Bit definition for FilterCtrl register  ***********************************************************************/
#define   FilterCtrl_RosiPgaCtr   ((uint32_t)(3UL<<11))      /*<Gain of two current channel Rogowski coil control bits>*/
#define   FilterCtrl_RosiPgaCtr_1 ((uint32_t)(0UL<<11))      /*<Gain of two current channel Rogowski coil is 1>*/
#define   FilterCtrl_RosiPgaCtr_2 ((uint32_t)(1UL<<11))      /*<Gain of two current channel Rogowski coil is 2>*/
#define   FilterCtrl_RosiPgaCtr_4 ((uint32_t)(2UL<<11))      /*<Gain of two current channel Rogowski coil is 4>*/
#define   FilterCtrl_RosiPgaCtr_8 ((uint32_t)(3UL<<11))      /*<Gain of two current channel Rogowski coil is 8>*/

#define   FilterCtrl_ZXsourceSel  		((uint32_t)(1UL<<10))      /*<Current voltage zero crossing source selection>*/
#define   FILTERCTRL_ZX_SRCSEL_HPF		((uint32_t)(0UL<<10))		
#define   FILTERCTRL_ZX_SRCSEL_ROSI		((uint32_t)(1UL<<10))		


#define   FilterCtrl_PahseShiftCtr        ((uint32_t)(3UL<<8))      /*<90de phase shift filter coefficient control bits>*/
#define   FilterCtrl_PahseShiftCtr_11     ((uint32_t)(0UL<<8))      /*<90de phase shift filter coefficient is 11>*/
#define   FilterCtrl_PahseShiftCtr_12     ((uint32_t)(1UL<<8))      /*<90de phase shift filter coefficient is 12>*/
#define   FilterCtrl_PahseShiftCtr_13     ((uint32_t)(2UL<<8))      /*<90de phase shift filter coefficient is 13>*/
#define   FilterCtrl_PahseShiftCtr_14     ((uint32_t)(3UL<<8))      /*<90de phase shift filter coefficient is 14>*/

#define   FilterCtrl_RosiCtr      ((uint32_t)(3UL<<6))      /*<Gain of two current channel Rogowski coil filter coefficient control bits>*/
#define   FilterCtrl_RosiCtr_11   ((uint32_t)(0UL<<6))      /*<Gain of two current channel Rogowski coil filter coefficient is 11>*/
#define   FilterCtrl_RosiCtr_12   ((uint32_t)(1UL<<6))      /*<Gain of two current channel Rogowski coil filter coefficient is 12>*/
#define   FilterCtrl_RosiCtr_13   ((uint32_t)(2UL<<6))      /*<Gain of two current channel Rogowski coil filter coefficient is 13>*/
#define   FilterCtrl_RosiCtr_14   ((uint32_t)(3UL<<6))      /*<Gain of two current channel Rogowski coil filter coefficient is 14>*/

#define   FilterCtrl_HCtl         ((uint32_t)(7UL<<3))      /*<Internal coefficient1 selection control bits>*/
#define   FilterCtrl_LCtl         ((uint32_t)(7UL<<0))      /*<Internal coefficient2 selection control bits>*/


#if defined HT503x
/**************************  Bit definition for SyncStart register  ***********************************************************************/
#define SYNCSTART_U_EN					((uint32_t)(1UL<<0))		
#define SYNCSTART_I_EN					((uint32_t)(1UL<<1))		

#define SYNCSTART_I_SEL					((uint32_t)(1UL<<2))		
#define SYNCSTART_I_SEL_I1				((uint32_t)(0UL<<2))
#define SYNCSTART_I_SEL_I2				((uint32_t)(1UL<<2))

#define SYNCSTART_GAIN_U				((uint32_t)(0xfUL<<3))		
#define SYNCSTART_GAIN_U_1				((uint32_t)(0UL<<3))
#define SYNCSTART_GAIN_U_2				((uint32_t)(1UL<<3))
#define SYNCSTART_GAIN_U_4				((uint32_t)(2UL<<3))
#define SYNCSTART_GAIN_U_8				((uint32_t)(3UL<<3))
#define SYNCSTART_GAIN_U_16				((uint32_t)(4UL<<3))
#define SYNCSTART_GAIN_U_32				((uint32_t)(5UL<<3))
#define SYNCSTART_GAIN_U_64				((uint32_t)(6UL<<3))
#define SYNCSTART_GAIN_U_128			((uint32_t)(7UL<<3))
#define SYNCSTART_GAIN_U_256			((uint32_t)(8UL<<3))
#define SYNCSTART_GAIN_U_512			((uint32_t)(9UL<<3))
#define SYNCSTART_GAIN_U_1024			((uint32_t)(10UL<<3))
#define SYNCSTART_GAIN_U_2048			((uint32_t)(11UL<<3))

#define SYNCSTART_GAIN_I				((uint32_t)(0xfUL<<7))		
#define SYNCSTART_GAIN_I_1				((uint32_t)(0UL<<7))
#define SYNCSTART_GAIN_I_2				((uint32_t)(1UL<<7))
#define SYNCSTART_GAIN_I_4				((uint32_t)(2UL<<7))
#define SYNCSTART_GAIN_I_8				((uint32_t)(3UL<<7))
#define SYNCSTART_GAIN_I_16				((uint32_t)(4UL<<7))
#define SYNCSTART_GAIN_I_32				((uint32_t)(5UL<<7))
#define SYNCSTART_GAIN_I_64				((uint32_t)(6UL<<7))
#define SYNCSTART_GAIN_I_128			((uint32_t)(7UL<<7))
#define SYNCSTART_GAIN_I_256			((uint32_t)(8UL<<7))
#define SYNCSTART_GAIN_I_512			((uint32_t)(9UL<<7))
#define SYNCSTART_GAIN_I_1024			((uint32_t)(10UL<<7))
#define SYNCSTART_GAIN_I_2048			((uint32_t)(11UL<<7))
/**************************  Bit definition for EMUCON2 register  ***********************************************************************/
#define EMUCON2_POWEROV_CF1SEL				((uint32_t)(1UL<<0))		
#define EMUCON2_POWEROV_CF2SEL				((uint32_t)(1UL<<1))		
#define EMUCON2_POWEROV_CF3SEL				((uint32_t)(1UL<<2))		

#define EMUCON2_ENERGY2_SRCSEL				((uint32_t)(1UL<<3))		
#define EMUCON2_ENERGY2_SRCSEL_Q			((uint32_t)(0UL<<3))		
#define EMUCON2_ENERGY2_SRCSEL_FundP		((uint32_t)(1UL<<3))		

#define EMUCON2_ENERGY_ACCUALG				((uint32_t)(1UL<<4))		
#define EMUCON2_ENERGY_ACCUALG_OLD			((uint32_t)(0UL<<4))		
#define EMUCON2_ENERGY_ACCUALG_NEW			((uint32_t)(1UL<<4))		


#define EMUCON2_ENERGY_INSSRC				((uint32_t)(1UL<<5))		
#define EMUCON2_ENERGY_INSSRC_AVG			((uint32_t)(0UL<<5))
#define EMUCON2_ENERGY_INSSRC_INS			((uint32_t)(1UL<<5))

#define EMUCON2_ENERGY_RKEN					((uint32_t)(1UL<<6))		
/**************************  Bit definition for DECShift register  ***********************************************************************/
#define DECSHIFT_U						((uint32_t)(0x7fUL<<0))			
#define DECSHIFT_I1						((uint32_t)(0x7fUL<<8))			
#define DECSHIFT_I2						((uint32_t)(0x7fUL<<16))		
/**************************  Bit definition for FlickerCFG register  ***********************************************************************/
#define FLICKERCFG_EN					((uint32_t)(1UL<<0))		/*flicker enable*/
#define FLICKERCFG_UPDRATE				((uint32_t)(0x1fUL<<1))		

#define FLICKERCFG_HPF_LSHIFT			((uint32_t)(7UL<<6))		
#define FLICKERCFG_BPF_LSHIFT			((uint32_t)(7UL<<9))		
#define FLICKERCFG_SET_OFFSET			((uint32_t)(1UL<<12))		
/**************************  Bit definition for FundCFG register  ***********************************************************************/
#define FUNDCFG_EN						((uint32_t)(1UL<<0))		
#define FUNDCFG_FLICKER_LPFSHIFT		((uint32_t)(7UL<<1))		
/**************************  Bit definition for ZCNumCFG register  ***********************************************************************/
#define ZCNUMCFG_MAX					((uint32_t)(0x1ffUL<<0))		
#define ZCNUMCFG_ZC_DELAY				((uint32_t)(0x1ffUL<<9))	

#endif

#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/**
* @brief  EMU Error Code
*/
#define EMU_ERROR_NONE              (0x00000000UL)   /*!< No error            */
#define EMU_ERROR_INVALID_CALLBACK  (0x00000020UL)   /*!< Invalid Callback error  */

#endif /* USE_EMU_REGISTER_CALLBACKS */


/*
*********************************************************************************************************
*                                            Structure Type define
*********************************************************************************************************
*/
typedef enum{PF0=0x01, PF1=0x02, PF2=0x04} PFPort;
#if defined HT501x ||defined HT502x
typedef enum{PFout=0, QFout=2, SFout=3}PFType;
typedef enum{P80ms, P40ms, P20ms,P10ms}PFWide;

typedef struct
{
  uint16_t  UdetEn;       /*!< =ENABLE or DISABLE         */
  uint16_t  IpeakEn;      /*!< =ENABLE or DISABLE         */
  uint16_t  USagLvl;  
  uint16_t  UPeakLvl;
  uint16_t  OVCyc;      /*!< range: 0~65535             */
  uint16_t  IPeakLvl;
  uint16_t  IDetCyc;      /*!< range: 0~65535             */
}SagPeak_InitTypeDef;
#endif

#if defined HT503x

typedef enum
{
    AllGP1 	= ECR_ALL_GP1,     
    AllGQ1  = ECR_ALL_GQ1,     
    GS1 	= ECR_GS1,    
    AllGP2  = ECR_ALL_GP2,    
    AllGQ2  = ECR_ALL_GQ2,   
    GS2 	= ECR_GS2, 
    FundGP1 = ECR_Fund_GP1,    
    FundGP2 = ECR_Fund_GP2,    
}PowerGP_AddrTypeDef;               
typedef enum
{
    AllGphs1    = ECR_ALL_GPhs1,     
    AllGphs2    = ECR_ALL_GPhs2,     
    AllQPhsCal  = ECR_ALL_QPhsCal,        
}PowerGphs_AddrTypeDef; 


typedef enum
{
	UOff 	= ECR_UOff,     
    I1Off   = ECR_I1Off,     
    I2Off 	= ECR_I2Off,    
}ADCOffset_AddrTypeDef;  

typedef enum
{
    CF1Cnt   = ECR_CF1Cnt,     
    CF2Cnt   = ECR_CF2Cnt,     
    CF3Cnt   = ECR_CF3Cnt,     
    CF1CntN  = ECR_CF1CntN,     
    CF2CntN  = ECR_CF2CntN,    
    CF3CntN  = ECR_CF3CntN,    
}CFxCnt_AddrTypeDef; 

typedef enum
{
    AllP1Off  = ECR_ALL_P1Offset,     
    AllQ1Off  = ECR_ALL_Q1Offset,     
    AllP2Off  = ECR_ALL_P2Offset,     
    AllQ2Off  = ECR_ALL_Q2Offset,     
    FundP1Off = ECR_Fund_P1Offset,    
    FundP2Off = ECR_Fund_P2Offset,    
}PowerOffset_AddrTypeDef;               

typedef enum
{
    AllRmsUoff   = ECR_ALL_URMSOffset,     
    AllRmsI1off  = ECR_ALL_I1RMSOffset,     
    AllRmsI2off  = ECR_ALL_I2RMSOffset,     
    FundRmsUoff  = ECR_Fund_URMSOffset,     
    FundRmsI1off = ECR_Fund_I1RMSOffset,    
    FundRmsI2off = ECR_Fund_I2RMSOffset,    
}RmsOffset_AddrTypeDef;        
typedef enum
{
	DMA_SPL    = ADCCFG_DMA_SRCSEL_SPL,     
    DMA_SYNC   = ADCCFG_DMA_SRCSEL_SYNC,     
}DMA_SrcSelTypeDef;  

typedef enum
{
	Wave_dec  = ADCCFG_WaveSel_Origi,     
    Wave_hpf  = ADCCFG_WaveSel_HPF,     
}Wave_SrcSelTypeDef;  
typedef enum
{
	WaveUpd_8  = ADCCFG_SPL_1K6,     
    WaveUpd_4  = ADCCFG_SPL_3K2,
    WaveUpd_2  = ADCCFG_SPL_6K4,     
    WaveUpd_1  = ADCCFG_SPL_12K8,     
}Wave_UpdTypeDef;  
typedef enum
{
	CiaddAbs    = ADCCFG_ADD_CIADD_ABS,     
    CiaddAdd    = ADCCFG_ADD_CIADD_ADD,     
}CIADD_AddModeTypeDef; 


typedef enum
{
	HpfChanel_U   = CHNLCR_HPFEN_U,     
    HpfChanel_I1  = CHNLCR_HPFEN_I1,
    HpfChanel_I2  = CHNLCR_HPFEN_I2,     
}Hpf_ChanelTypeDef; 

typedef enum
{
    PStartFast  = ADCCFG_PQSStartSourceSel_FastPower,     
    PStartSlow  = ADCCFG_PQSStartSourceSel_SlowPower,     
    PStartInst  = ADCCFG_PQSStartSourceSel_InstantPower,        
}PowerStart_SrcSelTypeDef;    

typedef enum
{
    SStartSelSStart = ADCCFG_SSTART_CFG_SSTART,     
    SStartSelPOrQ   = ADCCFG_SSTART_CFG_PORQ,     
}SStart_CfgTypeDef;    

typedef enum
{
    MeterCh1  = ADCCFG_CHNSEL_1,     
    MeterCh2  = ADCCFG_CHNSEL_2,     
}Chanel_SelTypeDef;  

typedef enum
{
    IpTampRms    = ADCCFG_IPTAMP_SEL_RMS,     
    IpTampPower  = ADCCFG_IPTAMP_SEL_POWER,     
}IpTamp_SrcSelTypeDef;  
typedef enum
{
    TampRms    = ADCCFG_TAMP_SEL_RMS,     
    TampPower  = ADCCFG_TAMP_SEL_POWER,     
}Tamp_SrcSelTypeDef;  

typedef enum
{
    ChnFix_ch1       = ADCCFG_CHNFIX_CH1,     
    ChnFix_beforeCh  = ADCCFG_CHNFIX_BEFORECH,     
}CHNFix_SelTypeDef;  

typedef enum
{
    IpTampSlow  = ADCCFG_IPTAMP_SRCSEL_SLOW,     
    IpTampFast  = ADCCFG_IPTAMP_SRCSEL_FAST,     
}IpTamp_SrcSpeedSelTypeDef;  

typedef enum
{
   TampSlow  = ADCCFG_TAMP_SRCSEL_SLOW,   
   TampFast  = ADCCFG_TAMP_SRCSEL_FAST,     
}Tamp_SrcSpeedSelTypeDef;

typedef enum
{
   PeakSagHalfVP  	= CHNLCR_PEAKSAG_SRCSEL_HVP,   
   PeakSagHalfRms   = CHNLCR_PEAKSAG_SRCSEL_HRMS,     
}PeakSag_SrcSelTypeDef; 
typedef enum
{
   IHvpZCSel_I   = CHNLCR_IHAIFVP_ZCSEL_I,   
   IHvpZCSel_U   = CHNLCR_IHAIFVP_ZCSEL_U,     
}IHvpZCSel_TypeDef; 

typedef enum
{
   ZXSrcSel_AfterHPF    = FILTERCTRL_ZX_SRCSEL_HPF,   
   ZXSrcSel_AfterRosi   = FILTERCTRL_ZX_SRCSEL_ROSI,         
}ZXSrcSel_TypeDef;
typedef enum
{
   HCycRms_Half  = ADCCFG_HCYCLERMS_SEL_HALF,   
   HCycRms_One   = ADCCFG_HCYCLERMS_SEL_ONE,     
}HCycRms_UpdSelTypeDef; 

typedef enum
{
   SyncISel_I1  = SYNCSTART_I_SEL_I1,   
   SyncISel_I2  = SYNCSTART_I_SEL_I2,     
}SyncISel_TypeDef; 

typedef enum
{
   FundUpd_1     = EMUCTRL_FUND_UPD_1,   
   FundUpd_2     = EMUCTRL_FUND_UPD_2,     
   FundUpd_4     = EMUCTRL_FUND_UPD_4,   
   FundUpd_8     = EMUCTRL_FUND_UPD_8,     
   FundUpd_16    = EMUCTRL_FUND_UPD_16,   
   FundUpd_32    = EMUCTRL_FUND_UPD_32,     
}FundUpd_TypeDef; 

typedef enum
{
   RmsItAddMode_add   = ADCCFG_RMSIT_ADDMODE_ADD,   
   RmsItAddMode_sub   = ADCCFG_RMSIT_ADDMODE_SUB,     
}RmsIt_AddModeTypeDef;


typedef enum
{
   LpProcSelNormal   = CHNLCR_LPPROC_SEL_NORMAL,   
   LpProcSelOneCyc   = CHNLCR_LPPROC_SEL_ONECYC,     
}LpProc_SelTypeDef; 
typedef enum
{
   LpEmuclk_32k   = CHNLCR_LP_EMUCLK_SEL_32K,  
   LpEmuclk_204k   = CHNLCR_LP_EMUCLK_SEL_204K,     
}LpEmuclk_SelTypeDef; 
typedef enum
{
   LpCF1P_CF3S   = CHNLCR_PSCF_SEL_CF1PCF3S,
   LpCF1S_CF3P   = CHNLCR_PSCF_SEL_CF1SCF3P,     
}LpCF1OR3_SelTypeDef; 

typedef enum
{
   CFPos_High  = CHNLCR_POS_HIGH,  
   CFPos_Low   = CHNLCR_POS_LOW,     
}CFPos_SelTypeDef; 

typedef enum
{
   EnergyConstClk_32K  = CHNLCR_ENERGY_CLKSEL_32K,  
   EnergyConstClk_BS   = CHNLCR_ENERGY_CLKSEL_BS,     
}EnergyConstClk_SelTypeDef; 


typedef enum
{
   LpStandByTime_4     = ROSICTRL_STANDBYTIME_4,   
   LpStandByTime_8     = ROSICTRL_STANDBYTIME_8,  
   LpStandByTime_16    = ROSICTRL_STANDBYTIME_16,   
   LpStandByTime_32    = ROSICTRL_STANDBYTIME_32,     
   LpStandByTime_64    = ROSICTRL_STANDBYTIME_64,   
   LpStandByTime_128   = ROSICTRL_STANDBYTIME_128,     
   LpStandByTime_256   = ROSICTRL_STANDBYTIME_256,   
   LpStandByTime_512   = ROSICTRL_STANDBYTIME_512,     
}LpStandByTime_SelTypeDef; 

typedef enum
{
	PowerConstS  = CHNLCR_SDatacpEn,     
    PowerConstQ  = CHNLCR_QDatacpEn,
    PowerConstP  = CHNLCR_PDatacpEn,     
}PowerConst_ChanelTypeDef; 

typedef enum
{
   CF1AccuModeAdd  = EMCON_PMOD_Algebraic,   
   CF1AccuModePos  = EMCON_PMOD_Positive,     
   CF1AccuModeAbs  = EMCON_PMOD_Absolute,     
   CF1AccuModePN   = EMUCON_ACCUNODE_CF1_PN,     
}CF1_AccuMode_TypeDef; 

typedef enum
{
   CF2AccuModeAdd  = EMCON_QMOD_Algebraic,   
   CF2AccuModePos  = EMCON_QMOD_Positive,     
   CF2AccuModeAbs  = EMCON_QMOD_Absolute,     
   CF2AccuModePN   = EMUCON_ACCUNODE_CF2_PN,     
}CF2_AccuMode_TypeDef; 

typedef enum
{
   CF1Run  = EMCON_PRun,   
   CF2Run  = EMCON_QRun,    
   CF3Run  = EMCON_SRun,     
}EnergyRun_ChanelTypeDef; 

typedef enum
{
   OSR128  = EMCON_OSR128,   
   OSR64   = EMUCON_OSR64,    
}EmuOsr_SelTypeDef; 

typedef enum
{
   AvgPowerSelFast  = EMUCON_POWERAVG_SRCSEL_FAST,   
   AvgPowerSelSlow  = EMUCON_POWERAVG_SRCSEL_SLOW,    
}AvgPower_SrcSelTypeDef; 

typedef enum
{
   CF1OutSelCF1PN  = EMUCON_CF1CFG_CF1PN,   
   CF1OutSelCF2PN  = EMUCON_CF1CFG_CF2PN,     
   CF1OutSelCF3PN  = EMUCON_CF1CFG_CF3PN,   
   CF1OutSelCF1P   = EMUCON_CF1CFG_CF1P,    
   CF1OutSelCF1N   = EMUCON_CF1CFG_CF1N,   
   CF1OutSelCF2P   = EMUCON_CF1CFG_CF2P,    
   CF1OutSelCF2N   = EMUCON_CF1CFG_CF2N,   
   CF1OutSelCF3P   = EMUCON_CF1CFG_CF3P,    
   CF1OutSelCF3N   = EMUCON_CF1CFG_CF3N,      
}CF1_OutSelTypeDef; 

typedef enum
{
   CF2OutSelCF1PN  = EMUCON_CF2CFG_CF1PN,   
   CF2OutSelCF2PN  = EMUCON_CF2CFG_CF2PN,     
   CF2OutSelCF3PN  = EMUCON_CF2CFG_CF3PN,   
}CF2_OutSelTypeDef; 
typedef enum
{
   CF3OutSelCF1PN  = EMUCON_CF3CFG_CF1PN,   
   CF3OutSelCF2PN  = EMUCON_CF3CFG_CF2PN,     
   CF3OutSelCF3PN  = EMUCON_CF3CFG_CF3PN,   
}CF3_OutSelTypeDef; 

typedef enum
{
   UPGA_1  = ADCCON_ANAU_1,   
   UPGA_2  = ADCCON_ANAU_2,     
   UPGA_4  = ADCCON_ANAU_4,   
}UPGA_SelTypeDef; 

typedef enum
{
   I1PGA_1   = ADCCON_ANAI1_1,   
   I1PGA_2   = ADCCON_ANAI1_2,     
   I1PGA_8   = ADCCON_ANAI1_8, 
   I1PGA_16  = ADCCON_ANAI1_16,
   I1PGA_24  = ADCCON_PGAI1_24,
}I1PGA_SelTypeDef; 
typedef enum
{
   I2PGA_1   = ADCCON_ANAI2_1,   
   I2PGA_2   = ADCCON_ANAI2_2,     
   I2PGA_8   = ADCCON_ANAI2_8, 
   I2PGA_16  = ADCCON_ANAI2_16,
}I2PGA_SelTypeDef; 

typedef enum
{
   CFP_80ms  = ADCCON_CFP_80MS,   
   CFP_40ms  = ADCCON_CFP_40MS,     
   CFP_20ms  = ADCCON_CFP_20MS, 
   CFP_10ms  = ADCCON_CFP_10MS,
}CFP_SelTypeDef; 

typedef enum
{
   UDG_1  = ADCCON_DGU_1,   
   UDG_2  = ADCCON_DGU_2,     
   UDG_4  = ADCCON_DGU_4, 
   UDG_8  = ADCCON_DGU_8,
}UDG_SelTypeDef;

typedef enum
{
   I1DG_1  = ADCCON_DGI1_1,   
   I1DG_2  = ADCCON_DGI1_2,     
   I1DG_4  = ADCCON_DGI1_4, 
   I1DG_8  = ADCCON_DGI1_8,
}I1DG_SelTypeDef; 

typedef enum
{
   I2DG_1  = ADCCON_DGI2_1,   
   I2DG_2  = ADCCON_DGI2_2,     
   I2DG_4  = ADCCON_DGI2_4, 
   I2DG_8  = ADCCON_DGI2_8,
}I2DG_SelTypeDef; 

typedef enum
{
   PowerShift_1   = ADCCON_POWER_SHIFT_1,   
   PowerShift_2   = ADCCON_POWER_SHIFT_2,     
   PowerShift_4   = ADCCON_POWER_SHIFT_4, 
   PowerShift_8   = ADCCON_POWER_SHIFT_8,
   PowerShift_16  = ADCCON_POWER_SHIFT_16,
}PowerShift_SelTypeDef;

typedef enum
{
   FastPRMS_UpdSel_1   = EMUCTRL_PRFCFG_20Hz,   
   FastPRMS_UpdSel_2   = EMUCTRL_PRFCFG_10Hz,     
   FastPRMS_UpdSel_4   = EMUCTRL_PRFCFG_5Hz, 
   FastPRMS_UpdSel_8   = EMUCTRL_PRFCFG_2Hz5,
}FastPRMS_UpdSelTypeDef;

typedef enum
{
   ZCdSel_P    = EMUCTRL_Zxd_Pos,   
   ZCdSel_N    = EMUCTRL_Zxd_Neg,     
   ZCdSel_PN   = EMUCTRL_Zxd_Bidir, 
}ZCd_SelTypeDef;



typedef enum
{
   SlowPRMS_UpdSel_2   = EMUCTRL_SLOW_PRMS_UPD_2,   
   SlowPRMS_UpdSel_4   = EMUCTRL_SLOW_PRMS_UPD_4,     
}SlowPRMS_UpdSelTypeDef;
typedef enum
{
   DC_UpdSel_1   = EMUCTRL_DCPRFCFG_25Hz,   
   DC_UpdSel_2   = EMUCTRL_DCPRFCFG_12Hz5,     
   DC_UpdSel_4   = EMUCTRL_DCPRFCFG_6Hz25, 
   DC_UpdSel_8   = EMUCTRL_DCPRFCFG_3Hz125,
}DC_UpdSelTypeDef;
typedef enum
{
   Normal_EmuClkSel_409K  = EMUCTRL_NORMAL_EMUCLK_SEL_409K,   
   Normal_EmuClkSel_819K  = EMUCTRL_NORMAL_EMUCLK_SEL_819K,     
   Normal_EmuClkSel_1638K = EMUCTRL_NORMAL_EMUCLK_SEL_1638K, 
}Normal_EmuClkSelTypeDef;
typedef enum
{
   Energy2SrcSel_PConst = CHNLCR_QDatacpEn, 
   Energy2SrcSel_AllP2  = EMUCTRL_ENERGY2_SRCSEL_ALLP2,     
   Energy2SrcSel_FundP  = EMUCON2_ENERGY2_SRCSEL_FundP, 
   Energy2SrcSel_Q      = EMUCON2_ENERGY2_SRCSEL_Q,   
}Energy2_SrcSelTypeDef;

typedef enum
{
   PQStartSel_PQ    = EMUCTRL_StartSel_PQResp, 
   PQStartSel_PORQ  = EMUCTRL_StartSel_PorQ,     
}PQStart_SelTypeDef;

typedef enum
{
   PowerSSrcSel_All   = EMUCTRL_POWERS_SRCSEL_ALL, 
   PowerSSrcSel_Fund  = EMUCTRL_POWERS_SRCSEL_FUND,     
}PowerS_SrcSelTypeDef;
typedef enum
{
   PowerQSrcSel_All   = EMUCTRL_POWERQ_SRCSEL_ALL, 
   PowerQSrcSel_Fund  = EMUCTRL_POWERQ_SRCSEL_FUND,     
}PowerQ_SrcSelTypeDef;

typedef enum
{
   RosiI1  = ROSICTRL_RosiI1En, 
   RosiI2  = ROSICTRL_RosiI2En,     
}Rosi_ChanelTypeDef;

typedef enum
{
   SysFreq50Hz  = ROSICTRL_SYSFREQ_SEL_50HZ, 
   SysFreq60Hz  = ROSICTRL_SYSFREQ_SEL_60HZ,     
}SysFreq_SelTypeDef;
typedef enum
{
   SyncU_En  = SYNCSTART_U_EN, 
   SyncI_En  = SYNCSTART_I_EN,     
}Sync_ChanelTypeDef;
typedef enum
{
   SyncGainU_1     = SYNCSTART_GAIN_U_1, 
   SyncGainU_2     = SYNCSTART_GAIN_U_2,  
   SyncGainU_4     = SYNCSTART_GAIN_U_4, 
   SyncGainU_8     = SYNCSTART_GAIN_U_8,     
   SyncGainU_16    = SYNCSTART_GAIN_U_16, 
   SyncGainU_32    = SYNCSTART_GAIN_U_32,     
   SyncGainU_64    = SYNCSTART_GAIN_U_64, 
   SyncGainU_128   = SYNCSTART_GAIN_U_128,     
   SyncGainU_256   = SYNCSTART_GAIN_U_256, 
   SyncGainU_512   = SYNCSTART_GAIN_U_512,     
   SyncGainU_1024  = SYNCSTART_GAIN_U_1024, 
   SyncGainU_2048  = SYNCSTART_GAIN_U_2048,     
}SyncUGain_TypeDef;

typedef enum
{
   SyncGainI_1    = SYNCSTART_GAIN_I_1, 
   SyncGainI_2    = SYNCSTART_GAIN_I_2,  
   SyncGainI_4    = SYNCSTART_GAIN_I_4, 
   SyncGainI_8    = SYNCSTART_GAIN_I_8,     
   SyncGainI_16   = SYNCSTART_GAIN_I_16, 
   SyncGainI_32   = SYNCSTART_GAIN_I_32,     
   SyncGainI_64   = SYNCSTART_GAIN_I_64, 
   SyncGainI_128  = SYNCSTART_GAIN_I_128,     
   SyncGainI_256  = SYNCSTART_GAIN_I_256, 
   SyncGainI_512  = SYNCSTART_GAIN_I_512,     
   SyncGainI_1024 = SYNCSTART_GAIN_I_1024, 
   SyncGainI_2048 = SYNCSTART_GAIN_I_2048,     
}SyncIGain_TypeDef;


typedef enum
{
   PowerOV_CF1    = EMUCON2_POWEROV_CF1SEL, 
   PowerOV_CF2    = EMUCON2_POWEROV_CF2SEL,  
   PowerOV_CF3    = EMUCON2_POWEROV_CF3SEL, 
}PowerOV_ChanelTypeDef;

typedef enum
{
   EnergyAccuAlgOld   = EMUCON2_ENERGY_ACCUALG_OLD, 
   EnergyAccuAlgNew   = EMUCON2_ENERGY_ACCUALG_NEW,  
}Energy_AccuAlgTypeDef;
typedef enum
{
   EnergyInAvg    = EMUCON2_ENERGY_INSSRC_AVG, 
   EnergyInIns   = EMUCON2_ENERGY_INSSRC_INS,  
}EnergyIn_SrcSelTypeDef;


typedef struct
{
  CIADD_AddModeTypeDef CIADD_AddMode;    	
  FunctionalState CIADD_En;					
}CIADD_TypeDef;


typedef struct
{
  uint8_t DecShiftU;    /* u chanel,0~127*/
  uint8_t DecShiftI1;	/*i1 chanel,0~127*/
  uint8_t DecShiftI2;   /*i2 chanel,0~127*/           
}DECShift_TypeDef;

typedef struct
{
  EnergyConstClk_SelTypeDef PowerConstClk;
  int32_t PConst; 
  int32_t QConst;	
  int32_t SConst;            
  FunctionalState  PConstEn;       /*!< =ENABLE or DISABLE*/
  FunctionalState  QConstEn;       /*!< =ENABLE or DISABLE*/
  FunctionalState  SConstEn;       /*!< =ENABLE or DISABLE*/
}PowerConst_InitTypeDef;

typedef struct
{
  PowerStart_SrcSelTypeDef StartSrcSel;     
  SStart_CfgTypeDef S_StartCFG;       
  PQStart_SelTypeDef PQ_StartCFG;      	

  uint16_t  PStart;  		
  uint16_t  QStart;			
  uint16_t  SStart;   		
}PowerStart_InitTypeDef;

typedef struct
{
  Chanel_SelTypeDef   			ChanelSel;   			
  IpTamp_SrcSpeedSelTypeDef     IpTampSrcSpeedSel;     
  Tamp_SrcSpeedSelTypeDef   	TampSrcSpeedSel;   		
  IpTamp_SrcSelTypeDef   		IpTampSrcSel;			
  Tamp_SrcSelTypeDef   			TampSrcSel;     		
  CHNFix_SelTypeDef   ChanelFix;      		
  uint16_t  IpTampLVL;  			
  uint8_t   ICHK;					
  FunctionalState   			FLTON;					
}Tamp_InitTypeDef;


typedef struct
{
  PeakSag_SrcSelTypeDef  PeakSagSrcSel;  
  uint16_t  USagLvl;       
  uint16_t  UPeakLvl;      
  uint16_t  USagLvlHys;    
  uint16_t  UPeakLvlHys;   
  uint16_t  IovLvl;        
  uint16_t  PeakSagHCyc;	
  uint16_t  IovHCyc; 		
  FunctionalState USagEn;	
  FunctionalState UPeakEn; 
  FunctionalState IovEn;   
}SagPeakIOV_InitTypeDef;


typedef struct
{
  int16_t  TGain_U;        
  int16_t  TGain_I1;       
  int16_t  TGain_I2;       
  int16_t  TCOFFA_U;       
  int16_t  TCOFFB_U;       
  int16_t  TCOFFC_U;		
  int16_t  TCOFFA_I1;    	
  int16_t  TCOFFB_I1;      
  int16_t  TCOFFC_I1;		
  int16_t  TCOFFA_I2;    	
  int16_t  TCOFFB_I2;      
  int16_t  TCOFFC_I2;		
  FunctionalState AutoTcEn;
}TempComp_InitTypeDef;


typedef struct
{
  IHvpZCSel_TypeDef IHvpZCSel;        
  ZCd_SelTypeDef ZC_IntSel;           
  ZXSrcSel_TypeDef  ZXSrcSel;         
  uint16_t  IZCLvl;       			  
  uint16_t  UZCLvl;		  			  
  uint16_t  ZCNumMax_U;       		   /*0~0x1ff*/
  uint16_t  ZC_Delay_U;		           /*0~0x1ff*/
}ZC_InitTypeDef;


typedef struct
{
  HCycRms_UpdSelTypeDef  HCycRms_UpdSel;         
  uint32_t  dPHfix;       						 /*0~0x7ffff*/
  FunctionalState HCycleRmsEn;					
  FunctionalState HCycleRmsI2En;				 
}HCycRms_InitTypeDef;


typedef struct
{
  SyncISel_TypeDef  SyncISel;         
  SyncUGain_TypeDef  SyncUGain;       
  SyncIGain_TypeDef  SyncIGain;       
  
  uint16_t  SyncCoff;       		  /*0~0x1ff*/
  FunctionalState SyncUEn;			  
  FunctionalState SyncIEn;			  
}Sync_InitTypeDef;


typedef struct
{
  FundUpd_TypeDef FundUpdCFG;	      
  PowerQ_SrcSelTypeDef PowerQSrcSel;   
  PowerS_SrcSelTypeDef PowerEnergySSrcSel; 
  uint32_t  FundCoff[16];       	  	  
  FunctionalState FundEn;			 
  FunctionalState FundEnergyPEn;	  
}Fund_InitTypeDef;
 

typedef struct
{
  RmsIt_AddModeTypeDef AddMode;			
  uint16_t  RmsItTHO;       			
  FunctionalState FundItEn; 			
  FunctionalState RmsItEn; 				
}RmsIt_InitTypeDef;

typedef struct
{
  int32_t  SqrOffset;       	  	/*bit31~29 is signed£¬bit28~0 is data bit*/
  uint32_t LpfCoff[16];       		
  uint32_t BpfCoff[16];       		
  
  uint8_t  HpfLshift;       		/*0~7,other is 0*/
  uint8_t  BpfLshift;       		/*0~7,other is 0*/
  uint8_t  UpdRate;       		    /*0~31 is 1~32div*/
  uint8_t  LpfLshift;       		/*0~7*/

  FunctionalState SetOffset_En;		
  FunctionalState Flicker_En;		
}Flicker_InitTypeDef;

typedef struct
{
  uint32_t  OneCycCoff[16];       		 
  uint16_t  OneCycNum;       		/*6~0x3ff*/
  FunctionalState OneCyc_En;		  
}CycRms_InitTypeDef;


typedef struct
{
  LpProc_SelTypeDef LpProc;    				
  LpEmuclk_SelTypeDef LpEmuclk;    			
  LpCF1OR3_SelTypeDef LpCF1OR3;    			
  LpStandByTime_SelTypeDef StandByTime; 
  uint32_t  OneCycCoff[16];       		 
  uint16_t  OneCycNum;       		/*6~0x3ff*/
  uint16_t  UConst;       			
  uint16_t  IdleTime;       		/*0~0x3ff is 1~0x400s£¬othert is 0*/
  uint16_t  LpIRmsTHO;       		
  FunctionalState LpIdle_En;		
  FunctionalState LpVref_En;		
  FunctionalState UConst_En;		
  FunctionalState LpMode_En;		
}LpMode_InitTypeDef;

#endif


/*
*********************************************************************************************************
*                                            self-defined global macro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            Global variable 
*********************************************************************************************************
*/

#if defined  HT501x 
#define IS_HT_EMU_EPReg_ADDR(ADDR) (((ADDR) <= EPR_AutoI2gain)&&(((ADDR)%4) == 0))
#elif defined  HT502x
#define IS_HT_EMU_EPReg_ADDR(ADDR) (((ADDR) <= EPR_UdetCNT)&&(((ADDR)%4) == 0))
#elif defined  HT503x
#define IS_HT_EMU_EPReg_ADDR(ADDR) (((ADDR) <= EPR_CheckSum2)&&(((ADDR)%4) == 0))
#endif
#if defined  HT501x
#define IS_HT_EMU_ECReg_ADDR(ADDR) (((ADDR) <= ECR_SRSTREG)&&(((ADDR)%4) == 0))
#elif defined  HT502x
#define IS_HT_EMU_ECReg_ADDR(ADDR) (((ADDR) <= ECR_QFCntN)&&(((ADDR)%4) == 0))
#elif defined  HT503x
#define IS_HT_EMU_ECReg_ADDR(ADDR) (((ADDR) <= ECR_CycRmsNum)&&(((ADDR)%4) == 0))
#endif

/**
* @brief  HT_EMUSR_Status
*/ 
#if defined  HT503x
#define IS_HT_EMUSR_STATUS(STATUS) (((STATUS) == EMUSR_REV_CF1) || \
																	((STATUS) == EMUSR_REV_CF2) || \
																	((STATUS) == EMUSR_NOLOAD_ALLP1) || \
																	((STATUS) == EMUSR_NOLOAD_ALLQ1) || \
																	((STATUS) == EMUSR_NOLOAD_ALLP2) || \
																	((STATUS) == EMUSR_NOLOAD_ALLQ2) || \
																	((STATUS) == EMUSR_I2GTI1) || \
																	((STATUS) == EMUSR_TAMP) || \
																	((STATUS) == EMUSR_CHANELSTATUS) || \
																	((STATUS) == EMUSR_OV_ENERGYPOS_CF1) || \
																	((STATUS) == EMUSR_OV_ENERGYPOS_CF2) || \
																	((STATUS) == EMUSR_OV_ENERGYPOS_CF3) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF1) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF2) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF3) || \
																	((STATUS) == EMUSR_NOLOAD_FUNDP1) || \
																	((STATUS) == EMUSR_NOLOAD_FUNDP2) || \
																	((STATUS) == EMUSR_REV_CF3) || \
																	((STATUS) == EMUSR_ZCVALID_U) || \
																	((STATUS) == EMUSR_ZCVALID_I1) || \
																	((STATUS) == EMUSR_ZCVALID_I2) || \
																	((STATUS) == EMUSR_PEAK_STATUS) || \
																	((STATUS) == EMUSR_SAG_STATUS) || \
																	((STATUS) == EMUSR_ADC_OV_U) || \
																	((STATUS) == EMUSR_ADC_OV_I1) || \
																	((STATUS) == EMUSR_ADC_OV_I2))
#else
#define IS_HT_EMUSR_STATUS(STATUS)                                  (((STATUS) == EMUSR_SFOF) || \
																	((STATUS) == EMUSR_PEOF) || \
																	((STATUS) == EMUSR_QEOF) || \
																	((STATUS) == EMUSR_CHSTS) || \
																	((STATUS) == EMUSR_G2GTI1) || \
																	((STATUS) == EMUSR_TAMP) || \
																	((STATUS) == EMUSR_NOQLD2) || \
																	((STATUS) == EMUSR_NOPLD2) || \
																	((STATUS) == EMUSR_NOQLD1) || \
																	((STATUS) == EMUSR_NOPLD1))
#endif

#if defined  HT503x
/**
* @brief  HT_EMUSR_Status_Clear
*/ 
#define IS_HT_EMUSR_STATUS_CLEAR(STATUS)                            (((STATUS) == EMUSR_OV_ENERGYPOS_CF1) || \
																	((STATUS) == EMUSR_OV_ENERGYPOS_CF2) || \
																	((STATUS) == EMUSR_OV_ENERGYPOS_CF3) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF1) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF2) || \
																	((STATUS) == EMUSR_OV_ENERGYNEG_CF3) || \
																	((STATUS) == EMUSR_ADC_OV_U) || \
																	((STATUS) == EMUSR_ADC_OV_I1) || \
																	((STATUS) == EMUSR_ADC_OV_I2)|| \
                                                                    ((((STATUS) & (uint32_t)(~EMUSR_CLEAR)) == 0x00) && ((STATUS) != 0x00)))
#endif
/**
* @brief  HT_EMUIT_CONFIG
*/ 
#if defined  HT503x
#define IS_HT_EMUIE_CONFIG(CONFIG) (((CONFIG) == EMUIE_SAG_START) || \
																	((CONFIG) == EMUIE_PEAK_START) || \
																	((CONFIG) == EMUIE_IOV_I1) || \
																	((CONFIG) == EMUIE_ZC_U) || \
																	((CONFIG) == EMUIE_SPL_UPD) || \
																	((CONFIG) == EMUIE_CF3) || \
																	((CONFIG) == EMUIE_CF2) || \
																	((CONFIG) == EMUIE_CF1) || \
																	((CONFIG) == EMUIE_IOV_I2) || \
																	((CONFIG) == EMUIE_ZC_I1) || \
																	((CONFIG) == EMUIE_ZC_I2) || \
																	((CONFIG) == EMUIE_FASTRMS_UPD) || \
																	((CONFIG) == EMUIE_SLOWRMS_UPD) || \
																	((CONFIG) == EMUIE_DCAVG_UPD) || \
																	((CONFIG) == EMUIE_TAMP) || \
																	((CONFIG) == EMUIE_PEAK_END) || \
																	((CONFIG) == EMUIE_SAG_END) || \
																	((CONFIG) == EMUIE_ZCLOST_U) || \
																	((CONFIG) == EMUIE_SYNC_UPD) || \
																	((CONFIG) == EMUIE_LPRMS_OV) || \
																	((CONFIG) == EMUIE_RMSIT_OV) || \
																	((CONFIG) == EMUIE_FUND_PRMS_UPD) || \
																	((CONFIG) == EMUIE_FLICKER_UPD) || \
																	((CONFIG) == EMUIE_HCYCVP_U_UPD) || \
																	((CONFIG) == EMUIE_HCYCRMS_UPD) || \
																	((CONFIG) == EMUIE_CYCRMS_UPD)|| \
                                                                    ((((CONFIG) & (uint32_t)(~EMUIE_ALL)) == 0x00) && ((CONFIG) != 0x00)))
#elif defined  HT501x
#define IS_HT_EMUIE_CONFIG(CONFIG) (((CONFIG) == EMUIE_SAG) || \
																	((CONFIG) == EMUIE_UOV) || \
																	((CONFIG) == EMUIE_I1OV) || \
																	((CONFIG) == EMUIE_ZXU) || \
																	((CONFIG) == EMUIE_SPL) || \
																	((CONFIG) == EMUIE_PF) || \
																	((CONFIG) == EMUIE_QF) || \
																	((CONFIG) == EMUIE_SF) || \
																	((CONFIG) == EMUIE_I2OV) || \
																	((CONFIG) == EMUIE_ZXI1) || \
																	((CONFIG) == EMUIE_ZXI2) || \
																	((CONFIG) == EMUIE_FRMS) || \
																	((CONFIG) == EMUIE_SRMS) || \
																	((CONFIG) == EMUIE_DCUPDATE) || \
																	((CONFIG) == EMUIE_TAMP)|| \
                                                                    ((((CONFIG) & (uint32_t)(~EMUIE_ALL)) == 0x00) && ((CONFIG) != 0x00)))

#elif defined  HT502x

#define IS_HT_EMUIE_CONFIG(CONFIG) (((CONFIG) == EMUIE_SAG) || \
																	((CONFIG) == EMUIE_UOV) || \
																	((CONFIG) == EMUIE_I1OV) || \
																	((CONFIG) == EMUIE_ZXU) || \
																	((CONFIG) == EMUIE_SPL) || \
																	((CONFIG) == EMUIE_PF) || \
																	((CONFIG) == EMUIE_QF) || \
																	((CONFIG) == EMUIE_SF) || \
																	((CONFIG) == EMUIE_I2OV) || \
																	((CONFIG) == EMUIE_ZXI1) || \
																	((CONFIG) == EMUIE_ZXI2) || \
																	((CONFIG) == EMUIE_FRMS) || \
																	((CONFIG) == EMUIE_SRMS) || \
																	((CONFIG) == EMUIE_DCUPDATE) || \
																	((CONFIG) == EMUIE_TAMP) || \
																	((CONFIG) == EMUIE_UDET) || \
																	((CONFIG) == EMUIE_BUFFULL) || \
																	((CONFIG) == EMUIE_ZXLOST)|| \
                                                                    ((((CONFIG) & (uint32_t)(~EMUIE_ALL)) == 0x00) && ((CONFIG) != 0x00)))



#endif

#if defined  HT503x
#define IS_HT_EMUIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_SAG_START) || \
																	((CONFIG) == EMUIF_PEAK_START) || \
																	((CONFIG) == EMUIF_IOV_I1) || \
																	((CONFIG) == EMUIF_ZC_U) || \
																	((CONFIG) == EMUIF_SPL_UPD) || \
																	((CONFIG) == EMUIF_CF3) || \
																	((CONFIG) == EMUIF_CF2) || \
																	((CONFIG) == EMUIF_CF1) || \
																	((CONFIG) == EMUIF_IOV_I2) || \
																	((CONFIG) == EMUIF_ZC_I1) || \
																	((CONFIG) == EMUIF_ZC_I2) || \
																	((CONFIG) == EMUIF_FASTRMS_UPD) || \
																	((CONFIG) == EMUIF_SLOWRMS_UPD) || \
																	((CONFIG) == EMUIF_DCAVG_UPD) || \
																	((CONFIG) == EMUIF_TAMP) || \
																	((CONFIG) == EMUIF_PEAK_END) || \
																	((CONFIG) == EMUIF_SAG_END) || \
																	((CONFIG) == EMUIF_ZCLOST_U) || \
																	((CONFIG) == EMUIF_SYNC_UPD) || \
																	((CONFIG) == EMUIF_LPRMS_OV) || \
																	((CONFIG) == EMUIF_RMSIT_OV) || \
																	((CONFIG) == EMUIF_FUND_PRMS_UPD) || \
																	((CONFIG) == EMUIF_FLICKER_UPD) || \
																	((CONFIG) == EMUIF_HCYCVP_U_UPD) || \
																	((CONFIG) == EMUIF_HCYCRMS_UPD) || \
																	((CONFIG) == EMUIF_CYCRMS_UPD))
#elif defined  HT501x
#define IS_HT_EMUIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_SAG) || \
																	((CONFIG) == EMUIF_UOV) || \
																	((CONFIG) == EMUIF_I1OV) || \
   																	((CONFIG) == EMUIF_ZXU) || \
   																	((CONFIG) == EMUIF_SPL) || \
   																	((CONFIG) == EMUIF_PF) || \
   																	((CONFIG) == EMUIF_QF) || \
   																	((CONFIG) == EMUIF_SF) || \
   																	((CONFIG) == EMUIF_I2OV) || \
   																	((CONFIG) == EMUIF_ZXI1) || \
   																	((CONFIG) == EMUIF_ZXI2) || \
   																	((CONFIG) == EMUIF_FRMS) || \
   																	((CONFIG) == EMUIF_SRMS) || \
   																	((CONFIG) == EMUIF_DCUPDATE) || \
   																	((CONFIG) == EMUIF_TAMP))
#elif defined  HT502x

#define IS_HT_EMUIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_SAG) || \
																	((CONFIG) == EMUIF_UOV) || \
																	((CONFIG) == EMUIF_I1OV) || \
																	((CONFIG) == EMUIF_ZXU) || \
																	((CONFIG) == EMUIF_SPL) || \
																	((CONFIG) == EMUIF_PF) || \
																	((CONFIG) == EMUIF_QF) || \
																	((CONFIG) == EMUIF_SF) || \
																	((CONFIG) == EMUIF_I2OV) || \
																	((CONFIG) == EMUIF_ZXI1) || \
																	((CONFIG) == EMUIF_ZXI2) || \
																	((CONFIG) == EMUIF_FRMS) || \
																	((CONFIG) == EMUIF_SRMS) || \
																	((CONFIG) == EMUIF_DCUPDATE) || \
																	((CONFIG) == EMUIF_TAMP) || \
																	((CONFIG) == EMUIF_USTART) || \
																	((CONFIG) == EMUIF_UEND) || \
																	((CONFIG) == EMUIF_BUFFULL) || \
																	((CONFIG) == EMUIF_ZXLOST))

#endif


#if defined  HT503x
/**
* @brief  HT_EMU_POWERGAIN_ADDR
*/ 
#define IS_HT_EMU_POWERGAIN_ADDR(ADDR)                              (((ADDR) == AllGP1) || \
																	((ADDR) == AllGQ1) || \
																	((ADDR) == GS1) || \
																	((ADDR) == AllGP2) || \
																	((ADDR) == AllGQ2) || \
																	((ADDR) == GS2) || \
																	((ADDR) == FundGP1) || \
																	((ADDR) == FundGP2))
/**
* @brief  HT_EMU_POWERPHASE_ADDR
*/ 
#define IS_HT_EMU_POWERPHASE_ADDR(ADDR)                             (((ADDR) == AllGphs1)||((ADDR) == AllGphs2)||((ADDR) == AllQPhsCal))


/**
* @brief  HT_EMU_DECShift
*/
#define IS_HT_EMU_DECShift(DECShift)                                ((DECShift) <= ECR_7BIT_DATA)

/**
* @brief  HT_EMU_ADCOFFSET_ADDR
*/ 
#define IS_HT_EMU_ADCOFFSET_ADDR(ADDR)                              (((ADDR) == UOff)||((ADDR) == I1Off)||((ADDR) == I2Off))

/**
* @brief  HT_EMU_HFCONST
*/
#define IS_HT_EMU_HFCONST(HFConst)                                  (((HFConst) >= ECR_EMU_HFConst_LLimit) && ((HFConst) <= ECR_21BIT_DATA))

/**
* @brief  HT_EMU_LPIDLETIME
*/
#define IS_HT_EMU_LPIDLETIME(TIME) ((TIME) <= ECR_10BIT_DATA)


#define IS_HT_EMU_AFDIV(DATA) ((DATA) <= ECR_15BIT_DATA)
/**
* @brief  HT_EMU_PRMS_AVGNUM
*/
#define IS_HT_EMU_PRMS_AVGNUM(AVGNUM) (((AVGNUM) >= ECR_EMU_AVGNUM_LLimit)&&((AVGNUM) <= ECR_EMU_AVGNUM_HLimit))

/**
* @brief  HT_EMU_CFXCNT_ADDR
*/ 
#define IS_HT_EMU_CFXCNT_ADDR(ADDR) (((ADDR) == CF1Cnt) || \
																	((ADDR) == CF2Cnt) || \
																	((ADDR) == CF3Cnt) || \
																	((ADDR) == CF1CntN) || \
																	((ADDR) == CF2CntN) || \
																	((ADDR) == CF3CntN))
/**
* @brief  HT_EMU_CFXCNT_NUM
*/
#define IS_HT_EMU_CFXCNT_NUM(NUM) ((NUM) <= ECR_22BIT_DATA)

/**
* @brief  HT_EMU_POWEROFFSET_ADDR
*/ 
#define IS_HT_EMU_POWEROFFSET_ADDR(ADDR) (((ADDR) == AllP1Off) || \
																	((ADDR) == AllQ1Off) || \
																	((ADDR) == AllP2Off) || \
																	((ADDR) == AllQ2Off) || \
																	((ADDR) == FundP1Off) || \
																	((ADDR) == FundP2Off))
/**
* @brief  HT_EMU_RMSOFFSET_ADDR
*/ 
#define IS_HT_EMU_RMSOFFSET_ADDR(ADDR) (((ADDR) == AllRmsUoff) || \
																	((ADDR) == AllRmsI1off) || \
																	((ADDR) == AllRmsI2off) || \
																	((ADDR) == FundRmsUoff) || \
																	((ADDR) == FundRmsI1off) || \
																	((ADDR) == FundRmsI2off))

#define IS_HT_EMU_ONECYC_RMSNUM(NUM) (((NUM) >= ECR_EMU_OneCycNUM_LLimit)&&((NUM) <= ECR_10BIT_DATA))

/**
* @brief  HT_EMU_HCYCRMS_UPDSEL
*/ 
#define IS_HT_EMU_HCYCRMS_UPDSEL(UPDSEL) (((UPDSEL) == HCycRms_Half)||((UPDSEL) == HCycRms_One))

/**
* @brief  HT_EMU_RMSIT_ADDMODE
*/ 
#define IS_HT_EMU_RMSIT_ADDMODE(MODE) (((MODE) == RmsItAddMode_add)||((MODE) == RmsItAddMode_sub))
/**
* @brief  HT_EMU_DMA_SRCSEL
*/ 
#define IS_HT_EMU_DMA_SRCSEL(SRCSEL) (((SRCSEL) == DMA_SPL)||((SRCSEL) == DMA_SYNC))

/**
* @brief  HT_EMU_SSTART_SRCSEL
*/ 
#define IS_HT_EMU_SSTART_SRCSEL(SRCSEL) (((SRCSEL) == SStartSelSStart)||((SRCSEL) == SStartSelPOrQ))
/**
* @brief  HT_EMU_PSTART_SPEEDSEL
*/ 
#define IS_HT_EMU_PSTART_SPEEDSEL(SPEEDSEL) (((SPEEDSEL) == PStartFast)||((SPEEDSEL) == PStartSlow)||((SPEEDSEL) == PStartInst))

/**
* @brief  HT_EMU_CIADD_ADDMODE
*/ 
#define IS_HT_EMU_CIADD_ADDMODE(MODE) (((MODE) == CiaddAbs)||((MODE) == CiaddAdd))

#define IS_HT_EMU_WAVE_SRCSEL(SRCSEL) (((SRCSEL) == Wave_dec)||((SRCSEL) == Wave_hpf))

#define IS_HT_EMU_IPTAMP_SPEEDSEL(SPEEDSEL) (((SPEEDSEL) == IpTampFast)||((SPEEDSEL) == IpTampSlow))

#define IS_HT_EMU_TAMP_SPEEDSEL(SPEEDSEL) (((SPEEDSEL) == TampFast)||((SPEEDSEL) == TampSlow))

#define IS_HT_EMU_CHNFIX_SRCSEL(SRCSEL) (((SRCSEL) == ChnFix_ch1)||((SRCSEL) == ChnFix_beforeCh))

#define IS_HT_EMU_IPTAMP_SRCSEL(SRCSEL) (((SRCSEL) == IpTampRms)||((SRCSEL) == IpTampPower))

#define IS_HT_EMU_TAMP_SRCSEL(SRCSEL) (((SRCSEL) == TampRms)||((SRCSEL) == TampPower))

#define IS_HT_EMU_METER_CHNSEL(CHNSEL) (((CHNSEL) == MeterCh1)||((CHNSEL) == MeterCh2))

#define IS_HT_EMU_WAVE_UPDSEL(UPDSEL) (((UPDSEL) == WaveUpd_8)||((UPDSEL) == WaveUpd_4)||((UPDSEL) == WaveUpd_2)||((UPDSEL) == WaveUpd_1))

#define IS_HT_EMU_HPF_CHNSEL(CHNSEL) (((CHNSEL) == HpfChanel_U)||((CHNSEL) == HpfChanel_I1)||((CHNSEL) == HpfChanel_I2))

#define IS_HT_EMU_LPCF1CF3_CHNSEL(CHNSEL) (((CHNSEL) == LpCF1P_CF3S)||((CHNSEL) == LpCF1S_CF3P))

#define IS_HT_EMU_LPEMUCLK_SRCSEL(SRCSEL) (((SRCSEL) == LpEmuclk_32k)||((SRCSEL) == LpEmuclk_204k))

#define IS_HT_EMU_CF_POS(POS) (((POS) == CFPos_High)||((POS) == CFPos_Low))

#define IS_HT_EMU_CONSTENERGY_CLKSEL(CLKSEL) (((CLKSEL) == EnergyConstClk_32K)||((CLKSEL) == EnergyConstClk_BS))

#define IS_HT_EMU_PowerConst_CHNSEL(CHNSEL) (((CHNSEL) == PowerConstS)||((CHNSEL) == PowerConstQ)||((CHNSEL) == PowerConstP))

#define IS_HT_EMU_UPEAKSAG_SRCSEL(SRCSEL) (((SRCSEL) == PeakSagHalfVP)||((SRCSEL) == PeakSagHalfRms))

#define IS_HT_EMU_LPPROC_CHNSEL(CHNSEL) (((CHNSEL) == LpProcSelNormal)||((CHNSEL) == LpProcSelOneCyc))

#define IS_HT_EMU_IHCYCVP_ZCSEL(ZCSEL) (((ZCSEL) == IHvpZCSel_I)||((ZCSEL) == IHvpZCSel_U))

#define IS_HT_EMU_ENERGY1_ACCMODESEL(MODESEL) (((MODESEL) == CF1AccuModeAdd) || \
																	((MODESEL) == CF1AccuModePos) || \
																	((MODESEL) == CF1AccuModeAbs) || \
																	((MODESEL) == CF1AccuModePN))

#define IS_HT_EMU_ENERGY2_ACCMODESEL(MODESEL) (((MODESEL) == CF2AccuModeAdd) || \
																	((MODESEL) == CF2AccuModePos) || \
																	((MODESEL) == CF2AccuModeAbs) || \
																	((MODESEL) == CF2AccuModePN))

#define IS_HT_EMU_ENERGYRUN_CHNSEL(CHNSEL) (((CHNSEL) == CF1Run)||((CHNSEL) == CF2Run)||((CHNSEL) == CF3Run))

#define IS_HT_EMU_OSRSEL(OSRSEL) (((OSRSEL) == OSR128)||((OSRSEL) == OSR64))

#define IS_HT_EMU_AVGPOWER_SCRSEL(SRCSEL) (((SRCSEL) == AvgPowerSelFast)||((SRCSEL) == AvgPowerSelSlow))

#define IS_HT_EMU_CF1_OUTSEL(OUTSEL) (((OUTSEL) == CF1OutSelCF1PN) || \
																	((OUTSEL) == CF1OutSelCF2PN) || \
																	((OUTSEL) == CF1OutSelCF3PN) || \
																	((OUTSEL) == CF1OutSelCF1P) || \
																	((OUTSEL) == CF1OutSelCF1N) || \
																	((OUTSEL) == CF1OutSelCF2P) || \
																	((OUTSEL) == CF1OutSelCF2N) || \
																	((OUTSEL) == CF1OutSelCF3P) || \
																	((OUTSEL) == CF1OutSelCF3N))

#define IS_HT_EMU_CF2_OUTSEL(OUTSEL) (((OUTSEL) == CF2OutSelCF1PN) || \
																	((OUTSEL) == CF2OutSelCF2PN) || \
																	((OUTSEL) == CF2OutSelCF3PN))


#define IS_HT_EMU_CF3_OUTSEL(OUTSEL) (((OUTSEL) == CF3OutSelCF1PN) || \
																	((OUTSEL) == CF3OutSelCF2PN) || \
																	((OUTSEL) == CF3OutSelCF3PN))


#define IS_HT_EMU_UPGA_SEL(SRCSEL) (((SRCSEL) == UPGA_1)||((SRCSEL) == UPGA_2)||((SRCSEL) == UPGA_4))
#define IS_HT_EMU_I1PGA_SEL(SRCSEL) (((SRCSEL) == I1PGA_1) || \
																	((SRCSEL) == I1PGA_2) || \
																	((SRCSEL) == I1PGA_8) || \
																	((SRCSEL) == I1PGA_16) || \
																	((SRCSEL) == I1PGA_24))

#define IS_HT_EMU_I2PGA_SEL(SRCSEL) (((SRCSEL) == I2PGA_1)||((SRCSEL) == I2PGA_2)||((SRCSEL) == I2PGA_8)||((SRCSEL) == I2PGA_16))

#define IS_HT_EMU_CFP_SCRSEL(SRCSEL) (((SRCSEL) == CFP_80ms)||((SRCSEL) == CFP_40ms)||((SRCSEL) == CFP_20ms)||((SRCSEL) == CFP_10ms))

#define IS_HT_EMU_UDG_SCRSEL(SRCSEL) (((SRCSEL) == UDG_8)||((SRCSEL) == UDG_4)||((SRCSEL) == UDG_2)||((SRCSEL) == UDG_1))
#define IS_HT_EMU_I1DG_SCRSEL(SRCSEL) (((SRCSEL) == I1DG_8)||((SRCSEL) == I1DG_4)||((SRCSEL) == I1DG_2)||((SRCSEL) == I1DG_1))
#define IS_HT_EMU_I2DG_SCRSEL(SRCSEL) (((SRCSEL) == I2DG_8)||((SRCSEL) == I2DG_4)||((SRCSEL) == I2DG_2)||((SRCSEL) == I2DG_1))

#define IS_HT_EMU_POWERSHIFT_SEL(SEL) (((SEL) == PowerShift_1) || \
																	((SEL) == PowerShift_2) || \
																	((SEL) == PowerShift_4) || \
																	((SEL) == PowerShift_8) || \
																	((SEL) == PowerShift_16))

#define IS_HT_EMU_FASTPRMS_UPDSEL(UPDSEL) (((UPDSEL) == FastPRMS_UpdSel_1) || \
																	((UPDSEL) == FastPRMS_UpdSel_2) || \
																	((UPDSEL) == FastPRMS_UpdSel_4) || \
																	((UPDSEL) == FastPRMS_UpdSel_8))
																	
#define IS_HT_EMU_ZCD_SEL(SEL) (((SEL) == ZCdSel_P)||((SEL) == ZCdSel_N)||((SEL) == ZCdSel_PN))

#define IS_HT_EMU_ADC_CHNSEL(SEL) (((SEL) == EMUCTRL_AdcUon) || \
																	((SEL) == EMUCTRL_AdcI1on) || \
																	((SEL) == EMUCTRL_AdcI2on) || \
																	((((SEL) & (uint32_t)(~EMUCTRL_AdcOn)) == 0x00) && ((SEL) != 0x00)))


#define IS_HT_EMU_SLOW_PRMS_UPDSEL(UPDSEL) (((UPDSEL) == SlowPRMS_UpdSel_2)||((UPDSEL) == SlowPRMS_UpdSel_4))

#define IS_HT_EMU_DC_UPDSEL(UPDSEL) (((UPDSEL) == DC_UpdSel_1)||((UPDSEL) == DC_UpdSel_2)||((UPDSEL) == DC_UpdSel_4)||((UPDSEL) == DC_UpdSel_8))

#define IS_HT_EMU_NORMAL_EMUCLK_SEL(SEL) (((SEL) == Normal_EmuClkSel_1638K)||((SEL) == Normal_EmuClkSel_819K)||((SEL) == Normal_EmuClkSel_409K))

#define IS_HT_EMU_ENERGY2_SRCSEL(SRCSEL) (((SRCSEL) == Energy2SrcSel_Q) || \
																	((SRCSEL) == Energy2SrcSel_FundP) || \
																	((SRCSEL) == Energy2SrcSel_AllP2) || \
																	((SRCSEL) == Energy2SrcSel_PConst))

#define IS_HT_EMU_PQSTART_SRCSEL(SRCSEL) (((SRCSEL) == PQStartSel_PQ)||((SRCSEL) == PQStartSel_PORQ))

#define IS_HT_EMU_FUND_UPDSEL(UPDSEL) (((UPDSEL) == FundUpd_1) || \
																	((UPDSEL) == FundUpd_2) || \
																	((UPDSEL) == FundUpd_4) || \
																	((UPDSEL) == FundUpd_8) || \
																	((UPDSEL) == FundUpd_16) || \
																	((UPDSEL) == FundUpd_32))

#define IS_HT_EMU_POWERS_SRCSEL(SRCSEL) (((SRCSEL) == PowerSSrcSel_All)||((SRCSEL) == PowerSSrcSel_Fund))

#define IS_HT_EMU_POWERQ_SRCSEL(SRCSEL) (((SRCSEL) == PowerQSrcSel_All)||((SRCSEL) == PowerQSrcSel_Fund))

#define IS_HT_EMU_IROSI_CHNSEL(CHNSEL) (((CHNSEL) == RosiI1)||((CHNSEL) == RosiI2))

#define IS_HT_EMU_LPSTANDBYTIME_SEL(SEL) (((SEL) == LpStandByTime_4) || \
																	((SEL) == LpStandByTime_8) || \
																	((SEL) == LpStandByTime_16) || \
																	((SEL) == LpStandByTime_32) || \
																	((SEL) == LpStandByTime_64) || \
																	((SEL) == LpStandByTime_128) || \
																	((SEL) == LpStandByTime_256) || \
																	((SEL) == LpStandByTime_512))

#define IS_HT_EMU_SYSFREQ_SEL(SEL) (((SEL) == SysFreq50Hz)||((SEL) == SysFreq60Hz))

#define IS_HT_EMU_ZCINT_SRCSEL(SRCSEL) (((SRCSEL) == ZXSrcSel_AfterHPF)||((SRCSEL) == ZXSrcSel_AfterRosi))

#define IS_HT_EMU_SYNC_CHNEN(CHNSEL) (((CHNSEL) == SyncU_En)||((CHNSEL) == SyncI_En))

#define IS_HT_EMU_SYNCI_CHNSEL(CHNSEL) (((CHNSEL) == SyncISel_I1)||((CHNSEL) == SyncISel_I2))

#define IS_HT_EMU_SYNCU_GAINSEL(SEL) (((SEL) == SyncGainU_1) || \
																	((SEL) == SyncGainU_2) || \
																	((SEL) == SyncGainU_4) || \
																	((SEL) == SyncGainU_8) || \
																	((SEL) == SyncGainU_16) || \
																	((SEL) == SyncGainU_32) || \
																	((SEL) == SyncGainU_64) || \
																	((SEL) == SyncGainU_128) || \
																	((SEL) == SyncGainU_256) || \
																	((SEL) == SyncGainU_512) || \
																	((SEL) == SyncGainU_1024) || \
																	((SEL) == SyncGainU_2048))

#define IS_HT_EMU_SYNCI_GAINSEL(SEL) (((SEL) == SyncGainI_1) || \
																	((SEL) == SyncGainI_2) || \
																	((SEL) == SyncGainI_4) || \
																	((SEL) == SyncGainI_8) || \
																	((SEL) == SyncGainI_16) || \
																	((SEL) == SyncGainI_32) || \
																	((SEL) == SyncGainI_64) || \
																	((SEL) == SyncGainI_128) || \
																	((SEL) == SyncGainI_256) || \
																	((SEL) == SyncGainI_512) || \
																	((SEL) == SyncGainI_1024) || \
																	((SEL) == SyncGainI_2048))

#define IS_HT_EMU_POWEROV_PNEN(PNEN) (((PNEN) == PowerOV_CF1)||((PNEN) == PowerOV_CF2)||((PNEN) == PowerOV_CF3))

#define IS_HT_EMU_ENERGY_ACCUALG_SEL(SEL) (((SEL) == EnergyAccuAlgOld)||((SEL) == EnergyAccuAlgNew))

#define IS_HT_EMU_ENERGYIN_SRCSEL(SRCSEL) (((SRCSEL) == EnergyInAvg)||((SRCSEL) == EnergyInIns))

#endif


#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
typedef struct __EMU_InitTypeDef
{
	__IO uint32_t    ErrorCode;        		  /*!< EMU Error code                    */
	void (* EmuCallback)(struct __EMU_InitTypeDef *EMU_InitStruct);               /*!< EMU  Complete Callback             */
}EMU_InitTypeDef;        


/**
* @brief  EMU Callback pointer definition
*/
typedef  void (*pEMU_CallbackTypeDef)(EMU_InitTypeDef *EMU_InitStruct);  /*!< pointer to an EMU callback function */

#endif/* USE_EMU_REGISTER_CALLBACKS */



/*
*********************************************************************************************************
*                                           Global function declaration
*********************************************************************************************************
*/
void Enable_emu_module(void);
void Disable_emu_module(void);
void Open_emu_LDO(void);
void Close_emu_LDO(void);
void Reset_EMU_ECA_Regs(void);
void Reset_EMU_Module(void);
#if defined  HT501x  ||  defined  HT502x
void Set_EMU_Reactive_Phase_Gain(uint32_t Freq); 
#endif
ITStatus HT_EMUSR_FlagStatusGet(uint32_t ITFlag);
#if defined  HT503x 
void HT_Clear_EMUSR_PendingBit(uint32_t ITFlag);
uint32_t Read_ECR_Chksum1_Reg(void);
uint32_t Read_ECR_Chksum2_Reg(void);
#endif
void HT_EMU_ITConfig(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_EMU_ITFlagStatusGet(uint32_t ITFlag);
void HT_EMU_ClearITPendingBit(uint32_t ITFlag);
uint32_t Read_ECR_ChksumReg(void);
uint32_t Read_EPR_Reg(uint32_t address);
uint32_t Read_ECR_Reg(uint32_t address);
void Write_ECR_Reg(uint32_t address, uint32_t data);



#if defined  HT501x  ||  defined  HT502x
void Select_Pulse_Port(PFPort Port, PFType Type, PFWide PulseWidth);
void Set_Valid_Channel(uint32_t ChOn, uint32_t ChGain );
void Start_AdcBuff(void);
void HT_EMU_Sag_Peak_init(SagPeak_InitTypeDef *SagPeakInit);
uint32_t Get_HFConst_value_ct(uint32_t meter_EC, uint32_t U_R1, uint32_t U_R2, uint32_t U_apga, uint32_t I_R, uint32_t CT_ratio, uint32_t APga);
uint32_t Get_HFConst_value_Shunt(uint32_t meter_EC, uint32_t U_R1, uint32_t U_R2, uint32_t U_apga, uint32_t I_R, uint32_t APga);
#endif

#if defined  HT503x 
void HT_Set_EMU_PowerGain(PowerGP_AddrTypeDef type,int16_t data);
void HT_Get_EMU_PowerGain(PowerGP_AddrTypeDef type,int16_t *data);
void HT_Set_EMU_PowerGphs(PowerGphs_AddrTypeDef type,int16_t data);
void HT_Get_EMU_PowerGphs(PowerGphs_AddrTypeDef type,int16_t *data);
void HT_Set_EMU_DECShift(DECShift_TypeDef *DecShiftStruct);
void HT_Get_EMU_DECShift(DECShift_TypeDef *DecShiftStruct);
void HT_Set_EMU_ADCOffset(ADCOffset_AddrTypeDef type,int16_t data);
void HT_Get_EMU_ADCOffset(ADCOffset_AddrTypeDef type,int16_t *data);
void HT_Set_EMU_I2Gain(int16_t data);
void HT_Get_EMU_I2Gain(int16_t *data);
void HT_Set_EMU_HFConst(uint32_t data);
uint32_t HT_Get_EMU_HFConst(void);
void HT_Set_EMU_UConst(uint16_t data);
uint32_t HT_Get_EMU_UConst(void);
void HT_Set_EMU_IPTamp(uint16_t data);
void HT_Set_EMU_ICHK(uint8_t data);
void HT_Set_EMU_LpIdleTime(uint16_t data);
void HT_Set_EMU_AFDIV(uint16_t data);
void HT_Set_EMU_PowerRmsAvgNum(uint16_t data);
void HT_Set_EMU_LpRmsTHO(uint16_t data);
void HT_Set_EMU_RmsItTHO(uint16_t data);
void HT_Set_EMU_CFxCnt(CFxCnt_AddrTypeDef type,uint32_t data);
void HT_Get_EMU_CFxCnt(CFxCnt_AddrTypeDef type,uint32_t *data);
void HT_Set_EMU_PowerOffset(PowerOffset_AddrTypeDef type,int16_t data);
void HT_Get_EMU_PowerOffset(PowerOffset_AddrTypeDef type,int16_t *data);
void HT_Set_EMU_RmsOffset(RmsOffset_AddrTypeDef type,uint16_t data);
void HT_Get_EMU_RmsOffset(RmsOffset_AddrTypeDef type,uint16_t *data);
void HT_Set_EMU_OneCycRmsNum(uint16_t data);
void HT_Set_EMU_HCycleRMS_I2En(FunctionalState NewState);
void HT_Set_EMU_HCycRms_UpdSel(HCycRms_UpdSelTypeDef Type);
void HT_Set_EMU_HCycleRms_En(FunctionalState NewState);
void HT_Set_EMU_RmsIt_AddMode(RmsIt_AddModeTypeDef Type);
void HT_Set_EMU_FundIt_En(FunctionalState NewState);
void HT_Set_EMU_RMSIt_En(FunctionalState NewState);
void HT_Set_EMU_DMA_SrcSel(DMA_SrcSelTypeDef Type);
void HT_Set_EMU_SSart_CFG(SStart_CfgTypeDef Type);
void HT_Set_EMU_PStart_SpeedSel(PowerStart_SrcSelTypeDef Type);
void HT_Set_EMU_VrefEn(FunctionalState NewState);
void HT_Set_EMU_CIADD_AddMode(CIADD_AddModeTypeDef Type);
void HT_Set_EMU_Wave_SrcSel(Wave_SrcSelTypeDef Type);
void HT_Set_EMU_IPTamp_SrcSpeedSel(IpTamp_SrcSpeedSelTypeDef Type);
void HT_Set_EMU_Tamp_SrcSpeedSel(Tamp_SrcSpeedSelTypeDef Type);
void HT_Set_EMU_CHNFix_Sel(CHNFix_SelTypeDef Type);
void HT_Set_EMU_IPTamp_SrcSel(IpTamp_SrcSelTypeDef Type);
void HT_Set_EMU_Tamp_SrcSel(Tamp_SrcSelTypeDef Type);
void HT_Set_EMU_FltonEn(FunctionalState NewState);
void HT_Set_EMU_MeterChanel_Sel(Chanel_SelTypeDef Type);
void HT_Set_EMU_CIADDEn(FunctionalState NewState);
void HT_Set_EMU_Wave_Upd(Wave_UpdTypeDef Type);
void HT_Set_EMU_HpfEn(Hpf_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_LpCF1CF3_Sel(LpCF1OR3_SelTypeDef Type);
void HT_Set_EMU_UConstEn(FunctionalState NewState);
void HT_Set_EMU_LpEmuClk_Sel(LpEmuclk_SelTypeDef Type);
void HT_Set_EMU_CF_POS_Sel(CFPos_SelTypeDef Type);
void HT_Set_EMU_LpModeEn(FunctionalState NewState);
void HT_Set_EMU_EnergyConstClk_Sel(EnergyConstClk_SelTypeDef Type);
void HT_Set_EMU_PQLpfEn(FunctionalState NewState);
void HT_Set_EMU_RmsLpfEn(FunctionalState NewState);
void HT_Set_EMU_UPeakEn(FunctionalState NewState);
void HT_Set_EMU_IOVEn(FunctionalState NewState);
void HT_Set_EMU_PowerConstEn(PowerConst_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_USagEn(FunctionalState NewState);
void HT_Set_EMU_UPeakSag_SrcSel(PeakSag_SrcSelTypeDef Type);
void HT_Set_EMU_OneCycRmsEn(FunctionalState NewState);
void HT_Set_EMU_LpProc_Sel(LpProc_SelTypeDef Type);
void HT_Set_EMU_IHCycVp_ZCSel(IHvpZCSel_TypeDef Type);
void HT_Set_EMU_Energy1AccuMode(CF1_AccuMode_TypeDef Type);
void HT_Set_EMU_Energy2AccuMode(CF2_AccuMode_TypeDef Type);
void HT_Set_EMU_EnergyRunEn(EnergyRun_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_OSR(EmuOsr_SelTypeDef Type);
void HT_Set_EMU_AvgPower_SrcSel(AvgPower_SrcSelTypeDef Type);
void HT_Set_EMU_CF1_OutSel(CF1_OutSelTypeDef Type);
void HT_Set_EMU_CF2_OutSel(CF2_OutSelTypeDef Type);
void HT_Set_EMU_CF3_OutSel(CF3_OutSelTypeDef Type);
void HT_Set_EMU_UPGA(UPGA_SelTypeDef Type);
void HT_Set_EMU_I1PGA(I1PGA_SelTypeDef Type);
void HT_Set_EMU_I2PGA(I2PGA_SelTypeDef Type);
void HT_Set_EMU_CFP(CFP_SelTypeDef Type);
void HT_Set_EMU_UDG(UDG_SelTypeDef Type);
void HT_Set_EMU_I1DG(I1DG_SelTypeDef Type);
void HT_Set_EMU_I2DG(I2DG_SelTypeDef Type);
void HT_Set_EMU_PowerShift(PowerShift_SelTypeDef Type);
void HT_Set_EMU_FastPRMS_UpdSel(FastPRMS_UpdSelTypeDef Type);
void HT_Set_EMU_ZCd_Sel(ZCd_SelTypeDef Type);
void HT_Set_EMU_ADCEn(uint32_t Chanel,FunctionalState NewState);
void HT_Set_EMU_SlowPRMS_UpdSel(SlowPRMS_UpdSelTypeDef Type);
void HT_Set_EMU_DCUpdSel(DC_UpdSelTypeDef Type);
void HT_Set_EMU_NormalEmuClk_Sel(Normal_EmuClkSelTypeDef Type);
void HT_Set_EMU_Energy2_SrcSel(Energy2_SrcSelTypeDef Type);
void HT_Set_EMU_LpVrefEn(FunctionalState NewState);
void HT_Set_EMU_PQStartSel(PQStart_SelTypeDef Type);
void HT_Set_EMU_FundUpdSel(FundUpd_TypeDef Type);
void HT_Set_EMU_PowerS_SrcSel(PowerS_SrcSelTypeDef Type);
void HT_Set_EMU_PowerQ_SrcSel(PowerQ_SrcSelTypeDef Type);
void HT_Set_EMU_IRosiEn(Rosi_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_LpStandByTime(LpStandByTime_SelTypeDef Type);
void HT_Set_EMU_LpIdle_En(FunctionalState NewState);
void HT_Set_EMU_SysFreq_Sel(SysFreq_SelTypeDef Type);
void HT_Set_EMU_PowerS_DCEn(FunctionalState NewState);
void HT_Set_EMU_DC_En(FunctionalState NewState);
void HT_Set_EMU_AutoTC_En(FunctionalState NewState);
void HT_Set_EMU_LDO_En(FunctionalState NewState);
void HT_Set_EMU_ZXSrcSel(ZXSrcSel_TypeDef Type);
void HT_Set_EMU_SyncEn(Sync_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_SyncISrcSel(SyncISel_TypeDef Type);
void HT_Set_EMU_SyncUGain(SyncUGain_TypeDef Type);
void HT_Set_EMU_SyncIGain(SyncIGain_TypeDef Type);
void HT_Set_EMU_PowerOV_PNEn(PowerOV_ChanelTypeDef Chanel,FunctionalState NewState);
void HT_Set_EMU_EnergyAccuAlg(Energy_AccuAlgTypeDef Type);
void HT_Set_EMU_EnergyInSrcSel(EnergyIn_SrcSelTypeDef Type);
void HT_Set_EMU_EnergyReadNotClr_En(FunctionalState NewState);
void HT_Set_EMU_FlickerEn(FunctionalState NewState);
void HT_Set_EMU_FlickerSetOffsetEn(FunctionalState NewState);
void HT_Set_EMU_FundEn(FunctionalState NewState);
void HT_Reset_EMU_Flicker(void);
void HT_EMU_PowerStart_Init(PowerStart_InitTypeDef *StartInit);
void HT_EMU_PowerConst_Init(PowerConst_InitTypeDef *PowerConstInit);
void HT_EMU_CIADD_Init(CIADD_TypeDef *CiaddInit);
void HT_EMU_Tamp_Init(Tamp_InitTypeDef *TampInit);
void HT_EMU_SagPeakIOV_Init(SagPeakIOV_InitTypeDef *SagPeakIOVInit);
void HT_EMU_TempComp_Init(TempComp_InitTypeDef *TempCompInit);
void HT_EMU_ZC_Init(ZC_InitTypeDef *ZCInit);
void HT_EMU_HCycRms_Init(HCycRms_InitTypeDef *HCycRmsInit);
void HT_EMU_Sync_Init(Sync_InitTypeDef *SyncInit);
void HT_EMU_Fund_Init(Fund_InitTypeDef *FundInit);
void HT_EMU_RmsIt_Init(RmsIt_InitTypeDef *RmsItInit);
void HT_EMU_Flicker_Init(Flicker_InitTypeDef *FlickerInit);
void HT_EMU_OneCycRms_Init(CycRms_InitTypeDef *CycRmsInit);
void HT_EMU_LpMode_Init(LpMode_InitTypeDef *LpModeInit);
#endif 
#if (USE_HT_EMU_REGISTER_CALLBACKS != 1U)
#if defined  HT501x  ||  defined  HT502x
void HT_EMU_Init(void);
#endif
#endif

#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
void HT_EMU_CpltCallback(EMU_InitTypeDef *EMU_InitStruct);
void HT_EMU_InitCallbacksToDefault(EMU_InitTypeDef *EMU_InitStruct);
StatusTypeDef HT_EMU_RegisterCallback(EMU_InitTypeDef *EMU_InitStruct, pEMU_CallbackTypeDef pCallback);
#endif /* USE_HT_EMU_REGISTER_CALLBACKS */

 

#endif                                               /* This File Only support HT50xx */

#ifdef __cplusplus
}
#endif

#endif /* __HT50XX_EMU_H__ */ 

