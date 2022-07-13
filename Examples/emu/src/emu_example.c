/*
*********************************************************************************************************
*                                              HT6XXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : emu_example.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#include "ht6xxx_lib.h"
#include "emu_example.h"

#if defined  HT762x  || defined  HT772x 

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


#if(USE_HT_EMU_REGISTER_CALLBACKS == 1U)
extern	EMU_InitTypeDef EmuHandle;
extern	EWU_InitTypeDef EwuHandle;
#endif
/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
	 

/**
*********************************************************************************************************
*                                  EMU EXAMPLES FOR HT7XXX                                       
* @brief : EMU module Init 
* @param : None
* @retval: None
* @note  : The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
void HT_EMU_Init_Example(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    uint32_t DigAdcChnEN = 0U,AnaAdcChnEN = 0U,CfEN = 0U;
	
    /*************************
    //Config System CLK to PLL 19.66M
    CMU_InitTypeDef  CMU_InitStructure;
    CMU_InitStructure.CPUDiv = CPUDiv1;         //FCPU= Fsys/1
    CMU_InitStructure.SysClkSel = SysPLL;       //!< Fpll en ---> Fsys 
    HT_CMU_Init(&CMU_InitStructure);
    ******************/
    /*Enable EMU ClkCtrl */
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_EMUEN,ENABLE);   /* enable EMU CLK */
    /* Config FGPIO to PFout */
	/* 1.PFOUT 1 2 3 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF1;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;         /*useless*/
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;       /*useless*/
    #if defined USE_GPIO_FILT
    GPIO_InitStructure.GPIO_InputFilter = ENABLE;       		 /*useless*/
    #endif
    HT_GPIO_Init(HT_GPIOB, &GPIO_InitStructure);        
	/* 2.PFOUT 0 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF1;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
    GPIO_InitStructure.GPIO_InputFilter = ENABLE;
    #endif
    HT_GPIO_Init(HT_GPIOA, &GPIO_InitStructure);        
	/* 3.PFOUT 4 */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF2;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
    GPIO_InitStructure.GPIO_InputFilter = ENABLE;
    #endif
    HT_GPIO_Init(HT_GPIOE, &GPIO_InitStructure);        
    
    /*EMU module init */
    HT_EMU_ANACFG1_EmuLdoEnSet(ENABLE);                 /* Enable EMU Ldo */
    HT_EMU_ANACFG1_VrefEnSet(ENABLE);                   /* Enable  Vref */
    HT_EMU_ANACFG2_IRefEnSet(ENABLE);                   /* Enable  Iref */
    HT_EMU_ADCCFG_OSRSet(ADCCFG_OSR_SEL_128);           /* OSR = OSR128 */
    HT_EMU_ADCCFG_EmuClkSet(ADCCFG_EMUClk_SEL_1638K4);  /*emuclk  = 1.6MHz */
	
	/****channel select***/
#if defined  HT772x
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_USel,ChannelSel_USel_U);
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_I1Sel,ChannelSel_I1Sel_I1);
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_I2Sel,ChannelSel_I2Sel_I2);
#endif
	
	/* Users can choose according to their own conditions */
	/* Enable ADC Channel */
#if defined  HT762x
    AnaAdcChnEN = ADCCON_ADCEn_ANA_Ua | ADCCON_ADCEn_ANA_Ub | ADCCON_ADCEn_ANA_Uc;
    AnaAdcChnEN |= (ADCCON_ADCEn_ANA_Ia|ADCCON_ADCEn_ANA_Ib|ADCCON_ADCEn_ANA_Ic|ADCCON_ADCEn_ANA_In);
	
    DigAdcChnEN = ADCCON_ADC_En_Ua|ADCCON_ADC_En_Ub|ADCCON_ADC_En_Uc;
    DigAdcChnEN |= (ADCCON_ADC_En_Ia|ADCCON_ADC_En_Ib|ADCCON_ADC_En_Ic|ADCCON_ADC_En_In);
#else
    AnaAdcChnEN = ADCCON_ADCEn_ANA_U | ADCCON_ADCEn_ANA_I1 | ADCCON_ADCEn_ANA_I2;
    DigAdcChnEN = ADCCON_ADC_En_U|ADCCON_ADC_En_I1|ADCCON_ADC_En_I2;
#endif
	
    HT_EMU_ADCCON_AdcChnEnSet(DigAdcChnEN, AnaAdcChnEN, ENABLE);       /* Enable ADC */
	
	/* Users can choose according to their own conditions */
	/*  Enable Energy Channel Run */
#if defined  HT762x
    CfEN = CFxRun_All_Pa_EN | CFxRun_All_Pb_EN | CFxRun_All_Pc_EN | CFxRun_All_Pt_EN;    /* enable all-wave Active energy channel */
    CfEN |= (CFxRun_All_Qa_EN | CFxRun_All_Qb_EN | CFxRun_All_Qc_EN | CFxRun_All_Qt_EN); /* enable all-wave reactive energy channel */
    CfEN |= (CFxRun_Sa_EN | CFxRun_Sb_EN | CFxRun_Sc_EN | CFxRun_St_EN);                 /* enable Apparent energy channel */
#else
    CfEN = CFxRun_All_P1_EN | CFxRun_All_P2_EN | CFxRun_All_Pt_EN;   				/* enable all-wave Active energy channel */
    CfEN |= (CFxRun_All_Q1_EN | CFxRun_All_Q2_EN | CFxRun_All_Qt_EN); 				/* enable all-wave reactive energy channel */
    CfEN |= (CFxRun_S1_EN | CFxRun_S2_EN | CFxRun_St_EN);                			/* enable Apparent energy channel */
#endif
    HT_EMU_CFxRun_ChnEnSet(CfEN, ENABLE);   /* enable energy channel */
				
	/**Interrupt init****/
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
	/********************************************
	* default call back name or set call back name
	*********************************************/
	EmuHandle.ErrorCode = EMU_ERROR_NONE;
	HT_EMU_InitCallbacksToDefault(&EmuHandle);
	EwuHandle.ErrorCode = EWU_ERROR_NONE;
	HT_EWU_InitCallbacksToDefault(&EwuHandle);

#endif
}

/**
*********************************************************************************************************
*                                  EMU EXAMPLES FOR HT6XXX                                       
* @brief : EMU module resample Init 
* @param : None
* @retval: None
* @note  : The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
void HT_EMU_Resample_Init_Example(void)
{
	SyncPLL_InitTypeDef SyncPLL;
	HpRms_InitTypeDef HpRms;
	REC_InitTypeDef Record;
	SyncFFT_InitTypeDef SyncFFT;
	EMUIFACE_InitTypeDef EMUIFace_InitStruct;
	uint32_t RecChnEN = 0U;
	uint32_t FFTChnEN = 0U;
	/*************************
    * Config Sync & PLL Module
    ******************/
    SyncPLL.PLL_manual_sfo = AUTO; 	/* Choose PLL SFO Mode:AUTO */
	SyncPLL.Freeze_En = DISABLE; 	/* Choose PLL Freeze Mode:freeze */
#if defined  HT762x
	SyncPLL.PLL_SourceSel = PLL_CTRL_PLL_source_Ua; /* Choose PLL signal source :UA */
#else
	SyncPLL.PLL_SourceSel = PLL_CTRL_PLL_source_U; /* Choose PLL signal source :U */
#endif
	SyncPLL.SyncSys_En = ENABLE; 	/* Enable SyncSys */
	SyncPLL.SyncSfo_En = ENABLE; 	/* Enable SyncSys SFO  */
	SyncPLL.SyncdisLpf_En = ENABLE;
	SyncPLL.SyncDFT_En = ENABLE;
	SyncPLL.DFT_LPF_ICoeff = 0X07;
	SyncPLL.DFT_LPF_UCoeff = 0X07;
	SyncPLL.PLL_Gain = 0x40003000;  /* Set PLL Parameters  */
	SyncPLL.Lock_THO = 0x00FA0;		/* Set PLL Parameters  */
	SyncPLL.AMP_THO = 0x000064;		/* Set PLL Parameters  */
	SyncPLL.TED_Amnt = 0x04;		/* Set PLL Parameters  */
#if defined  HT762x
	SyncPLL.SyncDMARshift_Ua = 0x00;
	SyncPLL.SyncDMARshift_Ub = 0x00;
	SyncPLL.SyncDMARshift_Uc = 0x00;
	SyncPLL.SyncDMARshift_Ia = 0x00;
	SyncPLL.SyncDMARshift_Ib = 0x00;
	SyncPLL.SyncDMARshift_Ic = 0x00;
	SyncPLL.SyncDMARshift_In = 0x00;
#else
	SyncPLL.SyncDMARshift_U = 0x00;
	SyncPLL.SyncDMARshift_I1 = 0x00;
	SyncPLL.SyncDMARshift_I2 = 0x00;
#endif
	SyncPLL.PLL_En = DISABLE;      /* Disable PLL module  */
	HT_EMU_SyncPLL_Init(&SyncPLL);
	/*************************
    * Config HpRMS Module
    ******************/
#if defined  HT762x
    HpRms.HpRMSOffset_Ua = 0x00;
	HpRms.HpRMSOffset_Ub = 0x00;
	HpRms.HpRMSOffset_Uc = 0x00;
	HpRms.HpRMSOffset_Ia = 0x00;
	HpRms.HpRMSOffset_Ib = 0x00;
	HpRms.HpRMSOffset_Ic = 0x00;
	HpRms.HpRMSOffset_In = 0x00;
	HpRms.HpRMS_Ctl_UaEnable = ENABLE;
	HpRms.HpRMS_Ctl_UbEnable = ENABLE;
	HpRms.HpRMS_Ctl_UcEnable = ENABLE;
	HpRms.HpRMS_Ctl_IaEnable = ENABLE;
	HpRms.HpRMS_Ctl_IbEnable = ENABLE;
	HpRms.HpRMS_Ctl_IcEnable = ENABLE;
	HpRms.HpRMS_Ctl_InEnable = ENABLE;
#else
	HpRms.HpRMSOffset_U = 0x00;
	HpRms.HpRMSOffset_I1 = 0x00;
	HpRms.HpRMSOffset_I2 = 0x00;
	HpRms.HpRMS_Ctl_UEnable = ENABLE;
	HpRms.HpRMS_Ctl_I1Enable = ENABLE;
	HpRms.HpRMS_Ctl_I2Enable = ENABLE;
#endif
	HT_EMU_HpRms_Init(&HpRms);
	/*************************
    * Config Record Module
    ******************/
		
    Record.REC_LpfEn = ENABLE;
	Record.REC_signalSrc = 	REC_CFG_REC_signalSrc_Sync;  /* Choose Record signal source : sync system output */
    Record.REC_RateSel = REC_CFG_REC_RateSelect_256;
#if defined  HT762x
	RecChnEN = REC_CFG_REC_UaEn | REC_CFG_REC_UbEn | REC_CFG_REC_UcEn;
    RecChnEN |= (REC_CFG_REC_IaEn|REC_CFG_REC_IbEn|REC_CFG_REC_IcEn|REC_CFG_REC_InEn);
#else
	RecChnEN = REC_CFG_REC_UEn | REC_CFG_REC_I1En | REC_CFG_REC_I2En;
#endif
	Record.REC_ChannelEn = RecChnEN;  	/* Enable record channel */
	Record.REC_ChannelEnState = ENABLE;
	Record.REC_En = ENABLE;
	HT_EMU_REC_Init(&Record);
	/*************************
    * Config SyncFFTinit Module
    ******************/
    SyncFFT.FFT_BWSel = SYNC_CFG_Sync_DMA_bw_mode_32;
	SyncFFT.FFT_RateSel = SYNC_CFG_SYNC_Rate_256_1C;
#if defined  HT762x
	FFTChnEN = SYNC_CFG_SYNC_UaEn | SYNC_CFG_SYNC_UbEn | SYNC_CFG_SYNC_UcEn;
    FFTChnEN |= (SYNC_CFG_SYNC_IaEn|SYNC_CFG_SYNC_IbEn|SYNC_CFG_SYNC_IcEn|SYNC_CFG_SYNC_InEn);
#else
	FFTChnEN = SYNC_CFG_SYNC_UEn | SYNC_CFG_SYNC_I1En | SYNC_CFG_SYNC_I2En;
#endif
	SyncFFT.SyncFFT_ChannelEn = FFTChnEN;
	SyncFFT.SyncFFT_ChannelEnState = ENABLE;
	SyncFFT.SyncOut_En = ENABLE;
	HT_EMU_SyncFFT_Init(&SyncFFT);	
	/*************************
    * Config Interface Module
    ******************/
#if defined  HT762x		
    EMUIFace_InitStruct.NIS_Chn0Sel = NIS_Channel0_Sel0;    /* Set REC channel remap */
	EMUIFace_InitStruct.NIS_Chn1Sel = NIS_Channel1_Sel1;
	EMUIFace_InitStruct.NIS_Chn2Sel = NIS_Channel2_Sel2;
	EMUIFace_InitStruct.NIS_Chn3Sel = NIS_Channel3_Sel3;
	EMUIFace_InitStruct.NIS_Chn4Sel = NIS_Channel4_Sel4;
	EMUIFace_InitStruct.NIS_Chn5Sel = NIS_Channel5_Sel5;
	EMUIFace_InitStruct.NIS_Chn6Sel = NIS_Channel6_Sel6;
	
	EMUIFace_InitStruct.FFT_Chn0Sel = FFT_Channel0_Sel0;	/* Set FFT channel remap */
	EMUIFace_InitStruct.FFT_Chn1Sel = FFT_Channel1_Sel1;	
	EMUIFace_InitStruct.FFT_Chn2Sel = FFT_Channel2_Sel2;
	EMUIFace_InitStruct.FFT_Chn3Sel = FFT_Channel3_Sel3;
	EMUIFace_InitStruct.FFT_Chn4Sel = FFT_Channel4_Sel4;
	EMUIFace_InitStruct.FFT_Chn5Sel = FFT_Channel5_Sel5;
	EMUIFace_InitStruct.FFT_Chn6Sel = FFT_Channel6_Sel6;
#else
    EMUIFace_InitStruct.NIS_Chn0Sel = NIS_Channel0_Sel0;    /* Set REC channel remap */
	EMUIFace_InitStruct.NIS_Chn1Sel = NIS_Channel1_Sel3;
	EMUIFace_InitStruct.NIS_Chn2Sel = NIS_Channel2_Sel4;
	
	EMUIFace_InitStruct.FFT_Chn0Sel = FFT_Channel0_Sel0;	/* Set FFT channel remap */
	EMUIFace_InitStruct.FFT_Chn1Sel = FFT_Channel1_Sel3;	
	EMUIFace_InitStruct.FFT_Chn2Sel = FFT_Channel2_Sel4;

#endif
	EMUIFace_InitStruct.NIS_BitWide = NIS_BitWide_32bits;	
	EMUIFace_InitStruct.NIS_Align = NIS_Align_LSB;
	EMUIFace_InitStruct.FFT_Align = FFT_Align_LSB;
	EMUIFace_InitStruct.NIS_Enable = ENABLE; 
	EMUIFace_InitStruct.FFT_Enable = ENABLE; 
	HT_EMUIFACE_Init(&EMUIFace_InitStruct);

	HT_EMU_PLLEnSet(ENABLE);	/* Enable PLL module  */
	while(HT_EMU_PLLFlagStatusGet(PLL_CTRL_PLL_locked_flag) != SET);	/* Wait PLL module locked */

}
 #if defined  HT762x 
/**
*********************************************************************************************************
*                                  EMU EXAMPLES FOR HT6XXX                                       
* @brief : EMU module all voltage lost Init
* @param : None
* @retval: None
* @note  : The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
void HT_EMU_AllVoltageLost_Init_Example(void)
{
	
	HT_EMU_ULostCMPCFG_LvlSet(ULostCMPCFG_VcmpLVL_0mV942);  /* configure voltage compare level, default 0.942mv */
	
	HT_EMU_ULostCMPCFG_DutySet(0x20);                       /* pulse width, default 0x20/32768 = 1ms */
	
	HT_EMU_ULostCMPCFG_VolNumSet(0x07); 					/*compare cycle num, default  0x07+1 = 8 */
	
	HT_EMU_ULostPRDCFG_Set(ULostPRDCFG_STBTime,0x0A); 		/* comparator stand by time after enable,default 0x0a = 10ms */
	
	HT_EMU_ULostPRDCFG_Set(ULostPRDCFG_CMPRunTime,0x40); 	/* comparator run time after enable,default 0x40 , 64*3.9ms =250ms*/

	HT_EMU_ULostCMPCFG_CmpPrdEnSet(DISABLE);
	
	if(!(HT_EMUECA->ULostCMPCFG &ULostCMPCFG_CMP_PRD_EN)) 	/* only comparator runs in periodic mode*/
	{
		HT_EMU_ULostPRDCFG_Set(ULostPRDCFG_CMPPRD,0x3C); 	/* comparator run period, dedault 0x3C, real time 0x3C+1 = 61ms*/
	}
	
	HT_EMU_ULostCMPCFG_CmpEnSet(ENABLE); 					/* enable comparator*/
		
		
}
 #endif
/**
*********************************************************************************************************
*                                  EMU EXAMPLES FOR HT6XXX                                       
* @brief : EMU module low power mode Init 
* @param : None
* @retval: None
* @note  : The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
void HT_EMU_LowPower_Init_Example(void)
{
	uint32_t DigAdcChnEN = 0U,AnaAdcChnEN = 0U,CfEN = 0U;
	UConst_InitTypeDef UConstInit;
	
	HT_EMU_ANACFG1_EmuLdoEnSet(ENABLE);                 							/* Enable EMU Ldo */
	
	HT_EMU_LPModeCON_LpVrefEnSet(ENABLE); 											/* select LPVref*/
		
	HT_EMU_LPModeCON_STBTimeSet(LPModeCON_StandByTime_64); 							/* standy by time after enable LP mode*/
	
	HT_EMU_LPModeCON_LpClkSet(LPModeCON_EMUCLK_LPSel_204K8);						/*LP mode emu clock */
	
	HT_EMU_FilterCon_LpfEnSet(FilterCon_RmsLpf_En,DISABLE);   					    /* disable rms low pass filter */
	
	HT_EMU_FilterCon_LpfEnSet(FilterCon_PowerLpf_En,DISABLE);						/* disable power low pass filter */
	
	HT_EMU_ANACFG1_AdcBasiSet(ANACFG1_UADC_BIAS,ANACFG1_UADC_BIAS_4uA);             /* Analog ADCU Bais Set 4uA*/
	
	HT_EMU_ANACFG1_AdcBasiSet(ANACFG1_IADC_BIAS,ANACFG1_IADC_BIAS_4uA);             /* Analog ADCI Bais Set 4uA*/
	
	HT_EMU_AvgNumSet(ECR_AVG_RMST,0x100);                                          /* AVG NUM set one period wave*/
	
	HT_EMU_AvgNumSet(ECR_AVG_RMS,0x100);							 	           /* AVG NUM set one period wave*/


	/****channel select***/
#if defined  HT772x
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_USel,ChannelSel_USel_U);
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_I1Sel,ChannelSel_I1Sel_I1);
	HT_EMU_ChnSel_ChnSelSet(ChannelSel_I2Sel,ChannelSel_I2Sel_I2);
#endif
	
	/* Users can choose according to their own conditions */
	/* Enable ADC Channel */
#if defined  HT762x
    AnaAdcChnEN = ADCCON_ADCEn_ANA_Ua | ADCCON_ADCEn_ANA_Ub | ADCCON_ADCEn_ANA_Uc;
    AnaAdcChnEN |= (ADCCON_ADCEn_ANA_Ia|ADCCON_ADCEn_ANA_Ib|ADCCON_ADCEn_ANA_Ic|ADCCON_ADCEn_ANA_In);
	
    DigAdcChnEN = ADCCON_ADC_En_Ua|ADCCON_ADC_En_Ub|ADCCON_ADC_En_Uc;
    DigAdcChnEN |= (ADCCON_ADC_En_Ia|ADCCON_ADC_En_Ib|ADCCON_ADC_En_Ic|ADCCON_ADC_En_In);
#else
    AnaAdcChnEN = ADCCON_ADCEn_ANA_U | ADCCON_ADCEn_ANA_I1 | ADCCON_ADCEn_ANA_I2;
    DigAdcChnEN = ADCCON_ADC_En_U|ADCCON_ADC_En_I1|ADCCON_ADC_En_I2;
#endif
	HT_EMU_ADCCON_AdcChnEnSet(DigAdcChnEN, AnaAdcChnEN, ENABLE);       /* Enable Channel ADC */
	
	
	/* Users can choose according to their own conditions */
	/* Enable Energy Channel Run */
#if defined  HT762x
    CfEN = CFxRun_All_Pa_EN | CFxRun_All_Pb_EN | CFxRun_All_Pc_EN | CFxRun_All_Pt_EN;    /* enable all-wave Active energy channel */
    CfEN |= (CFxRun_All_Qa_EN | CFxRun_All_Qb_EN | CFxRun_All_Qc_EN | CFxRun_All_Qt_EN); /* enable all-wave reactive energy channel */
    CfEN |= (CFxRun_Sa_EN | CFxRun_Sb_EN | CFxRun_Sc_EN | CFxRun_St_EN);                 /* enable Apparent energy channel */
#else
    CfEN = CFxRun_All_P1_EN | CFxRun_All_P2_EN | CFxRun_All_Pt_EN;   				/* enable all-wave Active energy channel */
    CfEN |= (CFxRun_All_Q1_EN | CFxRun_All_Q2_EN | CFxRun_All_Qt_EN); 				/* enable all-wave reactive energy channel */
    CfEN |= (CFxRun_S1_EN | CFxRun_S2_EN | CFxRun_St_EN);                			/* enable Apparent energy channel */
#endif
	HT_EMU_CFxRun_ChnEnSet(CfEN, ENABLE);   /* enable energy channel */
	
	/* Users can choose according to their own conditions */
	/* voltage can select voltage Const*/
#if defined  HT762x
	UConstInit.UaConstEn = DISABLE;
	UConstInit.UbConstEn = DISABLE;
	UConstInit.UcConstEn = DISABLE;
	UConstInit.UaConst = 0x00;
	UConstInit.UbConst = 0x00;
	UConstInit.UcConst = 0x00;
#else
	UConstInit.UConstEn = DISABLE;
	UConstInit.UConst = 0x00;
#endif
	HT_EMU_UConst_Init(&UConstInit);
	
	HT_EMU_LPModeCON_LpModeEnSet(ENABLE); 															/* enable lower power mode*/

		
}
#endif

