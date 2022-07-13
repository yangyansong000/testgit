﻿;/*
;*********************************************************************************************************
;*                                             HT6X2X
;*                                         Library Function
;*
;*                                  Copyright 2013, Hi-Trend Tech, Corp.
;*                                       All Rights Reserved
;*
;*
;* Project      : HT6xxx
;* File         : startup_ht6x2x.s
;* By           : SocTeam
;* Version      : Version1_8_20181106
;* Description  :
;*********************************************************************************************************
;*/

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .password:CODE
        DCD     0xF7FFFFA2

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     0                         ; MPU Fault Handler
        DCD     0                         ; Bus Fault Handler
        DCD     0                         ; Usage Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     0                         ; Debug Monitor Handler
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts
        DCD     PMU_IRQHandler            ; 16+ 0: PMU
        DCD     AES_IRQHandler            ; 16+ 1: AES
        DCD     EXTI0_IRQHandler          ; 16+ 2: EXTI0
        DCD     EXTI1_IRQHandler          ; 16+ 3: EXTI1
        DCD     EXTI2_IRQHandler          ; 16+ 4: EXTI2
        DCD     EXTI3_IRQHandler          ; 16+ 5: EXTI3
        DCD     EXTI4_IRQHandler          ; 16+ 6: EXTI4
        DCD     EXTI5_IRQHandler          ; 16+ 7: EXTI5
        DCD     EXTI6_IRQHandler          ; 16+ 8: EXTI6
        DCD     UART0_IRQHandler          ; 16+ 9: UART0
        DCD     UART1_IRQHandler          ; 16+10: UART1
        DCD     UART2_IRQHandler          ; 16+11: UART2
        DCD     UART3_IRQHandler          ; 16+12: UART3
        DCD     UART4_IRQHandler          ; 16+13: UART4
        DCD     UART5_IRQHandler          ; 16+14: UART5
        DCD     TIMER_0_IRQHandler        ; 16+15: Timer0
        DCD     TIMER_1_IRQHandler        ; 16+16: Timer1
        DCD     TIMER_2_IRQHandler        ; 16+17: Timer2
        DCD     TIMER_3_IRQHandler        ; 16+18: Timer3
        DCD     TBS_IRQHandler            ; 16+19: TBS
        DCD     RTC_IRQHandler            ; 16+20: RTC
        DCD     I2C_IRQHandler            ; 16+21: I2C
        DCD     SPI0_IRQHandler           ; 16+22: SPI0
        DCD     SPI1_IRQHandler           ; 16+23: SPI1
        DCD     SelfTestFreq_IRQHandler   ; 16+24: SelfTestFreq
        DCD     TIMER_4_IRQHandler        ; 16+25: Timer4
        DCD     TIMER_5_IRQHandler        ; 16+26: Timer5
        DCD     UART6_IRQHandler          ; 16+27: UART6
        DCD     EXTI7_IRQHandler          ; 16+28: EXTI7
        DCD     EXTI8_IRQHandler          ; 16+29: EXTI8
        DCD     EXTI9_IRQHandler          ; 16+30: EXTI9
        DCD     DMA_IRQHandler            ; 16+31: DMA


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        PUBWEAK PMU_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PMU_IRQHandler
        B PMU_IRQHandler

        PUBWEAK AES_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
AES_IRQHandler
        B AES_IRQHandler

        PUBWEAK EXTI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_IRQHandler
        B EXTI0_IRQHandler

        PUBWEAK EXTI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_IRQHandler
        B EXTI1_IRQHandler

        PUBWEAK EXTI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI2_IRQHandler
        B EXTI2_IRQHandler

        PUBWEAK EXTI3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_IRQHandler
        B EXTI3_IRQHandler

        PUBWEAK EXTI4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI4_IRQHandler
        B EXTI4_IRQHandler

        PUBWEAK EXTI5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI5_IRQHandler
        B EXTI5_IRQHandler

        PUBWEAK EXTI6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI6_IRQHandler
        B EXTI6_IRQHandler

        PUBWEAK UART0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART0_IRQHandler
        B UART0_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_IRQHandler
        B UART3_IRQHandler

        PUBWEAK UART4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_IRQHandler
        B UART4_IRQHandler

        PUBWEAK UART5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART5_IRQHandler
        B UART5_IRQHandler

        PUBWEAK TIMER_0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_0_IRQHandler
        B TIMER_0_IRQHandler

        PUBWEAK TIMER_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_1_IRQHandler
        B TIMER_1_IRQHandler

        PUBWEAK TIMER_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_2_IRQHandler
        B TIMER_2_IRQHandler

        PUBWEAK TIMER_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_3_IRQHandler
        B TIMER_3_IRQHandler

        PUBWEAK TBS_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TBS_IRQHandler
        B TBS_IRQHandler

        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_IRQHandler
        B RTC_IRQHandler

        PUBWEAK I2C_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C_IRQHandler
        B I2C_IRQHandler

        PUBWEAK SPI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI0_IRQHandler
        B SPI0_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK SelfTestFreq_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SelfTestFreq_IRQHandler
        B SelfTestFreq_IRQHandler

        PUBWEAK TIMER_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_4_IRQHandler
        B TIMER_4_IRQHandler

        PUBWEAK TIMER_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER_5_IRQHandler
        B TIMER_5_IRQHandler

        PUBWEAK UART6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART6_IRQHandler
        B UART6_IRQHandler

        PUBWEAK EXTI7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI7_IRQHandler
        B EXTI7_IRQHandler

        PUBWEAK EXTI8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI8_IRQHandler
        B EXTI8_IRQHandler

        PUBWEAK EXTI9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI9_IRQHandler
        B EXTI9_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA_IRQHandler
        B DMA_IRQHandler

        END
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
