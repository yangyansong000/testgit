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
* File         : ht6xxx_pmu.c
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_PMU_C

#include <stdio.h>
#include "ht6xxx_lib.h"

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
static const uint32_t RegisterWriteProtect[]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};





/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
static void PMU_InitCallbacksToDefault(PMU_InitTypeDef *PMU_InitStruct);
static void PMU_VCCDET_IT(PMU_InitTypeDef *PMU_InitStruct);
static void PMU_BORDET_IT(PMU_InitTypeDef *PMU_InitStruct);
static void PMU_LVDIN0_IT(PMU_InitTypeDef *PMU_InitStruct);

#ifdef USE_LVDIN1
static void PMU_LVDIN1_IT(PMU_InitTypeDef *PMU_InitStruct);
#endif

#ifdef USE_LVDIN2
static void PMU_LVDIN2_IT(PMU_InitTypeDef *PMU_InitStruct);
#endif

#ifdef USE_POWDET
static void PMU_POWDET_IT(PMU_InitTypeDef *PMU_InitStruct);
#endif

#endif

/**
*********************************************************************************************************
*                                         INITIAL PMU MODULE
* @brief:   Pmu initial
*
* @param:   PMU_InitStruct    pointer to the Initial structure 
*                             1) Lvdin0State      : Lvdin0 state 
*                             2) Lvdin1State      : Lvdin1 state (If support)
*                             3) Lvdin2State      : Lvdin2 state (If support)
*                             4) POWState         : Pow state    (If support)
*                             5) POWFilter        : Pow filter   (If support)
*                             6) BorState         : Bor state
*                             7) VccLvlSet        : Vcc Detection threshold
*                             8) BorLvlSet        : Bor Detection threshold
*                             9) VccBorDetTime    : Vcc and Bor detection time
*                             10) VccBorDetPeriod : Vcc and Bor detection cycle 
*
* @retval:  None
*
* @Note:    Ensure that the write protection unchanged during execution
*********************************************************************************************************
*/
void HT_PMU_Init(PMU_InitTypeDef *PMU_InitStruct)
{
    uint32_t tempreg = 0x0000U;
    uint32_t writeProtect = RegisterWriteProtect[(HT_CMU->WPREG) & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */

    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                    	/*!< Disable write protection         */

    tempreg = (HT_PMU->PMUCON);
    HT_LVDIN_CONFIG(tempreg,PMU_InitStruct);                            		/*!< config LVDIN          */
#if defined USE_POWDET 
    HT_POWDET_SET(tempreg,PMU_InitStruct);                             			/*!< config POWDET         */
    HT_PDTFLT_SET(PMU_InitStruct);    											/*!< POWDET digital filter      */
#endif    
    HT_BOR_CONFIG(tempreg,PMU_InitStruct);                                      /*!< config BOR            */
    HT_PMU->PMUCON = tempreg;
#if  defined USE_LVDIN_QR 
    HT_LVDINQR_SET(PMU_InitStruct);                                              	/*!< config LVDIN_QR       */
#endif
#if defined USE_LVDIN_SEL
    HT_LVDINSEL_SET(PMU_InitStruct);
#endif
    HT_CMU->WPREG = writeProtect;                                                 /*!< Restore previous write protection settings     */

    HT_PMU->VDETCFG &= ~(PMU_VDETCFG_VCCLVL | PMU_VDETCFG_BORLVL);
    HT_PMU->VDETCFG |= ((uint32_t)PMU_InitStruct->VccLvlSet | (uint32_t)PMU_InitStruct->BorLvlSet);   /*!< VccBor Detection threshold     */
    HT_PMU->VDETPCFG &= ~(PMU_VDETPCFG_VDETPRD | PMU_VDETPCFG_VDETTIME);
    HT_PMU->VDETPCFG |= ((uint32_t)PMU_InitStruct->VccBorDetTime | (uint32_t)PMU_InitStruct->VccBorDetPeriod);

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
	PMU_InitCallbacksToDefault(PMU_InitStruct);
	PMU_InitStruct->Instance = HT_PMU;
#endif
}

/**
*********************************************************************************************************
*                            Enable/Disable THE BIG POWER LDO ON HOLD MODE
* @brief:   config normal LDO in Hold mode
*
* @param:   NewState    = ENABLE： enable normal LDO in Hold mode
*                       = DISABLE：disable normal LDO in Hold mode
*
* @retval:  None
*
* @Note:    Ensure that the write protection unchanged during execution
*********************************************************************************************************
*/
void HT_PMU_HoldLDOConfig(FunctionalState NewState)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */

  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */

  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_HoldLDO;                              /*!< enable normal LDO in Hold mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_HoldLDO;                             /*!< disable normal LDO in Hold mode */
  }

  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */
}


#if defined USE_LDOVREF || defined USE_LPCFG
/**
*********************************************************************************************************
*                            CONFIG THE LOWPOWER LDO VOLT 
* @brief:   config lowpower LDO volt
*
* @param:   VoltLvl     = 0~3;
*
* @retval:  None
*
* @Note:    Ensure that the write protection unchanged during execution
*			for HT633x,make sure chip is under sleep/hold/hold_lp/lp_run mode and PREFETCH.flash_lp_fetch=1
*********************************************************************************************************
*/
void HT_LDO_LP_VoltConfig(uint32_t VoltLvl)
{
	uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */

  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */
	
	assert_param(IS_HT_C_LDO_LP(VoltLvl));
	HT_LDO_LP_SET(VoltLvl);
  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */
}
#endif


#if defined USE_LPCFG
/**
*********************************************************************************************************
*                      Enable/Disable THE NORMAL VREF ON HOLD/HOLD_LP MODE
* @brief:   config normal vref in Hold/Hold_lp mode
*
* @param:   NewState    = ENABLE： enable normal VREF in Hold/Hold_lp mode
*                       = DISABLE：disable normal VREF in Hold/Hold_lp mode
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_HoldVrefConfig(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_HoldVREF;      /*!< enable normal VREF in Hold/Hold_lp mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_HoldVREF;     /*!< disable normal VREF in Hold/Hold_lp mode */
  }
}

/**
*********************************************************************************************************
*                      Enable/Disable FLASH DPD IN HOLD/HOLD_LP MODE
* @brief:   config FLASH enter DPD in Hold/Hold_lp mode
*
* @param:   NewState    = ENABLE： FLASH enter DPD in Hold/Hold_lp mode
*                       = DISABLE：FLASH normal run in Hold/Hold_lp mode
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_FlashDPDConfig(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_FLASHDPD;     /*!< FLASH enter DPD in Hold/Hold_lp mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_FLASHDPD;    /*!< FLASH normal run in Hold/Hold_lp mode */
  }
}

/**
*********************************************************************************************************
*                      Enable/Disable SRAM0 RETENTION IN SLEEP/HOLD/HOLD_LP MODE
* @brief:   config SRAM0 retention in Sleep/Hold/Hold_lp mode
*
* @param:   NewState    = ENABLE： SRAM0 retention in Sleep/Hold/Hold_lp mode
*                       = DISABLE：SRAM0 powerdown in Sleep/Hold/Hold_lp mode
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_HoldSram0Config(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_HoldSRAM0;     /*!< SRAM0 retention in Sleep/Hold/Hold_lp mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_HoldSRAM0;    /*!< SRAM0 powerdown in Sleep/Hold/Hold_lp mode */
  }
}

/**
*********************************************************************************************************
*                      Enable/Disable SRAM1 RETENTION IN HOLD/HOLD_LP MODE
* @brief:   config SRAM1 retention in Hold/Hold_lp mode
*
* @param:   NewState    = ENABLE： SRAM1 retention in Hold/Hold_lp mode
*                       = DISABLE：SRAM1 powerdown in Hold/Hold_lp mode
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_HoldSram1Config(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_HoldSRAM1;     /*!< SRAM1 retention in Hold/Hold_lp mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_HoldSRAM1;    /*!< SRAM1 powerdown in Hold/Hold_lp mode */
  }
}

/**
*********************************************************************************************************
*                      Enable/Disable SRAM2 RETENTION IN HOLD/HOLD_LP MODE
* @brief:   config SRAM2 retention in Hold/Hold_lp mode
*
* @param:   NewState    = ENABLE： SRAM2 retention in Hold/Hold_lp mode
*                       = DISABLE：SRAM2 powerdown in Hold/Hold_lp mode
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_HoldSram2Config(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    HT_PMU->PMUCON |= PMU_PMUCON_HoldSRAM2;     /*!< SRAM2 retention in Hold/Hold_lp mode  */
  }
  else
  {
    HT_PMU->PMUCON &= ~PMU_PMUCON_HoldSRAM2;    /*!< SRAM2 powerdown in Hold/Hold_lp mode */
  }
}

/**
*********************************************************************************************************
*                            Enable/Disable LP RUN MODE
* @brief:   Enable/Disable LP RUN MODE
*
* @param:   NewState    = ENABLE： Enable LP RUN MODE
*                       = DISABLE：Disable LP RUN MODE
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_LPRunConfig(FunctionalState NewState)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */

  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */

  if (NewState != DISABLE)
  {
    HT_PMU->LPMCFG |= PMU_LPMCFG_LPRUNEN;     /*!< low power run enable  */
  }
  else
  {
    HT_PMU->LPMCFG &= ~PMU_LPMCFG_LPRUNEN;    /*!< low power run disable */
  }
  
  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */  
}


/**
*********************************************************************************************************
*                                   CONFIG NORMAL VREF TEMPERATURE COEFFICIENT
* @brief:   Config normal VREF temperature coefficient code
*
* @param:   VrefValue   (0x0~0x7)
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_NormalVref_TrimConfig(uint32_t VrefValue)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */
  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */
  assert_param(IS_HT_PMU_NORVREF_TRIM(VrefValue));
  HT_NORMAL_VREF_TC_SET(VrefValue); 
  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */  
}

/**
*********************************************************************************************************
*                                 CONFIG LOWPOWER VREF TEMPERATURE COEFFICIENT
* @brief:   Config lowpower VREF temperature coefficient code
*
* @param:   VrefValue   (0x0~0xF)
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_LowpowerVref_TcConfig(uint32_t VrefValue)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */
  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */
  assert_param(IS_HT_PMU_LPVREF_TC(VrefValue));
  HT_LP_VREF_TC_SET(VrefValue); 
  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */  
}

/**
*********************************************************************************************************
*                                 CONFIG LOWPOWER VREF VOLTAGE
* @brief:   Config lowpower VREF voltage code
*
* @param:   VrefValue   (0x0~0x1F)
*
* @retval:  None
*
*********************************************************************************************************
*/
void HT_PMU_LowpowerVref_TvConfig(uint32_t VrefValue)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */
  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection         */
  assert_param(IS_HT_PMU_LPVREF_TV(VrefValue));
  HT_LP_VREF_TV_SET(VrefValue); 
  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */  
}

/**
*********************************************************************************************************
*                                   GET LP_RUN STATUS 
* @brief:   Get LP_RUN status
*
* @param:   None
*
* @retval:  LPRUN_STA : = SET：  In Lp_run work mode
*                       = RESET：Not in Lp_run work mode
*
*********************************************************************************************************
*/
FlagStatus HT_LPRUN_StatusGet(void)
{
  FlagStatus status = RESET;
  if (HT_PMU->LPMCFG & PMU_LPMCFG_LPRUNSTA)
  {
    status = SET;                                          
  }
  else
  {
    status = RESET;                  
  }
  return status;    
}
#endif


/**
*********************************************************************************************************
*                                    DISCHARGE  CONFIGURE
* @brief:   config Battery protection against passivation
*
* @param:   ChargeMode    = DisCharge0mA
*                         = DisCharge1mA
*                         = DisCharge2mA
*                         = DisCharge50uA  (If support)
*                         = DisCharge100uA (If support)
*
* @retval:  None
*
* @Note:    Ensure that the write protection unchanged during execution
*********************************************************************************************************
*/
#if  defined USE_DISCHARGE 
void HT_PMU_DisChargeConfig(DISCharge_TypeDef ChargeMode)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status     */

  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                  /*!< Disable write protection         */
                                        
  HT_DISCHARGE_ENABLE((uint32_t)ChargeMode);                                           /*!< enable DisCharge      */

  HT_CMU->WPREG = writeProtect;                                           /*!< Restore previous write protection settings     */

  HT_DISCHARGE_CFG((uint32_t)ChargeMode);                                                /*!< set DisCharge current      */
}
#endif

/**
*********************************************************************************************************
*                               GET SPECIFIED PMU STATE FLAG STATUS
*
* @brief:   get PMU detection state flag status
*
* @param:   STAFlag    check PMU status，it can be the following parameters:
*                        @arg PMU_PMUSTA_VCCFLG
*                        @arg PMU_PMUSTA_BORFLG
*                        @arg PMU_PMUSTA_LVD0FLG
*                        @arg PMU_PMUSTA_LVD1FLG (If support)
*                        @arg PMU_PMUSTA_POWFLG  (If support)
*                        @arg PMU_PMUSTA_LVD2FLG (If support)
*
* @retval:  ITStatus    = SET：  The value detected is greater than the threshold
*                       = RESET：The detected value is less than the threshold
*
*********************************************************************************************************
*/
FlagStatus HT_PMUState_FlagStatusGet(uint32_t STAFlag)
{
  FlagStatus status = RESET;
  /*  assert_param  */
  assert_param(IS_HT_PMUSTA(STAFlag));
  if (HT_PMU->PMUSTA & STAFlag)
  {
    status = SET;                       /*!< The value detected is greater than the threshold      */                      
  }
  else
  {
    status = RESET;                     /*!< The detected value is less than the threshold         */
  }
  return status;
}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE PMU INTERRUPT
*
* @brief:   enable or disable PMU interrupt
*
* @param:   ITEn       PMU interrupt set, it can be one or a combination of the following parameters:
*                        @arg PMU_PMUIE_VCCIE
*                        @arg PMU_PMUIE_BORIE
*                        @arg PMU_PMUIE_LVD0IE
*                        @arg PMU_PMUIE_LVD1IE (If support)
*                        @arg PMU_PMUIE_POWIE  (If support)
*                        @arg PMU_PMUIE_LVD2IE (If support)
*
*           NewState   = ENABLE： enable interrupt
*                      = DISABLE：disable interrupt
* @retval:  none
*
*********************************************************************************************************
*/
void HT_PMU_ITConfig(uint32_t ITEn, FunctionalState NewState)
{
  /*  assert_param  */
  assert_param(IS_HT_PMUIE(ITEn));
  if (NewState != DISABLE)
  {
    HT_PMU->PMUIE |= (ITEn & PMU_PMUIE);            /*!< enable PMU interrupt           */
  }
  else
  {
    HT_PMU->PMUIE &= ~ITEn;                         /*!< disable PMU interrupt           */
  }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED PMU INTERRUPT FLAG STATUS
*
* @brief:   get PMU interrupt flag status
*
* @param:   ITFlag     PMU interrupt flag check, it can be one or a combination of the following parameters:
*                        @arg PMU_PMUIF_VCCIF
*                        @arg PMU_PMUIF_BORIF
*                        @arg PMU_PMUIF_LVD0IF
*                        @arg PMU_PMUIF_LVD1IF (If support)
*                        @arg PMU_PMUIF_POWIF  (If support)
*                        @arg PMU_PMUIF_LVD2IF (If support)
*
* @retval:  ITStatus    = SET：  the interrupt flag produced
*                       = RESET：the interrupt flag not produced
*
*********************************************************************************************************
*/
ITStatus HT_PMU_ITFlagStatusGet(uint32_t ITFlag)
{
  FlagStatus status = RESET;
  /*  assert_param  */
  assert_param(IS_HT_PMUIF(ITFlag));
  if (HT_PMU->PMUIF & ITFlag)
  {
    status = SET;                        /*!< PMU Interrupt Flag is set   */
  }
  else
  {
    status = RESET;                      /*!< PMU Interrupt Flag is reset */
  }
  return status;
}

/**
*********************************************************************************************************
*                                CLEAR PMU INTERRUPT FLAG
*
* @brief:   clear PMU interrupt flag
*
* @param:   ITFlag     PMU interrupt flag clear，It can be one or a combination of the following parameters
*                        @arg PMU_PMUIF_VCCIF
*                        @arg PMU_PMUIF_BORIF
*                        @arg PMU_PMUIF_LVD0IF
*                        @arg PMU_PMUIF_LVD1IF (If support)
*                        @arg PMU_PMUIF_POWIF  (If support)
*                        @arg PMU_PMUIF_LVD2IF (If support)
*
* @retval:  none
*
*********************************************************************************************************
*/
void HT_PMU_ClearITPendingBit(uint32_t ITFlag)
{
  /*  assert_param  */
  assert_param(IS_HT_PMUIF(ITFlag));
  HT_PMU->PMUIF  = ~ITFlag;                  /*!< Clear PMU Interrupt Flag    */
}



#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)

/**
* @brief  Register a User PMU Callback
*         To be used instead of the weak predefined callback
* @param  PMU_InitStruct PMU handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*         @arg @ref PMU_VCC_COMPLETE_CB_ID PMU VCC Complete Callback ID
*         @arg @ref PMU_BOR_COMPLETE_CB_ID PMU BOR Complete Callback ID
*         @arg @ref PMU_LVD0_COMPLETE_CB_ID PMU LVD0 Complete Callback ID
*         @arg @ref PMU_LVD1_COMPLETE_CB_ID PMU LVD1 Complete Callback ID
*         @arg @ref PMU_LVD2_COMPLETE_CB_ID PMU LVD2 Complete Callback ID
*         @arg @ref PMU_POW_COMPLETE_CB_ID PMU POW Complete Callback ID
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_PMU_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
*/
StatusTypeDef HT_PMU_RegisterCallback(PMU_InitTypeDef *PMU_InitStruct, PMU_CallbackIDTypeDef CallbackID, pPMU_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        PMU_InitStruct->ErrorCode |= PMU_ERROR_INVALID_CALLBACK;
        status = ERROR;
    }
    else
    {
        switch (CallbackID)
        {
            case PMU_VCC_COMPLETE_CB_ID :
                PMU_InitStruct->PmuVccCpltCallback = pCallback;
            break;
            case PMU_BOR_COMPLETE_CB_ID :
                PMU_InitStruct->PmuBorCpltCallback = pCallback;
            break;
            case PMU_LVD0_COMPLETE_CB_ID :
                PMU_InitStruct->PmuLvd0CpltCallback = pCallback;
            break;
        #ifdef USE_LVDIN1
            case PMU_LVD1_COMPLETE_CB_ID :
                PMU_InitStruct->PmuLvd1CpltCallback = pCallback;
            break;
        #endif
        #ifdef USE_LVDIN2
            case PMU_LVD2_COMPLETE_CB_ID :
                PMU_InitStruct->PmuLvd2CpltCallback = pCallback;
            break;
        #endif
        #ifdef USE_POWDET
            case PMU_POW_COMPLETE_CB_ID :
                PMU_InitStruct->PmuPowCpltCallback = pCallback;
            break;
        #endif
            default :
                /* Update the error code */
                PMU_InitStruct->ErrorCode |= PMU_ERROR_INVALID_CALLBACK;
                /* Return error status */
                status =  ERROR;
            break;
        }
    }
    return status;
}

/**
*********************************************************************************************************
*                                         INITIAL PMU CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_InitCallbacksToDefault(PMU_InitTypeDef* PMU_InitStruct)
{
	PMU_InitStruct->PmuVccCpltCallback  = HT_PMU_VccCpltCallback;
	PMU_InitStruct->PmuBorCpltCallback  = HT_PMU_BorCpltCallback;
	PMU_InitStruct->PmuLvd0CpltCallback = HT_PMU_Lvd0CpltCallback;
#ifdef USE_LVDIN1	
	PMU_InitStruct->PmuLvd1CpltCallback = HT_PMU_Lvd1CpltCallback;
#endif
#ifdef USE_LVDIN2
	PMU_InitStruct->PmuLvd2CpltCallback = HT_PMU_Lvd2CpltCallback;
#endif
#ifdef USE_POWDET	
	PMU_InitStruct->PmuPowCpltCallback  = HT_PMU_PowCpltCallback;
#endif
}

/**
*********************************************************************************************************
*                                  VCCDET IT HANDLER
*
* @brief: This function handles VCCDET interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_VCCDET_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuVccCpltCallback != NULL)
	{
		PMU_InitStruct->PmuVccCpltCallback(PMU_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                  BORDET IT HANDLER
*
* @brief: This function handles BORDET interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_BORDET_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuBorCpltCallback != NULL)
	{
		PMU_InitStruct->PmuBorCpltCallback(PMU_InitStruct);
	}
}

/**
*********************************************************************************************************
*                                  LVDIN0 IT HANDLER
*
* @brief: This function handles LVDIN0 interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_LVDIN0_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuLvd0CpltCallback != NULL)
	{
		PMU_InitStruct->PmuLvd0CpltCallback(PMU_InitStruct);
	}
}

#ifdef USE_LVDIN1
/**
*********************************************************************************************************
*                                  LVDIN1 IT HANDLER
*
* @brief: This function handles LVDIN1 interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_LVDIN1_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuLvd1CpltCallback != NULL)
	{
		PMU_InitStruct->PmuLvd1CpltCallback(PMU_InitStruct);
	}
}
#endif

#ifdef USE_LVDIN2
/**
*********************************************************************************************************
*                                  LVDIN2 IT HANDLER
*
* @brief: This function handles LVDIN2 interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_LVDIN2_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuLvd2CpltCallback != NULL)
	{
		PMU_InitStruct->PmuLvd2CpltCallback(PMU_InitStruct);
	}
}
#endif

#ifdef USE_POWDET
/**
*********************************************************************************************************
*                                  POWDET IT HANDLER
*
* @brief: This function handles POWDET interrupt request
*
* @param: PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*               the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void PMU_POWDET_IT(PMU_InitTypeDef* PMU_InitStruct)
{
	if(PMU_InitStruct->PmuPowCpltCallback != NULL)
	{
		PMU_InitStruct->PmuPowCpltCallback(PMU_InitStruct);
	}
}
#endif

/**
*********************************************************************************************************
*                               PMU IRQ HANDLER
*
* @brief:   This function handles PMU interrupt request
*
* @param:   PMU_InitStruct Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.          
*
* @retval:  None
*
* @Note: None
*********************************************************************************************************
*/
void HT_PMU_IRQHandler(PMU_InitTypeDef *PMU_InitStruct)
{
	uint32_t isrflags   = READ_REG(PMU_InitStruct->Instance->PMUIF);
    uint32_t cr1its     = READ_REG(PMU_InitStruct->Instance->PMUIE);
	
	/*	VCCDET	*/
	if (((isrflags & PMU_PMUIF_VCCIF) != RESET) && ((cr1its & PMU_PMUIE_VCCIE) != RESET))
	{
		PMU_VCCDET_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_VCCIF);              /*!< clear interrupt flag          */
	}
	/*	BORDET	*/
	if (((isrflags & PMU_PMUIF_BORIF) != RESET) && ((cr1its & PMU_PMUIE_BORIE) != RESET))
	{
		PMU_BORDET_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_BORIF);              /*!< clear interrupt flag          */
	}
	/*	LVDIN0	*/
	if (((isrflags & PMU_PMUIF_LVD0IF) != RESET) && ((cr1its & PMU_PMUIE_LVD0IE) != RESET))
	{
		PMU_LVDIN0_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD0IF);              /*!< clear interrupt flag          */
	}
 
#if  defined  USE_LVDIN1  
	/*	LVDIN1	*/
	if (((isrflags & PMU_PMUIF_LVD1IF) != RESET) && ((cr1its & PMU_PMUIE_LVD1IE) != RESET))
	{
		PMU_LVDIN1_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD1IF);              /*!< clear interrupt flag          */
	}
#endif
    
#if  defined  USE_LVDIN2
	/*	LVDIN2	*/
	if (((isrflags & PMU_PMUIF_LVD2IF) != RESET) && ((cr1its & PMU_PMUIE_LVD2IE) != RESET))
	{
		PMU_LVDIN2_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_LVD2IF);              /*!< clear interrupt flag          */
	}
#endif
	
#if defined	USE_POWDET
	/*	POWDET	*/
	if (((isrflags & PMU_PMUIF_POWIF) != RESET) && ((cr1its & PMU_PMUIE_POWIE) != RESET))
	{
		PMU_POWDET_IT(PMU_InitStruct);
		HT_PMU_ClearITPendingBit(PMU_PMUIF_POWIF);              /*!< clear interrupt flag          */
	}
#endif
}



/**
*********************************************************************************************************
*                                   VCCDET COMPLETE CALLBACK
*
* @brief: VCCDET completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_VccCpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_VccCpltCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                   BORDET COMPLETE CALLBACK
*
* @brief: BORDET completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_BorCpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_BorCpltCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                   LVDIN0 COMPLETE CALLBACK
*
* @brief: LVDIN0 completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_Lvd0CpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_Lsvd0CpltCallback could be implemented in the user file
    */
}

#ifdef USE_LVDIN1
/**
*********************************************************************************************************
*                                   LVDIN1 COMPLETE CALLBACK
*
* @brief: LVDIN1 completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_Lvd1CpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_Lvd1CpltCallback could be implemented in the user file
    */
}
#endif

#ifdef USE_LVDIN2
/**
*********************************************************************************************************
*                                   LVDIN2 COMPLETE CALLBACK
*
* @brief: LVDIN2 completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_Lvd2CpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_Lvd2CpltCallback could be implemented in the user file
    */
}
#endif

#ifdef USE_POWDET
/**
*********************************************************************************************************
*                                   POWDET COMPLETE CALLBACK
*
* @brief: POWDET completed callbacks.
*
* @param: PMU_InitStruct  Pointer to a PMU_InitTypeDef structure that contains
*                the configuration information for the specified PMU module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_PMU_PowCpltCallback(PMU_InitTypeDef *PMU_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(PMU_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_PMU_PowCpltCallback could be implemented in the user file
    */
}
#endif

#endif	/* USE_HT_PMU_REGISTER_CALLBACKS */
