/*
*********************************************************************************************************
*                                              HT6XXXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6x3x_emu.c
* By           : Hitrendtech_SD
* Version      : V2.0.5
* Description  : Only support for chips used EMU Constant Measurement Function. 
*********************************************************************************************************
*/

#define  __HT6X3X_EMU_C


#include "ht6xxx_lib.h"

#if defined  USE_EMU_CONST /* This File Only support for chips used EMU Constant Measurement Function. */

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
static const uint32_t RegisterWriteProtect[]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};

/**
*********************************************************************************************************
*                                  INITIAL EMU CONST MODULE
*
* @brief:  Init EMU Const module
*
* @param:  EMU_PowerQ_Set     32bit unsigned long, bit32 is sign, 
*                             positive number is not more than 0x40000000
*                             negative number is not more than 0xC0000000
*          EMU_PowerP_Set     The same as EMU_PowerQ_Set
*          EMU_HFConst_SET    15bit unsigned long, from 0x0000 to 0x7FFF
*          EMU_EMUClk_Sel     Emu Const Clock Select, one of follows:
*          (If support)       @arg EMUClkSel_PLLx2   EMU Clock selects 44M PLL clock
*                             @arg EMUClkSel_HRC11M  EMU Clock selects HRC clock
*                             @arg EMUClkSel_FOSC    EMU Clock selects OSC clock
*          EMU_EMUClk_DIV     EMU Const Clock division config, from 0x0000 to 0x00FF  
*          (If support)
*
* @retval: none
*
* @note:   1) PLL or HRC clock must be enabled, or EMU Const Module can not work.
*          2) EMU_EN in CMU Module is best to be enabled after configuring this function. 
*********************************************************************************************************
*/
void HT_EMU_Const_Init(EMUConst_InitTypeDef *EMUConst_InitStruct)
{
    /*  assert_param  */
#if defined USE_EMU_CONST_CLKSEL	
	  uint32_t tempreg = 0x0000U;
#endif
	  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protection status */
	
	  assert_param(IS_HT_EMU_CONST_POWERINQ(EMUConst_InitStruct->EMU_PowerQ_Set));
	  assert_param(IS_HT_EMU_CONST_POWERINP(EMUConst_InitStruct->EMU_PowerP_Set));
#if defined USE_EMU_CONST_CLKSEL	
	  assert_param(IS_HT_EMU_CONST_EMUCLKSEL(EMUConst_InitStruct->EMU_EMUClk_Sel));
#endif
	
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                /*!< Turn off write protection                */
  
#if defined USE_EMU_CONST_CLKSEL		
	  EMUCLKCFG_CONFIG(tempreg,EMUConst_InitStruct);                                        /*!< config EMUCLKCFG                         */
#endif
	
	  HT_EMU->PowerInQ  = EMUConst_InitStruct->EMU_PowerQ_Set;
	  HT_EMU->PowerInP  = EMUConst_InitStruct->EMU_PowerP_Set;
	  HT_EMU->HFConst   = EMUConst_InitStruct->EMU_HFConst_SET;
#if defined USE_EMU_CONST_CLKSEL	
    HT_CMU->EMUCLKCFG = tempreg;
#endif

    HT_CMU->CLKCTRL1 |= CMU_CLKCTRL1_EMUEN;                                               /*!< Enabled EMU Const Clock                  */
    HT_CMU->WPREG = writeProtect;                                                   /*!< Restore the previous write protection settings */

}

/**
*********************************************************************************************************
*                                      EMU Register Read
*
* @brief:  Read registers of EMU Const Module
*
* @param:  EMU_Register   One of follow registers：
*                         @arg EMU_PowerInQ  PowerQ Input Value 
*                         @arg EMU_PowerInP  PowerP Input Value
*                         @arg EMU_HFConst   Frequency of output pulse
*                         @arg EMU_EnergyP   EnergyP buffer register(read after clear)
*                         @arg EMU_EnergyQ   EnergyQ buffer register(read after clear)
*
* @retval: register data
*
* @note:   1) EMU_EnergyP、EMU_EnergyQ will be cleared after read;
           2) It will return 0 if parameter is nvalid.
*********************************************************************************************************
*/
uint32_t HT_EMU_RegisterRead(EMUReg_TypeDef EMU_Register)
{
    /*  assert_param  */
    assert_param(IS_HT_EMU_CONST_REG_READ(EMU_Register));
	
    switch (EMU_Register)
    {
      case EMU_PowerInQ:                                                                  /*!< Read power Q input register              */
        return HT_EMU->PowerInQ;

      case EMU_PowerInP:                                                                  /*!< Read power P input register              */
        return HT_EMU->PowerInP;

      case EMU_HFConst:                                                                   /*!< Read HFConst                             */
        return HT_EMU->HFConst;

      case EMU_EnergyP:                                                                   /*!< Read energy P register                   */
        HT_EMU->ReadCtrl |= EMU_READCRTL_ENERGYP_REQ;
          while(!(HT_EMU->ReadCtrl & EMU_READCRTL_ENERGYP_RDY)){}
                return HT_EMU->EnergyP;

      case EMU_EnergyQ:                                                                   /*!< Read energy Q register                   */
        HT_EMU->ReadCtrl |= EMU_READCRTL_ENERGYQ_REQ;
          while(!(HT_EMU->ReadCtrl & EMU_READCRTL_ENERGYQ_RDY)){}
                return HT_EMU->EnergyQ;

      default:
        return 0x0;                                                                       /*!< invalid parameter                        */
    }
}

/**
*********************************************************************************************************
*                                      EMU Register Write
*
* @brief:  Write registers of EMU Const Module
*
* @param:  EMU_Register   One of follow registers：
*                         @arg EMU_PowerInQ  PowerQ Input Value,
*                                            32bit unsigned long, bit32 is sign, 
*                                            positive number is not more than 0x40000000
*                                            negative number is not more than 0xC0000000
*                         @arg EMU_PowerInP  PowerP Input Value,
*                                            The same as EMU_PowerInQ
*                         @arg EMU_HFConst   Frequency of output pulse,
*                                            15bit unsigned long, from 0x0000 to 0x7FFF
* @retval: none
*
* @note:   none
*********************************************************************************************************
*/
void HT_EMU_RegisterWrite(EMUReg_TypeDef EMU_Register,uint32_t RegisterValue)
{
    /*  assert_param  */
	  assert_param(IS_HT_EMU_CONST_REG_WRITE(EMU_Register));

    switch (EMU_Register)
    {
      case EMU_PowerInQ:                                                                  /*!< Write power Q input register             */
				assert_param(IS_HT_EMU_CONST_POWERINQ(RegisterValue));
        HT_EMU->PowerInQ = RegisterValue;
        break;

      case EMU_PowerInP:                                                                  /*!< Write power P input register             */
				assert_param(IS_HT_EMU_CONST_POWERINP(RegisterValue));
        HT_EMU->PowerInP = RegisterValue;
        break;

      case EMU_HFConst:                                                                   /*!< Write HFConst                            */
        HT_EMU->HFConst  = RegisterValue;
        break;

      default:
        break;                                                                            /*!< invalid parameter                        */
    }
}


/**
*********************************************************************************************************
*                                      EMU Const Clock Config
*
* @brief:  EMU Const Clock Config
*
* @param:  HT_EMU_EMUCLKSEL   Emu Const Clock Select, one of follows:
*                             @arg EMUClkSel_PLLx2   EMU Clock selects 44M PLL clock
*                             @arg EMUClkSel_HRC11M  EMU Clock selects HRC clock
*                             @arg EMUClkSel_FOSC    EMU Clock selects OSC clock
*          HT_EMU_EMUCLKDIV   EMU Const Clock division config, from 0x0000 to 0x00FF 
*
* @retval: none
*
* @note:   none
*********************************************************************************************************
*/
#if defined USE_EMU_CONST_CLKSEL	
void HT_EMU_EMUCLK_Config(uint32_t EMUClkConfigItem, uint8_t SetValue)
{
    /*  assert_param  */
	  uint32_t tempreg = 0x0000U;
	  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protection status */
	
	  assert_param(IS_HT_EMU_CONST_EMUCLKCFG_ITEM(EMUClkConfigItem));
	  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                /*!< Turn off write protection                */

    switch (EMUClkConfigItem)
    {
      case HT_EMU_EMUCLKSEL:                                                              /*!< Select EMU Const Clock                   */
				assert_param(IS_HT_EMU_CONST_EMUCLKSEL(SetValue));
			  tempreg  =  HT_CMU->EMUCLKCFG;
			  tempreg &= ~CMU_EMUCLKCFG_EMUCLKSEL;
			  tempreg |= (SetValue << 12);
        HT_CMU->EMUCLKCFG = tempreg;
        break;

      case HT_EMU_EMUCLKDIV:                                                              /*!< Set division of EMU Const clock          */
        tempreg  =  HT_CMU->EMUCLKCFG;
			  tempreg &= ~CMU_EMUCLKCFG_EMUCLKDIV;
			  tempreg |=  SetValue;
        HT_CMU->EMUCLKCFG = tempreg;
        break;

      default:
        break;                                                                            /*!< invalid parameter                        */
    }
		
		HT_CMU->WPREG = writeProtect;                                                   /*!< Restore the previous write protection settings */
}
#endif


#endif                                                      /* This File Only support for chips used EMU Constant Measurement Function. */



