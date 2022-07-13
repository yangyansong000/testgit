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
* File         : ht6xxx_timer.h
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_TIMER_H__
#define __HT6XXX_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "ht6xxx_lib.h"




#define IS_TMR_BASE_PERIPH_LIST1(PERIPH) (((PERIPH) == HT_TMR0) || \
                                   ((PERIPH) == HT_TMR1) || \
                                   ((PERIPH) == HT_TMR2) || \
                                   ((PERIPH) == HT_TMR3))
#define IS_TMR_BASE_PERIPH_LIST2(PERIPH) (((PERIPH) == HT_TMR4))



#define IS_TMR_BASE_FuncMode1(ModeSelect) (((ModeSelect) == TIMCycleTiming) || \
                                  ((ModeSelect) == TIMPWMCountUpLevelHigh) || \
                                  ((ModeSelect) == TIMPWMCountDownLevelHigh) || \
                                  ((ModeSelect) == TIMPWMCenterAlignedLevelHigh) || \
                                  ((ModeSelect) == TIMPWMCountUpLevelLow) || \
                                  ((ModeSelect) == TIMPWMCountDownLevelLow) || \
                                  ((ModeSelect) == TIMPWMCenterAlignedLevelLow) || \
                                  ((ModeSelect) == TIMCaptureRiseEdge) || \
                                  ((ModeSelect) == TIMCaptureFallEdge))

#define IS_TMR_BASE_FuncMode2(ModeSelect) (((ModeSelect) == TIMCapDual_RiseStart_NotCLR) || \
                                  ((ModeSelect) == TIMCapDual_RiseStart_CLR) || \
                                  ((ModeSelect) == TIMCapDual_FallStart_NotCLR) || \
                                  ((ModeSelect) == TIMCapDual_FallStart_CLR))



#define IS_TMR_EventRecord_FuncMode(ModeSelect) (((ModeSelect) == TIMEventRecordRiseEdge) || \
                                                    ((ModeSelect) == TIMEventRecordFallEdge))



#define IS_TMR_PWMMode(ModeSelect) (((ModeSelect) == TIMPWMSyncOut) || \
                                  ((ModeSelect) == TIMPWMCompOutDeadTimeLevelLow) || \
                                  ((ModeSelect) == TIMPWMCompOutDeadTimeLevelHigh))


#define IS_TMR_CCMODE(ICPolarity) (((ICPolarity) == TMR_TMRCON_CCMODE_RISE) || \
                                  ((ICPolarity) == TMR_TMRCON_CCMODE_FALL))

#define IS_TMR_PWMHL(PWMPolarity) (((PWMPolarity) == TMR_TMRCON_PWMHL_HIGH) || \
                                  ((PWMPolarity) == TMR_TMRCON_PWMHL_LOW))



#define IS_TMRExt_PERIPH_LIST1(PERIPH) (((PERIPH) == HT_TMR4))
#define IS_TMRExt_PERIPH_LIST2(PERIPH) (((PERIPH) == HT_TMR5))






#define IS_TMRExt_FuncMode1(ModeSelect) (((ModeSelect) == TIMExtCycleTiming) || \
                                  ((ModeSelect) == TIMExtPWMCountUpLevelHigh) || \
                                  ((ModeSelect) == TIMExtPWMCountDownLevelHigh) || \
                                  ((ModeSelect) == TIMExtPWMCenterAlignedLevelHigh) || \
                                  ((ModeSelect) == TIMExtPWMCountUpLevelLow) || \
                                  ((ModeSelect) == TIMExtPWMCountDownLevelLow) || \
                                  ((ModeSelect) == TIMExtPWMCenterAlignedLevelLow))





#define IS_TMRExt_FuncMode2(ModeSelect) (((ModeSelect) == TIMExtCaptureRiseEdge) || \
                                  ((ModeSelect) == TIMExtCaptureFallEdge) || \
                                  ((ModeSelect) == TIMExtCapDual_RiseStart_NotCLR) || \
                                  ((ModeSelect) == TIMExtCapDual_RiseStart_CLR) || \
                                  ((ModeSelect) == TIMExtCapDual_FallStart_NotCLR) || \
                                  ((ModeSelect) == TIMExtCapDual_FallStart_CLR) || \
                                  ((ModeSelect) == TIMExtEventRecordRiseEdge) || \
                                  ((ModeSelect) == TIMExtEventRecordFallEdge))






#define IS_TMRExt_InternalCLKSource(ClkSel) (((ClkSel) == TIMExtClk_LRC) || \
                                        ((ClkSel) == TIMExtClk_LF) || \
                                        ((ClkSel) == TIMExtClk_HRC) || \
                                        ((ClkSel) == TIMExtClk_PLL))
#define IS_TMRExt_ExternalCLKSource(ExtClkSel) (((ExtClkSel) == TIMExtClk_Exclk))



#define IS_TMR_OPM_MODE(MODE) (((MODE) == TMR_TMRCFG_ONCE_ENABLE) || \
                                        ((MODE) == TMR_TMRCFG_ONCE_DISABLE))


#define IS_TMR_CONFIG_BASE_IT(IT)  (((IT) == TMR_TMRIE_PRDIE) || \
                               ((IT) == TMR_TMRIE_CAPIE) || \
							   ((IT) == TMR_TMRIE_CMPIE)	|| \
                                ((((IT) & (uint32_t)(~TMR_TMRIE)) == 0x00) && ((IT) != 0x00)))

#define IS_TMR_CONFIG_AC_IT(IT)  (((IT) == TMR_TMRIE_ACIE))

#define IS_TMR_CONFIG_TRIG_IT(IT)  (((IT) == TMR_TMRIE_TRIGIE))


#define IS_TMR_GET_BASE_ITFlag(IT) (((IT) == TMR_TMRIF_PRDIF) || \
																		((IT) == TMR_TMRIF_CAPIF) || \
																		((IT) == TMR_TMRIF_CMPIF) || \
																		((((IT) & (uint32_t)(~TMR_TMRIF)) == 0x00) && ((IT) != 0x00)))

#define IS_TMR_GET_AC_ITFlag(IT) (((IT) == TMR_TMRIF_ACIF))


#define IS_TMR_GET_TRIG_ITFlag(IT) (((IT) == TMR_TMRIF_TRIGIF))


#define IS_TMR_GET_CCSTA_ITFlag(IT) (((IT) == TMR_TMRIF_CCSTA))




#define IS_TMRExt_CapEvtTrigSource(Source)   (((Source)==TimCapEvtTrigSrc_INT0) || \
                                            ((Source)==TimCapEvtTrigSrc_INT1) || \
                                            ((Source)==TimCapEvtTrigSrc_INT2) || \
                                            ((Source)==TimCapEvtTrigSrc_INT3) || \
                                            ((Source)==TimCapEvtTrigSrc_RX0) || \
                                            ((Source)==TimCapEvtTrigSrc_RX1) || \
                                            ((Source)==TimCapEvtTrigSrc_RX2) || \
                                            ((Source)==TimCapEvtTrigSrc_RX3))

#define IS_TMRExt_CapEvtTrigFilter(Filter)   (((Filter)==TimCapEvtTrigFilter_0) || \
                                            ((Filter)==TimCapEvtTrigFilter_2) || \
                                            ((Filter)==TimCapEvtTrigFilter_5) || \
                                            ((Filter)==TimCapEvtTrigFilter_11))

#define IS_TMRExt_ReadMode(Mode)   (((Mode)==TIMExtReadMode_ASYN) || \
                                            ((Mode)==TIMExtReadMode_SYNC))


#define IS_TMRExt_ExTrigMode(TrigMode)   (((TrigMode)==TimExTrigMode_Rise) || \
                                            ((TrigMode)==TimExTrigMode_Fall) || \
                                            ((TrigMode)==TimExTrigMode_Dual))


#define IS_TMRExt_ExTrigSource1(Source)   (((Source)==TimerExTrigSrc_INT0) || \
                                            ((Source)==TimerExTrigSrc_INT3) || \
                                            ((Source)==TimerExTrigSrc_RX0) || \
                                            ((Source)==TimerExTrigSrc_RX3) || \
                                            ((Source)==TimerExTrigSrc_RTCTMR2_PRD) || \
                                            ((Source)==TimerExTrigSrc_TMR5_CMP) || \
                                            ((Source)==TimerExTrigSrc_TOUT))


#define IS_TMRExt_ExTrigSource2(Source)   (((Source)==TimerExTrigSrc_LPRX0) || \
                                            ((Source)==TimerExTrigSrc_TMR0_PRD))



#define TMR_CLEAR_BIT3IF (uint32_t)0x00000008U





/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

/**
* @brief  Define Timer working mode
*/
typedef enum
{
    TIMPWMCountUpLevelHigh       = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_UP|TMR_TMRCON_MODE_PWM),      /*!< PWM up counting mode, the initial level is high  */
    TIMPWMCountDownLevelHigh     = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_DOWM|TMR_TMRCON_MODE_PWM),    /*!< PWM down counting mode, the initial level is high    */
    TIMPWMCenterAlignedLevelHigh = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_CENTER|TMR_TMRCON_MODE_PWM),  /*!< PWM center-aligned counting mode, the initial level is high*/
    TIMPWMCountUpLevelLow        = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_UP|TMR_TMRCON_MODE_PWM),       /*!< PWM up counting mode, the initial level is low    */
    TIMPWMCountDownLevelLow      = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_DOWM|TMR_TMRCON_MODE_PWM),     /*!< PWM down counting mode, the initial level is low    */
    TIMPWMCenterAlignedLevelLow  = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_CENTER|TMR_TMRCON_MODE_PWM),   /*!< PWM center-aligned counting mode, the initial level is low*/
    TIMCaptureRiseEdge           = (TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),                    /*!< Rising edge capture method      */
    TIMCaptureFallEdge           = (TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),                    /*!< Falling edge capture method                 */
#if defined USE_TMR_RECORD
    TIMEventRecordRiseEdge       = (TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_RECORD),                     /*!< Rising edge EventRecord method        */
    TIMEventRecordFallEdge       = (TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_RECORD),                     /*!< Falling edge EventRecord method      */
#endif


#if defined USE_TMR_DOUBLECAP
    TIMCapDual_RiseStart_NotCLR  = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_0|TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Rising edge,
                                                                                                                                       After the capture is complete, the counter is not cleared to 0     */
    TIMCapDual_RiseStart_CLR     = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_1|TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),       /*!< Double edge capture,begin with Rising edge,
                                                                                                                                        After the capture is complete, the counter is  cleared to 0     */
    TIMCapDual_FallStart_NotCLR  = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_0|TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Falling edge,
                                                                                                                                        After the capture is complete, the counter is not cleared to 0     */
    TIMCapDual_FallStart_CLR     = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_1|TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Falling edge,
                                                                                                                                        After the capture is complete, the counter is cleared to 0     */

#endif


#if defined USE_TMR_TMRCON_TIMING
    TIMCycleTiming               = TMR_TMRCON_MODE_COMPARE,                                             /*!< Timer period timing               */
#else
    TIMCycleTiming               = TMR_TMRCON_MODE_TIMING,                                              /*!< Timer period timing                */
#endif
} TMRMode_TypeDef;                               /*!< end of group TMRMode_TypeDef   */

/**
* @brief  Timer PWM  mode and polarity     (If support)
*/
#if  defined USE_TMR_PWMMODE
typedef enum
{
    TIMPWMSyncOut                  = TMR_TMRCODT_SYNC_OUT,                     /*!< Synchronous output mode in PWM mode, no dead zone    */
    TIMPWMCompOutDeadTimeLevelLow  = (TMR_TMRCODT_COMP_OUT|TMR_TMRCODT_DT_LL), /*!< Complementary output mode in PWM mode, dead zone polarity is low */
    TIMPWMCompOutDeadTimeLevelHigh = (TMR_TMRCODT_COMP_OUT|TMR_TMRCODT_DT_HL), /*!< Complementary output mode in PWM mode, dead zone polarity is high */
} TMRPwnMode_TypeDef;                            /*!< end of group TMRPwnMode_TypeDef */
#endif

/**
* @brief  TimerExt Working mode definition     (If support)     
*/

#if defined USE_TMR_EXT

typedef enum
{
    TIMExtPWMCountUpLevelHigh       = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_UP|TMR_TMRCON_MODE_PWM),     /*!< PWM up counting mode, the initial level is high  */
    TIMExtPWMCountDownLevelHigh     = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_DOWM|TMR_TMRCON_MODE_PWM),   /*!< PWM down counting mode, the initial level is high    */
    TIMExtPWMCenterAlignedLevelHigh = (TMR_TMRCON_PWMHL_HIGH|TMR_TMRCON_PWMC_CENTER|TMR_TMRCON_MODE_PWM), /*!< PWM center-aligned counting mode, the initial level is high*/
    TIMExtPWMCountUpLevelLow        = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_UP|TMR_TMRCON_MODE_PWM),      /*!< PWM up counting mode, the initial level is low    */
    TIMExtPWMCountDownLevelLow      = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_DOWM|TMR_TMRCON_MODE_PWM),    /*!< PWM down counting mode, the initial level is low    */
    TIMExtPWMCenterAlignedLevelLow  = (TMR_TMRCON_PWMHL_LOW|TMR_TMRCON_PWMC_CENTER|TMR_TMRCON_MODE_PWM),  /*!< PWM center-aligned counting mode, the initial level is low*/
    TIMExtCycleTiming               = TMR_TMRCON_MODE_TIMING,                                              /*!< Timer period timing               */

#if defined USE_TMREXT_ADD_FUNC
    TIMExtCaptureRiseEdge           = (TMR_TMRCON_CDMODE_0|TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),                    /*!< Single Rising edge capture method      */
    TIMExtCaptureFallEdge           = (TMR_TMRCON_CDMODE_0|TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),                    /*!< Single Falling edge capture method                 */
    TIMExtCapDual_RiseStart_NotCLR  = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_0|TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Rising edge,
                                                                                                                                                  After the capture is complete, the counter is not cleared to 0     */
    TIMExtCapDual_RiseStart_CLR     = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_1|TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_CAPTURE),       /*!< Double edge capture,begin with Rising edge,
                                                                                                                                                  After the capture is complete, the counter is  cleared to 0     */
    TIMExtCapDual_FallStart_NotCLR  = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_0|TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Falling edge,
                                                                                                                                                  After the capture is complete, the counter is not cleared to 0     */
    TIMExtCapDual_FallStart_CLR     = (TMR_TMRCON_CDMODE_1|TMR_TMRCON_CDCLEAR_1|TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_CAPTURE),      /*!< Double edge capture,begin with Falling edge,
                                                                                                                                                  After the capture is complete, the counter is cleared to 0     */
    TIMExtEventRecordRiseEdge       = (TMR_TMRCON_CCMODE_RISE|TMR_TMRCON_MODE_RECORD),                     /*!< Rising edge EventRecord method        */
    TIMExtEventRecordFallEdge       = (TMR_TMRCON_CCMODE_FALL|TMR_TMRCON_MODE_RECORD),                     /*!< Falling edge EventRecord method      */


#endif

} TMRExtMode_TypeDef;                            /*!< end of group TMRExtMode_TypeDef*/

typedef enum
{
    TIMExtClk_LRC = TMR_TMRCON_CLKSEL_LRC,       /*!< Timer clock source is LRC                */
    TIMExtClk_LF  = TMR_TMRCON_CLKSEL_LF,        /*!< Timer clock source is LF(OSC)                  */
    TIMExtClk_HRC = TMR_TMRCON_CLKSEL_HRC,       /*!< Timer  clock source is HRC                */
    TIMExtClk_PLL = TMR_TMRCON_CLKSEL_PLL,       /*!< Timer clock source is PLL               */

#if defined USE_TMREXT_EXTCLK
    TIMExtClk_Exclk = TMR_TMRCON_CLKSEL_EXCLK,  /*!< Timer clock source is Fexclk               */

#endif

#if  defined  USE_TMR_EXTCLK_MEMS
    TIMExtClk_MEMS= TMR_TMRCON_CLKSEL_MEMS,      /*!< Timer clock source is MEMS              */
#endif

} TMRExtClkSource_TypeDef;                       /*!< end of group TMRExtClkSource_TypeDef*/


#if defined USE_TMREXT_EXTEND_FUNC

/**
* @brief Define TimerExt the mode of  read TMRCNT (If support)
*/

typedef enum
{
    TIMExtReadMode_ASYN = TMR_TMRTRIGERCFG_TMR_MODE_SEL_ASYN_READ,    /*!< read CNT mode,Use asynchronous logic for reading   */
    TIMExtReadMode_SYNC = TMR_TMRTRIGERCFG_TMR_MODE_SEL_SYNC_READ,    /*!< read CNT mode,Use synchronous logic for reading    */

} TimExtReadMode_TypeDef;  /*!< end of group TIMExtReadMode_TypeDef */


/**
* @brief   the input signal source filte  (If support)
*/
typedef enum
{   
    TimCapEvtTrigFilter_0 = TMR_TMRTRIGERCFG_FILTERSEL_0,           /*!< Select the input signal source filter to be 0   */
    TimCapEvtTrigFilter_2 = TMR_TMRTRIGERCFG_FILTERSEL_2,           /*!< Select the input signal source filter to be 2   */
    TimCapEvtTrigFilter_5 = TMR_TMRTRIGERCFG_FILTERSEL_5,           /*!< Select the input signal source filter to be 5   */
    TimCapEvtTrigFilter_11 = TMR_TMRTRIGERCFG_FILTERSEL_11,         /*!< Select the input signal source filter to be 11   */

} TimCapEvtTrigFilter_TypeDef; /*!< end of group TIMExtICTrigFilter_TypeDef */


/**
* @brief  Extended input source (If support)
*/

typedef enum
{
    TimCapEvtTrigSrc_INT0 = TMR_TMRTRIGERCFG_TRIGRSEL_INT0,       /*!< Extended input source selection is INT0 */
    TimCapEvtTrigSrc_INT1 = TMR_TMRTRIGERCFG_TRIGRSEL_INT1,       /*!< Extended input source selection is INT1 */
    TimCapEvtTrigSrc_INT2 = TMR_TMRTRIGERCFG_TRIGRSEL_INT2,       /*!< Extended input source selection is INT2 */
    TimCapEvtTrigSrc_INT3 = TMR_TMRTRIGERCFG_TRIGRSEL_INT3,       /*!< Extended input source selection is INT3 */
    TimCapEvtTrigSrc_RX0 = TMR_TMRTRIGERCFG_TRIGRSEL_RX0,         /*!< Extended input source selection is RX0 */
    TimCapEvtTrigSrc_RX1 = TMR_TMRTRIGERCFG_TRIGRSEL_RX1,         /*!< Extended input source selection is RX1 */
    TimCapEvtTrigSrc_RX2 = TMR_TMRTRIGERCFG_TRIGRSEL_RX2,         /*!< Extended input source selection is RX2 */
    TimCapEvtTrigSrc_RX3 = TMR_TMRTRIGERCFG_TRIGRSEL_RX3,         /*!< Extended input source selection is RX3 */

} TimCapEvtTrigSource_TypeDef;  /*!< end of group TIMExtICTrigSource_TypeDef */

/**
* @brief  TimerExt Input Trigger  Initialize structure definition (If support)
*/



/**
* @brief  Extended external trigger level edge (If support)
*/

typedef enum
{
    TimExTrigMode_Rise = TMR_TMREXTRIGCFG_TRIGMODE_RISE,      /*!<External Trigger level edge is  Rising       */
    TimExTrigMode_Fall = TMR_TMREXTRIGCFG_TRIGMODE_FALL,      /*!<External Trigger level edge is  falling         */
    TimExTrigMode_Dual= TMR_TMREXTRIGCFG_TRIGMODE_DOUBLE,     /*!<External Trigger level edge is  Rising and falling    */

} TimExTrigMode_TypeDef;  /*!< end of group TIMExtEXTrigMode_TypeDef */


/**
* @brief  Extended external Trigger signal source (If support)
*/

typedef enum
{
    TimerExTrigSrc_INT0 = TMR_TMREXTRIGCFG_TRIGERSEL_INT0,   /*!<External Trigger signal source selection is INT0       */
    TimerExTrigSrc_INT3 = TMR_TMREXTRIGCFG_TRIGERSEL_INT3,   /*!<External Trigger signal source selection is INT3       */
    TimerExTrigSrc_RX0 = TMR_TMREXTRIGCFG_TRIGERSEL_RX0,     /*!<External Trigger signal source selection is RX0       */
    TimerExTrigSrc_RX3 = TMR_TMREXTRIGCFG_TRIGERSEL_RX3,      /*!<External Trigger signal source selection is RX3       */
    TimerExTrigSrc_RTCTMR2_PRD = TMR_TMREXTRIGCFG_TRIGERSEL_RTCTMR2_PRD,  /*!<External Trigger signal source selection is the timing interrupt of RTCTMR2       */
    TimerExTrigSrc_TMR5_CMP = TMR_TMREXTRIGCFG_TRIGERSEL_TMR5_CMP,       /*!<External Trigger signal source selection is the comparison interrupt of TMR5       */
    TimerExTrigSrc_TOUT = TMR_TMREXTRIGCFG_TRIGERSEL_TOUT,               /*!<External Trigger signal source selection is TOUT       */

#if defined USE_TMREXT_EXTRIG_SEL
    TimerExTrigSrc_LPRX0= TMR_TMREXTRIGCFG_TRIGERSEL_LPRX0,      /*!<External Trigger signal source selection is LPRX0       */
    TimerExTrigSrc_TMR0_PRD = TMR_TMREXTRIGCFG_TRIGERSEL_TMR0_PRD,      /*!<External Trigger signal source selection is TMR0_PRD       */
#endif


} TimExTrigSource_TypeDef;  /*!< end of group TIMExtEXTrigSourceTypeDef */


#endif


#endif

/**
* @brief  Timer Initialize structure definition
*/

#if(USE_HT_TMR_REGISTER_CALLBACKS ==1U)


#define TMR_ERROR_INVALID_CALLBACK  0x00000040U   /*!< Invalid Callback error  */




typedef struct __TMR_InitTypeDef
#else
typedef struct
#endif
{

    TMRMode_TypeDef TimerMode;                   /*!< Timer working mode                 */

#if  defined USE_TMR_PWMMODE
    TMRPwnMode_TypeDef PwmMode;                  /*!< PWM output mode                    */
    uint16_t PwmDeadTime;                        /*!< PWM dead time                  */
#endif
    uint16_t TimerPreDiv;                        /*!< Timer clock prescaler setting           */
    uint16_t TimerPeriod;                        /*!< Timer's timing period                 */
    uint16_t TimerCompare;                       /*!< Timer compare register               */

#if defined USE_TMR_OPMODE

    uint16_t TimerOPModeEnable;

#endif


#if defined USE_TMR_EXTRIGCFG

    TimExTrigMode_TypeDef    TimerExTrigMode;   /*!< Configure the Polarity of External Trigger  */
    TimExTrigSource_TypeDef   TimerExTrigSource;     /*!< Configure the Source of External Trigger  */
    uint16_t TimExTrigEnable;                            /*!<  Enable or disable the  External Trigger start-up timer function*/

#endif


#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

    HT_TMR_TypeDef *Instance;                  /*!< TMR registers base address        */
    __IO uint32_t  ErrorCode;        		  /*!< TMR Error code                    */
    void (* PRDCallback)(struct __TMR_InitTypeDef *TMR_InitStruct);            /*!< TMR PRD Callback             */
    void (* CAPCallback)(struct __TMR_InitTypeDef *TMR_InitStruct);            /*!< TMR CAP Callback             */
    void (* CMPCallback)(struct __TMR_InitTypeDef *TMR_InitStruct);            /*!< TMR CMP Callback             */
    void (* ACCallback) (struct __TMR_InitTypeDef *TMR_InitStruct);            /*!< TMR AC Callback             */


#endif


} TMR_InitTypeDef;                               /*!< end of group TMR_InitTypeDef   */


/*
* @brief  TimerExt Initialize structure definition
*/

#if defined USE_TMR_EXT

#if(USE_HT_TMR_REGISTER_CALLBACKS ==1U)
#define TMRExt_ERROR_INVALID_CALLBACK  0x00000041U   /*!< Invalid Callback error  */
typedef struct __TMRExt_InitTypeDef
#else
typedef struct
#endif
{
    TMRExtClkSource_TypeDef TimerSource;         /*!< Clock source selection              */
    TMRExtMode_TypeDef TimerMode;                /*!< Timer working mode                  */
    uint16_t TimerPreDiv;                        /*!< Timer clock prescaler             */
    uint16_t TimerPeriod;                        /*!< Timer's timing period                */
    uint16_t TimerCompare;                       /*!< Timer compare register                 */
    
#if defined USE_TMREXT_EXTEND_FUNC

    TimExtReadMode_TypeDef      TimerReadMode;       /*!< Configure the read CNT mode*/
    TimCapEvtTrigFilter_TypeDef  TimerCapEvtTrigFilter;       /*!< Configure the number of filter */
    TimCapEvtTrigSource_TypeDef  TimerCapEvtTrigSource;       /*!< Configure the extended input source */
    uint16_t TimCapEvtTrigEnable;                            /*!< Enable or disable the  Extended Input source function*/

    TimExTrigMode_TypeDef    TimerExTrigMode;   /*!< Configure the Polarity of External Trigger  */
    TimExTrigSource_TypeDef   TimerExTrigSource;     /*!< Configure the Source of External Trigger  */
    uint16_t TimExTrigEnable;                            /*!<  Enable or disable the  External Trigger start-up timer function*/

    uint16_t TimExtOPModeEnable;                    /*!< Configure the  One pulse mode             */

#endif

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

    HT_TMR_TypeDef *Instance;                  /*!< TMR registers base address        */
    __IO uint32_t  ErrorCode;        		  /*!< TMRExt Error code                    */
    void (* ExtPRDCallback)(struct __TMRExt_InitTypeDef *TMRExt_InitStruct);            /*!< TMR PRD Callback             */
    void (* ExtCAPCallback)(struct __TMRExt_InitTypeDef *TMRExt_InitStruct);            /*!< TMR CAP Callback             */
    void (* ExtCMPCallback)(struct __TMRExt_InitTypeDef *TMRExt_InitStruct);            /*!< TMR CMP Callback             */
    void (* ExtACCallback) (struct __TMRExt_InitTypeDef *TMRExt_InitStruct);            /*!< TMR AC Callback             */
    void (* ExtTRIGCallback) (struct __TMRExt_InitTypeDef *TMRExt_InitStruct);          /*!< TMR TRIG Callback             */

#endif

} TMRExt_InitTypeDef;                            /*!< end of group TMRExt_InitTypeDef*/

#endif


#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

/**
* @brief  TMR Callback ID enumeration definition
*/
typedef enum
{
    TMR_PRD_CB_ID             = 0x00U,    	 /*!< TMR PRD  Callback ID             */
    TMR_CAP_CB_ID             = 0x01U,    	 /*!< TMR CAP  Callback ID             */
    TMR_CMP_CB_ID             = 0x02U,    	 /*!< TMR CMP  Callback ID             */
    TMR_AC_CB_ID              = 0x03U,    	 /*!< TMR AC  Callback ID             */
    TMR_TRIG_CB_ID            = 0x04U,    	 /*!< TMR TRIG  Callback ID             */
} TMR_CallbackIDTypeDef;

/**
* @brief  TMR Callback pointer definition
*/
typedef  void (*pTMR_CallbackTypeDef)(TMR_InitTypeDef *TMR_InitStruct);  /*!< pointer to an TMR callback function */

#if defined USE_TMR_EXT
typedef  void (*pTMRExt_CallbackTypeDef)(TMRExt_InitTypeDef *TMRExt_InitStruct);  /*!< pointer to an TMRExt callback function */
#endif

#endif

/*
*********************************************************************************************************
*                                             Global variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global function declaration
*********************************************************************************************************
*/

void HT_TMR_Init(HT_TMR_TypeDef *TMRx, TMR_InitTypeDef *TMR_InitStruct);
void HT_TMR_Cmd(HT_TMR_TypeDef *TMRx, FunctionalState NewState); /*Enables or disables TMR */


#if defined USE_TMR_EXT
void HT_TMRExt_Init(HT_TMR_TypeDef *TMRx, TMRExt_InitTypeDef *TMRExt_InitStruct); /*If support  */

#endif
void HT_TMR_PeriodSet(HT_TMR_TypeDef *TMRx, uint16_t TimerPeriod);
void HT_TMR_CompareSet(HT_TMR_TypeDef *TMRx, uint16_t TimerCompare);
void HT_TMR_PrescalerSet(HT_TMR_TypeDef *TMRx,uint16_t TimerDiv);
void HT_TMR_CounterSet(HT_TMR_TypeDef *TMRx,uint16_t TimerCounter);


uint16_t HT_TMR_CaptureGet(HT_TMR_TypeDef *TMRx);
uint16_t HT_TMR_CountGet(HT_TMR_TypeDef *TMRx);
void HT_TMR_ITConfig(HT_TMR_TypeDef *TMRx, uint16_t ITEn, FunctionalState NewState);
ITStatus HT_TMR_ITFlagStatusGet(HT_TMR_TypeDef *TMRx, uint16_t ITFlag);
void HT_TMR_ClearITPendingBit(HT_TMR_TypeDef *TMRx, uint16_t ITFlag);

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)

StatusTypeDef HT_TMR_RegisterCallback(TMR_InitTypeDef *TMR_InitStruct, TMR_CallbackIDTypeDef TMR_CallbackID, pTMR_CallbackTypeDef pCallback);
void HT_TMR_PRDCallback(TMR_InitTypeDef *TMR_InitStruct);
void HT_TMR_CAPCallback(TMR_InitTypeDef *TMR_InitStruct);
void HT_TMR_CMPCallback(TMR_InitTypeDef *TMR_InitStruct);

#if defined USE_TMR_ACIF
void HT_TMR_ACCallback(TMR_InitTypeDef *TMR_InitStruct);
#endif





#if defined USE_TMR_EXT
StatusTypeDef HT_TMRExt_RegisterCallback(TMRExt_InitTypeDef *TMRExt_InitStruct, TMR_CallbackIDTypeDef TMR_CallbackID, pTMRExt_CallbackTypeDef pCallback);
void HT_TMRExt_PRDCallback(TMRExt_InitTypeDef *TMRExt_InitStruct);
void HT_TMRExt_CAPCallback(TMRExt_InitTypeDef *TMRExt_InitStruct);
void HT_TMRExt_CMPCallback(TMRExt_InitTypeDef *TMRExt_InitStruct);
#if defined USE_TMR_ACIF
void HT_TMRExt_ACCallback(TMRExt_InitTypeDef *TMRExt_InitStruct);
#endif

#if defined USE_TMREXT_TRIG
void HT_TMRExt_TRIGCallback(TMRExt_InitTypeDef *TMRExt_InitStruct);
#endif

#endif

#endif /* USE_HT_TMR_REGISTER_CALLBACKS */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_TIMER_H__ */
