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
* File         : ht6x3x_emu.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : Only support for chips used EMU Constant Measurement Function. 
**********************************************************************************************************
*/

#ifndef __HT6X3X_EMU_H__
#define __HT6X3X_EMU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

#if defined  USE_EMU_CONST /* This File Only support for chips used EMU Constant Measurement Function. */
	
#define HT_EMU_POWERINQ_SEL  0x00UL
#define HT_EMU_POWERINP_SEL  0x01UL
#define HT_EMU_HFCONST_SEL   0x02UL
#define HT_EMU_ENERGYP_SEL   0x04UL
#define HT_EMU_ENERGYQ_SEL   0x08UL
	
#if defined USE_EMU_CONST_CLKSEL	
#define HT_EMU_EMUCLKSEL     0x10UL
#define HT_EMU_EMUCLKDIV     0x20UL
#endif
	
#if defined USE_EMU_CONST_CLKSEL	
#define HT_EMU_EMUCLKSEL_PLLX2   0x00UL
#define HT_EMU_EMUCLKSEL_HRC11M  0x01UL
#define HT_EMU_EMUCLKSEL_FOSC    0x02UL
#endif

#define HT_EMU_POWERINQ_START_P  0x00000000UL
#define HT_EMU_POWERINQ_END_P    0x40000000UL
#define HT_EMU_POWERINQ_START_N  0xC0000000UL
#define HT_EMU_POWERINQ_END_N    0xFFFFFFFFUL
	
#define HT_EMU_POWERINP_START_P  0x00000000UL
#define HT_EMU_POWERINP_END_P    0x40000000UL
#define HT_EMU_POWERINP_START_N  0xC0000000UL
#define HT_EMU_POWERINP_END_N    0xFFFFFFFFUL
	


/*
*********************************************************************************************************
*                                          Global macro / structure
*********************************************************************************************************
*/
#define IS_HT_EMU_CONST_POWERINQ(PERIPH)       ((((PERIPH) <= HT_EMU_POWERINQ_END_P)) || \
                                                (((PERIPH) >= HT_EMU_POWERINQ_START_N)))
																					      
#define IS_HT_EMU_CONST_POWERINP(PERIPH)       ((((PERIPH) <= HT_EMU_POWERINP_END_P)) || \
                                                (((PERIPH) >= HT_EMU_POWERINP_START_N)))

#define IS_HT_EMU_CONST_REG_READ(PERIPH)       (((PERIPH) == EMU_PowerInQ) || \
                                                ((PERIPH) == EMU_PowerInP) || \
                                                ((PERIPH) == EMU_HFConst) || \
                                                ((PERIPH) == EMU_EnergyP) || \
                                                ((PERIPH) == EMU_EnergyQ))
																								
#define IS_HT_EMU_CONST_REG_WRITE(PERIPH)      (((PERIPH) == EMU_PowerInQ) || \
                                                ((PERIPH) == EMU_PowerInP) || \
												((PERIPH) == EMU_HFConst))

#if defined USE_EMU_CONST_CLKSEL	
#define IS_HT_EMU_CONST_EMUCLKSEL(PERIPH)      (((PERIPH) == HT_EMU_EMUCLKSEL_PLLX2) || \
                                                ((PERIPH) == HT_EMU_EMUCLKSEL_HRC11M) || \
                                                ((PERIPH) == HT_EMU_EMUCLKSEL_FOSC))

#define IS_HT_EMU_CONST_EMUCLKCFG_ITEM(PERIPH) (((PERIPH) == HT_EMU_EMUCLKSEL) || \
                                                ((PERIPH) == HT_EMU_EMUCLKDIV))
																					 
#define EMUCLKCFG_CONFIG(temp,EMUCLKCFG_Init)  ((temp) = (((uint32_t)((EMUCLKCFG_Init)->EMU_EMUClk_DIV) & (uint32_t)0x00FF)|((((EMUCLKCFG_Init)->EMU_EMUClk_Sel) & (uint32_t)0x0007)<<12)))
#endif

typedef enum
{
    EMU_PowerInQ = HT_EMU_POWERINQ_SEL,                  /*!< Select power Q input register      */
    EMU_PowerInP = HT_EMU_POWERINP_SEL,                  /*!< Select power P input register      */
    EMU_HFConst  = HT_EMU_HFCONST_SEL,                   /*!< Select HFConst                     */
    EMU_EnergyP  = HT_EMU_ENERGYP_SEL,                   /*!< Select energy P  register          */
    EMU_EnergyQ  = HT_EMU_ENERGYQ_SEL,                   /*!< Select energy Q  register          */
}EMUReg_TypeDef;                                    /*!< end of group EMUReg_TypeDef      */

#if defined USE_EMU_CONST_CLKSEL
typedef enum
{
    EMUClkSel_PLLx2  = HT_EMU_EMUCLKSEL_PLLX2,           /*!< Select 44M PLL Clock as EMU Clock      */
    EMUClkSel_HRC11M = HT_EMU_EMUCLKSEL_HRC11M,          /*!< Select 11M HRC Clock as EMU Clock      */
    EMUClkSel_FOSC   = HT_EMU_EMUCLKSEL_FOSC,            /*!< Select OSC Clock as EMU Clock          */
}EMUClkSel_TypeDef; 
#endif

/**
* @brief  GPIO Init Type Define for AFMode
**/
typedef struct
{
    uint32_t            EMU_PowerQ_Set;                        /*!< Set PowerQ                       */
	  uint32_t            EMU_PowerP_Set;                        /*!< Set PowerP                       */
    uint16_t            EMU_HFConst_SET;                       /*!< Set HFConst                      */
#if defined USE_EMU_CONST_CLKSEL
    EMUClkSel_TypeDef   EMU_EMUClk_Sel;                        /*!< Select EMU Clock                 */
	  uint8_t             EMU_EMUClk_DIV;                        /*!< Set Clock division of EMU Clock  */
#endif
}EMUConst_InitTypeDef;                                     /*!< end of group GPIO_InitAFTypeDef      */

/*
*********************************************************************************************************
*                                            Global variable 
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global function declaration
*********************************************************************************************************
*/
void HT_EMU_Const_Init(EMUConst_InitTypeDef *EMUConst_InitStruct);
uint32_t HT_EMU_RegisterRead(EMUReg_TypeDef EMU_Register);
void HT_EMU_RegisterWrite(EMUReg_TypeDef EMU_Register,uint32_t RegisterValue);
#if defined USE_EMU_CONST_CLKSEL	
void HT_EMU_EMUCLK_Config(uint32_t EMUClkConfigItem, uint8_t SetValue);
#endif

#endif                     /* This File Only support for chips used EMU Constant Measurement Function. */

#ifdef __cplusplus
}
#endif

#endif /* __HT6X3X_EMU_H__ */
