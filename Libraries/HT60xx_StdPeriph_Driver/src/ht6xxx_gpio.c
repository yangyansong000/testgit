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
* File         : ht6xxx_gpio.c
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_GPIO_C

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                        Local Macro/Structure
*********************************************************************************************************
*/
#define  GPIO_Mode_AFx            0x10                      /*!< GPIO Alternate Function is used      */

/*
*********************************************************************************************************
*                                           Local Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       Local Function Declaration
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*                                         INITIAL THE GPIO
*
* @brief:  Configuring GPIO, this function can inital multiple Pins in the same GPIO group,
*          GPIO_Mode of these Pins must be consistent.
*
* @param:  GPIOx               Can only be one of the following Group
*                                @arg  HT_GPIOA
*                                @arg  HT_GPIOB
*                                @arg  HT_GPIOC
*                                @arg  HT_GPIOD
*                                @arg  HT_GPIOE
*                                @arg  HT_GPIOF  (If support)
*                                @arg  HT_GPIOG  (If support)
*                                @arg  HT_GPIOH  (If support)
*                                @arg  HT_GPIOI  (If support)
*                                @arg  HT_GPIOJ  (If support)
*
*           GPIO_InitStruct    Pointer to the GPIO Initial Structure:
*                              1) GPIO_Pin           : Initial Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*                              2) GPIO_Mode          : GPIO Mode, one of the follow Modes
*                                                      GPIO_Mode_IOIN            GPIO Input
*                                                      GPIO_Mode_IOOUT           GPIO Output
*                                                      GPIO_Mode_AF1             Alternate Function 1
*                                                      GPIO_Mode_AF2             Alternate Function 2
*                                                      GPIO_Mode_AF3             Alternate Function 3 (If support)
*                                                      GPIO_Mode_AF4             Alternate Function 4 (If support)
*                                                      GPIO_Mode_HighResistance  High Resistance Mode (If support)
*                              3) GPIO_InputStruct   : Configuring Pullup or Floating when GPIO Digital Input
*                              4) GPIO_OutputStruct  : Configuring Push or Open Drain when GPIO Digital Output
*                              5) GPIO_InputFilter   : Configuring Input Filter
*                                                      (If support)
*                              6) GPIO_NewAFCtrl     : Enable or Disable the new alternate function
*                                                      (If support)
*
* @retval:  None
*
* @Note:    1) When the Pin is configured as some Analog Function, such as ADCIN/Segment/Com,
*              the configuration of input, output, pullup or floating, push or open drain, will be invalid.
*           2) User should ensure the write protection status of register is keep unchanged
*              during the execution of the function.
*           3) The Priority of High Resistance is higher than other GPIO Modes except Analog Mode.
*
*********************************************************************************************************
**/
void HT_GPIO_Init(HT_GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_GPIOMode(GPIO_InitStruct->GPIO_Mode));
	assert_param(IS_HT_GPIO_InputStruct(GPIO_InitStruct->GPIO_InputStruct));
	assert_param(IS_HT_GPIO_OutputStruct(GPIO_InitStruct->GPIO_OutputStruct));
#if defined USE_GPIO_FILT
	assert_param(IS_HT_GPIO_InputFilter(GPIO_InitStruct->GPIO_InputFilter));
#endif
#if defined USE_GPIO_NEWAFCTRL
    assert_param(IS_HT_GPIO_NewAFCtrl(GPIO_InitStruct->GPIO_NewAFCtrl));
#endif


#if  defined  USE_GPIO_NEWAFCTRL
    if (GPIO_InitStruct->GPIO_NewAFCtrl == DISABLE)
    {
        GPIOx->NEWAFEN &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);           /*!< Disable New Alternate Functions                                     */
    }
    else
    {
      GPIOx->NEWAFEN |= (uint32_t)GPIO_InitStruct->GPIO_Pin;                /*!< Enable New Alternate Functions                                      */
    }
#endif
	
    if(GPIO_InitStruct->GPIO_Mode & GPIO_Mode_AFx)                          /*!< Judging whether the GPIO is multiplexed as a Alternate Function Pin */
    {
        if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF1)
        {
            GPIOx->AFCFG &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);         /*!< Configuring as Alternate Function 1                                 */
#if defined  USE_GPIO_AF34
			GPIOx->AFCFG1 &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);
#endif
        }
#if defined  USE_GPIO_AF34
        else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF2)
        {
            GPIOx->AFCFG  |=  ((uint32_t)GPIO_InitStruct->GPIO_Pin);        /*!< Configuring as Alternate Function 2                                 */
            GPIOx->AFCFG1 &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);
        }
        else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF3)
        {
            GPIOx->AFCFG  &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);        /*!< Configuring as Alternate Function 3                                 */
            GPIOx->AFCFG1 |=  ((uint32_t)GPIO_InitStruct->GPIO_Pin);
        }
        else
        {
            GPIOx->AFCFG  |=  ((uint32_t)GPIO_InitStruct->GPIO_Pin);        /*!< Configuring as Alternate Function 4                                 */
            GPIOx->AFCFG1 |=  ((uint32_t)GPIO_InitStruct->GPIO_Pin);
        }
#else
        else
        {
            GPIOx->AFCFG |= (uint32_t)GPIO_InitStruct->GPIO_Pin;            /*!< Configuring as Alternate Function 2                                 */
        }
#endif
        GPIOx->IOCFG |= GPIO_InitStruct->GPIO_Pin;                          /*!< Configuring GPIO as Alternate Function Pins                         */
    }
    else
    {
        if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IOIN)                    /*!< Judging whether the GPIO is Digital Input                           */
        {
            GPIOx->PTDIR &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);         /*!< Configuring as Digital Input                                        */
        }
        else
        {
            GPIOx->PTDIR |= (uint32_t)GPIO_InitStruct->GPIO_Pin;            /*!< Configuring as Digital Output                                       */
        }
        GPIOx->IOCFG &= ~((uint32_t)GPIO_InitStruct->GPIO_Pin);             /*!< Configuring as Digital IO Mode                                      */
    }

    if(GPIO_InitStruct->GPIO_InputStruct == GPIO_Input_Up)                  /*!< Judging whether the GPIO is Pullup or Input Floating                */
    {
        GPIOx->PTUP &=  ~((uint32_t)GPIO_InitStruct->GPIO_Pin);             /*!< Configuring as Input Pullup                                         */
    }
    else
    {
        GPIOx->PTUP |=  (uint32_t)GPIO_InitStruct->GPIO_Pin;                /*!< Configuring as Input Floating                                       */
    }

    if(GPIO_InitStruct->GPIO_OutputStruct == GPIO_Output_OD)                /*!< Judging whether the GPIO is Push or Open Drain                      */
    {
        GPIOx->PTOD &=  ~((uint32_t)GPIO_InitStruct->GPIO_Pin);             /*!< Configuring as Output Open Drain                                    */
    }
    else
    {
        GPIOx->PTOD |=  (uint32_t)GPIO_InitStruct->GPIO_Pin;                /*!< Configuring as Output Push                                          */
    }

#if  defined  USE_GPIO_FILT
    if (GPIO_InitStruct->GPIO_InputFilter == DISABLE)          /*!< Judging whether the GPIO is enabled input filter                                 */
    {
        GPIOx->FILT &=  ~((uint32_t)GPIO_InitStruct->GPIO_Pin);             /*!< Disable Input Filter                                                */
    }
    else
    {
        GPIOx->FILT |=  (uint32_t)GPIO_InitStruct->GPIO_Pin;                /*!< Enable Input Filter                                                 */
    }
#endif
    
#if defined USE_GPIO_HIIPM
    if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_HighResistance)
    {
          GPIOx->HIIPM |=  (uint32_t)GPIO_InitStruct->GPIO_Pin;               /*!< Enable High Resistance                                              */
    }
    else
    {
          GPIOx->HIIPM &=  ~((uint32_t)GPIO_InitStruct->GPIO_Pin);            /*!< Disable High Resistance                                             */
    }
#endif
}

/**
*********************************************************************************************************
*                         INITIAL GPIO TO SPECIFIC ALTERNATE FUNCTION
*
* @brief:  Configuring GPIO as Alternate Function,
*          this function can inital multiple Pins in the same GPIO group,
*          Alternate Function Group of these Pins can be different.
*
* @param:  GPIOx               Can only be one of the following Group
*                                @arg  HT_GPIOA
*                                @arg  HT_GPIOB
*                                @arg  HT_GPIOC
*                                @arg  HT_GPIOD
*                                @arg  HT_GPIOE
*                                @arg  HT_GPIOF  (If support)
*                                @arg  HT_GPIOG  (If support)
*                                @arg  HT_GPIOH  (If support)
*                                @arg  HT_GPIOI  (If support)
*                                @arg  HT_GPIOJ  (If support)
*
*           GPIO_InitAFStruct  Pointer to the GPIO Alternate Function Structure:
*                              1) GPIO_Pin         : Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*                              2) GPIO_AFMode      : GPIO Alternate Functon Mode,
*                                                    one or more AFModes of different Pins in the same GPIO Group
*                                                    Note: Only part of AFModes of GPIOA and GPIOE for several chips is listed below,
*                                                          the whold AFMode List for every chip can refer to the GPIO Pin AFMode Define of ht6xxx_gpio.h
*                                                    PA0_SEG28           PE0_TMR0
*                                                    PA1_SEG29           PE1_TX4
*                                                    PA2_SEG30           PE1_TOUT2
*                                                    PA3_SEG31           PE2_RX4
*                                                    PA4_SEG32           PE2_ESAMIO
*                                                    PA5_INT0            PE3_CLKOUT
*                                                    PA6_INT1            PE4_RX3
*                                                    PA7_INT2            PE4_CARDIO
*                                                    PA7_SEG33           PE5_TX3
*                                                    PA8_INT3            PE6_TMR1
*                                                    PA8_SEG34           PE7_LVDIN
*                                                    PA9_INT4            PE8_POWIN
*                                                    PA10_INT5           PE9_TMR2
*                                                    PA11_INT6           PE10_TMR3
*                                                    PA12_SEG35          PE11_TX2
*                                                    PA12_ADCIN0         PE12_RX2
*                                                    PA13_SEG36          PE13_SCL
*                                                    PA13_ADCIN1         PE14_SDA
*
*                              3) GPIO_InputStruct : Configuring Pullup or Floating when Alternate Function is Digital Input
*                              4) GPIO_OutputStruct: Configuring Push or Open Drain when Alternate Function is Digital Output
*                              5) GPIO_InputFilter : Configuring Input Filter
*                                                    (If support)
*                              6) GPIO_NewAFCtrl   : Enable or Disable the new alternate function
*                                                    (If support)
*
* @retval:  None
*
* @Note:    1) All selected Pins will be configured as Alternate Function Pins;
*           2) User should ensure GPIO_Pin and GPIO_AFMode correspondence,
*              For example, if GPIO_AFMode include PA0_SEG28, there should include GPIO_Pin_0 in GPIO_MODE.
*           3) When the Pin is configured as some Analog Function, such as ADCIN/Segment/Com,
*              the configuration of input, output, pullup or floating, push or open drain, will be invalid.
*           4) User should ensure the write protection status of register is keep unchanged
*              during the execution of the function.
*
*********************************************************************************************************
**/
void HT_GPIO_AFInit(HT_GPIO_TypeDef* GPIOx, GPIO_InitAFTypeDef* GPIO_InitAFStruct)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_InputStruct(GPIO_InitAFStruct->GPIO_InputStruct));
	assert_param(IS_HT_GPIO_OutputStruct(GPIO_InitAFStruct->GPIO_OutputStruct));
#if defined USE_GPIO_FILT
	assert_param(IS_HT_GPIO_InputFilter(GPIO_InitAFStruct->GPIO_InputFilter));
#endif
#if defined USE_GPIO_NEWAFCTRL
    assert_param(IS_HT_GPIO_NewAFCtrl(GPIO_InitAFStruct->GPIO_NewAFCtrl));
#endif

    uint32_t AFState;
#if defined USE_GPIO_AF34
	uint32_t AFState1;
#endif
    
#if  defined  USE_GPIO_NEWAFCTRL
    if (GPIO_InitAFStruct->GPIO_NewAFCtrl == DISABLE)
    {
        GPIOx->NEWAFEN &= ~((uint32_t)GPIO_InitAFStruct->GPIO_Pin);                 /*!< Disable New Alternate Functions                            */

    }
    else
    {
        GPIOx->NEWAFEN |= (uint32_t)GPIO_InitAFStruct->GPIO_Pin;                    /*!< Enable New Alternate Functions                             */
    }
#endif
    
    AFState = GPIOx->AFCFG & (~(uint32_t)GPIO_InitAFStruct->GPIO_Pin);              /*!< Save the Alternate Function Status of unconfigured pins    */
#if defined USE_GPIO_AF34
	AFState1 = GPIOx->AFCFG1 & (~(uint32_t)GPIO_InitAFStruct->GPIO_Pin);            /*!< Save the Alternate Function Status of unconfigured pins    */
#endif
    GPIOx->AFCFG = (uint32_t)GPIO_InitAFStruct->GPIO_AFMode | AFState;              /*!< Configuring specified pins as specified Alternate Function */
#if defined USE_GPIO_AF34
	GPIOx->AFCFG1 = ((uint32_t)GPIO_InitAFStruct->GPIO_AFMode >> 16) | AFState1;    /*!< Configuring specified pins as specified Alternate Function */
#endif
    GPIOx->IOCFG |= GPIO_InitAFStruct->GPIO_Pin;                                    /*!< Configuring as Alternate Function Pin                      */

    if(GPIO_InitAFStruct->GPIO_InputStruct == GPIO_Input_Up)                        /*!< Judging whether the GPIO is Pullup or Input Floating       */
    {
        GPIOx->PTUP &=  ~((uint32_t)GPIO_InitAFStruct->GPIO_Pin);                   /*!< Configuring as Input Pullup                                */
    }
    else
    {
        GPIOx->PTUP |=  (uint32_t)GPIO_InitAFStruct->GPIO_Pin;                      /*!< Configuring as Input Floating                              */
    }

    if(GPIO_InitAFStruct->GPIO_OutputStruct == GPIO_Output_OD)                      /*!< Judging whether the GPIO is Push or Open Drain             */
    {
        GPIOx->PTOD &=  ~((uint32_t)GPIO_InitAFStruct->GPIO_Pin);                   /*!< Configuring as Output Open Drain                           */
    }
    else
    {
        GPIOx->PTOD |=  (uint32_t)GPIO_InitAFStruct->GPIO_Pin;                      /*!< Configuring as Output Push                                 */
    }

#if  defined  USE_GPIO_FILT
    if (GPIO_InitAFStruct->GPIO_InputFilter == DISABLE)                             /*!< Judging whether the GPIO is enabled input filter           */
    {
        GPIOx->FILT &=  ~((uint32_t)GPIO_InitAFStruct->GPIO_Pin);                   /*!< Disable Input Filter                                       */
    }
    else
    {
        GPIOx->FILT |=  (uint32_t)GPIO_InitAFStruct->GPIO_Pin;                      /*!< Enable Input Filter                                        */
    }
#endif
    
#if defined USE_GPIO_HIIPM
    GPIOx->HIIPM &=  ~((uint32_t)GPIO_InitAFStruct->GPIO_Pin);                      /*!< Disable High Resistance                                    */
#endif
}

/**
*********************************************************************************************************
*                                          SET GPIO
*
* @brief:  Configuring GPIO as output high level,
*          this function is invaild for Pins of Input Mode or Alternate Function Mode
*
* @param:  GPIOx        Can only be one of the following Group
*                         @arg  HT_GPIOA
*                         @arg  HT_GPIOB
*                         @arg  HT_GPIOC
*                         @arg  HT_GPIOD
*                         @arg  HT_GPIOE
*                         @arg  HT_GPIOF  (If support)
*                         @arg  HT_GPIOG  (If support)
*                         @arg  HT_GPIOH  (If support)
*                         @arg  HT_GPIOI  (If support)
*                         @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin    Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_BitsSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));

    GPIOx->PTSET = (uint32_t)GPIO_Pin;                      /*!< Configuring GPIO as output high level */
}

/**
*********************************************************************************************************
*                                          RESET GPIO
*
* @brief:  Configuring GPIO as output low level,
*          this function is invaild for Pins of Input Mode or Alternate Function Mode
*
* @param:  GPIOx        Can only be one of the following Group
*                         @arg  HT_GPIOA
*                         @arg  HT_GPIOB
*                         @arg  HT_GPIOC
*                         @arg  HT_GPIOD
*                         @arg  HT_GPIOE
*                         @arg  HT_GPIOF  (If support)
*                         @arg  HT_GPIOG  (If support)
*                         @arg  HT_GPIOH  (If support)
*                         @arg  HT_GPIOI  (If support)
*                         @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin    Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_BitsReset(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));

    GPIOx->PTCLR = (uint32_t)GPIO_Pin;                      /*!< Configuring GPIO as output low level  */
}

/**
*********************************************************************************************************
*                                         TOGGLE GPIO
*
* @brief:  Toggling GPIO output level,
*          this function is invaild for Pins of Input Mode or Alternate Function Mode
*
* @param:  GPIOx        Can only be one of the following Group
*                         @arg  HT_GPIOA
*                         @arg  HT_GPIOB
*                         @arg  HT_GPIOC
*                         @arg  HT_GPIOD
*                         @arg  HT_GPIOE
*                         @arg  HT_GPIOF  (If support)
*                         @arg  HT_GPIOG  (If support)
*                         @arg  HT_GPIOH  (If support)
*                         @arg  HT_GPIOI  (If support)
*                         @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin    Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_BitsToggle(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));

    GPIOx->PTTOG = (uint32_t)GPIO_Pin;                      /*!< Toggling GPIO output level           */
}

/**
*********************************************************************************************************
*                                      READ GPIO BITS
*
* @brief:  Reading Input Value of specified GPIO,
*
* @param:  GPIOx        Can only be one of the following Group
*                         @arg  HT_GPIOA
*                         @arg  HT_GPIOB
*                         @arg  HT_GPIOC
*                         @arg  HT_GPIOD
*                         @arg  HT_GPIOE
*                         @arg  HT_GPIOF  (If support)
*                         @arg  HT_GPIOG  (If support)
*                         @arg  HT_GPIOH  (If support)
*                         @arg  HT_GPIOI  (If support)
*                         @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin    Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*
* @retval:  Input Value of specified GPIO
*
* @Note:    None
*********************************************************************************************************
**/
uint16_t HT_GPIO_BitsRead(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));

    return (uint16_t)(GPIOx->PTDAT & GPIO_Pin);             /*!< Reading Input Value of specified GPIO */
}

/**
*********************************************************************************************************
*                                 SET GPIO ON HIGH CURRENT MODE
*
* @brief:  Configuring specified GPIO as large current mode,
*          only part of GPIO Pins have this mode
*
* @param:  GPIO_Pin     Can only be one or more of the following Pins
*                         @arg  GPIO_HDPORT_PC0
*                         @arg  GPIO_HDPORT_PA6
*                         @arg  GPIO_HDPORT_PA7
*                         @arg  GPIO_HDPORT_PA8
*
*           NewState    = ENABLE： Enable Large Current Mode
*                       = DISABLE：Normal Current Mode
*
* @retval:  None
*
* @Note:    Only PC.0/PA.6/PA.7/PA.8 have large current mode
*********************************************************************************************************
**/
void HT_GPIO_HighCurrentSet(uint16_t GPIO_Pin, FunctionalState NewState)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_HighCurrent(GPIO_Pin));

    if (NewState != DISABLE)
    {
        HT_GPIOHDPORT |= (uint32_t)(GPIO_Pin & GPIO_HDPORT);    /*!< Enable Large Current Mode      */
    }
    else
    {
        HT_GPIOHDPORT &= ~(uint32_t)(GPIO_Pin & GPIO_HDPORT);   /*!< Disable Large Current Mode     */
    }
}

/**
*********************************************************************************************************
*                                    GPIO DIRECTION SET
*
* @brief:  Set Input or Output Status of specified GPIO in same Group
*
* @param:  GPIOx             Can only be one of the following Group
*                              @arg  HT_GPIOA
*                              @arg  HT_GPIOB
*                              @arg  HT_GPIOC
*                              @arg  HT_GPIOD
*                              @arg  HT_GPIOE
*                              @arg  HT_GPIOF  (If support)
*                              @arg  HT_GPIOG  (If support)
*                              @arg  HT_GPIOH  (If support)
*                              @arg  HT_GPIOI  (If support)
*                              @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin         Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_Direction     @arg  GPIO_Mode_IOIN   GPIO Input
*                              @arg  GPIO_Mode_IOOUT  GPIO Output
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_DirectionSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_Direction)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_Direction(GPIO_Direction));

    if(GPIO_Direction == GPIO_Mode_IOIN)                    /*!< Judging whether the GPIO is Digital Input */
    {
            GPIOx->PTDIR &= ~((uint32_t)GPIO_Pin);                 /*!< Configuring as Digital Input           */
    }
    else
    {
            GPIOx->PTDIR |= (uint32_t)GPIO_Pin;                    /*!< Configuring as Digital Output          */
    }
}

/**
*********************************************************************************************************
*                                    GPIO INPUT STATUS SET
*
* @brief:  Set Pullup or Input Floating Status of specified GPIO in same Group
*          this function is invaild for Pins of Output Mode(include Digital Output Alternate Function),
*          Analog Alternate Function or High Resistance Mode.
*
* @param:  GPIOx             Can only be one of the following Group
*                              @arg  HT_GPIOA
*                              @arg  HT_GPIOB
*                              @arg  HT_GPIOC
*                              @arg  HT_GPIOD
*                              @arg  HT_GPIOE
*                              @arg  HT_GPIOF  (If support)
*                              @arg  HT_GPIOG  (If support)
*                              @arg  HT_GPIOH  (If support)
*                              @arg  HT_GPIOI  (If support)
*                              @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin         Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_InputStatus   @arg  GPIO_Input_Up        GPIO Input Pullup
*                              @arg  GPIO_Input_Floating  GPIO Input Floating
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_InputStatusSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_InputStatus)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_InputStruct(GPIO_InputStatus));


    if(GPIO_InputStatus == GPIO_Input_Up)                  /*!< Judging whether the GPIO is Pullup or Input Floating  */
    {
        GPIOx->PTUP &=  ~((uint32_t)GPIO_Pin);                     /*!< Configuring as Input Pullup                   */
    }
    else
    {
        GPIOx->PTUP |=  (uint32_t)GPIO_Pin;                        /*!< Configuring as Input Floating                 */
    }
}

/**
*********************************************************************************************************
*                                    GPIO OUTPUT STATUS SET
*
* @brief:  Set Push or Open Drain Status of specified GPIO in same Group
*          this function is invaild for Pins of Input Mode(include Digital Input Alternate Function),
*          Analog Alternate Function or High Resistance Mode.
*
* @param:  GPIOx             Can only be one of the following Group
*                              @arg  HT_GPIOA
*                              @arg  HT_GPIOB
*                              @arg  HT_GPIOC
*                              @arg  HT_GPIOD
*                              @arg  HT_GPIOE
*                              @arg  HT_GPIOF  (If support)
*                              @arg  HT_GPIOG  (If support)
*                              @arg  HT_GPIOH  (If support)
*                              @arg  HT_GPIOI  (If support)
*                              @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin         Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_OutputStatus  @arg  GPIO_Output_OD      GPIO Output Open Drain
*                              @arg  GPIO_Output_PP      GPIO Output Push
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
void HT_GPIO_OutputStatusSet(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_OutputStatus)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_OutputStruct(GPIO_OutputStatus));

    if(GPIO_OutputStatus == GPIO_Output_OD)                /*!< Judging whether the GPIO is Push or Open Drain        */
    {
        GPIOx->PTOD &=  ~((uint32_t)GPIO_Pin);                      /*!< Configuring as Output Open Drain             */
    }
    else
    {
        GPIOx->PTOD |=  (uint32_t)GPIO_Pin;                         /*!< Configuring as Output Push                   */
    }

}

/**
*********************************************************************************************************
*                                    GPIO INPUT FILTER SET
*
* @brief:  Set Input Filter Status of specified GPIO in same Group
*
* @param:  GPIOx             Can only be one of the following Group
*                              @arg  HT_GPIOA
*                              @arg  HT_GPIOB
*                              @arg  HT_GPIOC
*                              @arg  HT_GPIOD
*                              @arg  HT_GPIOE
*                              @arg  HT_GPIOF  (If support)
*                              @arg  HT_GPIOG  (If support)
*                              @arg  HT_GPIOH  (If support)
*                              @arg  HT_GPIOI  (If support)
*                              @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin         Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_InputFilter   @arg  ENABLE      Enable Input Filter
*                              @arg  DISABLE     Disable Input Filter
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
#if defined USE_GPIO_FILT
void HT_GPIO_InputFilter(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_InputFilter)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_InputFilter(GPIO_InputFilter));

    if (GPIO_InputFilter == DISABLE)          /*!< Judging whether the GPIO is enabled input filter                   */
    {
        GPIOx->FILT &=  ~((uint32_t)GPIO_Pin);             /*!< Disable Input Filter                                  */
    }
    else
    {
        GPIOx->FILT |=  (uint32_t)GPIO_Pin;                /*!< Enable Input Filter                                   */
    }

}
#endif

/**
*********************************************************************************************************
*                                    GPIO NEW ALTERNATE FUNCTION STATUS SET
*
* @brief:  Set New Alternate Function Status of specified GPIO in same Group
*
* @param:  GPIOx             Can only be one of the following Group
*                              @arg  HT_GPIOA
*                              @arg  HT_GPIOB
*                              @arg  HT_GPIOC
*                              @arg  HT_GPIOD
*                              @arg  HT_GPIOE
*                              @arg  HT_GPIOF  (If support)
*                              @arg  HT_GPIOG  (If support)
*                              @arg  HT_GPIOH  (If support)
*                              @arg  HT_GPIOI  (If support)
*                              @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin         Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_NewAFCtrl     @arg  ENABLE      Enable New Alternate Functions
*                              @arg  DISABLE     Disable New Alternate Functions
* @retval:  None
*
* @Note:    None
*********************************************************************************************************
**/
#if defined USE_GPIO_NEWAFCTRL
void HT_GPIO_NewAFCtrl(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_NewAFCtrl)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_NewAFCtrl(GPIO_NewAFCtrl));

    if (GPIO_NewAFCtrl == DISABLE)          /*!< Judging whether the GPIO is enabled input filter        */
    {
        GPIOx->NEWAFEN &=  ~((uint32_t)GPIO_Pin);                   /*!< Disable New Alternate Functions */
    }
    else
    {
        GPIOx->NEWAFEN |=  (uint32_t)GPIO_Pin;                      /*!< Enable New Alternate Functions  */
    }

}
#endif

/**
*********************************************************************************************************
*                                    GPIO HIGH RESISTANCE SET
*
* @brief:  Configuring specified GPIO as High Resistance Status in same Group
*
* @param:  GPIOx                Can only be one of the following Group
*                                 @arg  HT_GPIOA
*                                 @arg  HT_GPIOB
*                                 @arg  HT_GPIOC
*                                 @arg  HT_GPIOD
*                                 @arg  HT_GPIOE
*                                 @arg  HT_GPIOF  (If support)
*                                 @arg  HT_GPIOG  (If support)
*                                 @arg  HT_GPIOH  (If support)
*                                 @arg  HT_GPIOI  (If support)
*                                 @arg  HT_GPIOJ  (If support)
*
*           GPIO_Pin            Configuring Pins:  GPIO_Pin_0 ~ GPIO_Pin_15
*           GPIO_HighResistance   @arg  ENABLE      Enable High Resistance
*                                 @arg  DISABLE     Disable High Resistance
* @retval:  None
*
* @Note:    The Priority of High Resistance is higher than other GPIO Modes except Analog Mode.
*********************************************************************************************************
**/
#if defined USE_GPIO_HIIPM
void HT_GPIO_High_Resistance_Set(HT_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint16_t GPIO_HighResistance)
{
    /*  assert_param  */
	assert_param(IS_HT_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_HT_GPIO_HighResistance(GPIO_HighResistance));

    if (GPIO_HighResistance == DISABLE)          /*!< Judging whether the GPIO is enabled High Resistance                    */
    {
        GPIOx->HIIPM &=  ~((uint32_t)GPIO_Pin);  /*!< Disable High Resistance                                                */
    }
    else
    {
        GPIOx->HIIPM |=  (uint32_t)GPIO_Pin;     /*!< Enable High Resistance                                                 */
    }

}
#endif

