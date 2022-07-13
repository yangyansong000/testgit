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
* File         : HT6xxx_cmu.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_CMU_C

#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/
#define Wait2mS         (WaitPllLock)

#define HRCDIV_LOCATION     ((uint32_t)0x04)
#define DELAY_TIME_ADJUST   ((uint32_t)10)
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
static void WaitPllLock(void);
static void Wait2mS(void);

/**
*********************************************************************************************************
*                                         INITIAL CMU MODULE
*
* @brief: Initializes the CMU peripheral according to the specified
*         parameters in the CMU_InitStruct .
*
* @param: CMU_InitStruct: pointer to a CMU_InitTypeDef structure that contains the
*         configuration information for the specified CMU peripheral, which consists of 2 parameters:
*             1) SysClkSel : System clock source selection, which can be one of the following parameters
*                            a) SysLRC        LRC--->Fsys
*                            b) SysLF         LF---->Fsys
*                            c) SysHRCDiv1    HRCdiv1--->Fsys (If support)
*                            d) SysHRCDiv2    HRCdiv2--->Fsys (If support)
*                            e) SysHRCDiv4    HRCdiv4--->Fsys (If support)
*                            f) SysHRCDiv8    HRCdiv8--->Fsys (If support)
*                            g) SysPLL        PLL--->Fsys
*                            h) SysMEMS       Mems-->Fsys (If support)
*                            i) SysPLLX2      PLL--->Fsys (If support)
*             2) CPUDiv    : CPU clock division setting, Fcpu = Fsys/CPUDiv
*
* @retval: None
*
* @note: 1) The user should ensure that the write protection status of the register will not be modified
*           during the execution of this function
*        2) When using SysPLLX2, the "DELAY" function     (If support)
*                                 or "PREFETCH" function  (If support)
*                                 or "CACHE" function     (If support)
*           will be turned on by default
*        3) When the PLL is not selected as the SysPLLX2 clock, the following function
*                                    "DELAY" function     (If support)
*                                 or "PREFETCH" function  (If support)
*                                 or "CACHE" function     (If support)
*           will be turned off.
*           If you need to turn on above function,
*           please call the "HT_CMU_FlashDly_Set" function(If support)
*           or the "HT_CMU_Prefetch_Set" function(If support)
*           or the "HT_CMU_CTRL_2T_Set" function(If support)
*           or the "HT_CMU_CTRL_3T_Set" function(If support)
*           or the "HT_CMU_Cache_Set" function(If support)
*        4) For HT633x, if HRCCLKSEL select 33.03MHz and HRCDIV select Fhrc/1, the cache and flash fetch 2T
*           will be turn on
*           if system clock not PLLX2 or HRC(33MHz), the cache and flash fetch 2T 3T will be turn off
*           
*********************************************************************************************************
*/
void HT_CMU_Init(CMU_InitTypeDef* CMU_InitStruct)
{

    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< assert_param  */
    assert_param(IS_HT_CMU_SYSCLKSEL(CMU_InitStruct->SysClkSel));
    assert_param(IS_HT_CMU_CPUDIV(CMU_InitStruct->CPUDiv));

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;
#if  defined  USE_CMU_SYSCLKDIV_SEL40M
    if((CMU_InitStruct->SysClkSel & CMU_SYSCLKDIV_SEL40M)==CMU_SYSCLKDIV_SEL20M)
    {
        /*!< Select PLL 20M */
        CMU_InitStruct->CPUDiv &= (CPU_DivTypeDef)(~CMU_SYSCLKDIV_SEL40M);
    }
    else
    {
        /*!< Select PLLX2, 40M */
        CMU_InitStruct->CPUDiv |= (CPU_DivTypeDef)(CMU_SYSCLKDIV_SEL40M);
    }
#endif
    /*!< Set CPU clock division */
    HT_CMU->SYSCLKDIV = CMU_InitStruct->CPUDiv;

    /*!< Fpll ---> Fsys */
    if((CMU_InitStruct->SysClkSel & CMU_SYSCLKCFG_CLKSEL) == SysPLL)
    {
    #if  defined  USE_CMU_SYSCLKDIV_SEL40M
        if (CMU_InitStruct->SysClkSel & CMU_SYSCLKDIV_SEL40M)
        {
        #if  defined  USE_CMU_PREFETCH_ENABLE
            /*!< enable prefetch */
            HT_CMU->PREFETCH |= CMU_PREFETCH_ENABLE;
            
        #elif  defined  USE_CMU_PREFETCH_CACHE_EN
            /*!< enable cache */
            HT_CMU->PREFETCH |= CMU_PREFETCH_CACHE_EN;
            
        #elif  defined  USE_CMU_FLASHDLY_ENABLE
            /*!< enable flash delay */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_ENABLE;

        #elif defined USE_CMU_FLASHDLY_CACHE_EN
            /*!< enable cache */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_CACHE_EN;
        #endif
            
        #if  defined USE_CMU_PREFETCH_2T
            /*!< enable 2T */
            HT_CMU->PREFETCH |= CMU_PREFETCH_CTRL_2T;
        #endif
            
        #if defined USE_CMU_FLASHDLY_2T
            /*!< enable 2T */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_2T_EN;
        #endif
        }
    #endif
        
        /*!< enable PLL */
        HT_CMU->CLKCTRL0 |= CMU_CLKCTRL0_PLLEN;
        /*!< wait a certain time */
        WaitPllLock();
        /*!< Configure the PLL as the system clock */
        HT_CMU->SYSCLKCFG = (CMU_SYSCLKCFG_CLKSEL_PLL | CMU_SYSCLKCFG_WCLKEN);
    }
    /*!< Fhrc ---> Fsys */
    else if((CMU_InitStruct->SysClkSel & CMU_SYSCLKCFG_CLKSEL) == CMU_SYSCLKCFG_CLKSEL_HRC)
    {
    #if  defined  USE_CMU_HRCCLKSEL
        if (((HT_CMU->HRCCLKCFG & CMU_HRCCLKCFG_HRCCLKSEL) == CMU_HRCCLKCFG_HRCCLKSEL_10) && \
            ((HT_CMU->HRCDIV & CMU_HRCDIV) == CMU_HRCDIV_1))
        {
        #if  defined  USE_CMU_PREFETCH_ENABLE
            /*!< enable prefetch */
            HT_CMU->PREFETCH |= CMU_PREFETCH_ENABLE;
            
        #elif  defined  USE_CMU_PREFETCH_CACHE_EN
            /*!< enable cache */
            HT_CMU->PREFETCH |= CMU_PREFETCH_CACHE_EN;
            
        #elif  defined  USE_CMU_FLASHDLY_ENABLE
            /*!< enable flash delay */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_ENABLE;

        #elif defined USE_CMU_FLASHDLY_CACHE_EN
            /*!< enable cache */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_CACHE_EN;
        #endif
            
        #if  defined USE_CMU_PREFETCH_2T
            /*!< enable 2T */
            HT_CMU->PREFETCH |= CMU_PREFETCH_CTRL_2T;
        #endif
            
        #if defined USE_CMU_FLASHDLY_2T
            /*!< enable 2T */
            HT_CMU->FLASHDLY |= CMU_FLASHDLY_2T_EN;
        #endif
        }
    #endif
        /*!< enable HRC */
        HT_CMU->CLKCTRL0 |= CMU_CLKCTRL0_HRCEN;
    #if  defined  USE_CMU_HRCDIV
        /*!< Set HRC clock divider */
        HT_CMU->HRCDIV = (uint32_t)(CMU_InitStruct->SysClkSel)>>HRCDIV_LOCATION;
    #endif
        /*!< wait a certain time */
        WaitPllLock();
        /*!< Configure the HRC as the system clock */
        HT_CMU->SYSCLKCFG = (CMU_SYSCLKCFG_CLKSEL_HRC | CMU_SYSCLKCFG_WCLKEN);
    }
    /*!< Fsys = FLrc/FLf/Fmems */
    else
    {
        /*!< Configure the set clock as the system clock */
        HT_CMU->SYSCLKCFG = (CMU_InitStruct->SysClkSel | CMU_SYSCLKCFG_WCLKEN);
    }
#if  defined  USE_CMU_SYSCLKDIV_SEL40M
    if (!(CMU_InitStruct->SysClkSel & CMU_SYSCLKDIV_SEL40M))
    {
    #if  defined  USE_CMU_HRCCLKSEL
        if (((HT_CMU->HRCCLKCFG & CMU_HRCCLKCFG_HRCCLKSEL) == CMU_HRCCLKCFG_HRCCLKSEL_10) && \
            ((HT_CMU->HRCDIV & CMU_HRCDIV) == CMU_HRCDIV_1))
        {
            /*!< if sysclk= Fhrc = 33M, keep cache and 2T */
        }
        else
    #endif        
        {
            /*!< disable prefetch, cache, 2T, 3T */      
        #if  defined  USE_CMU_PREFETCH_ENABLE
            /*!< disable prefetch */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_ENABLE);
            
        #elif  defined  USE_CMU_PREFETCH_CACHE_EN
            /*!< disable cache */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_CACHE_EN);
            
        #elif  defined  USE_CMU_FLASHDLY_ENABLE
            /*!< disable flash delay */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_ENABLE);

        #elif defined USE_CMU_FLASHDLY_2T
            /*!< disable 2T */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_2T_EN);
        #endif
            
        #if  defined USE_CMU_PREFETCH_2T
            /*!< disable 2T */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_CTRL_2T);
        #endif

        #if  defined  USE_CMU_PREFETCH_3T
            /*!< disable 3T */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_3T_EN);
        #endif
            
        #if  defined  USE_CMU_FLASHDLY_CACHE_EN
            /*!< disable cache */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_CACHE_EN);
        #endif
            
        #if defined USE_CMU_FLASHDLY_3T
            /*!< disable 3T */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_3T_EN);
        #endif
        }
    }
#endif

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}

/**
*********************************************************************************************************
*                                     GET FSYS CLOCK FREQUENCY
*
* @brief: Get the system clock frequency(ie Fsys, not Fcpu), and return the frequency in Hz
*
* @param: None
*
* @retval: sysclk: system clock frequency(Fsys), 32-bit unsigned number in Hz
*
* @note: If the system clock is a high-frequency RC or a low-frequency RC,
*        the clock frequency returned will not be completely accurate.
*        For high frequency RC, there will be an error of about 2%.
*        For low frequency RC, there will be an error of more than 10%
*********************************************************************************************************
*/
uint32_t HT_CMU_SysClkGet(void)
{
    /*!< assert_param */
    uint32_t sysclk, clksel;

    clksel = HT_CMU->SYSCLKCFG & CMU_SYSCLKCFG_CLKSEL;

    switch(clksel)
    {
        /*!< system clock source is LRC */
        case CMU_SYSCLKCFG_CLKSEL_LRC:
        /*!< system clock source is LF */
        case CMU_SYSCLKCFG_CLKSEL_LF:
             sysclk = OSC_FREQUENCY;
        break;

        /*!< system clock source is HRC */
        case CMU_SYSCLKCFG_CLKSEL_HRC:
            sysclk = HRC_FREQUENCY;
        #if defined  USE_CMU_HRCCLKSEL
            switch(HT_CMU->HRCCLKCFG & CMU_HRCCLKCFG_HRCCLKSEL)
            {
                case CMU_HRCCLKCFG_HRCCLKSEL_00:
                    sysclk = HRC_FREQUENCY_00;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_01:
                    sysclk = HRC_FREQUENCY_01;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_10:
                    sysclk = HRC_FREQUENCY_10;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_11:
                    sysclk = HRC_FREQUENCY_11;
                    break;
                default:
                    break;
            }
        #endif
        #if defined  USE_CMU_HRCDIV
            sysclk = sysclk>>(HT_CMU->HRCDIV & CMU_HRCDIV );
        #endif
            
        break;

        /*!< system clock source is PLL */
        case CMU_SYSCLKCFG_CLKSEL_PLL:
        #if  defined  USE_CMU_SYSCLKDIV_SEL40M
            if((HT_CMU->SYSCLKDIV & CMU_SYSCLKDIV_SEL40M))
            {
            #if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
                sysclk = OSC_FREQUENCY * (uint32_t)(CPLL_0_FACTOR+(int32_t)(HT_CMU->C_PLL & CMU_C_PLL_CPLL)*CPLL_STEP) * 2U;
            #else
                sysclk =  (uint32_t)(OSC_FREQUENCY*PLLX2_FACTOR);
            #endif
            }
            else
            {
            #if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
                sysclk = OSC_FREQUENCY * (uint32_t)(CPLL_0_FACTOR+(int32_t)(HT_CMU->C_PLL & CMU_C_PLL_CPLL)*CPLL_STEP);
            #else
                sysclk =  (uint32_t)(OSC_FREQUENCY*PLL_FACTOR);
            #endif            
            }
        #else
            sysclk = (uint32_t)(OSC_FREQUENCY*PLL_FACTOR);
        #endif
        break;

        default:
#if defined  USE_CMU_SYSCLKCFG_MEMS
            /*!< system clock source is Mems */
            sysclk = MEMS_FREQUENCY;
#else
            /*!< system clock source is abnormal */
            sysclk = 0U;
#endif
        break;
    }

    /*!< return system clock frequency */
    return sysclk;
}

/**
*********************************************************************************************************
*                                     GET CPU CLOCK FREQUENCY
*
* @brief: Get the CPU clock frequency and return the frequency value in Hz
*
* @param: None
*
* @retval: cpuclk: CPU clock frequency(Fcpu), 32-bit unsigned number in Hz
*
* @note: If the system clock is a high-frequency RC or a low-frequency RC,
*        the clock frequency returned will not be completely accurate.
*        For high frequency RC, there will be an error of about 2%.
*        For low frequency RC, there will be an error of more than 10%
*********************************************************************************************************
*/
uint32_t HT_CMU_CPUClkGet(void)
{
    /*!< assert_param */
    uint32_t cpuclk, clksel, cpuclkdiv;

    clksel = HT_CMU->SYSCLKCFG & CMU_SYSCLKCFG_CLKSEL;
    /*!< Get CPU clock divider */
    cpuclkdiv = HT_CMU->SYSCLKDIV & CMU_SYSCLKDIV;

    switch(clksel)
    {
        /*!< system clock source is LRC */
        case CMU_SYSCLKCFG_CLKSEL_LRC:
        /*!< system clock source is LF */
        case CMU_SYSCLKCFG_CLKSEL_LF:
            cpuclk = OSC_FREQUENCY;
        break;

        case CMU_SYSCLKCFG_CLKSEL_HRC:
            cpuclk = HRC_FREQUENCY;
        #if defined  USE_CMU_HRCCLKSEL
            switch(HT_CMU->HRCCLKCFG & CMU_HRCCLKCFG_HRCCLKSEL)
            {
                case CMU_HRCCLKCFG_HRCCLKSEL_00:
                    cpuclk = HRC_FREQUENCY_00;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_01:
                    cpuclk = HRC_FREQUENCY_01;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_10:
                    cpuclk = HRC_FREQUENCY_10;
                    break;
                case CMU_HRCCLKCFG_HRCCLKSEL_11:
                    cpuclk = HRC_FREQUENCY_11;
                    break;
                default:
                    break;
            }        
        #endif
        #if defined  USE_CMU_HRCDIV
            cpuclk = cpuclk>>(HT_CMU->HRCDIV & CMU_HRCDIV );
        #endif
            
        break;

        /*!< system clock source is PLL */
        case CMU_SYSCLKCFG_CLKSEL_PLL:
        #if  defined  USE_CMU_SYSCLKDIV_SEL40M
            if((HT_CMU->SYSCLKDIV & CMU_SYSCLKDIV_SEL40M))
            {
            #if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
                cpuclk = OSC_FREQUENCY * (uint32_t)(CPLL_0_FACTOR+(int32_t)(HT_CMU->C_PLL & CMU_C_PLL_CPLL)*CPLL_STEP) * 2U;
            #else
                cpuclk =  (uint32_t)(OSC_FREQUENCY*PLLX2_FACTOR);
            #endif
            }
            else
            {
            #if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
                cpuclk = OSC_FREQUENCY * (uint32_t)(CPLL_0_FACTOR+(int32_t)(HT_CMU->C_PLL & CMU_C_PLL_CPLL)*CPLL_STEP);
            #else
                cpuclk =  (uint32_t)(OSC_FREQUENCY*PLL_FACTOR);
            #endif  
            }
        #else
            cpuclk = (uint32_t)(OSC_FREQUENCY*PLL_FACTOR);
        #endif
        break;

        default:
#if defined  USE_CMU_SYSCLKCFG_MEMS
            /*!< system clock source is Mems */
            cpuclk = MEMS_FREQUENCY;
#else
            /*!< system clock source is abnormal */
            cpuclk = 0U;
#endif
        break;
    }
    /*!< Substitute into cpu clock divider */
    cpuclk >>= cpuclkdiv;
    /*!< return cpu clock frequency */
    return cpuclk;
}

/**
*********************************************************************************************************
*                                  SET CLKOUT TO SPECIFIC FREQUENCY
*
* @brief: Set clkout to specific frequency
*
* @param: Clkout_InitTypeDef: pointer to a Clkout_InitTypeDef structure that contains
*         the configuration information for the clkout, which consists of 2 parameters:
*             1) ClkoutSel : Source of clkout, which can be one of the following parameters:
*                            a) ClkoutFLRC    LRC--->Clkout
*                            b) ClkoutFLF     LF---->Clkout
*                            c) ClkoutFHRC    HRC--->Clkout
*                            d) ClkoutFSys    SYS--->Clkout
*                            e) ClkoutFMEMS   Mems-->Clkout (for HT6x1x)
*                            f) ClkoutFPLL    PLL -->Clkout (for HT6x2x verH, HT6x3x)
*             2) ClkoutDiv : Clkout division setting,
*                            the frequency division factor is: 2*(ClkoutDiv[3:0]+1)
*
* @retval: None
*
* @note: The user should ensure that the write protection status of the register will not be modified
*********************************************************************************************************
*/
void HT_CMU_ClkoutSet(Clkout_InitTypeDef* Clkout_InitStruct)
{
    /*!< assert_param */
    assert_param(IS_HT_CMU_CLKOUTSEL(Clkout_InitStruct->ClkoutSel));
    assert_param(IS_HT_CMU_CLKOUTDIV(Clkout_InitStruct->ClkoutDiv));

    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    /*!< Set clock source of clkout  */
    HT_CMU->CLKOUTSEL = Clkout_InitStruct->ClkoutSel;

    /*!< Set divider of clkout */
    HT_CMU->CLKOUTDIV = Clkout_InitStruct->ClkoutDiv & CMU_CLKOUTDIV;

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}

/**
*********************************************************************************************************
*                                  SET PLL FREQUENCY
*
* @brief: Set PLL frequency
*
* @param: CPLL_ValTypeDef: C_PLL module initialization structure pointer, which consists of 1 parameters:
*                          1) pllVal : Set PLL frequency, can be one of the following parameters
*                                 for HT6x3x:
*                                 @arg CPLL39M
*                                 @arg CPLL40M
*                                 @arg CPLL41M
*                                 @arg CPLL42M
*                                 @arg CPLL44M
*                                 @arg CPLL45M
*                                 @arg CPLL46M
*                                 @arg CPLL47M
*                                 or
*                                 for HT633x
*                                 @arg CPLL0 
*                                 @arg CPLL1 
*                                 @arg CPLL2 
*                                 @arg CPLL3 
*                                 @arg CPLL4 
*                                 @arg CPLL5 
*                                 @arg CPLL6 
*                                 @arg CPLL7 
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
void HT_CMU_CPllSet(CPLL_ValTypeDef pllVal)
{
    /*!< assert_param */
    assert_param(IS_HT_CMU_C_PLL(pllVal));

    /*!< Set C_PLL value */
    HT_CMU->C_PLL = ((pllVal | CMU_C_PLL_WRPEG) & CMU_C_PLL);
}
#endif

/**
*********************************************************************************************************
*                                  CONFIGUE CLKCTRL0 REGISTER
*
* @brief: Configure clkctrl0 register, enable or disable
*
* @param: ClkCtrl0Module: The CLKCTRL0 register module control bit,
*                         can be the following parameters or their combination:
*                               @arg  CMU_CLKCTRL0               Configure all control bits
*                               @arg  CMU_CLKCTRL0_LCD_PMU_FSEL  (If support)
*                               @arg  CMU_CLKCTRL0_LCDEN         (If support)
*                               @arg  CMU_CLKCTRL0_SPI0EN
*                               @arg  CMU_CLKCTRL0_I2CEN
*                               @arg  CMU_CLKCTRL0_PLLEN
*                               @arg  CMU_CLKCTRL0_HRCEN
*                               @arg  CMU_CLKCTRL0_PLLLOCKEN     (If support)
*                               @arg  CMU_CLKCTRL0_LFDETEN
*                               @arg  CMU_CLKCTRL0_PLLDETEN
*                               @arg  CMU_CLKCTRL0_HRCDETEN
*                               @arg  CMU_CLKCTRL0_OSC_SLP       (If support)
*                               @arg  CMU_CLKCTRL0_WDTEN         (If support)
*                               @arg  CMU_CLKCTRL0_KEYEN         (If support)
*                               @arg  CMU_CLKCTRL0_CLKOUTEN
*                               @arg  CMU_CLKCTRL0_1P5LBOREN
*                               @arg  CMU_CLKCTRL0_3DESRADEN     (If support)
*                               @arg  CMU_CLKCTRL0_ADESRADEN / CMU_CLKCTRL0_AESEN (If support)
*                               @arg  CMU_CLKCTRL0_ARGEN         (If support)
*                               @arg  CMU_CLKCTRL0_CRCEN         (If support)
*                               @arg  CMU_CLKCTRL0_EMUEN         (If support)
*                               @arg  CMU_CLKCTRL0_ECCEN         (If support)
*                               @arg  CMU_CLKCTRL0_CMU_NEWREG_EN (If support)
*                               @arg  CMU_CLKCTRL0_SEL_PLLN_HRC  (If support)
*
* @param: NewState              @arg  ENABLE     Enable the corresponding module
*                               @arg  DISABLE    Disable the corresponding module
*
* @retval: None
*
* @note: 1) The user should ensure that the write protection status of the register will not be modified
*        2) Any operation involving clock enable will concern startup time, so it is not recommended
*           to execute in this function, but you can turn off the corresponding clock
*        3) HT502x, HT6x2x, HT6x3x, HT503x: Turn on the HRC clock while turning on the AES/ARG module
*        4) HT502x, HT6x2x, HT6x3x: Turn off the AES/ARG module while turning off the HRC clock
*********************************************************************************************************
*/
void HT_CMU_ClkCtrl0Config(uint32_t ClkCtrl0Module, FunctionalState NewState)
{
    /*!< assert_param */

    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    ClkCtrl0Module &= CMU_CLKCTRL0;

    if (NewState != DISABLE)
    {
#if  defined  USE_CMU_CLKCTRL0_ARGEN_RAND_OPEN
        if (ClkCtrl0Module & CMU_CLKCTRL0_ARGEN)
        {
            /*!< Turn on the HRC clock while turning on the AES/ARG module */
            ClkCtrl0Module |= CMU_CLKCTRL0_HRCEN;
        }
#elif  defined  USE_CMU_CLKCTRL0_AESEN_RAND_OPEN
        if (ClkCtrl0Module & CMU_CLKCTRL0_AESEN)
        {
            /*!< Turn on the HRC clock while turning on the AES/ARG module */
            ClkCtrl0Module |= CMU_CLKCTRL0_HRCEN;
        }
#endif
        /*!< Enable the corresponding module in CLKCTRL0 */
        HT_CMU->CLKCTRL0 |= ClkCtrl0Module;
    }
    else
    {
#if defined USE_CMU_CLKCTRL0_1P5_OSC_GRP1
        /*!< bit6 is reserved as 1 */
        ClkCtrl0Module &= ~CMU_CLKCTRL0_Reserved;
#elif  defined  USE_CMU_CLKCTRL0_1P5_OSC_GRP2
        /*!< bit13 and bit10 are forced to 1 */
        ClkCtrl0Module &= (~(CMU_CLKCTRL0_1P5LBOREN | CMU_CLKCTRL0_OSC_SLP_LOWPOWER));

#elif  defined  USE_CMU_CLKCTRL0_1P5_OSC_GRP3
        /*!< bit13 forced to 1 */
        ClkCtrl0Module &= (~(CMU_CLKCTRL0_1P5LBOREN));
#endif
        if (ClkCtrl0Module & CMU_CLKCTRL0_PLLEN) /*!< close PLL */
        {
#if  defined  USE_CMU_TBSCLK_GRP1
            /*!< TBS clock source is PLL, force the TBS clock source to be switched to OSC */
            HT_TBS->TBSCON &= (~TBS_TBSCON_TBSCLKSEL);
            HT_TBS->TBSCON |= (TBS_TBSCON_TBSCLKSEL_OSC);
#elif  defined  USE_CMU_TBSCLK_GRP2
            if(((HT_TBS->TBSCON & TBS_TBSCON_TBSCLKSEL)==TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10) || \
               ((HT_TBS->TBSCON & TBS_TBSCON_TBSCLKSEL)==TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11))
            {
                /*!< TBS clock source is PLL, force the TBS clock source to be switched to OSC */
                HT_TBS->TBSCON &= (~TBS_TBSCON_TBSCLKSEL);
                HT_TBS->TBSCON |= (TBS_TBSCON_TBSCLKSEL_OSC);
            }
#elif  defined  USE_CMU_TBSCLK_GRP3
            if(((HT_CMU->LFCLKCFG & CMU_LFCLKCFG_TBSLFSEL) == CMU_LFCLKCFG_TBSLFSEL_TBSCLKSEL) && \
               ((HT_TBS->TBSCON & TBS_TBSCON_TBSCLKSEL) == TBS_TBSCON_TBSCLKSEL_PLLDIV))
            {
                /*!< TBS clock source is PLL, force the TBS clock source to be switched to OSC */
                HT_CMU->LFCLKCFG &= ~CMU_LFCLKCFG_TBSLFSEL;
                HT_TBS->TBSCON &= (~TBS_TBSCON_TBSCLKSEL);
                HT_TBS->TBSCON |= (TBS_TBSCON_TBSCLKSEL_OSC);
            }
#elif  defined  USE_CMU_TBSCLK_GRP4
            if(((HT_CMU->TBSCLKCFG & CMU_TBSCLKCFG_HSTBSCLKSEL) == CMU_TBSCLKCFG_HSTBSCLKSEL_PLLX2) && \
               (((HT_TBS->TBSCON & TBS_TBSCON_TBSCLKSEL) == TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10) || \
                ((HT_TBS->TBSCON & TBS_TBSCON_TBSCLKSEL) == TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11)))
            {
                /*!< TBS clock source is PLL, force the TBS clock source to be switched to OSC */
                HT_TBS->TBSCON &= (~TBS_TBSCON_TBSCLKSEL);
                HT_TBS->TBSCON |= (TBS_TBSCON_TBSCLKSEL_OSC);
            }
#endif
        }
#if  defined  USE_CMU_CLKCTRL0_ARGEN_RAND_CLOSE
        if (ClkCtrl0Module & CMU_CLKCTRL0_HRCEN)
        {
            /*!< Turn off the AES/ARG module while turning off the HRC clock */
            ClkCtrl0Module |= CMU_CLKCTRL0_ARGEN;
        }
#elif  defined  USE_CMU_CLKCTRL0_AESEN_RAND_CLOSE
        if (ClkCtrl0Module & CMU_CLKCTRL0_HRCEN)
        {
            /*!< Turn off the AES/ARG module while turning off the HRC clock */
            ClkCtrl0Module |= CMU_CLKCTRL0_AESEN;
        }
#endif
        /*!< Disable the corresponding module in CLKCTRL0 */
        HT_CMU->CLKCTRL0 &= ~ClkCtrl0Module;

        if (ClkCtrl0Module & CMU_CLKCTRL0_PLLEN) /*!< Change flash configuration when turning off PLL */
        {
#if  defined  USE_CMU_PREFETCH_ENABLE
            /*!< close prefetch */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_ENABLE);
#elif  defined  USE_CMU_PREFETCH_CACHE_EN
            /*!< close cache */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_CACHE_EN);
#elif  defined  USE_CMU_FLASHDLY_ENABLE
            /*!< close flash delay */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_ENABLE);
#elif  defined  USE_CMU_FLASHDLY_2T
            /*!< close 2T */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_2T_EN);
#endif

#if  defined  USE_CMU_PREFETCH_2T
            /*!< close 2T delay */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_CTRL_2T);
#endif

#if  defined  USE_CMU_PREFETCH_3T
            /*!< close 3T delay */
            HT_CMU->PREFETCH &= (~CMU_PREFETCH_3T_EN);
#endif

#if  defined  USE_CMU_FLASHDLY_CACHE_EN
            /*!< close cache */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_CACHE_EN);
#endif

#if  defined  USE_CMU_FLASHDLY_3T
            /*!< close 3T */
            HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_3T_EN);
#endif
        }
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}

/**
*********************************************************************************************************
*                                  CONFIGUE CLKCTRL1 REGISTER
*
* @brief: Configure clkctrl1 register, enable or disable
*
* @param: ClkCtrl1Module : The CLKCTRL1 register module control bit,
*                          can be the following parameters or their combination:
*                               @arg  CMU_CLKCTRL1                Configure all control bits
*                               @arg  CMU_CLKCTRL1_TMR0EN
*                               @arg  CMU_CLKCTRL1_TMR1EN
*                               @arg  CMU_CLKCTRL1_TMR2EN
*                               @arg  CMU_CLKCTRL1_TMR3EN
*                               @arg  CMU_CLKCTRL1_UART0EN
*                               @arg  CMU_CLKCTRL1_UART1EN
*                               @arg  CMU_CLKCTRL1_UART2EN
*                               @arg  CMU_CLKCTRL1_UART3_7816_1EN
*                               @arg  CMU_CLKCTRL1_UART4_7816_0EN
*                               @arg  CMU_CLKCTRL1_UART5EN
*                               @arg  CMU_CLKCTRL1_TMR4EN         (If support)
*                               @arg  CMU_CLKCTRL1_TMR5EN         (If support)
*                               @arg  CMU_CLKCTRL1_UART6EN        (If support)
*                               @arg  CMU_CLKCTRL1_SPI1EN         (If support)
*                               @arg  CMU_CLKCTRL1_SOFTWDTEN      (If support)
*                               @arg  CMU_CLKCTRL1_LRCRTC2EN      (If support)
*                               @arg  CMU_CLKCTRL1_LRCTFREQEN     (If support)
*                               @arg  CMU_CLKCTRL1_LRCRTCEN       (If support)
*                               @arg  CMU_CLKCTRL1_AUTORCCAL_EN   (If support)
*                               @arg  CMU_CLKCTRL1_SPI3EN         (If support)
*                               @arg  CMU_CLKCTRL1_RCADJEN        (If support)
*                               @arg  CMU_CLKCTRL1_ECCEN          (If support)
*                               @arg  CMU_CLKCTRL1_EMUEN          (If support)
*                               @arg  CMU_CLKCTRL1_SPI2EN         (If support)
*                               @arg  CMU_CLKCTRL1_LPUARTEN       (If support)
*                               @arg  CMU_CLKCTRL1_EMUCLKSRC      (If support)
*                               @arg  CMU_CLKCTRL1_EMUIFACEEN     (If support)
*                               @arg  CMU_CLKCTRL1_FFTEN          (If support)
*                               @arg  CMU_CLKCTRL1_PACKEN         (If support)
*
* @param: NewState       :
*                               @arg  ENABLE     Enable the corresponding module
*                               @arg  DISABLE    Disable the corresponding module
*
* @retval: None
*
* @note: 1) The user should ensure that the write protection status of the register will not be modified
*********************************************************************************************************
*/
void HT_CMU_ClkCtrl1Config(uint32_t ClkCtrl1Module, FunctionalState NewState)
{
    /*!< assert_param */

    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    ClkCtrl1Module &= CMU_CLKCTRL1;

    if (NewState != DISABLE)
    {
        /*!< Enable the corresponding module in CLKCTRL1 */
        HT_CMU->CLKCTRL1 |= ClkCtrl1Module;
    }
    else
    {
        /*!< Disable the corresponding module in CLKCTRL1 */
        HT_CMU->CLKCTRL1 &= ~ClkCtrl1Module;
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}

/**
*********************************************************************************************************
*                                      GET JTAG STATUS
*
* @brief: Get JTAG status
*
* @param: None
*
* @retval: Bool
*              @arg TRUE       The chip is in debug state
*              @arg FALSE      The chip is in normal state
*
* @note: None
*********************************************************************************************************
*/
Bool HT_CMU_JTAGStatusGet(void)
{
    /*!< assert_param */

#if defined  USE_CMU_JTAGSTA
    return ((HT_CMU->JTAGSTA & CMU_JTAGSTA_FLAG_SW) ? TRUE : FALSE);
#else
    return FALSE;
#endif
}

/**
*********************************************************************************************************
*                                      GET CHIP ID
*
* @brief: Get chipid
*
* @param: None
*
* @retval: chipid
*
* @note: None
*********************************************************************************************************
*/
uint32_t HT_CMU_ChipIDGet(void)
{
    /*!< assert_param */
#if  defined  USE_CMU_CHIPID
    return (HT_CMU->CHIPID & CMU_CHIPID);
#else
    return  0x0000U;
#endif
}


/**
*********************************************************************************************************
*                            GET SPECIFIED CLOCK STOP FLAG
*
* @brief: Get specified clock stop flag
*
* @param: STAFlag: The clock stop flag that you want to check, can be the one of the following parameters
*                        @arg CMU_CLKSTA_LFFLAG
*                        @arg CMU_CLKSTA_HRCFLAG
*                        @arg CMU_CLKSTA_PLLFLAG
*
* @retval: FlagStatus
*                        @arg SET    The clock is stop
*                        @arg RESET  The clock is normal
*
* @note: The user should turn on the clock stop detection enable bit to get a valid flag,
*        reference HT_CMU_ClkCtrl0Config()
*********************************************************************************************************
*/
FlagStatus HT_CMU_StopFlagGet(uint32_t STAFlag)
{
    FlagStatus state;

    /*!< assert_param */
    assert_param(IS_HT_CMU_STA_FLAG(STAFlag));


    if (HT_CMU->CLKSTA & STAFlag)
    {
        /*!< Clock Stop Flag is set */
        state = SET;
    }
    else
    {
        /*!< Clock Stop Flag is reset */
        state = RESET;
    }
    return state;
}

/**
*********************************************************************************************************
*                            Flash delay set
*
* @brief: Flash delay set
*
* @param: NewState
*                       @arg ENABLE     Enable the corresponding module
*                       @arg DISABLE    Disable the corresponding module
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_FLASHDLY_ENABLE
void  HT_CMU_FlashDly_Set(FunctionalState NewState)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    if (NewState != DISABLE)
    {
        /*!< enable flash delay */
        HT_CMU->FLASHDLY |= CMU_FLASHDLY_ENABLE;
    }
    else
    {
        /*!< disable flash delay */
        HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_ENABLE);
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif

/**
*********************************************************************************************************
*                            Flash prefetch set
*
* @brief: Set prefetch
*
* @param: NewState
*                    @arg ENABLE    enable prefetch
*                    @arg DISABLE   disable prefetch
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_PREFETCH_ENABLE  ||  defined  HT6x3x
void  HT_CMU_Prefetch_Set(FunctionalState NewState)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    if (NewState != DISABLE)
    {
    #if  defined  USE_CMU_PREFETCH_ENABLE
        /*!< enable prefetch */
        HT_CMU->PREFETCH |= CMU_PREFETCH_ENABLE;
    #elif  defined  HT6x3x
        /*!< enable cache */
        HT_CMU->PREFETCH |= CMU_PREFETCH_CACHE_EN;
    #endif
    }
    else
    {
    #if  defined  USE_CMU_PREFETCH_ENABLE
        /*!< disable prefetch */
        HT_CMU->PREFETCH &= (~CMU_PREFETCH_ENABLE);
    #elif  defined  HT6x3x
        /*!< disable cache */
        HT_CMU->PREFETCH &= (~CMU_PREFETCH_CACHE_EN);
    #endif
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif

/**
*********************************************************************************************************
*                            Flash cache set
*
* @brief: Set cache
*
* @param: NewState
*                    @arg ENABLE    enable cache
*                    @arg DISABLE   disable cache
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_PREFETCH_CACHE_EN  ||  defined  USE_CMU_FLASHDLY_CACHE_EN
void  HT_CMU_Cache_Set(FunctionalState NewState)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    if (NewState != DISABLE)
    {
    #if  defined  USE_CMU_PREFETCH_CACHE_EN
        /*!< enable cache */
        HT_CMU->PREFETCH |= CMU_PREFETCH_CACHE_EN;
    #elif  defined  USE_CMU_FLASHDLY_CACHE_EN
        /*!< enable cache */
        HT_CMU->FLASHDLY |= CMU_FLASHDLY_CACHE_EN;
    #endif
    }
    else
    {
    #if  defined  USE_CMU_PREFETCH_CACHE_EN
        /*!< disable cache */
        HT_CMU->PREFETCH &= (~CMU_PREFETCH_CACHE_EN);
    #elif  defined  USE_CMU_FLASHDLY_CACHE_EN
        /*!< disable cache */
        HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_CACHE_EN);
    #endif
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif

/**
*********************************************************************************************************
*                            Flash Ctrl 2T set
*
* @brief: flash delay set to 2T
*
* @param: NewState
*                    @arg ENABLE     Enable 2T
*                    @arg DISABLE    Disable 2T
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_PREFETCH_2T  ||  defined  USE_CMU_FLASHDLY_2T
void  HT_CMU_CTRL_2T_Set(FunctionalState NewState)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    if (NewState != DISABLE)
    {
        /*!< enable 2T */
        #if  defined  USE_CMU_PREFETCH_2T
        HT_CMU->PREFETCH |= CMU_PREFETCH_CTRL_2T;
        #else
        HT_CMU->FLASHDLY |= CMU_FLASHDLY_2T_EN;
        #endif
    }
    else
    {
        /*!< disable 2T */
        #if  defined  USE_CMU_PREFETCH_2T
        HT_CMU->PREFETCH &= (~CMU_PREFETCH_CTRL_2T);
        #else
        HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_2T_EN);
        #endif
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif


/**
*********************************************************************************************************
*                            Flash Ctrl 3T set
*
* @brief: flash delay set to 3T
*
* @param: NewState
*                     @arg ENABLE    Enable 3T
*                     @arg DISABLE   Disable 3T
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_PREFETCH_3T ||  defined USE_CMU_FLASHDLY_3T
void  HT_CMU_CTRL_3T_Set(FunctionalState NewState)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    if (NewState != DISABLE)
    {
        /*!< enable 3T */
        #if  defined  USE_CMU_PREFETCH_3T
        HT_CMU->PREFETCH |= CMU_PREFETCH_3T_EN;
        #else        
        HT_CMU->FLASHDLY |= CMU_FLASHDLY_3T_EN;
        #endif
    }
    else
    {
        /*!< disable 3T */
        #if  defined  USE_CMU_PREFETCH_3T
        HT_CMU->PREFETCH &= (~CMU_PREFETCH_3T_EN);
        #else
        HT_CMU->FLASHDLY &= (~CMU_FLASHDLY_3T_EN);
        #endif
    }

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif

/**
*********************************************************************************************************
*                            Flash latency set
*
* @brief: set flash latency
*
* @param: LATENCY_ValTypeDef
*                     @arg CMU_PREFETCH_LATENCY_0
*                     @arg CMU_PREFETCH_LATENCY_1
*                     @arg CMU_PREFETCH_LATENCY_2
*                     @arg CMU_PREFETCH_LATENCY_3
*                     @arg CMU_PREFETCH_LATENCY_4
*                     @arg CMU_PREFETCH_LATENCY_5
*                     @arg CMU_PREFETCH_LATENCY_6
*                     @arg CMU_PREFETCH_LATENCY_7
*
* @retval: None
*
* @note: None
*********************************************************************************************************
*/
#if  defined  USE_CMU_PREFETCH_LATENCY
void  HT_CMU_FLASH_LATENCY_Set(LATENCY_ValTypeDef Latency)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< assert_param */
    assert_param(IS_HT_CMU_LATENCY(Latency));
    
    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;

    /*!< set flash latency */    
    HT_CMU->PREFETCH &= ~CMU_PREFETCH_LATENCY;    
    HT_CMU->PREFETCH |= Latency;

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif

/**
*********************************************************************************************************
*                                     Wait For PLL
*
* @brief: Delay function waiting for PLL to stabilize. This function is an internal function
*
* @param: None
*
* @retval: None
*
* @note: The delay time is a rough time and cannot be used as a standard 2ms
*********************************************************************************************************
*/
static void WaitPllLock(void)
{
    uint32_t delay;

    /*!< Get current system clock */
    delay = HT_CMU_SysClkGet();
    /*!< Get current CPU clock */
    delay = delay>>(HT_CMU->SYSCLKDIV & CMU_SYSCLKDIV);
    /*!< 500 X 2 */
    delay = delay>>DELAY_TIME_ADJUST;

    /*!< wait 2ms */
    while(delay--){}
}

/**
*********************************************************************************************************
*                            HRC clock configuration
*
* @brief: configure hrc clock
*
* @param: HRC_InitStruct: 
*             1) HRCClk : HRC clock source frequency
*                            a) HRCClk0 (11.01MHz)
*                            b) HRCClk1 (22.02MHz)
*                            c) HRCClk2 (33.03MHz)
*                            d) HRCClk3 (8MHz)
*
*             2) HRCDiv : HRC clock divider
*                            a) HRCDiv1
*                            b) HRCDiv2
*                            c) HRCDiv4
*                            d) HRCDiv8
*
*
* @retval: None
*
* @note: If system clock is hrc, and HRCDiv1, and HRCClk = 33.03MHz, the cache and 2T will be turn on.
*********************************************************************************************************
*/
#if  defined  USE_CMU_HRCCLKSEL
void  HT_CMU_HRCCLK_Set(HRCCLK_InitTypeDef* HRC_InitStruct)
{
    /*!< Save the current write protection status */
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];

    /*!< assert_param */
    assert_param(IS_HT_CMU_HRCCLKSEL(HRC_InitStruct->HRCClk));
    assert_param(IS_HT_CMU_HRCDIV(HRC_InitStruct->HRCDiv));    
    
    /*!< Turn off write protection */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;
    
    if (((HT_CMU->SYSCLKCFG & CMU_SYSCLKCFG_CLKSEL) == CMU_SYSCLKCFG_CLKSEL_HRC)   && \
        ((HRC_InitStruct->HRCClk & CMU_HRCCLKCFG_HRCCLKSEL) == CMU_HRCCLKCFG_HRCCLKSEL_10) && \
        ((HRC_InitStruct->HRCDiv & CMU_HRCDIV)) == CMU_HRCDIV_1)
    {        
        /*!< if hrc is sysclk and hrc is 33MHz, turn on cache and 2T*/
        /*!< enable cache */
        HT_CMU->PREFETCH |= CMU_PREFETCH_CACHE_EN;
        /*!< enable 2T */
        HT_CMU->PREFETCH |= CMU_PREFETCH_CTRL_2T;
    }
    
    HT_CMU->HRCCLKCFG &= ~CMU_HRCCLKCFG_HRCCLKSEL;
    HT_CMU->HRCCLKCFG |= HRC_InitStruct->HRCClk;
    
    HT_CMU->HRCDIV &= ~CMU_HRCDIV;
    HT_CMU->HRCDIV |=  HRC_InitStruct->HRCDiv;

    /*!< Restore the previous write protection settings */
    HT_CMU->WPREG = writeProtect;
}
#endif
