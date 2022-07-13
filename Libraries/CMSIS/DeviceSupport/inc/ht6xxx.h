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
* File         : ht6xxx.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  : 
**********************************************************************************************************
*/

#ifndef __HT6XXX_H__
#define __HT6XXX_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
**********************************************************************************************************
*                                             Global Macro/Structure
**********************************************************************************************************
*/
#if !defined (HT6x2x) && !defined (HT6x1x) && !defined (HT501x) && !defined (HT502x) && !defined (HT6x3x)  &&!defined (HT6x2xK) && !defined (HT503x) && !defined (HT633x)  && !defined (HT762x)  && !defined (HT772x)
   #error "Please select one HT device used in your application"
#endif

#if defined (HT6x1x)
 #if defined (HT6x2x) || defined (HT501x) || defined (HT502x) || defined (HT6x3x)  ||  defined  (HT6x2xK) || defined (HT503x) || defined (HT633x) || defined (HT762x) || defined (HT772x)  
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT6x2x)
 #if defined (HT501x) || defined (HT502x) || defined (HT6x3x)  ||  defined  (HT6x2xK) || defined (HT503x) || defined (HT633x) || defined (HT762x) || defined (HT772x)
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT501x)
 #if defined (HT502x) || defined (HT6x3x)  ||  defined  (HT6x2xK) || defined (HT503x) || defined (HT633x) || defined (HT762x) || defined (HT772x) 
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT6x2xK)
 #if defined (HT502x) || defined (HT6x3x) || defined (HT503x) || defined (HT633x) || defined (HT762x) || defined (HT772x) 
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT502x)
 #if defined (HT503x) || defined (HT6x3x) || defined (HT633x) || defined (HT762x) || defined (HT772x) 	
   #error "More than one HT device used in your application"
 #endif   
#elif defined (HT503x) 	
 #if defined (HT6x3x) || defined (HT633x) || defined (HT762x) || defined (HT772x)	
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT6x3x) 	
 #if defined (HT633x) || defined (HT762x) || defined (HT772x)	
   #error "More than one HT device used in your application"
 #endif
#elif defined (HT633x)
 #if defined (HT762x) || defined (HT772x)
    #error "More than one HT device used in your application"
 #endif
#else
 #if defined (HT762x) && defined (HT772x)
   #error "More than one HT device used in your application"
 #endif
#endif

/*
**********************************************************************************************************
*                                       GPIO related Condition compilation
**********************************************************************************************************
*/
#if defined HT6x1x
#define USE_MCU
#define USE_GPIO_JTAG
#define UNUSE_GPIO_GPIOF
#define UNUSE_GPIO_GPIOG
#define UNUSE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#endif

#if defined HT6x2x
#define USE_MCU
#define USE_GPIO_SWD
#define UNUSE_GPIO_GPIOF
#define USE_GPIO_GPIOG
#define USE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#define USE_GPIO_FILT
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_EXTI_INT9
#define USE_LCD_SEG37_41
#define USE_PMU_LVDIN1
#define USE_POWIN
#define USE_SPI_SPI1
#define USE_TBS_ADCIN3
#define USE_TBS_ADCIN4
#define USE_TBS_ADCIN5
#define USE_TEST_CLOCKIN
#define USE_TMR_TMR4
#define USE_TMR_TMR5
#define USE_UART_UART6
#endif

#if defined HT6x2xK
#define USE_MCU
#define USE_GPIO_SWD
#define UNUSE_GPIO_GPIOF
#define USE_GPIO_GPIOG
#define UNUSE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#define USE_GPIO_NEWAFCTRL
#define USE_GPIO_FILT
#define USE_GPIO_VER_K
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_LCD_SEG37_41
#define USE_PMU_LVDIN1
#define USE_SPI_SPI1
#define USE_SPI_SPI3
#define USE_TBS_ADCIN3
#define USE_TBS_ADCIN4
#define USE_TBS_ADCIN5
#define USE_TEST_CLOCKIN
#define USE_TMR_TMR4
#define USE_TMR_TMR5
#endif

#if defined HT6x3x
#define USE_MCU
#define USE_GPIO_SWD
#define UNUSE_GPIO_GPIOF
#define USE_GPIO_GPIOG
#define USE_GPIO_GPIOH
#define USE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#define USE_GPIO_FILT
#define USE_EMU_CONST      /* constant metering */
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_EXTI_INT9
#define USE_LCD_CHARGEPUMP
#define USE_LCD_SEG37_41
#define USE_LCD_SEG42_55
#define USE_PMU_LVDIN1
#define USE_PMU_LVDIN2
#define USE_POWIN
#define USE_SPI_SPI1
#define USE_SPI_SPI2
#define USE_TBS_ADCIN3
#define USE_TBS_ADCIN4
#define USE_TBS_ADCIN5
#define USE_TEST_CLOCKIN
#define USE_TMR_DEADZONE
#define UNUSE_TMR_PH4_DEADZONE
#define USE_TMR_TMR4
#define USE_TMR_TMR5
#define USE_UART_UART6
#endif

#if defined HT633x
#define USE_MCU
#define USE_GPIO_SWD
#define UNUSE_GPIO_GPIOF
#define USE_GPIO_GPIOG
#define USE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define USE_GPIO_HIIPM
#define USE_GPIO_AF34
#define USE_GPIO_AF_PRIORITY
#define USE_GPIO_FILT
#define USE_GPIO_VER_M3
#define USE_EMU_CONST      /* constant metering */
#define USE_EMU_CONST_CLKSEL
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_EXTI_INT9
#define USE_EXTI_INT10
#define USE_EXTI_INT11
#define USE_EXTI_INT12
#define USE_EXTI_INT13
#define USE_EXTI_INT14
#define USE_LCD_SEG37_41
#define USE_LCD_SEG42_55
#define USE_PMU_LVDIN1
#define USE_PMU_LVDIN2
#define USE_PMU_LVDINN            
#define USE_RTC_NONINDEPENDENT
#define USE_RTC_STAMP0
#define USE_SPI_SPI1
#define USE_SPI_SPI2
#define USE_SPI_SPI3
#define USE_TBS_ADCIN3
#define USE_TBS_ADCIN4
#define USE_TBS_ADCIN5
#define USE_TBS_ADCIN6
#define USE_TBS_ADCIN7
#define USE_TBS_ADCIN8
#define USE_TBS_ADCIN9
#define USE_TEST_CLOCKIN
#define USE_TMR_TMR4
#define USE_TMR_TMR5
#define USE_TMR_DEADZONE
#define USE_UART_UART6
#define USE_UART_LPUART
#endif

#if defined HT501x
#define USE_SOC
#define USE_GPIO_GPIOF
#define UNUSE_GPIO_GPIOG
#define UNUSE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#endif

#if defined HT502x
#define USE_SOC
#define USE_GPIO_GPIOF
#define UNUSE_GPIO_GPIOG
#define UNUSE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_EXTI_INT9
#define USE_LCD_CHARGEPUMP
#define USE_LCD_SEG43_53
#define USE_RTC_TOUT3
#endif

#if defined HT503x
#define USE_SOC
#define USE_GPIO_GPIOF
#define UNUSE_GPIO_GPIOG
#define USE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define UNUSE_GPIO_GPIOJ
#define UNUSE_GPIO_HIIPM
#define USE_GPIO_AF34
#define USE_GPIO_FILT
#define USE_EXTI_INT7
#define USE_EXTI_INT8
#define USE_EXTI_INT9
#define USE_LCD_CHARGEPUMP
#define USE_LCD_VLCDNP
#define USE_LCD_SEG43_53
#define USE_RTC_TOUT3
#define USE_SPI_SPI1
#define USE_SPI_SPI2
#define USE_TBS_ADCIN3
#define USE_TBS_ADCIN4
#define USE_TBS_ADCIN5
#define USE_TBS_ADCIN6
#define USE_UART_UART6
#endif

#if defined HT762x ||  defined  HT772x
#define USE_MCU_EMU
#define UNUSE_GPIO_GPIOF
#define USE_GPIO_GPIOG
#define UNUSE_GPIO_GPIOH
#define UNUSE_GPIO_GPIOI
#define USE_GPIO_GPIOJ
#define USE_GPIO_HIIPM
#define UNUSE_GPIO_AF34
#define USE_GPIO_FILT
#endif

/*
**********************************************************************************************************
*                                       UART&7816 related Condition compilation
**********************************************************************************************************
*/


#if   defined  HT762x ||  defined  HT772x || defined  HT633x || defined  HT6x2x || defined  HT6x3x  ||  defined  HT6x2xK
#define		USE_UART_IRQ
#endif

#if defined  HT502x || defined  HT6x2x || defined  HT6x3x  ||  defined  HT6x2xK   || defined  HT503x ||  defined  HT762x ||  defined  HT772x
#define		USE_UART_IRCON_IRCLKSRC
#endif

#if  defined  HT633x
#define	USE_UART_IRCLKSRC
#endif

#if defined  HT502x || defined  HT6x2x || defined  HT6x3x  ||  defined  HT6x2xK   || defined  HT503x ||  defined  HT762x ||  defined  HT772x
#define		USE_IR38kSource
#endif

#if  defined  HT633x
#define	USE_IR38KSOURCE
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x ||  defined  HT772x || defined  HT633x
#define		USE_UartLogicAuto
#endif

#if defined	HT502x  ||  defined  HT6x2x  ||  defined HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x  || defined  HT503x
#define		USE_UART_IRCON_IR38KSOURCE
#endif

#if  defined  HT633x
#define	USE_UART_IR38KSOURCE
#endif

#if  defined  HT6x3x
#define		USE_UART_IRCLKDIV
#endif

#if  defined  HT633x
#define		USE_UART_IR38KDIV
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined HT762x ||  defined  HT772x || defined  HT503x || defined  HT633x
#define	USE_UART6
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined HT762x ||  defined  HT772x  || defined  HT633x
#define	USE_UART6_IT
#endif

#if defined  HT6x2x  ||  defined  HT6x2xK 
#define	USE_LOGDETNUM
#endif

#if defined  HT6x2xK  ||  defined  HT762x ||  defined  HT772x ||  defined  HT6x2x 
#define	USE_NEGDETLEN
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x
#define	USE_UARTCON
#endif

#if  defined  HT502x ||  defined  HT503x ||  defined  HT501x
#define	USE_UARTCON1
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x ||  defined  HT772x 
#define	USE_UARTCON2
#endif

#if  defined  HT633x
#define	USE_UARTCON3
#endif

#if  defined  HT502x ||  defined  HT503x ||  defined  HT501x
#define	USE_UARTCON_NEG
#endif

#if  defined  HT6x2x || defined HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x 
#define	USE_UARTSTA
#endif

#if  defined  HT6x2x || defined HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x 
#define	USE_UARTSTA1
#endif

#if  defined  HT633x 
#define	USE_UARTSTA2
#endif

#if  defined  HT633x
#define	USE_UART_SREL
#endif

#if  defined  HT502x  ||  defined  HT6x2x  ||  defined HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x  || defined  HT503x
#define	USE_IRCON
#endif

#if  defined  HT633x 
#define	USE_IRCON1
#endif

#if  defined  HT6x2x  ||  defined HT6x3x  ||  defined  HT6x2xK  || defined  HT762x ||  defined  HT772x || defined  HT633x
#define	USE_UART_NEGDETLEN
#endif

/*
**********************************************************************************************************
*                                       CMU related Condition compilation
**********************************************************************************************************
*/
#if  defined  HT6x1x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined HT633x
#define USE_CMU_MCU_FREQUENCY
#elif  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x  ||  defined  HT762x ||  defined  HT772x
#define USE_CMU_SOC_FREQUENCY
#endif

#if  defined  HT6x1x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
#define  USE_CMU_HRCDIV
#endif /* HRCDIV */

#if  defined  HT6x1x
#define  USE_CMU_SYSCLKCFG_MEMS
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT503x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
#define  USE_CMU_SYSCLKDIV_SEL40M
#endif /* SYSCLKDIV_SEL20M */

#if  defined  HT6x3x  ||  defined  HT6x2x   ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x   /*!<Applicable to HT6x2x H version and above */
#define  USE_CMU_CLKOUTSEL_PLL
#elif defined  HT6x1x
#define  USE_CMU_CLKOUTSEL_MEMS
#endif /* CLKOUTSEL */


#if !defined  HT502x  &&  !defined  HT503x
#define  USE_CMU_JTAGSTA
#endif

#if  !defined  HT6x1x
#define  USE_CMU_CHIPID
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined HT762x  ||  defined  HT772x  ||  defined HT633x
#define  USE_CMU_PREFETCH
    #if  defined  HT6x2x  ||  defined  HT6x2xK
    #define  USE_CMU_PREFETCH_ENABLE
    #elif  defined  HT6x3x  ||  defined  HT633x
    #define  USE_CMU_PREFETCH_CACHE_EN
    #endif
    
    #if  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
    #define  USE_CMU_PREFETCH_2T
    #endif
    
    #if  defined  HT762x  ||  defined  HT772x
    #define  USE_CMU_PREFETCH_3T
    #endif
    
    #if  defined  HT633x
    #define  USE_CMU_PREFETCH_LATENCY
    #endif
#elif  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#define  USE_CMU_FLASHDLY
    #if  defined  HT501x  ||  defined  HT502x
    #define USE_CMU_FLASHDLY_ENABLE
    #elif  defined  HT503x
    #define  USE_CMU_FLASHDLY_2T
    #endif
    
    #if  defined  HT503x
    #define  USE_CMU_FLASHDLY_CACHE_EN
    #define  USE_CMU_FLASHDLY_3T
    #endif
#endif

#if  defined  HT502x ||  defined  HT503x
#define  USE_CMU_CLKCTRL0_AESEN_RAND_OPEN
#elif  defined  HT6x2x || defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
#define  USE_CMU_CLKCTRL0_ARGEN_RAND_OPEN
#endif

#if  defined  HT502x
#define  USE_CMU_CLKCTRL0_AESEN_RAND_CLOSE
#elif  defined  HT6x2x || defined  HT6x3x
#define  USE_CMU_CLKCTRL0_ARGEN_RAND_CLOSE
#endif

#if defined HT6x1x
    #define  USE_CMU_CLKCTRL0_1P5_OSC_GRP1
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x   ||  defined  HT6x2xK
    #define  USE_CMU_CLKCTRL0_1P5_OSC_GRP2
#elif  defined  HT5x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
    #define  USE_CMU_CLKCTRL0_1P5_OSC_GRP3
#endif

#if  defined  HT6x3x
#define  USE_CMU_TBSCLK_GRP1
#elif  defined  HT503x
#define  USE_CMU_TBSCLK_GRP2
#elif  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x
#define  USE_CMU_TBSCLK_GRP3
#elif  defined  HT633x
#define  USE_CMU_TBSCLK_GRP4
#endif

#if  defined  HT6x3x
#define  USE_CMU_C_PLL_TYPE1
#elif  defined  HT633x
#define  USE_CMU_C_PLL_TYPE2
#endif /* CPLL */


#if  defined  HT6x1x
#define  USE_CMU_SYSCLKCFG_TYPE1
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT633x  ||  defined  HT762x  ||  defined  HT772x
#define  USE_CMU_SYSCLKCFG_TYPE2
#elif  defined HT501x || defined  HT502x ||  defined  HT503x
#define  USE_CMU_SYSCLKCFG_TYPE3
#endif

#if  defined  HT633x
#define  USE_CMU_HRCCLKSEL
#endif

#if  defined  HT6x2x || defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define USE_CMU_CLKCTRL0_ARGEN
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define USE_CMU_CLKCTRL0_CRCEN
#endif

#if  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#define USE_CMU_CLKCTRL0_EMUEN
#endif

#if  defined  HT502x  ||  defined  HT503x
#define USE_CMU_CLKCTRL0_ECCEN
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define USE_CMU_CLKCTRL0_SEL_PLLN_HRC
#endif

/*
**********************************************************************************************************
*                          PMU related Condition compilation
**********************************************************************************************************
*/
#if  defined HT501x 
#define	USE_VDETCFG_SOC_TYPE1
#define USE_VCCLVL_501x
#define USE_DETTIM_1068US
#endif

#if defined HT6x1x 
#define	USE_PMUCON_TYPE1
#define	USE_VDETCFG_MCU_TYPE1
#define USE_DETTIM_560US
#endif

#if defined HT502x
#define	USE_VDETCFG_SOC_TYPE2
#endif

#if defined HT503x
#define	USE_VDETCFG_SOC_TYPE3
#endif

#if defined HT501x   ||  defined HT502x ||  defined HT503x  ||  defined HT6x2xK  || defined HT762x  ||  defined  HT772x
#define USE_PMUCON_TYPE2
#endif

#if  defined HT6x2x   ||  defined HT6x3x   ||  defined HT501x   ||  defined HT502x   ||  defined HT6x2xK 
#define USE_DISCHARGE
#endif
#if  defined HT6x2x   ||  defined HT6x3x   ||  defined HT6x2xK 
#define USE_DISCHARGE_MCU
#endif

#if  defined HT6x2x || defined HT6x3x || defined HT501x || defined HT502x || defined HT503x || defined HT6x2xK || defined HT762x  ||  defined  HT772x || defined HT633x 
#define USE_LVDIN1
#endif

#if  defined HT6x2x || defined HT6x3x 
#define USE_POWDET
#endif

#if  defined HT6x3x   || defined HT633x 
#define USE_PMUCON_TYPE3
#define USE_LVDIN2
#define USE_LVDIN_QR
#endif

#if defined HT633x
#define USE_LVDIN_SEL
#define USE_WAKEIF1
#define USE_DETTIM_TYPE_3
#define USE_VCCLVL_633x
#endif

#if  defined HT6x3x || defined HT6x1x
#define USE_DETTIM_TYPE_1
#endif

#if  defined HT6x2x || defined HT501x
#define USE_DETTIM_TYPE_2
#endif

#if  defined HT6x3x 
#define USE_DETTIM_1120US
#endif


#if defined HT6x1x   ||  defined HT501x   ||  defined HT502x   ||  defined HT503x 
#define USE_BOR_SOC
#endif

#if defined HT6x2x   ||  defined HT6x3x   ||  defined HT6x2xK   ||  defined HT762x  ||  defined  HT772x 
#define USE_BOR_MCU
#endif

#if defined HT6x2xK   || defined HT762x  ||  defined  HT772x || defined HT502x || defined HT503x
#define USE_DETTIM_ONLY_1068US
#endif
/*
**********************************************************************************************************
*                          FLASH related Condition compilation
**********************************************************************************************************
*/
#if defined HT6x1x 
#define USE_HT601x_MEMORY
#endif

#if defined HT6x2x  
#define USE_HT602x_MEMORY
#endif

#if defined HT6x2xK  
#define USE_HT602x_MEMORY
#define USE_SPI3_K
#endif

#if  defined HT6x3x 
#define USE_HT603x_MEMORY
#define USE_FLASH_SECTORKEY_0
#define USE_FLASH_BLOCK     
#endif

#if defined HT633x 
#define USE_HT633x_MEMORY
#define USE_FLASH_SECTORKEY_0
#define USE_LPUART
#define USE_LPCFG
#endif

#if defined HT762x  ||  defined  HT772x 
#define USE_HT7x2x_MEMORY
#define USE_EMU_RESAMPLE
#define USE_FFT
#define USE_DMA_CH13
#define USE_EMUIFACE_7X
#define USE_FRAMPACK_7X
#define USE_LDOVREF
#define USE_STAMP
#endif

#if  defined HT501x 
#define USE_HT501x_MEMORY
#endif

#if  defined HT502x 
#define USE_HT502x_MEMORY
#define USE_FLASH_SECTORKEY_1
#endif

#if  defined HT503x 
#define USE_HT503x_MEMORY
#define USE_FLASH_SECTORKEY_2
#define USE_INFOFLASH_SECTOR_12
#define USE_SPI_SOC
#define USE_EMUIFACE_5X
#define USE_FRAMPACK_5X
#endif

#if defined USE_FLASH_SECTORKEY_0  || defined USE_FLASH_SECTORKEY_1  || defined USE_FLASH_SECTORKEY_2 
#define     USE_FLASH_SECTOR
#endif

#if  defined  HT6x3x  ||  defined  HT503x  ||  defined  HT633x 
#define		USE_FLASH_INFOLOCK_A
#endif

#if defined HT6x3x  || defined HT502x  || defined HT503x ||  defined  HT633x 
#define     USE_FLASH_FLASHCON2
#endif

#if defined HT6x2x  || defined HT6x2xK  || defined HT6x3x  || defined HT633x  || defined HT762x  ||  defined  HT772x 
#define USE_TIMER45
#endif

#if defined HT6x2x  || defined HT6x2xK  || defined HT6x3x  || defined HT633x  || defined HT762x  ||  defined  HT772x  || defined HT503x 
#define USE_CRC
#endif

#if defined HT6x2xK  || defined HT6x3x  || defined HT633x  || defined HT762x  ||  defined  HT772x 
#define USE_SPI2_MCU
#endif

#if defined HT6x2x  || defined HT6x2xK  || defined HT6x3x  || defined HT633x  || defined HT762x  ||  defined  HT772x 
#define USE_SPI1_MCU
#endif

#if defined HT501x  || defined HT502x  || defined HT503x 
#define USE_EMU_NORMAL
#endif

#if defined HT502x  || defined HT503x 
#define USE_ECC_SOC
#endif

#if defined HT6x3x  || defined HT633x 
#define USE_EMU_CONST
#define USE_ECC_MCU
#endif

#if defined HT633x  || defined HT762x  ||  defined  HT772x 
#define USE_SPI3
#endif

#if defined HT503x  || defined HT633x  || defined HT762x  ||  defined  HT772x 
#define USE_DMA_CH8
#endif

/*
**********************************************************************************************************
*                          RTC related Condition compilation
**********************************************************************************************************
*/
#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define USE_RTC_RTC2CAL 
#endif

#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define USE_RTC_RTC2RD
#endif

#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define USE_RTC_RTC2WR
#endif

#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x1x   ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT762x  ||  defined  HT772x || defined  HT633x
#define USE_RTC_MCON01_23
#endif

#if defined  HT6x1x ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
#define USE_RTC_RTCCON_TOUT_16TO128HZ
#endif

#if defined HT503x ||  defined  HT633x
#define USE_RTC_RTCCLKCFG
#endif

#if defined HT503x
#define USE_RTC_RTCTESTCTRL_C_OSC32K
#endif

#if defined HT633x
#define USE_RTC_RTCSTAMP0
#endif

#if defined HT762x  ||  defined  HT772x
#define USE_RTC_RTCSTAMP01
#endif

#if defined HT762x  ||  defined  HT772x || defined HT633x
#define USE_RTC_RTCBACKUP_REG
#endif

/*
**********************************************************************************************************
*                          SPI related Condition compilation
**********************************************************************************************************
*/
#if defined  HT6x3x
#define USE_SPI_SPICLK
#endif

#if defined  HT6x3x  ||  defined  HT633x
#define USE_SPI_ODDDIV
#endif

#if defined  HT6x1x || defined  HT501x  ||  defined  HT502x 
#define USE_SPI0
#endif

#if  defined  HT6x2x   
#define USE_SPI01
#endif

#if  defined  HT6x3x ||  defined  HT503x  
#define USE_SPI012
#endif

#if  defined  HT6x2xK   
#define USE_SPI013
#endif

#if  defined  HT762x  ||  defined  HT772x || defined  HT633x  
#define USE_SPI0123
#endif

#if defined  HT503x
#define USE_SPI_SPICON_FASTEN
#endif

#if defined  HT762x  ||  defined  HT772x  ||  defined  HT503x  ||  defined  HT633x
#define USE_SPI_SPICON_LSBEN
#endif

#if defined HT6x1x  ||  defined  HT501x  ||  defined  HT502x    
#define USE_SPI_SPISSN_CS
#endif

#if defined HT6x2x  ||  defined  HT6x3x  ||  defined HT762x  ||  defined  HT772x  ||  defined HT503x  ||  defined  HT6x2xK  ||  defined  HT633x
#define USE_SPI_SPISSN_SSN01
#endif

#if defined HT762x  ||  defined  HT772x  ||  defined HT503x  ||  defined  HT6x2xK 
#define USE_SPI_SPISSN_MSAM
#endif

#if defined HT762x  ||  defined  HT772x  ||  defined HT503x  ||  defined  HT6x2xK  
#define USE_SPI_CSDLY
#endif

#if defined HT762x  ||  defined  HT772x  ||  defined HT503x  
#define USE_SPI_FIFO
#endif

#if defined HT762x  ||  defined  HT772x
#define USE_SPI02_FIFO
#endif

#if defined HT503x
#define USE_SPI12_FIFO
#define USE_SPI12_SPICON_LSBEN
#define USE_SPI12_SPICON_FASTEN
#define USE_SPI12_SPISSN_MSAM
#define USE_SPI12_SPISSN_SSN1
#define USE_SPI12_CSDLY
#endif


/*
**********************************************************************************************************
*                          LCD related Condition compilation
**********************************************************************************************************
*/
#if defined  HT6x3x  ||  defined  HT503x 
#define	USE_REGISTER_LCDCPC
#endif

#if defined  HT6x1x  || defined  HT6x2xK
#define	USE_REGISTER_LCDBUF_37
#endif

#if defined  HT6x2x 
#define	USE_REGISTER_LCDBUF_42
#endif


#if defined  HT6x3x
#define	USE_REGISTER_LCDBUF_56
#endif

#if defined  HT502x ||  defined  HT503x
#define	USE_REGISTER_LCDBUF_54
#endif

#if defined  HT633x 
#define	USE_REGISTER_LCDBUF_48
#endif
#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK   ||  defined  HT503x    ||  defined  HT633x  	
#define	USE_LCD	
#endif

#if  defined  HT502x  ||  defined  HT6x3x	
#define	USE_PeriodDiv128
#define	USE_LCDChargeQuick_PeriodDiv8
#endif	
	
#if  defined  HT6x3x  ||  defined  HT503x 	
#define	USE_LCDDriverMode
#define USE_LCD_CPInit	
#define USE_IS_LCD_ChargePumpClk
#define USE_HT_LCD_CP_Init
#endif	
	
#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x 	
#define USE_LCDChargeMode	
#endif	

#if  defined  HT502x  ||  defined  HT6x3x  ||  defined  HT503x 
#define USE_HT_LCD_OutConfig
#define USE_REGISTER_LCDOUT
#endif

#if  defined  HT6x1x                                                        
#define    MaxSegNum_36
#elif  defined  HT6x2x  ||  defined  HT6x2xK                                /*!< HT6x2x                */
#define    MaxSegNum_41
#elif  defined  HT6x3x                                                      /*!< HT6x3x                */
#define    MaxSegNum_55
#elif  defined  HT501x                                                      /*!< HT501x                */
#define    MaxSegNum_42
#elif  defined  HT502x  ||  defined  HT503x                                 /*!< HT501x  /HT503x       */
#define    MaxSegNum_53
#elif  defined  HT633x                                  					/*!< HT633x                */
#define    MaxSegNum_48
#else                                                                       /*!< Default：HT6x3x       */
#define    MaxSegNum_55
#endif

/*
**********************************************************************************************************
*                          DMA related Condition compilation
**********************************************************************************************************
*/
#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK   ||  defined  HT503x  ||  defined  HT762x  ||  defined  HT772x  ||   defined  HT633x  	
#define	USE_DMA	
#endif	
	
#if defined  HT501x  ||  defined  HT502x   ||  defined  HT503x 	
#define	USE_DMA_SOC	
#endif	

#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||   defined  HT633x
#define	USE_DMA_MCU	
#endif	

#if defined  HT503x  ||  defined  HT762x  ||  defined  HT772x
#define	USE_DMA_Priority		
#endif
	
#if defined  HT633x 
#define USE_DMA_Direction
#endif		
#if defined  HT762x  ||  defined  HT772x
#define	USE_DMA_Channel12
#define	USE_DMA_Channel11	
#define USE_DMA_TRIG0
#define USE_DMA_TRIG3
#endif

#if defined  HT503x
#define	USE_DMA_TRIG0
#define USE_DMA_TRIG2
#endif

#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK 
#define USE_DMA_TRIG0
#define	USE_DMA_TRIG1
#endif

#if defined  HT633x
#define USE_DMA_TRIG0
#define USE_DMA_TRIG4
#endif

#if defined  HT503x  ||   defined  HT633x
#define	USE_DMA_Channel7
#endif
#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK
#define USE_DMA_Channel2
#endif

#if  defined  HT762x  ||  defined  HT772x ||   defined  HT503x ||   defined  HT633x  
#define USE_DMA_DMAIE
#define USE_DMA_DMAIF
#define USE_DMA_CHNCTL
#define USE_DMA_CHNSRC
#define USE_DMA_CHNTAR
#define USE_DMA_CHNCNT
#define USE_DMA_CHNTCCNT
#define USE_DMA_CHNBULKNUM
#endif

#if  defined  HT762x  ||  defined  HT772x
#define USE_DMA_DMAIE1
#define USE_DMA_DMAIF1
#define USE_DMA_DMAIE2
#define USE_DMA_DMAIF2
#define USE_DMA_CHN12
#endif
/*
**********************************************************************************************************
*                          TBS related Condition compilation
**********************************************************************************************************
*/
#if  defined  HT6x1x ||  defined  HT6x2x  ||  defined  HT6x2xK  ||  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_MCU

#if  defined  HT762x  ||  defined  HT772x
#define  USE_TBS_TPGA
#define  USE_TBS_VTP
#define  USE_TBS_VTPPRD
#define  USE_TBS_TRIREQ_TDVREFTRI
#define  USE_TBS_INJECTCTRL_TDVREF
#define  USE_TBS_TBSCON_TDVREFEn
#define  USE_TBS_TDVREFDAT
#define  USE_TBS_TDVREFCMP
#define  USE_TBS_TBSIF_TDVREFIF  
#define  USE_TBS_TBSIE_TDVREFIE
#define  USE_TBS_TBSIE_VTPIE
#define  USE_TBS_TBSIF_VTPIF
#define  USE_TBS_TBSIE_TDVREFCMPIE
#define  USE_TBS_TBSIF_TDVREFCMPIF
#define  USE_TBS_TBSPRD_TDVREFPRD
#define  USE_TBS_TRIREQ_VTPTRI
#endif

#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT6x2xK  ||  defined HT633x  ||  defined  HT633xH
#define  USE_TBS_TBSINJECTCTRL
#endif

#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT6x2xK
#define  USE_TBS_TBSINJECTCTRL_INJECTCLK
#endif

#if  !defined  HT6x1x
#define  USE_TBS_ADC0CMP
#endif

#if defined HT6x1x
#define USE_TBS_MEMS
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_ADC0CMP
#define  USE_TBS_TBSIE_ADC0CMP
#define  USE_TBS_TBSIF_ADC0CMP
#define  USE_TBS_TBSCON_ADC3
#define  USE_TBS_TBSCON_ADC4
#define  USE_TBS_TBSCON_ADC5
#define  USE_TBS_TBSIE_ADC3
#define  USE_TBS_TBSIE_ADC4
#define  USE_TBS_TBSIE_ADC5
#define  USE_TBS_TBSIF_ADC3
#define  USE_TBS_TBSIF_ADC4
#define  USE_TBS_TBSIF_ADC5
#define  USE_TBS_ADC3DAT
#define  USE_TBS_ADC4DAT
#define  USE_TBS_ADC5DAT
#define  USE_TBS_TBSPRD_ADC3PRD
#define  USE_TBS_TBSPRD_ADC4PRD
#define  USE_TBS_TBSPRD_ADC5PRD
#endif

#if  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_TBSCON_TBSCLKSEL_2BIT
#define  USE_TBS_TBSCON_ADC6
#define  USE_TBS_TBSCON_ADC7
#define  USE_TBS_TBSCON_ADC8
#define  USE_TBS_TBSCON_ADC9
#define  USE_TBS_TBSIE_ADC6
#define  USE_TBS_TBSIE_ADC7
#define  USE_TBS_TBSIE_ADC8
#define  USE_TBS_TBSIE_ADC9
#define  USE_TBS_TBSIF_ADC6
#define  USE_TBS_TBSIF_ADC7
#define  USE_TBS_TBSIF_ADC8
#define  USE_TBS_TBSIF_ADC9
#define  USE_TBS_ADC6DAT
#define  USE_TBS_ADC7DAT
#define  USE_TBS_ADC8DAT
#define  USE_TBS_ADC9DAT
#define  USE_TBS_TBSPRD_ADC6PRD
#define  USE_TBS_TBSPRD_ADC7PRD
#define  USE_TBS_TBSPRD_ADC8PRD
#define  USE_TBS_TBSPRD_ADC9PRD
#define  USE_TBS_ADC6TRI
#define  USE_TBS_ADC7TRI
#define  USE_TBS_ADC8TRI
#define  USE_TBS_ADC9TRI
#define  USE_TBS_INJECTCHEL_SEL_4BIT
#define  USE_HT_CMU_TBSCLKCFG
#endif

#if  defined  HT6x2xK  ||  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_TBSCON_TBSCLKSEL
#endif

#if  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT6x2xK  ||  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_TRIREQ
#endif

#if  defined  HT6x3x  ||  defined  HT633x  ||  defined  HT633xH
#define  USE_TBS_ADCBATEn
#define  USE_TBS_TRIREQ_VBATTRI
#endif

#if defined HT6x2xK
#define USE_TBS_NEWREG_En
#define  USE_TBS_TRIREQ_VBATTRI
#define  USE_TBS_TBSINJECTCTRL_EN
#endif

#endif

#if  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#define  USE_TBS_ADC0CMP
#define  USE_TBS_ADC1CMP
#define  USE_TBS_TBSCON_ADC2
#define  USE_TBS_TBSIE_ADC2
#define  USE_TBS_TBSIF_ADC2
#define  USE_TBS_ADC2DAT
#define  USE_TBS_TBSPRD_ADC2PRD
#define  USE_TBS_SOC

#if  defined  HT503x
#define  USE_TBS_TRIREQ
#define  USE_TBS_TBSCON_TBSCLKSEL
#define  USE_TBS_TBSCON_ADC3
#define  USE_TBS_TBSCON_ADC4
#define  USE_TBS_TBSCON_ADC5
#define  USE_TBS_TBSCON_ADC6
#define  USE_TBS_TBSIE_ADC3
#define  USE_TBS_TBSIE_ADC4
#define  USE_TBS_TBSIE_ADC5
#define  USE_TBS_TBSIE_ADC6
#define  USE_TBS_TBSIF_ADC3
#define  USE_TBS_TBSIF_ADC4
#define  USE_TBS_TBSIF_ADC5
#define  USE_TBS_TBSIF_ADC6
#define  USE_TBS_ADC3DAT
#define  USE_TBS_ADC4DAT
#define  USE_TBS_ADC5DAT
#define  USE_TBS_ADC6DAT
#define  USE_TBS_TBSPRD_ADC3PRD
#define  USE_TBS_TBSPRD_ADC4PRD
#define  USE_TBS_TBSPRD_ADC5PRD
#define  USE_TBS_TBSPRD_ADC6PRD
#define  USE_TBS_TBSINJECTCTRL       
#define  USE_TBS_ADC6TRI
#endif

#endif

/*
**********************************************************************************************************
*                                       TMR related Condition compilation
**********************************************************************************************************
*/

#if  defined  HT6x1x  ||  defined  HT501x

#define USE_TMR_TMRCON_TIMING  

#endif


#if  defined  HT6x3x || defined HT633x || defined HT633xH

#define USE_TMR_PWMMODE
#endif


#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  || defined  HT762x  ||  defined  HT772x || defined  HT633x || defined HT633xH

#define USE_TMR_EXT
#endif


#if  defined  HT6x2x  ||  defined  HT6x2xK
#define USE_TMR_EXTCLK_MEMS 
#endif

#if  defined  HT6x1x  ||  defined  HT501x                
#define USE_TMR_CLEAR_BIT3IF
#endif



# if defined HT762x  ||  defined  HT772x  || defined HT633x || defined HT633xH


#define USE_TMREXT_TRIG

#define USE_TMREXT_CCSTA

#define USE_TMREXT_ADD_FUNC
#define USE_TMREXT_EXTCLK
#define USE_TMREXT_EXTEND_FUNC


#endif




#if defined HT633x || defined HT633xH

#define USE_TMR_CCSTA

#define USE_TMR_DOUBLECAP
#define USE_TMR_OPMODE
#define USE_TMREXT_EXTRIG_SEL

#define USE_TMR_EXTRIGCFG


#endif

#if defined HT633xH

#define USE_TMR4_RANGE


#endif


# if defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined  HT503x || defined HT633x || defined HT633xH
#define USE_TMR_ACIF
#define USE_TMR_RECORD
#endif


#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined HT762x  ||  defined  HT772x  || defined HT633x || defined HT633xH
#define USE_TMRExt_IRQHANDLER
#endif

#if defined HT633x

#define USE_TMR4_IRQHANDLER

#endif

/*
**********************************************************************************************************
*                                       INT(EXTI) related Condition compilation
**********************************************************************************************************
*/
#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x || defined  HT503x || defined HT633x || defined HT633xH
#define USE_INT_EXTIX2 
#endif

#if defined HT633x || defined HT633xH

#define USE_EXTI10_14

#endif

#if defined  HT762x  ||  defined  HT772x
#define USE_EXTI0_6_IRQHANDLER
#endif

#if defined  HT6x2x  ||  defined  HT6x2xK || defined HT502x
#define USE_EXTI7_9_SINGLEIRQHANDLER
#endif


#if defined   HT762x  ||  defined  HT772x ||  defined HT503x || defined HT6x3x || defined HT633x || defined HT633xH
#define USE_EXTI7_9_COMMONIRQHANDLER
#endif

/*
***********************************************************************************************************
*                         ECC related condition compilation
***********************************************************************************************************
*/
#if defined HT502x  ||  defined  HT6x3x  || defined HT503x  
#define USE_ECC
#endif

#if defined HT633x
#define USE_ECC384
#endif

/*
***********************************************************************************************************
*                         CRC related condition compilation
***********************************************************************************************************
*/
#if defined HT6x2x || defined HT6x3x || defined  HT6x2xK  || defined HT503x || defined HT762x  ||  defined  HT772x || defined HT633x 
#define USE_CRC
#endif

/*
***********************************************************************************************************
*                         AES related condition compilation
***********************************************************************************************************
*/
#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x ||  defined  HT502x  ||  defined HT503x  || defined HT762x  ||  defined  HT772x  || defined HT633x
#define USE_ARG
#endif
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined HT502x ||  defined HT503x  || defined HT762x  ||  defined  HT772x || defined HT633x
#define USE_RAND
#endif

#if defined HT6x2x  ||  defined  HT6x3x  
#define USE_RAND_WORKMODE
#endif
#if defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x || defined HT633x
#define USE_RAND_BACKMODE
#endif

/*
***********************************************************************************************************
*                         I2C related condition compilation
***********************************************************************************************************
*/
  
#define USE_I2C


/*
***********************************************************************************************************
*                         KEYSCAN related condition compilation
***********************************************************************************************************
*/
#if defined  HT501x  ||  defined  HT502x  ||  defined  HT503x                    
#define USE_KEYSCAN
#endif

#if  defined  HT503x
#define  USE_CMU_KEYCLKCFG
#endif

/*
***********************************************************************************************************
*                         FRAMPACK related condition compilation
***********************************************************************************************************
*/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x
#define USE_PACK
#endif
/*
***********************************************************************************************************
*                         EMU related condition compilation
***********************************************************************************************************
*/
#if defined  HT501x  ||  defined  HT502x   ||  defined  HT503x ||  defined  HT762x  ||  defined  HT772x 		
#define	USE_EMU
#endif

/*
***********************************************************************************************************
*                         WDT related condition compilation
***********************************************************************************************************
*/
#if defined  HT633x
#define USE_WDTCFG_LPOVT
#endif


/**
* @brief  General Bool State
*/
typedef enum {DISABLE = 0, ENABLE = !DISABLE}   FunctionalState;        
typedef enum {RESET   = 0, SET    = !RESET  }   FlagStatus, ITStatus;   /* used for status or interrupt flag */
typedef enum {FALSE   = 0, TRUE   = !FALSE  }   Bool;                   /* used for function return */

/*
**********************************************************************************************************
*                                       Interrupt Number Definition
**********************************************************************************************************
*/
typedef enum IRQn
{
/*****************************  Cortex-M0 Processor Exceptions Numbers  *********************************/
    NonMaskableInt_IRQn         = -14,      /*!< 2 Non Maskable Interrupt  CMU                    */
    HardFault_IRQn              = -13,      /*!< 3 Cortex-M0 Hard Fault Interrupt                 */
    SVCall_IRQn                 = -5,       /*!< 11 Cortex-M0 SV Call Interrupt                   */
    PendSV_IRQn                 = -2,       /*!< 14 Cortex-M0 Pend SV Interrupt                   */
    SysTick_IRQn                = -1,       /*!< 15 Cortex-M0 System Tick Interrupt               */

/*****************************  HT6xxx Specific Interrupt Numbers  **************************************/
    PMU_IRQn                    = 0,        /*!< PMU Interrupt                                    */
#if defined  HT6x1x
    TDES_IRQn                   = 1,        /*!< 3DES Interrupt                                   */
#elif defined  HT6x2xK
                                            /*!< Reserved                                         */
#else
    AES_IRQn                    = 1,        /*!< AES Interrupt                                    */
                                            /*!<   HT6x2x: includ AES, RAND, GHASH                */
                                            /*!<   HT6x3x: includ AES, RAND, GHASH, ECC           */
                                            /*!<   HT501x: includ AES, GHASH                      */
                                            /*!<   HT502x: includ AES, RAND, GHASH, ECC           */
#endif
    EXTI0_IRQn                  = 2,        /*!< External Interrupt 0 Interrupt                   */
#if defined  HT762x  ||  defined  HT772x
    EXTI1_3_IRQn                = 3,        /*!< External Interrupt 1-3 Interrupt                   */
    FFT_IRQn                    = 4,        /*!< EFFT Interrupt                                   */
    EXTI4_6_IRQn                = 6,        /*!< External Interrupt 4 Interrupt                   */
    EMU_IRQn                    = 7,        /*!< EMU Interrupt                                    */
    EWU_IRQn                    = 8,        /*!< EWU Interrupt               	                  */	
#else	
    EXTI1_IRQn                  = 3,        /*!< External Interrupt 1 Interrupt                   */
    EXTI2_IRQn                  = 4,        /*!< External Interrupt 2 Interrupt                   */
    EXTI3_IRQn                  = 5,        /*!< External Interrupt 3 Interrupt                   */
    EXTI4_IRQn                  = 6,        /*!< External Interrupt 4 Interrupt                   */
    EXTI5_IRQn                  = 7,        /*!< External Interrupt 5 Interrupt                   */
    EXTI6_IRQn                  = 8,        /*!< External Interrupt 6 Interrupt                   */
#endif
    UART0_IRQn                  = 9,        /*!< UART0 Interrupt                                  */
    UART1_IRQn                  = 10,       /*!< UART1 Interrupt                                  */
    UART2_IRQn                  = 11,       /*!< UART2 Interrupt                                  */
    UART3_IRQn                  = 12,       /*!< UART3 Interrupt                                  */
    UART4_IRQn                  = 13,       /*!< UART4 Interrupt                                  */
    UART5_IRQn                  = 14,       /*!< UART5 Interrupt                                  */
    TIMER_0_IRQn                = 15,       /*!< Timer0 Interrupt                                 */
    TIMER_1_IRQn                = 16,       /*!< Timer1 Interrupt                                 */
    TIMER_2_IRQn                = 17,       /*!< Timer2 Interrupt                                 */
    TIMER_3_IRQn                = 18,       /*!< Timer3 Interrupt                                 */
    TBS_IRQn                    = 19,       /*!< TBS Interrupt                                    */
    RTC_IRQn                    = 20,       /*!< RTC Interrupt                                    */
    I2C_IRQn                    = 21,       /*!< I2C Converter Interrupt                          */
    SPI0_IRQn                   = 22,       /*!< SPI0 Interrupt                                   */
#if   defined HT6x1x
    WDT_IRQn                    = 23,       /*!< WDT Interrupt                                    */
#elif defined HT501x
    EMU_IRQn                    = 25,       /*!< EMU Interrupt                                    */
    DMA_IRQn                    = 26,       /*!< DMA Interrupt                                    */
    KEY_IRQn                    = 27,       /*!< KEY Scan Interrupt                               */
#elif defined HT502x
    EMU_IRQn                    = 25,       /*!< EMU Interrupt                                    */
    DMA_IRQn                    = 26,       /*!< DMA Interrupt                                    */
    KEY_IRQn                    = 27,       /*!< KEY Scan Interrupt                               */
    EXTI7_IRQn                  = 28,       /*!< External Interrupt 7 Interrupt                   */
    EXTI8_IRQn                  = 29,       /*!< External Interrupt 8 Interrupt                   */
    EXTI9_IRQn                  = 30,       /*!< External Interrupt 9 Interrupt                   */
#elif defined HT6x2x
    SPI1_IRQn                   = 23,       /*!< SPI1 Interrupt                                   */
    SelfTestF_IRQn              = 24,       /*!< SelfTestF Interrupt                              */
    TIMER_4_IRQn                = 25,       /*!< Timer4 Interrupt                                 */
    TIMER_5_IRQn                = 26,       /*!< Timer5 Interrupt                                 */
    UART6_IRQn                  = 27,       /*!< UART6 Interrupt                                  */
    EXTI7_IRQn                  = 28,       /*!< External Interrupt 7 Interrupt                   */
    EXTI8_IRQn                  = 29,       /*!< External Interrupt 8 Interrupt                   */
    EXTI9_IRQn                  = 30,       /*!< External Interrupt 9 Interrupt                   */
    DMA_IRQn                    = 31,       /*!< DMA Interrupt                                    */
#elif defined HT6x2xK
    SPI1_IRQn                   = 23,       /*!< SPI1 Interrupt                                   */
    SelfTestF_IRQn              = 24,       /*!< SelfTestF Interrupt                              */
    TIMER_4_IRQn                = 25,       /*!< Timer4 Interrupt                                 */
    TIMER_5_IRQn                = 26,       /*!< Timer5 Interrupt                                 */
    SPI3_IRQn                   = 27,       /*!< SPI3 Interrupt                                   */
    EXTI7_IRQn                  = 28,       /*!< External Interrupt 7 Interrupt                   */
    EXTI8_IRQn                  = 29,       /*!< External Interrupt 8 Interrupt                   */
    EXTI9_IRQn                  = 30,       /*!< External Interrupt 9 Interrupt                   */
    DMA_IRQn                    = 31,       /*!< DMA Interrupt                                    */
#elif defined  HT762x  ||  defined  HT772x
    SPI1_IRQn                 	= 23,       /*!< SPI1 Interrupt                                   */
    SelfTestF_IRQn              = 24,       /*!< SelfTestF Interrupt                              */
    TIMER_4_IRQn                = 25,       /*!< Timer4 Interrupt                                 */
    TIMER_5_IRQn                = 26,       /*!< Timer5 Interrupt                                 */
    UART6_IRQn                	= 27,       /*!< UART6 Interrupt                                  */
    EXTI7_9_IRQn              	= 28,       /*!< External Interrupt 7-9 Interrupt                 */
    SPI3_IRQn                 	= 29,       /*!< SPI3 Interrupt                                   */
    SPI2_IRQn                 	= 30,       /*!< SPI2 Interrupt                                   */
    DMA_IRQn                    = 31,       /*!< DMA Interrupt                                    */
#elif defined HT6x3x  ||  defined HT633x
    SPI1_IRQn                   = 23,       /*!< SPI1 Interrupt                                   */
    SelfTestF_IRQn              = 24,       /*!< SelfTestF Interrupt                              */
    TIMER_4_IRQn                = 25,       /*!< Timer4 Interrupt                                 */
    TIMER_5_IRQn                = 26,       /*!< Timer5 Interrupt                                 */
    UART6_IRQn                  = 27,       /*!< UART6 Interrupt                                  */
    EXTI7_9_IRQn              	= 28,       /*!< External Interrupt 7-9 Interrupt                 */
    Reserved_IRQn				= 29,		/*!< Reserved Interrupt                               */
    SPI2_IRQn                   = 30,       /*!< SPI2 Interrupt                                   */
    DMA_IRQn                    = 31,       /*!< DMA Interrupt                                    */
#elif defined HT503x		
    SPI1_IRQn               	= 23,       /*!< SPI1 Interrupt                                   */
    SelfTestF_IRQn              = 24,       /*!< SelfTestF Interrupt                              */
    EMU_IRQn                    = 25,       /*!< EMU Interrupt                                    */
    DMA_IRQn                    = 26,       /*!< DMA Interrupt                                    */
    KEY_IRQn                    = 27,       /*!< KEY Scan Interrupt                               */
    EXTI7_9_IRQn                = 28,       /*!< External Interrupt 7-9 Interrupt                 */
    UART6_IRQn                  = 29,       /*!< UART6 Interrupt                                  */
    SPI2_IRQn                   = 30,       /*!< SPI2 Interrupt                                   */
    FRAM_IRQn                   = 31,       /*!< FRAM Interrupt                                    */		
#endif
#if defined HT633x
    LPUART_IRQn                 = 32,       /*!< LPUART Interrupt                                 */
    EXTI10_14_IRQn              = 33,       /*!< External Interrupt 10-14 Interrupt               */
    SPI3_IRQn                   = 35,       /*!< SPI3 Interrupt                                   */
#endif
} IRQn_Type;

/*
**********************************************************************************************************
*                                   Processor and Core Peripheral Section
**********************************************************************************************************
*/

/********************  Configuration of the Cortex-M0 Processor and Core Peripherals  *******************/
#define __MPU_PRESENT             0         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
                                            /* end of group HT60xx_CMSIS                          */
#if defined HT633x
#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals           */
#else
#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals           */
#endif
#include <stdint.h>                         /* standard types definitions                         */


/*
**********************************************************************************************************
*                                 Device Specific Peripheral Registers structures
**********************************************************************************************************
*/
#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


/*****************************************  Timer Control Block  *****************************************/
/**
* @brief  Timer register definition
*/
typedef struct
{
    __IO uint32_t TMRCON;                   /*!< Offset: 0x000 control register      (R/W) */
    __IO uint32_t TMRDIV;                   /*!< Offset: 0x004 Prescaler register    (R/W) */
    __IO uint32_t TMRPRD;                   /*!< Offset: 0x008 Period register      (R/W) */
    __IO uint32_t TMRCAP;                   /*!< Offset: 0x00C Capture data register  (R/W) */
    __IO uint32_t TMRCNT;                   /*!< Offset: 0x010 Counter register    (R/W) */
    __IO uint32_t TMRCMP;                   /*!< Offset: 0x014 Comparator register    (R/W) */
    __IO uint32_t TMRIE;                    /*!< Offset: 0x018 Interrupt enable register  (R/W) */
    __IO uint32_t TMRIF;                    /*!< Offset: 0x01C Interrupt flag register  (R/W) */
#if defined  HT6x3x || defined HT633x || defined HT633xH
    __IO uint32_t TMRCODT;                  /*!< Offset: 0x020 Complementary output and dead zone control register(R/W) */
    __IO uint32_t TMRRDT;                   /*!< Offset: 0x024 Dead time register      (R/W) */
#else
	 __I  uint32_t Reserved[2];
#endif
# if defined  HT762x  ||  defined  HT772x || defined HT633x
   __IO uint32_t TMRTRIGERCFG;             /*!< Offset: 0x028 Timer 5 trigger source configuration register (R/W) */
   __IO uint32_t TMRCFG;                   /*!< Offset: 0x02C Timer 4/5 function configuration register      (R/W) */
   __IO uint32_t TMREXTRIGCFG;             /*!< Offset: 0x030 Timer 4/5 trigger signal selection register  (R/W) */
#endif		
} HT_TMR_TypeDef;                           /* end of group HT_TMR_TypeDef               */


/*****************************************  UART Control Block  ******************************************/
/**
* @brief  UART register definition
*/
typedef struct
{
    __IO uint32_t MODESEL;                  /*!< Offset: 0x000 UART/7816 fuunction select register      (R/W) */
    __IO uint32_t UARTCON;                  /*!< Offset: 0x004 Serial port function configuration register           (R/W) */
    __IO uint32_t ISO7816CON;               /*!< Offset: 0x008 7816function configuration register           (R/W) */
    __IO uint32_t SREL;                     /*!< Offset: 0x00C Serial port/7816 baud rate generator over value   (R/W) */
    __IO uint32_t SBUF;                     /*!< Offset: 0x010 Serial port/7816 data buffer register      (R/W) */
    __IO uint32_t UARTSTA;                  /*!< Offset: 0x014 Serial port status register               (R/W) */
    __IO uint32_t ISO7816STA;               /*!< Offset: 0x018 7816status register               (R/W) */
    __I  uint32_t Reserved[5];
    __IO uint32_t IRCON;                    /*!< Offset: 0x030 IR modulation control register            (R/W) */
    __IO uint32_t IRDUTY;                   /*!< Offset: 0x034 IR modulation pulse width adjustment register        (R/W) */
#if defined  USE_LOGDETNUM
    __IO uint32_t LOGDETNUM;                /*!< Offset: 0x038 Positive and negative logical data length settings   (R/W) */
#elif defined  USE_NEGDETLEN
    __IO uint32_t NEGDETLEN;                /*!< Offset: 0x038 485 logic positive and negative automatic judgment data length settings (R/W) */
#elif defined  USE_UART_IRCLKDIV
    __IO uint32_t NEGDETLEN;                /*!< Offset: 0x038 485 logic positive and negative automatic judgment data length settings (R/W) */
    __I  uint32_t Reserved2;	
    __IO uint32_t IRCLKDIV;                 /*!< Offset: 0x040 38K infrared modulated signal source frequency division register    (R/W) */
#elif defined  USE_UART_IR38KDIV
    __IO uint32_t NEGDETLEN;                /*!< Offset: 0x038 485 logic positive and negative automatic judgment data length settings (R/W) */
    __I  uint32_t Reserved2;	
    __IO uint32_t IR38KDIV;                 /*!< Offset: 0x040 38K infrared modulated signal source frequency division register    (R/W) */
#endif
} HT_UART_TypeDef, HT_ISO7816_TypeDef;      /* end of group HT_UART_TypeDef, HT_ISO7816_TypeDef */


/*****************************************  I2C Control Block  *******************************************/
/**
* @brief  I2C Register definition
*/
typedef struct
{
    __IO uint32_t I2CDAT;                   /*!< Offset: 0x000 I2C data register (R/W) */
    __IO uint32_t I2CADR;                   /*!< Offset: 0x004 I2C address register (R/W) */
    __IO uint32_t I2CCON;                   /*!< Offset: 0x008 I2C control register (R/W) */
    __IO uint32_t I2CSTA;                   /*!< Offset: 0x00C I2C status register (R/W) */
} HT_I2C_TypeDef;                           /* end of group HT_I2C_TypeDef         */


/*****************************************  SPI Control Block  *******************************************/
/**
* @brief  SPI Register definition
*/
typedef struct
{
    __IO uint32_t SPICON;                   /*!< Offset: 0x000 SPI Control Register      (R/W) */
    __IO uint32_t SPISTA;                   /*!< Offset: 0x004 SPI Status  Register      (R/W) */
    __IO uint32_t SPIDAT;                   /*!< Offset: 0x008 SPI Data    Register      (R/W) */
    __IO uint32_t SPISSN;                   /*!< Offset: 0x00C SPI Slave Select Register (R/W) */
#if defined  HT6x2x  ||  defined  HT6x2xK  || defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
    __I  uint32_t Reserved;
    __IO uint32_t CSDLY;                    /*!< Offset: 0x014 SPI CS/Delya Control Register (R/W) */   
	                                        /*!<This register only supports HT6x2x H and later versions */
#endif
#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
    __I  uint32_t Reserved1[6];
    __IO uint32_t FIFOCON;                  /*!< Offset: 0x030 SPI FIFO Control Register (R/W)           */
    __IO uint32_t FIFOIE;                   /*!< Offset: 0x034 SPI FIFO Interrupt Enable Register  (R/W) */
    __IO uint32_t FIFOIF;                   /*!< Offset: 0x038 SPI FIFO Interrupt Flag Register    (R/W) */
    __IO uint32_t BDLY;                     /*!< Offset: 0x03C Word Interval Configuration Register(R/W) */
    __IO uint32_t RXFIFOSTA;                /*!< Offset: 0x040 Receive the FIFO Status Register    (R/W) */
    __IO uint32_t TXFIFOSTA;                /*!< Offset: 0x044 Send the FIFO Status Register       (R/W) */	
#endif
#if defined  HT6x3x
    __IO uint32_t SPIDIV;                   /*!< Offset: 0x010 SPI Frequency Division Auxiliary Control Register (R/W) */
    __I  uint32_t Reserved2[8*16*4-5];
    __IO uint32_t SPICLKSEL;                /*!< Offset: 0x800 SPI2 Clock Source Selection Register (R/W) */
#endif
#if defined  HT633x
    __IO uint32_t SPIDIV;                   /*!< Offset: 0x010 SPI Frequency Division Auxiliary Control Register (R/W) */
#endif
} HT_SPI_TypeDef;                           /* end of group HT_SPI_TypeDef             */


/*****************************************  RTC Control Block  *******************************************/
/**
* @brief  RTC Register definition
*/
typedef struct
{
    __IO uint32_t RTCCON;                   /*!< Offset: 0x000 RTC Control Register (R/W)              */
    __IO uint32_t RTCIE;                    /*!< Offset: 0x004 RTC Interrupt Enable Register  (R/W)    */
    __IO uint32_t RTCIF;                    /*!< Offset: 0x008 RTC Interrupt Flag   Register  (R/W)    */
    __IO uint32_t ALMR;                     /*!< Offset: 0x00C RTC Alarm  Register (R/W)               */
    __IO uint32_t RTCTMR1;                  /*!< Offset: 0x010 RTC Timer1 Register (R/W)               */
    __IO uint32_t RTCTMR2;                  /*!< Offset: 0x014 RTC Timer2 Register (R/W)               */
    __IO uint32_t SECR;                     /*!< Offset: 0x018 RTC Second Register (R/W)               */
    __IO uint32_t MINR;                     /*!< Offset: 0x01C RTC Minute Register (R/W)               */
    __IO uint32_t HOURR;                    /*!< Offset: 0x020 RTC Hour   Register (R/W)               */
    __IO uint32_t DAYR;                     /*!< Offset: 0x024 RTC Day    Register (R/W)               */
    __IO uint32_t MONTHR;                   /*!< Offset: 0x028 RTC Month  Register (R/W)               */
    __IO uint32_t YEARR;                    /*!< Offset: 0x02C RTC Year   Register (R/W)               */
    __IO uint32_t WEEKR;                    /*!< Offset: 0x030 RTC Week   Register (R/W)               */
    __IO uint32_t RTCCNTH;                  /*!< Offset: 0x034 RTC Calibration Register to High 16 bits (R/W) */
    __IO uint32_t RTCCNTL;                  /*!< Offset: 0x038 RTC Calibration Register to Low  16 bits (R/W) */
    __IO uint32_t RTCRD;                    /*!< Offset: 0x03C RTC Read  Control Register (R/W)        */
    __IO uint32_t RTCWR;                    /*!< Offset: 0x040 RTC Write Control Register (R/W)        */
    __I  uint32_t Reserved[3];
    __IO uint32_t DFAH;                     /*!< Offset: 0x050 Mems Clock Frequency Constant  Term to High 7 bits  (R/W) */
    __IO uint32_t DFAL;                     /*!< Offset: 0x054 Mems Clock Frequency Constant  Term to Low  16 bits (R/W) */
    __IO uint32_t DFBH;                     /*!< Offset: 0x058 Mems Clock Frequency Primary   Term to High 7 bits  (R/W) */
    __IO uint32_t DFBL;                     /*!< Offset: 0x05C Mems Clock Frequency Primary   Term to Low  16 bits (R/W) */ 
    __IO uint32_t DFCH;                     /*!< Offset: 0x060 Mems Clock Frequency Quadratic Term to High 7 bits  (R/W) */
    __IO uint32_t DFCL;                     /*!< Offset: 0x064 Mems Clock Frequency Quadratic Term to Low  16 bits (R/W) */ 
    __IO uint32_t DFDH;                     /*!< Offset: 0x068 Mems Clock Frequency Cubic     Term to High 7 bits  (R/W) */
    __IO uint32_t DFDL;                     /*!< Offset: 0x06C Mems Clock Frequency Cubic     Term to Low  16 bits (R/W) */ 
    __IO uint32_t DFEH;                     /*!< Offset: 0x070 Mems Clock Frequency Quartic   Term to High 7 bits  (R/W) */
    __IO uint32_t DFEL;                     /*!< Offset: 0x074 Mems Clock Frequency Quartic   Term to Low  16 bits (R/W) */ 
    __IO uint32_t Toff;                     /*!< Offset: 0x078 Temperature Offset Register (R/W)       */
#if defined  HT503x	
	__I  uint32_t Reserved1[2];            
#else
    __IO uint32_t MCON01;                   /*!< Offset: 0x07C Mems01 Control Register (R/W)                  */
    __IO uint32_t MCON23;                   /*!< Offset: 0x080 Mems23 Control Register (R/W)                  */
#endif
    __IO uint32_t MCON45;                   /*!< Offset: 0x084 Mems45 Control Register  (R/W)                 */
    __IO uint32_t DFIH;                     /*!< Offset: 0x088 Frequency Error Register to High 5 bits (R/W)  */
    __IO uint32_t DFIL;                     /*!< Offset: 0x08C Frequency Error Register to Low  16 bits (R/W) */
    __IO uint32_t RTCRSTFLG;                /*!< Offset: 0x090 RTC Module Reset Flag Register (R/W)           */
    __IO uint32_t RTCRSTSET;                /*!< Offset: 0x094 RTC Write Reset Register (R/W)                 */
#if defined  HT6x1x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
    __I  uint32_t Reserved2[22];
#elif defined  HT6x2x  ||  defined  HT6x2xK
    __I  uint32_t RTCCHKSUM;                /*!< Offset: 0x098 RTC Checksum Register (R/W)                    */
    __I  uint32_t Reserved2[13];
    __IO uint32_t HRa;                      /*!< Offset: 0x0D0 HRC1Hz Compensation Constant  Term (R/W)        */
    __IO uint32_t HRb;                      /*!< Offset: 0x0D4 HRC1Hz Compensation Primary   Term (R/W)        */
    __IO uint32_t HRc;                      /*!< Offset: 0x0D8 HRC1Hz Compensation Quadratic Term (R/W)        */
    __IO uint32_t HRd;                      /*!< Offset: 0x0DC HRC1Hz Compensation Cubic     Term (R/W)        */
    __IO uint32_t HRe;                      /*!< Offset: 0x0E0 HRC1Hz Compensation Quartic   Term (R/W)        */
    __IO uint32_t HDFi;                     /*!< Offset: 0x0E4 HRC1Hz Frequency Error Register    (R/W)        */
    __I  uint32_t Reserved3[2];
#elif defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x 
    __IO uint32_t RTCCHKSUM;                /*!< Offset: 0x098 RTC Checksum Register (R/W)                     */
    __I  uint32_t Reserved2[21];
#endif
    __IO uint32_t HFCFG;                    /*!< Offset: 0x0F0 Frequency Measurement module Configuration Register (R/W)*/
    __IO uint32_t HFNUM;                    /*!< Offset: 0x0F4 Set the Number of Measuring Frequency Pluse Cycle   (R/W)*/
    __IO uint32_t HFCNTH;                   /*!< Offset: 0x0F8 The Number of Measured Frequency Register to High 16 bits (R/W)*/
    __IO uint32_t HFCNTL;                   /*!< Offset: 0x0FC The Number of Measured Frequency Register to Low  16 bits (R/W)*/
#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  || defined  HT503x  || defined  HT633x 
    __IO uint32_t CTRLBYFLASH;              /*!< Offset: 0x100 This Register is not Open to the User (R/W)      */
    __IO uint32_t LRCCOMAND;                /*!< Offset: 0x104 This Register is not Open to the User (R/W)      */
#if defined  HT6x2xK  ||  defined  HT633x
    __I  uint32_t Reserved4[2];
    __IO uint32_t CALENDARCLR;              /*!< Offset: 0x110 This Register is not Open to the User (R/W)      */
#elif defined  HT762x  ||  defined  HT772x
    __I  uint32_t Reserved4[2];
    __IO uint32_t CALENDARCLR;              /*!< Offset: 0x110 This Register is not Open to the User (R/W)      */
#elif defined  HT503x		
	__I  uint32_t Reserved4;            	/*!< Offset: 0x108 This Register is not Open to the User (R/W)      */
	__IO uint32_t RTCTESTCTRL;         		/*!< Offset: 0x10C RTC Test Control Register             (R/W)      */  
	__I  uint32_t Reserved5;  		
#else
	__I  uint32_t Reserved4[3];
#endif
#endif
#if defined  HT762x  ||  defined  HT772x
	__I  uint32_t Reserved5[3+14*4+16*4];
   	__IO uint32_t RTCTS0CON;                /*!< Offset: 0x300 RTC Timestamp0 Control Register               (R/W) */
    __IO uint32_t RTCTS0CMP;                /*!< Offset: 0x304 RTC Timestamp0 Event Comparison Register      (R/W) */
    __I  uint32_t RTCTS0CNT;                /*!< Offset: 0x308 RTC Timestamp0 Event Count Register           (R  ) */
    __IO uint32_t RTCTS0IE;                 /*!< Offset: 0x30C RTC Timestamp0 Interrupt Enable Register      (R/W) */
    __IO uint32_t RTCTS0IF;                 /*!< Offset: 0x310 RTC Timestamp0 Interrupt Flag Register        (R/W) */
    __I  uint32_t RTCTS0TIM0;               /*!< Offset: 0x314 RTC Timestamp0 Time Cache Register0           (R  ) */
    __I  uint32_t RTCTS0DAT0;               /*!< Offset: 0x318 RTC Timestamp0 Date Cache Register0           (R  ) */
    __I  uint32_t RTCTS0SOU0;               /*!< Offset: 0x31C RTC Timestamp0 Triggers Source Cache Register0(R  ) */
    __I  uint32_t RTCTS0TIM1;               /*!< Offset: 0x320 RTC Timestamp0 Time Cache Register1           (R  ) */
    __I  uint32_t RTCTS0DAT1;               /*!< Offset: 0x324 RTC Timestamp0 Date Cache Register1           (R  ) */
    __I  uint32_t RTCTS0SOU1;               /*!< Offset: 0x328 RTC Timestamp0 Triggers Source Cache Register1(R  ) */
    __I  uint32_t RTCTS0TIM2;               /*!< Offset: 0x32C RTC Timestamp0 Time Cache Register2           (R  ) */
    __I  uint32_t RTCTS0DAT2;               /*!< Offset: 0x330 RTC Timestamp0 Date Cache Register2           (R  ) */
    __I  uint32_t RTCTS0SOU2;               /*!< Offset: 0x334 RTC Timestamp0 Triggers Source Cache Register2(R  ) */
    __I  uint32_t RTCTS0TIM3;               /*!< Offset: 0x338 RTC Timestamp0 Time Cache Register3           (R  ) */
    __I  uint32_t RTCTS0DAT3;               /*!< Offset: 0x33C RTC Timestamp0 Date Cache Register3           (R  ) */
    __I  uint32_t RTCTS0SOU3;               /*!< Offset: 0x340 RTC Timestamp0 Triggers Source Cache Register3(R  ) */
    __I  uint32_t RTCTS0TIM4;               /*!< Offset: 0x344 RTC Timestamp0 Time Cache Register4           (R  ) */
    __I  uint32_t RTCTS0DAT4;               /*!< Offset: 0x348 RTC Timestamp0 Date Cache Register4           (R  ) */
    __I  uint32_t RTCTS0SOU4;               /*!< Offset: 0x34C RTC Timestamp0 Triggers Source Cache Register4(R  ) */
    __I  uint32_t RTCTS0TIM5;               /*!< Offset: 0x344 RTC Timestamp0 Time Cache Register5           (R  ) */
    __I  uint32_t RTCTS0DAT5;               /*!< Offset: 0x354 RTC Timestamp0 Date Cache Register5           (R  ) */
    __I  uint32_t RTCTS0SOU5;               /*!< Offset: 0x358 RTC Timestamp0 Triggers Source Cache Register5(R  ) */
    __I  uint32_t Reserved6[10*4+1];
    __IO uint32_t RTCTS1CON;                /*!< Offset: 0x400 RTC Timestamp1 Control Register               (R/W) */
    __IO uint32_t RTCTS1CMP;                /*!< Offset: 0x404 RTC Timestamp1 Event Comparison Register      (R/W) */
    __I  uint32_t RTCTS1CNT;                /*!< Offset: 0x408 RTC Timestamp1 Event Count Register           (R  ) */
    __IO uint32_t RTCTS1IE;                 /*!< Offset: 0x40C RTC Timestamp1 Interrupt Enable Register      (R/W) */
    __IO uint32_t RTCTS1IF;                 /*!< Offset: 0x410 RTC Timestamp1 Interrupt Flag Register        (R/W) */
    __I  uint32_t RTCTS1TIM0;               /*!< Offset: 0x414 RTC Timestamp1 Time Cache Register0           (R  ) */
    __I  uint32_t RTCTS1DAT0;               /*!< Offset: 0x418 RTC Timestamp1 Date Cache Register0           (R  ) */
    __I  uint32_t RTCTS1SOU0;               /*!< Offset: 0x41C RTC Timestamp1 Triggers Source Cache Register0(R  ) */
    __I  uint32_t RTCTS1TIM1;               /*!< Offset: 0x420 RTC Timestamp1 Time Cache Register1           (R  ) */
    __I  uint32_t RTCTS1DAT1;               /*!< Offset: 0x424 RTC Timestamp1 Date Cache Register1           (R  ) */
    __I  uint32_t RTCTS1SOU1;               /*!< Offset: 0x428 RTC Timestamp1 Triggers Source Cache Register1(R  ) */
    __I  uint32_t RTCTS1TIM2;               /*!< Offset: 0x42C RTC Timestamp1 Time Cache Register2           (R  ) */
    __I  uint32_t RTCTS1DAT2;               /*!< Offset: 0x430 RTC Timestamp1 Date Cache Register2           (R  ) */
    __I  uint32_t RTCTS1SOU2;               /*!< Offset: 0x434 RTC Timestamp1 Triggers Source Cache Register2(R  ) */
    __I  uint32_t RTCTS1TIM3;               /*!< Offset: 0x438 RTC Timestamp1 Time Cache Register3           (R  ) */
    __I  uint32_t RTCTS1DAT3;               /*!< Offset: 0x43C RTC Timestamp1 Date Cache Register3           (R  ) */
    __I  uint32_t RTCTS1SOU3;               /*!< Offset: 0x440 RTC Timestamp1 Triggers Source Cache Register3(R  ) */
    __I  uint32_t RTCTS1TIM4;               /*!< Offset: 0x444 RTC Timestamp1 Time Cache Register4           (R  ) */
    __I  uint32_t RTCTS1DAT4;               /*!< Offset: 0x448 RTC Timestamp1 Date Cache Register4           (R  ) */
    __I  uint32_t RTCTS1SOU4;               /*!< Offset: 0x44C RTC Timestamp1 Triggers Source Cache Register4(R  ) */
    __I  uint32_t RTCTS1TIM5;               /*!< Offset: 0x450 RTC Timestamp1 Time Cache Register5           (R  ) */
    __I  uint32_t RTCTS1DAT5;               /*!< Offset: 0x454 RTC Timestamp1 Date Cache Register5           (R  ) */
    __I  uint32_t RTCTS1SOU5;               /*!< Offset: 0x458 RTC Timestamp1 Triggers Source Cache Register5(R  ) */
    __I  uint32_t Reserved7[64*9+4*10+1];
    __IO uint32_t RTCBACKUP[32];            /*!< Offset: 0xE00 RTC Backup Register                           (R/W) */	
#elif  defined  HT503x	
	__I  uint32_t Reserved6[69];
#elif  defined  HT633x
	__I  uint32_t Reserved5[3+14*4+16*4];
   	__IO uint32_t RTCTS0CON;                /*!< Offset: 0x300 RTC Timestamp0 Control Register               (R/W) */
    __IO uint32_t RTCTS0CMP;                /*!< Offset: 0x304 RTC Timestamp0 Event Comparison Register      (R/W) */
    __I  uint32_t RTCTS0CNT;                /*!< Offset: 0x308 RTC Timestamp0 Event Count Register           (R  ) */
    __IO uint32_t RTCTS0IE;                 /*!< Offset: 0x30C RTC Timestamp0 Interrupt Enable Register      (R/W) */
    __IO uint32_t RTCTS0IF;                 /*!< Offset: 0x310 RTC Timestamp0 Interrupt Flag Register        (R/W) */
    __I  uint32_t RTCTS0TIM0;               /*!< Offset: 0x314 RTC Timestamp0 Time Cache Register0           (R  ) */
    __I  uint32_t RTCTS0DAT0;               /*!< Offset: 0x318 RTC Timestamp0 Date Cache Register0           (R  ) */
    __I  uint32_t RTCTS0SOU0;               /*!< Offset: 0x31C RTC Timestamp0 Triggers Source Cache Register0(R  ) */
    __I  uint32_t RTCTS0TIM1;               /*!< Offset: 0x320 RTC Timestamp0 Time Cache Register1           (R  ) */
    __I  uint32_t RTCTS0DAT1;               /*!< Offset: 0x324 RTC Timestamp0 Date Cache Register1           (R  ) */
    __I  uint32_t RTCTS0SOU1;               /*!< Offset: 0x328 RTC Timestamp0 Triggers Source Cache Register1(R  ) */
    __I  uint32_t RTCTS0TIM2;               /*!< Offset: 0x32C RTC Timestamp0 Time Cache Register2           (R  ) */
    __I  uint32_t RTCTS0DAT2;               /*!< Offset: 0x330 RTC Timestamp0 Date Cache Register2           (R  ) */
    __I  uint32_t RTCTS0SOU2;               /*!< Offset: 0x334 RTC Timestamp0 Triggers Source Cache Register2(R  ) */
    __I  uint32_t RTCTS0TIM3;               /*!< Offset: 0x338 RTC Timestamp0 Time Cache Register3           (R  ) */
    __I  uint32_t RTCTS0DAT3;               /*!< Offset: 0x33C RTC Timestamp0 Date Cache Register3           (R  ) */
    __I  uint32_t RTCTS0SOU3;               /*!< Offset: 0x340 RTC Timestamp0 Triggers Source Cache Register3(R  ) */
    __I  uint32_t RTCTS0TIM4;               /*!< Offset: 0x344 RTC Timestamp0 Time Cache Register4           (R  ) */
    __I  uint32_t RTCTS0DAT4;               /*!< Offset: 0x348 RTC Timestamp0 Date Cache Register4           (R  ) */
    __I  uint32_t RTCTS0SOU4;               /*!< Offset: 0x34C RTC Timestamp0 Triggers Source Cache Register4(R  ) */
    __I  uint32_t RTCTS0TIM5;               /*!< Offset: 0x344 RTC Timestamp0 Time Cache Register5           (R  ) */
    __I  uint32_t RTCTS0DAT5;               /*!< Offset: 0x354 RTC Timestamp0 Date Cache Register5           (R  ) */
    __I  uint32_t RTCTS0SOU5;               /*!< Offset: 0x358 RTC Timestamp0 Triggers Source Cache Register5(R  ) */
    __I  uint32_t Reserved6[64*11-23];
    __IO uint32_t RTCBACKUP[16];            /*!< Offset: 0xE00 RTC Backup Register                           (R/W) */
#else
    __I  uint32_t Reserved8[59];
    __IO uint32_t SECR2;                    /*!< Offset: 0x200 RTC2 Second Register (R/W)               */
    __IO uint32_t MINR2;                    /*!< Offset: 0x204 RTC2 Minute Register (R/W)               */
    __IO uint32_t HOURR2;                   /*!< Offset: 0x208 RTC2 Hour   Register (R/W)               */
    __IO uint32_t DAYR2;                    /*!< Offset: 0x20C RTC2 Day    Register (R/W)               */
    __IO uint32_t MONTHR2;                  /*!< Offset: 0x210 RTC2 Month  Register (R/W)               */
    __IO uint32_t YEARR2;                   /*!< Offset: 0x214 RTC2 Year   Register (R/W)               */
    __IO uint32_t WEEKR2;                   /*!< Offset: 0x218 RTC2 Week   Register (R/W)               */
    __IO uint32_t RTC2CAL;                  /*!< Offset: 0x21C LRC Timing  Adjustment Register (R/W)    */
    __IO uint32_t RTCRD2;                   /*!< Offset: 0x220 RTC Read Control Register (R/W )         */
    __IO uint32_t RTCWR2;                   /*!< Offset: 0x224 RTC Write Control Register (R/W )        */
#endif
#if defined  HT501x  ||  defined  HT502x
    __IO uint32_t FRE_LRC;                  /*!< Offset: 0x228 LRC Frequency Measurement (R)            */
#endif
} HT_RTC_TypeDef;                           /* end of group HT_RTC_TypeDef                              */

#if defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
typedef struct
{
    __IO  uint32_t RTCTSTIM;                 /*!< Offset: 0x314 RTC Timestamp Time Cache Register  (R/W ) */
    __IO  uint32_t RTCTSDAT;                 /*!< Offset: 0x318 RTC Timestamp Date Cache Register  (R/W ) */
    __IO  uint32_t RTCTSSOU;                 /*!< Offset: 0x31C RTC Timestamp Triggers the Source Cache Register(R/W ) */
} HT_RTC_STAMPSOURCE_TypeDef;               /*  end of group HT_RTC_STAMPSOURCE TypeDef                  */
#endif


/*****************************************  LCD Control Block  *******************************************/
/**
* @brief  LCD register definition
*/
#if !defined  HT762x  ||  defined  HT772x
typedef struct
{
    __IO uint32_t LCDCLK;                   /*!< Offset: 0x000 LCD CLK Sel Register(R/W)  */
    __IO uint32_t LCDCON;                   /*!< Offset: 0x004 LCD Ctrl Register (R/W)    */
#if defined  USE_REGISTER_LCDCPC 
    __IO uint32_t LCDCPC;                   /*!< Offset: 0x008 LCD Charge Pump Ctrl Register (R/W)  */
#elif defined  USE_REGISTER_LCDBUF_48
    __IO uint32_t Reserved[2];
#else
    __IO uint32_t Reserved;
#endif
#if defined  USE_REGISTER_LCDOUT	
    __IO uint32_t LCDOUT;                   /*!< Offset: 0x00C LCD Data Display Register (R/W)      */
#endif	
#if defined  USE_REGISTER_LCDBUF_37
    __IO uint32_t Reserved1;
    __IO uint32_t LCDBUF[37];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#elif defined  USE_REGISTER_LCDBUF_42
    __IO uint32_t Reserved1;
    __IO uint32_t LCDBUF[42];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#elif defined  USE_REGISTER_LCDBUF_48
    __IO uint32_t LCDBUF[48];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#elif defined  USE_REGISTER_LCDBUF_56
    __IO uint32_t LCDBUF[56];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#elif defined  USE_REGISTER_LCDBUF_54
    __IO uint32_t LCDBUF[54];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#else
	__IO uint32_t Reserved1;
    __IO uint32_t LCDBUF[43];               /*!< Offset: 0x010 LCD Data Display Register (R/W)      */
#endif

#if defined  USE_REGISTER_LCDBUF_37
    __I  uint32_t Reserved2[2*16*4-2-37];
    __IO uint32_t LCDTESTCTRL;              /*!< Offset: 0x208 LCD Test Ctrl Register (R/W)         */
#endif
#if defined  USE_REGISTER_LCDBUF_48
    __I  uint32_t Reserved2[2*16*4-2-48];
    __IO uint32_t LCDIBCTRL;               /*!< Offset: 0x208 LCD bias current Ctrl Register (R/W)  */
#endif
#if defined  USE_REGISTER_LCDBUF_56
    __IO uint32_t Reserved2[2*16*4-4-56];
    __IO uint32_t VCPADJ[1];                /*!< Offset: 0x200 Chargepump Vref Adjust Register (R/W)*/
#endif
#if defined  USE_REGISTER_LCDBUF_54
    __IO uint32_t Reserved2[2*16*4-4-54];
    __IO uint32_t VCPADJ[1];                /*!< Offset: 0x200 Chargepump Vref Adjust Register (R/W)*/
#endif
} HT_LCD_TypeDef;                           /* end of group HT_LCD_TypeDef                  */
#endif


/*****************************************  TBS Control Block  *******************************************/
/**
* @brief  TBS register definition
*/
typedef struct
{
#if defined HT501x ||  defined  HT502x  ||  defined  HT503x
    __IO uint32_t TBSCON;                   /*!< Offset: 0x000 TBS config register (R/W)      */
    __IO uint32_t TBSPRD;                   /*!< Offset: 0x004 Open period set register (R/W) */
    __IO uint32_t TBSIE;                    /*!< Offset: 0x008 TBS interruption enable register (R/W)  */
    __IO uint32_t TBSIF;                    /*!< Offset: 0x00C TBS interruption flag register (R/W)  */
    __I  uint32_t TMPDAT;                   /*!< Offset: 0x010 Temperature measurement data (R/)      */
    __I  uint32_t VBATDAT;                  /*!< Offset: 0x014 Battery voltage measurement data (R/)  */
    __I  uint32_t VCCDAT;                   /*!< Offset: 0x018 VCC measurement data (R/)   */                                            /*!<HT502x：it is VDDDAT in user datasheet     */
    __I  uint32_t ADC0DAT;                  /*!< Offset: 0x01C ADC channel 0 measurement data (R/)  */
    __I  uint32_t ADC1DAT;                  /*!< Offset: 0x020 ADC channel 1 measurement data (R/)  */
    __I  uint32_t ADC2DAT;                  /*!< Offset: 0x024 ADC channel 2 measurement data (R/)  */
    __IO uint32_t VBATCMP;                  /*!< Offset: 0x028 VBAT compare register (R/W)     */
    #if defined  HT503x 
	__I  uint32_t ADC3DAT;                  /*!< Offset: 0x02C ADC channel 3 measurement data (R/)  */
    #else
    __I  uint32_t Reserved;
    #endif
    __IO uint32_t TBSTEST;                  /*!< Offset: 0x030 TBS test register (R/W)      */
    __IO uint32_t ADC0CMP;                  /*!< Offset: 0x034 ADC0 compare register  (R/W)     */
    __IO uint32_t ADC1CMP;                  /*!< Offset: 0x038 ADC1 compare register  (R/W)     */
#elif  defined  HT762x  ||  defined  HT772x
	__IO uint32_t TBSCON;                   /*!< Offset: 0x000 TBS config register (R/W)      */
    __IO uint32_t TBSIE;                    /*!< Offset: 0x004 TBS interruption enable register (R/W)  */
    __IO uint32_t TBSIF;                    /*!< Offset: 0x008 TBS interruption flag register (R/W)  */
    __I  uint32_t TMPDAT;                   /*!< Offset: 0x00C Temperature measurement data (R/)      */
    __I  uint32_t TDVREFDAT;                /*!< Offset: 0x010 EMU module VREF test data (R)  */
    __I  uint32_t ADC0DAT;                  /*!< Offset: 0x014 ADC channel 0 measurement data (R/)  */
    __I  uint32_t ADC1DAT;                  /*!< Offset: 0x018 ADC channel 1 measurement data (R/)  */
    __IO uint32_t TDVREFCMP;                /*!< Offset: 0x01C EMU module VREF compare register (R/W)    */
    __IO uint32_t TBSPRD;                   /*!< Offset: 0x020 Open period set register (R/W) */
    __IO uint32_t TBSTEST;                  /*!< Offset: 0x024 TBS test register (R/W)      */
    __I  uint32_t VCCDAT;                   /*!< Offset: 0x028 VCC measurement data ((R/)   */
#else
    __IO uint32_t TBSCON;                   /*!< Offset: 0x000 TBS test register (R/W)      */
    __IO uint32_t TBSIE;                    /*!< Offset: 0x004 TBS interruption enable register (R/W)  */
    __IO uint32_t TBSIF;                    /*!< Offset: 0x008 TBS interruption flag register (R/W)  */
    __I  uint32_t TMPDAT;                   /*!< Offset: 0x00C Temperature measurement data (R/)      */
    __I  uint32_t VBATDAT;                  /*!< Offset: 0x010 Battery voltage measurement data (R/)      */
                                            /*!<                   mean ADCBATDAT  in the manual*/
    __I  uint32_t ADC0DAT;                  /*!< Offset: 0x014 ADC channel 0 measurement data (R/)  */
    __I  uint32_t ADC1DAT;                  /*!< Offset: 0x018 ADC channel 1 measurement data (R/)  */
    __IO uint32_t VBATCMP;                  /*!< Offset: 0x01C VBAT compare register (R/W)     */
                                            /*!<           HT6x3x: mean VDRCMP in the manual    */
    __IO uint32_t TBSPRD;                   /*!< Offset: 0x020 Open period set register (R/W) */
    __IO uint32_t TBSTEST;                  /*!< Offset: 0x024 TBS test register (R/W)      */
    __I  uint32_t VCCDAT;                   /*!< Offset: 0x028 VCC measurement data(R/)   */
#endif
#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
    __IO uint32_t ADC0CMP;                  /*!< Offset: 0x02C ADC0 compare register (R/)      */
    __I  uint32_t ADC3DAT;                  /*!< Offset: 0x030 ADC3 channel 3 measurement data (R/)      */
    __I  uint32_t ADC4DAT;                  /*!< Offset: 0x034 ADC4 channel 4 measurement data (R/)      */
    __I  uint32_t ADC5DAT;                  /*!< Offset: 0x038 ADC5 channel 5 measurement data (R/)      */
    #if defined  HT6x3x
    __I  uint32_t Reserved2;
    __IO uint32_t TRIREQ;                   /*!< Offset: 0x040 ADC real-time trigger control register (R/W) */
    #elif defined  HT6x2xK
    __I  uint32_t Reserved2;
    __IO uint32_t TRIREQ;                   /*!< Offset: 0x040 ADC real-time trigger control register (R/W)      */
    __I  uint32_t Reserved3;
    __IO uint32_t TBSINJECTCTRL;            /*!< Offset: 0x048 TBS injection mode control register (R/W)      */
    #elif defined  HT762x  ||  defined  HT772x
	__I  uint32_t Reserved2;
    __IO uint32_t TRIREQ;                   /*!< Offset: 0x040 ADC real-time trigger control register (R/W) */
    __I  uint32_t Reserved3;
    __IO uint32_t TBSINJECTCTRL;            /*!< Offset: 0x048 TBS injection mode control register (R/W) */
    __IO uint32_t VTPPRD;                   /*!< Offset: 0x04C Temperature measurement terminal period config register (R/W) */
    __I  uint32_t VTP0DAT;                  /*!< Offset: 0x050 VTP channel 0 data(R)   */
    __I  uint32_t VTP1DAT;                  /*!< Offset: 0x054 VTP channel 1 data(R)   */
    __I  uint32_t VTP2DAT;                  /*!< Offset: 0x058 VTP channel 2 data(R)   */
    __I  uint32_t VTP3DAT;                  /*!< Offset: 0x05C VTP channel 3 data(R)   */
    __I  uint32_t VTP4DAT;                  /*!< Offset: 0x060 VTP channel 4 data(R)   */
    __I  uint32_t VTP5DAT;                  /*!< Offset: 0x064 VTP channel 5 data(R)   */
    __I  uint32_t VTP6DAT;                  /*!< Offset: 0x068 VTP channel 6 data(R)   */
    __I  uint32_t VTP7DAT;                  /*!< Offset: 0x06C VTP channel 7 data(R)   */
    #elif defined  HT633x
	__I  uint32_t Reserved2;
    __IO uint32_t TRIREQ;                   /*!< Offset: 0x040 ADC real-time trigger control register (R/W) */
    __I  uint32_t Reserved3;
    __IO uint32_t TBSINJECTCTRL;            /*!< Offset: 0x048 TBS injection mode control register (R/W) */
    __I  uint32_t ADC6DAT;                  /*!< Offset: 0x04C ADC channel 6 measurement data (R/W)      */
    __I  uint32_t ADC7DAT;                  /*!< Offset: 0x050 ADC channel 7 measurement data (R/W)      */
    __I  uint32_t ADC8DAT;                  /*!< Offset: 0x054 ADC channel 8 measurement data (R/W)      */
    __I  uint32_t ADCMODECTRL;              /*!< Offset: 0x058 ADC control register (R/W)                */
    __I  uint32_t ADC9DAT;                  /*!< Offset: 0x05C ADC channel 9 measurement data (R/W)      */
    #else
    __IO uint32_t TBSPRD2;                  /*!< Offset: 0x03C Open period set register (R/W) */
    #endif
#endif
#if defined  HT503x 	
	__I  uint32_t Reserved2;
    __IO uint32_t TRIREQ;                   /*!< Offset: 0x040 ADC real-time trigger control register (R/W)             */
    __I  uint32_t Reserved3;
    __IO uint32_t TBSINJECTCTRL;            /*!< Offset: 0x048 TBS injection mode control register (R/W)      */
    __I  uint32_t ADC4DAT;                  /*!< Offset: 0x04C ADC channel 4 measurement data (R/W)      */
    __I  uint32_t ADC5DAT;                  /*!< Offset: 0x050 ADC channel 5 measurement data (R/W)      */
	__I  uint32_t ADC6DAT;                  /*!< Offset: 0x054 ADC channel 6 measurement data (R/W)      */
#endif
} HT_TBS_TypeDef;                           /* end of group HT_TBS_TypeDef              */


/*****************************************  PMU Control Block  *******************************************/
/**
* @brief  PMU register definition
*/
typedef struct
{
    __IO uint32_t PMUCON;                   /*!< Offset: 0x000 PMU config register (R/W)              */
    __IO uint32_t VDETCFG;                  /*!< Offset: 0x004 PMU Detect threshold configuration register (R/W)     */
    __IO uint32_t VDETPCFG;                 /*!< Offset: 0x008 PMU Detects the time period configuration register (R/W) */
    __IO uint32_t PMUIE;                    /*!< Offset: 0x00C PMU Interrupt enable register (R/W)          */
    __IO uint32_t PMUIF;                    /*!< Offset: 0x010 PMU Interrupt flag register (R/W)          */
    __I  uint32_t PMUSTA;                   /*!< Offset: 0x014 PMU status register (R)            */
    __IO uint32_t WAKEIF;                   /*!< Offset: 0x018 Wake up source flag register (R/W)           */
#if defined USE_POWDET
    __IO uint32_t PDTFLT;                   /*!< Offset: 0x01C POW Digital filter register (R/W)          */
#else
	__I  uint32_t Reserved0;
#endif
#if defined USE_LVDIN_QR
    __IO uint32_t LVDINQR;                  /*!< Offset: 0x020 LVDIN Quick start control bit (R/W)       */
#else
	__I  uint32_t Reserved1;
#endif
#if defined USE_LVDIN_SEL
    __IO uint32_t LVDINSEL;                 /*!< Offset: 0x024 LVDIN Input selection register (R/W)       */
#else	
		__I  uint32_t Reserved2;
#endif
#if defined USE_WAKEIF1
		__IO uint32_t WAKEIF1;                   /*!< Offset: 0x028 Wake up source flag register 1(R/W)       */
		__I  uint32_t Reserved3;
#else 
		__I  uint32_t Reserved3[2];
#endif
    __IO uint32_t RSTSTA;                   /*!< Offset: 0x030 Reset flag register (R/W)    */
#if defined USE_LDOVREF
    __I  uint32_t Reserved4[13*4];
    __IO uint32_t LDOVREFCFG;               /*!< Offset: 0x104 LDOVREF config register (R/W)*/
    __I  uint32_t Reserved5[10];
    __IO uint32_t LBORCFG;                  /*!< Offset: 0x130 LBOR Detect config register (R/W)*/
#endif
#if defined USE_LPCFG
    __I  uint32_t Reserved4[12*4+3];
    __IO uint32_t LPMCFG;                   /*!< Offset: 0x100 Low power mode configuration register(write protection) (R/W)*/
    __IO uint32_t LDOVREF;               	  /*!< Offset: 0x104 LDOVREF config register(write protection)   (R/W)*/
    __I  uint32_t Reserved5[6];
    __IO uint32_t LPMSTA;                   /*!< Offset: 0x120 低Low power mode status register  (R/W)*/
    __I  uint32_t Reserved6[13*4+3];
    __IO uint32_t OSCPWRADJ ;               /*!< Offset: 0x200 OSC Crystal power regulation register (R/W)*/
#endif
} HT_PMU_TypeDef;                           /* end of group HT_PMU_TypeDef                      */


/*****************************************  CMU Control Block  *******************************************/
/**
* @brief  CMU register definition
*/
typedef struct
{
    __IO uint32_t WPREG;                    /*!< Offset: 0x000 Write protection control register (R/W)        */
    __IO uint32_t SYSCLKCFG;                /*!< Offset: 0x004 System clock configuration register (R/W)      */
    __I  uint32_t JTAGSTA;                  /*!< Offset: 0x008 JTAG status indication (R)                     */
    __IO uint32_t LRCADJ;                   /*!< Offset: 0x00C Low frequency RC configuration register (R/W ) */
    __IO uint32_t HRCADJ;                   /*!< Offset: 0x010 High frequency RC configuration register (R/W) */
#if  defined  HT6x1x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
    __IO uint32_t HRCDIV;                   /*!< Offset: 0x014 High frequency RC divider register (R/W)       */
#else
    __I  uint32_t Reserved1[1];
#endif
    __IO uint32_t CLKSTA;                   /*!< Offset: 0x018 Clock Status Register (R/W)                    */
    __IO uint32_t SYSCLKDIV;                /*!< Offset: 0x01C System clock divider register (R/W)            */
    __I  uint32_t Reserved[1];
    __IO uint32_t CLKOUTSEL;                /*!< Offset: 0x024 CLKOUT clock selection register (R/W)          */
    __IO uint32_t CLKOUTDIV;                /*!< Offset: 0x028 CLKOUT clock divider register (R/W)            */
    __IO uint32_t CLKCTRL0;                 /*!< Offset: 0x02C Internal module enable register 0 (R/W)        */
    __IO uint32_t CLKCTRL1;                 /*!< Offset: 0x030 Internal module enable register 1 (R/W)        */
    __IO uint32_t FLASHCON;                 /*!< Offset: 0x034 Flash access control register (R/W)            */
    __IO uint32_t FLASHLOCK;                /*!< Offset: 0x038 Flash lock register (W)                        */
#if  defined  HT6x1x
    __I  uint32_t Reserved2[5];
#elif  defined HT6x2x  ||  defined  HT6x2xK || defined HT762x  ||  defined  HT772x
    __IO uint32_t PREFETCH;                 /*!< Offset: 0x03C Instruction prefetch enable register (R/W)     */
    __I  uint32_t Reserved2[4];
#elif  defined  HT6x3x || defined  HT633x
    __IO uint32_t PREFETCH;                 /*!< Offset: 0x03C Instruction prefetch enable register (R/W)     */
    __I  uint32_t Reserved2[3];    
#elif  defined  HT501x ||  defined  HT502x
    __IO uint32_t FLASHDLY;                 /*!< Offset: 0x03C Flash latency (R/W)                            */
    __I  uint32_t Reserved2[4];
#elif  defined  HT503x
    __IO uint32_t FLASHDLY;                 /*!< Offset: 0x03C Flash latency (R/W)                            */
    __I  uint32_t Reserved2[3];
#endif
#if  defined  HT6x3x  ||  defined  HT503x  ||  defined  HT633x
    __IO uint32_t INFOLOCK_B;               /*!< Offset: 0x04C Info Flash lock register B(R/W)                */
                                            /*!< This feature has not yet been opened and is temporarily unavailable */
    __IO uint32_t INFOLOCK_A;               /*!< Offset: 0x050 Info Flash lock register A (R/W)               */
    __IO uint32_t PORRSTSET;                /*!< Offset: 0x054 POR/LBOR reset register(not open) (R/W)        */
#else
    __IO uint32_t INFOLOCK;                 /*!< Offset: 0x050 Info Flash lock register(not open) (R/W)       */
    __IO uint32_t PORRSTSET;                /*!< Offset: 0x054 POR/LBOR reset register(not open) (R/W)        */
#endif

/* 0x58 - 0x70 */
#if  defined  HT6x1x
#elif  defined  HT6x2x  ||  defined  HT6x2xK  ||  defined  HT6x3x
    __I  uint32_t Reserved4[2];
    __IO uint32_t RCCALICON;                /*!< Offset: 0x060 RC correction configuration register (R/W)                     */
    __IO uint32_t RCCALIIE;                 /*!< Offset: 0x064 RC frequency measurement interrupt enable register (R/W)       */
    __IO uint32_t RCCALIIF;                 /*!< Offset: 0x068 RC frequency measurement interrupt flag register (R/W)         */
    __IO uint32_t HRCVALUE;                 /*!< Offset: 0x06C HRC frequency measurement value (24-bit unsigned number) (R/W) */
    __IO uint32_t LRCVALUE;                 /*!< Offset: 0x070 LRC frequency measurement value (17-bit unsigned number) (R/W) */
#elif  defined  HT762x  ||  defined  HT772x  ||  defined HT633x
    __I  uint32_t Reserved4[7];
#endif

/* 0x74 - 0xF40 */
#if  defined  HT6x2x  ||  defined  HT6x2xK
    __I  uint32_t Reserved5[99];
    __IO uint32_t LFDETCFG;                 /*!< Offset: 0x200 LF clock stop detection configuration register (R/W)           */
    __IO uint32_t MULTFUNCFG;               /*!< Offset: 0x204 Multi-function configuration register (R/W)                    */
    __IO uint32_t LFCLKCFG;                 /*!< Offset: 0x208 Low frequency clock source configuration register (R/W)        */
    __I  uint32_t OSCSTA;                   /*!< Offset: 0x20C OSC status register (R)                                        */
    __I  uint32_t Reserved6[13*64-4];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R) */
    __I  uint32_t Reserved7[11];
    __IO uint32_t FLTCTR;                   /*!< Offset: 0xF30 Clock filter control register, only for HT6x2xH and above (R)  */
#elif  defined  HT762x  ||  defined  HT772x
    __I  uint32_t Reserved5[99];
    __IO uint32_t LFDETCFG;                 /*!< Offset: 0x200 LF clock stop detection configuration register (R/W)           */
    __IO uint32_t HRCCLKCFG;                /*!< Offset: 0x204 HRC clock stop detection configuration register (R/W)          */
    __IO uint32_t LFCLKCFG;                 /*!< Offset: 0x208 Low frequency clock source configuration register (R/W)        */
    __IO uint32_t OSCSTA;                   /*!< Offset: 0x20C OSC state register (R/W)                                       */
    __I  uint32_t Reserved6[64*13-4];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)                             */
    __I  uint32_t Reserved7[3];
    __IO uint32_t PLLLOCK_PRE;              /*!< Offset: 0xF10 PLL lock condition set register  (R/W) */
    __I  uint32_t Reserved8[3+4];
    __IO uint32_t FLTCTR;                   /*!< Offset: 0xF30 Clock filter control register (R/W)    */
    __I  uint32_t Reserved9[3];
    __IO uint32_t CACHE_HIT_RATIO;          /*!< Offset: 0xF40 Cache-hit-ratio (R)                    */
#endif
/* 0x74 - 0x1EC */
#if  defined  HT6x3x
    __I  uint32_t Reserved5[3];
    __IO uint32_t FLASHLOCK_H256;           /*!< Offset: 0x080 high 256K Flash erase enable (R/W)     */
    __IO uint32_t FLASHLOCK_L256;           /*!< Offset: 0x084 low 256K Flash erase enable (R/W)      */
    __IO uint32_t FSA1LOCK;                 /*!< Offset: 0x088 FlashASector1 lock register (R/W)      */
    __IO uint32_t FSA2LOCK;                 /*!< Offset: 0x08C FlashASector2 lock register (R/W)      */
    __IO uint32_t FSA3LOCK;                 /*!< Offset: 0x090 FlashASector3 lock register (R/W)      */
    __IO uint32_t FSA4LOCK;                 /*!< Offset: 0x094 FlashASector4 lock register (R/W)      */
    __IO uint32_t FSA5LOCK;                 /*!< Offset: 0x098 FlashASector5 lock register (R/W)      */
    __IO uint32_t FSA6LOCK;                 /*!< Offset: 0x09C FlashASector6 lock register (R/W)      */
    __IO uint32_t FSA7LOCK;                 /*!< Offset: 0x0A0 FlashASector7 lock register (R/W)      */
    __IO uint32_t FSA8LOCK;                 /*!< Offset: 0x0A4 FlashASector8 lock register (R/W)      */
    __IO uint32_t FSA9LOCK;                 /*!< Offset: 0x0A8 FlashASector9 lock register (R/W)      */
    __IO uint32_t FSAALOCK;                 /*!< Offset: 0x0AC FlashASectorA lock register (R/W)      */
    __IO uint32_t FSB1LOCK;                 /*!< Offset: 0x0B0 FlashBSector1 lock register (R/W)      */
    __IO uint32_t FSB2LOCK;                 /*!< Offset: 0x0B4 FlashBSector2 lock register (R/W)      */
    __IO uint32_t FSB3LOCK;                 /*!< Offset: 0x0B8 FlashBSector3 lock register (R/W)      */
    __IO uint32_t FSB4LOCK;                 /*!< Offset: 0x0BC FlashBSector4 lock register (R/W)      */
    __IO uint32_t FSB5LOCK;                 /*!< Offset: 0x0C0 FlashBSector5 lock register (R/W)      */
    __IO uint32_t FSB6LOCK;                 /*!< Offset: 0x0C4 FlashBSector6 lock register (R/W)      */
    __IO uint32_t FSB7LOCK;                 /*!< Offset: 0x0C8 FlashBSector7 lock register (R/W)      */
    __IO uint32_t FSB8LOCK;                 /*!< Offset: 0x0CC FlashBSector8 lock register (R/W)      */
    __IO uint32_t FSB9LOCK;                 /*!< Offset: 0x0D0 FlashBSector9 lock register (R/W)      */
    __IO uint32_t FSBBLOCK;                 /*!< Offset: 0x0D4 FlashBSectorB lock register (R/W)      */
    __I  uint32_t Reserved6[2+2*4];
    __IO uint32_t FLASHCON2;                /*!< Offset: 0x100 Flash access control register2 (R/W)   */
    __I  uint32_t Reserved7[64-5];
#elif  defined HT633x
    __I  uint32_t Reserved5[5];
    __IO uint32_t FSA1LOCK;                 /*!< Offset: 0x088 FlashASector1 lock register (R/W)      */
    __IO uint32_t FSA2LOCK;                 /*!< Offset: 0x08C FlashASector2 lock register (R/W)      */
    __IO uint32_t FSA3LOCK;                 /*!< Offset: 0x090 FlashASector3 lock register (R/W)      */
    __IO uint32_t FSA4LOCK;                 /*!< Offset: 0x094 FlashASector4 lock register (R/W)      */
    __IO uint32_t FSA5LOCK;                 /*!< Offset: 0x098 FlashASector5 lock register (R/W)      */
    __IO uint32_t FSA6LOCK;                 /*!< Offset: 0x09C FlashASector6 lock register (R/W)      */
    __IO uint32_t FSA7LOCK;                 /*!< Offset: 0x0A0 FlashASector7 lock register (R/W)      */
    __IO uint32_t FSA8LOCK;                 /*!< Offset: 0x0A4 FlashASector8 lock register (R/W)      */
    __IO uint32_t FSA9LOCK;                 /*!< Offset: 0x0A8 FlashASector9 lock register (R/W)      */
    __IO uint32_t FSAALOCK;                 /*!< Offset: 0x0AC FlashASectorA lock register (R/W)      */
    __IO uint32_t FSB1LOCK;                 /*!< Offset: 0x0B0 FlashBSector1 lock register (R/W)      */
    __IO uint32_t FSB2LOCK;                 /*!< Offset: 0x0B4 FlashBSector2 lock register (R/W)      */
    __IO uint32_t FSB3LOCK;                 /*!< Offset: 0x0B8 FlashBSector3 lock register (R/W)      */
    __IO uint32_t FSB4LOCK;                 /*!< Offset: 0x0BC FlashBSector4 lock register (R/W)      */
    __IO uint32_t FSB5LOCK;                 /*!< Offset: 0x0C0 FlashBSector5 lock register (R/W)      */
    __IO uint32_t FSB6LOCK;                 /*!< Offset: 0x0C4 FlashBSector6 lock register (R/W)      */
    __IO uint32_t FSB7LOCK;                 /*!< Offset: 0x0C8 FlashBSector7 lock register (R/W)      */
    __IO uint32_t FSB8LOCK;                 /*!< Offset: 0x0CC FlashBSector8 lock register (R/W)      */
    __IO uint32_t FSB9LOCK;                 /*!< Offset: 0x0D0 FlashBSector9 lock register (R/W)      */
    __IO uint32_t FSBBLOCK;                 /*!< Offset: 0x0D4 FlashBSectorB lock register (R/W)      */
    __I  uint32_t Reserved6[2+2*4];
    __IO uint32_t FLASHCON2;                /*!< Offset: 0x100 Flash access control register2 (R/W)   */
    __I  uint32_t Reserved7[3+4*4];
    __IO uint32_t PRAM_UNLOCK;              /*!< Offset: 0x150 Parameters config unlock register (R/W)*/
    __IO uint32_t PTACFG;                   /*!< Offset: 0x154 FLASH program config register  (R/W)   */
    __IO uint32_t ERASE_TIME;               /*!< Offset: 0x158 Erase time config register  (R/W)      */
    __IO uint32_t SCE_TIME;                 /*!< Offset: 0x15C Chip erase time config register  (R/W) */
    __IO uint32_t PROG_TIME;                /*!< Offset: 0x160 Program time config register  (R/W)    */
    __IO uint32_t PROG2_TIME;               /*!< Offset: 0x164 Prog2 start time config register  (R/W)*/
    __IO uint32_t NVS_TIME;                 /*!< Offset: 0x168 NVS time config register  (R/W)        */
    __IO uint32_t RCV_TIME;                 /*!< Offset: 0x16C Recovery time config register  (R/W)   */
    __I  uint32_t Reserved8[35];
#endif

/* 0x1F0 - 0xFFC */
#if  defined  HT6x1x
#elif  defined  HT6x3x
    __I  uint32_t Reserved10[13*64+4];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)                              */
    __I  uint32_t Reserved11[3];
    __IO uint32_t PLLLOCK_PRE;              /*!< Offset: 0xF10 PLL lock condition set register (R/W)   */
    __I  uint32_t Reserved12[3];
    __IO uint32_t C_PLL;                    /*!< Offset: 0xF20 PLL frequency control (R/W)             */
    __I  uint32_t Reserved13[3+4];
    __IO uint32_t OCFG_hit_ratio;           /*!< Offset: 0xF40 Cache-hit-ratio (R)                     */
#elif  defined  HT633x
    __IO uint32_t EMUCLKCFG;                /*!< Offset: 0x1FC EMU clock configuration register (R/W)                */
    __IO uint32_t LFDETCFG;                 /*!< Offset: 0x200 LF clock stop detection configuration register (R/W)  */
    __IO uint32_t HRCCLKCFG;                /*!< Offset: 0x204 HRC clock stop detection configuration register (R/W) */
    __IO uint32_t TBSCLKCFG;                /*!< Offset: 0x208 TBS clock configuration register (R/W)                */
    __IO uint32_t OSCSTA;                   /*!< Offset: 0x20C OSC state register (R/W)                              */
    __I  uint32_t Reserved9[5];
    __IO uint32_t RTCCLKCFG;                /*!< Offset: 0x224 RTC clock configuration register (R/W)                */
    __IO uint32_t TOUTCLKCFG;               /*!< Offset: 0x228 TOUT clock configuration register (R/W)               */
    __I  uint32_t Reserved10[12*64+13*4+1];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)                                            */
    __I  uint32_t Reserved11[3];
    __IO uint32_t PLLLOCK_PRE;              /*!< Offset: 0xF10 PLL lock condition set register  (R/W)                */
    __I  uint32_t Reserved12[3];
    __IO uint32_t C_PLL;                    /*!< Offset: 0xF20 PLL frequency control (R/W)                           */
    __I  uint32_t Reserved13[7];
    __I  uint32_t Cache_hitratio;           /*!< Offset: 0xF40 Cache-hit-ratio (R/W)                                 */
#endif

/* 0x58-END */
#if  defined  HT501x
    __I  uint32_t Reserved4[2+10*4+14*64];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)                             */
#elif  defined  HT502x || defined  HT503x
    __I  uint32_t Reserved4[2];
    __IO uint32_t FS1LOCK;                  /*!< Offset: 0x060 FlashSector1 lock register (R/W)       */
    __IO uint32_t FS2LOCK;                  /*!< Offset: 0x064 FlashSector2 lock register (R/W)       */
    __IO uint32_t FS3LOCK;                  /*!< Offset: 0x068 FlashSector3 lock register (R/W)       */
    __IO uint32_t FS4LOCK;                  /*!< Offset: 0x06C FlashSector4 lock register (R/W)       */
    __IO uint32_t FS5LOCK;                  /*!< Offset: 0x070 FlashSector5 lock register (R/W)       */
    __IO uint32_t FS6LOCK;                  /*!< Offset: 0x074 FlashSector6 lock register (R/W)       */
    __IO uint32_t FS7LOCK;                  /*!< Offset: 0x078 FlashSector7 lock register (R/W)       */
    __IO uint32_t FS8LOCK;                  /*!< Offset: 0x07C FlashSector8 lock register (R/W)       */
    __IO uint32_t FS9LOCK;                  /*!< Offset: 0x080 FlashSector9 lock register (R/W)       */
    __IO uint32_t FSALOCK;                  /*!< Offset: 0x084 FlashSectorA lock register (R/W)       */
    __IO uint32_t FSBLOCK;                  /*!< Offset: 0x088 FlashSectorB lock register (R/W)       */
    __I  uint32_t Reserved5[1];
    __IO uint32_t FLASHCON2;                /*!< Offset: 0x090 Flash access control register 2 (R/W)  */
#if defined HT503x
    __I  uint32_t Reserved6[3];
    __IO uint32_t FSB1LOCK;                /*!< Offset: 0x0A0 FlashSectorB1 lock register (R/W)  */
    __IO uint32_t FSB2LOCK;                /*!< Offset: 0x0A4 FlashSectorB2 lock register (R/W)  */
    __IO uint32_t FSB3LOCK;                /*!< Offset: 0x0A8 FlashSectorB3 lock register (R/W)  */
    __IO uint32_t FSB4LOCK;                /*!< Offset: 0x0AC FlashSectorB4 lock register (R/W)  */
    __IO uint32_t FSB5LOCK;                /*!< Offset: 0x0B0 FlashSectorB5 lock register (R/W)  */
    __IO uint32_t FSB6LOCK;                /*!< Offset: 0x0B4 FlashSectorB6 lock register (R/W)  */
    __IO uint32_t FSB7LOCK;                /*!< Offset: 0x0B8 FlashSectorB7 lock register (R/W)  */
    __IO uint32_t FSB8LOCK;                /*!< Offset: 0x0BC FlashSectorB8 lock register (R/W)  */
    __IO uint32_t FSB9LOCK;                /*!< Offset: 0x0C0 FlashSectorB9 lock register (R/W)  */
    __IO uint32_t FSBALOCK;                /*!< Offset: 0x0C4 FlashSectorBA lock register (R/W)  */
    __IO uint32_t FSBBLOCK;                /*!< Offset: 0x0C8 FlashSectorBB lock register (R/W)  */
    __I  uint32_t Reserved7[4*4];
    __IO uint32_t INFOLOCK_C;               /*!< Offset: 0x109 Info Flash C lock register (R/W)   */
    __IO uint32_t INFOLOCK_D;               /*!< Offset: 0x110 Info Flash D lock register (R/W)   */
    __IO uint32_t INFOLOCK_E;               /*!< Offset: 0x114 Info Flash E lock register (R/W)   */
    __IO uint32_t INFOLOCK_F;               /*!< Offset: 0x118 Info Flash F lock register (R/W)   */
    __IO uint32_t INFOLOCK_G;               /*!< Offset: 0x11C Info Flash G lock register (R/W)   */
    __IO uint32_t INFOLOCK_H;               /*!< Offset: 0x120 Info Flash H lock register (R/W)   */
    __IO uint32_t INFOLOCK_I;               /*!< Offset: 0x124 Info Flash I lock register (R/W)   */
    __IO uint32_t INFOLOCK_J;               /*!< Offset: 0x128 Info Flash J lock register (R/W)   */
    __IO uint32_t INFOLOCK_K;               /*!< Offset: 0x12C Info Flash K lock register (R/W)   */
    __IO uint32_t INFOLOCK_L;               /*!< Offset: 0x130 Info Flash L lock register (R/W)   */
    __IO uint32_t INFOLOCK_M;               /*!< Offset: 0x134 Info Flash M lock register (R/W)   */
    __IO uint32_t INFOLOCK_N;               /*!< Offset: 0x138 Info Flash N lock register (R/W)   */
    __IO uint32_t INFOLOCK_O;               /*!< Offset: 0x13C Info Flash O lock register (R/W)   */
    __IO uint32_t INFOLOCK_P;               /*!< Offset: 0x140 Info Flash P lock register (R/W)   */
    __I  uint32_t Reserved8[4*12-1];
    __IO uint32_t LFDETCFG;                 /*!< Offset: 0x200 LF clock stop detection configuration register (R/W) */
    __I  uint32_t Reserved9[2];
    __IO uint32_t OSCSTA;                   /*!< Offset: 0x20C OSC state register (R/W)               */
    __IO uint32_t KEYCLKCFG;                /*!< Offset: 0x210 KEYSCAN clock control register (R/W)   */
    __I  uint32_t Reserved10[4];
    __IO uint32_t RTCCLKCFG;                /*!< Offset: 0x224 RTC clock configuration register (R/W) */
    __I  uint32_t Reserved11[2+13*4+12*64];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)  		                      */
    __I  uint32_t Reserved12[3];
    __IO uint32_t PLLLOCK_PRE;              /*!< Offset: 0xF10 PLL lock condition set register (R/W)  */
    __I  uint32_t Reserved13[7];
    __IO uint32_t FLTCTR;                   /*!< Offset: 0xF30 clock filter control (R/W)             */
    __I  uint32_t Reserved14[3];
    __IO uint32_t OCFG_hit_ratio;           /*!< Offset: 0xF40 Cache-hit-ratio (R)                    */
#else
    __I  uint32_t Reserved6[2+10*4+14*64-7-8];
    __I  uint32_t CHIPID;                   /*!< Offset: 0xF00 ChipID (R)  	                          */
#endif
#endif
} HT_CMU_TypeDef;                           /* end of group HT_CMU_TypeDef                              */


/*****************************************  WDT Control Block  *******************************************/
/**
* @brief  WDT registers difinition
*/
typedef struct
{
#if defined HT6x1x || defined HT633x
    __IO uint32_t WDTCFG;                   /*!< Offset: 0x000 WDT configuration register (R/W)           */
#else
    __I  uint32_t Reserved;
#endif
    __IO uint32_t WDTCLR;                   /*!< Offset: 0x004 WDT clear register (R/W) */
    __I  uint32_t WDTCNT;                   /*!< Offset: 0x008 WDT counter register(R)              */
} HT_WDT_TypeDef;                           /* end of group HT_WDT_TypeDef                      */


/*****************************************  GPIO Control Block  ******************************************/
/**
* @brief GPIO register definition
*/
typedef struct
{
    __IO uint32_t IOCFG;                    /*!< Offset: 0x000 Port Function Config Register 1         (R/W)  */
    __IO uint32_t AFCFG;                    /*!< Offset: 0x004 Port Function Config Register 2         (R/W)  */
    __IO uint32_t PTDIR;                    /*!< Offset: 0x008 Direction of Port Config Register       (R/W)  */
    __IO uint32_t PTUP;                     /*!< Offset: 0x00C Pullup or Floating Config Register      (R/W)  */
    __IO uint32_t PTDAT;                    /*!< Offset: 0x010 Port Date Register                      (R/W)  */
    __O  uint32_t PTSET;                    /*!< Offset: 0x014 Port Output Value Set Register            (W)  */
    __O  uint32_t PTCLR;                    /*!< Offset: 0x018 Port Output Value Reset Register          (W)  */
    __O  uint32_t PTTOG;                    /*!< Offset: 0x01C Port Output Value Toggle Register         (W)  */
    __IO uint32_t PTOD;                     /*!< Offset: 0x020 Open Drain Function Config Register     (R/W)  */
#if defined USE_GPIO_FILT
	  __IO uint32_t FILT;                     /*!< Offset: 0x024 Input Filter Config Register            (R/W)  */
                                            /*!<               It only support H Version above for HT6x2x     */
#else
	  __I  uint32_t reserved1;
#endif
#if defined USE_GPIO_HIIPM	
	  __IO uint32_t HIIPM;                    /*!< Offset: 0x028 Port High Resistance Config Register    (R/W)  */
#else
	  __I  uint32_t reserved2;
#endif
#if defined USE_GPIO_NEWAFCTRL
  	__IO uint32_t NEWAFEN;                  /*!< Offset: 0x02C New Alternate Function Control Register (R/W)  */
#else
	  __I  uint32_t reserved3;
#endif
  	__I  uint32_t reserved4;
#if defined USE_GPIO_AF34
    __IO uint32_t AFCFG1;                   /*!< Offset: 0x034 Port Function Config Register 3         (R/W)  */
#else
	  __I  uint32_t reserved5;
#endif

} HT_GPIO_TypeDef;                          /* end of group HT_GPIO_TypeDef               */


/*****************************************  INT Control Block  *******************************************/
/**
* @brief INT interrupt register definition
*/
typedef struct
{
    __IO uint32_t EXTIE;                    /*!< Offset: 0x000 External interrupt enable register (R/W) */
    __IO uint32_t EXTIF;                    /*!< Offset: 0x004 External interrupt flag register (R/W) */
    __IO uint32_t PINFLT;                   /*!< Offset: 0x008 Pin digital filter enable register (R/W) */
#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x || defined  HT503x || defined  HT633x
    __IO uint32_t Reserved[1];
    __IO uint32_t EXTIE2;                   /*!< Offset: 0x010 External interrupt enable register (R/W) */
    __IO uint32_t EXTIF2;                   /*!< Offset: 0x014 External interrupt flag register (R/W) */
    __IO uint32_t PINFLT2;                  /*!< Offset: 0x018 Pin digital filter enable register (R/W) */
#endif
#if defined  HT633x || defined HT633xH
    __IO uint32_t EWKUPIE;                  /*!< Offset: 0x01C External wake_up pin interrupt enable register (R/W) */
    __IO uint32_t EWKUPIF;                  /*!< Offset: 0x020 External wake_up pin interrupt flag register  (R/W) */
#endif
} HT_INT_TypeDef;                           /* end of group HT_INT_TypeDef              */


/*****************************************  DMA Control Block  *******************************************/
/**
* @brief DMA register definition
*/
#if defined  HT501x  ||  defined  HT502x ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||   defined  HT762x  ||  defined  HT772x  ||   defined  HT503x  ||   defined  HT633x  
typedef struct
{
    __IO uint32_t DMAIE;                    /*!< Offset: 0x000 DMA TNT ENABLE REGISTER(R/W)      */
    __IO uint32_t DMAIF;                    /*!< Offset: 0x004 DMA TNT FLAG  REGISTER(R)         */
	
    #if  defined  HT762x  ||  defined  HT772x
	__I  uint32_t Reserved[62];		
	__IO uint32_t DMAIE1;                   /*!< Offset: 0x000 DMA TNT ENABLE REGISTER 1(R/W)    */
	__IO uint32_t DMAIF1;                   /*!< Offset: 0x004 DMA TNT FLAG REGISTER 1(R)        */
	__I  uint32_t Reserved1[62];	
	__IO uint32_t DMAIE2;                   /*!< Offset: 0x000 DMA TNT ENABLE REGISTER 2(R/W)    */
	__IO uint32_t DMAIF2;                   /*!< Offset: 0x004 DMA TNT FLAG REGISTER 2(R)        */
    #else
    __IO uint32_t CHNSTA;                   /*!< Offset: 0x008 DMA STATE REGISTER(R/W)           */
    #endif

} HT_DMA_TypeDef;                           /* end of group HT_DMA_TypeDef                */

typedef struct
{
    __IO uint32_t CHNCTL;                   /*!< Offset: 0x000 CHANNEL CTRL REGISTER(R/W)      			 		*/
    __IO uint32_t CHNSRC;                   /*!< Offset: 0x004 CHANNEL SOURCE ADDR REGISTER(R/W)    		*/
    __IO uint32_t CHNTAR;                   /*!< Offset: 0x008 CHANNEL DESTINATION ADDR REGISTER(R/W)   */
    __IO uint32_t CHNCNT;                   /*!< Offset: 0x00C CHANNEL TRANSFER SIZE REGISTER(R/W)*/
    __I  uint32_t CHNTCCNT;                 /*!< Offset: 0x010 CHANNEL TRANSFER DONE DATA SIZE REGISTER (R)   */
    __IO uint32_t CHNBULKNUM;               /*!< Offset: 0x014 CHANNEL BULK	SIZE REGISTER (R/W) 				*/
} HT_DMA_Channel_TypeDef;                   /* end of group HT_DMA_Channel_TypeDef        							*/

    #if  defined  HT762x  ||  defined  HT772x
typedef struct
{
    __IO uint32_t CHNCTL;                   /*!< Offset: 0x000 CHANNEL12 CTRL REGISTER      				(R/W)   */
    __IO uint32_t CHNSRC;                   /*!< Offset: 0x004 CHANNEL12 SOURCE ADDR REGISTER    		(R/W)   */
    __IO uint32_t CHNTAR0;                  /*!< Offset: 0x008 CHANNEL12 DESTINATION ADDR REGISTER0 (R/W)   */
    __IO uint32_t CHNTAR1;                  /*!< Offset: 0x00C CHANNEL12 DESTINATION ADDR REGISTER1 (R/W)   */	
    __IO uint32_t CHNTAR2;                  /*!< Offset: 0x010 CHANNEL12 DESTINATION ADDR REGISTER2 (R/W)   */
    __IO uint32_t CHNTAR3;                  /*!< Offset: 0x014 CHANNEL12 DESTINATION ADDR REGISTER3 (R/W)   */
    __IO uint32_t CHNTAR4;                  /*!< Offset: 0x018 CHANNEL12 DESTINATION ADDR REGISTER4 (R/W)   */
    __IO uint32_t CHNTAR5;                  /*!< Offset: 0x01C CHANNEL12 DESTINATION ADDR REGISTER5 (R/W)   */
    __IO uint32_t CHNTAR6;                  /*!< Offset: 0x020 CHANNEL12 DESTINATION ADDR REGISTER6 (R/W)   */
    __IO uint32_t CHNSIZE;                  /*!< Offset: 0x024 CHANNEL12 LENGTH CTRL REGISTER  			(R/W)   */	
    __IO uint32_t CHNCLR;                   /*!< Offset: 0x028 CHANNEL12 CLEAR ENABLE REGISTER  		(R/W)   */	
    __IO uint32_t CHNPACK;                  /*!< Offset: 0x02C EMU PACK DATA LENGTH REGISTER				(R/W)   */	
    __IO uint32_t CHNEMUOFFSET;         		/*!< Offset: 0x030 EMU CHANNEL DATA TRANS OFFSET REGISTER(R/W)  */		
    __IO uint32_t CHNIDX;          					/*!< Offset: 0x034 EMU CHANNEL ID REGISTER   						 (R/W)  */
    __IO uint32_t CHNINTCNT;          			/*!< Offset: 0x038 TRANSFER DATA CNT REGISTER       		 (R/W)  */
    __IO uint32_t CHNPACKCNT;         			/*!< Offset: 0x03C PACK CNT REGISTER                     (R/W)  */	
    __IO uint32_t CHNSTARTOFFSET;           /*!< Offset: 0x040 DESTINATION ADDR START OFFSET REGISTER(R/W)  */		

} HT_FFTDMA_Channel_TypeDef;                   /* end of group HT_DMA_Channel_TypeDef        */
    #endif
#endif


/*****************************************  CRC Control Block  *******************************************/
/**
* @brief CRC register define
*/
#if  defined  USE_CRC
typedef struct
{
    __IO uint32_t CRCCON;                         /*!< Offset: 0x000 CRC Control Register (R/W)    */
    union
    {
        __IO uint32_t CRCDAT;                     /*!< Offset: 0x004 CRC Data Register (R/W)       */
        __O  uint32_t CRCDAT_DWORD;               /*!<    Reserved                              */
        __O  uint16_t CRCDAT_WORD;                /*!<    Reserved                              */
        __O  uint16_t Reserved_WORD;              /*!<    Reserved                              */
        __O  uint8_t  CRCDAT_BYTE;
        __O  uint8_t  Reserved_BYTE[3];
    };
    __IO uint32_t CRCINIT;                   /*!< Offset: 0x008 CRC Initialization SEED  Register(R/W)    */
} HT_CRC_TypeDef;                            /* end of group HT_CRC_TypeDef                 */
#endif


/*****************************************  AES Control Block  *******************************************/
/**
* @brief AES register define
*/
#if defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x ||  defined  HT762x  ||  defined  HT772x || defined  HT503x || defined  HT633x
typedef struct
{
    __IO uint32_t AESCON;                    /*!< Offset: 0x000 AES Control Register (R/W)                */
    __O  uint32_t AESSTR;                    /*!< Offset: 0x004 AES Opertion Start Register (W)           */
    __I  uint32_t AESFLG;                    /*!< Offset: 0x008 AES Flag Register (R/W)                   */
    __IO uint32_t AESINLL;                   /*!< Offset: 0x00C AES Input Data: Bit 0-31 (R/W)            */
    __IO uint32_t AESINML;                   /*!< Offset: 0x010 AES Input Data: Bit 32-63 (R/W)          */
    __IO uint32_t AESINHM;                   /*!< Offset: 0x014 AES Input Data: Bit 64-95 (R/W)          */
    __IO uint32_t AESINHH;                   /*!< Offset: 0x018 AES Input Data: Bit 96-127 (R/W)         */
    __IO uint32_t AESOUTLL;                  /*!< Offset: 0x02C AES Output Data: Bit 0-31 (R/W)          */
    __IO uint32_t AESOUTML;                  /*!< Offset: 0x020 AES Output Data: Bit 32-63 (R/W)          */
    __IO uint32_t AESOUTHM;                  /*!< Offset: 0x024 AES Output Data: Bit 64-95 (R/W)          */
    __IO uint32_t AESOUTHH;                  /*!< Offset: 0x028 AES Output Data: Bit 96-127 (R/W)         */
    __IO uint32_t AESKEY0;                   /*!< Offset: 0x02C AES Key Register0 (R/W)                   */
    __IO uint32_t AESKEY1;                   /*!< Offset: 0x030 AES Key Register1 (R/W)                   */
    __IO uint32_t AESKEY2;                   /*!< Offset: 0x034 AES Key Register2 (R/W)                   */
    __IO uint32_t AESKEY3;                   /*!< Offset: 0x038 AES Key Register3 (R/W)                   */
    __IO uint32_t AESKEY4;                   /*!< Offset: 0x03C AES Key Register4 (R/W)                   */
    __IO uint32_t AESKEY5;                   /*!< Offset: 0x040 AES Key Register5 (R/W)                   */
    __IO uint32_t AESKEY6;                   /*!< Offset: 0x044 AES Key Register6 (R/W)                   */
    __IO uint32_t AESKEY7;                   /*!< Offset: 0x048 AES Key Register7 (R/W)                   */
} HT_AES_TypeDef;                            /* end of group HT_AES_TypeDef                               */
#endif

#if defined  HT6x2x  || defined HT502x  ||  defined HT6x3x || defined  HT762x  ||  defined  HT772x || defined  HT503x || defined  HT633x
typedef struct
{
    __IO uint32_t RANDSTR;                    /*!< Offset: 0x000 RAND Module Start Register (R/W)             */
    __IO uint32_t RANDDAT;                    /*!< Offset: 0x004 RAND Data Register (R/W)                 */
} HT_RAND_TypeDef;                            /* end of group HT_RAND_TypeDef                             */
#endif

#if defined HT501x || defined HT6x2x  || defined HT502x  || defined HT6x3x  || defined  HT762x  ||  defined  HT772x || defined  HT503x || defined  HT633x
typedef struct
{
    __O  uint32_t GHASHSTR;                   /*!< Offset: 0x000 GHASH Start Register (W)                   */
    __I  uint32_t GHASHFLG;                   /*!< Offset: 0x004 GHASH Flag Register (R/W)                     */
    __IO uint32_t INPUT1LL;                   /*!< Offset: 0x008 GHASH Input Data1: Bit 0-31 (R/W)                  */
    __IO uint32_t INPUT1ML;                   /*!< Offset: 0x00C GHASH Input Data1: Bit 32-63 (R/W)                */
    __IO uint32_t INPUT1HM;                   /*!< Offset: 0x010 GHASH Input Data1: Bit 64-95 (R/W)                */
    __IO uint32_t INPUT1HH;                   /*!< Offset: 0x014 GHASH Input Data1: Bit 96-127 (R/W)                  */
    __IO uint32_t INPUT2LL;                   /*!< Offset: 0x018 GHASH Input Data1: Bit 0-31 (R/W)                  */
    __IO uint32_t INPUT2ML;                   /*!< Offset: 0x01C GHASH Input Data1: Bit 32-63 (R/W)                */
    __IO uint32_t INPUT2HM;                   /*!< Offset: 0x020 GHASH Input Data1: Bit 64-95 (R/W)                */
    __IO uint32_t INPUT2HH;                   /*!< Offset: 0x024 GHASH Input Data1: Bit 96-127 (R/W)                  */
    __IO uint32_t OUTPUTLL;                   /*!< Offset: 0x028 GHASH Output Data: Bit 0-31 (R/W)                   */
    __IO uint32_t OUTPUTML;                   /*!< Offset: 0x02C GHASH Output Data: Bit 32-63 (R/W)                 */
    __IO uint32_t OUTPUTHM;                   /*!< Offset: 0x030 GHASH Output Data: Bit 64-95 (R/W)                 */
    __IO uint32_t OUTPUTHH;                   /*!< Offset: 0x034 GHASH Output Data: Bit 96-127 (R/W)                   */
    __IO uint32_t AESGHASHIE;                 /*!< Offset: 0x038 AES/GHASH Interrupt Enable (R/W)                 */
    __IO uint32_t AESGHASHIF;                 /*!< Offset: 0x03C AES/GHASH Interrupt Flag (R/W)                 */
} HT_GHASH_TypeDef;                           /* end of group HT_GHASH_TypeDef                             */
#endif


/*****************************************  EMU Control Block  *******************************************/
/**
* @brief EMU EPR define
*/
#if defined  HT501x  ||  defined  HT502x
typedef struct
{
    __I uint32_t SPLI1;                       /*!< Offset: 0x000  current 1 ADC sample data 					(R)*/
    __I uint32_t SPLI2;                       /*!< Offset: 0x004  current 2 ADC sample data 					(R)*/
    __I uint32_t SPLU;                        /*!< Offset: 0x008  voltage ADC sample data 	    				(R)*/
    __I uint32_t SPLP;                        /*!< Offset: 0x00C  all active power sample data         			(R)*/
    __I uint32_t SPLQ;                        /*!< Offset: 0x010  reactive power sample data 					(R)*/
    __I uint32_t FASTRMSI1;                   /*!< Offset: 0x014  fast current 1 rms               				(R)*/
    __I uint32_t FASTRMSI2;                   /*!< Offset: 0x018  fast current 2 rms               				(R)*/
    __I uint32_t FASTRMSU;                    /*!< Offset: 0x01C  fast voltage rms                 				(R)*/
    __I uint32_t FREQU;                       /*!< Offset: 0x020  voltage frenquence							(R)*/
    __I uint32_t FASTPOWERP1;                 /*!< Offset: 0x024  fast channel 1 active power  					(R)*/
    __I uint32_t FASTPOWERQ1;                 /*!< Offset: 0x028  fast channel 1 reactive power  				(R)*/
    __I uint32_t FASTPOWERP2;                 /*!< Offset: 0x02C  fast channel 2 active power  					(R)*/
    __I uint32_t FASTPOWERQ2;                 /*!< Offset: 0x030  fast channel 2 reactive power  				(R)*/
    __I uint32_t FASTPOWERS1;                 /*!< Offset: 0x034  fast channel 1 apparent power  				(R)*/
    __I uint32_t FASTPOWERS2;                 /*!< Offset: 0x038  fast channel 2 apparent power  				(R)*/
    __I uint32_t RMSI1;                       /*!< Offset: 0x03C  slow current 1 rms               				(R)*/
    __I uint32_t RMSI2;                       /*!< Offset: 0x040  slow current 2 rms               				(R)*/
    __I uint32_t RMSU;                        /*!< Offset: 0x044  slow voltage rms                				(R)*/
    __I uint32_t POWERP1;                     /*!< Offset: 0x048  slow channel 1 active power  					(R)*/
    __I uint32_t POWERQ1;                     /*!< Offset: 0x04C  slow channel 1 reactive power  				(R)*/
    __I uint32_t POWERP2;                     /*!< Offset: 0x050  slow channel 2 active power  					(R)*/
    __I uint32_t POWERQ2;                     /*!< Offset: 0x054  slow channel 2 reactive power  				(R)*/
    __I uint32_t POWERS1;                     /*!< Offset: 0x058  slow channel 1 apparent power  				(R)*/
    __I uint32_t POWERS2;                     /*!< Offset: 0x05C  slow channel 2 apparent power  				(R)*/
    __I uint32_t ENERGYP;                     /*!< Offset: 0x060  active nenrgy 								(R)*/
    __I uint32_t ENERGYQ;                     /*!< Offset: 0x064  reactive nenrgy 								(R)*/
    __I uint32_t ENERGYS;                     /*!< Offset: 0x068  apparent nenrgy 								(R)*/
    __I uint32_t ENERGYPC;                    /*!< Offset: 0x06C  active nenrgy (read after clear)	 			(R)*/
    __I uint32_t ENERGYQC;                    /*!< Offset: 0x070  reactive nenrgy (read after clear)			(R)*/
    __I uint32_t ENERGYSC;                    /*!< Offset: 0x074  apparent nenrgy (read after clear)			(R)*/
    __I uint32_t DC_UAVERAGE;                 /*!< Offset: 0x078  DC voltage data								(R)*/
    __I uint32_t DC_I1AVERAGE;                /*!< Offset: 0x07C  DC current 1 data								(R)*/
    __I uint32_t DC_I2AVERAGE;                /*!< Offset: 0x080  DC current 2 data								(R)*/
    __I uint32_t CHECKSUM;                    /*!< Offset: 0x084  check sum 1 				            		(R)*/
    __I uint32_t UPEAK;                       /*!< Offset: 0x088  half cycle voltage peak 			    		(R)*/
    __I uint32_t I1PEAK;                      /*!< Offset: 0x08C  half cycle current 1 peak    					(R)*/
    __I uint32_t I2PEAK;                      /*!< Offset: 0x090  half cycle current 2 peak    					(R)*/
    __I uint32_t PFCNT_PHOTO;                 /*!< Offset: 0x094  PFCNT photo 									(R)*/
    __I uint32_t QFCNT_PHOTO;                 /*!< Offset: 0x098  QFCNT photo 									(R)*/
    __I uint32_t SFCNT_PHOTO;                 /*!< Offset: 0x09C  SFCNT photo 									(R)*/
    __I uint32_t AUTOUGAIN;                   /*!< Offset: 0x0A0  voltage automatic Temperature compensation    (R)*/
    __I uint32_t AUTOI1GAIN;                  /*!< Offset: 0x0A4  current 1 automatic Temperature compensation  (R)*/
    __I uint32_t AUTOI2GAIN;                  /*!< Offset: 0x0A8  current 2 automatic Temperature compensation  (R)*/
    __I uint32_t R_Buffer;                    /*!< Offset: 0x0AC  buffer read data 								(R)*/
    __I uint32_t Reserved[2];
    __I uint32_t UdetCNT;                     /*!< Offset: 0x0B8  voltage During peak/sag of half cycle count 	(R)*/
} HT_EMU_EPR_TypeDef;                         /* end of group HT_EMU_EPR_TypeDef           */

/**
* @brief EMU ECR define
*/
typedef struct
{
    __IO uint32_t EMUSR;                      /*!< Offset: 0x000  EMU status flag                				(R/W)*/
    __IO uint32_t EMUIE;                      /*!< Offset: 0x004  EMU interrupt enable                 			(R/W)*/
    __IO uint32_t EMUIF;                      /*!< Offset: 0x008  EMU interrupt flag                			(R/W)*/
    __IO uint32_t GP1;                        /*!< Offset: 0x00C  channel 1 active power GAIN           		(R/W)*/
    __IO uint32_t GQ1;                        /*!< Offset: 0x010  channel 1 reactive power GAIN           		(R/W)*/
    __IO uint32_t GS1;                        /*!< Offset: 0x014  channel 1 apparent power GAIN           		(R/W)*/
    __IO uint32_t GPHS1;                      /*!< Offset: 0x018  channel 1 phase correction                	(R/W)*/
    __IO uint32_t GP2;                        /*!< Offset: 0x01C  channel 2 active power GAIN           		(R/W)*/
    __IO uint32_t GQ2;                        /*!< Offset: 0x020  channel 2 reactive power GAIN           		(R/W)*/
    __IO uint32_t GS2;                        /*!< Offset: 0x024  channel 2 apparent power GAIN           		(R/W)*/
    __IO uint32_t GPHS2;                      /*!< Offset: 0x028  channel 2 phase correction                	(R/W)*/
    __IO uint32_t QPHSCAL;                    /*!< Offset: 0x02C  reactive power phase compensation				(R/W)*/
    __IO uint32_t I2GAIN;                     /*!< Offset: 0x030  current 2 gain           						(R/W)*/
    __IO uint32_t I1OFF;                      /*!< Offset: 0x034  current 1 small signal offset correction      (R/W)*/
    __IO uint32_t I2OFF;                      /*!< Offset: 0x038  current 2 small signal offset correction      (R/W)*/
    __IO uint32_t UOFF;                       /*!< Offset: 0x03C  voltage small signal offset correction        (R/W)*/
    __IO uint32_t PSTART;                     /*!< Offset: 0x040  active power start                   			(R/W)*/
    __IO uint32_t QSTART;                     /*!< Offset: 0x044  reactive power start                 			(R/W)*/
    __IO uint32_t SSTART;                     /*!< Offset: 0x048  apparentt power start                 		(R/W)*/
    __IO uint32_t HFCONST;                    /*!< Offset: 0x04C  HFCONST                  						(R/W)*/
    __IO uint32_t ADCCFG;                     /*!< Offset: 0x050  ADCCFG                     					(R/W)*/
    __IO uint32_t CHNLCR;                     /*!< Offset: 0x054  CHNLCR                  						(R/W)*/
    __IO uint32_t EMCON;                      /*!< Offset: 0x058  EMUCON                 						(R/W)*/
    __IO uint32_t PFCNT;                      /*!< Offset: 0x05C  energy P fast cf       						(R/W)*/
    __IO uint32_t QFCNT;                      /*!< Offset: 0x060  energy Q fast cf       						(R/W)*/
    __IO uint32_t SFCNT;                      /*!< Offset: 0x064  energy S fast cf       						(R/W)*/
    __IO uint32_t ADCCON;                     /*!< Offset: 0x068  ADCCON                   						(R/W)*/
    __IO uint32_t IPTAMP;                     /*!< Offset: 0x06C  IPTAMP                      					(R/W)*/
    __IO uint32_t ICHK;                       /*!< Offset: 0x070  ICHK                      					(R/W)*/
    __IO uint32_t EMUCTRL;                    /*!< Offset: 0x074  EMUCTRL                     					(R/W)*/
    __IO uint32_t P1OFFSET;                   /*!< Offset: 0x078  channel 1 active power small signal correction   (R/W)*/
    __IO uint32_t P2OFFSET;                   /*!< Offset: 0x07C  channel 2 active power small signal correction   (R/W)*/
    __IO uint32_t Q1OFFSET;                   /*!< Offset: 0x080  channel 1 reactive power small signal correction (R/W)*/
    __IO uint32_t Q2OFFSET;                   /*!< Offset: 0x084  channel 2 reactive power small signal correction (R/W)*/
    __IO uint32_t I1RMSOFFSET;                /*!< Offset: 0x088  current 1 small signal rms correction  		(R/W)*/
    __IO uint32_t I2RMSOFFSET;                /*!< Offset: 0x08C  current 2 small signal rms correction  		(R/W)*/
    __IO uint32_t URMSOFFSET;                 /*!< Offset: 0x090  voltage small signal rms correction  			(R/W)*/
    __IO uint32_t ROSICTRL;                   /*!< Offset: 0x094  RosiCtrl										(R/W)*/
    __IO uint32_t ANACTRL;                    /*!< Offset: 0x098  ANA_CTRL										(R/W)*/
    __IO uint32_t UCONST;                     /*!< Offset: 0x09C  UConst           								(R/W)*/
    __IO uint32_t LPIDELTIME;                 /*!< Offset: 0x0A0  low power mode idle time						(R/W)*/
#if defined HT502x
    __IO uint32_t USAGLVL;                    /*!< Offset: 0x0A4  voltage sag detection threshold               (R/W)*/
    __IO uint32_t IPEAKCYC;                   /*!< Offset: 0x0A8  current overflow detection half cycle num     (R/W)*/
    __IO uint32_t UOVLVL;                     /*!< Offset: 0x0AC  voltage peak detection threshold              (R/W)*/
    __IO uint32_t OVCyc;                      /*!< Offset: 0x0B0  voltage sag and peak detection half cycle num (R/W)*/
#else
    __IO uint32_t USAGLVL;                    /*!< Offset: 0x0A4  voltage sag detection threshold               (R/W)*/
    __IO uint32_t USAGCYC;                    /*!< Offset: 0x0A8  voltage sag  detection half cycle num 		(R/W)*/
    __IO uint32_t UOVLVL;                     /*!< Offset: 0x0AC  voltage peak detection threshold              (R/W)*/
    __IO uint32_t OVCYC;                      /*!< Offset: 0x0B0  voltage peak  detection half cycle num 		(R/W)*/
#endif
    __IO uint32_t IOVLVL;                     /*!< Offset: 0x0B4  current peak detection threshold              (R/W)*/
    __IO uint32_t ZXILVL;                     /*!< Offset: 0x0B8  current zerocross threshold                   (R/W)*/
    __IO uint32_t PDATCPH;                    /*!< Offset: 0x0BC  active power constant high 16bit              (R/W)*/
    __IO uint32_t PDATCPL;                    /*!< Offset: 0x0C0  active power constant low 16bit               (R/W)*/
    __IO uint32_t QDATCPH;                    /*!< Offset: 0x0C4  reactive power constant high 16bit            (R/W)*/
    __IO uint32_t QDATCPL;                    /*!< Offset: 0x0C8  reactive power constant low 16bit             (R/W)*/
    __IO uint32_t SDATCPH;                    /*!< Offset: 0x0CC  apparent power constant high 16bit            (R/W)*/
    __IO uint32_t SDATCPL;                    /*!< Offset: 0x0D0  apparent power constant low 16bit             (R/W)*/
    __IO uint32_t FILTERCTRL;                 /*!< Offset: 0x0D4  FilterCTRL                  					(R/W)*/
    __IO uint32_t TUGAIN;                     /*!< Offset: 0x0D8  voltage temperature compensation gain         (R/W)*/
    __IO uint32_t TI1GAIN;                    /*!< Offset: 0x0DC  current 1 temperature compensation gain       (R/W)*/
    __IO uint32_t TI2GAIN;                    /*!< Offset: 0x0E0  current 2 temperature compensation gain       (R/W)*/
    __IO uint32_t UTCCOFFA;                   /*!< Offset: 0x0E4  voltage Vref gain Quadratic coefficient       (R/W)*/
    __IO uint32_t UTCCOFFB;                   /*!< Offset: 0x0E8  voltage Vrefgain Coefficient of primary term  (R/W)*/
    __IO uint32_t UTCCOFFC;                   /*!< Offset: 0x0EC  voltage Vrefgain Constant term coefficient    (R/W)*/
    __IO uint32_t I1TCCOFFA;                  /*!< Offset: 0x0F0  current1 Vref gain Quadratic coefficient      (R/W)*/
    __IO uint32_t I1TCCOFFB;                  /*!< Offset: 0x0F4  current1 Vrefgain Coefficient of primary term (R/W)*/
    __IO uint32_t I1TCCOFFC;                  /*!< Offset: 0x0F8  current1 Vrefgain Constant term coefficient   (R/W)*/
    __IO uint32_t I2TCCOFFA;                  /*!< Offset: 0x0FC  current2 Vref gain Quadratic coefficient      (R/W)*/
    __IO uint32_t I2TCCOFFB;                  /*!< Offset: 0x100  current2 Vrefgain Coefficient of primary term (R/W)*/
    __IO uint32_t I2TCCOFFC;                  /*!< Offset: 0x104  current2 Vrefgain Constant term coefficient   (R/W)*/
    __IO uint32_t LOADDATACP;                 /*!< Offset: 0x108  power constant load                    		(R/W)*/
#if defined HT502x
    __IO uint32_t BufferStart;                /*!< Offset: 0x10C  buffer start(no checksum)                 	(R/W)*/
    __IO uint32_t BufferCoff;                 /*!< Offset: 0x110  buffer coefficient(no checksum)          		(R/W)*/
#else
    __I  uint32_t Reserved[2];                /*!<               RESERVED                      */
#endif
    __IO uint32_t SRSTREG;                    /*!< Offset: 0x114  soft reset  or reset Calibration register     (R/W)*/
#if defined  HT502x
    __IO uint32_t PFCNTN;                     /*!< Offset: 0x118  energy P fast PLUSE       					(R/W)*/
    __IO uint32_t QFCNTN;                     /*!< Offset: 0x11C  energy Q fast PLUSE      						(R/W)*/
#endif
} HT_EMU_ECR_TypeDef;                         /* end of group HT_EMU_ECR_TypeDef                                       */
#endif


#if defined  HT503x
typedef struct
{
    __I uint32_t SPL_I1;                       /*!< Offset: 0x000  current 1 ADC sample data 					(R)*/
    __I uint32_t SPL_I2;                       /*!< Offset: 0x004  current 2 ADC sample data 					(R)*/
    __I uint32_t SPL_U;                        /*!< Offset: 0x008  voltage ADC sample data 	    				(R)*/
    __I uint32_t All_SPL_PowerP;               /*!< Offset: 0x00C  all active power sample data         		(R)*/
    __I uint32_t All_SPL_PowerQ;               /*!< Offset: 0x010  all reactive power sample data 				(R)*/
    __I uint32_t All_FastRMS_I1;               /*!< Offset: 0x014  all fast current 1 rms               		(R)*/
    __I uint32_t All_FastRMS_I2;               /*!< Offset: 0x018  all fast current 2 rms               		(R)*/
    __I uint32_t All_FastRMS_U;                /*!< Offset: 0x01C  all fast voltage rms                 		(R)*/
    __I uint32_t Freq_U;                       /*!< Offset: 0x020  voltage frenquence							(R)*/
    __I uint32_t All_FastPower_P1;             /*!< Offset: 0x024  all fast channel 1 active power  			(R)*/
    __I uint32_t All_FastPower_Q1;             /*!< Offset: 0x028  all fast channel 1 reactive power  			(R)*/
    __I uint32_t All_FastPower_P2;             /*!< Offset: 0x02C  all fast channel 2 active power  			(R)*/
    __I uint32_t All_FastPower_Q2;             /*!< Offset: 0x030  all fast channel 2 reactive power  			(R)*/
    __I uint32_t FastPower_S1;                 /*!< Offset: 0x034  fast channel 1 apparent power  				(R)*/
    __I uint32_t FastPower_S2;                 /*!< Offset: 0x038  fast channel 2 apparent power  				(R)*/
    __I uint32_t All_SlowRMS_I1;               /*!< Offset: 0x03C  all slow current 1 rms               		(R)*/
    __I uint32_t All_SlowRMS_I2;               /*!< Offset: 0x040  all slow current 2 rms               		(R)*/
    __I uint32_t All_SlowRMS_U;                /*!< Offset: 0x044  all slow voltage rms                			(R)*/
    __I uint32_t All_SlowPower_P1;             /*!< Offset: 0x048  all slow channel 1 active power  			(R)*/
    __I uint32_t All_SlowPower_Q1;             /*!< Offset: 0x04C  all slow channel 1 reactive power  			(R)*/
    __I uint32_t All_SlowPower_P2;             /*!< Offset: 0x050  all slow channel 2 active power  			(R)*/
    __I uint32_t All_SlowPower_Q2;             /*!< Offset: 0x054  all slow channel 2 reactive power  			(R)*/
    __I uint32_t SlowPower_S1;                 /*!< Offset: 0x058  slow channel 1 apparent power  				(R)*/
    __I uint32_t SlowPower_S2;                 /*!< Offset: 0x05C  slow channel 2 apparent power  				(R)*/
    __I uint32_t Energy_Neg_CF1;               /*!< Offset: 0x060  channel 1 negtive nenrgy 					(R)*/
    __I uint32_t Energy_Neg_CF2;               /*!< Offset: 0x064  channel 2 negtive nenrgy 					(R)*/
    __I uint32_t Energy_Neg_CF3;               /*!< Offset: 0x068  channel 3 negtive nenrgy 					(R)*/
    __I uint32_t Energy_CF1;                   /*!< Offset: 0x06C  channel 1 positive nenrgy 					(R)*/
    __I uint32_t Energy_CF2;                   /*!< Offset: 0x070  channel 2 positive nenrgy 					(R)*/
    __I uint32_t Energy_CF3;                   /*!< Offset: 0x074  channel 3 positive nenrgy 					(R)*/
    __I uint32_t DCAVG_U;                 	   /*!< Offset: 0x078  DC voltage data								(R)*/
    __I uint32_t DCAVG_I1;                     /*!< Offset: 0x07C  DC current 1 data							(R)*/
    __I uint32_t DCAVG_I2;                     /*!< Offset: 0x080  DC current 2 data							(R)*/
    __I uint32_t CheckSum1;                    /*!< Offset: 0x084  check sum 1 				            		(R)*/
    __I uint32_t HCycleVp_U;                   /*!< Offset: 0x088  half cycle voltage peak 			    		(R)*/
    __I uint32_t HCycleVp_I1;                  /*!< Offset: 0x08C  half cycle current 1 peak    				(R)*/
    __I uint32_t HCycleVp_I2;                  /*!< Offset: 0x090  half cycle current 2 peak    				(R)*/
    __I uint32_t HCycleRMS_U;                  /*!< Offset: 0x094  half cycle voltage rms    		    		(R)*/
    __I uint32_t HCycleRMS_I;                  /*!< Offset: 0x098  half cycle current  rms    	    			(R)*/
    __I uint32_t Reserved1;                    /*!< Offset: 0x09C  reserved 						    		(R)*/
    __I uint32_t AutoTgain_U;                  /*!< Offset: 0x0A0  voltage automatic Temperature compensation   (R)*/
    __I uint32_t AutoTgain_I1;                 /*!< Offset: 0x0A4  current 1 automatic Temperature compensation (R)*/
    __I uint32_t AutoTgain_I2;                 /*!< Offset: 0x0A8  current 2 automatic Temperature compensation (R)*/
    __I uint32_t Reserved2[3];                 /*!< Offset: 0x0AC  ~0xB4 reserved								(R)*/
    __I uint32_t PeakCnt;                      /*!< Offset: 0x0B8  voltage During peak of half cycle count		(R)*/
	__I uint32_t PeakVp;                       /*!< Offset: 0x0BC  voltage During peak of max data 	    	    (R)*/
    __I uint32_t SagCnt;                       /*!< Offset: 0x0C0  voltage During sag of half cycle count		(R)*/
    __I uint32_t SagVp;                        /*!< Offset: 0x0C4  voltage During sag of max data 	    	    (R)*/
    __I uint32_t FlickerPinst;                 /*!< Offset: 0x0C8  voltage flicker pinst						(R)*/
    __I uint32_t ADCSync_U;                    /*!< Offset: 0x0CC  voltage sync sample data 					(R)*/
    __I uint32_t ADCSync_I;                    /*!< Offset: 0x0D0  current sync sample data 					(R)*/
    __I uint32_t Fund_RMS_U;                   /*!< Offset: 0x0D4  fund voltage rms								(R)*/
    __I uint32_t Fund_RMS_I1;                  /*!< Offset: 0x0D8  fund current 1 rms							(R)*/
    __I uint32_t Fund_RMS_I2;                  /*!< Offset: 0x0DC  fund current 2 rms							(R)*/
    __I uint32_t Fund_Power_P1;                /*!< Offset: 0x0E0  fund channel 1 active power     			    (R)*/
    __I uint32_t Fund_Power_P2;                /*!< Offset: 0x0E4  fund channel 2 active power     			    (R)*/
    __I uint32_t Reserved3;                    /*!< Offset: 0x0E8  reserved										(R)*/
    __I uint32_t CycRms_U;                     /*!< Offset: 0x0EC  voltage one cycle RMS 						(R)*/
    __I uint32_t CycRms_I1;                    /*!< Offset: 0x0F0  current 1 one cycle RMS 						(R)*/
    __I uint32_t CycRms_I2;                    /*!< Offset: 0x0F4  current 2 one cycle RMS 						(R)*/
    __I uint32_t CheckSum2;                    /*!< Offset: 0x0F8  check sum 2									(R)*/

} HT_EMU_EPR_TypeDef;                         /* end of group HT_EMU_EPR_TypeDef  */

/*
* @brief EMU ECR define
*/
typedef struct
{
    __IO uint32_t EMUSR;                      /*!< Offset: 0x000  EMU status flag                				(R/W)*/
    __IO uint32_t EMUIE;                      /*!< Offset: 0x004  EMU interrupt enable                 			(R/W)*/
    __IO uint32_t EMUIF;                      /*!< Offset: 0x008  EMU interrupt flag                			(R/W)*/
    __IO uint32_t All_GP1;                    /*!< Offset: 0x00C  all channel 1 active power Gain           	(R/W)*/
    __IO uint32_t All_GQ1;                    /*!< Offset: 0x010  all channel 1 reactive power Gain           	(R/W)*/
    __IO uint32_t GS1;                        /*!< Offset: 0x014  all channel 1 apparent power Gain           	(R/W)*/
    __IO uint32_t All_GPhs1;                  /*!< Offset: 0x018  all channel 1 phase correction                (R/W)*/
    __IO uint32_t All_GP2;                    /*!< Offset: 0x01C  all channel 2 active power Gain           	(R/W)*/
    __IO uint32_t All_GQ2;                    /*!< Offset: 0x020  all channel 2 reactive power Gain           	(R/W)*/
    __IO uint32_t GS2;                        /*!< Offset: 0x024  all channel 2 apparent power Gain           	(R/W)*/
    __IO uint32_t All_GPhs2;                  /*!< Offset: 0x028  all channel 2 phase correction                (R/W)*/
    __IO uint32_t All_QPhsCal;                /*!< Offset: 0x02C  all reactive power phase compensation			(R/W)*/
    __IO uint32_t Gain_I2;                    /*!< Offset: 0x030  current 2 gain           						(R/W)*/
    __IO uint32_t ADCOffset_I1;               /*!< Offset: 0x034  current 1 small signal offset correction      (R/W)*/
    __IO uint32_t ADCOffset_I2;               /*!< Offset: 0x038  current 2 small signal offset correction      (R/W)*/
    __IO uint32_t ADCOffset_U;                /*!< Offset: 0x03C  voltage small signal offset correction        (R/W)*/
    __IO uint32_t PStart;                     /*!< Offset: 0x040  active power start                   			(R/W)*/
    __IO uint32_t QStart;                     /*!< Offset: 0x044  reactive power start                 			(R/W)*/
    __IO uint32_t SStart;                     /*!< Offset: 0x048  apparentt power start                 		(R/W)*/
    __IO uint32_t HFConst;                    /*!< Offset: 0x04C  HFCONST                  						(R/W)*/
    __IO uint32_t ADCCFG;                     /*!< Offset: 0x050  ADCCFG                     					(R/W)*/
    __IO uint32_t CHNLCR;                     /*!< Offset: 0x054  CHNLCR                  						(R/W)*/
    __IO uint32_t EMUCON;                     /*!< Offset: 0x058  EMUCON                 						(R/W)*/
    __IO uint32_t CF1Cnt;                     /*!< Offset: 0x05C  energy channel 1 positive fast cf       		(R/W)*/
    __IO uint32_t CF2Cnt;                     /*!< Offset: 0x060  energy channel 2 positive fast cf       		(R/W)*/
    __IO uint32_t CF3Cnt;                     /*!< Offset: 0x064  energy channel 3 positive fast cf       		(R/W)*/
    __IO uint32_t ADCCON;                     /*!< Offset: 0x068  ADCCON                   						(R/W)*/
    __IO uint32_t IPTAMP;                     /*!< Offset: 0x06C  IPTAMP                      					(R/W)*/
    __IO uint32_t ICHK;                       /*!< Offset: 0x070  ICHK                      					(R/W)*/
    __IO uint32_t EMUCTRL;                    /*!< Offset: 0x074  EMUCTRL                     					(R/W)*/
    __IO uint32_t All_PowerOffset_P1;         /*!< Offset: 0x078  all channel 1 active power small signal correction   (R/W)*/
    __IO uint32_t All_PowerOffset_P2;         /*!< Offset: 0x07C  all channel 2 active power small signal correction   (R/W)*/
    __IO uint32_t All_PowerOffset_Q1;         /*!< Offset: 0x080  all channel 1 reactive power small signal correction (R/W)*/
    __IO uint32_t All_PowerOffset_Q2;         /*!< Offset: 0x084  all channel 2 reactive power small signal correction (R/W)*/
    __IO uint32_t All_RmsOffset_I1;           /*!< Offset: 0x088  all current 1 small signal rms correction  	(R/W)*/
    __IO uint32_t All_RmsOffset_I2;           /*!< Offset: 0x08C  all current 2 small signal rms correction  	(R/W)*/
    __IO uint32_t All_RmsOffset_U;            /*!< Offset: 0x090  all voltage small signal rms correction  		(R/W)*/
    __IO uint32_t RosiCtrl;                   /*!< Offset: 0x094  RosiCtrl										(R/W)*/
    __IO uint32_t ANA_CTRL;                   /*!< Offset: 0x098  ANA_CTRL										(R/W)*/
    __IO uint32_t UConst;                     /*!< Offset: 0x09C  UConst           								(R/W)*/
    __IO uint32_t LpIdleTime;                 /*!< Offset: 0x0A0  low power mode idle time						(R/W)*/
    __IO uint32_t USagLVL;                    /*!< Offset: 0x0A4  voltage sag detection threshold               (R/W)*/
    __IO uint32_t IOVHCyc;                    /*!< Offset: 0x0A8  current overflow detection half cycle num     (R/W)*/
    __IO uint32_t UPeakLVL;                   /*!< Offset: 0x0AC  voltage peak detection threshold              (R/W)*/
    __IO uint32_t PeakSagHCyc;                /*!< Offset: 0x0B0  voltage sag and peak detection half cycle num (R/W)*/
    __IO uint32_t IOVLVL;                     /*!< Offset: 0x0B4  current peak detection threshold              (R/W)*/
    __IO uint32_t IZCLVL;                     /*!< Offset: 0x0B8  current zerocross threshold                   (R/W)*/
    __IO uint32_t PowerConst_PH;              /*!< Offset: 0x0BC  active power constant high 16bit              (R/W)*/
    __IO uint32_t PowerConst_PL;              /*!< Offset: 0x0C0  active power constant low 16bit               (R/W)*/
    __IO uint32_t PowerConst_QH;              /*!< Offset: 0x0C4  reactive power constant high 16bit            (R/W)*/
    __IO uint32_t PowerConst_QL;              /*!< Offset: 0x0C8  reactive power constant low 16bit             (R/W)*/
    __IO uint32_t PowerConst_SH;              /*!< Offset: 0x0CC  apparent power constant high 16bit            (R/W)*/
    __IO uint32_t PowerConst_SL;              /*!< Offset: 0x0D0  apparent power constant low 16bit             (R/W)*/
    __IO uint32_t FilterCTRL;                 /*!< Offset: 0x0D4  FilterCTRL                  					(R/W)*/
    __IO uint32_t Tgain_U;                    /*!< Offset: 0x0D8  voltage temperature compensation gain         (R/W)*/
    __IO uint32_t Tgain_I1;                   /*!< Offset: 0x0DC  current 1 temperature compensation gain       (R/W)*/
    __IO uint32_t Tgain_I2;                   /*!< Offset: 0x0E0  current 2 temperature compensation gain       (R/W)*/
    __IO uint32_t TCOFF_UA;                   /*!< Offset: 0x0E4  voltage Vref gain Quadratic coefficient       (R/W)*/
    __IO uint32_t TCOFF_UB;                   /*!< Offset: 0x0E8  voltage Vrefgain Coefficient of primary term  (R/W)*/
    __IO uint32_t TCOFF_UC;                   /*!< Offset: 0x0EC  voltage Vrefgain Constant term coefficient    (R/W)*/
    __IO uint32_t TCOFF_I1A;                  /*!< Offset: 0x0F0  current1 Vref gain Quadratic coefficient      (R/W)*/
    __IO uint32_t TCOFF_I1B;                  /*!< Offset: 0x0F4  current1 Vrefgain Coefficient of primary term (R/W)*/
    __IO uint32_t TCOFF_I1C;                  /*!< Offset: 0x0F8  current1 Vrefgain Constant term coefficient   (R/W)*/
    __IO uint32_t TCOFF_I2A;                  /*!< Offset: 0x0FC  current2 Vref gain Quadratic coefficient      (R/W)*/
    __IO uint32_t TCOFF_I2B;                  /*!< Offset: 0x100  current2 Vrefgain Coefficient of primary term (R/W)*/
    __IO uint32_t TCOFF_I2C;                  /*!< Offset: 0x104  current2 Vrefgain Constant term coefficient   (R/W)*/
    __IO uint32_t PowerConstLoad;             /*!< Offset: 0x108  power constant load                    		(R/W)*/
    __IO uint32_t Reserved1;                  /*!< Offset: 0x10C  reserved                  					(R/W)*/
    __IO uint32_t SyncCoff;                   /*!< Offset: 0x110  sync  coefficient         					(R/W)*/
    __IO uint32_t SRSTREG;                    /*!< Offset: 0x114  soft reset  or reset Calibration register     (R/W)*/
    __IO uint32_t CF1CntN;                    /*!< Offset: 0x118  energy channel 1 negtive fast cf       		(R/W)*/
    __IO uint32_t CF2CntN;                    /*!< Offset: 0x11C  energy channel 2 negtive fast cf       		(R/W)*/
    __IO uint32_t CF3CntN;                    /*!< Offset: 0x120  energy channel 3 negtive fast cf       		(R/W)*/
    __IO uint32_t SyncStart;                  /*!< Offset: 0x124  sync cfg             							(R/W)*/
    __IO uint32_t HCycleRMS_dPHFix;           /*!< Offset: 0x128  half cycle RMS cfg             				(R/W)*/
    __IO uint32_t EMUCON2;                    /*!< Offset: 0x12C  EMUCON2              							(R/W)*/
    __IO uint32_t DEC_Shift;                  /*!< Offset: 0x130  dec shift correction             				(R/W)*/
    __IO uint32_t AVG_PowerRMS;               /*!< Offset: 0x134  power and rms average num             		(R/W)*/
    __IO uint32_t AFDIV;                      /*!< Offset: 0x138  AFDIV              							(R/W)*/
    __IO uint32_t LpRMS_THO;                  /*!< Offset: 0x13C  low power rms threshold              			(R/W)*/
    __IO uint32_t PeakLVLHys;                 /*!< Offset: 0x140  voltage peak hysteresis              			(R/W)*/
    __IO uint32_t SagLVLHys;                  /*!< Offset: 0x144  voltage sag hysteresis              			(R/W)*/
    __IO uint32_t UZCLVL;                     /*!< Offset: 0x148  voltage zerocross threshold              		(R/W)*/
    __IO uint32_t RMSIt_THO;                  /*!< Offset: 0x14C  RMSIT Threshold              					(R/W)*/
    __IO uint32_t Fund_GP1;                   /*!< Offset: 0x150  fund power channel 1 gain              		(R/W)*/
    __IO uint32_t Fund_GP2;                   /*!< Offset: 0x154  fund power channel 2 gain               		(R/W)*/
    __IO uint32_t Fund_PowerOffset_P1;        /*!< Offset: 0x158  fund power channel 1 small signal correction  (R/W)*/
    __IO uint32_t Fund_PowerOffset_P2;        /*!< Offset: 0x15C  fund power channel 2 small signal correction  (R/W)*/
    __IO uint32_t Fund_RmsOffset_I1;          /*!< Offset: 0x160  fund current 1 small signal rms correction  	(R/W)*/
    __IO uint32_t Fund_RmsOffset_I2;          /*!< Offset: 0x164  fund current 2 small signal rms correction  	(R/W)*/
    __IO uint32_t Fund_RmsOffset_U;           /*!< Offset: 0x168  fund voltage small signal rms correction      (R/W)*/
    __IO uint32_t FlickerCFG;                 /*!< Offset: 0x16C  flicker cfg              						(R/W)*/
    __IO uint32_t FlickerSqrOffset;           /*!< Offset: 0x170  flicker offset              					(R/W)*/
    __IO uint32_t FlickerReset;               /*!< Offset: 0x174  flicker reset              					(R/W)*/
    __IO uint32_t Fund_CFG;                   /*!< Offset: 0x178  fund cfg             							(R/W)*/
    __IO uint32_t ZCNumCFG;                   /*!< Offset: 0x17C  zerocross num cfg             				(R/W)*/
    __IO uint32_t CycRmsNum;                  /*!< Offset: 0x180  one cycle rms num              				(R/W)*/
    __IO uint32_t Reserved2;                  /*!< Offset: 0x184  reserved              						(R/W)*/
} HT_EMU_ECR_TypeDef;                         /* end of group HT_EMU_ECR_TypeDef */
#endif

#if defined  USE_EMU_CONST
/**
* @brief EMU define
*/
typedef struct
{
    __IO uint32_t PowerInQ;                   /*!< Offset: 0x000  power Q input register      (R/W) */
    __IO uint32_t PowerInP;                   /*!< Offset: 0x004  power P input register      (R/W) */
    __IO uint32_t HFConst;                    /*!< Offset: 0x008  HFConst set register        (R/W) */
    __I  uint32_t EnergyP;                    /*!< Offset: 0x00C  energy P counter register   (R)   */
    __I  uint32_t EnergyQ;                    /*!< Offset: 0x010  energy Q counter register   (R)   */
    __IO uint32_t ReadCtrl;                   /*!< Offset: 0x014  Read Control Register       (R/W) */
} HT_EMU_TypeDef;                             /* end of group HT_EMU_TypeDef                        */
#endif

#if defined  HT762x
/*
* @brief EMU_EPR define
*/
                                                                                                                        
typedef struct
{										 
    __I uint32_t SPL_Ua;                      /*!< Offset: 0x000  Voltage Channel A ADC SAMPLE						(R)*/
    __I uint32_t SPL_Ub;                      /*!< Offset: 0x004  Voltage Channel B ADC SAMPLE						(R)*/
    __I uint32_t SPL_Uc;                      /*!< Offset: 0x008  Voltage Channel C ADC SAMPLE						(R)*/
    __I uint32_t SPL_Ia;                      /*!< Offset: 0x00C  Current Channel A ADC SAMPLE						(R)*/
    __I uint32_t SPL_Ib;                      /*!< Offset: 0x010  Current Channel B ADC SAMPLE						(R)*/
    __I uint32_t SPL_Ic;                      /*!< Offset: 0x014  Current Channel C ADC SAMPLE						(R)*/
    __I uint32_t SPL_In;                      /*!< Offset: 0x018  Current Channel N ADC SAMPLE						(R)*/
    __I uint32_t All_Power_Pa;                /*!< Offset: 0x01C  All Channel A PPower  							(R)*/
    __I uint32_t All_Power_Pb;                /*!< Offset: 0x020  All Channel B PPower  							(R)*/
    __I uint32_t All_Power_Pc;                /*!< Offset: 0x024  All Channel C PPower  							(R)*/
    __I uint32_t All_Power_Pt;                /*!< Offset: 0x028  All Channel SUM PPower  							(R)*/
    __I uint32_t All_Power_Qa;                /*!< Offset: 0x02C  All Channel A QPower  							(R)*/
    __I uint32_t All_Power_Qb;                /*!< Offset: 0x030  All Channel B QPower  							(R)*/
    __I uint32_t All_Power_Qc;                /*!< Offset: 0x034  All Channel C QPower  							(R)*/
    __I uint32_t All_Power_Qt;                /*!< Offset: 0x038  All Channel SUM QPower  							(R)*/
    __I uint32_t All_Power_Sa;                /*!< Offset: 0x03C  All Channel A SPower  							(R)*/
    __I uint32_t All_Power_Sb;                /*!< Offset: 0x040  All Channel B SPower  							(R)*/
    __I uint32_t All_Power_Sc;                /*!< Offset: 0x044  All Channel C SPower  							(R)*/
    __I uint32_t All_Power_St;                /*!< Offset: 0x048  All Channel SUM SPower  							(R)*/
    __I uint32_t All_RMS_Ua;                  /*!< Offset: 0x04C  All Voltage Channel A RMS							(R)*/
    __I uint32_t All_RMS_Ub;                  /*!< Offset: 0x050  All Voltage Channel B RMS							(R)*/
    __I uint32_t All_RMS_Uc;                  /*!< Offset: 0x054  All Voltage Channel C RMS							(R)*/
    __I uint32_t All_RMS_Ia;                  /*!< Offset: 0x058  All Current Channel A RMS							(R)*/
    __I uint32_t All_RMS_Ib;                  /*!< Offset: 0x05C  All Current Channel B RMS							(R)*/
    __I uint32_t All_RMS_Ic;                  /*!< Offset: 0x060  All Current Channel C RMS							(R)*/
    __I uint32_t All_RMS_In;                  /*!< Offset: 0x064  All Current Channel N RMS							(R)*/
    __I uint32_t RMS_Ut;                      /*!< Offset: 0x068  All/Fund Voltage vector RMS 						(R)*/
    __I uint32_t RMS_It;                      /*!< Offset: 0x06C  All/Fund Current vector RMS 						(R)*/
    __I uint32_t RMS_UAB;                     /*!< Offset: 0x070  All/Fund Voltage Line AB RMS 						(R)*/
    __I uint32_t RMS_UBC;                     /*!< Offset: 0x074  All/Fund Voltage Line BC RMS 						(R)*/
    __I uint32_t RMS_UAC;                     /*!< Offset: 0x078  All/Fund Voltage Line AC RMS 						(R)*/
    __I uint32_t FreqUa;                      /*!< Offset: 0x07C  Voltage Channel A Freq  							(R)*/
    __I uint32_t FreqUb;                      /*!< Offset: 0x080  Voltage Channel B Freq  							(R)*/
    __I uint32_t FreqUc;                      /*!< Offset: 0x084  Voltage Channel C Freq  							(R)*/
    __I uint32_t FreqU;                       /*!< Offset: 0x088  Voltage Channel   Freq  							(R)*/
    __I uint32_t All_PFa;                     /*!< Offset: 0x08C  All Channel A POWER FACTOR 						(R)*/
    __I uint32_t All_PFb;                     /*!< Offset: 0x090  All Channel B POWER FACTOR 						(R)*/
    __I uint32_t All_PFc;                     /*!< Offset: 0x094  All Channel C POWER FACTOR 						(R)*/
    __I uint32_t All_PFt;                     /*!< Offset: 0x098  All Channel SUM POWER FACTOR 						(R)*/
    __I uint32_t PhaseAngle_Ua;               /*!< Offset: 0x09C  All/Fund Voltage Channel A Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_Ub;               /*!< Offset: 0x0A0  All/Fund Voltage Channel B Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_Uc;               /*!< Offset: 0x0A4  All/Fund Voltage Channel C Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_Ia;               /*!< Offset: 0x0A8  All/Fund Current Channel A Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_Ib;               /*!< Offset: 0x0AC  All/Fund Current Channel B Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_Ic;               /*!< Offset: 0x0B0  All/Fund Current Channel C Phase Angle 			(R)*/
    __I uint32_t PhaseAngle_In;               /*!< Offset: 0x0B4  All/Fund Current Channel N Phase Angle 			(R)*/
    __I uint32_t All_EnergyPos_Pa;            /*!< Offset: 0x0B8  All Channel A Positive PEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Pb;            /*!< Offset: 0x0BC  All Channel B Positive PEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Pc;            /*!< Offset: 0x0C0  All Channel C Positive PEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Pt;            /*!< Offset: 0x0C4  All Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t All_EnergyPos_Qa;            /*!< Offset: 0x0C8  All Channel A Positive QEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Qb;            /*!< Offset: 0x0CC  All Channel B Positive QEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Qc;            /*!< Offset: 0x0D0  All Channel C Positive QEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Qt;            /*!< Offset: 0x0D4  All Channel SUM Positive QEnergy  				(R)*/
    __I uint32_t Energy_Sa;                   /*!< Offset: 0x0D8  All/Fund Channel A Positive SEnergy  				(R)*/
    __I uint32_t Energy_Sb;                   /*!< Offset: 0x0DC  All/Fund Channel B Positive SEnergy  				(R)*/
    __I uint32_t Energy_Sc;                   /*!< Offset: 0x0E0  All/Fund Channel C Positive SEnergy  				(R)*/
    __I uint32_t Energy_St;                   /*!< Offset: 0x0E4  All/Fund Channel SUM Positive SEnergy  			(R)*/
    __I uint32_t All_CFCntPos_Pa;             /*!< Offset: 0x0E8  All Channel A Positive Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Pb;             /*!< Offset: 0x0EC  All Channel B Positive Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Pc;             /*!< Offset: 0x0F0  All Channel C Positive Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Pt;             /*!< Offset: 0x0F4  All Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t All_CFCntPos_Qa;             /*!< Offset: 0x0F8  All Channel A Positive Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Qb;             /*!< Offset: 0x0FC  All Channel B Positive Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Qc;             /*!< Offset: 0x100  All Channel C Positive Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Qt;             /*!< Offset: 0x104  All Channel SUM Positive Fast QCFCnt  			(R)*/
    __I uint32_t CFCntPos_Sa;                 /*!< Offset: 0x108  All/Fund Channel A Positive SCFCnt  				(R)*/
    __I uint32_t CFCntPos_Sb;                 /*!< Offset: 0x10C  All/Fund Channel B Positive SCFCnt  				(R)*/
    __I uint32_t CFCntPos_Sc;                 /*!< Offset: 0x110  All/Fund Channel C Positive SCFCnt  				(R)*/
    __I uint32_t CFCntPos_St;                 /*!< Offset: 0x114  All/Fund Channel SUM Positive SCFCnt  			(R)*/
    __I uint32_t All_EnergyNeg_Pa;            /*!< Offset: 0x118  All Channel A Negative PEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Pb;            /*!< Offset: 0x11C  All Channel B Negative PEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Pc;            /*!< Offset: 0x120  All Channel C Negative PEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Pt;            /*!< Offset: 0x124  All Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t All_EnergyNeg_Qa;            /*!< Offset: 0x128  All Channel A Negative QEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Qb;            /*!< Offset: 0x12C  All Channel B Negative QEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Qc;            /*!< Offset: 0x130  All Channel C Negative QEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Qt;            /*!< Offset: 0x134  All Channel SUM Negative QEnergy  				(R)*/
    __I uint32_t All_CFCntNeg_Pa;             /*!< Offset: 0x138  All Channel A Negative Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Pb;             /*!< Offset: 0x13C  All Channel B Negative Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Pc;             /*!< Offset: 0x140  All Channel C Negative Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Pt;             /*!< Offset: 0x144  All Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t All_CFCntNeg_Qa;             /*!< Offset: 0x148  All Channel A Negative Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Qb;             /*!< Offset: 0x14C  All Channel B Negative Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Qc;             /*!< Offset: 0x150  All Channel C Negative Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Qt;             /*!< Offset: 0x154  All Channel SUM Negative Fast QCFCnt  			(R)*/
    __I uint32_t EnergyNeg_SaConst;           /*!< Offset: 0x158  All/Fund Channel A Negative SEnergy  				(R)*/
    __I uint32_t EnergyNeg_SbConst;           /*!< Offset: 0x15C  All/Fund Channel B Negative SEnergy  				(R)*/
    __I uint32_t EnergyNeg_ScConst;           /*!< Offset: 0x160  All/Fund Channel C Negative SEnergy  				(R)*/
    __I uint32_t EnergyNeg_StConst;           /*!< Offset: 0x164  All/Fund Channel SUM Negative SEnergy  			(R)*/
    __I uint32_t CFCntNeg_Sa;                 /*!< Offset: 0x168  All/Fund Channel A Negative SCFCnt  				(R)*/
    __I uint32_t CFCntNeg_Sb;                 /*!< Offset: 0x16C  All/Fund Channel B Negative SCFCnt  				(R)*/
    __I uint32_t CFCntNeg_Sc;                 /*!< Offset: 0x170  All/Fund Channel C Negative SCFCnt  				(R)*/
    __I uint32_t CFCntNeg_St;                 /*!< Offset: 0x174  All/Fund Channel SUM Negative SCFCnt  			(R)*/
    __I uint32_t Fund_Power_Pa;               /*!< Offset: 0x178  Fund Channel A PPower  							(R)*/
    __I uint32_t Fund_Power_Pb;               /*!< Offset: 0x17C  Fund Channel B PPower  							(R)*/
    __I uint32_t Fund_Power_Pc;               /*!< Offset: 0x180  Fund Channel C PPower  							(R)*/
    __I uint32_t Fund_Power_Pt;               /*!< Offset: 0x184  Fund Channel SUM PPower  							(R)*/
    __I uint32_t Fund_Power_Qa;               /*!< Offset: 0x188  Fund Channel A QPower  							(R)*/
    __I uint32_t Fund_Power_Qb;               /*!< Offset: 0x18C  Fund Channel B QPower  							(R)*/
    __I uint32_t Fund_Power_Qc;               /*!< Offset: 0x190  Fund Channel C QPower  							(R)*/
    __I uint32_t Fund_Power_Qt;               /*!< Offset: 0x194  Fund Channel SUM QPower  							(R)*/
    __I uint32_t Fund_Power_Sa;               /*!< Offset: 0x198  Fund Channel A SPower  							(R)*/
    __I uint32_t Fund_Power_Sb;               /*!< Offset: 0x19C  Fund Channel B SPower  							(R)*/
    __I uint32_t Fund_Power_Sc;               /*!< Offset: 0x1A0  Fund Channel C SPower  							(R)*/
    __I uint32_t Fund_Power_St;               /*!< Offset: 0x1A4  Fund Channel SUM SPower  							(R)*/
    __I uint32_t Fund_RMS_Ua;                 /*!< Offset: 0x1A8  Fund Voltage Channel A RMS						(R)*/
    __I uint32_t Fund_RMS_Ub;                 /*!< Offset: 0x1AC  Fund Voltage Channel B RMS						(R)*/
    __I uint32_t Fund_RMS_Uc;                 /*!< Offset: 0x1B0  Fund Voltage Channel C RMS						(R)*/
    __I uint32_t Fund_RMS_Ia;                 /*!< Offset: 0x1B4  Fund Current Channel A RMS						(R)*/
    __I uint32_t Fund_RMS_Ib;                 /*!< Offset: 0x1B8  Fund Current Channel B RMS						(R)*/
    __I uint32_t Fund_RMS_Ic;                 /*!< Offset: 0x1BC  Fund Current Channel C RMS						(R)*/
    __I uint32_t Fund_RMS_In;                 /*!< Offset: 0x1C0  Fund Current Channel N RMS						(R)*/
    __I uint32_t Fund_PFa;                    /*!< Offset: 0x1C4  Fund Channel A POWER FACTOR 						(R)*/
    __I uint32_t Fund_PFb;                    /*!< Offset: 0x1C8  Fund Channel B POWER FACTOR 						(R)*/
    __I uint32_t Fund_PFc;                    /*!< Offset: 0x1CC  Fund Channel C POWER FACTOR 						(R)*/
    __I uint32_t Fund_PFt;                    /*!< Offset: 0x1D0  Fund Channel SUM POWER FACTOR 					(R)*/
    __I uint32_t Fund_EnergyPos_Pa;           /*!< Offset: 0x1D4  Fund Channel A Positive PEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Pb;           /*!< Offset: 0x1D8  Fund Channel B Positive PEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Pc;           /*!< Offset: 0x1DC  Fund Channel C Positive PEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Pt;           /*!< Offset: 0x1E0  Fund Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t Fund_EnergyPos_Qa;           /*!< Offset: 0x1E4  Fund Channel A Positive QEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Qb;           /*!< Offset: 0x1E8  Fund Channel B Positive QEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Qc;           /*!< Offset: 0x1EC  Fund Channel C Positive QEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Qt;           /*!< Offset: 0x1F0  Fund Channel SUM Positive QEnergy  				(R)*/
    __I uint32_t Fund_CFCntPos_Pa;            /*!< Offset: 0x1F4  Fund Channel A Positive Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_Pb;            /*!< Offset: 0x1F8  Fund Channel B Positive Fast PCFCnt  				(R)*/ 
    __I uint32_t Fund_CFCntPos_Pc;            /*!< Offset: 0x1FC  Fund Channel C Positive Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_Pt;            /*!< Offset: 0x200  Fund Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t Fund_CFCntPos_Qa;            /*!< Offset: 0x204  Fund Channel A Positive Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_Qb;            /*!< Offset: 0x208  Fund Channel B Positive Fast QCFCnt  				(R)*/ 
    __I uint32_t Fund_CFCntPos_Qc;            /*!< Offset: 0x20C  Fund Channel C Positive Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_Qt;            /*!< Offset: 0x210  Fund Channel SUM Positive Fast QCFCnt  			(R)*/
    __I uint32_t Fund_EnergyNeg_Pa;           /*!< Offset: 0x214  Fund Channel A Negative PEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Pb;           /*!< Offset: 0x218  Fund Channel B Negative PEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Pc;           /*!< Offset: 0x21C  Fund Channel C Negative PEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Pt;           /*!< Offset: 0x220  Fund Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t Fund_EnergyNeg_Qa;           /*!< Offset: 0x224  Fund Channel A Negative QEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Qb;           /*!< Offset: 0x228  Fund Channel B Negative QEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Qc;           /*!< Offset: 0x22C  Fund Channel C Negative QEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Qt;           /*!< Offset: 0x230  Fund Channel SUM Negative QEnergy  				(R)*/
    __I uint32_t Fund_CFCntNeg_Pa;            /*!< Offset: 0x234  Fund Channel A Negative Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Pb;            /*!< Offset: 0x238  Fund Channel B Negative Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Pc;            /*!< Offset: 0x23C  Fund Channel C Negative Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Pt;            /*!< Offset: 0x240  Fund Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t Fund_CFCntNeg_Qa;            /*!< Offset: 0x244  Fund Channel A Negative Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Qb;            /*!< Offset: 0x248  Fund Channel B Negative Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Qc;            /*!< Offset: 0x24C  Fund Channel C Negative Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Qt;            /*!< Offset: 0x250  Fund Channel SUM Negative Fast QCFCnt  			(R)*/
    __I uint32_t Har_Power_Pa;                /*!< Offset: 0x254  Har Channel A PPower  							(R)*/
    __I uint32_t Har_Power_Pb;                /*!< Offset: 0x258  Har Channel B PPower  							(R)*/
    __I uint32_t Har_Power_Pc;                /*!< Offset: 0x25C  Har Channel C PPower  							(R)*/
    __I uint32_t Har_Power_Pt;                /*!< Offset: 0x260  Har Channel SUM PPower  							(R)*/
    __I uint32_t Har_RMS_Ua;                  /*!< Offset: 0x264  Har Voltage Channel A RMS							(R)*/
    __I uint32_t Har_RMS_Ub;                  /*!< Offset: 0x268  Har Voltage Channel B RMS							(R)*/
    __I uint32_t Har_RMS_Uc;                  /*!< Offset: 0x26C  Har Voltage Channel C RMS							(R)*/
    __I uint32_t Har_RMS_Ia;                  /*!< Offset: 0x270  Har Current Channel A RMS							(R)*/
    __I uint32_t Har_RMS_Ib;                  /*!< Offset: 0x274  Har Current Channel B RMS							(R)*/
    __I uint32_t Har_RMS_Ic;                  /*!< Offset: 0x278  Har Current Channel C RMS							(R)*/
    __I uint32_t Har_RMS_In;                  /*!< Offset: 0x27C  Har Current Channel N RMS							(R)*/
    __I uint32_t Har_EnergyPos_Pa;            /*!< Offset: 0x280  Har Channel A Positive PEnergy  					(R)*/
    __I uint32_t Har_EnergyPos_Pb;            /*!< Offset: 0x284  Har Channel B Positive PEnergy  					(R)*/
    __I uint32_t Har_EnergyPos_Pc;            /*!< Offset: 0x288  Har Channel C Positive PEnergy  					(R)*/
    __I uint32_t Har_EnergyPos_Pt;            /*!< Offset: 0x28C  Har Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t Har_CFCntPos_Pa;             /*!< Offset: 0x290  Har Channel A Positive Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntPos_Pb;             /*!< Offset: 0x294  Har Channel B Positive Fast PCFCnt  				(R)*/ 
    __I uint32_t Har_CFCntPos_Pc;             /*!< Offset: 0x298  Har Channel C Positive Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntPos_Pt;             /*!< Offset: 0x29C  Har Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t Har_EnergyNeg_Pa;            /*!< Offset: 0x2A0  Har Channel A Negative PEnergy  					(R)*/
    __I uint32_t Har_EnergyNeg_Pb;            /*!< Offset: 0x2A4  Har Channel B Negative PEnergy  					(R)*/
    __I uint32_t Har_EnergyNeg_Pc;            /*!< Offset: 0x2A8  Har Channel C Negative PEnergy  					(R)*/
    __I uint32_t Har_EnergyNeg_Pt;            /*!< Offset: 0x2AC  Har Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t Har_CFCntNeg_Pa;             /*!< Offset: 0x2B0  Har Channel A Negative Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntNeg_Pb;             /*!< Offset: 0x2B4  Har Channel B Negative Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntNeg_Pc;             /*!< Offset: 0x2B8  Har Channel C Negative Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntNeg_Pt;             /*!< Offset: 0x2BC  Har Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t DCVar_Ua;                    /*!< Offset: 0x2C0  Voltage Channel A ADC DC DATA						(R)*/
    __I uint32_t DCVar_Ub;                    /*!< Offset: 0x2C4  Voltage Channel B ADC DC DATA						(R)*/
    __I uint32_t DCVar_Uc;                    /*!< Offset: 0x2C8  Voltage Channel C ADC DC DATA						(R)*/
    __I uint32_t DCVar_Ia;                    /*!< Offset: 0x2CC  Current Channel A ADC DC DATA						(R)*/
    __I uint32_t DCVar_Ib;                    /*!< Offset: 0x2D0  Current Channel B ADC DC DATA						(R)*/
    __I uint32_t DCVar_Ic;                    /*!< Offset: 0x2D4  Current Channel C ADC DC DATA						(R)*/
    __I uint32_t DCVar_In;                    /*!< Offset: 0x2D8  Current Channel N ADC DC DATA						(R)*/
    __I uint32_t UpdHalfWave_Ua;              /*!< Offset: 0x2DC  Voltage Channel A Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_Ub;              /*!< Offset: 0x2E0  Voltage Channel B Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_Uc;              /*!< Offset: 0x2E4  Voltage Channel C Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_Ia;              /*!< Offset: 0x2E8  Current Channel A Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_Ib;              /*!< Offset: 0x2EC  Current Channel B Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_Ic;              /*!< Offset: 0x2F0  Current Channel C Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_In;              /*!< Offset: 0x2F4  Current Channel N Half Cycle PEAK 				(R)*/
    __I uint32_t QuartRmsIns_Ua;              /*!< Offset: 0x2F8  Voltage Channel A Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_Ub;              /*!< Offset: 0x2FC  Voltage Channel B Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_Uc;              /*!< Offset: 0x300  Voltage Channel C Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_Ia;              /*!< Offset: 0x304  Current Channel A Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_Ib;              /*!< Offset: 0x308  Current Channel B Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_Ic;              /*!< Offset: 0x30C  Current Channel C Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_In;              /*!< Offset: 0x310  Current Channel N Instant Square Data (For RMS)	(R)*/
    __I uint32_t PeakVpUa;                    /*!< Offset: 0x314  Voltage Channel A PEAK Period MAX PEAK 			(R)*/
    __I uint32_t PeakVpUb;                    /*!< Offset: 0x318  Voltage Channel B PEAK Period MAX PEAK 			(R)*/
    __I uint32_t PeakVpUc;                    /*!< Offset: 0x31C  Voltage Channel C PEAK Period MAX PEAK 			(R)*/
    __I uint32_t PeakCntUa;                   /*!< Offset: 0x320  Voltage Channel A PEAK Period Continuous Half Cycle num (R)*/
    __I uint32_t PeakCntUb;                   /*!< Offset: 0x324  Voltage Channel B PEAK Period Continuous Half Cycle num (R)*/
    __I uint32_t PeakCntUc;                   /*!< Offset: 0x328  Voltage Channel C PEAK Period Continuous Half Cycle num (R)*/
    __I uint32_t SagVpUa;                     /*!< Offset: 0x32C  Voltage Channel A SAG Period MIN PEAK 			(R)*/
    __I uint32_t SagVpUb;                     /*!< Offset: 0x330  Voltage Channel B SAG Period MIN PEAK 			(R)*/
    __I uint32_t SagVpUc;                     /*!< Offset: 0x334  Voltage Channel C SAG Period MIN PEAK 			(R)*/
    __I uint32_t SagCntUa;                    /*!< Offset: 0x338  Voltage Channel A SAG Period Continuous Half Cycle num (R)*/
    __I uint32_t SagCntUb;                    /*!< Offset: 0x33C  Voltage Channel B SAG Period Continuous Half Cycle num (R)*/
    __I uint32_t SagCntUc;                    /*!< Offset: 0x340  Voltage Channel C SAG Period Continuous Half Cycle num (R)*/
    __I uint32_t IntVpUa;                     /*!< Offset: 0x344  Voltage Channel A INT Period MIN PEAK 			(R)*/
    __I uint32_t IntVpUb;                     /*!< Offset: 0x348  Voltage Channel B INT Period MIN PEAK 			(R)*/
    __I uint32_t IntVpUc;                     /*!< Offset: 0x34C  Voltage Channel C INT Period MIN PEAK 			(R)*/
    __I uint32_t IntCntUa;                    /*!< Offset: 0x350  Voltage Channel A INT Period Continuous Half Cycle num (R)*/
    __I uint32_t IntCntUb;                    /*!< Offset: 0x354  Voltage Channel B INT Period Continuous Half Cycle num (R)*/
    __I uint32_t IntCntUc;                    /*!< Offset: 0x358  Voltage Channel C INT Period Continuous Half Cycle num (R)*/
    __I uint32_t OverFlowVpIa;                /*!< Offset: 0x35C  Current Channel A IOV Period MAX PEAK 			(R)*/
    __I uint32_t OverFlowVpIb;                /*!< Offset: 0x360  Current Channel B IOV Period MAX PEAK 			(R)*/
    __I uint32_t OverFlowVpIc;                /*!< Offset: 0x364  Current Channel C IOV Period MAX PEAK 			(R)*/
    __I uint32_t OverFlowVpIn;                /*!< Offset: 0x368  Current Channel N IOV Period MAX PEAK 			(R)*/
    __I uint32_t OverFlowCntIa;               /*!< Offset: 0x36C  Current Channel A IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t OverFlowCntIb;               /*!< Offset: 0x370  Current Channel B IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t OverFlowCntIc;               /*!< Offset: 0x374  Current Channel C IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t OverFlowCntIn;               /*!< Offset: 0x378  Current Channel N IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t AutoTgain_U;                 /*!< Offset: 0x37C  Voltage Channel ABC automatic temperature compensation Gain	(R)*/
    __I uint32_t AutoTgain_I;                 /*!< Offset: 0x380  Current Channel ABC automatic temperature compensation Gain	(R)*/
    __I uint32_t AutoTgain_In;                /*!< Offset: 0x384  Current Channel N automatic temperature compensation Gain		(R)*/
    __I uint32_t HpRMS_Reg_Ua;                /*!< Offset: 0x388  Voltage Channel A Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_Ub;                /*!< Offset: 0x38C  Voltage Channel B Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_Uc;                /*!< Offset: 0x390  Voltage Channel C Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_Ia;                /*!< Offset: 0x394  Current Channel A Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_Ib;                /*!< Offset: 0x398  Current Channel B Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_Ic;                /*!< Offset: 0x39C  Current Channel C Half Cycle RMS 					(R)*/ 
    __I uint32_t HpRMS_Reg_In;                /*!< Offset: 0x3A0  Current Channel N Half Cycle RMS 					(R)*/ 
    __I uint32_t DFT_Value_UaReal;            /*!< Offset: 0x3A4  Voltage Channel A DFT Real						(R)*/  
    __I uint32_t DFT_Value_UaImage;           /*!< Offset: 0x3A8  Voltage Channel A DFT Imag 						(R)*/  
    __I uint32_t DFT_Value_UbReal;            /*!< Offset: 0x3AC  Voltage Channel B DFT Real						(R)*/
    __I uint32_t DFT_Value_UbImage;           /*!< Offset: 0x3B0  Voltage Channel B DFT Imag 						(R)*/
    __I uint32_t DFT_Value_UcReal;            /*!< Offset: 0x3B4  Voltage Channel C DFT Real						(R)*/
    __I uint32_t DFT_Value_UcImage;           /*!< Offset: 0x3B8  Voltage Channel C DFT Imag 						(R)*/ 
    __I uint32_t DFT_Value_IaReal;            /*!< Offset: 0x3BC  Current Channel A DFT Real						(R)*/
    __I uint32_t DFT_Value_IaImage;           /*!< Offset: 0x3C0  Current Channel A DFT Imag 						(R)*/
    __I uint32_t DFT_Value_IbReal;            /*!< Offset: 0x3C4  Current Channel B DFT Real						(R)*/
    __I uint32_t DFT_Value_IbImage;           /*!< Offset: 0x3C8  Current Channel B DFT Imag 						(R)*/ 
    __I uint32_t DFT_Value_IcReal;            /*!< Offset: 0x3CC  Current Channel C DFT Real						(R)*/
    __I uint32_t DFT_Value_IcImage;           /*!< Offset: 0x3D0  Current Channel C DFT Imag 						(R)*/                   
    __I uint32_t DFT_Value_InReal;            /*!< Offset: 0x3D4  Current Channel N DFT Real						(R)*/
    __I uint32_t DFT_Value_InImage;           /*!< Offset: 0x3D8  Current Channel N DFT Imag 						(R)*/
    __I uint32_t Reserved1[2];				  /*!< Offset: 0x3DC~0x3E0   			 								(R)*/ 
    __I uint32_t FlickerUaPinst;              /*!< Offset: 0x3E4  Voltage Channel A Flicker Pinst 					(R)*/ 
    __I uint32_t FlickerUbPinst;              /*!< Offset: 0x3E8  Voltage Channel B Flicker Pinst 					(R)*/
    __I uint32_t FlickerUcPinst;              /*!< Offset: 0x3EC  Voltage Channel C Flicker Pinst 					(R)*/
    __I uint32_t Chksum1;                     /*!< Offset: 0x3F0  Calibration register checksum1 					(R)*/ 
    __I uint32_t Chksum2;                     /*!< Offset: 0x3F4  Filter Calibration register checksum2 			(R)*/ 
    __I uint32_t Chksum3;                     /*!< Offset: 0x3F8  EWU/SYNC Calibration register checksum3 			(R)*/ 
    __I uint32_t Reserved0[1];                /*!< Offset: 0x3FC   													(R)*/ 
    __I uint32_t Noload;                      /*!< Offset: 0x400  start Flag 										(R)*/ 
    __I uint32_t REV_Power;                   /*!< Offset: 0x404  Power Direction Flag 								(R)*/  
    __I uint32_t REV_Energy;                  /*!< Offset: 0x408  Energy Direction Flag 							(R)*/ 
    __I uint32_t P90_Power;		              /*!< Offset: 0x40C  Energy Channel POWER 90 Flag						(R)*/ 
    __I uint32_t SignalStatus;                /*!< Offset: 0x410  sample signal and system stautus 					(R)*/ 
    __I uint32_t PeakSagIntIovStau;           /*!< Offset: 0x414  PeakSagINT status Flag 							(R)*/ 
} HT_EMU_EPR_TypeDef;                         /* end of group HT_EMU_EPR_TypeDef           */

/*
* @brief EMU ECR define
*/
typedef struct
{										 
    __IO uint32_t DECShift_UaH;               /*!< Offset: 0x000  VOLTAGE CHANNEL A Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_UaL;               /*!< Offset: 0x004  VOLTAGE CHANNEL A Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_UbH;               /*!< Offset: 0x008  VOLTAGE CHANNEL B Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_UbL;               /*!< Offset: 0x00C  VOLTAGE CHANNEL B Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_UcH;               /*!< Offset: 0x010  VOLTAGE CHANNEL C Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_UcL;               /*!< Offset: 0x014  VOLTAGE CHANNEL C Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_IaH;               /*!< Offset: 0x018  CURRENT CHANNEL A Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_IaL;               /*!< Offset: 0x01C  CURRENT CHANNEL A Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_IbH;               /*!< Offset: 0x020  CURRENT CHANNEL B Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_IbL;               /*!< Offset: 0x024  CURRENT CHANNEL B Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_IcH;               /*!< Offset: 0x028  CURRENT CHANNEL C Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_IcL;               /*!< Offset: 0x02C  CURRENT CHANNEL C Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_InH;               /*!< Offset: 0x030  CURRENT CHANNEL N Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_InL;               /*!< Offset: 0x034  CURRENT CHANNEL N Onebit Shift small pat 			(R/W)*/
    __IO uint32_t ADCOffset_Ua;               /*!< Offset: 0x038  VOLTAGE CHANNEL A ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_Ub;               /*!< Offset: 0x03C  VOLTAGE CHANNEL B ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_Uc;               /*!< Offset: 0x040  VOLTAGE CHANNEL C ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_Ia;               /*!< Offset: 0x044  CURRENT CHANNEL A ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_Ib;               /*!< Offset: 0x048  CURRENT CHANNEL B ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_Ic;               /*!< Offset: 0x04C  CURRENT CHANNEL C ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_In;               /*!< Offset: 0x050  CURRENT CHANNEL N ADC DC OFFSET					(R/W)*/
    __IO uint32_t Tgain_U;                    /*!< Offset: 0x054  Voltage CHANNEL ABC ADC Temperature gain			(R/W)*/
    __IO uint32_t Tgain_I;                    /*!< Offset: 0x058  CURRENT CHANNEL ABC ADC Temperature gain			(R/W)*/
    __IO uint32_t Tgain_In;                   /*!< Offset: 0x05C  CURRENT CHANNEL N ADC Temperature gain			(R/W)*/
    __IO uint32_t Gain_Ua;                    /*!< Offset: 0x060  VOLTAGE CHANNEL A ADC GAIN						(R/W)*/
    __IO uint32_t Gain_Ub;                    /*!< Offset: 0x064  VOLTAGE CHANNEL B ADC GAIN						(R/W)*/
    __IO uint32_t Gain_Uc;                    /*!< Offset: 0x068  VOLTAGE CHANNEL C ADC GAIN						(R/W)*/
    __IO uint32_t Gain_Ia;                    /*!< Offset: 0x06C  CURRENT CHANNEL A ADC GAIN						(R/W)*/
    __IO uint32_t Gain_Ib;                    /*!< Offset: 0x070  CURRENT CHANNEL B ADC GAIN						(R/W)*/
    __IO uint32_t Gain_Ic;                    /*!< Offset: 0x074  CURRENT CHANNEL C ADC GAIN						(R/W)*/
    __IO uint32_t Gain_In;                    /*!< Offset: 0x078  CURRENT CHANNEL N ADC GAIN						(R/W)*/
    __IO uint32_t Digtal_gain;                /*!< Offset: 0x07C  ADC DIGTAL GAIN									(R/W)*/
    __IO uint32_t All_GPa;                    /*!< Offset: 0x080  ALL CHANNEL A POWER PGAIN 						(R/W)*/
    __IO uint32_t All_GPb;                    /*!< Offset: 0x084  ALL CHANNEL B POWER PGAIN 						(R/W)*/
    __IO uint32_t All_GPc;                    /*!< Offset: 0x088  ALL CHANNEL C POWER PGAIN 						(R/W)*/
    __IO uint32_t All_GQa;                    /*!< Offset: 0x08C  ALL CHANNEL A POWER QGAIN 						(R/W)*/
    __IO uint32_t All_GQb;                    /*!< Offset: 0x090  ALL CHANNEL B POWER QGAIN 						(R/W)*/
    __IO uint32_t All_GQc;                    /*!< Offset: 0x094  ALL CHANNEL C POWER QGAIN 						(R/W)*/
    __IO uint32_t All_GSa;                    /*!< Offset: 0x098  ALL CHANNEL A POWER SGAIN 						(R/W)*/
    __IO uint32_t All_GSb;                    /*!< Offset: 0x09C  ALL CHANNEL B POWER SGAIN 						(R/W)*/
    __IO uint32_t All_GSc;                    /*!< Offset: 0x0A0  ALL CHANNEL C POWER SGAIN 						(R/W)*/
    __IO uint32_t All_GphsA0;                 /*!< Offset: 0x0A4  ALL CHANNEL A PHASE CORRECTION 0 					(R/W)*/
    __IO uint32_t All_GphsA1;                 /*!< Offset: 0x0A8  ALL CHANNEL A PHASE CORRECTION 1 					(R/W)*/
    __IO uint32_t All_GphsA2;                 /*!< Offset: 0x0AC  ALL CHANNEL A PHASE CORRECTION 2 					(R/W)*/
    __IO uint32_t All_GphsB0;                 /*!< Offset: 0x0B0  ALL CHANNEL B PHASE CORRECTION 0 					(R/W)*/
    __IO uint32_t All_GphsB1;                 /*!< Offset: 0x0B4  ALL CHANNEL B PHASE CORRECTION 1 					(R/W)*/
    __IO uint32_t All_GphsB2;                 /*!< Offset: 0x0B8  ALL CHANNEL B PHASE CORRECTION 2 					(R/W)*/
    __IO uint32_t All_GphsC0;                 /*!< Offset: 0x0BC  ALL CHANNEL C PHASE CORRECTION 0 					(R/W)*/	
    __IO uint32_t All_GphsC1;                 /*!< Offset: 0x0C0  ALL CHANNEL C PHASE CORRECTION 1 					(R/W)*/	
    __IO uint32_t All_GphsC2;                 /*!< Offset: 0x0C4  ALL CHANNEL C PHASE CORRECTION 2 					(R/W)*/	
    __IO uint32_t Reserved1[1];               /*!< Offset: 0x0C8   													(R/W)*/
    __IO uint32_t All_PowerOffset_Pa;         /*!< Offset: 0x0CC  ALL CHANNEL A POWER POFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Pb;         /*!< Offset: 0x0D0  ALL CHANNEL B POWER POFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Pc;         /*!< Offset: 0x0D4  ALL CHANNEL C POWER POFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Qa;         /*!< Offset: 0x0D8  ALL CHANNEL A POWER QOFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Qb;         /*!< Offset: 0x0DC  ALL CHANNEL B POWER QOFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Qc;         /*!< Offset: 0x0E0  ALL CHANNEL C POWER QOFFSET 						(R/W)*/
    __IO uint32_t All_RmsOffset_Ua;           /*!< Offset: 0x0E4  ALL VOLTAGE CHANNEL A RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_Ub;           /*!< Offset: 0x0E8  ALL VOLTAGE CHANNEL B RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_Uc;           /*!< Offset: 0x0EC  ALL VOLTAGE CHANNEL C RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_Ia;           /*!< Offset: 0x0F0  ALL CURRENT CHANNEL A RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_Ib;           /*!< Offset: 0x0F4  ALL CURRENT CHANNEL B RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_Ic;           /*!< Offset: 0x0F8  ALL CURRENT CHANNEL C RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_In;           /*!< Offset: 0x0FC  ALL CURRENT CHANNEL N RMS OFFSET 					(R/W)*/
    __IO uint32_t RMSOffset_Ut;               /*!< Offset: 0x100  VOLTAGE VECTOR RMS OFFSET	 						(R/W)*/
    __IO uint32_t RMSOffset_It;               /*!< Offset: 0x104  CURRENT VECTOR RMS OFFSET	 						(R/W)*/
    __IO uint32_t Reserved2[2];               /*!< Offset: 0x108~0x10C 						 						(R/W)*/
    __IO uint32_t Fund_GPa;                   /*!< Offset: 0x110  FUND CHANNEL A POWER PGAIN 						(R/W)*/
    __IO uint32_t Fund_GPb;                   /*!< Offset: 0x114  FUND CHANNEL B POWER PGAIN 						(R/W)*/
    __IO uint32_t Fund_GPc;                   /*!< Offset: 0x118  FUND CHANNEL C POWER PGAIN 						(R/W)*/
    __IO uint32_t Fund_GQa;                   /*!< Offset: 0x11C  FUND CHANNEL A POWER QGAIN 						(R/W)*/
    __IO uint32_t Fund_GQb;                   /*!< Offset: 0x120  FUND CHANNEL B POWER QGAIN 						(R/W)*/
    __IO uint32_t Fund_GQc;                   /*!< Offset: 0x124  FUND CHANNEL C POWER QGAIN 						(R/W)*/  
    __IO uint32_t Fund_GSa;                   /*!< Offset: 0x128  FUND CHANNEL A POWER SGAIN 						(R/W)*/
    __IO uint32_t Fund_GSb;                   /*!< Offset: 0x12C  FUND CHANNEL B POWER SGAIN 						(R/W)*/
    __IO uint32_t Fund_GSc;                   /*!< Offset: 0x130  FUND CHANNEL C POWER SGAIN 						(R/W)*/
    __IO uint32_t Fund_GphsA0;                /*!< Offset: 0x134  FUND CHANNEL A PHASE CORRECTION 0 				(R/W)*/
    __IO uint32_t Fund_GphsA1;                /*!< Offset: 0x138  FUND CHANNEL A PHASE CORRECTION 1 				(R/W)*/
    __IO uint32_t Fund_GphsA2;                /*!< Offset: 0x13C  FUND CHANNEL A PHASE CORRECTION 2 				(R/W)*/
    __IO uint32_t Fund_GphsB0;                /*!< Offset: 0x140  FUND CHANNEL B PHASE CORRECTION 0 				(R/W)*/
    __IO uint32_t Fund_GphsB1;                /*!< Offset: 0x144  FUND CHANNEL B PHASE CORRECTION 1 				(R/W)*/
    __IO uint32_t Fund_GphsB2;                /*!< Offset: 0x148  FUND CHANNEL B PHASE CORRECTION 2 				(R/W)*/  
    __IO uint32_t Fund_GphsC0;                /*!< Offset: 0x14C  FUND CHANNEL C PHASE CORRECTION 0 				(R/W)*/
    __IO uint32_t Fund_GphsC1;                /*!< Offset: 0x150  FUND CHANNEL C PHASE CORRECTION 1 				(R/W)*/
    __IO uint32_t Fund_GphsC2;                /*!< Offset: 0x154  FUND CHANNEL C PHASE CORRECTION 2 				(R/W)*/
    __IO uint32_t Reserved3[1];             
    __IO uint32_t Fund_PowerOffset_Pa;        /*!< Offset: 0x15C  FUND CHANNEL A POWER POFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_Pb;        /*!< Offset: 0x160  FUND CHANNEL B POWER POFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_Pc;        /*!< Offset: 0x164  FUND CHANNEL C POWER POFFSET 						(R/W)*/  
    __IO uint32_t Fund_PowerOffset_Qa;        /*!< Offset: 0x168  FUND CHANNEL A POWER QOFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_Qb;        /*!< Offset: 0x16C  FUND CHANNEL B POWER QOFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_Qc;        /*!< Offset: 0x170  FUND CHANNEL C POWER QOFFSET 						(R/W)*/
    __IO uint32_t Fund_RmsOffset_Ua;          /*!< Offset: 0x174  FUND VOLTAGE CHANNEL A RMS OFFSET 				(R/W)*/
    __IO uint32_t Fund_RmsOffset_Ub;          /*!< Offset: 0x178  FUND VOLTAGE CHANNEL B RMS OFFSET 				(R/W)*/
    __IO uint32_t Fund_RmsOffset_Uc;          /*!< Offset: 0x17C  FUND VOLTAGE CHANNEL C RMS OFFSET 				(R/W)*/
    __IO uint32_t Fund_RmsOffset_Ia;          /*!< Offset: 0x180  FUND CURRENT CHANNEL A RMS OFFSET 				(R/W)*/
    __IO uint32_t Fund_RmsOffset_Ib;          /*!< Offset: 0x184  FUND CURRENT CHANNEL B RMS OFFSET 				(R/W)*/ 	
    __IO uint32_t Fund_RmsOffset_Ic;          /*!< Offset: 0x188  FUND CURRENT CHANNEL C RMS OFFSET 				(R/W)*/   
    __IO uint32_t Fund_RmsOffset_In;          /*!< Offset: 0x18C  FUND CURRENT CHANNEL N RMS OFFSET 				(R/W)*/   
    __IO uint32_t Har_GPa;                    /*!< Offset: 0x190  HAR CHANNEL A POWER PGAIN 						(R/W)*/   
    __IO uint32_t Har_GPb;                    /*!< Offset: 0x194  HAR CHANNEL B POWER PGAIN 						(R/W)*/  
    __IO uint32_t Har_GPc;                    /*!< Offset: 0x198  HAR CHANNEL C POWER PGAIN 						(R/W)*/  
    __IO uint32_t Har_PowerOffset_Pa;         /*!< Offset: 0x19C  HAR CHANNEL A POWER POFFSET 						(R/W)*/  
    __IO uint32_t Har_PowerOffset_Pb;         /*!< Offset: 0x1A0  HAR CHANNEL B POWER POFFSET 						(R/W)*/  
    __IO uint32_t Har_PowerOffset_Pc;         /*!< Offset: 0x1A4  HAR CHANNEL C POWER POFFSET 						(R/W)*/  
    __IO uint32_t Har_RmsOffset_Ua;           /*!< Offset: 0x1A8  HAR VOLTAGE CHANNEL A RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_Ub;           /*!< Offset: 0x1AC  HAR VOLTAGE CHANNEL B RMS OFFSET 					(R/W)*/  
    __IO uint32_t Har_RmsOffset_Uc;           /*!< Offset: 0x1B0  HAR VOLTAGE CHANNEL C RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_Ia;           /*!< Offset: 0x1B4  HAR CURRENT CHANNEL A RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_Ib;           /*!< Offset: 0x1B8  HAR CURRENT CHANNEL B RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_Ic;           /*!< Offset: 0x1BC  HAR CURRENT CHANNEL C RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_In;           /*!< Offset: 0x1C0  HAR CURRENT CHANNEL N RMS OFFSET 					(R/W)*/ 
    __IO uint32_t PowerConst_All_Pa;          /*!< Offset: 0x1C4  CHANNEL 1 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Pb;          /*!< Offset: 0x1C8  CHANNEL 2 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Pc;          /*!< Offset: 0x1CC  CHANNEL 3 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Pt;          /*!< Offset: 0x1D0  CHANNEL 4 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Qa;          /*!< Offset: 0x1D4  CHANNEL 5 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Qb;          /*!< Offset: 0x1D8  CHANNEL 6 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Qc;          /*!< Offset: 0x1DC  CHANNEL 7 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Qt;          /*!< Offset: 0x1E0  CHANNEL 8 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Sa;              /*!< Offset: 0x1E4  CHANNEL 9 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Sb;              /*!< Offset: 0x1E8  CHANNEL 10 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Sc;              /*!< Offset: 0x1EC  CHANNEL 11 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_St;              /*!< Offset: 0x1F0  CHANNEL 12 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Pa;         /*!< Offset: 0x1F4  CHANNEL 13 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Pb;         /*!< Offset: 0x1F8  CHANNEL 14 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Pc;         /*!< Offset: 0x1FC  CHANNEL 15 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Pt;         /*!< Offset: 0x200  CHANNEL 16 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Qa;         /*!< Offset: 0x204  CHANNEL 17 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Qb;         /*!< Offset: 0x208  CHANNEL 18 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Qc;         /*!< Offset: 0x20C  CHANNEL 19 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Qt;         /*!< Offset: 0x210  CHANNEL 20 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_Pa;          /*!< Offset: 0x214  CHANNEL 21 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_Pb;          /*!< Offset: 0x218  CHANNEL 22 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_Pc;          /*!< Offset: 0x21C  CHANNEL 23 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_Pt;          /*!< Offset: 0x220  CHANNEL 24 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pa_Pos;      /*!< Offset: 0x224  A HAR POSITIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pa_Neg;      /*!< Offset: 0x228  A HAR NEGATIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pb_Pos;      /*!< Offset: 0x22C  B HAR POSITIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pb_Neg;      /*!< Offset: 0x230  B HAR NEGATIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pc_Pos;      /*!< Offset: 0x234  C HAR POSITIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pc_Neg;      /*!< Offset: 0x238  C HAR NEGATIVE ENERGY OFFSET 						(R/W)*/
    __IO uint32_t AccuOffset_Har_Pt_Pos;      /*!< Offset: 0x23C  SUM HAR POSITIVE ENERGY OFFSET 					(R/W)*/
    __IO uint32_t AccuOffset_Har_Pt_Neg;      /*!< Offset: 0x240  SUM HAR NEGATIVE ENERGY OFFSET 					(R/W)*/
    __IO uint32_t UconstA;                    /*!< Offset: 0x244  VOLTAGE CHANNEL A CONSTANT 						(R/W)*/
    __IO uint32_t UconstB;                    /*!< Offset: 0x248  VOLTAGE CHANNEL B CONSTANT 						(R/W)*/
    __IO uint32_t UconstC;                    /*!< Offset: 0x24C  VOLTAGE CHANNEL C CONSTANT 						(R/W)*/
    __IO uint32_t ZXLostCFG;                  /*!< Offset: 0x250  ZCNumMin / ZCNumMax / NumFund 					(R/W)*/
    __IO uint32_t PStart;                     /*!< Offset: 0x254  P POWER START CONFIG 								(R/W)*/
    __IO uint32_t QStart;                     /*!< Offset: 0x258  Q POWER START CONFIG 								(R/W)*/
    __IO uint32_t HarStart;                   /*!< Offset: 0x25C  HAR POWER START CONFIG 							(R/W)*/
    __IO uint32_t AVG_Energy;                 /*!< Offset: 0x260  ENERGY AVERAGE NUM								(R/W)*/
    __IO uint32_t AVG_PowerREG;               /*!< Offset: 0x264  POWER AVERAGE NUM 								(R/W)*/
    __IO uint32_t AVG_RMS;                    /*!< Offset: 0x268  RMS AVERAGE NUM 									(R/W)*/
    __IO uint32_t AVG_RMST;                   /*!< Offset: 0x26C  VECTOR RMS AVERAGE NUM 							(R/W)*/
    __IO uint32_t HFConstAF;  			      /*!< Offset: 0x270  ALL FUND ENERGY HFConst 							(R/W)*/
    __IO uint32_t HFConstHar;                 /*!< Offset: 0x274  HAR ENERGY HFConst 								(R/W)*/
    __IO uint32_t AFDIV;                      /*!< Offset: 0x278  ALL FUND ENERGY DIV 								(R/W)*/
    __IO uint32_t HarDIV;                     /*!< Offset: 0x27C  HAR ENERGY DIV 									(R/W)*/
    __IO uint32_t ChannelSel;                 /*!< Offset: 0x280  CHANNEL SELECT 									(R/W)*/
    __IO uint32_t PGACON;                     /*!< Offset: 0x284  ANALOG PGA CONCTRL 								(R/W)*/
    __IO uint32_t ADCCFG;                     /*!< Offset: 0x288  ADC CONFIG 										(R/W)*/
    __IO uint32_t ADCCON;                     /*!< Offset: 0x28C  ADC CONCTRL 										(R/W)*/     			     
    __IO uint32_t EMUCFG;                     /*!< Offset: 0x290  EMU CONFIG 										(R/W)*/     			   
    __IO uint32_t FilterCon;                  /*!< Offset: 0x294  FILTER CONTRL 									(R/W)*/     		   
    __IO uint32_t FilterCFG;                  /*!< Offset: 0x298  FILTER CONFIG										(R/W)*/     		   
    __IO uint32_t StartCFG;                   /*!< Offset: 0x29C  START CONFIG 										(R/W)*/     		   
    __IO uint32_t ANACFG1;                    /*!< Offset: 0x2A0  ANALOG CONFIG 1									(R/W)*/   		   
    __IO uint32_t ANACFG2;                    /*!< Offset: 0x2A4  ANALOG CONFIG 2									(R/W)*/     		   
    __IO uint32_t Reserved4[1];     		  /*!< Offset: 0x2A8      												(R/W)*/ 
    __IO uint32_t ULostCMPCFG;                /*!< Offset: 0x2AC  ALL VOLTAGE LOST COMPPARATOR CONFIG				(R/W)*/    		   
    __IO uint32_t ULostPRDCFG;                /*!< Offset: 0x2B0  ALL VOLTAGE LOST COMPPARATOR IDLE MODE CONFIG     (R/W)*/    		   
    __IO uint32_t FailVoltage;                /*!< Offset: 0x2B4  ALL_RMSU THRESHOLD CONFIG 						(R/W)*/    		   
    __IO uint32_t LPModeCON;                  /*!< Offset: 0x2B8  LOW POWER MODE CONFIG								(R/W)*/    		   
    __IO uint32_t CFxRun;                     /*!< Offset: 0x2BC  ENERGY ADD ENABLE 								(R/W)*/ 				   
    __IO uint32_t EnergyCon;                  /*!< Offset: 0x2C0  ENERGY CONTRL										(R/W)*/ 			   
    __IO uint32_t PowerSrcCFG1;               /*!< Offset: 0x2C4  ENERGY ADD SOURCE SELECT CONFIG1					(R/W)*/ 		 
    __IO uint32_t PowerSrcCFG2;               /*!< Offset: 0x2C8  ENERGY ADD SOURCE SELECT CONFIG2					(R/W)*/     	     
    __IO uint32_t PowerModeCFG;               /*!< Offset: 0x2CC  ENERGY ADD MODE CONFIG							(R/W)*/     	     
    __IO uint32_t CFCFG1;                     /*!< Offset: 0x2D0  ENERGY CF CONFIG1 								(R/W)*/     			     
    __IO uint32_t CFCFG2;                     /*!< Offset: 0x2D4  ENERGY CF CONFIG2 								(R/W)*/  			     
    __IO uint32_t Reserved5[2];  			  /*!< Offset: 0x2D8~0x2DC     											(R/W)*/     			     
    __IO uint32_t PowerConstLoad;             /*!< Offset: 0x2E0  CONSTANT POWER Load								(R/W)*/
    __IO uint32_t UPeakSagCyc;                /*!< Offset: 0x2E4  sag/peak CONTINUOUS HALF CYCLE NUM				(R/W)*/
    __IO uint32_t UIntCyc;                    /*!< Offset: 0x2E8  UInt CONTINUOUS HALF CYCLE NUM					(R/W)*/
    __IO uint32_t IOVCyc;                     /*!< Offset: 0x2EC  IOV CONTINUOUS HALF CYCLE NUM						(R/W)*/
    __IO uint32_t PeakLVL;                    /*!< Offset: 0x2F0  Upeak THRESHOLD 									(R/W)*/
    __IO uint32_t SagLVL;                     /*!< Offset: 0x2F4  Usag THRESHOLD 									(R/W)*/
    __IO uint32_t IntLVL;                     /*!< Offset: 0x2F8  UINT THRESHOLD 									(R/W)*/
    __IO uint32_t IOVLVL;                     /*!< Offset: 0x2FC  IOV THRESHOLD 									(R/W)*/
    __IO uint32_t PeakLVLHys;                 /*!< Offset: 0x300  Upeak HYSTERESIS 									(R/W)*/
    __IO uint32_t SagLVLHys;                  /*!< Offset: 0x304  Usag HYSTERESIS 									(R/W)*/
    __IO uint32_t IntLVLHys;                  /*!< Offset: 0x308  UINT HYSTERESIS 									(R/W)*/
    __IO uint32_t IOVLVLHys;                  /*!< Offset: 0x30C  CURRENT OVerflow HYSTERESIS 						(R/W)*/
    __IO uint32_t UZCLVL;                     /*!< Offset: 0x310  voltage CHANNEL ZEROCROSS THRESHOLD				(R/W)*/
    __IO uint32_t IZCLVL;                     /*!< Offset: 0x314  CURRENT CHANNEL ZEROCROSS THRESHOLD				(R/W)*/
    __IO uint32_t TU_CCOFF_A;                 /*!< Offset: 0x318  voltage Automatic Temperature Compensation Second coefficient		(R/W)*/
    __IO uint32_t TU_CCOFF_B;                 /*!< Offset: 0x31C  voltage Automatic Temperature Compensation First coefficient		(R/W)*/
    __IO uint32_t TU_CCOFF_C;                 /*!< Offset: 0x320  voltage Automatic Temperature Compensation Constant coefficient	(R/W)*/
    __IO uint32_t TI_CCOFF_A;                 /*!< Offset: 0x324  CURRENT Automatic Temperature Compensation Second coefficient		(R/W)*/
    __IO uint32_t TI_CCOFF_B;                 /*!< Offset: 0x328  CURRENT Automatic Temperature Compensation First coefficient		(R/W)*/
    __IO uint32_t TI_CCOFF_C;                 /*!< Offset: 0x32C  CURRENT Automatic Temperature Compensation Constant coefficient	(R/W)*/
    __IO uint32_t TIn_CCOFF_A;                /*!< Offset: 0x330  IN Automatic Temperature Compensation Second coefficient   		(R/W)*/
    __IO uint32_t TIn_CCOFF_B;                /*!< Offset: 0x334  IN Automatic Temperature Compensation First coefficient			(R/W)*/
    __IO uint32_t TIn_CCOFF_C;                /*!< Offset: 0x338  IN Automatic Temperature Compensation Constant coefficient		(R/W)*/
    __IO uint32_t Iregion0;                   /*!< Offset: 0x33C  PHASE SEGMENT THRESHOLD0 							(R/W)*/ 
    __IO uint32_t Iregion1;                   /*!< Offset: 0x340  PHASE SEGMENT THRESHOLD1 							(R/W)*/ 
    __IO uint32_t Iregion0Hys;                /*!< Offset: 0x344  PHASE SEGMENT THRESHOLD0 HYSTERESIS				(R/W)*/ 
    __IO uint32_t Iregion1Hys;                /*!< Offset: 0x348  PHASE SEGMENT THRESHOLD1 HYSTERESIS				(R/W)*/ 
    __IO uint32_t DECReset;                   /*!< Offset: 0x34C  RESET DEC 										(R/W)*/ 
    __IO uint32_t EMUWPREG;                   /*!< Offset: 0x350  EMU WRITE PROTECT  								(R/W)*/ 
    __IO uint32_t SRSTREG;                    /*!< Offset: 0x354  SOFT RESET 										(R/W)*/ 
    __IO uint32_t FlickerCfg;                 /*!< Offset: 0x358  Flicker CONFIG 									(R/W)*/ 
    __IO uint32_t FlickerUaSqrOffset;         /*!< Offset: 0x35C  VOLTAGE CHANNEL A Flicker OFFSET 					(R/W)*/ 
    __IO uint32_t FlickerUbSqrOffset;         /*!< Offset: 0x360  VOLTAGE CHANNEL B Flicker OFFSET 					(R/W)*/  
    __IO uint32_t FlickerUcSqrOffset;         /*!< Offset: 0x364  VOLTAGE CHANNEL C Flicker OFFSET 					(R/W)*/ 
    __IO uint32_t FlickerReset;               /*!< Offset: 0x368  RESET Flicker MODULE 								(R/W)*/ 
    __IO uint32_t RMSUt_THO;                  /*!< Offset: 0x36C  VOLTAGE CHANNEL VECTOR THRESHOLD 					(R/W)*/ 
    __IO uint32_t RMSIt_THO;                  /*!< Offset: 0x370  CURRENT CHANNEL VECTOR THRESHOLD  				(R/W)*/ 
    __IO uint32_t Reserved6[3];  		      /*!< Offset: 0x374~0x37C     											(R/W)*/ 		     
    __IO uint32_t EMUIE1;                     /*!< Offset: 0x380  EMU Interrupt ENABLE1 							(R/W)*/ 
    __IO uint32_t EMUIE2;                     /*!< Offset: 0x384  EMU Interrupt ENABLE2-PeakSagIntIOV				(R/W)*/ 
    __IO uint32_t EMUIF1;                     /*!< Offset: 0x388  EMU Interrupt Flag1 								(R/W)*/ 
    __IO uint32_t EMUIF2;                     /*!< Offset: 0x38C  EMU Interrupt Flag2-PeakSagIntIOV 				(R/W)*/ 
    __IO uint32_t EMUIF_EnergyPOVIF;          /*!< Offset: 0x390  EMU Energy Overflow Interrupt Flag 				(R/W)*/         
    __IO uint32_t EMUIF_EnergyNOVIF;          /*!< Offset: 0x394  EMU Energy Overflow Interrupt Flag 				(R/W)*/     	
} HT_EMU_ECR_TypeDef;                         /* end of group HT_EMU_ECR_TypeDef    */
#endif


#if defined  HT772x
/*
* @brief EMU_EPR define
*/
                                                                                                                        
typedef struct
{										 
    __I uint32_t SPL_U;                       /*!< Offset: 0x000  Voltage Channel ADC SAMPLE						(R)*/
    __I uint32_t Reserved0[2];                /*!< Offset: 0x004~0x008  reserved						(R)*/
    __I uint32_t SPL_I1;                      /*!< Offset: 0x00C  Current Channel 1 ADC SAMPLE						(R)*/
    __I uint32_t SPL_I2;                      /*!< Offset: 0x010  Current Channel 2 ADC SAMPLE						(R)*/
    __I uint32_t Reserved1[2];                /*!< Offset: 0x014~0x018  reserved						(R)*/
    __I uint32_t All_Power_P1;                /*!< Offset: 0x01C  All Channel 1 Power P  							(R)*/
    __I uint32_t All_Power_P2;                /*!< Offset: 0x020  All Channel 2 Power P  							(R)*/
    __I uint32_t Reserved2[1];                /*!< Offset: 0x024  reserved  							(R)*/
    __I uint32_t All_Power_Pt;                /*!< Offset: 0x028  All Channel SUM Power P 							(R)*/
    __I uint32_t All_Power_Q1;                /*!< Offset: 0x02C  All Channel 1 Power Q  							(R)*/
    __I uint32_t All_Power_Q2;                /*!< Offset: 0x030  All Channel 2 Power Q  							(R)*/
    __I uint32_t Reserved3[1];                /*!< Offset: 0x034  reserved  							(R)*/
    __I uint32_t All_Power_Qt;                /*!< Offset: 0x038  All Channel SUM Power Q  							(R)*/
    __I uint32_t All_Power_S1;                /*!< Offset: 0x03C  All Channel 1 Power S   							(R)*/
    __I uint32_t All_Power_S2;                /*!< Offset: 0x040  All Channel 2 Power S   							(R)*/
    __I uint32_t Reserved4[1];                /*!< Offset: 0x044  reserved  							(R)*/
    __I uint32_t All_Power_St;                /*!< Offset: 0x048  All Channel SUM Power S  							(R)*/
    __I uint32_t All_RMS_U;                   /*!< Offset: 0x04C  All Voltage Channel RMS							(R)*/
    __I uint32_t Reserved5[2];                /*!< Offset: 0x050~0x054   reserved						(R)*/
    __I uint32_t All_RMS_I1;                  /*!< Offset: 0x058  All Current Channel 1 RMS							(R)*/
    __I uint32_t All_RMS_I2;                  /*!< Offset: 0x05C  All Current Channel 2 RMS							(R)*/
    __I uint32_t Reserved6[3];                /*!< Offset: 0x060~0x068  reserved						(R)*/
    __I uint32_t RMS_It;                      /*!< Offset: 0x06C  All or Fund Current vector RMS 					(R)*/
    __I uint32_t Reserved7[3];                /*!< Offset: 0x070~0x078  reserved 						(R)*/
    __I uint32_t FreqU;                       /*!< Offset: 0x07C  Voltage Channel Freq  							(R)*/
    __I uint32_t Reserved8[3];                /*!< Offset: 0x080~0x088  reserved 						(R)*/
    __I uint32_t All_PF1;                     /*!< Offset: 0x08C  All Channel 1 POWER FACTOR 						(R)*/
    __I uint32_t All_PF2;                     /*!< Offset: 0x090  All Channel 2 POWER FACTOR 						(R)*/
    __I uint32_t Reserved9[2];                /*!< Offset: 0x094~0x098  reserved 						(R)*/
    __I uint32_t PhaseAngle_U;                /*!< Offset: 0x09C  All/Fund Voltage Channel  Angle 					(R)*/
    __I uint32_t Reserved10[2];               /*!< Offset: 0x0A0~0x0A4 reserved 						(R)*/
    __I uint32_t PhaseAngle_I1;               /*!< Offset: 0x0A8  All/Fund Current Channel 1 Angle 					(R)*/
    __I uint32_t PhaseAngle_I2;               /*!< Offset: 0x0AC  All/Fund Current Channel 2 Angle 					(R)*/
    __I uint32_t Reserved11[2];               /*!< Offset: 0x0B0~0x0B4  reserved  						(R)*/
    __I uint32_t All_EnergyPos_P1;            /*!< Offset: 0x0B8  All Channel 1 Positive PEnergy  					(R)*/
    __I uint32_t All_EnergyPos_P2;            /*!< Offset: 0x0BC  All Channel 2 Positive PEnergy  					(R)*/
    __I uint32_t Reserved12[1];            	  /*!< Offset: 0x0C0  reserved  							(R)*/
    __I uint32_t All_EnergyPos_Pt;            /*!< Offset: 0x0C4  All Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t All_EnergyPos_Q1;            /*!< Offset: 0x0C8  All Channel 1 Positive QEnergy  					(R)*/
    __I uint32_t All_EnergyPos_Q2;            /*!< Offset: 0x0CC  All Channel 2 Positive QEnergy  					(R)*/
    __I uint32_t Reserved13[1];            	  /*!< Offset: 0x0D0  reserved  							(R)*/
    __I uint32_t All_EnergyPos_Qt;            /*!< Offset: 0x0D4  All Channel SUM Positive QEnergy  				(R)*/
    __I uint32_t Energy_S1;                   /*!< Offset: 0x0D8  All/Fund Channel 1 Positive SEnergy  				(R)*/
    __I uint32_t Energy_S2;                   /*!< Offset: 0x0DC  All/Fund Channel 2 Positive SEnergy  				(R)*/
    __I uint32_t Reserved14[1];               /*!< Offset: 0x0E0  reserved  							(R)*/
    __I uint32_t Energy_St;                   /*!< Offset: 0x0E4  All/Fund Channel SUM Positive SEnergy  			(R)*/
    __I uint32_t All_CFCntPos_P1;             /*!< Offset: 0x0E8  All Channel 1 Positive Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_P2;             /*!< Offset: 0x0EC  All Channel 2 Positive Fast PCFCnt  				(R)*/
    __I uint32_t Reserved15[1];               /*!< Offset: 0x0F0  reserved  							(R)*/
    __I uint32_t All_CFCntPos_Pt;             /*!< Offset: 0x0F4  All Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t All_CFCntPos_Q1;             /*!< Offset: 0x0F8  All Channel 1 Positive Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntPos_Q2;             /*!< Offset: 0x0FC  All Channel 2 Positive Fast QCFCnt  				(R)*/
    __I uint32_t Reserved16[1];               /*!< Offset: 0x100  reserved  							(R)*/
    __I uint32_t All_CFCntPos_Qt;             /*!< Offset: 0x104  All Channel SUM Positive Fast QCFCnt  			(R)*/
    __I uint32_t CFCntPos_S1;                 /*!< Offset: 0x108  All/Fund Channel 1 Positive SCFCnt  				(R)*/
    __I uint32_t CFCntPos_S2;                 /*!< Offset: 0x10C  All/Fund Channel 2 Positive SCFCnt  				(R)*/
    __I uint32_t Reserved17[1];               /*!< Offset: 0x110  reserved  							(R)*/
    __I uint32_t CFCntPos_St;                 /*!< Offset: 0x114  All/Fund Channel SUM Positive SCFCnt  			(R)*/
    __I uint32_t All_EnergyNeg_P1;            /*!< Offset: 0x118  All Channel 1 Negative PEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_P2;            /*!< Offset: 0x11C  All Channel 2 Negative PEnergy  					(R)*/
    __I uint32_t Reserved18[1];            	  /*!< Offset: 0x120  reserved  							(R)*/
    __I uint32_t All_EnergyNeg_Pt;            /*!< Offset: 0x124  All Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t All_EnergyNeg_Q1;            /*!< Offset: 0x128  All Channel 1 Negative QEnergy  					(R)*/
    __I uint32_t All_EnergyNeg_Q2;            /*!< Offset: 0x12C  All Channel 2 Negative QEnergy  					(R)*/
    __I uint32_t Reserved19[1];               /*!< Offset: 0x130  reserved  							(R)*/
    __I uint32_t All_EnergyNeg_Qt;            /*!< Offset: 0x134  All Channel SUM Negative QEnergy  				(R)*/
    __I uint32_t All_CFCntNeg_P1;             /*!< Offset: 0x138  All Channel 1 Negative Fast PCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_P2;             /*!< Offset: 0x13C  All Channel 2 Negative Fast PCFCnt  				(R)*/
    __I uint32_t Reserved20[1];               /*!< Offset: 0x140  reserved  							(R)*/
    __I uint32_t All_CFCntNeg_Pt;             /*!< Offset: 0x144  All Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t All_CFCntNeg_Q1;             /*!< Offset: 0x148  All Channel 1 Negative Fast QCFCnt  				(R)*/
    __I uint32_t All_CFCntNeg_Q2;             /*!< Offset: 0x14C  All Channel 2 Negative Fast QCFCnt  				(R)*/
    __I uint32_t Reserved21[1];               /*!< Offset: 0x150  reserved  							(R)*/
    __I uint32_t All_CFCntNeg_Qt;             /*!< Offset: 0x154  All Channel SUM Negative Fast QCFCnt  			(R)*/
    __I uint32_t EnergyNeg_S1Const;           /*!< Offset: 0x158  All/Fund Channel 1 Negative SEnergy  				(R)*/
    __I uint32_t EnergyNeg_S2Const;           /*!< Offset: 0x15C  All/Fund Channel 2 Negative SEnergy  				(R)*/
    __I uint32_t Reserved22[1];               /*!< Offset: 0x160  reserved  							(R)*/
    __I uint32_t EnergyNeg_StConst;           /*!< Offset: 0x164  All/Fund Channel SUM Negative SEnergy  			(R)*/
    __I uint32_t CFCntNeg_S1;                 /*!< Offset: 0x168  All/Fund Channel 1 Negative SCFCnt  				(R)*/
    __I uint32_t CFCntNeg_S2;                 /*!< Offset: 0x16C  All/Fund Channel 2 Negative SCFCnt  				(R)*/
    __I uint32_t Reserved23[1];               /*!< Offset: 0x170  reserved  							(R)*/
    __I uint32_t CFCntNeg_St;                 /*!< Offset: 0x174  All/Fund Channel SUM Negative SCFCnt  			(R)*/
    __I uint32_t Fund_Power_P1;               /*!< Offset: 0x178  Fund Channel 1 PPower  							(R)*/
    __I uint32_t Fund_Power_P2;               /*!< Offset: 0x17C  Fund Channel 2 PPower  							(R)*/
    __I uint32_t Reserved24[1];               /*!< Offset: 0x180  reserved  							(R)*/
    __I uint32_t Fund_Power_Pt;               /*!< Offset: 0x184  Fund Channel SUM PPower  							(R)*/
    __I uint32_t Fund_Power_Q1;               /*!< Offset: 0x188  Fund Channel 1 QPower  							(R)*/
    __I uint32_t Fund_Power_Q2;               /*!< Offset: 0x18C  Fund Channel 2 QPower  							(R)*/
    __I uint32_t Reserved25[1];               /*!< Offset: 0x190  reserved  							(R)*/
    __I uint32_t Fund_Power_Qt;               /*!< Offset: 0x194  Fund Channel SUM QPower  							(R)*/
    __I uint32_t Fund_Power_S1;               /*!< Offset: 0x198  Fund Channel 1 SPower  							(R)*/
    __I uint32_t Fund_Power_S2;               /*!< Offset: 0x19C  Fund Channel 2 SPower  							(R)*/
    __I uint32_t Reserved26[1];               /*!< Offset: 0x1A0  reserved  							(R)*/
    __I uint32_t Fund_Power_St;               /*!< Offset: 0x1A4  Fund Channel SUM SPower  							(R)*/
    __I uint32_t Fund_RMS_U;                  /*!< Offset: 0x1A8  Fund Voltage Channel RMS							(R)*/
    __I uint32_t Reserved27[2];               /*!< Offset: 0x1AC~0x1B0  reserved  						(R)*/
    __I uint32_t Fund_RMS_I1;                 /*!< Offset: 0x1B4  Fund Current Channel 1 RMS						(R)*/
    __I uint32_t Fund_RMS_I2;                 /*!< Offset: 0x1B8  Fund Current Channel 2 RMS						(R)*/
    __I uint32_t Reserved28[2];               /*!< Offset: 0x1BC~0x1C0  Fund Current Channel C RMS						(R)*/
    __I uint32_t Fund_PF1;                    /*!< Offset: 0x1C4  Fund Channel 1 POWER FACTOR 						(R)*/
    __I uint32_t Fund_PF2;                    /*!< Offset: 0x1C8  Fund Channel 2 POWER FACTOR 						(R)*/
    __I uint32_t Reserved29[2];               /*!< Offset: 0x1CC~0x1D0  reserved  						(R)*/
    __I uint32_t Fund_EnergyPos_P1;           /*!< Offset: 0x1D4  Fund Channel 1 Positive PEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_P2;           /*!< Offset: 0x1D8  Fund Channel 2 Positive PEnergy  					(R)*/
    __I uint32_t Reserved30[1];               /*!< Offset: 0x1DC  reserved  							(R)*/
    __I uint32_t Fund_EnergyPos_Pt;           /*!< Offset: 0x1E0  Fund Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t Fund_EnergyPos_Q1;           /*!< Offset: 0x1E4  Fund Channel 1 Positive QEnergy  					(R)*/
    __I uint32_t Fund_EnergyPos_Q2;           /*!< Offset: 0x1E8  Fund Channel 2 Positive QEnergy  					(R)*/
    __I uint32_t Reserved31[1];               /*!< Offset: 0x1EC  reserved  							(R)*/
    __I uint32_t Fund_EnergyPos_Qt;           /*!< Offset: 0x1F0  Fund Channel SUM Positive QEnergy  				(R)*/
    __I uint32_t Fund_CFCntPos_P1;            /*!< Offset: 0x1F4  Fund Channel 1 Positive Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_P2;            /*!< Offset: 0x1F8  Fund Channel 2 Positive Fast PCFCnt  				(R)*/ 
    __I uint32_t Reserved32[1];               /*!< Offset: 0x1FC  reserved  							(R)*/
    __I uint32_t Fund_CFCntPos_Pt;            /*!< Offset: 0x200  Fund Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t Fund_CFCntPos_Q1;            /*!< Offset: 0x204  Fund Channel 1 Positive Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntPos_Q2;            /*!< Offset: 0x208  Fund Channel 2 Positive Fast QCFCnt  				(R)*/ 
    __I uint32_t Reserved33[1];            	  /*!< Offset: 0x20C  reserved  							(R)*/
    __I uint32_t Fund_CFCntPos_Qt;            /*!< Offset: 0x210  Fund Channel SUM Positive Fast QCFCnt  			(R)*/
    __I uint32_t Fund_EnergyNeg_P1;           /*!< Offset: 0x214  Fund Channel 1 Negative PEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_P2;           /*!< Offset: 0x218  Fund Channel 2 Negative PEnergy  					(R)*/
    __I uint32_t Reserved34[1];           	  /*!< Offset: 0x21C  reserved  							(R)*/
    __I uint32_t Fund_EnergyNeg_Pt;           /*!< Offset: 0x220  Fund Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t Fund_EnergyNeg_Q1;           /*!< Offset: 0x224  Fund Channel 1 Negative QEnergy  					(R)*/
    __I uint32_t Fund_EnergyNeg_Q2;           /*!< Offset: 0x228  Fund Channel 2 Negative QEnergy  					(R)*/
    __I uint32_t Reserved35[1];               /*!< Offset: 0x22C  reserved  							(R)*/
    __I uint32_t Fund_EnergyNeg_Qt;           /*!< Offset: 0x230  Fund Channel SUM Negative QEnergy  				(R)*/
    __I uint32_t Fund_CFCntNeg_P1;            /*!< Offset: 0x234  Fund Channel 1 Negative Fast PCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_P2;            /*!< Offset: 0x238  Fund Channel 2 Negative Fast PCFCnt  				(R)*/
    __I uint32_t Reserved36[1];            	  /*!< Offset: 0x23C  reserved  							(R)*/
    __I uint32_t Fund_CFCntNeg_Pt;            /*!< Offset: 0x240  Fund Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t Fund_CFCntNeg_Q1;            /*!< Offset: 0x244  Fund Channel 1 Negative Fast QCFCnt  				(R)*/
    __I uint32_t Fund_CFCntNeg_Q2;            /*!< Offset: 0x248  Fund Channel 2 Negative Fast QCFCnt  				(R)*/
    __I uint32_t Reserved37[1];            	  /*!< Offset: 0x24C  reserved  							(R)*/
    __I uint32_t Fund_CFCntNeg_Qt;            /*!< Offset: 0x250  Fund Channel SUM Negative Fast QCFCnt  			(R)*/
    __I uint32_t Har_Power_P1;                /*!< Offset: 0x254  Har Channel 1 PPower  							(R)*/
    __I uint32_t Har_Power_P2;                /*!< Offset: 0x258  Har Channel 2 PPower  							(R)*/
    __I uint32_t Reserved38[1];               /*!< Offset: 0x25C  reserved  							(R)*/
    __I uint32_t Har_Power_Pt;                /*!< Offset: 0x260  Har Channel SUM PPower  							(R)*/
    __I uint32_t Har_RMS_U;                   /*!< Offset: 0x264  Har Voltage Channel RMS							(R)*/
    __I uint32_t Reserved39[2];               /*!< Offset: 0x268~0x26C  reserved  						(R)*/
    __I uint32_t Har_RMS_I1;                  /*!< Offset: 0x270  Har Current Channel 1 RMS							(R)*/
    __I uint32_t Har_RMS_I2;                  /*!< Offset: 0x274  Har Current Channel 2 RMS							(R)*/
    __I uint32_t Reserved40[2];               /*!< Offset: 0x278~0x27C  reserved  						(R)*/
    __I uint32_t Har_EnergyPos_P1;            /*!< Offset: 0x280  Har Channel 1 Positive PEnergy  					(R)*/
    __I uint32_t Har_EnergyPos_P2;            /*!< Offset: 0x284  Har Channel 2 Positive PEnergy  					(R)*/
    __I uint32_t Reserved41[1];            	  /*!< Offset: 0x288  reserved  							(R)*/
    __I uint32_t Har_EnergyPos_Pt;            /*!< Offset: 0x28C  Har Channel SUM Positive PEnergy  				(R)*/
    __I uint32_t Har_CFCntPos_P1;             /*!< Offset: 0x290  Har Channel 1 Positive Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntPos_P2;             /*!< Offset: 0x294  Har Channel 2 Positive Fast PCFCnt  				(R)*/ 
    __I uint32_t Reserved42[1];               /*!< Offset: 0x298  reserved  							(R)*/
    __I uint32_t Har_CFCntPos_Pt;             /*!< Offset: 0x29C  Har Channel SUM Positive Fast PCFCnt  			(R)*/
    __I uint32_t Har_EnergyNeg_P1;            /*!< Offset: 0x2A0  Har Channel 1 Negative PEnergy  					(R)*/
    __I uint32_t Har_EnergyNeg_P2;            /*!< Offset: 0x2A4  Har Channel 2 Negative PEnergy  					(R)*/
    __I uint32_t Reserved43[1];               /*!< Offset: 0x2A8  reserved  							(R)*/
    __I uint32_t Har_EnergyNeg_Pt;            /*!< Offset: 0x2AC  Har Channel SUM Negative PEnergy  				(R)*/
    __I uint32_t Har_CFCntNeg_P1;             /*!< Offset: 0x2B0  Har Channel 1 Negative Fast PCFCnt  				(R)*/
    __I uint32_t Har_CFCntNeg_P2;             /*!< Offset: 0x2B4  Har Channel 2 Negative Fast PCFCnt  				(R)*/
    __I uint32_t Reserved44[1];               /*!< Offset: 0x2B8  reserved  							(R)*/
    __I uint32_t Har_CFCntNeg_Pt;             /*!< Offset: 0x2BC  Har Channel SUM Negative Fast PCFCnt  			(R)*/
    __I uint32_t DCVar_U;                     /*!< Offset: 0x2C0  Voltage Channel ADC DC DATA						(R)*/
    __I uint32_t Reserved45[2];               /*!< Offset: 0x2C4~0x2C8  reserved  						(R)*/
    __I uint32_t DCVar_I1;                    /*!< Offset: 0x2CC  Current Channel 1 ADC DC DATA						(R)*/
    __I uint32_t DCVar_I2;                    /*!< Offset: 0x2D0  Current Channel 2 ADC DC DATA						(R)*/
    __I uint32_t Reserved46[2];               /*!< Offset: 0x2D4~0x2D8  reserved  						(R)*/
    __I uint32_t UpdHalfWave_U;               /*!< Offset: 0x2DC  Voltage Channel Half Cycle PEAK 					(R)*/
    __I uint32_t Reserved47[2];               /*!< Offset: 0x2E0~0x2E4  reserved  						(R)*/
    __I uint32_t UpdHalfWave_I1;              /*!< Offset: 0x2E8  Current Channel 1 Half Cycle PEAK 				(R)*/
    __I uint32_t UpdHalfWave_I2;              /*!< Offset: 0x2EC  Current Channel 2 Half Cycle PEAK 				(R)*/
    __I uint32_t Reserved48[2];               /*!< Offset: 0x2F0~0x2F4  reserved  						(R)*/
    __I uint32_t QuartRmsIns_U;               /*!< Offset: 0x2F8  Voltage Channel Instant Square Data (For RMS)		(R)*/
    __I uint32_t Reserved49[2];               /*!< Offset: 0x2FC~0x300  reserved  						(R)*/
    __I uint32_t QuartRmsIns_I1;              /*!< Offset: 0x304  Current Channel 1 Instant Square Data (For RMS)	(R)*/
    __I uint32_t QuartRmsIns_I2;              /*!< Offset: 0x308  Current Channel 2 Instant Square Data (For RMS)	(R)*/
    __I uint32_t Reserved50[2];               /*!< Offset: 0x30C~0x310  reserved  						(R)*/
    __I uint32_t PeakVpU;                     /*!< Offset: 0x314  Voltage Channel PEAK Period MAX PEAK 				(R)*/
    __I uint32_t Reserved51[2];               /*!< Offset: 0x318~0x31C  Voltage Channel B PEAK Period MAX PEAK 		(R)*/
    __I uint32_t PeakCntU;                    /*!< Offset: 0x320  Voltage PEAK Period Continuous Half Cycle num 	(R)*/
    __I uint32_t Reserved52[2];               /*!< Offset: 0x324~0x328  reserved  						(R)*/
    __I uint32_t SagVpU;                      /*!< Offset: 0x32C  Voltage Channel SAG Period MIN PEAK 				(R)*/
    __I uint32_t Reserved53[2];               /*!< Offset: 0x330~0x334  reserved  						(R)*/
    __I uint32_t SagCntU;                     /*!< Offset: 0x338  Voltage SAG Period Continuous Half Cycle num 		(R)*/
    __I uint32_t Reserved54[2];               /*!< Offset: 0x33C~0x340  reserved  						(R)*/
    __I uint32_t IntVpU;                      /*!< Offset: 0x344  Voltage INT Period MIN PEAK 						(R)*/
    __I uint32_t Reserved55[2];               /*!< Offset: 0x348~0x34C  reserved  						(R)*/
    __I uint32_t IntCntU;                     /*!< Offset: 0x350  Voltage INT Period Continuous Half Cycle num 		(R)*/
    __I uint32_t Reserved56[2];               /*!< Offset: 0x354~0x358  reserved  						(R)*/
    __I uint32_t OverFlowVpI1;                /*!< Offset: 0x35C  Current Channel 1 IOV Period MAX PEAK 			(R)*/
    __I uint32_t OverFlowVpI2;                /*!< Offset: 0x360  Current Channel 2 IOV Period MAX PEAK 			(R)*/
    __I uint32_t Reserved57[2];               /*!< Offset: 0x364~0x368  reserved  						(R)*/
    __I uint32_t OverFlowCntI1;               /*!< Offset: 0x36C  Current Channel 1 IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t OverFlowCntI2;               /*!< Offset: 0x370  Current Channel 2 IOV Period Continuous Half Cycle num (R)*/
    __I uint32_t Reserved58[2];               /*!< Offset: 0x374~0x378  reserved  						(R)*/
    __I uint32_t AutoTgain_U;                 /*!< Offset: 0x37C  Voltage Channel automatic temperature compensation Gain	(R)*/
    __I uint32_t AutoTgain_I;                 /*!< Offset: 0x380  Current Channel automatic temperature compensation Gain	(R)*/
    __I uint32_t Reserved59;                  /*!< Offset: 0x384  reserved								(R)*/
    __I uint32_t HpRMS_Reg_U;                 /*!< Offset: 0x388  Voltage Channel Half Cycle RMS 					(R)*/
    __I uint32_t Reserved60[2];               /*!< Offset: 0x38C~0x390  reserved 						(R)*/
    __I uint32_t HpRMS_Reg_I1;                /*!< Offset: 0x394  Current Channel 1 Half Cycle RMS 					(R)*/
    __I uint32_t HpRMS_Reg_I2;                /*!< Offset: 0x398  Current Channel 2 Half Cycle RMS 					(R)*/
    __I uint32_t Reserved61[2];               /*!< Offset: 0x39C~0x3A0  reserved  						(R)*/ 
    __I uint32_t DFT_Value_UReal;             /*!< Offset: 0x3A4  Voltage Channel DFT Real						(R)*/  
    __I uint32_t DFT_Value_UImage;            /*!< Offset: 0x3A8  Voltage Channel DFT Imag 						(R)*/  
    __I uint32_t Reserved62[4];               /*!< Offset: 0x3AC~0x3B8  reserved						(R)*/
    __I uint32_t DFT_Value_I1Real;            /*!< Offset: 0x3BC  Current Channel 1 DFT Real						(R)*/
    __I uint32_t DFT_Value_I1Image;           /*!< Offset: 0x3C0  Current Channel 1 DFT Imag 						(R)*/
    __I uint32_t DFT_Value_I2Real;            /*!< Offset: 0x3C4  Current Channel 2 DFT Real						(R)*/
    __I uint32_t DFT_Value_I2Image;           /*!< Offset: 0x3C8  Current Channel 2 DFT Imag 						(R)*/ 
    __I uint32_t Reserved63[6];           	  /*!< Offset: 0x3CC~0x3E0  reserved						(R)*/
    __I uint32_t FlickerUaPinst;              /*!< Offset: 0x3E4  Voltage Channel Flicker Pinst 					(R)*/ 
    __I uint32_t Reserved64[2];               /*!< Offset: 0x3E8~0x3EC  reserved 					    (R)*/
    __I uint32_t Chksum1;                     /*!< Offset: 0x3F0  Calibration register checksum1 					(R)*/ 
    __I uint32_t Chksum2;                     /*!< Offset: 0x3F4  Filter Calibration register checksum2 			(R)*/ 
    __I uint32_t Chksum3;                     /*!< Offset: 0x3F8  EWU/SYNC Calibration register checksum3 			(R)*/ 
    __I uint32_t Reserved65[1];               /*!< Offset: 0x3FC   reserved								(R)*/ 
    __I uint32_t Noload;                      /*!< Offset: 0x400  start Flag 										(R)*/ 
    __I uint32_t REV_Power;                   /*!< Offset: 0x404  Power Direction Flag 								(R)*/  
    __I uint32_t REV_Energy;                  /*!< Offset: 0x408  Energy Direction Flag 							(R)*/ 
    __I uint32_t P90_Power;		              /*!< Offset: 0x40C  Energy Channel POWER 90 Flag						(R)*/ 
    __I uint32_t SignalStatus;                /*!< Offset: 0x410  sample signal and system stautus 					(R)*/ 
    __I uint32_t PeakSagIntIovStau;           /*!< Offset: 0x414  PeakSagINT status Flag 							(R)*/ 
} HT_EMU_EPR_TypeDef;                         /* end of group HT_EMU_EPR_TypeDef           */

/*
* @brief EMU ECR define
*/
typedef struct
{										 
    __IO uint32_t DECShift_UH;                /*!< Offset: 0x000  VOLTAGE CHANNEL Onebit Shift big pat 				(R/W)*/
    __IO uint32_t DECShift_UL;                /*!< Offset: 0x004  VOLTAGE CHANNEL Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_UH_BAK;            /*!< Offset: 0x008  VOLTAGE CHANNEL BAK Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_UL_BAK;            /*!< Offset: 0x00C  VOLTAGE CHANNEL BAK Onebit Shift small pat 		(R/W)*/
    __IO uint32_t Reserved0[2];               /*!< Offset: 0x010~0x014  reserved 			(R/W)*/
    __IO uint32_t DECShift_I1H;               /*!< Offset: 0x018  CURRENT CHANNEL 1 Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_I1L;               /*!< Offset: 0x01C  CURRENT CHANNEL 1 Onebit Shift small pat 			(R/W)*/
    __IO uint32_t DECShift_I2H;               /*!< Offset: 0x020  CURRENT CHANNEL 2 Onebit Shift big pat 			(R/W)*/
    __IO uint32_t DECShift_I2L;               /*!< Offset: 0x024  CURRENT CHANNEL 2 Onebit Shift small pat 			(R/W)*/
    __IO uint32_t Reserved1[4];               /*!< Offset: 0x028~0x034  reserved 			(R/W)*/
    __IO uint32_t ADCOffset_U;                /*!< Offset: 0x038  VOLTAGE CHANNEL ADC DC OFFSET						(R/W)*/
    __IO uint32_t ADCOffset_U_BAK;            /*!< Offset: 0x03C  VOLTAGE CHANNEL BAK ADC DC OFFSET					(R/W)*/
    __IO uint32_t Reserved2[1];               /*!< Offset: 0x040  VOLTAGE CHANNEL C ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_I1;               /*!< Offset: 0x044  CURRENT CHANNEL 1 ADC DC OFFSET					(R/W)*/
    __IO uint32_t ADCOffset_I2;               /*!< Offset: 0x048  CURRENT CHANNEL 2 ADC DC OFFSET					(R/W)*/
    __IO uint32_t Reserved3[2];               /*!< Offset: 0x04C~0x050  reserved 			(R/W)*/
    __IO uint32_t Tgain_U;                    /*!< Offset: 0x054  Voltage CHANNEL ADC Temperature gain				(R/W)*/
    __IO uint32_t Tgain_I;                    /*!< Offset: 0x058  CURRENT CHANNEL ADC Temperature gain				(R/W)*/
    __IO uint32_t Reserved4[1];               /*!< Offset: 0x05C  reserved 			 		(R/W)*/
    __IO uint32_t Gain_U;                     /*!< Offset: 0x060  VOLTAGE CHANNEL ADC GAIN						(R/W)*/
    __IO uint32_t Gain_U_BAK;                 /*!< Offset: 0x064  VOLTAGE CHANNEL BAK ADC GAIN						(R/W)*/
    __IO uint32_t Reserved5[1];               /*!< Offset: 0x068  reserved 					(R/W)*/
    __IO uint32_t Gain_I1;                    /*!< Offset: 0x06C  CURRENT CHANNEL 1 ADC GAIN						(R/W)*/
    __IO uint32_t Gain_I2;                    /*!< Offset: 0x070  CURRENT CHANNEL 2 ADC GAIN						(R/W)*/
    __IO uint32_t Reserved6[2];               /*!< Offset: 0x074~0x078  reserved 			(R/W)*/
    __IO uint32_t Digtal_gain;                /*!< Offset: 0x07C  ADC DIGTAL GAIN									(R/W)*/
    __IO uint32_t All_GP1;                    /*!< Offset: 0x080  ALL CHANNEL 1 POWER PGAIN 						(R/W)*/
    __IO uint32_t All_GP2;                    /*!< Offset: 0x084  ALL CHANNEL 2 POWER PGAIN 						(R/W)*/
    __IO uint32_t Reserved7[1];               /*!< Offset: 0x088  reserved 					(R/W)*/
    __IO uint32_t All_GQ1;                    /*!< Offset: 0x08C  ALL CHANNEL 1 POWER QGAIN 						(R/W)*/
    __IO uint32_t All_GQ2;                    /*!< Offset: 0x090  ALL CHANNEL 2 POWER QGAIN 						(R/W)*/
    __IO uint32_t Reserved8[1];               /*!< Offset: 0x094  reserved 					(R/W)*/
    __IO uint32_t All_GS1;                    /*!< Offset: 0x098  ALL CHANNEL 1 POWER SGAIN 						(R/W)*/
    __IO uint32_t All_GS2;                    /*!< Offset: 0x09C  ALL CHANNEL 2 POWER SGAIN 						(R/W)*/
    __IO uint32_t Reserved9[1];               /*!< Offset: 0x0A0  reserved 					(R/W)*/
    __IO uint32_t All_Gphs10;                 /*!< Offset: 0x0A4  ALL CHANNEL 1 PHASE CORRECTION 0 					(R/W)*/
    __IO uint32_t All_Gphs11;                 /*!< Offset: 0x0A8  ALL CHANNEL 1 PHASE CORRECTION 1 					(R/W)*/
    __IO uint32_t All_Gphs12;                 /*!< Offset: 0x0AC  ALL CHANNEL 1 PHASE CORRECTION 2 					(R/W)*/
    __IO uint32_t All_Gphs20;                 /*!< Offset: 0x0B0  ALL CHANNEL 2 PHASE CORRECTION 0 					(R/W)*/
    __IO uint32_t All_Gphs21;                 /*!< Offset: 0x0B4  ALL CHANNEL 2 PHASE CORRECTION 1 					(R/W)*/
    __IO uint32_t All_Gphs22;                 /*!< Offset: 0x0B8  ALL CHANNEL 2 PHASE CORRECTION 2 					(R/W)*/
    __IO uint32_t Reserved10[4];              /*!< Offset: 0x0BC~0x0C8   reserved 			(R/W)*/	
    __IO uint32_t All_PowerOffset_P1;         /*!< Offset: 0x0CC  ALL CHANNEL 1 POWER POFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_P2;         /*!< Offset: 0x0D0  ALL CHANNEL 2 POWER POFFSET 						(R/W)*/
    __IO uint32_t Reserved11[1];         	  /*!< Offset: 0x0D4  reserved 					(R/W)*/
    __IO uint32_t All_PowerOffset_Q1;         /*!< Offset: 0x0D8  ALL CHANNEL 1 POWER QOFFSET 						(R/W)*/
    __IO uint32_t All_PowerOffset_Q2;         /*!< Offset: 0x0DC  ALL CHANNEL 2 POWER QOFFSET 						(R/W)*/
    __IO uint32_t Reserved12[1];         	  /*!< Offset: 0x0E0  reserved 					(R/W)*/
    __IO uint32_t All_RmsOffset_U;            /*!< Offset: 0x0E4  ALL VOLTAGE CHANNEL RMS OFFSET 					(R/W)*/
    __IO uint32_t Reserved13[2];           	  /*!< Offset: 0x0E8~0x0EC  reserved 			(R/W)*/
    __IO uint32_t All_RmsOffset_I1;           /*!< Offset: 0x0F0  ALL CURRENT CHANNEL 1 RMS OFFSET 					(R/W)*/
    __IO uint32_t All_RmsOffset_I2;           /*!< Offset: 0x0F4  ALL CURRENT CHANNEL 2 RMS OFFSET 					(R/W)*/
    __IO uint32_t Reserved14[3];              /*!< Offset: 0x0F8~0x100  reserved 			(R/W)*/
    __IO uint32_t RMSOffset_It;               /*!< Offset: 0x104  CURRENT VECTOR RMS OFFSET	 						(R/W)*/
    __IO uint32_t Reserved15[2];              /*!< Offset: 0x108~0x10C reserved 			(R/W)*/
    __IO uint32_t Fund_GP1;                   /*!< Offset: 0x110  FUND CHANNEL 1 POWER PGAIN 						(R/W)*/
    __IO uint32_t Fund_GP2;                   /*!< Offset: 0x114  FUND CHANNEL 2 POWER PGAIN 						(R/W)*/
    __IO uint32_t Reserved16[1];              /*!< Offset: 0x118  reserved 			 		(R/W)*/
    __IO uint32_t Fund_GQ1;                   /*!< Offset: 0x11C  FUND CHANNEL 1 POWER QGAIN 						(R/W)*/
    __IO uint32_t Fund_GQ2;                   /*!< Offset: 0x120  FUND CHANNEL 2 POWER QGAIN 						(R/W)*/
    __IO uint32_t Reserved17[1];              /*!< Offset: 0x124  reserved 					(R/W)*/  
    __IO uint32_t Fund_GS1;                   /*!< Offset: 0x128  FUND CHANNEL 1 POWER SGAIN 						(R/W)*/
    __IO uint32_t Fund_GS2;                   /*!< Offset: 0x12C  FUND CHANNEL 2 POWER SGAIN 						(R/W)*/
    __IO uint32_t Reserved18[1];              /*!< Offset: 0x130  reserved 					(R/W)*/
    __IO uint32_t Fund_Gphs10;                /*!< Offset: 0x134  FUND CHANNEL 1 PHASE CORRECTION 0 				(R/W)*/
    __IO uint32_t Fund_Gphs11;                /*!< Offset: 0x138  FUND CHANNEL 1 PHASE CORRECTION 1 				(R/W)*/
    __IO uint32_t Fund_Gphs12;                /*!< Offset: 0x13C  FUND CHANNEL 1 PHASE CORRECTION 2 				(R/W)*/
    __IO uint32_t Fund_Gphs20;                /*!< Offset: 0x140  FUND CHANNEL 2 PHASE CORRECTION 0 				(R/W)*/
    __IO uint32_t Fund_Gphs21;                /*!< Offset: 0x144  FUND CHANNEL 2 PHASE CORRECTION 1 				(R/W)*/
    __IO uint32_t Fund_Gphs22;                /*!< Offset: 0x148  FUND CHANNEL 2 PHASE CORRECTION 2 				(R/W)*/  
    __IO uint32_t Reserved19[4];              /*!< Offset: 0x14C~0x158  reserved 			(R/W)*/
    __IO uint32_t Fund_PowerOffset_P1;        /*!< Offset: 0x15C  FUND CHANNEL 1 POWER POFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_P2;        /*!< Offset: 0x160  FUND CHANNEL 2 POWER POFFSET 						(R/W)*/
    __IO uint32_t Reserved20[1];        	  /*!< Offset: 0x164  reserved 					(R/W)*/  
    __IO uint32_t Fund_PowerOffset_Q1;        /*!< Offset: 0x168  FUND CHANNEL 1 POWER QOFFSET 						(R/W)*/
    __IO uint32_t Fund_PowerOffset_Q2;        /*!< Offset: 0x16C  FUND CHANNEL 2 POWER QOFFSET 						(R/W)*/
    __IO uint32_t Reserved21[1];        	  /*!< Offset: 0x170  reserved 					(R/W)*/
    __IO uint32_t Fund_RmsOffset_U;           /*!< Offset: 0x174  FUND VOLTAGE CHANNEL RMS OFFSET 					(R/W)*/
    __IO uint32_t Reserved22[2];          	  /*!< Offset: 0x178~0x17C  reserved 			(R/W)*/
    __IO uint32_t Fund_RmsOffset_I1;          /*!< Offset: 0x180  FUND CURRENT CHANNEL 1 RMS OFFSET 				(R/W)*/
    __IO uint32_t Fund_RmsOffset_I2;          /*!< Offset: 0x184  FUND CURRENT CHANNEL 2 RMS OFFSET 				(R/W)*/ 	
    __IO uint32_t Reserved23[2];          	  /*!< Offset: 0x188~0x18C  reserved 			(R/W)*/   
    __IO uint32_t Har_GP1;                    /*!< Offset: 0x190  HAR CHANNEL 1 POWER PGAIN 						(R/W)*/   
    __IO uint32_t Har_GP2;                    /*!< Offset: 0x194  HAR CHANNEL 2 POWER PGAIN 						(R/W)*/  
    __IO uint32_t Reserved24[1];              /*!< Offset: 0x198  reserved 					(R/W)*/  
    __IO uint32_t Har_PowerOffset_P1;         /*!< Offset: 0x19C  HAR CHANNEL 1 POWER POFFSET 						(R/W)*/  
    __IO uint32_t Har_PowerOffset_P2;         /*!< Offset: 0x1A0  HAR CHANNEL 2 POWER POFFSET 						(R/W)*/  
    __IO uint32_t Reserved25[1];         	  /*!< Offset: 0x1A4  reserved 			 		(R/W)*/  
    __IO uint32_t Har_RmsOffset_U;            /*!< Offset: 0x1A8  HAR VOLTAGE CHANNEL RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Reserved26[2];           	  /*!< Offset: 0x1AC~0x1B0  reserved 			(R/W)*/  
    __IO uint32_t Har_RmsOffset_I1;           /*!< Offset: 0x1B4  HAR CURRENT CHANNEL 1 RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Har_RmsOffset_I2;           /*!< Offset: 0x1B8  HAR CURRENT CHANNEL 2 RMS OFFSET 					(R/W)*/ 
    __IO uint32_t Reserved27[2];           	  /*!< Offset: 0x1BC~0x1C0  reserved 			(R/W)*/ 
    __IO uint32_t PowerConst_All_P1;          /*!< Offset: 0x1C4  CHANNEL 1 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_P2;          /*!< Offset: 0x1C8  CHANNEL 2 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved28[1];              /*!< Offset: 0x1CC  reserved 					(R/W)*/
    __IO uint32_t PowerConst_All_Pt;          /*!< Offset: 0x1D0  CHANNEL 3 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Q1;          /*!< Offset: 0x1D4  CHANNEL 4 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_All_Q2;          /*!< Offset: 0x1D8  CHANNEL 5 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved29[1];          	  /*!< Offset: 0x1DC  reserved 					(R/W)*/
    __IO uint32_t PowerConst_All_Qt;          /*!< Offset: 0x1E0  CHANNEL 6 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_S1;              /*!< Offset: 0x1E4  CHANNEL 7 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_S2;              /*!< Offset: 0x1E8  CHANNEL 8 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved30[1];              /*!< Offset: 0x1EC  reserved 					(R/W)*/
    __IO uint32_t PowerConst_St;              /*!< Offset: 0x1F0  CHANNEL 9 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_P1;         /*!< Offset: 0x1F4  CHANNEL 10 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_P2;         /*!< Offset: 0x1F8  CHANNEL 11 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved31[1];         	  /*!< Offset: 0x1FC  reserved 					(R/W)*/
    __IO uint32_t PowerConst_Fund_Pt;         /*!< Offset: 0x200  CHANNEL 12 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Q1;         /*!< Offset: 0x204  CHANNEL 13 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Fund_Q2;         /*!< Offset: 0x208  CHANNEL 14 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved32[1];         	  /*!< Offset: 0x20C  reserved 					(R/W)*/
    __IO uint32_t PowerConst_Fund_Qt;         /*!< Offset: 0x210  CHANNEL 15 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_P1;          /*!< Offset: 0x214  CHANNEL 16 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t PowerConst_Har_P2;          /*!< Offset: 0x218  CHANNEL 17 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t Reserved33[1];          	  /*!< Offset: 0x21C  reserved 					(R/W)*/
    __IO uint32_t PowerConst_Har_Pt;          /*!< Offset: 0x220  CHANNEL 18 ENENRGY CONSTANT 						(R/W)*/
    __IO uint32_t AccuOffset_Har_P1_Pos;      /*!< Offset: 0x224  channel 1 HAR POSITIVE ENERGY OFFSET 				(R/W)*/
    __IO uint32_t AccuOffset_Har_P1_Neg;      /*!< Offset: 0x228  channel 1  HAR NEGATIVE ENERGY OFFSET 			(R/W)*/
    __IO uint32_t AccuOffset_Har_P2_Pos;      /*!< Offset: 0x22C  channel 2  HAR POSITIVE ENERGY OFFSET 			(R/W)*/
    __IO uint32_t AccuOffset_Har_P2_Neg;      /*!< Offset: 0x230  channel 2  HAR NEGATIVE ENERGY OFFSET 			(R/W)*/
    __IO uint32_t Reserved34[2];      		  /*!< Offset: 0x234~0x238  reserved			(R/W)*/
    __IO uint32_t AccuOffset_Har_Pt_Pos;      /*!< Offset: 0x23C  SUM HAR POSITIVE ENERGY OFFSET 					(R/W)*/
    __IO uint32_t AccuOffset_Har_Pt_Neg;      /*!< Offset: 0x240  SUM HAR NEGATIVE ENERGY OFFSET 					(R/W)*/
    __IO uint32_t Uconst;                     /*!< Offset: 0x244  VOLTAGE CHANNEL CONSTANT 							(R/W)*/
    __IO uint32_t Uconst_BAK;              	  /*!< Offset: 0x248  VOLTAGE CHANNEL BAK CONSTANT 						(R/W)*/
    __IO uint32_t Reserved35[1];              /*!< Offset: 0x24C  reserved 					(R/W)*/
	__IO uint32_t ZXLostCFG;                  /*!< Offset: 0x250  ZCNumMin / ZCNumMax / NumFund 					(R/W)*/
    __IO uint32_t PStart;                     /*!< Offset: 0x254  P POWER START CONFIG 								(R/W)*/
    __IO uint32_t QStart;                     /*!< Offset: 0x258  Q POWER START CONFIG 								(R/W)*/
    __IO uint32_t HarStart;                   /*!< Offset: 0x25C  HAR POWER START CONFIG 							(R/W)*/
    __IO uint32_t AVG_Energy;                 /*!< Offset: 0x260  ENERGY AVERAGE NUM								(R/W)*/
    __IO uint32_t AVG_PowerREG;               /*!< Offset: 0x264  POWER AVERAGE NUM 								(R/W)*/
    __IO uint32_t AVG_RMS;                    /*!< Offset: 0x268  RMS AVERAGE NUM 									(R/W)*/
    __IO uint32_t AVG_RMST;                   /*!< Offset: 0x26C  VECTOR RMS AVERAGE NUM 							(R/W)*/
    __IO uint32_t HFConstAF;  			      /*!< Offset: 0x270  ALL FUND ENERGY HFConst 							(R/W)*/
    __IO uint32_t HFConstHar;                 /*!< Offset: 0x274  HAR ENERGY HFConst 								(R/W)*/
    __IO uint32_t AFDIV;                      /*!< Offset: 0x278  ALL FUND ENERGY DIV 								(R/W)*/
    __IO uint32_t HarDIV;                     /*!< Offset: 0x27C  HAR ENERGY DIV 									(R/W)*/
    __IO uint32_t ChannelSel;                 /*!< Offset: 0x280  CHANNEL SELECT 									(R/W)*/
    __IO uint32_t PGACON;                     /*!< Offset: 0x284  ANALOG PGA CONCTRL 								(R/W)*/
    __IO uint32_t ADCCFG;                     /*!< Offset: 0x288  ADC CONFIG 										(R/W)*/
    __IO uint32_t ADCCON;                     /*!< Offset: 0x28C  ADC CONCTRL 										(R/W)*/     			     
    __IO uint32_t EMUCFG;                     /*!< Offset: 0x290  EMU CONFIG 										(R/W)*/     			   
    __IO uint32_t FilterCon;                  /*!< Offset: 0x294  FILTER CONTRL 									(R/W)*/     		   
    __IO uint32_t FilterCFG;                  /*!< Offset: 0x298  FILTER CONFIG										(R/W)*/     		   
    __IO uint32_t StartCFG;                   /*!< Offset: 0x29C  START CONFIG 										(R/W)*/     		   
    __IO uint32_t ANACFG1;                    /*!< Offset: 0x2A0  ANALOG CONFIG 1									(R/W)*/   		   
    __IO uint32_t ANACFG2;                    /*!< Offset: 0x2A4  ANALOG CONFIG 2									(R/W)*/     		   
    __IO uint32_t Reserved36[3];     		  /*!< Offset: 0x2A8~0x2B0  RESERVED    								(R/W)*/ 
    __IO uint32_t FailVoltage;                /*!< Offset: 0x2B4  ALL_RMSU THRESHOLD CONFIG 						(R/W)*/    		   
    __IO uint32_t LPModeCON;                   /*!< Offset: 0x2B8  LOW POWER MODE CONFIG							(R/W)*/    		   
    __IO uint32_t CFxRun;                     /*!< Offset: 0x2BC  ENERGY ADD ENABLE 								(R/W)*/ 				   
    __IO uint32_t EnergyCon;                  /*!< Offset: 0x2C0  ENERGY CONTRL										(R/W)*/ 			   
    __IO uint32_t PowerSrcCFG1;               /*!< Offset: 0x2C4  ENERGY ADD SOURCE SELECT CONFIG1					(R/W)*/ 		 
    __IO uint32_t PowerSrcCFG2;               /*!< Offset: 0x2C8  ENERGY ADD SOURCE SELECT CONFIG2					(R/W)*/     	     
    __IO uint32_t PowerModeCFG;               /*!< Offset: 0x2CC  ENERGY ADD MODE CONFIG							(R/W)*/     	     
    __IO uint32_t CFCFG1;                     /*!< Offset: 0x2D0  ENERGY CF CONFIG1 								(R/W)*/     			     
    __IO uint32_t CFCFG2;                     /*!< Offset: 0x2D4  ENERGY CF CONFIG2 								(R/W)*/  			     
    __IO uint32_t Reserved37[2];  			  /*!< Offset: 0x2D8~0x2DC   reserved  									(R/W)*/     			     
    __IO uint32_t PowerConstLoad;             /*!< Offset: 0x2E0  CONSTANT POWER Load								(R/W)*/
    __IO uint32_t UPeakSagCyc;                /*!< Offset: 0x2E4  sag/peak CONTINUOUS HALF CYCLE NUM				(R/W)*/
    __IO uint32_t UIntCyc;                    /*!< Offset: 0x2E8  UInt CONTINUOUS HALF CYCLE NUM					(R/W)*/
    __IO uint32_t IOVCyc;                     /*!< Offset: 0x2EC  IOV CONTINUOUS HALF CYCLE NUM						(R/W)*/
    __IO uint32_t PeakLVL;                    /*!< Offset: 0x2F0  Upeak THRESHOLD 									(R/W)*/
    __IO uint32_t SagLVL;                     /*!< Offset: 0x2F4  Usag THRESHOLD 									(R/W)*/
    __IO uint32_t IntLVL;                     /*!< Offset: 0x2F8  UINT THRESHOLD 									(R/W)*/
    __IO uint32_t IOVLVL;                     /*!< Offset: 0x2FC  IOV THRESHOLD 									(R/W)*/
    __IO uint32_t PeakLVLHys;                 /*!< Offset: 0x300  Upeak HYSTERESIS 									(R/W)*/
    __IO uint32_t SagLVLHys;                  /*!< Offset: 0x304  Usag HYSTERESIS 									(R/W)*/
    __IO uint32_t IntLVLHys;                  /*!< Offset: 0x308  UINT HYSTERESIS 									(R/W)*/
    __IO uint32_t IOVLVLHys;                  /*!< Offset: 0x30C  CURRENT OVerflow HYSTERESIS 						(R/W)*/
    __IO uint32_t UZCLVL;                     /*!< Offset: 0x310  voltage CHANNEL ZEROCROSS THRESHOLD				(R/W)*/
    __IO uint32_t IZCLVL;                     /*!< Offset: 0x314  CURRENT CHANNEL ZEROCROSS THRESHOLD				(R/W)*/
    __IO uint32_t TU_CCOFF_A;                 /*!< Offset: 0x318  voltage Automatic Temperature Compensation Second coefficient		(R/W)*/
    __IO uint32_t TU_CCOFF_B;                 /*!< Offset: 0x31C  voltage Automatic Temperature Compensation First coefficient		(R/W)*/
    __IO uint32_t TU_CCOFF_C;                 /*!< Offset: 0x320  voltage Automatic Temperature Compensation Constant coefficient	(R/W)*/
    __IO uint32_t TI_CCOFF_A;                 /*!< Offset: 0x324  CURRENT Automatic Temperature Compensation Second coefficient		(R/W)*/
    __IO uint32_t TI_CCOFF_B;                 /*!< Offset: 0x328  CURRENT Automatic Temperature Compensation First coefficient		(R/W)*/
    __IO uint32_t TI_CCOFF_C;                 /*!< Offset: 0x32C  CURRENT Automatic Temperature Compensation Constant coefficient	(R/W)*/
    __IO uint32_t Reserved38[3];              /*!< Offset: 0x330~0x338  reserved   				(R/W)*/
    __IO uint32_t Iregion0;                   /*!< Offset: 0x33C  PHASE SEGMENT THRESHOLD0 							(R/W)*/ 
    __IO uint32_t Iregion1;                   /*!< Offset: 0x340  PHASE SEGMENT THRESHOLD1 							(R/W)*/ 
    __IO uint32_t Iregion0Hys;                /*!< Offset: 0x344  PHASE SEGMENT THRESHOLD0 HYSTERESIS				(R/W)*/ 
    __IO uint32_t Iregion1Hys;                /*!< Offset: 0x348  PHASE SEGMENT THRESHOLD1 HYSTERESIS				(R/W)*/ 
    __IO uint32_t DECReset;                   /*!< Offset: 0x34C  RESET DEC 										(R/W)*/ 
    __IO uint32_t EMUWPREG;                   /*!< Offset: 0x350  EMU WRITE PROTECT  								(R/W)*/ 
    __IO uint32_t SRSTREG;                    /*!< Offset: 0x354  SOFT RESET 										(R/W)*/ 
    __IO uint32_t FlickerCfg;                 /*!< Offset: 0x358  Flicker CONFIG 									(R/W)*/ 
    __IO uint32_t FlickerUSqrOffset;          /*!< Offset: 0x35C  VOLTAGE CHANNEL Flicker OFFSET 					(R/W)*/ 
    __IO uint32_t Reserved39[2];              /*!< Offset: 0x360~0x364  reserved 				(R/W)*/  
    __IO uint32_t FlickerReset;               /*!< Offset: 0x368  RESET Flicker MODULE 								(R/W)*/ 
    __IO uint32_t Reserved40[1];              /*!< Offset: 0x36C  VOLTAGE CHANNEL VECTOR THRESHOLD 					(R/W)*/ 
    __IO uint32_t RMSIt_THO;                  /*!< Offset: 0x370  CURRENT CHANNEL VECTOR THRESHOLD  				(R/W)*/ 
    __IO uint32_t Reserved41[3];  		      /*!< Offset: 0x374~0x37C   reserved  				(R/W)*/ 		     
    __IO uint32_t EMUIE1;                     /*!< Offset: 0x380  EMU Interrupt ENABLE1 							(R/W)*/ 
    __IO uint32_t EMUIE2;                     /*!< Offset: 0x384  EMU Interrupt ENABLE2-PeakSagIntIOV				(R/W)*/ 
    __IO uint32_t EMUIF1;                     /*!< Offset: 0x388  EMU Interrupt Flag1 								(R/W)*/ 
    __IO uint32_t EMUIF2;                     /*!< Offset: 0x38C  EMU Interrupt Flag2-PeakSagIntIOV 				(R/W)*/ 
    __IO uint32_t EMUIF_EnergyPOVIF;          /*!< Offset: 0x390  EMU Energy Overflow Interrupt Flag 				(R/W)*/         
    __IO uint32_t EMUIF_EnergyNOVIF;          /*!< Offset: 0x394  EMU Energy Overflow Interrupt Flag 				(R/W)*/     	
} HT_EMU_ECR_TypeDef;                         /* end of group HT_EMU_ECR_TypeDef    */
#endif


#if defined  HT762x  || defined  HT772x
/*
* @brief FILTER ECR define
*/
typedef struct
{										 
    __IO uint32_t FundHarCFG;                     /*!< Offset: 0x01c filter CONFIG 									(R/W)*/
} HT_FILTER_ECR_TypeDef;                        /* end of group HT_FILTER_ECRTypeDef */
/*
* @brief EWU ECR define
*/
typedef struct
{										 
    __IO uint32_t EWUIE;                  		/*!< Offset: 0x000 interrupt ENABLE CONFIG								    (R/W)*/
    __IO uint32_t EWUIF;                  		/*!< Offset: 0x004 interrupt flag status 									(R/W)*/
} HT_EWU_ECR_TypeDef;                        	/* end of group HT_EWU_ECRTypeDef */
/*
* @brief LTV ECR define
*/
typedef struct
{										 
    __IO uint32_t SYNC_CFG;                   /*!< Offset: 0x000 SYNC CONFIG 									(R/W)*/
    __IO uint32_t SFO_Value;                  /*!< Offset: 0x004 SFO DATA 										(R/W)*/
    __IO uint32_t REC_CFG;                    /*!< Offset: 0x008 NON-INTRUSIVE CONFIG 							(R/W)*/
    __IO uint32_t DFT_CFG;                    /*!< Offset: 0x00C RESAMPLE OUTPUT DFT DATA CONFIG 				(R/W)*/
    __IO uint32_t SYNC_DMA_rShift;            /*!< Offset: 0x010 SYNC RIGHT SHIFT								(R/W)*/
    __IO uint32_t HpRMS_Ctl_U;                /*!< Offset: 0x014 VOLTAGE CHANNEL HALF CYCLE RMS CONFIG 			(R/W)*/
    __IO uint32_t HpRMS_Ctl_I;                /*!< Offset: 0x018 CURRENT CHANNEL HALF CYCLE RMS CONFIG 			(R/W)*/
} HT_SYNC_ECR_TypeDef;                        /* end of group HT_SYNC_ECRTypeDef */
/*
* @brief ADCPLL ECR define
*/
typedef struct
{										 
    __IO uint32_t PLL_CTRL;                   /*!< Offset: 0x000    						(R/W)*/
    __IO uint32_t PLL_Gain;                   /*!< Offset: 0x004    						(R/W)*/
    __IO uint32_t PLL_Acc;                    /*!< Offset: 0x008    						(R/W)*/
    __IO uint32_t Sfo_Est;                    /*!< Offset: 0x00C    						(R/W)*/
    __IO uint32_t Lock_THO;                   /*!< Offset: 0x010    						(R/W)*/
    __IO uint32_t Amp_THO;                    /*!< Offset: 0x014    						(R/W)*/
    __IO uint32_t TED_Amnt;                   /*!< Offset: 0x018    						(R/W)*/
}  HT_ADCPLL_ECR_TypeDef;                     /* end of group HT_ADCPLL_ECRTypeDef */
#endif
/*****************************************  KEY Control Block  *******************************************/
#if defined USE_KEYSCAN  
typedef struct
{
    __IO uint32_t KEYSTA;                     /*!< Offset: 0x000 KEYSCAN status register (R/W)       */
    __IO uint32_t KEYIF;                      /*!< Offset: 0x004 key interrupt flag register (R/W)       */
} HT_KEY_TypeDef;                             /* end of group HT_KEY_TypeDef                   */
#endif


/*****************************************  ECC Control Block  *******************************************/
#if defined  USE_ECC ||  defined USE_ECC384
typedef struct
{
    __IO uint32_t ECCCON;                     /*!< Offset: 0x000 ECC Control Register       						(R/W)  */
    __IO uint32_t ECCSTA;                     /*!< Offset: 0x004 ECC Status Register       							(R/W)  */
    #if defined  USE_ECC
    __IO uint32_t PXREG;                      /*!< Offset: 0x008 Register for x Axile Value of Basic point G        (R/W)  */
    __IO uint32_t PYREG;                      /*!< Offset: 0x00C Register for y Axile Value of Basic point G        (R/W)  */
    __IO uint32_t KEYREG;                     /*!< Offset: 0x010 Register for Private Key                           (R/W)  */
    __IO uint32_t AREG;                       /*!< Offset: 0x014 Register for Parameter a of ECC Function           (R/W)  */
    __IO uint32_t PREG;                       /*!< Offset: 0x018 Register for Big Prime P                           (R/W)  */
    __IO uint32_t RXREG;                      /*!< Offset: 0x01C Register for x Axile Value of ECC Operation Result (R/W)  */
    __IO uint32_t RYREG;                      /*!< Offset: 0x020 Register for y Axile Value of ECC Operation Result (R/W)  */
    __IO uint32_t SXREG;                      /*!< Offset: 0x024 Register for x Axile Value of the other ECC Point  (R/W)  */
    __IO uint32_t SYREG;                      /*!< Offset: 0x028 Register for y Axile Value of the other ECC Point  (R/W)  */
    __IO uint32_t MREG;                       /*!< Offset: 0x02C Register for Message HASH       (R/W)  */
    #else
    __O uint32_t  ECCRST;                     /*!< Offset: 0x008 ECC Module Reset Register                          (R/W)  */
    __IO uint32_t PREG[12];                   /*!< Offset: 0x00C Register[0~11] for Big Prime P                     (R/W)  */
	__IO uint32_t NREG[12];                   /*!< Offset: 0x03C Register[0~11] for the Order n of Basic Point G    (R/W)  */
	__IO uint32_t AREG[12];                   /*!< Offset: 0x06C Register[0~11] for Parameter a of ECC Function     (R/W)  */
	__IO uint32_t BREG[12];                   /*!< Offset: 0x09C Register[0~11] for Parameter b of ECC Function     (R/W)  */
	__IO uint32_t PXREG[12];                  /*!< Offset: 0x0CC Register[0~11] for x Axile Value of Basic point G  (R/W)  */
	__IO uint32_t PYREG[12];                  /*!< Offset: 0x0FC Register[0~11] for y Axile Value of Basic point G  (R/W)  */
	__IO uint32_t SXREG[12];                  /*!< Offset: 0x12C Register[0~11] for x Axile Value of Public Key D   (R/W)  */
	__IO uint32_t SYREG[12];                  /*!< Offset: 0x15C Register[0~11] for Y Axile Value of Public Key D   (R/W)  */
	__IO uint32_t KEYREG[12];                 /*!< Offset: 0x18C Register[0~11] for Big Rand k                      (R/W)  */
	__IO uint32_t RXREG[12];                  /*!< Offset: 0x1BC Register[0~11] for ECDSA Signature result r        (R/W)  */
	__IO uint32_t RYREG[12];                  /*!< Offset: 0x1EC Register[0~11] for ECDSA Signature result s        (R/W)  */
    #endif
} HT_ECC_TypeDef;                             /* end of group HT_ECC_TypeDef                   */
#endif

/*****************************************  EMU Interface Block  *******************************************/
#if defined USE_EMUIFACE_5X
typedef struct
{
    __IO uint32_t EICON;                      /*!< Offset: 0x00 EMU Interface Control Register  (R/W)  */
    __IO uint32_t EIIE;                       /*!< Offset: 0x04 EMU Interface Interrupt Enable Register(R/W)  */
    __IO uint32_t EIIF;                       /*!< Offset: 0x08 EMU Interface Interrupt Falg Register(R/W)  */
	  __I  uint32_t Reserved;
		__IO uint32_t EI_NISCFG;                  /*!< Offset: 0x10 Non-intrusive data interface configuration register (R/W)  */
		__I  uint32_t Reserved1[27];
		__IO uint32_t NIS_DATA[3];                /*!< Offset: 0x80 Non-intrusive data interface outputs data registers i(i=0~3) (R/W)  */
} HT_EMU_Interface_TypeDef;                   /* end of group HT_EMU_Interface_TypeDef                   */
#endif

#if defined USE_EMUIFACE_7X
typedef struct
{
    __IO uint32_t EICON;                      /*!< Offset: 0x00 EMU Interface Control Register  (R/W)  */
    __IO uint32_t EIIE;                       /*!< Offset: 0x04 EMU Interface Interrupt Enable Register(R/W)  */
    __IO uint32_t EIIF;                       /*!< Offset: 0x08 EMU Interface Interrupt Falg Register(R/W)  */
    __IO uint32_t EI_FFTCFG;                  /*!< Offset: 0x0C FFT data interface configuration register(R/W)  */
    __IO uint32_t EI_NISCFG;                  /*!< Offset: 0x10 Non-intrusive data interface configuration register(R/W)  */
    __I  uint32_t Reserved[3];
    __IO uint32_t FFT_DATA[21];               /*!< Offset: 0x20 FFT data interface outputs data registers i(i=0~20) (R/W)  */
    __I  uint32_t Reserved2[3];
    __IO uint32_t NIS_DATA[7];                /*!< Offset: 0x80 Non-intrusive data interface outputs data registers i(i=0~6) (R/W)  */
} HT_EMU_Interface_TypeDef;                   /* end of group HT_EMU_Interface_TypeDef                   */
#endif


/*****************************************  FFT Block  *****************************************************/
#if defined  USE_FFT
typedef struct
{
    __IO uint32_t FFTCFG;                     /*!< Offset: 0x00 FFT config register (R/W)  */
    __IO uint32_t FFTIE;                      /*!< Offset: 0x04 FFT Interrupt enable register(R/W)  */
    __IO uint32_t FFT_SRC_DMA_CTL;            /*!< Offset: 0x08 FFT Source data configuration register (R/W)  */
    __IO uint32_t FFT_SRC_DMA_ADDR;           /*!< Offset: 0x0C FFT Source data base address configuration register (R/W)  */
    __IO uint32_t FFT_BUFLEN;                 /*!< Offset: 0x10 FFT Source data space size configuration register (per channel)(R/W)  */
    __IO uint32_t FFT_START_OFFSET;           /*!< Offset: 0x14 FFT Source data start offset register (R/W)  */
    __IO uint32_t FFT_DST_DMA_CTL;            /*!< Offset: 0x18 FFT Output data control register (R/W)  */
    __I  uint32_t FFT_DST_FUNDSCALE;          /*!< Offset: 0x1C FFT Output fundamental wave left shift number register(R)    */
    __I  uint32_t FFT_DST_NONFUNDSCALE;       /*!< Offset: 0x20 FFT Output non - fundamental left shift number register(R)    */
    __IO uint32_t FFT_DST_DMA_ADDR;           /*!< Offset: 0x24 FFT Output data destination address register(R/W)  */
    __I  uint32_t FFT_NUMS;                   /*!< Offset: 0x28 FFT Residual calculation quantity status register(R)    */
    __IO uint32_t FFTIF;                      /*!< Offset: 0x2C FFT Status flag register (R/W)  */
    __IO uint32_t FFTERR;                     /*!< Offset: 0x30 FFT Data overflow status register (R)    */
    __I  uint32_t FFT_DMACNT;                 /*!< Offset: 0x34 FFT DMA Count status register (R)    */
} HT_FFT_TypeDef;                             /* end of group HT_FFT_TypeDef                   */
#endif


/*****************************************  FRAMPACK Block  *************************************************/
#if defined  USE_PACK
typedef struct
{
    __IO uint32_t FRAMCON;                    /*!< Offset: 0x00 Frame function configuration register(R/W)  */
    __IO uint32_t HLCFG;                      /*!< Offset: 0x04 Frame header length configuration register(R/W)  */
    __IO uint32_t FCRCCFG;                    /*!< Offset: 0x08 CRC configuration register (R/W)   */
    __IO uint32_t FCRCINIT;                   /*!< Offset: 0x0C CRC Initialize seed register(R/W)  */
    __IO uint32_t IDCFG;                      /*!< Offset: 0x10 Frame ID configuration register (R/W)  */
    __IO uint32_t FRAMIE;                     /*!< Offset: 0x14 Frame packing interrupt enable register (R/W)  */
    __IO uint32_t FRAMIF;                     /*!< Offset: 0x18 Frame packing interrupt flag register (R/W)  */
    __I  uint32_t Reserved;
    __IO uint32_t SAMPNUM;                    /*!< Offset: 0x20 EMU Number of data sampling groups Configuration register(R/W)  */
    __IO uint32_t HEADA0;                     /*!< Offset: 0x24 Frame head A0 config register (R/W)  */
    __IO uint32_t HEADA1;                     /*!< Offset: 0x28 Frame head A1 config register (R/W)  */
    __IO uint32_t HEADA2;                     /*!< Offset: 0x2C Frame head A2 config register (R/W)  */
    __IO uint32_t HEADA3;                     /*!< Offset: 0x30 Frame head A3 config register (R/W)  */
    __IO uint32_t HEADB0;                     /*!< Offset: 0x34 Frame head B0 config register (R/W)  */
    __IO uint32_t HEADB1;                     /*!< Offset: 0x38 Frame head B1 config register (R/W)  */
    __IO uint32_t HEADB2;                     /*!< Offset: 0x3C Frame head B2 config register (R/W)  */
    __IO uint32_t HEADB3;                     /*!< Offset: 0x40 Frame head B3 config register (R/W)  */
    __IO uint32_t STOPF;                      /*!< Offset: 0x44 Frame tail configuration register (R/W)  */
    __IO uint32_t FRAMIDR;                    /*!< Offset: 0x48 Frame ID count register (R/W)  */
    __I  uint32_t FRAMSTA;                    /*!< Offset: 0x4C Frame state register (R/W)  */
    __IO uint32_t FDLY;                       /*!< Offset: 0x50 Frame interval delay configuration register (R/W)  */
    __IO uint32_t FAUTONUM;                   /*!< Offset: 0x54 Automatic frame sending quantity configuration register (R/W)  */
} HT_FRAMPACK_TypeDef;                        /* end of group HT_FFT_TypeDef                   */
#endif


/*****************************************  Info Control Block  ******************************************/
/**
* @brief  RTC Coefficients Definition in Info
*/
typedef union
{
    struct
    {
        __I  uint32_t iDFAH;
        __I  uint32_t iDFAL;
        __I  uint32_t iDFBH;
        __I  uint32_t iDFBL;
        __I  uint32_t iDFCH;
        __I  uint32_t iDFCL;
        __I  uint32_t iDFDH;
        __I  uint32_t iDFDL;
        __I  uint32_t iDFEH;
        __I  uint32_t iDFEL;
        __I  uint32_t iToff;
        __I  uint32_t iMCON01;
        __I  uint32_t iMCON23;
        __I  uint32_t iMCON45;
        __I  uint32_t iChkSum;               /* iChkSum = iDFAH + iDFAL +...+iMCON45   */
        __I  uint32_t iHRCADJ;
        __I  uint32_t irHRCADJ;
        __I  uint32_t iLRCADJ;
        __I  uint32_t irLRCADJ;
        __I  uint32_t reserved[3];
        __I  uint16_t iTMP275;
        __I  uint16_t iTMPDAT;
    }Muster;
    __I  uint32_t DataArry[24];
} HT_INFO_TypeDef;                           /* end of group HT_INFO_TypeDef           */


/*
**********************************************************************************************************
*                                        Peripheral memory map
*                                           Unit of Byte
**********************************************************************************************************
*/
/*  Base Address  */
#define HT_FLASH_BASE        (0x00000000U)
#define HT_RAM_BASE          (0x20000000U)
#define HT_APB0_BASE         (0x40000000U)

#if defined USE_HT601x_MEMORY 
#define HT_FLASH_SIZE        (0x00020000U)
#define HT_RAM_SIZE          (0x00002000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00040000U)

#define HT_APB0_SIZE         (0x00012000U)

#define HT_INFO_SIZE         (0x00000200U)
#define HT_INFO_BANK         (0x00000100U)
#endif

#if defined USE_HT602x_MEMORY
#define HT_FLASH_SIZE        (0x00040000U)
#define HT_RAM_SIZE          (0x00008000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00040000U)

#define HT_APB0_SIZE         (0x0001B000U)

#define HT_AHB0_BASE         (0x40020000U)
#define HT_AHB0_SIZE         (0x00002000U)

#define HT_INFO_SIZE         (0x00000400U)
#define HT_INFO_BANK         (0x00000400U)
#endif

#if defined USE_HT603x_MEMORY 
#define HT_FLASH_SIZE        (0x00080000U)
#define HT_RAM_SIZE          (0x00010000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00100000U)

#define HT_APB0_SIZE         (0x0001C000U)

#define HT_AHB0_BASE         (0x40020000U)
#define HT_AHB0_SIZE         (0x00002000U)

#define HT_INFO_SIZE         (0x00000400U)
#define HT_INFO_BANK         (0x00000400U)
#endif

#if defined USE_HT633x_MEMORY 
#define HT_FLASH_SIZE        (0x00080000U)
#define HT_RAM_SIZE          (0x00018000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x1FFFC000U)

#define HT_APB0_SIZE         (0x00020000U)

#define HT_AHB0_BASE         (0x40020000U)
#define HT_AHB0_SIZE         (0x00002000U)

#define HT_INFO_SIZE         (0x00000400U)
#define HT_INFO_BANK         (0x00000200U)
#endif

#if defined USE_HT501x_MEMORY 
#define HT_FLASH_SIZE        (0x00020000U)
#define HT_RAM_SIZE          (0x00002000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00040000U)

#define HT_APB0_SIZE         (0x00018000U)

#define HT_INFO_SIZE         (0x00000200U)
#define HT_INFO_BANK         (0x00000100U)
#endif

#if defined USE_HT502x_MEMORY 
#define HT_FLASH_SIZE        (0x00040000U)
#define HT_RAM_SIZE          (0x00008000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00040000U)

#define HT_APB0_SIZE         (0x00018000U)

#define HT_INFO_SIZE         (0x00000400U)
#define HT_INFO_BANK         (0x00000400U)
#endif


#if defined USE_HT503x_MEMORY 
#define HT_FLASH_SIZE        (0x00080000U)
#define HT_RAM_SIZE          (0x00010000U)
#define HT_RAM1_BASE         (0x20004000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x1FFFC000U)

#define HT_APB0_SIZE         (0x00016000U)
#define HT_APB1_BASE         (0x40017000U)
#define HT_APB1_SIZE         (0x0000A000U)

#define HT_AHB0_BASE         (0x40016000U)
#define HT_AHB0_SIZE         (0x00001000U)
#define HT_AHB1_BASE         (0x40021000U)
#define HT_AHB1_SIZE         (0x00002000U)

#define HT_INFO_SIZE         (0x00003000U)
#define HT_INFO_BANK         (0x00000400U)

#define INFO_ADDL_MIN_ADDRESS	(0x1FFFCC00U)
#define INFO_ADDL_MAX_ADDRESS (0x1FFFF800U)

#endif


#if defined USE_HT7x2x_MEMORY 
#define HT_FLASH_SIZE        (0x00040000U)
#define HT_RAM_SIZE          (0x00014000U)
#define HT_RAM1_BASE         (0x20004000U)
#define HT_RAM2_BASE         (0x20008000U)
#define HT_INFO_BASE         (HT_FLASH_BASE + 0x00040000U)

#define HT_APB0_SIZE         (0x00020000U)

#define HT_AHB0_BASE         (0x40020000U)
#define HT_AHB0_SIZE         (0x00003000U)

#define HT_INFO_SIZE         (0x00000400U)
#define HT_INFO_BANK         (0x00000400U)
#endif


/* APB0 Peripherals Address  */
#define HT_UART5_BASE        (HT_APB0_BASE + 0x00000U)
#define HT_TMR0_BASE         (HT_APB0_BASE + 0x01000U)
#define HT_TMR1_BASE         (HT_APB0_BASE + 0x02000U)
#define HT_TMR2_BASE         (HT_APB0_BASE + 0x03000U)
#define HT_TMR3_BASE         (HT_APB0_BASE + 0x04000U)
#define HT_UART0_BASE        (HT_APB0_BASE + 0x05000U)
#define HT_UART1_BASE        (HT_APB0_BASE + 0x06000U)
#define HT_UART2_BASE        (HT_APB0_BASE + 0x07000U)
#define HT_UART3_BASE        (HT_APB0_BASE + 0x08000U)
#define HT_UART4_BASE        (HT_APB0_BASE + 0x09000U)
#define HT_I2C_BASE          (HT_APB0_BASE + 0x0A000U)
#define HT_SPI0_BASE         (HT_APB0_BASE + 0x0B000U)
#define HT_RTC_BASE          (HT_APB0_BASE + 0x0C000U)
#if defined USE_LCD 
#define HT_LCD_BASE          (HT_APB0_BASE + 0x0D000U)
#endif
#define HT_TBS_BASE          (HT_APB0_BASE + 0x0E000U)
#define HT_PMU_BASE          (HT_APB0_BASE + 0x0F400U)
#define HT_CMU_BASE          (HT_APB0_BASE + 0x0F000U)
#define HT_WDT_BASE          (HT_APB0_BASE + 0x10000U)
#define HT_GPIO_BASE         (HT_APB0_BASE + 0x11000U)
#define HT_INT_BASE          (HT_APB0_BASE + 0x11800U)
#define HT_AES_BASE          (HT_APB0_BASE + 0x12000U)
#if defined USE_RAND 
#define HT_RAND_BASE         (HT_APB0_BASE + 0x12080U)
#endif
#define HT_GHASH_BASE        (HT_APB0_BASE + 0x12100U)
#if defined USE_EMU_NORMAL 
#define HT_EMU_EPA_BASE      (HT_APB0_BASE + 0x13000U)
#define HT_EMU_ECA_BASE      (HT_APB0_BASE + 0x13800U)
#endif
#if defined USE_KEYSCAN 
#define HT_KEY_BASE          (HT_APB0_BASE + 0x14000U)
#endif
#if defined USE_LPUART 
#define HT_LPUART_BASE       (HT_APB0_BASE + 0x15000U)
#endif
#if defined USE_SPI3_K 
#define HT_SPI3_BASE         (HT_APB0_BASE + 0x15000U)
#endif
#if defined USE_DMA_SOC 
#define HT_DMA_BASE          (HT_APB0_BASE + 0x16000U)
#endif
#if defined USE_SPI2_MCU 
#define HT_SPI2_BASE         (HT_APB0_BASE + 0x16000U)
#endif
#if defined USE_SPI1_MCU 
#define HT_SPI1_BASE         (HT_APB0_BASE + 0x17000U)
#endif
#if defined USE_ECC_SOC 
#define HT_ECC_BASE          (HT_APB0_BASE + 0x17000U)
#endif
#if defined USE_UART6 
#define HT_UART6_BASE        (HT_APB0_BASE + 0x18000U)
#endif
#if defined USE_TIMER45 
#define HT_TMR4_BASE       (HT_APB0_BASE + 0x19000U)
#define HT_TMR5_BASE       (HT_APB0_BASE + 0x1A000U)
#endif
#if defined USE_ECC_MCU 
#define HT_ECC_BASE          (HT_APB0_BASE + 0x1B000U)
#endif
#if defined USE_EMU_CONST 
#define HT_EMU_BASE          (HT_APB0_BASE + 0x1C000U)
#endif
#if defined USE_EMU_RESAMPLE 
#define HT_EMU_EPA_BASE      (HT_APB0_BASE + 0x1B000U)
#define HT_EMU_ECA_BASE      (HT_APB0_BASE + 0x1C000U)
#define HT_FILTER_ECA_BASE   (HT_APB0_BASE + 0x1C71CU)
#define HT_EWU_ECA_BASE      (HT_APB0_BASE + 0x1CA00U)
#define HT_SYNC_ECA_BASE     (HT_APB0_BASE + 0x1CC00U)
#define HT_ADCPLL_ECA_BASE   (HT_APB0_BASE + 0x1CE00U)
#endif
#if defined USE_SPI_SOC 
#define HT_SPI1_BASE         (HT_APB0_BASE + 0x1C000U)
#define HT_SPI2_BASE         (HT_APB0_BASE + 0x1D000U)
#endif
#if defined USE_FFT 
#define HT_FFT_BASE          (HT_APB0_BASE + 0x1E000U)        
#endif
#if defined USE_SPI3 
#define HT_SPI3_BASE         (HT_APB0_BASE + 0x1F000U)
#endif

#if defined USE_DMA_MCU 
#define HT_DMA_BASE          (HT_APB0_BASE + 0x20000U)
#endif
#if defined USE_CRC 
#define HT_CRC_BASE          (HT_APB0_BASE + 0x21000U)
#endif


#define HT_DMA_Channel0_BASE  (HT_DMA_BASE + 0x0000CU)
#define HT_DMA_Channel1_BASE  (HT_DMA_BASE + 0x00024U)
#define HT_DMA_Channel2_BASE  (HT_DMA_BASE + 0x0003CU)
#if  defined USE_DMA_CH8 
#define HT_DMA_Channel3_BASE  (HT_DMA_BASE + 0x00054U)
#define HT_DMA_Channel4_BASE  (HT_DMA_BASE + 0x0006CU)
#define HT_DMA_Channel5_BASE  (HT_DMA_BASE + 0x00084U)
#define HT_DMA_Channel6_BASE  (HT_DMA_BASE + 0x0009CU)
#define HT_DMA_Channel7_BASE  (HT_DMA_BASE + 0x000B4U)
#endif
#if defined USE_DMA_CH13 
#define HT_DMA_Channel8_BASE  (HT_DMA_BASE + 0x0010CU)
#define HT_DMA_Channel9_BASE  (HT_DMA_BASE + 0x00124U)
#define HT_DMA_Channel10_BASE (HT_DMA_BASE + 0x0013CU)
#define HT_DMA_Channel11_BASE (HT_DMA_BASE + 0x00154U)
#define HT_DMA_Channel12_BASE (HT_DMA_BASE + 0x00208U)   
#endif

#if defined USE_EMUIFACE_5X || defined USE_EMUIFACE_7X 
#define HT_EMU_INTERFACE_BASE (HT_APB0_BASE + 0x22000U)
#endif
#if defined USE_FRAMPACK_5X 
#define HT_FRAMPACK_BASE      (HT_APB0_BASE + 0x1B000U)
#endif
#if  defined USE_FRAMPACK_7X
#define HT_FRAMPACK_BASE      (HT_APB0_BASE + 0x13000U)
#endif

#if defined  USE_STAMP
#define HT_RTC_STAMP0SOURCE0_BASE (HT_APB0_BASE + 0x0C314U)
#define HT_RTC_STAMP0SOURCE1_BASE (HT_APB0_BASE + 0x0C320U)
#define HT_RTC_STAMP0SOURCE2_BASE (HT_APB0_BASE + 0x0C32CU)
#define HT_RTC_STAMP0SOURCE3_BASE (HT_APB0_BASE + 0x0C338U)
#define HT_RTC_STAMP0SOURCE4_BASE (HT_APB0_BASE + 0x0C344U)
#define HT_RTC_STAMP0SOURCE5_BASE (HT_APB0_BASE + 0x0C350U)
#define HT_RTC_STAMP1SOURCE0_BASE (HT_APB0_BASE + 0x0C414U)
#define HT_RTC_STAMP1SOURCE1_BASE (HT_APB0_BASE + 0x0C420U)
#define HT_RTC_STAMP1SOURCE2_BASE (HT_APB0_BASE + 0x0C42CU)
#define HT_RTC_STAMP1SOURCE3_BASE (HT_APB0_BASE + 0x0C438U)
#define HT_RTC_STAMP1SOURCE4_BASE (HT_APB0_BASE + 0x0C444U)
#define HT_RTC_STAMP1SOURCE5_BASE (HT_APB0_BASE + 0x0C450U)
#endif


/*  GPIO Address  */
#if  defined  USE_GPIO_GPIOF
#define USE_GPIOF
#endif
#if  defined  USE_GPIO_GPIOG
#define USE_GPIOG
#endif
#if  defined  USE_GPIO_GPIOH
#define USE_GPIOH
#endif
#if  defined  USE_GPIO_GPIOJ
#define USE_GPIOJ
#endif
#if  defined  USE_GPIO_GPIOI
#define USE_GPIOI
#endif

#define HT_GPIOA_BASE        (HT_GPIO_BASE + 0x00000)
#define HT_GPIOB_BASE        (HT_GPIO_BASE + 0x00100)
#define HT_GPIOC_BASE        (HT_GPIO_BASE + 0x00200)
#define HT_GPIOD_BASE        (HT_GPIO_BASE + 0x00300)
#define HT_GPIOE_BASE        (HT_GPIO_BASE + 0x00400)
#if  defined  USE_GPIOF
#define HT_GPIOF_BASE        (HT_GPIO_BASE + 0x00600)
#elif  defined  USE_GPIOG
#define HT_GPIOG_BASE        (HT_GPIO_BASE + 0x00600)
#endif
#if defined  USE_GPIOH
#define HT_GPIOH_BASE        (HT_GPIO_BASE + 0x00700)
#endif
#if  defined  USE_GPIOJ
#define HT_GPIOJ_BASE        (HT_GPIO_BASE + 0x00900)
#endif
#if  defined  USE_GPIOI
#define HT_GPIOI_BASE        (HT_GPIO_BASE + 0x00900)
#endif


/*
**********************************************************************************************************
*                                        Peripheral declaration
**********************************************************************************************************
*/
#define HT_TMR0              ((HT_TMR_TypeDef    *) HT_TMR0_BASE )
#define HT_TMR1              ((HT_TMR_TypeDef    *) HT_TMR1_BASE )
#define HT_TMR2              ((HT_TMR_TypeDef    *) HT_TMR2_BASE )
#define HT_TMR3              ((HT_TMR_TypeDef    *) HT_TMR3_BASE )
#if  defined  USE_TIMER45 || defined  USE_UART_BASE
#define HT_TMR4              ((HT_TMR_TypeDef    *) HT_TMR4_BASE )
#define HT_TMR5              ((HT_TMR_TypeDef    *) HT_TMR5_BASE )
#endif

#define HT_UART0             ((HT_UART_TypeDef   *) HT_UART0_BASE)
#define HT_UART1             ((HT_UART_TypeDef   *) HT_UART1_BASE)
#define HT_UART2             ((HT_UART_TypeDef   *) HT_UART2_BASE)
#define HT_UART3             ((HT_UART_TypeDef   *) HT_UART3_BASE)
#define HT_UART4             ((HT_UART_TypeDef   *) HT_UART4_BASE)
#define HT_UART5             ((HT_UART_TypeDef   *) HT_UART5_BASE)

#if  defined  USE_UART6  
#define HT_UART6             ((HT_UART_TypeDef   *) HT_UART6_BASE)
#endif

#define HT_ISO7816_0         ((HT_ISO7816_TypeDef*) HT_UART4_BASE)
#define HT_ISO7816_1         ((HT_ISO7816_TypeDef*) HT_UART3_BASE)

#define HT_I2C               ((HT_I2C_TypeDef    *) HT_I2C_BASE  )
#define HT_SPI0              ((HT_SPI_TypeDef    *) HT_SPI0_BASE )
#if  defined  USE_SPI1_MCU  || defined USE_SPI_SOC  
#define HT_SPI1              ((HT_SPI_TypeDef    *) HT_SPI1_BASE )
#endif
#if  defined USE_SPI2_MCU  || defined USE_SPI_SOC
#define HT_SPI2              ((HT_SPI_TypeDef    *) HT_SPI2_BASE )
#endif
#if  defined USE_SPI3 ||  defined  USE_SPI3_K  
#define HT_SPI3              ((HT_SPI_TypeDef    *) HT_SPI3_BASE )
#endif

#define HT_RTC               ((HT_RTC_TypeDef    *) HT_RTC_BASE  )
#if defined  USE_STAMP
#define HT_RTC_STAMP0SOURCE0 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE0_BASE )
#define HT_RTC_STAMP0SOURCE1 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE1_BASE )
#define HT_RTC_STAMP0SOURCE2 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE2_BASE )
#define HT_RTC_STAMP0SOURCE3 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE3_BASE )
#define HT_RTC_STAMP0SOURCE4 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE4_BASE )
#define HT_RTC_STAMP0SOURCE5 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP0SOURCE5_BASE )
#define HT_RTC_STAMP1SOURCE0 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE0_BASE )
#define HT_RTC_STAMP1SOURCE1 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE1_BASE )
#define HT_RTC_STAMP1SOURCE2 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE2_BASE )
#define HT_RTC_STAMP1SOURCE3 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE3_BASE )
#define HT_RTC_STAMP1SOURCE4 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE4_BASE )
#define HT_RTC_STAMP1SOURCE5 ((HT_RTC_STAMPSOURCE_TypeDef    *) HT_RTC_STAMP1SOURCE5_BASE )
#endif

#define HT_HDPORT_BASE  0x40011500
#if defined USE_LCD
#define HT_LCD               ((HT_LCD_TypeDef    *) HT_LCD_BASE  )
#endif
#define HT_TBS               ((HT_TBS_TypeDef    *) HT_TBS_BASE  )
#define HT_PMU               ((HT_PMU_TypeDef    *) HT_PMU_BASE  )
#define HT_CMU               ((HT_CMU_TypeDef    *) HT_CMU_BASE  )
#define HT_WDT               ((HT_WDT_TypeDef    *) HT_WDT_BASE  )
#define HT_INT               ((HT_INT_TypeDef    *) HT_INT_BASE  )

#define HT_GPIOA             ((HT_GPIO_TypeDef   *) HT_GPIOA_BASE)
#define HT_GPIOB             ((HT_GPIO_TypeDef   *) HT_GPIOB_BASE)
#define HT_GPIOC             ((HT_GPIO_TypeDef   *) HT_GPIOC_BASE)
#define HT_GPIOD             ((HT_GPIO_TypeDef   *) HT_GPIOD_BASE)
#define HT_GPIOE             ((HT_GPIO_TypeDef   *) HT_GPIOE_BASE)
#define HT_GPIOHDPORT        (*((uint32_t        *) HT_HDPORT_BASE))            /*!< High current port setting       */
#if  defined  USE_GPIOF
#define HT_GPIOF             ((HT_GPIO_TypeDef   *) HT_GPIOF_BASE)
#endif
#if  defined  USE_GPIOG
#define HT_GPIOG             ((HT_GPIO_TypeDef   *) HT_GPIOG_BASE)
#endif
#if defined USE_GPIOH
#define HT_GPIOH             ((HT_GPIO_TypeDef   *) HT_GPIOH_BASE)
#endif
#if  defined USE_GPIOJ
#define HT_GPIOJ             ((HT_GPIO_TypeDef   *) HT_GPIOJ_BASE)
#endif
#if  defined  USE_GPIOI
#define HT_GPIOI             ((HT_GPIO_TypeDef   *) HT_GPIOI_BASE)
#endif

#if  defined USE_EMU_NORMAL
#define HT_EMUEPA            ((HT_EMU_EPR_TypeDef*) HT_EMU_EPA_BASE)
#define HT_EMUECA            ((HT_EMU_ECR_TypeDef*) HT_EMU_ECA_BASE)
#endif
#if defined USE_KEYSCAN
#define HT_KEY               ((HT_KEY_TypeDef    *) HT_KEY_BASE  )
#endif

#if  defined  USE_EMU_RESAMPLE
#define HT_EMUEPA             ((HT_EMU_EPR_TypeDef*)            HT_EMU_EPA_BASE)
#define HT_EMUECA             ((HT_EMU_ECR_TypeDef*)            HT_EMU_ECA_BASE)
#define HT_FILTERECA          ((HT_FILTER_ECR_TypeDef*)         HT_FILTER_ECA_BASE)
#define HT_EWUECA             ((HT_EWU_ECR_TypeDef*)            HT_EWU_ECA_BASE)
#define HT_SYNCECA            ((HT_SYNC_ECR_TypeDef*)           HT_SYNC_ECA_BASE)
#define HT_ADCPLLECA          ((HT_ADCPLL_ECR_TypeDef*)         HT_ADCPLL_ECA_BASE)
#endif

#if  defined  USE_EMU_CONST
#define HT_EMU               ((HT_EMU_TypeDef    *) HT_EMU_BASE  )
#endif

#if  defined  USE_CRC  
#define HT_CRC               ((HT_CRC_TypeDef    *) HT_CRC_BASE  )
#endif

#if  defined USE_RAND  
#define HT_RAND              ((HT_RAND_TypeDef   *) HT_RAND_BASE )
#endif

#define HT_AES               ((HT_AES_TypeDef    *) HT_AES_BASE  )
#define HT_GHASH             ((HT_GHASH_TypeDef  *) HT_GHASH_BASE)

#define HT_DMA               ((HT_DMA_TypeDef    *) HT_DMA_BASE  )
#define HT_DMA_Channel0      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel0_BASE  )
#define HT_DMA_Channel1      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel1_BASE  )
#define HT_DMA_Channel2      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel2_BASE  )

#if defined USE_DMA_CH8 
#define HT_DMA_Channel3      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel3_BASE  )
#define HT_DMA_Channel4      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel4_BASE  )
#define HT_DMA_Channel5      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel5_BASE  )
#define HT_DMA_Channel6      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel6_BASE  )
#define HT_DMA_Channel7      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel7_BASE  )
#endif

#if  defined  USE_DMA_CH13
#define HT_DMA_Channel8      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel8_BASE  )
#define HT_DMA_Channel9      ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel9_BASE  )
#define HT_DMA_Channel10     ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel10_BASE )
#define HT_DMA_Channel11     ((HT_DMA_Channel_TypeDef*) HT_DMA_Channel11_BASE )
#define HT_DMA_Channel12     ((HT_FFTDMA_Channel_TypeDef*) HT_DMA_Channel12_BASE )
#endif

#if  defined USE_ECC_SOC  ||  defined USE_ECC_MCU
#define HT_ECC               ((HT_ECC_TypeDef    *) HT_ECC_BASE  )
#endif

#if  defined USE_FRAMPACK_5X  ||  defined  USE_FRAMPACK_7X
#define HT_FRAMPACK          ((HT_FRAMPACK_TypeDef  *) HT_FRAMPACK_BASE)
#endif

#if  defined USE_EMUIFACE_5X || defined USE_EMUIFACE_7X
#define HT_EMU_INTERFACE     ((HT_EMU_Interface_TypeDef  *) HT_EMU_INTERFACE_BASE)
#endif

#if  defined  USE_FFT
#define HT_FFT               ((HT_FFT_TypeDef  *) HT_FFT_BASE)
#endif

#define HT_INFO              ((HT_INFO_TypeDef *) (HT_INFO_BASE + 0x104U) )    /*!< RTC coefficient stored in Info  */


/*
**********************************************************************************************************
*                               Bits Definition For HT6x1x HT6x2x HT501x
**********************************************************************************************************
*/

/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of Timer Module
**********************************************************************************************************
*/
/************************  Bit definition for TMRCON register of HT_TMR_TypeDef  ************************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  TMR_TMRCON                              ((uint32_t)0x07ff)           /*!<  Timer control register    */
#elif defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRCON                              ((uint32_t)0x1fff)           /*!<   Timer control register   */
#else
#define  TMR_TMRCON                              ((uint32_t)0x00ff)           /*!<   Timer control register   */
#endif
#define  TMR_TMRCON_CNTEN                        ((uint32_t)0x0001)           /*!<  Timer counting function enable  */
#define  TMR_TMRCON_MODE                         ((uint32_t)0x0006)           /*!<  Timer working mode     */
#if  defined  HT6x1x  ||  defined  HT501x
#define  TMR_TMRCON_MODE_NONE                    ((uint32_t)0x0000)           /*!<Timer mode none       */
#define  TMR_TMRCON_MODE_PWM                     ((uint32_t)0x0002)           /*!<Timer mode pwm        */
#define  TMR_TMRCON_MODE_CAPTURE                 ((uint32_t)0x0004)           /*!<Timer mode capture    */
#define  TMR_TMRCON_MODE_COMPARE                 ((uint32_t)0x0006)           /*!<Timer mode compare    */
#elif  defined  HT6x2x || defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x || defined  HT503x  || defined HT502x  || defined HT633x
#define  TMR_TMRCON_MODE_RECORD                  ((uint32_t)0x0000)           /*!<Timer mode EventRecord*/
#define  TMR_TMRCON_MODE_PWM                     ((uint32_t)0x0002)           /*!<Timer mode pwm        */
#define  TMR_TMRCON_MODE_CAPTURE                 ((uint32_t)0x0004)           /*!<Timer mode capture    */
#define  TMR_TMRCON_MODE_TIMING                  ((uint32_t)0x0006)           /*!<Timer mode timing only*/
#endif
#define  TMR_TMRCON_CCMODE                       ((uint32_t)0x0008)           /*!<Capture/event trigger edge selection  */
#define  TMR_TMRCON_CCMODE_RISE                  ((uint32_t)0x0000)           /*!<Capture/event rising edge*/
#define  TMR_TMRCON_CCMODE_FALL                  ((uint32_t)0x0008)           /*!<Capture/event falling edge*/

#define  TMR_TMRCON_PWMC                         ((uint32_t)0x0030)           /*!<PWM counting method           */
#define  TMR_TMRCON_PWMC_UP                      ((uint32_t)0x0000)           /*!<PWM count up           */
#define  TMR_TMRCON_PWMC_DOWM                    ((uint32_t)0x0010)           /*!<PWM count down           */
#define  TMR_TMRCON_PWMC_CENTER                  ((uint32_t)0x0020)           /*!<PWM center alignment       */

#define  TMR_TMRCON_PWMHL                        ((uint32_t)0x0040)           /*!<PWM initial level selection       */
#define  TMR_TMRCON_PWMHL_HIGH                   ((uint32_t)0x0000)           /*!<PWM initial level is high         */
#define  TMR_TMRCON_PWMHL_LOW                    ((uint32_t)0x0040)           /*!<PWM initial level is low         */

#if  defined  HT6x1x  ||  defined  HT501x
#define  TMR_TMRCON_CMPMODE                      ((uint32_t)0x0080)           /*!<Output compare mode selection      */
#define  TMR_TMRCON_CMPMODE_0                    ((uint32_t)0x0000)           /*!<Output compare mode 0         */
#define  TMR_TMRCON_CMPMODE_1                    ((uint32_t)0x0080)           /*!<Output compare mode 1         */
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRCON_CLKSEL                       ((uint32_t)0x0700)           /*!<TMR5 clock source selection      */
#define  TMR_TMRCON_CLKSEL_LRC                   ((uint32_t)0x0000)           /*!<LRC               */
#define  TMR_TMRCON_CLKSEL_LF                    ((uint32_t)0x0100)           /*!<LF                */
#define  TMR_TMRCON_CLKSEL_HRC                   ((uint32_t)0x0200)           /*!<HRC               */
#define  TMR_TMRCON_CLKSEL_PLL                   ((uint32_t)0x0300)           /*!<PLL               */
#if  defined  HT6x2x  ||  defined  HT6x2xK
#define  TMR_TMRCON_CLKSEL_MEMS                  ((uint32_t)0x0400)           /*!<MEMS              */
#elif  defined  HT762x  ||  defined  HT772x  || defined  HT633x  
#define  TMR_TMRCON_CLKSEL_EXCLK                 ((uint32_t)0x0400)  	      /*!<Select external input clock       */
#endif 
#endif 

#if  defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRCON_CDMODE                     ((uint32_t)0x0800)            /*!<double edge capture mode control bit      */
#define  TMR_TMRCON_CDMODE_0                   ((uint32_t)0x0000)           /*!<Single edge capture                  */
#define  TMR_TMRCON_CDMODE_1                   ((uint32_t)0x0800)          /*!<Double edge capture                  */

#define  TMR_TMRCON_CDCLEAR                     ((uint32_t)0x1000)           /*!<Double-edge capture mode clear control bit    */
#define  TMR_TMRCON_CDCLEAR_0                   ((uint32_t)0x0000)           /*!<After double edge capture, the counter is not cleared to 0  */
#define  TMR_TMRCON_CDCLEAR_1                   ((uint32_t)0x1000)           /*!<After both edges are captured, the counter is cleared to 0*/
#endif

/*!<Only for timer4&5     */

/************************  Bit definition for TMRDIV register of HT_TMR_TypeDef  ************************/
#define  TMR_TMRDIV                            ((uint32_t)0xffff)           /*!<Prescaler register      */

/************************  Bit definition for TMRPRD register of HT_TMR_TypeDef  ************************/
#define  TMR_TMRPRD                            ((uint32_t)0xffff)           /*!<Period register        */

/************************  Bit definition for TMRCAP register of HT_TMR_TypeDef  ************************/
#define  TMR_TMRCAP                            ((uint32_t)0xffff)           /*!<Capture data register    */

/************************  Bit definition for TMRCNT register of HT_TMR_TypeDef  ************************/
#define  TMR_TMRCNT                            ((uint32_t)0xffff)           /*!<Counter register      */

/************************  Bit definition for TMRCMP register of HT_TMR_TypeDef  ************************/
#define  TMR_TMRCMP                            ((uint32_t)0xffff)           /*!<Comparator register      */

/************************  Bit definition for TMRIE register of HT_TMR_TypeDef   ************************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT503x || defined  HT502x
#define  TMR_TMRIE                             ((uint32_t)0x000f)           /*!<TMR  Interrupt enable        */
#elif defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRIE                             ((uint32_t)0x001f)           /*!<TMR  Interrupt enable          */
#else
#define  TMR_TMRIE                             ((uint32_t)0x0007)           /*!<TMR  Interrupt enable          */
#endif
#define  TMR_TMRIE_PRDIE                         ((uint32_t)0x0001)           /*!<Periodic interrupt enable          */
#define  TMR_TMRIE_CAPIE                         ((uint32_t)0x0002)           /*!<Capture interrupt enable          */
#define  TMR_TMRIE_CMPIE                         ((uint32_t)0x0004)           /*!<Compare interrupt enable          */
#if  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined  HT503x || defined  HT633x
#define  TMR_TMRIE_ACIE                          ((uint32_t)0x0008)           /*!<Event record interrupt enable     */
#endif
#if defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRIE_TRIGIE                         ((uint32_t)0x0010)           /*!<External trigger interrupt enable    */
#endif

/************************  Bit definition for TMRIF register of HT_TMR_TypeDef   ************************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT503x || defined  HT502x
#define  TMR_TMRIF                             ((uint32_t)0x000f)           /*!<TMR interrupt flag         */
#elif defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRIF                             ((uint32_t)0x001f)           /*!<TMR interrupt flag          */
#else
#define  TMR_TMRIF                              ((uint32_t)0x0007)           /*!<TMR interrupt flag          */
#endif
#define  TMR_TMRIF_PRDIF                         ((uint32_t)0x0001)           /*!<Periodic interrupt flag          */
#define  TMR_TMRIF_CAPIF                         ((uint32_t)0x0002)           /*!<Capture interrupt flag          */
#define  TMR_TMRIF_CMPIF                         ((uint32_t)0x0004)           /*!<Compare interrupt flag          */
#if  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined  HT503x || defined  HT633x
#define  TMR_TMRIF_ACIF                          ((uint32_t)0x0008)           /*!<Event record flag       */
#endif
#if defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRIF_TRIGIF                        ((uint32_t)0x0010)           /*!<External trigger  flag     */
#define  TMR_TMRIF_CCSTA                         ((uint32_t)0x0100)           /*!<Capture  trigger statue  flag     */

#endif
/************************  Bit definition for TMRCODT register of HT_TMR_TypeDef   ************************/
#if  defined  HT6x3x || defined  HT633x
#define  TMR_TMRCODT                             ((uint32_t)0x0003)            /*!<PWM output mode and dead zone setting */
#define  TMR_TMRCODT_SYNC_OUT                    ((uint32_t)0x0000)           /*!<PWM synchronous output mode       */
#define  TMR_TMRCODT_COMP_OUT                    ((uint32_t)0x0001)           /*!<PWM complementary output mode       */
#define  TMR_TMRCODT_DT_LL                       ((uint32_t)0x0000)           /*!<PWM dead time polarity is low     */
#define  TMR_TMRCODT_DT_HL                       ((uint32_t)0x0002)           /*!<PWM dead time polarity is high     */
#endif

/************************  Bit definition for TMRDT register of HT_TMR_TypeDef   ************************/
#if  defined  HT6x3x || defined  HT633x
#define  TMR_TMRDT                               ((uint32_t)0x3fff)           /*!< PWM Dead Time Register    */
#endif

/************************  Bit definition for TMRTRIGERCFG register of HT_TMR_TypeDef   ************************/
#if defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRTRIGERCFG                        ((uint32_t)0x01e7)            /*!<Timer trigger source configuration register */

#define  TMR_TMRTRIGERCFG_TRIGRSEL               ((uint32_t)0x0007)            /*!<Timer 5 extended input source selection */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_INT0          ((uint32_t)0x0000)            /*!<Timer 5 extended input source selection is INT0 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_INT1          ((uint32_t)0x0001)            /*!<Timer 5 extended input source selection is INT1 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_INT2          ((uint32_t)0x0002)            /*!<Timer 5 extended input source selection is INT2*/
#define  TMR_TMRTRIGERCFG_TRIGRSEL_INT3          ((uint32_t)0x0003)            /*!<Timer 5 extended input source selection is INT3 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_RX0           ((uint32_t)0x0004)            /*!<Timer 5 extended input source selection is RX0 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_RX1           ((uint32_t)0x0005)            /*!<Timer 5 extended input source selection is RX1 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_RX2           ((uint32_t)0x0006)            /*!<Timer 5 extended input source selection is RX2 */
#define  TMR_TMRTRIGERCFG_TRIGRSEL_RX3           ((uint32_t)0x0007)            /*!<Timer 5 extended input source selection is RX3 */

#define  TMR_TMRTRIGERCFG_EXTRIG_EN              ((uint32_t)0x0020)           /*!<Extended input source enable control bit     */

#define  TMR_TMRTRIGERCFG_FILTERSEL              ((uint32_t)0x00C0)           /*!<Input signal source filter selection bit    */
#define  TMR_TMRTRIGERCFG_FILTERSEL_0            ((uint32_t)0x0000)           /*!<Select the number of filtered clocks to be 0        */
#define  TMR_TMRTRIGERCFG_FILTERSEL_2            ((uint32_t)0x0040)           /*!<Select the number of filtered clocks to be 2        */
#define  TMR_TMRTRIGERCFG_FILTERSEL_5            ((uint32_t)0x0080)           /*!<Select the number of filtered clocks to be 5        */
#define  TMR_TMRTRIGERCFG_FILTERSEL_11           ((uint32_t)0x00C0)           /*!<Select the number of filtered clocks to be 11       */

#define  TMR_TMRTRIGERCFG_TMR_MODE_SEL           ((uint32_t)0x0100)           /*!<TMR5 asynchronous read CNT mode control bit*/
#define  TMR_TMRTRIGERCFG_TMR_MODE_SEL_ASYN_READ ((uint32_t)0x0000)           /*!<Read without synchronization logic   */
#define  TMR_TMRTRIGERCFG_TMR_MODE_SEL_SYNC_READ ((uint32_t)0x0100)           /*!<Use synchronous logic for reading     */
#endif

/************************  Bit definition for TMRCFG register of HT_TMR_TypeDef   ************************/
#if defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMRCFG                              ((uint32_t)0x0001)           /*!< TMR single counting function control bit   */

#define  TMR_TMRCFG_ONCE                         ((uint32_t)0x0001)           /*!< TMR single counting function control bit   */
#define  TMR_TMRCFG_ONCE_DISABLE                 ((uint32_t)0x0000)           /*!< disabled One pulse mode*/
#define  TMR_TMRCFG_ONCE_ENABLE                  ((uint32_t)0x0001)           /*!< Enable One pulse mode*/

#endif

/************************  Bit definition for TMREXTRIGCFG register of HT_TMR_TypeDef   ************************/
#if defined  HT762x  ||  defined  HT772x || defined  HT633x
#define  TMR_TMREXTRIGCFG                       ((uint32_t)0x830F)            /*!<Timer trigger source configuration register */

#define  TMR_TMREXTRIGCFG_TRIGERSEL              ((uint32_t)0x000F)           /*!<Timer trigger signal source selection control bit */
#define  TMR_TMREXTRIGCFG_TRIGERSEL_INT0         ((uint32_t)0x0000)           /*!<Trigger signal source selection is INT0       */
#define  TMR_TMREXTRIGCFG_TRIGERSEL_INT3         ((uint32_t)0x0001)           /*!<Trigger signal source selection is INT3       */
#define  TMR_TMREXTRIGCFG_TRIGERSEL_RX0          ((uint32_t)0x0002)           /*!<Trigger signal source selection is RX0        */
#define  TMR_TMREXTRIGCFG_TRIGERSEL_RX3          ((uint32_t)0x0003)           /*!<Trigger signal source selection is RX3        */
#if defined HT633x
#define  TMR_TMREXTRIGCFG_TRIGERSEL_LPRX0        ((uint32_t)0x0004)           /*!<Trigger signal source selection is LPRX0     */ 
#endif

#define  TMR_TMREXTRIGCFG_TRIGERSEL_RTCTMR2_PRD  ((uint32_t)0x0005)           /*!<Trigger signal source selection is the timing interrupt of RTCTMR2 */

#if defined HT633x 
#define  TMR_TMREXTRIGCFG_TRIGERSEL_TMR0_PRD     ((uint32_t)0x0006)            /*!<Trigger signal source selection is TMR0_PRD    */
#endif

#define  TMR_TMREXTRIGCFG_TRIGERSEL_TMR5_CMP     ((uint32_t)0x0007)           /*!<The trigger signal source is selected as the comparison interrupt of TMR5    */
#define  TMR_TMREXTRIGCFG_TRIGERSEL_TOUT         ((uint32_t)0x0008)           /*!<Trigger signal source selection is  TOUT       */

#define  TMR_TMREXTRIGCFG_TRIGMODE               ((uint32_t)0x0300)           /*!<Trigger level edge selection         */
#define  TMR_TMREXTRIGCFG_TRIGMODE_RISE          ((uint32_t)0x0000)           /*!<Rising edge                   */
#define  TMR_TMREXTRIGCFG_TRIGMODE_FALL          ((uint32_t)0x0100)           /*!<falling edge                   */
#define  TMR_TMREXTRIGCFG_TRIGMODE_DOUBLE        ((uint32_t)0x0200)           /*!<Rising/falling edge              */

#define  TMR_TMREXTRIGCFG_TMRTRIG_EN             ((uint32_t)0x8000)           /*!<External trigger enable control bit       */
#endif


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of UART Module
**********************************************************************************************************
*/
/************************  Bit definition for MODESEL register of HT_UART_TypeDef ***********************/
#define  UART_MODESEL                            ((uint32_t)0x0001)           /*!<Serial port function selection    */
#define  UART_MODESEL_UART                       ((uint32_t)0x0000)           /*!<Select the UART function         */
#define  UART_MODESEL_7816                       ((uint32_t)0x0001)           /*!<Select the ISO7816 function           */
                                                                              /*!<Uart3&4 only          */
/************************  Bit definition for UARTCON register of HT_UART_TypeDef ***********************/
#if  defined USE_UARTCON
#define  UART_UARTCON                            ((uint32_t)0x87ff)           /*!<Uart control register        */
#elif defined USE_UARTCON1
#define  UART_UARTCON                            ((uint32_t)0x07ff)           /*!<Uart control register          */
#elif defined USE_UARTCON3
#define UART_UARTCON                             ((uint32_t)0xC7ff)           /*!<Uart control register        */   
#else
#define  UART_UARTCON                            ((uint32_t)0x03ff)           /*!<Uart control register          */
#endif
#define  UART_UARTCON_TXEN                       ((uint32_t)0x0001)           /*!<Uart send enable          */
#define  UART_UARTCON_RXEN                       ((uint32_t)0x0002)           /*!<Uart receive enable         */
#define  UART_UARTCON_TXIE                       ((uint32_t)0x0004)           /*!<Uart send interrupt enable        */
#define  UART_UARTCON_RXIE                       ((uint32_t)0x0008)           /*!<Uart receive interrupt enable      */
#define  UART_UARTCON_PARITYEN                   ((uint32_t)0x0010)           /*!<Uart  enable parity      */

#define  UART_UARTCON_PARITYSEL                  ((uint32_t)0x0060)           /*!<Uart parity select      */
#define  UART_UARTCON_PARITYSEL_1                ((uint32_t)0x0060)           /*!<The parity bit is always one     */
#define  UART_UARTCON_PARITYSEL_0                ((uint32_t)0x0000)           /*!<The parity bit is always zero     */
#define  UART_UARTCON_PARITYSEL_ODD              ((uint32_t)0x0020)           /*!<The parity bit is ODD      */
#define  UART_UARTCON_PARITYSEL_EVEN             ((uint32_t)0x0040)           /*!<The parity bit is EVEN      */

#define  UART_UARTCON_LENSEL                     ((uint32_t)0x0080)           /*!<UART data length bit        */
#define  UART_UARTCON_LENSEL_7Bit                ((uint32_t)0x0080)           /*!<Seven data bits */
#define  UART_UARTCON_LENSEL_8Bit                ((uint32_t)0x0000)           /*!<Eight data bits */

#define  UART_UARTCON_STOPSEL                    ((uint32_t)0x0100)           /*!<UART stop bit        */
#define  UART_UARTCON_STOPSEL_2Bit               ((uint32_t)0x0100)           /*!<Two stop bit    */
#define  UART_UARTCON_STOPSEL_1Bit               ((uint32_t)0x0000)           /*!<One stop bit    */

#define  UART_UARTCON_UNEG                       ((uint32_t)0x0200)           /*!<UART communication logic bit   */
#define  UART_UARTCON_UNEG_NEGETIVE              ((uint32_t)0x0200)           /*!<UART communications select negative logic      */
#define  UART_UARTCON_UNEG_POSITIVE              ((uint32_t)0x0000)           /*!<UART communications select positive logic      */

#if  defined 	USE_UARTCON2
#define  UART_UARTCON_UNEG_AUTO                  ((uint32_t)0x0400)           /*!<Automatic judgment of UART communication selection and receiving logic  */
#define  UART_UARTCON_PRDIE                      ((uint32_t)0x8000)           /*!<The UART overflow interrupt function is enabled      */
#endif

#if  defined 	USE_UARTCON3
#define  UART_UARTCON_UNEG_AUTO                  ((uint32_t)0x0400)           /*!<Automatic judgment of UART communication selection and receiving logic  */
#define  UART_UARTCON_NEG_RXIE                   ((uint32_t)0x4000)           /*!<Negative logic receiving completes the interrupt enable control bit  */
#define  UART_UARTCON_PRDIE                      ((uint32_t)0x8000)           /*!<The UART overflow interrupt function is enabled      */
#endif

#if  defined  USE_UARTCON_NEG
#define  UART_UARTCON_NEGFIX                     ((uint32_t)0x0400)           /*!<Uart commubication logic locking bit    */
#define  UART_UARTCON_NEGFIX_BYHARDWARE          ((uint32_t)0x0400)           /*!<The UART communication logic is configured by the hardware */
#define  UART_UARTCON_NEGFIX_BYSOFTWARE          ((uint32_t)0x0000)           /*!<The UART communication logic is configured by the software */
#endif

/**********************  Bit definition for ISO7816CON register of HT_UART_TypeDef **********************/
#define  UART_ISO7816CON                         ((uint32_t)0x03ff)           /*!<ISO7816 control register     */

#define  UART_ISO7816CON_IEALL                   ((uint32_t)0x0007)           /*!<ISO7816 interrupt enable     */
#define  UART_ISO7816CON_TXIE                    ((uint32_t)0x0001)           /*!<send interrupt enable        */
#define  UART_ISO7816CON_RXIE                    ((uint32_t)0x0002)           /*!<Receive interrupt enable        */
#define  UART_ISO7816CON_PRDIE                   ((uint32_t)0x0004)           /*!<Overflow interrupt enable        */

#define  UART_ISO7816CON_ACKLEN                  ((uint32_t)0x0018)           /*!<ACKLEN control bit    */
#define  UART_ISO7816CON_ACKLEN_1Bit             ((uint32_t)0x0000)           /*!<ACK bit length is 1Bit        */
#define  UART_ISO7816CON_ACKLEN_1P5Bit           ((uint32_t)0x0008)           /*!<ACK bit length is 1.5Bit     */
#define  UART_ISO7816CON_ACKLEN_2Bit             ((uint32_t)0x0010)           /*!<ACK bit length is 2Bit       */

#define  UART_ISO7816CON_REPTR                   ((uint32_t)0x0060)           /*!<Maximum number of automatic resending times  */
#define  UART_ISO7816CON_REPTR_0                 ((uint32_t)0x0000)           /*!<Set the automatic resend times to 0        */
#define  UART_ISO7816CON_REPTR_1                 ((uint32_t)0x0020)           /*!<Set the automatic resend times to 1       */
#define  UART_ISO7816CON_REPTR_2                 ((uint32_t)0x0040)           /*!<Set the automatic resend times to 2        */
#define  UART_ISO7816CON_REPTR_3                 ((uint32_t)0x0060)           /*!<Set the automatic resend times to 3       */

#define  UART_ISO7816CON_AUTOTXEN                ((uint32_t)0x0080)           /*!<Automatic resend enable bit       */
#define  UART_ISO7816CON_AUTORXEN                ((uint32_t)0x0100)           /*!<Automatic resend enable bit        */

#define  UART_ISO7816CON_7816PARITY              ((uint32_t)0x0200)           /*!<Parity selection bit        */
#define  UART_ISO7816CON_7816PARITY_ODD          ((uint32_t)0x0200)           /*!<ODD                */
#define  UART_ISO7816CON_7816PARITY_EVEN         ((uint32_t)0x0000)           /*!<EVEN               */
                                                                              /*!<Uart3&4 only          */
/*************************  Bit definition for SREL register of HT_UART_TypeDef *************************/
#if defined USE_UART_SREL
#define  UART_SREL                               ((uint32_t)0xffffff)           /*!<Serial port baud rate generator      */
#else
#define  UART_SREL                               ((uint32_t)0xffff)           /*!<Serial port baud rate generator      */
#endif
/*************************  Bit definition for SBUF register of HT_UART_TypeDef *************************/
#define  UART_SBUF                               ((uint32_t)0x00ff)           /*!<Serial port data buffer register    */

/************************  Bit definition for UARTSTA register of HT_UART_TypeDef ***********************/
#if  defined USE_UARTSTA
#define  UART_UARTSTA                            ((uint32_t)0x001f)           /*!<uart status register        */
#elif defined USE_UARTSTA2
#define  UART_UARTSTA                            ((uint32_t)0x003f)           /*!<uart status register        */
#else
#define  UART_UARTSTA                            ((uint32_t)0x0007)           /*!<uart status register         */
#endif
#define  UART_UARTSTA_TXIF                       ((uint32_t)0x0001)           /*!<Send interrupt flag         */
#define  UART_UARTSTA_RXIF                       ((uint32_t)0x0002)           /*!<Receive interrupt flag           */
#define  UART_UARTSTA_PARITY                     ((uint32_t)0x0004)           /*!<Parity interrupt flag      */
#if  defined USE_UARTSTA1
#define  UART_UARTSTA_PRDIF                      ((uint32_t)0x0008)           /*!<Receive the overflow interrupt flag      */

#define  UART_UARTSTA_POLASTA                    ((uint32_t)0x0010)           /*!<Polar state bit            */
#define  UART_UARTSTA_POLASTA_POSITIVE           ((uint32_t)0x0000)           /*!<Polarity is positive          */
#define  UART_UARTSTA_POLASTA_NEGETIVE           ((uint32_t)0x0010)           /*!<Polarity is negetive          */
#endif

#if  defined USE_UARTSTA2
#define  UART_UARTSTA_PRDIF                      ((uint32_t)0x0008)           /*!<Receive the overflow interrupt flag      */

#define  UART_UARTSTA_POLASTA                    ((uint32_t)0x0010)           /*!<Polar state bit            */
#define  UART_UARTSTA_POLASTA_POSITIVE           ((uint32_t)0x0000)           /*!<Polarity is positive          */
#define  UART_UARTSTA_POLASTA_NEGETIVE           ((uint32_t)0x0010)           /*!<Polarity is negetive          */
#define  UART_UARTSTA_NEG_RXIF                   ((uint32_t)0x0020)           /*!<Negative logic receive complete interrupt flag          */
#endif

/**********************  Bit definition for ISO7816STA register of HT_UART_TypeDef **********************/
#define  UART_ISO7816STA                         ((uint32_t)0x001f)           /*!<7816status register         */
#define  UART_ISO7816STA_TXIF                    ((uint32_t)0x0001)           /*!<Send interrupt flag           */
#define  UART_ISO7816STA_RXIF                    ((uint32_t)0x0002)           /*!<Receive interrupt flag          */
#define  UART_ISO7816STA_PRDIF                   ((uint32_t)0x0004)           /*!<Receive the overflow interrupt flag      */
#define  UART_ISO7816STA_TXERRSTAT               ((uint32_t)0x0008)           /*!<Send data error flag      */
#define  UART_ISO7816STA_RXERRSTAT               ((uint32_t)0x0010)           /*!<Receive data error flag      */
                                                                              /*!<Uart3&4 only          */
/*************************  Bit definition for IRCON register of HT_UART_TypeDef ************************/
#if  defined USE_IRCON
#define  UART_IRCON                              ((uint32_t)0x0007)           /*!<IR control register   */
#elif defined USE_IRCON1                         
#define  UART_IRCON                              ((uint32_t)0x000F)           /*!<IR control register   */
#else
#define  UART_IRCON                              ((uint32_t)0x0003)           /*!<IR control register器   */
#endif

#define  UART_IRCON_IRTX                         ((uint32_t)0x0001)           /*!<IR enable control   */

#define  UART_IRCON_IRLVL                        ((uint32_t)0x0002)           /*!<IR modulation output polarity selection  */
#define  UART_IRCON_IRLVL_NEGETIVE               ((uint32_t)0x0002)           /*!<NEGETIVE                 */
#define  UART_IRCON_IRLVL_POSITIVE               ((uint32_t)0x0000)           /*!<UART_IRCON_IRLVL_POSITIVE                */

#if  defined  USE_UART_IRCON_IR38KSOURCE
#define  UART_IRCON_IR38KSOURCE                  ((uint32_t)0x0004)           /*!<IR modulation signal source selection  */
#define  UART_IRCON_IR38KSOURCE_HRC              ((uint32_t)0x0004)           /*!<Select HRC             */
#define  UART_IRCON_IR38KSOURCE_PLL              ((uint32_t)0x0000)           /*!<Select PLL             */
#endif

#if  defined  USE_UART_IR38KSOURCE
#define  UART_IRCON_IR38KSOURCE                  ((uint32_t)0x0004)           /*!<IR modulation signal source selection  */
#define  UART_IRCON_IR38KSOURCE_HRC              ((uint32_t)0x0004)           /*!<Select HRC             */
#define  UART_IRCON_IR38KSOURCE_PLLX2            ((uint32_t)0x0000)           /*!<Select PLLX2             */
#endif

/*************************  Bit definition for IRDUTY register of HT_UART_TypeDef ***********************/
#define  UART_IRDUTY                             ((uint32_t)0x0003)           /*!<IR modulation pulse width register    */
#define  UART_IRDUTY_IRDUTY                      ((uint32_t)0x0003)           /*!<Modulation waveform duty cycle setting    */
#define  UART_IRDUTY_IRDUTY_50                   ((uint32_t)0x0000)           /*!<IR waveform duty cycle 50%  */
#define  UART_IRDUTY_IRDUTY_25                   ((uint32_t)0x0001)           /*!<IR waveform duty cycle 25%      */
#define  UART_IRDUTY_IRDUTY_12P5                 ((uint32_t)0x0002)           /*!<IR waveform duty cycle 12.5%    */
#define  UART_IRDUTY_IRDUTY_6P25                 ((uint32_t)0x0003)           /*!<IR waveform duty cycle 6.25%   */

/************************  Bit definition for NEGDETLEN register of HT_UART_TypeDef *********************/
#if  defined USE_UART_NEGDETLEN 
#define  UART_NEGDETLEN                        ((uint32_t)0xffff)           /*!<Set the logiacal judgment duration     */
#endif

/************************  Bit definition for NEGDETLEN register of HT_UART_TypeDef *********************/
#if  defined  USE_UART_IRCLKDIV
#define  UART_IRCLKDIV                         ((uint32_t)0x007f)           /*!<Predivision of 38K signal       */
#endif


#if  defined  USE_UART_IR38KDIV
#define  UART_IR38KDIV                         ((uint32_t)0x00ff)           /*!<Predivision of 38K signal       */
#endif



/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of I2C Module
**********************************************************************************************************
*/
/*************************  Bit definition for I2CDAT register of HT_I2C_TypeDef ************************/
#define  I2C_I2CDAT                            ((uint32_t)0x00ff)           /*!<I2C Data Register        */

/*************************  Bit definition for I2CADR register of HT_I2C_TypeDef ************************/
#define  I2C_I2CADR                            ((uint32_t)0x00ff)           /*!<I2C addres register         */

/*************************  Bit definition for I2CCON register of HT_I2C_TypeDef ************************/
#define  I2C_I2CCON                              ((uint32_t)0x7fff)           /*!<I2C Control Register     */
#define  I2C_I2CCON_AA                           ((uint32_t)0x0004)           /*!<I2C ACK Generation Bit   */
#define  I2C_I2CCON_SI                           ((uint32_t)0x0008)           /*!<I2C Interrupt Flag       */
#define  I2C_I2CCON_STO                          ((uint32_t)0x0010)           /*!<I2C Stop Generation Bit  */
#define  I2C_I2CCON_STA                          ((uint32_t)0x0020)           /*!<I2C Start Generation Bit */
#define  I2C_I2CCON_ENS1                         ((uint32_t)0x0040)           /*!<I2C Module Enable Bit    */
#define  I2C_I2CCON_CR                           ((uint32_t)0x7f83)           /*!<I2C Clock Generation Register    */

/*************************  Bit definition for I2CSTA register of HT_I2C_TypeDef ************************/
#define  I2C_I2CSTA                            ((uint32_t)0x00f8)           /*!<I2C Status Register         */


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of SPI Module
**********************************************************************************************************
*/
/*************************  Bit definition for SPICON register of HT_SPI_TypeDef ************************/
#if defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
#define  SPI_SPICON                              ((uint32_t)0x03ff)           /*!<SPI Control Register  */
#elif defined  HT633x
#define  SPI_SPICON                              ((uint32_t)0x01ff)           /*!<SPI Control Register  */
#else
#define  SPI_SPICON                              ((uint32_t)0x00ff)           /*!<SPI Control Register  */
#endif

#define  SPI_SPICON_SPIEN                        ((uint32_t)0x0001)           /*!<SPI Module Enable Bit */
#define  SPI_SPICON_MSTR                         ((uint32_t)0x0002)           /*!<SPI Master/Slave Mode Selection Bit */
#define  SPI_SPICON_CPOL                         ((uint32_t)0x0004)           /*!<SPI Clock Polarity Selection Bit    */
#define  SPI_SPICON_CPHA                         ((uint32_t)0x0008)           /*!<SPI Clock Phase Selection Bit       */

#define  SPI_SPICON_SPR                          ((uint32_t)0x0070)           /*!<SPI Clock Rate Control Bits */
#define  SPI_SPICON_SPR_FSYSDIV2                 ((uint32_t)0x0000)           /*!<SPI Clock Rate Fsys/2 */
#define  SPI_SPICON_SPR_FSYSDIV4                 ((uint32_t)0x0010)           /*!<SPI Clock Rate Fsys/4 */
#define  SPI_SPICON_SPR_FSYSDIV8                 ((uint32_t)0x0020)           /*!<SPI Clock Rate Fsys/8 */
#define  SPI_SPICON_SPR_FSYSDIV16                ((uint32_t)0x0030)           /*!<SPI Clock Rate Fsys/16 */
#define  SPI_SPICON_SPR_FSYSDIV32                ((uint32_t)0x0040)           /*!<SPI Clock Rate Fsys/32 */
#define  SPI_SPICON_SPR_FSYSDIV64                ((uint32_t)0x0050)           /*!<SPI Clock Rate Fsys/64 */
#define  SPI_SPICON_SPR_FSYSDIV128               ((uint32_t)0x0060)           /*!<SPI Clock Rate Fsys/128 */
#define  SPI_SPICON_SPR_NONCLK                   ((uint32_t)0x0070)           /*!<SPI Clock Rate don't Generate Clk */

#define  SPI_SPICON_SSDIS                        ((uint32_t)0x0080)           /*!<SPI_SS Control Bit                  */

#if defined  HT762x  ||  defined  HT772x  ||  defined  HT503x  ||   defined  HT633x
#define  SPI_SPICON_LSBEN                        ((uint32_t)0x0100)           /*!<SPI Size Control Bit                */
#define  SPI_SPICON_LSBEN_MSB                    ((uint32_t)0x0000)           /*!<SPI MSB in the front                */
#define  SPI_SPICON_LSBEN_LSB                    ((uint32_t)0x0100)           /*!<SPI LSB in the front                */
#endif

#if defined  HT503x  
#define  SPI_SPICON_FASTEN                       ((uint32_t)0x0200)           /*!<Slave Fast Mode Enable Control Bit */
#endif

/*************************  Bit definition for SPISTA register of HT_SPI_TypeDef ************************/
#define  SPI_SPISTA                              ((uint32_t)0x000f)           /*!<SPI Status Register    */
#define  SPI_SPISTA_MODF                         ((uint32_t)0x0001)           /*!<SPI Mode Fault Flag Bit     */
#define  SPI_SPISTA_SSERR                        ((uint32_t)0x0002)           /*!<SPI Slave Synchronization Error Flag Bit */
#define  SPI_SPISTA_WCOL                         ((uint32_t)0x0004)           /*!<SPI Writes Conflicting Flag Bit       */
#define  SPI_SPISTA_SPIF                         ((uint32_t)0x0008)           /*!<SPI Data Transfer Completion Flag Bit */

/*************************  Bit definition for SPIDAT register of HT_SPI_TypeDef ************************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  SPI_SPIDAT                              ((uint32_t)0xffff)           /*!<SPI Data Register         */
#define  SPI_SPIDAT_SPIDAT                       ((uint32_t)0x00ff)           /*!<SPI Data Output Bits      */
#define  SPI_SPIDAT_ITDelay                      ((uint32_t)0x0f00)           /*!<SPIDAT Delay Control Bits */
#define  SPI_SPIDAT_CSA                          ((uint32_t)0x3000)           /*!<SPI CS End Control Bits   */
#define  SPI_SPIDAT_CSB                          ((uint32_t)0xc000)           /*!<SPI CS Start Control Bits */
#else
#define  SPI_SPIDAT                              ((uint32_t)0x00ff)           /*!<SPI Data Register         */
#endif

/*************************  Bit definition for SPISSN register of HT_SPI_TypeDef ************************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT633x 
#define  SPI_SPISSN                              ((uint32_t)0x00ff)           /*!<SPI Slave Selects Control Registers*/  
#define  SPI_SPISSN_SSN0                         ((uint32_t)0x0001)           /*!<SPI Slave Selection Control      */
#define  SPI_SPISSN_SSN1                         ((uint32_t)0x0002)           /*!<SPIDAT Control SPI_CS Enable Control(If support) */
#elif defined HT762x  ||  defined  HT772x  ||  defined HT503x  ||  defined  HT6x2xK       
#define  SPI_SPISSN                              ((uint32_t)0x00ff)           /*!<SPI Slave Selects Control Registers*/  
#define  SPI_SPISSN_SSN0                         ((uint32_t)0x0001)           /*!<SPI_CS Master Controls high and low levels */
#define  SPI_SPISSN_SSN1                         ((uint32_t)0x0002)           /*!<SPIDAT control SPI_CS                      */
#define  SPI_SPISSN_MSAM                         ((uint32_t)0x00C0)           /*!<Master Samples Along the Back              */
#define  SPI_SPISSN_MSAM_0                       ((uint32_t)0x00C0)           /*!<Master Samples 0 CLKS Along the Back       */
#define  SPI_SPISSN_MSAM_1                       ((uint32_t)0x0080)           /*!<Master Samples 1 CLKS Along the Back       */
#define  SPI_SPISSN_MSAM_2                       ((uint32_t)0x0040)           /*!<Master Samples 2 CLKS Along the Back       */
#define  SPI_SPISSN_MSAM_3                       ((uint32_t)0x0000)           /*!<Master Samples 3 CLKS Along the Back       */
#else
#define  SPI_SPISSN_CS                           ((uint32_t)0x0001)           /*!<SPI Slave Selection Control       */
#endif

/*************************  Bit definition for CSDLY register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x  ||  defined  HT6x2xK       
#define  SPI_CSDLY                              ((uint32_t)0x00ff)           /*!<SPI CS DELAY Control Register       */
#define  SPI_CSDLY_ITDELAY                      ((uint32_t)0x000f)           /*!<DATA Send  Wait Time  to DMA        */

#define  SPI_CSDLY_CSA                          ((uint32_t)0x0030)           /*!<CS Maintains Control After Sending   */
#define  SPI_CSDLY_CSA_0                        ((uint32_t)0x0000)           /*!<CS Maintains 0 CLKS After Sending    */
#define  SPI_CSDLY_CSA_2                        ((uint32_t)0x0010)           /*!<CS Maintains 2 CLKS After Sending    */
#define  SPI_CSDLY_CSA_4                        ((uint32_t)0x0020)           /*!<CS Maintains 4 CLKS After Sending    */
#define  SPI_CSDLY_CSA_8                        ((uint32_t)0x0030)           /*!<CS Maintains 8 CLKS After Sending    */
#define  SPI_CSDLY_CSB                          ((uint32_t)0x00C0)           /*!<CS Maintains Control Before Sending  */
#define  SPI_CSDLY_CSB_0                        ((uint32_t)0x0000)           /*!<CS Maintains 0 CLKS Before Sending   */
#define  SPI_CSDLY_CSB_2                        ((uint32_t)0x0040)           /*!<CS Maintains 2 CLKS Before Sending   */
#define  SPI_CSDLY_CSB_4                        ((uint32_t)0x0080)           /*!<CS Maintains 4 CLKS Before Sending   */
#define  SPI_CSDLY_CSB_8                        ((uint32_t)0x00C0)           /*!<CS Maintains 8 CLKS Before Sending   */
#endif

/*************************  Bit definition for FIFOCON register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x      
#define  SPI_FIFOCON                      ((uint32_t)0x03fffff7)           /*!<FIFO Control Register          */
#define  SPI_FIFOCON_TXFIFO_EN            ((uint32_t)0x00000001)           /*!<FIFO Sending Enable Control     */
#define  SPI_FIFOCON_RXFIFO_EN            ((uint32_t)0x00000002)           /*!<FIFO Receiving Enable Control   */
#define  SPI_FIFOCON_FS_EN                ((uint32_t)0x00000004)           /*!<Enable Fast Slave With FIFO   */
#define  SPI_FIFOCON_TXFIFO_RST           ((uint32_t)0x00000010)           /*!<Send FIFO Write Reset   */
#define  SPI_FIFOCON_RXFIFO_RST           ((uint32_t)0x00000020)           /*!<Receive FIFO Write Reset  */

#define  SPI_FIFOCON_HLCS                 ((uint32_t)0x00000040)           /*!<CS State Control During BDLY Delay */
#define  SPI_FIFOCON_HLCS_LOW             ((uint32_t)0x00000000)           /*!<Set SPI_CS to Low */
#define  SPI_FIFOCON_HLCS_HIGH            ((uint32_t)0x00000040)           /*!<Set SPI_CS to High*/ 

#define  SPI_FIFOCON_EX_IN_SEL            ((uint32_t)0x00000080)           /*!<FIFO Data Source Control  */
#define  SPI_FIFOCON_EX_IN_SEL_APB        ((uint32_t)0x00000000)           /*!<FIFO Data is Written from APB   */
#define  SPI_FIFOCON_EX_IN_SEL_EXIN       ((uint32_t)0x00000080)           /*!<FIFO Data Source External Port   */

#define  SPI_FIFOCON_TXFIFO_TL            ((uint32_t)0x00001f00)           /*!<Send FIFO Threshold Setting    */
#define  SPI_FIFOCON_RXFIFO_TL            ((uint32_t)0x001f0000)           /*!<Receive FIFO threshold Setting  */

#define  SPI_FIFOCON_CTR                  ((uint32_t)0x03000000)           /*!<Fast Slave Mode Filter Control Bit   */
#if defined HT762x  ||  defined  HT772x
#define  SPI_FIFOCON_CTR_0                ((uint32_t)0x00000000)           /*!<Fast Slave Mode Filter 0ns  */
#endif
#define  SPI_FIFOCON_CTR_1P5              ((uint32_t)0x01000000)           /*!<Fast Slave Mode Filter 1.5ns   */
#define  SPI_FIFOCON_CTR_3P0              ((uint32_t)0x02000000)           /*!<Fast Slave Mode Filter 3 ns  */
#define  SPI_FIFOCON_CTR_4P5              ((uint32_t)0x03000000)           /*!<Fast Slave Mode Filter 4.5ns  */
#endif

/*************************  Bit definition for FIFOIE register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x   
#define  SPI_FIFOIE                      ((uint32_t)0x01ff)                /*!<FIFO Interrupt Enable Register   */
#define  SPI_FIFOIE_TXE_IE               ((uint32_t)0x0001)                /*!<Send FIFO Empty Interrupt        */
#define  SPI_FIFOIE_RXNE_IE              ((uint32_t)0x0002)                /*!<Receive FIFO Non-Empty Interrupt */
#define  SPI_FIFOIE_TXF_IE               ((uint32_t)0x0004)                /*!<Send FIFO Full Interrupt      */
#define  SPI_FIFOIE_RXF_IE               ((uint32_t)0x0008)                /*!<Receive FIFO Full Interrupt      */
#define  SPI_FIFOIE_TXO_IE               ((uint32_t)0x0010)                /*!<Send FIFO OverFlow Interrupt     */
#define  SPI_FIFOIE_RXO_IE               ((uint32_t)0x0020)                /*!<Receive FIFO Overflow Interrupt  */
#define  SPI_FIFOIE_TXT_IE               ((uint32_t)0x0040)                /*!<Send FIFO is Less Than or Equal to the Threshold Interrupt   */
#define  SPI_FIFOIE_RXT_IE               ((uint32_t)0x0080)                /*!<Receive FIFO Exceeds the Threshold  Interrupt  */
#define  SPI_FIFOIE_TXFIFO_DONE_IE       ((uint32_t)0x0100)                /*!<FIFO Data Transmission Interrupt  */
#endif

/*************************  Bit definition for FIFOIF register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x    
#define  SPI_FIFOIF                      ((uint32_t)0x01ff)                /*!<FIFO Interrupt Flag Register       */
#define  SPI_FIFOIF_TXE_IF               ((uint32_t)0x0001)                /*!<Send FIFO Empty Interrupt Flag Bit */
#define  SPI_FIFOIF_RXNE_IF              ((uint32_t)0x0002)                /*!<Receive FIFO non-Empty Interrupt Flag Bit */
#define  SPI_FIFOIF_TXF_IF               ((uint32_t)0x0004)                /*!<Send FIFO Full Interrupt  Flag Bit   */
#define  SPI_FIFOIF_RXF_IF               ((uint32_t)0x0008)                /*!<Receive FIFO Full Interrupt Flag Bit   */
#define  SPI_FIFOIF_TXO_IF               ((uint32_t)0x0010)                /*!<Send FIFO OverFlow Interrupt Flag Bit */
#define  SPI_FIFOIF_RXO_IF               ((uint32_t)0x0020)                /*!<Receive FIFO Overflow Interrupt Flag Bit   */
#define  SPI_FIFOIF_TXT_IF               ((uint32_t)0x0040)                /*!<Send FIFO is Less Than or Equal to the Threshold Interrupt Flag Bit */
#define  SPI_FIFOIF_RXT_IF               ((uint32_t)0x0080)                /*!<Receive FIFO Exceeds the Threshold Interrupt Flag Bit   */
#define  SPI_FIFOIF_TXFIFO_DONE_IF       ((uint32_t)0x0100)                /*!<FIFO Data Transmission Interrupt Interrupt Flag Bit     */
#endif

/*************************  Bit definition for BDLY register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x    
#define  SPI_BDLY                        ((uint32_t)0xffff)                 /*!<Interword Interval Delay Configuration Register         */
#endif

/*************************  Bit definition for RXFIFOSTA register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x     
#define  SPI_RXFIFOSTA                   ((uint32_t)0x00ff)                 /*!<Receive FIFO Status Register     */
#define  SPI_RXFIFOSTA_RXFIFO_CNT        ((uint32_t)0x003f)                 /*!<Receive FIFO Data Count           */
#endif

/*************************  Bit definition for TXFIFOSTA register of HT_SPI_TypeDef ************************/
#if defined HT762x  ||  defined  HT772x  ||  defined HT503x     
#define  SPI_TXFIFOSTA                    ((uint32_t)0x00ff)                /*!<Send FIFO Status Register     */
#define  SPI_TXFIFOSTA_TXFIFO_CNT         ((uint32_t)0x003f)                /*!<Send FIFO Data Count          */
#endif

/*************************  Bit definition for SPIDIV register of HT_SPI_TypeDef ************************/
#if  defined  HT6x3x
#define  SPI_SPIDIV                       ((uint32_t)0x008f)                 /*!<SPI Crossover Auxiliary Register   */
#define  SPI_SPIDIV_DIV                   ((uint32_t)0x000f)                 /*!<SPI Clock Rate Control Bit (for Master)     */
#define  SPI_SPIDIV_FSYSDIV3              ((uint32_t)0x0003)                 /*!<SPI Clock Rate Fsys/3 */
#define  SPI_SPIDIV_FSYSDIV5              ((uint32_t)0x0005)                 /*!<SPI Clock Rate Fsys/5 */
#define  SPI_SPIDIV_FSYSDIV6              ((uint32_t)0x0006)                 /*!<SPI Clock Rate Fsys/6 */
#define  SPI_SPIDIV_FSYSDIV7              ((uint32_t)0x0007)                 /*!<SPI Clock Rate Fsys/7 */
#define  SPI_SPIDIV_FSYSDIV9              ((uint32_t)0x0009)                 /*!<SPI Clock Rate Fsys/9 */

#define  SPI_SPICON_SPR_FSYSDIV3          ((uint32_t)0x0001)                 /*!<SPI Clock Rate Fsys/3 */
#define  SPI_SPICON_SPR_FSYSDIV5          ((uint32_t)0x0005)                 /*!<SPI Clock Rate Fsys/5*/
#define  SPI_SPICON_SPR_FSYSDIV6          ((uint32_t)0x0006)                 /*!<SPI Clock Rate Fsys/6*/
#define  SPI_SPICON_SPR_FSYSDIV7          ((uint32_t)0x0007)                 /*!<SPI Clock Rate Fsys/7*/
#define  SPI_SPICON_SPR_FSYSDIV9          ((uint32_t)0x0009)                 /*!<SPI Clock Rate Fsys/9*/

#define  SPI_SPIDAT_DIV_EN                ((uint32_t)0x0080)                 /*!<SPI Auxiliary Frequency Division Enable Bit */
#endif

#if  defined  HT633x
#define  SPI_SPICON_SPR_FSYSDIV3          ((uint32_t)0x0001)                 /*!<SPI Clock Rate Fsys/3 */
#define  SPI_SPICON_SPR_FSYSDIV5          ((uint32_t)0x0005)                 /*!<SPI Clock Rate Fsys/5*/
#define  SPI_SPICON_SPR_FSYSDIV6          ((uint32_t)0x0006)                 /*!<SPI Clock Rate Fsys/6*/
#define  SPI_SPICON_SPR_FSYSDIV7          ((uint32_t)0x0007)                 /*!<SPI Clock Rate Fsys/7*/
#define  SPI_SPICON_SPR_FSYSDIV9          ((uint32_t)0x0009)                 /*!<SPI Clock Rate Fsys/9*/

#define  SPI_SPIDIV                       ((uint32_t)0x00bf)                 /*!<SPI Crossover Auxiliary Register   */
#define  SPI_SPIDAT_DIV_EN                ((uint32_t)0x0080)                 /*!<SPI Auxiliary Frequency Division Enable Bit */

#define  SPI_SPIDIV_DIV                   ((uint32_t)0x000f)                 /*!<SPI Clock Rate Control Bit (for Master)     */
#define  SPI_SPIDIV_FSYSDIV3              ((uint32_t)0x0003)                 /*!<SPI Clock Rate Fsys/3 */
#define  SPI_SPIDIV_FSYSDIV5              ((uint32_t)0x0005)                 /*!<SPI Clock Rate Fsys/5 */
#define  SPI_SPIDIV_FSYSDIV6              ((uint32_t)0x0006)                 /*!<SPI Clock Rate Fsys/6 */
#define  SPI_SPIDIV_FSYSDIV7              ((uint32_t)0x0007)                 /*!<SPI Clock Rate Fsys/7 */
#define  SPI_SPIDIV_FSYSDIV9              ((uint32_t)0x0009)                 /*!<SPI Clock Rate Fsys/9 */

#define  SPI_SPIDIV_DLYSEL                ((uint32_t)0x0030)                 /*!<SPI Master Receive Delay Control Bit (for Master) */
#define  SPI_SPIDIV_DLYSEL_0T             ((uint32_t)0x0000)                 /*!<SPI Master Receive Delay 0T */
#define  SPI_SPIDIV_DLYSEL_1T             ((uint32_t)0x0010)                 /*!<SPI Master Receive Delay 1T */
#define  SPI_SPIDIV_DLYSEL_2T             ((uint32_t)0x0020)                 /*!<SPI Master Receive Delay 2T */
#define  SPI_SPIDIV_DLYSEL_3T             ((uint32_t)0x0030)                 /*!<SPI Master Receive Delay 2T */
#endif

/*************************  Bit definition for SPICLKSEL register of HT_SPI_TypeDef ************************/
#if  defined  HT6x3x
#define  SPI_SPICLKSEL                    ((uint32_t)0x00b0)                  /*!<SPI Module Clock Source Selection Register      */
#define  SPI_SPICLKSEL_SPICLK             ((uint32_t)0x0030)                  /*!<SPI Module Clock Source (Used in Compatible Mode)*/
#define  SPI_SPICLKSEL_SPICLK_OSC         ((uint32_t)0x0000)                  /*!<SPI Module Clock Select OSC (Used in Compatible Mode)*/
#define  SPI_SPICLKSEL_SPICLK_LRC         ((uint32_t)0x0010)                  /*!<SPI Module Clock Select LRC (Used in Compatible Mode)*/
#define  SPI_SPICLKSEL_SPICLK_HRC         ((uint32_t)0x0020)                  /*!<SPI Module Clock Select HRC (Used in Compatible Mode)*/
#define  SPI_SPICLKSEL_SPICLK_PLL         ((uint32_t)0x0030)                  /*!<SPI Module Clock Select PLL (Used in Compatible Mode)*/

#define  SPI_SPICLKSEL_SPIMODE            ((uint32_t)0x0080)                  /*!<SPI Working Mode Selection Bit                   */
#endif


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of RTC Module
**********************************************************************************************************
*/
/*************************  Bit definition for RTCCON register of HT_RTC_TypeDef ************************/
#if  defined  HT502x  ||  defined HT503x  
#define  RTC_RTCCON                              ((uint32_t)0x006f)           /*!<RTC Control Register    */
#else
#define  RTC_RTCCON                              ((uint32_t)0x007f)           /*!<RTC Control Register    */
#endif
#define  RTC_RTCCON_AUTOC                        ((uint32_t)0x0001)           /*!<Automatic Manual Compensation Selection Control  */

#if  defined  HT501x  ||  defined  HT502x  ||  defined HT503x  
#define  RTC_RTCCON_TOUT                         ((uint32_t)0x000E)           /*!<Tout Output Control               */
#define  RTC_RTCCON_TOUT_LOW                     ((uint32_t)0x0000)           /*!<Tout Output Low                   */
#define  RTC_RTCCON_TOUT_HIGH                    ((uint32_t)0x0002)           /*!<Tout Output High                  */
#define  RTC_RTCCON_TOUT_LF                      ((uint32_t)0x0004)           /*!<Tout Outputs Low Frequency Clocks */
#define  RTC_RTCCON_TOUT_1HZ                     ((uint32_t)0x0006)           /*!<Tout Output High Frequency Compensation 1Hz   */
#define  RTC_RTCCON_TOUT_2HZ                     ((uint32_t)0x0008)           /*!<Tout Output High Frequency Compensation 2Hz   */
#define  RTC_RTCCON_TOUT_4HZ                     ((uint32_t)0x000A)           /*!<Tout Output High Frequency Compensation 4Hz   */
#define  RTC_RTCCON_TOUT_8HZ                     ((uint32_t)0x000C)           /*!<Tout Output High Frequency Compensation 8Hz   */
#define  RTC_RTCCON_TOUT_RTC1HZ                  ((uint32_t)0x000E)           /*!<Tout Outputs Internal RTC1hz       */
#else
#define  RTC_RTCCON_TOUT                         ((uint32_t)0x001E)           /*!<Tout Output Control          */
#define  RTC_RTCCON_TOUT_LOW                     ((uint32_t)0x0000)           /*!<Tout Output Low          */
#define  RTC_RTCCON_TOUT_HIGH                    ((uint32_t)0x0002)           /*!<Tout Output High           */
#define  RTC_RTCCON_TOUT_LF                      ((uint32_t)0x0004)           /*!<Tout Outputs Low Frequency Clocks       */
#define  RTC_RTCCON_TOUT_1HZ                     ((uint32_t)0x0006)           /*!<Tout Output High Frequency Compensation 1Hz  */
#define  RTC_RTCCON_TOUT_2HZ                     ((uint32_t)0x0008)           /*!<Tout Output High Frequency Compensation 2Hz   */
#define  RTC_RTCCON_TOUT_4HZ                     ((uint32_t)0x000A)           /*!<Tout Output High Frequency Compensation 4Hz   */
#define  RTC_RTCCON_TOUT_8HZ                     ((uint32_t)0x000C)           /*!<Tout Output High Frequency Compensation 8Hz  */
#define  RTC_RTCCON_TOUT_16HZ                    ((uint32_t)0x000E)           /*!<Tout Output High Frequency Compensation 16Hz */
#define  RTC_RTCCON_TOUT_32HZ                    ((uint32_t)0x0010)           /*!<Tout Output High Frequency Compensation 32Hz  */
#define  RTC_RTCCON_TOUT_64HZ                    ((uint32_t)0x0012)           /*!<Tout Output High Frequency Compensation 64Hz  */
#define  RTC_RTCCON_TOUT_128HZ                   ((uint32_t)0x0014)           /*!<Tout Output High Frequency Compensation 128Hz*/
#endif

#define  RTC_RTCCON_RTC1EN                       ((uint32_t)0x0020)           /*!<RTC Timer1 Enable Bit */
#define  RTC_RTCCON_RTC2EN                       ((uint32_t)0x0040)           /*!<RTC Timer2 Enable Bit */

/*************************  Bit definition for RTCIE register of HT_RTC_TypeDef *************************/
#define  RTC_RTCIE                               ((uint32_t)0x00ff)           /*!<RTC Interrupt Enable Bits      */
#define  RTC_RTCIE_SECIE                         ((uint32_t)0x0001)           /*!<RTC Second Interrupt Enable bit */
#define  RTC_RTCIE_MINIE                         ((uint32_t)0x0002)           /*!<RTC Minute Interrupt Enable bit */
#define  RTC_RTCIE_HRIE                          ((uint32_t)0x0004)           /*!<RTC HOUR   Interrupt Enable bit */
#define  RTC_RTCIE_DAYIE                         ((uint32_t)0x0008)           /*!<RTC DAY    Interrupt Enable bit */
#define  RTC_RTCIE_MTHIE                         ((uint32_t)0x0010)           /*!<RTC MONTH  Interrupt Enable bit */
#define  RTC_RTCIE_RTC1IE                        ((uint32_t)0x0020)           /*!<RTC Timer1 Interrupt Enable bit */
#define  RTC_RTCIE_RTC2IE                        ((uint32_t)0x0040)           /*!<RTC Timer2 Interrupt Enable bit */
#define  RTC_RTCIE_ALMIE                         ((uint32_t)0x0080)           /*!<RTC Alarm  Interrupt Enable bit */

/*************************  Bit definition for RTCIF register of HT_RTC_TypeDef *************************/
#define  RTC_RTCIF                               ((uint32_t)0x00ff)           /*!<RTC Interrupt Flag Bits         */
#define  RTC_RTCIF_SECIF                         ((uint32_t)0x0001)           /*!<RTC Second Interrupt Flag bit   */
#define  RTC_RTCIF_MINIF                         ((uint32_t)0x0002)           /*!<RTC Minute Interrupt Flag bit   */
#define  RTC_RTCIF_HRIF                          ((uint32_t)0x0004)           /*!<RTC HOUR   Interrupt Flag bit   */
#define  RTC_RTCIF_DAYIF                         ((uint32_t)0x0008)           /*!<RTC DAY    Interrupt Flag bit   */
#define  RTC_RTCIF_MTHIF                         ((uint32_t)0x0010)           /*!<RTC MONTH  Interrupt Flag bit   */
#define  RTC_RTCIF_RTC1IF                        ((uint32_t)0x0020)           /*!<RTC Timer1 Interrupt Flag bit   */
#define  RTC_RTCIF_RTC2IF                        ((uint32_t)0x0040)           /*!<RTC Timer2 Interrupt Flag bit   */
#define  RTC_RTCIF_ALMIF                         ((uint32_t)0x0080)           /*!<RTC Alarm  Interrupt Flag bit   */

/*************************  Bit definition for ALMR register of HT_RTC_TypeDef **************************/
#define  RTC_ALMR                                ((uint32_t)0x1f3f)             /*!<RTC Alarm Register        */
#define  RTC_ALMR_ALMH                           ((uint32_t)0x1700)             /*!<RTC Alarm Hour   Setting  */  
#define  RTC_ALMR_ALMM                           ((uint32_t)0x003B)             /*!<RTC Alarm Minute Setting  */  

/************************  Bit definition for RTCTMR1 register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTMR1                             ((uint32_t)0xffff)             /*!<RTC Timer1 Register */

/************************  Bit definition for RTCTMR2 register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTMR2                             ((uint32_t)0xffff)             /*!<RTC Timer2 Register */

/**************************  Bit definition for SECR register of HT_RTC_TypeDef *************************/
#define  RTC_SECR                                ((uint32_t)0x003f)             /*!<RTC Second Register */

/**************************  Bit definition for MINR register of HT_RTC_TypeDef *************************/
#define  RTC_MINR                                ((uint32_t)0x003f)             /*!<RTC Minute Register */

/*************************  Bit definition for HOURR register of HT_RTC_TypeDef *************************/
#define  RTC_HOURR                               ((uint32_t)0x001f)             /*!<RTC Hour  Register  */

/**************************  Bit definition for DAYR register of HT_RTC_TypeDef *************************/
#define  RTC_DAYR                                ((uint32_t)0x001f)             /*!<RTC Day   Register  */

/*************************  Bit definition for MONTHR register of HT_RTC_TypeDef ************************/
#define  RTC_MONTHR                              ((uint32_t)0x000f)             /*!<RTC Month Register  */

/*************************  Bit definition for YEARR register of HT_RTC_TypeDef *************************/
#define  RTC_YEARR                               ((uint32_t)0x007f)             /*!<RTC Year  Register  */

/*************************  Bit definition for WEEKR register of HT_RTC_TypeDef *************************/
#define  RTC_WEEKR                               ((uint32_t)0x0007)             /*!<RTC Week  Register  */

/************************  Bit definition for RTCCNTH register of HT_RTC_TypeDef ************************/
#define  RTC_RTCCNTH                             ((uint32_t)0xffff)             /*!<RTC Calibration Register to High 16 bits */

/************************  Bit definition for RTCCNTL register of HT_RTC_TypeDef ************************/
#define  RTC_RTCCNTL                             ((uint32_t)0xffff)             /*!<RTC Calibration Register to Low  16 bits */

/*************************  Bit definition for RTCRD register of HT_RTC_TypeDef *************************/
#define  RTC_RTCRD_READFLAG                      ((uint32_t)0x0001)             /*!<RTC Read Control Bit*/

/*************************  Bit definition for RTCWR register of HT_RTC_TypeDef *************************/
#define  RTC_RTCWR_UPDATE                        ((uint32_t)0x0001)             /*!<RTC Write Control Bit       */
#define  RTC_RTCWR_CLEAR                         ((uint32_t)0x0000)             /*!<RTC Write Control Bit Clear */

/***********************  Bit definition for RTCRSTFLG register of HT_RTC_TypeDef ***********************/
#define  RTC_RTCRSTFLG_SOFTReset                 ((uint32_t)0x0001)             /*!<RTC Soft Reset Flag       */
#define  RTC_RTCRSTFLG_PORReset                  ((uint32_t)0x0002)             /*!<RTC Por  Reset Flag*/

/***********************  Bit definition for RTCRSTSET register of HT_RTC_TypeDef ***********************/
#define  RTC_RTCRSTSET                           ((uint32_t)0xffff)             /*!<RTC Write Reset Register  */

/***********************  Bit definition for RTCCHKSUM register of HT_RTC_TypeDef ***********************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  RTC_RTCCHKSUM                           ((uint32_t)0xffff)             /*!<RTC Checksum Register      */
#endif
#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x 
#define  RTC_RTCCHKSUM                           ((uint32_t)0xffffffff)         /*!<RTC Checksum Register      */
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK
/**************************  Bit definition for SECR2 register of HT_RTC_TypeDef ************************/
#define  RTC_SECR2                               ((uint32_t)0x003f)             /*!<RTC2 Second Register       */

/**************************  Bit definition for MINR2 register of HT_RTC_TypeDef ************************/
#define  RTC_MINR2                               ((uint32_t)0x003f)             /*!<RTC2 Minute Register       */

/*************************  Bit definition for HOURR2 register of HT_RTC_TypeDef ************************/
#define  RTC_HOURR2                              ((uint32_t)0x001f)             /*!<RTC2 Hour  Register        */

/**************************  Bit definition for DAYR2 register of HT_RTC_TypeDef ************************/
#define  RTC_DAYR2                               ((uint32_t)0x001f)             /*!<RTC2 Day   Register        */

/*************************  Bit definition for MONTHR2 register of HT_RTC_TypeDef ***********************/
#define  RTC_MONTHR2                             ((uint32_t)0x000f)             /*!<RTC2 Month Register        */

/*************************  Bit definition for YEARR2 register of HT_RTC_TypeDef ************************/
#define  RTC_YEARR2                              ((uint32_t)0x007f)             /*!<RTC2 Year  Register        */

/*************************  Bit definition for WEEKR2 register of HT_RTC_TypeDef ************************/
#define  RTC_WEEKR2                              ((uint32_t)0x0007)             /*!<RTC2 Week  Register        */

/*************************  Bit definition for RTC2CAL register of HT_RTC_TypeDef ***********************/
#define  RTC_RTC2CAL                             ((uint32_t)0x1ffff)            /*!<LRC RTC Calibration Register */
#endif

/*************************  Bit definition for FRE_LRC register of HT_RTC_TypeDef ***********************/
#if  defined  HT501x  ||  defined  HT502x
#define  RTC_FRELRC                              ((uint32_t)0x1ffff)            /*!<LRC Frequency Measuring Values */
#endif

#if  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
/*************************  Bit definition for RTCRD2 register of HT_RTC_TypeDef ************************/
#define  RTC_RTCRD2_READFLAG                     ((uint32_t)0x0001)           /*!<RTC2 Read  Control Bit */

/*************************  Bit definition for RTCWR2 register of HT_RTC_TypeDef ************************/
#define  RTC_RTCWR2_UPDATE                       ((uint32_t)0x0001)           /*!<RTC2 Write Control Bit */
#define  RTC_RTCWR2_CLEAR                        ((uint32_t)0x0000)           /*!<RTC2 Write Control Bit Clear */
#endif

#if defined  HT503x
/*************************  Bit definition for RTCTESTCTRL register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTESTCTRL                         ((uint32_t)0xFF03)           /*!<RTC Test Control Register */
#define  RTC_RTCTESTCTRL_RTCTEST_WP              ((uint32_t)0xFF00)           /*!<RTC Test Control Register Lower 8 Write Protection*/
#define  RTC_RTCTESTCTRL_RTCTEST_WP_UnProtected  ((uint32_t)0xA500)           /*!<RTC Test Control Register Lower 8 Write Protection Close*/
#define  RTC_RTCTESTCTRL_RTCTEST_WP_Protected    ((uint32_t)0x0000)           /*!<RTC Test Control Register Lower 8 Write Protection Open*/

#define  RTC_RTCTESTCTRL_C_OSC32K                ((uint32_t)0x0003)           /*!<32K Crystal Power Consumption Adjustment*/
#define  RTC_RTCTESTCTRL_C_OSC32K_1000nA         ((uint32_t)0x0000)           /*!<32K Crystal Power Consumption Adjustment 1000nA*/
#define  RTC_RTCTESTCTRL_C_OSC32K_692nA          ((uint32_t)0x0001)           /*!<32K Crystal Power Consumption Adjustment 692nA*/
#define  RTC_RTCTESTCTRL_C_OSC32K_530nA          ((uint32_t)0x0002)           /*!<32K Crystal Power Consumption Adjustment 530nA*/
#define  RTC_RTCTESTCTRL_C_OSC32K_430nA          ((uint32_t)0x0003)           /*!<32K Crystal Power Consumption Adjustment 430nA*/
#endif

#if defined  HT762x  ||  defined  HT772x 
/*************************  Bit definition for CALENDARCLR register of HT_RTC_TypeDef ************************/
#define  RTC_CALENDARCLR                         ((uint32_t)0xFF01)            /*!<RTC Clear Calibration Register */
#define  RTC_CALENDARCLR_WP                      ((uint32_t)0xFF00)            /*!<RTC Clear Calibration Register Lower 8 Write Protection*/
#define  RTC_CALENDARCLR_WP_UnProtected          ((uint32_t)0xA500)            /*!<RTC Clear Calibration Register Lower 8 Write Protection Close*/
#define  RTC_CALENDARCLR_WP_Protected            ((uint32_t)0x0000)            /*!<RTC Clear Calibration Register Lower 8 Write Protection Open*/

#define  RTC_CALENDARCLR_WRCLDCLR                ((uint32_t)0x0001)            /*!<RTC Clear Calibration to zero Control Bit*/
#endif

#if defined  HT633x 
#define  RTC_CALENDARCLR                         ((uint32_t)0x0001)            /*!<RTC Clear Calibration Register */
#define  RTC_CALENDARCLR_WRCLDCLR                ((uint32_t)0x0001)            /*!<RTC Clear Calibration to zero Control Bit*/
#endif


#if defined  HT762x  ||  defined  HT772x  ||  defined   HT633x
/*************************  Bit definition for RTCTSxCON(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxCON                           ((uint32_t)0xA335)            /*!<RTC TimeStampx Control Register */
#define  RTC_RTCTSxCON_TSCLR                     ((uint32_t)0x8000)            /*!<TimeStampx Event Count And Cache Clearance Control Bit*/

#define  RTC_RTCTSxCON_TSxFILT                   ((uint32_t)0x0300)            /*!<TimeStampx Digital Filter Selection Bits*/
#if defined   HT633x
#define  RTC_RTCTSxCON_TSxFILT_16CLK             ((uint32_t)0x0000)            /*!<TimeStampx Digital Filter Selection 16 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_496CLK            ((uint32_t)0x0100)            /*!<TimeStampx Digital Filter Selection 496 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_16368CLK          ((uint32_t)0x0200)            /*!<TimeStampx Digital Filter Selection 16368 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_32752CLK          ((uint32_t)0x0300)            /*!<TimeStampx Digital Filter Selection 32752 Clock*/
#else
#define  RTC_RTCTSxCON_TSxFILT_512CLK            ((uint32_t)0x0000)            /*!<TimeStampx Digital Filter Selection 512 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_4096CLK           ((uint32_t)0x0100)            /*!<TimeStampx Digital Filter Selection 4096 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_16384CLK          ((uint32_t)0x0200)            /*!<TimeStampx Digital Filter Selection 16384 Clock*/
#define  RTC_RTCTSxCON_TSxFILT_32768CLK          ((uint32_t)0x0300)            /*!<TimeStampx Digital Filter Selection 32768 Clock*/
#endif

#define  RTC_RTCTSxCON_TSxPOL                    ((uint32_t)0x0030)            /*!<TimeStampx Trigger Source Selection Bits*/
#define  RTC_RTCTSxCON_TSxPOL_RISING             ((uint32_t)0x0000)            /*!<TimeStampx Rising  Edge Trigger*/
#define  RTC_RTCTSxCON_TSxPOL_FALLING            ((uint32_t)0x0010)            /*!<TimeStampx Falling Edge Trigger*/
#define  RTC_RTCTSxCON_TSxPOL_DOUBLE             ((uint32_t)0x0020)            /*!<TimeStampx Double  Edge Trigger*/

#define  RTC_RTCTSxCON_TSxCMPEN                  ((uint32_t)0x0004)            /*!<TimeStampx Count Comparison Enable Control Bits*/
#define  RTC_RTCTSxCON_TSxCMPEN_ENABLE           ((uint32_t)0x0004)            /*!<TimeStampx Count Comparison Enable*/
#define  RTC_RTCTSxCON_TSxCMPEN_DISABLE          ((uint32_t)0x0000)            /*!<TimeStampx Count Comparison Disable*/

#define  RTC_RTCTSxCON_TSxEN                     ((uint32_t)0x0001)            /*!<TimeStampx Enable  Control Bits*/
#define  RTC_RTCTSxCON_TSxEN_ENABLE              ((uint32_t)0x0001)            /*!<TimeStampx Enable  Control */
#define  RTC_RTCTSxCON_TSxEN_DISABLE             ((uint32_t)0x0000)            /*!<TimeStampx Disable Control */

/*************************  Bit definition for RTCTSxCMP(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxCMP                           ((uint32_t)0x00FF)            /*!<RTC TimeStampx Event Comparison Register */
#define  RTC_RTCTSxCMP_TSxCMP                    ((uint32_t)0x00FF)            /*!<RTC TimeStampx Event Comparison SET Control Bits */

/*************************  Bit definition for RTCTSxCNT(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxCNT                           ((uint32_t)0x00FF)            /*!<RTC TimeStampx Event Count Register */
#define  RTC_RTCTSxCNT_TSxCNT                    ((uint32_t)0x00FF)            /*!<RTC TimeStampx Event Count Bits */

/*************************  Bit definition for RTCTSxIE(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxIE                            ((uint32_t)0x0015)            /*!<RTC TimeStampx Interrupt Enable Register */

#define  RTC_RTCTSxIE_TSxOVIE                    ((uint32_t)0x0010)            /*!<RTC TimeStampx Count Overflow Interrupt Enable Bit */
#define  RTC_RTCTSxIE_TSxCMPIE                   ((uint32_t)0x0004)            /*!<RTC TimeStampx Count Comparison Interrupt Enable Bit */
#define  RTC_RTCTSxIE_TSxIE                      ((uint32_t)0x0001)            /*!<RTC TimeStampx Trigger Interrupt Enable Bit */

/*************************  Bit definition for RTCTSxIF(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxIF                            ((uint32_t)0x0015)            /*!<RTC TimeStampx Interrupt Flag Register */

#define  RTC_RTCTSxIF_TSxOVIF                    ((uint32_t)0x0010)            /*!<RTC TimeStampx Count Overflow Interrupt Flag Bit */
#define  RTC_RTCTSxIF_TSxCMPIF                   ((uint32_t)0x0004)            /*!<RTC TimeStampx Count Comparison Interrupt Flag Bit */
#define  RTC_RTCTSxIF_TSxIF                      ((uint32_t)0x0001)            /*!<RTC TimeStampx Trigger Interrupt Flag Bit */

/*************************  Bit definition for RTCTSxTIM0(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM0                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM0_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM0_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM0_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT0(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT0                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT0_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT0_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT0_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU0(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU0                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU0_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU0_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU0_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */
 
/*************************  Bit definition for RTCTSxTIM1(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM1                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM1_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM1_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM1_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT1(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT1                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT1_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT1_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT1_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU1(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU1                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU1_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU1_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU1_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */ 

/*************************  Bit definition for RTCTSxTIM2(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM2                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM2_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM2_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM2_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT2(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT2                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT2_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT2_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT2_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU2(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU2                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU2_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU2_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU2_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */ 

/*************************  Bit definition for RTCTSxTIM3(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM3                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM3_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM3_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM3_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT3(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT3                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT3_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT3_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT3_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU3(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU3                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU3_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU3_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU3_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */ 

/*************************  Bit definition for RTCTSxTIM4(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM4                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM4_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM4_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM4_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT4(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT4                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT4_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT4_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT4_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU4(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU4                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU4_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU4_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU4_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */ 

/*************************  Bit definition for RTCTSxTIM5(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxTIM5                          ((uint32_t)0x1F3F3F)          /*!<RTC TimeStampx Time Cache Register */

#define  RTC_RTCTSxTIM5_HOUR                     ((uint32_t)0x1F0000)          /*!<RTC TimeStampx Hour Cache  */
#define  RTC_RTCTSxTIM5_MIN                      ((uint32_t)0x003F00)          /*!<RTC TimeStampx Minute Cache */
#define  RTC_RTCTSxTIM5_SEC                      ((uint32_t)0x00003F)          /*!<RTC TimeStampx Second Cache */
 
/*************************  Bit definition for RTCTSxDAT5(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxDAT5                          ((uint32_t)0x7F0F1F)          /*!<RTC TimeStampx Date Cache Register */

#define  RTC_RTCTSxDAT5_YEAR                     ((uint32_t)0x7F0000)          /*!<RTC TimeStampx Year Cache  */
#define  RTC_RTCTSxDAT5_MONTH                    ((uint32_t)0x000F00)          /*!<RTC TimeStampx Month Cache */
#define  RTC_RTCTSxDAT5_DAY                      ((uint32_t)0x00001F)          /*!<RTC TimeStampx Day Cache */
 
/*************************  Bit definition for RTCTSxSOU5(x=0/1) register of HT_RTC_TypeDef ************************/
#define  RTC_RTCTSxSOU5                          ((uint32_t)0x000003)          /*!<RTC TimeStampx Trigger Source Cache Register */

#define  RTC_RTCTSxSOU5_SPOL                     ((uint32_t)0x000002)          /*!<RTC TimeStampx Trigger Source Bit  */
#define  RTC_RTCTSxSOU5_SPOL_RISING              ((uint32_t)0x000000)          /*!<RTC TimeStampx Rising  Trigger */
#define  RTC_RTCTSxSOU5_SPOL_FALLING             ((uint32_t)0x000002)          /*!<RTC TimeStampx Ralling Trigger */ 

/*************************  Bit definition for RTCBACKUP register of HT_RTC_TypeDef ************************/
#define  RTC_RTCBACKUP0                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 0  */
#define  RTC_RTCBACKUP1                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 1  */
#define  RTC_RTCBACKUP2                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 2  */
#define  RTC_RTCBACKUP3                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 3  */
#define  RTC_RTCBACKUP4                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 4  */
#define  RTC_RTCBACKUP5                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 5  */
#define  RTC_RTCBACKUP6                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 6  */
#define  RTC_RTCBACKUP7                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 7  */
#define  RTC_RTCBACKUP8                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 8  */
#define  RTC_RTCBACKUP9                         ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 9  */
#define  RTC_RTCBACKUP10                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 10 */
#define  RTC_RTCBACKUP11                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 11 */
#define  RTC_RTCBACKUP12                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 12 */
#define  RTC_RTCBACKUP13                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 13 */
#define  RTC_RTCBACKUP14                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 14 */
#define  RTC_RTCBACKUP15                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 15 */
#define  RTC_RTCBACKUP16                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 16 */
#define  RTC_RTCBACKUP17                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 17 */
#define  RTC_RTCBACKUP18                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 18 */
#define  RTC_RTCBACKUP19                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 19 */
#define  RTC_RTCBACKUP20                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 20 */
#define  RTC_RTCBACKUP21                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 21 */
#define  RTC_RTCBACKUP22                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 22 */
#define  RTC_RTCBACKUP23                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 23 */
#define  RTC_RTCBACKUP24                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 24 */
#define  RTC_RTCBACKUP25                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 25 */
#define  RTC_RTCBACKUP26                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 26 */
#define  RTC_RTCBACKUP27                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 27 */
#define  RTC_RTCBACKUP28                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 28 */
#define  RTC_RTCBACKUP29                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 29 */
#define  RTC_RTCBACKUP30                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 30 */
#define  RTC_RTCBACKUP31                        ((uint32_t)0xFFFFFFFF)         /*!<RTC Date Backup Register 31 */
#endif

/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of LCD Module
**********************************************************************************************************
*/
/*************************  Bit definition for LCDCLK register of HT_LCD_TypeDef ************************/
#if  !defined  HT762x  ||  defined  HT772x
#define  LCD_LCDCLK                              ((uint32_t)0x009f)           /*!<LCD CLK Register        */

#define  LCD_LCDCLK_LCLK                         ((uint32_t)0x0007)           /*!<LCD Sweep Frequency Sel     */                                                                            /*!<Frame Rate Ver          */
#define  LCD_LCDCLK_LCLK_FRAME8HZ                ((uint32_t)0x0003)           /*!<Frame Rate = 8        */
#define  LCD_LCDCLK_LCLK_FRAME16HZ               ((uint32_t)0x0002)           /*!<Frame Rate = 16       */
#define  LCD_LCDCLK_LCLK_FRAME32HZ               ((uint32_t)0x0001)           /*!<Frame Rate = 32       */
#define  LCD_LCDCLK_LCLK_FRAME64HZ               ((uint32_t)0x0000)           /*!<Frame Rate = 64       */
#define  LCD_LCDCLK_LCLK_FRAME128HZ              ((uint32_t)0x0004)           /*!<Frame Rate = 128      */
                                                                            /*!<Divide Rate Ver         */
#define  LCD_LCDCLK_LCLK_DIV64                   LCD_LCDCLK_LCLK_FRAME128HZ   /*!<Divide Radio = 64     */
#define  LCD_LCDCLK_LCLK_DIV128                  LCD_LCDCLK_LCLK_FRAME64HZ    /*!<Divide Radio = 128    */
#define  LCD_LCDCLK_LCLK_DIV256                  LCD_LCDCLK_LCLK_FRAME32HZ    /*!<Divide Radio = 256    */
#define  LCD_LCDCLK_LCLK_DIV512                  LCD_LCDCLK_LCLK_FRAME16HZ    /*!<Divide Radio = 512    */
#define  LCD_LCDCLK_LCLK_DIV1024                 LCD_LCDCLK_LCLK_FRAME8HZ     /*!<Divide Radio = 1024   */

#define  LCD_LCDCLK_DUTY                         ((uint32_t)0x0018)           /*!<LCDDuty Crtl Sel      */
#define  LCD_LCDCLK_DUTY_COM4                    ((uint32_t)0x0000)           /*!<4Com                  */
#define  LCD_LCDCLK_DUTY_COM6                    ((uint32_t)0x0008)           /*!<6Com                  */
#define  LCD_LCDCLK_DUTY_COM8                    ((uint32_t)0x0010)           /*!<8Com                  */

#define  LCD_LCDCLK_BIASCTL                      ((uint32_t)0x0080)           /*!<LCD Bias Ctrl Sel     */
#define  LCD_LCDCLK_BIASCTL_3                    ((uint32_t)0x0080)           /*!<1/3 bias Drive        */
#define  LCD_LCDCLK_BIASCTL_4                    ((uint32_t)0x0000)           /*!<1/4 bias Drive        */

/*************************  Bit definition for LCDCON register of HT_LCD_TypeDef ************************/
#if  defined  HT502x  ||  defined  HT6x3x  ||  defined  HT503x
#define  LCD_LCDCON                              ((uint32_t)0x01ff)           /*!<LCD Ctrl Register     */
#else
#define  LCD_LCDCON                              ((uint32_t)0x00ff)           /*!<LCD Ctrl Register     */
#endif

#define  LCD_LCDCON_VRSEL                        ((uint32_t)0x000f)           /*!<LCD Contrast Ratio Set*/
#if defined  HT503x
#else
#define  LCD_LCDCON_LC                           ((uint32_t)0x0010)           /*!<LCD Slow Charge Mode Sel */
#define  LCD_LCDCON_FC                           ((uint32_t)0x0020)           /*!<LCD Fast Charge Mode Sel */
#endif

#if  defined  HT502x  ||  defined  HT6x3x
#define  LCD_LCDCON_FCSET                        ((uint32_t)0x00c0)           /*!<LCD Fast Charge Time Sel */
#define  LCD_LCDCON_FCSET_16                     ((uint32_t)0x0000)           /*!<Charge Time = 1/16flcd   */
#define  LCD_LCDCON_FCSET_32                     ((uint32_t)0x0040)           /*!<Charge Time = 1/32flcd   */
#define  LCD_LCDCON_FCSET_64                     ((uint32_t)0x0080)           /*!<Charge Time = 1/64flcd   */
#define  LCD_LCDCON_FCSET_128                    ((uint32_t)0x00c0)           /*!<Charge Time = 1/128flcd  */
#elif  defined  HT503x
#else
#define  LCD_LCDCON_FCSET                        ((uint32_t)0x00c0)           /*!<LCD Fast Charge Time Sel */
#define  LCD_LCDCON_FCSET_8                      ((uint32_t)0x0000)           /*!<Charge Time = 1/8flcd    */
#define  LCD_LCDCON_FCSET_16                     ((uint32_t)0x0040)           /*!<Charge Time = 1/16flcd   */
#define  LCD_LCDCON_FCSET_32                     ((uint32_t)0x0080)           /*!<Charge Time = 1/32flcd   */
#define  LCD_LCDCON_FCSET_64                     ((uint32_t)0x00c0)           /*!<Charge Time = 1/64flcd   */
#endif

#if  defined  HT502x  ||  defined  HT6x3x
#define  LCD_LCDCON_FCSET2                       ((uint32_t)0x0100)           /*!<Resistance Divider Structure Ctrl Bit    */
#define  LCD_LCDCON_FCSET2_CHANGER               ((uint32_t)0x0100)           /*!<Improved Resistance Divider Structure    */
#define  LCD_LCDCON_FCSET2_KEEPR                 ((uint32_t)0x0000)           /*!<Keep Resistance Divider Structure  */
#endif

/*************************  Bit definition for LCDCPC register of HT_LCD_TypeDef ************************/
#if  defined  HT6x3x  ||  defined  HT503x
#define  LCD_LCDCPC                              ((uint32_t)0x079f)           /*!<LCD Charge Pump Ctrl Register*/
#define  LCD_LCDCPC_VCSEL                        ((uint32_t)0x001f)           /*!<LCD Display Contrast Set     */

#define  LCD_LCDCPC_MODSET                       ((uint32_t)0x0080)           /*!<LCD Drive Mode Set       		 */
#define  LCD_LCDCPC_MODSET_ChargePumpDrive       ((uint32_t)0x0080)           /*!<Charge Pump Drive        		 */
#define  LCD_LCDCPC_MODSET_InsideRESDrive         ((uint32_t)0x0000)          /*!<Interval Resistance Divider	 */

#define  LCD_LCDCPC_CCLKSEL                      ((uint32_t)0x0700)           /*!<Chargepump Clk Sel Register  */
#define  LCD_LCDCPC_CCLKSEL_256                  ((uint32_t)0x0000)           /*!<256                    */
#define  LCD_LCDCPC_CCLKSEL_512                  ((uint32_t)0x0100)           /*!<512                    */
#define  LCD_LCDCPC_CCLKSEL_1K                   ((uint32_t)0x0200)           /*!<1K                     */
#define  LCD_LCDCPC_CCLKSEL_2K                   ((uint32_t)0x0300)           /*!<2K                     */
#define  LCD_LCDCPC_CCLKSEL_4K                   ((uint32_t)0x0400)           /*!<4K (Default)           */
#define  LCD_LCDCPC_CCLKSEL_8K                   ((uint32_t)0x0500)           /*!<8K                     */
#define  LCD_LCDCPC_CCLKSEL_16K                  ((uint32_t)0x0600)           /*!<16K                    */
#define  LCD_LCDCPC_CCLKSEL_32K                  ((uint32_t)0x0700)           /*!<32K                    */
#endif

/*************************  Bit definition for LCDOUT register of HT_LCD_TypeDef ************************/
#if  defined  HT502x  ||  defined  HT6x3x  ||  defined  HT503x
#define  LCD_LCDOUT                              ((uint32_t)0x0001)           /*!<LCD Out Ctrl Register    */
#define  LCD_LCDOUT_ENABLE                       ((uint32_t)0x0001)           /*!<LCD Out Enable           */
#define  LCD_LCDOUT_DISABLE                      ((uint32_t)0x0000)           /*!<LCD Out Disable           */
#endif

/*************************  Bit definition for VCPADJ register of HT_LCD_TypeDef ************************/
#if  defined  HT6x3x  ||  defined  HT503x
#define  LCD_VCPADJ                              ((uint32_t)0x001f)           /*!<Chargepump Vref Adjust Register*/
#endif
#endif


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of TBS Module
**********************************************************************************************************
*/
/*************************  Bit definition for TBSCON register of HT_TBS_TypeDef ************************/
#if  defined  USE_TBS_SOC

#if  defined  HT501x  ||  defined  HT502x
#define  TBS_TBSCON                              ((uint32_t)0x00001b7f)           /*!<TBS Control Register        */
#elif  defined  HT503x
#define  TBS_TBSCON                              ((uint32_t)0x0060fbff)           /*!<TBS Control Register        */
#endif

#define  TBS_TBSCON_TMPEn                      	 ((uint32_t)0x00000001)           /*!<Temperature measurement function enable*/
#define  TBS_TBSCON_VBATEn                       ((uint32_t)0x00000002)           /*!<Battery voltage measurement function enable  */
#define  TBS_TBSCON_VDDEn                        ((uint32_t)0x00000004)           /*!<VDD measurement function enable  */
#define  TBS_TBSCON_VCCEn                        TBS_TBSCON_VDDEn                 /*!<  Corresponding  VDDEn in the manual*/
#define  TBS_TBSCON_ADC0En                       ((uint32_t)0x00000008)           /*!<ADC0 measurement function enable      */
#define  TBS_TBSCON_ADC1En                       ((uint32_t)0x00000010)           /*!<ADC1 measurement function enable      */
#define  TBS_TBSCON_ADC2En                       ((uint32_t)0x00000020)           /*!<ADC2 measurement function enable      */
#define  TBS_TBSCON_VBATCMPEn                    ((uint32_t)0x00000040)           /*!<Vbat compare function enable      */

#if  defined  USE_TBS_TBSCON_ADC3
#define  TBS_TBSCON_ADC3En                       ((uint32_t)0x00000080)           /*!<ADC3 measurement function enable      */
#endif

#define  TBS_TBSCON_FILTER                       ((uint32_t)0x00000300)           /*!<Filter output configuration for temperature measurement*/
#define  TBS_TBSCON_FILTER_1                     ((uint32_t)0x00000000)           /*!<Filter output 1 time average for temperature measurement*/
#define  TBS_TBSCON_FILTER_2                     ((uint32_t)0x00000100)           /*!<Filter output 2 times average for temperature measurement*/
#define  TBS_TBSCON_FILTER_4                     ((uint32_t)0x00000200)           /*!<Filter output 4 times average for temperature measurement*/
#define  TBS_TBSCON_FILTER_8                     ((uint32_t)0x00000300)           /*!<Filter output 8 times average for temperature measurement*/
#define  TBS_TBSCON_ADC0CMPEn                    ((uint32_t)0x00000800)           /*!<ADC0 compare function enable      */
#define  TBS_TBSCON_ADC1CMPEn                    ((uint32_t)0x00001000)           /*!<ADC1 compare function enable     */

#if  defined  USE_TBS_TBSCON_ADC4
#define  TBS_TBSCON_ADC4En                       ((uint32_t)0x00002000)           /*!<ADC4 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC5
#define  TBS_TBSCON_ADC5En                       ((uint32_t)0x00004000)           /*!<ADC5 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC6
#define  TBS_TBSCON_ADC6En                       ((uint32_t)0x00008000)           /*!<ADC6 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_TBSCLKSEL
#define  TBS_TBSCON_TBSCLKSEL                    ((uint32_t)0x00600000)           /*!<TBS module clock source select     */
#define  TBS_TBSCON_TBSCLKSEL_OSC                ((uint32_t)0x00000000)           /*!<TBS module clock select OSC     */
#define  TBS_TBSCON_TBSCLKSEL_LRC                ((uint32_t)0x00200000)           /*!<TBS module clock select LRC     */
#define  TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10        ((uint32_t)0x00400000)           /*!<TBS module clock select LSTBSCLK */
#define  TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11        ((uint32_t)0x00600000)           /*!<TBS module clock select LSTBSCLK */
#endif

#if  defined  HT501x  ||  defined  HT502x
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0000187f)           /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	 		 ((uint32_t)0x00000100)		      /*!<OSC TPS configuration */

#elif  defined  HT503x
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0000f8ff)           /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	 		 ((uint32_t)0x00000100)		      /*!<OSC TPS configuration */
#endif

#endif



#if  defined  USE_TBS_MCU

#if  defined  HT6x1x  ||  defined  HT6x2x  ||  defined  HT6x3x
#define  TBS_TBSCON                              ((uint32_t)0x0003ffff)           /*!<TBS Control Register       */
#elif  defined  HT6x2xK
#define  TBS_TBSCON                              ((uint32_t)0x0083ffff)           /*!<TBS Control Register       */
#elif  defined  HT762x  ||  defined  HT772x
#define  TBS_TBSCON                              ((uint32_t)0xf3ffffff)           /*!<TBS Control Register       */
#elif  defined  HT633x  ||  defined  HT633xH
#define  TBS_TBSCON                              ((uint32_t)0x00ffff1f)           /*!<TBS Control Register       */
#endif

#define  TBS_TBSCON_TMPEn                        ((uint32_t)0x00000001)           /*!<Temperature measurement function enable      */

#if  defined  USE_TBS_TBSCON_TDVREFEn
#define  TBS_TBSCON_TDVREFEn                     ((uint32_t)0x00000002)           /*!<Battery voltage measurement function enable  */
#else
#define  TBS_TBSCON_ADCBATEn                     ((uint32_t)0x00000002)           /*!<Battery voltage measurement function enable  */
#define  TBS_TBSCON_VBATEn                       TBS_TBSCON_ADCBATEn          	  /*!<  Corresponding  VDDEn in the manual  */
#endif

#define  TBS_TBSCON_ADC0En                       ((uint32_t)0x00000004)           /*!<ADC0 measurement function enable      */
#define  TBS_TBSCON_ADC1En                       ((uint32_t)0x00000008)           /*!<ADC1 measurement function enable      */
#define  TBS_TBSCON_VCCEn                        ((uint32_t)0x00000010)           /*!<VCC measurement function enable       */

#if  defined  USE_TBS_TBSCON_TBSCLKSEL  &  !defined  USE_TBS_TBSCON_TBSCLKSEL_2BIT
#define  TBS_TBSCON_TBSCLKSEL                    ((uint32_t)0x00000020)           /*!<TBS working clock source select  */                                                                              /*!<   Only support version above HT6x2x H */
#define  TBS_TBSCON_TBSCLKSEL_OSC                ((uint32_t)0x00000000)           /*!<TBS working clock source select OSC     */
#define  TBS_TBSCON_TBSCLKSEL_PLLDIV             ((uint32_t)0x00000020)           /*!<TBS working clock source select PLL/168 for HT6x2xK & HT6x3x*/
																			      /*!<TBS working clock source select PLL/150 for HT762x  & HT772x*/
#endif

#define  TBS_TBSCON_FILTER                       ((uint32_t)0x00000300)           /*!<Filter output configuration for temperature measurement*/
#define  TBS_TBSCON_FILTER_1                     ((uint32_t)0x00000000)           /*!<Filter output 1 time average for temperature measurement*/
#define  TBS_TBSCON_FILTER_2                     ((uint32_t)0x00000100)           /*!<Filter output 2 times average for temperature measurement*/
#define  TBS_TBSCON_FILTER_4                     ((uint32_t)0x00000200)           /*!<Filter output 4 times average for temperature measurement*/
#define  TBS_TBSCON_FILTER_8                     ((uint32_t)0x00000300)           /*!<Filter output 8 times average for temperature measurement*/

#if  defined  USE_TBS_TBSCON_ADC3
#define  TBS_TBSCON_ADC3En                       ((uint32_t)0x00008000)           /*!<ADC3 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC4
#define  TBS_TBSCON_ADC4En                       ((uint32_t)0x00010000)          /*!<ADC4 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC5
#define  TBS_TBSCON_ADC5En                       ((uint32_t)0x00020000)      /*!<ADC5 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC6
#define  TBS_TBSCON_ADC6En                       ((uint32_t)0x00040000)      /*!<ADC6 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC7
#define  TBS_TBSCON_ADC7En                       ((uint32_t)0x00080000)      /*!<ADC7 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_ADC8
#define  TBS_TBSCON_ADC8En                       ((uint32_t)0x00100000)      /*!<ADC8 measurement function enable      */
#endif

#if  defined  USE_TBS_TBSCON_TBSCLKSEL_2BIT
#define  TBS_TBSCON_TBSCLKSEL                    ((uint32_t)0x00600000)      /*!<TBS working clock source select--2 control bits  */
#define  TBS_TBSCON_TBSCLKSEL_OSC                ((uint32_t)0x00000000)      /*!<TBS module clock select OSC     */
#define  TBS_TBSCON_TBSCLKSEL_LRC                ((uint32_t)0x00200000)      /*!<TBS module clock select LRC     */
#define  TBS_TBSCON_TBSCLKSEL_LSTBSCLK_10        ((uint32_t)0x00400000)      /*!<TBS module clock select LSTBSCLK */
#define  TBS_TBSCON_TBSCLKSEL_LSTBSCLK_11        ((uint32_t)0x00600000)      /*!<TBS module clock select LSTBSCLK */
#endif

#if  defined  USE_TBS_TBSCON_ADC9
#define  TBS_TBSCON_ADC9En                       ((uint32_t)0x00800000)      /*!<ADC9 measurement function enable      */
#endif

#if  defined  USE_TBS_VTP
#define  TBS_TBSCON_VTP0En                       ((uint32_t)0x00040000)      /*!<Temperature measurement terminal channel 0 enable     */
#define  TBS_TBSCON_VTP1En                       ((uint32_t)0x00080000)      /*!<Temperature measurement terminal channel 1 enable     */
#define  TBS_TBSCON_VTP2En                       ((uint32_t)0x00100000)      /*!<Temperature measurement terminal channel 2 enable     */
#define  TBS_TBSCON_VTP3En                       ((uint32_t)0x00200000)      /*!<Temperature measurement terminal channel 3 enable     */
#define  TBS_TBSCON_VTP4En                       ((uint32_t)0x00400000)      /*!<Temperature measurement terminal channel 4 enable     */
#define  TBS_TBSCON_VTP5En                       ((uint32_t)0x00800000)      /*!<Temperature measurement terminal channel 5 enable     */
#define  TBS_TBSCON_VTP6En                       ((uint32_t)0x01000000)      /*!<Temperature measurement terminal channel 6 enable     */
#define  TBS_TBSCON_VTP7En                       ((uint32_t)0x02000000)      /*!<Temperature measurement terminal channel 7 enable     */
#endif

#if  defined  USE_TBS_NEWREG_En
#define  TBS_TBSCON_TBS_NEWREG_En				 ((uint32_t)0x00800000)		 /*!<TBS mdoule new function write-protect control    */
#endif

#if  defined  USE_TBS_TPGA
#define  TBS_TBSCON_TPGA                         ((uint32_t)0x30000000)      /*!<Temperature measurement terminal TPGA gear select  */
#define  TBS_TBSCON_TPGA_2                       ((uint32_t)0x00000000)      /*!<Temperature measurement terminal TPGA gear select 2  times */
#define  TBS_TBSCON_TPGA_4                       ((uint32_t)0x10000000)      /*!<Temperature measurement terminal TPGA gear select 4  times */
#define  TBS_TBSCON_TPGA_8                       ((uint32_t)0x20000000)      /*!<Temperature measurement terminal TPGA gear select 8  times */
#define  TBS_TBSCON_TPGA_16                      ((uint32_t)0x30000000)      /*!<Temperature measurement terminal TPGA gear select 16 times */
#define  TBS_TBSCON_PGA_SEL                      ((uint32_t)0x40000000)      /*!<PGA select control           */
#define  TBS_TBSCON_PGA_En                       ((uint32_t)0x80000000)      /*!<PGA module enable           */
#endif

#if  defined  HT6x1x
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0000001f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	         ((uint32_t)0x00006540)		 /*!<OSC TPS configuration */
#elif  defined  HT6x2x
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0003801f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	         ((uint32_t)0x00006540)		 /*!<OSC TPS configuration */
#elif  defined  HT6x2xK
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0083801f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	         ((uint32_t)0x00006540)		 /*!<OSC TPS configuration */
#elif  defined  HT6x3x
#define  TBS_TBSCON_xEn                          ((uint32_t)0x0083801f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	         ((uint32_t)0x00006540)		 /*!<OSC TPS configuration */
#elif  defined  HT762x  ||  defined  HT772x
#define  TBS_TBSCON_xEn                          ((uint32_t)0xC3ff801f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG		  	         ((uint32_t)0x10006540)		 /*!<OSC TPS configuration */
#elif  defined  HT633x  ||  defined  HT633xH
#define  TBS_TBSCON_xEn                          ((uint32_t)0x009f801f)      /*!<TBS submodule enable       */
#define  TBS_TBSCON_OSC_CONFIG                   ((uint32_t)0x00006500)      /*!<OSC TPS configuration */
#endif

#endif

/*************************  Bit definition for TBSIE register of HT_TBS_TypeDef *************************/
#if  defined  USE_TBS_SOC

#if  defined  HT501x  ||  defined  HT502x
#define  TBS_TBSIE                               ((uint32_t)0x000003ff)           /*!<TBS interrupt enable           */
#elif  defined  HT503x
#define  TBS_TBSIE                               ((uint32_t)0x0000e3ff)           /*!<TBS interrupt enable           */
#endif

#define  TBS_TBSIE_TMPIE                         ((uint32_t)0x00000001)           /*!<Temperature measurement interrupt enable      */
#define  TBS_TBSIE_VBATIE                        ((uint32_t)0x00000002)           /*!<Battery voltage measurement interrupt enable  */
#define  TBS_TBSIE_VCCIE                         ((uint32_t)0x00000004)           /*!<VCC measurement interrupt enable       */                                                                             /*!<  Correspondencing to VDDIE in the manual    */
#define  TBS_TBSIE_ADC0IE                        ((uint32_t)0x00000008)           /*!<ADC0 measurement interrupt enable      */
#define  TBS_TBSIE_ADC1IE                        ((uint32_t)0x00000010)           /*!<ADC1 measurement interrupt enable      */
#define  TBS_TBSIE_ADC2IE                        ((uint32_t)0x00000020)           /*!<ADC2 measurement interrupt enable      */
#define  TBS_TBSIE_VBATCMPIE                     ((uint32_t)0x00000040)           /*!<Battery voltage compare interrupt enable  */

#if  defined  USE_TBS_TBSIE_ADC3
#define  TBS_TBSIE_ADC3IE                        ((uint32_t)0x00000080)           /*!<ADC3 measurement interrupt enable      */
#endif

#define  TBS_TBSIE_ADC0CMPIE                     ((uint32_t)0x00000100)           /*!<ADC0 compare interrupt enable      */
#define  TBS_TBSIE_ADC1CMPIE                     ((uint32_t)0x00000200)           /*!<ADC1 compare interrupt enable      */

#if  defined  USE_TBS_TBSIE_ADC4
#define  TBS_TBSIE_ADC4IE                        ((uint32_t)0x00002000)           /*!<ADC4 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC5
#define  TBS_TBSIE_ADC5IE                        ((uint32_t)0x00004000)           /*!<ADC5 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC6
#define  TBS_TBSIE_ADC6IE                        ((uint32_t)0x00008000)           /*!<ADC6 measurement interrupt enable      */
#endif

#endif



#if  defined  USE_TBS_MCU

#if  defined  HT6x1x
#define  TBS_TBSIE                               ((uint32_t)0x0000003f)           /*!<TBS interrupt enable           */
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  TBS_TBSIE                               ((uint32_t)0x000003ff)           /*!<TBS interrupt enable           */
#elif  defined  HT762x  ||  defined  HT772x
#define  TBS_TBSIE                               ((uint32_t)0x0003ffff)           /*!<TBS interrupt enable           */
#elif  defined  HT633x  ||  defined  HT633xH
#define  TBS_TBSIE                               ((uint32_t)0x00003fff)           /*!<TBS interrupt enable           */
#endif

#define  TBS_TBSIE_TMPIE                         ((uint32_t)0x00000001)           /*!<Temperature measurement interrupt enable      */

#if defined  USE_TBS_TBSIE_TDVREFIE
#define  TBS_TBSIE_TDVREFIE                      ((uint32_t)0x00000002)           /*!<EMU module VREF measurement interrupt enable  */
#else
#define  TBS_TBSIE_VBATIE                        ((uint32_t)0x00000002)           /*!<Battery voltage compare interrupt enable  */
#endif

#define  TBS_TBSIE_ADC0IE                        ((uint32_t)0x00000004)           /*!<ADC0 measurement interrupt enable      */
#define  TBS_TBSIE_ADC1IE                        ((uint32_t)0x00000008)           /*!<ADC1 measurement interrupt enable      */

#if defined  USE_TBS_TBSIE_TDVREFCMPIE
#define  TBS_TBSIE_TDVREFCMPIE                   ((uint32_t)0x00000010)           /*!<EMU module VREF measurement interrupt enable  */
#else
#define  TBS_TBSIE_VBATCMPIE                     ((uint32_t)0x00000010)           /*!<Battery voltage compare interrupt enable  */
#endif

#define  TBS_TBSIE_VCCIE                         ((uint32_t)0x00000020)           /*!<VCC measurement interrupt enable       */

#if  defined  USE_TBS_TBSIE_ADC0CMP
#define  TBS_TBSIE_ADC0CMPIE                     ((uint32_t)0x00000040)           /*!<ADC0 compare interrupt enable  */
#endif

#if  defined  USE_TBS_TBSIE_ADC3
#define  TBS_TBSIE_ADC3IE                        ((uint32_t)0x00000080)           /*!<ADC3 measurement interrupt enable     */
#endif

#if  defined  USE_TBS_TBSIE_ADC4
#define  TBS_TBSIE_ADC4IE                        ((uint32_t)0x00000100)           /*!<ADC4 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC5
#define  TBS_TBSIE_ADC5IE                        ((uint32_t)0x00000200)           /*!<ADC5 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC6
#define  TBS_TBSIE_ADC6IE                        ((uint32_t)0x00000400)           /*!<ADC6 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC7
#define  TBS_TBSIE_ADC7IE                        ((uint32_t)0x00000800)           /*!<ADC7 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC8
#define  TBS_TBSIE_ADC8IE                        ((uint32_t)0x00001000)           /*!<ADC8 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_ADC9
#define  TBS_TBSIE_ADC9IE                        ((uint32_t)0x00002000)           /*!<ADC9 measurement interrupt enable      */
#endif

#if  defined  USE_TBS_TBSIE_VTPIE
#define  TBS_TBSIE_VTP0IE                        ((uint32_t)0x00000400)           /*!<Temperature measurement terminal channel 0 interrupt enable    */
#define  TBS_TBSIE_VTP1IE                        ((uint32_t)0x00000800)           /*!<Temperature measurement terminal channel 1 interrupt enable    */
#define  TBS_TBSIE_VTP2IE                        ((uint32_t)0x00001000)           /*!<Temperature measurement terminal channel 2 interrupt enable    */
#define  TBS_TBSIE_VTP3IE                        ((uint32_t)0x00002000)           /*!<Temperature measurement terminal channel 3 interrupt enable    */
#define  TBS_TBSIE_VTP4IE                        ((uint32_t)0x00004000)           /*!<Temperature measurement terminal channel 4 interrupt enable    */
#define  TBS_TBSIE_VTP5IE                        ((uint32_t)0x00008000)           /*!<Temperature measurement terminal channel 5 interrupt enable    */
#define  TBS_TBSIE_VTP6IE                        ((uint32_t)0x00010000)           /*!<Temperature measurement terminal channel 6 interrupt enable    */
#define  TBS_TBSIE_VTP7IE                        ((uint32_t)0x00020000)           /*!<Temperature measurement terminal channel 7 interrupt enable    */
#endif

#endif

/*************************  Bit definition for TBSIF register of HT_TBS_TypeDef *************************/
#if  defined  USE_TBS_SOC

#if  defined  HT501x  ||  defined  HT502x
#define  TBS_TBSIF                               ((uint32_t)0x000003ff)           /*!<TBS interrupt flag           */
#elif  defined  HT503x
#define  TBS_TBSIF                               ((uint32_t)0x0000e3ff)           /*!<TBS interrupt flag           */
#endif

#define  TBS_TBSIF_TMPIF                         ((uint32_t)0x00000001)           /*!<Temperature measurement interrupt flag      */
#define  TBS_TBSIF_VBATIF                        ((uint32_t)0x00000002)           /*!<Battery voltage measurement interrupt flag  */
#define  TBS_TBSIF_VCCIF                         ((uint32_t)0x00000004)           /*!<VCC measurement interrupt flag       */                                                                             /*!<  Correspondencing to VDDIE in the manual    */
#define  TBS_TBSIF_ADC0IF                        ((uint32_t)0x00000008)           /*!<ADC0 measurement interrupt flag      */
#define  TBS_TBSIF_ADC1IF                        ((uint32_t)0x00000010)           /*!<ADC1 measurement interrupt flag      */
#define  TBS_TBSIF_ADC2IF                        ((uint32_t)0x00000020)           /*!<ADC2 measurement interrupt flag      */
#define  TBS_TBSIF_VBATCMPIF                     ((uint32_t)0x00000040)           /*!<Battery voltage compare interrupt flag  */

#if  defined  USE_TBS_TBSIF_ADC3
#define  TBS_TBSIF_ADC3IF                        ((uint32_t)0x00000080)           /*!<ADC3 measurement interrupt flag      */
#endif

#define  TBS_TBSIF_ADC0CMPIF                     ((uint32_t)0x00000100)           /*!<ADC0 compare interrupt flag      */
#define  TBS_TBSIF_ADC1CMPIF                     ((uint32_t)0x00000200)           /*!<ADC1 compare interrupt flag      */

#if  defined  USE_TBS_TBSIF_ADC4
#define  TBS_TBSIF_ADC4IF                        ((uint32_t)0x00002000)           /*!<ADC4 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC5
#define  TBS_TBSIF_ADC5IF                        ((uint32_t)0x00004000)           /*!<ADC5 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC6
#define  TBS_TBSIF_ADC6IF                        ((uint32_t)0x00008000)           /*!<ADC6 measurement interrupt flag      */
#endif

#endif



#if  defined  USE_TBS_MCU

#if  defined  HT6x1x
#define  TBS_TBSIF                               ((uint32_t)0x0000003f)           /*!<TBS interrupt flag           */
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  TBS_TBSIF                               ((uint32_t)0x000003ff)           /*!<TBS interrupt flag           */
#elif  defined  HT762x  ||  defined  HT772x
#define  TBS_TBSIF                               ((uint32_t)0x0003ffff)           /*!<TBS interrupt flag           */
#elif  defined  HT633x  ||  defined  HT633xH
#define  TBS_TBSIF                               ((uint32_t)0x00003fff)           /*!<TBS interrupt flag           */
#endif

#define  TBS_TBSIF_TMPIF                         ((uint32_t)0x00000001)           /*!<Temperature measurement interrupt flag      */

#if defined  USE_TBS_TBSIF_TDVREFIF
#define  TBS_TBSIF_TDVREFIF                      ((uint32_t)0x00000002)           /*!<EMU module VREF measurement interrupt flag  */
#else
#define  TBS_TBSIF_VBATIF                        ((uint32_t)0x00000002)           /*!<Battery voltage compare interrupt flag  */
#endif

#define  TBS_TBSIF_ADC0IF                        ((uint32_t)0x00000004)           /*!<ADC0 measurement interrupt flag      */
#define  TBS_TBSIF_ADC1IF                        ((uint32_t)0x00000008)           /*!<ADC1 measurement interrupt flag      */

#if defined  USE_TBS_TBSIF_TDVREFCMPIF
#define  TBS_TBSIF_TDVREFCMPIF                   ((uint32_t)0x00000010)           /*!<EMU module VREF measurement interrupt flag  */
#else
#define  TBS_TBSIF_VBATCMPIF                     ((uint32_t)0x00000010)           /*!<Battery voltage compare interrupt flag  */
#endif

#define  TBS_TBSIF_VCCIF                         ((uint32_t)0x00000020)           /*!<VCC measurement interrupt flag       */

#if  defined  USE_TBS_TBSIF_ADC0CMP
#define  TBS_TBSIF_ADC0CMPIF                     ((uint32_t)0x00000040)           /*!<ADC0 compare interrupt flag  */
#endif

#if  defined  USE_TBS_TBSIF_ADC3
#define  TBS_TBSIF_ADC3IF                        ((uint32_t)0x00000080)           /*!<ADC3 measurement interrupt flag     */
#endif

#if  defined  USE_TBS_TBSIF_ADC4
#define  TBS_TBSIF_ADC4IF                        ((uint32_t)0x00000100)           /*!<ADC4 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC5
#define  TBS_TBSIF_ADC5IF                        ((uint32_t)0x00000200)           /*!<ADC5 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC6
#define  TBS_TBSIF_ADC6IF                        ((uint32_t)0x00000400)           /*!<ADC6 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC7
#define  TBS_TBSIF_ADC7IF                        ((uint32_t)0x00000800)           /*!<ADC7 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC8
#define  TBS_TBSIF_ADC8IF                        ((uint32_t)0x00001000)           /*!<ADC8 measurement interrupt flag      */
#endif

#if  defined  USE_TBS_TBSIF_ADC9
#define  TBS_TBSIF_ADC9IF                        ((uint32_t)0x00002000)           /*!<ADC9 measurement interrupt flag      */
#endif


#if  defined  USE_TBS_TBSIF_VTPIF
#define  TBS_TBSIF_VTP0IF                        ((uint32_t)0x00000400)           /*!<Temperature measurement terminal channel 0 interrupt flag    */
#define  TBS_TBSIF_VTP1IF                        ((uint32_t)0x00000800)           /*!<Temperature measurement terminal channel 1 interrupt flag    */
#define  TBS_TBSIF_VTP2IF                        ((uint32_t)0x00001000)           /*!<Temperature measurement terminal channel 2 interrupt flag    */
#define  TBS_TBSIF_VTP3IF                        ((uint32_t)0x00002000)           /*!<Temperature measurement terminal channel 3 interrupt flag    */
#define  TBS_TBSIF_VTP4IF                        ((uint32_t)0x00004000)           /*!<Temperature measurement terminal channel 4 interrupt flag    */
#define  TBS_TBSIF_VTP5IF                        ((uint32_t)0x00008000)           /*!<Temperature measurement terminal channel 5 interrupt flag    */
#define  TBS_TBSIF_VTP6IF                        ((uint32_t)0x00010000)           /*!<Temperature measurement terminal channel 6 interrupt flag    */
#define  TBS_TBSIF_VTP7IF                        ((uint32_t)0x00020000)           /*!<Temperature measurement terminal channel 7 interrupt flag    */
#endif

#endif

/************************  Bit definition for TMPDAT register of HT_TBS_TypeDef *************************/
#define  TBS_TMPDAT                            ((uint32_t)0x0000ffff)           /*!<Temperature measurement data register    */

/************************  Bit definition for VBATDAT register of HT_TBS_TypeDef ************************/
#if defined  USE_TBS_TDVREFDAT
#define  TBS_TDVREFDAT                         ((uint32_t)0x0000ffff)           /*!<EMU module VREF measurement data register    */
#else
#define  TBS_VBATDAT                           ((uint32_t)0x0000ffff)           /*!<Battery voltage measurement data register    */
#endif
/************************  Bit definition for ADC0DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC0DAT                           ((uint32_t)0x0000ffff)           /*!<ADC0 measurement data register        */

/************************  Bit definition for ADC1DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC1DAT                           ((uint32_t)0x0000ffff)           /*!<ADC1 measurement data register        */

/***********************  Bit definition for VBATCMP register of HT_TBS_TypeDef *************************/
#if defined  USE_TBS_TDVREFCMP
#define  TBS_TDVREFCMP                         ((uint32_t)0x0000ffff)           /*!<EMU module VREF compare register    */
#else
#define  TBS_VBATCMP                           ((uint32_t)0x0000ffff)           /*!<Battery voltage compare register    */
#endif

#if  defined  USE_TBS_ADC2DAT
/***********************  Bit definition for ADC2DAT register of HT_TBS_TypeDef *************************/
#define  TBS_ADC2DAT                           ((uint32_t)0x0000ffff)           /*!<ADC2 measurement register        */
#endif

#if  defined  USE_TBS_ADC0CMP
/************************  Bit definition for ADC0CMP register of HT_TBS_TypeDef ************************/
#define  TBS_ADC0CMP                           ((uint32_t)0x0000ffff)           /*!<ADC0 compare register            */
#endif

#if  defined  USE_TBS_ADC1CMP
/************************  Bit definition for ADC1CMP register of HT_TBS_TypeDef ************************/
#define  TBS_ADC1CMP                           ((uint32_t)0x0000ffff)           /*!<ADC1 compare register            */
#endif

#if  defined  USE_TBS_ADC3DAT
/************************  Bit definition for ADC3DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC3DAT                           ((uint32_t)0x0000ffff)           /*!<ADC3 measurement register        */
#endif

#if  defined  USE_TBS_ADC4DAT
/************************  Bit definition for ADC4DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC4DAT                           ((uint32_t)0x0000ffff)           /*!<ADC4 measurement register        */
#endif

#if  defined  USE_TBS_ADC5DAT
/************************  Bit definition for ADC5DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC5DAT                           ((uint32_t)0x0000ffff)           /*!<ADC5 measurement register        */
#endif

#if  defined  USE_TBS_ADC6DAT  
/************************  Bit definition for ADC6DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC6DAT                           ((uint32_t)0x0000ffff)           /*!<ADC6 measurement register        */
#endif

#if  defined  USE_TBS_ADC7DAT  
/************************  Bit definition for ADC6DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC7DAT                           ((uint32_t)0x0000ffff)           /*!<ADC7 measurement register        */
#endif

#if  defined  USE_TBS_ADC8DAT  
/************************  Bit definition for ADC6DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC8DAT                           ((uint32_t)0x0000ffff)           /*!<ADC8 measurement register        */
#endif

#if  defined  USE_TBS_ADC9DAT  
/************************  Bit definition for ADC6DAT register of HT_TBS_TypeDef ************************/
#define  TBS_ADC9DAT                           ((uint32_t)0x0000ffff)           /*!<ADC9 measurement register        */
#endif


/************************  Bit definition for TBSPRD register of HT_TBS_TypeDef *************************/
#if  defined  USE_TBS_SOC
#define  TBS_TBSPRD_TMPPRD                     ((uint32_t)0x00000003)           /*!<TMP period configuration         */
#define  TBS_TBSPRD_TMPPRD_1S                  ((uint32_t)0x00000000)           /*!<TMP period = 1s          */
#define  TBS_TBSPRD_TMPPRD_8S                  ((uint32_t)0x00000001)           /*!<TMP period = 8s          */
#define  TBS_TBSPRD_TMPPRD_32S                 ((uint32_t)0x00000002)           /*!<TMP period = 32s         */
#define  TBS_TBSPRD_TMPPRD_125mS               ((uint32_t)0x00000003)           /*!<TMP period = 1/8s        */

#define  TBS_TBSPRD_VBATPRD                    ((uint32_t)0x0000000C)           /*!<Vbat detect period configuration      */
#define  TBS_TBSPRD_VBATPRD_1S                 ((uint32_t)0x00000000)           /*!<Vbat detect period = 1s     */
#define  TBS_TBSPRD_VBATPRD_4S                 ((uint32_t)0x00000004)           /*!<Vbat detect period = 4s     */
#define  TBS_TBSPRD_VBATPRD_8S                 ((uint32_t)0x00000008)           /*!<Vbat detect period = 8s     */
#define  TBS_TBSPRD_VBATPRD_32S                ((uint32_t)0x0000000C)           /*!<Vbat detect period = 32s    */

#define  TBS_TBSPRD_VCCPRD                     ((uint32_t)0x00000030)           /*!<VCC detect period configuration       */
#define  TBS_TBSPRD_VCCPRD_1S                  ((uint32_t)0x00000000)           /*!<VCC detect period = 1s      */
#define  TBS_TBSPRD_VCCPRD_4S                  ((uint32_t)0x00000010)           /*!<VCC detect period = 4s      */
#define  TBS_TBSPRD_VCCPRD_8S                  ((uint32_t)0x00000020)           /*!<VCC detect period = 8s      */
#define  TBS_TBSPRD_VCCPRD_32S                 ((uint32_t)0x00000030)           /*!<VCC detect period = 32s     */
                                                                              /*!<  HT502x means VDDPRD in the manual */
#define  TBS_TBSPRD_ADC0PRD                    ((uint32_t)0x000000C0)           /*!<ADC0 detect period configuration      */
#define  TBS_TBSPRD_ADC0PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC0 detect period = 1s     */
#define  TBS_TBSPRD_ADC0PRD_4S                 ((uint32_t)0x00000040)           /*!<ADC0 detect period = 4s     */
#define  TBS_TBSPRD_ADC0PRD_8S                 ((uint32_t)0x00000080)           /*!<ADC0 detect period = 8s     */
#define  TBS_TBSPRD_ADC0PRD_32S                ((uint32_t)0x000000C0)          /*!<ADC0 detect period = 32s     */

#define  TBS_TBSPRD_ADC1PRD                    ((uint32_t)0x00000300)           /*!<ADC1 detect period configuration      */
#define  TBS_TBSPRD_ADC1PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC1 detect period = 1s     */
#define  TBS_TBSPRD_ADC1PRD_4S                 ((uint32_t)0x00000100)           /*!<ADC1 detect period = 4s     */
#define  TBS_TBSPRD_ADC1PRD_8S                 ((uint32_t)0x00000200)           /*!<ADC1 detect period = 8s     */
#define  TBS_TBSPRD_ADC1PRD_32S                ((uint32_t)0x00000300)           /*!<ADC1 detect period = 32s    */

#define  TBS_TBSPRD_ADC2PRD                    ((uint32_t)0x00000C00)           /*!<ADC2 detect period configuration      */
#define  TBS_TBSPRD_ADC2PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC2 detect period = 1s     */
#define  TBS_TBSPRD_ADC2PRD_4S                 ((uint32_t)0x00000400)           /*!<ADC2 detect period = 4s     */
#define  TBS_TBSPRD_ADC2PRD_8S                 ((uint32_t)0x00000800)           /*!<ADC2 detect period = 8s     */
#define  TBS_TBSPRD_ADC2PRD_32S                ((uint32_t)0x00000C00)           /*!<ADC2 detect period = 32s    */

#if  defined  USE_TBS_TBSPRD_ADC3PRD
#define  TBS_TBSPRD_ADC3PRD                    ((uint32_t)0x00003000)           /*!<ADC3 detect period configuration      */
#define  TBS_TBSPRD_ADC3PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC3 detect period = 1s     */
#define  TBS_TBSPRD_ADC3PRD_4S                 ((uint32_t)0x00001000)           /*!<ADC3 detect period = 4s     */
#define  TBS_TBSPRD_ADC3PRD_8S                 ((uint32_t)0x00002000)           /*!<ADC3 detect period = 8s     */
#define  TBS_TBSPRD_ADC3PRD_32S                ((uint32_t)0x00003000)           /*!<ADC3 detect period = 32s    */
#endif

#if  defined  USE_TBS_TBSPRD_ADC4PRD
#define  TBS_TBSPRD_ADC4PRD                    ((uint32_t)0x0000C000)           /*!<ADC4 detect period configuration      */
#define  TBS_TBSPRD_ADC4PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC4 detect period = 1s     */
#define  TBS_TBSPRD_ADC4PRD_4S                 ((uint32_t)0x00004000)           /*!<ADC4 detect period = 4s     */
#define  TBS_TBSPRD_ADC4PRD_8S                 ((uint32_t)0x00008000)           /*!<ADC4 detect period = 8s     */
#define  TBS_TBSPRD_ADC4PRD_32S                ((uint32_t)0x0000C000)           /*!<ADC4 detect period = 32s    */
#endif

#if  defined  USE_TBS_TBSPRD_ADC5PRD
#define  TBS_TBSPRD_ADC5PRD                    ((uint32_t)0x00030000)           /*!<ADC5 detect period configuration      */
#define  TBS_TBSPRD_ADC5PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC5 detect period = 1s     */
#define  TBS_TBSPRD_ADC5PRD_4S                 ((uint32_t)0x00010000)           /*!<ADC5 detect period = 4s     */
#define  TBS_TBSPRD_ADC5PRD_8S                 ((uint32_t)0x00020000)           /*!<ADC5 detect period = 8s     */
#define  TBS_TBSPRD_ADC5PRD_32S                ((uint32_t)0x00030000)           /*!<ADC5 detect period = 32s    */
#endif

#if  defined  USE_TBS_TBSPRD_ADC6PRD
#define  TBS_TBSPRD_ADC6PRD                    ((uint32_t)0x000C0000)           /*!<ADC6 detect period configuration      */
#define  TBS_TBSPRD_ADC6PRD_1S                 ((uint32_t)0x00000000)           /*!<ADC6 detect period = 1s     */
#define  TBS_TBSPRD_ADC6PRD_4S                 ((uint32_t)0x00040000)           /*!<ADC6 detect period = 4s     */
#define  TBS_TBSPRD_ADC6PRD_8S                 ((uint32_t)0x00080000)           /*!<ADC6 detect period = 8s     */
#define  TBS_TBSPRD_ADC6PRD_32S                ((uint32_t)0x000C0000)           /*!<ADC6 detect period = 32s    */
#endif

#endif


#if  defined  USE_TBS_MCU                                                     
#define  TBS_TBSPRD_TMPPRD                       ((uint32_t)0x00000007)           /*!<TMP period configuration */
#define  TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S         ((uint32_t)0x00000000)           /*!<TMP period = 0.5s / 8s   */
#define  TBS_TBSPRD_TMPPRD_OSC1S_MEM4S           ((uint32_t)0x00000001)           /*!<TMP period = 1s   / 4s   */
#define  TBS_TBSPRD_TMPPRD_OSC2S_MEM2S           ((uint32_t)0x00000002)           /*!<TMP period = 2s   / 2s   */
#define  TBS_TBSPRD_TMPPRD_OSC4S_MEM1S           ((uint32_t)0x00000003)           /*!<TMP period = 4s   / 1s   */
#define  TBS_TBSPRD_TMPPRD_OSC8S_MEM0P5S         ((uint32_t)0x00000004)           /*!<TMP period = 8s   / 0.5s */
#define  TBS_TBSPRD_TMPPRD_OSC16S_MEM125mS       ((uint32_t)0x00000005)           /*!<TMP period = 16s  / 125ms*/
#define  TBS_TBSPRD_TMPPRD_OSC32S_MEM31mS        ((uint32_t)0x00000006)           /*!<TMP period = 32s  / 31ms */
#define  TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS         ((uint32_t)0x00000007)           /*!<TMP period = 64s  / 8ms  */

#if defined  USE_TBS_TBSPRD_TDVREFPRD
#define  TBS_TBSPRD_TDVREFPRD                    ((uint32_t)0x00000018)           /*!<EMU module VREF detect period configuration   */
#define  TBS_TBSPRD_TDVREFPRD_1S                 ((uint32_t)0x00000000)           /*!<VREF detect period = 1s     */
#define  TBS_TBSPRD_TDVREFPRD_2S                 ((uint32_t)0x00000008)           /*!<VREF detect period = 2s     */
#define  TBS_TBSPRD_TDVREFPRD_8S                 ((uint32_t)0x00000010)           /*!<VREF detect period = 8s     */
#define  TBS_TBSPRD_TDVREFPRD_16S                ((uint32_t)0x00000018)           /*!<VREF detect period = 16s    */
#else
#define  TBS_TBSPRD_VBATPRD                      ((uint32_t)0x00000018)           /*!<Vbat detect period configuration      */
#define  TBS_TBSPRD_VBATPRD_1S                   ((uint32_t)0x00000000)           /*!<Vbat detect period = 1s     */
#define  TBS_TBSPRD_VBATPRD_2S                   ((uint32_t)0x00000008)           /*!<Vbat detect period = 2s     */
#define  TBS_TBSPRD_VBATPRD_8S                   ((uint32_t)0x00000010)           /*!<Vbat detect period = 8s     */
#define  TBS_TBSPRD_VBATPRD_16S                  ((uint32_t)0x00000018)           /*!<Vbat detect period = 16s    */
#endif

#define  TBS_TBSPRD_ADC0PRD                      ((uint32_t)0x00000060)           /*!<ADC0 detect period configuration     */
#define  TBS_TBSPRD_ADC0PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC0 detect period = 1s     */
#define  TBS_TBSPRD_ADC0PRD_2S                   ((uint32_t)0x00000020)           /*!<ADC0 detect period = 2s     */
#define  TBS_TBSPRD_ADC0PRD_8S                   ((uint32_t)0x00000040)           /*!<ADC0 detect period = 8s     */
#define  TBS_TBSPRD_ADC0PRD_16S                  ((uint32_t)0x00000060)           /*!<ADC0 detect period = 16s    */

#define  TBS_TBSPRD_ADC1PRD                      ((uint32_t)0x00000180)           /*!<ADC1 detect period configuration      */
#define  TBS_TBSPRD_ADC1PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC1 detect period = 1s     */
#define  TBS_TBSPRD_ADC1PRD_2S                   ((uint32_t)0x00000080)           /*!<ADC1 detect period = 2s     */
#define  TBS_TBSPRD_ADC1PRD_8S                   ((uint32_t)0x00000100)           /*!<ADC1 detect period = 8s     */
#define  TBS_TBSPRD_ADC1PRD_16S                  ((uint32_t)0x00000180)           /*!<ADC1 detect period = 16s    */

#define  TBS_TBSPRD_VCCPRD                       ((uint32_t)0x00000600)           /*!<VCC detect period configuration       */
#define  TBS_TBSPRD_VCCPRD_1S                    ((uint32_t)0x00000000)           /*!<VCC detect period = 1s      */
#define  TBS_TBSPRD_VCCPRD_2S                    ((uint32_t)0x00000200)           /*!<VCC detect period = 2s      */
#define  TBS_TBSPRD_VCCPRD_8S                    ((uint32_t)0x00000400)           /*!<VCC detect period = 8s      */
#define  TBS_TBSPRD_VCCPRD_16S                   ((uint32_t)0x00000600)           /*!<VCC detect period = 16s     */

#if  defined  USE_TBS_TBSPRD_ADC3PRD
#define  TBS_TBSPRD_ADC3PRD                      ((uint32_t)0x00001800)           /*!<ADC3 detect period configuration        */
#define  TBS_TBSPRD_ADC3PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC3 detect period = 1s     */
#define  TBS_TBSPRD_ADC3PRD_2S                   ((uint32_t)0x00000800)           /*!<ADC3 detect period = 2s     */
#define  TBS_TBSPRD_ADC3PRD_8S                   ((uint32_t)0x00001000)           /*!<ADC3 detect period = 8s     */
#define  TBS_TBSPRD_ADC3PRD_16S                  ((uint32_t)0x00001800)           /*!<ADC3 detect period = 16s    */
#endif

#if  defined  USE_TBS_TBSPRD_ADC4PRD
#define  TBS_TBSPRD_ADC4PRD                      ((uint32_t)0x00006000)           /*!<ADC4 detect period configuration        */
#define  TBS_TBSPRD_ADC4PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC4 detect period = 1s     */
#define  TBS_TBSPRD_ADC4PRD_2S                   ((uint32_t)0x00002000)           /*!<ADC4 detect period = 2s     */
#define  TBS_TBSPRD_ADC4PRD_8S                   ((uint32_t)0x00004000)           /*!<ADC4 detect period = 8s     */
#define  TBS_TBSPRD_ADC4PRD_16S                  ((uint32_t)0x00006000)           /*!<ADC4 detect period = 16s    */
#endif

#if  defined  USE_TBS_TBSPRD_ADC5PRD
#define  TBS_TBSPRD_ADC5PRD                      ((uint32_t)0x00018000)           /*!<ADC5 detect period configuration     */
#define  TBS_TBSPRD_ADC5PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC5 detect period = 1s    */
#define  TBS_TBSPRD_ADC5PRD_2S                   ((uint32_t)0x00008000)           /*!<ADC5 detect period = 2s    */
#define  TBS_TBSPRD_ADC5PRD_8S                   ((uint32_t)0x00010000)           /*!<ADC5 detect period = 8s    */
#define  TBS_TBSPRD_ADC5PRD_16S                  ((uint32_t)0x00018000)           /*!<ADC5 detect period = 16s   */
#endif

#if  defined  USE_TBS_TBSPRD_ADC6PRD
#define  TBS_TBSPRD_ADC6PRD                      ((uint32_t)0x00060000)           /*!<ADC6 detect period configuration     */
#define  TBS_TBSPRD_ADC6PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC6 detect period = 1s    */
#define  TBS_TBSPRD_ADC6PRD_2S                   ((uint32_t)0x00020000)           /*!<ADC6 detect period = 2s    */
#define  TBS_TBSPRD_ADC6PRD_8S                   ((uint32_t)0x00040000)           /*!<ADC6 detect period = 8s    */
#define  TBS_TBSPRD_ADC6PRD_16S                  ((uint32_t)0x00060000)           /*!<ADC6 detect period = 16s   */
#endif

#if  defined  USE_TBS_TBSPRD_ADC7PRD
#define  TBS_TBSPRD_ADC7PRD                      ((uint32_t)0x00180000)           /*!<ADC7 detect period configuration     */
#define  TBS_TBSPRD_ADC7PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC7 detect period = 1s    */
#define  TBS_TBSPRD_ADC7PRD_2S                   ((uint32_t)0x00080000)           /*!<ADC7 detect period = 2s    */
#define  TBS_TBSPRD_ADC7PRD_8S                   ((uint32_t)0x00100000)           /*!<ADC7 detect period = 8s    */
#define  TBS_TBSPRD_ADC7PRD_16S                  ((uint32_t)0x00180000)           /*!<ADC7 detect period = 16s   */
#endif

#if  defined  USE_TBS_TBSPRD_ADC8PRD
#define  TBS_TBSPRD_ADC8PRD                      ((uint32_t)0x00600000)           /*!<ADC8 detect period configuration     */
#define  TBS_TBSPRD_ADC8PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC8 detect period = 1s    */
#define  TBS_TBSPRD_ADC8PRD_2S                   ((uint32_t)0x00200000)           /*!<ADC8 detect period = 2s    */
#define  TBS_TBSPRD_ADC8PRD_8S                   ((uint32_t)0x00400000)           /*!<ADC8 detect period = 8s    */
#define  TBS_TBSPRD_ADC8PRD_16S                  ((uint32_t)0x00600000)           /*!<ADC8 detect period = 16s   */
#endif

#if  defined  USE_TBS_TBSPRD_ADC9PRD
#define  TBS_TBSPRD_ADC9PRD                      ((uint32_t)0x01800000)           /*!<ADC9 detect period configuration     */
#define  TBS_TBSPRD_ADC9PRD_1S                   ((uint32_t)0x00000000)           /*!<ADC9 detect period = 1s    */
#define  TBS_TBSPRD_ADC9PRD_2S                   ((uint32_t)0x00800000)           /*!<ADC9 detect period = 2s    */
#define  TBS_TBSPRD_ADC9PRD_8S                   ((uint32_t)0x01000000)           /*!<ADC9 detect period = 8s    */
#define  TBS_TBSPRD_ADC9PRD_16S                  ((uint32_t)0x01800000)           /*!<ADC9 detect period = 16s   */
#endif

#endif

/*************************  Bit definition for VCCDAT register of HT_TBS_TypeDef ************************/
#define  TBS_VCCDAT                            ((uint32_t)0x0000ffff)           /*!<VCC measurement register         */

/************************  Bit definition for ADC0CMP register of HT_TBS_TypeDef ************************/
#if  defined  USE_TBS_ADC0CMP
#define  TBS_ADC0CMP                           ((uint32_t)0x0000ffff)           /*!<ADC0 compare register        */

#if  defined  USE_TBS_ADC3CMP
#define  TBS_ADC3CMP                           ((uint32_t)0x0000ffff)           /*!<ADC3 compare register        */
#endif

#if  defined  USE_TBS_ADC4CMP
#define  TBS_ADC4CMP                           ((uint32_t)0x0000ffff)           /*!<ADC4 compare register        */
#endif

#if  defined  USE_TBS_ADC5CMP
#define  TBS_ADC5CMP                           ((uint32_t)0x0000ffff)           /*!<ADC5 compare register        */
#endif

#endif

/*************************  Bit definition for TRIREQ register of HT_TBS_TypeDef ************************/
#if  defined  USE_TBS_SOC

#if  defined  USE_TBS_TRIREQ
#define  TBS_TRIREQ                              ((uint32_t)0x0000e0bf)           /*!<ADC quick trigger register   */
#define  TBS_TRIREQ_TMPTRI                       ((uint32_t)0x00000001)           /*!<TMP quick trigger            */
#define  TBS_TRIREQ_VBATTRI                      ((uint32_t)0x00000002)           /*!<VBAT quick trigger           */
#define  TBS_TRIREQ_VDDTRI                       ((uint32_t)0x00000004)           /*!<VCC quick trigger            */
#define  TBS_TRIREQ_ADC0TRI                      ((uint32_t)0x00000008)           /*!<ADC0 quick trigger           */
#define  TBS_TRIREQ_ADC1TRI                      ((uint32_t)0x00000010)           /*!<ADC1 quick trigger           */
#define  TBS_TRIREQ_ADC2TRI                      ((uint32_t)0x00000020)           /*!<ADC2 quick trigger           */
#define  TBS_TRIREQ_ADC3TRI                      ((uint32_t)0x00000080)           /*!<ADC3 quick trigger           */
#define  TBS_TRIREQ_ADC4TRI                      ((uint32_t)0x00002000)           /*!<ADC4 quick trigger           */
#define  TBS_TRIREQ_ADC5TRI                      ((uint32_t)0x00004000)           /*!<ADC5 quick trigger           */

#if  defined  USE_TBS_ADC6TRI
#define  TBS_TRIREQ_ADC6TRI                      ((uint32_t)0x00008000)           /*!<ADC6 quick trigger           */
#endif

#endif

#endif


#if  defined  USE_TBS_MCU

#if  defined  USE_TBS_TRIREQ

#if  defined  HT6x3x  ||  defined  HT6x2xK
#define  TBS_TRIREQ                              ((uint32_t)0x000000ff)           /*!<ADC quick trigger register   */
#endif

#if  defined  HT762x  ||  defined  HT772x
#define  TBS_TRIREQ                              ((uint32_t)0x0000ffff)           /*!<ADC quick trigger register     */
#endif

#if  defined  HT633x  ||  defined  HT633xH
#define  TBS_TRIREQ                              ((uint32_t)0x00000fff)           /*!<ADC quick trigger register     */
#endif

#define  TBS_TRIREQ_TMPTRI                       ((uint32_t)0x00000001)           /*!<TMP quick trigger              */

#if  defined  USE_TBS_TRIREQ_TDVREFTRI
#define  TBS_TRIREQ_TDVREFTRI                    ((uint32_t)0x00000002)           /*!<EMU module VREF quick trigger  */
#else
#define  TBS_TRIREQ_VBATTRI                      ((uint32_t)0x00000002)           /*!<VBAT quick trigger           */
#endif

#define  TBS_TRIREQ_ADC0TRI                      ((uint32_t)0x00000004)           /*!<ADC0 quick trigger             */
#define  TBS_TRIREQ_ADC1TRI                      ((uint32_t)0x00000008)           /*!<ADC1 quick trigger             */
#define  TBS_TRIREQ_VCCTRI                       ((uint32_t)0x00000010)           /*!<VCC quick trigger              */
#define  TBS_TRIREQ_ADC3TRI                      ((uint32_t)0x00000020)           /*!<ADC3 quick trigger             */
#define  TBS_TRIREQ_ADC4TRI                      ((uint32_t)0x00000040)           /*!<ADC4 quick trigger             */
#define  TBS_TRIREQ_ADC5TRI                      ((uint32_t)0x00000080)           /*!<ADC5 quick trigger             */

#if  defined  USE_TBS_VTP
#define  TBS_TRIREQ_VTP0TRI                      ((uint32_t)0x00000100)           /*!<Temperature measurement terminal channel 0 quick trigger  */
#define  TBS_TRIREQ_VTP1TRI                      ((uint32_t)0x00000200)           /*!<Temperature measurement terminal channel 1 quick trigger  */
#define  TBS_TRIREQ_VTP2TRI                      ((uint32_t)0x00000400)           /*!<Temperature measurement terminal channel 2 quick trigger  */
#define  TBS_TRIREQ_VTP3TRI                      ((uint32_t)0x00000800)           /*!<Temperature measurement terminal channel 3 quick trigger  */
#define  TBS_TRIREQ_VTP4TRI                      ((uint32_t)0x00001000)           /*!<Temperature measurement terminal channel 4 quick trigger  */
#define  TBS_TRIREQ_VTP5TRI                      ((uint32_t)0x00002000)           /*!<Temperature measurement terminal channel 5 quick trigger  */
#define  TBS_TRIREQ_VTP6TRI                      ((uint32_t)0x00004000)           /*!<Temperature measurement terminal channel 6 quick trigger  */
#define  TBS_TRIREQ_VTP7TRI                      ((uint32_t)0x00008000)           /*!<Temperature measurement terminal channel 7 quick trigger  */
#endif

#if  defined  USE_TBS_ADC6TRI
#define  TBS_TRIREQ_ADC6TRI                      ((uint32_t)0x00000100)           /*!<ADC6 quick trigger             */
#endif

#if  defined  USE_TBS_ADC7TRI
#define  TBS_TRIREQ_ADC7TRI                      ((uint32_t)0x00000200)           /*!<ADC7 quick trigger             */
#endif

#if  defined  USE_TBS_ADC8TRI
#define  TBS_TRIREQ_ADC8TRI                      ((uint32_t)0x00000400)           /*!<ADC8 quick trigger             */
#endif

#if  defined  USE_TBS_ADC9TRI
#define  TBS_TRIREQ_ADC9TRI                      ((uint32_t)0x00000800)           /*!<ADC9 quick trigger             */
#endif

#endif

#endif

/*************************  Bit definition for TBSINJECTCTRL register of HT_TBS_TypeDef ************************/
#if  defined  USE_TBS_SOC

#if  defined  USE_TBS_TBSINJECTCTRL
#define  TBS_TBSINJECTCTRL                       ((uint32_t)0x000000f1)         /*!<TBS inject mode control register  */
#define  TBS_TBSINJECTCTRL_INJECTMODE_EN         ((uint32_t)0x00000001)         /*!<ADC inject mode enable control    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL        ((uint32_t)0x000000f0)         /*!<ADC inject mode channel select    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TMP    ((uint32_t)0x00000000)         /*!<ADC inject mode channel = TMP     */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VBAT   ((uint32_t)0x00000010)         /*!<ADC inject mode channel = VBAT    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VDD    ((uint32_t)0x00000020)         /*!<ADC inject mode channel = VDD     */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC0   ((uint32_t)0x00000030)         /*!<ADC inject mode channel = ADC0    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC1   ((uint32_t)0x00000040)         /*!<ADC inject mode channel = ADC1    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC2   ((uint32_t)0x00000050)         /*!<ADC inject mode channel = ADC2    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC3   ((uint32_t)0x00000060)         /*!<ADC inject mode channel = ADC3    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC4   ((uint32_t)0x00000070)         /*!<ADC inject mode channel = ADC4    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC5   ((uint32_t)0x00000080)         /*!<ADC inject mode channel = ADC5    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC6   ((uint32_t)0x00000090)         /*!<ADC inject mode channel = ADC6    */
#endif

#endif

#if  defined  USE_TBS_MCU

#if  defined  USE_TBS_TBSINJECTCTRL

#if  defined  HT762x  ||  defined  HT772x
#define  TBS_TBSINJECTCTRL                       ((uint32_t)0x00004771)         /*!<TBS inject mode control register  */
#define  TBS_TBSINJECTCTRL_DEFAULT               ((uint32_t)0x00000400)         /*!<TBS inject mode control register default value */
#endif
#if  defined  HT6x2xK
#define  TBS_TBSINJECTCTRL                       ((uint32_t)0x0000C771)         /*!<TBS inject mode control register  */
#define  TBS_TBSINJECTCTRL_DEFAULT               ((uint32_t)0x00000500)         /*!<TBS inject mode control register default value */
#endif

#if  defined  HT633x  ||  defined  HT633xH
#define  TBS_TBSINJECTCTRL                       ((uint32_t)0x000000f1)         /*!<TBS inject mode control register  */
#define  TBS_TBSINJECTCTRL_DEFAULT               ((uint32_t)0x00000000)         /*!<TBS inject mode control register default value */
#endif

#define  TBS_TBSINJECTCTRL_INJECTMODE_EN         ((uint32_t)0x00000001)         /*!<ADC inject mode enable control    */

#if  !defined  USE_TBS_INJECTCHEL_SEL_4BIT
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL        ((uint32_t)0x00000070)         /*!<ADC inject mode channel select    */
#else
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL        ((uint32_t)0x000000f0)         /*!<ADC inject mode channel select    */
#endif

#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TMP    ((uint32_t)0x00000000)         /*!<ADC inject mode channel = TMP     */

#if  defined  USE_TBS_INJECTCTRL_TDVREF
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_TDVREF ((uint32_t)0x00000010)         /*!<ADC inject mode channel = VBAT    */
#else
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VBAT   ((uint32_t)0x00000010)         /*!<ADC inject mode channel = VBAT    */
#endif

#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC0   ((uint32_t)0x00000020)         /*!<ADC inject mode channel = ADC0    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC1   ((uint32_t)0x00000030)         /*!<ADC inject mode channel = ADC1    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_VCC    ((uint32_t)0x00000040)         /*!<ADC inject mode channel = VCC     */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC3   ((uint32_t)0x00000050)         /*!<ADC inject mode channel = ADC3    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC4   ((uint32_t)0x00000060)         /*!<ADC inject mode channel = ADC4    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC5   ((uint32_t)0x00000070)         /*!<ADC inject mode channel = ADC5    */

#if  defined  USE_TBS_INJECTCHEL_SEL_4BIT
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC6   ((uint32_t)0x00000080)         /*!<ADC inject mode channel = ADC6    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC7   ((uint32_t)0x00000090)         /*!<ADC inject mode channel = ADC7    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC8   ((uint32_t)0x000000a0)         /*!<ADC inject mode channel = ADC8    */
#define  TBS_TBSINJECTCTRL_INJECTCHEL_SEL_ADC9   ((uint32_t)0x000000b0)         /*!<ADC inject mode channel = ADC9    */
#endif

#if  defined  USE_TBS_TBSINJECTCTRL_INJECTCLK
#define  TBS_TBSINJECTCTRL_INJECTCLK_SEL         ((uint32_t)0x00000700)         /*!<TBS inject mode clock division select*/
#define  TBS_INJECTCLK_SEL_END                   ((uint32_t)0x00000700)         /*!<TBS inject mode clock division select end bit*/
#define  TBS_TBSINJECTCTRL_INJECTCLK_EN          ((uint32_t)0x00004000)         /*!<TBS inject mode clock contorl enable   */
#endif

#if  defined  USE_TBS_TBSINJECTCTRL_EN
#define  TBS_TBSINJECTCTRL_EN					 ((uint32_t)0x00008000)         /*!<TBS inject mode new function contorl enable   */
#endif

#endif

#endif

#if  defined  USE_TBS_VTP
/*************************  Bit definition for VTPPRD register of HT_TBS_TypeDef ************************/
#define  TBS_VTPPRD                               ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal period configuration register  */

#define  TBS_VTPPRD_VTP0PRD                       ((uint32_t)0x00000003)           /*!<Temperature measurement terminal channel 0 measurement period coniguration           */
#define  TBS_VTPPRD_VTP0PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 0 measurement period = 1s         */
#define  TBS_VTPPRD_VTP0PRD_2S                    ((uint32_t)0x00000001)           /*!<Channel 0 measurement period = 2s         */
#define  TBS_VTPPRD_VTP0PRD_8S                    ((uint32_t)0x00000002)           /*!<Channel 0 measurement period = 8s         */
#define  TBS_VTPPRD_VTP0PRD_16S                   ((uint32_t)0x00000003)           /*!<Channel 0 measurement period = 16s        */

#define  TBS_VTPPRD_VTP1PRD                       ((uint32_t)0x0000000c)           /*!<Temperature measurement terminal channel 1 measurement period coniguration            */
#define  TBS_VTPPRD_VTP1PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 1 measurement period = 1s         */
#define  TBS_VTPPRD_VTP1PRD_2S                    ((uint32_t)0x00000004)           /*!<Channel 1 measurement period = 2s         */
#define  TBS_VTPPRD_VTP1PRD_8S                    ((uint32_t)0x00000008)           /*!<Channel 1 measurement period = 8s         */
#define  TBS_VTPPRD_VTP1PRD_16S                   ((uint32_t)0x0000000c)           /*!<Channel 1 measurement period = 16s        */

#define  TBS_VTPPRD_VTP2PRD                       ((uint32_t)0x00000030)           /*!<Temperature measurement terminal channel 2 measurement period coniguration            */
#define  TBS_VTPPRD_VTP2PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 2 measurement period = 1s         */
#define  TBS_VTPPRD_VTP2PRD_2S                    ((uint32_t)0x00000010)           /*!<Channel 2 measurement period = 2s         */
#define  TBS_VTPPRD_VTP2PRD_8S                    ((uint32_t)0x00000020)           /*!<Channel 2 measurement period = 8s         */
#define  TBS_VTPPRD_VTP2PRD_16S                   ((uint32_t)0x00000030)           /*!<Channel 2 measurement period = 16s        */

#define  TBS_VTPPRD_VTP3PRD                       ((uint32_t)0x000000c0)           /*!<Temperature measurement terminal channel 3 measurement period coniguration            */
#define  TBS_VTPPRD_VTP3PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 3 measurement period = 1s         */
#define  TBS_VTPPRD_VTP3PRD_2S                    ((uint32_t)0x00000040)           /*!<Channel 3 measurement period = 2s         */
#define  TBS_VTPPRD_VTP3PRD_8S                    ((uint32_t)0x00000080)           /*!<Channel 3 measurement period = 8s         */
#define  TBS_VTPPRD_VTP3PRD_16S                   ((uint32_t)0x000000c0)           /*!<Channel 3 measurement period = 16s        */

#define  TBS_VTPPRD_VTP4PRD                       ((uint32_t)0x00000300)           /*!<Temperature measurement terminal channel 4 measurement period coniguration            */
#define  TBS_VTPPRD_VTP4PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 4 measurement period = 1s         */
#define  TBS_VTPPRD_VTP4PRD_2S                    ((uint32_t)0x00000100)           /*!<Channel 4 measurement period = 2s         */
#define  TBS_VTPPRD_VTP4PRD_8S                    ((uint32_t)0x00000200)           /*!<Channel 4 measurement period = 8s         */
#define  TBS_VTPPRD_VTP4PRD_16S                   ((uint32_t)0x00000300)           /*!<Channel 4 measurement period = 16s        */

#define  TBS_VTPPRD_VTP5PRD                       ((uint32_t)0x00000c00)           /*!<Temperature measurement terminal channel 5 measurement period coniguration            */
#define  TBS_VTPPRD_VTP5PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 5 measurement period = 1s         */
#define  TBS_VTPPRD_VTP5PRD_2S                    ((uint32_t)0x00000400)           /*!<Channel 5 measurement period = 2s         */
#define  TBS_VTPPRD_VTP5PRD_8S                    ((uint32_t)0x00000800)           /*!<Channel 5 measurement period = 8s         */
#define  TBS_VTPPRD_VTP5PRD_16S                   ((uint32_t)0x00000c00)           /*!<Channel 5 measurement period = 16s        */

#define  TBS_VTPPRD_VTP6PRD                       ((uint32_t)0x00003000)           /*!<Temperature measurement terminal channel 6 measurement period coniguration            */
#define  TBS_VTPPRD_VTP6PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 6 measurement period = 1s         */
#define  TBS_VTPPRD_VTP6PRD_2S                    ((uint32_t)0x00001000)           /*!<Channel 6 measurement period = 2s         */
#define  TBS_VTPPRD_VTP6PRD_8S                    ((uint32_t)0x00002000)           /*!<Channel 6 measurement period = 8s         */
#define  TBS_VTPPRD_VTP6PRD_16S                   ((uint32_t)0x00003000)           /*!<Channel 6 measurement period = 16s        */

#define  TBS_VTPPRD_VTP7PRD                       ((uint32_t)0x0000c000)           /*!<Temperature measurement terminal channel 7 measurement period coniguration            */
#define  TBS_VTPPRD_VTP7PRD_1S                    ((uint32_t)0x00000000)           /*!<Channel 7 measurement period = 1s         */
#define  TBS_VTPPRD_VTP7PRD_2S                    ((uint32_t)0x00004000)           /*!<Channel 7 measurement period = 2s         */
#define  TBS_VTPPRD_VTP7PRD_8S                    ((uint32_t)0x00008000)           /*!<Channel 7 measurement period = 8s         */
#define  TBS_VTPPRD_VTP7PRD_16S                   ((uint32_t)0x0000c000)           /*!<Channel 7 measurement period = 16s        */

/*************************  Bit definition for VTP0DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP0DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 0 measurement output register  */
/*************************  Bit definition for VTP1DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP1DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 1 measurement output register  */
/*************************  Bit definition for VTP2DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP2DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 2 measurement output register  */
/*************************  Bit definition for VTP3DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP3DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 3 measurement output register  */
/*************************  Bit definition for VTP4DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP4DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 4 measurement output register  */
/*************************  Bit definition for VTP5DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP5DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 5 measurement output register  */
/*************************  Bit definition for VTP6DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP6DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 6 measurement output register  */
/*************************  Bit definition for VTP7DAT register of HT_TBS_TypeDef ************************/
#define  TBS_VTP7DAT                              ((uint32_t)0x0000ffff)           /*!<Temperature measurement terminal channel 7 measurement output register  */
#endif


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of PMU Module
**********************************************************************************************************
*/
/*************************  Bit definition for PMUCON register of HT_PMU_TypeDef ************************/
#if defined USE_PMUCON_TYPE3
#if defined HT633x
#define  PMU_PMUCON                              ((uint32_t)0x19f7f)          /*!<PMU control register */
#else
#define  PMU_PMUCON                              ((uint32_t)0x807f)           /*!<PMU control register */
#endif
#elif defined USE_PMUCON_TYPE2
#define  PMU_PMUCON                              ((uint32_t)0x801f)           /*!<PMU control register */
#elif defined USE_PMUCON_TYPE1
#define  PMU_PMUCON                              ((uint32_t)0x0017)           /*!<PMU control register */
#else
#define  PMU_PMUCON                              ((uint32_t)0x803f)           /*!<PMU control register */
#endif
#define  PMU_PMUCON_BORDETEN                     ((uint32_t)0x0001)           /*!<BOR_DET enable       */
#define  PMU_PMUCON_BORRST                       ((uint32_t)0x0002)           /*!<BOR interrupt or reset     */
#define  PMU_PMUCON_LVD0DETEN                    ((uint32_t)0x0004)           /*!<LVDIN0 enable        */
#if  defined USE_LVDIN1
#define  PMU_PMUCON_LVD1DETEN                    ((uint32_t)0x0008)           /*!<LVDIN1 enable        */
#endif
#define  PMU_PMUCON_HoldLDO                      ((uint32_t)0x0010)           /*!<normal_LDO enable in Hold mode  */

#if defined USE_LPCFG                            
#define  PMU_PMUCON_HoldVREF                     ((uint32_t)0x1000)
#define  PMU_PMUCON_HoldSRAM0                    ((uint32_t)0x0100)
#define  PMU_PMUCON_HoldSRAM1                    ((uint32_t)0x0200)
#define  PMU_PMUCON_HoldSRAM2                    ((uint32_t)0x0400)
#define  PMU_PMUCON_FLASHDPD                     ((uint32_t)0x0800)

#define  PMU_LPMCFG                              ((uint32_t)0x1130)
#define  PMU_LPMCFG_LPRUNEN                      ((uint32_t)0x0100)
#define  PMU_LPMCFG_LPRUNSTA                     ((uint32_t)0x0100)

#define  PMU_LPMCFG_LDOSVL                       ((uint32_t)0x0030)           /*!<LDO output voltage config       */
#define  PMU_LPMCFG_LDOSVL_0                     ((uint32_t)0x0000)           /*!<LDO output voltage = 1.2v       */
#define  PMU_LPMCFG_LDOSVL_1                     ((uint32_t)0x0010)           /*!<LDO output voltage = 1.1v       */
#define  PMU_LPMCFG_LDOSVL_2                     ((uint32_t)0x0020)           /*!<LDO output voltage = 1.0v       */
#define  PMU_LPMCFG_LDOSVL_3                     ((uint32_t)0x0030)           /*!<LDO output voltage = 0.9v       */

#define  PMU_LDOVREF                             ((uint32_t)0x00ff7f0f)
#define  PMU_LDOVREF_TRIM_VREF                   ((uint32_t)0x00007000)
#define  PMU_LDOVREF_LVREF_TC                    ((uint32_t)0x00000f00)
#define  PMU_LDOVREF_LVREF_TV                    ((uint32_t)0x0000001f)
#define  PMU_LDOVREF_LDOVREF_WP                  ((uint32_t)0x00a50000)

#endif

#if  defined USE_POWDET
#define  PMU_PMUCON_POWDETEN                     ((uint32_t)0x0020)           /*!<POW_DET  enable      */
#endif
#if  defined  USE_LVDIN2
#define  PMU_PMUCON_LVD2DETEN                    ((uint32_t)0x0040)           /*!<LVDIN2 enable        */
#endif
#if  defined USE_DISCHARGE
#define  PMU_PMUCON_DisChargeEN                  ((uint32_t)0x8000)           /*!<Battery passivation enable      */
#endif

/*************************  Bit definition for VDETCFG register of HT_PMU_TypeDef ***********************/
#if defined USE_VDETCFG_MCU_TYPE1
#define  PMU_VDETCFG                             ((uint32_t)0x003f)           /*!<DET level config register */
#elif	defined USE_VDETCFG_SOC_TYPE1
#define  PMU_VDETCFG                             ((uint32_t)0x800f)           /*!<DET level config register */
#elif defined USE_VDETCFG_SOC_TYPE2
#define  PMU_VDETCFG                             ((uint32_t)0x80bf)           /*!<DET level config register */
#elif defined USE_VDETCFG_SOC_TYPE3
#define  PMU_VDETCFG                             ((uint32_t)0x801f)           /*!<DET level config register */
#else
#define  PMU_VDETCFG                             ((uint32_t)0xc1ff)           /*!<DET level config register */
#endif

#if  defined USE_BOR_SOC  
#define  PMU_VDETCFG_BORLVL                      ((uint32_t)0x0003)           /*!<BOR_DET detection threshold  */
#define  PMU_VDETCFG_BORLVL_2V2                  ((uint32_t)0x0001)           /*!<detection threshold = 2.2v       */
#define  PMU_VDETCFG_BORLVL_2V4                  ((uint32_t)0x0000)           /*!<detection threshold = 2.4v       */
#define  PMU_VDETCFG_BORLVL_2V6                  ((uint32_t)0x0003)           /*!<detection threshold = 2.6v       */
#define  PMU_VDETCFG_BORLVL_2V8                  ((uint32_t)0x0002)           /*!<detection threshold = 2.8v       */
#elif  defined USE_BOR_MCU
#define  PMU_VDETCFG_BORLVL                      ((uint32_t)0x0003)           /*!<BOR_DET detection threshold   */
#define  PMU_VDETCFG_BORLVL_2V0                  ((uint32_t)0x0001)           /*!<detection threshold = 2.0v       */
#define  PMU_VDETCFG_BORLVL_2V2                  ((uint32_t)0x0000)           /*!<detection threshold = 2.2v       */
#define  PMU_VDETCFG_BORLVL_2V6                  ((uint32_t)0x0003)           /*!<detection threshold = 2.6v       */
#define  PMU_VDETCFG_BORLVL_2V8                  ((uint32_t)0x0002)           /*!<detection threshold = 2.8v       */
#else                                                                         /*!<used for HT633x                  */
#define  PMU_VDETCFG_BORLVL                      ((uint32_t)0x0003)           /*!<BOR_DET detection threshold   */
#define  PMU_VDETCFG_BORLVL_1V65                 ((uint32_t)0x0000)           /*!<detection threshold = 1.65v      */
#define  PMU_VDETCFG_BORLVL_2V0                  ((uint32_t)0x0001)           /*!<detection threshold = 2.0v       */
#define  PMU_VDETCFG_BORLVL_2V4                  ((uint32_t)0x0002)           /*!<detection threshold = 2.4v       */
#define  PMU_VDETCFG_BORLVL_2V8                  ((uint32_t)0x0003)           /*!<detection threshold = 2.8v       */
#endif

#if  defined USE_VCCLVL_501x
#define  PMU_VDETCFG_VCCLVL                      ((uint32_t)0x000c)           /*!<VCC_DET detection threshold  */
#define  PMU_VDETCFG_VCCLVL_2V4                  ((uint32_t)0x0000)           /*!<detection threshold = 2.4V       */
#define  PMU_VDETCFG_VCCLVL_2V6                  ((uint32_t)0x0004)           /*!<detection threshold = 2.6V       */
#define  PMU_VDETCFG_VCCLVL_2V8                  ((uint32_t)0x0008)           /*!<detection threshold = 2.8V       */
#define  PMU_VDETCFG_VCCLVL_3V0                  ((uint32_t)0x000c)           /*!<detection threshold = 3.0V       */

#elif defined USE_VCCLVL_633x
#define  PMU_VDETCFG_VCCLVL                      ((uint32_t)0x003c)           /*!<VCC_DET detection threshold  */
#define  PMU_VDETCFG_VCCLVL_1V8                  ((uint32_t)0x0000)           /*!<detection threshold = 1.8V       */
#define  PMU_VDETCFG_VCCLVL_1V95                 ((uint32_t)0x0004)           /*!<detection threshold = 1.95V      */
#define  PMU_VDETCFG_VCCLVL_2V1                  ((uint32_t)0x0008)           /*!<detection threshold = 2.1V       */
#define  PMU_VDETCFG_VCCLVL_2V25                 ((uint32_t)0x000c)           /*!<detection threshold = 2.25V      */
#define  PMU_VDETCFG_VCCLVL_2V4                  ((uint32_t)0x0010)           /*!<detection threshold = 2.4V       */
#define  PMU_VDETCFG_VCCLVL_2V55                 ((uint32_t)0x0014)           /*!<detection threshold = 2.55V      */
#define  PMU_VDETCFG_VCCLVL_2V7                  ((uint32_t)0x0018)           /*!<detection threshold = 2.7V       */
#define  PMU_VDETCFG_VCCLVL_2V85                 ((uint32_t)0x001c)           /*!<detection threshold = 2.85V      */
#define  PMU_VDETCFG_VCCLVL_3V0                  ((uint32_t)0x0020)           /*!<detection threshold = 3.0V       */
#define  PMU_VDETCFG_VCCLVL_3V15                 ((uint32_t)0x0024)           /*!<detection threshold = 3.15V      */
#define  PMU_VDETCFG_VCCLVL_3V3                  ((uint32_t)0x0028)           /*!<detection threshold = 3.3V       */

#else    /*!<HT6x1x && HT6x2x && HT6x3x && HT502x      */
#define  PMU_VDETCFG_VCCLVL                      ((uint32_t)0x003c)           /*!<VCC_DET detection threshold  */
#define  PMU_VDETCFG_VCCLVL_2V4                  ((uint32_t)0x0000)           /*!<detection threshold = 2.4V       */
#define  PMU_VDETCFG_VCCLVL_2V6                  ((uint32_t)0x0004)           /*!<detection threshold = 2.6V       */
#define  PMU_VDETCFG_VCCLVL_2V8                  ((uint32_t)0x0008)           /*!<detection threshold = 2.8V       */
#define  PMU_VDETCFG_VCCLVL_3V0                  ((uint32_t)0x000c)           /*!<detection threshold = 3.0V       */
#define  PMU_VDETCFG_VCCLVL_3V2                  ((uint32_t)0x0010)           /*!<detection threshold = 3.2V       */
#define  PMU_VDETCFG_VCCLVL_3V4                  ((uint32_t)0x0014)           /*!<detection threshold = 3.4V       */
#define  PMU_VDETCFG_VCCLVL_3V6                  ((uint32_t)0x0018)           /*!<detection threshold = 3.6V       */
#define  PMU_VDETCFG_VCCLVL_3V8                  ((uint32_t)0x001c)           /*!<detection threshold = 3.8V       */
#define  PMU_VDETCFG_VCCLVL_4V0                  ((uint32_t)0x0020)           /*!<detection threshold = 4.0V       */
#define  PMU_VDETCFG_VCCLVL_4V2                  ((uint32_t)0x0024)           /*!<detection threshold = 4.2V       */
#define  PMU_VDETCFG_VCCLVL_4V4                  ((uint32_t)0x0028)           /*!<detection threshold = 4.4V       */
#define  PMU_VDETCFG_VCCLVL_4V6                  ((uint32_t)0x002c)           /*!<detection threshold = 4.6V       */
#define  PMU_VDETCFG_VCCLVL_4V8                  ((uint32_t)0x0030)           /*!<detection threshold = 4.8V       */
#define  PMU_VDETCFG_VCCLVL_5V0                  ((uint32_t)0x0034)           /*!<detection threshold = 5.0V       */
#endif
#if  defined USE_POWDET
#define  PMU_VDETCFG_POWLVL                      ((uint32_t)0x01c0)           /*!<POW_DET detection threshold  */
#define  PMU_VDETCFG_POWLVL_1P25mV               ((uint32_t)0x0000)           /*!<detection threshold = 1.25mV     */
#define  PMU_VDETCFG_POWLVL_2P5mV                ((uint32_t)0x0040)           /*!<detection threshold = 2.5mV      */
#define  PMU_VDETCFG_POWLVL_3P75mV               ((uint32_t)0x0080)           /*!<detection threshold = 3.75mV     */
#define  PMU_VDETCFG_POWLVL_5mV                  ((uint32_t)0x00c0)           /*!<detection threshold = 5mV        */
#define  PMU_VDETCFG_POWLVL_6P25mV               ((uint32_t)0x0100)           /*!<detection threshold = 6.25mV     */
#define  PMU_VDETCFG_POWLVL_7P5mV                ((uint32_t)0x0140)           /*!<detection threshold = 7.5mV      */
#define  PMU_VDETCFG_POWLVL_8P75mV               ((uint32_t)0x0180)           /*!<detection threshold = 8.75mV     */
#define  PMU_VDETCFG_POWLVL_10mV                 ((uint32_t)0x01c0)           /*!<detection threshold = 10mV       */
#endif

#if defined USE_DISCHARGE
#define  PMU_VDETCFG_DisChargeCTRL_1mA           ((uint32_t)0x0000)           /*!<Battery passivation current 1mA       */
#define  PMU_VDETCFG_DisChargeCTRL_2mA           ((uint32_t)0x8000)           /*!<Battery passivation current 2mA       */
#if  defined USE_DISCHARGE_MCU
#define  PMU_VDETCFG_DisChargeCTRL               ((uint32_t)0xc000)           /*!<Battery passivation current   */
#define  PMU_VDETCFG_DisChargeCTRL_50uA          ((uint32_t)0x4000)           /*!<Battery passivation current 50uA      */
#define  PMU_VDETCFG_DisChargeCTRL_100uA         ((uint32_t)0xc000)           /*!<Battery passivation current 100uA     */
#elif  defined USE_DISCHARGE_SOC
#define  PMU_VDETCFG_DisChargeCTRL               ((uint32_t)0x8000)           /*!<Battery passivation current   */
#endif
#endif

/************************  Bit definition for VDETPCFG register of HT_PMU_TypeDef ***********************/
#define  PMU_VDETPCFG                            ((uint32_t)0x001f)           /*!<Power supply detection cycle      */

#define  PMU_VDETPCFG_VDETPRD                    ((uint32_t)0x0007)           /*!<Time-sharing detection cycle */
#define  PMU_VDETPCFG_VDETPRD_16P5mS             ((uint32_t)0x0000)           /*!<Time-sharing detection cycle = 16.5ms  */
#define  PMU_VDETPCFG_VDETPRD_33mS               ((uint32_t)0x0001)           /*!<Time-sharing detection cycle = 33ms    */
#define  PMU_VDETPCFG_VDETPRD_67mS               ((uint32_t)0x0002)           /*!<Time-sharing detection cycle = 67ms    */
#define  PMU_VDETPCFG_VDETPRD_134mS              ((uint32_t)0x0003)           /*!<Time-sharing detection cycle = 134ms   */
#define  PMU_VDETPCFG_VDETPRD_268mS              ((uint32_t)0x0004)           /*!<Time-sharing detection cycle = 268ms   */
#define  PMU_VDETPCFG_VDETPRD_536mS              ((uint32_t)0x0005)           /*!<Time-sharing detection cycle = 536ms   */
#define  PMU_VDETPCFG_VDETPRD_1072mS             ((uint32_t)0x0006)           /*!<Time-sharing detection cycle = 1072ms  */
#define  PMU_VDETPCFG_VDETPRD_2144mS             ((uint32_t)0x0007)           /*!<Time-sharing detection cycle = 2144ms  */

#define  PMU_VDETPCFG_VDETTIME                   ((uint32_t)0x0018)           /*!<Time-sharing detection time  */

#define  PMU_VDETPCFG_VDETTIME_300uS             ((uint32_t)0x0000)           /*!<Time-sharing detection time = 300us */
#define  PMU_VDETPCFG_VDETTIME_360uS             ((uint32_t)0x0008)           /*!<Time-sharing detection time = 360us */
#define  PMU_VDETPCFG_VDETTIME_480uS             ((uint32_t)0x0010)           /*!<Time-sharing detection time = 480us */
#define  PMU_VDETPCFG_VDETTIME_1120uS            ((uint32_t)0x0018)           /*!<Time-sharing detection time = 1120us */
#define  PMU_VDETPCFG_VDETTIME_560uS             ((uint32_t)0x0018)           /*!<Time-sharing detection time = 560us */
#define  PMU_VDETPCFG_VDETTIME_1068uS            ((uint32_t)0x0018)           /*!<Time-sharing detection time = 1068us */

#define  PMU_VDETPCFG_VDETTIME_LVL0              ((uint32_t)0x0000)
#define  PMU_VDETPCFG_VDETTIME_LVL1              ((uint32_t)0x0008)
#define  PMU_VDETPCFG_VDETTIME_LVL2              ((uint32_t)0x0010)
#define  PMU_VDETPCFG_VDETTIME_LVL3              ((uint32_t)0x0018)

/**************************  Bit definition for PMUIE register of HT_PMU_TypeDef ************************/
#if defined USE_PMUCON_TYPE3
#define  PMU_PMUIE                               ((uint32_t)0x003f)           /*!<PMU interrupt enable  */
#elif defined USE_PMUCON_TYPE2
#define  PMU_PMUIE                               ((uint32_t)0x000f)           /*!<PMU interrupt enable  */
#elif defined USE_PMUCON_TYPE1
#define  PMU_PMUIE                               ((uint32_t)0x0007)           /*!<PMU interrupt enable  */
#else
#define  PMU_PMUIE                               ((uint32_t)0x001f)           /*!<PMU interrupt enable  */
#endif

#define  PMU_PMUIE_VCCIE                         ((uint32_t)0x0001)           /*!<VCC detection interrupt enable  */ 
                                                                             
#define  PMU_PMUIE_BORIE                         ((uint32_t)0x0002)           /*!<BOR detection interrupt enable  */
#define  PMU_PMUIE_LVD0IE                        ((uint32_t)0x0004)           /*!<LVDIN0 detection interrupt enable   */
#if defined USE_LVDIN1
#define  PMU_PMUIE_LVD1IE                        ((uint32_t)0x0008)           /*!<LVDIN1 detection interrupt enable   */
#endif
#if defined USE_POWDET
#define  PMU_PMUIE_POWIE                         ((uint32_t)0x0010)           /*!<POW detection interrupt enable  */
#endif
#if defined USE_LVDIN2
#define  PMU_PMUIE_LVD2IE                        ((uint32_t)0x0020)           /*!<LVDIN2 detection interrupt enable   */
#endif

/**************************  Bit definition for PMUIF register of HT_PMU_TypeDef ************************/

#if defined USE_PMUCON_TYPE3
#define  PMU_PMUIF                               ((uint32_t)0x003f)           /*!<PMU interrupt flag    */
#elif defined USE_PMUCON_TYPE2
#define  PMU_PMUIF                               ((uint32_t)0x000f)           /*!<PMU interrupt flag    */
#elif defined USE_PMUCON_TYPE1
#define  PMU_PMUIF                               ((uint32_t)0x0007)           /*!<PMU interrupt flag    */
#else
#define  PMU_PMUIF                               ((uint32_t)0x001f)           /*!<PMU interrupt flag    */
#endif

#define  PMU_PMUIF_VCCIF                         ((uint32_t)0x0001)           /*!<VCC detection interrupt flag     */
                                                                             
#define  PMU_PMUIF_BORIF                         ((uint32_t)0x0002)           /*!<BOR detection interrupt flag     */
#define  PMU_PMUIF_LVD0IF                        ((uint32_t)0x0004)           /*!<LVDIN0 detection interrupt flag  */
#if defined USE_LVDIN1
#define  PMU_PMUIF_LVD1IF                        ((uint32_t)0x0008)           /*!<LVDIN1 detection interrupt flag  */
#endif
#if defined USE_POWDET
#define  PMU_PMUIF_POWIF                         ((uint32_t)0x0010)           /*!<POW detection interrupt flag     */
#endif
#if defined USE_LVDIN2
#define  PMU_PMUIF_LVD2IF                        ((uint32_t)0x0020)           /*!<LVDIN2 detection interrupt flag  */
#endif

/*************************  Bit definition for PMUSTA register of HT_PMU_TypeDef ************************/
#if defined USE_PMUCON_TYPE3
#define  PMU_PMUSTA                               ((uint32_t)0x003f)           /*!<PMU status flag   		*/
#elif defined USE_PMUCON_TYPE2
#define  PMU_PMUSTA                               ((uint32_t)0x000f)           /*!<PMU status flag    	*/
#elif defined USE_PMUCON_TYPE1
#define  PMU_PMUSTA                               ((uint32_t)0x0007)           /*!<PMU status flag    	*/
#else
#define  PMU_PMUSTA                               ((uint32_t)0x001f)           /*!<PMU status flag    	*/
#endif

#define  PMU_PMUSTA_VCCFLG                       ((uint32_t)0x0001)           /*!<VCC status flag @VCCLVL  */ 
#define  PMU_PMUSTA_BORFLG                       ((uint32_t)0x0002)           /*!<VCC status flag @BORLVL  */
#define  PMU_PMUSTA_LVD0FLG                      ((uint32_t)0x0004)           /*!<LVDIN0 status flag       */
#if defined USE_LVDIN1
#define  PMU_PMUSTA_LVD1FLG                      ((uint32_t)0x0008)           /*!<LVDIN1 status flag       */
#endif
#if defined USE_POWDET
#define  PMU_PMUSTA_POWFLG                       ((uint32_t)0x0010)           /*!<POWIN  status flag       */
#endif
#if defined USE_LVDIN2
#define  PMU_PMUSTA_LVD2FLG                      ((uint32_t)0x0020)           /*!<LVDIN2 status flag       */
#endif

/*************************  Bit definition for PDTFLT register of HT_PMU_TypeDef ************************/
#if  defined USE_POWDET
#define  PMU_PDTFLT                            ((uint32_t)0x000f)           /*!<POWER_DET_FILTER Low power detection filtering*/
#endif
/*************************  Bit definition for LVDINQR register of HT_PMU_TypeDef ************************/
#if  defined  USE_LVDIN_QR
#define  PMU_LVDINQR                             ((uint32_t)0x0007)           /*!<LVDDET Quick start sampling control     */
#define  PMU_LVDINQR_LVD_QR0                     ((uint32_t)0x0001)           /*!<LVDIN0 Quick start sampling enable      */
#define  PMU_LVDINQR_LVD_QR1                     ((uint32_t)0x0002)           /*!<LVDIN1 Quick start sampling enable      */
#define  PMU_LVDINQR_LVD_QR2                     ((uint32_t)0x0004)           /*!<LVDIN2 Quick start sampling enable      */
#endif

/*************************  Bit definition for LDOVREFCFG register of HT_PMU_TypeDef ************************/
#if  defined  USE_LDOVREF
#define  PMU_LDOVREFCFG                          ((uint32_t)0x00C0)           /*!<LDOVREF config      */
#define  PMU_LDOVREFCFG_C_LDO_LP                 ((uint32_t)0x0080)           /*!<LP_LDO volt config         */

#define  PMU_LDOVREFCFG_LDOSVL                   ((uint32_t)0x0300)           /*!<LDO output voltage config   */
#define  PMU_LDOVREFCFG_LDOSVL_0                 ((uint32_t)0x0000)           /*!<LDO output voltage = 1.68v  */
#define  PMU_LDOVREFCFG_LDOSVL_1                 ((uint32_t)0x0100)           /*!<LDO output voltage = 1.55v  */
#define  PMU_LDOVREFCFG_LDOSVL_2                 ((uint32_t)0x0200)           /*!<LDO output voltage = 1.46v  */
#define  PMU_LDOVREFCFG_LDOSVL_3                 ((uint32_t)0x0300)           /*!<LDO output voltage = 1.40v  */
#endif

#if defined USE_LVDIN_SEL
#define  PMU_LVDINSEL                             ((uint32_t)0x0015)           /*!<LVDDET compare select       */
#define  PMU_LVDINSEL_LVD0SEL                     ((uint32_t)0x0001)           /*!<LVDIN0 compare select       */
#define  PMU_LVDINSEL_LVD1SEL                     ((uint32_t)0x0004)           /*!<LVDIN1 compare select       */
#define  PMU_LVDINSEL_LVD2SEL                     ((uint32_t)0x0010)           /*!<LVDIN2 compare select       */
#endif

/*************************  Bit definition for WAKEIF register of HT_PMU_TypeDef ************************/
#define  PMU_WAKEIF                              ((uint32_t)0xffffffff)       /*!< wakeup flag              */
#define  PMU_WAKEIF_PMUWKIF                      ((uint32_t)0x00000001)       /*!<PMU wakeup flag           */
#if  defined  USE_ARG
#define  PMU_WAKEIF_ARGWKIF                      ((uint32_t)0x00000002)       /*!<AES wakeup flag           */
#endif
#define  PMU_WAKEIF_INT0WKIF                     ((uint32_t)0x00000004)       /*!<INT0 wakeup flag          */
#if  defined  HT762x  ||  defined  HT772x
#define  PMU_WAKEIF_INT123WKIF                   ((uint32_t)0x00000008)       /*!<INT123 wakeup flag        */
#define  PMU_WAKEIF_FFTFRAMWKIF                  ((uint32_t)0x00000010)       /*!<FFTFRAM wakeup flag        */
#define  PMU_WAKEIF_INT456WKIF                   ((uint32_t)0x00000040)       /*!<INT456 wakeup flag        */
#define  PMU_WAKEIF_EMUWKIF                      ((uint32_t)0x00000080)       /*!<EMU wakeup flag        */
#define  PMU_WAKEIF_EWUWKIF                      ((uint32_t)0x00000100)       /*!<EWU wakeup flag        */
#else
#define  PMU_WAKEIF_INT1WKIF                     ((uint32_t)0x00000008)       /*!<INT1 wakeup flag          */
#define  PMU_WAKEIF_INT2WKIF                     ((uint32_t)0x00000010)       /*!<INT2 wakeup flag          */
#define  PMU_WAKEIF_INT3WKIF                     ((uint32_t)0x00000020)       /*!<INT3 wakeup flag          */
#define  PMU_WAKEIF_INT4WKIF                     ((uint32_t)0x00000040)       /*!<INT4 wakeup flag          */
#define  PMU_WAKEIF_INT5WKIF                     ((uint32_t)0x00000080)       /*!<INT5 wakeup flag          */
#define  PMU_WAKEIF_INT6WKIF                     ((uint32_t)0x00000100)       /*!<INT6 wakeup flag          */
#endif
#define  PMU_WAKEIF_RX0WKIF                      ((uint32_t)0x00000200)       /*!<RX0 wakeup flag           */
#define  PMU_WAKEIF_RX1WKIF                      ((uint32_t)0x00000400)       /*!<RX1 wakeup flag           */
#define  PMU_WAKEIF_RX2WKIF                      ((uint32_t)0x00000800)       /*!<RX2 wakeup flag           */
#define  PMU_WAKEIF_RX3WKIF                      ((uint32_t)0x00001000)       /*!<RX3 wakeup flag           */
#define  PMU_WAKEIF_RX4WKIF                      ((uint32_t)0x00002000)       /*!<RX4 wakeup flag           */
#define  PMU_WAKEIF_RX5WKIF                      ((uint32_t)0x00004000)       /*!<RX5 wakeup flag           */

#define  PMU_WAKEIF_TIM0WKIF                     ((uint32_t)0x00008000)       /*!<Timer0 wakeup flag        */
#define  PMU_WAKEIF_TIM1WKIF                     ((uint32_t)0x00010000)       /*!<Timer1 wakeup flag        */
#define  PMU_WAKEIF_TIM2WKIF                     ((uint32_t)0x00020000)       /*!<Timer2 wakeup flag        */
#define  PMU_WAKEIF_TIM3WKIF                     ((uint32_t)0x00040000)       /*!<Timer3 wakeup flag        */

#define  PMU_WAKEIF_TBSWKIF                      ((uint32_t)0x00080000)       /*!<TBS wakeup flag           */
#define  PMU_WAKEIF_RTCWKIF                      ((uint32_t)0x00100000)       /*!<RTC wakeup flag           */
#define  PMU_WAKEIF_I2CWKIF                      ((uint32_t)0x00200000)       /*!<I2C wakeup flag           */
#if defined HT501x || defined  HT502x 
#define  PMU_WAKEIF_SPIWKIF                      ((uint32_t)0x00400000)       /*!<SPI wakeup flag          */
#endif
#if defined HT503x || defined USE_SPI1_MCU
#define  PMU_WAKEIF_SPI0WKIF                      ((uint32_t)0x00400000)       /*!<SPI0 wakeup flag          */
#endif

#if defined USE_SPI1_MCU || defined HT503x
#define  PMU_WAKEIF_SPI1WKIF                     ((uint32_t)0x00800000)       /*!<SPI1 wakeup flag          */
#endif
#if  defined  HT6x1x
#define  PMU_WAKEIF_WDTWKIF                      ((uint32_t)0x00800000)       /*!<WDT wakeup flag           */
#endif
#if  defined  HT501x || defined  HT502x || HT503x || defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT633x  || defined  HT762x  ||  defined  HT772x
#define  PMU_WAKEIF_SELFTESTWKIF                 ((uint32_t)0x01000000)       /*!<SELFTEST wakeup flag      */
#endif
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  PMU_WAKEIF_TMR4WKIF                     ((uint32_t)0x02000000)       /*!<Timer4 wakeup flag        */
#define  PMU_WAKEIF_TMR5WKIF                     ((uint32_t)0x04000000)       /*!<Timer5 wakeup flag        */
#define  PMU_WAKEIF_INT7WKIF                     ((uint32_t)0x10000000)       /*!<INT7 wakeup flag          */
#define  PMU_WAKEIF_INT8WKIF                     ((uint32_t)0x20000000)       /*!<INT8 wakeup flag          */
#endif
#if  defined  HT6x2x  ||  defined  HT6x3x
#define  PMU_WAKEIF_RX6WKIF                      ((uint32_t)0x08000000)       /*!<RX6 wakeup flag           */
#define  PMU_WAKEIF_INT9WKIF                     ((uint32_t)0x40000000)       /*!<INT9 wakeup flag          */
#endif

#if  defined  HT762x  ||  defined  HT772x || defined HT633x
#define  PMU_WAKEIF_TMR4WKIF                     ((uint32_t)0x02000000)       /*!<Timer4 wakeup flag        */
#define  PMU_WAKEIF_TMR5WKIF                     ((uint32_t)0x04000000)       /*!<Timer5 wakeup flag        */
#define  PMU_WAKEIF_RX6WKIF                      ((uint32_t)0x08000000)       /*!<RX6 wakeup flag           */
#define  PMU_WAKEIF_INT789WKIF                   ((uint32_t)0x10000000)       /*!<INT789 wakeup flag        */
#define  PMU_WAKEIF_SPI3WKIF                     ((uint32_t)0x20000000)       /*!<SPI3 wakeup flag           */
#define  PMU_WAKEIF_SPI2WKIF                     ((uint32_t)0x40000000)       /*!<SPI2 wakeup flag           */
#define  PMU_WAKEIF_DMAWKIF                      ((uint32_t)0x80000000)       /*!<DMA wakeup flag           */
#endif

#if  defined  HT501x || defined  HT502x || defined HT503x
#define  PMU_WAKEIF_EMUWKIF                      ((uint32_t)0x02000000)       /*!<EMU wakeup flag                 */
#define  PMU_WAKEIF_DMAWKIF                      ((uint32_t)0x04000000)       /*!<DMA wakeup flag                */
#define  PMU_WAKEIF_KEYWKIF                      ((uint32_t)0x08000000)       /*!<KEY wakeup flag                */
#endif

#if  defined  HT502x
#define  PMU_WAKEIF_INT7WKIF                     ((uint32_t)0x10000000)       /*!<INT7 wakeup flag               */
#define  PMU_WAKEIF_INT8WKIF                     ((uint32_t)0x20000000)       /*!<INT8 wakeup flag               */
#define  PMU_WAKEIF_INT9WKIF                     ((uint32_t)0x40000000)       /*!<INT9 wakeup flag               */
#define  PMU_WAKEIF_NMIWKIF                      ((uint32_t)0x80000000)       /*!<NMI wakeup flag                */
#endif

#if  defined  HT503x
#define  PMU_WAKEIF_INT789WKIF                   ((uint32_t)0x10000000)       /*!<INT7-9 wakeup flag              */
#define  PMU_WAKEIF_RX6WKIF                      ((uint32_t)0x20000000)       /*!<RX6 wakeup flag                 */
#define  PMU_WAKEIF_SPI2WKIF                     ((uint32_t)0x40000000)       /*!<SPI2 wakeup flag                */
#define  PMU_WAKEIF_NMIWKIF                      ((uint32_t)0x80000000)       /*!<NMI wakeup flag                 */
#endif

#if defined HT633x
#define PMU_WAKEIF1_LPRXWKIF                     ((uint32_t)0x00000001)       /*!<LPUART wakeup flag  						*/
#define PMU_WAKEIF1_INT1014WKIF                  ((uint32_t)0x00000002)       /*!<INT10-14 wakeup flag 						*/
#define PMU_WAKEIF1_EWKUPWKIF                    ((uint32_t)0x00000004)       /*!<EWAKEUP wakeup flag  						*/
#endif

/*************************  Bit definition for RSTSTA register of HT_PMU_TypeDef ************************/

#define  PMU_RSTSTA                              ((uint32_t)0xc1ff)           /*!<reset status flag     */

#define  PMU_RSTSTA_PORRST                       ((uint32_t)0x0001)           /*!<POR reset status flag     */
#define  PMU_RSTSTA_LBORRST                      ((uint32_t)0x0002)           /*!<LBOR reset status flag    */
#define  PMU_RSTSTA_WDTRST                       ((uint32_t)0x0004)           /*!<WDT reset status flag     */
#define  PMU_RSTSTA_WakeupRST                    ((uint32_t)0x0008)           /*!<WakeUp reset status flag  */
#define  PMU_RSTSTA_ExtRST                       ((uint32_t)0x0020)           /*!<Pin RST reset status flag */
#define  PMU_RSTSTA_SoftRST                      ((uint32_t)0x0040)           /*!<Soft reset status flag    */
#define  PMU_RSTSTA_DebugRST                     ((uint32_t)0x0080)           /*!<Debug reset status flag   */
#define  PMU_RSTSTA_BORRST                       ((uint32_t)0x0100)           /*!<BOR reset status flag     */
#define  PMU_RSTSTA_SleepFlag                    ((uint32_t)0x4000)           /*!<Sleep Wake  flag          */
#define  PMU_RSTSTA_HoldFlag                     ((uint32_t)0x8000)           /*!<Hold wakeup flag          */


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of CMU Module
**********************************************************************************************************
*/
/**************************  Bit definition for WPREG register of HT_CMU_TypeDef ************************/
#define  CMU_WPREG                             ((uint32_t)0xffff)           /*!<write protection register         */
#define  CMU_WPREG_UnProtected                 ((uint32_t)0xA55A)           /*!<Disable write protection function */
#define  CMU_WPREG_Protected                   ((uint32_t)0x0000)           /*!<Enable write protection function  */
                                                                            /*!<0xA55A: Unprotected               */
                                                                            /*!<other : Protected                 */

#define   CMU_WPSTA_UNPROTECT                  ((uint32_t)0x0001)           /*!<write protection state: unprotect */
#define   CMU_WPSTA_PROTECT                    ((uint32_t)0x0000)           /*!<write protection state: protect   */

/************************  Bit definition for SYSCLKCFG register of HT_CMU_TypeDef **********************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x1x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x
#define  CMU_SYSCLKCFG_CLKSEL                  ((uint32_t)0x0007)           /*!<System clock selection control bit */
#elif defined HT501x  ||  defined  HT503x  ||  defined  HT633x
#define  CMU_SYSCLKCFG_CLKSEL                  ((uint32_t)0x0003)           /*!<System clock selection control bit */
#endif
#define  CMU_SYSCLKCFG_CLKSEL_LRC              ((uint32_t)0x0000)           /*!<Select lrc               */
#define  CMU_SYSCLKCFG_CLKSEL_LF               ((uint32_t)0x0001)           /*!<Select low frequency osc */
#define  CMU_SYSCLKCFG_CLKSEL_HRC              ((uint32_t)0x0002)           /*!<Select hrc               */
#define  CMU_SYSCLKCFG_CLKSEL_PLL              ((uint32_t)0x0003)           /*!<Select PLL               */
#if  defined  HT6x1x
#define  CMU_SYSCLKCFG_CLKSEL_MEMS             ((uint32_t)0x0004)           /*!<Select mems              */
#endif
#if  defined  HT633x
#define  CMU_SYSCLKCFG_SYSCLKBAK               ((uint32_t)0x0100)           /*!<System backup clock selection control bit */
#define  CMU_SYSCLKCFG_SYSCLKBAK_LRC           ((uint32_t)0x0000)           /*!<System backup clock select lrc */
#define  CMU_SYSCLKCFG_SYSCLKBAK_OSC           ((uint32_t)0x0100)           /*!<System backup clock select osc */
#endif
#define  CMU_SYSCLKCFG_WCLKEN                  ((uint32_t)0x0080)           /*!<Clock configuration write protection bit */

/*************************  Bit definition for JTAGSTA register of HT_CMU_TypeDef ***********************/
#if defined  HT6x3x
#define  CMU_JTAGSTA                           ((uint32_t)0x0003)           /*!<JTAG status indication                         */
#define  CMU_JTAGSTA_FLASHSTA                  ((uint32_t)0x0001)           /*!<Internal state reserved bit                    */
#define  CMU_JTAGSTA_FLAG_SW                   ((uint32_t)0x0002)           /*!<Indicates that the chip is in debugging state  */
#define  CMU_JTAGSTA_FLAG_NORMAL               ((uint32_t)0x0000)           /*!<Indicates that the chip is in normal operation */
#elif defined  HT503x
#define  CMU_JTAGSTA_FLASHSTA                  ((uint32_t)0x0001)           /*!<Internal state reserved bit                    */
#elif defined  HT501x  ||  defined  HT6x1x  ||  defined  HT6x2x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT633x
#define  CMU_JTAGSTA                           ((uint32_t)0x0020)           /*!<JTAG status indication                         */
#define  CMU_JTAGSTA_FLAG_SW                   ((uint32_t)0x0002)           /*!<Indicates that the chip is in debugging state  */
#define  CMU_JTAGSTA_FLAG_NORMAL               ((uint32_t)0x0000)           /*!<Indicates that the chip is in normal operation */
#else
#define  CMU_JTAGSTA                           ((uint32_t)0x0001)           /*!<JTAG status indication                         */
#endif

/*************************  Bit definition for LRCADJ register of HT_CMU_TypeDef ************************/
#if defined  HT6x1x ||  defined  HT501x  ||  defined  HT502x
#define  CMU_LRCADJ                            ((uint32_t)0x000f)           /*!<lrc Output frequency modulation bit */
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT762x  ||  defined  HT772x   ||  defined  HT503x  ||  defined HT633x
#define  CMU_LRCADJ                            ((uint32_t)0x00ff)           /*!<lrc Output frequency modulation bit */
#endif
/*************************  Bit definition for HRCADJ register of HT_CMU_TypeDef ************************/
#if  defined  HT6x1x ||  defined  HT501x
#define  CMU_HRCADJ                            ((uint32_t)0x003f)           /*!<hrc Output frequency modulation bit */
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK
#define  CMU_HRCADJ                            ((uint32_t)0x007f)           /*!<hrc Output frequency modulation bit */
#elif  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
#define  CMU_HRCADJ                            ((uint32_t)0x3f7f)           /*!<hrc Output frequency modulation bit */
#elif  defined  HT633x
#define  CMU_HRCADJ                            ((uint32_t)0x0fff)           /*!<hrc Output frequency modulation bit */
#endif

/*************************  Bit definition for HRCDIV register of HT_CMU_TypeDef ************************/
#if  defined  USE_CMU_HRCDIV 
#define  CMU_HRCDIV                            ((uint32_t)0x0003)           /*!<hrc clock division setting */
#define  CMU_HRCDIV_1                          ((uint32_t)0x0000)           /*!<Division factor = 1        */
#define  CMU_HRCDIV_2                          ((uint32_t)0x0001)           /*!<Division factor = 2        */
#define  CMU_HRCDIV_4                          ((uint32_t)0x0002)           /*!<Division factor = 4        */
#define  CMU_HRCDIV_8                          ((uint32_t)0x0003)           /*!<Division factor = 8        */
#endif

/*************************  Bit definition for CLKSTA register of HT_CMU_TypeDef ************************/
#if  defined  HT6x2x  ||  defined  HT6x2xK  ||  defined HT633x
#define  CMU_CLKSTA                            ((uint32_t)0x003b)           /*!<MCU clock status register */
#elif  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x  ||  defined HT762x  ||  defined  HT772x
#define  CMU_CLKSTA                            ((uint32_t)0x0039)           /*!<MCU clock status register */
#elif  defined  HT6x1x
#define  CMU_CLKSTA                            ((uint32_t)0x001b)           /*!<MCU clock status register */
#endif
#define  CMU_CLKSTA_LFFLAG                     ((uint32_t)0x0001)           /*!<LF stop flag              */
#if  defined  HT6x1x
#define  CMU_CLKSTA_LFSEL                      ((uint32_t)0x0002)           /*!<0:osc 1:mems              */
#elif defined HT633x
#define  CMU_CLKSTA_LFSTA                      ((uint32_t)0x0002)           /*!<low frequency clock stop state */
#else
#define  CMU_CLKSTA_LFSEL                      ((uint32_t)0x0000)           /*!<0:osc osc only            */
#endif
#define  CMU_CLKSTA_HRCFLAG                    ((uint32_t)0x0008)           /*!<HRC stop flag             */
#define  CMU_CLKSTA_PLLFLAG                    ((uint32_t)0x0010)           /*!<PLL stop flag             */
#if  !defined  HT6x1x
#define  CMU_CLKSTA_PLLLOCK                    ((uint32_t)0x0020)           /*!<PLL lock  flag            */
#endif

/***********************  Bit definition for SYSCLKDIV register of HT_CMU_TypeDef ***********************/
#define  CMU_SYSCLKDIV                         ((uint32_t)0x0007)           /*!<System clock division setting */
#if  defined  USE_CMU_SYSCLKDIV_SEL40M
#define  CMU_SYSCLKDIV_SEL20M                  ((uint32_t)0x0000)           /*!<PLL outputs 20M clock         */
#define  CMU_SYSCLKDIV_SEL40M                  ((uint32_t)0x0008)           /*!<PLL outputs 40M clock         */
#endif
#define  CMU_CPUCLKDIV_1                       ((uint32_t)0x0000)           /*!<Division factor = 1           */
#define  CMU_CPUCLKDIV_2                       ((uint32_t)0x0001)           /*!<Division factor = 2           */
#define  CMU_CPUCLKDIV_4                       ((uint32_t)0x0002)           /*!<Division factor = 4           */
#define  CMU_CPUCLKDIV_8                       ((uint32_t)0x0003)           /*!<Division factor = 8           */
#define  CMU_CPUCLKDIV_16                      ((uint32_t)0x0004)           /*!<Division factor = 16          */
#define  CMU_CPUCLKDIV_32                      ((uint32_t)0x0005)           /*!<Division factor = 32          */
#define  CMU_CPUCLKDIV_64                      ((uint32_t)0x0006)           /*!<Division factor = 64          */
#define  CMU_CPUCLKDIV_128                     ((uint32_t)0x0007)           /*!<Division factor = 128         */

/***********************  Bit definition for CLKOUTSEL register of HT_CMU_TypeDef ***********************/
#define  CMU_CLKOUTSEL                         ((uint32_t)0x0007)           /*!<CLKOUT output clock setting   */
#define  CMU_CLKOUTSEL_LRC                     ((uint32_t)0x0000)           /*!<LRC --> CLKOUT                */
#define  CMU_CLKOUTSEL_LF                      ((uint32_t)0x0001)           /*!<OSC --> CLKOUT                */
#define  CMU_CLKOUTSEL_HRC                     ((uint32_t)0x0002)           /*!<HRC --> CLKOUT                */
#define  CMU_CLKOUTSEL_SYS                     ((uint32_t)0x0003)           /*!<SYS --> CLKOUT                */
#if  defined  USE_CMU_CLKOUTSEL_PLL
#define  CMU_CLKOUTSEL_PLL                     ((uint32_t)0x0004)           /*!<PLL --> CLKOUT                */
#elif defined  HT503x
/*#define  CMU_CLKOUTSEL_LF                      ((uint32_t)0x0004)           !<OSC --> CLKOUT                */
#elif defined  HT6x1x
#define  CMU_CLKOUTSEL_MEMS                    ((uint32_t)0x0004)           /*!<MEMS--> CLKOUT                */
#endif

/***********************  Bit definition for CLKOUTDIV register of HT_CMU_TypeDef ***********************/
#define  CMU_CLKOUTDIV                         ((uint32_t)0x000f)           /*!<CLKOUT output clock setting  */
                                                                            /*!<Division factor = 2*(N+1)    */
/************************  Bit definition for CLKCTRL0 register of HT_CMU_TypeDef ***********************/
#if   defined  HT6x1x
#define  CMU_CLKCTRL0                          ((uint32_t)0x003bfe)         /*!<CLKCTRL0 register             */
#elif  defined  HT6x2x
#define  CMU_CLKCTRL0                          ((uint32_t)0x01f7fe)         /*!<CLKCTRL0 register             */
#elif  defined  HT6x2xK
#define  CMU_CLKCTRL0                          ((uint32_t)0x03b7ff)         /*!<CLKCTRL0 register             */
#elif  defined  HT6x3x
#define  CMU_CLKCTRL0                          ((uint32_t)0x01f7fe)         /*!<CLKCTRL0 register             */
#elif  defined  HT501x
#define  CMU_CLKCTRL0                          ((uint32_t)0x00fbfe)         /*!<CLKCTRL0 register             */
#elif  defined  HT502x
#define  CMU_CLKCTRL0                          ((uint32_t)0x01fffe)         /*!<CLKCTRL0 register             */
#elif  defined  HT762x  ||  defined  HT772x
#define  CMU_CLKCTRL0                          ((uint32_t)0x01f3fd)         /*!<CLKCTRL0 register             */
#elif  defined  HT503x
#define  CMU_CLKCTRL0                          ((uint32_t)0x81ffff)         /*!<CLKCTRL0 register             */
#elif  defined  HT633x
#define  CMU_CLKCTRL0                          ((uint32_t)0x01f3ff)         /*!<CLKCTRL0 register             */
#endif

#if defined  HT503x  ||  defined HT762x  ||  defined  HT772x  ||  defined HT633x  ||  defined HT6x2xK
#define  CMU_CLKCTRL0_LCD_PMU_FSEL             ((uint32_t)0x0001)           /*!<LCD&PMU module clock enable   */
#endif
#if !defined  HT762x  ||  defined  HT772x
#define  CMU_CLKCTRL0_LCDEN                    ((uint32_t)0x0002)           /*!<LCD module clock enable       */
#endif
#define  CMU_CLKCTRL0_SPI0EN                   ((uint32_t)0x0004)           /*!<SPI0 module clock enable      */
#define  CMU_CLKCTRL0_I2CEN                    ((uint32_t)0x0008)           /*!<I2C module clock enable       */
#define  CMU_CLKCTRL0_PLLEN                    ((uint32_t)0x0010)           /*!<PLL module clock enable       */
#define  CMU_CLKCTRL0_HRCEN                    ((uint32_t)0x0020)           /*!<HRC module clock enable       */
#if  !defined  HT6x1x
#define  CMU_CLKCTRL0_PLLLOCKEN                ((uint32_t)0x0040)           /*!<PLL lock enable           */
#elif  defined  HT6x1x
#define  CMU_CLKCTRL0_Reserved                 ((uint32_t)0x0040)           /*!<Reserve as 1              */
#endif
#define  CMU_CLKCTRL0_LFDETEN                  ((uint32_t)0x0080)           /*!<LF clock detection module enable    */
#define  CMU_CLKCTRL0_PLLDETEN                 ((uint32_t)0x0100)           /*!<PLL clock detection module enable   */
#define  CMU_CLKCTRL0_HRCDETEN                 ((uint32_t)0x0200)           /*!<HRC clock detection module enable   */

#if !defined  HT762x  &&  !defined HT772x  &&  !defined  HT503x  &&  !defined HT633x
#define  CMU_CLKCTRL0_OSC_SLP                  ((uint32_t)0x0400)           /*!<OSC low power enable control signal */
#define  CMU_CLKCTRL0_OSC_SLP_LOWPOWER         ((uint32_t)0x0400)           /*!<OSC low power consumption           */
#define  CMU_CLKCTRL0_OSC_SLP_LARGEPOWER       ((uint32_t)0x0000)           /*!<OSC large power consumption         */
#endif
#if  defined  HT6x1x
#define  CMU_CLKCTRL0_WDTEN                    ((uint32_t)0x0800)           /*!<WDT enable bit in low power mode          */
#elif  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#define  CMU_CLKCTRL0_KEYEN                    ((uint32_t)0x0800)           /*!<Key scan enable bit                       */
#endif
#define  CMU_CLKCTRL0_CLKOUTEN                 ((uint32_t)0x1000)           /*!<CLKOUT output enable bit                  */
#define  CMU_CLKCTRL0_1P5LBOREN                ((uint32_t)0x2000)           /*!<Low power consumption 1P5 LBOR enable bit */
#if   defined  HT6x1x
#define  CMU_CLKCTRL0_3DESRADEN                ((uint32_t)0x4000)           /*!<3DES/Random number module enable bit (this function is not open) */
#elif  defined  HT501x  ||  defined  HT502x ||  defined  HT503x
#define  CMU_CLKCTRL0_AESEN                    ((uint32_t)0x4000)           /*!<AES/random number module enable bit (random number function only supports HT502x&HT503x) */
#define  CMU_CLKCTRL0_ADESRADEN                CMU_CLKCTRL0_AESEN           /*!<Downward compatibility definition         */
#elif  defined  HT6x2x || defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define  CMU_CLKCTRL0_ARGEN                    ((uint32_t)0x4000)           /*!<AES/RAND/GHASH module clock enable bit    */
#define  CMU_CLKCTRL0_ADESRADEN                CMU_CLKCTRL0_ARGEN           /*!<Downward compatibility definition         */
#endif
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define  CMU_CLKCTRL0_CRCEN                    ((uint32_t)0x8000)           /*!<CRC module enable bit                     */
#elif  defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#define  CMU_CLKCTRL0_EMUEN                    ((uint32_t)0x8000)           /*!<EMU module enable bit                     */
#endif

#if  defined  HT502x  ||  defined  HT503x
#define  CMU_CLKCTRL0_ECCEN                    ((uint32_t)0x010000)         /*!<ECC module enable bit                                   */
#elif  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK || defined  HT762x  ||  defined  HT772x  ||  defined HT633x /*!<Applicable to HT6x2x H version and above      */
#define  CMU_CLKCTRL0_SEL_PLLN_HRC             ((uint32_t)0x010000)         /*!<High frequency compensation 1HZ source selection bit    */
#define  CMU_CLKCTRL0_SEL_PLLN_HRC_HRC         ((uint32_t)0x010000)         /*!<HRC clock                                               */
#define  CMU_CLKCTRL0_SEL_PLLN_HRC_PLL         ((uint32_t)0x000000)         /*!<PLL clock                                               */
#endif
#if  defined  HT6x2xK
#define  CMU_CLKCTRL0_CMU_NEWREG_EN            ((uint32_t)0x020000)         /*!<New register write protection control bit of CMU module */
#endif
#if  defined  HT503x
#define  CMU_CLKCTRL0_CRCEN                    ((uint32_t)0x800000)         /*!<CRC module clock enable bit                             */
#endif

/************************  Bit definition for CLKCTRL1 register of HT_CMU_TypeDef ***********************/
#if  defined  HT6x1x
#define  CMU_CLKCTRL1                          ((uint32_t)0x0003ff)         /*!<CLKCTRL1 register */
#elif  defined  HT6x2x
#define  CMU_CLKCTRL1                          ((uint32_t)0x01ffff)         /*!<CLKCTRL1 register */
#elif  defined  HT6x2xK
#define  CMU_CLKCTRL1                          ((uint32_t)0x03ffff)         /*!<CLKCTRL1 register */
#elif  defined  HT6x3x
#define  CMU_CLKCTRL1                          ((uint32_t)0x0fffff)         /*!<CLKCTRL1 register */
#elif  defined  HT501x
#define  CMU_CLKCTRL1                          ((uint32_t)0x00c3ff)         /*!<CLKCTRL1 register */
#elif  defined  HT502x
#define  CMU_CLKCTRL1                          ((uint32_t)0x00c3ff)         /*!<CLKCTRL1 register */
#elif  defined  HT503x
#define  CMU_CLKCTRL1                          ((uint32_t)0x0548f3ff)       /*!<CLKCTRL1 register */
#elif  defined  HT762x  ||  defined  HT772x
#define  CMU_CLKCTRL1                          ((uint32_t)0x076c7fff)       /*!<CLKCTRL1 register */
#elif  defined  HT633x
#define  CMU_CLKCTRL1                          ((uint32_t)0x003effff)       /*!<CLKCTRL1 register */
#endif
#define  CMU_CLKCTRL1_TMR0EN                   ((uint32_t)0x0001)           /*!<Timer0 module clock enable       */
#define  CMU_CLKCTRL1_TMR1EN                   ((uint32_t)0x0002)           /*!<Timer1 module clock enable       */
#define  CMU_CLKCTRL1_TMR2EN                   ((uint32_t)0x0004)           /*!<Timer2 module clock enable       */
#define  CMU_CLKCTRL1_TMR3EN                   ((uint32_t)0x0008)           /*!<Timer3 module clock enable       */
#define  CMU_CLKCTRL1_UART0EN                  ((uint32_t)0x0010)           /*!<UART0 module clock enable        */
#define  CMU_CLKCTRL1_UART1EN                  ((uint32_t)0x0020)           /*!<UART1 module clock enable        */
#define  CMU_CLKCTRL1_UART2EN                  ((uint32_t)0x0040)           /*!<UART2 module clock enable        */
#define  CMU_CLKCTRL1_UART3_7816_1EN           ((uint32_t)0x0080)           /*!<UART37816 module clock enable    */
#define  CMU_CLKCTRL1_UART4_7816_0EN           ((uint32_t)0x0100)           /*!<UART47816 module clock enable    */
#define  CMU_CLKCTRL1_UART5EN                  ((uint32_t)0x0200)           /*!<UART5 module clock enable        */
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define  CMU_CLKCTRL1_TMR4EN                   ((uint32_t)0x0400)           /*!<Timer4 module clock enable       */
#define  CMU_CLKCTRL1_TMR5EN                   ((uint32_t)0x0800)           /*!<Timer5 module clock enable       */
#define  CMU_CLKCTRL1_UART6EN                  ((uint32_t)0x1000)           /*!<UART6 module clock enable        */
#define  CMU_CLKCTRL1_SPI1EN                   ((uint32_t)0x2000)           /*!<SPI1 module clock enable         */
#define  CMU_CLKCTRL1_SOFTWDTEN                ((uint32_t)0x4000)           /*!<Software WDT module clock enable */
#if  !defined  HT762x && !defined  HT772x
#define  CMU_CLKCTRL1_LRCRTC2EN                ((uint32_t)0x8000)           /*!<Set second RTC work enable bit   */
#endif
#elif  defined  HT501x  ||  defined  HT502x
#define  CMU_CLKCTRL1_LRCTFREQEN               ((uint32_t)0x4000)           /*!<LRC frequency measurement module enable */
#define  CMU_CLKCTRL1_LRCRTCEN                 ((uint32_t)0x8000)           /*!<Set second RTC work enable bit   */
#endif

#if  defined  HT6x2x  ||  defined  HT6x2xK
#define  CMU_CLKCTRL1_AUTORCCAL_EN             ((uint32_t)0x010000)         /*!<HRC/LRC automatic correction enable */
#endif

#if  defined  HT6x2xK
#define  CMU_CLKCTRL1_SPI3EN                   ((uint32_t)0x20000)          /*!<SPI3 module clock enable         */
#endif

#if  defined  HT633x
#define  CMU_CLKCTRL1_ECCEN                    ((uint32_t)0x20000)          /*!<ECC module clock enable          */
#define  CMU_CLKCTRL1_EMUEN                    ((uint32_t)0x40000)          /*!<EMU module clock enable          */
#define  CMU_CLKCTRL1_SPI2EN                   ((uint32_t)0x80000)          /*!<SPI2 module clock enable         */
#define  CMU_CLKCTRL1_LPUARTEN                 ((uint32_t)0x100000)         /*!<LPUART module clock enable       */
#define  CMU_CLKCTRL1_SPI3EN                   ((uint32_t)0x200000)         /*!<SPI3 module clock enable         */
#endif

#if  defined  HT6x3x
#define  CMU_CLKCTRL1_RCADJEN                  ((uint32_t)0x010000)         /*!<UART6 module clock enable        */
#define  CMU_CLKCTRL1_ECCEN                    ((uint32_t)0x020000)         /*!<SPI1 module clock enable         */
#define  CMU_CLKCTRL1_EMUEN                    ((uint32_t)0x040000)         /*!<Software WDT module clock enable */
#define  CMU_CLKCTRL1_SPI2EN                   ((uint32_t)0x080000)         /*!<LRCRTC module clock enable       */
#endif

#if  defined  HT762x  ||  defined  HT772x
#define  CMU_CLKCTRL1_EMUEN                    ((uint32_t)0x040000)         /*!<EMU module clock enable           */
#define  CMU_CLKCTRL1_SPI2EN                   ((uint32_t)0x080000)         /*!<SPI2 module clock enable          */
#define  CMU_CLKCTRL1_SPI3EN                   ((uint32_t)0x200000)         /*!<SPI3 module clock enable          */
#define  CMU_CLKCTRL1_EMUCLKSRC                ((uint32_t)0x400000)         /*!<EMU clock selection bit           */
#define  CMU_CLKCTRL1_EMUCLKSRC_PLL            ((uint32_t)0x000000)         /*!<EMU clock selection PLL           */
#define  CMU_CLKCTRL1_EMUCLKSRC_HRC            ((uint32_t)0x400000)         /*!<EMU clock selection HRC           */
#define  CMU_CLKCTRL1_EMUIFACEEN               ((uint32_t)0x1000000)        /*!<EMU Interface module clock enable */
#define  CMU_CLKCTRL1_FFTEN                    ((uint32_t)0x2000000)        /*!<FFT module clock enable           */
#define  CMU_CLKCTRL1_PACKEN                   ((uint32_t)0x4000000)        /*!<PACK module clock enable          */
#endif

#if  defined  HT503x
#define  CMU_CLKCTRL1_UART6EN                  ((uint32_t)0x01000)           /*!<UART6 module clock enable         */
#define  CMU_CLKCTRL1_SPI1EN                   ((uint32_t)0x02000)           /*!<SPI1 module clock enable          */
#define  CMU_CLKCTRL1_SPI2EN                   ((uint32_t)0x80000)           /*!<SPI2 module clock enable          */
#define  CMU_CLKCTRL1_EMUCLKSRC                ((uint32_t)0x400000)          /*!<EMU clock selection bit           */
#define  CMU_CLKCTRL1_EMUCLKSRC_PLL            ((uint32_t)0x000000)          /*!<EMU clock selection PLL           */
#define  CMU_CLKCTRL1_EMUCLKSRC_HRC            ((uint32_t)0x400000)          /*!<EMU clock selection HRC           */
#define  CMU_CLKCTRL1_EMUIFACEEN               ((uint32_t)0x1000000)         /*!<EMU Interface module clock enable */
#define  CMU_CLKCTRL1_PACKEN                   ((uint32_t)0x4000000)         /*!<PACK module clock enable          */
#endif

/************************  Bit definition for FLASHCON register of HT_CMU_TypeDef ***********************/
#if  defined  USE_HT503x_MEMORY
#define  CMU_FLASHCON                            ((uint32_t)0x8007)           /*!<Flash control register     */
#elif defined  USE_HT633x_MEMORY
#define  CMU_FLASHCON                            ((uint32_t)0x0407)           /*!<Flash control register     */        
#else                                                                                                       
#define  CMU_FLASHCON                            ((uint32_t)0x0007)           /*!<Flash control register     */
#endif

#define  CMU_FLASHCON_FOP                        ((uint32_t)0x0003)           /*!<Flash mode      	  	*/
#define  CMU_FLASHCON_FOP_READ                   ((uint32_t)0x0000)           /*!<Flash read mode   	  */
#define  CMU_FLASHCON_FOP_WRITE                  ((uint32_t)0x0001)           /*!<Flash write mode      */
#define  CMU_FLASHCON_FOP_PAGEERASE              ((uint32_t)0x0002)           /*!<Flash page erase mode */
#define  CMU_FLASHCON_FOP_CHIPERASE              ((uint32_t)0x0003)           /*!<Flash mass erase mode */

#define  CMU_FLASHCON_BUSY                       ((uint32_t)0x0004)           /*!<Flash status 0:idle 1:busy */
#if  defined  USE_HT503x_MEMORY
#define  CMU_FLASHCON_WE_ERR                     ((uint32_t)0x8000)           /*!<Flash write/erase fail flag*/
#endif

#if defined  USE_HT633x_MEMORY
#define  CMU_FLASHCON_ADDERR                     ((uint32_t)0x0400)           /*!<Flash access address error status 0:normal 1:error */
#endif

/************************  Bit definition for FLASHLOCK register of HT_CMU_TypeDef **********************/
#define  CMU_FLASHLOCK                           ((uint32_t)0xffff)           /*!<Flash lock register      */
#define  CMU_FLASHLOCK_UnLocked                  ((uint32_t)0x7A68)           /*!<Flash write/erase unlock */
#define  CMU_FLASHLOCK_Locked                    ((uint32_t)0x0000)           /*!<Flash lock               */
                                                                              /*!<0x7A68 : Unlock       */                               
                                                                              /*!<other  : Lock         */
#if  defined  USE_HT603x_MEMORY
#define  CMU_FLASHLOCK_H256                      ((uint32_t)0xffff)           /*!<high 256K flash write/erase enable */
#define  CMU_FLASHLOCK_H256_UnLocked             ((uint32_t)0x7A68)           /*!<Flash write/erase unlock     			 */
#define  CMU_FLASHLOCK_H256_Locked               ((uint32_t)0x0000)           /*!<Flash lock            */
                                                                              /*!<0x7A68 : Unlock       */
																			  /*!<other  : Lock         */
																			  
#define  CMU_FLASHLOCK_L256                      ((uint32_t)0xffff)           /*!<low 256K flash write/erase enable */
#define  CMU_FLASHLOCK_L256_UnLocked             ((uint32_t)0x7A68)           /*!<Flash write/erase unlock */
#define  CMU_FLASHLOCK_L256_Locked               ((uint32_t)0x0000)           /*!<Flash lock               */
                                                                              /*!<0x7A68 : Unlock       */  
                                                                              /*!<other  : Lock         */
#endif

/************************  Bit definition for PREFETCH register of HT_CMU_TypeDef ***********************/
#if  defined  USE_HT602x_MEMORY
#define  CMU_PREFETCH                          ((uint32_t)0x0001)           /*!<Instruction prefetch enable control               */
#define  CMU_PREFETCH_ENABLE                   ((uint32_t)0x0001)           /*!<Instruction prefetch enable                       */
#define  CMU_PREFETCH_DISABLE                  ((uint32_t)0x0000)           /*!<Instruction prefetch disable                      */
#elif  defined  USE_HT603x_MEMORY 
#define  CMU_PREFETCH                          ((uint32_t)0x03f7)           /*!<Instruction prefetch enable control               */
#define  CMU_PREFETCH_CACHE_EN                 ((uint32_t)0x0001)           /*!<Cache enable                                      */
#define  CMU_PREFETCH_HITRATE_EN               ((uint32_t)0x0002)           /*!<Hit-rate function enable                          */
#define  CMU_PREFETCH_HITRATE_CLR              ((uint32_t)0x0004)           /*!<Hit-rate counter reset                            */
#define  CMU_PREFETCH_CYC_VDR_WD               ((uint32_t)0x0010)           /*!<Cache LRU algorithm combination configuration bit */
#define  CMU_PREFETCH_CYC_VDF_WD               ((uint32_t)0x0020)           /*!<Cache LRU algorithm combination configuration bit */
#define  CMU_PREFETCH_CYC_VDB_WR               ((uint32_t)0x0040)           /*!<Cache LRU algorithm combination configuration bit */
#define  CMU_PREFETCH_HF_RECTR                 ((uint32_t)0x0080)           /*!<Automatic 2T fetch control                        */
#define  CMU_PREFETCH_CTRL_2T                  ((uint32_t)0x0100)           /*!<Fixed 2T control                                  */
#define  CMU_PREFETCH_FLASH_WR_SYN             ((uint32_t)0x0200)           /*!<Flash-cache write synchronization control         */

#define  CMU_PREFETCH_CYC_LRU_CLOSE            ((uint32_t)0x0000)           /*!<Close background LRU replacement function         */
#define  CMU_PREFETCH_CYC_LRU_FMISS            ((uint32_t)0x0020)           /*!<Start the background LRU forward replacement function, only replace in miss */
#define  CMU_PREFETCH_CYC_LRU_RMISS            ((uint32_t)0x0010)           /*!<Start the background LRU reverse replacement function, only replace in miss */
#define  CMU_PREFETCH_CYC_LRU_FACCESS          ((uint32_t)0x0060)           /*!<Start the background LRU forward replacement function, and replace it every time you access */
#define  CMU_PREFETCH_CYC_LRU_RACCESS          ((uint32_t)0x0050)           /*!<Start the background LRU reverse replacement function, and replace it every time you access */
#elif  defined  USE_HT7x2x_MEMORY
#define  CMU_PREFETCH                          ((uint32_t)0x03f7)           /*!<Instruction prefetch enable control               */
#define  CMU_PREFETCH_3T_EN                    ((uint32_t)0x0080)           /*!<Fixed 3T control                                  */
#define  CMU_PREFETCH_CTRL_2T                  ((uint32_t)0x0100)           /*!<Fixed 2T control                                  */
#elif  defined  USE_HT633x_MEMORY
#define  CMU_PREFETCH                          ((uint32_t)0xffff)           /*!<Instruction prefetch enable control               */
#define  CMU_PREFETCH_CACHE_EN                 ((uint32_t)0x0001)           /*!<Cache enable                                      */
#define  CMU_PREFETCH_CTRL_2T                  ((uint32_t)0x0100)           /*!<Fixed 2T control                                  */
#define  CMU_PREFETCH_WRSYN                    ((uint32_t)0x0200)           /*!<Flash write synchronous control                   */
#define  CMU_PREFETCH_LPFETCH                  ((uint32_t)0x0800)           /*!<lp mode flash fetch                               */
#define  CMU_PREFETCH_LATENCY                  ((uint32_t)0x7000)           /*!<Set flash latency                                 */
#define  CMU_PREFETCH_LATENCY_0                ((uint32_t)0x0000)           /*!<flash fetch cycle = 1                             */
#define  CMU_PREFETCH_LATENCY_1                ((uint32_t)0x1000)           /*!<flash fetch cycle = 2                             */
#define  CMU_PREFETCH_LATENCY_2                ((uint32_t)0x2000)           /*!<flash fetch cycle = 3                             */
#define  CMU_PREFETCH_LATENCY_3                ((uint32_t)0x3000)           /*!<flash fetch cycle = 4                             */
#define  CMU_PREFETCH_LATENCY_4                ((uint32_t)0x4000)           /*!<flash fetch cycle = 5                             */
#define  CMU_PREFETCH_LATENCY_5                ((uint32_t)0x5000)           /*!<flash fetch cycle = 6                             */
#define  CMU_PREFETCH_LATENCY_6                ((uint32_t)0x6000)           /*!<flash fetch cycle = 7                             */
#define  CMU_PREFETCH_LATENCY_7                ((uint32_t)0x7000)           /*!<flash fetch cycle = 8                             */
#endif

#if  defined  USE_HT633x_MEMORY
#define FLASH_TIMECTRL_DEFAULT                 ((uint32_t)0x100000)         
#endif

/************************  Bit definition for FLASHDLY register of HT_CMU_TypeDef ***********************/
#if  defined  USE_HT501x_MEMORY  ||  defined  USE_HT502x_MEMORY
#define  CMU_FLASHDLY                          ((uint32_t)0x0001)           /*!<Instruction delay control */
#define  CMU_FLASHDLY_ENABLE                   ((uint32_t)0x0001)           /*!<Enable flash delay        */
#define  CMU_FLASHDLY_DISABLE                  ((uint32_t)0x0000)           /*!<Disable flash delay       */
#endif
#if  defined  USE_HT503x_MEMORY
#define  CMU_FLASHDLY                          ((uint32_t)0x03f7)           /*!<Instruction delay control */
#define  CMU_FLASHDLY_2T_EN                    ((uint32_t)0x0001)           /*!<Flash 2T delay enable bit */
#define  CMU_FLASHDLY_3T_EN                    ((uint32_t)0x0080)           /*!<Flash 3T delay enable bit */
#define  CMU_FLASHDLY_CACHE_EN                 ((uint32_t)0x0100)           /*!<cache enable control bit  */
#endif

#if  defined USE_FLASH_FLASHCON2
/************************  Bit definition for FLASHCON2 register of HT_CMU_TypeDef **********************/
#define  CMU_FLASHCON2                         ((uint32_t)0xffff)           /*!<Flash control register 2    */
#define  CMU_FLASHCON2_FOP                     ((uint32_t)0xffff)           /*!<Flash operation mode        */
#define  CMU_FLASHCON2_FOP_READ                ((uint32_t)0x0000)           /*!<Flash is in read-only mode  */
#define  CMU_FLASHCON2_FOP_WRITE               ((uint32_t)0xca53)           /*!<Flash is in write only mode */
#define  CMU_FLASHCON2_FOP_PAGEERASE           ((uint32_t)0xac35)           /*!<Flash is in page erase mode */
#endif

#if  defined  HT6x2x  ||  defined  HT6x2xK
/************************  Bit definition for RCCALICON register of HT_CMU_TypeDef **********************/
#define  CMU_RCCALICON                         ((uint32_t)0x001f)           /*!<HRC correction configuration register   */

#define  CMU_RCCALICON_HRCAutoCali             ((uint32_t)0x0001)           /*!<HRC auto test enable bit         */
#define  CMU_RCCALICON_LRCAutoCali             ((uint32_t)0x0002)           /*!<LRC auto test enable bit         */
#define  CMU_RCCALICON_HRCCaliStart            ((uint32_t)0x0004)           /*!<HRC frequency measurement enable */
#define  CMU_RCCALICON_LRCCaliStart            ((uint32_t)0x0008)           /*!<LRC frequency measurement enable */

#define  CMU_RCCALICON_FreqSource              ((uint32_t)0x0010)           /*!<The selected 1Hz clock source to be tested      */
#define  CMU_RCCALICON_FreqSourceInner         ((uint32_t)0x0000)           /*!<The source of the tested clock is internal 32Hz */
#define  CMU_RCCALICON_FreqSourceOut           ((uint32_t)0x0010)           /*!<The source of the tested clock is external 1Hz  */

/************************  Bit definition for RCCALIIE register of HT_CMU_TypeDef ***********************/
#define  CMU_RCCALIIE                          ((uint32_t)0x0003)           /*!<HRC/LRC frequency measurement interrupt enable */

#define  CMU_RCCALIIE_HRCCaliIE                ((uint32_t)0x0001)           /*!<HRC frequency measurement interrupt enable bit */
#define  CMU_RCCALIIE_LRCCaliIE                ((uint32_t)0x0002)           /*!<LRC frequency measurement interrupt enable bit */

/************************  Bit definition for RCCALIIF register of HT_CMU_TypeDef ***********************/
#define  CMU_RCCALIIF                          ((uint32_t)0x0003)           /*!<HRC/LRC frequency measurement interrupt flag bit */

#define  CMU_RCCALIIF_HRCCaliIF                ((uint32_t)0x0001)           /*!<HRC frequency measurement interrupt flag bit     */
#define  CMU_RCCALIIF_LRCCaliIF                ((uint32_t)0x0002)           /*!<LRC frequency measurement interrupt flag bit     */

/************************  Bit definition for HRCVALUE register of HT_CMU_TypeDef ***********************/
#define  CMU_HRCVALUE                          ((uint32_t)0xffffff)         /*!<HRC frequency measurement value */

/************************  Bit definition for LRCVALUE register of HT_CMU_TypeDef ***********************/
#define  CMU_LRCVALUE                          ((uint32_t)0x1ffff)          /*!<LRC frequency measurement value */
#endif

/*************************  Bit definition for INFOLOCK register of HT_CMU_TypeDef ************************/
#define  CMU_INFOLOCK                            ((uint32_t)0xffff)           /*!<Info lock register        */
#define  CMU_INFOLOCK_UnLocked                   ((uint32_t)0xf998)           /*!<Info write/erase unlock   */
#define  CMU_INFOLOCK_Locked                     ((uint32_t)0x0000)           /*!<Info lock             */
                                                                              /*!<0xF998 : Unlock       */

#if defined USE_HT603x_MEMORY
#define  INFOLOCK                                INFOLOCK_A  
#define  CMU_INFOLOCK_A                          CMU_INFOLOCK                 /*!<Info lock register A 0x00100000~0x001003FF */
#define  CMU_INFOLOCK_A_UnLocked                 CMU_INFOLOCK_UnLocked        /*!<Info write/erase unlock   */
#define  CMU_INFOLOCK_A_Locked                   CMU_INFOLOCK_Locked          /*!<Info lock             */
                                                                              /*!<0xF998 : Unlock       */

#define  CMU_INFOLOCK_B                          ((uint32_t)0xffff)           /*!<Info lock registar B 0x00100400~0x001007FF */
                                                                              /*!< This function is not open and cannot be used at present */
#define  CMU_INFOLOCK_B_UnLocked                 ((uint32_t)0xf997)           /*!<Info write/erase unlock   */
#define  CMU_INFOLOCK_B_Locked                   ((uint32_t)0x0000)           /*!<Info lock             */                                                                            /*!<0xF997 : Unlock       */
                                                                              /*!<0xF997 : Unlock       */
#endif

/*************************  Bit definition for C_PLL register of HT_CMU_TypeDef ************************/
#if  defined  HT6x3x
#define  CMU_C_PLL                             ((uint32_t)0xff07)           /*!<PLL clock frequency generation control register */
#define  CMU_C_PLL_WRPEG                       ((uint32_t)0xA500)           /*!<C_PLL register write protection bit */
#define  CMU_C_PLL_CPLL                        ((uint32_t)0x0007)           /*!<C_PLL control bit masking           */
#define  CMU_C_PLL_39M                         ((uint32_t)0x0000)           /*!<PLL clock frequency is 39.845888MHz */
#define  CMU_C_PLL_40M                         ((uint32_t)0x0001)           /*!<PLL clock frequency is 40.894464MHz */
#define  CMU_C_PLL_41M                         ((uint32_t)0x0002)           /*!<PLL clock frequency is 41.943040MHz */
#define  CMU_C_PLL_42M                         ((uint32_t)0x0003)           /*!<PLL clock frequency is 42.991616MHz */
#define  CMU_C_PLL_44M                         ((uint32_t)0x0004)           /*!<PLL clock frequency is 44.040192MHz */
#define  CMU_C_PLL_45M                         ((uint32_t)0x0005)           /*!<PLL clock frequency is 45.088768MHz */
#define  CMU_C_PLL_46M                         ((uint32_t)0x0006)           /*!<PLL clock frequency is 46.137344MHz */
#define  CMU_C_PLL_47M                         ((uint32_t)0x0007)           /*!<PLL clock frequency is 47.185920MHz */
#endif

/*************************  Bit definition for HIT_RATIO register of HT_CMU_TypeDef ************************/
#if  defined  HT6x3x
#define  CMU_HIT_RATIO                         ((uint32_t)0xffffffff)       /*!<Cache-hit-ratio         */
#endif

/*************************  Bit definition for FSxLOCK register of HT_CMU_TypeDef ************************/
#if  defined  USE_HT502x_MEMORY
#define  CMU_FS1LOCK                             ((uint32_t)0xffff)           /*!<FlashSector1 lock register      */
#define  CMU_FS1LOCK_UnLocked                    ((uint32_t)0x7161)           /*!<FlashSector1 write/erase unlock */
#define  CMU_FS1LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector1 lock         */
                                                                              /*!<0x7161 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS2LOCK                             ((uint32_t)0xffff)           /*!<FlashSector2 lock register      */
#define  CMU_FS2LOCK_UnLocked                    ((uint32_t)0x7262)           /*!<FlashSector2 write/erase unlock */
#define  CMU_FS2LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector2 lock         */
                                                                              /*!<0x7262 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS3LOCK                             ((uint32_t)0xffff)           /*!<FlashSector3 lock register      */
#define  CMU_FS3LOCK_UnLocked                    ((uint32_t)0x7363)           /*!<FlashSector3 write/erase unlock */
#define  CMU_FS3LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector3 lock         */
                                                                              /*!<0x7363 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS4LOCK                             ((uint32_t)0xffff)           /*!<FlashSector4 lock register      */
#define  CMU_FS4LOCK_UnLocked                    ((uint32_t)0x7464)           /*!<FlashSector4 write/erase unlock */
#define  CMU_FS4LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector4 lock         */
                                                                              /*!<0x7464 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS5LOCK                             ((uint32_t)0xffff)           /*!<FlashSector5 lock register      */
#define  CMU_FS5LOCK_UnLocked                    ((uint32_t)0x7565)           /*!<FlashSector5 write/erase unlock */
#define  CMU_FS5LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector5 lock         */
                                                                              /*!<0x7565 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS6LOCK                             ((uint32_t)0xffff)           /*!<FlashSector6 lock register      */
#define  CMU_FS6LOCK_UnLocked                    ((uint32_t)0x7666)           /*!<FlashSector6 write/erase unlock */
#define  CMU_FS6LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector6 lock         */
                                                                              /*!<0x7666 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS7LOCK                             ((uint32_t)0xffff)           /*!<FlashSector7 lock register      */
#define  CMU_FS7LOCK_UnLocked                    ((uint32_t)0x7767)           /*!<FlashSector7 write/erase unlock */
#define  CMU_FS7LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector7 lock         */
                                                                              /*!<0x7767 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS8LOCK                             ((uint32_t)0xffff)           /*!<FlashSector8 lock register      */
#define  CMU_FS8LOCK_UnLocked                    ((uint32_t)0x7868)           /*!<FlashSector8 write/erase unlock */
#define  CMU_FS8LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector8 lock         */
                                                                              /*!<0x7868 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FS9LOCK                             ((uint32_t)0xffff)           /*!<FlashSector9 lock register      */
#define  CMU_FS9LOCK_UnLocked                    ((uint32_t)0x7969)           /*!<FlashSector9 write/erase unlock */
#define  CMU_FS9LOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSector9 lock         */
                                                                              /*!<0x7969 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSALOCK                             ((uint32_t)0xffff)           /*!<FlashSectorA lock register      */
#define  CMU_FSALOCK_UnLocked                    ((uint32_t)0x7a6a)           /*!<FlashSectorA write/erase unlock */
#define  CMU_FSALOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSectorA lock         */
                                                                              /*!<0x7A6A : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSBLOCK                             ((uint32_t)0xffff)           /*!<FlashSectorB lock register      */
#define  CMU_FSBLOCK_UnLocked                    ((uint32_t)0x7b6b)           /*!<FlashSectorB write/erase unlock */
#define  CMU_FSBLOCK_Locked                      ((uint32_t)0x0000)           /*!<FlashSectorB lock         */
                                                                              /*!<0x7B6B : Unlock           */
                                                                              /*!<other  : Lock             */

#elif  defined  USE_HT603x_MEMORY  ||  defined  USE_HT503x_MEMORY  

#define  CMU_FSA1LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA1 lock register      */
#define  CMU_FSA1LOCK_UnLocked                   ((uint32_t)0x7161)           /*!<FlashSectorA1 write/erase unlock */
#define  CMU_FSA1LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA1 lock         */
                                                                              /*!<0x7161 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA2LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA2 lock register      */
#define  CMU_FSA2LOCK_UnLocked                   ((uint32_t)0x7262)           /*!<FlashSectorA2 write/erase unlock */
#define  CMU_FSA2LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA2 lock         */
                                                                              /*!<0x7262 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA3LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA3 lock register      */
#define  CMU_FSA3LOCK_UnLocked                   ((uint32_t)0x7363)           /*!<FlashSectorA3 write/erase unlock */
#define  CMU_FSA3LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA3 lock         */
                                                                              /*!<0x7363 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA4LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA4 lock register      */
#define  CMU_FSA4LOCK_UnLocked                   ((uint32_t)0x7464)           /*!<FlashSectorA4 write/erase unlock */
#define  CMU_FSA4LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA4 lock         */
                                                                              /*!<0x7464 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA5LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA5 lock register      */
#define  CMU_FSA5LOCK_UnLocked                   ((uint32_t)0x7565)           /*!<FlashSectorA5 write/erase unlock */
#define  CMU_FSA5LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA5 lock         */
                                                                              /*!<0x7565 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA6LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA6 lock register      */
#define  CMU_FSA6LOCK_UnLocked                   ((uint32_t)0x7666)           /*!<FlashSectorA6 write/erase unlock */
#define  CMU_FSA6LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA6 lock         */
                                                                              /*!<0x7666 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA7LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA7 lock register      */
#define  CMU_FSA7LOCK_UnLocked                   ((uint32_t)0x7767)           /*!<FlashSectorA7 write/erase unlock */
#define  CMU_FSA7LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA7 lock         */
                                                                              /*!<0x7767 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA8LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA8 lock register      */
#define  CMU_FSA8LOCK_UnLocked                   ((uint32_t)0x7868)           /*!<FlashSectorA8 write/erase unlock */
#define  CMU_FSA8LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA8 lock         */
                                                                              /*!<0x7868 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSA9LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorA9 lock register      */
#define  CMU_FSA9LOCK_UnLocked                   ((uint32_t)0x7969)           /*!<FlashSectorA9 write/erase unlock */
#define  CMU_FSA9LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorA9 lock         */
                                                                              /*!<0x7969 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSAALOCK                            ((uint32_t)0xffff)           /*!<FlashSectorAA lock register      */
#define  CMU_FSAALOCK_UnLocked                   ((uint32_t)0x7a6a)           /*!<FlashSectorAA write/erase unlock */
#define  CMU_FSAALOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorAA lock         */
                                                                              /*!<0x7A6A : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB1LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB1 lock register      */
#define  CMU_FSB1LOCK_UnLocked                   ((uint32_t)0x8161)           /*!<FlashSectorB1 write/erase unlock */
#define  CMU_FSB1LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB1 lock         */
                                                                              /*!<0x8161 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB2LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB2 lock register      */
#define  CMU_FSB2LOCK_UnLocked                   ((uint32_t)0x8262)           /*!<FlashSectorB2 write/erase unlock */
#define  CMU_FSB2LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB2 lock         */
                                                                              /*!<0x8262 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB3LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB3 lock register      */
#define  CMU_FSB3LOCK_UnLocked                   ((uint32_t)0x8363)           /*!<FlashSectorB3 write/erase unlock */
#define  CMU_FSB3LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB3 lock         */
                                                                              /*!<0x8363 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB4LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB4 lock register      */
#define  CMU_FSB4LOCK_UnLocked                   ((uint32_t)0x8464)           /*!<FlashSectorB4 write/erase unlock */
#define  CMU_FSB4LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB4 lock         */
                                                                              /*!<0x8464 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB5LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB5 lock register      */
#define  CMU_FSB5LOCK_UnLocked                   ((uint32_t)0x8565)           /*!<FlashSectorB5 write/erase unlock */
#define  CMU_FSB5LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB5 lock         */
                                                                              /*!<0x8565 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB6LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB6 lock register      */
#define  CMU_FSB6LOCK_UnLocked                   ((uint32_t)0x8666)           /*!<FlashSectorB6 write/erase unlock */
#define  CMU_FSB6LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB6 lock         */
                                                                              /*!<0x8666 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB7LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB7 lock register      */
#define  CMU_FSB7LOCK_UnLocked                   ((uint32_t)0x8767)           /*!<FlashSectorB7 write/erase unlock */
#define  CMU_FSB7LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB7 lock         */
                                                                              /*!<0x8767 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB8LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB8 lock register      */
#define  CMU_FSB8LOCK_UnLocked                   ((uint32_t)0x8868)           /*!<FlashSectorB8 write/erase unlock */
#define  CMU_FSB8LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB8 lock         */
                                                                              /*!<0x8868 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSB9LOCK                            ((uint32_t)0xffff)           /*!<FlashSectorB9 lock register      */
#define  CMU_FSB9LOCK_UnLocked                   ((uint32_t)0x8969)           /*!<FlashSectorB9 write/erase unlock */
#define  CMU_FSB9LOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorB9 lock         */
                                                                              /*!<0x8969 : Unlock           */
                                                                              /*!<other  : Lock             */

#define  CMU_FSBBLOCK                            ((uint32_t)0xffff)           /*!<FlashSectorBB lock register      */
#define  CMU_FSBBLOCK_UnLocked                   ((uint32_t)0x8a6a)           /*!<FlashSectorBB write/erase unlock */
#define  CMU_FSBBLOCK_Locked                     ((uint32_t)0x0000)           /*!<FlashSectorBB lock         */
                                                                              /*!<0x8A6A : Unlock           */                                                                             /*!<other  : Lock             */
                                                                              /*!<other  : Lock             */
#endif

#if  defined  USE_HT503x_MEMORY
#define  CMU_INFOLOCKD                         ((uint32_t)0xffff)              /*!<info BlockD lock register      */
#define  CMU_INFOLOCKD_UnLocked                ((uint32_t)0xf996)              /*!<info BlockD write/erase unlock */
#define  CMU_INFOLOCKD_Locked                  ((uint32_t)0x0000)              /*!<info BlockD lock         */
                                                                               /*!<0xf996 : Unlock           */  
																			   
#define  CMU_INFOLOCKE                         ((uint32_t)0xffff)              /*!<info BlockE lock register      */
#define  CMU_INFOLOCKE_UnLocked                ((uint32_t)0xf995)              /*!<info BlockE write/erase unlock */
#define  CMU_INFOLOCKE_Locked                  ((uint32_t)0x0000)              /*!<info BlockE lock         */
                                                                               /*!<0xf995 : Unlock     */

#define  CMU_INFOLOCKF                         ((uint32_t)0xffff)              /*!<info BlockF lock register      */
#define  CMU_INFOLOCKF_UnLocked                ((uint32_t)0xf994)              /*!<info BlockF write/erase unlock */
#define  CMU_INFOLOCKF_Locked                  ((uint32_t)0x0000)              /*!<info BlockF lock         */
                                                                               /*!<0xf994 : Unlock     */
																			   
#define  CMU_INFOLOCKG                         ((uint32_t)0xffff)              /*!<info BlockG lock register      */
#define  CMU_INFOLOCKG_UnLocked                ((uint32_t)0xf993)              /*!<info BlockG write/erase unlock */
#define  CMU_INFOLOCKG_Locked                  ((uint32_t)0x0000)              /*!<info BlockG lock         */
                                                                               /*!<0xf993 : Unlock     */	
																			   
#define  CMU_INFOLOCKH                         ((uint32_t)0xffff)              /*!<info BlockH lock register      */
#define  CMU_INFOLOCKH_UnLocked                ((uint32_t)0xf992)              /*!<info BlockH write/erase unlock */
#define  CMU_INFOLOCKH_Locked                  ((uint32_t)0x0000)              /*!<info BlockH lock         */
                                                                               /*!<0xf992 : Unlock     */
																			   
#define  CMU_INFOLOCKI                         ((uint32_t)0xffff)              /*!<info BlockI lock register      */
#define  CMU_INFOLOCKI_UnLocked                ((uint32_t)0xf991)              /*!<info BlockI write/erase unlock */
#define  CMU_INFOLOCKI_Locked                  ((uint32_t)0x0000)              /*!<info BlockI lock         */
                                                                               /*!<0xf991 : Unlock     */
																			   
#define  CMU_INFOLOCKJ                         ((uint32_t)0xffff)              /*!<info BlockJ lock register      */
#define  CMU_INFOLOCKJ_UnLocked                ((uint32_t)0xf990)              /*!<info BlockJ write/erase unlock */
#define  CMU_INFOLOCKJ_Locked                  ((uint32_t)0x0000)              /*!<info BlockJ lock         */
                                                                               /*!<0xf990 : Unlock     */																			   

#define  CMU_INFOLOCKK                         ((uint32_t)0xffff)              /*!<info BlockK lock register      */
#define  CMU_INFOLOCKK_UnLocked                ((uint32_t)0xf98f)              /*!<info BlockK write/erase unlock */
#define  CMU_INFOLOCKK_Locked                  ((uint32_t)0x0000)              /*!<info BlockK lock         */
                                                                               /*!<0xf98f : Unlock     */
																			   
#define  CMU_INFOLOCKL                         ((uint32_t)0xffff)              /*!<info BlockL lock register      */
#define  CMU_INFOLOCKL_UnLocked                ((uint32_t)0xf98e)              /*!<info BlockL write/erase unlock */
#define  CMU_INFOLOCKL_Locked                  ((uint32_t)0x0000)              /*!<info BlockL lock         */
                                                                               /*!<0xf98e : Unlock     */

#define  CMU_INFOLOCKM                         ((uint32_t)0xffff)              /*!<info BlockM lock register      */
#define  CMU_INFOLOCKM_UnLocked                ((uint32_t)0xf98d)              /*!<info BlockM write/erase unlock */
#define  CMU_INFOLOCKM_Locked                  ((uint32_t)0x0000)              /*!<info BlockM lock         */
                                                                               /*!<0xf98d : Unlock     */
																			   
#define  CMU_INFOLOCKN                         ((uint32_t)0xffff)              /*!<info BlockN lock register      */
#define  CMU_INFOLOCKN_UnLocked                ((uint32_t)0xf98c)              /*!<info BlockN write/erase unlock */
#define  CMU_INFOLOCKN_Locked                  ((uint32_t)0x0000)              /*!<info BlockN lock         */
                                                                               /*!<0xf98c : Unlock     */
#endif

#if  defined  HT633x
/************************  Bit definition for EMUCLKCFG register of HT_CMU_TypeDef ***********************/
#define  CMU_EMUCLKCFG                         ((uint32_t)0x70ff)           /*!<EMU clock configuration register                  */
#define  CMU_EMUCLKCFG_EMUCLKDIV               ((uint32_t)0x00ff)           /*!<EMU clock divider, EMUCLK=EMUCLKSEL/(EMUCLKDIV+1) */

#define  CMU_EMUCLKCFG_EMUCLKSEL               ((uint32_t)0x7000)           /*!<EMU clock source selection control bit            */
#define  CMU_EMUCLKCFG_EMUCLKSEL_PLLX2         ((uint32_t)0x0000)           /*!<EMU clock source is PLLX2                         */
#define  CMU_EMUCLKCFG_EMUCLKSEL_HRC           ((uint32_t)0x1000)           /*!<EMU clock source is HRC11M                        */
#define  CMU_EMUCLKCFG_EMUCLKSEL_OSC           ((uint32_t)0x2000)           /*!<EMU clock source is OSC                           */


#endif

#if  defined  HT762x  ||  defined  HT772x ||  defined  HT503x  ||  defined HT633x
/************************  Bit definition for LFDETCFG register of HT_CMU_TypeDef ***********************/
	#if !defined HT633x
		#define  CMU_LFDETCFG                          ((uint32_t)0x00e7)           /*!<LF stop vibration detection configuration register */
	#else
		#define  CMU_LFDETCFG                          ((uint32_t)0x03e7)           /*!<LF stop vibration detection configuration register */
		#define  CMU_LFDETCFG_DETCLKDIV                ((uint32_t)0x0001)           /*!<Detection clock divider control bit                */
		#define  CMU_LFDETCFG_STOP_NUM                 ((uint32_t)0x0006)           /*!<OSC stop vibration lock cycle number setting       */
		#define  CMU_LFDETCFG_STOP_NUM_0               ((uint32_t)0x0000)           /*!<The number of OSC lockout periods is 28-36         */
		#define  CMU_LFDETCFG_STOP_NUM_1               ((uint32_t)0x0002)           /*!<The number of OSC lockout periods is 24-40         */
		#define  CMU_LFDETCFG_STOP_NUM_2               ((uint32_t)0x0004)           /*!<The number of OSC lockout periods is 20-44         */
		#define  CMU_LFDETCFG_STOP_NUM_3               ((uint32_t)0x0006)           /*!<The number of OSC lockout periods is 16-48         */

		#define  CMU_LFDETCFG_STOP_LIMIT               ((uint32_t)0x0060)           /*!<Stop detection threshold setting                   */
		#define  CMU_LFDETCFG_STOP_LIMIT_0             ((uint32_t)0x0000)           /*!<40% LRC                                            */
		#define  CMU_LFDETCFG_STOP_LIMIT_1             ((uint32_t)0x0020)           /*!<50% LRC                                            */
		#define  CMU_LFDETCFG_STOP_LIMIT_2             ((uint32_t)0x0040)           /*!<60% LRC                                            */
		#if !defined HT633x
			#define  CMU_LFDETCFG_STOP_LIMIT_3             ((uint32_t)0x0060)           /*!<Stop vibration detection switch to the old mode    */
		#else
			#define  CMU_LFCLKCFG_LFDETMODSEL              ((uint32_t)0x0300)           /*!<osc detect mode selection control bit              */
			#define  CMU_LFCLKCFG_LFDETMODSEL_0            ((uint32_t)0x0300)           /*!<osc detect mode select new mode                    */
			#define  CMU_LFCLKCFG_LFDETMODSEL_1            ((uint32_t)0x0300)           /*!<osc detect mode select ole mode                    */
			#define  CMU_LFCLKCFG_LFDETMODSEL_2            ((uint32_t)0x0300)           /*!<osc detect mode select analog mode                 */
		#endif
		#define  CMU_LFDETCFG_QUICKSTOP                ((uint32_t)0x0080)           /*!<Quick stop vibration detection control bit         */
	#endif
#endif

#if  defined  HT762x  ||  defined  HT772x
/************************  Bit definition for HRCCLKCFG register of HT_CMU_TypeDef ***********************/
#define  CMU_HRCCLKCFG_HRC20M                  ((uint32_t)0x0100)           /*!<HRC clock prescaler control bit  */
#define  CMU_HRCCLKCFG_HRC20M_DIV2             ((uint32_t)0x0000)           /*!<HRC clock divided by 2           */
#define  CMU_HRCCLKCFG_HRC20M_DIV1             ((uint32_t)0x0100)           /*!<HRC clock is not divided         */
#endif

#if  defined  HT633x
/************************  Bit definition for HRCCLKCFG register of HT_CMU_TypeDef ***********************/
#define  CMU_HRCCLKCFG_HRCCLKSEL               ((uint32_t)0x0300)           /*!<HRC clock configuration register */
#define  CMU_HRCCLKCFG_HRCCLKSEL_00            ((uint32_t)0x0000)           /*!<HRC clock is 11.01MHz            */
#define  CMU_HRCCLKCFG_HRCCLKSEL_01            ((uint32_t)0x0100)           /*!<HRC clock is 22.02MHz            */
#define  CMU_HRCCLKCFG_HRCCLKSEL_10            ((uint32_t)0x0200)           /*!<HRC clock is 33.03MHz            */
#define  CMU_HRCCLKCFG_HRCCLKSEL_11            ((uint32_t)0x0300)           /*!<HRC clock is 11.01MHz            */
#endif

#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT6x2xK
/************************  Bit definition for LFCLKCFG  register of HT_CMU_TypeDef ***********************/
#define  CMU_LFCLKCFG                          ((uint32_t)0x0003)           /*!<Low frequency clock configuration register   */
#define  CMU_LFCLKCFG_RTCCLKSEL                ((uint32_t)0x0001)           /*!<RTC module clock selection configuration bit */
#define  CMU_LFCLKCFG_RTCCLKSEL_OSC            ((uint32_t)0x0000)           /*!<RTC module clock selection OSC               */
#define  CMU_LFCLKCFG_RTCCLKSEL_LRC            ((uint32_t)0x0001)           /*!<RTC module clock selection LRC               */

#define  CMU_LFCLKCFG_TBSLFSEL                 ((uint32_t)0x0002)           /*!<TBS module clock selection configuration bit */
#define  CMU_LFCLKCFG_TBSLFSEL_TBSCLKSEL       ((uint32_t)0x0000)           /*!<TBS module is determined by TBSCLKSEL        */
#define  CMU_LFCLKCFG_TBSLFSEL_LRC             ((uint32_t)0x0002)           /*!<TBS module clock select LRC                  */
#endif

#if  defined  HT633x
/************************  Bit definition for TBSCLKCFG  register of HT_CMU_TypeDef ***********************/
#define  CMU_TBSCLKCFG                          ((uint32_t)0xff30)           /*!<TBS clock configuration register      */
#define  CMU_TBSCLKCFG_HSTBSCLKSEL              ((uint32_t)0x0030)           /*!<TBS high frequency clock selection configuration bit */
#define  CMU_TBSCLKCFG_HSTBSCLKSEL_PLLX2        ((uint32_t)0x0000)           /*!<TBS high frequency clock select PLLX2 */
#define  CMU_TBSCLKCFG_HSTBSCLKSEL_HRC          ((uint32_t)0x0001)           /*!<TBS high frequency clock select HRC   */

#define  CMU_TBSCLKCFG_HSTBSDIV                 ((uint32_t)0xFF00)           /*!<TBS high frequency clock divider      */
#endif

#if  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x  ||  defined HT633x
/************************  Bit definition for OSCSTA  register of HT_CMU_TypeDef ***********************/
#define  CMU_OSCSTA_OVERFLAG                   ((uint32_t)0x01)             /*!<OSC overclocking flag             */
#define  CMU_OSCSTA_AUXLFFLAG                  ((uint32_t)0x02)             /*!<OSC auxiliary vibration stop flag */
#endif

#if	 defined  USE_CMU_KEYCLKCFG
/************************  Bit definition for KEYCLKCFG  register of HT_CMU_TypeDef ***********************/
#define  CMU_KEYCLKCFG                         ((uint32_t)0x01)             /*!<Key module clock control register */
#define  CMU_KEYCLKCFG_KEYCLKSEL               ((uint32_t)0x01)             /*!<Key module clock selection        */
#define  CMU_KEYCLKCFG_KEYCLKSEL_OSC           ((uint32_t)0x00)             /*!<Key module clock select OSC       */
#define  CMU_KEYCLKCFG_KEYCLKSEL_LRC           ((uint32_t)0x01)             /*!<Key module clock select LRC       */
#endif

#if  defined  HT503x ||  defined HT633x
/************************  Bit definition for RTCCLKCFG  register of HT_CMU_TypeDef ***********************/
#define  CMU_RTCCLKCFG                         ((uint32_t)0x01)             /*!<RTC clock control register */
#define  CMU_RTCCLKCFG_RTCCLKSEL               ((uint32_t)0x01)             /*!<RTC clock selection        */
#define  CMU_RTCCLKCFG_RTCCLKSEL_OSC           ((uint32_t)0x00)             /*!<RTC clock select OSC       */
#define  CMU_RTCCLKCFG_RTCCLKSEL_LRC           ((uint32_t)0x01)             /*!<RTC clock select LRC       */
#endif

#if  defined  HT633x
/************************  Bit definition for TOUTCLKCFG  register of HT_CMU_TypeDef ***********************/
#define  CMU_TOUTCLKCFG                        ((uint32_t)0x03FF30)         /*!<TOUT clock control register */
#define  CMU_TOUTCLKCFG_HRCTOUTDIV             ((uint32_t)0x0030)           /*!<TOUT clock divider when source is hrc clock */
#define  CMU_TOUTCLKCFG_HRCTOUTDIV_1           ((uint32_t)0x0000)           /*!<HRC/1                       */
#define  CMU_TOUTCLKCFG_HRCTOUTDIV_2           ((uint32_t)0x0000)           /*!<HRC/2                       */
#define  CMU_TOUTCLKCFG_HRCTOUTDIV_3           ((uint32_t)0x0000)           /*!<HRC/3                       */
#define  CMU_TOUTCLKCFG_HRCTOUTDIV_4           ((uint32_t)0x0000)           /*!<HRC/4                       */

#define  CMU_TOUTCLKCFG_TOUTVALUE              ((uint32_t)0x03FF00)         /*!<TOUT clock divider = INT(HSTOUTCLK/32768) */
#endif

#if defined USE_CMU_CHIPID
/*************************  Bit definition for CHIPID register of HT_CMU_TypeDef ************************/
    #if  defined  HT633x
    #define  CMU_CHIPID                            ((uint32_t)0xfffff)          /*!<ChipID                */
    #else
    #define  CMU_CHIPID                            ((uint32_t)0xffff)           /*!<ChipID                */
    #endif
#endif

/*************************  Bit definition for PLLLOCK_PRE register of HT_CMU_TypeDef ************************/
#if  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined HT633x
#define  CMU_PLLLOCK_PRE                       ((uint32_t)0x0033)           /*!<PLL lock condition setting register */
#define  CMU_PLLLOCK_PRE_SamNum                ((uint32_t)0x0003)           /*!<Sampling times setting              */
#define  CMU_PLLLOCK_PRE_SamNum_16             ((uint32_t)0x0000)           /*!<Sampling times: 16                  */
#define  CMU_PLLLOCK_PRE_SamNum_32             ((uint32_t)0x0001)           /*!<Sampling times: 32                  */
#define  CMU_PLLLOCK_PRE_SamNum_64             ((uint32_t)0x0002)           /*!<Sampling times: 64                  */
#define  CMU_PLLLOCK_PRE_SamNum_128            ((uint32_t)0x0003)           /*!<Sampling times: 128                 */

#define  CMU_PLLLOCK_PRE_SamValu               ((uint32_t)0x0030)           /*!<Sampling value range setting        */
#define  CMU_PLLLOCK_PRE_SamValu_2             ((uint32_t)0x0000)           /*!<Sampling value: +-2 clock           */
#define  CMU_PLLLOCK_PRE_SamValu_4             ((uint32_t)0x0010)           /*!<Sampling value: +-4 clock           */
#define  CMU_PLLLOCK_PRE_SamValu_6             ((uint32_t)0x0020)           /*!<Sampling value: +-6 clock           */
#define  CMU_PLLLOCK_PRE_SamValu_8             ((uint32_t)0x0030)           /*!<Sampling value: +-8 clock           */

#endif

/*************************  Bit definition for C_PLL register of HT_CMU_TypeDef *****************************/
#if  defined  HT633x
#define  CMU_C_PLL                             ((uint32_t)0xff07)           /*!<PLL clock frequency generation control register */
#define  CMU_C_PLL_CPLL                        ((uint32_t)0x0007)           /*!<C_PLL control bit masking           */
#define  CMU_C_PLL_0                           ((uint32_t)0x0000)           /*!<PLL clock frequency is 44.040192MHz */
#define  CMU_C_PLL_1                           ((uint32_t)0x0001)           /*!<PLL clock frequency is 41.287680MHz */
#define  CMU_C_PLL_2                           ((uint32_t)0x0002)           /*!<PLL clock frequency is 38.535168MHz */
#define  CMU_C_PLL_3                           ((uint32_t)0x0003)           /*!<PLL clock frequency is 35.782656MHz */
#define  CMU_C_PLL_4                           ((uint32_t)0x0004)           /*!<PLL clock frequency is 33.030144MHz */
#define  CMU_C_PLL_5                           ((uint32_t)0x0005)           /*!<PLL clock frequency is 30.277632MHz */
#define  CMU_C_PLL_6                           ((uint32_t)0x0006)           /*!<PLL clock frequency is 27.525120MHz */
#define  CMU_C_PLL_7                           ((uint32_t)0x0007)           /*!<PLL clock frequency is 24.772608MHz */

#define  CMU_C_PLL_WRPEG                       ((uint32_t)0xA500)           /*!<CPLL disable write protect key */
#endif

/*************************  Bit definition for FITCTR register of HT_CMU_TypeDef ************************/
#if  defined  HT762x  ||  defined  HT772x
#define  CMU_FITCLR                            ((uint32_t)0x00ff)           /*!<Clock filter control register */
#define  CMU_FITCLR_OSCCTR                     ((uint32_t)0x0003)           /*!<OSC clock filter control bit  */
#define  CMU_FITCLR_OSCCTR_NONE                ((uint32_t)0x0000)           /*!<OSC clock: without filter     */
#define  CMU_FITCLR_OSCCTR_LOW                 ((uint32_t)0x0001)           /*!<OSC clock: low filter         */
#define  CMU_FITCLR_OSCCTR_MID                 ((uint32_t)0x0002)           /*!<OSC clock: middle filter      */
#define  CMU_FITCLR_OSCCTR_HIGH                ((uint32_t)0x0003)           /*!<OSC clock: high filter        */

#define  CMU_FITCLR_LRCCTR                     ((uint32_t)0x000C)           /*!<LRC clock filter control bit  */
#define  CMU_FITCLR_LRCCTR_NONE                ((uint32_t)0x0000)           /*!<LRC clock: without filter     */
#define  CMU_FITCLR_LRCCTR_LOW                 ((uint32_t)0x0004)           /*!<LRC clock: low filter         */
#define  CMU_FITCLR_LRCCTR_MID                 ((uint32_t)0x0008)           /*!<LRC clock: middle filter      */
#define  CMU_FITCLR_LRCCTR_HIGH                ((uint32_t)0x000C)           /*!<LRC clock: high filter        */

#define  CMU_FITCLR_PLLCTR                     ((uint32_t)0x00C0)           /*!<PLL clock filter control bit  */
#define  CMU_FITCLR_PLLCTR_NONE                ((uint32_t)0x0000)           /*!<PLL clock: without filter     */
#define  CMU_FITCLR_PLLCTR_LOW                 ((uint32_t)0x0004)           /*!<PLL clock: low filter         */
#define  CMU_FITCLR_PLLCTR_MID                 ((uint32_t)0x0080)           /*!<PLL clock: middle filter      */
#endif

/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of WDT Module
**********************************************************************************************************
*/
/**************************  Bit definition for WDTCFG register of HT_WDT_TypeDef ***********************/
#if  defined  HT6x1x
#define  WDT_WDTCFG_INTRST                       ((uint32_t)0x0001)           /*!<WDT timeout INT/RESET select  */
#define  WDT_WDTCFG_INT                          ((uint32_t)0x0001)           /*!<WDT timeout INT               */
#define  WDT_WDTCFG_RST                          ((uint32_t)0x0000)           /*!<WDT timeout RESET             */
#endif

#if  defined  USE_WDTCFG_LPOVT
#define  WDT_WDTCFG_LPOVT_CTR                    ((uint32_t)0x0002)           /*!<WDT timeout mode control under SLEEP\HOLD\HOLD_LP  */
#define  WDT_WDTCFG_LPOVT_CTR_L                  ((uint32_t)0x0002)           /*!<WDT long timeout mode under SLEEP\HOLD\HOLD_LP  */
#define  WDT_WDTCFG_LPOVT_CTR_S                  ((uint32_t)0x0000)           /*!<WDT short timeout mode  */
#endif

/**************************  Bit definition for WDTCLR register of HT_WDT_TypeDef ***********************/
#define  WDT_WDTCLR                            ((uint32_t)0xffff)           /*!<WDT timeout config      */

/**************************  Bit definition for WDTCNT register of HT_WDT_TypeDef ***********************/
#define  WDT_WDTCNT                            ((uint32_t)0xffff)           /*!<WDT counter register    */


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of GPIO Module
**********************************************************************************************************
*/
/**************************  Bit definition for IOCFG register of HT_GPIO_TypeDef ***********************/
#define  GPIO_IOCFG                            ((uint32_t)0xffff)           /*!<0:GPIO 1:FunctionPin  */

/**************************  Bit definition for AFCFG register of HT_GPIO_TypeDef ***********************/
#define  GPIO_AFCFG                            ((uint32_t)0xffff)           /*!<0:Func1 1:Func2       */

/**************************  Bit definition for PTDIR register of HT_GPIO_TypeDef ***********************/
#define  GPIO_PTDIR                            ((uint32_t)0xffff)           /*!<0:In 1:Out  GPIOOnly  */

/**************************  Bit definition for PTUP register of HT_GPIO_TypeDef ************************/
#define  GPIO_PTUP                             ((uint32_t)0xffff)           /*!<0:Pull-up 1:NoPull-up*/

/**************************  Bit definition for PTDAT register of HT_GPIO_TypeDef ***********************/
#define  GPIO_PTDAT                            ((uint32_t)0xffff)           /*!<Data                  */

/**************************  Bit definition for PTSET register of HT_GPIO_TypeDef ***********************/
#define  GPIO_PTSET                            ((uint32_t)0xffff)           /*!<Write 1 to Set High   */

/**************************  Bit definition for PTCLR register of HT_GPIO_TypeDef ***********************/
#define  GPIO_PTCLR                            ((uint32_t)0xffff)           /*!<Write 1 to Set Low    */

/**************************  Bit definition for PTTOG register of HT_GPIO_TypeDef ***********************/
#define  GPIO_PTTOG                            ((uint32_t)0xffff)           /*!<Write 1 to Toggle     */

/**************************  Bit definition for PTOD register of HT_GPIO_TypeDef ************************/
#define  GPIO_PTOD                             ((uint32_t)0xffff)           /*!<0:OD 1:Push-Pull      */

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x
/**************************  Bit definition for FILT register of HT_GPIO_TypeDef ************************/
#define  GPIO_FILT                             ((uint32_t)0xffff)           /*!<0:端口滤波无效  1:端口滤波有效*/                                                                            /*!<  此寄存器仅对部分IO有效，详见用户手册 */
#endif

#if  defined  HT762x  ||  defined  HT772x
/**************************  Bit definition for HIIPM register of HT_GPIO_TypeDef ************************/
#define  GPIO_HIIPM                            ((uint32_t)0xffff)           /*!<0:端口高阻关闭  1:端口高阻开启*/
#endif 

#if  defined  HT503x
/**************************  Bit definition for AFCFG1 register of HT_GPIO_TypeDef ************************/
#define  GPIO_AFCFG1                           ((uint32_t)0xffff)           /*!<复用功能选择寄存器2*/
#endif 

/*********************  Bit definition for HT_GPIOHDPORT register of HT_GPIO_TypeDef ********************/
#define  GPIO_HDPORT                           ((uint32_t)0x000f)           /*!<大电流模式设定        */
#define  GPIO_HDPORT_PC0                         ((uint32_t)0x0001)           /*!<PC0大电流模式设定     */
#define  GPIO_HDPORT_PA6                         ((uint32_t)0x0002)           /*!<PA6大电流模式设定     */
#define  GPIO_HDPORT_PA7                         ((uint32_t)0x0004)           /*!<PA7大电流模式设定     */
#define  GPIO_HDPORT_PA8                         ((uint32_t)0x0008)           /*!<PA8大电流模式设定     */


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of INT Module
**********************************************************************************************************
*/
/**************************  Bit definition for EXTIE register of HT_INT_TypeDef ************************/
#define  INT_EXTIE                             ((uint32_t)0x7f7f)            /*!<External interrupt edge configuration register*/

#define  INT_EXTIE_FIE                           ((uint32_t)0x007f)           /*!<Falling edge interrupt enable        */
#define  INT_EXTIE_FIE_INT0                      ((uint32_t)0x0001)           /*!<INT0 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT1                      ((uint32_t)0x0002)           /*!<INT1 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT2                      ((uint32_t)0x0004)           /*!<INT2 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT3                      ((uint32_t)0x0008)           /*!<INT3 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT4                      ((uint32_t)0x0010)           /*!<INT4 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT5                      ((uint32_t)0x0020)           /*!<INT5 Falling edge interrupt enable    */
#define  INT_EXTIE_FIE_INT6                      ((uint32_t)0x0040)           /*!<INT6 Falling edge interrupt enable    */

#define  INT_EXTIE_RIE                           ((uint32_t)0x7f00)           /*!<Rising edge interrupt enable        */
#define  INT_EXTIE_RIE_INT0                      ((uint32_t)0x0100)           /*!<INT0 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT1                      ((uint32_t)0x0200)           /*!<INT1 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT2                      ((uint32_t)0x0400)           /*!<INT2 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT3                      ((uint32_t)0x0800)           /*!<INT3 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT4                      ((uint32_t)0x1000)           /*!<INT4 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT5                      ((uint32_t)0x2000)           /*!<INT5 rising edge interrupt enable    */
#define  INT_EXTIE_RIE_INT6                      ((uint32_t)0x4000)           /*!<INT6 rising edge interrupt enable    */

/**************************  Bit definition for EXTIF register of HT_INT_TypeDef ************************/
#define  INT_EXTIF                             ((uint32_t)0x7f7f)             /*!<External interrupt flag register*/

#define  INT_EXTIF_FIF                          ((uint32_t)0x007f)           /*!<Falling edge interrupt flag        */
#define  INT_EXTIF_FIF_INT0                      ((uint32_t)0x0001)           /*!<INT0 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT1                      ((uint32_t)0x0002)           /*!<INT1 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT2                      ((uint32_t)0x0004)           /*!<INT2 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT3                      ((uint32_t)0x0008)           /*!<INT3 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT4                      ((uint32_t)0x0010)           /*!<INT4 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT5                      ((uint32_t)0x0020)           /*!<INT5 falling edge interrupt flag    */
#define  INT_EXTIF_FIF_INT6                      ((uint32_t)0x0040)           /*!<INT6 falling edge interrupt flag    */

#define  INT_EXTIF_RIF                          ((uint32_t)0x7f00)           /*!<Rising edge interrupt flag        */
#define  INT_EXTIF_RIF_INT0                      ((uint32_t)0x0100)           /*!<INT0 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT1                      ((uint32_t)0x0200)           /*!<INT1 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT2                      ((uint32_t)0x0400)           /*!<INT2 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT3                      ((uint32_t)0x0800)           /*!<INT3 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT4                      ((uint32_t)0x1000)           /*!<INT4 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT5                      ((uint32_t)0x2000)           /*!<INT5 rising edge interrupt flag    */
#define  INT_EXTIF_RIF_INT6                      ((uint32_t)0x4000)           /*!<INT6 rising edge interrupt flag    */

/**************************  Bit definition for PINFLT register of HT_INT_TypeDef ***********************/
#define  INT_PINFLT                            ((uint32_t)0x7f7f)          /*!<External pin digital filter register */

#define  INT_PINFLT_INTFLT                      ((uint32_t)0x007f)           /*!<INT0-6 digital filter enable   */
#define  INT_PINFLT_INTFLT_INT0                  ((uint32_t)0x0001)          /*!<INT0 digital filter enable    */
#define  INT_PINFLT_INTFLT_INT1                  ((uint32_t)0x0002)          /*!<INT1 digital filter enable     */
#define  INT_PINFLT_INTFLT_INT2                  ((uint32_t)0x0004)          /*!<INT2 digital filter enable    */
#define  INT_PINFLT_INTFLT_INT3                  ((uint32_t)0x0008)          /*!<INT3 digital filter enable     */
#define  INT_PINFLT_INTFLT_INT4                  ((uint32_t)0x0010)          /*!<INT4 digital filter enable    */
#define  INT_PINFLT_INTFLT_INT5                  ((uint32_t)0x0020)          /*!<INT5 digital filter enable     */
#define  INT_PINFLT_INTFLT_INT6                  ((uint32_t)0x0040)          /*!<INT6 digital filter enable     */

#define  INT_PINFLT_RXFLT                       ((uint32_t)0x7f00)           /*!<RX0-6 digital filter enable   */
#define  INT_PINFLT_RXFLT_RX0                    ((uint32_t)0x0100)          /*!<RX0 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX1                    ((uint32_t)0x0200)          /*!<RX1 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX2                    ((uint32_t)0x0400)          /*!<RX2 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX3                    ((uint32_t)0x0800)          /*!<RX3 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX4                    ((uint32_t)0x1000)          /*!<RX4 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX5                    ((uint32_t)0x2000)          /*!<RX5 digital filter enable    */
#define  INT_PINFLT_RXFLT_RX6                    ((uint32_t)0x4000)          /*!<RX6 digital filter enable    */

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x || defined HT633x || defined HT633xH
/**************************  Bit definition for EXTIE2 register of HT_INT_TypeDef ***********************/
#define	 INT_EXTI2_BIT_POS									 		 ((uint32_t)16)

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x

#define  INT_EXTIE2                              ((uint32_t)0x0707<<INT_EXTI2_BIT_POS)         /*!<External interrupt edge configuration register*/
#define  INT_EXTIE2_FIE                          ((uint32_t)0x0007<<INT_EXTI2_BIT_POS)       /*!<Falling edge interrupt enable        */
#define  INT_EXTIE2_RIE                          ((uint32_t)0x0700<<INT_EXTI2_BIT_POS)       /*!<Rising edge interrupt enable        */

#elif defined HT633x || defined HT633xH
#define  INT_EXTIE2                              ((uint32_t)0xffff<<INT_EXTI2_BIT_POS)         /*!<External interrupt edge configuration register*/
#define  INT_EXTIE2_FIE                          ((uint32_t)0x00ff<<INT_EXTI2_BIT_POS)       /*!<Falling edge interrupt enable        */
#define  INT_EXTIE2_RIE                          ((uint32_t)0xff00<<INT_EXTI2_BIT_POS)       /*!<Rising edge interrupt enable        */

#endif

#define  INT_EXTIE2_FIE_INT7                     ((uint32_t)0x0001<<INT_EXTI2_BIT_POS)       /*!<INT7 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT8                     ((uint32_t)0x0002<<INT_EXTI2_BIT_POS)       /*!<INT8 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT9                     ((uint32_t)0x0004<<INT_EXTI2_BIT_POS)       /*!<INT9 Falling edge interrupt enable    */

#if defined HT633x || defined HT633xH
#define  INT_EXTIE2_FIE_INT10                     ((uint32_t)0x0008<<INT_EXTI2_BIT_POS)       /*!<INT10 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT11                     ((uint32_t)0x0010<<INT_EXTI2_BIT_POS)       /*!<INT11 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT12                     ((uint32_t)0x0020<<INT_EXTI2_BIT_POS)       /*!<INT12 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT13                     ((uint32_t)0x0040<<INT_EXTI2_BIT_POS)       /*!<INT13 Falling edge interrupt enable    */
#define  INT_EXTIE2_FIE_INT14                     ((uint32_t)0x0080<<INT_EXTI2_BIT_POS)       /*!<INT14 Falling edge interrupt enable    */
#endif


#define  INT_EXTIE2_RIE_INT7                     ((uint32_t)0x0100<<INT_EXTI2_BIT_POS)       /*!<INT7 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT8                     ((uint32_t)0x0200<<INT_EXTI2_BIT_POS)       /*!<INT8 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT9                     ((uint32_t)0x0400<<INT_EXTI2_BIT_POS)       /*!<INT9 rising edge interrupt enable    */

#if defined HT633x || defined HT633xH

#define  INT_EXTIE2_RIE_INT10                     ((uint32_t)0x0800<<INT_EXTI2_BIT_POS)       /*!<INT10 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT11                     ((uint32_t)0x1000<<INT_EXTI2_BIT_POS)       /*!<INT11 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT12                     ((uint32_t)0x2000<<INT_EXTI2_BIT_POS)       /*!<INT12 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT13                     ((uint32_t)0x4000<<INT_EXTI2_BIT_POS)       /*!<INT13 rising edge interrupt enable    */
#define  INT_EXTIE2_RIE_INT14                     ((uint32_t)0x8000<<INT_EXTI2_BIT_POS)       /*!<INT14 rising edge interrupt enable    */


#endif


/**************************  Bit definition for EXTIF2 register of HT_INT_TypeDef ***********************/


#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x

#define  INT_EXTIF2                            ((uint32_t)0x0707<<INT_EXTI2_BIT_POS)         /*!<External interrupt flag register*/
#define  INT_EXTIF2_FIF                         ((uint32_t)0x0007<<INT_EXTI2_BIT_POS)       /*!<Falling edge interrupt flag        */
#define  INT_EXTIF2_RIF                         ((uint32_t)0x0700<<INT_EXTI2_BIT_POS)       /*!<Rising edge interrupt flag        */

#elif defined HT633x || defined HT633xH

#define  INT_EXTIF2                            ((uint32_t)0xffff<<INT_EXTI2_BIT_POS)         /*!<External interrupt flag register*/
#define  INT_EXTIF2_FIF                         ((uint32_t)0x00ff<<INT_EXTI2_BIT_POS)       /*!<Falling edge interrupt flag        */
#define  INT_EXTIF2_RIF                         ((uint32_t)0xff00<<INT_EXTI2_BIT_POS)       /*!<Rising edge interrupt flag        */

#endif

#define  INT_EXTIF2_FIF_INT7                     ((uint32_t)0x0001<<INT_EXTI2_BIT_POS)       /*!<INT7 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT8                     ((uint32_t)0x0002<<INT_EXTI2_BIT_POS)       /*!<INT8 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT9                     ((uint32_t)0x0004<<INT_EXTI2_BIT_POS)       /*!<INT9 falling edge interrupt flag    */

#if defined HT633x || defined HT633xH

#define  INT_EXTIF2_FIF_INT10                     ((uint32_t)0x0008<<INT_EXTI2_BIT_POS)       /*!<INT10 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT11                     ((uint32_t)0x0010<<INT_EXTI2_BIT_POS)       /*!<INT11 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT12                     ((uint32_t)0x0020<<INT_EXTI2_BIT_POS)       /*!<INT12 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT13                     ((uint32_t)0x0040<<INT_EXTI2_BIT_POS)       /*!<INT13 falling edge interrupt flag    */
#define  INT_EXTIF2_FIF_INT14                     ((uint32_t)0x0080<<INT_EXTI2_BIT_POS)       /*!<INT14 falling edge interrupt flag    */

#endif


#define  INT_EXTIF2_RIF_INT7                     ((uint32_t)0x0100<<INT_EXTI2_BIT_POS)       /*!<INT7 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT8                     ((uint32_t)0x0200<<INT_EXTI2_BIT_POS)       /*!<INT8 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT9                     ((uint32_t)0x0400<<INT_EXTI2_BIT_POS)       /*!<INT9 rising edge interrupt flag    */

#if defined HT633x || defined HT633xH

#define  INT_EXTIF2_RIF_INT10                     ((uint32_t)0x0800<<INT_EXTI2_BIT_POS)       /*!<INT10 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT11                     ((uint32_t)0x1000<<INT_EXTI2_BIT_POS)       /*!<INT11 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT12                     ((uint32_t)0x2000<<INT_EXTI2_BIT_POS)       /*!<INT12 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT13                     ((uint32_t)0x4000<<INT_EXTI2_BIT_POS)       /*!<INT13 rising edge interrupt flag    */
#define  INT_EXTIF2_RIF_INT14                     ((uint32_t)0x8000<<INT_EXTI2_BIT_POS)       /*!<INT14 rising edge interrupt flag    */


#endif


/**************************  Bit definition for PINFLT2 register of HT_INT_TypeDef ***********************/

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT502x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
#define  INT_PINFLT2                            ((uint32_t)0x0007<<INT_EXTI2_BIT_POS)       /*!<External pin digital filter register */
#define  INT_PINFLT2_INTFLT                     ((uint32_t)0x0007<<INT_EXTI2_BIT_POS)        /*!<INT7-9 digital filter enable  */
#elif defined HT633x || defined HT633xH
#define  INT_PINFLT2                             ((uint32_t)0x00ff<<INT_EXTI2_BIT_POS)       /*!<External pin digital filter register */
#define  INT_PINFLT2_INTFLT                      ((uint32_t)0x00ff<<INT_EXTI2_BIT_POS)        /*!<INT7-14 digital filter enable  */
#endif

#define  INT_PINFLT2_INTFLT_INT7                 ((uint32_t)0x0001<<INT_EXTI2_BIT_POS)       /*!<INT7 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT8                 ((uint32_t)0x0002<<INT_EXTI2_BIT_POS)       /*!<INT8 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT9                 ((uint32_t)0x0004<<INT_EXTI2_BIT_POS)       /*!<INT9 digital filter enable    */

#if defined HT633x  || defined HT633xH
#define  INT_PINFLT2_INTFLT_INT10                ((uint32_t)0x0008<<INT_EXTI2_BIT_POS)       /*!<INT10 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT11                ((uint32_t)0x0010<<INT_EXTI2_BIT_POS)       /*!<INT11 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT12                ((uint32_t)0x0020<<INT_EXTI2_BIT_POS)       /*!<INT12 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT13                ((uint32_t)0x0040<<INT_EXTI2_BIT_POS)       /*!<INT13 digital filter enable    */
#define  INT_PINFLT2_INTFLT_INT14                ((uint32_t)0x0080<<INT_EXTI2_BIT_POS)       /*!<INT14 digital filter enable    */

#endif

#endif

/**************************  Bit definition for EWKUPIE register of HT_INT_TypeDef ***********************/
#if defined HT633x || defined HT633xH

#define  INT_EWKUPIE                           ((uint32_t)0x0006)         /*!<External wake_up pin interrupt enable register*/

#define  INT_EWKUPIE_EWKUP1                    ((uint32_t)0x0002)         /*!<External wake_up pin_1 interrupt enable*/
#define  INT_EWKUPIE_EWKUP2                    ((uint32_t)0x0004)         /*!<External wake_up pin_2 interrupt enable*/

/**************************  Bit definition for EWKUPIF register of HT_INT_TypeDef ***********************/
#define  INT_EWKUPIF                           ((uint32_t)0x0006)         /*!<External wake_up pin interrupt flag register*/

#define  INT_EWKUPIF_EWKUP1                    ((uint32_t)0x0002)         /*!<External wake_up pin_1 interrupt flag */
#define  INT_EWKUPIF_EWKUP2                    ((uint32_t)0x0004)         /*!<External wake_up pin_2 interrupt flag */

#endif




/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of DMA Module
**********************************************************************************************************
*/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK
/**************************  Bit definition for DMAIE register of HT_DMA_TypeDef ************************/
#define  DMA_DMAIE                             ((uint32_t)0x0777)           /*!<DMA INT ENABLE REGISTER   */

#define  DMA_DMAIE_TCIE0                         ((uint32_t)0x0001)           /*!<CHANNEL0 TRANSFER OVER INT ENABLE */
#define  DMA_DMAIE_TCIE1                         ((uint32_t)0x0002)           /*!<CHANNEL1 TRANSFER OVER INT ENABLE */
#define  DMA_DMAIE_TCIE2                         ((uint32_t)0x0004)           /*!<CHANNEL2 TRANSFER OVER INT ENABLE */

#define  DMA_DMAIE_BCIE0                         ((uint32_t)0x0010)           /*!<CHANNEL0 BULK TRANSFER INT ENABLE */
#define  DMA_DMAIE_BCIE1                         ((uint32_t)0x0020)           /*!<CHANNEL1 BULK TRANSFER INT ENABLE */
#define  DMA_DMAIE_BCIE2                         ((uint32_t)0x0040)           /*!<CHANNEL2 BULK TRANSFER INT ENABLE */

#define  DMA_DMAIE_TEIE0                         ((uint32_t)0x0100)           /*!<CHANNEL0 TRANSFER ERR INT ENABLE */
#define  DMA_DMAIE_TEIE1                         ((uint32_t)0x0200)           /*!<CHANNEL1 TRANSFER ERR INT ENABLE */
#define  DMA_DMAIE_TEIE2                         ((uint32_t)0x0400)           /*!<CHANNEL2 TRANSFER ERR INT ENABLE */

/**************************  Bit definition for DMAIF register of HT_DMA_TypeDef ************************/
#define  DMA_DMAIF                             ((uint32_t)0x0777)           	/*!<DMA INT FLAG REGISTER     */

#define  DMA_DMAIF_TCIF0                         ((uint32_t)0x0001)           /*!<CHANNEL0 TRANSFER OVER INT FLAG   */
#define  DMA_DMAIF_TCIF1                         ((uint32_t)0x0002)           /*!<CHANNEL1 TRANSFER OVER INT FLAG   */
#define  DMA_DMAIF_TCIF2                         ((uint32_t)0x0004)           /*!<CHANNEL2 TRANSFER OVER INT FLAG   */

#define  DMA_DMAIF_BCIF0                         ((uint32_t)0x0010)           /*!<CHANNEL0 BULK TRANSFER INT FLAG   */
#define  DMA_DMAIF_BCIF1                         ((uint32_t)0x0020)           /*!<CHANNEL1 BULK TRANSFER INT FLAG   */
#define  DMA_DMAIF_BCIF2                         ((uint32_t)0x0040)           /*!<CHANNEL2 BULK TRANSFER INT FLAG   */

#define  DMA_DMAIF_TEIF0                         ((uint32_t)0x0100)           /*!<CHANNEL0 TRANSFER ERR INT FLAG    */
#define  DMA_DMAIF_TEIF1                         ((uint32_t)0x0200)           /*!<CHANNEL1 TRANSFER ERR INT FLAG    */
#define  DMA_DMAIF_TEIF2                         ((uint32_t)0x0400)           /*!<CHANNEL2 TRANSFER ERR INT FLAG    */

/**************************  Bit definition for CHNSTA register of HT_DMA_TypeDef ***********************/
#define  DMA_CHNSTA                            	 ((uint32_t)0x0007)           /*!<DMA STATE REGISTER    */
#define  DMA_CHNSTA_BUSY0                        ((uint32_t)0x0001)           /*!<CHANNEL0 BUSY FLAG    */
#define  DMA_CHNSTA_BUSY1                        ((uint32_t)0x0002)           /*!<CHANNEL1 BUSY FLAG    */
#define  DMA_CHNSTA_BUSY2                        ((uint32_t)0x0004)           /*!<CHANNEL2 BUSY FLAG    */
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK
/*********************  Bit definition for CHNCTL register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHNCTL                            ((uint32_t)0x7fff)             /*!<DMA CHANNEL CTRL REGISTER    */

#define  DMA_CHNCTL_CHNEN                       ((uint32_t)0x0001)            /*!<DMA CHANNEL ENABLE           */

#define  DMA_CHNCTL_PSIZE                       ((uint32_t)0x0006)            /*!<DMA TRANSFER SIZE            */
#if  defined  HT6x3x
#define  DMA_CHNCTL_PSIZE_8BIT                   ((uint32_t)0x0000)           /*!<DMA TRANSFER SIZE= 8BIT      */
#define  DMA_CHNCTL_PSIZE_16BIT                  ((uint32_t)0x0002)           /*!<DMA TRANSFER SIZE = 16BIT    */
#define  DMA_CHNCTL_PSIZE_32BIT                  ((uint32_t)0x0004)           /*!<DMA TRANSFER SIZE = 32BIT    */
//#define  DMA_CHNCTL_PSIZE_32BIT                  ((uint32_t)0x0006)         /*!<DMA TRANSFER SIZE = 32BIT    */
#else
#define  DMA_CHNCTL_PSIZE_Byte                   ((uint32_t)0x0000)           /*!<DMA TRANSFER SIZE = Byte     */
#define  DMA_CHNCTL_PSIZE_HalfWord               ((uint32_t)0x0002)           /*!<DMA TRANSFER SIZE = HalfWord */
#define  DMA_CHNCTL_PSIZE_Word                   ((uint32_t)0x0004)           /*!<DMA TRANSFER SIZE = Word     */
#endif

#define  DMA_CHNCTL_MODE                        ((uint32_t)0x0008)            /*!<DMA TRANSFER MODE            */
#define  DMA_CHNCTL_MODE_WordTransfer            ((uint32_t)0x0000)           /*!<DMA Word TRANSFER            */
#define  DMA_CHNCTL_MODE_BlockTransfer           ((uint32_t)0x0008)           /*!<DMA Block TRANSFER           */

#define  DMA_CHNCTL_CYCLE                       ((uint32_t)0x0010)            /*!<DMA CYCLE TRANSFER MODE      */
#define  DMA_CHNCTL_CYCLE_DISABLE                ((uint32_t)0x0000)           /*!<NO CYCLE            				 */
#define  DMA_CHNCTL_CYCLE_ENABLE                 ((uint32_t)0x0010)           /*!<CYCLE               				 */

#define  DMA_CHNCTL_SOURCEINC                   ((uint32_t)0x0060)            /*!<SOURCE ADDR INCREASE MODE  	 */
#define  DMA_CHNCTL_SOURCEINC_NOINC              ((uint32_t)0x0000)           /*!<NO INCREASE                  */
#define  DMA_CHNCTL_SOURCEINC_INC                ((uint32_t)0x0020)           /*!<INCREASE                     */
#define  DMA_CHNCTL_SOURCEINC_BLOCKINC           ((uint32_t)0x0040)           /*!<BLOCK INCREASE INSIDE        */

#define  DMA_CHNCTL_DESTININC                   ((uint32_t)0x0180)           	/*!<DESTINATION ADDR INCREASE MODE  */
#define  DMA_CHNCTL_DESTININC_NOINC              ((uint32_t)0x0000)           /*!<NO INCREASE                  */
#define  DMA_CHNCTL_DESTININC_INC                ((uint32_t)0x0080)           /*!<INCREASE                     */
#define  DMA_CHNCTL_DESTININC_BLOCKINC           ((uint32_t)0x0100)           /*!<BLOCK INCREASE INSIDE        */

#if  defined  HT6x3x
#define  DMA_CHNCTL_CHANNEL                     ((uint32_t)0x7e00)           /*!<DMA CHANNEL SEL               */

#else
#define  DMA_CHNCTL_CHANNEL                     ((uint32_t)0x3e00)           /*!<DMA CHANNEL SEL               */
#endif

/*********************  Bit definition for CHNSRC register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHNSRC                            ((uint32_t)0xffffffff)       /*!<SOURCE ADDR REGISTER          */

/*********************  Bit definition for CHNTAR register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHNTAR                            ((uint32_t)0xffffffff)       /*!<DESTINATION ADDR REGISTER        */

/*********************  Bit definition for CHNCNT register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHNCNT                            ((uint32_t)0xffff)           /*!<TRANSFER NUM SET          */

/********************  Bit definition for CHNTCCNT register of HT_DMA_Channel_TypeDef *******************/
#define  DMA_CHNTCCNT                          ((uint32_t)0xffff)           /*!<TRANSFER DATA DONE SIZE      */

/*******************  Bit definition for CHNBULKNUM register of HT_DMA_Channel_TypeDef ******************/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
#define  DMA_CHNBULKNUM                        ((uint32_t)0xffff)           /*!<TRANSFER SET  */
#define  DMA_CHNBULKNUM_NUM                      ((uint32_t)0x00ff)         /*!<BLOCK INSIDE DATA LENGTH SET*/
#define  DMA_CHNBULKNUM_CYCLE                    ((uint32_t)0xff00)         /*!<CYCLE NUM SET   */
#else
#define  DMA_CHNBULKNUM                        ((uint32_t)0x00ff)           /*!<TRANSFER SET  */
#define  DMA_CHNBULKNUM_NUM                      ((uint32_t)0x00ff)         /*!<BLOCK INSIDE DATA LENGTH SET */
#endif
#endif

  

/*******************  Bit definition for DMAIE register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIE

#define  DMA_DMAIE                            ((uint32_t)0x77777777)        /*<DMA INT ENABLE REGISTER*/

#define  DMA_DMAIE_TCIE0                      ((uint32_t)0x00000001)        /*<CHANNEL0 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE0                      ((uint32_t)0x00000002)        /*<CHANNEL0 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE0                      ((uint32_t)0x00000004)        /*<CHANNEL0 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE1                      ((uint32_t)0x00000010)        /*<CHANNEL1 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE1                      ((uint32_t)0x00000020)        /*<CHANNEL1 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE1                      ((uint32_t)0x00000040)        /*<CHANNEL1 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE2                      ((uint32_t)0x00000100)        /*<CHANNEL2 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE2                      ((uint32_t)0x00000200)        /*<CHANNEL2 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE2                      ((uint32_t)0x00000400)        /*<CHANNEL2 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE3                      ((uint32_t)0x00001000)        /*<CHANNEL3 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE3                      ((uint32_t)0x00002000)        /*<CHANNEL3 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE3                      ((uint32_t)0x00004000)        /*<CHANNEL3 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE4                      ((uint32_t)0x00010000)        /*<CHANNEL4 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE4                      ((uint32_t)0x00020000)        /*<CHANNEL4 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE4                      ((uint32_t)0x00040000)        /*<CHANNEL4 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE5                      ((uint32_t)0x00100000)        /*<CHANNEL5 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE5                      ((uint32_t)0x00200000)        /*<CHANNEL5 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE5                      ((uint32_t)0x00400000)        /*<CHANNEL5 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE6                      ((uint32_t)0x01000000)        /*<CHANNEL6 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE6                      ((uint32_t)0x02000000)        /*<CHANNEL6 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE6                      ((uint32_t)0x04000000)        /*<CHANNEL6 TRANSFER ERR INT ENABLE	*/

#define  DMA_DMAIE_TCIE7                      ((uint32_t)0x10000000)        /*<CHANNEL7 TRANSFER OVER INT ENABLE*/
#define  DMA_DMAIE_BCIE7                      ((uint32_t)0x20000000)        /*<CHANNEL7 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE_TEIE7                      ((uint32_t)0x40000000)        /*<CHANNEL7 TRANSFER ERR INT ENABLE*/	

#endif
/*******************  Bit definition for DMAIF register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIF

#define  DMA_DMAIF                            ((uint32_t)0x77777777)        /*<DMA INT FLAG REGISTER*/

#define  DMA_DMAIF_TCIF0                      ((uint32_t)0x00000001)        /*<CHANNEL0 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF0                      ((uint32_t)0x00000002)        /*<CHANNEL0 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF0                      ((uint32_t)0x00000004)        /*<CHANNEL0 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF1                      ((uint32_t)0x00000010)        /*<CHANNEL1 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF1                      ((uint32_t)0x00000020)        /*<CHANNEL1 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF1                      ((uint32_t)0x00000040)        /*<CHANNEL1 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF2                      ((uint32_t)0x00000100)        /*<CHANNEL2 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF2                      ((uint32_t)0x00000200)        /*<CHANNEL2 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF2                      ((uint32_t)0x00000400)        /*<CHANNEL2 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF3                      ((uint32_t)0x00001000)        /*<CHANNEL3 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF3                      ((uint32_t)0x00002000)        /*<CHANNEL3 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF3                      ((uint32_t)0x00004000)        /*<CHANNEL3 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF4                      ((uint32_t)0x00010000)        /*<CHANNEL4 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF4                      ((uint32_t)0x00020000)        /*<CHANNEL4 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF4                      ((uint32_t)0x00040000)        /*<CHANNEL4 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF5                      ((uint32_t)0x00100000)        /*<CHANNEL5 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF5                      ((uint32_t)0x00200000)        /*<CHANNEL5 BULK TRANSFER INT FLAG*/ 
#define  DMA_DMAIF_TEIF5                      ((uint32_t)0x00400000)        /*<CHANNEL5 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF6                      ((uint32_t)0x01000000)        /*<CHANNEL6 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF6                      ((uint32_t)0x02000000)        /*<CHANNEL6 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF6                      ((uint32_t)0x04000000)        /*<CHANNEL6 TRANSFER ERR INT FLAG	*/

#define  DMA_DMAIF_TCIF7                      ((uint32_t)0x10000000)        /*<CHANNEL7 TRANSFER OVER INT FLAG*/
#define  DMA_DMAIF_BCIF7                      ((uint32_t)0x20000000)        /*<CHANNEL7 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF_TEIF7                      ((uint32_t)0x40000000)        /*<CHANNEL7 TRANSFER ERR INT FLAG	*/

#endif
/*******************  Bit definition for CHNCTL register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_CHNCTL

#define  DMA_CHNCTL                              ((uint32_t)0xc3ffff)           /*!<DMA CHANNEL CTRL REGISTER     */

#define  DMA_CHNCTL_CHNEN                        ((uint32_t)0x000001)           /*!<DMA CHANNEL ENABLE           	*/

#define  DMA_CHNCTL_SIZE                         ((uint32_t)0x000006)           /*!<DMA TRANSFER SIZE             */
#define  DMA_CHNCTL_SIZE_8BIT                    ((uint32_t)0x000000)           /*!<DMA TRANSFER SIZE= 8BIT       */
#define  DMA_CHNCTL_SIZE_16BIT                   ((uint32_t)0x000002)           /*!<DMA TRANSFER SIZE= 16BIT      */
#define  DMA_CHNCTL_SIZE_32BIT                   ((uint32_t)0x000004)           /*!<DMA TRANSFER SIZE= 32BIT      */
/*#define  DMA_CHNCTL_SIZE_32BIT                   ((uint32_t)0x000006)         !<DMA TRANSFER SIZE= 32BIT      */

#define  DMA_CHNCTL_MODE                         ((uint32_t)0x000008)           /*!<DMA TRANSFER MODE             */
#define  DMA_CHNCTL_MODE_WordTransfer            ((uint32_t)0x000000)           /*!<DMA Word TRANSFER             */
#define  DMA_CHNCTL_MODE_BlockTransfer           ((uint32_t)0x000008)           /*!<DMA BLOCK TRANSFER            */

#define  DMA_CHNCTL_CYCLE                        ((uint32_t)0x000010)           /*!<DMA CYCLE TRANSFER MODE       */
#define  DMA_CHNCTL_CYCLE_DISABLE                ((uint32_t)0x000000)           /*!<NO CYCLE           						*/
#define  DMA_CHNCTL_CYCLE_ENABLE                 ((uint32_t)0x000010)           /*!<CYCLE              						*/

#define  DMA_CHNCTL_SOURCE_INC                    ((uint32_t)0x000060)           /*!<SOURCE ADDR INCREASE/DECREASE MODE     */
#define  DMA_CHNCTL_SOURCE_INC_NOINC              ((uint32_t)0x000000)           /*!<NO INCREASE/DECREASE                   */
#define  DMA_CHNCTL_SOURCE_INC_INC                ((uint32_t)0x000020)           /*!<INCREASE/DECREASE              				*/
#define  DMA_CHNCTL_SOURCE_INC_BLOCKINC           ((uint32_t)0x000040)           /*!<BLOCK INSIDE INCREASE/DECREASE   			*/
#define  DMA_CHNCTL_SOURCE_INC_ENTBLOCKINC        ((uint32_t)0x000060)           /*!<BLOCK INCREASE/DECREASE*/

#define  DMA_CHNCTL_DESTIN_INC                    ((uint32_t)0x0180)            /*!<DESTINATION ADDR INCREASE/DECREASE MODE */
#define  DMA_CHNCTL_DESTIN_INC_NOINC              ((uint32_t)0x0000)            /*!<NO INCREASE/DECREASE                    */
#define  DMA_CHNCTL_DESTIN_INC_INC                ((uint32_t)0x0080)            /*!<INCREASE/DECREASE              					*/
#define  DMA_CHNCTL_DESTIN_INC_BLOCKINC           ((uint32_t)0x0100)            /*!<BLOCK INSIDE INCREASE/DECREASE  				*/
#define  DMA_CHNCTL_DESTIN_INC_ENTBLOCKINC        ((uint32_t)0x0100)            /*!<BLOCK INCREASE/DECREASE									*/

    #if  defined  HT762x  ||  defined  HT772x
#define  DMA_CHNCTL_CHANNEL                     ((uint32_t)0x00FE00)            /*!<DMA CHANNEL SEL              */
    #else
#define  DMA_CHNCTL_CHANNEL                     ((uint32_t)0x007E00)            /*!<DMA CHANNEL SEL              */
    #endif

#define  DMA_CHNCTL_PRI                          ((uint32_t)0x030000)           /*!<DMA CHANNEL PRIORITY SET     */
#define  DMA_CHNCTL_PRI_LOW                      ((uint32_t)0x000000)           /*!<DMA CHANNEL LOW PRIORITY     */
#define  DMA_CHNCTL_PRI_MEDIIUM                  ((uint32_t)0x010000)           /*!<DMA CHANNEL MEDIUM PRIORITY  */
#define  DMA_CHNCTL_PRI_HIGH                     ((uint32_t)0x020000)           /*!<DMA CHANNEL HIGH PRIORITY    */
#define  DMA_CHNCTL_PRI_HIGHEST                  ((uint32_t)0x030000)           /*!DMA CHANNEL TOP HIGH PRIORITY */

#define  DMA_CHNCTL_SOURC_DIR                    ((uint32_t)0x400000)           /*!<SOURCE ADDR INCREASE/DECREASE DIRECTION*/
#define  DMA_CHNCTL_SOURC_DIR_INC                ((uint32_t)0x000000)           /*!<SOURCE ADDR INCREASE MODE      */
#define  DMA_CHNCTL_SOURC_DIR_DEC                ((uint32_t)0x400000)           /*!<SOURCE ADDR DECREASE MODE      */

#define  DMA_CHNCTL_DESTIN_DIR                   ((uint32_t)0x800000)           /*!<DESTINATION ADDR INCREASE/DECREASE DIRECTION*/
#define  DMA_CHNCTL_DESTIN_DIR_INC               ((uint32_t)0x000000)           /*!<DESTINATION ADDR INCREASE MODE */
#define  DMA_CHNCTL_DESTIN_DIR_DEC               ((uint32_t)0x800000)           /*!<DESTINATION ADDR DECREASE MODE */

#endif
/*******************  Bit definition for CHNSRC register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_CHNSRC

#define  DMA_CHNSRC                             ((uint32_t)0xffffffff)        /*!<SOURCE ADDR REGISTER     */

#endif
/*********************  Bit definition for CHNTAR register of HT_DMA_Channel_TypeDef ********************/
#if defined USE_DMA_CHNTAR

#define  DMA_CHNTAR                            ((uint32_t)0xffffffff)       	/*!<DESTINATION ADDR REGISTER*/

#endif
/*********************  Bit definition for CHNCNT register of HT_DMA_Channel_TypeDef ********************/
#if defined USE_DMA_CHNCNT

#define  DMA_CHNCNT                            ((uint32_t)0xffff)           	/*!<TRANSFER SIZE SET        */

#endif
/********************  Bit definition for CHNTCCNT register of HT_DMA_Channel_TypeDef *******************/
#if defined USE_DMA_CHNTCCNT

#define  DMA_CHNTCCNT                          ((uint32_t)0xffff)           	/*!<TRANSFER DONE SIZE       */

#endif
/*******************  Bit definition for CHNBULKNUM register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_CHNBULKNUM

#define  DMA_CHNBULKNUM                        ((uint32_t)0xffff)           	/*!<BLOCK INSIDE LENGTH SET  */
#define  DMA_CHNBULKNUM_NUM                      ((uint32_t)0x00ff)           /*!<CYCLE NUM SET */
#define  DMA_CHNBULKNUM_CYCLE                    ((uint32_t)0xff00)           /*!<BLOCK INSIDE LENGTH SET  */
#endif



/*******************  Bit definition for DMAIE1 register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIE1

#define  DMA_DMAIE1                           ((uint32_t)0x7777)        /*<DMA INT ENABLE REGISTER1*/

#define  DMA_DMAIE1_TCIE8                      ((uint32_t)0x0001)        /*<CHANNEL8 TRANSFER ERR INT ENABLE	*/
#define  DMA_DMAIE1_BCIE8                      ((uint32_t)0x0002)        /*<CHANNEL8 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE1_TEIE8                      ((uint32_t)0x0004)        /*<CHANNEL8 TRANSFER OVER INT ENABLE*/

#define  DMA_DMAIE1_TCIE9                      ((uint32_t)0x0010)        /*<CHANNEL9 TRANSFER ERR INT ENABLE	*/
#define  DMA_DMAIE1_BCIE9                      ((uint32_t)0x0020)        /*<CHANNEL9 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE1_TEIE9                      ((uint32_t)0x0040)        /*<CHANNEL9 TRANSFER OVER INT ENABLE*/

#define  DMA_DMAIE1_TCIE10                     ((uint32_t)0x0100)        /*<CHANNEL10 TRANSFER ERR INT ENABLE	*/
#define  DMA_DMAIE1_BCIE10                     ((uint32_t)0x0200)        /*<CHANNEL10 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE1_TEIE10                     ((uint32_t)0x0400)        /*<CHANNEL10 TRANSFER OVER INT ENABLE*/

#define  DMA_DMAIE1_TCIE11                     ((uint32_t)0x1000)        /*<CHANNEL11 TRANSFER ERR INT ENABLE	*/
#define  DMA_DMAIE1_BCIE11                     ((uint32_t)0x2000)        /*<CHANNEL11 BULK TRANSFER INT ENABLE*/
#define  DMA_DMAIE1_TEIE11                     ((uint32_t)0x4000)        /*<CHANNEL11 TRANSFER OVER INT ENABLE*/

#endif
/*******************  Bit definition for DMAIF1 register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIF1

#define  DMA_DMAIF1                           ((uint32_t)0x7777)         /*<DMA INT FLAG REGISTER*/

#define  DMA_DMAIF1_TCIF8                      ((uint32_t)0x0001)        /*<CHANNEL8 TRANSFER ERR INT FLAG */
#define  DMA_DMAIF1_BCIF8                      ((uint32_t)0x0002)        /*<CHANNEL8 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF1_TEIF8                      ((uint32_t)0x0004)        /*<CHANNEL8 TRANSFER OVER INT FLAG*/

#define  DMA_DMAIF1_TCIF9                      ((uint32_t)0x0010)        /*<CHANNEL9 TRANSFER ERR INT FLAG */
#define  DMA_DMAIF1_BCIF9                      ((uint32_t)0x0020)        /*<CHANNEL9 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF1_TEIF9                      ((uint32_t)0x0040)        /*<CHANNEL9 TRANSFER OVER INT FLAG*/

#define  DMA_DMAIF1_TCIF10                     ((uint32_t)0x0100)        /*<CHANNEL10 TRANSFER ERR INT FLAG	*/
#define  DMA_DMAIF1_BCIF10                     ((uint32_t)0x0200)        /*<CHANNEL10 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF1_TEIF10                     ((uint32_t)0x0400)        /*<CHANNEL10 TRANSFER OVER INT FLAG*/

#define  DMA_DMAIF1_TCIF11                     ((uint32_t)0x1000)        /*<CHANNEL11 TRANSFER ERR INT FLAG	*/
#define  DMA_DMAIF1_BCIF11                     ((uint32_t)0x2000)        /*<CHANNEL11 BULK TRANSFER INT FLAG*/
#define  DMA_DMAIF1_TEIF11                     ((uint32_t)0x4000)        /*<CHANNEL11 TRANSFER OVER INT FLAG*/

#endif
/*******************  Bit definition for DMAIE2 register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIE2

#define  DMA_DMAIE2                           ((uint32_t)0x0111)          /*<DMA INT ENABLE REGISTER*/

#define  DMA_DMAIE2_PEIE12                      ((uint32_t)0x0001)        /*<CHANNEL12 PACK INT ENABLE*/
#define  DMA_DMAIE2_BCIE12                      ((uint32_t)0x0010)        /*<CHANNEL12 BULK TRANSFER INT ENABLE */
#define  DMA_DMAIE2_TEIE12                      ((uint32_t)0x0100)        /*<CHANNEL12 TRANSFER ERR INT ENABLE  */

#endif
/*******************  Bit definition for DMAIF2 register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_DMAIF2

#define  DMA_DMAIF2                           ((uint32_t)0x0111)          /*<DMA INT FLAG REGISTER*/

#define  DMA_DMAIF2_PEIF12                      ((uint32_t)0x0001)        /*<CHANNEL12 PACK INT FLAG*/
#define  DMA_DMAIF2_BCIF12                      ((uint32_t)0x0010)        /*<CHANNEL12 BULK TRANSFER INT FLAG    */
#define  DMA_DMAIF2_TEIF12                      ((uint32_t)0x0100)        /*<CHANNEL12 TRANSFER ERR INT FLAG     */

#endif
/*******************  Bit definition for CHN12CTL register of HT_DMA_Channel_TypeDef ******************/
#if defined USE_DMA_CHN12

#define  DMA_CHN12CTL                         ((uint32_t)0x03fe03)        /*<CHANNEL12 CTRL REGISTER*/

#define  DMA_CHN12CTL_CHN12EN                   ((uint32_t)0x000001)      /*<CHANNEL12 ENABLE        */
#define  DMA_CHN12CTL_FFTTRIG_EN                ((uint32_t)0x000002)      /*<TRIG FFT ENABLE         */
#define  DMA_CHN12CTL_CHANNEL                   ((uint32_t)0x00fe00)      /*<CHANNEL  SELECT         */

#define  DMA_CHN12CTL_PRI                        ((uint32_t)0x030000)      /*!<DMA CHANNEL PRIORITY SET      */
#define  DMA_CHN12CTL_PRI_LOW                    ((uint32_t)0x000000)      /*!<DMA CHANNEL LOW PRIORITY      */
#define  DMA_CHN12CTL_PRI_MEDIIUM                ((uint32_t)0x010000)      /*!<DMA CHANNEL MEDIUM PRIORITY   */
#define  DMA_CHN12CTL_PRI_HIGH                   ((uint32_t)0x020000)      /*!<DMA CHANNEL HIGH PRIORITY     */
#define  DMA_CHN12CTL_PRI_HIGHEST                ((uint32_t)0x030000)      /*!<DMA CHANNEL TOP HIGH PRIORITY */

/*******************  Bit definition for CHN12SRC register of HT_DMA_Channel_TypeDef ******************/
#define  DMA_CHN12SRC                         ((uint32_t)0xffffffff)        /*<DMA CHANNEL12 Source Addr REGISTER         */
/*********************  Bit definition for CHN12TAR0 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR0                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 0  */
/*********************  Bit definition for CHN12TAR1 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR1                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 1  */
/*********************  Bit definition for CHN12TAR2 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR2                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 2  */
/*********************  Bit definition for CHN12TAR3 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR3                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 3  */
/*********************  Bit definition for CHN12TAR4 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR4                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 4  */
/*********************  Bit definition for CHN12TAR5 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR5                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 5  */
/*********************  Bit definition for CHN12TAR6 register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12TAR6                        ((uint32_t)0xffffffff)        /*!<DMA CHANNEL12 Destination Addr REGISTER 6  */

/*********************  Bit definition for CHN12SIZE register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12SIZE                         ((uint32_t)0x77ffffff)       /*!<CHANNEL12 LENGTH CTRL REGISTER          */
#define  DMA_CHN12SIZE_BUFSIZE                 ((uint32_t)0x0000ffff)       /*!<Data Memory LENGTH For EMU DATA by word*/
#define  DMA_CHN12SIZE_INTSIZE                 ((uint32_t)0x07ff0000)       /*!<Trig Int Data Size by word						 */
#define  DMA_CHN12SIZE_CHN_NUM                 ((uint32_t)0x70000000)       /*!<EMU TRANS DATA SIZE                    */

/*********************  Bit definition for CHN12CLR register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12CLR                         	((uint32_t)0x0001)       /*!<CLR DMA CHANNEL12 ENABLE REGISTER           */

/*********************  Bit definition for CHN12CLR register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12EMUOFFSET                   	((uint32_t)0xffff)       /*!<DMA CHANNEL12 TRANSFER DATA OFFSET REGISTER */

/*********************  Bit definition for CHN12IDX register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12IDX                         	((uint32_t)0x0007)       /*!<DMA CHANNEL12 TRANSFER DATA CHANNEL ID REGISTER*/

/*********************  Bit definition for CHN12INTCNT register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12INTCNT                      	((uint32_t)0x07ff)       /*!<DMA CHANNEL12 TRANSFER DATA SIZE            */

/*********************  Bit definition for CHN12PACKCNT register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12PACKCNT                       ((uint32_t)0x0003)       /*!<DMA CHANNEL12 PACK INT                      */

/*********************  Bit definition for CHN12STRARTOFFSET register of HT_DMA_Channel_TypeDef ********************/
#define  DMA_CHN12STARTOFFSET                   ((uint32_t)0xffff)     /*!<DMA CHANNEL12 DESTNATION ADDR START OFFSET  */

#endif



/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of CRC Module
**********************************************************************************************************
*/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT633x
/*************************  Bit definition for CRCCON register of HT_CRC_TypeDef ************************/
#define  CRC_CRCCON                             (uint32_t)0x0077)           /*!<CRC Control Register        */
#define  CRC_CRCCON_MODE                        ((uint32_t)0x0003)           /*!<CRC Mode          */
#define  CRC_CRCCON_MODE_CCITT                  ((uint32_t)0x0000)           /*!<CRC-CCITT             */
#define  CRC_CRCCON_MODE_CRC16                  ((uint32_t)0x0001)           /*!<CRC-16                */
#define  CRC_CRCCON_MODE_CRC32                  ((uint32_t)0x0002)           /*!<CRC-32                */

#define  CRC_CRCCON_RESET                       ((uint32_t)0x0004)           /*!<CRC Operation Reset          */

#define  CRC_CRCCON_RefIn                       ((uint32_t)0x0010)           /*!<Input Data bit Reverse Control     */
#define  CRC_CRCCON_RefOut                      ((uint32_t)0x0020)           /*!<Output Data bit Reverse Control    */
#define  CRC_CRCCON_XorOut                      ((uint32_t)0x0040)           /*!<Output Data XOR Control            */
#endif

#if defined  HT762x  ||  defined  HT772x ||  defined  HT503x
#define  CRC_CRCCON                             (uint32_t)0x0177)            /*!<CRC Control Register       */
#define  CRC_CRCCON_MODE                        ((uint32_t)0x0003)           /*!<CRC Mode Configuration     */
#define  CRC_CRCCON_MODE_CCITT                  ((uint32_t)0x0000)           /*!<CRC-CCITT             */
#define  CRC_CRCCON_MODE_CRC16                  ((uint32_t)0x0001)           /*!<CRC-16                */
#define  CRC_CRCCON_MODE_CRC32                  ((uint32_t)0x0002)           /*!<CRC-32                */

#define  CRC_CRCCON_RESET                       ((uint32_t)0x0004)           /*!<CRC Operation Reset    */

#define  CRC_CRCCON_RefIn                       ((uint32_t)0x0010)           /*!<Input Data bit Reverse Control     */
#define  CRC_CRCCON_RefOut                      ((uint32_t)0x0020)           /*!<Output Data bit Reverse Control    */
#define  CRC_CRCCON_XorOut                      ((uint32_t)0x0040)           /*!<<Output Data XOR Control           */

#define  CRC_CRCCON_ENDIAN                      ((uint32_t)0x0100)           /*!<CRC Big/Small Endian Selector   */
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK  ||  defined  HT762x  ||  defined  HT772x ||  defined  HT503x
/*************************  Bit definition for CRCDAT register of HT_CRC_TypeDef ************************/
#define  CRC_CRCDAT                            ((uint32_t)0xffffffff)       /*!<CRC Data Register        */
#endif

#if  defined  HT6x3x  ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x
/*************************  Bit definition for CRCDAT register of HT_CRC_TypeDef ************************/
#define  CRC_CRCINIT                           ((uint32_t)0xffffffff)       /*!<CRC SEED Initialization Register    */
#endif


/*
**********************************************************************************************************
*                          Peripheral Registers_Bits_Definition of AES Module
**********************************************************************************************************
*/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK ||  defined  HT762x  ||  defined  HT772x ||  defined  HT503x || defined HT633x
/*************************  Bit definition for AESCON register of HT_AES_TypeDef ************************/
#define  AES_AESCON                              ((uint32_t)0x0007)           /*!<AES Control Register        */
#define  AES_AESCON_MODE                         ((uint32_t)0x0001)           /*!<AES Mode Configuration      */
#define  AES_AESCON_MODE_ENCRYPT                 ((uint32_t)0x0000)           /*!<AES Mode: Encryption        */
#define  AES_AESCON_MODE_DECRYPT                 ((uint32_t)0x0001)           /*!<AES Mode：Decryption        */

#define  AES_AESCON_KEYMODE                      ((uint32_t)0x0006)           /*!<Key Length Configuraton */
#define  AES_AESCON_KEYMODE_AES128               ((uint32_t)0x0000)           /*!<Key Length：128bits     */
#define  AES_AESCON_KEYMODE_AES192               ((uint32_t)0x0002)           /*!<Key Length：192bits     */
#define  AES_AESCON_KEYMODE_AES256               ((uint32_t)0x0004)           /*!<Key Length：256bits     */

/*************************  Bit definition for AESSTR register of HT_AES_TypeDef ************************/
#define  AES_AESSTR                              ((uint32_t)0xffff)           /*!<AES Start Register         */
#define  AES_AESSTR_NormalStart                  ((uint32_t)0x8329)           /*!<General Start              */
#define  AES_AESSTR_KeyStart                     ((uint32_t)0x8581)           /*!<No-changing KEY Start      */

/*************************  Bit definition for AESFLG register of HT_AES_TypeDef ************************/
#define  AES_AESFLG_BUSY                        ((uint32_t)0x0001)           /*!<AES Busy Flag        */

/*************************  Bit definition for AESINLL register of HT_AES_TypeDef ***********************/
#define  AES_AESINLL                           ((uint32_t)0xffffffff)       /*!<AES input data: bit0-31  */

/*************************  Bit definition for AESINML register of HT_AES_TypeDef ***********************/
#define  AES_AESINML                           ((uint32_t)0xffffffff)       /*!<AES input data: bit32-63 */

/*************************  Bit definition for AESINHM register of HT_AES_TypeDef ***********************/
#define  AES_AESINHM                           ((uint32_t)0xffffffff)       /*!<AES input data: bit64-95 */

/*************************  Bit definition for AESINHH register of HT_AES_TypeDef ***********************/
#define  AES_AESINHH                           ((uint32_t)0xffffffff)       /*!<AES input data: bit96-127*/

/************************  Bit definition for AESOUTLL register of HT_AES_TypeDef ***********************/
#define  AES_AESOUTLL                          ((uint32_t)0xffffffff)       /*!<AES input data: bit0-31  */

/************************  Bit definition for AESOUTML register of HT_AES_TypeDef ***********************/
#define  AES_AESOUTML                          ((uint32_t)0xffffffff)       /*!<AES output data: bit32-63 */

/************************  Bit definition for AESOUTHM register of HT_AES_TypeDef ***********************/
#define  AES_AESOUTHM                          ((uint32_t)0xffffffff)       /*!<AES output data: bit64-95 */

/************************  Bit definition for AESOUTHH register of HT_AES_TypeDef ***********************/
#define  AES_AESOUTHH                          ((uint32_t)0xffffffff)       /*!<AES output data: bit96-127*/

/*************************  Bit definition for AESKEY0 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY0                           ((uint32_t)0xffffffff)       /*!<KEY Part0             */

/*************************  Bit definition for AESKEY1 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY1                           ((uint32_t)0xffffffff)       /*!<KEY Part1             */

/*************************  Bit definition for AESKEY2 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY2                           ((uint32_t)0xffffffff)       /*!<KEY Part2             */

/*************************  Bit definition for AESKEY3 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY3                           ((uint32_t)0xffffffff)       /*!<KEY Part3             */

/*************************  Bit definition for AESKEY4 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY4                           ((uint32_t)0xffffffff)       /*!<KEY Part4             */

/*************************  Bit definition for AESKEY5 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY5                           ((uint32_t)0xffffffff)       /*!<KEY Part5             */

/*************************  Bit definition for AESKEY6 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY6                           ((uint32_t)0xffffffff)       /*!<KEY Part6             */

/*************************  Bit definition for AESKEY7 register of HT_AES_TypeDef ***********************/
#define  AES_AESKEY7                           ((uint32_t)0xffffffff)       /*!<KEY Part7             */
#endif


/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of RAND Module
**********************************************************************************************************
*/
#if  defined  USE_RAND
/************************  Bit definition for RANDSTR register of HT_RAND_TypeDef ***********************/
#define  RAND_RANDSTR                           ((uint32_t)0x8707)           /*!<RAND Start control Register  */
#define  RAND_RANDSTR_START                     ((uint32_t)0x0004)           /*!<RAND Start Bit      */
#define  RAND_RANDSTR_RANDEN                    ((uint32_t)0x8000)           /*!<RAND Module Enable  */
#endif
#if  defined  USE_RAND_BACKMODE 
#define  RAND_RANDSTR_BACKMODE                  ((uint32_t)0x0300)           /*!<RAND Back Processing Mode Control */
#define  RAND_RANDSTR_BACKMODE_LFSR             ((uint32_t)0x0000)           /*!<LFSR Mode              */
#define  RAND_RANDSTR_BACKMODE_PSEUDO           ((uint32_t)0x0100)           /*!<Fake Rand Mix Mode     */
#define  RAND_RANDSTR_BACKMODE_ADD              ((uint32_t)0x0200)           /*!<LFSR + Fake Rand Mix   */
#define  RAND_RANDSTR_BACKEN                    ((uint32_t)0x0400)           /*!<Back Processing Enable bit */
#endif

#if  defined  USE_RAND_WORKMODE
/************************  Bit definition for RANDSTR register of HT_RAND_TypeDef ***********************/
#define  RAND_RANDSTR_MODESEL                   ((uint32_t)0x0003)           /*!<RAND Work Mode control */
#define  RAND_RANDSTR_MODESEL_SAMPLE            ((uint32_t)0x0000)           /*!<Low frequncy sample high frequency   */
#define  RAND_RANDSTR_MODESEL_DFF               ((uint32_t)0x0001)           /*!<D flip-flop uncertain state          */
#define  RAND_RANDSTR_MODESEL_XOR               ((uint32_t)0x0002)           /*!<XOR Mix Output                       */

#endif

#if  defined  USE_RAND
/************************  Bit definition for RANDDAT register of HT_RAND_TypeDef ***********************/
#define  RAND_RANDDAT                           ((uint32_t)0xffffffff)       /*!<RAND Data Register     */
#endif

/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of GHASH Module
**********************************************************************************************************
*/
#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT501x  ||  defined  HT502x  ||  defined  HT6x2xK ||  defined  HT762x  ||  defined  HT772x  ||  defined  HT503x || HT633x
/**********************  Bit definition for GHASHSTR register of HT_GHASH_TypeDef ***********************/
#define  GHASH_GHASHSTR                        ((uint32_t)0x0501)           /*!<GHASH Operation Start Register  */

/**********************  Bit definition for GHASHFLG register of HT_GHASH_TypeDef ***********************/
#define  GHASH_GHASHFLG_BUSY                   ((uint32_t)0x0001)           /*!<GHASH Operation Busy Flag     */

/**********************  Bit definition for INPUT1LL register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT1LL                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data1: bit0-31         */

/**********************  Bit definition for INPUT1ML register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT1ML                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data1: bit32-63        */

/**********************  Bit definition for INPUT1HM register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT1HM                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data1: bit64-95        */

/**********************  Bit definition for INPUT1HH register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT1HH                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data1: bit96-127       */

/**********************  Bit definition for INPUT2LL register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT2LL                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data2: bit0-31         */

/**********************  Bit definition for INPUT2ML register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT2ML                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data2: bit32-63        */

/**********************  Bit definition for INPUT2HM register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT2HM                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data2: bit64-95        */

/**********************  Bit definition for INPUT2HH register of HT_GHASH_TypeDef ***********************/
#define  GHASH_INPUT2HH                        ((uint32_t)0xffffffff)       /*!<GHASH Input Data2: bit96-127       */

/**********************  Bit definition for OUTPUTLL register of HT_GHASH_TypeDef ***********************/
#define  GHASH_OUTPUTLL                        ((uint32_t)0xffffffff)       /*!<GHASH Output Data: bit0-31      */

/**********************  Bit definition for OUTPUTML register of HT_GHASH_TypeDef ***********************/
#define  GHASH_OUTPUTML                        ((uint32_t)0xffffffff)       /*!<GHASH Output Data: bit32-63     */

/**********************  Bit definition for OUTPUTHM register of HT_GHASH_TypeDef ***********************/
#define  GHASH_OUTPUTHM                        ((uint32_t)0xffffffff)       /*!<GHASH Output Data:bit64-95     */

/**********************  Bit definition for OUTPUTHH register of HT_GHASH_TypeDef ***********************/
#define  GHASH_OUTPUTHH                        ((uint32_t)0xffffffff)       /*!<GHASH Output Data: bit96-127    */

/*********************  Bit definition for AESGHASHIE register of HT_GHASH_TypeDef **********************/
#define  GHASH_AESGHASHIE_AESIE                ((uint32_t)0x0001)           /*!<AES Operation Interrupt Enable      */
#define  GHASH_AESGHASHIE_GHASHIE              ((uint32_t)0x0002)           /*!<GHASH Operation Interrupt Enable    */
#define  GHASH_AESGHASHIE_RANDIE               ((uint32_t)0x0004)           /*!<RAND Operation Interrupt Enable     */

/*********************  Bit definition for AESGHASHIF register of HT_GHASH_TypeDef **********************/
#define  GHASH_AESGHASHIF_AESIF                ((uint32_t)0x0001)           /*!<AES Operation Interrupt Flag       */
#define  GHASH_AESGHASHIF_GHASHIF              ((uint32_t)0x0002)           /*!<GHASH Operation Interrupt Flag     */
#define  GHASH_AESGHASHIF_RANDIF               ((uint32_t)0x0004)           /*!<RAND Operation Interrupt Flag      */
#endif

/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of KEY Module
**********************************************************************************************************
*/
#if defined USE_KEYSCAN
/************************  Bit definition for KEYIF register of HT_KEY_TypeDef ***********************/
#define  KEY_KEYIF                             ((uint32_t)0x0001)           /*!<key flag register    */

/************************  Bit definition for KEYSTA register of HT_KEY_TypeDef ***********************/
#define  KEY_KEYSTA                            ((uint32_t)0xffff)           /*!<key status register    */
#define  KEY_KEYSTA_STA0                         ((uint32_t)0x0001<<0)        /*!<key status:STA0    */
#define  KEY_KEYSTA_STA1                         ((uint32_t)0x0001<<1)        /*!<key status:STA1    */
#define  KEY_KEYSTA_STA2                         ((uint32_t)0x0001<<2)        /*!<key status:STA2    */
#define  KEY_KEYSTA_STA3                         ((uint32_t)0x0001<<3)        /*!<key status:STA3    */
#define  KEY_KEYSTA_STA4                         ((uint32_t)0x0001<<4)        /*!<key status:STA4    */
#define  KEY_KEYSTA_STA5                         ((uint32_t)0x0001<<5)        /*!<key status:STA5    */
#define  KEY_KEYSTA_STA6                         ((uint32_t)0x0001<<6)        /*!<key status:STA6    */
#define  KEY_KEYSTA_STA7                         ((uint32_t)0x0001<<7)        /*!<key status:STA7    */
#define  KEY_KEYSTA_STA8                         ((uint32_t)0x0001<<8)        /*!<key status:STA8    */
#define  KEY_KEYSTA_STA9                         ((uint32_t)0x0001<<9)        /*!<key status:STA9    */
#define  KEY_KEYSTA_STA10                        ((uint32_t)0x0001<<10)       /*!<key status:STA10   */
#define  KEY_KEYSTA_STA11                        ((uint32_t)0x0001<<11)       /*!<key status:STA11   */
#define  KEY_KEYSTA_STA12                        ((uint32_t)0x0001<<12)       /*!<key status:STA12   */
#define  KEY_KEYSTA_STA13                        ((uint32_t)0x0001<<13)       /*!<key status:STA13   */
#define  KEY_KEYSTA_STA14                        ((uint32_t)0x0001<<14)       /*!<key status:STA14   */
#define  KEY_KEYSTA_STA15                        ((uint32_t)0x0001<<15)       /*!<key status:STA15   */
#endif


/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of ECC Module
**********************************************************************************************************
*/
#if  defined  USE_ECC
/************************  Bit definition for ECCCON register of HT_ECC_TypeDef ***********************/
#define  ECC_ECCCON                              ((uint32_t)0x007f)           /*!<ECC Control Register      */

#define  ECC_ECCCON_OP_STR                       ((uint32_t)0x0001)           /*!<Operation Start Bit             */

#define  ECC_ECCCON_OP_SEL                       ((uint32_t)0x001e)           /*!<Operation Mode Selector          */
#define  ECC_ECCCON_OP_SEL_ECSM                  ((uint32_t)0x0000)           /*!<point Multiply Opertaion        */
#define  ECC_ECCCON_OP_SEL_ECA                   ((uint32_t)0x0002)           /*!<Point Add Operation             */
#define  ECC_ECCCON_OP_SEL_ECD                   ((uint32_t)0x0004)           /*!<Point Double Operation          */
#define  ECC_ECCCON_OP_SEL_MA                    ((uint32_t)0x0006)           /*!<Modular Add Operation           */
#define  ECC_ECCCON_OP_SEL_MS                    ((uint32_t)0x0008)           /*!<Modular Sub Operation           */
#define  ECC_ECCCON_OP_SEL_MM                    ((uint32_t)0x000a)           /*!<Modular Multiply Operation      */
#define  ECC_ECCCON_OP_SEL_MD                    ((uint32_t)0x000c)           /*!<Modular Division Operation      */
#define  ECC_ECCCON_OP_SEL_MI                    ((uint32_t)0x000e)           /*!<Modular Inverse Operation       */
#define  ECC_ECCCON_OP_SEL_ECDSA_S               ((uint32_t)0x0010)           /*!<ECDSA Signature Operation       */
#define  ECC_ECCCON_OP_SEL_ECDSA_V               ((uint32_t)0x0012)           /*!<ESDA Verification Operation     */
#define  ECC_ECCCON_OP_SEL_PKV                   ((uint32_t)0x0014)           /*!<ECC Public Key Verification Operation   */

#define  ECC_ECCCON_ECCIE                        ((uint32_t)0x0020)           /*!<ECC Interrupt Enable          */

#define  ECC_ECCCON_SE                           ((uint32_t)0x0040)           /*!<Private Key Selector           */
#define  ECC_ECCCON_SE_SECRETKEY                 ((uint32_t)0x0040)           /*!<Set Secret Key as Private Key */
#define  ECC_ECCCON_SE_KEYREG                    ((uint32_t)0x0000)           /*!<Set value in KEYREG Register as Private Key */

/************************  Bit definition for ECCSTA register of HT_ECC_TypeDef ***********************/
#define  ECC_ECCSTA                              ((uint32_t)0x001f)           /*!<ECC Status Register      */

#define  ECC_ECCSTA_ECCFLG                       ((uint32_t)0x0001)           /*!<ECC Opertion Complete Flag        */
#define  ECC_ECCSTA_BUSY                         ((uint32_t)0x0002)           /*!<Operation Busy Flag               */
#define  ECC_ECCSTA_ECDSA_V                      ((uint32_t)0x0004)           /*!<ECDSA Verification Flag           */
#define  ECC_ECCSTA_ECDSA_S                      ((uint32_t)0x0008)           /*!<ECDSA Re-Signature Flag           */
#define  ECC_ECCSTA_PKV                          ((uint32_t)0x0010)           /*!<ECC Public Key Verification Flag  */

/************************  Bit definition for PXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PXREG                             ((uint32_t)0xffffffff)       /*!<Register for x Axile Value of Basic point */

/************************  Bit definition for PYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PYREG                             ((uint32_t)0xffffffff)       /*!<Register for y Axile Value of Basic point */

/************************  Bit definition for KEYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_KEYREG                            ((uint32_t)0xffffffff)       /*!<Register for Private Key			 */

/************************  Bit definition for AREG register of HT_ECC_TypeDef ***********************/
#define  ECC_AREG                              ((uint32_t)0xffffffff)       /*!<Register for Parameter a of ECC Function     */

/************************  Bit definition for PREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PREG                              ((uint32_t)0xffffffff)       /*!<Register for Big Prime P        */

/************************  Bit definition for RXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_RXREG                             ((uint32_t)0xffffffff)       /*!<Register for x Axile Value of the other ECC Point in Point Operation  */

/************************  Bit definition for RYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_RYREG                             ((uint32_t)0xffffffff)       /*!<Register for y Axile Value of the other ECC Point in Point Operation  */

/************************  Bit definition for SXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_SXREG                             ((uint32_t)0xffffffff)       /*!<Register for x Axile Value of Point Operation Result  */

/************************  Bit definition for SYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_SYREG                             ((uint32_t)0xffffffff)       /*!<Register for y Axile Value of Point Operation Result  */

/************************  Bit definition for MREG register of HT_ECC_TypeDef ***********************/
#define  ECC_MREG                              ((uint32_t)0xffffffff)       /*!<Register for Message Hash value           */

#endif


#if  defined  USE_ECC384
/************************  Bit definition for ECCCON register of HT_ECC_TypeDef ***********************/
#define  ECC_ECCCON                             ((uint32_t)0x002f)           /*!<ECC Module Control Register       */

#define  ECC_ECCCON_OP_STR                      ((uint32_t)0x0001)           /*!<Operation Start Bit               */

#define  ECC_ECCCON_OP_SEL                      ((uint32_t)0x001e)           /*!<Operation Mode Selector           */
#define  ECC_ECCCON_OP_SEL_MA                   ((uint32_t)0x0000)           /*!<Modular Add Operation             */
#define  ECC_ECCCON_OP_SEL_MS                   ((uint32_t)0x0002)           /*!<Modular Sub Operation             */
#define  ECC_ECCCON_OP_SEL_MM                   ((uint32_t)0x0004)           /*!<Modular Multiply Operation        */
#define  ECC_ECCCON_OP_SEL_MD                   ((uint32_t)0x0006)           /*!<Modular Division Operation        */
#define  ECC_ECCCON_OP_SEL_MI                   ((uint32_t)0x0008)           /*!<Modular Inverse Operation         */
#define  ECC_ECCCON_OP_SEL_ECSM                 ((uint32_t)0x000a)           /*!<point Multiply Opertaion          */
#define  ECC_ECCCON_OP_SEL_ECA                  ((uint32_t)0x000c)           /*!<Point Add Operation               */
#define  ECC_ECCCON_OP_SEL_PKV                  ((uint32_t)0x000e)           /*!<ECC Public Key Verification Operation  */
#define  ECC_ECCCON_OP_SEL_ECDSA_S              ((uint32_t)0x0010)           /*!<ECDSA Signature Operation              */
#define  ECC_ECCCON_OP_SEL_ECDSA_V              ((uint32_t)0x0012)           /*!< ESDA Verification Operation           */

#define  ECC_ECCCON_ECCIE                       ((uint32_t)0x0020)           /*!<ECC Interrupt Enable          */
/************************  Bit definition for ECCSTA register of HT_ECC_TypeDef ***********************/
#define  ECC_ECCSTA                             ((uint32_t)0x001f)           /*!<ECC Status Register           */

#define  ECC_ECCSTA_ECCIF                      ((uint32_t)0x0001)           /*!<ECC Opertion Complete Interrut Flag     */
#define  ECC_ECCSTA_BUSY                        ((uint32_t)0x0002)           /*!<ECC Operation Busy Flag       */
#define  ECC_ECCSTA_ECC_V                     ((uint32_t)0x0004)           /*!<ECC Operation Sucess Flag     */


/************************  Bit definition for PREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PREG                             ((uint32_t)0xffffffff)       /*!<Registerfor Big Prime P         */

/************************  Bit definition for NREG register of HT_ECC_TypeDef ***********************/
#define  ECC_NREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for the Order n of Basic Point G      */

/************************  Bit definition for AREG register of HT_ECC_TypeDef ***********************/
#define  ECC_AREG                             ((uint32_t)0xffffffff)       /*!Register[0~11] for Parameter a of ECC Function        */

/************************  Bit definition for BREG register of HT_ECC_TypeDef ***********************/
#define  ECC_BREG                              ((uint32_t)0xffffffff)       /*!<Register[0~11] for Parameter b of ECC Function      */

/************************  Bit definition for PXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PXREG                              ((uint32_t)0xffffffff)       /*!<Register[0~11] for x Axile Value of Basic point G  */

/************************  Bit definition for PYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_PYREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for y Axile Value of Basic point G   */

/************************  Bit definition for SXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_SXREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for x Axile Value of Public Key D    */

/************************  Bit definition for SYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_SYREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for Y Axile Value of Public Key D    */

/************************  Bit definition for KEYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_KEYREG                            ((uint32_t)0xffffffff)       /*!<Register[0~11] for Big Rand k  */

/************************  Bit definition for RXREG register of HT_ECC_TypeDef ***********************/
#define  ECC_RXREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for ECDSA Signature result r         */

/************************  Bit definition for RYREG register of HT_ECC_TypeDef ***********************/
#define  ECC_RYREG                             ((uint32_t)0xffffffff)       /*!<Register[0~11] for ECDSA Signature result s          */

#endif

/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of EMU INTERFACE Module
**********************************************************************************************************
*/
#if defined  USE_EMUIFACE_5X  
/************************  Bit definition for EICON register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_EICON                   ((uint32_t)0x7f00)          /*!<EMU INTERFACE control register  */
#define  EI_EICON_EI_NISEN          ((uint32_t)0x100)           /*!<Non intrusive data interface enable bit  */

#define EI_EICON_EI_NISEN_Pos				(8U)	
#define EI_EICON_EI_NISEN_Mask			(1U<<EI_EICON_EI_NISEN_Pos)	
#define EI_EICON_EI_NISEN_DISABLE		(0x00U<<EI_EICON_EI_NISEN_Pos)	
#define EI_EICON_EI_NISEN_ENABLE		(0x01U<<EI_EICON_EI_NISEN_Pos)	

#define EI_EICON_EI_NISHA           ((uint32_t)0x200)           /*!<Non intrusive data interface alignment enable bit  */
#define EI_EICON_EI_NISHA_Pos				(9U)	
#define EI_EICON_EI_NISHA_Mask			(1U<<EI_EICON_EI_NISHA_Pos)	
#define EI_EICON_EI_NISHA_LOW				(0x00U<<EI_EICON_EI_NISHA_Pos)	
#define EI_EICON_EI_NISHA_HIGH			(0x01U<<EI_EICON_EI_NISHA_Pos)	

#define EI_EICON_EI_NISMODE         ((uint32_t)0xC00)           /*!<Non intrusive data interface Bit width enable bit*/
#define EI_EICON_EI_NISMODE_Pos			(10U)	
#define EI_EICON_EI_NISMODE_Mask		(3U<<EI_EICON_EI_NISMODE_Pos)	
#define EI_EICON_EI_NISMODE_16BITS	(0x0000U<<EI_EICON_EI_NISMODE_Pos)
#define EI_EICON_EI_NISMODE_24BITS	(0x0001U<<EI_EICON_EI_NISMODE_Pos)
#define EI_EICON_EI_NISMODE_32BITS	(0x0002U<<EI_EICON_EI_NISMODE_Pos)

#endif

#if defined  USE_EMUIFACE_7X 
#define  EI_EICON                    ((uint32_t)0x7fff)           /*!<EMU INTERFACE control register  */

#define EI_EICON_EI_FFTEN           ((uint32_t)0x0001)           /*!<FFT data interface enable bit  */
#define EI_EICON_EI_FFTEN_Pos				(0U)	
#define EI_EICON_EI_FFTEN_Mask			(1U<<EI_EICON_EI_FFTEN_Pos)	
#define EI_EICON_EI_FFTEN_DISABLE		(0x00U<<EI_EICON_EI_FFTEN_Pos)	
#define EI_EICON_EI_FFTEN_ENABLE		(0x01U<<EI_EICON_EI_FFTEN_Pos)

#define EI_EICON_EI_FFTHA           ((uint32_t)0x0002)           /*!<FFT data interface alignment enable bit  */
#define EI_EICON_EI_FFTHA_Pos				(1U)	
#define EI_EICON_EI_FFTHA_Mask			(1U<<EI_EICON_EI_FFTHA_Pos)	
#define EI_EICON_EI_FFTHA_LOW				(0x00U<<EI_EICON_EI_FFTHA_Pos)	
#define EI_EICON_EI_FFTHA_HIGH			(0x01U<<EI_EICON_EI_FFTHA_Pos)	

#define EI_EICON_EI_FFTRST          ((uint32_t)0x0080)           /*!<FFTdata interface reset enable bit  */

#define EI_EICON_EI_NISEN           ((uint32_t)0x100)           /*!<Non intrusive data interface enable bit  */
#define EI_EICON_EI_NISEN_Pos				(8U)	
#define EI_EICON_EI_NISEN_Mask			(1U<<EI_EICON_EI_NISEN_Pos)	
#define EI_EICON_EI_NISEN_DISABLE		(0x00U<<EI_EICON_EI_NISEN_Pos)	
#define EI_EICON_EI_NISEN_ENABLE		(0x01U<<EI_EICON_EI_NISEN_Pos)	

#define EI_EICON_EI_NISHA           ((uint32_t)0x200)           /*!<Non intrusive data interface alignment enable bit  */
#define EI_EICON_EI_NISHA_Pos				(9U)	
#define EI_EICON_EI_NISHA_Mask			(1U<<EI_EICON_EI_NISHA_Pos)	
#define EI_EICON_EI_NISHA_LOW				(0x00U<<EI_EICON_EI_NISHA_Pos)	
#define EI_EICON_EI_NISHA_HIGH			(0x01U<<EI_EICON_EI_NISHA_Pos)	

#define EI_EICON_EI_NISMODE         ((uint32_t)0xC00)           /*!<Non intrusive data interface bit width enable bit*/
#define EI_EICON_EI_NISMODE_Pos			(10U)	
#define EI_EICON_EI_NISMODE_Mask		(3U<<EI_EICON_EI_NISMODE_Pos)	
#define EI_EICON_EI_NISMODE_16BITS	(0x0000U<<EI_EICON_EI_NISMODE_Pos)
#define EI_EICON_EI_NISMODE_24BITS	(0x0001U<<EI_EICON_EI_NISMODE_Pos)
#define EI_EICON_EI_NISMODE_32BITS	(0x0002U<<EI_EICON_EI_NISMODE_Pos)
#endif

#if defined  USE_EMUIFACE_5X
/************************  Bit definition for EIIE register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_EIIE                  ((uint32_t)0x0002)            /*!< EMU INTERFACE interrupt enable register */
#define  EI_EIIE_EI_NISIE         ((uint32_t)0x0002)            /*!< Non intrusive data interface interrupt enable register */
#endif

#if defined  USE_EMUIFACE_7X
#define  EI_EIIE                  ((uint32_t)0x0003)            /*!< EMU INTERFACE interrupt enable register */
#define  EI_EIIE_EI_FFTIE         ((uint32_t)0x0001)            /*!< FFT data interface interrupt enable register*/
#define  EI_EIIE_EI_NISIE         ((uint32_t)0x0002)            /*!< Non intrusive data interface interrupt enable register*/
#endif

#if defined  USE_EMUIFACE_5X
/************************  Bit definition for EIIF register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_EIIF                  ((uint32_t)0x0002)            /*!< EMU INTERFACE interrupt flag register */
#define  EI_EIIF_EI_NISIF         ((uint32_t)0x0002)            /*!< Non intrusive data interface interrupt flag register*/
#endif

#if defined  USE_EMUIFACE_7X
#define  EI_EIIF                  ((uint32_t)0x0003)            /*!< EMU INTERFACE interrupt flag register */
#define  EI_EIIF_EI_FFTIF         ((uint32_t)0x0001)            /*!< FFT data interface interrupt flag register*/
#define  EI_EIIF_EI_NISIF         ((uint32_t)0x0002)            /*!< Non intrusive data interface interrupt flag register*/
#endif

#if defined  USE_EMUIFACE_7X
/************************  Bit definition for EI_FFTCFG register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_EI_FFTCFG                 ((uint32_t)0x07777777)         /*!<FFT data interface configuration register */
#define  EI_EI_FFTCFG_FFT_CHNSEL0     ((uint32_t)0x00000007)         /*!<FFT output channel0 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL1     ((uint32_t)0x00000070)         /*!<FFT output channel1 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL2     ((uint32_t)0x00000700)         /*!<FFT output channel2 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL3     ((uint32_t)0x00007000)         /*!<FFT output channel3 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL4     ((uint32_t)0x00070000)         /*!<FFT output channel4 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL5     ((uint32_t)0x00700000)         /*!<FFT output channel5 data selection control bit */
#define  EI_EI_FFTCFG_FFT_CHNSEL6     ((uint32_t)0x07000000)         /*!<FFT output channel6 data selection control bit */
#endif

#if defined  USE_EMUIFACE_5X
/************************  Bit definition for EI_NISCFG register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_EI_NISCFG                   ((uint32_t)0x0777)        /*!< EMU INTERFACE NON-INTRUSIVE data interface configuration register */
#define  EI_EI_NISCFG_NIS_CHNSEL0       ((uint32_t)0x0007)        /*!< Non intrusive data interface output channel 0 data select control bit*/
#define  EI_EI_NISCFG_NIS_CHNSEL0_CH0   ((uint32_t)0x0000)        /*!< Non intrusive data interface output channel 0 data select CH0*/
#define  EI_EI_NISCFG_NIS_CHNSEL0_CH1   ((uint32_t)0x0001)        /*!< Non intrusive data interface output channel 0 data select CH1*/
#define  EI_EI_NISCFG_NIS_CHNSEL0_CH2   ((uint32_t)0x0002)        /*!< Non intrusive data interface output channel 0 data select CH2*/
                                                                 
#define  EI_EI_NISCFG_NIS_CHNSEL1       ((uint32_t)0x0070)        /*!< Non intrusive data interface output channel 1 data select control bit*/
#define  EI_EI_NISCFG_NIS_CHNSEL1_CH0   ((uint32_t)0x0000)        /*!< Non intrusive data interface output channel 1 data select CH0*/
#define  EI_EI_NISCFG_NIS_CHNSEL1_CH1   ((uint32_t)0x0010)        /*!< Non intrusive data interface output channel 1 data select CH1*/
#define  EI_EI_NISCFG_NIS_CHNSEL1_CH2   ((uint32_t)0x0020)        /*!< Non intrusive data interface output channel 1 data select CH2*/
                                                                 
#define  EI_EI_NISCFG_NIS_CHNSEL2       ((uint32_t)0x0700)        /*!< Non intrusive data interface output channel 2 data select control bit*/
#define  EI_EI_NISCFG_NIS_CHNSEL2_CH0   ((uint32_t)0x0000)        /*!< Non intrusive data interface output channel 2 data select CH0*/
#define  EI_EI_NISCFG_NIS_CHNSEL2_CH1   ((uint32_t)0x0100)        /*!< Non intrusive data interface output channel 2 data select CH1*/
#define  EI_EI_NISCFG_NIS_CHNSEL2_CH2   ((uint32_t)0x0200)        /*!< Non intrusive data interface output channel 2 data select CH2*/
#endif

#if defined  USE_EMUIFACE_7X
#define  EI_EI_CFG                   ((uint32_t)0x7777777)        /*!< EMU INTERFACE configuration register */

#define  EI_EI_CFG_CHNSEL0           ((uint32_t)0x0000007)        /*!< interface output channel 0 data select control bit*/
#define  EI_EI_CFG_CHNSEL0_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 0 data select CH0*/
#define  EI_EI_CFG_CHNSEL0_CH1       ((uint32_t)0x0000001)        /*!< interface output channel 0 data select CH1*/
#define  EI_EI_CFG_CHNSEL0_CH2       ((uint32_t)0x0000002)        /*!< interface output channel 0 data select CH2*/
#define  EI_EI_CFG_CHNSEL0_CH3       ((uint32_t)0x0000003)        /*!< interface output channel 0 data select CH3*/
#define  EI_EI_CFG_CHNSEL0_CH4       ((uint32_t)0x0000004)        /*!< interface output channel 0 data select CH4*/
#define  EI_EI_CFG_CHNSEL0_CH5       ((uint32_t)0x0000005)        /*!< interface output channel 0 data select CH5*/
#define  EI_EI_CFG_CHNSEL0_CH6       ((uint32_t)0x0000006)        /*!< interface output channel 0 data select CH6*/
                                                                  
#define  EI_EI_CFG_CHNSEL1           ((uint32_t)0x0000070)        /*!< interface output channel 1 data select control bit*/
#define  EI_EI_CFG_CHNSEL1_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 1 data select CH0*/
#define  EI_EI_CFG_CHNSEL1_CH1       ((uint32_t)0x0000010)        /*!< interface output channel 1 data select CH1*/
#define  EI_EI_CFG_CHNSEL1_CH2       ((uint32_t)0x0000020)        /*!< interface output channel 1 data select CH2*/
#define  EI_EI_CFG_CHNSEL1_CH3       ((uint32_t)0x0000030)        /*!< interface output channel 1 data select CH3*/
#define  EI_EI_CFG_CHNSEL1_CH4       ((uint32_t)0x0000040)        /*!< interface output channel 1 data select CH4*/
#define  EI_EI_CFG_CHNSEL1_CH5       ((uint32_t)0x0000050)        /*!< interface output channel 1 data select CH5*/
#define  EI_EI_CFG_CHNSEL1_CH6       ((uint32_t)0x0000060)        /*!< interface output channel 1 data select CH6*/

#define  EI_EI_CFG_CHNSEL2           ((uint32_t)0x0000700)        /*!< interface output channel 2 data select control bit*/
#define  EI_EI_CFG_CHNSEL2_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 2 data select CH0*/
#define  EI_EI_CFG_CHNSEL2_CH1       ((uint32_t)0x0000100)        /*!< interface output channel 2 data select CH1*/
#define  EI_EI_CFG_CHNSEL2_CH2       ((uint32_t)0x0000200)        /*!< interface output channel 2 data select CH2*/
#define  EI_EI_CFG_CHNSEL2_CH3       ((uint32_t)0x0000300)        /*!< interface output channel 2 data select CH3*/
#define  EI_EI_CFG_CHNSEL2_CH4       ((uint32_t)0x0000400)        /*!< interface output channel 2 data select CH4*/
#define  EI_EI_CFG_CHNSEL2_CH5       ((uint32_t)0x0000500)        /*!< interface output channel 2 data select CH5*/
#define  EI_EI_CFG_CHNSEL2_CH6       ((uint32_t)0x0000600)        /*!< interface output channel 2 data select CH6*/

#define  EI_EI_CFG_CHNSEL3           ((uint32_t)0x0007000)        /*!< interface output channel 3 data select control bit*/
#define  EI_EI_CFG_CHNSEL3_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 3 data select CH0*/
#define  EI_EI_CFG_CHNSEL3_CH1       ((uint32_t)0x0001000)        /*!< interface output channel 3 data select CH1*/
#define  EI_EI_CFG_CHNSEL3_CH2       ((uint32_t)0x0002000)        /*!< interface output channel 3 data select CH2*/
#define  EI_EI_CFG_CHNSEL3_CH3       ((uint32_t)0x0003000)        /*!< interface output channel 3 data select CH3*/
#define  EI_EI_CFG_CHNSEL3_CH4       ((uint32_t)0x0004000)        /*!< interface output channel 3 data select CH4*/
#define  EI_EI_CFG_CHNSEL3_CH5       ((uint32_t)0x0005000)        /*!< interface output channel 3 data select CH5*/
#define  EI_EI_CFG_CHNSEL3_CH6       ((uint32_t)0x0006000)        /*!< interface output channel 3 data select CH6*/
                                                                  
#define  EI_EI_CFG_CHNSEL4           ((uint32_t)0x0070000)        /*!< interface output channel 4 data select control bit*/
#define  EI_EI_CFG_CHNSEL4_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 4 data select CH0*/
#define  EI_EI_CFG_CHNSEL4_CH1       ((uint32_t)0x0010000)        /*!< interface output channel 4 data select CH1*/
#define  EI_EI_CFG_CHNSEL4_CH2       ((uint32_t)0x0020000)        /*!< interface output channel 4 data select CH2*/
#define  EI_EI_CFG_CHNSEL4_CH3       ((uint32_t)0x0030000)        /*!< interface output channel 4 data select CH3*/
#define  EI_EI_CFG_CHNSEL4_CH4       ((uint32_t)0x0040000)        /*!< interface output channel 4 data select CH4*/
#define  EI_EI_CFG_CHNSEL4_CH5       ((uint32_t)0x0050000)        /*!< interface output channel 4 data select CH5*/
#define  EI_EI_CFG_CHNSEL4_CH6       ((uint32_t)0x0060000)        /*!< interface output channel 4 data select CH6*/

#define  EI_EI_CFG_CHNSEL5           ((uint32_t)0x0700000)        /*!< interface output channel 5 data select control bit*/
#define  EI_EI_CFG_CHNSEL5_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 5 data select CH0*/
#define  EI_EI_CFG_CHNSEL5_CH1       ((uint32_t)0x0100000)        /*!< interface output channel 5 data select CH1*/
#define  EI_EI_CFG_CHNSEL5_CH2       ((uint32_t)0x0200000)        /*!< interface output channel 5 data select CH2*/
#define  EI_EI_CFG_CHNSEL5_CH3       ((uint32_t)0x0300000)        /*!< interface output channel 5 data select CH3*/
#define  EI_EI_CFG_CHNSEL5_CH4       ((uint32_t)0x0400000)        /*!< interface output channel 5 data select CH4*/
#define  EI_EI_CFG_CHNSEL5_CH5       ((uint32_t)0x0500000)        /*!< interface output channel 5 data select CH5*/
#define  EI_EI_CFG_CHNSEL5_CH6       ((uint32_t)0x0600000)        /*!< interface output channel 5 data select CH6*/

#define  EI_EI_CFG_CHNSEL6           ((uint32_t)0x7000000)        /*!< interface output channel 6 data select control bit*/
#define  EI_EI_CFG_CHNSEL6_CH0       ((uint32_t)0x0000000)        /*!< interface output channel 6 data select CH0*/
#define  EI_EI_CFG_CHNSEL6_CH1       ((uint32_t)0x1000000)        /*!< interface output channel 6 data select CH1*/
#define  EI_EI_CFG_CHNSEL6_CH2       ((uint32_t)0x2000000)        /*!< interface output channel 6 data select CH2*/
#define  EI_EI_CFG_CHNSEL6_CH3       ((uint32_t)0x3000000)        /*!< interface output channel 6 data select CH3*/
#define  EI_EI_CFG_CHNSEL6_CH4       ((uint32_t)0x4000000)        /*!< interface output channel 6 data select CH4*/
#define  EI_EI_CFG_CHNSEL6_CH5       ((uint32_t)0x5000000)        /*!< interface output channel 6 data select CH5*/
#define  EI_EI_CFG_CHNSEL6_CH6       ((uint32_t)0x6000000)        /*!< interface output channel 6 data select CH6*/

#endif                                                            

#if defined  USE_EMUIFACE_7X 
/************************  Bit definition for FFT_DATA register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_FFT_DATA0               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 0 */
#define  EI_FFT_DATA1               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 1 */
#define  EI_FFT_DATA2               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 2 */
#define  EI_FFT_DATA3               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 3 */
#define  EI_FFT_DATA4               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 4 */
#define  EI_FFT_DATA5               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 5 */
#define  EI_FFT_DATA6               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 6 */
#define  EI_FFT_DATA7               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 7 */
#define  EI_FFT_DATA8               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 8 */
#define  EI_FFT_DATA9               ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 9 */
#define  EI_FFT_DATA10              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 10 */
#define  EI_FFT_DATA11              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 11 */
#define  EI_FFT_DATA12              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 12 */
#define  EI_FFT_DATA13              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 13 */
#define  EI_FFT_DATA14              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 14 */
#define  EI_FFT_DATA15              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 15 */
#define  EI_FFT_DATA16              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 16 */
#define  EI_FFT_DATA17              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 17 */
#define  EI_FFT_DATA18              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 18 */
#define  EI_FFT_DATA19              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 19 */
#define  EI_FFT_DATA20              ((uint32_t)0xffffffff)       /*!<FFT data interface ouotput data register 20 */
#endif

#if defined  USE_EMUIFACE_5X || defined  USE_EMUIFACE_7X 
/************************  Bit definition for NIS_DATA register of HT_EMU_Interface_TypeDef ***********************/
#define  EI_NIS_DATA0               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 0 */
#define  EI_NIS_DATA1               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 1 */
#define  EI_NIS_DATA2               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 2 */
#if defined  USE_EMUIFACE_7X 
#define  EI_NIS_DATA3               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 3 */
#define  EI_NIS_DATA4               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 4 */
#define  EI_NIS_DATA5               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 5 */
#define  EI_NIS_DATA6               ((uint32_t)0xffffffff)      /*!<Non intrusive data interface data register 6 */
#endif
#endif


/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of FFT Module
**********************************************************************************************************
*/
#if defined  USE_FFT
/************************  Bit definition for FFTCFG register of HT_FFT_TypeDef ***********************/
#define  FFT_FFTCFG                    ((uint32_t)0x07ff)           /*!<FFT configuration register  */
#define  FFT_FFTCFG_SOFT_START         ((uint32_t)0x0001)           /*!<FFT software startup control bit  */

#define  FFT_FFTCFG_FFTMODE            ((uint32_t)0x0006)           /*!<FFT calculate points control bit  */
#define  FFT_FFTCFG_FFTMODE_64         ((uint32_t)0x0000)           /*!<FFT calculate 64 points */
#define  FFT_FFTCFG_FFTMODE_128        ((uint32_t)0x0002)           /*!<FFT calculate 128 points */
#define  FFT_FFTCFG_FFTMODE_256        ((uint32_t)0x0004)           /*!<FFT calculate 256 points */
#define  FFT_FFTCFG_FFTMODE_512        ((uint32_t)0x0006)           /*!<FFT calculate 512 points */

#define  FFT_FFTCFG_IODTYPE            ((uint32_t)0x0008)           /*!<FFT input data type configuration bit */
#define  FFT_FFTCFG_IODTYPE_C_C        ((uint32_t)0x0000)           /*!<FFT input data C_C mode */
#define  FFT_FFTCFG_IODTYPE_R_C        ((uint32_t)0x0008)           /*!<FFT input data R_C mode */

#define  FFT_FFTCFG_NOR_SQRTN          ((uint32_t)0x0010)           /*!<FFT normalization factor configuration bit */
#define  FFT_FFTCFG_NOR_SQRTN_N        ((uint32_t)0x0000)           /*!<FFT normalization factor configuration bit */
#define  FFT_FFTCFG_NOR_SQRTN_SQRT     ((uint32_t)0x0010)           /*!<FFT normalization factor configuration bit */

#define  FFT_FFTCFG_NUM_FFTS           ((uint32_t)0x00e0)           /*!<FFT calculation number configuration bit */
#define  FFT_FFTCFG_ABORT              ((uint32_t)0x0100)           /*!<FFT abort bit*/

#define  FFT_FFTCFG_INV                ((uint32_t)0x0200)           /*!<FFT calculation bit*/
#define  FFT_FFTCFG_INV_FFT            ((uint32_t)0x0000)           /*!<FFT calculation FFT*/
#define  FFT_FFTCFG_INV_IFFT           ((uint32_t)0x0200)           /*!<FFT calculation IFFT*/

#define  FFT_FFTCFG_SOFT_EN            ((uint32_t)0x0400)           /*!<FFT software startup enable bit*/

/************************  Bit definition for FFTIE register of HT_FFT_TypeDef ***********************/
#define  FFT_FFTIE                   ((uint32_t)0x0003)             /*!<FFT interrupt enable register  */
#define  FFT_FFTIE_FFT_IE            ((uint32_t)0x0001)             /*!< FFT calculation completion interrupt enable bit（sigle） */
#define  FFT_FFTIE_FFT_DONE_IE       ((uint32_t)0x0002)             /*!<FFT calculation completion interrupt enable bit（all currently configured channels） */
                                                                    
/************************  Bit definition for FFT_SRC_DMA_CTL register of HT_FFT_TypeDef ***********************/
#define  FFT_SRC_DMA_CTRL                ((uint32_t)0x3fffffff)           /*!<FFT source data configuration register  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT0       ((uint32_t)0x0000000f)           /*!<FFT source data channel 0 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT1       ((uint32_t)0x000000f0)           /*!<FFT source data channel 1 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT2       ((uint32_t)0x00000f00)           /*!<FFT source data channel 2 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT3       ((uint32_t)0x0000f000)           /*!<FFT source data channel 3 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT4       ((uint32_t)0x000f0000)           /*!<FFT source data channel 4 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT5       ((uint32_t)0x00f00000)           /*!<FFT source data channel 5 right shift control bit  */
#define  FFT_SRC_DMA_CTRL_R_SHIFT6       ((uint32_t)0x0f000000)           /*!<FFT source data channel 6 right shift control bit  */

#define  FFT_SRC_DMA_CTRL_SRC_BW         ((uint32_t)0x30000000)           /*!<FFT input data bit width selection  */
#define  FFT_SRC_DMA_CTRL_SRC_BW_16BITS  ((uint32_t)0x00000000)           /*!<FFT input data bit width select 16 bits  */
#define  FFT_SRC_DMA_CTRL_SRC_BW_24BITS  ((uint32_t)0x10000000)           /*!<FFT input data width select 24 bits  */
#define  FFT_SRC_DMA_CTRL_SRC_BW_32BITS  ((uint32_t)0x20000000)           /*!<FFT input data width select 32 bits  */

/************************  Bit definition for FFT_DST_DMA_CTL register of HT_FFT_TypeDef ***********************/
#define  FFT_DST_DMA_CTRL               ((uint32_t)0x03ffffff)            /*!<control register of FFT output data */

#define  FFT_DST_DMA_CTL_DST_BW         ((uint32_t)0x00000001)            /*!<bit width of output data of FFT calculation result configuration bit */
#define  FFT_DST_DMA_CTL_DST_BW_16BITS  ((uint32_t)0x00000000)            /*!<bit width of output data of FFT calculation result configurate to 16 bits */
#define  FFT_DST_DMA_CTL_DST_BW_32BITS  ((uint32_t)0x00000001)            /*!<bit width of output data of FFT calculation result configurate to 24 bits */

#define  FFT_DST_DMA_CTL_SCALE_EN       ((uint32_t)0x00000002)            /*!<result automatically proportion adjustment enable */
#define  FFT_DST_DMA_CTL_FUNDIDX        ((uint32_t)0x03ff0000)            /*!<configuration bit of fundamental location */

/************************  Bit definition for FFT_DST_FUNDSCALE register of HT_FFT_TypeDef ***********************/
#define   FFT_DST_FUNDSCALE_Mask        ((uint32_t)0x0fffffff)            /*!<bit number register of left shift of FFT output fundamental */
#define   FFT_DST_FUNDSCALE_SHIFT0      ((uint32_t)0x0000000f)            /*!<fundamental left shift status bit of FFT output data channel 0 */
#define   FFT_DST_FUNDSCALE_SHIFT1      ((uint32_t)0x000000f0)            /*!<fundamental left shift status bit of FFT output data channel 1 */
#define   FFT_DST_FUNDSCALE_SHIFT2      ((uint32_t)0x00000f00)            /*!<fundamental left shift status bit of FFT output data channel 2 */
#define   FFT_DST_FUNDSCALE_SHIFT3      ((uint32_t)0x0000f000)            /*!<fundamental left shift status bit of FFT output data channel 3 */
#define   FFT_DST_FUNDSCALE_SHIFT4      ((uint32_t)0x000f0000)            /*!<fundamental left shift status bit of FFT output data channel 4 */
#define   FFT_DST_FUNDSCALE_SHIFT5      ((uint32_t)0x00f00000)            /*!<fundamental left shift status bit of FFT output data channel 5 */
#define   FFT_DST_FUNDSCALE_SHIFT6      ((uint32_t)0x0f000000)            /*!<fundamental left shift status bit of FFT output data channel 6 */

/************************  Bit definition for FFT_DST_NONFUNDSCALE register of HT_FFT_TypeDef ***********************/
#define   FFT_DST_NONFUNDSCALE_Mask        ((uint32_t)0x0fffffff)            /*!<bit number register of left shift of FFT output fundamental */
#define   FFT_DST_NONFUNDSCALE_SHIFT0      ((uint32_t)0x0000000f)            /*!<non-fundamental left shift status bit of FFT output data channel 0 */
#define   FFT_DST_NONFUNDSCALE_SHIFT1      ((uint32_t)0x000000f0)            /*!<non-fundamental left shift status bit of FFT output data channel 1 */
#define   FFT_DST_NONFUNDSCALE_SHIFT2      ((uint32_t)0x00000f00)            /*!<non-fundamental left shift status bit of FFT output data channel 2 */
#define   FFT_DST_NONFUNDSCALE_SHIFT3      ((uint32_t)0x0000f000)            /*!<non-fundamental left shift status bit of FFT output data channel 3 */
#define   FFT_DST_NONFUNDSCALE_SHIFT4      ((uint32_t)0x000f0000)            /*!<non-fundamental left shift status bit of FFT output data channel 4 */
#define   FFT_DST_NONFUNDSCALE_SHIFT5      ((uint32_t)0x00f00000)            /*!<non-fundamental left shift status bit of FFT output data channel 5 */
#define   FFT_DST_NONFUNDSCALE_SHIFT6      ((uint32_t)0x0f000000)            /*!<non-fundamental left shift status bit of FFT output data channel 6 */

/************************  Bit definition for FFT_NUMS register of HT_FFT_TypeDef ***********************/
#define   FFT_NUMS_Mask                    ((uint32_t)0x0007)                /*!<FFT remaining calculation quantity status bit  */    

/************************  Bit definition for FFTIF register of HT_FFT_TypeDef ***********************/
#define   FFT_FFTIF                        ((uint32_t)0x0003)                /*!<FFT interrupt flag */    
#define   FFT_FFTIF_FFT_IF                 ((uint32_t)0x0001)                /*!<FFT calculatation completion interrupt flag */ 
#define   FFT_FFTIF_FFT_DONE_IF            ((uint32_t)0x0002)                /*!<FFTconfiguration channel calculation completion interrupt flag */ 

/************************  Bit definition for FFTERR register of HT_FFT_TypeDef ***********************/
#define   FFT_FFTERR                       ((uint32_t)0x0019)                /*!FFT data overflow status register */    
#define   FFT_FFTERR_CLIPE                 ((uint32_t)0x0001)                /*!FFT first-level operation overflow status flag */    
#define   FFT_FFTERR_CLIPIN                ((uint32_t)0x0008)                /*!input data proportion adjustment overflow status flag（right shift） */ 
#define   FFT_FFTERR_CLIPOUT               ((uint32_t)0x0010)                /*!output data proportion adjustment overflow status flag（left shift） */ 

/************************  Bit definition for FFTERR register of HT_FFT_TypeDef ***********************/
#define   FFT_DMACNT                       ((uint32_t)0xffffffff)            /*!FFT DMA count status register */ 
#define   FFT_DMACNT_DMAINCNT              ((uint32_t)0x0000ffff)            /*!FFT input DMA remain count status flag（word） */ 
#define   FFT_DMACNT_DMAOUTCNT             ((uint32_t)0xffff0000)            /*!FFT output DMA remain count status flag（word） */ 
#endif

/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of FRAMPACK Module
**********************************************************************************************************
*/
#if defined  USE_FRAMPACK_5X  ||  defined  USE_FRAMPACK_7X
/************************  Bit definition for FRAMCON register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FRAMCON                ((uint32_t)0x03ff)           /*!<Fram config register  */

#define  FRAMPACK_EN_Pos								  (0U)	
#define  FRAMPACK_EN_Mask						      (1U<<FRAMPACK_EN_Pos)	
#define  FRAMPACK_FRAMCON_PACKEN		      (0x01U<<FRAMPACK_EN_Pos)
#define  FRAMPACK_ABORT_Pos							  (1U)	
#define  FRAMPACK_ABORT_Mask						  (1U<<FRAMPACK_ABORT_Pos)	
#define  FRAMPACK_FRAMCON_ABORT 		      (0x01U<<FRAMPACK_ABORT_Pos)


#define  FRAMPACK_SPISEL_Pos						  (2U)	
#define  FRAMPACK_SPISEL_Mask						  (1U<<FRAMPACK_SPISEL_Pos)
#if defined  USE_FRAMPACK_5X 	
#define  FRAMPACK_FRAMCON_SPISEL_SPI1		  (0x00U<<FRAMPACK_SPISEL_Pos)	
#else
#define  FRAMPACK_FRAMCON_SPISEL_SPI0		  (0x00U<<FRAMPACK_SPISEL_Pos)
#endif
#define  FRAMPACK_FRAMCON_SPISEL_SPI2		  (0x01U<<FRAMPACK_SPISEL_Pos)                                          
                                          
#define  FRAMPACK_ENDSEL_Pos						  (3U)	
#define  FRAMPACK_ENDSEL_Mask						  (1U<<FRAMPACK_ENDSEL_Pos)		
#define  FRAMPACK_FRAMCON_ENDSEL	  		  (0x01U<<FRAMPACK_ENDSEL_Pos)

#define  FRAMPACK_COMSEL_Pos							(4U)	
#define  FRAMPACK_COMSEL_Mask						  (7U<<FRAMPACK_COMSEL_Pos)	
#define  FRAMPACK_FRAMCON_COMSEL_1		  	(0x01U<<FRAMPACK_COMSEL_Pos)
#define  FRAMPACK_FRAMCON_COMSEL_2		  	(0x02U<<FRAMPACK_COMSEL_Pos)
#define  FRAMPACK_FRAMCON_COMSEL_3	 		  (0x03U<<FRAMPACK_COMSEL_Pos)
#if defined  USE_FRAMPACK_7X
#define  FRAMPACK_FRAMCON_COMSEL_4	 		  (0x04U<<FRAMPACK_COMSEL_Pos)
#define  FRAMPACK_FRAMCON_COMSEL_5	 		  (0x05U<<FRAMPACK_COMSEL_Pos)
#define  FRAMPACK_FRAMCON_COMSEL_6	 		  (0x06U<<FRAMPACK_COMSEL_Pos)
#define  FRAMPACK_FRAMCON_COMSEL_7	 		  (0x07U<<FRAMPACK_COMSEL_Pos)
#endif
#define  FRAMPACK_SDACFG_Pos							(7U)	
#define  FRAMPACK_SDACFG_Mask						  (1U<<FRAMPACK_SDACFG_Pos)	
#define  FRAMPACK_FRAMCON_SDACFG_24BITS	 	(0x00U<<FRAMPACK_SDACFG_Pos)	
#define  FRAMPACK_FRAMCON_SDACFG_16BITS	  (0x01U<<FRAMPACK_SDACFG_Pos)

#define  FRAMPACK_DATAOUTDLY_Pos					(8U)	
#define  FRAMPACK_DATAOUTDLY_Mask					(3U<<FRAMPACK_DATAOUTDLY_Pos)	
#define  FRAMPACK_FRAMCON_DATAOUTDLY_NONE	(0x00U<<FRAMPACK_DATAOUTDLY_Pos)	
#define  FRAMPACK_FRAMCON_DATAOUTDLY_1CLK (0x01U<<FRAMPACK_DATAOUTDLY_Pos)
#define  FRAMPACK_FRAMCON_DATAOUTDLY_2CLK (0x02U<<FRAMPACK_DATAOUTDLY_Pos)
#define  FRAMPACK_FRAMCON_DATAOUTDLY_3CLK (0x03U<<FRAMPACK_DATAOUTDLY_Pos)

/************************  Bit definition for HLCFG register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HLCFG                ((uint32_t)0x00ff)           /*!<frame head length config register  */
#define  FRAMPACK_HLCFG_HEADA_Pos				(4U)	
#define  FRAMPACK_HLCFG_HEADA_Mask			(0x0FU<<FRAMPACK_HLCFG_HEADA_Pos)	
#define  FRAMPACK_HLCFG_HEADB_Pos				(0U)	
#define  FRAMPACK_HLCFG_HEADB_Mask			(0x0FU<<FRAMPACK_HLCFG_HEADB_Pos)	

/************************  Bit definition for FCRCCFG register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FCRCCFG              ((uint32_t)0x01ff)           /*!<CRC config register  */

#define  FRAMPACK_FCRCCFG_CRCSEL_Pos			(0U)	
#define  FRAMPACK_FCRCCFG_CRCSEL_Mask			(1U<<FRAMPACK_FCRCCFG_CRCSEL_Pos)
#define  FRAMPACK_FCRCCFG_CRC_SEL      		(1U<<FRAMPACK_FCRCCFG_CRCSEL_Pos)

#define  FRAMPACK_FCRCCFG_CRC_MODE_Pos		(1U)	
#define  FRAMPACK_FCRCCFG_CRC_MODE_Mask		(3U<<FRAMPACK_FCRCCFG_CRC_MODE_Pos)
#define  FRAMPACK_FCRCCFG_CRC16_1021      (0U<<FRAMPACK_FCRCCFG_CRC_MODE_Pos)
#define  FRAMPACK_FCRCCFG_CRC16_8005      (1U<<FRAMPACK_FCRCCFG_CRC_MODE_Pos)
#define  FRAMPACK_FCRCCFG_CRC32			      (2U<<FRAMPACK_FCRCCFG_CRC_MODE_Pos)

#define  FRAMPACK_FCRCCFG_CLEN_SEL_Pos		(3U)	
#define  FRAMPACK_FCRCCFG_CLEN_SEL_Mask		(3U<<FRAMPACK_FCRCCFG_CLEN_SEL_Pos)
#define  FRAMPACK_FCRCCFG_CLEN_SEL_4BYTE  (0U<<FRAMPACK_FCRCCFG_CLEN_SEL_Pos)
#define  FRAMPACK_FCRCCFG_CLEN_SEL_1BYTE  (1U<<FRAMPACK_FCRCCFG_CLEN_SEL_Pos)
#define  FRAMPACK_FCRCCFG_CLEN_SEL_2BYTE  (2U<<FRAMPACK_FCRCCFG_CLEN_SEL_Pos)

#define  FRAMPACK_FCRCCFG_REFIN_Pos       (5U)
#define  FRAMPACK_FCRCCFG_REFIN_Mask			(1U<<FRAMPACK_FCRCCFG_REFIN_Pos)
#define  FRAMPACK_FCRCCFG_REFIN_REVERSE		(1U<<FRAMPACK_FCRCCFG_REFIN_Pos)

#define  FRAMPACK_FCRCCFG_REFOUT_Pos      (6U)
#define  FRAMPACK_FCRCCFG_REFOUT_Mask			(1U<<FRAMPACK_FCRCCFG_REFOUT_Pos)
#define  FRAMPACK_FCRCCFG_REFOUT_REVERSE	(1U<<FRAMPACK_FCRCCFG_REFOUT_Pos)

#define  FRAMPACK_FCRCCFG_XOROUT_Pos      (7U)
#define  FRAMPACK_FCRCCFG_XOROUT_Mask			(1U<<FRAMPACK_FCRCCFG_XOROUT_Pos)
#define  FRAMPACK_FCRCCFG_XOROUT_REVERSE	(1U<<FRAMPACK_FCRCCFG_XOROUT_Pos)

#define  FRAMPACK_FCRCCFG_CHECK_ENDIAN_Pos	(8U)
#define  FRAMPACK_FCRCCFG_CHECK_ENDSEL_Mask	(1U<<FRAMPACK_FCRCCFG_CHECK_ENDIAN_Pos)
#define  FRAMPACK_FCRCCFG_CHECK_ENDSEL			(1U<<FRAMPACK_FCRCCFG_CHECK_ENDIAN_Pos)

/************************  Bit definition for FCRCINIT register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FCRCINIT              ((uint32_t)0xffffffff)           /*!<CRC Initialize seed register  */

/************************  Bit definition for IDCFG register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_IDCFG                 ((uint32_t)0x00f3)           /*!<frame ID config register  */
#define  FRAMPACK_IDCFG_ID_CLR          ((uint32_t)0x0001)           /*!<clear ID cnt control bit  */

#define  FRAMPACK_IDCFG_ID_SEL          ((uint32_t)0x0002)           /*!<frame ID length select bit*/
#define  FRAMPACK_IDCFG_ID_SEL_Pos				(1U)
#define  FRAMPACK_IDCFG_ID_SEL_Mask				(1U<<FRAMPACK_IDCFG_ID_SEL_Pos)
#define  FRAMPACK_IDCFG_ID_SEL_1BYTE    	(0U<<FRAMPACK_IDCFG_ID_SEL_Pos)
#define  FRAMPACK_IDCFG_ID_SEL_2BYTE    	(1U<<FRAMPACK_IDCFG_ID_SEL_Pos)

#define  FRAMPACK_IDCFG_ID_ADDR         ((uint32_t)0x00f0)           /*!<frame ID address config register  */
#define  FRAMPACK_IDCFG_ID_ADDR_Pos				(4U)
#define  FRAMPACK_IDCFG_ID_ADDR_Mask			(0xFU<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_0					(0U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_1					(1U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_2					(2U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_3					(3U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_4					(4U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_5					(5U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_6					(6U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_7					(7U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_8					(8U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_9					(9U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_10				(10U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_11				(11U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_12				(12U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_13				(13U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_14				(14U<<FRAMPACK_IDCFG_ID_ADDR_Pos)
#define  FRAMPACK_IDCFG_ID_ADDR_15				(15U<<FRAMPACK_IDCFG_ID_ADDR_Pos)

/************************  Bit definition for FRAMIE register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FRAMIE                      ((uint32_t)0x001f)          /*!<frame pack interrupt enable register  */
#define  FRAMPACK_FRAMIE_ENDIE                ((uint32_t)0x0001)          /*!<End of frame transmission completion interrupt enable bit */
#define  FRAMPACK_FRAMIE_HEADIE               ((uint32_t)0x0002)          /*!<Head of frame transmission completion interrupt enable bit */
#define  FRAMPACK_FRAMIE_FIFOFULLIE           ((uint32_t)0x0004)          /*!<EMU data FIFO full interrupt enable bit  */
#define  FRAMPACK_FRAMIE_FIFOEMPTYIE          ((uint32_t)0x0008)          /*!<EMU data FIFO empty interrupt enable bit  */
#define  FRAMPACK_FRAMIE_FRAM_DONEIE          ((uint32_t)0x0010)          /*!<Automatic frame transmission completed interrupt enable bit  */

/************************  Bit definition for FRAMIE register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FRAMIF                      ((uint32_t)0x001f)          /*!<frame pack interrupt flag register  */
#define  FRAMPACK_FRAMIF_ENDIF                ((uint32_t)0x0001)          /*!<End of frame transmission completion interrupt flag bit */
#define  FRAMPACK_FRAMIF_HEADIF               ((uint32_t)0x0002)          /*!<Head of frame transmission completion interrupt flag bit */
#define  FRAMPACK_FRAMIF_FIFOFULLIF           ((uint32_t)0x0004)          /*!<EMU data FIFO full interrupt flag bit  */
#define  FRAMPACK_FRAMIF_FIFOEMPTYIF          ((uint32_t)0x0008)          /*!<EMU data FIFO empty interrupt flag bit  */
#define  FRAMPACK_FRAMIF_FRAM_DONEIF          ((uint32_t)0x0010)          /*!<Automatic frame transmission completed interrupt flag bit  */

/************************  Bit definition for SAMPNUM register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_SAMPNUM                      ((uint32_t)0xffff)           /*!<EMU Sampling group number configuration register*/

/************************  Bit definition for HEADA0 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADA0                      ((uint32_t)0xffffffff)           /*!<frame head A0 config register*/
#define  FRAMPACK_HEADA0_HA0                  ((uint32_t)0x000000ff)           /*!<frame head A0 data register  */
#define  FRAMPACK_HEADA0_HA1                  ((uint32_t)0x0000ff00)           /*!<frame head A1 data register  */
#define  FRAMPACK_HEADA0_HA2                  ((uint32_t)0x00ff0000)           /*!<frame head A2 data register  */
#define  FRAMPACK_HEADA0_HA3                  ((uint32_t)0xff000000)           /*!<frame head A3 data register  */

/************************  Bit definition for HEADA1 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADA1                      ((uint32_t)0xffffffff)           /*!<frame head A1 config register*/
#define  FRAMPACK_HEADA1_HA4                  ((uint32_t)0x000000ff)           /*!<frame head A4 data register  */
#define  FRAMPACK_HEADA1_HA5                  ((uint32_t)0x0000ff00)           /*!<frame head A5 data register  */
#define  FRAMPACK_HEADA1_HA6                  ((uint32_t)0x00ff0000)           /*!<frame head A6 data register  */
#define  FRAMPACK_HEADA1_HA7                  ((uint32_t)0xff000000)           /*!<frame head A7 data register  */

/************************  Bit definition for HEADA2 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADA2                      ((uint32_t)0xffffffff)           /*!<frame head A2  config register*/
#define  FRAMPACK_HEADA2_HA8                  ((uint32_t)0x000000ff)           /*!<frame head A8  data register  */
#define  FRAMPACK_HEADA2_HA9                  ((uint32_t)0x0000ff00)           /*!<frame head A9  data register  */
#define  FRAMPACK_HEADA2_HA10                 ((uint32_t)0x00ff0000)           /*!<frame head A10 data register  */
#define  FRAMPACK_HEADA2_HA11                 ((uint32_t)0xff000000)           /*!<frame head A11 data register  */

/************************  Bit definition for HEADA3 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADA3                      ((uint32_t)0xffffffff)           /*!<frame head A3  config register*/
#define  FRAMPACK_HEADA3_HA12                 ((uint32_t)0x000000ff)           /*!<frame head A12 data register  */
#define  FRAMPACK_HEADA3_HA13                 ((uint32_t)0x0000ff00)           /*!<frame head A13 data register  */
#define  FRAMPACK_HEADA3_HA14                 ((uint32_t)0x00ff0000)           /*!<frame head A14 data register  */
#define  FRAMPACK_HEADA3_HA15                 ((uint32_t)0xff000000)           /*!<frame head A15 data register  */

/************************  Bit definition for HEADB0 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADB0                      ((uint32_t)0xffffffff)           /*!<frame head B0 config register*/
#define  FRAMPACK_HEADB0_HB0                  ((uint32_t)0x000000ff)           /*!<frame head B0 data register  */
#define  FRAMPACK_HEADB0_HB1                  ((uint32_t)0x0000ff00)           /*!<frame head B1 data register  */
#define  FRAMPACK_HEADB0_HB2                  ((uint32_t)0x00ff0000)           /*!<frame head B2 data register  */
#define  FRAMPACK_HEADB0_HB3                  ((uint32_t)0xff000000)           /*!<frame head B3 data register  */

/************************  Bit definition for HEADB1 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADB1                      ((uint32_t)0xffffffff)           /*!<frame head B1 config register*/
#define  FRAMPACK_HEADB1_HB4                  ((uint32_t)0x000000ff)           /*!<frame head B4 data register  */
#define  FRAMPACK_HEADB1_HB5                  ((uint32_t)0x0000ff00)           /*!<frame head B5 data register  */
#define  FRAMPACK_HEADB1_HB6                  ((uint32_t)0x00ff0000)           /*!<frame head B6 data register  */
#define  FRAMPACK_HEADB1_HB7                  ((uint32_t)0xff000000)           /*!<frame head B7 data register  */

/************************  Bit definition for HEADB2 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADB2                      ((uint32_t)0xffffffff)           /*!<frame head B2  config register*/
#define  FRAMPACK_HEADB2_HB8                  ((uint32_t)0x000000ff)           /*!<frame head B8  data register  */
#define  FRAMPACK_HEADB2_HB9                  ((uint32_t)0x0000ff00)           /*!<frame head B9  data register  */
#define  FRAMPACK_HEADB2_HB10                 ((uint32_t)0x00ff0000)           /*!<frame head B10 data register  */
#define  FRAMPACK_HEADB2_HB11                 ((uint32_t)0xff000000)           /*!<frame head B11 data register  */

/************************  Bit definition for HEADB3 register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_HEADB3                      ((uint32_t)0xffffffff)           /*!<frame head B3  config register*/
#define  FRAMPACK_HEADB3_HA12                 ((uint32_t)0x000000ff)           /*!<frame head B12 data register  */
#define  FRAMPACK_HEADB3_HA13                 ((uint32_t)0x0000ff00)           /*!<frame head B13 data register  */
#define  FRAMPACK_HEADB3_HA14                 ((uint32_t)0x00ff0000)           /*!<frame head B14 data register  */
#define  FRAMPACK_HEADB3_HA15                 ((uint32_t)0xff000000)           /*!<frame head B15 data register  */

/************************  Bit definition for STOPE register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_STOPE                     ((uint32_t)0x00ff)           /*!<frame end config register*/

/************************  Bit definition for FRAMID  register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FRAMID                     ((uint32_t)0xffff)           /*!<frame ID config register*/

/************************  Bit definition for FRAMSTA  register of HT_FRAMPACK_TypeDef ***********************/
#if defined  USE_FRAMPACK_5X
#define  FRAMPACK_FRAMSTA                    ((uint32_t)0x707)           /*!<frame pack status register*/
#define  FRAMPACK_FRAMSTA_FIFOSTA            ((uint32_t)0x007)           /*!<EMU data FIFO status*/
#else
#define  FRAMPACK_FRAMSTA                    ((uint32_t)0x703)           /*!<frame pack status register*/
#define  FRAMPACK_FRAMSTA_FIFOSTA            ((uint32_t)0x003)           /*!<EMU data FIFO status*/
#endif

#define  FRAMPACK_FRAMSTA_STATE              ((uint32_t)0x700)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_IDLE         ((uint32_t)0x000)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_ST_HEADA     ((uint32_t)0x100)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_ST_HEADB     ((uint32_t)0x200)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_ST_DATA      ((uint32_t)0x300)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_ST_CHECK     ((uint32_t)0x400)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_ST_STOP      ((uint32_t)0x500)          /*!<Internal working status*/
#define  FRAMPACK_FRAMSTA_STATE_OTHER        ((uint32_t)0x600)          /*!<Internal working status*/
/************************  Bit definition for FDLY  register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FDLY                     ((uint32_t)0xffff)           /*!<Frame interval configuration register*/

/************************  Bit definition for FAUTONUM  register of HT_FRAMPACK_TypeDef ***********************/
#define  FRAMPACK_FAUTONUM                 ((uint32_t)0xffff)           /*!<Automatic frame transmission quantity configuration register*/
#endif
/*
**********************************************************************************************************
*                         Peripheral Registers_Bits_Definition of EMU Module
**********************************************************************************************************
*/
#if  defined  USE_EMU_CONST
/************************  Bit definition for ECCCON register of HT_ECC_TypeDef ***********************/
#define  EMU_POWERINQ                      ((uint32_t)0xFFFFFFFF)       /*!<Power Q Input Register         */
#define  EMU_POWERINP                      ((uint32_t)0xFFFFFFFF)       /*!<Power P Input Register         */
#define  EMU_HFCONST                       ((uint32_t)0x00007FFF)       /*!<HFConst Config Register        */
#define  EMU_ENERGYP                       ((uint32_t)0x00FFFFFF)       /*!<Energy P Counter Register      */
#define  EMU_ENERGYQ                       ((uint32_t)0x00FFFFFF)       /*!<Energy Q Counter Register      */
                                                                      
#define  EMU_READCRTL                      ((uint32_t)0x0000000F)       /*!<Energy Read Control Register   */
#define  EMU_READCRTL_ENERGYP_REQ            ((uint32_t)0x00000008)       /*!<EnergyP Read Request Bit     */
#define  EMU_READCRTL_ENERGYQ_REQ            ((uint32_t)0x00000004)       /*!<EnergyQ Read Request Bit     */
#define  EMU_READCRTL_ENERGYP_RDY            ((uint32_t)0x00000002)       /*!<EnergyP buffer state Bit     */
#define  EMU_READCRTL_ENERGYQ_RDY            ((uint32_t)0x00000001)       /*!<EnergyQ buffer state Bit     */

#endif

#ifdef __cplusplus
}
#endif

#endif  /* __HT6XXX_H__ */
