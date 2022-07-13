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
* File         : ht6xxx_lib.h
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_LIB_H__
#define __HT6XXX_LIB_H__

#ifdef __cplusplus
extern "C" {
#endif
	
/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/

/**
* @brief This is the HT system configuration section
*/
#define  USE_HT_UART_REGISTER_CALLBACKS        0U /* UART register callback disabled       */
#define  USE_HT_ISO7816_REGISTER_CALLBACKS     0U /* UART register callback disabled       */
#define  USE_HT_IR_REGISTER_CALLBACKS          0U /* UART register callback disabled       */
#define  USE_HT_DMA_REGISTER_CALLBACKS         0U /* DMA register callback disabled        */
#define  USE_HT_SPI_REGISTER_CALLBACKS         0U /* SPI register callback disabled 	   */
#define  USE_HT_RTC_REGISTER_CALLBACKS         0U /* RTC register callback disabled        */
#define  USE_HT_PMU_REGISTER_CALLBACKS	       0U /* PMU register callback disabled        */
#define  USE_HT_TBS_REGISTER_CALLBACKS         0U /* TBS register callback disabled        */

#if  defined  HT6x1x
#define  USE_HT_WDT_REGISTER_CALLBACKS         0U /* WDT register callback disabled        */
#endif

#define  USE_HT_SYSTICK_REGISTER_CALLBACKS     0U /* Systick register callback disabled    */
#define  USE_HT_TMR_REGISTER_CALLBACKS         0U /* TMR register callback disabled        */
#define  USE_HT_EXTI_REGISTER_CALLBACKS        0U /* EXTI register callback disabled       */

#if defined  HT501x  ||  defined  HT502x   ||  defined  HT503x ||  defined  HT762x ||  defined  HT772x 	
#define  USE_HT_EMU_REGISTER_CALLBACKS         0U /* EMU register callback disabled		   */
#endif

#define  USE_HT_ECC_REGISTER_CALLBACKS         0U  /* ECC_ECDSA register callback disabled */
#define  USE_HT_CRC_REGISTER_CALLBACKS         0U  /* CRC register callback disabled	   */
#define  USE_HT_ARG_REGISTER_CALLBACKS         0U  /* AES register callback disabled  	   */
#define  USE_HT_I2C_REGISTER_CALLBACKS	       0U  /* I2C register callback disabled  	   */
#define  USE_HT_KEY_REGISTER_CALLBACKS	       0U  /* KEY register callback disabled  	   */

#if defined  HT762x ||  defined  HT772x  ||  defined  HT503x
#define USE_HT_EMUIFACE_REGISTER_CALLBACKS	   0U  /* EMUIF register callback disabled     */
#define USE_HT_FRAMPACK_REGISTER_CALLBACKS     0U  /* FRAMPACK register callback disabled  */
#endif

#if defined  HT762x ||  defined  HT772x
#define USE_HT_FFT_REGISTER_CALLBACKS          0U  /* FFT register callback disabled       */
#endif

#define UNUSED(X) (void*)((X)=(X))                 /* To avoid gcc/g++ warnings            */	

/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
#define USE_FULL_ASSERT

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
* @brief  The assert_param macro is used for function's parameters check.
* @param  expr: If expr is false, it calls assert_failed function which reports 
*         the name of the source file and the source line number of the call 
*         that failed. If expr is true, it returns no value.
* @retval None
*/
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(unsigned char* file, unsigned int line);
#else
  #define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/**
* @brief  Exported_macro
*/
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

#define IS_BIT_SET(REG, BIT)       (((REG) & (BIT)) == (BIT))

#define IS_BIT_CLR(REG, BIT)       (((REG) & (BIT)) == 0U)

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0U))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
* @brief  Lock structures definition
*/
typedef enum 
{
  UNLOCKED = 0x00U,
  LOCKED   = 0x01U  
} LockTypeDef;
  
/**
* @brief  Status structures definition
*/
typedef enum 
{
  OK       = 0x00U,
  ERROR    = 0x01U,
  BUSY     = 0x02U,
  TIMEOUT  = 0x03U
} StatusTypeDef;

/*
*********************************************************************************************************
*                                           Global Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/




/*
*********************************************************************************************************
*                                           Includes
*********************************************************************************************************
*/
#include "ht6xxx.h"
#include "ht6xxx_cmu.h"
#include "ht6xxx_crc.h"
#include "ht6xxx_ecc.h"
#include "ht6xxx_exti.h"
#include "ht6xxx_flash.h"
#include "ht6xxx_gpio.h"
#include "ht6xxx_iic.h"
#include "ht6xxx_lcd.h"
#include "ht6xxx_pmu.h"
#include "ht6xxx_reset.h"
#include "ht6xxx_rtc.h"
#include "ht6xxx_spi.h"
#include "ht6xxx_tbs.h"
#include "ht6xxx_timer.h"
#include "ht6xxx_uart&7816.h"
#include "ht6xxx_tdes&rand.h"
#include "ht6xxx_aes&rand.h"
#include "ht6xxx_dma.h"
#include "ht50xx_emu.h"
#include "ht7xxx_emu.h"
#include "ht501x_keyscan.h"
#include "ht6x3x_emu.h"
#include "system_ht6xxx.h"
#include "ht6xxx_it.h"
#include "ht6xxx_wdt.h"
#if defined  HT503x
#include "ht5x3x_emuiface.h"
#include "ht5x3x_frampack.h"
#endif
#if defined  HT762x ||  defined  HT772x
#include "ht7x2x_emuiface.h"
#include "ht7x2x_fft.h"
#include "ht7x2x_frampack.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_LIB_H__ */
