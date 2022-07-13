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
* File         : ht6xxx_timer.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_TIMER_C

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
										Local Macro/Structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
											Local Variables
*********************************************************************************************************
*/



/*
*********************************************************************************************************
										Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_TMR_REGISTER_CALLBACKS ==1U)
static void TMR_InitCallbacksToDefault(TMR_InitTypeDef *TMR_InitStruct);
static void TMR_PRD_IT(TMR_InitTypeDef *TMR_InitStruct);
static void TMR_CAP_IT(TMR_InitTypeDef *TMR_InitStruct);
static void TMR_CMP_IT(TMR_InitTypeDef *TMR_InitStruct);

    #if defined USE_TMR_ACIF
    static void TMR_AC_IT(TMR_InitTypeDef *TMR_InitStruct);
    #endif

    #if defined USE_TMR_EXT
        static void TMRExt_InitCallbacksToDefault(TMRExt_InitTypeDef *TMRExt_InitStruct);
        static void TMRExt_PRD_IT(TMRExt_InitTypeDef *TMRExt_InitStruct);
        static void TMRExt_CAP_IT(TMRExt_InitTypeDef *TMRExt_InitStruct);
        static void TMRExt_CMP_IT(TMRExt_InitTypeDef *TMRExt_InitStruct);
        #if defined USE_TMR_ACIF
        static void TMRExt_AC_IT(TMRExt_InitTypeDef *TMRExt_InitStruct);
        #endif
        #if defined USE_TMREXT_TRIG
        static void TMRExt_TRIG_IT(TMRExt_InitTypeDef *TMRExt_InitStruct);
        #endif
    #endif
#endif


/**
*********************************************************************************************************
*                                         INITIAL TIMER MODULE
*
* @brief: Initializes the TMRx peripheral according to the specified
*         parameters in the TMR_InitStruct.

* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 @arg HT_TMR0
*                                 @arg HT_TMR1
*                                 @arg HT_TMR2
*                                 @arg HT_TMR3
*                                 @arg HT_TMR4 (If support)
* @param: TMR_InitStruct: pointer to a TMR_InitTypeDef structure
*   that contains the configuration information for the specified TMR peripheral.
*   which consists of some parameters:
*            1) TimerMode    : Set Timer working mode.This parameter can be one of the following values:
*                                 @arg TIMCycleTiming
*                                 @arg TIMPWMCountUpLevelHigh
*                                 @arg TIMPWMCountDownLevelHigh
*                                 @arg TIMPWMCenterAlignedLevelHigh
*                                 @arg TIMPWMCountUpLevelLow
*                                 @arg TIMPWMCountDownLevelLow
*                                 @arg TIMPWMCenterAlignedLevelLow
*                                 @arg TIMCaptureRiseEdge         (for HT6x1x,pin---AF2)
*                                 @arg TIMCaptureFallEdge         (for HT6x1x,pin---AF2)
*                                 @arg TIMEventRecordRiseEdge  (If support)
*                                 @arg TIMEventRecordFallEdge  (If support)

*                                 @arg TIMCapDual_RiseStart_NotCLR     (If support)
*                                 @arg TIMCapDual_RiseStart_CLR        (If support)
*                                 @arg TIMCapDual_FallStart_NotCLR     (If support)
*                                 @arg TIMCapDual_FallStart_CLR        (If support)

*            2) TimerPeriod  : Set timing period
*            3) TimerCompare : Set compare register
*            4) TimerPreDiv  : Set the prescaler of the timer
*            5) TimerOPMode  : Set the one pulse mode  (If support)

*            6) TimerExTrigMode : Set the Polarity of External Trigger  (If support)
*                            @arg TimExTrigMode_Rise
*                            @arg TimExTrigMode_Fall
*                            @arg TimExTrigMode_Dual
*
*            7) TimerEXTRIGSource  : Set the Source of External Trigger   (If support)
*                             @arg TimerExTrigSrc_INT0
*                             @arg TimerExTrigSrc_INT3
*                             @arg TimerExTrigSrc_RX0
*                             @arg TimerExTrigSrc_RX3
*                             @arg TimerExTrigSrc_RTCTMR2_PRD
*                             @arg TimerExTrigSrc_TMR5_CMP
*                             @arg TimerExTrigSrc_TOUT
*                             @arg TimerExTrigSrc_LPRX0         (If support)
*                             @arg TimerExTrigSrc_TMR0_PRD      (If support)

*             8) TimExTrigEnable : Enable or disable the  External Trigger start-up timer function   (If support)
*
@retval None
*
* @note: Special note: The user should enable the TIMER module before configuring the TIMER register.
*    For details, refer to the HT_CMU_ClkCtrl1Config() function


* @note:  For the HT6x1x chip,if the capture function is used,the pin must be configured as the AF2 function.
*********************************************************************************************************
*/
void HT_TMR_Init(HT_TMR_TypeDef *TMRx, TMR_InitTypeDef *TMR_InitStruct)
{
    uint32_t tempreg;
    /*  assert_param */
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));

#if defined USE_TMR_DOUBLECAP
     assert_param(IS_TMR_EventRecord_FuncMode(TMR_InitStruct->TimerMode)||IS_TMR_BASE_FuncMode1(TMR_InitStruct->TimerMode)||IS_TMR_BASE_FuncMode2(TMR_InitStruct->TimerMode));
#elif defined USE_TMR_RECORD
    assert_param(IS_TMR_EventRecord_FuncMode(TMR_InitStruct->TimerMode)||IS_TMR_BASE_FuncMode1(TMR_InitStruct->TimerMode));
#else
    assert_param(IS_TMR_BASE_FuncMode1(TMR_InitStruct->TimerMode));
#endif
    
#if  defined  USE_TMR_PWMMODE
    assert_param(IS_TMR_PWMMode(TMR_InitStruct->PwmMode));
#endif

#if defined USE_TMR_OPMODE
    assert_param(IS_FUNCTIONAL_STATE(TMR_InitStruct->TimerOPModeEnable));
#endif

#if defined USE_TMR_EXTRIGCFG

    assert_param(IS_TMRExt_ExTrigSource1(TMR_InitStruct->TimerExTrigSource) || IS_TMRExt_ExTrigSource2(TMR_InitStruct->TimerExTrigSource));
    assert_param(IS_TMRExt_ExTrigMode(TMR_InitStruct->TimerExTrigMode));
    assert_param(IS_FUNCTIONAL_STATE(TMR_InitStruct->TimExTrigEnable));
#endif

    if ((TMRx == HT_TMR0) || (TMRx == HT_TMR1) || (TMRx == HT_TMR2) || (TMRx == HT_TMR3))
    {
        TMRx->TMRCON &= (~TMR_TMRCON_CNTEN);                    /*!< disable CNTEN             */
        TMRx->TMRDIV = TMR_InitStruct->TimerPreDiv;             /*!< Configure timer prescaler          */
        TMRx->TMRPRD = TMR_InitStruct->TimerPeriod;             /*!< Configure the timer period        */
        TMRx->TMRCMP = TMR_InitStruct->TimerCompare;            /*!< Configure compare register        */
        TMRx->TMRCNT = 0U;                                       /*!< Clear the timer count register        */
        TMRx->TMRCAP = 0U;                                       /*!< Clear the timer capture register        */
        TMRx->TMRIF = 0U;                                        /*!< Clear the timer Interrupt Flag register        */

#if  defined  USE_TMR_PWMMODE
        if((TMR_InitStruct->TimerMode & TMR_TMRCON_MODE) == TMR_TMRCON_MODE_PWM)
        {
            TMRx->TMRCODT = (TMR_InitStruct->PwmMode & TMR_TMRCODT);  /*!< pwm output mode                */
            TMRx->TMRRDT = TMR_InitStruct->PwmDeadTime;             /*!< pwm dead time register          */
        }
#endif

#if defined USE_TMR_OPMODE

        if(TMR_InitStruct-> TimerOPModeEnable!= DISABLE)
        {

            TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
            TMRx->TMRCFG |= TMR_TMRCFG_ONCE_ENABLE;                 /*!< Enable One pulse mode */
            if((TMR_InitStruct->TimerMode == TIMPWMCenterAlignedLevelHigh) || (TMR_InitStruct->TimerMode == TIMPWMCenterAlignedLevelLow))
            {
                TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
            }    /*!< One pulse mode is not suitable for pwm center counting mode*/
        } 
        else
        {
            TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
        }

#endif

#if defined USE_TMR_EXTRIGCFG

        if(TMR_InitStruct->TimExTrigEnable !=DISABLE)
        {
            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TRIGERSEL;
            TMRx->TMREXTRIGCFG |= TMR_InitStruct->TimerExTrigSource;     /*!< Configure the External Trigger signal source */


            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TRIGMODE;
            uint16_t tmp_EXTrigSel = (TMRx->TMREXTRIGCFG & TMR_TMREXTRIGCFG_TRIGERSEL);

            if((tmp_EXTrigSel == TimerExTrigSrc_RTCTMR2_PRD) || (tmp_EXTrigSel == TimerExTrigSrc_TMR5_CMP) || (tmp_EXTrigSel == TimerExTrigSrc_TMR0_PRD) ||(tmp_EXTrigSel == TimerExTrigSrc_TOUT))
            {
                TMRx->TMREXTRIGCFG |= TMR_TMREXTRIGCFG_TRIGMODE_RISE;     /*!< It must configure the Polarity to rise    */
            }
            else
            {
                TMRx->TMREXTRIGCFG |=TMR_InitStruct->TimerExTrigMode;    /*!< Configure the Polarity of Trigger  */
            }
            TMRx->TMREXTRIGCFG |= TMR_TMREXTRIGCFG_TMRTRIG_EN;              /*!<  Enable the  External Trigger start-up timer function*/
        }
        else
        {
            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TMRTRIG_EN;
        }

#endif

        tempreg = TMR_TMRCON_CNTEN;                             /*!< Set enable                 */
        tempreg |= (uint32_t)TMR_InitStruct->TimerMode;
        TMRx->TMRCON = tempreg;                                 /*!< Set Timer working mode          */
    }

#if (USE_HT_TMR_REGISTER_CALLBACKS ==1U)

    TMR_InitCallbacksToDefault(TMR_InitStruct);
    TMR_InitStruct->Instance = TMRx;

#endif
}


/**
*********************************************************************************************************
*                                         INITIAL TIMEREXT MODULE
*
* @brief: Initializes the TMRx peripheral according to the specified
*         parameters in the TMR_InitStruct.

* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 		@arg HT_TMR4  (If support)
										@arg HT_TMR5

@param: TMR_InitStruct: pointer to a TMR_InitTypeDef structure
*   that contains the configuration information for the specified TMR peripheral.
*   which consists of some parameters:
*                              1) TimerSource  : Select timer clock source
*                                       @arg TIMExtClk_LRC: clock source is LRC
*                                       @arg TIMExtClk_LF:  clock source is LF(OSC)
*                                       @arg TIMExtClk_HRC: clock source is HRC
*                                       @arg TIMExtClk_PLL: clock source is PLL
*                                       @arg TIMExtClk_Exclk: clock source is exclk (If support)
*
*                              2) TimerMode    : Set Timer working mode
*                                       @arg TIMExtPWMCountUpLevelHigh
*                                       @arg TIMExtPWMCountDownLevelHigh
*                                       @arg TIMExtPWMCenterAlignedLevelHigh
*                                       @arg TIMExtPWMCountUpLevelLow
*                                       @arg TIMExtPWMCountDownLevelLow
*                                       @arg TIMExtPWMCenterAlignedLevelLow
*                                       @arg TIMExtCycleTiming
*
*                                       @arg TIMExtCaptureRiseEdge     (If support)
*                                       @arg TIMExtCaptureFallEdge     (If support)
*                                       @arg TIMExtCapDual_RiseStart_NotCLR   (If support)
*                                       @arg TIMExtCapDual_RiseStart_CLR     (If support)
*                                       @arg TIMExtCapDual_FallStart_NotCLR   (If support)
*                                       @arg TIMExtCapDual_FallStart_CLR     (If support)
*                                       @arg TIMExtEventRecordRiseEdge     (If support)
*                                       @arg TIMExtEventRecordFallEdge     (If support)
*
*                              3) TimerPeriod  : Set timing period
*                              4) TimerCompare : Set compare register
*                              5) TimerPreDiv  : Set the prescaler of the timer
*
*                              6) TimerReadMode  : Set the read CNT mode   (If support)
*                                       @arg TIMExtReadMode_ASYN
*                                       @arg TIMExtReadMode_SYNC
*                              7) TimerCapEvtTrigFilter : Set the number of filter (If support)
*                                       @arg TimCapEvtTrigFilter_0
*                                       @arg TimCapEvtTrigFilter_2
*                                       @arg TimCapEvtTrigFilter_5
*                                       @arg TimCapEvtTrigFilter_11
*
*                              8) TimerCapEvtTrigSource  : Set the extended input source  (If support)
*                                       @arg TimCapEvtTrigSrc_INT0
*                                       @arg TimCapEvtTrigSrc_INT1
*                                       @arg TimCapEvtTrigSrc_INT2
*                                       @arg TimCapEvtTrigSrc_INT3
*                                       @arg TimCapEvtTrigSrc_RX0
*                                       @arg TimCapEvtTrigSrc_RX1
*                                       @arg TimCapEvtTrigSrc_RX2
*                                       @arg TimCapEvtTrigSrc_RX3
*                              9) TimCapEvtTrigEnable  : Enable or disable the  Extended Input source function  (If support)
*
*                              10) TimerExTrigMode : Set the Polarity of External Trigger  (If support)
*                                       @arg TimExTrigMode_Rise
*                                       @arg TimExTrigMode_Fall
*                                       @arg TimExTrigMode_Dual
*
*                              11) TimerEXTRIGSource  : Set the Source of External Trigger   (If support)
*                                       @arg TimerExTrigSrc_INT0
*                                       @arg TimerExTrigSrc_INT3
*                                       @arg TimerExTrigSrc_RX0
*                                       @arg TimerExTrigSrc_RX3
*                                       @arg TimerExTrigSrc_RTCTMR2_PRD
*                                       @arg TimerExTrigSrc_TMR5_CMP
*                                       @arg TimerExTrigSrc_TOUT

*                                       @arg TimerExTrigSrc_LPRX0         (If support)
*                                       @arg TimerExTrigSrc_TMR0_PRD      (If support)
*                              12) TimExTrigEnable : Enable or disable the  External Trigger start-up timer function   (If support)
*                              13) TimExtOPModeEnable  : Set the One pulse mode   (If support)
* @retval None
*
* @note: Special note: The user should enable the TIMER module before configuring the TIMER register.
*    For details, refer to the HT_CMU_ClkCtrl1Config() function
*********************************************************************************************************
*/
#if  defined  USE_TMR_EXT
void HT_TMRExt_Init(HT_TMR_TypeDef *TMRx, TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*  assert_param  */
    assert_param(IS_TMRExt_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST2(TMRx));

#if defined USE_TMREXT_ADD_FUNC
    assert_param(IS_TMRExt_FuncMode1(TMRExt_InitStruct->TimerMode)||IS_TMRExt_FuncMode2(TMRExt_InitStruct->TimerMode));
#else
    assert_param(IS_TMRExt_FuncMode1(TMRExt_InitStruct->TimerMode));
#endif

#if defined USE_TMREXT_EXTCLK
    assert_param(IS_TMRExt_InternalCLKSource(TMRExt_InitStruct->TimerSource) || IS_TMRExt_ExternalCLKSource(TMRExt_InitStruct->TimerSource));
#else
    assert_param(IS_TMRExt_InternalCLKSource(TMRExt_InitStruct->TimerSource));
#endif

#if defined USE_TMREXT_EXTEND_FUNC
    
    assert_param(IS_TMRExt_CapEvtTrigFilter(TMRExt_InitStruct->TimerCapEvtTrigFilter));
    assert_param(IS_TMRExt_CapEvtTrigSource(TMRExt_InitStruct->TimerCapEvtTrigSource));
    assert_param(IS_TMRExt_ReadMode(TMRExt_InitStruct->TimerReadMode));
    assert_param(IS_TMRExt_ExTrigMode(TMRExt_InitStruct->TimerExTrigMode));

#if defined USE_TMREXT_EXTRIG_SEL
    assert_param(IS_TMRExt_ExTrigSource1(TMRExt_InitStruct->TimerExTrigSource) || IS_TMRExt_ExTrigSource2(TMRExt_InitStruct->TimerExTrigSource));
#else
    assert_param(IS_TMRExt_ExTrigSource1(TMRExt_InitStruct->TimerExTrigSource));
#endif

    assert_param(IS_FUNCTIONAL_STATE(TMRExt_InitStruct->TimCapEvtTrigEnable));
    assert_param(IS_FUNCTIONAL_STATE(TMRExt_InitStruct->TimExTrigEnable));
    assert_param(IS_FUNCTIONAL_STATE(TMRExt_InitStruct->TimExtOPModeEnable));
    
#endif

    if ((TMRx == HT_TMR4) || (TMRx == HT_TMR5))
    {
        TMRx->TMRCON &= (~TMR_TMRCON_CNTEN);               /*!< disable CNTEN               */
        TMRx->TMRCON =(uint32_t)TMRExt_InitStruct->TimerSource;
        TMRx->TMRCON |= (uint32_t)TMRExt_InitStruct->TimerMode;

#if defined USE_TMREXT_EXTCLK
                
        if(TMRExt_InitStruct->TimerSource == TIMExtClk_Exclk)
        {
            TMRx->TMRCON &= ~TMR_TMRCON_MODE;
            TMRx->TMRCON |= (uint32_t)TIMExtCycleTiming;
        }
#endif

        TMRx->TMRPRD = TMRExt_InitStruct->TimerPeriod;        /*!< Configure the timer period        */
        TMRx->TMRCMP = TMRExt_InitStruct->TimerCompare;       /*!< Configure compare register        */
        TMRx->TMRDIV = TMRExt_InitStruct->TimerPreDiv;        /*!< Configure timer prescaler   */

#if defined USE_TMREXT_EXTEND_FUNC
        if(TMRExt_InitStruct->TimExtOPModeEnable != DISABLE)
        {
            TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
            TMRx->TMRCFG |= TMR_TMRCFG_ONCE_ENABLE;                 /*!< Enable One pulse mode */

            if((TMRExt_InitStruct->TimerMode == TIMExtPWMCenterAlignedLevelHigh) || (TMRExt_InitStruct->TimerMode == TIMExtPWMCenterAlignedLevelLow))
            {
                TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
            }    /*!< One pulse mode is not suitable for pwm center counting mode*/
        } 
        else
        {
            TMRx->TMRCFG &= ~TMR_TMRCFG_ONCE;
        }

        if(TMRExt_InitStruct->TimCapEvtTrigEnable != DISABLE)
        {
            TMRx->TMRTRIGERCFG &= ~TMR_TMRTRIGERCFG_FILTERSEL;
            TMRx->TMRTRIGERCFG |= TMRExt_InitStruct->TimerCapEvtTrigFilter;      /*!< Configure the number of filter */

            TMRx->TMRTRIGERCFG &= ~TMR_TMRTRIGERCFG_TRIGRSEL;
            TMRx->TMRTRIGERCFG |= TMRExt_InitStruct->TimerCapEvtTrigSource;      /*!< Configure the extended input source */

            TMRx->TMRTRIGERCFG &= ~TMR_TMRTRIGERCFG_TMR_MODE_SEL;
            TMRx->TMRTRIGERCFG |= TMRExt_InitStruct->TimerReadMode;      /*!< Configure the read CNT mode*/
            TMRx->TMRTRIGERCFG |= TMR_TMRTRIGERCFG_EXTRIG_EN;              /*!< Enable the  Extended Input source function*/
        } 
        else
        {
            TMRx->TMRTRIGERCFG &= ~TMR_TMRTRIGERCFG_EXTRIG_EN;
        }
		
        if(TMRExt_InitStruct->TimExTrigEnable !=DISABLE)
        {
            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TRIGERSEL;
            TMRx->TMREXTRIGCFG |= TMRExt_InitStruct->TimerExTrigSource;     /*!< Configure the External Trigger signal source */

            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TRIGMODE;
                        
            uint16_t tmp_EXTrigSel = (TMRx->TMREXTRIGCFG & TMR_TMREXTRIGCFG_TRIGERSEL);
            
#if defined USE_TMREXT_EXTRIG_SEL
            if((tmp_EXTrigSel == TimerExTrigSrc_RTCTMR2_PRD)|| (tmp_EXTrigSel == TimerExTrigSrc_TMR5_CMP) || (tmp_EXTrigSel == TimerExTrigSrc_TMR0_PRD))
            {
                TMRx->TMREXTRIGCFG |= TMR_TMREXTRIGCFG_TRIGMODE_RISE;     /*!< It must configure the Polarity to rise    */
            }
            else
            {
                TMRx->TMREXTRIGCFG |=TMRExt_InitStruct->TimerExTrigMode;    /*!< Configure the Polarity of Trigger  */
            }
#else
            if((tmp_EXTrigSel == TimerExTrigSrc_RTCTMR2_PRD)|| (tmp_EXTrigSel == TimerExTrigSrc_TMR5_CMP))
            {
                TMRx->TMREXTRIGCFG |= TMR_TMREXTRIGCFG_TRIGMODE_RISE;     /*!< It must configure the Polarity to rise    */
            } 
            else
            {
                TMRx->TMREXTRIGCFG |=TMRExt_InitStruct->TimerExTrigMode;    /*!< Configure the Polarity of Trigger  */
            }
           
#endif
            TMRx->TMREXTRIGCFG |= TMR_TMREXTRIGCFG_TMRTRIG_EN;              /*!<  Enable the  External Trigger start-up timer function*/
        } 
        else
        {
            TMRx->TMREXTRIGCFG &= ~TMR_TMREXTRIGCFG_TMRTRIG_EN;
        }

#endif
        TMRx->TMRCNT = 0U;                                  /*!< Clear the timer count register    */
        TMRx->TMRIF = 0U;                                   /*!< Clear the timer Interrupt Flag register        */
        TMRx->TMRCON |= TMR_TMRCON_CNTEN;                            /*!< Set Timer working mode        */
    }

#if (USE_HT_TMR_REGISTER_CALLBACKS ==1U) 
    TMRExt_InitCallbacksToDefault(TMRExt_InitStruct);
    TMRExt_InitStruct->Instance = TMRx;    
#endif
    
}
#endif


/**
  * @brief  Enables or disables the specified TMR peripheral.
  * @param  TMRx: where x can be 0 to 5 to select the TMRx peripheral.
  * @param  NewState: new state of the TMRx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void HT_TMR_Cmd(HT_TMR_TypeDef *TMRx, FunctionalState NewState)
{
    /* Check the parameters */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the TMR Counter */
        TMRx->TMRCON |=TMR_TMRCON_CNTEN;
    }
    else
    {
        /* Disable the TMR Counter */
        TMRx->TMRCON &=~(TMR_TMRCON_CNTEN);
    }
}


/**
*********************************************************************************************************
*                                         SET TIMER PERIOD VALUE
*
* @brief:Set the period register value and clear the current count value
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
*
* @param:  TimerPeriod:  Timer period value
*
* @retval None
*
* @Note ：None
**********************************************************************************************************
*/
void HT_TMR_PeriodSet(HT_TMR_TypeDef *TMRx, uint16_t TimerPeriod)
{
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

    TMRx->TMRPRD = TimerPeriod;                             /*!< Configure the timer period register   */
    TMRx->TMRCNT = 0U;                                       /*!< Clear the timer count register        */
}


/**
*********************************************************************************************************
*                                         SET TIMER Prescaler(TMRDIV) VALUE
*
* @brief:Set the Prescaler register value
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
*
* @param:  TimerDiv:  Timer Prescaler(TMRDIV) value
*
* @retval None
*
* @Note ：None
**********************************************************************************************************
*/
void HT_TMR_PrescalerSet(HT_TMR_TypeDef *TMRx,uint16_t TimerDiv)
{
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

    TMRx->TMRDIV = TimerDiv;   /*!< Configure the timer Prescaler(TMRDIV) register   */
}


/**
*********************************************************************************************************
*                                         SET TIMER Counter VALUE
*
* @brief:Set the Counter register value
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
*
* @param:  TimerCounter:  Timer Counter value
*
* @retval None
*
* @Note ：None
**********************************************************************************************************
*/
void HT_TMR_CounterSet(HT_TMR_TypeDef *TMRx,uint16_t TimerCounter)
{
    /*  assert_param  */

#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

    TMRx->TMRCNT = TimerCounter;                            /*!< Configure the Counter register        */
}


/**
*********************************************************************************************************
*                                         SET TIMER COMPARE VALUE
*
* @brief:Set the compare register value
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
* @param:  TimerCompare:  Timer Compare value
* @retval ：None
*
*@Note ：None
*********************************************************************************************************
*/
void HT_TMR_CompareSet(HT_TMR_TypeDef *TMRx, uint16_t TimerCompare)
{
    /*  assert_param  */

#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

    TMRx->TMRCMP = TimerCompare;                            /*!< Configure the timer Compare register        */
}


/**
*********************************************************************************************************
*                                         GET TIMER CAPTURE VALUE
*@brief:Get the value of the capture register
*
** @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
* @retval ：None
*
* @Note ：if same TMRx does not have the cap register or does not support the input capture function ,
*          the function return value is the default Value(0).
*********************************************************************************************************
*/
uint16_t HT_TMR_CaptureGet(HT_TMR_TypeDef *TMRx)
{
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif
   
    return  ((uint16_t)TMRx->TMRCAP);                /*!< Return the capture value of the capture register         */
}


/**
*********************************************************************************************************
*                                         GET TIMER COUNT VALUE
*
* @brief:Get the current  value of the timer Counting register
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
* @retval ：None
*
* @Note ：None
*********************************************************************************************************
*/
uint16_t HT_TMR_CountGet(HT_TMR_TypeDef *TMRx)
{
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

    return  ((uint16_t)TMRx->TMRCNT);                /*!< Return the timer counter value         */
}


/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE TIMER INTERRUPT
*
* @brief:  Enable or disable the TIMER interrupt
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one or a combination of the following values:
*
*                                 			@arg TMR_TMRIE_PRDIE
*                                 			@arg TMR_TMRIE_CAPIE
*                                			@arg TMR_TMRIE_CMPIE
*                        					@arg TMR_TMRIE_ACIE    (If support)
*                                           @arg TMR_TMRIE_TRIGIE  (If support)
*
*           NewState   = ENABLE： Enable interrupt
*                      = DISABLE：disable interrupt
* @retval ：None
*
* @Note ：None
*********************************************************************************************************
*/
void HT_TMR_ITConfig(HT_TMR_TypeDef *TMRx, uint16_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */

#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

#if defined USE_TMREXT_TRIG
    assert_param(IS_TMR_CONFIG_BASE_IT(ITEn) || IS_TMR_CONFIG_AC_IT(ITEn) || IS_TMR_CONFIG_TRIG_IT(ITEn));

#elif defined USE_TMR_RECORD
    assert_param(IS_TMR_CONFIG_BASE_IT(ITEn)|| IS_TMR_CONFIG_AC_IT(ITEn));
#else
    assert_param(IS_TMR_CONFIG_BASE_IT(ITEn));
#endif

    assert_param(IS_FUNCTIONAL_STATE(NewState));

    TMRx->TMRIF =0U;                                /*!< Clear the TIMER Interrupt Flag register        */

    if (NewState != DISABLE)
    {
        TMRx->TMRIE |= (uint32_t)ITEn;               /*!< Enable TIMER interrupt         */
    }
    else
    {
        TMRx->TMRIE &= ~(uint32_t)ITEn;              /*!< disable the TIMER interrupt     */
    }
}


/**
*********************************************************************************************************
*                            GET SPECIFIED TIMER INTERRUPT FLAG STATUS
*
* @brief:  Get the status of the corresponding TIMER interrupt flag
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
*
* @param:   ITFlag：: specifies the flag to check.
*   This parameter can be one of the following values:
*                                           @arg TMR_TMRIF_PRDIF
*                                           @arg TMR_TMRIF_CAPIF
*                                           @arg TMR_TMRIF_CMPIF
*                        					@arg TMR_TMRIF_ACIF     (If support)
*                                           @arg TMR_TMRIF_TRIGIF   (If support)
*                                           @arg TMR_TMRIF_CCSTA   (If support,for double capture)
*
* @retval ：ITStatus     = SET：  Generate the corresponding interrupt flag
*                       = RESET：Corresponding interrupt flag is not generated
*
* @Note ：None
*********************************************************************************************************
*/
ITStatus HT_TMR_ITFlagStatusGet(HT_TMR_TypeDef *TMRx, uint16_t ITFlag)
{
    ITStatus tempStatus = RESET;
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

#if defined USE_TMREXT_TRIG
    assert_param(IS_TMR_GET_CCSTA_ITFlag(ITFlag)||IS_TMR_GET_TRIG_ITFlag(ITFlag) || IS_TMR_GET_AC_ITFlag(ITFlag) || IS_TMR_GET_BASE_ITFlag(ITFlag));
#elif defined USE_TMR_ACIF
    assert_param(IS_TMR_GET_AC_ITFlag(ITFlag) || IS_TMR_GET_BASE_ITFlag(ITFlag));
#else
    assert_param(IS_TMR_GET_BASE_ITFlag(ITFlag));
#endif    
    
    if (TMRx->TMRIF & ITFlag)
    {
        tempStatus = SET;                        /*!< TIMER Interrupt Flag is set   */
    }
    else
    {
        tempStatus = RESET;                      /*!< TIMER Interrupt Flag is reset */
    }
    return  tempStatus;
}


/**
*********************************************************************************************************
*                                   CLEAR TIMER INTERRUPT FLAG
*
* @brief: Clear the TIMER interrupt flag
*
* @param: TMRx: Select the TMR peripheral.
*   This parameter can be one of the following values:
*                                 			@arg HT_TMR0
*                                 			@arg HT_TMR1
*                                			@arg HT_TMR2
*                               			@arg HT_TMR3
*                                 			@arg HT_TMR4
*											@arg HT_TMR5
*
* @param:   ITFlag：: specifies the flag to check.
*   This parameter can be one or a combination of the following values:
*                                           @arg TMR_TMRIF_PRDIF
*                                           @arg TMR_TMRIF_CAPIF
*                                           @arg TMR_TMRIF_CMPIF
*                        					@arg TMR_TMRIF_ACIF    (If support)
*                                           @arg TMR_TMRIF_TRIGIF  (If support)
*                                           @arg TMR_TMRIF_CCSTA   (If support,can not write 0)
*
*
* @retval None
*
* @Note ：None
*********************************************************************************************************
*/
void HT_TMR_ClearITPendingBit(HT_TMR_TypeDef *TMRx, uint16_t ITFlag)
{
    /*  assert_param  */
#if defined USE_TMR_EXT
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx)||IS_TMRExt_PERIPH_LIST1(TMRx) || IS_TMRExt_PERIPH_LIST2(TMRx));
#else
    assert_param(IS_TMR_BASE_PERIPH_LIST1(TMRx));
#endif

#if defined USE_TMREXT_TRIG
    assert_param(IS_TMR_GET_TRIG_ITFlag(ITFlag) || IS_TMR_GET_AC_ITFlag(ITFlag) || IS_TMR_GET_BASE_ITFlag(ITFlag));
#elif defined USE_TMR_RECORD
    assert_param(IS_TMR_GET_AC_ITFlag(ITFlag) || IS_TMR_GET_BASE_ITFlag(ITFlag));
#else
    assert_param(IS_TMR_GET_BASE_ITFlag(ITFlag));
#endif

#if  defined  USE_TMR_CLEAR_BIT3IF
    ITFlag |= TMR_CLEAR_BIT3IF;
#endif                                                   /*!<If support */
    TMRx->TMRIF   = ~((uint32_t)ITFlag);                 /*!< Clear TIMER Interrupt Flag      */
}


#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)
/**
*********************************************************************************************************
*                                         TMR PRD CALLBACK
*
* @brief: period timing callbacks.
*
* @param: TMR_InitStruct  Pointer to a TMR_InitTypeDef structure that contains
*                the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMR_PRDCallback(TMR_InitTypeDef *TMR_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMR_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMR_CAPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMR CAP CALLBACK
*
* @brief: Input capture  callbacks.
*
* @param: TMR_InitStruct  Pointer to a TMR_InitTypeDef structure that contains
*                the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMR_CAPCallback(TMR_InitTypeDef *TMR_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMR_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMR_CAPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMR CMP CALLBACK
*
* @brief: Output comparison interrupt callbacks.
*
* @param: TMR_InitStruct  Pointer to a TMR_InitTypeDef structure that contains
*                the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMR_CMPCallback(TMR_InitTypeDef *TMR_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMR_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMR_CAPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMR AC CALLBACK
*
* @brief: Event Record callbacks.
*
* @param: TMR_InitStruct  Pointer to a TMR_InitTypeDef structure that contains
*                the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMR_ACIF
__weak void HT_TMR_ACCallback(TMR_InitTypeDef *TMR_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMR_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMR_ACCallback could be implemented in the user file
     */
}
#endif


/**
* @brief  Register a User TMR Callback
*         To be used instead of the weak predefined callback
* @param  TMR_InitStruct TMR handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref TMR_PRD_CB_ID  period timing  Callback ID
*           @arg @ref TMR_CAP_CB_ID  input capture Callback ID
*           @arg @ref TMR_CMP_CB_ID  Output comparison Callback ID     (If support)
*           @arg @ref TMR_AC_CB_ID   Event count Callback ID           (If support)
*           @arg @ref TMR_TRIG_CB_ID External trigger Callback ID     (If support)
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_TMR_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register 
*		himself defined callback function.
*/
StatusTypeDef HT_TMR_RegisterCallback(TMR_InitTypeDef *TMR_InitStruct, TMR_CallbackIDTypeDef TMR_CallbackID, pTMR_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        TMR_InitStruct->ErrorCode |= TMR_ERROR_INVALID_CALLBACK;

        status = ERROR;
    }
    else
    {
        switch (TMR_CallbackID)
        {
        case TMR_PRD_CB_ID:
            TMR_InitStruct->PRDCallback = pCallback;
            break;

        case TMR_CAP_CB_ID:
            TMR_InitStruct->CAPCallback = pCallback;
            break;

        case TMR_CMP_CB_ID:
            TMR_InitStruct->CMPCallback = pCallback;
            break;

        case TMR_AC_CB_ID:
            TMR_InitStruct->ACCallback = pCallback;
            break;
            
        default :
            /* Update the error code */
            TMR_InitStruct->ErrorCode |= TMR_ERROR_INVALID_CALLBACK;

            /* Return error status */
            status =  ERROR;
            break;
        }
    }
    return status;
}


/**
*********************************************************************************************************
*                                         INITIAL TMR CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: TMR_InitStruct Pointer to a TMR_InitStruct structure that contains
*               the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMR_InitCallbacksToDefault(TMR_InitTypeDef *TMR_InitStruct)
{
    /* Init the TMR Callback settings */
    TMR_InitStruct->PRDCallback =HT_TMR_PRDCallback;
    TMR_InitStruct->CAPCallback = HT_TMR_CAPCallback;
    TMR_InitStruct->CMPCallback =HT_TMR_CMPCallback;
#if defined USE_TMR_ACIF
    TMR_InitStruct->ACCallback = HT_TMR_ACCallback;
#endif
}


/**
*********************************************************************************************************
*                                         PEROID TIMING IT HANDLER
*
* @brief: Timer peroid overflow interrupt
*
* @param: TMR_InitStruct Pointer to a TMR_InitTypeDef structure that contains
*               the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMR_PRD_IT(TMR_InitTypeDef *TMR_InitStruct)
{
    /*Call registered peroid overflow callback*/
    if(TMR_InitStruct->PRDCallback!= NULL)
    {
        TMR_InitStruct->PRDCallback(TMR_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         input capture IT HANDLER
*
* @brief: Capture the rising or falling edge
*
* @param: TMR_InitStruct Pointer to a TMR_InitTypeDef structure that contains
*               the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMR_CAP_IT(TMR_InitTypeDef *TMR_InitStruct)
{
    /*Call registered capture callback*/
    if(TMR_InitStruct->CAPCallback!= NULL)
    {
        TMR_InitStruct->CAPCallback(TMR_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         Output comparison IT HANDLER
*
* @brief: When the count value reaches the compare register value, a compare interrupt occurs
*
* @param: TMR_InitStruct Pointer to a TMR_InitTypeDef structure that contains
*               the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMR_CMP_IT(TMR_InitTypeDef *TMR_InitStruct)
{
    /*Call registered capare callback*/
    if(TMR_InitStruct->CMPCallback!= NULL)
    {
        TMR_InitStruct->CMPCallback(TMR_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         EventRecord IT HANDLER
*
* @brief: Detect the external input signal of the set number of times
*
* @param: TMR_InitStruct Pointer to a TMR_InitTypeDef structure that contains
*               the configuration information for the specified TMR module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMR_ACIF
static void TMR_AC_IT(TMR_InitTypeDef *TMR_InitStruct)
{
    /*Call registered AC callback*/
    if(TMR_InitStruct->ACCallback!= NULL)
    {
        TMR_InitStruct->ACCallback(TMR_InitStruct);
    }
}
#endif


void HT_TMR_IRQHandler(TMR_InitTypeDef *TMR_InitStruct)
{
    uint32_t isrflags   = READ_REG(TMR_InitStruct->Instance->TMRIF);

    /* TMR Period interrupt -------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_PRDIF) != RESET))
    {
        TMR_PRD_IT(TMR_InitStruct);
        HT_TMR_ClearITPendingBit(TMR_InitStruct->Instance,(uint16_t)TMR_TMRIF_PRDIF);
    }

    /* TMR capture interrupt ------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_CAPIF) != RESET))
    {
        TMR_CAP_IT(TMR_InitStruct);
        HT_TMR_ClearITPendingBit(TMR_InitStruct->Instance,(uint16_t)TMR_TMRIF_CAPIF);
    }
    
    /* TMR compare interrupt ------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_CMPIF) != RESET))
    {
        TMR_CMP_IT(TMR_InitStruct);
        HT_TMR_ClearITPendingBit(TMR_InitStruct->Instance,(uint16_t)TMR_TMRIF_CMPIF);
    }
    
    /* TMR Event record interrupt ------------------------------------------------*/
#if defined USE_TMR_ACIF

    if (((isrflags & TMR_TMRIF_ACIF) != RESET))
    {
        TMR_AC_IT(TMR_InitStruct);
        HT_TMR_ClearITPendingBit(TMR_InitStruct->Instance,(uint16_t)TMR_TMRIF_ACIF);
    }
#endif
}


#if defined USE_TMR_EXT

/**
*********************************************************************************************************
*                                         TMRExt PRD CALLBACK
*
* @brief: period timing callbacks.
*
* @param: TMRExt_InitStruct  Pointer to a TMRExt_InitTypeDef structure that contains
*                the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMRExt_PRDCallback(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMRExt_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMRExt_CAPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMRExt CAP CALLBACK
*
* @brief: Input capture  callbacks.
*
* @param: TMRExt_InitStruct  Pointer to a TMRExt_InitTypeDef structure that contains
*                the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMRExt_CAPCallback(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMRExt_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMRExt_CAPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMRExt CMP CALLBACK
*
* @brief: Output comparison interrupt callbacks.
*
* @param: TMRExt_InitStruct  Pointer to a TMRExt_InitTypeDef structure that contains
*                the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_TMRExt_CMPCallback(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMRExt_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMRExt_CMPCallback could be implemented in the user file
     */
}


/**
*********************************************************************************************************
*                                         TMRExt AC CALLBACK
*
* @brief: Event Record callbacks.
*
* @param: TMRExt_InitStruct  Pointer to a TMRExt_InitTypeDef structure that contains
*                the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMR_ACIF
__weak void HT_TMRExt_ACCallback(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMRExt_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMRExt_ACCallback could be implemented in the user file
     */
}
#endif


/**
*********************************************************************************************************
*                                         TMRExt TRIG CALLBACK
*
* @brief: External trigger callbacks.
*
* @param: TMRExt_InitStruct  Pointer to a TMR_InitTypeDef structure that contains
*                the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMREXT_TRIG
__weak void HT_TMRExt_TRIGCallback(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(TMRExt_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_TMRExt_TRIGCallback could be implemented in the user file
     */
}
#endif


/**
* @brief  Register a User TMRExt Callback
*         To be used instead of the weak predefined callback
* @param  TMRExt_InitStruct TMRExt handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref TMR_PRD_CB_ID  period timing  Callback ID
*           @arg @ref TMR_CAP_CB_ID  input capture Callback ID
*           @arg @ref TMR_CMP_CB_ID  Output comparison Callback ID
*           @arg @ref TMR_AC_CB_ID   Event count Callback ID              (If support)
*           @arg @ref TMR_TRIG_CB_ID  External trigger Callback ID    (If support)

* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_TMR_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register
*		himself defined callback function.
*/
StatusTypeDef HT_TMRExt_RegisterCallback(TMRExt_InitTypeDef *TMRExt_InitStruct, TMR_CallbackIDTypeDef TMR_CallbackID, pTMRExt_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        TMRExt_InitStruct->ErrorCode |= TMRExt_ERROR_INVALID_CALLBACK;

        status = ERROR;
    }
    else
    {
        switch (TMR_CallbackID)
        {
        case TMR_PRD_CB_ID:
            TMRExt_InitStruct->ExtPRDCallback = pCallback;
            break;

        case TMR_CAP_CB_ID:
            TMRExt_InitStruct->ExtCAPCallback = pCallback;
            break;

        case TMR_CMP_CB_ID:
            TMRExt_InitStruct->ExtCMPCallback = pCallback;
            break;

        case TMR_AC_CB_ID:
            TMRExt_InitStruct->ExtACCallback = pCallback;
            break;

        case TMR_TRIG_CB_ID:
            TMRExt_InitStruct->ExtTRIGCallback = pCallback;
            break;

        default :
            /* Update the error code */
            TMRExt_InitStruct->ErrorCode |= TMRExt_ERROR_INVALID_CALLBACK;

            /* Return error status */
            status =  ERROR;
            break;
        }
    }
    return status;
}


/**
*********************************************************************************************************
*                                         INITIAL TMRExt CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitStruct structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMRExt_InitCallbacksToDefault(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /* Init the TMRExt Callback settings */
    TMRExt_InitStruct->ExtPRDCallback = HT_TMRExt_PRDCallback;
    TMRExt_InitStruct->ExtCAPCallback = HT_TMRExt_CAPCallback;
    TMRExt_InitStruct->ExtCMPCallback =HT_TMRExt_CMPCallback;
#if defined USE_TMR_ACIF
    TMRExt_InitStruct->ExtACCallback = HT_TMRExt_ACCallback;
#endif

#if defined USE_TMREXT_TRIG
    TMRExt_InitStruct->ExtTRIGCallback = HT_TMRExt_TRIGCallback;
#endif

}


/**
*********************************************************************************************************
*                                         PEROID TIMING IT HANDLER
*
* @brief: Timer peroid overflow interrupt
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitTypeDef structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMRExt_PRD_IT(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*Call registered peroid overflow callback*/
    if(TMRExt_InitStruct->ExtPRDCallback!= NULL)
    {
        TMRExt_InitStruct->ExtPRDCallback(TMRExt_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         input capture IT HANDLER
*
* @brief: Capture the rising or falling edge
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitTypeDef structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMRExt_CAP_IT(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*Call registered capture callback*/
    if(TMRExt_InitStruct->ExtCAPCallback!= NULL)
    {
        TMRExt_InitStruct->ExtCAPCallback(TMRExt_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         Output comparison IT HANDLER
*
* @brief: When the count value reaches the compare register value, a compare interrupt occurs
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitTypeDef structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void TMRExt_CMP_IT(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*Call registered capare callback*/
    if(TMRExt_InitStruct->ExtCMPCallback!= NULL)
    {
        TMRExt_InitStruct->ExtCMPCallback(TMRExt_InitStruct);
    }
}


/**
*********************************************************************************************************
*                                         EventRecord IT HANDLER
*
* @brief: Detect the external input signal of the set number of times
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitTypeDef structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMR_ACIF
static void TMRExt_AC_IT(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*Call registered AC callback*/
    if(TMRExt_InitStruct->ExtACCallback!= NULL)
    {
        TMRExt_InitStruct->ExtACCallback(TMRExt_InitStruct);
    }
}
#endif


/**
*********************************************************************************************************
*                                         External trigger event IT HANDLER
*
* @brief: Start the timer when an external trigger event occurs
*
* @param: TMRExt_InitStruct Pointer to a TMRExt_InitTypeDef structure that contains
*               the configuration information for the specified TMRExt module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if defined USE_TMREXT_TRIG
static void TMRExt_TRIG_IT(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    /*Call registered TRIG callback*/
    if(TMRExt_InitStruct->ExtTRIGCallback!= NULL)
    {
        TMRExt_InitStruct->ExtTRIGCallback(TMRExt_InitStruct);
    }
}
#endif


void HT_TMRExt_IRQHandler(TMRExt_InitTypeDef *TMRExt_InitStruct)
{
    uint32_t isrflags   = READ_REG(TMRExt_InitStruct->Instance->TMRIF);

    /* TMRExt Period interrupt -------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_PRDIF) != RESET))
    {
        TMRExt_PRD_IT(TMRExt_InitStruct);
        HT_TMR_ClearITPendingBit(TMRExt_InitStruct->Instance,(uint16_t)TMR_TMRIF_PRDIF);   
    }

    /* TMRExt capture interrupt ------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_CAPIF) != RESET))
    {
        TMRExt_CAP_IT(TMRExt_InitStruct);
        HT_TMR_ClearITPendingBit(TMRExt_InitStruct->Instance,(uint16_t)TMR_TMRIF_CAPIF);
    }
    /* TMRExt compare interrupt ------------------------------------------------*/
    if (((isrflags & TMR_TMRIF_CMPIF) != RESET))
    {
        TMRExt_CMP_IT(TMRExt_InitStruct);
        HT_TMR_ClearITPendingBit(TMRExt_InitStruct->Instance,(uint16_t)TMR_TMRIF_CMPIF);
    }
    /* TMRExt Event record interrupt ------------------------------------------------*/
    #if defined USE_TMR_ACIF

    if (((isrflags & TMR_TMRIF_ACIF) != RESET))
    {
        TMRExt_AC_IT(TMRExt_InitStruct);
        HT_TMR_ClearITPendingBit(TMRExt_InitStruct->Instance,(uint16_t)TMR_TMRIF_ACIF);
    }
    #endif
    /* TMRExt trigger interrupt ------------------------------------------------*/
    #if defined USE_TMREXT_TRIG
    if (((isrflags & TMR_TMRIF_TRIGIF) != RESET))
    {
        TMRExt_TRIG_IT(TMRExt_InitStruct);
        HT_TMR_ClearITPendingBit(TMRExt_InitStruct->Instance,(uint16_t)TMR_TMRIF_TRIGIF);
    }
    #endif
}

#endif

#endif


