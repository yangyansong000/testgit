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
* File         : example.c
* By           : Hitrendtech_SD
* Version      : V2.0.8
* Description  :
*********************************************************************************************************
*/

#define  __EXAMPLE_C
//#undef   __EXAMPLE_C

#ifdef   __EXAMPLE_C

#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/
#define DELAY_1MS_ADJ   ((uint32_t)11)

/*
*********************************************************************************************************
*                                             Local Variables
*********************************************************************************************************
*/
#if (USE_HT_UART_REGISTER_CALLBACKS == 1U)
/* UART handler declared in "main.c" file */
extern UART_InitTypeDef UartHandle;
extern ISO7816_InitTypeDef ISO7816Handle;
extern IR_InitTypeDef IRHandle;
#endif

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
/* RTC handler declared in "main.c" file */
extern RTC_InitTypeDef RtcHandle;
#endif

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
/* SPI handler declared in "main.c" file */
extern SPI_InitTypeDef SpiHandle;
#endif

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
/* PMU handler declared in "main.c" file */
extern PMU_InitTypeDef PmuHandle;
#endif

#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
/* TBS handler declared in "main.c" file */
extern TBS_InitTypeDef TBSHandle;
#endif

#if (USE_HT_WDT_REGISTER_CALLBACKS == 1U)
/* WDT handler declared in "main.c" file */
extern WDT_InitTypeDef WdtHandle;
#endif

#if (USE_HT_TMR_REGISTER_CALLBACKS == 1U)
/* TMR handler declared in "main.c" file */
extern TMR_InitTypeDef TimHandle;

#if defined USE_TMR_EXT
extern TMRExt_InitTypeDef TimExtHandle;
#endif



#endif

#if( USE_HT_EXTI_REGISTER_CALLBACKS ==1U)
/* EXTI handler declared in "main.c" file */
extern EXTI_TypeDef ExtiHandle;
#endif

#if defined USE_KEYSCAN
#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
/* KEY handler declaration */
extern KEY_InitTypeDef KeyHandle;
#endif
#endif

#if defined  HT501x  ||  defined  HT502x  ||  defined  HT503x
#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
/* EMU handler declared in "main.c" file */
extern EMU_InitTypeDef EmuHandle;
#endif
#endif
/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if( USE_HT_EXTI_REGISTER_CALLBACKS ==1U)
/* EXTI_InitCallbacksToDefault declared in "ht6xxx_exti.c" file */
extern void EXTI_InitCallbacksToDefault(EXTI_TypeDef *ExtiStruct);
#endif

/**
*********************************************************************************************************
*                                       DELAY EXAMPLES
*
* @brief: Delay function used by examples
*
* @param: mSec  number of 1 ms delay
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void Delay_Ms(uint32_t mSec)
{
    uint32_t delay;
	
    if(mSec != 0)
    {
	    /*!< Get current system clock */
	    delay = HT_CMU_CPUClkGet();

	    /*!< delay = 1ms * mSec */
	    delay = (delay*mSec)>>DELAY_1MS_ADJ;

	    /*!< wait N ms */
	    while(delay--){}
	}
}


/*
*********************************************************************************************************
*                                GPIO EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example of GPIO initialization
*
* @param: None
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void GPIO_Example(void)
{
#if defined USE_MCU
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitAFTypeDef  GPIO_InitAFStructure;
	
	/***** Follow Code Use to Set PA.0 and PA.1 as Output Push *****/
	GPIO_InitStructure.GPIO_Mode           = GPIO_Mode_IOOUT;
    GPIO_InitStructure.GPIO_Pin            = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_InputStruct    = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct   = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	GPIO_InitStructure.GPIO_InputFilter    = DISABLE;
    #endif
    #if defined USE_GPIO_NEWAFCTRL
	GPIO_InitStructure.GPIO_NewAFCtrl      = DISABLE;
    #endif

    HT_GPIO_Init(HT_GPIOA, &GPIO_InitStructure);
	
    #if defined USE_GPIO_HIIPM
    /***** Follow Code Use to Set PB.0 and PB.1 as HighResistance *****/
    GPIO_InitStructure.GPIO_Mode           = GPIO_Mode_HighResistance;
    GPIO_InitStructure.GPIO_Pin            = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_InputStruct    = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct   = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	GPIO_InitStructure.GPIO_InputFilter    = DISABLE;
    #endif
    #if defined USE_GPIO_NEWAFCTRL
	GPIO_InitStructure.GPIO_NewAFCtrl      = DISABLE;
    #endif

    HT_GPIO_Init(HT_GPIOB, &GPIO_InitStructure);
	#endif

    /***** Follow Code Use to Set PC.4, PC.5, PC.6 and PC.7 as SPI Pins  *****/
    GPIO_InitAFStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitAFStructure.GPIO_AFMode = PC4_SPI0_MOSI | PC5_SPI0_MISO | PC6_SPI0_CLK | PC7_SPI0_CS;
    GPIO_InitAFStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitAFStructure.GPIO_OutputStruct = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
    GPIO_InitAFStructure.GPIO_InputFilter    = DISABLE;
    #endif
    #if defined USE_GPIO_NEWAFCTRL
    GPIO_InitAFStructure.GPIO_NewAFCtrl      = DISABLE;
    #endif

	HT_GPIO_AFInit(HT_GPIOC, &GPIO_InitAFStructure);
#endif

}

#if defined USE_EMU_CONST
/*
*********************************************************************************************************
*                                EMU CONST EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example of EMU Const initialization
*
* @param: None
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void EMU_Const_Example(void)
{
    CMU_InitTypeDef  CMU_InitStructure;
    EMUConst_InitTypeDef EMUConst_InitStruct;

	  /***** Initial EMU Const Module *****/
    CMU_InitStructure.SysClkSel = SysPLLX2;
    CMU_InitStructure.CPUDiv = CPUDiv2;

    HT_CMU_Init(&CMU_InitStructure);
    
    EMUConst_InitStruct.EMU_PowerQ_Set  = 0x10000000;
    EMUConst_InitStruct.EMU_PowerP_Set  = 0x20000000;
    EMUConst_InitStruct.EMU_HFConst_SET = 0x0020;
#if defined USE_EMU_CONST_CLKSEL
    EMUConst_InitStruct.EMU_EMUClk_Sel  = EMUClkSel_PLLx2;
    EMUConst_InitStruct.EMU_EMUClk_DIV  = 0x0002;
#endif 
  
    HT_EMU_Const_Init(&EMUConst_InitStruct);
	
}
#endif

#if defined USE_KEYSCAN
/**
*********************************************************************************************************
*                                         EXAMPLES FOR USER KEY PROCESS
*
* @brief: User KEY process.
*
* @param: KEY_InitStruct  Pointer to a KEY_InitTypeDef structure that contains
*                the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
void HT_KeyScan_Proc(KEY_InitTypeDef *KEY_InitStruct)
{
    switch(KEY_InitStruct->Instance->KEYSTA)
    {
        case KEY_KEYSTA_STA0:
            break;
        case KEY_KEYSTA_STA1:
            break;
        case KEY_KEYSTA_STA2:
            break;
        case KEY_KEYSTA_STA3:
            break;
        case KEY_KEYSTA_STA4:
            break;
        case KEY_KEYSTA_STA5:
            break;
        case KEY_KEYSTA_STA6:
            break;
        case KEY_KEYSTA_STA7:
            break;
        case KEY_KEYSTA_STA8:
            break;
        case KEY_KEYSTA_STA9:
            break;
        case KEY_KEYSTA_STA10:
            break;
        case KEY_KEYSTA_STA11:
            break;
        case KEY_KEYSTA_STA12:
            break;
        case KEY_KEYSTA_STA13:
            break;
        case KEY_KEYSTA_STA14:
            break;
        case KEY_KEYSTA_STA15:
            break;
        default:
            break;
    }
}

/**
*********************************************************************************************************
*                                         EXAMPLES FOR USER KEY CALLBACK
*
* @brief: User KEY callbacks.
*
* @param: KEY_InitStruct  Pointer to a KEY_InitTypeDef structure that contains
*                the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_User_KeyCallback(KEY_InitTypeDef *KEY_InitStruct)
{
    HT_KeyScan_Proc(KEY_InitStruct);
}

/**
*********************************************************************************************************
*                                         EXAMPLES FOR KEY CALLBACK
*
* @brief: KEY callbacks.
*
* @param: KEY_InitStruct  Pointer to a KEY_InitTypeDef structure that contains
*                the configuration information for the specified KEY module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_KEY_KeyCallback(KEY_InitTypeDef *KEY_InitStruct)
{
    HT_KeyScan_Proc(KEY_InitStruct);
}
#endif
/*
*********************************************************************************************************
*                                KEYSCAN EXAMPLES
*
* @brief: Use library functions to example of KEYSCAN initialization
*
* @param: None
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void KEYSCAN_Example(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    /***** Follow Code Use to Configure KEYSCAN module *****/
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_KEYEN,ENABLE);
    
#if defined USE_CMU_KEYCLKCFG
    HT_KEY_ClkConfig(KeyClkLrc);
#endif	
	
	/***** Follow Code Use to Set PA.5/PA.6 as SCANIN Pins *****/
    GPIO_InitStructure.GPIO_Pin            = GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode           = GPIO_Mode_AF2;
    GPIO_InitStructure.GPIO_InputStruct    = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct   = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	  GPIO_InitStructure.GPIO_InputFilter  = DISABLE;
    #endif
    HT_GPIO_Init(HT_GPIOA, &GPIO_InitStructure);
    
    /***** Follow Code Use to Set PC.9/PC.10 as SCANIN Pins *****/
    GPIO_InitStructure.GPIO_Pin            = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode           = GPIO_Mode_AF2;
    GPIO_InitStructure.GPIO_InputStruct    = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct   = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	  GPIO_InitStructure.GPIO_InputFilter  = DISABLE;
    #endif
    HT_GPIO_Init(HT_GPIOC, &GPIO_InitStructure);
    
    /***** Follow Code Use to Set PD.2/PD.3/PD.4/PD.5 as SCANOUT Pins *****/
    GPIO_InitStructure.GPIO_Pin            = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode           = GPIO_Mode_AF2;
    GPIO_InitStructure.GPIO_InputStruct    = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct   = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	  GPIO_InitStructure.GPIO_InputFilter  = DISABLE;
    #endif
    HT_GPIO_Init(HT_GPIOD, &GPIO_InitStructure);

#if (USE_HT_KEY_REGISTER_CALLBACKS == 1U)
    HT_KEY_Init(HT_KEY,&KeyHandle);
    HT_KEY_RegisterCallback(&KeyHandle, KEY_CB_ID, HT_User_KeyCallback);  /* this sentence is NO need if you want to use default KeyCallback function */  
    NVIC_EnableIRQ(KEY_IRQn);
#endif

}
#endif

/*
*********************************************************************************************************
*                                CMU EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example of CMU initialization
*
* @param: None
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void CMU_Example(void)
{
    /***** The following code is used to configure the PLL clock,the CPU clock is decaves of the system clock *****/

    CMU_InitTypeDef  CMU_InitStructure;
    
    Delay_Ms(800);      //delay 800ms
    
    CMU_InitStructure.SysClkSel = SysPLL;
    CMU_InitStructure.CPUDiv = CPUDiv2;

    HT_CMU_Init(&CMU_InitStructure);
}

/**
*********************************************************************************************************
*                                       PMU EXAMPLES
*
* @brief: Use library functions to example the PMU configuration
*
* @param: None
*
* @retval: None
*
* @note: Does not participate in project compilation by default
*********************************************************************************************************
*/
void PMU_Example(void)
{

#if (USE_HT_PMU_REGISTER_CALLBACKS == 1U)
	  PmuHandle.Lvdin0State = LVDINEnable;                /*!< LVDIN0 enable                */

    #if  defined  USE_BOR_MCU
        PmuHandle.BorLvlSet = BORLVL_2V2;                   /*!< BOR threshold value 2.2v                  */
    #elif defined  USE_BOR_SOC
        PmuHandle.BorLvlSet = BORLVL_2V4;                   /*!< BOR threshold value 2.4v                  */
    #else
        PmuHandle.BorLvlSet = BORLVL_2V4;                   /*!< BOR threshold value 2.4v                  */
    #endif
        PmuHandle.BorState = BORReset;                      /*!< BOR generate a system reset                  */

    #if defined USE_VCCLVL_501x
        PmuHandle.VccLvlSet = VccLVL_2V8;                   /*!< Vcc threshold value 2.8v              */
    #elif defined USE_VCCLVL_633x
        PmuHandle.VccLvlSet = VccLVL_3V3;                   /*!< Vcc threshold value 3.3v                */
    #else
        PmuHandle.VccLvlSet = VccLVL_4V0;                   /*!< Vcc threshold value 4v                */
    #endif
        PmuHandle.VccBorDetPeriod = DETPRD_1072mS;          /*!< Vcc and Bor Time-sharing detection cycle =1072ms  */
    #if defined USE_DETTIM_TYPE_1
        PmuHandle.VccBorDetTime = DETTIM_300uS;        
    #elif defined USE_DETTIM_TYPE_2
        PmuHandle.VccBorDetTime = DETTIM_336uS;

    #elif defined USE_DETTIM_TYPE_3 
        PmuHandle.VccBorDetTime = DETTIM_427uS;
    #endif
        HT_PMU_Init(&PmuHandle);
#else
	PMU_InitTypeDef  PMU_InitStructure;

    PMU_InitStructure.Lvdin0State = LVDINEnable;                /*!< LVDIN0 enable                 */

    #if  defined  USE_BOR_MCU
        PMU_InitStructure.BorLvlSet = BORLVL_2V2;                   /*!< BOR threshold value 2.2v                  */
    #elif defined  USE_BOR_SOC
        PMU_InitStructure.BorLvlSet = BORLVL_2V4;                   /*!< BOR threshold value 2.4v                  */
    #else
        PMU_InitStructure.BorLvlSet = BORLVL_2V4;                   /*!< BOR threshold value 2.4v                  */
    #endif
        PMU_InitStructure.BorState = BORReset;                      /*!< BOR generate a system reset           */

    #if defined USE_VCCLVL_501x
        PMU_InitStructure.VccLvlSet = VccLVL_2V8;                   /*!< Vcc threshold value 2.8v              */
    #elif defined USE_VCCLVL_633x
        PMU_InitStructure.VccLvlSet = VccLVL_3V3;                           /*!< Vcc threshold value 3.3v                */
    #else
        PMU_InitStructure.VccLvlSet = VccLVL_4V0;                   /*!< Vcc threshold value 4v                */
    #endif
        PMU_InitStructure.VccBorDetPeriod = DETPRD_1072mS;          /*!< Vcc and Bor Time-sharing detection cycle =1072ms  */
    #if defined USE_DETTIM_TYPE_1
        PMU_InitStructure.VccBorDetTime = DETTIM_300uS; 
    #elif defined USE_DETTIM_TYPE_2
        PMU_InitStructure.VccBorDetTime = DETTIM_336uS;
    #elif defined USE_DETTIM_TYPE_3
        PMU_InitStructure.VccBorDetTime = DETTIM_427uS;
	#endif
        HT_PMU_Init(&PMU_InitStructure);
#endif
}

/**
*********************************************************************************************************
*                                UART EXAMPLES FOR HT50XX
*
* @brief: Initialize examples of UART using library functions
*
* @param: None
*
* @retval: None
*
* @Note:This function does not participate in project compilation by default
*********************************************************************************************************
*/
void UART_Example(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
#if (USE_HT_UART_REGISTER_CALLBACKS == 1)
    /***** The following code is used to configure the chip UART0 module *****/

    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART0EN, ENABLE);        /*!< Enable UART0 module                */

    UartHandle.UART_Logic = UartLogicPositive;          /*!< UartLogicPositive                          */
    UartHandle.UART_StopBits = OneStopBits;             /*!< OneStopBits                                */
    UartHandle.UART_WordLength = WordLength_8Bits;      /*!< WordLength_8Bits                           */
    UartHandle.UART_Parity = UartParity_EVEN;           /*!< EVEN                                       */
    UartHandle.UART_BaudRate = 2400;                    /*!< UART_BaudRate 2400                         */
    UartHandle.ReceiveEN = ENABLE;                      /*!< Receive enable                             */
    UartHandle.SendEN = ENABLE;                         /*!< Send enable                                */

    HT_UART_Init(HT_UART0, &UartHandle);

#else
    /***** The following code is used to configure the chip UART0 module *****/
	UART_InitTypeDef UART_InitStructure;

    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART0EN, ENABLE);        /*!< Enable UART0 module                */
    UART_InitStructure.UART_Logic = UartLogicPositive;          /*!< UartLogicPositive                  */
    UART_InitStructure.UART_StopBits = OneStopBits;             /*!< OneStopBits                        */
    UART_InitStructure.UART_WordLength = WordLength_8Bits;      /*!< WordLength_8Bits                   */
    UART_InitStructure.UART_Parity = UartParity_EVEN;           /*!< EVEN                               */
    UART_InitStructure.UART_BaudRate = 2400;                    /*!< UART_BaudRate 2400                 */
    UART_InitStructure.ReceiveEN = ENABLE;                      /*!< Receive enable                     */
    UART_InitStructure.SendEN = ENABLE;                         /*!< Send enable                        */
    HT_UART_Init(HT_UART0, &UART_InitStructure);

#endif
    HT_UART_ITConfig(HT_UART0, UART_UARTCON_RXIE, ENABLE);
    NVIC_EnableIRQ(UART0_IRQn);
    
    /***** PC2£¬PC3 used for UART *****/    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF1;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;
#if defined USE_GPIO_FILT
	GPIO_InitStructure.GPIO_InputFilter = DISABLE;
#endif
#if defined USE_GPIO_NEWAFCTRL
    GPIO_InitStructure.GPIO_NewAFCtrl = DISABLE;
#endif
    HT_GPIO_Init(HT_GPIOC, &GPIO_InitStructure);
}

/**
*********************************************************************************************************
*                                 IR EXAMPLES FOR HT60XX
*
* @brief: Initialize examples of IR using library functions
*
* @param: None
*
* @retval: None
*
* @Note:This function does not participate in project compilation by default
*********************************************************************************************************
*/
void IR_Example(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
#if (USE_HT_UART_REGISTER_CALLBACKS == 1)

    /***** The following code is used to configure the chip IR module,excluding the GPIO configuration *****/
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART0EN, ENABLE);               /*!< Enable UART0 module         */

    IRHandle.UARTModule.UART_Logic = UartLogicPositive;      
    IRHandle.UARTModule.UART_StopBits = OneStopBits;
    IRHandle.UARTModule.UART_WordLength = WordLength_8Bits;
    IRHandle.UARTModule.UART_Parity = UartParity_EVEN;
    IRHandle.UARTModule.UART_BaudRate = 2400;
    IRHandle.UARTModule.ReceiveEN = ENABLE;
    IRHandle.UARTModule.SendEN = ENABLE;

    IRHandle.IRPolarity = IRPolarityPositive;                  /*!< IR              */
    IRHandle.IRDuty = IRDuty50;
    #if  defined  USE_UART_IRCON_IRCLKSRC
    IRHandle.IRClkSrc = IR_HRC_SOURCE;           /*!< Select IR CLOCK source  */
    #elif defined USE_UART_IRCLKSRC
    IRHandle.IRCLKSRC = IR_HRC_SOURCE; 
    #endif
    
    #if  defined  USE_UART_IRCLKDIV  
    IRHandle.IRClkDiv16 = 0x01;
    #endif    
    HT_IR_Init(HT_UART0, &IRHandle);
    
    
#else
    
    IR_InitTypeDef IR_InitStructure;
	HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART0EN, ENABLE);      /*!< Enable UART0 module     */

    IR_InitStructure.UARTModule.UART_Logic = UartLogicPositive;      
    IR_InitStructure.UARTModule.UART_StopBits = OneStopBits;
    IR_InitStructure.UARTModule.UART_WordLength = WordLength_8Bits;
    IR_InitStructure.UARTModule.UART_Parity = UartParity_EVEN;
    IR_InitStructure.UARTModule.UART_BaudRate = 2400;
    IR_InitStructure.UARTModule.ReceiveEN = ENABLE;
    IR_InitStructure.UARTModule.SendEN = ENABLE;

    IR_InitStructure.IRPolarity = IRPolarityPositive;         /*!< IR config               */
    IR_InitStructure.IRDuty = IRDuty50;
    #if  defined  USE_UART_IRCON_IRCLKSRC
    IR_InitStructure.IRClkSrc = IR_HRC_SOURCE;                /*!< Select IR CLOCK source  */
    #elif defined USE_UART_IRCLKSRC
    IR_InitStructure.IRCLKSRC = IR_HRC_SOURCE; 
    #endif
    
    #if  defined  USE_UART_IRCLKDIV  
    IR_InitStructure.IRClkDiv16 = 0x01;
    #endif 
    
    HT_IR_Init(HT_UART0, &IR_InitStructure);
#endif

    HT_UART_ITConfig(HT_UART0, UART_UARTCON_RXIE, ENABLE);
    NVIC_EnableIRQ(UART0_IRQn);
    
    /***** PC2£¬PC3 used for UART *****/    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF1;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;
    #if defined USE_GPIO_FILT
	GPIO_InitStructure.GPIO_InputFilter = DISABLE;
    #endif
    #if defined USE_GPIO_NEWAFCTRL
    GPIO_InitStructure.GPIO_NewAFCtrl = DISABLE;
    #endif
    HT_GPIO_Init(HT_GPIOC, &GPIO_InitStructure);


}
/**
*********************************************************************************************************
*                                 ISO7816 EXAMPLES FOR HT60XX
*
* @brief: Initialize examples of IR using library functions
*
* @param: None
*
* @retval: None
*
* @Note:This function does not participate in project compilation by default
*********************************************************************************************************
*/
void ISO7816_Example(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
#if (USE_HT_UART_REGISTER_CALLBACKS == 1)
	/***** The following code is used to configure the chip 7816 module,excluding the GPIO configuration *****/
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART3_7816_1EN, ENABLE);     /*!< Enable 7816_1                    */

    ISO7816Handle.ISO7816_Parity = ISO7816Parity_EVEN;              /*!< EVEN                             */
    ISO7816Handle.ISO7816_RepeatTime = Repeat_Zero;                 /*!< Auto resend times is set to zero */
    ISO7816Handle.AutoRxEN = DISABLE;                               /*!< Auto receive disable             */
    ISO7816Handle.AutoTxEN = DISABLE;                               /*!< Auto send disable                */
    ISO7816Handle.ISO7816_AckLen = ACKLen_1P5Bit;                   /*!< ACKLen_1P5Bit                    */
    ISO7816Handle.ISO7816_BaudRate = 9600;                          /*!< ISO7816_BaudRate 9600            */

    HT_ISO7816_Init(HT_ISO7816_1, &ISO7816Handle);
#else
    /***** The following code is used to configure the chip 7816 module,excluding the GPIO configuration *****/
    
    ISO7816_InitTypeDef  ISO7816_InitStructure;

    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART3_7816_1EN, ENABLE);     /*!< Enable 7816_1                    */

    ISO7816_InitStructure.ISO7816_Parity = ISO7816Parity_EVEN;      /*!< EVEN                             */
    ISO7816_InitStructure.ISO7816_RepeatTime = Repeat_Zero;         /*!< Auto resend times is set to zero */
    ISO7816_InitStructure.AutoRxEN = DISABLE;                       /*!< Auto receive disable             */
    ISO7816_InitStructure.AutoTxEN = DISABLE;                       /*!< Auto send disable                */
    ISO7816_InitStructure.ISO7816_AckLen = ACKLen_1P5Bit;           /*!< ACKLen_1P5Bit                    */
    ISO7816_InitStructure.ISO7816_BaudRate = 9600;                  /*!< ISO7816_BaudRate 9600            */

    HT_ISO7816_Init(HT_ISO7816_1, &ISO7816_InitStructure);
#endif

    HT_ISO7816_ITConfig(HT_UART3, UART_ISO7816CON_RXIE, ENABLE);
	NVIC_EnableIRQ(UART3_IRQn);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF1;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_InputStruct = GPIO_Input_Up;
    GPIO_InitStructure.GPIO_OutputStruct = GPIO_Output_PP;
    
    HT_GPIO_Init(HT_GPIOE, &GPIO_InitStructure);
#if defined USE_GPIO_FILT
	GPIO_InitStructure.GPIO_InputFilter = DISABLE;
#endif
#if defined USE_GPIO_NEWAFCTRL
    GPIO_InitStructure.GPIO_NewAFCtrl = DISABLE;
#endif
    HT_GPIO_Init(HT_GPIOC, &GPIO_InitStructure);

}

/**
*********************************************************************************************************
*                                  LCD EXAMPLES 
*
* @brief: LCD Moudle Function Init
*          step1: configure LCD parameters
*              2: call HT_LCD_Init(), write to LCD registers  
* @param: None
* @retval:None 
*********************************************************************************************************
*/
#if defined USE_LCD	
void LCD_Example(void)
{
    LCD_InitTypeDef  LCD_InitStructure;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_LCDEN, ENABLE);            /*!< Enable LCD moudle     */

    LCD_InitStructure.LCD_Bias = LCDBias_OneThird;                /*!< 1/3 bias set          */
    LCD_InitStructure.LCD_Com  = LCD_6COM;                        /*!< 6Com set              */
    LCD_InitStructure.LCD_CLK  = LCDCLK_Div1;                     /*!< Flcd set              */
#if defined USE_LCDChargeMode	
    LCD_InitStructure.LCD_ChargeMode  = LCDCharge_HighCurrent;    /*!< charge mode           */
#endif	
    LCD_InitStructure.LCD_Vrsel = 0x02;                           /*!< Vrsel                 */

    HT_LCD_Init(&LCD_InitStructure);
}
#endif

#if  defined  HT6x2x  ||  defined  HT6x3x  ||  defined  HT6x2xK ||  defined  HT762x ||  defined  HT772x  ||  defined HT633x ||  defined  HT503x
/**
*********************************************************************************************************
*                                  SPI EXAMPLES FOR HT60XX
*
* @brief:  Initialize the sample SPI using library functions
*
* @param:  None
*
* @retval: None
*
* @Note:   This function does not participate in project compilation by default
*********************************************************************************************************
*/
void SPI_Example(void)
{
	/* The following code is used to configure the SPI and does not contain the GPIO configuration */
#if (USE_HT_SPI_REGISTER_CALLBACKS == 1)
   	HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_SPI1EN, ENABLE);            /*!<Enable the SPI1 module*/
	SpiHandle.SPI_CSInCtrol = ENABLE;
	SpiHandle.SPI_Baudrate = SPI_BaudRatePrescaler_128;            
	SpiHandle.SPI_CPHA = SPI_CPHA_1Edge;
	SpiHandle.SPI_CPOL = SPI_CPOL_Low;
	SpiHandle.SPI_Mode = SPI_Master;
	#if defined  USE_SPI_SPICON_FASTEN
	SpiHandle.SPI_FASTEN = SPI_SlowSlave;
	#endif
	#if defined  USE_SPI_SPICON_LSBEN
	SpiHandle.SPI_LSBEN = SPI_MSB;
	#endif
    HT_SPI_Init(HT_SPI1, &SpiHandle);
    
    #if defined USE_SPI_FIFO 
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_TXFIFOEN = DISABLE; 
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_RXFIFOEN = DISABLE;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_FSEN = DISABLE;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_TXFIFORST = FIFO_TXFIFORST_1;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_RXFIFORST = FIFO_RXFIFORST_1;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_HLCS = FIFO_HLCS_HIGH;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_EXINSEL = FIFO_EXINSEL_APB;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_TXFIFOTL = 0x03;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_RXFIFOTL = 0x03;
	SpiHandle.SPI_FIFOInitStruct.SPIFIFO_CTR = FIFOCTR_3P0;
    SpiHandle.SPI_FIFOInitStruct.Instance = HT_SPI1;      
	HT_SPI_FIFOInit(HT_SPI1, &SpiHandle);
    #endif	   
#else
    SPI_InitTypeDef  SPI_InitStructure;
   
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_SPI1EN, ENABLE); 
    SPI_InitStructure.SPI_CSInCtrol = ENABLE;
    SPI_InitStructure.SPI_Baudrate = SPI_BaudRatePrescaler_32;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_high;
    SPI_InitStructure.SPI_Mode = SPI_Master;

    HT_SPI_Init(HT_SPI1, &SPI_InitStructure);
#endif
}
#endif

/**
*********************************************************************************************************
*                                  TIMER 0~3 EXAMPLES FOR HT60XX
*
* @brief: Example of using library functions to initialize Timer0~3
*

* @param: None
* @retval: None
*
* @Note: This function does not participate in project compilation by default
*********************************************************************************************************
*/
void TMR_Example(void)
{
    /***** The following code is used to configure timer 0, without GPIO configuration *****/
#if (USE_HT_TMR_REGISTER_CALLBACKS == 1)
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_TMR0EN, ENABLE);    /*!< Enable TIMER0 module                             */
    TimHandle.TimerMode = TIMCycleTiming;                  /*!< Timer is set to timer function                   */
    TimHandle.TimerPreDiv = 0x00;                          /*!< set  TMRDIV                                      */
    TimHandle.TimerPeriod = 1 * HT_CMU_SysClkGet()/(TimHandle.TimerPreDiv + 1) - 1;/*!< Set timing period = 1s */
    TimHandle.TimerCompare = 0x00;                         /*!< Set compare register                             */

#if  defined  USE_TMR_OPMODE
    TimHandle.TimerOPModeEnable =  DISABLE;                /*!< disable  One pulse mode                          */
#endif
    
    
    HT_TMR_Init(HT_TMR0, &TimHandle);

#else
    TMR_InitTypeDef  TMR_InitStructure;

    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_TMR0EN, ENABLE);    /*!< Enable TIMER0 module                             */

    TMR_InitStructure.TimerMode = TIMCycleTiming;          /*!< Timer is set to timer function                   */
    TMR_InitStructure.TimerPreDiv = 0x00;                  /*!< set  TMRDIV                                      */
    TMR_InitStructure.TimerPeriod = 1 * HT_CMU_SysClkGet()/(TMR_InitStructure.TimerPreDiv + 1) - 1;/*!< Set timing period = 1s */
    TMR_InitStructure.TimerCompare = 0x00;                 /*!< Set compare register                             */

#if  defined  USE_TMR_OPMODE
    TMR_InitStructure.TimerOPModeEnable =  DISABLE;        /*!< disable  One pulse mode                          */

#endif

    HT_TMR_Init(HT_TMR0, &TMR_InitStructure);
#endif
}


/**
*********************************************************************************************************
*                                  TIMER4~5 EXAMPLES FOR HT60XX
*
* @brief: Example of using library functions to initialize Timer4~5
*

* @param: None
* @retval: None
*
* @Note: This function does not participate in project compilation by default
*********************************************************************************************************
*/

#if defined USE_TMR_EXT

void TMRExt_Example(void)
{
    /***** The following code is used to configure timer5, without GPIO configuration *****/
#if (USE_HT_TMR_REGISTER_CALLBACKS == 1)
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_TMR5EN, ENABLE);         /*!< Enable TIMER5 module                        */
    TimExtHandle.TimerSource = TIMExtClk_PLL;                   /*!< Timer5 clock source is PLL                  */
    TimExtHandle.TimerMode = TIMExtCycleTiming;                 /*!< Timer is set to timer function              */
    TimExtHandle.TimerPreDiv = 0x0000;                          /*!<  set  TMRDIV                                */
    TimExtHandle.TimerPeriod = 1 * HT_CMU_SysClkGet()/(TimExtHandle.TimerPreDiv + 1) - 1;/*!< Set timing period = 1s */
    TimExtHandle.TimerCompare = 0x0000;                         /*!< Set compare register                        */


	#if  defined  USE_TMREXT_EXTEND_FUNC
    TimExtHandle.TimExtOPModeEnable =  DISABLE;                 /*!< disable  One pulse mode                     */
    TimExtHandle.TimCapEvtTrigEnable = DISABLE;                 /*!< disable the  Extended Input source function */
    TimExtHandle.TimExTrigEnable =  DISABLE;                    /*!< disable the  External Trigger start-up timer function */
	#endif

    HT_TMRExt_Init(HT_TMR5, &TimExtHandle);


#else
    TMRExt_InitTypeDef TMRExt_InitStruct;

    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_TMR5EN, ENABLE);         /*!< Enable TIMER5 module                           */
    TMRExt_InitStruct.TimerSource = TIMExtClk_PLL;              /*!< Timer5 clock source is PLL                     */
    TMRExt_InitStruct.TimerMode = TIMExtCycleTiming;            /*!< Timer is set to timer function                 */
    TMRExt_InitStruct.TimerPreDiv = 0x0000;                     /*!<  set  TMRDIV                                   */
    TMRExt_InitStruct.TimerPeriod = 1 * HT_CMU_SysClkGet()/(TMRExt_InitStruct.TimerPreDiv + 1) - 1;/*!< Set timing period = 1s */
    TMRExt_InitStruct.TimerCompare = 0x0000;                    /*!< Set compare register                           */


	#if  defined  USE_TMREXT_EXTEND_FUNC
    TMRExt_InitStruct.TimExtOPModeEnable =  DISABLE;            /*!< disable  One pulse mode                        */
    TMRExt_InitStruct.TimCapEvtTrigEnable = DISABLE;            /*!< disable the  Extended Input source function    */
    TMRExt_InitStruct.TimExTrigEnable =  DISABLE;               /*!< disable the  External Trigger start-up timer function */
	#endif

    HT_TMRExt_Init(HT_TMR5, &TMRExt_InitStruct);
#endif
}



#endif









/**
*********************************************************************************************************
*                                   RTC EXAMPLES FOR HT60XX
*
* @brief:  Initialize the sample RTC using library functions
*
* @param:  None
*
* @retval: None
*
* @Note:   This function does not participate in project compilation by default
*********************************************************************************************************
*/
void RTC_Example(void)	
{
	/* The following code is used to configure the RTC and does not contain the GPIO configuration */	
#if (USE_HT_RTC_REGISTER_CALLBACKS == 1)
	RtcHandle.RTC_TMR1.NewState = ENABLE;               /*!< Enable RTC timer 1   */
	RtcHandle.RTC_TMR1.Count = 5;                       /*!< Timing period set 6s */
    RtcHandle.RTC_TMR2.NewState = DISABLE;              /*!< Disable RTC timer 2  */
    RtcHandle.RTC_TMR2.Count = 0;

    RtcHandle.RTC_Alarm.Muster.hour = 0x17;             /*!< No alarm */
    RtcHandle.RTC_Alarm.Muster.minute = 0x3B;

    RtcHandle.RTC_TOUT = Tout1Hz;                       /*!<Tout output 1 Hz */

    HT_RTC_Init(&RtcHandle);
#else
    RTC_InitTypeDef  RTC_InitStructure;

    RTC_InitStructure.RTC_TMR1.NewState = ENABLE;                /*!< Enable RTC timer 1   */
    RTC_InitStructure.RTC_TMR1.Count = 5;                        /*!< Timing period set 6s */
    RTC_InitStructure.RTC_TMR2.NewState = DISABLE;               /*!< Disable RTC timer 2  */
    RTC_InitStructure.RTC_TMR2.Count = 0;

    RTC_InitStructure.RTC_Alarm.Muster.hour = 0x17;              /*!< No alarm */
    RTC_InitStructure.RTC_Alarm.Muster.minute = 0x3B;

    RTC_InitStructure.RTC_TOUT = Tout1Hz;                       /*!<Tout output 1 Hz */

    HT_RTC_Init(&RTC_InitStructure);
#endif
    HT_RTC_ITConfig(RTC_RTCIE,ENABLE);
    NVIC_EnableIRQ(RTC_IRQn);
}
/**
*********************************************************************************************************
*                                  EXTI EXAMPLES FOR HT60XX
*
* @brief: Example of using library functions to initialize EXTI
*

* @param: None
* @retval: None
*
* @Note: This function does not participate in project compilation by default
*********************************************************************************************************
*/
void EXTI_Example(void)
{
    /***** The following code is used to configure the Rise edge of INT7   *****/
#if (USE_HT_EXTI_REGISTER_CALLBACKS == 1)

    HT_EXTI_InitCallback(&ExtiHandle);
    
    HT_EXTIFall_ITConfig(INT_EXTIE_FIE_INT0,ENABLE);              /*configure the fall edge of INT0 */
    /*   HT_EXTIRise_ITConfig(INT_EXTIE2_RIE_INT7,ENABLE);              configure the Rise edge of INT7 */
#else
    HT_EXTIFall_ITConfig(INT_EXTIE_FIE_INT0,ENABLE);              /*configure the fall edge of INT0 */
    /*   HT_EXTIRise_ITConfig(INT_EXTIE2_RIE_INT7,ENABLE);              configure the Rise edge of INT7 */
#endif
}

/**
*********************************************************************************************************
*                                   TBS EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example the TBS configuration
*
* @param: None
*
* @retval: None
*
* @note: The following code does not participate in project compilation by default 
*********************************************************************************************************
*/
void TBS_Example(void)
{
    /***** The following code is used to configure TBS moduleï¼Œenable temperature and battery voltage measurement and set the period*****/

/*!<    HT_TBS_PeriodSet(TBS_TMP, TBS_TBSPRD_TMPPRD_OSC1S_MEM4S);     temperature measurent open per 1s            */
/*!<    HT_TBS_PeriodSet(TBS_VBAT, TBS_TBSPRD_VBATPRD_8S);            battery voltage measurement open per 8s      */
#if  !defined  USE_TBS_TDVREFDAT
    HT_TBSConfig(TBS_TBSCON_TMPEn|TBS_TBSCON_VBATEn, ENABLE);      /*!< Enable temperature and battery voltage measurement */
#else
    HT_TBSConfig(TBS_TBSCON_TMPEn|TBS_TBSCON_TDVREFEn, ENABLE);    /*!< Enable temperature and battery voltage measurement */
#endif
    
#if (USE_HT_TBS_REGISTER_CALLBACKS == 1U)
	HT_TBS_Init(&TBSHandle);
#endif
}

/**
*********************************************************************************************************
*                                   FLASH EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example the Flash configuration
*
* @param: None
*
* @retval: None
*
* @note: The following code does not participate in project compilation by default 
*********************************************************************************************************
*/
void Flash_Example(void)
{
    const uint8_t WriteCode[]={0,1,2,3,4,5,6,7,8,9};

    HT_Flash_PageErase(0x1FC00);                 /*!< Erase the page where address 0x1FC00 resides  */

    HT_Flash_ByteWrite(WriteCode, 0x1FC00, sizeof(WriteCode));
                                                 /*!< Write 10 bytes to address 0x1FC00             */
}

/*
*********************************************************************************************************
*                                 Interrupt EXAMPLES FOR HT60XX
*
* @brief: Use library functions to example of RTC interrupt enables
*
* @param: None
*
* @retval: None
*
* @note: The following code does not participate in project compilation by default
*********************************************************************************************************
*/
void Interrupt_Example(void)
{
    /***** The following code is used to enable minute and second interrupt of RTC *****/

    HT_RTC_ITConfig(RTC_RTCIE_MINIE|RTC_RTCIE_HRIE, ENABLE);

    NVIC_EnableIRQ(RTC_IRQn);                                  /*!< Enable RTC interrupt */

    /***** The following code is used to disable minute and second interrupt of RTC *****/

    HT_RTC_ITConfig(RTC_RTCIE_MINIE|RTC_RTCIE_HRIE, DISABLE);

    /***** The following code is used to disable RTC interrupt *****/

    NVIC_DisableIRQ(RTC_IRQn);                                 /*!< Disable RTC interrupt */
}

/*
*********************************************************************************************************
*                                  CHIP LOW POWER CONFIGURE
*
* @brief: Chip low power configuration, the chip needs to do this configuration before entering hold or 
*         sleep mode
* @param: None
*
* @retval: None
*
* @note: 1) The following code does not participate in project compilation by default
*        2) This function does not contain a GPIO configuration which need to be based on 
*           specific project
*        3) This function turns off all other modules except the TBS temperature measurement module,user 
*           can reopen these modules on the actual needs of their scheme 
*********************************************************************************************************
*/
void LowPowerConfigure_Example(void)
{
    CMU_InitTypeDef  CMU_InitStructure;
    PMU_InitTypeDef  PMU_InitStructure;

    HT_FreeDog();
    /**********  Configure the CMU module  **********/
    CMU_InitStructure.SysClkSel = SysLF;
    CMU_InitStructure.CPUDiv = CPUDiv1;
    HT_CMU_Init(&CMU_InitStructure);                    /*!< Configure system clock Fsys = Flf       */

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0, DISABLE);       /*!< Disable CLKCTRL0 register               */
    HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1, DISABLE);       /*!< Disable CLKCTRL1 register               */
	
#if defined USE_HT_WDT_REGISTER_CALLBACKS
    HT_SHModeDogConfigure(DISABLE);                     /*!< Turn off WatchDog in Sleep/Hold mode    */
#endif
	
    /**********  Configure the PMU module  **********/
    PMU_InitStructure.Lvdin0State = LVDINDisable;
    PMU_InitStructure.BorState = BORDisable;
#if  defined  USE_VCCLVL_501x
    PMU_InitStructure.VccLvlSet = VccLVL_2V8;
#elif defined USE_VCCLVL_633x
    PMU_InitStructure.VccLvlSet = VccLVL_3V3;
#else
    PMU_InitStructure.VccLvlSet = VccLVL_4V0;
#endif
#if  defined  USE_BOR_MCU
    PMU_InitStructure.BorLvlSet = BORLVL_2V2;
#elif defined USE_BOR_SOC
    PMU_InitStructure.BorLvlSet = BORLVL_2V4;
#else
    PMU_InitStructure.BorLvlSet = BORLVL_2V4;
#endif
#if defined USE_DETTIM_TYPE_1
    PMU_InitStructure.VccBorDetTime = DETTIM_300uS;        
#elif defined USE_DETTIM_TYPE_2
    PMU_InitStructure.VccBorDetTime = DETTIM_336uS;

#elif defined USE_DETTIM_TYPE_3 
    PMU_InitStructure.VccBorDetTime = DETTIM_427uS;
#endif    
    PMU_InitStructure.VccBorDetPeriod = DETPRD_536mS;
#if defined USE_LDOVREF || defined USE_LPCFG
	HT_LDO_LP_VoltConfig(LDOSVL_2);
#endif    
	HT_PMU_Init(&PMU_InitStructure);

    /**********  Configure TBS module  **********/
    #if  !defined  USE_TBS_TDVREFDAT
    HT_TBSConfig(TBS_TBSCON_VBATEn|TBS_TBSCON_ADC0En|TBS_TBSCON_ADC1En
                 |TBS_TBSCON_VCCEn, DISABLE);
                                                        /*!< Close all modules but TMP              */
    #endif
    HT_TBSConfig(TBS_TBSCON_TMPEn, ENABLE);             /*!< Enable TMP measurement                              */

//  HT_TBS_PeriodSet(TBS_TMP, TBS_TBSPRD_TMPPRD_OSC64S_MEM8mS);  /*!< For HT60xx Set as open once per 64s           */
 // HT_TBS_PeriodSet(TBS_TMP, TBS_TBSPRD_TMPPRD_OSC0P5S_MEM8S);  /*!< For HT61xx Set as open once per 8s     */
}


/*
*********************************************************************************************************
*                                  WDT EXAMPLES FOR HT60XX                                       
* @brief  Sample of Refresh  WDT 
* @param  None
* @retval None
* @note   The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
void WDT_Example(void)
{
#if (USE_HT_WDT_REGISTER_CALLBACKS == 1)
	WdtHandle.Instance = HT_WDT;
    WdtHandle.OveRstTimeMs = 4000;                  /* Configurate WDT overflow reset time period for 4 seconds, 
	                                                     this value is the theoretical value.*/
    HT_WDT_Init(&WdtHandle);
    HT_FreeDog_WithPara(&WdtHandle);                /* Free dog */
#else
    WDT_InitTypeDef WDT_InitStruct;
    WDT_InitStruct.Instance = HT_WDT;
    WDT_InitStruct.OveRstTimeMs = 4000;             /* Configurate WDT overflow reset time period for 4 seconds, 
	                                                     this value is the theoretical value.*/
	HT_FreeDog_WithPara(& WDT_InitStruct);        /* Free dog */
#endif
}


/**
*********************************************************************************************************
*                                  EMU EXAMPLES FOR HT6XXX                                       
* @brief  Sample of EMU Init 
* @param  None
* @retval None
* @note   The function is not participate in project compilation by default
*
*********************************************************************************************************
*/
#if (defined HT501x ||defined HT502x||defined HT503x)
void EMU_Init_Example(void)
{

#if  defined  HT503x
	PowerStart_InitTypeDef StartInit;
	
    Enable_emu_module();
    Reset_EMU_Module();	
	Open_emu_LDO();
	
	/*** delay 10ms wait 2p8 stable,user can adjust***/
	Delay_Ms(10);
	
	/*OSR AND EMUCLK config*/
	HT_Set_EMU_OSR(OSR128);
	HT_Set_EMU_NormalEmuClk_Sel(Normal_EmuClkSel_1638K);
	
	/*pluse config,GPIO config need place GPIO module*/   	
	HT_Set_EMU_CF1_OutSel(CF1OutSelCF1PN);
	HT_Set_EMU_CF2_OutSel(CF2OutSelCF2PN);
	HT_Set_EMU_CF3_OutSel(CF3OutSelCF3PN);
	HT_Set_EMU_CF_POS_Sel(CFPos_High);
	HT_Set_EMU_CFP(CFP_80ms);
	/*ADC CHANNEL PGA config*/	
	HT_Set_EMU_UPGA(UPGA_1);
	HT_Set_EMU_I1PGA(I1PGA_16);
	HT_Set_EMU_I2PGA(I2PGA_1);
	/*ADC CHANNEL ENABLE*/
	HT_Set_EMU_ADCEn(EMUCTRL_AdcUon|EMUCTRL_AdcI1on|EMUCTRL_AdcI2on,ENABLE);
	/*ENERGY CHANNEL ENABLE*/
	HT_Set_EMU_EnergyRunEn(CF1Run,ENABLE);
	HT_Set_EMU_EnergyRunEn(CF2Run,ENABLE);
	HT_Set_EMU_EnergyRunEn(CF3Run,ENABLE);
	
	/*power start init*/
	StartInit.StartSrcSel = PStartFast;
	StartInit.PQ_StartCFG = PQStartSel_PQ;
	StartInit.S_StartCFG = SStartSelSStart;
	StartInit.SStart = 0x0040;
	StartInit.PStart = 0x0080;
	StartInit.QStart = 0x0090;
	HT_EMU_PowerStart_Init(&StartInit);
	/**************************************
	**other function config,user need config
	*filcker,lpmode,fund,tamp.......
	****************************************/

#elif (defined HT501x ||defined HT502x)
    Enable_emu_module();
    Reset_EMU_Module();	
    Select_Pulse_Port(PF0, PFout, P80ms);
    Select_Pulse_Port(PF1, QFout, P80ms);
	Open_emu_LDO();
	
	/*** delay 10ms wait 2p8 stable,user can adjust***/
	Delay_Ms(10);
    Set_Valid_Channel((EMUCTRL_AdcUon|EMUCTRL_AdcI1on),(ADCCON_ANAI1_16|ADCCON_ANAU_1));
    
    Set_EMU_Reactive_Phase_Gain(50);
#endif

#if (USE_HT_EMU_REGISTER_CALLBACKS == 1U)
	/********************************************
	*default call back name or set call back name
	*********************************************/
	EmuHandle.ErrorCode = EMU_ERROR_NONE;
	HT_EMU_InitCallbacksToDefault(&EmuHandle);
#endif



}
#endif

#endif  /* __EXAMPLE_C */
