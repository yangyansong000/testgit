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
* File         : ht6xxx_reset.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_RESET_C

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


/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*                               GET SPECIFIED WAKE FLAG STATUS
*
* @brief: Gets the specified wake-up state
*
* @param: STAFlag    Some wake-up flag to check,this parameter can be one of the following values:
*                       @arg PMU_WAKEIF_PMUWKIF
*                       @arg PMU_WAKEIF_INT0WKIF
*                       @arg PMU_WAKEIF_INT1WKIF
*                       @arg PMU_WAKEIF_INT2WKIF
*                       @arg PMU_WAKEIF_INT3WKIF
*                       @arg PMU_WAKEIF_INT4WKIF
*                       @arg PMU_WAKEIF_INT5WKIF
*                       @arg PMU_WAKEIF_INT6WKIF
*                       @arg PMU_WAKEIF_RX0WKIF
*                       @arg PMU_WAKEIF_RX1WKIF
*                       @arg PMU_WAKEIF_RX2WKIF
*                       @arg PMU_WAKEIF_RX3WKIF
*                       @arg PMU_WAKEIF_RX4WKIF
*                       @arg PMU_WAKEIF_RX5WKIF
*                       @arg PMU_WAKEIF_TBSWKIF
*                       @arg PMU_WAKEIF_RTCWKIF
*                       @arg PMU_WAKEIF_WDTWKIF     (If support)
*                       @arg PMU_WAKEIF_AREGWKIF    (If support)
*                       @arg PMU_WAKEIF_TMR0WKIF    (If support)
*                       @arg PMU_WAKEIF_TMR1WKIF    (If support)
*                       @arg PMU_WAKEIF_TMR2WKIF    (If support)
*                       @arg PMU_WAKEIF_TMR3WKIF    (If support)
*                       @arg PMU_WAKEIF_TMR4WKIF    (If support)
*                       @arg PMU_WAKEIF_TMR5WKIF    (If support)
*                       @arg PMU_WAKEIF_IICWKIF     (If support)
*                       @arg PMU_WAKEIF_SPI0WKIF    (If support)
*                       @arg PMU_WAKEIF_SPI1WKIF    (If support)
*                       @arg PMU_WAKEIF_SPI2WKIF    (If support)
*                       @arg PMU_WAKEIF_SELFTESTWKIF(If support)
*                       @arg PMU_WAKEIF_EMUWKIF     (If support)
*                       @arg PMU_WAKEIF_DMAWKIF     (If support)
*                       @arg PMU_WAKEIF_KEYWKIF     (If support)
*                       @arg PMU_WAKEIF_RX6WKIF     (If support)
*                       @arg PMU_WAKEIF_INT789WKIF  (If support)
*                       @arg PMU_WAKEIF_NMIWKIF     (If support)
*
* @retval: ITStatus    = SET：  The wake-up flag is set
*                       = RESET：The wake-up flag is not set
*
* @Note: Both hold and sleep wake up causes the corresponding wake-up flag to be set,if the user wants
*   to further distinguish between hold wake up and sleep wake up,please look at the PMU_RSTSTA_SleepFlag
*   and PMU_RSTSTA_HoldFlag in the RSTSTA register.
*********************************************************************************************************
*/
FlagStatus HT_WakeFlagStatusGet(uint32_t STAFlag)
{
    FlagStatus flag;
    /*  assert_param  */
    if (HT_PMU->WAKEIF & STAFlag)
    {
        flag = SET;                        /*!< The specified wake-up flag is generated */
    }
    else
    {
        flag = RESET;                      /*!< No specified wake-up flag is generated */
    }
    return flag;
}


/**
*********************************************************************************************************
*                               GET SPECIFIED RESET FLAG STATUS
*
* @brief: Gets the specified reset flag state
*
* @param: STAFlag    Some reset flag to check,this parameter can be one of the following values:
*                       @arg PMU_RSTSTA_PORRST
*                       @arg PMU_RSTSTA_LBORRST
*                       @arg PMU_RSTSTA_WDTRST
*                       @arg PMU_RSTSTA_WakeupRST
*                       @arg PMU_RSTSTA_ExtRST
*                       @arg PMU_RSTSTA_SoftRST
*                       @arg PMU_RSTSTA_DebugRST
*                       @arg PMU_RSTSTA_BORRST
*                       @arg PMU_RSTSTA_SleepFlag
*                       @arg PMU_RSTSTA_HoldFlag
*
*
*
* @retval: ITStatus    = SET：  The reset flag is set
*                       = RESET  The reset flag is not set
*
* @Note: None
*********************************************************************************************************
*/
FlagStatus HT_ResetFlagStatusGet(uint32_t STAFlag)
{
    FlagStatus flag;
    /*  assert_param  */
    if (HT_PMU->RSTSTA & STAFlag)
    {
        flag = SET;                        /*!< The specified reset flag is generated          */
    }
    else
    {
        flag = RESET;                      /*!< No specified reset flag is generated        */
    }
    return flag;
}

/**
*********************************************************************************************************
*                               CLEAR SPECIFIED RESET FLAG STATUS
*
* @brief: Clear specified reset flag
*
* @param: STAFlag    Some reset flag to clear,this parameter can be one of the following values:
*                       @arg PMU_RSTSTA           Clear all reset flags
*                       @arg PMU_RSTSTA_PORRST
*                       @arg PMU_RSTSTA_LBORRST
*                       @arg PMU_RSTSTA_WDTRST
*                       @arg PMU_RSTSTA_WakeupRST
*                       @arg PMU_RSTSTA_ExtRST
*                       @arg PMU_RSTSTA_SoftRST
*                       @arg PMU_RSTSTA_DebugRST
*                       @arg PMU_RSTSTA_BORRST
*                       @arg PMU_RSTSTA_SleepFlag
*                       @arg PMU_RSTSTA_HoldFlag
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_ResetFlagClear(uint32_t STAFlag)
{
    /*  assert_param  */
    HT_PMU->RSTSTA &= ~STAFlag;                     /*!< Clear specified reset flag          */
}

/**
*********************************************************************************************************
*                                     ENTER HOLD MODE
*
* @brief: Registers are configured to put the chip into HOLD low power mode
*
* @param: None
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_EnterHold(void)
{
    SCB->SCR = 0x0000U;
    __WFI();
}

/**
*********************************************************************************************************
*                                     ENTER SLEEP MODE
*
* @brief: Registers are configured to put the chip into SLEEP low power mode
*
* @param: None
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_EnterSleep(void)
{
    SCB->SCR = 0x0004U;
    __WFI();
}






