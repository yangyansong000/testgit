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
* File         : ht7xxx_emu.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used emu Function.
**********************************************************************************************************
*/

#ifndef __HT7XXX_EMU_H__
#define __HT7XXX_EMU_H__

#ifdef __cplusplus
extern "C" {
#endif 
    
#include "ht6xxx_lib.h"
    
#if defined  HT762x ||  defined  HT772x                      /* This File Only support HT7xxx */
    
/*
*********************************************************************************************************
*                                          Global macro / structure
*********************************************************************************************************
*/
#define	HT7X2X_LIB_VERSION_NUM                  	"HT7x2x_StdPeriphLib_Emu_V00.00.002"

#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/**
* @brief  EMU Error Code
*/
#define EMU_ERROR_NONE              (0x00000000UL)   /*!< No error            */
#define EMU_ERROR_INVALID_CALLBACK  (0x00000020UL)   /*!< Invalid Callback error  */
#define EWU_ERROR_NONE              (0x00000000UL)   /*!< No error            */
#define EWU_ERROR_INVALID_CALLBACK  (0x00000020UL)   /*!< Invalid Callback error  */

#endif /* USE_EMU_REGISTER_CALLBACKS */

/****EPR register offset address,base address: 0x4001B000,(read only)******************************/
#if defined  HT762x 
#define	EPR_SPL_Ua                  	((uint32_t)0x0000)
#define	EPR_SPL_Ub                  	((uint32_t)0x0004)
#define	EPR_SPL_Uc                  	((uint32_t)0x0008)
#define	EPR_SPL_Ia                  	((uint32_t)0x000C)
#define	EPR_SPL_Ib                  	((uint32_t)0x0010)
#define	EPR_SPL_Ic                  	((uint32_t)0x0014)
#define	EPR_SPL_In                  	((uint32_t)0x0018)
#define	EPR_All_Power_Pa            	((uint32_t)0x001C)
#define	EPR_All_Power_Pb            	((uint32_t)0x0020)
#define	EPR_All_Power_Pc            	((uint32_t)0x0024)
#define	EPR_All_Power_Pt            	((uint32_t)0x0028)
#define	EPR_All_Power_Qa            	((uint32_t)0x002C)
#define	EPR_All_Power_Qb            	((uint32_t)0x0030)
#define	EPR_All_Power_Qc            	((uint32_t)0x0034)
#define	EPR_All_Power_Qt            	((uint32_t)0x0038)
#define	EPR_All_Power_Sa            	((uint32_t)0x003C)
#define	EPR_All_Power_Sb            	((uint32_t)0x0040)
#define	EPR_All_Power_Sc            	((uint32_t)0x0044)
#define	EPR_All_Power_St            	((uint32_t)0x0048)
#define	EPR_All_RMS_Ua              	((uint32_t)0x004C)
#define	EPR_All_RMS_Ub              	((uint32_t)0x0050)
#define	EPR_All_RMS_Uc              	((uint32_t)0x0054)
#define	EPR_All_RMS_Ia              	((uint32_t)0x0058)
#define	EPR_All_RMS_Ib              	((uint32_t)0x005C)
#define	EPR_All_RMS_Ic              	((uint32_t)0x0060)
#define	EPR_All_RMS_In              	((uint32_t)0x0064)
#define	EPR_RMS_Ut                  	((uint32_t)0x0068)
#define	EPR_RMS_It                  	((uint32_t)0x006C)
#define	EPR_RMS_UAB                 	((uint32_t)0x0070)
#define	EPR_RMS_UBC                 	((uint32_t)0x0074)
#define	EPR_RMS_UAC                 	((uint32_t)0x0078)
#define	EPR_FreqUa                  	((uint32_t)0x007C)
#define	EPR_FreqUb                  	((uint32_t)0x0080)
#define	EPR_FreqUc                  	((uint32_t)0x0084)
#define	EPR_FreqU                   	((uint32_t)0x0088)
#define	EPR_All_PFa                 	((uint32_t)0x008C)
#define	EPR_All_PFb                 	((uint32_t)0x0090)
#define	EPR_All_PFc                 	((uint32_t)0x0094)
#define	EPR_All_PFt                 	((uint32_t)0x0098)
#define	EPR_PhaseAngle_Ua           	((uint32_t)0x009C)
#define	EPR_PhaseAngle_Ub           	((uint32_t)0x00A0)
#define	EPR_PhaseAngle_Uc           	((uint32_t)0x00A4)
#define	EPR_PhaseAngle_Ia           	((uint32_t)0x00A8)
#define	EPR_PhaseAngle_Ib           	((uint32_t)0x00AC)
#define	EPR_PhaseAngle_Ic           	((uint32_t)0x00B0)
#define	EPR_PhaseAngle_In           	((uint32_t)0x00B4)
#define	EPR_All_EnergyPos_Pa        	((uint32_t)0x00B8)
#define	EPR_All_EnergyPos_Pb        	((uint32_t)0x00BC)
#define	EPR_All_EnergyPos_Pc        	((uint32_t)0x00C0)
#define	EPR_All_EnergyPos_Pt        	((uint32_t)0x00C4)
#define	EPR_All_EnergyPos_Qa        	((uint32_t)0x00C8)
#define	EPR_All_EnergyPos_Qb        	((uint32_t)0x00CC)
#define	EPR_All_EnergyPos_Qc        	((uint32_t)0x00D0)
#define	EPR_All_EnergyPos_Qt        	((uint32_t)0x00D4)
#define	EPR_Energy_Sa               	((uint32_t)0x00D8)
#define	EPR_Energy_Sb               	((uint32_t)0x00DC)
#define	EPR_Energy_Sc               	((uint32_t)0x00E0)
#define	EPR_Energy_St               	((uint32_t)0x00E4)
#define	EPR_All_CFCntPos_Pa         	((uint32_t)0x00E8)
#define	EPR_All_CFCntPos_Pb         	((uint32_t)0x00EC)
#define	EPR_All_CFCntPos_Pc         	((uint32_t)0x00F0)
#define	EPR_All_CFCntPos_Pt         	((uint32_t)0x00F4)
#define	EPR_All_CFCntPos_Qa         	((uint32_t)0x00F8)
#define	EPR_All_CFCntPos_Qb         	((uint32_t)0x00FC)
#define	EPR_All_CFCntPos_Qc         	((uint32_t)0x0100)
#define	EPR_All_CFCntPos_Qt         	((uint32_t)0x0104)
#define	EPR_CFCntPos_Sa             	((uint32_t)0x0108)
#define	EPR_CFCntPos_Sb             	((uint32_t)0x010C)
#define	EPR_CFCntPos_Sc             	((uint32_t)0x0110)
#define	EPR_CFCntPos_St             	((uint32_t)0x0114)
#define	EPR_All_EnergyNeg_Pa        	((uint32_t)0x0118)
#define	EPR_All_EnergyNeg_Pb        	((uint32_t)0x011C)
#define	EPR_All_EnergyNeg_Pc        	((uint32_t)0x0120)
#define	EPR_All_EnergyNeg_Pt        	((uint32_t)0x0124)
#define	EPR_All_EnergyNeg_Qa        	((uint32_t)0x0128)
#define	EPR_All_EnergyNeg_Qb        	((uint32_t)0x012C)
#define	EPR_All_EnergyNeg_Qc        	((uint32_t)0x0130)
#define	EPR_All_EnergyNeg_Qt        	((uint32_t)0x0134)
#define	EPR_All_CFCntNeg_Pa         	((uint32_t)0x0138)
#define	EPR_All_CFCntNeg_Pb         	((uint32_t)0x013C)
#define	EPR_All_CFCntNeg_Pc         	((uint32_t)0x0140)
#define	EPR_All_CFCntNeg_Pt         	((uint32_t)0x0144)
#define	EPR_All_CFCntNeg_Qa         	((uint32_t)0x0148)
#define	EPR_All_CFCntNeg_Qb         	((uint32_t)0x014C)
#define	EPR_All_CFCntNeg_Qc         	((uint32_t)0x0150)
#define	EPR_All_CFCntNeg_Qt         	((uint32_t)0x0154)
#define	EPR_EnergyNeg_SaConst       	((uint32_t)0x0158)
#define	EPR_EnergyNeg_SbConst       	((uint32_t)0x015C)
#define	EPR_EnergyNeg_ScConst       	((uint32_t)0x0160)
#define	EPR_EnergyNeg_StConst       	((uint32_t)0x0164)
#define	EPR_CFCntNeg_Sa             	((uint32_t)0x0168)
#define	EPR_CFCntNeg_Sb             	((uint32_t)0x016C)
#define	EPR_CFCntNeg_Sc             	((uint32_t)0x0170)
#define	EPR_CFCntNeg_St             	((uint32_t)0x0174)
#define	EPR_Fund_Power_Pa           	((uint32_t)0x0178)
#define	EPR_Fund_Power_Pb           	((uint32_t)0x017C)
#define	EPR_Fund_Power_Pc           	((uint32_t)0x0180)
#define	EPR_Fund_Power_Pt           	((uint32_t)0x0184)
#define	EPR_Fund_Power_Qa           	((uint32_t)0x0188)
#define	EPR_Fund_Power_Qb           	((uint32_t)0x018C)
#define	EPR_Fund_Power_Qc           	((uint32_t)0x0190)
#define	EPR_Fund_Power_Qt           	((uint32_t)0x0194)
#define	EPR_Fund_Power_Sa           	((uint32_t)0x0198)
#define	EPR_Fund_Power_Sb           	((uint32_t)0x019C)
#define	EPR_Fund_Power_Sc           	((uint32_t)0x01A0)
#define	EPR_Fund_Power_St           	((uint32_t)0x01A4)
#define	EPR_Fund_RMS_Ua             	((uint32_t)0x01A8)
#define	EPR_Fund_RMS_Ub             	((uint32_t)0x01AC)
#define	EPR_Fund_RMS_Uc             	((uint32_t)0x01B0)
#define	EPR_Fund_RMS_Ia             	((uint32_t)0x01B4)
#define	EPR_Fund_RMS_Ib             	((uint32_t)0x01B8)
#define	EPR_Fund_RMS_Ic             	((uint32_t)0x01BC)
#define	EPR_Fund_RMS_In             	((uint32_t)0x01C0)
#define	EPR_Fund_PFa                	((uint32_t)0x01C4)
#define	EPR_Fund_PFb                	((uint32_t)0x01C8)
#define	EPR_Fund_PFc                	((uint32_t)0x01CC)
#define	EPR_Fund_PFt                	((uint32_t)0x01D0)
#define	EPR_Fund_EnergyPos_Pa       	((uint32_t)0x01D4)
#define	EPR_Fund_EnergyPos_Pb       	((uint32_t)0x01D8)
#define	EPR_Fund_EnergyPos_Pc       	((uint32_t)0x01DC)
#define	EPR_Fund_EnergyPos_Pt       	((uint32_t)0x01E0)
#define	EPR_Fund_EnergyPos_Qa       	((uint32_t)0x01E4)
#define	EPR_Fund_EnergyPos_Qb       	((uint32_t)0x01E8)
#define	EPR_Fund_EnergyPos_Qc       	((uint32_t)0x01EC)
#define	EPR_Fund_EnergyPos_Qt       	((uint32_t)0x01F0)
#define	EPR_Fund_CFCntPos_Pa        	((uint32_t)0x01F4)
#define	EPR_Fund_CFCntPos_Pb        	((uint32_t)0x01F8)
#define	EPR_Fund_CFCntPos_Pc        	((uint32_t)0x01FC)
#define	EPR_Fund_CFCntPos_Pt        	((uint32_t)0x0200)
#define	EPR_Fund_CFCntPos_Qa        	((uint32_t)0x0204)
#define	EPR_Fund_CFCntPos_Qb        	((uint32_t)0x0208)
#define	EPR_Fund_CFCntPos_Qc        	((uint32_t)0x020C)
#define	EPR_Fund_CFCntPos_Qt        	((uint32_t)0x0210)
#define	EPR_Fund_EnergyNeg_Pa       	((uint32_t)0x0214)
#define	EPR_Fund_EnergyNeg_Pb       	((uint32_t)0x0218)
#define	EPR_Fund_EnergyNeg_Pc       	((uint32_t)0x021C)
#define	EPR_Fund_EnergyNeg_Pt       	((uint32_t)0x0220)
#define	EPR_Fund_EnergyNeg_Qa       	((uint32_t)0x0224)
#define	EPR_Fund_EnergyNeg_Qb       	((uint32_t)0x0228)
#define	EPR_Fund_EnergyNeg_Qc       	((uint32_t)0x022C)
#define	EPR_Fund_EnergyNeg_Qt       	((uint32_t)0x0230)
#define	EPR_Fund_CFCntNeg_Pa        	((uint32_t)0x0234)
#define	EPR_Fund_CFCntNeg_Pb        	((uint32_t)0x0238)
#define	EPR_Fund_CFCntNeg_Pc        	((uint32_t)0x023C)
#define	EPR_Fund_CFCntNeg_Pt        	((uint32_t)0x0240)
#define	EPR_Fund_CFCntNeg_Qa        	((uint32_t)0x0244)
#define	EPR_Fund_CFCntNeg_Qb        	((uint32_t)0x0248)
#define	EPR_Fund_CFCntNeg_Qc        	((uint32_t)0x024C)
#define	EPR_Fund_CFCntNeg_Qt        	((uint32_t)0x0250)
#define	EPR_Har_Power_Pa            	((uint32_t)0x0254)
#define	EPR_Har_Power_Pb            	((uint32_t)0x0258)
#define	EPR_Har_Power_Pc            	((uint32_t)0x025C)
#define	EPR_Har_Power_Pt            	((uint32_t)0x0260)
#define	EPR_Har_RMS_Ua              	((uint32_t)0x0264)
#define	EPR_Har_RMS_Ub              	((uint32_t)0x0268)
#define	EPR_Har_RMS_Uc              	((uint32_t)0x026C)
#define	EPR_Har_RMS_Ia              	((uint32_t)0x0270)
#define	EPR_Har_RMS_Ib              	((uint32_t)0x0274)
#define	EPR_Har_RMS_Ic              	((uint32_t)0x0278)
#define	EPR_Har_RMS_In              	((uint32_t)0x027C)
#define	EPR_Har_EnergyPos_Pa        	((uint32_t)0x0280)
#define	EPR_Har_EnergyPos_Pb        	((uint32_t)0x0284)
#define	EPR_Har_EnergyPos_Pc        	((uint32_t)0x0288)
#define	EPR_Har_EnergyPos_Pt        	((uint32_t)0x028C)
#define	EPR_Har_CFCntPos_Pa         	((uint32_t)0x0290)
#define	EPR_Har_CFCntPos_Pb         	((uint32_t)0x0294)
#define	EPR_Har_CFCntPos_Pc         	((uint32_t)0x0298)
#define	EPR_Har_CFCntPos_Pt         	((uint32_t)0x029C)
#define	EPR_Har_EnergyNeg_Pa        	((uint32_t)0x02A0)
#define	EPR_Har_EnergyNeg_Pb        	((uint32_t)0x02A4)
#define	EPR_Har_EnergyNeg_Pc        	((uint32_t)0x02A8)
#define	EPR_Har_EnergyNeg_Pt        	((uint32_t)0x02AC)
#define	EPR_Har_CFCntNeg_Pa         	((uint32_t)0x02B0)
#define	EPR_Har_CFCntNeg_Pb         	((uint32_t)0x02B4)
#define	EPR_Har_CFCntNeg_Pc         	((uint32_t)0x02B8)
#define	EPR_Har_CFCntNeg_Pt         	((uint32_t)0x02BC)
#define	EPR_DCVar_Ua                	((uint32_t)0x02C0)
#define	EPR_DCVar_Ub                	((uint32_t)0x02C4)
#define	EPR_DCVar_Uc                	((uint32_t)0x02C8)
#define	EPR_DCVar_Ia                	((uint32_t)0x02CC)
#define	EPR_DCVar_Ib                	((uint32_t)0x02D0)
#define	EPR_DCVar_Ic                	((uint32_t)0x02D4)
#define	EPR_DCVar_In                	((uint32_t)0x02D8)
#define	EPR_UpdHalfWave_Ua          	((uint32_t)0x02DC)
#define	EPR_UpdHalfWave_Ub          	((uint32_t)0x02E0)
#define	EPR_UpdHalfWave_Uc          	((uint32_t)0x02E4)
#define	EPR_UpdHalfWave_Ia          	((uint32_t)0x02E8)
#define	EPR_UpdHalfWave_Ib          	((uint32_t)0x02EC)
#define	EPR_UpdHalfWave_Ic          	((uint32_t)0x02F0)
#define	EPR_UpdHalfWave_In          	((uint32_t)0x02F4)
#define	EPR_QuartRmsIns_Ua          	((uint32_t)0x02F8)
#define	EPR_QuartRmsIns_Ub          	((uint32_t)0x02FC)
#define	EPR_QuartRmsIns_Uc          	((uint32_t)0x0300)
#define	EPR_QuartRmsIns_Ia          	((uint32_t)0x0304)
#define	EPR_QuartRmsIns_Ib          	((uint32_t)0x0308)
#define	EPR_QuartRmsIns_Ic          	((uint32_t)0x030C)
#define	EPR_QuartRmsIns_In          	((uint32_t)0x0310)
#define	EPR_PeakVpUa                	((uint32_t)0x0314)
#define	EPR_PeakVpUb                	((uint32_t)0x0318)
#define	EPR_PeakVpUc                	((uint32_t)0x031C)
#define	EPR_PeakCntUa               	((uint32_t)0x0320)
#define	EPR_PeakCntUb               	((uint32_t)0x0324)
#define	EPR_PeakCntUc               	((uint32_t)0x0328)
#define	EPR_SagVpUa                 	((uint32_t)0x032C)
#define	EPR_SagVpUb                 	((uint32_t)0x0330)
#define	EPR_SagVpUc                 	((uint32_t)0x0334)
#define	EPR_SagCntUa                	((uint32_t)0x0338)
#define	EPR_SagCntUb                	((uint32_t)0x033C)
#define	EPR_SagCntUc                	((uint32_t)0x0340)
#define	EPR_IntVpUa                 	((uint32_t)0x0344)
#define	EPR_IntVpUb                 	((uint32_t)0x0348)
#define	EPR_IntVpUc                 	((uint32_t)0x034C)
#define	EPR_IntCntUa                	((uint32_t)0x0350)
#define	EPR_IntCntUb                	((uint32_t)0x0354)
#define	EPR_IntCntUc                	((uint32_t)0x0358)
#define	EPR_OverFlowVpIa            	((uint32_t)0x035C)
#define	EPR_OverFlowVpIb            	((uint32_t)0x0360)
#define	EPR_OverFlowVpIc            	((uint32_t)0x0364)
#define	EPR_OverFlowVpIn            	((uint32_t)0x0368)
#define	EPR_OverFlowCntIa           	((uint32_t)0x036C)
#define	EPR_OverFlowCntIb           	((uint32_t)0x0370)
#define	EPR_OverFlowCntIc           	((uint32_t)0x0374)
#define	EPR_OverFlowCntIn           	((uint32_t)0x0378)
#else
#define	EPR_SPL_U                  		((uint32_t)0x0000)
#define	EPR_SPL_I1                  	((uint32_t)0x000C)
#define	EPR_SPL_I2                  	((uint32_t)0x0010)
#define	EPR_All_Power_P1            	((uint32_t)0x001C)
#define	EPR_All_Power_P2            	((uint32_t)0x0020)
#define	EPR_All_Power_Pt            	((uint32_t)0x0028)
#define	EPR_All_Power_Q1            	((uint32_t)0x002C)
#define	EPR_All_Power_Q2            	((uint32_t)0x0030)
#define	EPR_All_Power_Qt            	((uint32_t)0x0038)
#define	EPR_All_Power_S1            	((uint32_t)0x003C)
#define	EPR_All_Power_S2            	((uint32_t)0x0040)
#define	EPR_All_Power_St            	((uint32_t)0x0048)
#define	EPR_All_RMS_U  	            	((uint32_t)0x004C)
#define	EPR_All_RMS_I1              	((uint32_t)0x0058)
#define	EPR_All_RMS_I2              	((uint32_t)0x005C)
#define	EPR_RMS_It                  	((uint32_t)0x006C)
#define	EPR_FreqU      	            	((uint32_t)0x007C)
#define	EPR_All_PF1                 	((uint32_t)0x008C)
#define	EPR_All_PF2                 	((uint32_t)0x0090)
#define	EPR_PhaseAngle_U           		((uint32_t)0x009C)
#define	EPR_PhaseAngle_I1           	((uint32_t)0x00A8)
#define	EPR_PhaseAngle_I2           	((uint32_t)0x00AC)
#define	EPR_All_EnergyPos_P1        	((uint32_t)0x00B8)
#define	EPR_All_EnergyPos_P2        	((uint32_t)0x00BC)
#define	EPR_All_EnergyPos_Pt        	((uint32_t)0x00C4)
#define	EPR_All_EnergyPos_Q1        	((uint32_t)0x00C8)
#define	EPR_All_EnergyPos_Q2        	((uint32_t)0x00CC)
#define	EPR_All_EnergyPos_Qt        	((uint32_t)0x00D4)
#define	EPR_Energy_S1               	((uint32_t)0x00D8)
#define	EPR_Energy_S2               	((uint32_t)0x00DC)
#define	EPR_Energy_St               	((uint32_t)0x00E4)
#define	EPR_All_CFCntPos_P1         	((uint32_t)0x00E8)
#define	EPR_All_CFCntPos_P2         	((uint32_t)0x00EC)
#define	EPR_All_CFCntPos_Pt         	((uint32_t)0x00F4)
#define	EPR_All_CFCntPos_Q1         	((uint32_t)0x00F8)
#define	EPR_All_CFCntPos_Q2         	((uint32_t)0x00FC)
#define	EPR_All_CFCntPos_Qt         	((uint32_t)0x0104)
#define	EPR_CFCntPos_S1             	((uint32_t)0x0108)
#define	EPR_CFCntPos_S2             	((uint32_t)0x010C)
#define	EPR_CFCntPos_St             	((uint32_t)0x0114)
#define	EPR_All_EnergyNeg_P1        	((uint32_t)0x0118)
#define	EPR_All_EnergyNeg_P2        	((uint32_t)0x011C)
#define	EPR_All_EnergyNeg_Pt        	((uint32_t)0x0124)
#define	EPR_All_EnergyNeg_Q1        	((uint32_t)0x0128)
#define	EPR_All_EnergyNeg_Q2        	((uint32_t)0x012C)
#define	EPR_All_EnergyNeg_Qt        	((uint32_t)0x0134)
#define	EPR_All_CFCntNeg_P1         	((uint32_t)0x0138)
#define	EPR_All_CFCntNeg_P2         	((uint32_t)0x013C)
#define	EPR_All_CFCntNeg_Pt         	((uint32_t)0x0144)
#define	EPR_All_CFCntNeg_Q1         	((uint32_t)0x0148)
#define	EPR_All_CFCntNeg_Q2         	((uint32_t)0x014C)
#define	EPR_All_CFCntNeg_Qt         	((uint32_t)0x0154)
#define	EPR_EnergyNeg_S1Const       	((uint32_t)0x0158)
#define	EPR_EnergyNeg_S2Const       	((uint32_t)0x015C)
#define	EPR_EnergyNeg_StConst       	((uint32_t)0x0164)
#define	EPR_CFCntNeg_S1             	((uint32_t)0x0168)
#define	EPR_CFCntNeg_S2             	((uint32_t)0x016C)
#define	EPR_CFCntNeg_St             	((uint32_t)0x0174)
#define	EPR_Fund_Power_P1           	((uint32_t)0x0178)
#define	EPR_Fund_Power_P2           	((uint32_t)0x017C)
#define	EPR_Fund_Power_Pt           	((uint32_t)0x0184)
#define	EPR_Fund_Power_Q1           	((uint32_t)0x0188)
#define	EPR_Fund_Power_Q2           	((uint32_t)0x018C)
#define	EPR_Fund_Power_Qt           	((uint32_t)0x0194)
#define	EPR_Fund_Power_S1           	((uint32_t)0x0198)
#define	EPR_Fund_Power_S2           	((uint32_t)0x019C)
#define	EPR_Fund_Power_St           	((uint32_t)0x01A4)
#define	EPR_Fund_RMS_U             		((uint32_t)0x01A8)
#define	EPR_Fund_RMS_I1             	((uint32_t)0x01B4)
#define	EPR_Fund_RMS_I2             	((uint32_t)0x01B8)
#define	EPR_Fund_PF1                	((uint32_t)0x01C4)
#define	EPR_Fund_PF2                	((uint32_t)0x01C8)
#define	EPR_Fund_EnergyPos_P1       	((uint32_t)0x01D4)
#define	EPR_Fund_EnergyPos_P2       	((uint32_t)0x01D8)
#define	EPR_Fund_EnergyPos_Pt       	((uint32_t)0x01E0)
#define	EPR_Fund_EnergyPos_Q1       	((uint32_t)0x01E4)
#define	EPR_Fund_EnergyPos_Q2       	((uint32_t)0x01E8)
#define	EPR_Fund_EnergyPos_Qt       	((uint32_t)0x01F0)
#define	EPR_Fund_CFCntPos_P1        	((uint32_t)0x01F4)
#define	EPR_Fund_CFCntPos_P2        	((uint32_t)0x01F8)
#define	EPR_Fund_CFCntPos_Pt        	((uint32_t)0x0200)
#define	EPR_Fund_CFCntPos_Q1        	((uint32_t)0x0204)
#define	EPR_Fund_CFCntPos_Q2        	((uint32_t)0x0208)
#define	EPR_Fund_CFCntPos_Qt        	((uint32_t)0x0210)
#define	EPR_Fund_EnergyNeg_P1       	((uint32_t)0x0214)
#define	EPR_Fund_EnergyNeg_P2       	((uint32_t)0x0218)
#define	EPR_Fund_EnergyNeg_Pt       	((uint32_t)0x0220)
#define	EPR_Fund_EnergyNeg_Q1       	((uint32_t)0x0224)
#define	EPR_Fund_EnergyNeg_Q2       	((uint32_t)0x0228)
#define	EPR_Fund_EnergyNeg_Qt       	((uint32_t)0x0230)
#define	EPR_Fund_CFCntNeg_P1        	((uint32_t)0x0234)
#define	EPR_Fund_CFCntNeg_P2        	((uint32_t)0x0238)
#define	EPR_Fund_CFCntNeg_Pt        	((uint32_t)0x0240)
#define	EPR_Fund_CFCntNeg_Q1        	((uint32_t)0x0244)
#define	EPR_Fund_CFCntNeg_Q2        	((uint32_t)0x0248)
#define	EPR_Fund_CFCntNeg_Qt        	((uint32_t)0x0250)
#define	EPR_Har_Power_P1            	((uint32_t)0x0254)
#define	EPR_Har_Power_P2            	((uint32_t)0x0258)
#define	EPR_Har_Power_Pt            	((uint32_t)0x0260)
#define	EPR_Har_RMS_U              		((uint32_t)0x0264)
#define	EPR_Har_RMS_I1              	((uint32_t)0x0270)
#define	EPR_Har_RMS_I2              	((uint32_t)0x0274)
#define	EPR_Har_EnergyPos_P1        	((uint32_t)0x0280)
#define	EPR_Har_EnergyPos_P2        	((uint32_t)0x0284)
#define	EPR_Har_EnergyPos_Pt        	((uint32_t)0x028C)
#define	EPR_Har_CFCntPos_P1         	((uint32_t)0x0290)
#define	EPR_Har_CFCntPos_P2         	((uint32_t)0x0294)
#define	EPR_Har_CFCntPos_Pt         	((uint32_t)0x029C)
#define	EPR_Har_EnergyNeg_P1        	((uint32_t)0x02A0)
#define	EPR_Har_EnergyNeg_P2        	((uint32_t)0x02A4)
#define	EPR_Har_EnergyNeg_Pt        	((uint32_t)0x02AC)
#define	EPR_Har_CFCntNeg_P1         	((uint32_t)0x02B0)
#define	EPR_Har_CFCntNeg_P2         	((uint32_t)0x02B4)
#define	EPR_Har_CFCntNeg_Pt         	((uint32_t)0x02BC)
#define	EPR_DCVar_U                		((uint32_t)0x02C0)
#define	EPR_DCVar_I1                	((uint32_t)0x02CC)
#define	EPR_DCVar_I2                	((uint32_t)0x02D0)
#define	EPR_UpdHalfWave_U          		((uint32_t)0x02DC)
#define	EPR_UpdHalfWave_I1          	((uint32_t)0x02E8)
#define	EPR_UpdHalfWave_I2          	((uint32_t)0x02EC)
#define	EPR_QuartRmsIns_U          		((uint32_t)0x02F8)
#define	EPR_QuartRmsIns_I1          	((uint32_t)0x0304)
#define	EPR_QuartRmsIns_I2          	((uint32_t)0x0308)
#define	EPR_PeakVpU                		((uint32_t)0x0314)
#define	EPR_PeakCntU               		((uint32_t)0x0320)
#define	EPR_SagVpU                 		((uint32_t)0x032C)
#define	EPR_SagCntU                		((uint32_t)0x0338)
#define	EPR_IntVpU                 		((uint32_t)0x0344)
#define	EPR_IntCntU                		((uint32_t)0x0350)
#define	EPR_OverFlowVpI1            	((uint32_t)0x035C)
#define	EPR_OverFlowVpI2            	((uint32_t)0x0360)
#define	EPR_OverFlowCntI1           	((uint32_t)0x036C)
#define	EPR_OverFlowCntI2           	((uint32_t)0x0370)
#endif
#define	EPR_AutoTgain_U             	((uint32_t)0x037C)
#define	EPR_AutoTgain_I             	((uint32_t)0x0380)
#if defined  HT762x 
#define	EPR_AutoTgain_In            	((uint32_t)0x0384)
#define	EPR_HpRMS_Reg_Ua            	((uint32_t)0x0388)
#define	EPR_HpRMS_Reg_Ub            	((uint32_t)0x038C)
#define	EPR_HpRMS_Reg_Uc            	((uint32_t)0x0390)
#define	EPR_HpRMS_Reg_Ia            	((uint32_t)0x0394)
#define	EPR_HpRMS_Reg_Ib            	((uint32_t)0x0398)
#define	EPR_HpRMS_Reg_Ic            	((uint32_t)0x039C)
#define	EPR_HpRMS_Reg_In            	((uint32_t)0x03A0)
#define	EPR_DFT_Value_UaReal        	((uint32_t)0x03A4)
#define	EPR_DFT_Value_UaImage       	((uint32_t)0x03A8)
#define	EPR_DFT_Value_UbReal        	((uint32_t)0x03AC)
#define	EPR_DFT_Value_UbImage       	((uint32_t)0x03B0)
#define	EPR_DFT_Value_UcReal        	((uint32_t)0x03B4)
#define	EPR_DFT_Value_UcImage       	((uint32_t)0x03B8)
#define	EPR_DFT_Value_IaReal        	((uint32_t)0x03BC)
#define	EPR_DFT_Value_IaImage       	((uint32_t)0x03C0)
#define	EPR_DFT_Value_IbReal        	((uint32_t)0x03C4)
#define	EPR_DFT_Value_IbImage       	((uint32_t)0x03C8)
#define	EPR_DFT_Value_IcReal        	((uint32_t)0x03CC)
#define	EPR_DFT_Value_IcImage       	((uint32_t)0x03D0)
#define	EPR_DFT_Value_InReal        	((uint32_t)0x03D4)
#define	EPR_DFT_Value_InImage       	((uint32_t)0x03D8)

#define	EPR_FlickerUaPinst          	((uint32_t)0x03E4)
#define	EPR_FlickerUbPinst          	((uint32_t)0x03E8)
#define	EPR_FlickerUcPinst          	((uint32_t)0x03EC)
#else
#define	EPR_HpRMS_Reg_U	            	((uint32_t)0x0388)
#define	EPR_HpRMS_Reg_I1            	((uint32_t)0x0394)
#define	EPR_HpRMS_Reg_I2            	((uint32_t)0x0398)
#define	EPR_DFT_Value_UReal       	 	((uint32_t)0x03A4)
#define	EPR_DFT_Value_UImage       		((uint32_t)0x03A8)
#define	EPR_DFT_Value_I1Real        	((uint32_t)0x03BC)
#define	EPR_DFT_Value_I1Image       	((uint32_t)0x03C0)
#define	EPR_DFT_Value_I2Real        	((uint32_t)0x03C4)
#define	EPR_DFT_Value_I2Image       	((uint32_t)0x03C8)
#define	EPR_FlickerUPinst          		((uint32_t)0x03E4)
#endif
#define	EPR_Checksum1               	((uint32_t)0x03F0)
#define	EPR_Checksum2               	((uint32_t)0x03F4)
#define	EPR_Checksum3               	((uint32_t)0x03F8)
#define	EPR_Noload                  	((uint32_t)0x0400)
#define	EPR_REV_Power               	((uint32_t)0x0404)
#define	EPR_REV_Energy              	((uint32_t)0x0408)
#define	EPR_P90_Power               	((uint32_t)0x040C)
#define	EPR_SignalStatus            	((uint32_t)0x0410)
#define	EPR_PeakSagIntIovStau       	((uint32_t)0x0414)
    
/****ECR register offset address,base address: 0x4001C000, (write & read enable )*****************/
#if defined  HT762x 
#define   ECR_DecShift_UaH                          ((uint32_t)0x0000)
#define   ECR_DecShift_UaL                          ((uint32_t)0x0004)
#define   ECR_DecShift_UbH                          ((uint32_t)0x0008)
#define   ECR_DecShift_UbL                          ((uint32_t)0x000C)
#define   ECR_DecShift_UcH                          ((uint32_t)0x0010)
#define   ECR_DecShift_UcL                          ((uint32_t)0x0014)
#define   ECR_DecShift_IaH                          ((uint32_t)0x0018)
#define   ECR_DecShift_IaL                          ((uint32_t)0x001C)
#define   ECR_DecShift_IbH                          ((uint32_t)0x0020)
#define   ECR_DecShift_IbL                          ((uint32_t)0x0024)
#define   ECR_DecShift_IcH                          ((uint32_t)0x0028)
#define   ECR_DecShift_IcL                          ((uint32_t)0x002C)
#define   ECR_DecShift_InH                          ((uint32_t)0x0030)
#define   ECR_DecShift_InL                          ((uint32_t)0x0034)
#define   ECR_ADCOffset_Ua                          ((uint32_t)0x0038)
#define   ECR_ADCOffset_Ub                          ((uint32_t)0x003C)
#define   ECR_ADCOffset_Uc                          ((uint32_t)0x0040)
#define   ECR_ADCOffset_Ia                          ((uint32_t)0x0044)
#define   ECR_ADCOffset_Ib                          ((uint32_t)0x0048)
#define   ECR_ADCOffset_Ic                          ((uint32_t)0x004C)
#define   ECR_ADCOffset_In                          ((uint32_t)0x0050)
#define   ECR_Tgain_U                               ((uint32_t)0x0054)
#define   ECR_Tgain_I                               ((uint32_t)0x0058)
#define   ECR_Tgain_In                              ((uint32_t)0x005C)
#define   ECR_Gain_Ua                               ((uint32_t)0x0060)
#define   ECR_Gain_Ub                               ((uint32_t)0x0064)
#define   ECR_Gain_Uc                               ((uint32_t)0x0068)
#define   ECR_Gain_Ia                               ((uint32_t)0x006C)
#define   ECR_Gain_Ib                               ((uint32_t)0x0070)
#define   ECR_Gain_Ic                               ((uint32_t)0x0074)
#define   ECR_Gain_In                               ((uint32_t)0x0078)
#define   ECR_Digtal_gain                           ((uint32_t)0x007C)
#define   ECR_All_GPa                               ((uint32_t)0x0080)
#define   ECR_All_GPb                               ((uint32_t)0x0084)
#define   ECR_All_GPc                               ((uint32_t)0x0088)
#define   ECR_All_GQa                               ((uint32_t)0x008C)
#define   ECR_All_GQb                               ((uint32_t)0x0090)
#define   ECR_All_GQc                               ((uint32_t)0x0094)
#define   ECR_All_GSa                               ((uint32_t)0x0098)
#define   ECR_All_GSb                               ((uint32_t)0x009C)
#define   ECR_All_GSc                               ((uint32_t)0x00A0)
#define   ECR_All_GphsA0                            ((uint32_t)0x00A4)
#define   ECR_All_GphsA1                            ((uint32_t)0x00A8)
#define   ECR_All_GphsA2                            ((uint32_t)0x00AC)
#define   ECR_All_GphsB0                            ((uint32_t)0x00B0)
#define   ECR_All_GphsB1                            ((uint32_t)0x00B4)
#define   ECR_All_GphsB2                            ((uint32_t)0x00B8)
#define   ECR_All_GphsC0                            ((uint32_t)0x00BC)
#define   ECR_All_GphsC1                            ((uint32_t)0x00C0)
#define   ECR_All_GphsC2                            ((uint32_t)0x00C4)
#define   ECR_All_PowerOffset_Pa                    ((uint32_t)0x00CC)
#define   ECR_All_PowerOffset_Pb                    ((uint32_t)0x00D0)
#define   ECR_All_PowerOffset_Pc                    ((uint32_t)0x00D4)
#define   ECR_All_PowerOffset_Qa                    ((uint32_t)0x00D8)
#define   ECR_All_PowerOffset_Qb                    ((uint32_t)0x00DC)
#define   ECR_All_PowerOffset_Qc                    ((uint32_t)0x00E0)
#define   ECR_All_RmsOffset_Ua                      ((uint32_t)0x00E4)
#define   ECR_All_RmsOffset_Ub                      ((uint32_t)0x00E8)
#define   ECR_All_RmsOffset_Uc                      ((uint32_t)0x00EC)
#define   ECR_All_RmsOffset_Ia                      ((uint32_t)0x00F0)
#define   ECR_All_RmsOffset_Ib                      ((uint32_t)0x00F4)
#define   ECR_All_RmsOffset_Ic                      ((uint32_t)0x00F8)
#define   ECR_All_RmsOffset_In                      ((uint32_t)0x00FC)
#define   ECR_RMSOffset_Ut                          ((uint32_t)0x0100)
#define   ECR_RMSOffset_It                          ((uint32_t)0x0104)
#define   ECR_Fund_GPa                              ((uint32_t)0x0110)
#define   ECR_Fund_GPb                              ((uint32_t)0x0114)
#define   ECR_Fund_GPc                              ((uint32_t)0x0118)
#define   ECR_Fund_GQa                              ((uint32_t)0x011C)
#define   ECR_Fund_GQb                              ((uint32_t)0x0120)
#define   ECR_Fund_GQc                              ((uint32_t)0x0124)
#define   ECR_Fund_GSa                              ((uint32_t)0x0128)
#define   ECR_Fund_GSb                              ((uint32_t)0x012C)
#define   ECR_Fund_GSc                              ((uint32_t)0x0130)
#define   ECR_Fund_GphsA0                           ((uint32_t)0x0134)
#define   ECR_Fund_GphsA1                           ((uint32_t)0x0138)
#define   ECR_Fund_GphsA2                           ((uint32_t)0x013C)
#define   ECR_Fund_GphsB0                           ((uint32_t)0x0140)
#define   ECR_Fund_GphsB1                           ((uint32_t)0x0144)
#define   ECR_Fund_GphsB2                           ((uint32_t)0x0148)
#define   ECR_Fund_GphsC0                           ((uint32_t)0x014C)
#define   ECR_Fund_GphsC1                           ((uint32_t)0x0150)
#define   ECR_Fund_GphsC2                           ((uint32_t)0x0154)
#define   ECR_Fund_PowerOffset_Pa                   ((uint32_t)0x015C)
#define   ECR_Fund_PowerOffset_Pb                   ((uint32_t)0x0160)
#define   ECR_Fund_PowerOffset_Pc                   ((uint32_t)0x0164)
#define   ECR_Fund_PowerOffset_Qa                   ((uint32_t)0x0168)
#define   ECR_Fund_PowerOffset_Qb                   ((uint32_t)0x016C)
#define   ECR_Fund_PowerOffset_Qc                   ((uint32_t)0x0170)
#define   ECR_Fund_RmsOffset_Ua                     ((uint32_t)0x0174)
#define   ECR_Fund_RmsOffset_Ub                     ((uint32_t)0x0178)
#define   ECR_Fund_RmsOffset_Uc                     ((uint32_t)0x017C)
#define   ECR_Fund_RmsOffset_Ia                     ((uint32_t)0x0180)
#define   ECR_Fund_RmsOffset_Ib                     ((uint32_t)0x0184)
#define   ECR_Fund_RmsOffset_Ic                     ((uint32_t)0x0188)
#define   ECR_Fund_RmsOffset_In                     ((uint32_t)0x018C)
#define   ECR_Har_GPa                               ((uint32_t)0x0190)
#define   ECR_Har_GPb                               ((uint32_t)0x0194)
#define   ECR_Har_GPc                               ((uint32_t)0x0198)
#define   ECR_Har_PowerOffset_Pa                    ((uint32_t)0x019C)
#define   ECR_Har_PowerOffset_Pb                    ((uint32_t)0x01A0)
#define   ECR_Har_PowerOffset_Pc                    ((uint32_t)0x01A4)
#define   ECR_Har_RmsOffset_Ua                      ((uint32_t)0x01A8)
#define   ECR_Har_RmsOffset_Ub                      ((uint32_t)0x01AC)
#define   ECR_Har_RmsOffset_Uc                      ((uint32_t)0x01B0)
#define   ECR_Har_RmsOffset_Ia                      ((uint32_t)0x01B4)
#define   ECR_Har_RmsOffset_Ib                      ((uint32_t)0x01B8)
#define   ECR_Har_RmsOffset_Ic                      ((uint32_t)0x01BC)
#define   ECR_Har_RmsOffset_In                      ((uint32_t)0x01C0)
#define   ECR_PowerConst_All_Pa                     ((uint32_t)0x01C4)
#define   ECR_PowerConst_All_Pb                     ((uint32_t)0x01C8)
#define   ECR_PowerConst_All_Pc                     ((uint32_t)0x01CC)
#define   ECR_PowerConst_All_Pt                     ((uint32_t)0x01D0)
#define   ECR_PowerConst_All_Qa                     ((uint32_t)0x01D4)
#define   ECR_PowerConst_All_Qb                     ((uint32_t)0x01D8)
#define   ECR_PowerConst_All_Qc                     ((uint32_t)0x01DC)
#define   ECR_PowerConst_All_Qt                     ((uint32_t)0x01E0)
#define   ECR_PowerConst_Sa                         ((uint32_t)0x01E4)
#define   ECR_PowerConst_Sb                         ((uint32_t)0x01E8)
#define   ECR_PowerConst_Sc                         ((uint32_t)0x01EC)
#define   ECR_PowerConst_St                         ((uint32_t)0x01F0)
#define   ECR_PowerConst_Fund_Pa                    ((uint32_t)0x01F4)
#define   ECR_PowerConst_Fund_Pb                    ((uint32_t)0x01F8)
#define   ECR_PowerConst_Fund_Pc                    ((uint32_t)0x01FC)
#define   ECR_PowerConst_Fund_Pt                    ((uint32_t)0x0200)
#define   ECR_PowerConst_Fund_Qa                    ((uint32_t)0x0204)
#define   ECR_PowerConst_Fund_Qb                    ((uint32_t)0x0208)
#define   ECR_PowerConst_Fund_Qc                    ((uint32_t)0x020C)
#define   ECR_PowerConst_Fund_Qt                    ((uint32_t)0x0210)
#define   ECR_PowerConst_Har_Pa                     ((uint32_t)0x0214)
#define   ECR_PowerConst_Har_Pb                     ((uint32_t)0x0218)
#define   ECR_PowerConst_Har_Pc                     ((uint32_t)0x021C)
#define   ECR_PowerConst_Har_Pt                     ((uint32_t)0x0220)
#define   ECR_AccuOffset_Har_Pa_Pos                 ((uint32_t)0x0224)
#define   ECR_AccuOffset_Har_Pa_Neg                 ((uint32_t)0x0228)
#define   ECR_AccuOffset_Har_Pb_Pos                 ((uint32_t)0x022C)
#define   ECR_AccuOffset_Har_Pb_Neg                 ((uint32_t)0x0230)
#define   ECR_AccuOffset_Har_Pc_Pos                 ((uint32_t)0x0234)
#define   ECR_AccuOffset_Har_Pc_Neg                 ((uint32_t)0x0238)
#define   ECR_AccuOffset_Har_Pt_Pos                 ((uint32_t)0x023C)
#define   ECR_AccuOffset_Har_Pt_Neg                 ((uint32_t)0x0240)
#define   ECR_UconstA                               ((uint32_t)0x0244)
#define   ECR_UconstB                               ((uint32_t)0x0248)
#define   ECR_UconstC                               ((uint32_t)0x024C)
#else
#define   ECR_DecShift_UH                           ((uint32_t)0x0000)
#define   ECR_DecShift_UL                           ((uint32_t)0x0004)
#define   ECR_DecShift_UH_BAK                       ((uint32_t)0x0008)
#define   ECR_DecShift_UL_BAK                       ((uint32_t)0x000C)
#define   ECR_DecShift_I1H                          ((uint32_t)0x0018)
#define   ECR_DecShift_I1L                          ((uint32_t)0x001C)
#define   ECR_DecShift_I2H                          ((uint32_t)0x0020)
#define   ECR_DecShift_I2L                          ((uint32_t)0x0024)
#define   ECR_ADCOffset_U                           ((uint32_t)0x0038)
#define   ECR_ADCOffset_U_BAK                       ((uint32_t)0x003C)
#define   ECR_ADCOffset_I1                          ((uint32_t)0x0044)
#define   ECR_ADCOffset_I2                          ((uint32_t)0x0048)
#define   ECR_Tgain_U                               ((uint32_t)0x0054)
#define   ECR_Tgain_I                               ((uint32_t)0x0058)
#define   ECR_Gain_U                                ((uint32_t)0x0060)
#define   ECR_Gain_U_BAK                            ((uint32_t)0x0064)
#define   ECR_Gain_I1                               ((uint32_t)0x006C)
#define   ECR_Gain_I2                               ((uint32_t)0x0070)
#define   ECR_Digtal_gain                           ((uint32_t)0x007C)
#define   ECR_All_GP1                               ((uint32_t)0x0080)
#define   ECR_All_GP2                               ((uint32_t)0x0084)
#define   ECR_All_GQ1                               ((uint32_t)0x008C)
#define   ECR_All_GQ2                               ((uint32_t)0x0090)
#define   ECR_All_GS1                               ((uint32_t)0x0098)
#define   ECR_All_GS2                               ((uint32_t)0x009C)
#define   ECR_All_Gphs10                            ((uint32_t)0x00A4)
#define   ECR_All_Gphs11                            ((uint32_t)0x00A8)
#define   ECR_All_Gphs12                            ((uint32_t)0x00AC)
#define   ECR_All_Gphs20                            ((uint32_t)0x00B0)
#define   ECR_All_Gphs21                            ((uint32_t)0x00B4)
#define   ECR_All_Gphs22                            ((uint32_t)0x00B8)
#define   ECR_All_PowerOffset_P1                    ((uint32_t)0x00CC)
#define   ECR_All_PowerOffset_P2                    ((uint32_t)0x00D0)
#define   ECR_All_PowerOffset_Q1                    ((uint32_t)0x00D8)
#define   ECR_All_PowerOffset_Q2                    ((uint32_t)0x00DC)
#define   ECR_All_RmsOffset_U                       ((uint32_t)0x00E4)
#define   ECR_All_RmsOffset_I1                      ((uint32_t)0x00F0)
#define   ECR_All_RmsOffset_I2                      ((uint32_t)0x00F4)
#define   ECR_RMSOffset_It                          ((uint32_t)0x0104)
#define   ECR_Fund_GP1                              ((uint32_t)0x0110)
#define   ECR_Fund_GP2                              ((uint32_t)0x0114)
#define   ECR_Fund_GQ1                              ((uint32_t)0x011C)
#define   ECR_Fund_GQ2                              ((uint32_t)0x0120)
#define   ECR_Fund_GS1                              ((uint32_t)0x0128)
#define   ECR_Fund_GS2                              ((uint32_t)0x012C)
#define   ECR_Fund_Gphs10                           ((uint32_t)0x0134)
#define   ECR_Fund_Gphs11                           ((uint32_t)0x0138)
#define   ECR_Fund_Gphs12                           ((uint32_t)0x013C)
#define   ECR_Fund_Gphs20                           ((uint32_t)0x0140)
#define   ECR_Fund_Gphs21                           ((uint32_t)0x0144)
#define   ECR_Fund_Gphs22                           ((uint32_t)0x0148)
#define   ECR_Fund_PowerOffset_P1                   ((uint32_t)0x015C)
#define   ECR_Fund_PowerOffset_P2                   ((uint32_t)0x0160)
#define   ECR_Fund_PowerOffset_Q1                   ((uint32_t)0x0168)
#define   ECR_Fund_PowerOffset_Q2                   ((uint32_t)0x016C)
#define   ECR_Fund_RmsOffset_U                      ((uint32_t)0x0174)
#define   ECR_Fund_RmsOffset_I1                     ((uint32_t)0x0180)
#define   ECR_Fund_RmsOffset_I2                     ((uint32_t)0x0184)
#define   ECR_Har_GP1                               ((uint32_t)0x0190)
#define   ECR_Har_GP2                               ((uint32_t)0x0194)
#define   ECR_Har_PowerOffset_P1                    ((uint32_t)0x019C)
#define   ECR_Har_PowerOffset_P2                    ((uint32_t)0x01A0)
#define   ECR_Har_RmsOffset_U                       ((uint32_t)0x01A8)
#define   ECR_Har_RmsOffset_I1                      ((uint32_t)0x01B4)
#define   ECR_Har_RmsOffset_I2                      ((uint32_t)0x01B8)
#define   ECR_PowerConst_All_P1                     ((uint32_t)0x01C4)
#define   ECR_PowerConst_All_P2                     ((uint32_t)0x01C8)
#define   ECR_PowerConst_All_Pt                     ((uint32_t)0x01D0)
#define   ECR_PowerConst_All_Q1                     ((uint32_t)0x01D4)
#define   ECR_PowerConst_All_Q2                     ((uint32_t)0x01D8)
#define   ECR_PowerConst_All_Qt                     ((uint32_t)0x01E0)
#define   ECR_PowerConst_S1                         ((uint32_t)0x01E4)
#define   ECR_PowerConst_S2                         ((uint32_t)0x01E8)
#define   ECR_PowerConst_St                         ((uint32_t)0x01F0)
#define   ECR_PowerConst_Fund_P1                    ((uint32_t)0x01F4)
#define   ECR_PowerConst_Fund_P2                    ((uint32_t)0x01F8)
#define   ECR_PowerConst_Fund_Pt                    ((uint32_t)0x0200)
#define   ECR_PowerConst_Fund_Q1                    ((uint32_t)0x0204)
#define   ECR_PowerConst_Fund_Q2                    ((uint32_t)0x0208)
#define   ECR_PowerConst_Fund_Qt                    ((uint32_t)0x0210)
#define   ECR_PowerConst_Har_P1                     ((uint32_t)0x0214)
#define   ECR_PowerConst_Har_P2                     ((uint32_t)0x0218)
#define   ECR_PowerConst_Har_Pt                     ((uint32_t)0x0220)
#define   ECR_AccuOffset_Har_P1_Pos                 ((uint32_t)0x0224)
#define   ECR_AccuOffset_Har_P1_Neg                 ((uint32_t)0x0228)
#define   ECR_AccuOffset_Har_P2_Pos                 ((uint32_t)0x022C)
#define   ECR_AccuOffset_Har_P2_Neg                 ((uint32_t)0x0230)
#define   ECR_AccuOffset_Har_Pt_Pos                 ((uint32_t)0x023C)
#define   ECR_AccuOffset_Har_Pt_Neg                 ((uint32_t)0x0240)
#define   ECR_Uconst                                ((uint32_t)0x0244)
#define   ECR_Uconst_BAK                            ((uint32_t)0x0248)
#endif
#define   ECR_ZXLostCFG                             ((uint32_t)0x0250)
#define   ECR_PStart                                ((uint32_t)0x0254)
#define   ECR_QStart                                ((uint32_t)0x0258)
#define   ECR_HarStart                              ((uint32_t)0x025C)
#define   ECR_AVG_Energy                            ((uint32_t)0x0260)
#define   ECR_AVG_PowerREG                          ((uint32_t)0x0264)
#define   ECR_AVG_RMS                               ((uint32_t)0x0268)
#define   ECR_AVG_RMST                              ((uint32_t)0x026C)
#define   ECR_HFConstAF                             ((uint32_t)0x0270)
#define   ECR_HFConstHar                            ((uint32_t)0x0274)
#define   ECR_AFDIV                                 ((uint32_t)0x0278)
#define   ECR_HarDIV                                ((uint32_t)0x027C)
#define   ECR_ChannelSel                            ((uint32_t)0x0280)
#define   ECR_PGACON                                ((uint32_t)0x0284)
#define   ECR_ADCCFG                                ((uint32_t)0x0288)
#define   ECR_ADCCON                                ((uint32_t)0x028C)
#define   ECR_EMUCFG                                ((uint32_t)0x0290)
#define   ECR_FilterCon                             ((uint32_t)0x0294)
#define   ECR_FilterCFG                             ((uint32_t)0x0298)
#define   ECR_StartCFG                              ((uint32_t)0x029C)
#define   ECR_ANACFG1                               ((uint32_t)0x02A0)
#define   ECR_ANACFG2                               ((uint32_t)0x02A4)
#if defined  HT762x 
#define   ECR_ULostCMPCFG                           ((uint32_t)0x02AC)
#define   ECR_ULostPRDCFG                           ((uint32_t)0x02B0)
#endif
#define   ECR_FailVoltage                           ((uint32_t)0x02B4)
#define   ECR_LPModeCON                             ((uint32_t)0x02B8)
#define   ECR_CFxRun                                ((uint32_t)0x02BC)
#define   ECR_EnergyCon                             ((uint32_t)0x02C0)
#define   ECR_PowerSrcCFG1                          ((uint32_t)0x02C4)
#define   ECR_PowerSrcCFG2                          ((uint32_t)0x02C8)
#define   ECR_PowerModeCFG                          ((uint32_t)0x02CC)
#define   ECR_CFCFG1                                ((uint32_t)0x02D0)
#define   ECR_CFCFG2                                ((uint32_t)0x02D4)
#define   ECR_PowerConstLoad                        ((uint32_t)0x02E0)
#define   ECR_UPeakSagCyc                           ((uint32_t)0x02E4)
#define   ECR_UIntCyc                               ((uint32_t)0x02E8)
#define   ECR_IOVCyc                                ((uint32_t)0x02EC)
#define   ECR_PeakLVL                               ((uint32_t)0x02F0)
#define   ECR_SagLVL                                ((uint32_t)0x02F4)
#define   ECR_IntLVL                                ((uint32_t)0x02F8)
#define   ECR_IOVLVL                                ((uint32_t)0x02FC)
#define   ECR_PeakLVLHys                            ((uint32_t)0x0300)
#define   ECR_SagLVLHys                             ((uint32_t)0x0304)
#define   ECR_IntLVLHys                             ((uint32_t)0x0308)
#define   ECR_IOVLVLHys                             ((uint32_t)0x030C)
#define   ECR_UZCLVL                                ((uint32_t)0x0310)
#define   ECR_IZCLVL                                ((uint32_t)0x0314)
#define   ECR_TU_CCOFF_A                            ((uint32_t)0x0318)
#define   ECR_TU_CCOFF_B                            ((uint32_t)0x031C)
#define   ECR_TU_CCOFF_C                            ((uint32_t)0x0320)
#define   ECR_TI_CCOFF_A                            ((uint32_t)0x0324)
#define   ECR_TI_CCOFF_B                            ((uint32_t)0x0328)
#define   ECR_TI_CCOFF_C                            ((uint32_t)0x032C)
#if defined  HT762x 
#define   ECR_TIn_CCOFF_A                           ((uint32_t)0x0330)
#define   ECR_TIn_CCOFF_B                           ((uint32_t)0x0334)
#define   ECR_TIn_CCOFF_C                           ((uint32_t)0x0338)
#endif
#define   ECR_Iregion0                              ((uint32_t)0x033C)
#define   ECR_Iregion1                              ((uint32_t)0x0340)
#define   ECR_Iregion0Hys                           ((uint32_t)0x0344)
#define   ECR_Iregion1Hys                           ((uint32_t)0x0348)
#define   ECR_DECReset                              ((uint32_t)0x034C)
#define   ECR_EMUWPREG                              ((uint32_t)0x0350)
#define   ECR_SRSTREG                               ((uint32_t)0x0354)
#define   ECR_FlickerCfg                            ((uint32_t)0x0358)
#define   ECR_FlickerReset                          ((uint32_t)0x0368)
#if defined  HT762x 
#define   ECR_RMSUt_THO                             ((uint32_t)0x036C)
#endif
#define   ECR_RMSIt_THO                             ((uint32_t)0x0370)
#define   ECR_EMUIE1                                ((uint32_t)0x0380)
#define   ECR_EMUIE2                                ((uint32_t)0x0384)
#define   ECR_EMUIF1                                ((uint32_t)0x0388)
#define   ECR_EMUIF2                                ((uint32_t)0x038C)
#define   ECR_EMUIF_EnergyPOVIF                     ((uint32_t)0x0390)
#define   ECR_EMUIF_EnergyNOVIF                     ((uint32_t)0x0394)

#define   ECR_FundHarCFG                            ((uint32_t)0x071C)

#define   ECR_EWUIE                                 ((uint32_t)0x0A00)
#define   ECR_EWUIF                                 ((uint32_t)0x0A04)

#define   ECR_SYNC_CFG                              ((uint32_t)0x0C00)
#define   ECR_SFO_Value                             ((uint32_t)0x0C04)
#define   ECR_REC_CFG                               ((uint32_t)0x0C08)
#define   ECR_DFT_CFG                               ((uint32_t)0x0C0C)
#define   ECR_SYNC_DMA_rShift                       ((uint32_t)0x0C10)
#define   ECR_HpRMS_Ctl_U                           ((uint32_t)0x0C14)
#define   ECR_HpRMS_Ctl_I                           ((uint32_t)0x0C18)

#define   ECR_PLL_CTRL                              ((uint32_t)0x0E00)
#define   ECR_PLL_Gain                              ((uint32_t)0x0E04)
#define   ECR_PLL_Acc                               ((uint32_t)0x0E08)
#define   ECR_SFO_EST                               ((uint32_t)0x0E0C)
#define   ECR_Lock_THO                              ((uint32_t)0x0E10)
#define   ECR_AMP_THO                               ((uint32_t)0x0E14)
#define   ECR_TED_Amnt                              ((uint32_t)0x0E18)

/**************************************************************************
*                         BIT  DEFINE
***************************************************************************/

#define   ECR_EMU_PowerConst_Load      ((uint32_t)0xBC)
#define   ECR_EMU_Flicker_Reset        ((uint32_t)0x69)
#define   ECR_EMU_CReg_Reset           ((uint32_t)0x55)
#define   ECR_EMU_Moudle_Reset         ((uint32_t)0xAA)
#define   ECR_EMU_DEC_Reset            ((uint32_t)0x6A)

#define   ECR_EMU_HFConst_LLimit       ((uint32_t)0x00000002)
#define   ECR_EMU_AFDIV_LLimit         ((uint32_t)0x00000001)
#define   ECR_EMU_AVGNUM_HLimit        ((uint32_t)0x00002C88)
#define   ECR_EMU_AVGNUM_LLimit        ((uint32_t)0x0000002d)

#define   ECR_EMU_DecShiftH_HLimit     ((uint32_t)0x00000009)
#define   ECR_EMU_DecShiftL_HLimit     ((uint32_t)0x0000007f)

#define   ECR_EMU_ADCOffset_LLimit     ((int32_t)0xffe00000)
#define   ECR_EMU_ADCOffset_HLimit     ((int32_t)0x001fffff)
#define   ECR_EMU_ADCOffset_Symbol     ((uint32_t)(0x1UL<<21))
#define   ECR_EMU_ADCOffset_Signed     ((uint32_t)0xffc00000)

#define   ECR_EMU_PowerOffset_LLimit   ((int32_t)0xff800000)
#define   ECR_EMU_PowerOffset_HLimit   ((int32_t)0x007fffff)
#define   ECR_EMU_PowerOffset_Symbol   ((uint32_t)(0x1UL<<23))
#define   ECR_EMU_PowerOffset_Signed   ((uint32_t)0xff000000)
#define   ECR_EMU_AccuOffset_Limit     ((int32_t)0x00000000)

#define   EMU_WPREG_Unprotected        ((uint32_t)0xA55A)
#define   EMUFILTER_WPREG_Unprotected  ((uint32_t)0xA5BC)
#define   EMU_WPREG_Protected          ((uint32_t)0x0000)

#define   ECR_FILTER_START             ((uint32_t)0x0700)

#define   ECR_2BIT_DATA                ((uint32_t)0x00000003)
#define   ECR_3BIT_DATA                ((uint32_t)0x00000007)
#define   ECR_4BIT_DATA                ((uint32_t)0x0000000f)
#define   ECR_5BIT_DATA                ((uint32_t)0x0000001f)
#define   ECR_6BIT_DATA                ((uint32_t)0x0000003f)
#define   ECR_7BIT_DATA                ((uint32_t)0x0000007f)
#define   ECR_8BIT_DATA                ((uint32_t)0x000000ff)
#define   ECR_9BIT_DATA                ((uint32_t)0x000001ff)
#define   ECR_10BIT_DATA               ((uint32_t)0x000003ff)
#define   ECR_12BIT_DATA               ((uint32_t)0x00000fff)
#define   ECR_14BIT_DATA               ((uint32_t)0x00003fff)
#define   ECR_15BIT_DATA               ((uint32_t)0x00007fff)
#define   ECR_16BIT_DATA               ((uint32_t)0x0000ffff)
#define   ECR_19BIT_DATA               ((uint32_t)0x0007ffff)
#define   ECR_20BIT_DATA               ((uint32_t)0x000fffff)
#define   ECR_21BIT_DATA               ((uint32_t)0x001fffff)
#define   ECR_22BIT_DATA               ((uint32_t)0x003fffff)
#define   ECR_23BIT_DATA               ((uint32_t)0x007fffff)
#define   ECR_24BIT_DATA               ((uint32_t)0x00ffffff)
#define   ECR_25BIT_DATA               ((uint32_t)0x01ffffff)
#define   ECR_30BIT_DATA               ((uint32_t)0x3fffffff)
#define   ECR_32BIT_DATA               ((uint32_t)0xffffffff)

/**************************  Bit definition for  NoLoad register  *******************************************************************/
#if defined  HT762x 
#define    NoLoad_HarPc                                   				((uint32_t)(0x1UL<<20))
#define    NoLoad_HarPb                                   				((uint32_t)(0x1UL<<19))
#define    NoLoad_HarPa                                   				((uint32_t)(0x1UL<<18))
#define    NoLoad_FundSc                                  				((uint32_t)(0x1UL<<17))
#define    NoLoad_FundSb                                  				((uint32_t)(0x1UL<<16))
#define    NoLoad_FundSa                                  				((uint32_t)(0x1UL<<15))
#define    NoLoad_FundQc                                  				((uint32_t)(0x1UL<<14))
#define    NoLoad_FundQb                                  				((uint32_t)(0x1UL<<13))
#define    NoLoad_FundQa                                  				((uint32_t)(0x1UL<<12))
#define    NoLoad_FundPc                                  				((uint32_t)(0x1UL<<11))
#define    NoLoad_FundPb                                  				((uint32_t)(0x1UL<<10))
#define    NoLoad_FundPa                                   				((uint32_t)(0x1UL<<9))
#define    NoLoad_AllSc                                    				((uint32_t)(0x1UL<<8))
#define    NoLoad_AllSb                                    				((uint32_t)(0x1UL<<7))
#define    NoLoad_AllSa                                    				((uint32_t)(0x1UL<<6))
#define    NoLoad_AllQc                                    				((uint32_t)(0x1UL<<5))
#define    NoLoad_AllQb                                    				((uint32_t)(0x1UL<<4))
#define    NoLoad_AllQa                                    				((uint32_t)(0x1UL<<3))
#define    NoLoad_AllPc                                    				((uint32_t)(0x1UL<<2))
#define    NoLoad_AllPb                                    				((uint32_t)(0x1UL<<1))
#define    NoLoad_AllPa                                    				((uint32_t)(0x1UL<<0))
#else
#define    NoLoad_HarP2                                   				((uint32_t)(0x1UL<<19))
#define    NoLoad_HarP1                                   				((uint32_t)(0x1UL<<18))
#define    NoLoad_FundS2                                  				((uint32_t)(0x1UL<<16))
#define    NoLoad_FundS1                                  				((uint32_t)(0x1UL<<15))
#define    NoLoad_FundQ2                                  				((uint32_t)(0x1UL<<13))
#define    NoLoad_FundQ1                                  				((uint32_t)(0x1UL<<12))
#define    NoLoad_FundP2                                  				((uint32_t)(0x1UL<<10))
#define    NoLoad_FundP1                                   				((uint32_t)(0x1UL<<9))
#define    NoLoad_AllS2                                    				((uint32_t)(0x1UL<<7))
#define    NoLoad_AllS1                                    				((uint32_t)(0x1UL<<6))
#define    NoLoad_AllQ2                                    				((uint32_t)(0x1UL<<4))
#define    NoLoad_AllQ1                                    				((uint32_t)(0x1UL<<3))
#define    NoLoad_AllP2                                    				((uint32_t)(0x1UL<<1))
#define    NoLoad_AllP1                                    				((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  REV_Power register  *******************************************************************/
#if defined  HT762x 
#define    REV_Power_HarPt                                   			((uint32_t)(0x1UL<<19))
#define    REV_Power_HarPc                                   			((uint32_t)(0x1UL<<18))
#define    REV_Power_HarPb                                   			((uint32_t)(0x1UL<<17))
#define    REV_Power_HarPa                                   			((uint32_t)(0x1UL<<16))
#define    REV_Power_FundQt                                  			((uint32_t)(0x1UL<<15))
#define    REV_Power_FundQc                                  			((uint32_t)(0x1UL<<14))
#define    REV_Power_FundQb                                  			((uint32_t)(0x1UL<<13))
#define    REV_Power_FundQa                                  			((uint32_t)(0x1UL<<12))
#define    REV_Power_FundPt                                  			((uint32_t)(0x1UL<<11))
#define    REV_Power_FundPc                                  			((uint32_t)(0x1UL<<10))
#define    REV_Power_FundPb                                   			((uint32_t)(0x1UL<<9))
#define    REV_Power_FundPa                                   			((uint32_t)(0x1UL<<8))
#define    REV_Power_AllQt                                    			((uint32_t)(0x1UL<<7))
#define    REV_Power_AllQc                                    			((uint32_t)(0x1UL<<6))
#define    REV_Power_AllQb                                    			((uint32_t)(0x1UL<<5))
#define    REV_Power_AllQa                                    			((uint32_t)(0x1UL<<4))
#define    REV_Power_AllPt                                    			((uint32_t)(0x1UL<<3))
#define    REV_Power_AllPc                                    			((uint32_t)(0x1UL<<2))
#define    REV_Power_AllPb                                    			((uint32_t)(0x1UL<<1))
#define    REV_Power_AllPa                                    			((uint32_t)(0x1UL<<0))
#else
#define    REV_Power_HarPt                                   			((uint32_t)(0x1UL<<19))
#define    REV_Power_HarP2                                   			((uint32_t)(0x1UL<<17))
#define    REV_Power_HarP1                                   			((uint32_t)(0x1UL<<16))
#define    REV_Power_FundQt                                  			((uint32_t)(0x1UL<<15))
#define    REV_Power_FundQ2                                  			((uint32_t)(0x1UL<<13))
#define    REV_Power_FundQ1                                  			((uint32_t)(0x1UL<<12))
#define    REV_Power_FundPt                                  			((uint32_t)(0x1UL<<11))
#define    REV_Power_FundP2                                   			((uint32_t)(0x1UL<<9))
#define    REV_Power_FundP1                                   			((uint32_t)(0x1UL<<8))
#define    REV_Power_AllQt                                    			((uint32_t)(0x1UL<<7))
#define    REV_Power_AllQ2                                    			((uint32_t)(0x1UL<<5))
#define    REV_Power_AllQ1                                    			((uint32_t)(0x1UL<<4))
#define    REV_Power_AllPt                                    			((uint32_t)(0x1UL<<3))
#define    REV_Power_AllP2                                    			((uint32_t)(0x1UL<<1))
#define    REV_Power_AllP1                                    			((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  REV_Energy register  *******************************************************************/
#if defined  HT762x 
#define    REV_Energy_HarEPt                                 			((uint32_t)(0x1UL<<23))
#define    REV_Energy_HarEPc                                 			((uint32_t)(0x1UL<<22))
#define    REV_Energy_HarEPb                                 			((uint32_t)(0x1UL<<21))
#define    REV_Energy_HarEPa                                 			((uint32_t)(0x1UL<<20))
#define    REV_Energy_FundEQt                                			((uint32_t)(0x1UL<<19))
#define    REV_Energy_FundEQc                                			((uint32_t)(0x1UL<<18))
#define    REV_Energy_FundEQb                                			((uint32_t)(0x1UL<<17))
#define    REV_Energy_FundEQa                                			((uint32_t)(0x1UL<<16))
#define    REV_Energy_FundEPt                                			((uint32_t)(0x1UL<<15))
#define    REV_Energy_FundEPc                                			((uint32_t)(0x1UL<<14))
#define    REV_Energy_FundEPb                                			((uint32_t)(0x1UL<<13))
#define    REV_Energy_FundEPa                                			((uint32_t)(0x1UL<<12))
#define    REV_Energy_ESt                                    			((uint32_t)(0x1UL<<11))
#define    REV_Energy_ESc                                    			((uint32_t)(0x1UL<<10))
#define    REV_Energy_ESb                                     			((uint32_t)(0x1UL<<9))
#define    REV_Energy_ESa                                     			((uint32_t)(0x1UL<<8))
#define    REV_Energy_AllEQt                                  			((uint32_t)(0x1UL<<7))
#define    REV_Energy_AllEQc                                  			((uint32_t)(0x1UL<<6))
#define    REV_Energy_AllEQb                                  			((uint32_t)(0x1UL<<5))
#define    REV_Energy_AllEQa                                  			((uint32_t)(0x1UL<<4))
#define    REV_Energy_AllEPt                                  			((uint32_t)(0x1UL<<3))
#define    REV_Energy_AllEPc                                  			((uint32_t)(0x1UL<<2))
#define    REV_Energy_AllEPb                                  			((uint32_t)(0x1UL<<1))
#define    REV_Energy_AllEPa                                  			((uint32_t)(0x1UL<<0))
#else
#define    REV_Energy_HarEPt                                 			((uint32_t)(0x1UL<<23))
#define    REV_Energy_HarEP2                                 			((uint32_t)(0x1UL<<21))
#define    REV_Energy_HarEP1                                 			((uint32_t)(0x1UL<<20))
#define    REV_Energy_FundEQt                                			((uint32_t)(0x1UL<<19))
#define    REV_Energy_FundEQ2                                			((uint32_t)(0x1UL<<17))
#define    REV_Energy_FundEQ1                                			((uint32_t)(0x1UL<<16))
#define    REV_Energy_FundEPt                                			((uint32_t)(0x1UL<<15))
#define    REV_Energy_FundEP2                                			((uint32_t)(0x1UL<<13))
#define    REV_Energy_FundEP1                                			((uint32_t)(0x1UL<<12))
#define    REV_Energy_ESt                                    			((uint32_t)(0x1UL<<11))
#define    REV_Energy_ES2                                     			((uint32_t)(0x1UL<<9))
#define    REV_Energy_ES1                                     			((uint32_t)(0x1UL<<8))
#define    REV_Energy_AllEQt                                  			((uint32_t)(0x1UL<<7))
#define    REV_Energy_AllEQ2                                  			((uint32_t)(0x1UL<<5))
#define    REV_Energy_AllEQ1                                  			((uint32_t)(0x1UL<<4))
#define    REV_Energy_AllEPt                                  			((uint32_t)(0x1UL<<3))
#define    REV_Energy_AllEP2                                  			((uint32_t)(0x1UL<<1))
#define    REV_Energy_AllEP1                                  			((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  P90_Power register  *******************************************************************/
#if defined  HT762x 
#define    P90_Power_FundEQt                                 			((uint32_t)(0x1UL<<15))
#define    P90_Power_FundEQc                                 			((uint32_t)(0x1UL<<14))
#define    P90_Power_FundEQb                                 			((uint32_t)(0x1UL<<13))
#define    P90_Power_FundEQa                                 			((uint32_t)(0x1UL<<12))
#define    P90_Power_FundEPt                                 			((uint32_t)(0x1UL<<11))
#define    P90_Power_FundEPc                                 			((uint32_t)(0x1UL<<10))
#define    P90_Power_FundEPb                                  			((uint32_t)(0x1UL<<9))
#define    P90_Power_FundEPa                                  			((uint32_t)(0x1UL<<8))
#define    P90_Power_AllEQt                                   			((uint32_t)(0x1UL<<7))
#define    P90_Power_AllEQc                                   			((uint32_t)(0x1UL<<6))
#define    P90_Power_AllEQb                                   			((uint32_t)(0x1UL<<5))
#define    P90_Power_AllEQa                                   			((uint32_t)(0x1UL<<4))
#define    P90_Power_AllEPt                                   			((uint32_t)(0x1UL<<3))
#define    P90_Power_AllEPc                                   			((uint32_t)(0x1UL<<2))
#define    P90_Power_AllEPb                                   			((uint32_t)(0x1UL<<1))
#define    P90_Power_AllEPa                                   			((uint32_t)(0x1UL<<0))
#else
#define    P90_Power_FundEQt                                 			((uint32_t)(0x1UL<<15))
#define    P90_Power_FundEQ2                                 			((uint32_t)(0x1UL<<13))
#define    P90_Power_FundEQ1                                 			((uint32_t)(0x1UL<<12))
#define    P90_Power_FundEPt                                 			((uint32_t)(0x1UL<<11))
#define    P90_Power_FundEP2                                  			((uint32_t)(0x1UL<<9))
#define    P90_Power_FundEP1                                  			((uint32_t)(0x1UL<<8))
#define    P90_Power_AllEQt                                   			((uint32_t)(0x1UL<<7))
#define    P90_Power_AllEQ2                                   			((uint32_t)(0x1UL<<5))
#define    P90_Power_AllEQ1                                   			((uint32_t)(0x1UL<<4))
#define    P90_Power_AllEPt                                   			((uint32_t)(0x1UL<<3))
#define    P90_Power_AllEP2                                   			((uint32_t)(0x1UL<<1))
#define    P90_Power_AllEP1                                   			((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  SignalStatus register  *******************************************************************/
#define    SignalStatus_AngleBaseFlag                            		((uint32_t)(0x7UL<<23))
#if defined  HT762x 
#define    SignalStatus_ZCValid_In                               		((uint32_t)(0x1UL<<22))
#define    SignalStatus_ZCValid_Ic                               		((uint32_t)(0x1UL<<21))
#define    SignalStatus_ZCValid_Ib                               		((uint32_t)(0x1UL<<20))
#define    SignalStatus_ZCValid_Ia                               		((uint32_t)(0x1UL<<19))
#define    SignalStatus_ZCValid_Uc                               		((uint32_t)(0x1UL<<18))
#define    SignalStatus_ZCValid_Ub                               		((uint32_t)(0x1UL<<17))
#define    SignalStatus_ZCValid_Ua                              		((uint32_t)(0x1UL<<16))
#define    SignalStatus_RegionIc                                 		((uint32_t)(0x3UL<<14))
#define    SignalStatus_RegionIb                                 		((uint32_t)(0x3UL<<12))
#define    SignalStatus_RegionIa                                 		((uint32_t)(0x3UL<<10))
#define    SignalStatus_UOrder                                    		((uint32_t)(0x1UL<<9))
#define    SignalStatus_IOrder                                    		((uint32_t)(0x1UL<<8))
#define    SignalStatus_Mod3P3Status                              		((uint32_t)(0x1UL<<7))
#define    SignalStatus_VoltageFailC                              		((uint32_t)(0x1UL<<6))
#define    SignalStatus_VoltageFailB                              		((uint32_t)(0x1UL<<5))
#define    SignalStatus_VoltageFailA                              		((uint32_t)(0x1UL<<4))
#define    SignalStatus_CMPC                                      		((uint32_t)(0x1UL<<3))
#define    SignalStatus_CMPB                                      		((uint32_t)(0x1UL<<2))
#define    SignalStatus_CMPA                                      		((uint32_t)(0x1UL<<1))
#define    SignalStatus_CMPDone                                      	((uint32_t)(0x1UL<<0))
#else
#define    SignalStatus_ZCValid_I2                               		((uint32_t)(0x1UL<<20))
#define    SignalStatus_ZCValid_I1                               		((uint32_t)(0x1UL<<19))
#define    SignalStatus_ZCValid_U                              			((uint32_t)(0x1UL<<16))
#define    SignalStatus_RegionI2                                 		((uint32_t)(0x3UL<<12))
#define    SignalStatus_RegionI1                                 		((uint32_t)(0x3UL<<10))
#define    SignalStatus_VoltageFail                              		((uint32_t)(0x1UL<<4))
#endif
/**************************  Bit definition for  PeakSagIntIovStau register  *******************************************************************/
#if defined  HT762x 
#define    PeakSagIntIovStau_OVIN                		         		((uint32_t)(0x1UL<<12))
#define    PeakSagIntIovStau_OVIC                		         		((uint32_t)(0x1UL<<11))
#define    PeakSagIntIovStau_OVIB                		         		((uint32_t)(0x1UL<<10))
#define    PeakSagIntIovStau_OVIA                 		         		((uint32_t)(0x1UL<<9))
#define    PeakSagIntIovStau_UINTUC               		         		((uint32_t)(0x1UL<<8))
#define    PeakSagIntIovStau_UINTUB               		         		((uint32_t)(0x1UL<<7))
#define    PeakSagIntIovStau_UINTUA               		         		((uint32_t)(0x1UL<<6))
#define    PeakSagIntIovStau_SagUC                		        		((uint32_t)(0x1UL<<5))
#define    PeakSagIntIovStau_SagUB                		         		((uint32_t)(0x1UL<<4))
#define    PeakSagIntIovStau_SagUA                		         		((uint32_t)(0x1UL<<3))
#define    PeakSagIntIovStau_PeakUC               		         		((uint32_t)(0x1UL<<2))
#define    PeakSagIntIovStau_PeakUB               		          		((uint32_t)(0x1UL<<1))
#define    PeakSagIntIovStau_PeakUA               		          		((uint32_t)(0x1UL<<0))
#else
#define    PeakSagIntIovStau_OVI2                		         		((uint32_t)(0x1UL<<10))
#define    PeakSagIntIovStau_OVI1                 		         		((uint32_t)(0x1UL<<9))
#define    PeakSagIntIovStau_UINTU               		         		((uint32_t)(0x1UL<<6))
#define    PeakSagIntIovStau_SagU                		         		((uint32_t)(0x1UL<<3))
#define    PeakSagIntIovStau_PeakU               		          		((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  DECShift_H register  *******************************************************************/
#define    DECShift_High_Area2                       				    ((uint32_t)(0xfUL<<8))
#define    DECShift_High_Area1                       				    ((uint32_t)(0xfUL<<4))
#define    DECShift_High_Area0                       				    ((uint32_t)(0xfUL<<0))

/**************************  Bit definition for  DECShift L register  *******************************************************************/
#define    DECShift_Low_Area2                      					    ((uint32_t)(0x7fUL<<14))
#define    DECShift_Low_Area1                       				    ((uint32_t)(0x7fUL<<7))
#define    DECShift_Low_Area0                       				    ((uint32_t)(0x7fUL<<0))

/**************************  Bit definition for  Digtal_gain register  *******************************************************************/
#if defined  HT762x 
#define    Digtal_gain_DGUc                                     		((uint32_t)(0x3UL<<12)) /*UC digtal gain*/
#define    Digtal_gain_DGUc_1                                     		((uint32_t)(0x0UL<<12)) /* 1 times*/
#define    Digtal_gain_DGUc_2                                     		((uint32_t)(0x1UL<<12)) /* 2 times*/
#define    Digtal_gain_DGUc_4                                     		((uint32_t)(0x2UL<<12)) /* 4 times*/
#define    Digtal_gain_DGUc_8                                     		((uint32_t)(0x3UL<<12)) /* 8 times*/

#define    Digtal_gain_DGUb                                     		((uint32_t)(0x3UL<<10)) /*UB digtal gain*/
#define    Digtal_gain_DGUb_1                                     		((uint32_t)(0x0UL<<10)) /* 1 times*/
#define    Digtal_gain_DGUb_2                                     		((uint32_t)(0x1UL<<10)) /* 2 times*/
#define    Digtal_gain_DGUb_4                                     		((uint32_t)(0x2UL<<10)) /* 4 times*/
#define    Digtal_gain_DGUb_8                                     		((uint32_t)(0x3UL<<10)) /* 8 times*/

#define    Digtal_gain_DGUa                                      		((uint32_t)(0x3UL<<8)) /*UA digtal gain*/
#define    Digtal_gain_DGUa_1                                      		((uint32_t)(0x0UL<<8)) /* 1 times*/
#define    Digtal_gain_DGUa_2                                      		((uint32_t)(0x1UL<<8)) /* 2 times*/
#define    Digtal_gain_DGUa_4                                      		((uint32_t)(0x2UL<<8)) /* 4 times*/
#define    Digtal_gain_DGUa_8                                      		((uint32_t)(0x3UL<<8)) /* 8 times*/

#define    Digtal_gain_DGIn                                      		((uint32_t)(0x3UL<<6)) /*IN digtal gain*/
#define    Digtal_gain_DGIn_1                                      		((uint32_t)(0x0UL<<6)) /* 1 times*/
#define    Digtal_gain_DGIn_2                                      		((uint32_t)(0x1UL<<6)) /* 2 times*/
#define    Digtal_gain_DGIn_4                                      		((uint32_t)(0x2UL<<6)) /* 4 times*/
#define    Digtal_gain_DGIn_8                                      		((uint32_t)(0x3UL<<6)) /* 8 times*/

#define    Digtal_gain_DGIc                                      		((uint32_t)(0x3UL<<4)) /*IC digtal gain*/
#define    Digtal_gain_DGIc_1                                      		((uint32_t)(0x0UL<<4)) /* 1 times*/
#define    Digtal_gain_DGIc_2                                      		((uint32_t)(0x1UL<<4)) /* 2 times*/
#define    Digtal_gain_DGIc_4                                      		((uint32_t)(0x2UL<<4)) /* 4 times*/
#define    Digtal_gain_DGIc_8                                      		((uint32_t)(0x3UL<<4)) /* 8 times*/

#define    Digtal_gain_DGIb                                      		((uint32_t)(0x3UL<<2)) /*IB digtal gain*/
#define    Digtal_gain_DGIb_1                                      		((uint32_t)(0x0UL<<2)) /* 1 times*/
#define    Digtal_gain_DGIb_2                                      		((uint32_t)(0x1UL<<2)) /* 2 times*/
#define    Digtal_gain_DGIb_4                                      		((uint32_t)(0x2UL<<2)) /* 4 times*/
#define    Digtal_gain_DGIb_8                                      		((uint32_t)(0x3UL<<2)) /* 8 times*/

#define    Digtal_gain_DGIa                                      		((uint32_t)(0x3UL<<0)) /*IA digtal gain*/
#define    Digtal_gain_DGIa_1                                      		((uint32_t)(0x0UL<<0)) /* 1 times*/
#define    Digtal_gain_DGIa_2                                      		((uint32_t)(0x1UL<<0)) /* 2 times*/
#define    Digtal_gain_DGIa_4                                      		((uint32_t)(0x2UL<<0)) /* 4 times*/
#define    Digtal_gain_DGIa_8                                      		((uint32_t)(0x3UL<<0)) /* 8 times*/
#else
#define    Digtal_gain_DGU_BAK                                      	((uint32_t)(0x3UL<<10)) /*U BAK digtal gain*/

#define    Digtal_gain_DGU                                      		((uint32_t)(0x3UL<<8)) /*U digtal gain*/
#define    Digtal_gain_DGU_1                                      		((uint32_t)(0x0UL<<8)) /* 1 times*/
#define    Digtal_gain_DGU_2                                      		((uint32_t)(0x1UL<<8)) /* 2 times*/
#define    Digtal_gain_DGU_4                                      		((uint32_t)(0x2UL<<8)) /* 4 times*/
#define    Digtal_gain_DGU_8                                      		((uint32_t)(0x3UL<<8)) /* 8 times*/

#define    Digtal_gain_DGI2                                      		((uint32_t)(0x3UL<<2)) /*I2 digtal gain*/
#define    Digtal_gain_DGI2_1                                      		((uint32_t)(0x0UL<<2)) /* 1 times*/
#define    Digtal_gain_DGI2_2                                      		((uint32_t)(0x1UL<<2)) /* 2 times*/
#define    Digtal_gain_DGI2_4                                      		((uint32_t)(0x2UL<<2)) /* 4 times*/
#define    Digtal_gain_DGI2_8                                      		((uint32_t)(0x3UL<<2)) /* 8 times*/

#define    Digtal_gain_DGI1                                      		((uint32_t)(0x3UL<<0)) /*I1 digtal gain*/
#define    Digtal_gain_DGI1_1                                      		((uint32_t)(0x0UL<<0)) /* 1 times*/
#define    Digtal_gain_DGI1_2                                      		((uint32_t)(0x1UL<<0)) /* 2 times*/
#define    Digtal_gain_DGI1_4                                      		((uint32_t)(0x2UL<<0)) /* 4 times*/
#define    Digtal_gain_DGI1_8                                      		((uint32_t)(0x3UL<<0)) /* 8 times*/
#endif
/**************************  Bit definition for  ZXLostCFG register  *******************************************************************/
#define    ZXLostCFG_NumFund                                    		((uint32_t)(0x3fUL<<18))
#define    ZXLostCFG_NumFund_12K8                                    	((uint32_t)(0x28UL<<18)) /* zerocross valid 12.8KHz  number 40 */
#define    ZXLostCFG_NumFund_25K6                                    	((uint32_t)(0x28UL<<18)) /* zerocross valid 25.6KHz  number 40 */

#define    ZXLostCFG_ZCNumMin                                   		((uint32_t)(0x1ffUL<<9))
#define    ZXLostCFG_ZCNumMin_12K8                                   	((uint32_t)(0x40UL<<9)) /* zerocross detection 12.8KHz MIN number 64 */
#define    ZXLostCFG_ZCNumMin_25K6                                   	((uint32_t)(0x80UL<<9)) /* zerocross detection 25.6KHz MIN number 128 */

#define    ZXLostCFG_ZCNumMax                                   		((uint32_t)(0x1ffUL<<0))
#define    ZXLostCFG_ZCNumMax_12K8                                   	((uint32_t)(0xC0UL<<0))  /* zerocross detection 25.6KHz MAX number 192 */
#define    ZXLostCFG_ZCNumMax_25K6                                   	((uint32_t)(0x180UL<<0)) /* zerocross detection 25.6KHz MAX number 384 */
/**************************  Bit definition for  ChannelSel register  *******************************************************************/
#if defined  HT762x 
#define    ChannelSel_ANSI_Mode                                  		((uint32_t)(0x3UL<<21)) /*ansi mode select*/
#define    ChannelSel_ANSI_Mode_NoChange                                ((uint32_t)(0x0UL<<21)) /* not change channel*/
#define    ChannelSel_ANSI_Mode_UbChange1                               ((uint32_t)(0x1UL<<21)) /* Ub =  - Ua - Uc */
#define    ChannelSel_ANSI_Mode_UbChange2                               ((uint32_t)(0x2UL<<21)) /* Ub =  - Ua */
#define    ChannelSel_ANSI_Mode_UbUcChange                              ((uint32_t)(0x3UL<<21)) /* Ua = Ua - Ub,Uc = Uc - Ub */

#define    ChannelSel_ChnRev_EN                                      	((uint32_t)(0x7fUL<<14)) /* channel  *(-1) enable */
#define    ChannelSel_UcRev_EN                                      	((uint32_t)(0x1UL<<20)) /* Uc DATA *(-1) enable */
#define    ChannelSel_UbRev_EN                                      	((uint32_t)(0x1UL<<19)) /* Ub DATA *(-1) enable */
#define    ChannelSel_UaRev_EN                                      	((uint32_t)(0x1UL<<18)) /* Ua DATA *(-1) enable */
#define    ChannelSel_InRev_EN                                      	((uint32_t)(0x1UL<<17)) /* In DATA *(-1) enable */
#define    ChannelSel_IcRev_EN                                      	((uint32_t)(0x1UL<<16)) /* Ic DATA *(-1) enable */
#define    ChannelSel_IbRev_EN                                      	((uint32_t)(0x1UL<<15)) /* Ib DATA *(-1) enable */
#define    ChannelSel_IaRev_EN                                      	((uint32_t)(0x1UL<<14)) /* Ia DATA *(-1) enable */

#define    ChannelSel_UcSel                                      		((uint32_t)(0x3UL<<12)) /* Uc channel select where chanel data */
#define    ChannelSel_UcSel_Uc                                      	((uint32_t)(0x0UL<<12)) /* select Uc */
#define    ChannelSel_UcSel_Ua                                      	((uint32_t)(0x1UL<<12)) /* select Ua */
#define    ChannelSel_UcSel_Ub                                      	((uint32_t)(0x2UL<<12)) /* select Ub */

#define    ChannelSel_UbSel                                      		((uint32_t)(0x3UL<<10)) /* Ub channel select where chanel data */
#define    ChannelSel_UbSel_Ub                                      	((uint32_t)(0x0UL<<10)) /* select Ub */
#define    ChannelSel_UbSel_Uc                                      	((uint32_t)(0x1UL<<10)) /* select Uc */
#define    ChannelSel_UbSel_Ua                                      	((uint32_t)(0x2UL<<10)) /* select Ua */

#define    ChannelSel_UaSel                                       		((uint32_t)(0x3UL<<8)) /* Ua channel select where chanel data */
#define    ChannelSel_UaSel_Ua                                       	((uint32_t)(0x0UL<<8)) /* select Ua */
#define    ChannelSel_UaSel_Ub                                       	((uint32_t)(0x1UL<<8)) /* select Ub */
#define    ChannelSel_UaSel_Uc                                       	((uint32_t)(0x2UL<<8)) /* select Uc */

#define    ChannelSel_InSel                                       		((uint32_t)(0x3UL<<6)) /* In channel select where chanel data */
#define    ChannelSel_InSel_In                                       	((uint32_t)(0x0UL<<6)) /* select In */
#define    ChannelSel_InSel_Ia                                       	((uint32_t)(0x1UL<<6)) /* select Ia */
#define    ChannelSel_InSel_Ib                                       	((uint32_t)(0x2UL<<6)) /* select Ib */
#define    ChannelSel_InSel_Ic                                       	((uint32_t)(0x3UL<<6)) /* select Ic */

#define    ChannelSel_IcSel                                       		((uint32_t)(0x3UL<<4)) /* Ic channel select where chanel data */
#define    ChannelSel_IcSel_Ic                                       	((uint32_t)(0x0UL<<4)) /* select Ic */
#define    ChannelSel_IcSel_In                                       	((uint32_t)(0x1UL<<4)) /* select In */
#define    ChannelSel_IcSel_Ia                                       	((uint32_t)(0x2UL<<4)) /* select Ia */
#define    ChannelSel_IcSel_Ib                                       	((uint32_t)(0x3UL<<4)) /* select Ib */

#define    ChannelSel_IbSel                                       		((uint32_t)(0x3UL<<2)) /* Ib channel select where chanel data */
#define    ChannelSel_IbSel_Ib                                       	((uint32_t)(0x0UL<<2)) /* select Ib */
#define    ChannelSel_IbSel_Ic                                       	((uint32_t)(0x1UL<<2)) /* select Ic */
#define    ChannelSel_IbSel_In                                       	((uint32_t)(0x2UL<<2)) /* select In */
#define    ChannelSel_IbSel_Ia                                      	((uint32_t)(0x3UL<<2)) /* select Ia */

#define    ChannelSel_IaSel                                       		((uint32_t)(0x3UL<<0)) /* Ia channel select where chanel data */
#define    ChannelSel_IaSel_Ia                                       	((uint32_t)(0x0UL<<0)) /* select Ia */
#define    ChannelSel_IaSel_Ib                                       	((uint32_t)(0x1UL<<0)) /* select Ib */
#define    ChannelSel_IaSel_Ic                                       	((uint32_t)(0x2UL<<0)) /* select Ic */
#define    ChannelSel_IaSel_In                                       	((uint32_t)(0x3UL<<0)) /* select In */
#else
#define    ChannelSel_ChnRev_EN                                      	((uint32_t)(0x04c000)) /* channel  *(-1) enable */
#define    ChannelSel_UBakRev_EN                                      	((uint32_t)(0x1UL<<19)) /* U BAK DATA *(-1) enable */
#define    ChannelSel_URev_EN                                      		((uint32_t)(0x1UL<<18)) /* U DATA *(-1) enable */
#define    ChannelSel_I2Rev_EN                                      	((uint32_t)(0x1UL<<15)) /* I2 DATA *(-1) enable */
#define    ChannelSel_I1Rev_EN                                      	((uint32_t)(0x1UL<<14)) /* I1 DATA *(-1) enable */

#define    ChannelSel_UBakSel                                      		((uint32_t)(0x3UL<<10)) /* U BAK channel select where chanel data */
#define    ChannelSel_UBakSel_U                                      	((uint32_t)(0x2UL<<10)) /* select U */

#define    ChannelSel_USel                                       		((uint32_t)(0x3UL<<8)) /* U channel select where chanel data */
#define    ChannelSel_USel_U                                       		((uint32_t)(0x0UL<<8)) /* select U */

#define    ChannelSel_I2Sel                                       		((uint32_t)(0x3UL<<2)) /* I2 channel select where chanel data */
#define    ChannelSel_I2Sel_I2                                       	((uint32_t)(0x0UL<<2)) /* select I2 */
#define    ChannelSel_I2Sel_I1                                       	((uint32_t)(0x2UL<<2)) /* select I1 */

#define    ChannelSel_I1Sel                                       		((uint32_t)(0x3UL<<0)) /* I1 channel select where chanel data */
#define    ChannelSel_I1Sel_I2                                       	((uint32_t)(0x1UL<<0)) /* select I2 */
#define    ChannelSel_I1Sel_I1                                       	((uint32_t)(0x3UL<<0)) /* select I1 */

#endif
/**************************  Bit definition for  PGACON register  *******************************************************************/
#define    PGACON_PGAU                                            		((uint32_t)(0x3UL<<9)) /* voltage channel analog Gain */
#define    PGACON_PGAU_1                                            	((uint32_t)(0x0UL<<9)) /* 1 times */
#define    PGACON_PGAU_2                                            	((uint32_t)(0x1UL<<9)) /* 2 times */
#define    PGACON_PGAU_8                                            	((uint32_t)(0x2UL<<9)) /* 8 times */
#if defined  HT762x 
#define    PGACON_PGAIn                                           		((uint32_t)(0x7UL<<6)) /*In channel analog gain*/
#define    PGACON_PGAIn_1                                           	((uint32_t)(0x0UL<<6)) /* 1 times */
#define    PGACON_PGAIn_2                                           	((uint32_t)(0x5UL<<6)) /* 2 times */
#define    PGACON_PGAIn_4                                           	((uint32_t)(0x1UL<<6)) /* 4 times */
#define    PGACON_PGAIn_8                                           	((uint32_t)(0x2UL<<6)) /* 8 times */
#define    PGACON_PGAIn_16                                           	((uint32_t)(0x3UL<<6)) /* 16 times */
#define    PGACON_PGAIn_24                                           	((uint32_t)(0x7UL<<6)) /* 24 times */
#define    PGACON_PGAIn_32                                           	((uint32_t)(0x4UL<<6)) /* 32 times */

#define    PGACON_PGAIc                                           		((uint32_t)(0x3UL<<4)) /*Ic channel analog gain*/
#define    PGACON_PGAIc_1                                           	((uint32_t)(0x0UL<<4)) /* 1 times */
#define    PGACON_PGAIc_2                                           	((uint32_t)(0x1UL<<4)) /* 2 times */
#define    PGACON_PGAIc_8                                           	((uint32_t)(0x2UL<<4)) /* 8 times */
#define    PGACON_PGAIc_16                                           	((uint32_t)(0x3UL<<4)) /* 16 times */

#define    PGACON_PGAIb                                           		((uint32_t)(0x3UL<<2)) /*Ib channel analog gain*/
#define    PGACON_PGAIb_1                                           	((uint32_t)(0x0UL<<2)) /* 1 times */
#define    PGACON_PGAIb_2                                           	((uint32_t)(0x1UL<<2)) /* 2 times */
#define    PGACON_PGAIb_8                                           	((uint32_t)(0x2UL<<2)) /* 8 times */
#define    PGACON_PGAIb_16                                           	((uint32_t)(0x3UL<<2)) /* 16 times */

#define    PGACON_PGAIa                                           		((uint32_t)(0x3UL<<0)) /*Ia channel analog gain*/
#define    PGACON_PGAIa_1                                           	((uint32_t)(0x0UL<<0)) /* 1 times */
#define    PGACON_PGAIa_2                                           	((uint32_t)(0x1UL<<0)) /* 2 times */
#define    PGACON_PGAIa_8                                           	((uint32_t)(0x2UL<<0)) /* 8 times */
#define    PGACON_PGAIa_16                                           	((uint32_t)(0x3UL<<0)) /* 16 times */
#else
#define    PGACON_PGAI1                                           		((uint32_t)(0x7UL<<6)) /*I1 channel analog gain*/
#define    PGACON_PGAI1_1                                           	((uint32_t)(0x0UL<<6)) /* 1 times */
#define    PGACON_PGAI1_2                                           	((uint32_t)(0x5UL<<6)) /* 2 times */
#define    PGACON_PGAI1_4                                           	((uint32_t)(0x1UL<<6)) /* 4 times */
#define    PGACON_PGAI1_8                                           	((uint32_t)(0x2UL<<6)) /* 8 times */
#define    PGACON_PGAI1_16                                           	((uint32_t)(0x3UL<<6)) /* 16 times */
#define    PGACON_PGAI1_24                                           	((uint32_t)(0x7UL<<6)) /* 24 times */
#define    PGACON_PGAI1_32                                           	((uint32_t)(0x4UL<<6)) /* 32 times */

#define    PGACON_PGAI2                                           		((uint32_t)(0x3UL<<2)) /*I2 channel analog gain*/
#define    PGACON_PGAI2_1                                           	((uint32_t)(0x0UL<<2)) /* 1 times */
#define    PGACON_PGAI2_2                                           	((uint32_t)(0x1UL<<2)) /* 2 times */
#define    PGACON_PGAI2_8                                           	((uint32_t)(0x2UL<<2)) /* 8 times */
#define    PGACON_PGAI2_16                                           	((uint32_t)(0x3UL<<2)) /* 16 times */
#endif
/**************************  Bit definition for  ADCCFG register  *******************************************************************/
#define    ADCCFG_ZcSrSel                                        		((uint32_t)(0x1UL<<19)) /* zero cross and half wave peak source selcet*/
#define    ADCCFG_ZcSrSel_All                                        	((uint32_t)(0x0UL<<19)) /* selcet all data*/
#define    ADCCFG_ZcSrSel_Fund                                        	((uint32_t)(0x1UL<<19)) /* selcet fund data*/

#define    ADCCFG_FreqSel                                        		((uint32_t)(0x1UL<<18)) /* current metering system frequency select */
#define    ADCCFG_FreqSel_50Hz                                        	((uint32_t)(0x0UL<<18)) /* select 50Hz */
#define    ADCCFG_FreqSel_60Hz                                        	((uint32_t)(0x1UL<<18)) /* select 60Hz */
#if defined  HT762x 
#define    ADCCFG_MODE3P3_EN                                        	((uint32_t)(0x1UL<<17)) /* current metering system three phase three wire enable */
#endif
#define    ADCCFG_DMASrc_Sel                                     		((uint32_t)(0x1UL<<16)) /* dma source selcet */
#define    ADCCFG_DMASrc_Sel_SPL                                     	((uint32_t)(0x0UL<<16)) /* select spl wave */
#define    ADCCFG_DMASrc_Sel_QuartRmsIns                                ((uint32_t)(0x1UL<<16)) /* select QuartRmsIns */

#define    ADCCFG_Auto_Tc_EN                                     		((uint32_t)(0x1UL<<15)) /* adc channel temperature compensation enable */

#define    ADCCFG_WaveSel                                        		((uint32_t)(0x3UL<<13)) /* spl wave source select */
#define    ADCCFG_WaveSel_BeforeHPF                                     ((uint32_t)(0x0UL<<13)) /* select before hpf */
#define    ADCCFG_WaveSel_AfterHPF                                      ((uint32_t)(0x1UL<<13)) /* select after hpf */
#define    ADCCFG_WaveSel_AfterGain                                     ((uint32_t)(0x2UL<<13)) /* select after gain */

#define    ADCCFG_ZCd                                            		((uint32_t)(0x3UL<<11)) /* zero cross Interrupt way select */
#define    ADCCFG_ZCd_P                                            		((uint32_t)(0x0UL<<11)) /* select positive */
#define    ADCCFG_ZCd_N                                            		((uint32_t)(0x1UL<<11)) /* select negitive */
#define    ADCCFG_ZCd_PN                                            	((uint32_t)(0x2UL<<11)) /* select positive and negitive */

#define    ADCCFG_SPL                                             		((uint32_t)(0x7UL<<8)) /* spl wave update rate select */
#define    ADCCFG_SPL_1k6                                             	((uint32_t)(0x0UL<<8)) /* fs=12.8khz,select 1.6kHz;fs = 25.6khz,select 3.2kHz */
#define    ADCCFG_SPL_3k2                                               ((uint32_t)(0x1UL<<8)) /* fs=12.8khz,select 3.2kHz;fs = 25.6khz,select 6.4kHz */
#define    ADCCFG_SPL_6k4                                               ((uint32_t)(0x2UL<<8)) /* fs=12.8khz,select 6.4kHz;fs = 25.6khz,select 12.8kHz */
#define    ADCCFG_SPL_12k8                                              ((uint32_t)(0x3UL<<8)) /* fs=12.8khz,select 12.8kHz;fs = 25.6khz,select 25.6kHz */

#define    ADCCFG_ZCINTSrc_SEL                                    		((uint32_t)(0x3UL<<6)) /* zero cross Interrupt source select */
#define    ADCCFG_ZCINTSrc_SEL_AfterHPF                                 ((uint32_t)(0x0UL<<6)) /* select hpf after*/
#define    ADCCFG_ZCINTSrc_SEL_BeforeHPF                                ((uint32_t)(0x1UL<<6)) /* select before hpf */
#define    ADCCFG_ZCINTSrc_SEL_Fund                                     ((uint32_t)(0x2UL<<6)) /* select fund filter after */

#define    ADCCFG_EMUClk_SEL                                      		((uint32_t)(0x1UL<<5)) /* emuclk select */
#define    ADCCFG_EMUClk_SEL_819K2                                      ((uint32_t)(0x0UL<<5)) /* select 819.2kHz */
#define    ADCCFG_EMUClk_SEL_1638K4                                     ((uint32_t)(0x1UL<<5)) /* select 1.6384MHz */

#define    ADCCFG_Deccomp_EN                                      		((uint32_t)(0x1UL<<4)) /*cic compensation enable*/

#define    ADCCFG_OSR_SEL                                          		((uint32_t)(0x1UL<<3)) /* adc OSR select */
#define    ADCCFG_OSR_SEL_64                                          	((uint32_t)(0x0UL<<3)) /* SELECT 64 */
#define    ADCCFG_OSR_SEL_128                                          	((uint32_t)(0x1UL<<3)) /* SELECT 128 */
#if defined  HT762x 
#define    ADCCFG_HPFON                                        			((uint32_t)(0x7UL<<0)) /* ADC open hpf */
#define    ADCCFG_HPFON_In                                        		((uint32_t)(0x1UL<<2)) /* In channel open hpf */
#else
#define    ADCCFG_HPFON                                        			((uint32_t)(0x3UL<<0)) /* ADC open hpf */
#endif
#define    ADCCFG_HPFON_I                                         		((uint32_t)(0x1UL<<1)) /* current channel open hpf */
#define    ADCCFG_HPFON_U                                         		((uint32_t)(0x1UL<<0)) /* voltage channel open hpf */
/**************************  Bit definition for  ADCCON register  *******************************************************************/
#if defined  HT762x 
#define    ADCCON_ADCEn_ANA                                   			((uint32_t)(0x7fUL<<16)) /* analog channel enable */
#define    ADCCON_ADCEn_ANA_Uc                                   		((uint32_t)(0x1UL<<22)) /* Uc analog channel enable */
#define    ADCCON_ADCEn_ANA_Ub                                   		((uint32_t)(0x1UL<<21)) /* Ub analog channel enable */
#define    ADCCON_ADCEn_ANA_Ua                                   		((uint32_t)(0x1UL<<20)) /* Ua analog channel enable */
#define    ADCCON_ADCEn_ANA_In                                   		((uint32_t)(0x1UL<<19)) /* In analog channel enable */
#define    ADCCON_ADCEn_ANA_Ic                                   		((uint32_t)(0x1UL<<18)) /* Ic analog channel enable */
#define    ADCCON_ADCEn_ANA_Ib                                   		((uint32_t)(0x1UL<<17)) /* Ib analog channel enable */
#define    ADCCON_ADCEn_ANA_Ia                                   		((uint32_t)(0x1UL<<16)) /* Ia analog channel enable */
#else
#define    ADCCON_ADCEn_ANA                                   			((uint32_t)(0x01a0000)) /* analog channel enable */
#define    ADCCON_ADCEn_ANA_U                                   		((uint32_t)(0x1UL<<20)) /* Ua analog channel enable */
#define    ADCCON_ADCEn_ANA_I1                                   		((uint32_t)(0x1UL<<19)) /* In analog channel enable */
#define    ADCCON_ADCEn_ANA_I2                                   		((uint32_t)(0x1UL<<17)) /* Ib analog channel enable */
#endif
#define    ADCCON_PeakSagSrc                                     		((uint32_t)(0x1UL<<14)) /* peak,sag,int,iov detection source select */
#define    ADCCON_PeakSagSrc_HVp                                     	((uint32_t)(0x0UL<<14)) /* select half wave peak */
#define    ADCCON_PeakSagSrc_HRms                                     	((uint32_t)(0x1UL<<14)) /* select half wave rms */

#define    ADCCON_PeakEn                                         		((uint32_t)(0x1UL<<13)) /* voltage swell/peak detection enable*/
#define    ADCCON_SagEn                                          		((uint32_t)(0x1UL<<12)) /* voltage dip/sag detection enable*/
#define    ADCCON_IntEn                                          		((uint32_t)(0x1UL<<11)) /* voltage interrupt detection enable*/
#define    ADCCON_IovEn                                          		((uint32_t)(0x1UL<<10)) /* current overflow detection enable*/
#if defined  HT762x 
#define    ADCCON_CT2_OSR                                         		((uint32_t)(0x1UL<<9)) /* CT2 OSR select */
#define    ADCCON_CT2_OSR_16                                         	((uint32_t)(0x0UL<<9)) /* select osr = 16 */
#define    ADCCON_CT2_OSR_32                                         	((uint32_t)(0x1UL<<9)) /* select osr = 32 */
#endif
#define    ADCCON_Phase_Sel                                       		((uint32_t)(0x1UL<<8)) /* phase segment source select */
#define    ADCCON_Phase_Sel_All                                        	((uint32_t)(0x0UL<<8)) /* selcet all data */
#define    ADCCON_Phase_Sel_Fund                                       	((uint32_t)(0x1UL<<8)) /* selcet fund data */
#if defined  HT762x 
#define    ADCCON_CTdetEn                                         		((uint32_t)(0x1UL<<7)) /* CT2 enable */

#define    ADCCON_ADC_En                                      			((uint32_t)(0x7fUL<<0)) /* digtal adc channel enable */
#define    ADCCON_ADC_En_Uc                                       		((uint32_t)(0x1UL<<6)) /* Uc digtal adc channel enable */
#define    ADCCON_ADC_En_Ub                                       		((uint32_t)(0x1UL<<5)) /* Ub digtal adc channel enable */
#define    ADCCON_ADC_En_Ua                                       		((uint32_t)(0x1UL<<4)) /* Ua digtal adc channel enable */
#define    ADCCON_ADC_En_In                                       		((uint32_t)(0x1UL<<3)) /* In digtal adc channel enable */
#define    ADCCON_ADC_En_Ic                                       		((uint32_t)(0x1UL<<2)) /* Ic digtal adc channel enable */
#define    ADCCON_ADC_En_Ib                                       		((uint32_t)(0x1UL<<1)) /* Ib digtal adc channel enable */
#define    ADCCON_ADC_En_Ia                                       		((uint32_t)(0x1UL<<0)) /* Ia digtal adc channel enable */
#else
#define    ADCCON_ADC_En                                      			((uint32_t)(0x0000013)) /* digtal adc channel enable */
#define    ADCCON_ADC_En_UBak                                       	((uint32_t)(0x1UL<<5)) /* U BAK digtal adc channel enable */
#define    ADCCON_ADC_En_U                                       		((uint32_t)(0x1UL<<4)) /* U digtal adc channel enable */
#define    ADCCON_ADC_En_I2                                       		((uint32_t)(0x1UL<<1)) /* I2 digtal adc channel enable */
#define    ADCCON_ADC_En_I1                                       		((uint32_t)(0x1UL<<0)) /* I1 digtal adc channel enable */
#endif
/**************************  Bit definition for  EMUCFG register  *******************************************************************/
#define    EMUCFG_SQRMS_Src                                      		((uint32_t)(0x1UL<<22)) /* square data source select */
#define    EMUCFG_SQRMS_Src_All                                      	((uint32_t)(0x0UL<<22)) /* select all wave channel data */
#define    EMUCFG_SQRMS_Src_Fund                                      	((uint32_t)(0x1UL<<22)) /* select fundamental wave channel data */
#if defined  HT762x 
#define    EMUCFG_AngleBaseSel                                   		((uint32_t)(0x7UL<<19)) /* angle basis reference select */
#define    EMUCFG_AngleBaseSel_Ua                                   	((uint32_t)(0x0UL<<19)) /* select ua */
#define    EMUCFG_AngleBaseSel_Ub                                   	((uint32_t)(0x1UL<<19)) /* select ub */
#define    EMUCFG_AngleBaseSel_Uc                                   	((uint32_t)(0x2UL<<19)) /* select uc */
#define    EMUCFG_AngleBaseSel_Ia                                   	((uint32_t)(0x3UL<<19)) /* select ia */
#define    EMUCFG_AngleBaseSel_Ib                                   	((uint32_t)(0x4UL<<19)) /* select ib */
#define    EMUCFG_AngleBaseSel_Ic                                   	((uint32_t)(0x5UL<<19)) /* select ic */
#define    EMUCFG_AngleBaseSel_In                                   	((uint32_t)(0x6UL<<19)) /* select in */
#else
#define    EMUCFG_AngleBaseSel                                   		((uint32_t)(0x7UL<<19)) /* angle basis reference select */
#define    EMUCFG_AngleBaseSel_U                                   		((uint32_t)(0x0UL<<19)) /* select u */
#define    EMUCFG_AngleBaseSel_I1                                   	((uint32_t)(0x3UL<<19)) /* select i1 */
#define    EMUCFG_AngleBaseSel_I2                                   	((uint32_t)(0x4UL<<19)) /* select i2 */
#endif
#define    EMUCFG_AutoAngBase_EN                                    	((uint32_t)(0x1UL<<18)) /* angle basis reference automatic switch enable */
#if defined  HT762x 
#define    EMUCFG_PtCfgC                                         		((uint32_t)(0x3UL<<16)) /* C channel power part in sum power select */
#define    EMUCFG_PtCfgC_PartIn                                         ((uint32_t)(0x0UL<<16)) /* direct part in */
#define    EMUCFG_PtCfgC_RevPartIn                                      ((uint32_t)(0x1UL<<16)) /* *(-1) after part in */
#define    EMUCFG_PtCfgC_NoPartIn                                       ((uint32_t)(0x2UL<<16)) /* not part in */

#define    EMUCFG_PtCfgB                                         		((uint32_t)(0x3UL<<14)) /* B channel power part in sum power select */
#define    EMUCFG_PtCfgB_PartIn                                         ((uint32_t)(0x0UL<<14)) /* direct part in */
#define    EMUCFG_PtCfgB_RevPartIn                                      ((uint32_t)(0x1UL<<14)) /* *(-1) after part in */
#define    EMUCFG_PtCfgB_NoPartIn                                       ((uint32_t)(0x2UL<<14)) /* not part in */

#define    EMUCFG_PtCfgA                                         		((uint32_t)(0x3UL<<12)) /* A channel power part in sum power select */
#define    EMUCFG_PtCfgA_PartIn                                         ((uint32_t)(0x0UL<<12)) /* direct part in */
#define    EMUCFG_PtCfgA_RevPartIn                                      ((uint32_t)(0x1UL<<12)) /* *(-1) after part in */
#define    EMUCFG_PtCfgA_NoPartIn                                       ((uint32_t)(0x2UL<<12)) /* not part in */

#define    EMUCFG_UtCfg                                         		((uint32_t)(0x7UL<<9)) /* voltage part in vector voltage select */
#define    EMUCFG_UtCfgC                                         		((uint32_t)(0x1UL<<11)) /* C phase voltage part in vector voltage select */
#define    EMUCFG_UtCfgB                                         		((uint32_t)(0x1UL<<10)) /* B phase voltage part in vector voltage select */
#define    EMUCFG_UtCfgA                                          		((uint32_t)(0x1UL<<9)) /* A phase voltage part in vector voltage select */

#define    EMUCFG_ItCfg                                          		((uint32_t)(0xfUL<<5)) /* current part in vector current select */
#define    EMUCFG_ItCfgN                                          		((uint32_t)(0x1UL<<8)) /* N phase current part in vector current select */
#define    EMUCFG_ItCfgC                                          		((uint32_t)(0x1UL<<7)) /* C phase current part in vector current select */
#define    EMUCFG_ItCfgB                                          		((uint32_t)(0x1UL<<6)) /* B phase current part in vector current select */
#define    EMUCFG_ItCfgA                                          		((uint32_t)(0x1UL<<5)) /* A phase current part in vector current select */

#define    EMUCFG_UacSel                                          		((uint32_t)(0x1UL<<4)) /* three phase three wire :UB channel rms calculate way select */
#define    EMUCFG_UacSel_Ub                                          	((uint32_t)(0x0UL<<4)) /* select like three phase four wire */
#define    EMUCFG_UacSel_UaSubUc                                        ((uint32_t)(0x1UL<<4)) /* select ub = ua-uc */
#else
#define    EMUCFG_PtCfg2                                         		((uint32_t)(0x3UL<<14)) /* channel 2 power part in sum power select */
#define    EMUCFG_PtCfg2_PartIn                                         ((uint32_t)(0x0UL<<14)) /* direct part in */
#define    EMUCFG_PtCfg2_RevPartIn                                      ((uint32_t)(0x1UL<<14)) /* *(-1) after part in */
#define    EMUCFG_PtCfg2_NoPartIn                                       ((uint32_t)(0x2UL<<14)) /* not part in */

#define    EMUCFG_PtCfg1                                         		((uint32_t)(0x3UL<<12)) /* channel 1 power part in sum power select */
#define    EMUCFG_PtCfg1_PartIn                                         ((uint32_t)(0x0UL<<12)) /* direct part in */
#define    EMUCFG_PtCfg1_RevPartIn                                      ((uint32_t)(0x1UL<<12)) /* *(-1) after part in */
#define    EMUCFG_PtCfg1_NoPartIn                                       ((uint32_t)(0x2UL<<12)) /* not part in */

#define    EMUCFG_ItCfg                                          		((uint32_t)(0x3UL<<5)) /* current part in vector current select */
#define    EMUCFG_ItCfg2                                          		((uint32_t)(0x1UL<<6)) /* current channel 2 part in vector current select */
#define    EMUCFG_ItCfg1                                          		((uint32_t)(0x1UL<<5)) /* current channel 1 part in vector current select */
#endif
#define    EMUCFG_PowerSCal_Sel                                   		((uint32_t)(0x1UL<<3)) /* Apparent power calculate way select */
#define    EMUCFG_PowerSCal_Sel_PQS                                   	((uint32_t)(0x0UL<<3)) /* select PQS */
#define    EMUCFG_PowerSCal_Sel_RMS                                   	((uint32_t)(0x1UL<<3)) /* select RMS */
#if defined  HT762x 
#define    EMUCFG_FundLineU_En                                    		((uint32_t)(0x1UL<<2)) /* Fundamental line voltage rms enable*/
#define    EMUCFG_UtFund_En                                       		((uint32_t)(0x1UL<<1)) /* Fundamental vector voltage rms enable*/
#endif
#define    EMUCFG_ItFund_En                                       		((uint32_t)(0x1UL<<0)) /* Fundamental vector current rms enable*/
/**************************  Bit definition for  FilterCon register  *******************************************************************/
#define    FilterCon_FundZCDelay                               			((uint32_t)(0x1ffUL<<12)) /* fundamental wave zero cross delay number */
#if defined  HT762x 
#define    FilterCon_Uconst_En                                  		((uint32_t)(0x7UL<<9))  /* voltage const enable */
#define    FilterCon_UconstC_En                                  		((uint32_t)(0x1UL<<11)) /* C phase voltage const enable */
#define    FilterCon_UconstB_En                                  		((uint32_t)(0x1UL<<10)) /* B phase voltage const enable */
#define    FilterCon_UconstA_En                                   		((uint32_t)(0x1UL<<9))  /* A phase voltage const enable */
#else
#define    FilterCon_UconstBAK_En                                  		((uint32_t)(0x1UL<<10)) /* voltage const BAK enable */
#define    FilterCon_Uconst_En                                   		((uint32_t)(0x1UL<<9))  /* voltage const enable */
#endif
#define    FilterCon_Lpf_En                                    		    ((uint32_t)(0x3UL<<6))  /* RMS Channel LPF enable */
#define    FilterCon_RmsLpf_En                                    		((uint32_t)(0x1UL<<7))  /* RMS Channel LPF enable */
#define    FilterCon_PowerLpf_En                                    	((uint32_t)(0x1UL<<6))  /* power Channel LPF enable */

#define    FilterCon_RosiShift                                    		((uint32_t)(0x3UL<<4))  /* current channel rosi gain select */
#define    FilterCon_RosiShift_1                                    	((uint32_t)(0x0UL<<4))  /* 1 times */
#define    FilterCon_RosiShift_2                                    	((uint32_t)(0x1UL<<4))  /* 2 times */
#define    FilterCon_RosiShift_4                                    	((uint32_t)(0x2UL<<4))  /* 4 times */
#define    FilterCon_RosiShift_8                                    	((uint32_t)(0x3UL<<4))  /* 8 times */
#if defined  HT762x 
#define    FilterCon_Rosi_En                                   			((uint32_t)(0xfUL<<0))  /* current rosi enable */
#define    FilterCon_Rosi_En_In                                   		((uint32_t)(0x1UL<<3))  /* N phase current rosi enable */
#define    FilterCon_Rosi_En_Ic                                   		((uint32_t)(0x1UL<<2))  /* C phase current rosi enable */
#define    FilterCon_Rosi_En_Ib                                   		((uint32_t)(0x1UL<<1))  /* B phase current rosi enable */
#define    FilterCon_Rosi_En_Ia                                   		((uint32_t)(0x1UL<<0))  /* A phase current rosi enable */
#else
#define    FilterCon_Rosi_En                                   			((uint32_t)(0x3UL<<0))  /* current rosi enable */
#define    FilterCon_Rosi_En_I2                                   		((uint32_t)(0x1UL<<1))  /* current channel 2 rosi enable */
#define    FilterCon_Rosi_En_I1                                   		((uint32_t)(0x1UL<<0))  /* current channel 1 rosi enable */
#endif
/**************************  Bit definition for  FilterCFG register  *******************************************************************/
#define    FilterCFG_PH90Ctrl                                    		((uint32_t)(0x3UL<<17)) /* 90¡ãshfit filter contrl */
#define    FilterCFG_LPFCtrl                                    		((uint32_t)(0xfffUL<<5)) /* rms and power lpf filter contrl */
#define    FilterCFG_RosiCtrl                                     		((uint32_t)(0x3UL<<3)) /* rosi filter contrl */
#define    FilterCFG_HpfCtrl                                      		((uint32_t)(0x7UL<<0)) /* Hpf filter contrl */
/**************************  Bit definition for  StartCFG register  *******************************************************************/
#define    StartCFG_HarStart_CFG                                  		((uint32_t)(0x1UL<<3)) /* harmonic start way select */
#define    StartCFG_HarStart_CFG_POWER                                  ((uint32_t)(0x0UL<<3)) /* select power */
#define    StartCFG_HarStart_CFG_RMS                                  	((uint32_t)(0x1UL<<3)) /* select rms */

#define    StartCFG_StartSrc_CFG                                  		((uint32_t)(0x1UL<<2)) /* all and fundamental wave start way select power type select */
#define    StartCFG_StartSrc_CFG_AvgPower                               ((uint32_t)(0x0UL<<2)) /*  select average power*/
#define    StartCFG_StartSrc_CFG_InsPower                               ((uint32_t)(0x1UL<<2)) /* select instantaneous power*/

#define    StartCFG_Start_CFG                                     		((uint32_t)(0x3UL<<0)) /* all and fundamental wave start way select */
#define    StartCFG_Start_CFG_POWER1                                    ((uint32_t)(0x0UL<<0)) /* power 1*/
#define    StartCFG_Start_CFG_POWER2                                    ((uint32_t)(0x1UL<<0)) /* power 2*/
#define    StartCFG_Start_CFG_RMS1                                     	((uint32_t)(0x2UL<<0)) /* rms 1*/
#define    StartCFG_Start_CFG_RMS2                                     	((uint32_t)(0x3UL<<0)) /* rms 2*/

/**************************  Bit definition for  ANACFG1 register  *******************************************************************/
#define    ANACFG1_Vref_En                                       		((uint32_t)(0x1UL<<22))  /* emu Normal Vref Enable  */
#define    ANACFG1_Emu_Ldo_En                                    		((uint32_t)(0x1UL<<21))  /* EMU LDO Enable */

#define    ANACFG1_UADC_BIAS                              				((uint32_t)(0x7UL<<18))   /* voltage channel ADC Bias adjust*/
#define    ANACFG1_UADC_BIAS_4uA                              			((uint32_t)(0x0UL<<18))   /* 4uA */
#define    ANACFG1_UADC_BIAS_6uA                              			((uint32_t)(0x1UL<<18))   /* 6uA */
#define    ANACFG1_UADC_BIAS_8uA                              			((uint32_t)(0x2UL<<18))   /* 8uA */
#define    ANACFG1_UADC_BIAS_10uA                              			((uint32_t)(0x3UL<<18))   /* 10uA */
#define    ANACFG1_UADC_BIAS_12uA                              			((uint32_t)(0x4UL<<18))   /* 12uA */

#define    ANACFG1_CLKCfg                                				((uint32_t)(0x1fUL<<13))  /* CLK adjust */

#define    ANACFG1_PGA_BIAS                                  			((uint32_t)(0x7UL<<3)) /* PGA Bias adjust */
#define    ANACFG1_PGA_BIAS_5uA                                  		((uint32_t)(0x0UL<<3)) /* 5uA  */
#define    ANACFG1_PGA_BIAS_10uA                                  		((uint32_t)(0x1UL<<3)) /* 10uA */
#define    ANACFG1_PGA_BIAS_15uA                                  		((uint32_t)(0x2UL<<3)) /* 15uA */
#define    ANACFG1_PGA_BIAS_20uA                                  		((uint32_t)(0x3UL<<3)) /* 20uA */
#define    ANACFG1_PGA_BIAS_25uA                                  		((uint32_t)(0x4UL<<3)) /* 25uA */

#define    ANACFG1_IADC_BIAS                                 			((uint32_t)(0x7UL<<0)) /* current channel ADC Bias adjust */
#define    ANACFG1_IADC_BIAS_4uA                                   		((uint32_t)(0x0UL<<0)) /*  4uA  */
#define    ANACFG1_IADC_BIAS_6uA                                   		((uint32_t)(0x1UL<<0)) /*  6uA  */
#define    ANACFG1_IADC_BIAS_8uA                                   		((uint32_t)(0x2UL<<0)) /*  8uA  */
#define    ANACFG1_IADC_BIAS_10uA                                  		((uint32_t)(0x3UL<<0)) /*  10uA */
#define    ANACFG1_IADC_BIAS_12uA                                  		((uint32_t)(0x4UL<<0)) /*  12uA */
/**************************  Bit definition for  ANACFG2 register  *******************************************************************/
#define    ANACFG2_Iref_En                                       		((uint32_t)(0x1UL<<19)) /* high precision Iref enable */
#define    ANACFG2_TC2ND_EN                                      		((uint32_t)(0x1UL<<18))

#define    ANACFG2_Vref_Ctrl                                      		((uint32_t)(0x7UL<<5))

#define    ANACFG2_Chop_En                                       		((uint32_t)(0x1fUL<<0)) /* chop en */
#define    ANACFG2_VrefChop_En                                    		((uint32_t)(0x1UL<<4)) /* vref Chopper Enable*/
#define    ANACFG2_InChop_En                                      		((uint32_t)(0x1UL<<3)) /* In ADC Chopper Enable*/
#define    ANACFG2_IChop_En                                       		((uint32_t)(0x1UL<<2)) /* I ADC Chopper Enable*/
#define    ANACFG2_UChop_En                                       		((uint32_t)(0x1UL<<1)) /* U ADC Chopper Enable*/
#define    ANACFG2_AMPChop_En                                     		((uint32_t)(0x1UL<<0)) /* PGA Chopper Enable */
#if defined  HT762x
/**************************  Bit definition for  ULostCMPCFG register  *******************************************************************/
#define    ULostCMPCFG_CMP_PRD_EN                                		((uint32_t)(0x1UL<<15)) /* Voltage all lost comparator continuous detection enable */

#define    ULostCMPCFG_DUTY                                      		((uint32_t)(0x7fUL<<8)) /* Voltage all lost comparator Minimum effective pulse width time coefficient */

#define    ULostCMPCFG_VcmpLVL                                    		((uint32_t)(0x7UL<<5)) /* Voltage all lost comparator compare threshold */
#define    ULostCMPCFG_VcmpLVL_0mV942                                   ((uint32_t)(0x0UL<<5)) /* 0.942mV */
#define    ULostCMPCFG_VcmpLVL_1mV414                                   ((uint32_t)(0x1UL<<5)) /* 1.414mV */
#define    ULostCMPCFG_VcmpLVL_1mV791                                   ((uint32_t)(0x2UL<<5)) /* 1.791mV */
#define    ULostCMPCFG_VcmpLVL_3mV140                                   ((uint32_t)(0x3UL<<5)) /* 3.140mV */
#define    ULostCMPCFG_VcmpLVL_4mV488                                   ((uint32_t)(0x4UL<<5)) /* 4.488mV */
#define    ULostCMPCFG_VcmpLVL_5mV837                                   ((uint32_t)(0x5UL<<5)) /* 5.837mV */
#define    ULostCMPCFG_VcmpLVL_7mV185                                   ((uint32_t)(0x6UL<<5)) /* 7.185mV */
#define    ULostCMPCFG_VcmpLVL_9mV542                                   ((uint32_t)(0x7UL<<5)) /* 9.542mV */

#define    ULostCMPCFG_VOLNUM                                     		((uint32_t)(0xfUL<<1)) /* Voltage all lost comparator compare numberof cycle */
#define    ULostCMPCFG_CMP_EN                                     		((uint32_t)(0x1UL<<0)) /* Voltage all lost comparator enable */
/**************************  Bit definition for  ULostPRDCFG register  *******************************************************************/
#define    ULostPRDCFG_STBTime                                  		((uint32_t)(0x3fUL<<16)) /* Voltage all lost comparator stand by time */ 
#define    ULostPRDCFG_CMPRunTime                                		((uint32_t)(0xffUL<<8)) /* Voltage all lost comparator enable run time set */
#define    ULostPRDCFG_CMPPRD                                    		((uint32_t)(0xffUL<<0)) /* Voltage all lost comparator Time-sharing detection period time set */
#endif
/**************************  Bit definition for  LPModeCONEMU register  *******************************************************************/
#define    LPModeCON_StandByTime                               			((uint32_t)(0xfUL<<4)) /* low power mode stand by time select */
#define    LPModeCON_StandByTime_0                               		((uint32_t)(0x0UL<<4)) /* not lost time */
#define    LPModeCON_StandByTime_4                               		((uint32_t)(0x1UL<<4)) /* lost 4    points */
#define    LPModeCON_StandByTime_8                               		((uint32_t)(0x2UL<<4)) /* lost 8    points */
#define    LPModeCON_StandByTime_16                               		((uint32_t)(0x3UL<<4)) /* lost 16   points */
#define    LPModeCON_StandByTime_32                               		((uint32_t)(0x4UL<<4)) /* lost 32   points */
#define    LPModeCON_StandByTime_64                               		((uint32_t)(0x5UL<<4)) /* lost 64   points */
#define    LPModeCON_StandByTime_128                               		((uint32_t)(0x6UL<<4)) /* lost 128  points */
#define    LPModeCON_StandByTime_256                               		((uint32_t)(0x7UL<<4)) /* lost 256  points */
#define    LPModeCON_StandByTime_512                              		((uint32_t)(0x8UL<<4)) /* lost 512  points */
#define    LPModeCON_StandByTime_1024                               	((uint32_t)(0x9UL<<4)) /* lost 1024 points */

#define    LPModeCON_LP_VREF_EN                               			((uint32_t)(0x1UL<<2)) /* Low power LVref enable*/

#define    LPModeCON_EMUCLK_LPSel                              			((uint32_t)(0x1UL<<1)) /* Low power mode clk select */
#define    LPModeCON_EMUCLK_LPSel_204K8                              	((uint32_t)(0x0UL<<1)) /* 204.8kHz */
#define    LPModeCON_EMUCLK_LPSel_32K                              		((uint32_t)(0x1UL<<1)) /* 32kHz */

#define    LPModeCON_LPMode_EN                                    		((uint32_t)(0x1UL<<0)) /* Low power mode enable*/
/**************************  Bit definition for  CFxRun register  *******************************************************************/
#if defined  HT762x
#define    CFxRun_EN                                   					((uint32_t)(0xffffff)) /* Energy accumulation enable */
#define    CFxRun_Har_Pt_EN                                   			((uint32_t)(0x1UL<<23)) /* sum harmonic Positive Energy accumulation enable */
#define    CFxRun_Har_Pc_EN                                   			((uint32_t)(0x1UL<<22)) /* C phase harmonic Positive Energy accumulation enable */
#define    CFxRun_Har_Pb_EN                                   			((uint32_t)(0x1UL<<21)) /* B phase harmonic Positive Energy accumulation enable */
#define    CFxRun_Har_Pa_EN                                   			((uint32_t)(0x1UL<<20)) /* A phase harmonic Positive Energy accumulation enable */
#define    CFxRun_Fund_Qt_EN                                  			((uint32_t)(0x1UL<<19)) /* sum fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Qc_EN                                  			((uint32_t)(0x1UL<<18)) /* C phase fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Qb_EN                                  			((uint32_t)(0x1UL<<17)) /* B phase fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Qa_EN                                  			((uint32_t)(0x1UL<<16)) /* A phase fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Pt_EN                                  			((uint32_t)(0x1UL<<15)) /* sum fundamental Positive Energy accumulation enable */
#define    CFxRun_Fund_Pc_EN                                  			((uint32_t)(0x1UL<<14)) /* C phase fundamental Positive Energy accumulation enable */
#define    CFxRun_Fund_Pb_EN                                  			((uint32_t)(0x1UL<<13)) /* B phase fundamental Positive Energy accumulation enable */
#define    CFxRun_Fund_Pa_EN                                  			((uint32_t)(0x1UL<<12)) /* A phase fundamental Positive Energy accumulation enable */
#define    CFxRun_St_EN                                       			((uint32_t)(0x1UL<<11)) /* sum apparent Energy accumulation enable */
#define    CFxRun_Sc_EN                                       			((uint32_t)(0x1UL<<10)) /* C phase apparent Energy accumulation enable */
#define    CFxRun_Sb_EN                                        			((uint32_t)(0x1UL<<9))  /* B phase apparent Energy accumulation enable */
#define    CFxRun_Sa_EN                                        			((uint32_t)(0x1UL<<8))  /* A phase apparent  Energy accumulation enable */
#define    CFxRun_All_Qt_EN                                    			((uint32_t)(0x1UL<<7))  /* sum all negitive Energy accumulation enable */
#define    CFxRun_All_Qc_EN                                    			((uint32_t)(0x1UL<<6))  /* C phase all negitive Energy accumulation enable */
#define    CFxRun_All_Qb_EN                                    			((uint32_t)(0x1UL<<5))  /* B phase all negitive Energy accumulation enable */
#define    CFxRun_All_Qa_EN                                    			((uint32_t)(0x1UL<<4))  /* A phase all negitive Energy accumulation enable */
#define    CFxRun_All_Pt_EN                                    			((uint32_t)(0x1UL<<3))  /* sum all Positive Energy accumulation enable */
#define    CFxRun_All_Pc_EN                                    			((uint32_t)(0x1UL<<2))  /* C phase all Positive Energy accumulation enable */
#define    CFxRun_All_Pb_EN                                    			((uint32_t)(0x1UL<<1))  /* B phase all Positive Energy accumulation enable */
#define    CFxRun_All_Pa_EN                                    			((uint32_t)(0x1UL<<0))  /* A phase all Positive Energy accumulation enable */
#else
#define    CFxRun_EN                                   					((uint32_t)(0xbbbbbb)) /* Energy accumulation enable */
#define    CFxRun_Har_Pt_EN                                   			((uint32_t)(0x1UL<<23)) /* sum harmonic Positive Energy accumulation enable */
#define    CFxRun_Har_P2_EN                                   			((uint32_t)(0x1UL<<21)) /* channel 2 harmonic Positive Energy accumulation enable */
#define    CFxRun_Har_P1_EN                                   			((uint32_t)(0x1UL<<20)) /* channel 1 harmonic Positive Energy accumulation enable */
#define    CFxRun_Fund_Qt_EN                                  			((uint32_t)(0x1UL<<19)) /* sum fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Q2_EN                                  			((uint32_t)(0x1UL<<17)) /* channel 2 fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Q1_EN                                  			((uint32_t)(0x1UL<<16)) /* channel 1 fundamental negitive Energy accumulation enable */
#define    CFxRun_Fund_Pt_EN                                  			((uint32_t)(0x1UL<<15)) /* sum fundamental Positive Energy accumulation enable */
#define    CFxRun_Fund_P2_EN                                  			((uint32_t)(0x1UL<<13)) /* channel 2 fundamental Positive Energy accumulation enable */
#define    CFxRun_Fund_P1_EN                                  			((uint32_t)(0x1UL<<12)) /* channel 1 fundamental Positive Energy accumulation enable */
#define    CFxRun_St_EN                                       			((uint32_t)(0x1UL<<11)) /* sum apparent Energy accumulation enable */
#define    CFxRun_S2_EN                                        			((uint32_t)(0x1UL<<9))  /* channel 2 apparent Energy accumulation enable */
#define    CFxRun_S1_EN                                        			((uint32_t)(0x1UL<<8))  /* channel 1 apparent  Energy accumulation enable */
#define    CFxRun_All_Qt_EN                                    			((uint32_t)(0x1UL<<7))  /* sum all negitive Energy accumulation enable */
#define    CFxRun_All_Q2_EN                                    			((uint32_t)(0x1UL<<5))  /* channel 2 all negitive Energy accumulation enable */
#define    CFxRun_All_Q1_EN                                    			((uint32_t)(0x1UL<<4))  /* channel 1 all negitive Energy accumulation enable */
#define    CFxRun_All_Pt_EN                                    			((uint32_t)(0x1UL<<3))  /* sum all Positive Energy accumulation enable */
#define    CFxRun_All_P2_EN                                    			((uint32_t)(0x1UL<<1))  /* channel 2 all Positive Energy accumulation enable */
#define    CFxRun_All_P1_EN                                    			((uint32_t)(0x1UL<<0))  /* channel 1 all Positive Energy accumulation enable */

#endif
/**************************  Bit definition for  EnergyCon register  *******************************************************************/
#define    EnergyCon_PassMode_Har_P                              		((uint32_t)(0x3UL<<22)) /* harmonic wave active energy in way select */
#define    EnergyCon_PassMode_Har_P_All                              	((uint32_t)(0x0UL<<22)) /* all power */
#define    EnergyCon_PassMode_Har_P_POS                              	((uint32_t)(0x1UL<<22)) /* positive power*/
#define    EnergyCon_PassMode_Har_P_NEG                              	((uint32_t)(0x2UL<<22)) /* negitive power*/

#define    EnergyCon_PassMode_Fund_Q                             		((uint32_t)(0x3UL<<20)) /* fundamental wave reactive energy in way select */
#define    EnergyCon_PassMode_Fund_Q_All                             	((uint32_t)(0x0UL<<20)) /* all power */
#define    EnergyCon_PassMode_Fund_Q_POS                             	((uint32_t)(0x1UL<<20)) /* positive power*/
#define    EnergyCon_PassMode_Fund_Q_NEG                             	((uint32_t)(0x2UL<<20)) /* negitive power*/

#define    EnergyCon_PassMode_Fund_P                             		((uint32_t)(0x3UL<<18)) /* fundamental wave active energy in way select */
#define    EnergyCon_PassMode_Fund_P_All                             	((uint32_t)(0x0UL<<18)) /* all power */
#define    EnergyCon_PassMode_Fund_P_POS                             	((uint32_t)(0x1UL<<18)) /* positive power*/
#define    EnergyCon_PassMode_Fund_P_NEG                             	((uint32_t)(0x2UL<<18)) /* negitive power*/

#define    EnergyCon_PassMode_S                                  		((uint32_t)(0x3UL<<16)) /* apparent energy in way select */
#define    EnergyCon_PassMode_S_All                                  	((uint32_t)(0x0UL<<16)) /* all power */
#define    EnergyCon_PassMode_S_POS                                  	((uint32_t)(0x1UL<<16)) /* positive power*/
#define    EnergyCon_PassMode_S_NEG                                  	((uint32_t)(0x2UL<<16)) /* negitive power*/

#define    EnergyCon_PassMode_All_Q                              		((uint32_t)(0x3UL<<14)) /* all wave reactive energy in way select */
#define    EnergyCon_PassMode_All_Q_All                              	((uint32_t)(0x0UL<<14)) /* all power */
#define    EnergyCon_PassMode_All_Q_POS                              	((uint32_t)(0x1UL<<14)) /* positive power*/
#define    EnergyCon_PassMode_All_Q_NEG                              	((uint32_t)(0x2UL<<14)) /* negitive power*/

#define    EnergyCon_PassMode_All_P                              		((uint32_t)(0x3UL<<12)) /* all wave active energy in way select */
#define    EnergyCon_PassMode_All_P_All                              	((uint32_t)(0x0UL<<12)) /* all power */
#define    EnergyCon_PassMode_All_P_POS                              	((uint32_t)(0x1UL<<12)) /* positive power*/
#define    EnergyCon_PassMode_All_P_NEG                              	((uint32_t)(0x2UL<<12)) /* negitive power*/

#define    EnergyCon_EnergySSrc_Sel                              		((uint32_t)(0x1UL<<11)) /* apparent energy source select*/
#define    EnergyCon_EnergySSrc_Sel_All                              	((uint32_t)(0x0UL<<11)) /* all wave */
#define    EnergyCon_EnergySSrc_Sel_Fund                              	((uint32_t)(0x1UL<<11)) /* fundamental wave */

#define    EnergyCon_EnergyRC_En                                 		((uint32_t)(0x1UL<<10)) /* ENERGY read after clear enable */

#define    EnergyCon_PtAddMode                                    		((uint32_t)(0x1UL<<9)) /* sum power calculate way select */
#define    EnergyCon_PtAddMode_ALG                                    	((uint32_t)(0x0UL<<9)) /* ALGEBRA */
#define    EnergyCon_PtAddMode_ABS                                    	((uint32_t)(0x1UL<<9)) /* ABSOLUTE */

#define    EnergyCon_POS                                          		((uint32_t)(0x1UL<<8)) /* pluse valid level select */
#define    EnergyCon_POS_High                                          	((uint32_t)(0x0UL<<8)) /* High is valid */
#define    EnergyCon_POS_Low                                          	((uint32_t)(0x1UL<<8)) /* low is valid */

#define    EnergyCon_CFP                                          		((uint32_t)(0x3UL<<6)) /* plus width select*/
#define    EnergyCon_CFP_80                                          	((uint32_t)(0x0UL<<6)) /* 80ms */
#define    EnergyCon_CFP_40                                          	((uint32_t)(0x1UL<<6)) /* 40ms */
#define    EnergyCon_CFP_20                                          	((uint32_t)(0x2UL<<6)) /* 20ms */
#define    EnergyCon_CFP_160                                          	((uint32_t)(0x3UL<<6)) /* 160ms */

#define    EnergyCon_Power_Shift                                  		((uint32_t)(0x7UL<<0)) /*plus double config */
#define    EnergyCon_Power_Shift_1                                  	((uint32_t)(0x0UL<<0)) /* 1 times */
#define    EnergyCon_Power_Shift_2                                  	((uint32_t)(0x1UL<<0)) /* 2 times */
#define    EnergyCon_Power_Shift_4                                  	((uint32_t)(0x2UL<<0)) /* 4 times */
#define    EnergyCon_Power_Shift_8                                  	((uint32_t)(0x3UL<<0)) /* 8 times */
#define    EnergyCon_Power_Shift_16                                  	((uint32_t)(0x4UL<<0)) /* 16 times */
/**************************  Bit definition for  PowerSrcCFG1 register  *******************************************************************/
#define    PowerSrcCFG1_St                              				((uint32_t)(0x3UL<<22)) /* sum apparent energy channel in power select */
#define    PowerSrcCFG1_St_AvgPower                              		((uint32_t)(0x0UL<<22)) /* average power*/
#define    PowerSrcCFG1_St_InsPower                              		((uint32_t)(0x1UL<<22)) /* instantaneous power */
#define    PowerSrcCFG1_St_ConstPower                              		((uint32_t)(0x2UL<<22)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG1_Sc                              				((uint32_t)(0x3UL<<20)) /* C apparent energy channel in power select */
#define    PowerSrcCFG1_Sc_AvgPower                                		((uint32_t)(0x0UL<<20)) /* average power*/
#define    PowerSrcCFG1_Sc_InsPower                                		((uint32_t)(0x1UL<<20)) /* instantaneous power */
#define    PowerSrcCFG1_Sc_ConstPower                              		((uint32_t)(0x2UL<<20)) /* const power */

#define    PowerSrcCFG1_Sb                              				((uint32_t)(0x3UL<<18)) /* B apparent energy channel in power select */
#define    PowerSrcCFG1_Sb_AvgPower                                		((uint32_t)(0x0UL<<18)) /* average power*/
#define    PowerSrcCFG1_Sb_InsPower                                		((uint32_t)(0x1UL<<18)) /* instantaneous power */
#define    PowerSrcCFG1_Sb_ConstPower                              		((uint32_t)(0x2UL<<18)) /* const power */

#define    PowerSrcCFG1_Sa                              				((uint32_t)(0x3UL<<16)) /* A apparent energy channel in power select */
#define    PowerSrcCFG1_Sa_AvgPower                                		((uint32_t)(0x0UL<<16)) /* average power*/
#define    PowerSrcCFG1_Sa_InsPower                                		((uint32_t)(0x1UL<<16)) /* instantaneous power */
#define    PowerSrcCFG1_Sa_ConstPower                              		((uint32_t)(0x2UL<<16)) /* const power */
#else
#define    PowerSrcCFG1_S2                              				((uint32_t)(0x3UL<<18)) /* apparent energy channel 2 in power select */
#define    PowerSrcCFG1_S2_AvgPower                                		((uint32_t)(0x0UL<<18)) /* average power*/
#define    PowerSrcCFG1_S2_InsPower                                		((uint32_t)(0x1UL<<18)) /* instantaneous power */
#define    PowerSrcCFG1_S2_ConstPower                              		((uint32_t)(0x2UL<<18)) /* const power */

#define    PowerSrcCFG1_S1                              				((uint32_t)(0x3UL<<16)) /* apparent energy channel 1 in power select */
#define    PowerSrcCFG1_S1_AvgPower                                		((uint32_t)(0x0UL<<16)) /* average power*/
#define    PowerSrcCFG1_S1_InsPower                                		((uint32_t)(0x1UL<<16)) /* instantaneous power */
#define    PowerSrcCFG1_S1_ConstPower                              		((uint32_t)(0x2UL<<16)) /* const power */
#endif
#define    PowerSrcCFG1_All_Qt                          				((uint32_t)(0x3UL<<14)) /* sum All Wave reactive energy channel in power select */
#define    PowerSrcCFG1_All_Qt_AvgPower                            		((uint32_t)(0x0UL<<14)) /* average power*/
#define    PowerSrcCFG1_All_Qt_InsPower                            		((uint32_t)(0x1UL<<14)) /* instantaneous power */
#define    PowerSrcCFG1_All_Qt_ConstPower                          		((uint32_t)(0x2UL<<14)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG1_All_Qc                          				((uint32_t)(0x3UL<<12)) /* C All Wave reactive energy channel in power select */
#define    PowerSrcCFG1_All_Qc_AvgPower                            		((uint32_t)(0x0UL<<12)) /* average power*/
#define    PowerSrcCFG1_All_Qc_InsPower                            		((uint32_t)(0x1UL<<12)) /* instantaneous power */
#define    PowerSrcCFG1_All_Qc_ConstPower                          		((uint32_t)(0x2UL<<12)) /* const power */

#define    PowerSrcCFG1_All_Qb                          				((uint32_t)(0x3UL<<10)) /* B All Wave reactive energy channel in power select */
#define    PowerSrcCFG1_All_Qb_AvgPower                            		((uint32_t)(0x0UL<<10)) /* average power*/
#define    PowerSrcCFG1_All_Qb_InsPower                            		((uint32_t)(0x1UL<<10)) /* instantaneous power */
#define    PowerSrcCFG1_All_Qb_ConstPower                          		((uint32_t)(0x2UL<<10)) /* const power */

#define    PowerSrcCFG1_All_Qa                           				((uint32_t)(0x3UL<<8)) /* A All Wave reactive energy channel in power select */
#define    PowerSrcCFG1_All_Qa_AvgPower                             	((uint32_t)(0x0UL<<8)) /* average power*/
#define    PowerSrcCFG1_All_Qa_InsPower                             	((uint32_t)(0x1UL<<8)) /* instantaneous power */
#define    PowerSrcCFG1_All_Qa_ConstPower                           	((uint32_t)(0x2UL<<8)) /* const power */
#else
#define    PowerSrcCFG1_All_Q2                          				((uint32_t)(0x3UL<<10)) /* All Wave reactive energy channel 2 in power select */
#define    PowerSrcCFG1_All_Q2_AvgPower                            		((uint32_t)(0x0UL<<10)) /* average power*/
#define    PowerSrcCFG1_All_Q2_InsPower                            		((uint32_t)(0x1UL<<10)) /* instantaneous power */
#define    PowerSrcCFG1_All_Q2_ConstPower                          		((uint32_t)(0x2UL<<10)) /* const power */

#define    PowerSrcCFG1_All_Q1                           				((uint32_t)(0x3UL<<8)) /* All Wave reactive energy channel 1 in power select */
#define    PowerSrcCFG1_All_Q1_AvgPower                             	((uint32_t)(0x0UL<<8)) /* average power*/
#define    PowerSrcCFG1_All_Q1_InsPower                             	((uint32_t)(0x1UL<<8)) /* instantaneous power */
#define    PowerSrcCFG1_All_Q1_ConstPower                           	((uint32_t)(0x2UL<<8)) /* const power */
#endif
#define    PowerSrcCFG1_All_Pt                           				((uint32_t)(0x3UL<<6)) /* sum All Wave active energy channel in power select */
#define    PowerSrcCFG1_All_Pt_AvgPower                             	((uint32_t)(0x0UL<<6)) /* average power*/
#define    PowerSrcCFG1_All_Pt_InsPower                             	((uint32_t)(0x1UL<<6)) /* instantaneous power */
#define    PowerSrcCFG1_All_Pt_ConstPower                           	((uint32_t)(0x2UL<<6)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG1_All_Pc                           				((uint32_t)(0x3UL<<4)) /* C All Wave active energy channel in power select */
#define    PowerSrcCFG1_All_Pc_AvgPower                             	((uint32_t)(0x0UL<<4)) /* average power*/
#define    PowerSrcCFG1_All_Pc_InsPower                             	((uint32_t)(0x1UL<<4)) /* instantaneous power */
#define    PowerSrcCFG1_All_Pc_ConstPower                           	((uint32_t)(0x2UL<<4)) /* const power */

#define    PowerSrcCFG1_All_Pb                           				((uint32_t)(0x3UL<<2)) /* B All Wave active energy channel in power select */
#define    PowerSrcCFG1_All_Pb_AvgPower                             	((uint32_t)(0x0UL<<2)) /* average power*/
#define    PowerSrcCFG1_All_Pb_InsPower                             	((uint32_t)(0x1UL<<2)) /* instantaneous power */
#define    PowerSrcCFG1_All_Pb_ConstPower                           	((uint32_t)(0x2UL<<2)) /* const power */

#define    PowerSrcCFG1_All_Pa                           				((uint32_t)(0x3UL<<0)) /* A All Wave active energy channel in power select */
#define    PowerSrcCFG1_All_Pa_AvgPower                             	((uint32_t)(0x0UL<<0)) /* average power*/
#define    PowerSrcCFG1_All_Pa_InsPower                             	((uint32_t)(0x1UL<<0)) /* instantaneous power */
#define    PowerSrcCFG1_All_Pa_ConstPower                           	((uint32_t)(0x2UL<<0)) /* const power */
#else
#define    PowerSrcCFG1_All_P2                           				((uint32_t)(0x3UL<<2)) /* All Wave active energy channel 2 in power select */
#define    PowerSrcCFG1_All_P2_AvgPower                             	((uint32_t)(0x0UL<<2)) /* average power*/
#define    PowerSrcCFG1_All_P2_InsPower                             	((uint32_t)(0x1UL<<2)) /* instantaneous power */
#define    PowerSrcCFG1_All_P2_ConstPower                           	((uint32_t)(0x2UL<<2)) /* const power */

#define    PowerSrcCFG1_All_P1                           				((uint32_t)(0x3UL<<0)) /* All Wave active energy channel 1 in power select */
#define    PowerSrcCFG1_All_P1_AvgPower                             	((uint32_t)(0x0UL<<0)) /* average power*/
#define    PowerSrcCFG1_All_P1_InsPower                             	((uint32_t)(0x1UL<<0)) /* instantaneous power */
#define    PowerSrcCFG1_All_P1_ConstPower                           	((uint32_t)(0x2UL<<0)) /* const power */
#endif
/**************************  Bit definition for  PowerSrcCFG2 register  *******************************************************************/
#define    PowerSrcCFG2_Har_Pt                          				((uint32_t)(0x3UL<<22)) /* sum harmonic active energy channel in power select */
#define    PowerSrcCFG2_Har_Pt_AvgPower                             	((uint32_t)(0x0UL<<22)) /* average power*/
#define    PowerSrcCFG2_Har_Pt_InsPower                             	((uint32_t)(0x1UL<<22)) /* instantaneous power */
#define    PowerSrcCFG2_Har_Pt_ConstPower                           	((uint32_t)(0x2UL<<22)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG2_Har_Pc                                      	((uint32_t)(0x3UL<<20)) /* C harmonic reactive energy channel in power select */
#define    PowerSrcCFG2_Har_Pc_AvgPower                             	((uint32_t)(0x0UL<<20)) /* average power*/
#define    PowerSrcCFG2_Har_Pc_InsPower                             	((uint32_t)(0x1UL<<20)) /* instantaneous power */
#define    PowerSrcCFG2_Har_Pc_ConstPower                           	((uint32_t)(0x2UL<<20)) /* const power */

#define    PowerSrcCFG2_Har_Pb                                      	((uint32_t)(0x3UL<<18)) /* B harmonic reactive energy channel in power select */
#define    PowerSrcCFG2_Har_Pb_AvgPower                             	((uint32_t)(0x0UL<<18)) /* average power*/
#define    PowerSrcCFG2_Har_Pb_InsPower                             	((uint32_t)(0x1UL<<18)) /* instantaneous power */
#define    PowerSrcCFG2_Har_Pb_ConstPower                           	((uint32_t)(0x2UL<<18)) /* const power */

#define    PowerSrcCFG2_Har_Pa                                      	((uint32_t)(0x3UL<<16)) /* A harmonic reactive energy channel in power select */
#define    PowerSrcCFG2_Har_Pa_AvgPower                             	((uint32_t)(0x0UL<<16)) /* average power*/
#define    PowerSrcCFG2_Har_Pa_InsPower                             	((uint32_t)(0x1UL<<16)) /* instantaneous power */
#define    PowerSrcCFG2_Har_Pa_ConstPower                           	((uint32_t)(0x2UL<<16)) /* const power */
#else
#define    PowerSrcCFG2_Har_P2                                      	((uint32_t)(0x3UL<<18)) /* harmonic reactive energy channel 2 in power select */
#define    PowerSrcCFG2_Har_P2_AvgPower                             	((uint32_t)(0x0UL<<18)) /* average power*/
#define    PowerSrcCFG2_Har_P2_InsPower                             	((uint32_t)(0x1UL<<18)) /* instantaneous power */
#define    PowerSrcCFG2_Har_P2_ConstPower                           	((uint32_t)(0x2UL<<18)) /* const power */

#define    PowerSrcCFG2_Har_P1                                      	((uint32_t)(0x3UL<<16)) /* harmonic reactive energy channel 1 in power select */
#define    PowerSrcCFG2_Har_P1_AvgPower                             	((uint32_t)(0x0UL<<16)) /* average power*/
#define    PowerSrcCFG2_Har_P1_InsPower                             	((uint32_t)(0x1UL<<16)) /* instantaneous power */
#define    PowerSrcCFG2_Har_P1_ConstPower                           	((uint32_t)(0x2UL<<16)) /* const power */

#endif
#define    PowerSrcCFG2_Fund_Qt                         				((uint32_t)(0x3UL<<14)) /* sum fundamental Wave reactive energy channel in power select */
#define    PowerSrcCFG2_Fund_Qt_AvgPower                            	((uint32_t)(0x0UL<<14)) /* average power*/
#define    PowerSrcCFG2_Fund_Qt_InsPower                            	((uint32_t)(0x1UL<<14)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Qt_ConstPower                          	((uint32_t)(0x2UL<<14)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG2_Fund_Qc                                     	((uint32_t)(0x3UL<<12)) /* C fundamental Wave reactive energy channel in power select */
#define    PowerSrcCFG2_Fund_Qc_AvgPower                            	((uint32_t)(0x0UL<<12)) /* average power*/
#define    PowerSrcCFG2_Fund_Qc_InsPower                            	((uint32_t)(0x1UL<<12)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Qc_ConstPower                          	((uint32_t)(0x2UL<<12)) /* const power */

#define    PowerSrcCFG2_Fund_Qb                                     	((uint32_t)(0x3UL<<10)) /* B fundamental Wave reactive energy channel in power select */
#define    PowerSrcCFG2_Fund_Qb_AvgPower                            	((uint32_t)(0x0UL<<10)) /* average power*/
#define    PowerSrcCFG2_Fund_Qb_InsPower                            	((uint32_t)(0x1UL<<10)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Qb_ConstPower                          	((uint32_t)(0x2UL<<10)) /* const power */

#define    PowerSrcCFG2_Fund_Qa                                      	((uint32_t)(0x3UL<<8)) /* A fundamental Wave reactive energy channel in power select */
#define    PowerSrcCFG2_Fund_Qa_AvgPower                             	((uint32_t)(0x0UL<<8)) /* average power*/
#define    PowerSrcCFG2_Fund_Qa_InsPower                             	((uint32_t)(0x1UL<<8)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Qa_ConstPower                           	((uint32_t)(0x2UL<<8)) /* const power */
#else
#define    PowerSrcCFG2_Fund_Q2                                     	((uint32_t)(0x3UL<<10)) /* fundamental Wave reactive energy channel 2 in power select */
#define    PowerSrcCFG2_Fund_Q2_AvgPower                            	((uint32_t)(0x0UL<<10)) /* average power*/
#define    PowerSrcCFG2_Fund_Q2_InsPower                            	((uint32_t)(0x1UL<<10)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Q2_ConstPower                          	((uint32_t)(0x2UL<<10)) /* const power */

#define    PowerSrcCFG2_Fund_Q1                                      	((uint32_t)(0x3UL<<8)) /* fundamental Wave reactive energy channel 1 in power select */
#define    PowerSrcCFG2_Fund_Q1_AvgPower                             	((uint32_t)(0x0UL<<8)) /* average power*/
#define    PowerSrcCFG2_Fund_Q1_InsPower                             	((uint32_t)(0x1UL<<8)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Q1_ConstPower                           	((uint32_t)(0x2UL<<8)) /* const power */

#endif
#define    PowerSrcCFG2_Fund_Pt                          				((uint32_t)(0x3UL<<6)) /* sum fundamental Wave active energy channel in power select */
#define    PowerSrcCFG2_Fund_Pt_AvgPower                             	((uint32_t)(0x0UL<<6)) /* average power*/
#define    PowerSrcCFG2_Fund_Pt_InsPower                             	((uint32_t)(0x1UL<<6)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Pt_ConstPower                           	((uint32_t)(0x2UL<<6)) /* const power */
#if defined  HT762x
#define    PowerSrcCFG2_Fund_Pc                                      	((uint32_t)(0x3UL<<4)) /* C fundamental Wave active energy channel in power select */
#define    PowerSrcCFG2_Fund_Pc_AvgPower                             	((uint32_t)(0x0UL<<4)) /* average power*/
#define    PowerSrcCFG2_Fund_Pc_InsPower                             	((uint32_t)(0x1UL<<4)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Pc_ConstPower                           	((uint32_t)(0x2UL<<4)) /* const power */

#define    PowerSrcCFG2_Fund_Pb                                      	((uint32_t)(0x3UL<<2)) /* B fundamental Wave active energy channel in power select */
#define    PowerSrcCFG2_Fund_Pb_AvgPower                             	((uint32_t)(0x0UL<<2)) /* average power*/
#define    PowerSrcCFG2_Fund_Pb_InsPower                             	((uint32_t)(0x1UL<<2)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Pb_ConstPower                           	((uint32_t)(0x2UL<<2)) /* const power */

#define    PowerSrcCFG2_Fund_Pa                                      	((uint32_t)(0x3UL<<0)) /* A fundamental Wave active energy channel in power select */
#define    PowerSrcCFG2_Fund_Pa_AvgPower                             	((uint32_t)(0x0UL<<0)) /* average power*/
#define    PowerSrcCFG2_Fund_Pa_InsPower                             	((uint32_t)(0x1UL<<0)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_Pa_ConstPower                           	((uint32_t)(0x2UL<<0)) /* const power */
#else
#define    PowerSrcCFG2_Fund_P2                                      	((uint32_t)(0x3UL<<2)) /* fundamental Wave active energy channel 2 in power select */
#define    PowerSrcCFG2_Fund_P2_AvgPower                             	((uint32_t)(0x0UL<<2)) /* average power*/
#define    PowerSrcCFG2_Fund_P2_InsPower                             	((uint32_t)(0x1UL<<2)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_P2_ConstPower                           	((uint32_t)(0x2UL<<2)) /* const power */

#define    PowerSrcCFG2_Fund_P1                                      	((uint32_t)(0x3UL<<0)) /* fundamental Wave active energy channel 1 in power select */
#define    PowerSrcCFG2_Fund_P1_AvgPower                             	((uint32_t)(0x0UL<<0)) /* average power*/
#define    PowerSrcCFG2_Fund_P1_InsPower                             	((uint32_t)(0x1UL<<0)) /* instantaneous power */
#define    PowerSrcCFG2_Fund_P1_ConstPower                           	((uint32_t)(0x2UL<<0)) /* const power */
#endif
/**************************  Bit definition for  PowerModeCFG register  *******************************************************************/
#define    PowerModeCFG_JudgeEn                              			((uint32_t)(0x3fUL<<18)) /* total harmonic active energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_HarP                              		((uint32_t)(0x1UL<<23)) /* total harmonic active energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_FundQ                           		((uint32_t)(0x1UL<<22)) /* fundamental reactive energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_FundP                           		((uint32_t)(0x1UL<<21)) /* fundamental active energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_S                                		((uint32_t)(0x1UL<<20)) /* apparent energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_AllQ                            		((uint32_t)(0x1UL<<19)) /* all reactive energy channel small power factor judge enable */
#define    PowerModeCFG_JudgeEn_AllP                            		((uint32_t)(0x1UL<<18)) /* all active energy channel small power factor judge enable */

#define    PowerModeCFG_PowerOVSel_HarP                          		((uint32_t)(0x1UL<<17)) /* total harmonic active energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_HarP_P                          		((uint32_t)(0x0UL<<17)) /* positive */
#define    PowerModeCFG_PowerOVSel_HarP_PN                          	((uint32_t)(0x1UL<<17)) /* negitive */

#define    PowerModeCFG_PowerOVSel_FundQ                         		((uint32_t)(0x1UL<<16)) /* fundamental reactive energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_FundQ_P                         		((uint32_t)(0x0UL<<16)) /* positive */
#define    PowerModeCFG_PowerOVSel_FundQ_PN                          	((uint32_t)(0x1UL<<16)) /* negitive */

#define    PowerModeCFG_PowerOVSel_FundP                         		((uint32_t)(0x1UL<<15)) /* fundamental active energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_FundP_P                         		((uint32_t)(0x0UL<<15)) /* positive */
#define    PowerModeCFG_PowerOVSel_FundP_PN                          	((uint32_t)(0x1UL<<15)) /* negitive */

#define    PowerModeCFG_PowerOVSel_S                             		((uint32_t)(0x1UL<<14)) /* apparent energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_S_P                             		((uint32_t)(0x0UL<<14)) /* positive */
#define    PowerModeCFG_PowerOVSel_S_PN                              	((uint32_t)(0x1UL<<14)) /* negitive */

#define    PowerModeCFG_PowerOVSel_AllQ                          		((uint32_t)(0x1UL<<13)) /* all reactive energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_AllQ_P                          		((uint32_t)(0x0UL<<13)) /* positive */
#define    PowerModeCFG_PowerOVSel_AllQ_PN                           	((uint32_t)(0x1UL<<13)) /* negitive */

#define    PowerModeCFG_PowerOVSel_AllP                          		((uint32_t)(0x1UL<<12)) /* all active energy negitive energy channel Overflow select */
#define    PowerModeCFG_PowerOVSel_AllP_P                          		((uint32_t)(0x0UL<<12)) /* positive */
#define    PowerModeCFG_PowerOVSel_AllP_PN                           	((uint32_t)(0x1UL<<12)) /* negitive */

#define    PowerModeCFG_AccuMode_HarP                           		((uint32_t)(0x3UL<<10)) /* harmonic active energy calculate mode select */
#define    PowerModeCFG_AccuMode_HarP_0                           		((uint32_t)(0x0UL<<10)) /* mode 0 */
#define    PowerModeCFG_AccuMode_HarP_1                           		((uint32_t)(0x1UL<<10)) /* mode 1 */
#define    PowerModeCFG_AccuMode_HarP_2                           		((uint32_t)(0x2UL<<10)) /* mode 2 */
#define    PowerModeCFG_AccuMode_HarP_3                           		((uint32_t)(0x3UL<<10)) /* mode 3 */

#define    PowerModeCFG_AccuMode_FundQ                           		((uint32_t)(0x3UL<<8)) /* fundamental reactive energy calculate mode select */
#define    PowerModeCFG_AccuMode_FundQ_0                           		((uint32_t)(0x0UL<<8)) /* mode 0 */
#define    PowerModeCFG_AccuMode_FundQ_1                           		((uint32_t)(0x1UL<<8)) /* mode 1 */
#define    PowerModeCFG_AccuMode_FundQ_2                           		((uint32_t)(0x2UL<<8)) /* mode 2 */
#define    PowerModeCFG_AccuMode_FundQ_3                           		((uint32_t)(0x3UL<<8)) /* mode 3 */

#define    PowerModeCFG_AccuMode_FundP                           		((uint32_t)(0x3UL<<6)) /* fundamental active energy calculate mode select */
#define    PowerModeCFG_AccuMode_FundP_0                           		((uint32_t)(0x0UL<<6)) /* mode 0 */
#define    PowerModeCFG_AccuMode_FundP_1                           		((uint32_t)(0x1UL<<6)) /* mode 1 */
#define    PowerModeCFG_AccuMode_FundP_2                           		((uint32_t)(0x2UL<<6)) /* mode 2 */
#define    PowerModeCFG_AccuMode_FundP_3                           		((uint32_t)(0x3UL<<6)) /* mode 3 */

#define    PowerModeCFG_AccuMode_S                                		((uint32_t)(0x3UL<<4)) /* apparent energy calculate mode select */
#define    PowerModeCFG_AccuMode_S_0                                	((uint32_t)(0x0UL<<4)) /* mode 0 */
#define    PowerModeCFG_AccuMode_S_1                                	((uint32_t)(0x1UL<<4)) /* mode 1 */
#define    PowerModeCFG_AccuMode_S_2                                	((uint32_t)(0x2UL<<4)) /* mode 2 */
#define    PowerModeCFG_AccuMode_S_3                                	((uint32_t)(0x3UL<<4)) /* mode 3 */

#define    PowerModeCFG_AccuMode_AllQ                            		((uint32_t)(0x3UL<<2)) /* all reactive energy calculate mode select */
#define    PowerModeCFG_AccuMode_AllQ_0                            		((uint32_t)(0x0UL<<2)) /* mode 0 */
#define    PowerModeCFG_AccuMode_AllQ_1                            		((uint32_t)(0x1UL<<2)) /* mode 1 */
#define    PowerModeCFG_AccuMode_AllQ_2                            		((uint32_t)(0x2UL<<2)) /* mode 2 */
#define    PowerModeCFG_AccuMode_AllQ_3                            		((uint32_t)(0x3UL<<2)) /* mode 3 */

#define    PowerModeCFG_AccuMode_AllP                            		((uint32_t)(0x3UL<<0)) /* all active energy calculate mode select */
#define    PowerModeCFG_AccuMode_AllP_0                            		((uint32_t)(0x0UL<<0)) /* mode 0 */
#define    PowerModeCFG_AccuMode_AllP_1                            		((uint32_t)(0x1UL<<0)) /* mode 1 */
#define    PowerModeCFG_AccuMode_AllP_2                            		((uint32_t)(0x2UL<<0)) /* mode 2 */
#define    PowerModeCFG_AccuMode_AllP_3                            		((uint32_t)(0x3UL<<0)) /* mode 3 */

/**************************  Bit definition for  CFCFG1 register  *******************************************************************/
#define    CFCFG1_IO2                                     				((uint32_t)(0x1fUL<<16)) /* PLUS IO 2 output select*/
#define    CFCFG1_IO2_PN4                                     			((uint32_t)(0x0UL<<16))
#define    CFCFG1_IO2_P4                                      			((uint32_t)(0x1UL<<16))
#define    CFCFG1_IO2_N4                                      			((uint32_t)(0x2UL<<16))
#define    CFCFG1_IO2_PN1                                    			((uint32_t)(0x3UL<<16))
#define    CFCFG1_IO2_P1                                      			((uint32_t)(0x4UL<<16))
#define    CFCFG1_IO2_N1                                      			((uint32_t)(0x5UL<<16))
#define    CFCFG1_IO2_PN2                                     			((uint32_t)(0x6UL<<16))
#define    CFCFG1_IO2_P2                                      			((uint32_t)(0x7UL<<16))
#define    CFCFG1_IO2_N2                                      			((uint32_t)(0x8UL<<16))
#define    CFCFG1_IO2_PN3                                     			((uint32_t)(0x9UL<<16))
#define    CFCFG1_IO2_P3                                      			((uint32_t)(0xAUL<<16))
#define    CFCFG1_IO2_N3                                      			((uint32_t)(0xBUL<<16))
#define    CFCFG1_IO2_PN5                                     			((uint32_t)(0xCUL<<16))
#define    CFCFG1_IO2_P5                                      			((uint32_t)(0xDUL<<16))
#define    CFCFG1_IO2_N5                                      			((uint32_t)(0xEUL<<16))
#define    CFCFG1_IO2_PN6                                     			((uint32_t)(0xFUL<<16))
#define    CFCFG1_IO2_P6                                      			((uint32_t)(0x10UL<<16))
#define    CFCFG1_IO2_N6                                      			((uint32_t)(0x11UL<<16))

#define    CFCFG1_IO1                                      				((uint32_t)(0x1fUL<<8))  /* PLUS IO 1 output select*/
#define    CFCFG1_IO1_PN2                                      			((uint32_t)(0x0UL<<8))
#define    CFCFG1_IO1_P2                                       			((uint32_t)(0x1UL<<8))
#define    CFCFG1_IO1_N2                                       			((uint32_t)(0x2UL<<8))
#define    CFCFG1_IO1_PN1                                      			((uint32_t)(0x3UL<<8))
#define    CFCFG1_IO1_P1                                       			((uint32_t)(0x4UL<<8))
#define    CFCFG1_IO1_N1                                       			((uint32_t)(0x5UL<<8))
#define    CFCFG1_IO1_PN3                                      			((uint32_t)(0x6UL<<8))
#define    CFCFG1_IO1_P3                                       			((uint32_t)(0x7UL<<8))
#define    CFCFG1_IO1_N3                                       			((uint32_t)(0x8UL<<8))
#define    CFCFG1_IO1_PN4                                      			((uint32_t)(0x9UL<<8))
#define    CFCFG1_IO1_P4                                       			((uint32_t)(0xAUL<<8))
#define    CFCFG1_IO1_N4                                       			((uint32_t)(0xBUL<<8))
#define    CFCFG1_IO1_PN5                                      			((uint32_t)(0xCUL<<8))
#define    CFCFG1_IO1_P5                                       			((uint32_t)(0xDUL<<8))
#define    CFCFG1_IO1_N5                                       			((uint32_t)(0xEUL<<8))
#define    CFCFG1_IO1_PN6                                      			((uint32_t)(0xFUL<<8))
#define    CFCFG1_IO1_P6                                       			((uint32_t)(0x10UL<<8))
#define    CFCFG1_IO1_N6                                       			((uint32_t)(0x11UL<<8))

#define    CFCFG1_IO0                                      				((uint32_t)(0x1fUL<<0))  /* PLUS IO 0 output select*/
#define    CFCFG1_IO0_PN1                                      			((uint32_t)(0x0UL<<0))
#define    CFCFG1_IO0_P1                                      			((uint32_t)(0x1UL<<0))
#define    CFCFG1_IO0_N1                                      			((uint32_t)(0x2UL<<0))
#define    CFCFG1_IO0_PN2                                      			((uint32_t)(0x3UL<<0))
#define    CFCFG1_IO0_P2                                       			((uint32_t)(0x4UL<<0))
#define    CFCFG1_IO0_N2                                       			((uint32_t)(0x5UL<<0))
#define    CFCFG1_IO0_PN3                                      			((uint32_t)(0x6UL<<0))
#define    CFCFG1_IO0_P3                                       			((uint32_t)(0x7UL<<0))
#define    CFCFG1_IO0_N3                                       			((uint32_t)(0x8UL<<0))
#define    CFCFG1_IO0_PN4                                      			((uint32_t)(0x9UL<<0))
#define    CFCFG1_IO0_P4                                       			((uint32_t)(0xAUL<<0))
#define    CFCFG1_IO0_N4                                       			((uint32_t)(0xBUL<<0))
#define    CFCFG1_IO0_PN5                                      			((uint32_t)(0xCUL<<0))
#define    CFCFG1_IO0_P5                                       			((uint32_t)(0xDUL<<0))
#define    CFCFG1_IO0_N5                                       			((uint32_t)(0xEUL<<0))
#define    CFCFG1_IO0_PN6                                      			((uint32_t)(0xFUL<<0))
#define    CFCFG1_IO0_P6                                       			((uint32_t)(0x10UL<<0))
#define    CFCFG1_IO0_N6                                       			((uint32_t)(0x11UL<<0))

/**************************  Bit definition for  CFCFG2 register  *******************************************************************/
#define    CFCFG2_IO4                                      				((uint32_t)(0x1fUL<<8)) /* PLUS IO 4 output select*/
#define    CFCFG2_IO4_N6                                      			((uint32_t)(0x0UL<<8))
#define    CFCFG2_IO4_PN6                                      			((uint32_t)(0x1UL<<8))
#define    CFCFG2_IO4_P6                                      			((uint32_t)(0x2UL<<8))
#define    CFCFG2_IO4_PN1                                       		((uint32_t)(0x3UL<<8))
#define    CFCFG2_IO4_P1                                        		((uint32_t)(0x4UL<<8))
#define    CFCFG2_IO4_N1                                        		((uint32_t)(0x5UL<<8))
#define    CFCFG2_IO4_PN2                                       		((uint32_t)(0x6UL<<8))
#define    CFCFG2_IO4_P2                                        		((uint32_t)(0x7UL<<8))
#define    CFCFG2_IO4_N2                                        		((uint32_t)(0x8UL<<8))
#define    CFCFG2_IO4_PN3                                       		((uint32_t)(0x9UL<<8))
#define    CFCFG2_IO4_P3                                        		((uint32_t)(0xAUL<<8))
#define    CFCFG2_IO4_N3                                        		((uint32_t)(0xBUL<<8))
#define    CFCFG2_IO4_PN4                                       		((uint32_t)(0xCUL<<8))
#define    CFCFG2_IO4_P4                                        		((uint32_t)(0xDUL<<8))
#define    CFCFG2_IO4_N4                                        		((uint32_t)(0xEUL<<8))
#define    CFCFG2_IO4_PN5                                       		((uint32_t)(0xFUL<<8))
#define    CFCFG2_IO4_P5                                        		((uint32_t)(0x10UL<<8))
#define    CFCFG2_IO4_N5                                        		((uint32_t)(0x11UL<<8))

#define    CFCFG2_IO3                                      				((uint32_t)(0x1fUL<<0)) /* PLUS IO 3 output select*/
#define    CFCFG2_IO3_P6                                      			((uint32_t)(0x0UL<<0))
#define    CFCFG2_IO3_PN6                                      			((uint32_t)(0x1UL<<0))
#define    CFCFG2_IO3_N6                                      			((uint32_t)(0x2UL<<0))
#define    CFCFG2_IO3_PN1                                       		((uint32_t)(0x3UL<<0))
#define    CFCFG2_IO3_P1                                        		((uint32_t)(0x4UL<<0))
#define    CFCFG2_IO3_N1                                        		((uint32_t)(0x5UL<<0))
#define    CFCFG2_IO3_PN2                                       		((uint32_t)(0x6UL<<0))
#define    CFCFG2_IO3_P2                                        		((uint32_t)(0x7UL<<0))
#define    CFCFG2_IO3_N2                                        		((uint32_t)(0x8UL<<0))
#define    CFCFG2_IO3_PN3                                       		((uint32_t)(0x9UL<<0))
#define    CFCFG2_IO3_P3                                        		((uint32_t)(0xAUL<<0))
#define    CFCFG2_IO3_N3                                        		((uint32_t)(0xBUL<<0))
#define    CFCFG2_IO3_PN4                                       		((uint32_t)(0xCUL<<0))
#define    CFCFG2_IO3_P4                                        		((uint32_t)(0xDUL<<0))
#define    CFCFG2_IO3_N4                                        		((uint32_t)(0xEUL<<0))
#define    CFCFG2_IO3_PN5                                       		((uint32_t)(0xFUL<<0))
#define    CFCFG2_IO3_P5                                        		((uint32_t)(0x10UL<<0))
#define    CFCFG2_IO3_N5                                        		((uint32_t)(0x11UL<<0))

/**************************  Bit definition for  FlickerCfg register  *******************************************************************/
#define    FlickerCfg_bpf_lshift                          				((uint32_t)(0x7UL<<11)) /* voltage flicker second filter left shifit select */
#define    FlickerCfg_hpf_lshift                           				((uint32_t)(0x7UL<<8))  /* voltage flicker first filter left shifit select */
#define    FlickerCfg_UpdRate                             				((uint32_t)(0x1fUL<<3)) /* voltage flicker update rate select */
#if defined  HT762x
#define    FlickerCfg_FlickerEn                                 		((uint32_t)(0x7UL<<0)) 
#define    FlickerCfg_FlickerUcEn                                 		((uint32_t)(0x1UL<<2)) /* uc flicker enable*/
#define    FlickerCfg_FlickerUbEn                                 		((uint32_t)(0x1UL<<1)) /* ub flicker enable*/
#define    FlickerCfg_FlickerUaEn                                 		((uint32_t)(0x1UL<<0)) /* ua flicker enable*/
#else
#define    FlickerCfg_FlickerUEn                                 		((uint32_t)(0x1UL<<0)) /* u flicker enable*/
#endif
/**************************  Bit definition for  FundHarCFG register  *******************************************************************/
#if defined  HT762x
#define    FundHarCFG_InHarFilterShift                            		((uint32_t)(0x7UL<<8)) /*IN CHANNEL harmonic filter shift select */
#define    FundHarCFG_InHarFilterShift_1                              	((uint32_t)(0x0UL<<8)) /* 1 times */
#define    FundHarCFG_InHarFilterShift_2                              	((uint32_t)(0x1UL<<8)) /* 2 times */
#define    FundHarCFG_InHarFilterShift_4                              	((uint32_t)(0x2UL<<8)) /* 4 times */
#define    FundHarCFG_InHarFilterShift_8                              	((uint32_t)(0x3UL<<8)) /* 8 times */
#define    FundHarCFG_InHarFilterShift_16                             	((uint32_t)(0x4UL<<8)) /* 16 times */
#define    FundHarCFG_InHarFilterShift_32                             	((uint32_t)(0x5UL<<8)) /* 32 times ,Har_AlgMode select Har_AlgMode0,not surport */
#define    FundHarCFG_InHarFilterShift_64                             	((uint32_t)(0x6UL<<8)) /* 64 times ,Har_AlgMode select Har_AlgMode0,not surport */
#define    FundHarCFG_InHarFilterShift_128                            	((uint32_t)(0x7UL<<8)) /* 128 times ,Har_AlgMode select Har_AlgMode0,not surport */

#define    FundHarCFG_InMultiFunc_En                              		((uint32_t)(0x1UL<<7)) /* In channel filter multi-function enable */

#define    FundHarCFG_InMultiFuncSel                              		((uint32_t)(0x1UL<<6)) /* In channel filter function select */
#define    FundHarCFG_InMultiFuncSel_HAR                              	((uint32_t)(0x0UL<<6)) /* calculate harmonic data */
#define    FundHarCFG_InMultiFuncSel_OTHER                              ((uint32_t)(0x1UL<<6)) /* multi-function or other function */
#endif
#define    FundHarCFG_HarFilter_Shift                             		((uint32_t)(0x7UL<<3)) /* total harmonic and flicker filter shift select */
#define    FundHarCFG_HarFilter_Shift_1                             	((uint32_t)(0x0UL<<3)) /* 1 times */
#define    FundHarCFG_HarFilter_Shift_2                             	((uint32_t)(0x1UL<<3)) /* 2 times */
#define    FundHarCFG_HarFilter_Shift_4                             	((uint32_t)(0x2UL<<3)) /* 4 times */
#define    FundHarCFG_HarFilter_Shift_8                             	((uint32_t)(0x3UL<<3)) /* 8 times */
#define    FundHarCFG_HarFilter_Shift_16                             	((uint32_t)(0x4UL<<3)) /* 16 times */
#define    FundHarCFG_HarFilter_Shift_32                             	((uint32_t)(0x5UL<<3)) /* 32 times ,Har_AlgMode select Har_AlgMode0,not surport */
#define    FundHarCFG_HarFilter_Shift_64                             	((uint32_t)(0x6UL<<3)) /* 64 times ,Har_AlgMode select Har_AlgMode0,not surport */
#define    FundHarCFG_HarFilter_Shift_128                             	((uint32_t)(0x7UL<<3)) /* 128 times ,Har_AlgMode select Har_AlgMode0,not surport */

#define    FundHarCFG_Har_AlgMode                                 		((uint32_t)(0x1UL<<2)) /* calculate total harmonic way select */
#define    FundHarCFG_Har_AlgMode0                                 		((uint32_t)(0x0UL<<2)) /* har = all - fund */
#define    FundHarCFG_Har_AlgMode1                                 		((uint32_t)(0x1UL<<2)) /* harmonic filter */

#define    FundHarCFG_All_En                                      		((uint32_t)(0x1UL<<1)) /* all wave filter enable */
#define    FundHarCFG_FundHar_Func_En                             		((uint32_t)(0x1UL<<0)) /* fundamental and harmonic function enable */
/**************************  Bit definition for  EMUIE1 register  *******************************************************************/
#if defined  HT762x
#define    EMUIE1_ALL                                      		        ((uint32_t)(0xffffffff))
#else
#define    EMUIE1_ALL                                      		        ((uint32_t)(0xbe419fff))
#endif
#define    EMUIE1_RMSItOVIE                                      		((uint32_t)(0x1UL<<31))
#if defined  HT762x
#define    EMUIE1_RMSUtOVIE                                      		((uint32_t)(0x1UL<<30))
#endif
#define    EMUIE1_RMSTUpdateIE                                   		((uint32_t)(0x1UL<<29))
#define    EMUIE1_RMSUpdateIE                                    		((uint32_t)(0x1UL<<28))
#define    EMUIE1_PowerUpdateIE                                  		((uint32_t)(0x1UL<<27))
#define    EMUIE1_SPLUpdateIE                                    		((uint32_t)(0x1UL<<26))
#define    EMUIE1_EnergyOVIE                                     		((uint32_t)(0x1UL<<25))
#if defined  HT762x
#define    EMUIE1_ZCUcLostIE                                     		((uint32_t)(0x1UL<<24))
#define    EMUIE1_ZCUbLostIE                                     		((uint32_t)(0x1UL<<23))
#define    EMUIE1_ZCUaLostIE                                     		((uint32_t)(0x1UL<<22))
#define    EMUIE1_CMPcIE                                         		((uint32_t)(0x1UL<<21))
#define    EMUIE1_CMPbIE                                         		((uint32_t)(0x1UL<<20))
#define    EMUIE1_CMPaIE                                         		((uint32_t)(0x1UL<<19))
#define    EMUIE1_ZCInIE                                         		((uint32_t)(0x1UL<<18))
#define    EMUIE1_ZCIcIE                                         		((uint32_t)(0x1UL<<17))
#define    EMUIE1_ZCIbIE                                         		((uint32_t)(0x1UL<<16))
#define    EMUIE1_ZCIaIE                                         		((uint32_t)(0x1UL<<15))
#define    EMUIE1_ZCUcIE                                         		((uint32_t)(0x1UL<<14))
#define    EMUIE1_ZCUbIE                                         		((uint32_t)(0x1UL<<13))
#define    EMUIE1_ZCUaIE                                         		((uint32_t)(0x1UL<<12))
#else
#define    EMUIE1_ZCULostIE                                     		((uint32_t)(0x1UL<<22))
#define    EMUIE1_ZCI2IE                                         		((uint32_t)(0x1UL<<16))
#define    EMUIE1_ZCI1IE                                         		((uint32_t)(0x1UL<<15))
#define    EMUIE1_ZCUIE                                         		((uint32_t)(0x1UL<<12))
#endif
#define    EMUIE1_HarP_NegCFIE                                   		((uint32_t)(0x1UL<<11))
#define    EMUIE1_FundQ_NegCFIE                                  		((uint32_t)(0x1UL<<10))
#define    EMUIE1_FundP_NegCFIE                                   		((uint32_t)(0x1UL<<9))
#define    EMUIE1_S_NegCFIE                                       		((uint32_t)(0x1UL<<8))
#define    EMUIE1_AllQ_NegCFIE                                    		((uint32_t)(0x1UL<<7))
#define    EMUIE1_AllP_NegCFIE                                    		((uint32_t)(0x1UL<<6))
#define    EMUIE1_HarP_PosCFIE                                    		((uint32_t)(0x1UL<<5))
#define    EMUIE1_FundQ_PosCFIE                                   		((uint32_t)(0x1UL<<4))
#define    EMUIE1_FundP_PosCFIE                                   		((uint32_t)(0x1UL<<3))
#define    EMUIE1_S_PosCFIE                                       		((uint32_t)(0x1UL<<2))
#define    EMUIE1_AllQ_PosCFIE                                    		((uint32_t)(0x1UL<<1))
#define    EMUIE1_AllP_PosCFIE                                    		((uint32_t)(0x1UL<<0))
/**************************  Bit definition for  EMUIE2 register  *******************************************************************/
#if defined  HT762x
#define    EMUIE2_ALL                                      		        ((uint32_t)(0x7fffffff))
#define    EMUIE2_VpupdInIE                                      		((uint32_t)(0x1UL<<30))
#define    EMUIE2_VpupdIcIE                                      		((uint32_t)(0x1UL<<29))
#define    EMUIE2_VpupdIbIE                                      		((uint32_t)(0x1UL<<28))
#define    EMUIE2_VpupdIaIE                                      		((uint32_t)(0x1UL<<27))
#define    EMUIE2_VpupdUcIE                                      		((uint32_t)(0x1UL<<26))
#define    EMUIE2_VpupdUbIE                                      		((uint32_t)(0x1UL<<25))
#define    EMUIE2_VpupdUaIE                                      		((uint32_t)(0x1UL<<24))
#define    EMUIE2_InOVEndIE                                      		((uint32_t)(0x1UL<<23))
#define    EMUIE2_IcOVEndIE                                      		((uint32_t)(0x1UL<<22))
#define    EMUIE2_IbOVEndIE                                      		((uint32_t)(0x1UL<<21))
#define    EMUIE2_IaOVEndIE                                      		((uint32_t)(0x1UL<<20))
#define    EMUIE2_InOVIE                                         		((uint32_t)(0x1UL<<19))
#define    EMUIE2_IcOVIE                                         		((uint32_t)(0x1UL<<18))
#define    EMUIE2_IbOVIE                                         		((uint32_t)(0x1UL<<17))
#define    EMUIE2_IaOVIE                                         		((uint32_t)(0x1UL<<16))
#define    EMUIE2_UcINTEndIE                                     		((uint32_t)(0x1UL<<15))
#define    EMUIE2_UbINTEndIE                                     		((uint32_t)(0x1UL<<14))
#define    EMUIE2_UaINTEndIE                                     		((uint32_t)(0x1UL<<13))
#define    EMUIE2_INTUIE                                         		((uint32_t)(0x1UL<<12))
#define    EMUIE2_INTUcIE                                        		((uint32_t)(0x1UL<<11))
#define    EMUIE2_INTUbIE                                        		((uint32_t)(0x1UL<<10))
#define    EMUIE2_INTUaIE                                         		((uint32_t)(0x1UL<<9))
#define    EMUIE2_UcEndIE                                         		((uint32_t)(0x1UL<<8))
#define    EMUIE2_UbEndIE                                         		((uint32_t)(0x1UL<<7))
#define    EMUIE2_UaEndIE                                         		((uint32_t)(0x1UL<<6))
#define    EMUIE2_SagUcIE                                         		((uint32_t)(0x1UL<<5))
#define    EMUIE2_SagUbIE                                         		((uint32_t)(0x1UL<<4))
#define    EMUIE2_SagUaIE                                         		((uint32_t)(0x1UL<<3))
#define    EMUIE2_PeakUcIE                                        		((uint32_t)(0x1UL<<2))
#define    EMUIE2_PeakUbIE                                        		((uint32_t)(0x1UL<<1))
#define    EMUIE2_PeakUaIE                                        		((uint32_t)(0x1UL<<0))
#else
#define    EMUIE2_ALL                                      		        ((uint32_t)(0x19332249))
#define    EMUIE2_VpupdI2IE                                      		((uint32_t)(0x1UL<<28))
#define    EMUIE2_VpupdI1IE                                      		((uint32_t)(0x1UL<<27))
#define    EMUIE2_VpupdUIE                                      		((uint32_t)(0x1UL<<24))
#define    EMUIE2_I2OVEndIE                                      		((uint32_t)(0x1UL<<21))
#define    EMUIE2_I1OVEndIE                                      		((uint32_t)(0x1UL<<20))
#define    EMUIE2_I2OVIE                                         		((uint32_t)(0x1UL<<17))
#define    EMUIE2_I1OVIE                                         		((uint32_t)(0x1UL<<16))
#define    EMUIE2_UINTEndIE                                     		((uint32_t)(0x1UL<<13))
#define    EMUIE2_INTUIE                                         		((uint32_t)(0x1UL<<9))
#define    EMUIE2_UEndIE                                         		((uint32_t)(0x1UL<<6))
#define    EMUIE2_SagUIE                                         		((uint32_t)(0x1UL<<3))
#define    EMUIE2_PeakUIE                                        		((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  EMUIF1 register  *******************************************************************/
#if defined  HT762x
#define    EMUIF1_ALL                                      		        ((uint32_t)(0xffffffff))
#else
#define    EMUIF1_ALL                                      		        ((uint32_t)(0xbe419fff))
#endif
#define    EMUIF1_RMSItOVIF                                      		((uint32_t)(0x1UL<<31))
#if defined  HT762x
#define    EMUIF1_RMSUtOVIF                                      		((uint32_t)(0x1UL<<30))
#endif
#define    EMUIF1_RMSTUpdateIF                                   		((uint32_t)(0x1UL<<29))
#define    EMUIF1_RMSUpdateIF                                    		((uint32_t)(0x1UL<<28))
#define    EMUIF1_PowerUpdateIF                                  		((uint32_t)(0x1UL<<27))
#define    EMUIF1_SPLUpdateIF                                    		((uint32_t)(0x1UL<<26))
#define    EMUIF1_EnergyOVIF                                     		((uint32_t)(0x1UL<<25))
#if defined  HT762x
#define    EMUIF1_ZCUcLostIF                                     		((uint32_t)(0x1UL<<24))
#define    EMUIF1_ZCUbLostIF                                     		((uint32_t)(0x1UL<<23))
#define    EMUIF1_ZCUaLostIF                                     		((uint32_t)(0x1UL<<22))
#define    EMUIF1_CMPcIF                                         		((uint32_t)(0x1UL<<21))
#define    EMUIF1_CMPbIF                                         		((uint32_t)(0x1UL<<20))
#define    EMUIF1_CMPaIF                                         		((uint32_t)(0x1UL<<19))
#define    EMUIF1_ZCInIF                                         		((uint32_t)(0x1UL<<18))
#define    EMUIF1_ZCIcIF                                         		((uint32_t)(0x1UL<<17))
#define    EMUIF1_ZCIbIF                                         		((uint32_t)(0x1UL<<16))
#define    EMUIF1_ZCIaIF                                         		((uint32_t)(0x1UL<<15))
#define    EMUIF1_ZCUcIF                                         		((uint32_t)(0x1UL<<14))
#define    EMUIF1_ZCUbIF                                         		((uint32_t)(0x1UL<<13))
#define    EMUIF1_ZCUaIF                                         		((uint32_t)(0x1UL<<12))
#else
#define    EMUIF1_ZCULostIF                                     		((uint32_t)(0x1UL<<22))
#define    EMUIF1_ZCI2IF                                         		((uint32_t)(0x1UL<<16))
#define    EMUIF1_ZCI1IF                                         		((uint32_t)(0x1UL<<15))
#define    EMUIF1_ZCUIF                                         		((uint32_t)(0x1UL<<12))
#endif
#define    EMUIF1_HarP_NegCFIF                                   		((uint32_t)(0x1UL<<11))
#define    EMUIF1_FundQ_NegCFIF                                  		((uint32_t)(0x1UL<<10))
#define    EMUIF1_FundP_NegCFIF                                   		((uint32_t)(0x1UL<<9))
#define    EMUIF1_S_NegCFIF                                       		((uint32_t)(0x1UL<<8))
#define    EMUIF1_AllQ_NegCFIF                                    		((uint32_t)(0x1UL<<7))
#define    EMUIF1_AllP_NegCFIF                                    		((uint32_t)(0x1UL<<6))
#define    EMUIF1_HarP_PosCFIF                                    		((uint32_t)(0x1UL<<5))
#define    EMUIF1_FundQ_PosCFIF                                   		((uint32_t)(0x1UL<<4))
#define    EMUIF1_FundP_PosCFIF                                   		((uint32_t)(0x1UL<<3))
#define    EMUIF1_S_PosCFIF                                       		((uint32_t)(0x1UL<<2))
#define    EMUIF1_AllQ_PosCFIF                                    		((uint32_t)(0x1UL<<1))
#define    EMUIF1_AllP_PosCFIF                                    		((uint32_t)(0x1UL<<0))
/**************************  Bit definition for  EMUIF2 register  *******************************************************************/
#if defined  HT762x
#define    EMUIF2_ALL                                      		        ((uint32_t)(0x7fffffff))
#define    EMUIF2_VpupdInIF                                      		((uint32_t)(0x1UL<<30))
#define    EMUIF2_VpupdIcIF                                      		((uint32_t)(0x1UL<<29))
#define    EMUIF2_VpupdIbIF                                      		((uint32_t)(0x1UL<<28))
#define    EMUIF2_VpupdIaIF                                      		((uint32_t)(0x1UL<<27))
#define    EMUIF2_VpupdUcIF                                      		((uint32_t)(0x1UL<<26))
#define    EMUIF2_VpupdUbIF                                      		((uint32_t)(0x1UL<<25))
#define    EMUIF2_VpupdUaIF                                      		((uint32_t)(0x1UL<<24))
#define    EMUIF2_InOVEndIF                                      		((uint32_t)(0x1UL<<23))
#define    EMUIF2_IcOVEndIF                                      		((uint32_t)(0x1UL<<22))
#define    EMUIF2_IbOVEndIF                                      		((uint32_t)(0x1UL<<21))
#define    EMUIF2_IaOVEndIF                                      		((uint32_t)(0x1UL<<20))
#define    EMUIF2_InOVIF                                         		((uint32_t)(0x1UL<<19))
#define    EMUIF2_IcOVIF                                         		((uint32_t)(0x1UL<<18))
#define    EMUIF2_IbOVIF                                         		((uint32_t)(0x1UL<<17))
#define    EMUIF2_IaOVIF                                         		((uint32_t)(0x1UL<<16))
#define    EMUIF2_UcINTEndIF                                     		((uint32_t)(0x1UL<<15))
#define    EMUIF2_UbINTEndIF                                     		((uint32_t)(0x1UL<<14))
#define    EMUIF2_UaINTEndIF                                     		((uint32_t)(0x1UL<<13))
#define    EMUIF2_INTUIF                                         		((uint32_t)(0x1UL<<12))
#define    EMUIF2_INTUcIF                                        		((uint32_t)(0x1UL<<11))
#define    EMUIF2_INTUbIF                                        		((uint32_t)(0x1UL<<10))
#define    EMUIF2_INTUaIF                                         		((uint32_t)(0x1UL<<9))
#define    EMUIF2_UcEndIF                                         		((uint32_t)(0x1UL<<8))
#define    EMUIF2_UbEndIF                                         		((uint32_t)(0x1UL<<7))
#define    EMUIF2_UaEndIF                                         		((uint32_t)(0x1UL<<6))
#define    EMUIF2_SagUcIF                                         		((uint32_t)(0x1UL<<5))
#define    EMUIF2_SagUbIF                                         		((uint32_t)(0x1UL<<4))
#define    EMUIF2_SagUaIF                                         		((uint32_t)(0x1UL<<3))
#define    EMUIF2_PeakUcIF                                        		((uint32_t)(0x1UL<<2))
#define    EMUIF2_PeakUbIF                                        		((uint32_t)(0x1UL<<1))
#define    EMUIF2_PeakUaIF                                        		((uint32_t)(0x1UL<<0))
#else
#define    EMUIF2_ALL                                      		        ((uint32_t)(0x19332249))
#define    EMUIF2_VpupdI2IF                                      		((uint32_t)(0x1UL<<28))
#define    EMUIF2_VpupdI1IF                                      		((uint32_t)(0x1UL<<27))
#define    EMUIF2_VpupdUIF                                      		((uint32_t)(0x1UL<<24))
#define    EMUIF2_I2OVEndIF                                      		((uint32_t)(0x1UL<<21))
#define    EMUIF2_I1OVEndIF                                      		((uint32_t)(0x1UL<<20))
#define    EMUIF2_I2OVIF                                         		((uint32_t)(0x1UL<<17))
#define    EMUIF2_I1OVIF                                         		((uint32_t)(0x1UL<<16))
#define    EMUIF2_UINTEndIF                                     		((uint32_t)(0x1UL<<13))
#define    EMUIF2_INTUIF                                         		((uint32_t)(0x1UL<<9))
#define    EMUIF2_UEndIF                                         		((uint32_t)(0x1UL<<6))
#define    EMUIF2_SagUIF                                         		((uint32_t)(0x1UL<<3))
#define    EMUIF2_PeakUIF                                        		((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  EMUIF_EnergyPOVIF register  *******************************************************************/
#if defined  HT762x
#define    EMUIF_EnergyPOVIF_ALL                                ((uint32_t)(0x00ffffff))
#define    EMUIF_EnergyPOVIF_HarEPt                     		((uint32_t)(0x1UL<<23))
#define    EMUIF_EnergyPOVIF_HarEPc                     		((uint32_t)(0x1UL<<22))
#define    EMUIF_EnergyPOVIF_HarEPb                     		((uint32_t)(0x1UL<<21))
#define    EMUIF_EnergyPOVIF_HarEPa                     		((uint32_t)(0x1UL<<20))
#define    EMUIF_EnergyPOVIF_FundEQt                    		((uint32_t)(0x1UL<<19))
#define    EMUIF_EnergyPOVIF_FundEQc                    		((uint32_t)(0x1UL<<18))
#define    EMUIF_EnergyPOVIF_FundEQb                    		((uint32_t)(0x1UL<<17))
#define    EMUIF_EnergyPOVIF_FundEQa                    		((uint32_t)(0x1UL<<16))
#define    EMUIF_EnergyPOVIF_FundEPt                    		((uint32_t)(0x1UL<<15))
#define    EMUIF_EnergyPOVIF_FundEPc                    		((uint32_t)(0x1UL<<14))
#define    EMUIF_EnergyPOVIF_FundEPb                    		((uint32_t)(0x1UL<<13))
#define    EMUIF_EnergyPOVIF_FundEPa                    		((uint32_t)(0x1UL<<12))
#define    EMUIF_EnergyPOVIF_ESt                        		((uint32_t)(0x1UL<<11))
#define    EMUIF_EnergyPOVIF_ESc                        		((uint32_t)(0x1UL<<10))
#define    EMUIF_EnergyPOVIF_ESb                         		((uint32_t)(0x1UL<<9))
#define    EMUIF_EnergyPOVIF_ESa                         		((uint32_t)(0x1UL<<8))
#define    EMUIF_EnergyPOVIF_AllEQt                      		((uint32_t)(0x1UL<<7))
#define    EMUIF_EnergyPOVIF_AllEQc                      		((uint32_t)(0x1UL<<6))
#define    EMUIF_EnergyPOVIF_AllEQb                      		((uint32_t)(0x1UL<<5))
#define    EMUIF_EnergyPOVIF_AllEQa                      		((uint32_t)(0x1UL<<4))
#define    EMUIF_EnergyPOVIF_AllEPt                      		((uint32_t)(0x1UL<<3))
#define    EMUIF_EnergyPOVIF_AllEPc                      		((uint32_t)(0x1UL<<2))
#define    EMUIF_EnergyPOVIF_AllEPb                      		((uint32_t)(0x1UL<<1))
#define    EMUIF_EnergyPOVIF_AllEPa                      		((uint32_t)(0x1UL<<0))
#else
#define    EMUIF_EnergyPOVIF_ALL                                ((uint32_t)(0x00bbbbbb))
#define    EMUIF_EnergyPOVIF_HarEPt                     		((uint32_t)(0x1UL<<23))
#define    EMUIF_EnergyPOVIF_HarEP2                     		((uint32_t)(0x1UL<<21))
#define    EMUIF_EnergyPOVIF_HarEP1                     		((uint32_t)(0x1UL<<20))
#define    EMUIF_EnergyPOVIF_FundEQt                    		((uint32_t)(0x1UL<<19))
#define    EMUIF_EnergyPOVIF_FundEQ2                    		((uint32_t)(0x1UL<<17))
#define    EMUIF_EnergyPOVIF_FundEQ1                    		((uint32_t)(0x1UL<<16))
#define    EMUIF_EnergyPOVIF_FundEPt                    		((uint32_t)(0x1UL<<15))
#define    EMUIF_EnergyPOVIF_FundEP2                    		((uint32_t)(0x1UL<<13))
#define    EMUIF_EnergyPOVIF_FundEP1                    		((uint32_t)(0x1UL<<12))
#define    EMUIF_EnergyPOVIF_ESt                        		((uint32_t)(0x1UL<<11))
#define    EMUIF_EnergyPOVIF_ES2                         		((uint32_t)(0x1UL<<9))
#define    EMUIF_EnergyPOVIF_ES1                         		((uint32_t)(0x1UL<<8))
#define    EMUIF_EnergyPOVIF_AllEQt                      		((uint32_t)(0x1UL<<7))
#define    EMUIF_EnergyPOVIF_AllEQ2                      		((uint32_t)(0x1UL<<5))
#define    EMUIF_EnergyPOVIF_AllEQ1                      		((uint32_t)(0x1UL<<4))
#define    EMUIF_EnergyPOVIF_AllEPt                      		((uint32_t)(0x1UL<<3))
#define    EMUIF_EnergyPOVIF_AllEP2                      		((uint32_t)(0x1UL<<1))
#define    EMUIF_EnergyPOVIF_AllEP1                      		((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  EMUIF_EnergyNOVIF register  *******************************************************************/
#if defined  HT762x
#define    EMUIF_EnergyNOVIF_ALL                                ((uint32_t)(0x00ffffff))
#define    EMUIF_EnergyNOVIF_HarEPt                     		((uint32_t)(0x1UL<<23))
#define    EMUIF_EnergyNOVIF_HarEPc                     		((uint32_t)(0x1UL<<22))
#define    EMUIF_EnergyNOVIF_HarEPb                     		((uint32_t)(0x1UL<<21))
#define    EMUIF_EnergyNOVIF_HarEPa                     		((uint32_t)(0x1UL<<20))
#define    EMUIF_EnergyNOVIF_FundEQt                    		((uint32_t)(0x1UL<<19))
#define    EMUIF_EnergyNOVIF_FundEQc                    		((uint32_t)(0x1UL<<18))
#define    EMUIF_EnergyNOVIF_FundEQb                    		((uint32_t)(0x1UL<<17))
#define    EMUIF_EnergyNOVIF_FundEQa                    		((uint32_t)(0x1UL<<16))
#define    EMUIF_EnergyNOVIF_FundEPt                    		((uint32_t)(0x1UL<<15))
#define    EMUIF_EnergyNOVIF_FundEPc                    		((uint32_t)(0x1UL<<14))
#define    EMUIF_EnergyNOVIF_FundEPb                    		((uint32_t)(0x1UL<<13))
#define    EMUIF_EnergyNOVIF_FundEPa                    		((uint32_t)(0x1UL<<12))
#define    EMUIF_EnergyNOVIF_ESt                        		((uint32_t)(0x1UL<<11))
#define    EMUIF_EnergyNOVIF_ESc                        		((uint32_t)(0x1UL<<10))
#define    EMUIF_EnergyNOVIF_ESb                         		((uint32_t)(0x1UL<<9))
#define    EMUIF_EnergyNOVIF_ESa                         		((uint32_t)(0x1UL<<8))
#define    EMUIF_EnergyNOVIF_AllEQt                      		((uint32_t)(0x1UL<<7))
#define    EMUIF_EnergyNOVIF_AllEQc                      		((uint32_t)(0x1UL<<6))
#define    EMUIF_EnergyNOVIF_AllEQb                      		((uint32_t)(0x1UL<<5))
#define    EMUIF_EnergyNOVIF_AllEQa                      		((uint32_t)(0x1UL<<4))
#define    EMUIF_EnergyNOVIF_AllEPt                      		((uint32_t)(0x1UL<<3))
#define    EMUIF_EnergyNOVIF_AllEPc                      		((uint32_t)(0x1UL<<2))
#define    EMUIF_EnergyNOVIF_AllEPb                      		((uint32_t)(0x1UL<<1))
#define    EMUIF_EnergyNOVIF_AllEPa                      		((uint32_t)(0x1UL<<0))
#else
#define    EMUIF_EnergyNOVIF_ALL                                ((uint32_t)(0x00bbbbbb))
#define    EMUIF_EnergyNOVIF_HarEPt                     		((uint32_t)(0x1UL<<23))
#define    EMUIF_EnergyNOVIF_HarEP2                     		((uint32_t)(0x1UL<<21))
#define    EMUIF_EnergyNOVIF_HarEP1                     		((uint32_t)(0x1UL<<20))
#define    EMUIF_EnergyNOVIF_FundEQt                    		((uint32_t)(0x1UL<<19))
#define    EMUIF_EnergyNOVIF_FundEQ2                    		((uint32_t)(0x1UL<<17))
#define    EMUIF_EnergyNOVIF_FundEQ1                    		((uint32_t)(0x1UL<<16))
#define    EMUIF_EnergyNOVIF_FundEPt                    		((uint32_t)(0x1UL<<15))
#define    EMUIF_EnergyNOVIF_FundEP2                    		((uint32_t)(0x1UL<<13))
#define    EMUIF_EnergyNOVIF_FundEP1                    		((uint32_t)(0x1UL<<12))
#define    EMUIF_EnergyNOVIF_ESt                        		((uint32_t)(0x1UL<<11))
#define    EMUIF_EnergyNOVIF_ES2                         		((uint32_t)(0x1UL<<9))
#define    EMUIF_EnergyNOVIF_ES1                         		((uint32_t)(0x1UL<<8))
#define    EMUIF_EnergyNOVIF_AllEQt                      		((uint32_t)(0x1UL<<7))
#define    EMUIF_EnergyNOVIF_AllEQ2                      		((uint32_t)(0x1UL<<5))
#define    EMUIF_EnergyNOVIF_AllEQ1                      		((uint32_t)(0x1UL<<4))
#define    EMUIF_EnergyNOVIF_AllEPt                      		((uint32_t)(0x1UL<<3))
#define    EMUIF_EnergyNOVIF_AllEP2                      		((uint32_t)(0x1UL<<1))
#define    EMUIF_EnergyNOVIF_AllEP1                      		((uint32_t)(0x1UL<<0))
#endif
/**************************  Bit definition for  EWUIE register  *******************************************************************/
#define    EWUIE_ALL                                    				((uint32_t)(0x7UL<<16))
#define    EWUIE_FlickerUpdIE                                    		((uint32_t)(0x1UL<<18))
#define    EWUIE_SyncDftUpdIE                                     		((uint32_t)(0x1UL<<17))
#define    EWUIE_HpRmsIE                                         		((uint32_t)(0x1UL<<16))
/**************************  Bit definition for  EWUIF register  *******************************************************************/
#define    EWUIF_ALL                                    				((uint32_t)(0x7UL<<16))
#define    EWUIF_FlickerUpdIF                                    		((uint32_t)(0x1UL<<18))
#define    EWUIF_SyncDftUpdIF                                     		((uint32_t)(0x1UL<<17))
#define    EWUIF_HpRmsIF                                          		((uint32_t)(0x1UL<<16))
/**************************  Bit definition for  SYNC_CFG register  *******************************************************************/
#define    SYNC_CFG_Sync_DMA_bw_mode                             		((uint32_t)(0x3UL<<16)) /* sync system output to EMU InterFace bit width select */
#define    SYNC_CFG_Sync_DMA_bw_mode_16                             	((uint32_t)(0x0UL<<16)) /* 16bit */
#define    SYNC_CFG_Sync_DMA_bw_mode_24                             	((uint32_t)(0x1UL<<16)) /* 24bit */
#define    SYNC_CFG_Sync_DMA_bw_mode_32                             	((uint32_t)(0x2UL<<16)) /* 32bit */

#define    SYNC_CFG_RmsUpdHp                                     		((uint32_t)(0x1UL<<15)) /* HALF cycle rms update select */
#define    SYNC_CFG_RmsUpdHp_HALF                                     	((uint32_t)(0x0UL<<15)) /* half cycle time update half cycle rms */
#define    SYNC_CFG_RmsUpdHp_ONE                                     	((uint32_t)(0x1UL<<15)) /* half cycle time update one cycle rms */

#define    SYNC_CFG_SFO_En                                       		((uint32_t)(0x1UL<<14)) /* sync system sfo enable */

#define    SYNC_CFG_SYNC_DisLpf                                  		((uint32_t)(0x1UL<<13)) /* sync system lpf output disable */
#define    SYNC_CFG_SYNC_DFTEn                                   		((uint32_t)(0x1UL<<12)) /* sync system dft output enable */

#define    SYNC_CFG_SYNC_Rate                                    		((uint32_t)(0x3UL<<10))  /* sync system output to FFT rate select */
#define    SYNC_CFG_SYNC_Rate_256_1C                                    ((uint32_t)(0x0UL<<10))  /* 1 cycle 256 points */
#define    SYNC_CFG_SYNC_Rate_128_1C                                    ((uint32_t)(0x1UL<<10))  /* 1 cycle 128 points */
#define    SYNC_CFG_SYNC_Rate_1024_10C                                  ((uint32_t)(0x2UL<<10))  /* 10 cycle 1024 points */
#define    SYNC_CFG_SYNC_Rate_1024_12C                                  ((uint32_t)(0x3UL<<10))  /* 12 cycle 1024 points */

#define    SYNC_CFG_SYNCOUT_En                                    		((uint32_t)(0x1UL<<9))  /* sync system output to FFT enable */
#if defined  HT762x
#define    SYNC_CFG_SYNC_ChannelEn                                   	((uint32_t)(0x7fUL<<2))  /* sync system output to FFT enable */
#define    SYNC_CFG_SYNC_InEn                                     		((uint32_t)(0x1UL<<8))  /* In sync system enable */
#define    SYNC_CFG_SYNC_IcEn                                     		((uint32_t)(0x1UL<<7))  /* Ic sync system enable */
#define    SYNC_CFG_SYNC_IbEn                                     		((uint32_t)(0x1UL<<6))  /* Ib sync system enable */
#define    SYNC_CFG_SYNC_IaEn                                     		((uint32_t)(0x1UL<<5))  /* Ia sync system enable */
#define    SYNC_CFG_SYNC_UcEn                                     		((uint32_t)(0x1UL<<4))  /* uc sync system enable */
#define    SYNC_CFG_SYNC_UbEn                                     		((uint32_t)(0x1UL<<3))  /* ub sync system enable */
#define    SYNC_CFG_SYNC_UaEn                                     		((uint32_t)(0x1UL<<2))  /* ua sync system enable */
#else
#define    SYNC_CFG_SYNC_ChannelEn                                   	((uint32_t)(0x000064))  /* sync system output to FFT enable */
#define    SYNC_CFG_SYNC_I2En                                     		((uint32_t)(0x1UL<<6))  /* I2 sync system enable */
#define    SYNC_CFG_SYNC_I1En                                     		((uint32_t)(0x1UL<<5))  /* I1 sync system enable */
#define    SYNC_CFG_SYNC_UEn                                     		((uint32_t)(0x1UL<<2))  /* u sync system enable */
#endif
#define    SYNC_CFG_SYNC_Reset                                    		((uint32_t)(0x1UL<<1))  /* sync system reset */
#define    SYNC_CFG_SYNCSys_En                                    		((uint32_t)(0x1UL<<0))  /* sync system filter enable */
/**************************  Bit definition for  REC_CFG register  *******************************************************************/
#define    REC_CFG_REC_lpfEn                                     		((uint32_t)(0x1UL<<12)) /*  non-intrusive module lpf enable */

#define    REC_CFG_REC_signalSrc                                 		((uint32_t)(0x1UL<<11)) /*  non-intrusive module signal source select */
#define    REC_CFG_REC_signalSrc_Sync                                 	((uint32_t)(0x0UL<<11)) /* sync system output */
#define    REC_CFG_REC_signalSrc_Gain                                 	((uint32_t)(0x1UL<<11)) /* after gain */

#define    REC_CFG_REC_RateSelect                                 		((uint32_t)(0x3UL<<9)) /*  non-intrusive module output rate select */
#define    REC_CFG_REC_RateSelect_256                                 	((uint32_t)(0x0UL<<9)) /* 1 cycle 256 points */
#define    REC_CFG_REC_RateSelect_128                                 	((uint32_t)(0x1UL<<9)) /* 1 cycle 128 points */
#define    REC_CFG_REC_RateSelect_64                                 	((uint32_t)(0x2UL<<9)) /* 1 cycle 64 points */
#define    REC_CFG_REC_RateSelect_32                                 	((uint32_t)(0x3UL<<9)) /* 1 cycle 32 points */
#if defined  HT762x
#define    REC_CFG_REC_En                                               ((uint32_t)(0x7fUL<<2))
#define    REC_CFG_REC_InEn                                       		((uint32_t)(0x1UL<<8)) /* non-intrusive module in channel enable */
#define    REC_CFG_REC_IcEn                                       		((uint32_t)(0x1UL<<7)) /* non-intrusive module ic channel enable */
#define    REC_CFG_REC_IbEn                                       		((uint32_t)(0x1UL<<6)) /* non-intrusive module ib channel enable */
#define    REC_CFG_REC_IaEn                                       		((uint32_t)(0x1UL<<5)) /* non-intrusive module ia channel enable */
#define    REC_CFG_REC_UcEn                                       		((uint32_t)(0x1UL<<4)) /* non-intrusive module uc channel enable */
#define    REC_CFG_REC_UbEn                                       		((uint32_t)(0x1UL<<3)) /* non-intrusive module ub channel enable */
#define    REC_CFG_REC_UaEn                                       		((uint32_t)(0x1UL<<2)) /* non-intrusive module ua channel enable */
#else
#define    REC_CFG_REC_En                                               ((uint32_t)(0x000064))
#define    REC_CFG_REC_I2En                                       		((uint32_t)(0x1UL<<6)) /* non-intrusive module ib channel enable */
#define    REC_CFG_REC_I1En                                       		((uint32_t)(0x1UL<<5)) /* non-intrusive module ia channel enable */
#define    REC_CFG_REC_UEn                                       		((uint32_t)(0x1UL<<2)) /* non-intrusive module ua channel enable */
#endif
#define    REC_CFG_REC_reset                                      		((uint32_t)(0x1UL<<1)) /* non-intrusive module reset */
#define    REC_CFG_REC_enable                                     		((uint32_t)(0x1UL<<0)) /* non-intrusive module enable */
/**************************  Bit definition for  DFT_CFG register  *******************************************************************/
#define    DFT_CFG_DFT_LPF_I                                      		((uint32_t)(0x7UL<<4)) /* sync system current dft lpf contrl */
#define    DFT_CFG_DFT_LPF_U                                      		((uint32_t)(0x7UL<<0)) /* sync system voltage dft lpf contrl */
/**************************  Bit definition for  SYNC_DMA_rShift register  *******************************************************************/
#if defined  HT762x
#define    SYNC_DMA_rShift_In                    						((uint32_t)(0xfUL<<24)) /* sync system In channel dma right shift */
#define    SYNC_DMA_rShift_Ic                    						((uint32_t)(0xfUL<<20)) /* sync system Ic channel dma right shift */
#define    SYNC_DMA_rShift_Ib                    						((uint32_t)(0xfUL<<16)) /* sync system Ib channel dma right shift */
#define    SYNC_DMA_rShift_Ia                    						((uint32_t)(0xfUL<<12)) /* sync system Ia channel dma right shift */
#define    SYNC_DMA_rShift_Uc                     						((uint32_t)(0xfUL<<8))  /* sync system Uc channel dma right shift */
#define    SYNC_DMA_rShift_Ub                     						((uint32_t)(0xfUL<<4))  /* sync system Ub channel dma right shift */
#define    SYNC_DMA_rShift_Ua                     						((uint32_t)(0xfUL<<0))  /* sync system Ua channel dma right shift */
#else
#define    SYNC_DMA_rShift_I2                    						((uint32_t)(0xfUL<<16)) /* sync system I2 channel dma right shift */
#define    SYNC_DMA_rShift_I1                    						((uint32_t)(0xfUL<<12)) /* sync system I1 channel dma right shift */
#define    SYNC_DMA_rShift_U                     						((uint32_t)(0xfUL<<0))  /* sync system U channel dma right shift */
#endif
/**************************  Bit definition for  HpRMS_Ctl_U register  *******************************************************************/
#if defined  HT762x
#define    HpRMS_Ctl_U_Offset_Uc                          				((uint32_t)(0x3fUL<<17))
#define    HpRMS_Ctl_U_UcEnable                            				((uint32_t)(0x1UL<<16))  /* uc channnel half cycle rms enable */
#define    HpRMS_Ctl_U_Offset_Ub                           				((uint32_t)(0x3fUL<<9))
#define    HpRMS_Ctl_U_UbEnable                             			((uint32_t)(0x1UL<<8))   /* ub channnel half cycle rms enable */
#define    HpRMS_Ctl_U_Offset_Ua                           				((uint32_t)(0x3fUL<<1))
#define    HpRMS_Ctl_U_UaEnable                             			((uint32_t)(0x1UL<<0))   /* ua channnel half cycle rms enable */
#else
#define    HpRMS_Ctl_U_Offset_U                           				((uint32_t)(0x3fUL<<1))
#define    HpRMS_Ctl_U_UEnable                             				((uint32_t)(0x1UL<<0))   /* u channnel half cycle rms enable */
#endif
/**************************  Bit definition for  HpRMS_Ctl_I register  *******************************************************************/
#if defined  HT762x
#define    HpRMS_Ctl_I_Offset_In                          				((uint32_t)(0x3fUL<<25))
#define    HpRMS_Ctl_I_InEnable                            				((uint32_t)(0x1UL<<24))  /* In channnel half cycle rms enable */
#define    HpRMS_Ctl_I_Offset_Ic                          				((uint32_t)(0x3fUL<<17))
#define    HpRMS_Ctl_I_IcEnable                            				((uint32_t)(0x1UL<<16))  /* Ic channnel half cycle rms enable */
#define    HpRMS_Ctl_I_Offset_Ib                           				((uint32_t)(0x3fUL<<9))
#define    HpRMS_Ctl_I_IbEnable                             			((uint32_t)(0x1UL<<8))   /* Ib channnel half cycle rms enable */
#define    HpRMS_Ctl_I_Offset_Ia                           				((uint32_t)(0x3fUL<<1))
#define    HpRMS_Ctl_I_IaEnable                             			((uint32_t)(0x1UL<<0))   /* Ia channnel half cycle rms enable */
#else
#define    HpRMS_Ctl_I_Offset_I2                           				((uint32_t)(0x3fUL<<9))
#define    HpRMS_Ctl_I_I2Enable                             			((uint32_t)(0x1UL<<8))   /* I2 channnel half cycle rms enable */
#define    HpRMS_Ctl_I_Offset_I1                           				((uint32_t)(0x3fUL<<1))
#define    HpRMS_Ctl_I_I1Enable                             			((uint32_t)(0x1UL<<0))   /* I1 channnel half cycle rms enable */
#endif
/**************************  Bit definition for  PLL_CTRL register  *******************************************************************/
#define    PLL_CTRL_PLL_locked_flag                                    ((uint32_t)(0x1UL<<6)) /* read only , pll locked flag */

#define    PLL_CTRL_PLL_manual_sfo_EN                                  ((uint32_t)(0x1UL<<5)) /* manual produce pll sfo enable */

#define    PLL_CTRL_PLL_source                                    		((uint32_t)(0x3UL<<3)) /* pll lock source select */
#if defined  HT762x
#define    PLL_CTRL_PLL_source_Ua                                    	((uint32_t)(0x0UL<<3)) /* UA */
#define    PLL_CTRL_PLL_source_Ub                                    	((uint32_t)(0x1UL<<3)) /* UB */
#define    PLL_CTRL_PLL_source_Uc                                    	((uint32_t)(0x2UL<<3)) /* UC */
#else
#define    PLL_CTRL_PLL_source_U                                    	((uint32_t)(0x0UL<<3)) /* U */
#endif
#define    PLL_CTRL_PLL_reset                                     		((uint32_t)(0x1UL<<2)) /* PLL reset */
#define    PLL_CTRL_PLL_freeze                                    		((uint32_t)(0x1UL<<1)) /* PLL freeze success flag */
#define    PLL_CTRL_PLL_enable                                    		((uint32_t)(0x1UL<<0)) /*  pll lock enable */

/*
*********************************************************************************************************
*                                            Structure Type define
*********************************************************************************************************
*/
typedef enum {AUTO = 0, MANUAL = !AUTO}   AccessState;	 

typedef struct
{
	uint32_t DFT_LPF_UCoeff;
	uint32_t DFT_LPF_ICoeff;
	uint32_t Sfo_Value;
	uint32_t PLL_Gain;
	uint32_t Lock_THO;
	uint32_t AMP_THO;
	uint32_t TED_Amnt;
#if defined  HT762x	
	uint32_t SyncDMARshift_Ua;
	uint32_t SyncDMARshift_Ub;	
	uint32_t SyncDMARshift_Uc;	
	uint32_t SyncDMARshift_Ia;	
	uint32_t SyncDMARshift_Ib;	
	uint32_t SyncDMARshift_Ic;	
	uint32_t SyncDMARshift_In;
#else
	uint32_t SyncDMARshift_U;	
	uint32_t SyncDMARshift_I1;	
	uint32_t SyncDMARshift_I2;	
#endif
	uint32_t PLL_SourceSel;				
	AccessState PLL_manual_sfo;
	FunctionalState PLL_En; 	
	FunctionalState Freeze_En;
	FunctionalState SyncSfo_En;
	FunctionalState SyncSys_En;
	FunctionalState SyncDFT_En;
	FunctionalState SyncdisLpf_En;	
}SyncPLL_InitTypeDef;




typedef struct
{
#if defined  HT762x	
	uint32_t HpRMSOffset_Ua;
	uint32_t HpRMSOffset_Ub;	
	uint32_t HpRMSOffset_Uc;	
	uint32_t HpRMSOffset_Ia;	
	uint32_t HpRMSOffset_Ib;	
	uint32_t HpRMSOffset_Ic;	
	uint32_t HpRMSOffset_In;
#else
	uint32_t HpRMSOffset_U;	
	uint32_t HpRMSOffset_I1;	
	uint32_t HpRMSOffset_I2;	
#endif
	uint32_t HpRmsSel;
#if defined  HT762x	
	FunctionalState HpRMS_Ctl_UaEnable;
	FunctionalState HpRMS_Ctl_UbEnable; 
	FunctionalState HpRMS_Ctl_UcEnable; 
	FunctionalState HpRMS_Ctl_IaEnable; 
	FunctionalState HpRMS_Ctl_IbEnable; 
	FunctionalState HpRMS_Ctl_IcEnable; 
	FunctionalState HpRMS_Ctl_InEnable; 
#else
	FunctionalState HpRMS_Ctl_UEnable; 
	FunctionalState HpRMS_Ctl_I1Enable; 
	FunctionalState HpRMS_Ctl_I2Enable; 
#endif
}HpRms_InitTypeDef;


typedef struct
{
	uint32_t REC_ChannelEn;
	uint32_t REC_RateSel;
	uint32_t REC_signalSrc;
	FunctionalState REC_ChannelEnState; 
	FunctionalState REC_En; 
	FunctionalState REC_LpfEn;
}REC_InitTypeDef;	

typedef struct
{
	uint32_t SyncFFT_ChannelEn;
	uint32_t  FFT_RateSel;
	uint32_t FFT_BWSel;
	FunctionalState SyncFFT_ChannelEnState; 
	FunctionalState SyncOut_En;
}SyncFFT_InitTypeDef;



typedef struct
{
	uint32_t  DecCompCoff[5];    /* filter coefficient */   
	FunctionalState DecCompEn;   /* DEC compensation enable or disable */
}DecComp_InitTypeDef;

typedef struct
{
	uint32_t  UZcLvl;             /* voltage zeroCross threshold value */  
	uint32_t  IZcLvl;             /* current zeroCross threshold value  */  
	uint32_t  ZcLostMaxNum;       /* zeroCross lost max points */   
	uint32_t  ZcLostMinNum;       /* zeroCross lost max points */   
	uint32_t  FundZcValidNum;     /* fund zeroCross valid points */   
	uint32_t  FundZcDelyNum;      /* fund zeroCross delay points */  
	uint32_t  ZcSrcSel;           /* zeroCross source select */   
	uint32_t  ZcIntWaySel;        /* zeroCross Interrupt way select */   
	uint32_t  ZcIntSrcSel;        /* zeroCross Interrupt source select */  
}ZeroCross_InitTypeDef;

typedef struct
{
	uint32_t  RmsAvgNum;          	/* rms average points */
	uint32_t  RmsTAvgNum;          	/* vector sum rms average pionts */
	uint32_t  ItRmsTho;          	/* vector sum current rms threshold value*/
#if defined  HT762x
	uint32_t  UtRmsTho;          	/* vector sum voltage rms threshold value*/
	uint32_t  UbRms3P3Cal;          /* three phase three line mode Ub Rms calculate */
	FunctionalState UtCfgUaEn;  	/* calculate vector sum voltage rms Ua part in enable or disable */   
	FunctionalState UtCfgUbEn;  	/* calculate vector sum voltage rms Ub part in enable or disable */     
	FunctionalState UtCfgUcEn;  	/* calculate vector sum voltage rms Uc part in enable or disable */    
	FunctionalState ItCfgIaEn;  	/* calculate vector sum current rms Ia part in enable or disable */   
	FunctionalState ItCfgIbEn;  	/* calculate vector sum current rms Ib part in enable or disable */  
	FunctionalState ItCfgIcEn;  	/* calculate vector sum current rms Ic part in enable or disable */   
	FunctionalState ItCfgInEn;  	/* calculate vector sum current rms In part in enable or disable */  
	FunctionalState UtFundRmsEn;    /* calculate fund vector sum current rms enable or disable */    
	FunctionalState UFundLineRmsEn; /* calculate fund line voltage rms enable or disable */  
#else
	FunctionalState ItCfgI1En;  	/* calculate vector sum current rms I1 part in enable or disable */   
	FunctionalState ItCfgI2En;  	/* calculate vector sum current rms I2 part in enable or disable */  
#endif
	FunctionalState ItFundRmsEn;    /* calculate fund vector sum voltage rms enable or disable */   
}Rms_InitTypeDef;

typedef struct
{
	uint32_t  AngBaseSel;          /* angle base select */
	FunctionalState AutoAngBaseEn; /* angle base automatic change enable or disable */  
}Ang_InitTypeDef;


typedef struct
{
#if defined  HT762x
	uint32_t  UaConst;          /* Ua const data */
	uint32_t  UbConst;          /* Ub const data */
	uint32_t  UcConst;          /* Uc const data */
	FunctionalState UaConstEn;  /* Ua const enable or disable */  
	FunctionalState UbConstEn;  /* Ub const enable or disable */   
	FunctionalState UcConstEn;  /* Uc const enable or disable */ 
#else
	uint32_t  UConst;          /* U const data */
	FunctionalState UConstEn;  /* U const enable or disable */  
#endif
}UConst_InitTypeDef;

typedef struct
{
	uint32_t  SrcSel;     	  /* peak sag,int,iov detect source select */
	uint32_t  USagLvl;        /* voltage sag threshold value */     
	uint32_t  UPeakLvl;       /* voltage peak threshold value */ 
	uint32_t  UIntLvl;        /* voltage INT threshold value */ 
	uint32_t  IovLvl;         /* current overflow threshold value */ 
	uint32_t  USagLvlHys;     /* voltage sag threshold hysteresis */     
	uint32_t  UPeakLvlHys;    /* voltage peak threshold hysteresis */ 
	uint32_t  UIntLvlHys;     /* voltage INT threshold hysteresis */ 
	uint32_t  IovLvlHys;      /* current overflow threshold hysteresis */
	uint32_t  UPeakSagHCyc;   /* peak sag detect half cycle number */
	uint32_t  UIntHCyc;       /* INT detect half cycle number */
	uint32_t  IovHCyc; 	      /* current overflow  detect half cycle number */	
	FunctionalState USagEn;	  /* voltage sag detect enable or disable */     
	FunctionalState UPeakEn;  /* voltage peak enable or disable  */ 
	FunctionalState UIntEn;   /* voltage INT enable or disable  */ 
	FunctionalState IovEn;    /* current overflow enable or disable  */ 
}SagPeakIntIov_InitTypeDef;

typedef struct
{
	uint32_t  	FilterCoff[32];    	 				/* filter coefficient */ 
	uint32_t  	FlickerShift[3];    	 			/* flicker shift */  
	uint32_t  	FlickerUpdRate;    	 			    /* flicker update rate */  
	uint32_t  	HarFilterShift;    	 			    /* total Har wave filter Shift */  
#if defined  HT762x
	uint32_t  	InFilterCoff[16];    	 			/* In filter coefficient */ 
	uint32_t  	InFilterShift;    	 			    /* In filter Shift */  
	FunctionalState UaFlickerEn;	  				/* Flicker enable contrl */ 
	FunctionalState UbFlickerEn;	  				/* Flicker enable contrl */ 
	FunctionalState UcFlickerEn;	  				/* Flicker enable contrl */ 
	FunctionalState InMultiFuncEn;	  				/* In multi-function enable contrl */  
#else
	FunctionalState UFlickerEn;	  					/* Flicker enable contrl */ 
#endif
}MultiFilter_InitTypeDef;





/*
*********************************************************************************************************
*                                            self-defined global macro
*********************************************************************************************************
*/

/************************************************Param check ********************************************/
#define IS_HT_EMU_EPReg_ADDR(ADDR) (((ADDR) <= EPR_PeakSagIntIovStau)&&(((ADDR)%4) == 0))

#define IS_HT_EMU_ECReg_ADDR(ADDR) (((ADDR) <= ECR_TED_Amnt)&&(((ADDR)%4) == 0))
#if defined  HT762x
#define IS_HT_EMU_NOLOAD_STATUS(STATUS) (((STATUS) == NoLoad_AllPa) || \
																	((STATUS) == NoLoad_AllPb) || \
																	((STATUS) == NoLoad_AllPc) || \
																	((STATUS) == NoLoad_AllQa) || \
																	((STATUS) == NoLoad_AllQb) || \
																	((STATUS) == NoLoad_AllQc) || \
																	((STATUS) == NoLoad_AllSa) || \
																	((STATUS) == NoLoad_AllSb) || \
																	((STATUS) == NoLoad_AllSc) || \
																	((STATUS) == NoLoad_FundPa) || \
																	((STATUS) == NoLoad_FundPb) || \
																	((STATUS) == NoLoad_FundPc) || \
																	((STATUS) == NoLoad_FundQa) || \
																	((STATUS) == NoLoad_FundQb) || \
																	((STATUS) == NoLoad_FundQc) || \
																	((STATUS) == NoLoad_FundSa) || \
																	((STATUS) == NoLoad_FundSb) || \
																	((STATUS) == NoLoad_FundSc) || \
																	((STATUS) == NoLoad_HarPa) || \
																	((STATUS) == NoLoad_HarPb) || \
																	((STATUS) == NoLoad_HarPc))
#else
#define IS_HT_EMU_NOLOAD_STATUS(STATUS) (((STATUS) == NoLoad_AllP1) || \
																	((STATUS) == NoLoad_AllP2) || \
																	((STATUS) == NoLoad_AllQ1) || \
																	((STATUS) == NoLoad_AllQ2) || \
																	((STATUS) == NoLoad_AllS1) || \
																	((STATUS) == NoLoad_AllS2) || \
																	((STATUS) == NoLoad_FundP1) || \
																	((STATUS) == NoLoad_FundP2) || \
																	((STATUS) == NoLoad_FundQ1) || \
																	((STATUS) == NoLoad_FundQ2) || \
																	((STATUS) == NoLoad_FundS1) || \
																	((STATUS) == NoLoad_FundS2) || \
																	((STATUS) == NoLoad_HarP1) || \
																	((STATUS) == NoLoad_HarP2))
#endif


#if defined  HT762x
#define IS_HT_EMU_REVPOWER_STATUS(STATUS) (((STATUS) == REV_Power_AllPa) || \
																	((STATUS) == REV_Power_AllPb) || \
																	((STATUS) == REV_Power_AllPc) || \
																	((STATUS) == REV_Power_AllPt) || \
																	((STATUS) == REV_Power_AllQa) || \
																	((STATUS) == REV_Power_AllQb) || \
																	((STATUS) == REV_Power_AllQc) || \
																	((STATUS) == REV_Power_AllQt) || \
																	((STATUS) == REV_Power_FundPa) || \
																	((STATUS) == REV_Power_FundPb) || \
																	((STATUS) == REV_Power_FundPc) || \
																	((STATUS) == REV_Power_FundPt) || \
																	((STATUS) == REV_Power_FundQa) || \
																	((STATUS) == REV_Power_FundQb) || \
																	((STATUS) == REV_Power_FundQc) || \
																	((STATUS) == REV_Power_FundQt) || \
																	((STATUS) == REV_Power_HarPa) || \
																	((STATUS) == REV_Power_HarPb) || \
																	((STATUS) == REV_Power_HarPc) || \
																	((STATUS) == REV_Power_HarPt))
#else
#define IS_HT_EMU_REVPOWER_STATUS(STATUS) (((STATUS) == REV_Power_AllP1) || \
																	((STATUS) == REV_Power_AllP2) || \
																	((STATUS) == REV_Power_AllPt) || \
																	((STATUS) == REV_Power_AllQ1) || \
																	((STATUS) == REV_Power_AllQ2) || \
																	((STATUS) == REV_Power_AllQt) || \
																	((STATUS) == REV_Power_FundP1) || \
																	((STATUS) == REV_Power_FundP2) || \
																	((STATUS) == REV_Power_FundPt) || \
																	((STATUS) == REV_Power_FundQ1) || \
																	((STATUS) == REV_Power_FundQ2) || \
																	((STATUS) == REV_Power_FundQt) || \
																	((STATUS) == REV_Power_HarP1) || \
																	((STATUS) == REV_Power_HarP2) || \
																	((STATUS) == REV_Power_HarPt))
#endif

#if defined  HT762x
#define IS_HT_EMU_REVENERGY_STATUS(STATUS) (((STATUS) == REV_Energy_AllEPa) || \
																	((STATUS) == REV_Energy_AllEPb) || \
																	((STATUS) == REV_Energy_AllEPc) || \
																	((STATUS) == REV_Energy_AllEPt) || \
																	((STATUS) == REV_Energy_AllEQa) || \
																	((STATUS) == REV_Energy_AllEQb) || \
																	((STATUS) == REV_Energy_AllEQc) || \
																	((STATUS) == REV_Energy_AllEQt) || \
																	((STATUS) == REV_Energy_ESa) || \
																	((STATUS) == REV_Energy_ESb) || \
																	((STATUS) == REV_Energy_ESc) || \
																	((STATUS) == REV_Energy_ESt) || \
																	((STATUS) == REV_Energy_FundEPa) || \
																	((STATUS) == REV_Energy_FundEPb) || \
																	((STATUS) == REV_Energy_FundEPc) || \
																	((STATUS) == REV_Energy_FundEPt) || \
																	((STATUS) == REV_Energy_FundEQa) || \
																	((STATUS) == REV_Energy_FundEQb) || \
																	((STATUS) == REV_Energy_FundEQc) || \
																	((STATUS) == REV_Energy_FundEQt) || \
																	((STATUS) == REV_Energy_HarEPa) || \
																	((STATUS) == REV_Energy_HarEPb) || \
																	((STATUS) == REV_Energy_HarEPc) || \
																	((STATUS) == REV_Energy_HarEPt))
#else
#define IS_HT_EMU_REVENERGY_STATUS(STATUS) (((STATUS) == REV_Energy_AllEP1) || \
																	((STATUS) == REV_Energy_AllEP2) || \
																	((STATUS) == REV_Energy_AllEPt) || \
																	((STATUS) == REV_Energy_AllEQ1) || \
																	((STATUS) == REV_Energy_AllEQ2) || \
																	((STATUS) == REV_Energy_AllEQt) || \
																	((STATUS) == REV_Energy_ES1) || \
																	((STATUS) == REV_Energy_ES2) || \
																	((STATUS) == REV_Energy_ESt) || \
																	((STATUS) == REV_Energy_FundEP1) || \
																	((STATUS) == REV_Energy_FundEP2) || \
																	((STATUS) == REV_Energy_FundEPt) || \
																	((STATUS) == REV_Energy_FundEQ1) || \
																	((STATUS) == REV_Energy_FundEQ2) || \
																	((STATUS) == REV_Energy_FundEQt) || \
																	((STATUS) == REV_Energy_HarEP1) || \
																	((STATUS) == REV_Energy_HarEP2) || \
																	((STATUS) == REV_Energy_HarEPt))

#endif
#if defined  HT762x
#define IS_HT_EMU_P90POWER_STATUS(STATUS) (((STATUS) == P90_Power_AllEPa) || \
																	((STATUS) == P90_Power_AllEPb) || \
																	((STATUS) == P90_Power_AllEPc) || \
																	((STATUS) == P90_Power_AllEPt) || \
																	((STATUS) == P90_Power_AllEQa) || \
																	((STATUS) == P90_Power_AllEQb) || \
																	((STATUS) == P90_Power_AllEQc) || \
																	((STATUS) == P90_Power_AllEQt) || \
																	((STATUS) == P90_Power_FundEPa) || \
																	((STATUS) == P90_Power_FundEPb) || \
																	((STATUS) == P90_Power_FundEPc) || \
																	((STATUS) == P90_Power_FundEPt) || \
																	((STATUS) == P90_Power_FundEQa) || \
																	((STATUS) == P90_Power_FundEQb) || \
																	((STATUS) == P90_Power_FundEQc) || \
																	((STATUS) == P90_Power_FundEQt))
#else
#define IS_HT_EMU_P90POWER_STATUS(STATUS) (((STATUS) == P90_Power_AllEP1) || \
																	((STATUS) == P90_Power_AllEP2) || \
																	((STATUS) == P90_Power_AllEPt) || \
																	((STATUS) == P90_Power_AllEQ1) || \
																	((STATUS) == P90_Power_AllEQ2) || \
																	((STATUS) == P90_Power_AllEQt) || \
																	((STATUS) == P90_Power_FundEP1) || \
																	((STATUS) == P90_Power_FundEP2) || \
																	((STATUS) == P90_Power_FundEPt) || \
																	((STATUS) == P90_Power_FundEQ1) || \
																	((STATUS) == P90_Power_FundEQ2) || \
																	((STATUS) == P90_Power_FundEQt))

#endif
#if defined  HT762x
#define IS_HT_EMU_SIGNAL_STATUS(STATUS) (((STATUS) == SignalStatus_CMPDone) || \
																	((STATUS) == SignalStatus_CMPC) || \
																	((STATUS) == SignalStatus_CMPB) || \
																	((STATUS) == SignalStatus_CMPA) || \
																	((STATUS) == SignalStatus_Mod3P3Status) || \
																	((STATUS) == SignalStatus_VoltageFailC) || \
																	((STATUS) == SignalStatus_VoltageFailB) || \
																	((STATUS) == SignalStatus_VoltageFailA) || \
																	((STATUS) == SignalStatus_UOrder) || \
																	((STATUS) == SignalStatus_IOrder) || \
																	((STATUS) == SignalStatus_RegionIc) || \
																	((STATUS) == SignalStatus_RegionIb) || \
																	((STATUS) == SignalStatus_RegionIa) || \
																	((STATUS) == SignalStatus_ZCValid_Ua) || \
																	((STATUS) == SignalStatus_ZCValid_Ub) || \
																	((STATUS) == SignalStatus_ZCValid_Uc) || \
																	((STATUS) == SignalStatus_ZCValid_Ia) || \
																	((STATUS) == SignalStatus_ZCValid_Ib) || \
																	((STATUS) == SignalStatus_ZCValid_Ic) || \
																	((STATUS) == SignalStatus_ZCValid_In) || \
																	((STATUS) == SignalStatus_AngleBaseFlag))
#else
#define IS_HT_EMU_SIGNAL_STATUS(STATUS) (((STATUS) == SignalStatus_RegionI1) || \
																	((STATUS) == SignalStatus_RegionI2) || \
																	((STATUS) == SignalStatus_VoltageFail) || \
																	((STATUS) == SignalStatus_ZCValid_U) || \
																	((STATUS) == SignalStatus_ZCValid_I1) || \
																	((STATUS) == SignalStatus_ZCValid_I2) || \
																	((STATUS) == SignalStatus_AngleBaseFlag))

#endif
#if defined  HT762x
#define IS_HT_EMU_PEAKSAG_STATUS(STATUS) (((STATUS) == PeakSagIntIovStau_PeakUA) || \
																	((STATUS) == PeakSagIntIovStau_PeakUB) || \
																	((STATUS) == PeakSagIntIovStau_PeakUC) || \
																	((STATUS) == PeakSagIntIovStau_SagUA) || \
																	((STATUS) == PeakSagIntIovStau_SagUB) || \
																	((STATUS) == PeakSagIntIovStau_SagUC) || \
																	((STATUS) == PeakSagIntIovStau_UINTUA) || \
																	((STATUS) == PeakSagIntIovStau_UINTUB) || \
																	((STATUS) == PeakSagIntIovStau_UINTUC) || \
																	((STATUS) == PeakSagIntIovStau_OVIA) || \
																	((STATUS) == PeakSagIntIovStau_OVIB) || \
																	((STATUS) == PeakSagIntIovStau_OVIC) || \
																	((STATUS) == PeakSagIntIovStau_OVIN))
#else
#define IS_HT_EMU_PEAKSAG_STATUS(STATUS) (((STATUS) == PeakSagIntIovStau_PeakU) || \
																	((STATUS) == PeakSagIntIovStau_SagU) || \
																	((STATUS) == PeakSagIntIovStau_UINTU) || \
																	((STATUS) == PeakSagIntIovStau_OVI1) || \
																	((STATUS) == PeakSagIntIovStau_OVI2))

#endif
#if defined  HT762x
#define IS_HT_EMUIE1_CONFIG(CONFIG) (((CONFIG) == EMUIE1_AllP_PosCFIE) || \
																	((CONFIG) == EMUIE1_AllQ_PosCFIE) || \
																	((CONFIG) == EMUIE1_S_PosCFIE) || \
																	((CONFIG) == EMUIE1_FundP_PosCFIE) || \
																	((CONFIG) == EMUIE1_FundQ_PosCFIE) || \
																	((CONFIG) == EMUIE1_HarP_PosCFIE) || \
																	((CONFIG) == EMUIE1_AllP_NegCFIE) || \
																	((CONFIG) == EMUIE1_AllQ_NegCFIE) || \
																	((CONFIG) == EMUIE1_S_NegCFIE) || \
																	((CONFIG) == EMUIE1_FundP_NegCFIE) || \
																	((CONFIG) == EMUIE1_FundQ_NegCFIE) || \
																	((CONFIG) == EMUIE1_HarP_NegCFIE) || \
																	((CONFIG) == EMUIE1_ZCUaIE) || \
																	((CONFIG) == EMUIE1_ZCUbIE) || \
																	((CONFIG) == EMUIE1_ZCUcIE) || \
																	((CONFIG) == EMUIE1_ZCIaIE) || \
																	((CONFIG) == EMUIE1_ZCIbIE) || \
																	((CONFIG) == EMUIE1_ZCIcIE) || \
																	((CONFIG) == EMUIE1_ZCInIE) || \
																	((CONFIG) == EMUIE1_CMPaIE) || \
																	((CONFIG) == EMUIE1_CMPbIE) || \
																	((CONFIG) == EMUIE1_CMPcIE) || \
																	((CONFIG) == EMUIE1_ZCUaLostIE) || \
																	((CONFIG) == EMUIE1_ZCUbLostIE) || \
																	((CONFIG) == EMUIE1_ZCUcLostIE) || \
																	((CONFIG) == EMUIE1_EnergyOVIE) || \
																	((CONFIG) == EMUIE1_SPLUpdateIE)|| \
																	((CONFIG) == EMUIE1_PowerUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSTUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSUtOVIE) || \
																	((CONFIG) == EMUIE1_RMSItOVIE)|| \
																	((((CONFIG) & (uint32_t)(~EMUIE1_ALL)) == 0x00) && ((CONFIG) != 0x00)))
#else
#define IS_HT_EMUIE1_CONFIG(CONFIG) (((CONFIG) == EMUIE1_AllP_PosCFIE) || \
																	((CONFIG) == EMUIE1_AllQ_PosCFIE) || \
																	((CONFIG) == EMUIE1_S_PosCFIE) || \
																	((CONFIG) == EMUIE1_FundP_PosCFIE) || \
																	((CONFIG) == EMUIE1_FundQ_PosCFIE) || \
																	((CONFIG) == EMUIE1_HarP_PosCFIE) || \
																	((CONFIG) == EMUIE1_AllP_NegCFIE) || \
																	((CONFIG) == EMUIE1_AllQ_NegCFIE) || \
																	((CONFIG) == EMUIE1_S_NegCFIE) || \
																	((CONFIG) == EMUIE1_FundP_NegCFIE) || \
																	((CONFIG) == EMUIE1_FundQ_NegCFIE) || \
																	((CONFIG) == EMUIE1_HarP_NegCFIE) || \
																	((CONFIG) == EMUIE1_ZCUIE) || \
																	((CONFIG) == EMUIE1_ZCI1IE) || \
																	((CONFIG) == EMUIE1_ZCI2IE) || \
																	((CONFIG) == EMUIE1_ZCULostIE) || \
																	((CONFIG) == EMUIE1_EnergyOVIE) || \
																	((CONFIG) == EMUIE1_SPLUpdateIE)|| \
																	((CONFIG) == EMUIE1_PowerUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSTUpdateIE) || \
																	((CONFIG) == EMUIE1_RMSItOVIE)|| \
																	((((CONFIG) & (uint32_t)(~EMUIE1_ALL)) == 0x00) && ((CONFIG) != 0x00)))

#endif
#if defined  HT762x
#define IS_HT_EMUIF1_CONFIG(CONFIG) (((CONFIG) == EMUIF1_AllP_PosCFIF) || \
																	((CONFIG) == EMUIF1_AllQ_PosCFIF) || \
																	((CONFIG) == EMUIF1_S_PosCFIF) || \
																	((CONFIG) == EMUIF1_FundP_PosCFIF) || \
																	((CONFIG) == EMUIF1_FundQ_PosCFIF) || \
																	((CONFIG) == EMUIF1_HarP_PosCFIF) || \
																	((CONFIG) == EMUIF1_AllP_NegCFIF) || \
																	((CONFIG) == EMUIF1_AllQ_NegCFIF) || \
																	((CONFIG) == EMUIF1_S_NegCFIF) || \
																	((CONFIG) == EMUIF1_FundP_NegCFIF) || \
																	((CONFIG) == EMUIF1_FundQ_NegCFIF) || \
																	((CONFIG) == EMUIF1_HarP_NegCFIF) || \
																	((CONFIG) == EMUIF1_ZCUaIF) || \
																	((CONFIG) == EMUIF1_ZCUbIF) || \
																	((CONFIG) == EMUIF1_ZCUcIF) || \
																	((CONFIG) == EMUIF1_ZCIaIF) || \
																	((CONFIG) == EMUIF1_ZCIbIF) || \
																	((CONFIG) == EMUIF1_ZCIcIF) || \
																	((CONFIG) == EMUIF1_ZCInIF) || \
																	((CONFIG) == EMUIF1_CMPaIF) || \
																	((CONFIG) == EMUIF1_CMPbIF) || \
																	((CONFIG) == EMUIF1_CMPcIF) || \
																	((CONFIG) == EMUIF1_ZCUaLostIF) || \
																	((CONFIG) == EMUIF1_ZCUbLostIF) || \
																	((CONFIG) == EMUIF1_ZCUcLostIF) || \
																	((CONFIG) == EMUIF1_EnergyOVIF) || \
																	((CONFIG) == EMUIF1_SPLUpdateIF)|| \
																	((CONFIG) == EMUIF1_PowerUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSTUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSUtOVIF) || \
																	((CONFIG) == EMUIF1_RMSItOVIF))
#else
#define IS_HT_EMUIF1_CONFIG(CONFIG) (((CONFIG) == EMUIF1_AllP_PosCFIF) || \
																	((CONFIG) == EMUIF1_AllQ_PosCFIF) || \
																	((CONFIG) == EMUIF1_S_PosCFIF) || \
																	((CONFIG) == EMUIF1_FundP_PosCFIF) || \
																	((CONFIG) == EMUIF1_FundQ_PosCFIF) || \
																	((CONFIG) == EMUIF1_HarP_PosCFIF) || \
																	((CONFIG) == EMUIF1_AllP_NegCFIF) || \
																	((CONFIG) == EMUIF1_AllQ_NegCFIF) || \
																	((CONFIG) == EMUIF1_S_NegCFIF) || \
																	((CONFIG) == EMUIF1_FundP_NegCFIF) || \
																	((CONFIG) == EMUIF1_FundQ_NegCFIF) || \
																	((CONFIG) == EMUIF1_HarP_NegCFIF) || \
																	((CONFIG) == EMUIF1_ZCUIF) || \
																	((CONFIG) == EMUIF1_ZCI1IF) || \
																	((CONFIG) == EMUIF1_ZCI2IF) || \
																	((CONFIG) == EMUIF1_ZCULostIF) || \
																	((CONFIG) == EMUIF1_EnergyOVIF) || \
																	((CONFIG) == EMUIF1_SPLUpdateIF)|| \
																	((CONFIG) == EMUIF1_PowerUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSTUpdateIF) || \
																	((CONFIG) == EMUIF1_RMSItOVIF))
#endif

#if defined  HT762x
#define IS_HT_EMUIE2_CONFIG(CONFIG) (((CONFIG) == EMUIE2_PeakUaIE) || \
																	((CONFIG) == EMUIE2_PeakUbIE) || \
																	((CONFIG) == EMUIE2_PeakUcIE) || \
																	((CONFIG) == EMUIE2_SagUaIE) || \
																	((CONFIG) == EMUIE2_SagUbIE) || \
																	((CONFIG) == EMUIE2_SagUcIE) || \
																	((CONFIG) == EMUIE2_UaEndIE) || \
																	((CONFIG) == EMUIE2_UbEndIE) || \
																	((CONFIG) == EMUIE2_UcEndIE) || \
																	((CONFIG) == EMUIE2_INTUaIE) || \
																	((CONFIG) == EMUIE2_INTUbIE) || \
																	((CONFIG) == EMUIE2_INTUcIE) || \
																	((CONFIG) == EMUIE2_INTUIE) || \
																	((CONFIG) == EMUIE2_UaINTEndIE) || \
																	((CONFIG) == EMUIE2_UbINTEndIE) || \
																	((CONFIG) == EMUIE2_UcINTEndIE) || \
																	((CONFIG) == EMUIE2_IaOVIE) || \
																	((CONFIG) == EMUIE2_IbOVIE) || \
																	((CONFIG) == EMUIE2_IcOVIE) || \
																	((CONFIG) == EMUIE2_InOVIE) || \
																	((CONFIG) == EMUIE2_IaOVEndIE) || \
																	((CONFIG) == EMUIE2_IbOVEndIE) || \
																	((CONFIG) == EMUIE2_IcOVEndIE) || \
																	((CONFIG) == EMUIE2_InOVEndIE) || \
																	((CONFIG) == EMUIE2_VpupdUaIE) || \
																	((CONFIG) == EMUIE2_VpupdUbIE)|| \
																	((CONFIG) == EMUIE2_VpupdUcIE) || \
																	((CONFIG) == EMUIE2_VpupdIaIE) || \
																	((CONFIG) == EMUIE2_VpupdIbIE) || \
																	((CONFIG) == EMUIE2_VpupdIcIE) || \
																	((CONFIG) == EMUIE2_VpupdInIE)|| \
																	((((CONFIG) & (uint32_t)(~EMUIE2_ALL)) == 0x00) && ((CONFIG) != 0x00)))
#else
#define IS_HT_EMUIE2_CONFIG(CONFIG) (((CONFIG) == EMUIE2_PeakUIE) || \
																	((CONFIG) == EMUIE2_SagUIE) || \
																	((CONFIG) == EMUIE2_UEndIE) || \
																	((CONFIG) == EMUIE2_INTUIE) || \
																	((CONFIG) == EMUIE2_UINTEndIE) || \
																	((CONFIG) == EMUIE2_I1OVIE) || \
																	((CONFIG) == EMUIE2_I2OVIE) || \
																	((CONFIG) == EMUIE2_I1OVEndIE) || \
																	((CONFIG) == EMUIE2_I2OVEndIE) || \
																	((CONFIG) == EMUIE2_VpupdUIE) || \
																	((CONFIG) == EMUIE2_VpupdI1IE) || \
																	((CONFIG) == EMUIE2_VpupdI2IE) || \
																	((((CONFIG) & (uint32_t)(~EMUIE2_ALL)) == 0x00) && ((CONFIG) != 0x00)))

#endif
#if defined  HT762x
#define IS_HT_EMUIF2_CONFIG(CONFIG) (((CONFIG) == EMUIF2_PeakUaIF) || \
																	((CONFIG) == EMUIF2_PeakUbIF) || \
																	((CONFIG) == EMUIF2_PeakUcIF) || \
																	((CONFIG) == EMUIF2_SagUaIF) || \
																	((CONFIG) == EMUIF2_SagUbIF) || \
																	((CONFIG) == EMUIF2_SagUcIF) || \
																	((CONFIG) == EMUIF2_UaEndIF) || \
																	((CONFIG) == EMUIF2_UbEndIF) || \
																	((CONFIG) == EMUIF2_UcEndIF) || \
																	((CONFIG) == EMUIF2_INTUaIF) || \
																	((CONFIG) == EMUIF2_INTUbIF) || \
																	((CONFIG) == EMUIF2_INTUcIF) || \
																	((CONFIG) == EMUIF2_INTUIF) || \
																	((CONFIG) == EMUIF2_UaINTEndIF) || \
																	((CONFIG) == EMUIF2_UbINTEndIF) || \
																	((CONFIG) == EMUIF2_UcINTEndIF) || \
																	((CONFIG) == EMUIF2_IaOVIF) || \
																	((CONFIG) == EMUIF2_IbOVIF) || \
																	((CONFIG) == EMUIF2_IcOVIF) || \
																	((CONFIG) == EMUIF2_InOVIF) || \
																	((CONFIG) == EMUIF2_IaOVEndIF) || \
																	((CONFIG) == EMUIF2_IbOVEndIF) || \
																	((CONFIG) == EMUIF2_IcOVEndIF) || \
																	((CONFIG) == EMUIF2_InOVEndIF) || \
																	((CONFIG) == EMUIF2_VpupdUaIF) || \
																	((CONFIG) == EMUIF2_VpupdUbIF)|| \
																	((CONFIG) == EMUIF2_VpupdUcIF) || \
																	((CONFIG) == EMUIF2_VpupdIaIF) || \
																	((CONFIG) == EMUIF2_VpupdIbIF) || \
																	((CONFIG) == EMUIF2_VpupdIcIF) || \
																	((CONFIG) == EMUIF2_VpupdInIF))
#else
#define IS_HT_EMUIF2_CONFIG(CONFIG) (((CONFIG) == EMUIF2_PeakUIF) || \
																	((CONFIG) == EMUIF2_SagUIF) || \
																	((CONFIG) == EMUIF2_UEndIF) || \
																	((CONFIG) == EMUIF2_INTUIF) || \
																	((CONFIG) == EMUIF2_UINTEndIF) || \
																	((CONFIG) == EMUIF2_I1OVIF) || \
																	((CONFIG) == EMUIF2_I2OVIF) || \
																	((CONFIG) == EMUIF2_I1OVEndIF) || \
																	((CONFIG) == EMUIF2_I2OVEndIF) || \
																	((CONFIG) == EMUIF2_VpupdUIF) || \
																	((CONFIG) == EMUIF2_VpupdI1IF) || \
																	((CONFIG) == EMUIF2_VpupdI2IF))

#endif
#if defined  HT762x
#define IS_HT_EMU_ENERGYPOVIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_EnergyPOVIF_AllEPa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEPb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEPc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEPt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ESa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ESb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ESc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ESt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEPa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEPb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEPc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEPt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEPa) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEPb) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEPc) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEPt))
#else
#define IS_HT_EMU_ENERGYPOVIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_EnergyPOVIF_AllEP1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEP2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEPt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQ1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQ2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_AllEQt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ES1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ES2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_ESt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEP1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEP2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEPt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQ1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQ2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_FundEQt) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEP1) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEP2) || \
																	((CONFIG) == EMUIF_EnergyPOVIF_HarEPt))

#endif
#if defined  HT762x
#define IS_HT_EMU_ENERGYNOVIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_EnergyNOVIF_AllEPa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEPb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEPc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEPt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ESa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ESb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ESc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ESt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEPa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEPb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEPc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEPt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEPa) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEPb) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEPc) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEPt))
#else
#define IS_HT_EMU_ENERGYNOVIF_CONFIG(CONFIG) (((CONFIG) == EMUIF_EnergyNOVIF_AllEP1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEP2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEPt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQ1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQ2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_AllEQt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ES1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ES2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_ESt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEP1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEP2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEPt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQ1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQ2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_FundEQt) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEP1) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEP2) || \
																	((CONFIG) == EMUIF_EnergyNOVIF_HarEPt))

#endif
#define IS_HT_EWUIE_CONFIG(CONFIG) (((CONFIG) == EWUIE_HpRmsIE) || \
																	((CONFIG) == EWUIE_SyncDftUpdIE) || \
																	((CONFIG) == EWUIE_FlickerUpdIE)|| \
																	((((CONFIG) & (uint32_t)(~EWUIE_ALL)) == 0x00) && ((CONFIG) != 0x00)))




#define IS_HT_EWUIF_CONFIG(CONFIG) (((CONFIG) == EWUIF_HpRmsIF) || \
																	((CONFIG) == EWUIF_SyncDftUpdIF) || \
																	((CONFIG) == EWUIF_FlickerUpdIF))

#if defined  HT762x
#define IS_HT_EMU_DEC_ShiftH_CHANNEL_SEL(CHN) (((CHN) == ECR_DecShift_UaH) || \
																			((CHN) == ECR_DecShift_UbH) || \
                                                							((CHN) == ECR_DecShift_UcH) || \
                                                							((CHN) == ECR_DecShift_IaH) || \
                                                							((CHN) == ECR_DecShift_IbH) || \
                                                							((CHN) == ECR_DecShift_IcH) || \
                                                							((CHN) == ECR_DecShift_InH))
#else
#define IS_HT_EMU_DEC_ShiftH_CHANNEL_SEL(CHN) (((CHN) == ECR_DecShift_UH) || \
                                                							((CHN) == ECR_DecShift_I1H) || \
                                                							((CHN) == ECR_DecShift_I2H))

#endif
#if defined  HT762x
#define IS_HT_EMU_DEC_ShiftL_CHANNEL_SEL(CHN) (((CHN) == ECR_DecShift_UaL) || \
																			((CHN) == ECR_DecShift_UbL) || \
                                                							((CHN) == ECR_DecShift_UcL) || \
                                                							((CHN) == ECR_DecShift_IaL) || \
                                                							((CHN) == ECR_DecShift_IbL) || \
                                                							((CHN) == ECR_DecShift_IcL) || \
                                                							((CHN) == ECR_DecShift_InL))
#else
#define IS_HT_EMU_DEC_ShiftL_CHANNEL_SEL(CHN) (((CHN) == ECR_DecShift_UL) || \
                                                							((CHN) == ECR_DecShift_I1L) || \
                                                							((CHN) == ECR_DecShift_I2L))

#endif
#define IS_HT_EMU_DEC_ShiftH_AREA_SEL(HAE) (((HAE) == DECShift_High_Area2) || \
																			((HAE) == DECShift_High_Area1) || \
                                                							((HAE) == DECShift_High_Area0))
                                                
#define IS_HT_EMU_DEC_ShiftL_AREA_SEL(LAE) (((LAE) == DECShift_Low_Area2) || \
																			((LAE) == DECShift_Low_Area1) || \
                                                							((LAE) == DECShift_Low_Area0))
                                                
#define IS_HT_EMU_DEC_ShiftH_LIMIT(LIMIT)   ((LIMIT) <= ECR_EMU_DecShiftH_HLimit)

#define IS_HT_EMU_DEC_ShiftL_LIMIT(LIMIT)   ((LIMIT) <= ECR_EMU_DecShiftL_HLimit) 
#if defined  HT762x
#define IS_HT_EMU_ADCOffset_CHANNEL_SEL(CHN)    (((CHN) == ECR_ADCOffset_Ua) || \
																			((CHN) == ECR_ADCOffset_Ub) || \
                                                							((CHN) == ECR_ADCOffset_Uc) || \
                                                							((CHN) == ECR_ADCOffset_Ia) || \
                                                							((CHN) == ECR_ADCOffset_Ib) || \
                                                							((CHN) == ECR_ADCOffset_Ic) || \
                                                							((CHN) == ECR_ADCOffset_In))
#else
#define IS_HT_EMU_ADCOffset_CHANNEL_SEL(CHN)    (((CHN) == ECR_ADCOffset_U) || \
                                                							((CHN) == ECR_ADCOffset_I1) || \
                                                							((CHN) == ECR_ADCOffset_I2))

#endif
#define IS_HT_EMU_ADCOffset_LIMIT(LIMIT) (((LIMIT) <= ECR_EMU_ADCOffset_HLimit) && ((LIMIT) >= ECR_EMU_ADCOffset_LLimit))  
#if defined  HT762x
#define IS_HT_EMU_DigGain_CHANNEL_SEL(CHN)  (((CHN) == Digtal_gain_DGUa) || \
																		((CHN) == Digtal_gain_DGUb) || \
                                                						((CHN) == Digtal_gain_DGUc) || \
                                                						((CHN) == Digtal_gain_DGIa) || \
                                                						((CHN) == Digtal_gain_DGIb) || \
                                                						((CHN) == Digtal_gain_DGIc) || \
                                                						((CHN) == Digtal_gain_DGIn))
#else 
#define IS_HT_EMU_DigGain_CHANNEL_SEL(CHN)  (((CHN) == Digtal_gain_DGU) || \
                                                						((CHN) == Digtal_gain_DGI1) || \
                                                						((CHN) == Digtal_gain_DGI2))

#endif
#if defined  HT762x
#define IS_HT_EMU_DigGainUA_SEL(SEL)  (((SEL) == Digtal_gain_DGUa_1) || \
																		((SEL) == Digtal_gain_DGUa_2) || \
                                        								((SEL) == Digtal_gain_DGUa_4) || \
                                        								((SEL) == Digtal_gain_DGUa_8))  
                                        							
#define IS_HT_EMU_DigGainUB_SEL(SEL)  (((SEL) == Digtal_gain_DGUb_1) || \
																		((SEL) == Digtal_gain_DGUb_2) || \
                                        								((SEL) == Digtal_gain_DGUb_4) || \
                                        								((SEL) == Digtal_gain_DGUb_8))
                                        							
#define IS_HT_EMU_DigGainUC_SEL(SEL)  (((SEL) == Digtal_gain_DGUc_1) || \
																		((SEL) == Digtal_gain_DGUc_2) || \
                                        								((SEL) == Digtal_gain_DGUc_4) || \
                                        								((SEL) == Digtal_gain_DGUc_8))
                                        								
#define IS_HT_EMU_DigGainIA_SEL(SEL)  (((SEL) == Digtal_gain_DGIa_1) || \
																		((SEL) == Digtal_gain_DGIa_2) || \
																		((SEL) == Digtal_gain_DGIa_4) || \
																		((SEL) == Digtal_gain_DGIa_8))
																		
#define IS_HT_EMU_DigGainIB_SEL(SEL)  (((SEL) == Digtal_gain_DGIb_1) || \
																		((SEL) == Digtal_gain_DGIb_2) || \
																		((SEL) == Digtal_gain_DGIb_4) || \
																		((SEL) == Digtal_gain_DGIb_8))
																		
#define IS_HT_EMU_DigGainIC_SEL(SEL)  (((SEL) == Digtal_gain_DGIc_1) || \
																		((SEL) == Digtal_gain_DGIc_2) || \
                                        								((SEL) == Digtal_gain_DGIc_4) || \
                                        								((SEL) == Digtal_gain_DGIc_8))
#define IS_HT_EMU_DigGainIN_SEL(SEL)  (((SEL) == Digtal_gain_DGIn_1) || \
																		((SEL) == Digtal_gain_DGIn_2) || \
                                        								((SEL) == Digtal_gain_DGIn_4) || \
                                        								((SEL) == Digtal_gain_DGIn_8))  
#else
#define IS_HT_EMU_DigGainU_SEL(SEL)  (((SEL) == Digtal_gain_DGU_1) || \
																		((SEL) == Digtal_gain_DGU_2) || \
                                        								((SEL) == Digtal_gain_DGU_4) || \
                                        								((SEL) == Digtal_gain_DGU_8))  
#define IS_HT_EMU_DigGainI1_SEL(SEL)  (((SEL) == Digtal_gain_DGI1_1) || \
																		((SEL) == Digtal_gain_DGI1_2) || \
																		((SEL) == Digtal_gain_DGI1_4) || \
																		((SEL) == Digtal_gain_DGI1_8))
																		
#define IS_HT_EMU_DigGainI2_SEL(SEL)  (((SEL) == Digtal_gain_DGI2_1) || \
																		((SEL) == Digtal_gain_DGI2_2) || \
																		((SEL) == Digtal_gain_DGI2_4) || \
																		((SEL) == Digtal_gain_DGI2_8))

#endif

#if defined  HT762x                                       
#define IS_HT_EMU_TGain_CHANNEL_SEL(CHN)  (((CHN) == ECR_Tgain_U) || ((CHN) == ECR_Tgain_I) || ((CHN) == ECR_Tgain_In))
#else
#define IS_HT_EMU_TGain_CHANNEL_SEL(CHN)  (((CHN) == ECR_Tgain_U) || ((CHN) == ECR_Tgain_I))

#endif
#if defined  HT762x  
#define IS_HT_EMU_Gain_CHANNEL_SEL(CHN)  (((CHN) == ECR_Gain_Ua) || \
																((CHN) == ECR_Gain_Ub) || \
																((CHN) == ECR_Gain_Uc) || \
                                            					((CHN) == ECR_Gain_Ia) || \
                                            					((CHN) == ECR_Gain_Ib) || \
                                            					((CHN) == ECR_Gain_Ic) || \
                                            					((CHN) == ECR_Gain_In))
#else
#define IS_HT_EMU_Gain_CHANNEL_SEL(CHN)  (((CHN) == ECR_Gain_U) || \
                                            					((CHN) == ECR_Gain_I1) || \
                                            					((CHN) == ECR_Gain_I2))
#endif
#if defined  HT762x 
#define IS_HT_EMU_POWERGAIN_SEL(SEL) (((SEL) == ECR_All_GPa) || \
																		((SEL) == ECR_All_GPb) || \
																		((SEL) == ECR_All_GPc) || \
																		((SEL) == ECR_All_GQa) || \
																		((SEL) == ECR_All_GQb) || \
																		((SEL) == ECR_All_GQc) || \
																		((SEL) == ECR_All_GSa) || \
																		((SEL) == ECR_All_GSb) || \
																		((SEL) == ECR_All_GSc) || \
																		((SEL) == ECR_Fund_GPa) || \
																		((SEL) == ECR_Fund_GPb) || \
																		((SEL) == ECR_Fund_GPc) || \
																		((SEL) == ECR_Fund_GQa) || \
																		((SEL) == ECR_Fund_GQb) || \
																		((SEL) == ECR_Fund_GQc) || \
																		((SEL) == ECR_Fund_GSa) || \
																		((SEL) == ECR_Fund_GSb) || \
																		((SEL) == ECR_Fund_GSc) || \
																		((SEL) == ECR_Har_GPa) || \
																		((SEL) == ECR_Har_GPb) || \
																		((SEL) == ECR_Har_GPc))
#else
#define IS_HT_EMU_POWERGAIN_SEL(SEL) (((SEL) == ECR_All_GP1) || \
																		((SEL) == ECR_All_GP2) || \
																		((SEL) == ECR_All_GQ1) || \
																		((SEL) == ECR_All_GQ2) || \
																		((SEL) == ECR_All_GS1) || \
																		((SEL) == ECR_All_GS2) || \
																		((SEL) == ECR_Fund_GP1) || \
																		((SEL) == ECR_Fund_GP2) || \
																		((SEL) == ECR_Fund_GQ1) || \
																		((SEL) == ECR_Fund_GQ2) || \
																		((SEL) == ECR_Fund_GS1) || \
																		((SEL) == ECR_Fund_GS2) || \
																		((SEL) == ECR_Har_GP1) || \
																		((SEL) == ECR_Har_GP2))

#endif
#if defined  HT762x 	
#define IS_HT_EMU_PHASEGAIN_SEL(SEL) (((SEL) == ECR_All_GphsA0) || \
																		((SEL) == ECR_All_GphsA1) || \
																		((SEL) == ECR_All_GphsA2) || \
																		((SEL) == ECR_All_GphsB0) || \
																		((SEL) == ECR_All_GphsB1) || \
																		((SEL) == ECR_All_GphsB2) || \
																		((SEL) == ECR_All_GphsC0) || \
																		((SEL) == ECR_All_GphsC1) || \
																		((SEL) == ECR_All_GphsC2) || \
																		((SEL) == ECR_Fund_GphsA0) || \
																		((SEL) == ECR_Fund_GphsA1) || \
																		((SEL) == ECR_Fund_GphsA2) || \
																		((SEL) == ECR_Fund_GphsB0) || \
																		((SEL) == ECR_Fund_GphsB1) || \
																		((SEL) == ECR_Fund_GphsB2) || \
																		((SEL) == ECR_Fund_GphsC0) || \
																		((SEL) == ECR_Fund_GphsC1) || \
																		((SEL) == ECR_Fund_GphsC2))
#else
#define IS_HT_EMU_PHASEGAIN_SEL(SEL) (((SEL) == ECR_All_Gphs10) || \
																		((SEL) == ECR_All_Gphs11) || \
																		((SEL) == ECR_All_Gphs12) || \
																		((SEL) == ECR_All_Gphs20) || \
																		((SEL) == ECR_All_Gphs21) || \
																		((SEL) == ECR_All_Gphs22) || \
																		((SEL) == ECR_Fund_Gphs10) || \
																		((SEL) == ECR_Fund_Gphs11) || \
																		((SEL) == ECR_Fund_Gphs12) || \
																		((SEL) == ECR_Fund_Gphs20) || \
																		((SEL) == ECR_Fund_Gphs21) || \
																		((SEL) == ECR_Fund_Gphs22))

#endif
#if defined  HT762x 
#define IS_HT_EMU_POWEROFFSET_SEL(SEL) (((SEL) ==ECR_All_PowerOffset_Pa) || \
																			((SEL) == ECR_All_PowerOffset_Pb) || \
																			((SEL) == ECR_All_PowerOffset_Pc) || \
																			((SEL) == ECR_All_PowerOffset_Qa) || \
																			((SEL) == ECR_All_PowerOffset_Qb) || \
																			((SEL) == ECR_All_PowerOffset_Qc) || \
																			((SEL) == ECR_Fund_PowerOffset_Pa) || \
																			((SEL) == ECR_Fund_PowerOffset_Pb) || \
																			((SEL) == ECR_Fund_PowerOffset_Pc) || \
																			((SEL) == ECR_Fund_PowerOffset_Qa) || \
																			((SEL) == ECR_Fund_PowerOffset_Qb) || \
																			((SEL) == ECR_Fund_PowerOffset_Qc) || \
																			((SEL) == ECR_Har_PowerOffset_Pa) || \
																			((SEL) == ECR_Har_PowerOffset_Pb) || \
																			((SEL) == ECR_Har_PowerOffset_Pc))																			
#else
#define IS_HT_EMU_POWEROFFSET_SEL(SEL) (((SEL) ==ECR_All_PowerOffset_P1) || \
																			((SEL) == ECR_All_PowerOffset_P2) || \
																			((SEL) == ECR_All_PowerOffset_Q1) || \
																			((SEL) == ECR_All_PowerOffset_Q2) || \
																			((SEL) == ECR_Fund_PowerOffset_P1) || \
																			((SEL) == ECR_Fund_PowerOffset_P2) || \
																			((SEL) == ECR_Fund_PowerOffset_Q1) || \
																			((SEL) == ECR_Fund_PowerOffset_Q2) || \
																			((SEL) == ECR_Har_PowerOffset_P1) || \
																			((SEL) == ECR_Har_PowerOffset_P2) )

#endif
#define IS_HT_EMU_POWEROFFSET_LIMIT(LIMIT)   (((LIMIT) <= ECR_EMU_PowerOffset_HLimit) && ((LIMIT) >= ECR_EMU_PowerOffset_LLimit))
#if defined  HT762x 
#define IS_HT_EMU_RMSOFFSET_SEL(SEL) (((SEL) == ECR_All_RmsOffset_Ua) || \
																	 ((SEL) == ECR_All_RmsOffset_Ub) || \
																	 ((SEL) == ECR_All_RmsOffset_Uc) || \
																	 ((SEL) == ECR_All_RmsOffset_Ia) || \
																	 ((SEL) == ECR_All_RmsOffset_Ib) || \
																	 ((SEL) == ECR_All_RmsOffset_Ic) || \
																	 ((SEL) == ECR_All_RmsOffset_In) || \
																	 ((SEL) == ECR_RMSOffset_Ut)  || \
																	 ((SEL) == ECR_RMSOffset_It) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Ua) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Ub) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Uc) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Ia) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Ib) || \
																	 ((SEL) == ECR_Fund_RmsOffset_Ic) || \
																	 ((SEL) == ECR_Fund_RmsOffset_In) || \
																	 ((SEL) == ECR_Har_RmsOffset_Ua) || \
																	 ((SEL) == ECR_Har_RmsOffset_Ub) || \
																	 ((SEL) == ECR_Har_RmsOffset_Uc) || \
																	 ((SEL) == ECR_Har_RmsOffset_Ia) || \
																	 ((SEL) == ECR_Har_RmsOffset_Ib) || \
																	 ((SEL) == ECR_Har_RmsOffset_Ic) || \
																	 ((SEL) == ECR_Har_RmsOffset_In) )
#else
#define IS_HT_EMU_RMSOFFSET_SEL(SEL) (((SEL) == ECR_All_RmsOffset_U) || \
																	 ((SEL) == ECR_All_RmsOffset_I1) || \
																	 ((SEL) == ECR_All_RmsOffset_I2) || \
																	 ((SEL) == ECR_RMSOffset_It) || \
																	 ((SEL) == ECR_Fund_RmsOffset_U) || \
																	 ((SEL) == ECR_Fund_RmsOffset_I1) || \
																	 ((SEL) == ECR_Fund_RmsOffset_I2) || \
																	 ((SEL) == ECR_Har_RmsOffset_U) || \
																	 ((SEL) == ECR_Har_RmsOffset_I1) || \
																	 ((SEL) == ECR_Har_RmsOffset_I2))

#endif
#define IS_HT_EMU_RMSOFFSET_LIMIT(LIMIT) (((LIMIT) <= ECR_24BIT_DATA))
#if defined  HT762x 
#define IS_HT_EMU_POWERCONST_CHNNEL_SEL(SEL) (((SEL) == ECR_PowerConst_All_Pa) || \
																			((SEL) == ECR_PowerConst_All_Pb) || \
																			((SEL) == ECR_PowerConst_All_Pc) || \
																			((SEL) == ECR_PowerConst_All_Pt) || \
																			((SEL) == ECR_PowerConst_All_Qa) || \
																			((SEL) == ECR_PowerConst_All_Qb) || \
																			((SEL) == ECR_PowerConst_All_Qc) || \
																			((SEL) == ECR_PowerConst_All_Qt) || \
																			((SEL) == ECR_PowerConst_Sa) || \
																			((SEL) == ECR_PowerConst_Sb) || \
																			((SEL) == ECR_PowerConst_Sc) || \
																			((SEL) == ECR_PowerConst_St) || \
																			((SEL) == ECR_PowerConst_Fund_Pa) || \
																			((SEL) == ECR_PowerConst_Fund_Pb) || \
																			((SEL) == ECR_PowerConst_Fund_Pc) || \
																			((SEL) == ECR_PowerConst_Fund_Pt) || \
																			((SEL) == ECR_PowerConst_Fund_Qa) || \
																			((SEL) == ECR_PowerConst_Fund_Qb) || \
																			((SEL) == ECR_PowerConst_Fund_Qc) || \
																			((SEL) == ECR_PowerConst_Fund_Qt) || \
																			((SEL) == ECR_PowerConst_Har_Pa) || \
																			((SEL) == ECR_PowerConst_Har_Pb) || \
																			((SEL) == ECR_PowerConst_Har_Pc) || \
																			((SEL) == ECR_PowerConst_Har_Pt))
#else
#define IS_HT_EMU_POWERCONST_CHNNEL_SEL(SEL) (((SEL) == ECR_PowerConst_All_P1) || \
																			((SEL) == ECR_PowerConst_All_P2) || \
																			((SEL) == ECR_PowerConst_All_Pt) || \
																			((SEL) == ECR_PowerConst_All_Q1) || \
																			((SEL) == ECR_PowerConst_All_Q2) || \
																			((SEL) == ECR_PowerConst_All_Qt) || \
																			((SEL) == ECR_PowerConst_S1) || \
																			((SEL) == ECR_PowerConst_S2) || \
																			((SEL) == ECR_PowerConst_St) || \
																			((SEL) == ECR_PowerConst_Fund_P1) || \
																			((SEL) == ECR_PowerConst_Fund_P2) || \
																			((SEL) == ECR_PowerConst_Fund_Pt) || \
																			((SEL) == ECR_PowerConst_Fund_Q1) || \
																			((SEL) == ECR_PowerConst_Fund_Q2) || \
																			((SEL) == ECR_PowerConst_Fund_Qt) || \
																			((SEL) == ECR_PowerConst_Har_P1) || \
																			((SEL) == ECR_PowerConst_Har_P2) || \
																			((SEL) == ECR_PowerConst_Har_Pt))

#endif
#if defined  HT762x 
#define IS_HT_EMU_HARACCUOFFSET_CHNNEL_SEL(SEL) (((SEL) == ECR_AccuOffset_Har_Pa_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_Pa_Neg) || \
																			((SEL) == ECR_AccuOffset_Har_Pb_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_Pb_Neg) || \
																			((SEL) == ECR_AccuOffset_Har_Pc_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_Pc_Neg) || \
																			((SEL) == ECR_AccuOffset_Har_Pt_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_Pt_Neg))
																			
#else
#define IS_HT_EMU_HARACCUOFFSET_CHNNEL_SEL(SEL) (((SEL) == ECR_AccuOffset_Har_P1_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_P1_Neg) || \
																			((SEL) == ECR_AccuOffset_Har_P2_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_P2_Neg) || \
																			((SEL) == ECR_AccuOffset_Har_Pt_Pos) || \
																			((SEL) == ECR_AccuOffset_Har_Pt_Neg))

#endif

#define IS_HT_EMU_HARACCUOFFSET_LIMIT_NEG(LIMIT)   ((LIMIT) <= ECR_EMU_AccuOffset_Limit)
#define IS_HT_EMU_HARACCUOFFSET_LIMIT_POS(LIMIT)   ((LIMIT) >= ECR_EMU_AccuOffset_Limit)

#if defined  HT762x
#define IS_HT_EMU_UCONST_CHANNEL_SEL(SEL) (((SEL) == ECR_UconstA)||((SEL) == ECR_UconstB)||((SEL) == ECR_UconstC))
#else
#define IS_HT_EMU_UCONST_CHANNEL_SEL(SEL) (((SEL) == ECR_Uconst))

#endif
#define IS_HT_EMU_UCONST_LIMIT(LIMIT)   ((LIMIT) <= ECR_23BIT_DATA)

#define IS_HT_EMU_CHECHSUM_CHANNEL_SEL(SEL) (((SEL) == EPR_Checksum1)||((SEL) == EPR_Checksum2)||((SEL) == EPR_Checksum3))

#define IS_HT_EMU_ZXLOSTCFG_TYPE_SEL(SEL) (((SEL) == ZXLostCFG_ZCNumMax)||((SEL) == ZXLostCFG_ZCNumMin)||((SEL) == ZXLostCFG_NumFund))


#define IS_HT_EMU_ZCNUMMAX_LIMIT(LIMIT) ((LIMIT) <= ECR_9BIT_DATA)

#define IS_HT_EMU_ZCNUMMIN_LIMIT(LIMIT) ((LIMIT) <= ECR_9BIT_DATA)

#define IS_HT_EMU_ZCNUMFUND_LIMIT(LIMIT) ((LIMIT) <= ECR_6BIT_DATA)

#define IS_HT_EMU_POWERSTART_TYPE_SEL(SEL) (((SEL) == ECR_PStart)||((SEL) == ECR_QStart)||((SEL) == ECR_HarStart))

#define IS_HT_EMU_POWERSTART_LIMIT(LIMIT) ((LIMIT) <= ECR_16BIT_DATA)

#define IS_HT_EMU_AVGNUM_TYPE_SEL(SEL) (((SEL) == ECR_AVG_Energy) || \
																	((SEL) == ECR_AVG_PowerREG) || \
																	((SEL) == ECR_AVG_RMS) || \
																	((SEL) == ECR_AVG_RMST))

#define IS_HT_EMU_AVGNUM_LIMIT(LIMIT) (((LIMIT) >= ECR_EMU_AVGNUM_LLimit) && ((LIMIT) <= ECR_EMU_AVGNUM_HLimit))

#define IS_HT_EMU_HFCONST_TYPE_SEL(SEL) (((SEL) == ECR_HFConstAF)||((SEL) == ECR_HFConstHar))

#define IS_HT_EMU_HFCONST_LIMIT(LIMIT) (((LIMIT) >= ECR_EMU_HFConst_LLimit) && ((LIMIT) <= ECR_20BIT_DATA))

#define IS_HT_EMU_AFDIV_TYPE_SEL(SEL) (((SEL) == ECR_AFDIV)||((SEL) == ECR_HarDIV))

#define IS_HT_EMU_AFDIV_LIMIT(LIMIT) (((LIMIT) >= ECR_EMU_AFDIV_LLimit) && ((LIMIT) <= ECR_15BIT_DATA))

#if defined  HT762x
#define IS_HT_EMU_ANSIMODE_SEL(SEL) (((SEL) == ChannelSel_ANSI_Mode_NoChange) || \
																	((SEL) == ChannelSel_ANSI_Mode_UbChange1) || \
																	((SEL) == ChannelSel_ANSI_Mode_UbChange2) || \
																	((SEL) == ChannelSel_ANSI_Mode_UbUcChange))
#endif
#if defined  HT762x
#define IS_HT_EMU_CHNSEL_CHANNEL_SEL(SEL) (((SEL) == ChannelSel_UaSel) || \
																	((SEL) == ChannelSel_UbSel) || \
																	((SEL) == ChannelSel_UcSel) || \
																	((SEL) == ChannelSel_IaSel) || \
																	((SEL) == ChannelSel_IbSel) || \
																	((SEL) == ChannelSel_IcSel) || \
																	((SEL) == ChannelSel_InSel))
#else
#define IS_HT_EMU_CHNSEL_CHANNEL_SEL(SEL) (((SEL) == ChannelSel_USel) || ((SEL) == ChannelSel_I1Sel) || ((SEL) == ChannelSel_I2Sel))
#endif
#if defined  HT762x
#define IS_HT_EMU_CHNSEL_UA_SEL(SEL) (((SEL) == ChannelSel_UaSel_Ua)||((SEL) == ChannelSel_UaSel_Ub)||((SEL) == ChannelSel_UaSel_Uc))
#define IS_HT_EMU_CHNSEL_UB_SEL(SEL) (((SEL) == ChannelSel_UbSel_Ua)||((SEL) == ChannelSel_UbSel_Ub)||((SEL) == ChannelSel_UbSel_Uc))
#define IS_HT_EMU_CHNSEL_UC_SEL(SEL) (((SEL) == ChannelSel_UcSel_Ua)||((SEL) == ChannelSel_UcSel_Ub)||((SEL) == ChannelSel_UcSel_Uc))

#define IS_HT_EMU_CHNSEL_IA_SEL(SEL) (((SEL) == ChannelSel_IaSel_Ia) || \
																	((SEL) == ChannelSel_IaSel_Ib) || \
																	((SEL) == ChannelSel_IaSel_Ic) || \
																	((SEL) == ChannelSel_IaSel_In))

#define IS_HT_EMU_CHNSEL_IB_SEL(SEL) (((SEL) == ChannelSel_IbSel_Ia) || \
																	((SEL) == ChannelSel_IbSel_Ib) || \
																	((SEL) == ChannelSel_IbSel_Ic) || \
																	((SEL) == ChannelSel_IbSel_In))

#define IS_HT_EMU_CHNSEL_IC_SEL(SEL) (((SEL) == ChannelSel_IcSel_Ia) || \
																	((SEL) == ChannelSel_IcSel_Ib) || \
																	((SEL) == ChannelSel_IcSel_Ic) || \
																	((SEL) == ChannelSel_IcSel_In))

#define IS_HT_EMU_CHNSEL_IN_SEL(SEL) (((SEL) == ChannelSel_InSel_Ia) || \
																	((SEL) == ChannelSel_InSel_Ib) || \
																	((SEL) == ChannelSel_InSel_Ic) || \
																	((SEL) == ChannelSel_InSel_In))
#else
#define IS_HT_EMU_CHNSEL_U_SEL(SEL) ((SEL) == ChannelSel_USel_U)
#define IS_HT_EMU_CHNSEL_I1_SEL(SEL) (((SEL) == ChannelSel_I1Sel_I1)||((SEL) == ChannelSel_I1Sel_I2))
#define IS_HT_EMU_CHNSEL_I2_SEL(SEL) (((SEL) == ChannelSel_I2Sel_I1)||((SEL) == ChannelSel_I2Sel_I2))

#endif

#if defined  HT762x
#define IS_HT_EMU_CHNREV_CHANNEL_SEL(SEL) (((SEL) == ChannelSel_IaRev_EN) || \
																	((SEL) == ChannelSel_IbRev_EN) || \
																	((SEL) == ChannelSel_IcRev_EN) || \
																	((SEL) == ChannelSel_InRev_EN)|| \
																	((SEL) == ChannelSel_UaRev_EN) || \
																	((SEL) == ChannelSel_UbRev_EN)|| \
																	((SEL) == ChannelSel_UcRev_EN)|| \
																	((((SEL) & (uint32_t)(~ChannelSel_ChnRev_EN)) == 0x00) && ((SEL) != 0x00)))

#else
#define IS_HT_EMU_CHNREV_CHANNEL_SEL(SEL) (((SEL) == ChannelSel_I1Rev_EN) || \
																	((SEL) == ChannelSel_I2Rev_EN) || \
																	((SEL) == ChannelSel_URev_EN)|| \
																	((((SEL) & (uint32_t)(~ChannelSel_ChnRev_EN)) == 0x00) && ((SEL) != 0x00)))
#endif
#if defined  HT762x
#define IS_HT_EMU_PGA_CHANNEL_SEL(SEL) (((SEL) == PGACON_PGAU) || \
																	((SEL) == PGACON_PGAIa) || \
																	((SEL) == PGACON_PGAIb) || \
																	((SEL) == PGACON_PGAIc) || \
																	((SEL) == PGACON_PGAIn))

#else
#define IS_HT_EMU_PGA_CHANNEL_SEL(SEL) (((SEL) == PGACON_PGAU) || \
																	((SEL) == PGACON_PGAI1) || \
																	((SEL) == PGACON_PGAI2))


#endif
#define IS_HT_EMU_CHNU_PGA_SEL(SEL) (((SEL) == PGACON_PGAU_1) || \
																	((SEL) == PGACON_PGAU_2) || \
																	((SEL) == PGACON_PGAU_8))


#if defined  HT762x
#define IS_HT_EMU_CHNIA_PGA_SEL(SEL) (((SEL) == PGACON_PGAIa_1) || \
																	((SEL) == PGACON_PGAIa_2) || \
																	((SEL) == PGACON_PGAIa_8) || \
																	((SEL) == PGACON_PGAIa_16))

#define IS_HT_EMU_CHNIB_PGA_SEL(SEL) (((SEL) == PGACON_PGAIb_1) || \
																	((SEL) == PGACON_PGAIb_2) || \
																	((SEL) == PGACON_PGAIb_8) || \
																	((SEL) == PGACON_PGAIb_16))


#define IS_HT_EMU_CHNIC_PGA_SEL(SEL) (((SEL) == PGACON_PGAIc_1) || \
																	((SEL) == PGACON_PGAIc_2) || \
																	((SEL) == PGACON_PGAIc_8) || \
																	((SEL) == PGACON_PGAIc_16))


#define IS_HT_EMU_CHNIN_PGA_SEL(SEL) (((SEL) == PGACON_PGAIn_1) || \
																	((SEL) == PGACON_PGAIn_2) || \
																	((SEL) == PGACON_PGAIn_4) || \
																	((SEL) == PGACON_PGAIn_8) || \
																	((SEL) == PGACON_PGAIn_16) || \
																	((SEL) == PGACON_PGAIn_24) || \
																	((SEL) == PGACON_PGAIn_32))
#else
#define IS_HT_EMU_CHNI2_PGA_SEL(SEL) (((SEL) == PGACON_PGAI2_1) || \
																	((SEL) == PGACON_PGAI2_2) || \
																	((SEL) == PGACON_PGAI2_8) || \
																	((SEL) == PGACON_PGAI2_16))


#define IS_HT_EMU_CHNI1_PGA_SEL(SEL) (((SEL) == PGACON_PGAI1_1) || \
																	((SEL) == PGACON_PGAI1_2) || \
																	((SEL) == PGACON_PGAI1_4) || \
																	((SEL) == PGACON_PGAI1_8) || \
																	((SEL) == PGACON_PGAI1_16) || \
																	((SEL) == PGACON_PGAI1_24) || \
																	((SEL) == PGACON_PGAI1_32))
#endif
#if defined  HT762x
#define IS_HT_EMU_HPF_CHANNEL_SEL(SEL) (((SEL) == ADCCFG_HPFON_U) || \
																	((SEL) == ADCCFG_HPFON_I) || \
																	((SEL) == ADCCFG_HPFON_In)|| \
																	((((SEL) & (uint32_t)(~ADCCFG_HPFON)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_HPF_CHANNEL_SEL(SEL) (((SEL) == ADCCFG_HPFON_U) || \
																	((SEL) == ADCCFG_HPFON_I) || \
																	((((SEL) & (uint32_t)(~ADCCFG_HPFON)) == 0x00) && ((SEL) != 0x00)))
#endif
#define IS_HT_EMU_OSR_TYPE_SEL(SEL) (((SEL) == ADCCFG_OSR_SEL_64)||((SEL) == ADCCFG_OSR_SEL_128))

#define IS_HT_EMU_CLK_TYPE_SEL(SEL) (((SEL) == ADCCFG_EMUClk_SEL_819K2)||((SEL) == ADCCFG_EMUClk_SEL_1638K4))

#define IS_HT_EMU_ZCINTSRC_SEL(SEL) (((SEL) == ADCCFG_ZCINTSrc_SEL_AfterHPF) || \
																	((SEL) == ADCCFG_ZCINTSrc_SEL_BeforeHPF) || \
																	((SEL) == ADCCFG_ZCINTSrc_SEL_Fund))


#define IS_HT_EMU_SPLUPD_SEL(SEL) (((SEL) == ADCCFG_SPL_1k6) || \
																	((SEL) == ADCCFG_SPL_3k2) || \
																	((SEL) == ADCCFG_SPL_6k4) || \
																	((SEL) == ADCCFG_SPL_12k8))


#define IS_HT_EMU_ZCD_TYPE_SEL(SEL) (((SEL) == ADCCFG_ZCd_P)||((SEL) == ADCCFG_ZCd_N)||((SEL) == ADCCFG_ZCd_PN))

#define IS_HT_EMU_SPLWAVE_SEL(SEL) (((SEL) == ADCCFG_WaveSel_BeforeHPF)||((SEL) == ADCCFG_WaveSel_AfterHPF)||((SEL) == ADCCFG_WaveSel_AfterGain))

#define IS_HT_EMU_DMASRC_SEL(SEL) (((SEL) == ADCCFG_DMASrc_Sel_SPL)||((SEL) == ADCCFG_DMASrc_Sel_QuartRmsIns))

#define IS_HT_EMU_SYSFREQ_SEL(SEL) (((SEL) == ADCCFG_FreqSel_50Hz)||((SEL) == ADCCFG_FreqSel_60Hz))

#define IS_HT_EMU_ZCSRC_SEL(SEL) (((SEL) == ADCCFG_ZcSrSel_All)||((SEL) == ADCCFG_ZcSrSel_Fund))
#if defined  HT762x
#define IS_HT_EMU_DIGADC_CHANNEL_SEL(SEL) (((SEL) == ADCCON_ADC_En_Ua) || \
																	((SEL) == ADCCON_ADC_En_Ub) || \
																	((SEL) == ADCCON_ADC_En_Uc) || \
																	((SEL) == ADCCON_ADC_En_Ia) || \
																	((SEL) == ADCCON_ADC_En_Ib) || \
																	((SEL) == ADCCON_ADC_En_Ic) || \
																	((SEL) == ADCCON_ADC_En_In) || \
																	((((SEL) & (uint32_t)(~ADCCON_ADC_En)) == 0x00) && ((SEL) != 0x00)))


#define IS_HT_EMU_ANAADC_CHANNEL_SEL(SEL) (((SEL) == ADCCON_ADCEn_ANA_Ua) || \
																	((SEL) == ADCCON_ADCEn_ANA_Ub) || \
																	((SEL) == ADCCON_ADCEn_ANA_Uc) || \
																	((SEL) == ADCCON_ADCEn_ANA_Ia) || \
																	((SEL) == ADCCON_ADCEn_ANA_Ib) || \
																	((SEL) == ADCCON_ADCEn_ANA_Ic) || \
																	((SEL) == ADCCON_ADCEn_ANA_In) || \
																	((((SEL) & (uint32_t)(~ADCCON_ADCEn_ANA)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_DIGADC_CHANNEL_SEL(SEL) (((SEL) == ADCCON_ADC_En_U) || \
																	((SEL) == ADCCON_ADC_En_I1) || \
																	((SEL) == ADCCON_ADC_En_I2) || \
																	((((SEL) & (uint32_t)(~ADCCON_ADC_En)) == 0x00) && ((SEL) != 0x00)))


#define IS_HT_EMU_ANAADC_CHANNEL_SEL(SEL) (((SEL) == ADCCON_ADCEn_ANA_U) || \
																	((SEL) == ADCCON_ADCEn_ANA_I1) || \
																	((SEL) == ADCCON_ADCEn_ANA_I2) || \
																	((((SEL) & (uint32_t)(~ADCCON_ADCEn_ANA)) == 0x00) && ((SEL) != 0x00)))

#endif
#if defined  HT762x
#define IS_HT_EMU_CT2OSR_SEL(SEL) (((SEL) == ADCCON_CT2_OSR_16)||((SEL) == ADCCON_CT2_OSR_32))
#endif
#define IS_HT_EMU_PHASESRC_SEL(SEL) (((SEL) == ADCCON_Phase_Sel_All)||((SEL) == ADCCON_Phase_Sel_Fund))

#define IS_HT_EMU_PEAKSAGSRC_SEL(SEL) (((SEL) == ADCCON_PeakSagSrc_HVp)||((SEL) == ADCCON_PeakSagSrc_HRms))

#define IS_HT_EMU_POWERSCAL_SEL(SEL) (((SEL) == EMUCFG_PowerSCal_Sel_PQS)||((SEL) == EMUCFG_PowerSCal_Sel_RMS))
#if defined  HT762x
#define IS_HT_EMU_3P3UBRMSCAL_SEL(SEL) (((SEL) == EMUCFG_UacSel_Ub)||((SEL) == EMUCFG_UacSel_UaSubUc))
#endif

#if defined  HT762x
#define IS_HT_EMU_ITCFG_CHANNEL_SEL(SEL) (((SEL) == EMUCFG_ItCfgA) || \
																	((SEL) == EMUCFG_ItCfgB) || \
																	((SEL) == EMUCFG_ItCfgC) || \
																	((SEL) == EMUCFG_ItCfgN) || \
																	((((SEL) & (uint32_t)(~EMUCFG_ItCfg)) == 0x00) && ((SEL) != 0x00)))

#define IS_HT_EMU_UTCFG_CHANNEL_SEL(SEL) (((SEL) == EMUCFG_UtCfgA) || \
																	((SEL) == EMUCFG_UtCfgB) || \
																	((SEL) == EMUCFG_UtCfgC) || \
																	((((SEL) & (uint32_t)(~EMUCFG_UtCfg)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_ITCFG_CHANNEL_SEL(SEL) (((SEL) == EMUCFG_ItCfg1) || \
																	((SEL) == EMUCFG_ItCfg2) || \
																	((((SEL) & (uint32_t)(~EMUCFG_ItCfg)) == 0x00) && ((SEL) != 0x00)))

#endif
#if defined  HT762x
#define IS_HT_EMU_PTCFG_CHANNEL_SEL(SEL) (((SEL) == EMUCFG_PtCfgA)||((SEL) == EMUCFG_PtCfgB)||((SEL) == EMUCFG_PtCfgC))

#define IS_HT_EMU_PTCFGA_SEL(SEL) (((SEL) == EMUCFG_PtCfgA_PartIn)||((SEL) == EMUCFG_PtCfgA_RevPartIn)||((SEL) == EMUCFG_PtCfgA_NoPartIn))
#define IS_HT_EMU_PTCFGB_SEL(SEL) (((SEL) == EMUCFG_PtCfgB_PartIn)||((SEL) == EMUCFG_PtCfgB_RevPartIn)||((SEL) == EMUCFG_PtCfgB_NoPartIn))
#define IS_HT_EMU_PTCFGC_SEL(SEL) (((SEL) == EMUCFG_PtCfgC_PartIn)||((SEL) == EMUCFG_PtCfgC_RevPartIn)||((SEL) == EMUCFG_PtCfgC_NoPartIn))

#define IS_HT_EMU_ANGBASE_SEL(SEL) (((SEL) == EMUCFG_AngleBaseSel_Ua) || \
																	((SEL) == EMUCFG_AngleBaseSel_Ub) || \
																	((SEL) == EMUCFG_AngleBaseSel_Uc) || \
																	((SEL) == EMUCFG_AngleBaseSel_Ia) || \
																	((SEL) == EMUCFG_AngleBaseSel_Ib) || \
																	((SEL) == EMUCFG_AngleBaseSel_Ic) || \
																	((SEL) == EMUCFG_AngleBaseSel_In))

#else
#define IS_HT_EMU_PTCFG_CHANNEL_SEL(SEL) (((SEL) == EMUCFG_PtCfg1)||((SEL) == EMUCFG_PtCfg2))

#define IS_HT_EMU_PTCFG1_SEL(SEL) (((SEL) == EMUCFG_PtCfg1_PartIn)||((SEL) == EMUCFG_PtCfg1_RevPartIn)||((SEL) == EMUCFG_PtCfg1_NoPartIn))
#define IS_HT_EMU_PTCFG2_SEL(SEL) (((SEL) == EMUCFG_PtCfg2_PartIn)||((SEL) == EMUCFG_PtCfg2_RevPartIn)||((SEL) == EMUCFG_PtCfg2_NoPartIn))

#define IS_HT_EMU_ANGBASE_SEL(SEL) (((SEL) == EMUCFG_AngleBaseSel_U) || \
																	((SEL) == EMUCFG_AngleBaseSel_I1) || \
																	((SEL) == EMUCFG_AngleBaseSel_I2))
#endif



#define IS_HT_EMU_SQRMSSRC_SEL(SEL) (((SEL) == EMUCFG_SQRMS_Src_All)||((SEL) == EMUCFG_SQRMS_Src_Fund))
#if defined  HT762x
#define IS_HT_EMU_ROSI_CHANNEL_SEL(SEL) (((SEL) == FilterCon_Rosi_En_Ia) || \
																	((SEL) == FilterCon_Rosi_En_Ib) || \
																	((SEL) == FilterCon_Rosi_En_Ic) || \
																	((SEL) == FilterCon_Rosi_En_In) || \
																	((((SEL) & (uint32_t)(~FilterCon_Rosi_En)) == 0x00) && ((SEL) != 0x00)))

#else
#define IS_HT_EMU_ROSI_CHANNEL_SEL(SEL) (((SEL) == FilterCon_Rosi_En_I1) || \
																	((SEL) == FilterCon_Rosi_En_I2) || \
																	((((SEL) & (uint32_t)(~FilterCon_Rosi_En)) == 0x00) && ((SEL) != 0x00)))

#endif
#define IS_HT_EMU_ROSISHIFT_SEL(SEL) (((SEL) == FilterCon_RosiShift_1) || \
																	((SEL) == FilterCon_RosiShift_2) || \
																	((SEL) == FilterCon_RosiShift_4) || \
																	((SEL) == FilterCon_RosiShift_8))


#define IS_HT_EMU_LPF_CHANNEL_SEL(SEL) (((SEL) == FilterCon_RmsLpf_En) || \
																	((SEL) == FilterCon_PowerLpf_En) || \
																	((((SEL) & (uint32_t)(~FilterCon_Lpf_En)) == 0x00) && ((SEL) != 0x00)))
#if defined  HT762x
#define IS_HT_EMU_UCONSTEN_CHANNEL_SEL(SEL) (((SEL) == FilterCon_UconstA_En) || \
																	((SEL) == FilterCon_UconstB_En) || \
																	((SEL) == FilterCon_UconstC_En) || \
																	((((SEL) & (uint32_t)(~FilterCon_Uconst_En)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_UCONSTEN_CHANNEL_SEL(SEL) ((SEL) == FilterCon_Uconst_En)
#endif
#define IS_HT_EMU_FUNDZCDELAY_LIMIT(LIMIT) ((LIMIT) <= ECR_9BIT_DATA)

#define IS_HT_EMU_FILTERCFG_TYPE_SEL(SEL) (((SEL) == FilterCFG_HpfCtrl) || \
																	((SEL) == FilterCFG_RosiCtrl) || \
																	((SEL) == FilterCFG_LPFCtrl) || \
																	((SEL) == FilterCFG_PH90Ctrl))

#define IS_HT_EMU_HPFCTRL_LIMIT(LIMIT) ((LIMIT) <= ECR_3BIT_DATA)

#define IS_HT_EMU_ROSICTRL_LIMIT(LIMIT) ((LIMIT) <= ECR_2BIT_DATA)

#define IS_HT_EMU_LPFCTRL_LIMIT(LIMIT) ((LIMIT) <= ECR_12BIT_DATA)

#define IS_HT_EMU_PH90CTRL_LIMIT(LIMIT) ((LIMIT) <= ECR_2BIT_DATA)

#define IS_HT_EMU_STARTCFG_TYPE_SEL(SEL) (((SEL) == StartCFG_Start_CFG) || \
																	((SEL) == StartCFG_StartSrc_CFG) || \
																	((SEL) == StartCFG_HarStart_CFG))


#define IS_HT_EMU_STARTWAY_SEL(SEL) (((SEL) == StartCFG_Start_CFG_POWER1) || \
																	((SEL) == StartCFG_Start_CFG_POWER2) || \
																	((SEL) == StartCFG_Start_CFG_RMS1) || \
																	((SEL) == StartCFG_Start_CFG_RMS2))


#define IS_HT_EMU_STARTSRC_SEL(SEL) (((SEL) == StartCFG_StartSrc_CFG_AvgPower)||((SEL) == StartCFG_StartSrc_CFG_InsPower))

#define IS_HT_EMU_HARSTARTWAY_SEL(SEL) (((SEL) == StartCFG_HarStart_CFG_POWER)||((SEL) == StartCFG_HarStart_CFG_RMS))

#define IS_HT_EMU_ADCBASI_CHANNEL_SEL(SEL) (((SEL) == ANACFG1_UADC_BIAS)||((SEL) == ANACFG1_IADC_BIAS))

#define IS_HT_EMU_UADCBAIS_SEL(SEL) (((SEL) == ANACFG1_UADC_BIAS_4uA) || \
																	((SEL) == ANACFG1_UADC_BIAS_6uA) || \
																	((SEL) == ANACFG1_UADC_BIAS_8uA) || \
																	((SEL) == ANACFG1_UADC_BIAS_10uA) || \
																	((SEL) == ANACFG1_UADC_BIAS_12uA))

#define IS_HT_EMU_IADCBAIS_SEL(SEL) (((SEL) == ANACFG1_IADC_BIAS_4uA) || \
																	((SEL) == ANACFG1_IADC_BIAS_6uA) || \
																	((SEL) == ANACFG1_IADC_BIAS_8uA) || \
																	((SEL) == ANACFG1_IADC_BIAS_10uA) || \
																	((SEL) == ANACFG1_IADC_BIAS_12uA))

#define IS_HT_EMU_PGABASI_SEL(SEL) (((SEL) == ANACFG1_PGA_BIAS_5uA) || \
																	((SEL) == ANACFG1_PGA_BIAS_10uA) || \
																	((SEL) == ANACFG1_PGA_BIAS_15uA) || \
																	((SEL) == ANACFG1_PGA_BIAS_20uA) || \
																	((SEL) == ANACFG1_PGA_BIAS_25uA))

#define IS_HT_EMU_CLKCFG_LIMIT(LIMIT) ((LIMIT) <= ECR_5BIT_DATA)

#define IS_HT_EMU_CHOP_CHNNEL_SEL(SEL) (((SEL) == ANACFG2_AMPChop_En) || \
																	((SEL) == ANACFG2_UChop_En) || \
																	((SEL) == ANACFG2_IChop_En) || \
																	((SEL) == ANACFG2_InChop_En) || \
																	((SEL) == ANACFG2_VrefChop_En) || \
																	((((SEL) & (uint32_t)(~ANACFG2_Chop_En)) == 0x00) && ((SEL) != 0x00)))

#define IS_HT_EMU_VREFCTRL_LIMIT(LIMIT) ((LIMIT) <= ECR_3BIT_DATA)

#define IS_HT_EMU_VOLNUM_LIMIT(LIMIT) ((LIMIT) <= ECR_4BIT_DATA)

#define IS_HT_EMU_VCMPLVL_SEL(SEL) (((SEL) == ULostCMPCFG_VcmpLVL_0mV942) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_1mV414) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_1mV791) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_3mV140) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_4mV488) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_5mV837) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_7mV185) || \
																	((SEL) == ULostCMPCFG_VcmpLVL_9mV542))

#define IS_HT_EMU_DUTY_LIMIT(LIMIT) ((LIMIT) <= ECR_7BIT_DATA)

#define IS_HT_EMU_PRDCFG_CHANNEL_SEL(SEL) (((SEL) == ULostPRDCFG_CMPPRD) || \
																	((SEL) == ULostPRDCFG_CMPRunTime) || \
																	((SEL) == ULostPRDCFG_STBTime))

#define IS_HT_EMU_LOSTPRD_LIMIT(LIMIT) ((LIMIT) <= ECR_8BIT_DATA)

#define IS_HT_EMU_LOSTRUNTIME_LIMIT(LIMIT) ((LIMIT) <= ECR_8BIT_DATA)

#define IS_HT_EMU_LOSTSTBTIME_LIMIT(LIMIT) ((LIMIT) <= ECR_6BIT_DATA)

#define IS_HT_EMU_FAILVOLTAGE_LIMIT(LIMIT) ((LIMIT) <= ECR_16BIT_DATA)

#define IS_HT_EMU_LPCLK_SEL(SEL) (((SEL) == LPModeCON_EMUCLK_LPSel_204K8)||((SEL) == LPModeCON_EMUCLK_LPSel_32K))


#define IS_HT_EMU_LPSTBTIME_SEL(SEL) (((SEL) == LPModeCON_StandByTime_0) || \
																	((SEL) == LPModeCON_StandByTime_4) || \
																	((SEL) == LPModeCON_StandByTime_8) || \
																	((SEL) == LPModeCON_StandByTime_16) || \
																	((SEL) == LPModeCON_StandByTime_32) || \
																	((SEL) == LPModeCON_StandByTime_64) || \
																	((SEL) == LPModeCON_StandByTime_128) || \
																	((SEL) == LPModeCON_StandByTime_256) || \
																	((SEL) == LPModeCON_StandByTime_512) || \
																	((SEL) == LPModeCON_StandByTime_1024))
#if defined  HT762x
#define IS_HT_EMU_CFXRUN_CHANNEL_SEL(SEL) (((SEL) == CFxRun_All_Pa_EN) || \
																	((SEL) == CFxRun_All_Pb_EN) || \
																	((SEL) == CFxRun_All_Pc_EN) || \
																	((SEL) == CFxRun_All_Pt_EN) || \
																	((SEL) == CFxRun_All_Qa_EN) || \
																	((SEL) == CFxRun_All_Qb_EN) || \
																	((SEL) == CFxRun_All_Qc_EN) || \
																	((SEL) == CFxRun_All_Qt_EN) || \
																	((SEL) == CFxRun_Sa_EN) || \
																	((SEL) == CFxRun_Sb_EN) || \
																	((SEL) == CFxRun_Sc_EN) || \
																	((SEL) == CFxRun_St_EN) || \
																	((SEL) == CFxRun_Fund_Pa_EN) || \
																	((SEL) == CFxRun_Fund_Pb_EN) || \
																	((SEL) == CFxRun_Fund_Pc_EN) || \
																	((SEL) == CFxRun_Fund_Pt_EN) || \
																	((SEL) == CFxRun_Fund_Qa_EN) || \
																	((SEL) == CFxRun_Fund_Qb_EN) || \
																	((SEL) == CFxRun_Fund_Qc_EN) || \
																	((SEL) == CFxRun_Fund_Qt_EN) || \
																	((SEL) == CFxRun_Har_Pa_EN) || \
																	((SEL) == CFxRun_Har_Pb_EN) || \
																	((SEL) == CFxRun_Har_Pc_EN) || \
																	((SEL) == CFxRun_Har_Pt_EN) || \
																	((((SEL) & (uint32_t)(~CFxRun_EN)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_CFXRUN_CHANNEL_SEL(SEL) (((SEL) == CFxRun_All_P1_EN) || \
																	((SEL) == CFxRun_All_P2_EN) || \
																	((SEL) == CFxRun_All_Pt_EN) || \
																	((SEL) == CFxRun_All_Q1_EN) || \
																	((SEL) == CFxRun_All_Q2_EN) || \
																	((SEL) == CFxRun_All_Qt_EN) || \
																	((SEL) == CFxRun_S1_EN) || \
																	((SEL) == CFxRun_S2_EN) || \
																	((SEL) == CFxRun_St_EN) || \
																	((SEL) == CFxRun_Fund_P1_EN) || \
																	((SEL) == CFxRun_Fund_P2_EN) || \
																	((SEL) == CFxRun_Fund_Pt_EN) || \
																	((SEL) == CFxRun_Fund_Q1_EN) || \
																	((SEL) == CFxRun_Fund_Q2_EN) || \
																	((SEL) == CFxRun_Fund_Qt_EN) || \
																	((SEL) == CFxRun_Har_P1_EN) || \
																	((SEL) == CFxRun_Har_P2_EN) || \
																	((SEL) == CFxRun_Har_Pt_EN) || \
																	((((SEL) & (uint32_t)(~CFxRun_EN)) == 0x00) && ((SEL) != 0x00)))

#endif
#define IS_HT_EMU_POWERSHIFT_SEL(SEL) (((SEL) == EnergyCon_Power_Shift_1) || \
																	((SEL) == EnergyCon_Power_Shift_2) || \
																	((SEL) == EnergyCon_Power_Shift_4) || \
																	((SEL) == EnergyCon_Power_Shift_8) || \
																	((SEL) == EnergyCon_Power_Shift_16))


#define IS_HT_EMU_CFP_SEL(SEL) (((SEL) == EnergyCon_CFP_80) || \
																	((SEL) == EnergyCon_CFP_40) || \
																	((SEL) == EnergyCon_CFP_20) || \
																	((SEL) == EnergyCon_CFP_160))


#define IS_HT_EMU_POS_SEL(SEL) (((SEL) == EnergyCon_POS_High)||((SEL) == EnergyCon_POS_Low))

#define IS_HT_EMU_PTADDMODE_SEL(SEL) (((SEL) == EnergyCon_PtAddMode_ALG)||((SEL) == EnergyCon_PtAddMode_ABS))

#define IS_HT_EMU_ENERGYS_SRCSEL(SEL) (((SEL) == EnergyCon_EnergySSrc_Sel_All)||((SEL) == EnergyCon_EnergySSrc_Sel_Fund))

#define IS_HT_EMU_PASSMODE_CHANNEL_SEL(SEL) (((SEL) == EnergyCon_PassMode_All_P) || \
																	((SEL) == EnergyCon_PassMode_All_Q) || \
																	((SEL) == EnergyCon_PassMode_S) || \
																	((SEL) == EnergyCon_PassMode_Fund_P) || \
																	((SEL) == EnergyCon_PassMode_Fund_Q) || \
																	((SEL) == EnergyCon_PassMode_Har_P))


#define IS_HT_EMU_PASSMODE_ALLP_SEL(SEL) (((SEL) == EnergyCon_PassMode_All_P_All) || \
																	((SEL) == EnergyCon_PassMode_All_P_POS) || \
																	((SEL) == EnergyCon_PassMode_All_P_NEG))
																	
#define IS_HT_EMU_PASSMODE_ALLQ_SEL(SEL) (((SEL) == EnergyCon_PassMode_All_Q_All) || \
																	((SEL) == EnergyCon_PassMode_All_Q_POS) || \
																	((SEL) == EnergyCon_PassMode_All_Q_NEG))

#define IS_HT_EMU_PASSMODE_S_SEL(SEL) (((SEL) == EnergyCon_PassMode_S_All) || \
																	((SEL) == EnergyCon_PassMode_S_POS) || \
																	((SEL) == EnergyCon_PassMode_S_NEG))
																	

#define IS_HT_EMU_PASSMODE_FUNDP_SEL(SEL) (((SEL) == EnergyCon_PassMode_Fund_P_All) || \
																	((SEL) == EnergyCon_PassMode_Fund_P_POS) || \
																	((SEL) == EnergyCon_PassMode_Fund_P_NEG))


#define IS_HT_EMU_PASSMODE_FUNDQ_SEL(SEL) (((SEL) == EnergyCon_PassMode_Fund_Q_All) || \
																	((SEL) == EnergyCon_PassMode_Fund_Q_POS) || \
																	((SEL) == EnergyCon_PassMode_Fund_Q_NEG))


#define IS_HT_EMU_PASSMODE_HARP_SEL(SEL) (((SEL) == EnergyCon_PassMode_Har_P_All) || \
																	((SEL) == EnergyCon_PassMode_Har_P_POS) || \
																	((SEL) == EnergyCon_PassMode_Har_P_NEG))



#define IS_HT_EMU_POWERCFG_CHANNEL_SEL(SEL) (((SEL) == ECR_PowerSrcCFG1) || ((SEL) == ECR_PowerSrcCFG2))
#if defined  HT762x
#define IS_HT_EMU_POWERCFG1_CHANNEL_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Pa) || \
																	((SEL) == PowerSrcCFG1_All_Pb) || \
																	((SEL) == PowerSrcCFG1_All_Pc) || \
																	((SEL) == PowerSrcCFG1_All_Pt) || \
																	((SEL) == PowerSrcCFG1_All_Qa) || \
																	((SEL) == PowerSrcCFG1_All_Qb) || \
																	((SEL) == PowerSrcCFG1_All_Qc) || \
																	((SEL) == PowerSrcCFG1_All_Qt) || \
																	((SEL) == PowerSrcCFG1_Sa) || \
																	((SEL) == PowerSrcCFG1_Sb) || \
																	((SEL) == PowerSrcCFG1_Sc) || \
																	((SEL) == PowerSrcCFG1_St))


#define IS_HT_EMU_POWERCFG2_CHANNEL_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Pa) || \
																	((SEL) == PowerSrcCFG2_Fund_Pb) || \
																	((SEL) == PowerSrcCFG2_Fund_Pc) || \
																	((SEL) == PowerSrcCFG2_Fund_Pt) || \
																	((SEL) == PowerSrcCFG2_Fund_Qa) || \
																	((SEL) == PowerSrcCFG2_Fund_Qb) || \
																	((SEL) == PowerSrcCFG2_Fund_Qc) || \
																	((SEL) == PowerSrcCFG2_Fund_Qt) || \
																	((SEL) == PowerSrcCFG2_Har_Pa) || \
																	((SEL) == PowerSrcCFG2_Har_Pb) || \
																	((SEL) == PowerSrcCFG2_Har_Pc) || \
																	((SEL) == PowerSrcCFG2_Har_Pt))
#else
#define IS_HT_EMU_POWERCFG1_CHANNEL_SEL(SEL) (((SEL) == PowerSrcCFG1_All_P1) || \
																	((SEL) == PowerSrcCFG1_All_P2) || \
																	((SEL) == PowerSrcCFG1_All_Pt) || \
																	((SEL) == PowerSrcCFG1_All_Q1) || \
																	((SEL) == PowerSrcCFG1_All_Q2) || \
																	((SEL) == PowerSrcCFG1_All_Qt) || \
																	((SEL) == PowerSrcCFG1_S1) || \
																	((SEL) == PowerSrcCFG1_S2) || \
																	((SEL) == PowerSrcCFG1_St))


#define IS_HT_EMU_POWERCFG2_CHANNEL_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_P1) || \
																	((SEL) == PowerSrcCFG2_Fund_P2) || \
																	((SEL) == PowerSrcCFG2_Fund_Pt) || \
																	((SEL) == PowerSrcCFG2_Fund_Q1) || \
																	((SEL) == PowerSrcCFG2_Fund_Q2) || \
																	((SEL) == PowerSrcCFG2_Fund_Qt) || \
																	((SEL) == PowerSrcCFG2_Har_P1) || \
																	((SEL) == PowerSrcCFG2_Har_P2) || \
																	((SEL) == PowerSrcCFG2_Har_Pt))

#endif


#define IS_HT_EMU_POWERSRC_ALLPT_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Pt_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Pt_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Pt_ConstPower))
																	
#define IS_HT_EMU_POWERSRC_ALLQT_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Qt_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Qt_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Qt_ConstPower))


#define IS_HT_EMU_POWERSRC_ST_SEL(SEL) (((SEL) == PowerSrcCFG1_St_AvgPower) || \
																	((SEL) == PowerSrcCFG1_St_InsPower) || \
																	((SEL) == PowerSrcCFG1_St_ConstPower))



#define IS_HT_EMU_POWERSRC_FUNDPT_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Pt_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pt_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pt_ConstPower))

#define IS_HT_EMU_POWERSRC_FUNDQT_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Qt_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qt_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qt_ConstPower))


#define IS_HT_EMU_POWERSRC_HARPT_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_Pt_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pt_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pt_ConstPower))

#if defined  HT762x
#define IS_HT_EMU_POWERSRC_ALLPA_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Pa_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Pa_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Pa_ConstPower))


#define IS_HT_EMU_POWERSRC_ALLPB_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Pb_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Pb_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Pb_ConstPower))

#define IS_HT_EMU_POWERSRC_ALLPC_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Pc_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Pc_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Pc_ConstPower))


#define IS_HT_EMU_POWERSRC_ALLQA_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Qa_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Qa_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Qa_ConstPower))


#define IS_HT_EMU_POWERSRC_ALLQB_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Qb_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Qb_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Qb_ConstPower))

#define IS_HT_EMU_POWERSRC_ALLQC_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Qc_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Qc_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Qc_ConstPower))


#define IS_HT_EMU_POWERSRC_SA_SEL(SEL) (((SEL) == PowerSrcCFG1_Sa_AvgPower) || \
																	((SEL) == PowerSrcCFG1_Sa_InsPower) || \
																	((SEL) == PowerSrcCFG1_Sa_ConstPower))


#define IS_HT_EMU_POWERSRC_SB_SEL(SEL) (((SEL) == PowerSrcCFG1_Sb_AvgPower) || \
																	((SEL) == PowerSrcCFG1_Sb_InsPower) || \
																	((SEL) == PowerSrcCFG1_Sb_ConstPower))

#define IS_HT_EMU_POWERSRC_SC_SEL(SEL) (((SEL) == PowerSrcCFG1_Sc_AvgPower) || \
																	((SEL) == PowerSrcCFG1_Sc_InsPower) || \
																	((SEL) == PowerSrcCFG1_Sc_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDPA_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Pa_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pa_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pa_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDPB_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Pb_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pb_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pb_ConstPower))

#define IS_HT_EMU_POWERSRC_FUNDPC_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Pc_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pc_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Pc_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDQA_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Qa_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qa_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qa_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDQB_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Qb_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qb_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qb_ConstPower))

#define IS_HT_EMU_POWERSRC_FUNDQC_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Qc_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qc_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Qc_ConstPower))


#define IS_HT_EMU_POWERSRC_HARPA_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_Pa_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pa_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pa_ConstPower))

#define IS_HT_EMU_POWERSRC_HARPB_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_Pb_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pb_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pb_ConstPower))

#define IS_HT_EMU_POWERSRC_HARPC_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_Pc_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pc_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_Pc_ConstPower))

#else
#define IS_HT_EMU_POWERSRC_ALLP1_SEL(SEL) (((SEL) == PowerSrcCFG1_All_P1_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_P1_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_P1_ConstPower))

#define IS_HT_EMU_POWERSRC_ALLP2_SEL(SEL) (((SEL) == PowerSrcCFG1_All_P2_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_P2_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_P2_ConstPower))

#define IS_HT_EMU_POWERSRC_ALLQ1_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Q1_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Q1_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Q1_ConstPower))

#define IS_HT_EMU_POWERSRC_ALLQ2_SEL(SEL) (((SEL) == PowerSrcCFG1_All_Q2_AvgPower) || \
																	((SEL) == PowerSrcCFG1_All_Q2_InsPower) || \
																	((SEL) == PowerSrcCFG1_All_Q2_ConstPower))


#define IS_HT_EMU_POWERSRC_S1_SEL(SEL) (((SEL) == PowerSrcCFG1_S1_AvgPower) || \
																	((SEL) == PowerSrcCFG1_S1_InsPower) || \
																	((SEL) == PowerSrcCFG1_S1_ConstPower))

#define IS_HT_EMU_POWERSRC_S2_SEL(SEL) (((SEL) == PowerSrcCFG1_S2_AvgPower) || \
																	((SEL) == PowerSrcCFG1_S2_InsPower) || \
																	((SEL) == PowerSrcCFG1_S2_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDP1_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_P1_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_P1_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_P1_ConstPower))

#define IS_HT_EMU_POWERSRC_FUNDP2_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_P2_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_P2_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_P2_ConstPower))


#define IS_HT_EMU_POWERSRC_FUNDQ1_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Q1_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Q1_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Q1_ConstPower))

#define IS_HT_EMU_POWERSRC_FUNDQ2_SEL(SEL) (((SEL) == PowerSrcCFG2_Fund_Q2_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Q2_InsPower) || \
																	((SEL) == PowerSrcCFG2_Fund_Q2_ConstPower))


#define IS_HT_EMU_POWERSRC_HARP1_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_P1_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_P1_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_P1_ConstPower))

#define IS_HT_EMU_POWERSRC_HARP2_SEL(SEL) (((SEL) == PowerSrcCFG2_Har_P2_AvgPower) || \
																	((SEL) == PowerSrcCFG2_Har_P2_InsPower) || \
																	((SEL) == PowerSrcCFG2_Har_P2_ConstPower))


#endif

#define IS_HT_EMU_ACCUMODE_CHANNEL_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_AllP) || \
																	((SEL) == PowerModeCFG_AccuMode_AllQ) || \
																	((SEL) == PowerModeCFG_AccuMode_S) || \
																	((SEL) == PowerModeCFG_AccuMode_FundP) || \
																	((SEL) == PowerModeCFG_AccuMode_FundQ) || \
																	((SEL) == PowerModeCFG_AccuMode_HarP))

#define IS_HT_EMU_ACCUMODE_ALLP_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_AllP_0) || \
																	((SEL) == PowerModeCFG_AccuMode_AllP_1) || \
																	((SEL) == PowerModeCFG_AccuMode_AllP_2) || \
																	((SEL) == PowerModeCFG_AccuMode_AllP_3))


#define IS_HT_EMU_ACCUMODE_ALLQ_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_AllQ_0) || \
																	((SEL) == PowerModeCFG_AccuMode_AllQ_1) || \
																	((SEL) == PowerModeCFG_AccuMode_AllQ_2) || \
																	((SEL) == PowerModeCFG_AccuMode_AllQ_3))

#define IS_HT_EMU_ACCUMODE_S_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_S_0) || \
																	((SEL) == PowerModeCFG_AccuMode_S_1) || \
																	((SEL) == PowerModeCFG_AccuMode_S_2) || \
																	((SEL) == PowerModeCFG_AccuMode_S_3))

#define IS_HT_EMU_ACCUMODE_FUNDP_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_FundP_0) || \
																	((SEL) == PowerModeCFG_AccuMode_FundP_1) || \
																	((SEL) == PowerModeCFG_AccuMode_FundP_2) || \
																	((SEL) == PowerModeCFG_AccuMode_FundP_3))

#define IS_HT_EMU_ACCUMODE_FUNDQ_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_FundQ_0) || \
																	((SEL) == PowerModeCFG_AccuMode_FundQ_1) || \
																	((SEL) == PowerModeCFG_AccuMode_FundQ_2) || \
																	((SEL) == PowerModeCFG_AccuMode_FundQ_3))

#define IS_HT_EMU_ACCUMODE_HARP_SEL(SEL) (((SEL) == PowerModeCFG_AccuMode_HarP_0) || \
																	((SEL) == PowerModeCFG_AccuMode_HarP_1) || \
																	((SEL) == PowerModeCFG_AccuMode_HarP_2) || \
																	((SEL) == PowerModeCFG_AccuMode_HarP_3))


#define IS_HT_EMU_POWEROVSEL_CHANNEL_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_AllP) || \
																	((SEL) == PowerModeCFG_PowerOVSel_AllQ) || \
																	((SEL) == PowerModeCFG_PowerOVSel_S) || \
																	((SEL) == PowerModeCFG_PowerOVSel_FundP) || \
																	((SEL) == PowerModeCFG_PowerOVSel_FundQ) || \
																	((SEL) == PowerModeCFG_PowerOVSel_HarP))


#define IS_HT_EMU_POWEROVSEL_ALLP_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_AllP_P)||((SEL) == PowerModeCFG_PowerOVSel_AllP_PN))

#define IS_HT_EMU_POWEROVSEL_ALLQ_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_AllQ_P)||((SEL) == PowerModeCFG_PowerOVSel_AllQ_PN))

#define IS_HT_EMU_POWEROVSEL_S_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_S_P)||((SEL) == PowerModeCFG_PowerOVSel_S_PN))

#define IS_HT_EMU_POWEROVSEL_FUNDP_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_FundP_P)||((SEL) == PowerModeCFG_PowerOVSel_FundP_PN))

#define IS_HT_EMU_POWEROVSEL_FUNDQ_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_FundQ_P)||((SEL) == PowerModeCFG_PowerOVSel_FundQ_PN))

#define IS_HT_EMU_POWEROVSEL_HARP_SEL(SEL) (((SEL) == PowerModeCFG_PowerOVSel_HarP_P)||((SEL) == PowerModeCFG_PowerOVSel_HarP_PN))

#define IS_HT_EMU_JUDGEEN_CHANNEL_SEL(SEL) (((SEL) == PowerModeCFG_JudgeEn_AllP) || \
																	((SEL) == PowerModeCFG_JudgeEn_AllQ) || \
																	((SEL) == PowerModeCFG_JudgeEn_S) || \
																	((SEL) == PowerModeCFG_JudgeEn_FundP) || \
																	((SEL) == PowerModeCFG_JudgeEn_FundQ) || \
																	((SEL) == PowerModeCFG_JudgeEn_HarP) || \
																	((((SEL) & (uint32_t)(~PowerModeCFG_JudgeEn)) == 0x00) && ((SEL) != 0x00)))


#define IS_HT_EMU_CFCFG_CHANNEL_SEL(SEL) (((SEL) == ECR_CFCFG1) || ((SEL) == ECR_CFCFG2))

#define IS_HT_EMU_CFCFG1_CHANNEL_SEL(SEL) (((SEL) == CFCFG1_IO0) || ((SEL) == CFCFG1_IO1) || ((SEL) == CFCFG1_IO2))

#define IS_HT_EMU_CFCFG2_CHANNEL_SEL(SEL) (((SEL) == CFCFG2_IO3) || ((SEL) == CFCFG2_IO4))


#define IS_HT_EMU_CFCFG_IO0_SEL(SEL) (((SEL) == CFCFG1_IO0_PN1) || \
																	((SEL) == CFCFG1_IO0_P1) || \
																	((SEL) == CFCFG1_IO0_N1) || \
																	((SEL) == CFCFG1_IO0_PN2) || \
																	((SEL) == CFCFG1_IO0_P2) || \
																	((SEL) == CFCFG1_IO0_N2) || \
																	((SEL) == CFCFG1_IO0_PN3) || \
																	((SEL) == CFCFG1_IO0_P3) || \
																	((SEL) == CFCFG1_IO0_N3) || \
																	((SEL) == CFCFG1_IO0_PN4) || \
																	((SEL) == CFCFG1_IO0_P4) || \
																	((SEL) == CFCFG1_IO0_N4) || \
																	((SEL) == CFCFG1_IO0_PN5) || \
																	((SEL) == CFCFG1_IO0_P5) || \
																	((SEL) == CFCFG1_IO0_N5) || \
																	((SEL) == CFCFG1_IO0_PN6) || \
																	((SEL) == CFCFG1_IO0_P6) || \
																	((SEL) == CFCFG1_IO0_N6))


#define IS_HT_EMU_CFCFG_IO1_SEL(SEL) (((SEL) == CFCFG1_IO1_PN1) || \
																	((SEL) == CFCFG1_IO1_P1) || \
																	((SEL) == CFCFG1_IO1_N1) || \
																	((SEL) == CFCFG1_IO1_PN2) || \
																	((SEL) == CFCFG1_IO1_P2) || \
																	((SEL) == CFCFG1_IO1_N2) || \
																	((SEL) == CFCFG1_IO1_PN3) || \
																	((SEL) == CFCFG1_IO1_P3) || \
																	((SEL) == CFCFG1_IO1_N3) || \
																	((SEL) == CFCFG1_IO1_PN4) || \
																	((SEL) == CFCFG1_IO1_P4) || \
																	((SEL) == CFCFG1_IO1_N4) || \
																	((SEL) == CFCFG1_IO1_PN5) || \
																	((SEL) == CFCFG1_IO1_P5) || \
																	((SEL) == CFCFG1_IO1_N5) || \
																	((SEL) == CFCFG1_IO1_PN6) || \
																	((SEL) == CFCFG1_IO1_P6) || \
																	((SEL) == CFCFG1_IO1_N6))


#define IS_HT_EMU_CFCFG_IO2_SEL(SEL) (((SEL) == CFCFG1_IO2_PN1) || \
																	((SEL) == CFCFG1_IO2_P1) || \
																	((SEL) == CFCFG1_IO2_N1) || \
																	((SEL) == CFCFG1_IO2_PN2) || \
																	((SEL) == CFCFG1_IO2_P2) || \
																	((SEL) == CFCFG1_IO2_N2) || \
																	((SEL) == CFCFG1_IO2_PN3) || \
																	((SEL) == CFCFG1_IO2_P3) || \
																	((SEL) == CFCFG1_IO2_N3) || \
																	((SEL) == CFCFG1_IO2_PN4) || \
																	((SEL) == CFCFG1_IO2_P4) || \
																	((SEL) == CFCFG1_IO2_N4) || \
																	((SEL) == CFCFG1_IO2_PN5) || \
																	((SEL) == CFCFG1_IO2_P5) || \
																	((SEL) == CFCFG1_IO2_N5) || \
																	((SEL) == CFCFG1_IO2_PN6) || \
																	((SEL) == CFCFG1_IO2_P6) || \
																	((SEL) == CFCFG1_IO2_N6))




#define IS_HT_EMU_CFCFG_IO3_SEL(SEL) (((SEL) == CFCFG2_IO3_PN1) || \
																	((SEL) == CFCFG2_IO3_P1) || \
																	((SEL) == CFCFG2_IO3_N1) || \
																	((SEL) == CFCFG2_IO3_PN2) || \
																	((SEL) == CFCFG2_IO3_P2) || \
																	((SEL) == CFCFG2_IO3_N2) || \
																	((SEL) == CFCFG2_IO3_PN3) || \
																	((SEL) == CFCFG2_IO3_P3) || \
																	((SEL) == CFCFG2_IO3_N3) || \
																	((SEL) == CFCFG2_IO3_PN4) || \
																	((SEL) == CFCFG2_IO3_P4) || \
																	((SEL) == CFCFG2_IO3_N4) || \
																	((SEL) == CFCFG2_IO3_PN5) || \
																	((SEL) == CFCFG2_IO3_P5) || \
																	((SEL) == CFCFG2_IO3_N5) || \
																	((SEL) == CFCFG2_IO3_PN6) || \
																	((SEL) == CFCFG2_IO3_P6) || \
																	((SEL) == CFCFG2_IO3_N6))



#define IS_HT_EMU_CFCFG_IO4_SEL(SEL) (((SEL) == CFCFG2_IO4_PN1) || \
																	((SEL) == CFCFG2_IO4_P1) || \
																	((SEL) == CFCFG2_IO4_N1) || \
																	((SEL) == CFCFG2_IO4_PN2) || \
																	((SEL) == CFCFG2_IO4_P2) || \
																	((SEL) == CFCFG2_IO4_N2) || \
																	((SEL) == CFCFG2_IO4_PN3) || \
																	((SEL) == CFCFG2_IO4_P3) || \
																	((SEL) == CFCFG2_IO4_N3) || \
																	((SEL) == CFCFG2_IO4_PN4) || \
																	((SEL) == CFCFG2_IO4_P4) || \
																	((SEL) == CFCFG2_IO4_N4) || \
																	((SEL) == CFCFG2_IO4_PN5) || \
																	((SEL) == CFCFG2_IO4_P5) || \
																	((SEL) == CFCFG2_IO4_N5) || \
																	((SEL) == CFCFG2_IO4_PN6) || \
																	((SEL) == CFCFG2_IO4_P6) || \
																	((SEL) == CFCFG2_IO4_N6))


#define IS_HT_EMU_ACCESS_STATE(STATE) (((STATE) == AUTO) || ((STATE) == MANUAL))

#define IS_HT_EMUWPREG_STATE(STATE) (((STATE) == EMU_WPREG_Unprotected) || \
																		((STATE) == EMUFILTER_WPREG_Unprotected)|| \
																		((STATE) == EMU_WPREG_Protected))
#if defined  HT762x
#define IS_HT_EMU_PLL_SOURCE_SEL(SEL) (((SEL) == PLL_CTRL_PLL_source_Ua) || \
																	((SEL) == PLL_CTRL_PLL_source_Ub) || \
																	((SEL) == PLL_CTRL_PLL_source_Uc))
																
#else
#define IS_HT_EMU_PLL_SOURCE_SEL(SEL) (((SEL) == PLL_CTRL_PLL_source_U))
#endif
#define IS_HT_EMU_PLLFLAG_CONFIG(CONFIG) (((CONFIG) == PLL_CTRL_PLL_locked_flag) ||((CONFIG) == PLL_CTRL_PLL_freeze))

#define IS_HT_EMU_SFO_LIMIT(LIMIT) ((LIMIT) <= ECR_24BIT_DATA)															


#define IS_HT_PLL_LockTHO_LIMIT(LIMIT) ((LIMIT) <= ECR_23BIT_DATA)

#define IS_HT_PLL_AmpTHO_LIMIT(LIMIT) ((LIMIT) <= ECR_25BIT_DATA)

#define IS_HT_PLL_TEDAmnt_LIMIT(LIMIT) ((LIMIT) <= ECR_8BIT_DATA)




/**
* @brief  HT_EMU_PLLPARAMETER_ADDR
*/ 
#define IS_HT_EMU_PLLPARAMETER_ADDR(ADDR) (((ADDR) == ECR_PLL_Gain) || \
																	((ADDR) == ECR_TED_Amnt) || \
																	((ADDR) == ECR_Lock_THO)|| \
																	((ADDR) == ECR_AMP_THO))
#if defined  HT762x											
#define IS_HT_EMU_SYNC_CHANNEL_SEL(SEL) (((SEL) == SYNC_CFG_SYNC_UaEn) || \
																	((SEL) == SYNC_CFG_SYNC_UbEn) || \
																	((SEL) == SYNC_CFG_SYNC_UcEn) || \
																	((SEL) == SYNC_CFG_SYNC_IaEn) || \
																	((SEL) == SYNC_CFG_SYNC_IbEn) || \
																	((SEL) == SYNC_CFG_SYNC_IcEn) || \
																	((SEL) == SYNC_CFG_SYNC_InEn) || \
																	((((SEL) & (uint32_t)(~SYNC_CFG_SYNC_ChannelEn)) == 0x00) && ((SEL) != 0x00)))
#else
#define IS_HT_EMU_SYNC_CHANNEL_SEL(SEL) (((SEL) == SYNC_CFG_SYNC_UEn) || \
																	((SEL) == SYNC_CFG_SYNC_I1En) || \
																	((SEL) == SYNC_CFG_SYNC_I2En) || \
																	((((SEL) & (uint32_t)(~SYNC_CFG_SYNC_ChannelEn)) == 0x00) && ((SEL) != 0x00)))

#endif
#define IS_HT_EMU_SYNC_FFTRate_SEL(SEL) (((SEL) == SYNC_CFG_SYNC_Rate_256_1C) || \
																	((SEL) == SYNC_CFG_SYNC_Rate_128_1C) || \
																	((SEL) == SYNC_CFG_SYNC_Rate_1024_10C)|| \
																	((SEL) == SYNC_CFG_SYNC_Rate_1024_12C))

#define IS_HT_EMU_RMSUpdHp_SEL(SEL) (((SEL) == SYNC_CFG_RmsUpdHp_HALF) || \
																	((SEL) == SYNC_CFG_RmsUpdHp_ONE))

#define IS_HT_EMU_SYNC_Interface_BWSEL(SEL) (((SEL) == SYNC_CFG_Sync_DMA_bw_mode_16) || \
																		((SEL) == SYNC_CFG_Sync_DMA_bw_mode_24) || \
																		((SEL) == SYNC_CFG_Sync_DMA_bw_mode_32))
																	
#if defined  HT762x
#define IS_HT_EMU_REC_CHANNEL_SEL(SEL) (((SEL) == REC_CFG_REC_UaEn) || \
																	((SEL) == REC_CFG_REC_UbEn) || \
																	((SEL) == REC_CFG_REC_UcEn) || \
																	((SEL) == REC_CFG_REC_IaEn) || \
																	((SEL) == REC_CFG_REC_IbEn) || \
																	((SEL) == REC_CFG_REC_IcEn) || \
																	((SEL) == REC_CFG_REC_InEn) || \
																	((((SEL) & (uint32_t)(~REC_CFG_REC_En)) == 0x00) && ((SEL) != 0x00)))												
#else
#define IS_HT_EMU_REC_CHANNEL_SEL(SEL) (((SEL) == REC_CFG_REC_UEn) || \
																	((SEL) == REC_CFG_REC_I1En) || \
																	((SEL) == REC_CFG_REC_I2En) || \
																	((((SEL) & (uint32_t)(~REC_CFG_REC_En)) == 0x00) && ((SEL) != 0x00)))												

#endif
#define IS_HT_EMU_RECRate_SEL(SEL) (((SEL) == REC_CFG_REC_RateSelect_32) || \
																	((SEL) == REC_CFG_REC_RateSelect_64) || \
																	((SEL) == REC_CFG_REC_RateSelect_128)|| \
																	((SEL) == REC_CFG_REC_RateSelect_256))

#define IS_HT_EMU_RECSignalSrc_SEL(SEL) (((SEL) == REC_CFG_REC_signalSrc_Sync) || \
																		((SEL) == REC_CFG_REC_signalSrc_Gain))

#define IS_HT_EMU_DFTLPF_SEL(SEL) (((SEL) == DFT_CFG_DFT_LPF_I) || \
																		((SEL) == DFT_CFG_DFT_LPF_U))
																																	
#define IS_HT_EMU_DFTLPF_LIMIT(LIMIT) ((LIMIT) <= ECR_3BIT_DATA)	

#define IS_HT_EMU_SYNCRSHIFT_LIMIT(LIMIT) ((LIMIT) <= ECR_4BIT_DATA)	

#define IS_HT_EMU_HpRMSOFFSET_LIMIT(LIMIT) ((LIMIT) <= ECR_6BIT_DATA)	

#define IS_HT_EMU_FlickerUpRate_LIMIT(LIMIT) ((LIMIT) <= ECR_5BIT_DATA)	

#define IS_HT_EMU_FlickerFiltershift_LIMIT(LIMIT) ((LIMIT) <= ECR_3BIT_DATA)

#if defined  HT762x
#define IS_HT_EMU_SYNC_DMARSHIFT_SEL(SEL) (((SEL) == SYNC_DMA_rShift_Ua) || \
																	((SEL) == SYNC_DMA_rShift_Ub) || \
																	((SEL) == SYNC_DMA_rShift_Uc) || \
																	((SEL) == SYNC_DMA_rShift_Ia) || \
																	((SEL) == SYNC_DMA_rShift_Ib) || \
																	((SEL) == SYNC_DMA_rShift_Ic) || \
																	((SEL) == SYNC_DMA_rShift_In))	
#else
#define IS_HT_EMU_SYNC_DMARSHIFT_SEL(SEL) (((SEL) == SYNC_DMA_rShift_U) || \
																	((SEL) == SYNC_DMA_rShift_I1) || \
																	((SEL) == SYNC_DMA_rShift_I2))	

#endif
#if defined  HT762x
#define IS_HT_EMU_HpRMS_U_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_U_UaEnable) || \
																			((SEL) == HpRMS_Ctl_U_UbEnable) || \
																			((SEL) == HpRMS_Ctl_U_UcEnable))	


#define IS_HT_EMU_HpRMS_I_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_I_IaEnable) || \
																			((SEL) == HpRMS_Ctl_I_IbEnable) || \
																			((SEL) == HpRMS_Ctl_I_IcEnable) || \
																			((SEL) == HpRMS_Ctl_I_InEnable))

#define IS_HT_EMU_HpRMSOFFSET_U_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_U_Offset_Ua) || \
																					((SEL) == HpRMS_Ctl_U_Offset_Ub) || \
																					((SEL) == HpRMS_Ctl_U_Offset_Uc))

#define IS_HT_EMU_HpRMSOFFSET_I_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_I_Offset_Ia) || \
																					((SEL) == HpRMS_Ctl_I_Offset_Ib) || \
																					((SEL) == HpRMS_Ctl_I_Offset_Ic) || \
																					((SEL) == HpRMS_Ctl_I_Offset_In))
#else
#define IS_HT_EMU_HpRMS_U_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_U_UEnable))	


#define IS_HT_EMU_HpRMS_I_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_I_I1Enable) ||((SEL) == HpRMS_Ctl_I_I2Enable))

#define IS_HT_EMU_HpRMSOFFSET_U_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_U_Offset_U))

#define IS_HT_EMU_HpRMSOFFSET_I_CHANNEL_SEL(SEL) (((SEL) == HpRMS_Ctl_I_Offset_I1) || ((SEL) == HpRMS_Ctl_I_Offset_I2))

#endif
#define IS_HT_EMU_UPeakSagIntIOV_LIMIT(LIMIT) ((LIMIT) <= ECR_16BIT_DATA)	

#define IS_HT_EMU_UPeakSagIntIOVCyc_ADDR(ADDR) (((ADDR) == ECR_UPeakSagCyc) ||((ADDR) == ECR_UIntCyc) ||((ADDR) == ECR_IOVCyc))

#define IS_HT_EMU_UPeakSagIntIOVLVL_ADDR(ADDR) (((ADDR) == ECR_PeakLVL) || \
																	((ADDR) == ECR_SagLVL) || \
																	((ADDR) == ECR_IntLVL) || \
																	((ADDR) == ECR_IOVLVL))

#define IS_HT_EMU_UPeakSagIntIOVHys_ADDR(ADDR) (((ADDR) == ECR_PeakLVLHys) || \
																	((ADDR) == ECR_SagLVLHys) || \
																	((ADDR) == ECR_IntLVLHys) || \
																	((ADDR) == ECR_IOVLVLHys))

#define IS_HT_EMU_UIZCLVL_LIMIT(LIMIT) ((LIMIT) <= ECR_21BIT_DATA)	

#define IS_HT_EMU_UIZCLVL_ADDR(ADDR) (((ADDR) == ECR_UZCLVL) || ((ADDR) == ECR_IZCLVL))

#if defined  HT762x
#define IS_HT_EMU_UITCCOFF_ADDR(ADDR) (((ADDR) == ECR_TU_CCOFF_A) || \
																	((ADDR) == ECR_TU_CCOFF_B) || \
																	((ADDR) == ECR_TU_CCOFF_C)|| \
																	((ADDR) == ECR_TI_CCOFF_A)|| \
																	((ADDR) == ECR_TI_CCOFF_B)|| \
																	((ADDR) == ECR_TI_CCOFF_C)|| \
																	((ADDR) == ECR_TIn_CCOFF_A)|| \
																	((ADDR) == ECR_TIn_CCOFF_B)|| \
																	((ADDR) == ECR_TIn_CCOFF_C))
#else
#define IS_HT_EMU_UITCCOFF_ADDR(ADDR) (((ADDR) == ECR_TU_CCOFF_A) || \
																	((ADDR) == ECR_TU_CCOFF_B) || \
																	((ADDR) == ECR_TU_CCOFF_C)|| \
																	((ADDR) == ECR_TI_CCOFF_A)|| \
																	((ADDR) == ECR_TI_CCOFF_B)|| \
																	((ADDR) == ECR_TI_CCOFF_C))
#endif
#define IS_HT_EMU_IregionLVLHys_LIMIT(LIMIT) ((LIMIT) <= ECR_23BIT_DATA)	

#define IS_HT_EMU_IregionLVLHys_ADDR(ADDR) (((ADDR) == ECR_Iregion0) || \
																	((ADDR) == ECR_Iregion1)|| \
																	((ADDR) == ECR_Iregion0Hys)|| \
																	((ADDR) == ECR_Iregion1Hys))
#if defined  HT762x
#define IS_HT_EMU_Flicker_U_CHANNEL_SEL(SEL) (((SEL) == FlickerCfg_FlickerUaEn) || \
																	((SEL) == FlickerCfg_FlickerUbEn) || \
																	((SEL) == FlickerCfg_FlickerUcEn) || \
																	((((SEL) & (uint32_t)(~FlickerCfg_FlickerEn)) == 0x00) && ((SEL) != 0x00)))	
#else
#define IS_HT_EMU_Flicker_U_CHANNEL_SEL(SEL) (((SEL) == FlickerCfg_FlickerUEn))
#endif
#define IS_HT_EMU_UIRMSItLVL_LIMIT(LIMIT) ((LIMIT) <= ECR_23BIT_DATA)	
#if defined  HT762x
#define IS_HT_EMU_UIRMSItLVL_ADDR(ADDR) (((ADDR) == ECR_RMSUt_THO) || ((ADDR) == ECR_RMSIt_THO))
#else
#define IS_HT_EMU_UIRMSItLVL_ADDR(ADDR) (((ADDR) == ECR_RMSIt_THO))
#endif
																
#define IS_HT_EMU_FlickerFiltershift_SEL(SEL) (((SEL) == FlickerCfg_bpf_lshift) ||((SEL) == FlickerCfg_hpf_lshift))

#define IS_HT_EMU_HarAlgMode_SEL(SEL) (((SEL) == FundHarCFG_Har_AlgMode0) ||((SEL) == FundHarCFG_Har_AlgMode1))																	

#define IS_HT_EMU_HarFilShift_SEL(SEL) (((SEL) == FundHarCFG_HarFilter_Shift_1) || \
																	((SEL) == FundHarCFG_HarFilter_Shift_2) || \
																	((SEL) == FundHarCFG_HarFilter_Shift_4)|| \
																	((SEL) == FundHarCFG_HarFilter_Shift_8)|| \
																	((SEL) == FundHarCFG_HarFilter_Shift_16)|| \
																	((SEL) == FundHarCFG_HarFilter_Shift_32)|| \
																	((SEL) == FundHarCFG_HarFilter_Shift_64)|| \
																	((SEL) == FundHarCFG_HarFilter_Shift_128))

#define IS_HT_EMU_InMultiFunc_SEL(SEL) (((SEL) == FundHarCFG_InMultiFuncSel_HAR) || ((SEL) == FundHarCFG_InMultiFuncSel_OTHER))	

#define IS_HT_EMU_InHarFilShift_SEL(SEL) (((SEL) == FundHarCFG_InHarFilterShift_1) || \
																	((SEL) == FundHarCFG_InHarFilterShift_2) || \
																	((SEL) == FundHarCFG_InHarFilterShift_4)|| \
																	((SEL) == FundHarCFG_InHarFilterShift_8)|| \
																	((SEL) == FundHarCFG_InHarFilterShift_16)|| \
																	((SEL) == FundHarCFG_InHarFilterShift_32)|| \
																	((SEL) == FundHarCFG_InHarFilterShift_64)|| \
																	((SEL) == FundHarCFG_InHarFilterShift_128))

/*
*********************************************************************************************************
*                                            Global variable 
*********************************************************************************************************
*/
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
typedef struct __EMU_InitTypeDef
{
	__IO uint32_t    ErrorCode;        		  /*!< EMU Error code                    */
	void (* EmuCallback)(struct __EMU_InitTypeDef *EMU_InitStruct);               /*!< EMU  Complete Callback             */
}EMU_InitTypeDef;        

typedef struct __EWU_InitTypeDef
{
	__IO uint32_t    ErrorCode;        		  /*!< EWU Error code                    */
	void (* EwuCallback)(struct __EWU_InitTypeDef *EWU_InitStruct);               /*!< EWU  Complete Callback             */
}EWU_InitTypeDef;        

/**
* @brief  EMU Callback pointer definition
*/
typedef  void (*pEMU_CallbackTypeDef)(EMU_InitTypeDef *EMU_InitStruct);  /*!< pointer to an EMU callback function */

typedef  void (*pEWU_CallbackTypeDef)(EWU_InitTypeDef *EWU_InitStruct);  /*!< pointer to an EWU callback function */

#endif/* USE_EMU_REGISTER_CALLBACKS */



/*
*********************************************************************************************************
*                                           Global function declaration
*********************************************************************************************************
*/
uint32_t HT_EMU_EPReg_Read(uint32_t addr);
uint32_t HT_EMU_ECReg_Read(uint32_t addr);
void HT_EMU_ECReg_Write(uint32_t addr, uint32_t data);
ITStatus HT_EMU_Noload_StatusGet(uint32_t ulStatus);
ITStatus HT_EMU_RevPower_StatusGet(uint32_t ulStatus);
ITStatus HT_EMU_RevEnergy_StatusGet(uint32_t ulStatus);
ITStatus HT_EMU_P90Power_StatusGet(uint32_t ulStatus);
ITStatus HT_EMU_Signal_StatusGet(uint32_t ulStatus);
ITStatus HT_EMU_PeakSagIntIov_StatusGet(uint32_t ulStatus);
void HT_EMUIE1_Config(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_EMUIF1_FlagStatusGet(uint32_t ITFlag);
void HT_EMUIF1_PendingBitClear(uint32_t ITFlag);
void HT_EMUIE2_Config(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_EMUIF2_FlagStatusGet(uint32_t ITFlag);
void HT_EMUIF2_PendingBitClear(uint32_t ITFlag);
ITStatus HT_EMU_EnergyPOVIF_FlagStatusGet(uint32_t ITFlag);
void HT_EMU_EnergyPOVIF_PendingBitClear(uint32_t ITFlag);
ITStatus HT_EMU_EnergyNOVIF_FlagStatusGet(uint32_t ITFlag);
void HT_EMU_EnergyNOVIF_PendingBitClear(uint32_t ITFlag);
void HT_EMU_EWUIE_Config(uint32_t ITEn, FunctionalState NewState);
ITStatus HT_EMU_EWUIF_FlagStatusGet(uint32_t ITFlag);
void HT_EMU_EWUIF_PendingBitClear(uint32_t ITFlag);
void HT_EMU_DEC_ShiftHSet(uint32_t Channel, uint32_t Area, uint32_t data);
void HT_EMU_DEC_ShiftLSet(uint32_t Channel, uint32_t Area, uint32_t data);
uint32_t HT_EMU_DEC_ShiftHGet(uint32_t Channel, uint32_t Area);
uint32_t HT_EMU_DEC_ShiftLGet(uint32_t Channel, uint32_t Area);
void HT_EMU_ADCOffsetSet(uint32_t Channel, int32_t data);
int32_t HT_EMU_ADCOffsetGet(uint32_t Channel);
void HT_EMU_Digital_GainSet(uint32_t Channel,uint32_t select);
void HT_EMU_TGainSet(uint32_t Channel, int16_t data);
void HT_EMU_GainSet(uint32_t Channel, int16_t data);
int16_t HT_EMU_TGainGet(uint32_t Channel);
int16_t HT_EMU_GainGet(uint32_t Channel);
void HT_EMU_PowerGainSet(uint32_t Channel,int16_t data);
int16_t HT_EMU_PowerGainGet(uint32_t Channel);
void HT_EMU_PhaseGainSet(uint32_t Channel,int16_t data);
int16_t HT_EMU_PhaseGainGet(uint32_t Channel);
void HT_EMU_PowerOffsetSet(uint32_t Channel, int32_t data);
int32_t HT_EMU_PowerOffsetGet(uint32_t Channel);
void HT_EMU_RMSOffsetSet(uint32_t Channel,uint32_t data);
uint32_t HT_EMU_RMSOffsetGet(uint32_t Channel);
void HT_EMU_PowerConstSet(uint32_t Channel,int32_t data);
int32_t HT_EMU_PowerConstGet(uint32_t Channel);
void HT_EMU_HarAccuOffsetSet(uint32_t Channel,int32_t data);
int32_t HT_EMU_HarAccuOffsetGet(uint32_t Channel);
uint32_t HT_EMU_ChecksumGet(uint32_t Chanel);
void HT_EMU_UConstSet(uint32_t Chanel,uint32_t data);
uint32_t HT_EMU_UConstGet(uint32_t Chanel);
void HT_EMU_ZxLostCFG_NumSet(uint32_t Type,uint32_t data);
void HT_EMU_PowerStartSet(uint32_t Type,uint32_t data);
uint32_t HT_EMU_PowerStartGet(uint32_t Type);
void HT_EMU_AvgNumSet(uint32_t Type,uint32_t data);
uint32_t HT_EMU_AvgNumGet(uint32_t Type);
void HT_EMU_HFConstSet(uint32_t Type,uint32_t data);
uint32_t HT_EMU_HFConstGet(uint32_t Type);
void HT_EMU_AFDIVSet(uint32_t Type,uint32_t data);
uint32_t HT_EMU_AFDIVGet(uint32_t Type);
#if defined  HT762x
void HT_EMU_ChnSel_AnsiModeSet(uint32_t select);
#endif
void HT_EMU_ChnSel_ChnSelSet(uint32_t Channel,uint32_t select);
void HT_EMU_ChnSel_ChnRevEnSet(uint32_t Chanel,FunctionalState NewState);
void HT_EMU_PGACON_PGASet(uint32_t Channel,uint32_t select);
void HT_EMU_ADCCFG_HpfEnSet(uint32_t Chanel,FunctionalState NewState);
void HT_EMU_ADCCFG_OSRSet(uint32_t Type);
void HT_EMU_ADCCFG_DecCompEnSet(FunctionalState NewState);
void HT_EMU_ADCCFG_EmuClkSet(uint32_t Type);
void HT_EMU_ADCCFG_ZcIntSrcSet(uint32_t Type);
void HT_EMU_ADCCFG_SplUpdateSet(uint32_t Type);
void HT_EMU_ADCCFG_ZcdSet(uint32_t Type);
void HT_EMU_ADCCFG_SplWaveSet(uint32_t Type);
void HT_EMU_ADCCFG_AutoTCEnSet(FunctionalState NewState);
void HT_EMU_ADCCFG_DmaSrcSet(uint32_t Type);
#if defined  HT762x
void HT_EMU_ADCCFG_Mode3p3EnSet(FunctionalState NewState);
#endif
void HT_EMU_ADCCFG_SysFreqSet(uint32_t Type);
void HT_EMU_ADCCFG_ZcSrcSet(uint32_t Type);
void HT_EMU_ADCCON_AdcChnEnSet(uint32_t DChn,uint32_t AChn,FunctionalState NewState);
void HT_EMU_ADCCON_DigADCEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_ADCCON_AnaADCEnSet(uint32_t Channel,FunctionalState NewState);
#if defined  HT762x
void HT_EMU_ADCCON_CT2EnSet(FunctionalState NewState);
void HT_EMU_ADCCON_CT2OsrSet(uint32_t Type);
#endif
void HT_EMU_ADCCON_PhaseSrcSet(uint32_t Type);
void HT_EMU_ADCCON_UPeakEnSet(FunctionalState NewState);
void HT_EMU_ADCCON_USagEnSet(FunctionalState NewState);
void HT_EMU_ADCCON_UIntEnSet(FunctionalState NewState);
void HT_EMU_ADCCON_IovEnSet(FunctionalState NewState);
void HT_EMU_ADCCON_PeakSagSrcSet(uint32_t Type);
void HT_EMU_EMUCFG_ItFundRmsEnSet(FunctionalState NewState);
#if defined  HT762x
void HT_EMU_EMUCFG_UtFundRmsEnSet(FunctionalState NewState);
#endif
void HT_EMU_EMUCFG_UFundLRmsEnSet(FunctionalState NewState);
void HT_EMU_EMUCFG_PowerSCalSet(uint32_t Type);
#if defined  HT762x
void HT_EMU_EMUCFG_3P3UbRmsCalSet(uint32_t Type);
#endif
void HT_EMU_EMUCFG_ItCfgSet(uint32_t Channel,FunctionalState NewState);
#if defined  HT762x
void HT_EMU_EMUCFG_UtCfgSet(uint32_t Channel,FunctionalState NewState);
#endif
void HT_EMU_EMUCFG_PtCfgSet(uint32_t Channel,uint32_t select);
void HT_EMU_EMUCFG_AutoAngBaseEnSet(FunctionalState NewState);
void HT_EMU_EMUCFG_AngBaseSet(uint32_t Type);
void HT_EMU_EMUCFG_SqRmsSrcSet(uint32_t Type);
void HT_EMU_FilterCon_IRosiEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_FilterCon_RosiShiftSet(uint32_t Type);
void HT_EMU_FilterCon_LpfEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_FilterCon_UConstEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_FilterCon_FundZcDelaySet(uint32_t data);
void HT_EMU_FilterCFG_Set(uint32_t Type,uint32_t select);
void HT_EMU_StartCFG_Set(uint32_t Type,uint32_t select);
void HT_EMU_ANACFG1_AdcBasiSet(uint32_t Channel,uint32_t select);
void HT_EMU_ANACFG1_PgaBasiSet(uint32_t Type);
void HT_EMU_ANACFG1_ClkCfgSet(uint32_t data);
void HT_EMU_ANACFG1_EmuLdoEnSet(FunctionalState NewState);
void HT_EMU_ANACFG1_VrefEnSet(FunctionalState NewState);
void HT_EMU_ANACFG2_ChopEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_ANACFG2_TC2NdEnSet(FunctionalState NewState);
void HT_EMU_ANACFG2_IRefEnSet(FunctionalState NewState);
void HT_EMU_ANACFG2_VrefCrtlSet(uint32_t data);
#if defined  HT762x
void HT_EMU_ULostCMPCFG_CmpEnSet(FunctionalState NewState);
void HT_EMU_ULostCMPCFG_VolNumSet(uint32_t data);
void HT_EMU_ULostCMPCFG_LvlSet(uint32_t Type);
void HT_EMU_ULostCMPCFG_DutySet(uint32_t data);
void HT_EMU_ULostCMPCFG_CmpPrdEnSet(FunctionalState NewState);
void HT_EMU_ULostPRDCFG_Set(uint32_t Type,uint32_t data);
#endif
void HT_EMU_FailVoltageSet(uint32_t data);
uint32_t HT_EMU_FailVoltageGet(void);
void HT_EMU_LPModeCON_LpModeEnSet(FunctionalState NewState);
void HT_EMU_LPModeCON_LpClkSet(uint32_t Type);
void HT_EMU_LPModeCON_LpVrefEnSet(FunctionalState NewState);
void HT_EMU_LPModeCON_STBTimeSet(uint32_t Type);
void HT_EMU_CFxRun_ChnEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_EnergyCon_PowerShiftSet(uint32_t Type);
void HT_EMU_EnergyCon_CFPSet(uint32_t Type);
void HT_EMU_EnergyCon_PosSet(uint32_t Type);
void HT_EMU_EnergyCon_PtAddModeSet(uint32_t Type);
void HT_EMU_EnergyCon_EnergyRCEnSet(FunctionalState NewState);
void HT_EMU_EnergyCon_EnergySSrcSet(uint32_t Type);
void HT_EMU_EnergyCon_PassModeSet(uint32_t Channel,uint32_t select);
void HT_EMU_PowerSrcCFG_Set(uint32_t SrcChnl,uint32_t Channel,uint32_t select);
void HT_EMU_PowerModeCFG_AccuModeSet(uint32_t Channel,uint32_t select);
void HT_EMU_PowerModeCFG_OvSelSet(uint32_t Channel,uint32_t select);
void HT_EMU_PowerModeCFG_JudgeEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_CFCFG_Set(uint32_t CfCfgChnl,uint32_t Channel,uint32_t select);
void HT_EMU_SyncSysEnSet(FunctionalState NewState);
void HT_EMU_SyncReset(void);
void HT_EMU_Sync_ChannelEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_SyncOutEnSet(FunctionalState NewState);
void HT_EMU_SyncToFFTRateSel(uint32_t Type);
void HT_EMU_SyncDFTEnSet(FunctionalState NewState);
void HT_EMU_SyncLpfEnSet(FunctionalState NewState);
void HT_EMU_SfoEnSet(FunctionalState NewState);
void HT_EMU_RmsUpdHpSel(uint32_t Type);
void HT_EMU_SyncToInterfaceBwSel(uint32_t Type);
void HT_EMU_RecEnSet(FunctionalState NewState);
void HT_EMU_RecReset(void);
void HT_EMU_RecChannelEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_RecRateSel(uint32_t Type);
void HT_EMU_RecSignalSrcSel(uint32_t Type);
void HT_EMU_RecLpfEnSet(FunctionalState NewState);
void HT_EMU_DFTLpfCoeffSet(uint32_t Type, uint32_t data);
void HT_EMU_SyncDmaRShiftSet(uint32_t Type, uint32_t data);
void HT_EMU_HpRmsUChannelEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_HpRmsIChannelEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_HpRmsOffsetUSet(uint32_t Type, uint32_t data);
void HT_EMU_HpRmsOffsetISet(uint32_t Type, uint32_t data);
void HT_EMU_PLLEnSet(FunctionalState NewState);
void HT_EMU_PLLFreezeSet(FunctionalState NewState);
void HT_EMU_PLLReset(void);
void HT_EMU_PLLManualSfo_Config(AccessState NewState);
void HT_EMU_PLLSourceSel(uint32_t Type);
ITStatus HT_EMU_PLLFlagStatusGet(uint32_t ITFlag);
void HT_EMU_PLLSfoSet(uint32_t data);
void HT_EMU_PLLParameterSet(uint32_t type,uint32_t data);
void HT_EMU_PowerConstLoad(void);
void HT_EMU_PeakSagIntIovCycSet(uint32_t type,uint32_t data);
void HT_EMU_PeakSagIntIovLvlSet(uint32_t type,uint32_t data);
void HT_EMU_PeakSagIntIovHysSet(uint32_t type,uint32_t data);
void HT_EMU_ZCLvlSet(uint32_t type,uint32_t data);
void HT_EMU_AutoTcCoffSet(uint32_t type,int16_t data);
void HT_EMU_RegionHysLvlSet(uint32_t type,uint32_t data);
void HT_EMU_DecReset(void);
void HT_EMU_EMUWPREG_Set(uint32_t NewState);
void HT_EMU_SRSTREG_EMUModule_Reset(void);
void HT_EMU_SRSTREG_EMUECR_Reset(void);
void HT_EMU_FlickerUEnSet(uint32_t Channel,FunctionalState NewState);
void HT_EMU_FlickerUpRateSet(uint32_t data);
void HT_EMU_FlickerLShiftSet(uint32_t Type, uint32_t data);
void HT_EMU_FlickerReset(void);
void HT_EMU_RmsThoSet(uint32_t type,uint32_t data);
void HT_EMU_FundHarFuncEnSet(FunctionalState NewState);
void HT_EMU_AllFuncEnSet(FunctionalState NewState);
void HT_EMU_HarAlgModeSel(uint32_t Type);
void HT_EMU_HarFilterShiftSel(uint32_t Type);
#if defined  HT762x
void HT_EMU_InMultiFuncSel(uint32_t Type);
void HT_EMU_InMultiFuncEnSet(FunctionalState NewState);
void HT_EMU_InHarFilterShiftSel(uint32_t Type);
#endif
void HT_EMU_SyncPLL_Init(SyncPLL_InitTypeDef *SyncPLLInit);
void HT_EMU_HpRms_Init(HpRms_InitTypeDef* HpRmsInit);
void HT_EMU_REC_Init(REC_InitTypeDef *RECInit);
void HT_EMU_SyncFFT_Init(SyncFFT_InitTypeDef *SyncFFTInit);
void HT_EMU_DecComp_Init(DecComp_InitTypeDef *DecCompInit);
void HT_EMU_Rms_Init(Rms_InitTypeDef *RmsInit);
void HT_EMU_ZC_Init(ZeroCross_InitTypeDef *ZCInit);
void HT_EMU_SagPeakIntIov_Init(SagPeakIntIov_InitTypeDef *SagPeakIntIovInit);
void HT_EMU_Ang_Init(Ang_InitTypeDef *AngInit);
void HT_EMU_UConst_Init(UConst_InitTypeDef *UConstInit);
void HT_EMU_MultiFilter_Init(MultiFilter_InitTypeDef *MultiFilterInit);
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
void HT_EMU_CpltCallback(EMU_InitTypeDef *EMU_InitStruct);
void HT_EMU_InitCallbacksToDefault(EMU_InitTypeDef *EMU_InitStruct);
StatusTypeDef HT_EMU_RegisterCallback(EMU_InitTypeDef *EMU_InitStruct, pEMU_CallbackTypeDef pCallback);
void HT_EWU_CpltCallback(EWU_InitTypeDef *EWU_InitStruct);
void HT_EWU_InitCallbacksToDefault(EWU_InitTypeDef *EWU_InitStruct);
StatusTypeDef HT_EWU_RegisterCallback(EWU_InitTypeDef *EWU_InitStruct, pEWU_CallbackTypeDef pCallback);

#endif /* USE_HT_EMU_REGISTER_CALLBACKS */



#endif                                               /* This File Only support HT7xxx */

#ifdef __cplusplus
}
#endif

#endif /* __HT7XXX_EMU_H__ */ 

