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
* File         : ht6xxx_lcd.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_LCD_C

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Local macro definition/struct
*********************************************************************************************************
*/
#if defined USE_LCD	
#if  defined  MaxSegNum_36                                                     
#define    MaxSegNum                 36U
#elif  defined  MaxSegNum_41                               
#define    MaxSegNum                 41U
#elif  defined  MaxSegNum_55                                                     
#define    MaxSegNum                 55U
#elif  defined  MaxSegNum_42                                                  
#define    MaxSegNum                 42U
#elif  defined  MaxSegNum_53                                
#define    MaxSegNum                 53U
#elif  defined  MaxSegNum_48                                
#define    MaxSegNum                 48U
#else                                                                     
#define    MaxSegNum                 55U
#endif

/*
*********************************************************************************************************
*                                             Local variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local fun declaration
*********************************************************************************************************
*/


/**
*********************************************************************************************************                                        
* @brief: INITIAL LCD MODULE
* @param: LCD_InitStruct     Pointer to a LCD_InitTypeDef structure that contains
*													the following information for the specified LCD module.
*                              1) LCD_Bias       : LCD Bias
*                              2) LCD_Com        : LCD Com Number
*                              3) LCD_CLK        : LCD Sweep Clk
*                              4) LCD_ChargeMode : LCD Charge Mode
*                              5) LCD_Vrsel[3..0]: LCD Vrsel
* @retval: None
* @special: User should enable LCD module before configuring LCD register;
*********************************************************************************************************
*/
void HT_LCD_Init(LCD_InitTypeDef *LCD_InitStruct)
{
    uint32_t tempreg;
	/*  assert_param  */
    assert_param(IS_LCD_BIAS(LCD_InitStruct->LCD_Bias));
    assert_param(IS_LCD_COM(LCD_InitStruct->LCD_Com));		
    assert_param(IS_LCD_CLK(LCD_InitStruct->LCD_CLK));	
	
    tempreg  = LCD_InitStruct->LCD_Bias;                   		 /*!< LCD Bias Sel             */
    tempreg |= LCD_InitStruct->LCD_Com;                    		 /*!< LCD Com Number           */
    tempreg |= LCD_InitStruct->LCD_CLK;                    		 /*!< LCD Sweep Frequency      */

    HT_LCD->LCDCLK = tempreg;                              		 /*!< Write to LCDCLK register */
	tempreg=0U;
#if  defined USE_LCDChargeMode 
    tempreg  = (uint32_t)LCD_InitStruct->LCD_ChargeMode;   		 /*!< LCD ChargeMode Set       */
#endif 
	tempreg |= (LCD_InitStruct->LCD_Vrsel & LCD_LCDCON_VRSEL); /*!< LCD VRSEL            		 */
																												
    HT_LCD->LCDCON = tempreg;                              		 /*!<	Write to LCDCON register */
}

/**
*********************************************************************************************************
* @brief: ENABLE/DISABLE LCD MODULE
* @param: NewState            = ENABLE： ENABLE LCD MODULE
*                             = DISABLE：DISABLE LCD MODULE
* @retval: None
* @special:Before LCD_OUT enable，user should configure HT_LCD_Init() or HT_LCD_ChgPump_Init()(If support)
*********************************************************************************************************
*/
#if  defined  USE_HT_LCD_OutConfig  
void HT_LCD_OutConfig(FunctionalState NewState)
{
    /*  assert_param  */
    if (NewState == ENABLE)
    {
        HT_LCD->LCDOUT |= LCD_LCDOUT_ENABLE;
    }
    else
    {
        HT_LCD->LCDOUT &= (~LCD_LCDOUT_ENABLE);
    }
}
#endif


/**
*********************************************************************************************************
* @brief: INITIAL LCD CHARGEPUMP MODULE
* @param: LCD_InitStruct     Pointer to a LCD_InitTypeDef structure that contains
*												    	the following information for the specified LCD module.
*                              1) LCD_ChargePumpClk : LCD chargepump clk sel
*                              2) LCD_DriverMode    : LCD driver mode sel
*                              3) LCD_Vcsel[4..0]   : LCD chargepump contrast ratio sel
* @retval: None
* @special:Before sel chargepump mode，user should disable LCD, then enable lcd clk bit（CLKCTRL0）,enable LCD some time later
*********************************************************************************************************
*/
#if  defined  USE_HT_LCD_CP_Init
void HT_LCD_CP_Init(LCD_CPInitTypeDef *LCD_CPInitStruct)
{
    uint32_t tempreg=0U;
		/*  assert_param  */
		assert_param(IS_LCD_ChargePumpClk(LCD_CPInitStruct->LCD_ChargePumpClk));
		assert_param(IS_LCD_DriverMode(LCD_CPInitStruct->LCD_DriverMode));			
	
    tempreg  = LCD_CPInitStruct->LCD_ChargePumpClk & LCD_LCDCPC_CCLKSEL; /*!< LCD ChargePump CLK Sel   */
    tempreg |= (LCD_CPInitStruct->LCD_DriverMode & LCD_LCDCPC_MODSET);   /*!< LCD Driver Mode Sel         */
    tempreg |= (LCD_CPInitStruct->LCD_Vcsel & LCD_LCDCPC_VCSEL);         /*!< LCD Chargepump Contrast Ratio Sel */

    HT_LCD->LCDCPC = tempreg;                                            /*!< Write to LCDCPC register         */
}
#endif

/**
*********************************************************************************************************
* @brief: WRITE LCD SEGMENT
* @param: SegNum     Between 0 and MaxSegNum.
*         SegValue   Val write in Segment.
* @retval: None
* @special: None
*********************************************************************************************************
*/
void HT_LCD_Write(uint8_t SegNum, uint8_t SegValue)
{
    /*  assert_param  */
    if(SegNum<=MaxSegNum)
    {
      HT_LCD->LCDBUF[SegNum] = SegValue;
    }
}

/**
*********************************************************************************************************
* @brief: READ LCD SEGMENT
* @param: SegNum     Between 0 and MaxSegNum.
*         SegValue   Val write in Segment.
* @retval: None
* @special: None
*********************************************************************************************************
*/
uint8_t HT_LCD_Read(uint8_t SegNum)
{
    uint8_t tmp;
  /*  assert_param  */
    if(SegNum>MaxSegNum)
    {
      tmp=0U;    
    }
    else
    {
      tmp=(uint8_t)HT_LCD->LCDBUF[SegNum];
    }
    return tmp;
}


#endif





