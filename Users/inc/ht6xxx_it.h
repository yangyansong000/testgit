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
* File         : ht6xxx_it.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_IT_H__
#define __HT6XXX_IT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             Global Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
void NMI_Handler(void);                          /*!< #16-14              */
void HardFault_Handler(void);                    /*!< #16-13              */
void SVC_Handler(void);                          /*!< #16-5               */
void PendSV_Handler(void);                       /*!< #16-2               */
void SysTick_Handler(void);                      /*!< #16-1               */

void PMU_IRQHandler(void);                       /*!< #16+0               */

#if defined HT6x1x                               /*!< #16+1               */
void TDES_IRQHandler(void);
#else
void AES_IRQHandler(void);
#endif

void EXTI0_IRQHandler(void);                     /*!< #16+2               */
void EXTI1_IRQHandler(void);                     /*!< #16+3               */
void EXTI2_IRQHandler(void);                     /*!< #16+4               */
void EXTI3_IRQHandler(void);                     /*!< #16+5               */
void EXTI4_IRQHandler(void);                     /*!< #16+6               */
void EXTI5_IRQHandler(void);                     /*!< #16+7               */
void EXTI6_IRQHandler(void);                     /*!< #16+8               */
void UART0_IRQHandler(void);                     /*!< #16+9               */
void UART1_IRQHandler(void);                     /*!< #16+10              */
void UART2_IRQHandler(void);                     /*!< #16+11              */
void UART3_IRQHandler(void);                     /*!< #16+12              */
void UART4_IRQHandler(void);                     /*!< #16+13              */
void UART5_IRQHandler(void);                     /*!< #16+14              */
void TIMER_0_IRQHandler(void);                   /*!< #16+15              */
void TIMER_1_IRQHandler(void);                   /*!< #16+16              */
void TIMER_2_IRQHandler(void);                   /*!< #16+17              */
void TIMER_3_IRQHandler(void);                   /*!< #16+18              */
void TBS_IRQHandler(void);                       /*!< #16+19              */
void RTC_IRQHandler(void);                       /*!< #16+20              */
void I2C_IRQHandler(void);                       /*!< #16+21              */
void SPI0_IRQHandler(void);                      /*!< #16+22              */

#if defined  HT6x1x                              /*!< #16+23              */
void WDT_IRQHandler(void);
#elif defined HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
void SPI1_IRQHandler(void);
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
                                                 /*!< #16+24              */
void SelfTestFreq_IRQHandler(void);
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
                                                 /*!< #16+25              */
void TIMER_4_IRQHandler(void);
#elif defined HT501x
void EMU_IRQHandler(void);
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
                                                 /*!< #16+26              */
void TIMER_5_IRQHandler(void);
#elif defined HT501x
void DMA_IRQHandler(void);
#endif

#if defined  HT6x2x  ||  defined  HT6x3x         /*!< #16+27              */
void UART6_IRQHandler(void);
#elif defined HT501x
void KEY_IRQHandler(void);
#endif

#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
void EXTI7_IRQHandler(void);                     /*!< #16+28              */
#endif
#if defined  HT6x2x  ||  defined  HT6x2xK
void EXTI8_IRQHandler(void);                     /*!< #16+29              */
#endif
#if defined  HT6x2x  ||  defined  HT6x2xK
void EXTI9_IRQHandler(void);                     /*!< #16+30              */
#elif defined  HT6x3x
void SPI2_IRQHandler(void);
#endif
#if defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK
void DMA_IRQHandler(void);                       /*!< #16+31              */
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_IT_H__ */
