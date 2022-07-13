/*
*********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_cmu.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_CMU_H__
#define __HT6XXX_CMU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

/**
* @brief  system clock source selection definition
*/
typedef enum
{
    SysLRC     = CMU_SYSCLKCFG_CLKSEL_LRC,                        /*!< Fsys = internal low frequency RC      */
    SysLF      = CMU_SYSCLKCFG_CLKSEL_LF,                         /*!< Fsys = external oscillator or mems/16 */
#if  defined  USE_CMU_HRCDIV
    SysHRCDiv1 = (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_1<<4)),    /*!< Fsys = internal high frequency RC /1  */
    SysHRCDiv2 = (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_2<<4)),    /*!< Fsys = internal high frequency RC /2  */
    SysHRCDiv4 = (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_4<<4)),    /*!< Fsys = internal high frequency RC /4  */
    SysHRCDiv8 = (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_8<<4)),    /*!< Fsys = internal high frequency RC /8  */
#else
    SysHRCDiv1 = CMU_SYSCLKCFG_CLKSEL_HRC,                        /*!< Fsys = internal high frequency RC /1  */
#endif
    SysPLL     = CMU_SYSCLKCFG_CLKSEL_PLL,                        /*!< Fsys = internal PLL clock             */
#if  defined  USE_CMU_SYSCLKCFG_MEMS
    SysMEMS    = CMU_SYSCLKCFG_CLKSEL_MEMS,                       /*!< Fsys = internal mems clock            */
#endif
#if  defined  USE_CMU_SYSCLKDIV_SEL40M
    SysPLLX2   = (CMU_SYSCLKCFG_CLKSEL_PLL|CMU_SYSCLKDIV_SEL40M), /*!< Fsys = internal PLL clock X2          */
#endif
}SYSCLK_SelectTypeDef;                                            /*!< end of group SYSCLK_SelectTypeDef     */

/**
* @brief  Clkout source selection definition
*/
typedef enum
{
    ClkoutFLRC = CMU_CLKOUTSEL_LRC,     /*!< internal low frequency RC ---> Clkout  */
    ClkoutFLF  = CMU_CLKOUTSEL_LF,      /*!< osc or mems/16 ---> Clkout             */
    ClkoutFHRC = CMU_CLKOUTSEL_HRC,     /*!< external high frequency RC ---> Clkout */
    ClkoutFSys = CMU_CLKOUTSEL_SYS,     /*!< internal sysclk ---> Clkout            */
#if  defined  USE_CMU_CLKOUTSEL_MEMS
    ClkoutFMEMS= CMU_CLKOUTSEL_MEMS,    /*!< internal mems clock ---> Clkout        */
#endif
#if  defined  USE_CMU_CLKOUTSEL_PLL     /*!< for HT6x2xH and above                  */
    ClkoutFPLL = CMU_CLKOUTSEL_PLL,     /*!< internal PLL clock ---> Clkout         */
#endif
}Clkout_SelectTypeDef;                  /*!< end of group Clkout_SelectTypeDef      */

/**
* @brief  definition of CPU clock division
*/
typedef enum
{
    CPUDiv1   = CMU_CPUCLKDIV_1,        /*!< Fcpu=Fsys                        */
    CPUDiv2   = CMU_CPUCLKDIV_2,        /*!< Fcpu=Fsys/2                      */
    CPUDiv4   = CMU_CPUCLKDIV_4,        /*!< Fcpu=Fsys/4                      */
    CPUDiv8   = CMU_CPUCLKDIV_8,        /*!< Fcpu=Fsys/8                      */
    CPUDiv16  = CMU_CPUCLKDIV_16,       /*!< Fcpu=Fsys/16                     */
    CPUDiv32  = CMU_CPUCLKDIV_32,       /*!< Fcpu=Fsys/32                     */
    CPUDiv64  = CMU_CPUCLKDIV_64,       /*!< Fcpu=Fsys/64                     */
    CPUDiv128 = CMU_CPUCLKDIV_128,      /*!< Fcpu=Fsys/128                    */
}CPU_DivTypeDef;                        /*!< end of group CPU_DivTypeDef      */

/**
* @brief  PLL setting value definition
*/
#if  defined  USE_CMU_C_PLL_TYPE1
typedef enum
{
    CPLL39M = CMU_C_PLL_39M,            /*!< Fpll=39M                         */
    CPLL40M = CMU_C_PLL_40M,            /*!< Fpll=40M                         */
    CPLL41M = CMU_C_PLL_41M,            /*!< Fpll=41M                         */
    CPLL42M = CMU_C_PLL_42M,            /*!< Fpll=42M                         */
    CPLL44M = CMU_C_PLL_44M,            /*!< Fpll=44M                         */
    CPLL45M = CMU_C_PLL_45M,            /*!< Fpll=45M                         */
    CPLL46M = CMU_C_PLL_46M,            /*!< Fpll=46M                         */
    CPLL47M = CMU_C_PLL_47M,            /*!< Fpll=47M                         */
 }CPLL_ValTypeDef;                      /*!< end of group CPLL_ValTypeDef     */
#elif  defined  USE_CMU_C_PLL_TYPE2
typedef enum
{ 
    CPLL0 = CMU_C_PLL_0,                /*!< Fpll = OSC*1344 = 44.040192MHz   */
    CPLL1 = CMU_C_PLL_1,                /*!< Fpll = OSC*1260 = 41.287680MHz   */
    CPLL2 = CMU_C_PLL_2,                /*!< Fpll = OSC*1176 = 38.535168MHz   */
    CPLL3 = CMU_C_PLL_3,                /*!< Fpll = OSC*1092 = 35.782656MHz   */
    CPLL4 = CMU_C_PLL_4,                /*!< Fpll = OSC*1008 = 33.030144MHz   */
    CPLL5 = CMU_C_PLL_5,                /*!< Fpll = OSC*924  = 30.277632MHz   */
    CPLL6 = CMU_C_PLL_6,                /*!< Fpll = OSC*840  = 27.525120MHz   */
    CPLL7 = CMU_C_PLL_7,                /*!< Fpll = OSC*756  = 24.772608MHz   */   
}CPLL_ValTypeDef;                       /*!< end of group CPLL_ValTypeDef     */
#endif

/**
* @brief  flash latency selection definition
*/
#if  defined  USE_CMU_PREFETCH_LATENCY
typedef enum
{
    LATENCY0 = CMU_PREFETCH_LATENCY_0,  /*!< flash fetch cycle = 1           */
    LATENCY1 = CMU_PREFETCH_LATENCY_1,  /*!< flash fetch cycle = 2           */
    LATENCY2 = CMU_PREFETCH_LATENCY_2,  /*!< flash fetch cycle = 3           */
    LATENCY3 = CMU_PREFETCH_LATENCY_3,  /*!< flash fetch cycle = 4           */
    LATENCY4 = CMU_PREFETCH_LATENCY_4,  /*!< flash fetch cycle = 5           */
    LATENCY5 = CMU_PREFETCH_LATENCY_5,  /*!< flash fetch cycle = 6           */
    LATENCY6 = CMU_PREFETCH_LATENCY_6,  /*!< flash fetch cycle = 7           */
    LATENCY7 = CMU_PREFETCH_LATENCY_7,  /*!< flash fetch cycle = 8           */
}LATENCY_ValTypeDef;                    /*!< end of group LATENCY_ValTypeDef */
#endif

/**
* @brief  system clock configuration module intialization structure definition
*/
typedef struct
{
   SYSCLK_SelectTypeDef  SysClkSel;    /*!< select system clock               */
   CPU_DivTypeDef        CPUDiv;       /*!< set cpu clock division            */
}CMU_InitTypeDef;                      /*!< end of group CMU_InitTypeDef      */

/**
* @brief  clkout configuration module intialization structure definition
*/
typedef struct
{
   Clkout_SelectTypeDef   ClkoutSel;    /*!< select clkout source                    */
   uint8_t  ClkoutDiv;                 /*!< select clkout division
                                            ClkoutDiv setting range: 0~15
                                            division setting = 2*(ClkoutDiv[3:0]+1) */
}Clkout_InitTypeDef;                   /*!< end of group Clkout_InitTypeDef         */


#if  defined  USE_CMU_HRCCLKSEL
typedef enum
{
    HRCDiv1 = CMU_HRCDIV_1,  /*!< flash fetch cycle = 2           */
    HRCDiv2 = CMU_HRCDIV_2,  /*!< flash fetch cycle = 3           */
    HRCDiv4 = CMU_HRCDIV_4,  /*!< flash fetch cycle = 5           */
    HRCDiv8 = CMU_HRCDIV_8,  /*!< flash fetch cycle = 8           */
}HRC_DivTypeDef;                    /*!< end of group HRC_DivTypeDef */

typedef enum
{
    HRCClk0 = CMU_HRCCLKCFG_HRCCLKSEL_00,  /*!< flash fetch cycle = 2           */
    HRCClk1 = CMU_HRCCLKCFG_HRCCLKSEL_01,  /*!< flash fetch cycle = 3           */
    HRCClk2 = CMU_HRCCLKCFG_HRCCLKSEL_10,  /*!< flash fetch cycle = 5           */
    HRCClk3 = CMU_HRCCLKCFG_HRCCLKSEL_11,  /*!< flash fetch cycle = 8           */
}HRC_ClkTypeDef;                    /*!< end of group HRC_ClkTypeDef */

typedef struct
{
    HRC_ClkTypeDef    HRCClk;
    HRC_DivTypeDef    HRCDiv;
}HRCCLK_InitTypeDef;

#endif

#define MEMS_FREQUENCY             ((uint32_t)524288)
#define OSC_FREQUENCY              ((uint32_t)32768)
#define LRC_FREQUENCY              OSC_FREQUENCY

#if  defined  USE_CMU_MCU_FREQUENCY
    #ifdef HT6x1x
    #define HRC_FREQUENCY          ((uint32_t)11000000)
    #else
    #define HRC_FREQUENCY          ((uint32_t)11010048)
    #endif /* HRC_FREQUENCY */

    #define PLL_FACTOR             ((uint32_t)672)
    #define PLLX2_FACTOR           ((uint32_t)PLL_FACTOR*2)
#elif  defined  USE_CMU_SOC_FREQUENCY
    #if  defined  HT501x
    #define HRC_FREQUENCY          ((uint32_t)9500000)
    #elif  defined  HT502x	||	defined  HT503x
    #define HRC_FREQUENCY          ((uint32_t)9800000)
    #else
    #define HRC_FREQUENCY          ((uint32_t)19600000)
    #endif /* HRC_FREQUENCY */
    
    #define PLL_FACTOR             ((uint32_t)600)
    #define PLLX2_FACTOR           ((uint32_t)PLL_FACTOR*2)
#endif

#if  defined  USE_CMU_HRCCLKSEL
    #define  HRC_FREQUENCY_00      HRC_FREQUENCY
    #define  HRC_FREQUENCY_01      (HRC_FREQUENCY*2)
    #define  HRC_FREQUENCY_10      (HRC_FREQUENCY*3)
    #define  HRC_FREQUENCY_11      HRC_FREQUENCY
#endif

#if  defined  USE_CMU_C_PLL_TYPE1
#define CPLL_0_FACTOR              ((uint32_t)608)
#define CPLL_STEP                  ((uint32_t)16)
#elif  defined  USE_CMU_C_PLL_TYPE2
#define CPLL_0_FACTOR              PLL_FACTOR
#define CPLL_STEP                  ((int32_t)-42)
#endif



/**
* @brief  HT_CMU_SysClkSel, check input parameters
*/
#if  defined  USE_CMU_SYSCLKCFG_TYPE1
#define IS_HT_CMU_SYSCLKSEL(CLKSEL) (((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LRC)                                       || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LF)                                        || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_1<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_2<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_4<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_8<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_PLL)                                       || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_MEMS))
#elif  defined  USE_CMU_SYSCLKCFG_TYPE2
#define IS_HT_CMU_SYSCLKSEL(CLKSEL) (((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LRC)                                       || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LF)                                        || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_1<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_2<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_4<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_HRC|(CMU_HRCDIV_8<<HRCDIV_LOCATION)))     || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_PLL)                                       || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_PLL|CMU_SYSCLKDIV_SEL40M)))
#elif defined  USE_CMU_SYSCLKCFG_TYPE3
#define IS_HT_CMU_SYSCLKSEL(CLKSEL) (((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LRC)                                       || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_LF)                                        || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_HRC)                                       || \
                                     ((CLKSEL) == CMU_SYSCLKCFG_CLKSEL_PLL)                                       || \
                                     ((CLKSEL) == (CMU_SYSCLKCFG_CLKSEL_PLL|CMU_SYSCLKDIV_SEL40M)))
#endif

/**
* @brief  HT_CMU_CPUDiv, check input parameters
*/
#define IS_HT_CMU_CPUDIV(CPUDIV) (((CPUDIV) == CMU_CPUCLKDIV_1)   || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_2)   || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_4)   || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_8)   || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_16)  || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_32)  || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_64)  || \
                                  ((CPUDIV) == CMU_CPUCLKDIV_128))

/**
* @brief  HT_CMU_CLKOUTSEL, check input parameters
*/
#if  defined  USE_CMU_CLKOUTSEL_MEMS
#define IS_HT_CMU_CLKOUTSEL(CLKOUTSEL) (((CLKOUTSEL) == CMU_CLKOUTSEL_LRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_LF)   || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_HRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_SYS)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_MEMS))
#elif  defined  USE_CMU_CLKOUTSEL_PLL
#define IS_HT_CMU_CLKOUTSEL(CLKOUTSEL) (((CLKOUTSEL) == CMU_CLKOUTSEL_LRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_LF)   || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_HRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_SYS)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_PLL))
#else
#define IS_HT_CMU_CLKOUTSEL(CLKOUTSEL) (((CLKOUTSEL) == CMU_CLKOUTSEL_LRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_LF)   || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_HRC)  || \
                                        ((CLKOUTSEL) == CMU_CLKOUTSEL_SYS))
#endif

/**
* @brief  HT_CMU_CLKOUTDIV, check input parameters
*/
#define CLKOUTDIV_MAX                   (15U)
#define IS_HT_CMU_CLKOUTDIV(CLKOUTDIV)  ((CLKOUTDIV) <= CLKOUTDIV_MAX)

/**
* @brief  HT_CMU_C_PLL, check input parameters
*/
#if  defined  USE_CMU_C_PLL_TYPE1
#define IS_HT_CMU_C_PLL(PLLVAL)  (((PLLVAL) == CMU_C_PLL_39M) || \
                                  ((PLLVAL) == CMU_C_PLL_40M) || \
                                  ((PLLVAL) == CMU_C_PLL_41M) || \
                                  ((PLLVAL) == CMU_C_PLL_42M) || \
                                  ((PLLVAL) == CMU_C_PLL_44M) || \
                                  ((PLLVAL) == CMU_C_PLL_45M) || \
                                  ((PLLVAL) == CMU_C_PLL_46M) || \
                                  ((PLLVAL) == CMU_C_PLL_47M))
#elif  defined  USE_CMU_C_PLL_TYPE2
#define IS_HT_CMU_C_PLL(PLLVAL)  (((PLLVAL) == CMU_C_PLL_0) || \
                                  ((PLLVAL) == CMU_C_PLL_1) || \
                                  ((PLLVAL) == CMU_C_PLL_2) || \
                                  ((PLLVAL) == CMU_C_PLL_3) || \
                                  ((PLLVAL) == CMU_C_PLL_4) || \
                                  ((PLLVAL) == CMU_C_PLL_5) || \
                                  ((PLLVAL) == CMU_C_PLL_6) || \
                                  ((PLLVAL) == CMU_C_PLL_7))
#endif

/**
* @brief  HT_CMU_STA_FLAG, check input parameters
*/
#define IS_HT_CMU_STA_FLAG(FLAG)  (((FLAG) == CMU_CLKSTA_LFFLAG)  || \
                                   ((FLAG) == CMU_CLKSTA_HRCFLAG) || \
                                   ((FLAG) == CMU_CLKSTA_PLLFLAG))

/**
* @brief  HT_CMU_FLASH_LATENCY_Set, check input parameters
*/                                
#if  defined  USE_CMU_PREFETCH_LATENCY
#define IS_HT_CMU_LATENCY(LATENCY)  (((LATENCY) == CMU_PREFETCH_LATENCY_0)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_1)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_2)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_3)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_4)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_5)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_6)  || \
                                     ((LATENCY) == CMU_PREFETCH_LATENCY_7))
#endif

/**
* @brief  HT_CMU_HRCCLK_Set, check input parameters
*/
#if  defined  USE_CMU_HRCCLKSEL
#define IS_HT_CMU_HRCCLKSEL(HRCCLK) (((HRCCLK) == CMU_HRCCLKCFG_HRCCLKSEL_00)  || \
                                     ((HRCCLK) == CMU_HRCCLKCFG_HRCCLKSEL_01)  || \
                                     ((HRCCLK) == CMU_HRCCLKCFG_HRCCLKSEL_10)  || \
                                     ((HRCCLK) == CMU_HRCCLKCFG_HRCCLKSEL_11))

#define IS_HT_CMU_HRCDIV(HRCDIV)    (((HRCDIV) == CMU_HRCDIV_1)  || \
                                     ((HRCDIV) == CMU_HRCDIV_2)  || \
                                     ((HRCDIV) == CMU_HRCDIV_4)  || \
                                     ((HRCDIV) == CMU_HRCDIV_8))

#endif
/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
void HT_CMU_Init(CMU_InitTypeDef* CMU_InitStruct);
uint32_t HT_CMU_SysClkGet(void);
uint32_t HT_CMU_CPUClkGet(void);
void HT_CMU_ClkoutSet(Clkout_InitTypeDef* Clkout_InitStruct);
void HT_CMU_ClkCtrl0Config(uint32_t ClkCtrl0Module, FunctionalState NewState);
void HT_CMU_ClkCtrl1Config(uint32_t ClkCtrl1Module, FunctionalState NewState);
Bool HT_CMU_JTAGStatusGet(void);
uint32_t HT_CMU_ChipIDGet(void);
FlagStatus HT_CMU_StopFlagGet(uint32_t STAFlag);
#if  defined  USE_CMU_FLASHDLY_ENABLE
void  HT_CMU_FlashDly_Set(FunctionalState NewState);
#endif
#if  defined  USE_CMU_PREFETCH_ENABLE  ||  defined  HT6x3x
void  HT_CMU_Prefetch_Set(FunctionalState NewState);
#endif
#if  defined  USE_CMU_PREFETCH_CACHE_EN ||  defined  USE_CMU_FLASHDLY_CACHE_EN
void  HT_CMU_Cache_Set(FunctionalState NewState);
#endif
#if  defined  USE_CMU_PREFETCH_2T  ||  defined  USE_CMU_FLASHDLY_2T
void  HT_CMU_CTRL_2T_Set(FunctionalState NewState);
#endif
#if  defined  USE_CMU_PREFETCH_3T ||  defined USE_CMU_FLASHDLY_3T
void  HT_CMU_CTRL_3T_Set(FunctionalState NewState);
#endif

#if  defined  USE_CMU_C_PLL_TYPE1  ||  defined  USE_CMU_C_PLL_TYPE2
void HT_CMU_CPllSet(CPLL_ValTypeDef pllVal);
#endif

#if  defined  USE_CMU_PREFETCH_LATENCY
void  HT_CMU_FLASH_LATENCY_Set(LATENCY_ValTypeDef Latency);
#endif

#if  defined  USE_CMU_HRCCLKSEL
void  HT_CMU_HRCCLK_Set(HRCCLK_InitTypeDef* HRC_InitStruct);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6xxx_CMU_H__ */
