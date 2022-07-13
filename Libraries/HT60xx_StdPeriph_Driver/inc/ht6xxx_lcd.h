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
* File         : ht6xxx_lcd.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_LCD_H__
#define __HT6XXX_LCD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"
	
#if defined USE_LCD	
/*
*********************************************************************************************************
*                                           Global macro definition/struct
*********************************************************************************************************
*/



/**
* @brief  LCD bias sel definition 
*/
typedef enum
{
    LCDBias_OneThird = LCD_LCDCLK_BIASCTL_3,  /*!< 1/3 bias               */
    LCDBias_OneFourth = LCD_LCDCLK_BIASCTL_4, /*!< 1/4 bias               */
}LCDBias_TypeDef;                          		/*!< end of group LCDBias_TypeDef   */

/**
* @brief  LCDCom定义
*/
typedef enum
{
    LCD_4COM = LCD_LCDCLK_DUTY_COM4,       		/*!< 4Com                           */
    LCD_6COM = LCD_LCDCLK_DUTY_COM6,       		/*!< 6Com                           */
    LCD_8COM = LCD_LCDCLK_DUTY_COM8,       		/*!< 8Com                           */
}LCDCom_TypeDef;                           		/*!< end of group LCDCom_TypeDef    */

/**
* @brief  LCD sweep frequency definition 
*/
typedef enum
{
    LCDCLK_Div1 = LCD_LCDCLK_LCLK_FRAME128HZ, /*!< LCD sweep frequency = 128Hz     */
    LCDCLK_Div2 = LCD_LCDCLK_LCLK_FRAME64HZ,  /*!< LCD sweep frequency/2           */
    LCDCLK_Div4 = LCD_LCDCLK_LCLK_FRAME32HZ,  /*!< LCD sweep frequency/4           */
    LCDCLK_Div8 = LCD_LCDCLK_LCLK_FRAME16HZ,  /*!< LCD sweep frequency/8           */
    LCDCLK_Div16 = LCD_LCDCLK_LCLK_FRAME8HZ,  /*!< LCD sweep frequency/16          */
}LCDCLK_TypeDef;                           		/*!< end of group LCDCLK_TypeDef     */

/**
* @brief  LCD charge mode definition 
*/
#if defined USE_LCDChargeMode
typedef enum
{
    LCDCharge_HighCurrent = 0,                                                                                        /*!< LCD large current charge mode                 */
    LCDCharge_LittleCurrent = ((~LCD_LCDCON_FC)&LCD_LCDCON_LC),                                                       /*!< LCD low current charge mode                   */
#if   defined  USE_PeriodDiv128
    LCDChargeQuick_PeriodDiv16_ResDef = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_16|LCD_LCDCON_FCSET2_KEEPR),    /*!< fast charge mode，charge time 1/16 Flcd period，resistance default    */
    LCDChargeQuick_PeriodDiv32_ResDef = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_32|LCD_LCDCON_FCSET2_KEEPR),    /*!< fast charge mode，charge time 1/32 Flcd period，resistance default    */
    LCDChargeQuick_PeriodDiv64_ResDef = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_64|LCD_LCDCON_FCSET2_KEEPR),    /*!< fast charge mode，charge time 1/64 Flcd period，resistance default    */
    LCDChargeQuick_PeriodDiv128_ResDef = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_128|LCD_LCDCON_FCSET2_KEEPR),  /*!< fast charge mode，charge time 1/128 Flcd period，resistance default   */
    LCDChargeQuick_PeriodDiv16_ResChg = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_16|LCD_LCDCON_FCSET2_CHANGER),  /*!< fast charge mode，charge time 1/16 Flcd period，resistance improve    */
    LCDChargeQuick_PeriodDiv32_ResChg = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_32|LCD_LCDCON_FCSET2_CHANGER),  /*!< fast charge mode，charge time 1/32 Flcd period，resistance improve    */
    LCDChargeQuick_PeriodDiv64_ResChg = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_64|LCD_LCDCON_FCSET2_CHANGER),  /*!< fast charge mode，charge time 1/64 Flcd period，resistance improve    */
    LCDChargeQuick_PeriodDiv128_ResChg = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_128|LCD_LCDCON_FCSET2_CHANGER),/*!< fast charge mode，charge time 1/128 Flcd period，resistance improve   */
#else
    LCDChargeQuick_PeriodDiv8 = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_8),   /*!< fast charge mode，charge time 1/8 Flcd period */
    LCDChargeQuick_PeriodDiv16 = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_16), /*!< fast charge mode，charge time 1/16 Flcd period*/
    LCDChargeQuick_PeriodDiv32 = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_32), /*!< fast charge mode，charge time 1/32 Flcd period*/
    LCDChargeQuick_PeriodDiv64 = (LCD_LCDCON_FC|LCD_LCDCON_LC|LCD_LCDCON_FCSET_64), /*!< fast charge mode，charge time 1/64 Flcd period*/
#endif
}LCDChargeMode_TypeDef;                    																					/*!< end of group LCDChargeMode_TypeDef  */
#endif

/* HT502x and HT6x3x Backwards compatible definition */
#if  defined  USE_LCDChargeQuick_PeriodDiv8  
#define LCDChargeQuick_PeriodDiv8       LCDChargeQuick_PeriodDiv16_ResDef
#define LCDChargeQuick_PeriodDiv16      LCDChargeQuick_PeriodDiv32_ResDef
#define LCDChargeQuick_PeriodDiv32      LCDChargeQuick_PeriodDiv64_ResDef
#define LCDChargeQuick_PeriodDiv64      LCDChargeQuick_PeriodDiv128_ResDef
#endif


/**
* @brief  LCD chargepump clk sel
*/
#if  defined  USE_LCDDriverMode 
typedef enum
{
    LCDDriveMode_InsideRes   = LCD_LCDCPC_MODSET_InsideRESDrive,  /*!< Internal resistance partial voltage Mode  */
    LCDChargePump_ChargePump = LCD_LCDCPC_MODSET_ChargePumpDrive, /*!< Charge Pump Mode */
}LCDDriverMode_TypeDef;                    												/*!< end of group LCDDriverMode_TypeDef  */
#endif

/**
* @brief  LCD chargepump clk sel
*/
#if  defined  USE_LCDDriverMode 
typedef enum
{
    LCDChargePump_Clk256 = LCD_LCDCPC_CCLKSEL_256,  /*!< Chargepump CLK 256Hz */
    LCDChargePump_Clk512 = LCD_LCDCPC_CCLKSEL_512,  /*!< Chargepump CLK 512Hz */
    LCDChargePump_Clk1K  = LCD_LCDCPC_CCLKSEL_1K,   /*!< Chargepump CLK 1kHz  */
    LCDChargePump_Clk2K  = LCD_LCDCPC_CCLKSEL_2K,   /*!< Chargepump CLK 2kHz  */
    LCDChargePump_Clk4K  = LCD_LCDCPC_CCLKSEL_4K,   /*!< Chargepump CLK 4kHz  */
    LCDChargePump_Clk8K  = LCD_LCDCPC_CCLKSEL_8K,   /*!< Chargepump CLK 8kHz  */
    LCDChargePump_Clk16K = LCD_LCDCPC_CCLKSEL_16K,  /*!< Chargepump CLK 16kHz */
    LCDChargePump_Clk32K = LCD_LCDCPC_CCLKSEL_32K,  /*!< Chargepump CLK 32kHz */
}LCDChargePumpClk_TypeDef;                    			/*!< end of group LCDChargePumpClk_TypeDef  */
#endif

/**
* @brief  LCD init structure definition
*/

typedef struct
{
    LCDBias_TypeDef LCD_Bias;              /*!< LCD Bias Definition                     */
    LCDCom_TypeDef  LCD_Com;               /*!< LCD Com Number Definition               */
    LCDCLK_TypeDef  LCD_CLK;               /*!< LCD sweep frequency definition          */
#if    defined  USE_LCDChargeMode   
	LCDChargeMode_TypeDef LCD_ChargeMode;  	 /*!< LCD charge mode definition              */
#endif    
	uint16_t LCD_Vrsel;                    	 /*!< LCD_Vrsel[3..0]: contrast ratio set     */

}LCD_InitTypeDef;                          /*!< end of group LCD_InitTypeDef        		*/



/**
* @brief  LCD chargepump init structure definition
*/
#if  defined  USE_LCD_CPInit
typedef struct
{
    LCDChargePumpClk_TypeDef LCD_ChargePumpClk; /*!< LCD ChargePumpClk Definition               */
    LCDDriverMode_TypeDef    LCD_DriverMode;    /*!< LCD Driver Mode Definition                   */
    uint16_t LCD_Vcsel;                         /*!< LCD_Vcsel[4..0]: contrast ratio set        */
}LCD_CPInitTypeDef;
#endif


#define IS_LCD_BIAS(BIAS) (((BIAS) == LCDBias_OneThird) || \
                            ((BIAS) == LCDBias_OneFourth) )

#define IS_LCD_COM(COM) (((COM) == LCD_4COM) || \
												((COM) == LCD_6COM) || \
													 ((COM) == LCD_8COM) )

#define IS_LCD_CLK(CLK) (((CLK) == LCDCLK_Div1) || \
												((CLK) == LCDCLK_Div2) || \
												((CLK) == LCDCLK_Div4) || \
												((CLK) == LCDCLK_Div8) || \
													 ((CLK) == LCDCLK_Div16) )

#if  defined  USE_IS_LCD_ChargePumpClk
#define IS_LCD_ChargePumpClk(ChargePumpClk) (((ChargePumpClk) == LCDChargePump_Clk256) || \
																							((ChargePumpClk) == LCDChargePump_Clk512) || \
																							((ChargePumpClk) == LCDChargePump_Clk1K) || \
																							((ChargePumpClk) == LCDChargePump_Clk2K) || \
																							((ChargePumpClk) == LCDChargePump_Clk4K) || \
																							((ChargePumpClk) == LCDChargePump_Clk8K) || \
																							((ChargePumpClk) == LCDChargePump_Clk16K) || \
																							((ChargePumpClk) == LCDChargePump_Clk32K) )																					

#define IS_LCD_DriverMode(DriverMode) (((DriverMode) == LCDDriveMode_InsideRes) || \
																				((DriverMode) == LCDChargePump_ChargePump) )	
#endif


/*
*********************************************************************************************************
*                                             Global variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global fun declaration
*********************************************************************************************************
*/

void HT_LCD_Init(LCD_InitTypeDef *LCD_InitStruct);
void HT_LCD_Write(uint8_t SegNum, uint8_t SegValue);
uint8_t HT_LCD_Read(uint8_t SegNum);

#if  defined  USE_HT_LCD_OutConfig 
void HT_LCD_OutConfig(FunctionalState NewState);
#endif

#if  defined  USE_HT_LCD_CP_Init
void HT_LCD_CP_Init(LCD_CPInitTypeDef *LCD_CPInitStruct);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_LCD_H__ */

#endif
