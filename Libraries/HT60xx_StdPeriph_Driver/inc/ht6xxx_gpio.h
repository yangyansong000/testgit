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
* File         : ht6xxx_gpio.h
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_GPIO_H__
#define __HT6XXX_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                         Global Macro/Structure
*********************************************************************************************************
*/

#define HT_GPIO_MODE_INPUT      0x000UL
#define HT_GPIO_MODE_OUTPUT     0x001UL
#define HT_GPIO_MODE_AF1        0x010UL
#define HT_GPIO_MODE_AF2        0x011UL
#define HT_GPIO_MODE_AF3        0x110UL
#define HT_GPIO_MODE_AF4        0x111UL
#define HT_GPIO_MODE_HIIPM      0x100UL

#define HT_GPIO_INPUT_UP        0x00UL
#define HT_GPIO_INPUT_FLOATING  0x01UL

#define HT_GPIO_OUTPUT_OD       0x00UL
#define HT_GPIO_OUTPUT_PP       0x01UL

/**
* @brief  HT_GPIO_Exported_Constants
**/
#if defined UNUSE_GPIO_GPIOF & defined UNUSE_GPIO_GPIOG & defined UNUSE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE))
#endif

#if defined USE_GPIO_GPIOF & defined UNUSE_GPIO_GPIOG & defined UNUSE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOF))
#endif

#if defined USE_GPIO_GPIOF & defined UNUSE_GPIO_GPIOG & defined USE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOF) || \
                                       ((PERIPH) == HT_GPIOH))
#endif

#if defined UNUSE_GPIO_GPIOF & defined USE_GPIO_GPIOG & defined UNUSE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOG))
#endif

#if defined UNUSE_GPIO_GPIOF & defined USE_GPIO_GPIOG & defined USE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOG) || \
                                       ((PERIPH) == HT_GPIOH))
#endif

#if defined UNUSE_GPIO_GPIOF & defined USE_GPIO_GPIOG & defined USE_GPIO_GPIOH & defined USE_GPIO_GPIOI & defined UNUSE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOG) || \
                                       ((PERIPH) == HT_GPIOH) || \
                                       ((PERIPH) == HT_GPIOI))
#endif

#if defined UNUSE_GPIO_GPIOF & defined USE_GPIO_GPIOG & defined UNUSE_GPIO_GPIOH & defined UNUSE_GPIO_GPIOI & defined USE_GPIO_GPIOJ
#define IS_HT_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HT_GPIOA) || \
                                       ((PERIPH) == HT_GPIOB) || \
                                       ((PERIPH) == HT_GPIOC) || \
                                       ((PERIPH) == HT_GPIOD) || \
                                       ((PERIPH) == HT_GPIOE) || \
                                       ((PERIPH) == HT_GPIOG) || \
                                       ((PERIPH) == HT_GPIOJ))
#endif

/**
* @brief  HT_GPIO_GPIOPin
**/
#define IS_HT_GPIO_GPIOPin(GPIO_Pin) (((GPIO_Pin) == GPIO_Pin_0)   || \
                                      ((GPIO_Pin) == GPIO_Pin_1)   || \
																		  ((GPIO_Pin) == GPIO_Pin_2)   || \
																		  ((GPIO_Pin) == GPIO_Pin_3)   || \
																		  ((GPIO_Pin) == GPIO_Pin_4)   || \
																		  ((GPIO_Pin) == GPIO_Pin_5)   || \
																		  ((GPIO_Pin) == GPIO_Pin_6)   || \
																		  ((GPIO_Pin) == GPIO_Pin_7)   || \
																		  ((GPIO_Pin) == GPIO_Pin_8)   || \
																		  ((GPIO_Pin) == GPIO_Pin_9)   || \
																		  ((GPIO_Pin) == GPIO_Pin_10)  || \
																		  ((GPIO_Pin) == GPIO_Pin_11)  || \
																		  ((GPIO_Pin) == GPIO_Pin_12)  || \
																		  ((GPIO_Pin) == GPIO_Pin_13)  || \
																		  ((GPIO_Pin) == GPIO_Pin_14)  || \
																		  ((GPIO_Pin) == GPIO_Pin_15)  || \
																		  ((GPIO_Pin) == GPIO_Pin_All))

/**
* @brief  HT_GPIO_GPIOMode
**/
#if defined USE_GPIO_AF34 & defined USE_GPIO_HIIPM
#define IS_HT_GPIO_GPIOMode(GPIO_Mode) (((GPIO_Mode) == GPIO_Mode_IOIN)  || \
                                        ((GPIO_Mode) == GPIO_Mode_IOOUT) || \
                                        ((GPIO_Mode) == GPIO_Mode_AF1)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF2)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF3)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF4)   || \
                                        ((GPIO_Mode) == GPIO_Mode_HighResistance))
#endif

#if defined USE_GPIO_AF34 & defined UNUSE_GPIO_HIIPM
#define IS_HT_GPIO_GPIOMode(GPIO_Mode) (((GPIO_Mode) == GPIO_Mode_IOIN)  || \
                                        ((GPIO_Mode) == GPIO_Mode_IOOUT) || \
                                        ((GPIO_Mode) == GPIO_Mode_AF1)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF2)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF3)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF4))
#endif

#if defined UNUSE_GPIO_AF34 & defined USE_GPIO_HIIPM
#define IS_HT_GPIO_GPIOMode(GPIO_Mode) (((GPIO_Mode) == GPIO_Mode_IOIN)  || \
                                        ((GPIO_Mode) == GPIO_Mode_IOOUT) || \
                                        ((GPIO_Mode) == GPIO_Mode_AF1)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF2)   || \
                                        ((GPIO_Mode) == GPIO_Mode_HighResistance))
#endif

#if defined UNUSE_GPIO_AF34 & defined UNUSE_GPIO_HIIPM
#define IS_HT_GPIO_GPIOMode(GPIO_Mode) (((GPIO_Mode) == GPIO_Mode_IOIN)  || \
                                        ((GPIO_Mode) == GPIO_Mode_IOOUT) || \
                                        ((GPIO_Mode) == GPIO_Mode_AF1)   || \
                                        ((GPIO_Mode) == GPIO_Mode_AF2))
#endif


/**
* @brief  HT_GPIO_Direction
**/
#define IS_HT_GPIO_Direction(GPIO_Direction) (((GPIO_Direction) == GPIO_Mode_IOIN)   || \
                                              ((GPIO_Direction) == GPIO_Mode_IOOUT))


/**
* @brief  HT_GPIO_InputStruct
**/
#define IS_HT_GPIO_InputStruct(GPIO_InputStruct) (((GPIO_InputStruct) == GPIO_Input_Up)       || \
                                                  ((GPIO_InputStruct) == GPIO_Input_Floating))

/**
* @brief  HT_GPIO_OutputStruct
**/
#define IS_HT_GPIO_OutputStruct(GPIO_OutputStruct) (((GPIO_OutputStruct) == GPIO_Output_OD)   || \
                                                    ((GPIO_OutputStruct) == GPIO_Output_PP))

/**
* @brief  HT_GPIO_InputFilter
**/
#if defined USE_GPIO_FILT
#define IS_HT_GPIO_InputFilter(GPIO_InputFilter) (((GPIO_InputFilter) == ENABLE)   || \
                                                  ((GPIO_InputFilter) == DISABLE))
#endif

#if defined USE_GPIO_NEWAFCTRL
#define IS_HT_GPIO_NewAFCtrl(GPIO_NewAFCtrl)     (((GPIO_NewAFCtrl) == ENABLE)   || \
                                                  ((GPIO_NewAFCtrl) == DISABLE))
#endif

#if defined USE_GPIO_HIIPM
#define IS_HT_GPIO_HighResistance(GPIO_HighResistance)     (((GPIO_HighResistance) == ENABLE)   || \
                                                            ((GPIO_HighResistance) == DISABLE))
#endif

/**
* @brief  HT_GPIO_HighCurrent
**/
#define IS_HT_GPIO_HighCurrent(GPIO_Pin) (((GPIO_Pin) == GPIO_HDPORT_PC0)  || \
                                          ((GPIO_Pin) == GPIO_HDPORT_PA6)  || \
                                          ((GPIO_Pin) == GPIO_HDPORT_PA7)  || \
                                          ((GPIO_Pin) == GPIO_HDPORT_PA8))

/**
* @brief  GPIO Pin Function Define
**/
typedef enum
{
    GPIO_Mode_IOIN           = HT_GPIO_MODE_INPUT,             /*!< GPIO Input                     */
    GPIO_Mode_IOOUT          = HT_GPIO_MODE_OUTPUT,            /*!< GPIO Output                    */
    GPIO_Mode_AF1            = HT_GPIO_MODE_AF1,               /*!< AF1                            */
    GPIO_Mode_AF2            = HT_GPIO_MODE_AF2,               /*!< AF2                            */
#if defined USE_GPIO_AF34
	  GPIO_Mode_AF3            = HT_GPIO_MODE_AF3,               /*!< AF3                            */
	  GPIO_Mode_AF4            = HT_GPIO_MODE_AF4,               /*!< AF4                            */
#endif
#if defined USE_GPIO_HIIPM
    GPIO_Mode_HighResistance = HT_GPIO_MODE_HIIPM              /*!< High Resistance                */
#endif
}GPIOMode_TypeDef;                                       /*!<end of group GPIOMode_TypeDef         */

/**
* @brief  GPIO Input Pullup or Floating
**/
typedef enum
{
    GPIO_Input_Up       = HT_GPIO_INPUT_UP,                    /*!< GPIO Input Pullup              */
    GPIO_Input_Floating = HT_GPIO_INPUT_FLOATING,              /*!< GPIO Input Floating            */
}GPIOInput_TypeDef;                                      /*!< end of group GPIOInput_TypeDef       */

/**
* @brief  GPIO Output Push or Open Drain
**/
typedef enum
{
    GPIO_Output_OD = HT_GPIO_OUTPUT_OD,                        /*!< GPIO Output Open Drain         */
    GPIO_Output_PP = HT_GPIO_OUTPUT_PP,                        /*!< GPIO Output Push               */
}GPIOOutput_TypeDef;                                     /*!< end of group GPIOOutput_TypeDef      */

/**
* @brief  GPIO Init Type Define
**/
typedef struct
{
    uint16_t            GPIO_Pin;                              /*!< GPIO Pin                       */
    GPIOMode_TypeDef    GPIO_Mode;                             /*!< GPIO Mode                      */
    GPIOInput_TypeDef   GPIO_InputStruct;                      /*!< GPIO Input Pullup or Floating  */
    GPIOOutput_TypeDef  GPIO_OutputStruct;                     /*!< GPIO Output Push or Open Drain */
#if  defined  USE_GPIO_FILT
    FunctionalState     GPIO_InputFilter;                      /*!< GPIO Input Filter              */
#endif
#if  defined  USE_GPIO_NEWAFCTRL
    FunctionalState     GPIO_NewAFCtrl;                        /*!< New AF Enable                  */
#endif
}GPIO_InitTypeDef;                                       /*!< end of group GPIO_InitTypeDef        */

/**
* @brief  GPIO Init Type Define for AFMode
**/
typedef struct
{
    uint16_t            GPIO_Pin;                              /*!< GPIO Pin                       */
    uint32_t            GPIO_AFMode;                           /*!< GPIO Mode                      */
    GPIOInput_TypeDef   GPIO_InputStruct;                      /*!< GPIO Input Pullup or Floating  */
    GPIOOutput_TypeDef  GPIO_OutputStruct;                     /*!< GPIO Output Push or Open Drain */
#if  defined  USE_GPIO_FILT
    FunctionalState     GPIO_InputFilter;                      /*!< GPIO Input Filter              */
#endif
#if  defined  USE_GPIO_NEWAFCTRL
    FunctionalState     GPIO_NewAFCtrl;                        /*!< New AF Enable                  */
#endif
}GPIO_InitAFTypeDef;                                     /*!< end of group GPIO_InitAFTypeDef      */

/**
* @brief  GPIO Pin Definition
**/
#define GPIO_Pin_0                 ((uint16_t)0x0001)          /*!< Pin 0 selected         */
#define GPIO_Pin_1                 ((uint16_t)0x0002)          /*!< Pin 1 selected         */
#define GPIO_Pin_2                 ((uint16_t)0x0004)          /*!< Pin 2 selected         */
#define GPIO_Pin_3                 ((uint16_t)0x0008)          /*!< Pin 3 selected         */
#define GPIO_Pin_4                 ((uint16_t)0x0010)          /*!< Pin 4 selected         */
#define GPIO_Pin_5                 ((uint16_t)0x0020)          /*!< Pin 5 selected         */
#define GPIO_Pin_6                 ((uint16_t)0x0040)          /*!< Pin 6 selected         */
#define GPIO_Pin_7                 ((uint16_t)0x0080)          /*!< Pin 7 selected         */
#define GPIO_Pin_8                 ((uint16_t)0x0100)          /*!< Pin 8 selected         */
#define GPIO_Pin_9                 ((uint16_t)0x0200)          /*!< Pin 9 selected         */
#define GPIO_Pin_10                ((uint16_t)0x0400)          /*!< Pin 10 selected        */
#define GPIO_Pin_11                ((uint16_t)0x0800)          /*!< Pin 11 selected        */
#define GPIO_Pin_12                ((uint16_t)0x1000)          /*!< Pin 12 selected        */
#define GPIO_Pin_13                ((uint16_t)0x2000)          /*!< Pin 13 selected        */
#define GPIO_Pin_14                ((uint16_t)0x4000)          /*!< Pin 14 selected        */
#define GPIO_Pin_15                ((uint16_t)0x8000)          /*!< Pin 15 selected        */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)          /*!< All pins selected      */

/**
* @brief  GPIO Pin AFMode Define
**/
/*!< HT_GPIOA  */
#if defined USE_MCU
#define PA0_SEG28                  ((uint16_t)0x0000<<0)       /*!<PA0_AF1:seg28           */
#if defined USE_SPI_SPI2
#define PA0_SPI2_CS                ((uint16_t)0x0001<<0)       /*!<PA0_AF2:spi2_cs         */
#endif
#define PA1_SEG29                  ((uint16_t)0x0000<<1)       /*!<PA1_AF1:seg29           */
#if defined USE_SPI_SPI2
#define PA1_SPI2_CLK               ((uint16_t)0x0001<<1)       /*!<PA1_AF2:spi2_clk        */
#endif
#define PA2_SEG30                  ((uint16_t)0x0000<<2)       /*!<PA2_AF1:seg30           */
#if defined USE_SPI_SPI2
#define PA2_SPI2_MISO              ((uint16_t)0x0001<<2)       /*!<PA2_AF2:spi2_miso       */
#endif
#define PA3_SEG31                  ((uint16_t)0x0000<<3)       /*!<PA3_AF1:seg31           */
#if defined USE_SPI_SPI2
#define PA3_SPI2_MOSI              ((uint16_t)0x0001<<3)       /*!<PA3_AF2:spi2_mosi       */
#endif
#define PA4_SEG32                  ((uint16_t)0x0000<<4)       /*!<PA4_AF1:seg32           */
#if defined USE_RTC_STAMP0 & defined USE_RTC_NONINDEPENDENT
#define PA4_STAMP0                 ((uint16_t)0x0001<<4)       /*!<PA4_AF2:stamp0          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_UART6
#define PA4_RX6                    ((uint32_t)0x00010000<<4)   /*!<PA4_AF3:rx6             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA4_SPI0_MISO              ((uint32_t)0x00010001<<4)   /*!<PA4_AF4:spi0_miso       */
#endif
#define PA5_INT0                   ((uint16_t)0x0000<<5)       /*!<PA5_AF1:int0            */
#if defined USE_TEST_CLOCKIN
#define PA5_CLOCKIN                ((uint16_t)0x0001<<5)       /*!<PA5_AF2:clockin         */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TMR_TMR5
#define PA5_TMR5                   ((uint32_t)0x00010000<<5)   /*!<PA5_AF3:tmr5            */
#endif
#define PA6_INT1                   ((uint16_t)0x0000<<6)       /*!<PA6_AF1:int1            */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_UART6
#define PA6_TX6                    ((uint32_t)0x00010000<<6)   /*!<PA6_AF3:tx6             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA6_SPI0_MOSI              ((uint32_t)0x00010001<<6)   /*!<PA6_AF4:spi0_mosi       */
#endif
#define PA7_INT2                   ((uint16_t)0x0000<<7)       /*!<PA7_AF1:int2            */
#define PA7_SEG33                  ((uint16_t)0x0001<<7)       /*!<PA7_AF2:seg33           */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA7_RX0                    ((uint32_t)0x00010000<<7)   /*!<PA7_AF3:rx0             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA7_SPI0_CLK               ((uint32_t)0x00010001<<7)   /*!<PA7_AF4:spi0_clk        */
#endif
#define PA8_INT3                   ((uint16_t)0x0000<<8)       /*!<PA8_AF1:int3            */
#define PA8_SEG34                  ((uint16_t)0x0001<<8)       /*!<PA8_AF2:seg34           */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA8_TX0                    ((uint32_t)0x00010000<<8)   /*!<PA8_AF3:tx0             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA8_SPI0_CS                ((uint32_t)0x00010001<<8)   /*!<PA8_AF4:spi0_cs         */
#endif
#define PA9_INT4                   ((uint16_t)0x0000<<9)       /*!<PA9_AF1:int4            */
#if defined USE_EMU_CONST
#define PA9_PFOUT                  ((uint16_t)0x0001<<9)       /*!<PA9_AF2:pfout           */
#endif
#define PA10_INT5                  ((uint16_t)0x0000<<10)      /*!<PA10_AF1:int5           */
#if defined USE_EMU_CONST
#define PA10_QFOUT                 ((uint16_t)0x0001<<10)      /*!<PA10_AF2:qfout          */
#endif
#define PA11_INT6                  ((uint16_t)0x0000<<11)      /*!<PA11_AF1:int6           */
#if defined USE_RTC_STAMP0 & defined USE_RTC_NONINDEPENDENT
#define PA11_STAMP0                ((uint16_t)0x0001<<11)      /*!<PA11_AF2:stamp0         */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PA11_TMR3                  ((uint32_t)0x00010000<<11)  /*!<PA11_AF3:tmr3           */
#endif
#if defined USE_GPIO_AF34 & defined USE_PMU_LVDINN
#define PA11_LVDIN0N               ((uint32_t)0x00010001<<11)  /*!<PA11_AF4:lvdin0n        */
#endif
#define PA12_SEG35                 ((uint16_t)0x0000<<12)      /*!<PA12_AF1:seg35          */
#define PA12_ADCIN0                ((uint16_t)0x0001<<12)      /*!<PA12_AF2:adcin0         */
#define PA13_SEG36                 ((uint16_t)0x0000<<13)      /*!<PA13_AF1:seg36          */
#define PA13_ADCIN1                ((uint16_t)0x0001<<13)      /*!<PA13_AF2:adcin1         */

/*!< HT_GPIOB  */
#define PB0_SEG0                   ((uint16_t)0x0000<<0)       /*!<PB0_AF1:seg0            */
#define PB1_SEG1                   ((uint16_t)0x0000<<1)       /*!<PB1_AF1:seg1            */
#define PB2_SEG2                   ((uint16_t)0x0000<<2)       /*!<PB2_AF1:seg2            */
#if defined USE_LCD_CHARGEPUMP
#define PB2_VLCD3                  ((uint16_t)0x0001<<2)       /*!<PB2_AF2:vlcd3           */
#endif
#define PB3_SEG3                   ((uint16_t)0x0000<<3)       /*!<PB3_AF1:seg3            */
#if defined USE_LCD_CHARGEPUMP
#define PB3_VLCD2                  ((uint16_t)0x0001<<3)       /*!<PB3_AF2:vlcd2           */
#endif
#define PB4_SEG4                   ((uint16_t)0x0000<<4)       /*!<PB4_AF1:seg4            */
#if defined USE_LCD_CHARGEPUMP
#define PB4_VLCD1                  ((uint16_t)0x0001<<4)       /*!<PB4_AF2:vlcd1           */
#endif
#if defined USE_GPIO_AF_PRIORITY
#define PB4_RX3                    ((uint16_t)0x0001<<4)       /*!<PB4_AF2:rx3             */
#endif
#define PB5_SEG5                   ((uint16_t)0x0000<<5)       /*!<PB5_AF1:seg5            */
#if defined USE_LCD_CHARGEPUMP
#define PB5_VLCD0                  ((uint16_t)0x0001<<5)       /*!<PB5_AF2:vlcd0           */
#endif
#if defined USE_GPIO_AF_PRIORITY
#define PB5_TX3                    ((uint16_t)0x0001<<5)       /*!<PB5_AF2:tx3             */
#endif
#define PB6_SEG6                   ((uint16_t)0x0000<<6)       /*!<PB6_AF1:seg6            */
#if defined USE_LCD_CHARGEPUMP
#define PB6_VLCDCN                 ((uint16_t)0x0001<<6)       /*!<PB6_AF2:vlcdcn          */
#endif
#if defined USE_SPI_SPI3
#define PB6_SPI3_CS                ((uint16_t)0x0001<<6)       /*!<PB6_AF2:spi3_cs         */
#endif
#if defined USE_GPIO_AF_PRIORITY
#define PB6_SPI1_CS                ((uint16_t)0x0001<<6)       /*!<PB6_AF2:spi1_cs         */
#endif
#define PB7_SEG7                   ((uint16_t)0x0000<<7)       /*!<PB7_AF1:seg7            */
#if defined USE_LCD_CHARGEPUMP
#define PB7_VLCDCP                 ((uint16_t)0x0001<<7)       /*!<PB7_AF2:vlcdcp          */
#endif
#if defined USE_SPI_SPI3
#define PB7_SPI3_CLK               ((uint16_t)0x0001<<7)       /*!<PB7_AF2:spi3_clk        */
#endif
#if defined USE_GPIO_AF_PRIORITY
#define PB7_SPI1_CLK               ((uint16_t)0x0001<<7)       /*!<PB7_AF2:spi1_clk        */
#endif
#define PB8_SEG8                   ((uint16_t)0x0000<<8)       /*!<PB8_AF1:seg8            */
#if defined USE_SPI_SPI3
#define PB8_SPI3_MISO              ((uint16_t)0x0001<<8)       /*!<PB8_AF2:spi3_miso       */
#endif
#if defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI1
#define PB8_SPI1_MISO              ((uint16_t)0x0001<<8)       /*!<PB8_AF2:spi1_miso       */
#endif
#define PB9_SEG9                   ((uint16_t)0x0000<<9)       /*!<PB9_AF1:seg9            */
#if defined USE_SPI_SPI3
#define PB9_SPI3_MOSI              ((uint16_t)0x0001<<9)       /*!<PB9_AF2:spi3_mosi       */
#endif
#if defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI1
#define PB9_SPI1_MOSI              ((uint16_t)0x0001<<9)       /*!<PB9_AF2:spi1_mosi       */
#endif
#define PB10_SEG10                 ((uint16_t)0x0000<<10)      /*!<PB10_AF1:seg10          */
#if defined USE_TBS_ADCIN9
#define PB10_ADCIN9                ((uint16_t)0x0001<<10)      /*!<PB10_AF2:adcin9         */
#endif
#define PB11_SEG11                 ((uint16_t)0x0000<<11)      /*!<PB11_AF1:seg11          */
#if defined USE_TMR_DEADZONE
#define PB11_TMR1N                 ((uint16_t)0x0001<<11)      /*!<PB11_AF2:tmr1n          */
#endif
#if defined USE_TBS_ADCIN3 & defined USE_GPIO_VER_K
#define PB11_ADCIN5                ((uint16_t)0x0001<<11)      /*!<PB11_AF2:adcin5         */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PB11_RX5                   ((uint32_t)0x00010000<<11)  /*!<PB11_AF3:rx5            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TBS_ADCIN5
#define PB11_ADCIN5                ((uint32_t)0x00010001<<11)  /*!<PB11_AF4:adcin5         */
#endif
#define PB12_SEG12                 ((uint16_t)0x0000<<12)      /*!<PB12_AF1:seg12          */
#if defined USE_GPIO_JTAG
#define PB12_TDO                   ((uint16_t)0x0001<<12)      /*!<PB12_AF2:tdo            */
#endif
#if defined USE_GPIO_AF_PRIORITY & defined USE_TMR_TMR4
#define PB12_TMR4                  ((uint16_t)0x0001<<12)      /*!<PB12_AF2:tmr4           */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PB12_TX5                   ((uint32_t)0x00010000<<12)  /*!<PB12_AF3:tx5            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TBS_ADCIN4
#define PB12_ADCIN4                ((uint32_t)0x00010001<<12)  /*!<PB12_AF4:adcin4         */
#endif
#define PB13_SEG13                 ((uint16_t)0x0000<<13)      /*!<PB13_AF1:seg13          */
#if defined USE_GPIO_JTAG
#define PB13_TMS                   ((uint16_t)0x0001<<13)      /*!<PB13_AF2:tms            */
#endif
#if defined USE_GPIO_SWD
#define PB13_SWIO                  ((uint16_t)0x0001<<13)      /*!<PB13_AF2:swio           */
#endif
#define PB14_SEG14                 ((uint16_t)0x0000<<14)      /*!<PB14_AF1:seg14          */
#if defined USE_GPIO_JTAG
#define PB14_TDI                   ((uint16_t)0x0001<<14)      /*!<PB14_AF2:tdi            */
#endif
#if defined USE_EXTI_INT14
#define PB14_INT14                 ((uint16_t)0x0001<<14)      /*!<PB14_AF2:int14          */
#endif
#if defined USE_GPIO_AF34 & defined USE_PMU_LVDIN2 & defined USE_PMU_LVDINN
#define PB14_LVDIN2N               ((uint32_t)0x00010000<<14)  /*!<PB14_AF3:lvdin2n        */
#endif
#if defined USE_GPIO_AF34 & defined USE_TMR_TMR4 & defined USE_TMR_DEADZONE
#define PB14_TMR4N                 ((uint32_t)0x00010001<<14)  /*!<PB14_AF4:tmr4n          */
#endif
#define PB15_SEG15                 ((uint16_t)0x0000<<15)      /*!<PB15_AF1:seg15          */
#if defined USE_GPIO_JTAG
#define PB15_TCK                   ((uint16_t)0x0001<<15)      /*!<PB15_AF2:tck            */
#endif
#if defined USE_GPIO_SWD
#define PB15_SWCLK                 ((uint16_t)0x0001<<15)      /*!<PB15_AF2:swclk          */
#endif

/*!< HT_GPIOC  */
#define PC0_TX1                    ((uint16_t)0x0000<<0)       /*!<PC0_AF1:tx1             */
#if defined USE_GPIO_AF_PRIORITY
#define PC0_INT3                   ((uint16_t)0x0001<<0)       /*!<PC0_AF2:int3            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC0_TMR0                   ((uint32_t)0x00010000<<0)   /*!<PC0_AF3:tmr0            */
#endif
#define PC1_RX1                    ((uint16_t)0x0000<<1)       /*!<PC1_AF1:rx1             */
#if defined USE_GPIO_AF_PRIORITY
#define PC1_INT6                   ((uint16_t)0x0001<<1)       /*!<PC1_AF2:int6            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TMR_DEADZONE
#define PC1_TMR0N                  ((uint32_t)0x00010000<<1)   /*!<PC1_AF3:tmr0n           */
#endif
#define PC2_RX0                    ((uint16_t)0x0000<<2)       /*!<PC2_AF1:rx0             */
#if defined  USE_EXTI_INT7
#define PC2_INT7                   ((uint16_t)0x0001<<2)       /*!<PC2_AF2:int7            */
#endif
#define PC3_TX0                    ((uint16_t)0x0000<<3)       /*!<PC3_AF1:tx0             */
#if defined USE_TMR_DEADZONE
#define PC3_TMR2N                  ((uint16_t)0x0001<<3)       /*!<PC3_AF2:tmr2n           */
#endif
#define PC4_SPIMOSI                ((uint16_t)0x0000<<4)       /*!<PC4_AF1:spi0_mosi       */
#define PC4_SPI0_MOSI              ((uint16_t)0x0000<<4)       /*!<PC4_AF1:spi0_mosi       */
#define PC4_RX5                    ((uint16_t)0x0001<<4)       /*!<PC4_AF2:rx5             */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC4_TMR1                   ((uint32_t)0x00010000<<4)   /*!<PC4_AF3:tmr1            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC4_SDA                    ((uint32_t)0x00010001<<4)   /*!<PC4_AF4:sda             */
#endif
#define PC5_SPIMISO                ((uint16_t)0x0000<<5)       /*!<PC5_AF1:spi0_miso       */
#define PC5_SPI0_MISO              ((uint16_t)0x0000<<5)       /*!<PC5_AF1:spi0_miso       */
#define PC5_TX5                    ((uint16_t)0x0001<<5)       /*!<PC5_AF2:tx5             */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TMR_DEADZONE
#define PC5_TMR1N                  ((uint32_t)0x00010000<<5)   /*!<PC5_AF3:tmr1n           */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC5_SCL                    ((uint32_t)0x00010001<<5)   /*!<PC5_AF4:scl             */
#endif
#define PC6_SPICLK                 ((uint16_t)0x0000<<6)       /*!<PC6_AF1:spi0_clk        */
#define PC6_SPI0_CLK               ((uint16_t)0x0000<<6)       /*!<PC6_AF1:spi0_clk        */
#if defined USE_GPIO_AF_PRIORITY
#define PC6_TX1                    ((uint16_t)0x0001<<6)       /*!<PC6_AF2:tx1             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC6_TMR2                   ((uint32_t)0x00010000<<6)   /*!<PC6_AF3:tmr2            */
#endif
#define PC7_SPICS                  ((uint16_t)0x0000<<7)       /*!<PC7_AF1:spi0_cs         */
#define PC7_SPI0_CS                ((uint16_t)0x0000<<7)       /*!<PC7_AF1:spi0_cs         */
#if defined USE_GPIO_AF_PRIORITY
#define PC7_RX1                    ((uint16_t)0x0001<<7)       /*!<PC7_AF2:rx1             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TMR_DEADZONE
#define PC7_TMR2N                  ((uint32_t)0x00010000<<7)   /*!<PC7_AF3:tmr2n           */
#endif
#define PC8_TOUT1                  ((uint16_t)0x0000<<8)       /*!<PC8_AF1:tout1           */
#if defined USE_GPIO_AF_PRIORITY & defined USE_EXTI_INT9
#define PC8_INT9                   ((uint16_t)0x0001<<8)       /*!<PC8_AF2:int9            */
#endif
#define PC9_TMR2                   ((uint16_t)0x0000<<9)       /*!<PC9_AF1:tmr2            */
#if defined USE_LCD_SEG42_55
#define PC9_SEG44                  ((uint16_t)0x0001<<9)       /*!<PC9_AF2:seg44           */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC9_INT4                   ((uint32_t)0x00010000<<9)   /*!<PC9_AF3:int4            */
#endif
#define PC10_TMR3                  ((uint16_t)0x0000<<10)      /*!<PC10_AF1:tmr3           */
#if defined USE_LCD_SEG42_55
#define PC10_SEG45                 ((uint16_t)0x0001<<10)      /*!<PC10_AF2:seg45          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_EXTI_INT7
#define PC10_INT7                  ((uint32_t)0x00010000<<10)  /*!<PC10_AF3:int7           */
#endif
#define PC11_TX2                   ((uint16_t)0x0000<<11)      /*!<PC11_AF1:tx2            */
#if defined USE_LCD_SEG42_55
#define PC11_SEG46                 ((uint16_t)0x0001<<11)      /*!<PC11_AF2:seg46          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_EXTI_INT12
#define PC11_INT12                 ((uint32_t)0x00010000<<11)  /*!<PC11_AF3:int12          */
#endif
#define PC12_RX2                   ((uint16_t)0x0000<<12)      /*!<PC12_AF1:rx2            */
#if defined USE_LCD_SEG42_55
#define PC12_SEG47                 ((uint16_t)0x0001<<12)      /*!<PC12_AF2:seg47          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_EXTI_INT13
#define PC12_INT13                 ((uint32_t)0x00010000<<12)  /*!<PC12_AF3:int13          */
#endif
#define PC13_SCL                   ((uint16_t)0x0000<<13)      /*!<PC13_AF1:scl            */
#if defined USE_GPIO_AF_PRIORITY & defined USE_EMU_CONST
#define PC13_PFOUT                 ((uint16_t)0x0001<<13)      /*!<PC13_AF2:pfout          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC13_INT0                  ((uint32_t)0x00010000<<13)  /*!<PC13_AF3:int0           */
#endif
#define PC14_SDA                   ((uint16_t)0x0000<<14)      /*!<PC14_AF1:sda            */
#if defined USE_TMR_DEADZONE
#define PC14_TMR0N                 ((uint16_t)0x0001<<14)      /*!<PC14_AF2:tmr0n          */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY
#define PC14_INT1                  ((uint32_t)0x00010000<<14)  /*!<PC14_AF3:int1           */
#endif

/*!< HT_GPIOD  */
#define PD0_SEG16                  ((uint16_t)0x0000<<0)       /*!<PD0_AF1:seg16           */
#define PD1_SEG17                  ((uint16_t)0x0000<<1)       /*!<PD1_AF1:seg17           */
#define PD2_SEG18                  ((uint16_t)0x0000<<2)       /*!<PD2_AF1:seg18           */
#define PD3_SEG19                  ((uint16_t)0x0000<<3)       /*!<PD3_AF1:seg19           */
#if defined USE_TBS_ADCIN8
#define PD3_ADCIN8                 ((uint16_t)0x0001<<3)       /*!<PD3_AF2:adcin8          */
#endif
#define PD4_SEG20                  ((uint16_t)0x0000<<4)       /*!<PD4_AF1:seg20           */
#if defined USE_PMU_LVDIN1 & defined USE_PMU_LVDINN
#define PD4_LVDIN1N                ((uint16_t)0x0001<<4)       /*!<PD4_AF2:lvdin1n         */
#endif
#define PD5_SEG21                  ((uint16_t)0x0000<<5)       /*!<PD5_AF1:seg21           */
#define PD6_SEG22                  ((uint16_t)0x0000<<6)       /*!<PD6_AF1:seg22           */
#if defined USE_EXTI_INT10
#define PD6_INT10                  ((uint16_t)0x0001<<6)       /*!<PD6_AF2:int10           */
#endif
#define PD7_SEG23                  ((uint16_t)0x0000<<7)       /*!<PD7_AF1:seg23           */
#if defined USE_EXTI_INT11
#define PD7_INT11                  ((uint16_t)0x0001<<7)       /*!<PD7_AF2:int11           */
#endif
#define PD8_COM0                   ((uint16_t)0x0000<<8)       /*!<PD8_AF1:com0            */
#if defined USE_GPIO_AF_PRIORITY
#define PD8_RX2                    ((uint16_t)0x0001<<8)       /*!<PD8_AF2:rx2             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI3
#define PD8_SPI3_CS                ((uint32_t)0x00010000<<8)   /*!<PD8_AF3:spi3_cs         */
#endif
#define PD9_COM1                   ((uint16_t)0x0000<<9)       /*!<PD9_AF1:com1            */
#if defined USE_GPIO_AF_PRIORITY
#define PD9_TX2                    ((uint16_t)0x0001<<9)       /*!<PD9_AF2:tx2             */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI3
#define PD9_SPI3_CLK               ((uint32_t)0x00010000<<9)   /*!<PD9_AF3:spi3_clk        */
#endif
#define PD10_COM2                  ((uint16_t)0x0000<<10)      /*!<PD10_AF1:com2           */
#if defined USE_GPIO_AF_PRIORITY
#define PD10_RX4                   ((uint16_t)0x0001<<10)      /*!<PD10_AF2:rx4            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI3
#define PD10_SPI3_MISO             ((uint32_t)0x00010000<<10)  /*!<PD10_AF3:spi3_miso      */
#endif
#define PD11_COM3                  ((uint16_t)0x0000<<11)      /*!<PD11_AF1:com3           */
#if defined USE_GPIO_AF_PRIORITY
#define PD11_TX4                   ((uint16_t)0x0001<<11)      /*!<PD11_AF2:tx4            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI3
#define PD11_SPI3_MOSI             ((uint32_t)0x00010000<<11)  /*!<PD11_AF3:spi3_mosi      */
#endif
#define PD12_COM4                  ((uint16_t)0x0000<<12)      /*!<PD12_AF1:com4           */
#define PD12_SEG24                 ((uint16_t)0x0001<<12)      /*!<PD12_AF2:seg24          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI2
#define PD12_SPI2_MOSI             ((uint32_t)0x00010000<<12)  /*!<PD12_AF3:spi2_mosi      */
#endif
#define PD13_COM5                  ((uint16_t)0x0000<<13)      /*!<PD13_AF1:com5           */
#define PD13_SEG25                 ((uint16_t)0x0001<<13)      /*!<PD13_AF2:seg25          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI2
#define PD13_SPI2_MISO             ((uint32_t)0x00010000<<13)  /*!<PD13_AF3:spi2_miso      */
#endif
#define PD14_COM6                  ((uint16_t)0x0000<<14)      /*!<PD14_AF1:com6           */
#define PD14_SEG26                 ((uint16_t)0x0001<<14)      /*!<PD14_AF2:seg26          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI2
#define PD14_SPI2_CLK              ((uint32_t)0x00010000<<14)  /*!<PD14_AF3:spi2_clk       */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_LPUART
#define PD14_LPTX0                 ((uint32_t)0x00010001<<14)  /*!<PD14_AF4:lptx0          */
#endif
#define PD15_COM7                  ((uint16_t)0x0000<<15)      /*!<PD15_AF1:com7           */
#define PD15_SEG27                 ((uint16_t)0x0001<<15)      /*!<PD15_AF2:seg27          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_SPI_SPI2
#define PD15_SPI2_CS               ((uint32_t)0x00010000<<15)  /*!<PD15_AF3:spi2_cs        */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_LPUART
#define PD15_LPRX0                 ((uint32_t)0x00010001<<15)  /*!<PD15_AF4:lprx0          */
#endif

/*!< HT_GPIOE  */
#define PE0_TMR0                   ((uint16_t)0x0000<<0)       /*!<PE0_AF1:tmr0            */
#if defined USE_GPIO_AF_PRIORITY & defined USE_EMU_CONST
#define PE0_QFOUT                  ((uint16_t)0x0001<<0)       /*!<PE0_AF2:qfout           */
#endif
#define PE1_TX4                    ((uint16_t)0x0000<<1)       /*!<PE1_AF1:tx4             */
#define PE1_TOUT2                  ((uint16_t)0x0001<<1)       /*!<PE1_AF2:tout2           */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_LPUART
#define PE1_LPTX0                  ((uint32_t)0x00010000<<1)   /*!<PE1_AF3:lptx0           */
#endif
#define PE2_RX4                    ((uint16_t)0x0000<<2)       /*!<PE2_AF1:rx4             */
#define PE2_7816_0                 ((uint16_t)0x0001<<2)       /*!<PE2_AF2:7816_0          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_UART_LPUART
#define PE2_LPRX0                  ((uint32_t)0x00010000<<2)   /*!<PE2_AF3:lprx0           */
#endif
#define PE3_CLKOUT                 ((uint16_t)0x0000<<3)       /*!<PE3_AF1:clkout          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TBS_ADCIN7
#define PE3_ADCIN7                 ((uint32_t)0x00010000<<3)   /*!<PE3_AF3:adcin7          */
#endif
#define PE4_RX3                    ((uint16_t)0x0000<<4)       /*!<PE4_AF1:rx3             */
#define PE4_7816_1                 ((uint16_t)0x0001<<4)       /*!<PE4_AF2:7816_1          */
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TBS_ADCIN6
#define PE4_ADCIN6                 ((uint32_t)0x00010001<<4)   /*!<PE4_AF4:adcin6          */
#endif
#define PE5_TX3                    ((uint16_t)0x0000<<5)       /*!<PE5_AF1:tx3             */
#if defined USE_TBS_ADCIN3 & defined USE_GPIO_VER_K
#define PE5_ADCIN3                 ((uint16_t)0x0001<<5)       /*!<PE5_AF2:adcin3          */
#endif
#if defined USE_GPIO_AF_PRIORITY
#define PE5_INT2                   ((uint16_t)0x0001<<5)       /*!<PE5_AF2:int2            */
#endif
#if defined USE_GPIO_AF34 & defined USE_GPIO_AF_PRIORITY & defined USE_TBS_ADCIN3
#define PE5_ADCIN3                 ((uint32_t)0x00010000<<5)   /*!<PE5_AF3:adcin3          */
#endif
#define PE6_TMR1                   ((uint16_t)0x0000<<6)       /*!<PE6_AF1:tmr1            */
#if defined USE_TBS_ADCIN3 & defined USE_GPIO_VER_K
#define PE6_ADCIN4                 ((uint16_t)0x0001<<6)       /*!<PE6_AF2:adcin4          */
#endif
#define PE7_LVDIN0                 ((uint16_t)0x0000<<7)       /*!<PE7_AF1:lvdin0          */
#if defined USE_POWIN
#define PE8_POWIN                  ((uint16_t)0x0000<<8)       /*!<PE8_AF1:powin           */
#endif
#if defined USE_EXTI_INT8 & (defined USE_GPIO_VER_K  ||  defined USE_GPIO_VER_M3)
#define PE8_INT8                   ((uint16_t)0x0000<<8)       /*!<PE8_AF1:int8            */
#endif
#if defined USE_PMU_LVDIN2
#define PE8_LVDIN2                 ((uint16_t)0x0001<<8)       /*!<PE8_AF2:lvdin2          */
#endif
#if defined USE_TMR_TMR4 & defined USE_GPIO_VER_K
#define PE8_TMR4                   ((uint16_t)0x0001<<8)       /*!<PE8_AF2:tmr4            */
#endif

/*!< HT_GPIOG  */
#if defined USE_GPIO_GPIOG
#if defined USE_LCD_SEG37_41 & (!defined USE_GPIO_VER_K)
#define PG0_SEG37                  ((uint16_t)0x0000<<0)       /*!<PG0_AF1:seg37           */
#endif
#if defined USE_LCD_SEG37_41 & (!defined USE_GPIO_VER_K)
#define PG1_SEG38                  ((uint16_t)0x0000<<1)       /*!<PG1_AF1:seg38           */
#endif
#if defined USE_LCD_SEG37_41 & (!defined USE_GPIO_VER_K)
#define PG2_SEG39                  ((uint16_t)0x0000<<2)       /*!<PG2_AF1:seg39           */
#endif
#if defined USE_TBS_ADCIN3 & (!defined USE_GPIO_VER_K)
#define PG2_ADCIN3                 ((uint16_t)0x0001<<2)       /*!<PG2_AF2:adcin3          */
#endif
#if defined USE_LCD_SEG37_41 & (!defined USE_GPIO_VER_K)
#define PG3_SEG40                  ((uint16_t)0x0000<<3)       /*!<PG3_AF1:seg40           */
#endif
#if defined USE_TBS_ADCIN4 & (!defined USE_GPIO_VER_K)
#define PG3_ADCIN4                 ((uint16_t)0x0001<<3)       /*!<PG3_AF2:adcin4          */
#endif
#if defined USE_LCD_SEG37_41 & (!defined USE_GPIO_VER_K)
#define PG4_SEG41                  ((uint16_t)0x0000<<4)       /*!<PG4_AF1:seg41           */
#endif
#if defined USE_TBS_ADCIN5 & (!defined USE_GPIO_VER_K)
#define PG4_ADCIN5                 ((uint16_t)0x0001<<4)       /*!<PG4_AF2:adcin5          */
#endif
#if defined USE_PMU_LVDIN1
#define PG5_LVDIN1                 ((uint16_t)0x0000<<5)       /*!<PG5_AF1:lvdin1          */
#endif
#if defined USE_SPI_SPI1
#define PG6_SPI1_CS                ((uint16_t)0x0000<<6)       /*!<PG6_AF1:spi1_cs         */
#endif
#if defined USE_SPI_SPI1
#define PG7_SPI1_CLK               ((uint16_t)0x0000<<7)       /*!<PG7_AF1:spi1_clk        */
#endif
#if defined USE_SPI_SPI1
#define PG8_SPI1_MISO              ((uint16_t)0x0000<<8)       /*!<PG8_AF1:spi1_miso       */
#endif
#if defined USE_SPI_SPI1
#define PG9_SPI1_MOSI              ((uint16_t)0x0000<<9)       /*!<PG9_AF1:spi1_mosi       */
#endif
#if defined USE_UART_UART6
#define PG11_RX6                   ((uint16_t)0x0000<<11)      /*!<PG11_AF1:rx6            */
#endif
#if defined USE_UART_UART6
#define PG12_TX6                   ((uint16_t)0x0000<<12)      /*!<PG12_AF1:tx6            */
#endif
#if defined USE_LCD_SEG42_55
#define PG13_SEG42                 ((uint16_t)0x0000<<13)      /*!<PG13_AF1:seg42          */
#endif
#if defined USE_LCD_SEG42_55
#define PG14_SEG43                 ((uint16_t)0x0000<<14)      /*!<PG14_AF1:seg43          */
#endif
#endif

/*!< HT_GPIOH  */
#if defined USE_GPIO_GPIOH
#if defined USE_TMR_TMR4
#define PH0_TMR4                   ((uint16_t)0x0000<<0)       /*!<PH0_AF1:tmr4            */
#endif
#if defined USE_TMR_TMR5
#define PH1_TMR5                   ((uint16_t)0x0000<<1)       /*!<PH1_AF1:tmr5            */
#endif
#if defined USE_EXTI_INT8
#define PH2_INT8                   ((uint16_t)0x0000<<2)       /*!<PH2_AF1:int8            */
#endif
#if defined USE_EXTI_INT9
#define PH3_INT9                   ((uint16_t)0x0000<<3)       /*!<PH3_AF1:int9            */
#endif
#if defined USE_TMR_DEADZONE & (!defined UNUSE_TMR_PH4_DEADZONE)
#define PH4_TMR3N                  ((uint16_t)0x0000<<4)       /*!<PH4_AF1:tmr3n           */
#endif
#endif

/*!< HT_GPIOI  */
#if defined USE_GPIO_GPIOI
#if defined USE_LCD_SEG42_55
#define PI0_SEG48                  ((uint16_t)0x0000<<0)       /*!<PI0_AF1:seg48           */
#endif
#if defined USE_LCD_SEG42_55
#define PI1_SEG49                  ((uint16_t)0x0000<<1)       /*!<PI1_AF1:seg49           */
#endif
#if defined USE_LCD_SEG42_55
#define PI2_SEG50                  ((uint16_t)0x0000<<2)       /*!<PI2_AF1:seg50           */
#endif
#if defined USE_LCD_SEG42_55
#define PI3_SEG51                  ((uint16_t)0x0000<<3)       /*!<PI3_AF1:seg51           */
#endif
#if defined USE_LCD_SEG42_55
#define PI4_SEG52                  ((uint16_t)0x0000<<4)       /*!<PI4_AF1:seg52           */
#endif
#if defined USE_LCD_SEG42_55
#define PI5_SEG53                  ((uint16_t)0x0000<<5)       /*!<PI5_AF1:seg53           */
#endif
#if defined USE_LCD_SEG42_55
#define PI6_SEG54                  ((uint16_t)0x0000<<6)       /*!<PI6_AF1:seg54           */
#endif
#if defined USE_LCD_SEG42_55
#define PI7_SEG55                  ((uint16_t)0x0000<<7)       /*!<PI7_AF1:seg55           */
#endif
#if defined USE_TMR_DEADZONE
#define PI8_TMR3N                  ((uint16_t)0x0000<<8)       /*!<PI8_AF1:tmr3n           */
#endif
#endif
#endif   /*!< end of define USE_MCU  */

#if defined USE_SOC
#define PA0_SEG28                  ((uint16_t)0x0000<<0)       /*!< PA0_AF1: seg28         */
#define PA1_SEG29                  ((uint16_t)0x0000<<1)       /*!< PA1_AF1: seg29         */
#define PA2_SEG30                  ((uint16_t)0x0000<<2)       /*!< PA2_AF1: seg30         */
#define PA3_SEG31                  ((uint16_t)0x0000<<3)       /*!< PA3_AF1: seg31         */
#define PA4_SEG32                  ((uint16_t)0x0000<<4)       /*!< PA4_AF1: seg32         */
#define PA5_INT0                   ((uint16_t)0x0000<<5)       /*!< PA5_AF1: int0          */
#define PA5_SCANIN0                ((uint16_t)0x0001<<5)       /*!< PA5_AF2: scanin0       */
#if defined USE_GPIO_AF34
#if defined USE_TBS_ADCIN3
#define PA5_ADCIN3                 ((uint32_t)0x00010000<<5)   /*!< PA5_AF3: adcin3        */
#endif
#endif
#define PA6_INT1                   ((uint16_t)0x0000<<6)       /*!< PA6_AF1: int1          */
#define PA6_SCANIN1                ((uint16_t)0x0001<<6)       /*!< PA6_AF2: scanin1       */
#define PA7_INT2                   ((uint16_t)0x0000<<7)       /*!< PA7_AF1: int2          */
#define PA7_SEG33                  ((uint16_t)0x0001<<7)       /*!< PA7_AF2: seg33         */
#define PA8_INT3                   ((uint16_t)0x0000<<8)       /*!< PA8_AF1: int3          */
#define PA8_SEG34                  ((uint16_t)0x0001<<8)       /*!< PA8_AF2: seg34         */
#if defined USE_GPIO_AF34
#if defined USE_TBS_ADCIN6
#define PA8_ADCIN6                 ((uint32_t)0x00010001<<8)   /*!< PA5_AF3: adcin3        */
#endif
#endif
#define PA9_INT4                   ((uint16_t)0x0000<<9)       /*!< PA9_AF1: int4          */
#define PA10_INT5                  ((uint16_t)0x0000<<10)      /*!< PA10_AF1: int5         */
#define PA11_INT6                  ((uint16_t)0x0000<<11)      /*!< PA11_AF1: int6         */
#define PA11_SEG50                 ((uint16_t)0x0001<<11)      /*!< PA11_AF2: seg50        */
#define PA12_SEG35                 ((uint16_t)0x0000<<12)      /*!< PA12_AF1: seg35        */
#define PA12_ADCIN0                ((uint16_t)0x0001<<12)      /*!< PA12_AF2: adcin0       */
#define PA13_SEG36                 ((uint16_t)0x0000<<13)      /*!< PA13_AF1: seg36        */
#define PA13_ADCIN1                ((uint16_t)0x0001<<13)      /*!< PA13_AF2: adcin1       */

#define PB0_SEG0                   ((uint16_t)0x0000<<0)       /*!< PB0_AF1: seg0          */
#if defined USE_LCD_CHARGEPUMP & defined USE_LCD_VLCDNP
#define PB0_VLCDCP                 ((uint16_t)0x0001<<0)       /*!< PB0_AF2: vlcdcp        */
#endif
#if defined USE_GPIO_AF34
#if defined USE_UART_UART6
#define PB0_RX6                    ((uint32_t)0x00010000<<0)   /*!< PB0_AF3: rx6           */
#endif
#endif
#define PB1_SEG1                   ((uint16_t)0x0000<<1)       /*!< PB1_AF1: seg1          */
#if defined USE_LCD_CHARGEPUMP & defined USE_LCD_VLCDNP
#define PB1_VLCDCN                 ((uint16_t)0x0001<<1)       /*!< PB1_AF2: vlcdcn        */
#endif
#if defined USE_GPIO_AF34
#if defined USE_UART_UART6
#define PB1_TX6                    ((uint32_t)0x00010000<<1)   /*!< PB1_AF3: tx6           */
#endif
#endif
#define PB2_SEG2                   ((uint16_t)0x0000<<2)       /*!< PB2_AF1: seg2          */
#if defined USE_LCD_CHARGEPUMP
#define PB2_VLCD0                  ((uint16_t)0x0001<<2)       /*!< PB2_AF2: vlcd0         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PB2_SPI1_MOSI              ((uint32_t)0x00010000<<2)   /*!< PB2_AF3: spi1_mosi     */
#endif
#endif
#define PB3_SEG3                   ((uint16_t)0x0000<<3)       /*!< PB3_AF1: seg3          */
#if defined USE_LCD_CHARGEPUMP
#define PB3_VLCD1                  ((uint16_t)0x0001<<3)       /*!< PB3_AF2: vlcd1         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PB3_SPI1_MISO              ((uint32_t)0x00010000<<3)   /*!< PB3_AF3: spi1_miso     */
#endif
#endif
#define PB4_SEG4                   ((uint16_t)0x0000<<4)       /*!< PB4_AF1: seg4          */
#if defined USE_LCD_CHARGEPUMP
#define PB4_VLCD2                  ((uint16_t)0x0001<<4)       /*!< PB4_AF2: vlcd2         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PB4_SPI1_CLK               ((uint32_t)0x00010000<<4)   /*!< PB4_AF3: spi1_clk      */
#endif
#endif
#define PB5_SEG5                   ((uint16_t)0x0000<<5)       /*!< PB5_AF1: seg5          */
#if defined USE_LCD_CHARGEPUMP
#define PB5_VLCD3                  ((uint16_t)0x0001<<5)       /*!< PB5_AF2: vlcd3         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PB5_SPI1_CS                ((uint32_t)0x00010000<<5)   /*!< PB5_AF3: spi1_cs       */
#endif
#endif
#define PB6_SEG6                   ((uint16_t)0x0000<<6)       /*!< PB6_AF1: seg6          */
#define PB7_SEG7                   ((uint16_t)0x0000<<7)       /*!< PB7_AF1: seg7          */
#define PB8_SEG8                   ((uint16_t)0x0000<<8)       /*!< PB8_AF1: seg8          */
#define PB9_SEG9                   ((uint16_t)0x0000<<9)       /*!< PB9_AF1: seg9          */
#define PB10_SEG10                 ((uint16_t)0x0000<<10)      /*!< PB10_AF1: seg10        */
#define PB11_SEG11                 ((uint16_t)0x0000<<11)      /*!< PB11_AF1: seg11        */
#define PB12_SEG12                 ((uint16_t)0x0000<<12)      /*!< PB12_AF1: seg12        */
#if defined USE_EXTI_INT8
#define PB12_INT8                  ((uint16_t)0x0001<<12)      /*!< PB12_AF2: int8         */
#endif
#define PB13_SEG13                 ((uint16_t)0x0000<<13)      /*!< PB13_AF1: seg13        */
#define PB13_SWIO                  ((uint16_t)0x0001<<13)      /*!< PB13_AF2: swio         */
#define PB14_SEG14                 ((uint16_t)0x0000<<14)      /*!< PB14_AF1: seg14        */
#if defined USE_EXTI_INT9
#define PB14_INT9                  ((uint16_t)0x0001<<14)      /*!< PB14_AF2: int9         */
#endif
#define PB15_SEG15                 ((uint16_t)0x0000<<15)      /*!< PB15_AF1: seg15        */
#define PB15_SWCLK                 ((uint16_t)0x0001<<15)      /*!< PB15_AF2: swclk        */

#define PC0_TX1                    ((uint16_t)0x0000<<0)       /*!< PC0_AF1: tx1           */
#if defined USE_LCD_SEG43_53
#define PC0_SEG43                  ((uint16_t)0x0001<<0)       /*!< PC0_AF2: seg43         */
#endif
#if defined USE_GPIO_AF34
#define PC0_SCL                    ((uint32_t)0x00010000<<0)   /*!< PC0_AF3: scl           */
#endif
#define PC1_RX1                    ((uint16_t)0x0000<<1)       /*!< PC1_AF1: rx1           */
#if defined USE_LCD_SEG43_53
#define PC1_SEG44                  ((uint16_t)0x0001<<1)       /*!< PC1_AF2: seg44         */
#endif
#if defined USE_GPIO_AF34
#define PC1_SDA                    ((uint32_t)0x00010000<<1)   /*!< PC1_AF3: sda           */
#endif
#define PC2_RX0                    ((uint16_t)0x0000<<2)       /*!< PC2_AF1: rx0           */
#if defined USE_LCD_SEG43_53
#define PC2_SEG45                  ((uint16_t)0x0001<<2)       /*!< PC2_AF2: seg45         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_TBS_ADCIN4
#define PC2_ADCIN4                 ((uint32_t)0x00010000<<2)   /*!< PC2_AF3: adcin4        */
#endif
#endif
#define PC3_TX0                    ((uint16_t)0x0000<<3)       /*!< PC3_AF1: tx0           */
#if defined USE_LCD_SEG43_53
#define PC3_SEG46                  ((uint16_t)0x0001<<3)       /*!< PC3_AF2: seg46         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_TBS_ADCIN5
#define PC3_ADCIN5                 ((uint32_t)0x00010000<<3)   /*!< PC3_AF3: adcin5        */
#endif
#endif
#define PC4_SPI_MOSI               ((uint16_t)0x0000<<4)       /*!< PC4_AF1: spi_mosi      */
#define PC4_SPI0_MOSI              ((uint16_t)0x0000<<4)       /*!< PC4_AF1: spi0_mosi     */
#define PC4_RX5                    ((uint16_t)0x0001<<4)       /*!< PC4_AF2: rx5           */
#define PC5_SPI_MISO               ((uint16_t)0x0000<<5)       /*!< PC5_AF1: spi_miso      */
#define PC5_SPI0_MISO              ((uint16_t)0x0000<<5)       /*!< PC5_AF1: spi0_miso     */
#define PC5_TX5                    ((uint16_t)0x0001<<5)       /*!< PC5_AF2: tx5           */
#define PC6_SPI_CLK                ((uint16_t)0x0000<<6)       /*!< PC6_AF1: spi_clk       */
#define PC6_SPI0_CLK               ((uint16_t)0x0000<<6)       /*!< PC6_AF1: spi0_clk      */
#if defined USE_LCD_SEG43_53
#define PC6_SEG51                  ((uint16_t)0x0001<<6)       /*!< PC6_AF2: seg51         */
#endif
#define PC7_SPI_CS                 ((uint16_t)0x0000<<7)       /*!< PC7_AF1: spi_cs        */
#define PC7_SPI0_CS                ((uint16_t)0x0000<<7)       /*!< PC7_AF1: spi0_cs       */
#if defined USE_LCD_SEG43_53
#define PC7_SEG52                  ((uint16_t)0x0001<<7)       /*!< PC7_AF2: seg52         */
#endif
#define PC8_TOUT1                  ((uint16_t)0x0000<<8)       /*!< PC8_AF1: tout1         */
#if defined USE_EXTI_INT7
#define PC8_INT7                   ((uint16_t)0x0001<<8)       /*!< PC8_AF2: int7          */
#endif
#define PC9_TMR2                   ((uint16_t)0x0000<<9)       /*!< PC9_AF1: tmr2          */
#define PC9_SCANIN3                ((uint16_t)0x0001<<9)       /*!< PC9_AF2: scanin3       */
#define PC10_TMR3                  ((uint16_t)0x0000<<10)      /*!< PC10_AF1: tmr3         */
#define PC10_SCANIN2               ((uint16_t)0x0001<<10)      /*!< PC10_AF2: scanin2      */
#define PC11_TX2                   ((uint16_t)0x0000<<11)      /*!< PC11_AF1: tx2          */
#define PC12_RX2                   ((uint16_t)0x0000<<12)      /*!< PC12_AF1: rx2          */
#define PC13_SCL                   ((uint16_t)0x0000<<13)      /*!< PC13_AF1: scl          */
#define PC14_SDA                   ((uint16_t)0x0000<<14)      /*!< PC14_AF1: sda          */

#define PD0_SEG16                  ((uint16_t)0x0000<<0)       /*!< PD0_AF1: seg16         */
#define PD1_SEG17                  ((uint16_t)0x0000<<1)       /*!< PD1_AF1: seg17         */
#define PD2_SEG18                  ((uint16_t)0x0000<<2)       /*!< PD2_AF1: seg18         */
#define PD2_SCANOUT0               ((uint16_t)0x0001<<2)       /*!< PD2_AF2: scanout0      */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI2
#define PD2_SPI2_CS                ((uint32_t)0x00010000<<2)   /*!< PD2_AF3: spi2_cs       */
#endif
#endif
#define PD3_SEG19                  ((uint16_t)0x0000<<3)       /*!< PD3_AF1: seg19         */
#define PD3_SCANOUT1               ((uint16_t)0x0001<<3)       /*!< PD3_AF2: scanout1      */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI2
#define PD3_SPI2_CLK               ((uint32_t)0x00010000<<3)   /*!< PD3_AF3: spi2_clk      */
#endif
#endif
#define PD4_SEG20                  ((uint16_t)0x0000<<4)       /*!< PD4_AF1: seg20         */
#define PD4_SCANOUT2               ((uint16_t)0x0001<<4)       /*!< PD4_AF2: scanout2      */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI2
#define PD4_SPI2_MISO              ((uint32_t)0x00010000<<4)   /*!< PD4_AF3: spi2_miso     */
#endif
#endif
#define PD5_SEG21                  ((uint16_t)0x0000<<5)       /*!< PD5_AF1: seg21         */
#define PD5_SCANOUT3               ((uint16_t)0x0001<<5)       /*!< PD5_AF2: scanout3      */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI2
#define PD5_SPI2_MOSI              ((uint32_t)0x00010000<<5)   /*!< PD5_AF3: spi2_mosi     */
#endif
#endif
#define PD6_SEG22                  ((uint16_t)0x0000<<6)       /*!< PD6_AF1: seg22         */
#define PD7_SEG23                  ((uint16_t)0x0000<<7)       /*!< PD7_AF1: seg23         */
#define PD8_COM0                   ((uint16_t)0x0000<<8)       /*!< PD8_AF1: com0          */
#if defined USE_SPI_SPI2
#define PD8_SPI2_CS                ((uint16_t)0x0001<<8)       /*!< PD8_AF2: spi2_cs       */
#endif
#define PD9_COM1                   ((uint16_t)0x0000<<9)       /*!< PD9_AF1: com1          */
#if defined USE_SPI_SPI2
#define PD9_SPI2_CLK               ((uint16_t)0x0001<<9)       /*!< PD9_AF2: spi2_clk      */
#endif
#define PD10_COM2                  ((uint16_t)0x0000<<10)      /*!< PD10_AF1: com2         */
#if defined USE_SPI_SPI2
#define PD10_SPI2_MISO             ((uint16_t)0x0001<<10)      /*!< PD10_AF2: spi2_miso    */
#endif
#define PD11_COM3                  ((uint16_t)0x0000<<11)      /*!< PD11_AF1: com3         */
#if defined USE_SPI_SPI2
#define PD11_SPI2_MOSI             ((uint16_t)0x0001<<11)      /*!< PD11_AF2: spi2_mosi    */
#endif
#define PD12_COM4                  ((uint16_t)0x0000<<12)      /*!< PD12_AF1: com4         */
#define PD12_SEG24                 ((uint16_t)0x0001<<12)      /*!< PD12_AF2: seg24        */
#define PD13_COM5                  ((uint16_t)0x0000<<13)      /*!< PD13_AF1: com5         */
#define PD13_SEG25                 ((uint16_t)0x0001<<13)      /*!< PD13_AF2: seg25        */
#define PD14_COM6                  ((uint16_t)0x0000<<14)      /*!< PD14_AF1: com6         */
#define PD14_SEG26                 ((uint16_t)0x0001<<14)      /*!< PD14_AF2: seg26        */
#define PD15_COM7                  ((uint16_t)0x0000<<15)      /*!< PD15_AF1: com7         */
#define PD15_SEG27                 ((uint16_t)0x0001<<15)      /*!< PD15_AF2: seg27        */

#define PE0_TMR0                   ((uint16_t)0x0000<<0)       /*!< PE0_AF1: tmr0          */
#define PE1_TX4                    ((uint16_t)0x0000<<1)       /*!< PE1_AF1: tx4           */
#define PE1_TOUT2                  ((uint16_t)0x0001<<1)       /*!< PE1_AF2: tout2         */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PE1_SPI1_MOSI              ((uint32_t)0x00010000<<1)   /*!< PE1_AF3: spi1_mosi     */
#endif
#endif
#define PE2_RX4                    ((uint16_t)0x0000<<2)       /*!< PE2_AF1: rx4           */
#define PE2_7816_0                 ((uint16_t)0x0001<<2)       /*!< PE2_AF2: 7816_0        */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PE2_SPI1_MISO              ((uint32_t)0x00010000<<2)   /*!< PE2_AF3: spi1_miso     */
#endif
#endif
#define PE3_CLKOUT                 ((uint16_t)0x0000<<3)       /*!< PE3_AF1: clkout        */
#if defined USE_LCD_SEG43_53
#define PE3_SEG53                  ((uint16_t)0x0001<<3)       /*!< PE3_AF2: seg53         */
#endif
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PE3_SPI1_CLK               ((uint32_t)0x00010000<<3)   /*!< PE1_AF3: spi1_clk      */
#endif
#endif
#define PE4_RX3                    ((uint16_t)0x0000<<4)       /*!< PE4_AF1: rx3           */
#define PE4_7816_1                 ((uint16_t)0x0001<<4)       /*!< PE4_AF2: 7816_1        */
#if defined USE_GPIO_AF34
#if defined USE_SPI_SPI1
#define PE4_SPI1_CS                ((uint32_t)0x00010000<<4)   /*!< PE4_AF3: spi1_cs     */
#endif
#endif
#define PE5_TX3                    ((uint16_t)0x0000<<5)       /*!< PE5_AF1: tx3           */
#if defined USE_LCD_SEG43_53
#define PE5_SEG49                  ((uint16_t)0x0001<<5)       /*!< PE5_AF2: seg49         */
#endif
#define PE6_TMR1                   ((uint16_t)0x0000<<6)       /*!< PE6_AF1: tmr1          */
#define PE7_LVDIN0                 ((uint16_t)0x0000<<7)       /*!< PE7_AF1: lvdin0        */
#if defined USE_LCD_SEG43_53
#define PE7_SEG47                  ((uint16_t)0x0001<<7)       /*!< PE7_AF2: seg47         */
#endif
#define PE8_SEG37                  ((uint16_t)0x0000<<8)       /*!< PE8_AF1: seg37         */
#define PE8_ADCIN2                 ((uint16_t)0x0001<<8)       /*!< PE8_AF2: adcin2        */
#define PE9_LVDIN1                 ((uint16_t)0x0000<<9)       /*!< PE9_AF1: lvdin1        */

#define PF0_PFOUT                  ((uint16_t)0x0000<<0)       /*!< PF0_AF1: pfout         */
#if defined USE_RTC_TOUT3
#define PF0_TOUT3                  ((uint16_t)0x0001<<0)       /*!< PF0_AF2: tout3         */
#endif
#define PF1_QFOUT                  ((uint16_t)0x0000<<1)       /*!< PF1_AF1: qfout         */
#define PF2_SFOUT                  ((uint16_t)0x0000<<2)       /*!< PF2_AF1: sfout         */
#if defined USE_LCD_SEG43_53
#define PF2_SEG48                  ((uint16_t)0x0001<<2)       /*!< PF2_AF2: seg48         */
#endif
#define PF3_SEG38                  ((uint16_t)0x0000<<3)       /*!< PF3_AF1: seg38         */
#define PF4_SEG39                  ((uint16_t)0x0000<<4)       /*!< PF4_AF1: seg39         */
#define PF5_SEG40                  ((uint16_t)0x0000<<5)       /*!< PF5_AF1: seg40         */
#define PF6_SEG41                  ((uint16_t)0x0000<<6)       /*!< PF6_AF1: seg41         */
#define PF7_SEG42                  ((uint16_t)0x0000<<7)       /*!< PF7_AF1: seg42         */

#endif

#if defined USE_MCU_EMU
#define PA0_SPI2_CS                ((uint16_t)0x0000<<0)       /*!<PA0_AF1:spi2_cs         */
#define PA0_TMR1                   ((uint16_t)0x0001<<0)       /*!<PA0_AF2:tmr1            */
#define PA1_SPI2_CLK               ((uint16_t)0x0000<<1)       /*!<PA1_AF1:spi2_clk        */
#define PA1_TMR4                   ((uint16_t)0x0001<<1)       /*!<PA1_AF2:tmr4            */
#define PA2_SPI2_MISO              ((uint16_t)0x0000<<2)       /*!<PA2_AF1:spi2_miso       */
#define PA2_RX3                    ((uint16_t)0x0001<<2)       /*!<PA2_AF2:rx3             */
#define PA3_SPI2_MOSI              ((uint16_t)0x0000<<3)       /*!<PA3_AF1:spi2_mosi       */
#define PA3_TX3                    ((uint16_t)0x0001<<3)       /*!<PA3_AF2:tx3             */
#define PA5_PFOUT0                 ((uint16_t)0x0000<<5)       /*!<PA5_AF1:pfout0          */
#define PA5_INT8                   ((uint16_t)0x0001<<5)       /*!<PA5_AF2:int8            */
#define PA6_INT1                   ((uint16_t)0x0000<<6)       /*!<PA6_AF1:int1            */
#define PA7_INT2                   ((uint16_t)0x0000<<7)       /*!<PA7_AF1:int2            */
#define PA8_INT3                   ((uint16_t)0x0000<<8)       /*!<PA8_AF1:int3            */
#define PA9_INT4                   ((uint16_t)0x0000<<9)       /*!<PA9_AF1:int4            */
#define PA10_INT5                  ((uint16_t)0x0000<<10)      /*!<PA10_AF1:int5           */
#define PA11_INT6                  ((uint16_t)0x0000<<11)      /*!<PA11_AF1:int6           */
#define PA12_INT4                  ((uint16_t)0x0000<<12)      /*!<PA12_AF1:int4           */
#define PA12_ADCIN0                ((uint16_t)0x0001<<12)      /*!<PA12_AF2:adcin0         */
#define PA13_INT5                  ((uint16_t)0x0000<<13)      /*!<PA13_AF1:int5           */
#define PA13_ADCIN1                ((uint16_t)0x0001<<13)      /*!<PA13_AF2:adcin1         */
                                  
#define PB0_INT0                   ((uint16_t)0x0000<<0)       /*!<PB0_AF1:int0            */
#define PB1_PFOUT1                 ((uint16_t)0x0000<<1)       /*!<PB1_AF1:pfout1          */
#define PB2_PFOUT2                 ((uint16_t)0x0000<<2)       /*!<PB2_AF1:pfout2          */
#define PB2_INT9                   ((uint16_t)0x0001<<2)       /*!<PB2_AF2:int9            */
#define PB3_PFOUT3                 ((uint16_t)0x0000<<3)       /*!<PB3_AF1:pfout3          */
#define PB3_TOUT3                  ((uint16_t)0x0001<<3)       /*!<PB3_AF2:tout3           */
#define PB13_TX6                   ((uint16_t)0x0000<<13)      /*!<PB13_AF1:tx6            */
#define PB13_SWIO                  ((uint16_t)0x0001<<13)      /*!<PB13_AF2:swio           */
#define PB15_RX6                   ((uint16_t)0x0000<<15)      /*!<PB15_AF1:rx6            */
#define PB15_SWCLK                 ((uint16_t)0x0001<<15)      /*!<PB15_AF2:swclk          */
                                  
#define PC0_TX1                    ((uint16_t)0x0000<<0)       /*!<PC0_AF1:tx1             */
#define PC1_RX1                    ((uint16_t)0x0000<<1)       /*!<PC1_AF1:rx1             */
#define PC2_RX0                    ((uint16_t)0x0000<<2)       /*!<PC2_AF1:rx0             */
#define PC2_INT7                   ((uint16_t)0x0001<<2)       /*!<PC2_AF2:int7            */
#define PC3_TX0                    ((uint16_t)0x0000<<3)       /*!<PC3_AF1:tx0             */
#define PC4_SPI0_MOSI              ((uint16_t)0x0000<<4)       /*!<PC4_AF1:spi0_mosi       */
#define PC4_RX5                    ((uint16_t)0x0001<<4)       /*!<PC4_AF2:rx5             */
#define PC5_SPI0_MISO              ((uint16_t)0x0000<<5)       /*!<PC5_AF1:spi0_miso       */
#define PC5_TX5                    ((uint16_t)0x0001<<5)       /*!<PC5_AF2:tx5             */
#define PC6_SPI0_CLK               ((uint16_t)0x0000<<6)       /*!<PC6_AF1:spi0_clk        */
#define PC7_SPI0_CS                ((uint16_t)0x0000<<7)       /*!<PC7_AF1:spi0_cs         */
#define PC8_TOUT1                  ((uint16_t)0x0000<<8)       /*!<PC8_AF1:tout1           */
#define PC8_INT2                   ((uint16_t)0x0001<<8)       /*!<PC8_AF2:int2            */
#define PC9_TMR2                   ((uint16_t)0x0000<<9)       /*!<PC9_AF1:tmr2            */
#define PC10_TMR3                  ((uint16_t)0x0000<<10)      /*!<PC10_AF1:tmr3           */
#define PC11_TX2                   ((uint16_t)0x0000<<11)      /*!<PC11_AF1:tx2            */
#define PC12_RX2                   ((uint16_t)0x0000<<12)      /*!<PC12_AF1:rx2            */
#define PC13_SCL                   ((uint16_t)0x0000<<13)      /*!<PC13_AF1:scl            */
#define PC13_INT3                  ((uint16_t)0x0001<<13)      /*!<PC13_AF2:int3           */
#define PC14_SDA                   ((uint16_t)0x0000<<14)      /*!<PC14_AF1:sda            */
#define PC14_TMR3                  ((uint16_t)0x0001<<14)      /*!<PC14_AF2:tmr3           */
                                  
#define PD8_SPI3_CS                ((uint16_t)0x0000<<8)       /*!<PD8_AF1:spi3_cs         */
#define PD9_SPI3_CLK               ((uint16_t)0x0000<<9)       /*!<PD9_AF1:spi3_clk        */
#define PD10_SPI3_MISO             ((uint16_t)0x0000<<10)      /*!<PD10_AF1:spi3_miso      */
#define PD10_TX2                   ((uint16_t)0x0001<<10)      /*!<PD10_AF2:tx2            */
#define PD11_SPI3_MOSI             ((uint16_t)0x0000<<11)      /*!<PD11_AF1:spi3_mosi      */
#define PD11_RX2                   ((uint16_t)0x0001<<11)      /*!<PD11_AF2:rx2            */
#define PD12_TMR5                  ((uint16_t)0x0000<<12)      /*!<PD12_AF1:tmr5           */
                                  
#define PE0_TMR0                   ((uint16_t)0x0000<<0)       /*!<PE0_AF1:tmr0            */
#define PE1_TX4                    ((uint16_t)0x0000<<1)       /*!<PE1_AF1:tx4             */
#define PE1_TOUT2                  ((uint16_t)0x0001<<1)       /*!<PE1_AF2:tout2           */
#define PE2_RX4                    ((uint16_t)0x0000<<2)       /*!<PE2_AF1:rx4             */
#define PE2_7816_0                 ((uint16_t)0x0001<<2)       /*!<PE2_AF2:7816_0          */
#define PE3_CLKOUT                 ((uint16_t)0x0000<<3)       /*!<PE3_AF1:clkout          */
#define PE3_PFOUT4                 ((uint16_t)0x0001<<3)       /*!<PE3_AF2:pfout4          */
#define PE4_RX3                    ((uint16_t)0x0000<<4)       /*!<PE4_AF1:rx3             */
#define PE4_7816_1                 ((uint16_t)0x0001<<4)       /*!<PE4_AF2:7816_1          */
#define PE5_TX3                    ((uint16_t)0x0000<<5)       /*!<PE5_AF1:tx3             */
#define PE5_ADCIN3                 ((uint16_t)0x0001<<5)       /*!<PE5_AF2:adcin3          */
#define PE6_TMR1                   ((uint16_t)0x0000<<6)       /*!<PE6_AF1:tmr1            */
#define PE6_ADCIN4                 ((uint16_t)0x0001<<6)       /*!<PE6_AF2:adcin4          */
#define PE7_LVDIN0                 ((uint16_t)0x0000<<7)       /*!<PE7_AF1:lvdin0          */
#define PE7_ADCIN5                 ((uint16_t)0x0001<<7)       /*!<PE7_AF2:adcin5          */
#define PE8_INT8                   ((uint16_t)0x0000<<8)       /*!<PE8_AF1:int8            */
#define PE8_TMR4                   ((uint16_t)0x0001<<8)       /*!<PE8_AF2:tmr4            */
                                  
#define PG5_LVDIN1                 ((uint16_t)0x0000<<5)       /*!<PG5_AF1:lvdin1          */
#define PG5_TMR0                   ((uint16_t)0x0001<<5)       /*!<PG5_AF2:tmr0            */
#define PG6_SPI1_CS                ((uint16_t)0x0000<<6)       /*!<PG6_AF1:spi1_cs         */
#define PG7_SPI1_CLK               ((uint16_t)0x0000<<7)       /*!<PG7_AF1:spi1_clk        */
#define PG8_SPI1_MISO              ((uint16_t)0x0000<<8)       /*!<PG8_AF1:spi1_miso       */
#define PG8_TX1                    ((uint16_t)0x0001<<8)       /*!<PG8_AF2:tx1             */
#define PG9_SPI1_MOSI              ((uint16_t)0x0000<<9)       /*!<PG9_AF1:spi1_mosi       */
#define PG9_RX1                    ((uint16_t)0x0001<<9)       /*!<PG9_AF2:rx1             */
                                  
#define PJ0_STAMP0                 ((uint16_t)0x0000<<0)       /*!<PJ0_AF1:stamp0          */
#define PJ0_INT9                   ((uint16_t)0x0001<<0)       /*!<PJ0_AF2:int9            */
#define PJ1_STAMP1                 ((uint16_t)0x0000<<1)       /*!<PJ1_AF1:stamp1          */

#endif

/*
*********************************************************************************************************
*                                           Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      Global Function Declaration
*********************************************************************************************************
*/

void HT_GPIO_Init(HT_GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void HT_GPIO_AFInit(HT_GPIO_TypeDef* GPIOx, GPIO_InitAFTypeDef* GPIO_InitAFStruct);
void HT_GPIO_BitsSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HT_GPIO_BitsReset(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HT_GPIO_BitsToggle(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t HT_GPIO_BitsRead(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HT_GPIO_HighCurrentSet(uint16_t GPIO_Pin, FunctionalState NewState);
void HT_GPIO_DirectionSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_Direction);
void HT_GPIO_InputStatusSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_InputStatus);
void HT_GPIO_OutputStatusSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_OutputStatus);
#if defined USE_GPIO_FILT
void HT_GPIO_InputFilter(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_InputFilter);
#endif
#if defined USE_GPIO_NEWAFEN
void HT_GPIO_NewAFCtrl(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_NewAFCtrl);
#endif
#if defined USE_GPIO_HIIPM
void HT_GPIO_High_Resistance_Set(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_HighResistance);
#endif


#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_GPIO_H__ */
