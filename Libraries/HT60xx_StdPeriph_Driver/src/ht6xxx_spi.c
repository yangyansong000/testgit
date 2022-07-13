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
* File         : ht6xxx_spi.c
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_SPI_C

#include <stdio.h>
#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                          Local Macro/Structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                            Local Variables
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
static void SPI_InitCallbacksToDefault(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_MODF_IT(SPI_InitTypeDef *SPI_InitStruct);
#if  defined  USE_SPI_FIFO
static void SPI_TRANSFER_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFOTXE_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFORXNE_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFOTXF_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFORXF_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFOTXO_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFORXO_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFOTXT_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFORXT_IT(SPI_InitTypeDef *SPI_InitStruct);
static void SPI_FIFOTXDONE_IT(SPI_InitTypeDef *SPI_InitStruct);
#endif

#endif /* USE_HT_SPI_REGISTER_CALLBACKS */
/**
*********************************************************************************************************
*                                 INITIAL SPI MODULE
*
* @brief:  Initializes the SPI peripheral according to the specified
*          parameters in the SPI_InitStruct
*
* @param:  SPIx               Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*          SPI_InitStruct     The SPI module initializes the structure pointer, which contains five parameters:
*                               1) SPI_CSInCtrol : SPI_CS Control
*                               2) SPI_Baudrate  : SPI Clock Setting
*                               3) SPI_CPHA      : Clock phase Setting
*                               4) SPI_CPOL      : Clock polarity Setting
*                               5) SPI_Mode      : SPI master/slave mode Setting
*                               6) SPI_CLK       : SPI clock source selection( only SPI2,and currently only open compatible mode)
*                               7) SPI_FASTEN    : SPI Fast slave Setting
*                               8) SPI_LSBEN     : SPI MSB or LSB Setting
*
* @retval: None
*
* @Note:   User should enable the SPI module before configuring the SPI register. for details please see HT_CMU_ClkCtrl0Config() function.
*********************************************************************************************************
*/
void HT_SPI_Init(HT_SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct)
{
    /*  assert_param  */
    uint32_t tempreg = (SPI_SPICON_SSDIS | SPI_SPICON_SPIEN);
#if  defined  USE_SPI_SPICLK
    uint32_t tempreg1 = 0x00;
#endif
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_CSINCTROL(SPI_InitStruct->SPI_CSInCtrol));
    assert_param(IS_HT_SPI_BAUDRATE(SPI_InitStruct->SPI_Baudrate));
    assert_param(IS_HT_SPI_CPHA(SPI_InitStruct->SPI_CPHA));
    assert_param(IS_HT_SPI_CPOL(SPI_InitStruct->SPI_CPOL));
    assert_param(IS_HT_SPI_MODE(SPI_InitStruct->SPI_Mode));
    
#if  defined  USE_SPI_SPICON_FASTEN
    assert_param(IS_HT_SPI_FASTEN(SPI_InitStruct->SPI_FASTEN));
#endif
    
#if  defined  USE_SPI_SPICON_LSBEN
    assert_param(IS_HT_SPI_LSBEN(SPI_InitStruct->SPI_LSBEN));
#endif

#if  defined  USE_SPI_SPICLK
    if (SPIx == HT_SPI2)
    {
        assert_param(IS_HT_SPI_CLK(SPI_InitStruct->SPI_CLK));
    }
#endif

    if(SPI_InitStruct->SPI_CSInCtrol != DISABLE)
    {
        tempreg &= ~SPI_SPICON_SSDIS;                               /*!< Turn on SPI_CS Input */
    }
    
#if  defined  USE_SPI_ODDDIV
    if ((SPI_InitStruct->SPI_Baudrate >= SPI_BaudRatePrescaler_3)
      && (SPI_InitStruct->SPI_Baudrate <= SPI_BaudRatePrescaler_9))
    {
        SPIx->SPIDIV &= (~SPI_SPIDIV_DIV);                          /*!< Clear the Secondary Frequency Settings */
        SPIx->SPIDIV |= SPI_InitStruct->SPI_Baudrate;               /*!< Secondary Clock Frequency Setting */
        SPIx->SPIDIV |= SPI_SPIDAT_DIV_EN;                          /*!< Enable the Secondary Clock Frequency */
    }
    else
    {
        SPIx->SPIDIV &= (~SPI_SPIDAT_DIV_EN);                       /*!< Disable the Secondary Clock Frequency */
        tempreg |= SPI_InitStruct->SPI_Baudrate;                    /*!< Configuring the Clock Frequency */
    }
#else
    tempreg |= SPI_InitStruct->SPI_Baudrate;                        /*!< Configuring the Clock Frequency */
#endif
    
    tempreg |= SPI_InitStruct->SPI_CPHA;                            /*!< Configuring the Clock Phase */
    tempreg |= SPI_InitStruct->SPI_CPOL;                            /*!< Configuring the Clock Polarity */
    tempreg |= SPI_InitStruct->SPI_Mode;                            /*!< Configuring the Master/Slave Mode */

#if  defined  USE_SPI_SPICLK
    if (SPIx == HT_SPI2)
    {
        tempreg1 = SPI_SPICLKSEL_SPIMODE;
        tempreg1 |= (SPI_InitStruct->SPI_CLK & SPI_SPICLKSEL_SPICLK);
        SPIx->SPICLKSEL = tempreg1;
    }
#endif

#if  defined  USE_SPI_SPICON_FASTEN
    #if  defined USE_SPI12_SPICON_FASTEN
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI2))
    {
        tempreg |= (uint32_t) (SPI_InitStruct->SPI_FASTEN);                   /*!< Configuring Fast Slave Mode */
    }
    #else
    {
         tempreg |= (uint32_t) (SPI_InitStruct->SPI_FASTEN);                   /*!< Configuring Fast Slave Mode */        
    }
    #endif
#endif
#if  defined  USE_SPI_SPICON_LSBEN 
    #if  defined  USE_SPI12_SPICON_LSBEN
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI2))
    {
        tempreg |= (uint32_t)(SPI_InitStruct->SPI_LSBEN);                         /*!< Configuring MSB or LSB */
    }
    #else
    {
        tempreg |= (uint32_t)(SPI_InitStruct->SPI_LSBEN);                         /*!< Configuring MSB or LSB */
    }
    #endif
#endif
    
    SPIx->SPICON = tempreg;

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
    SPI_InitStruct->Instance = SPIx;
    SPI_InitCallbacksToDefault(SPI_InitStruct);
#endif
}

/**
*********************************************************************************************************
*                            GET SPECIFIED SPI INTERRUPT FLAG STATUS
*
* @brief:  Gets the corresponding SPI interrupt flag status
*
* @param:  SPIx     Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*          ITFlag   Check an SPI interrupt with the following parameters.
*                      @arg SPI_SPISTA_MODF
*                      @arg SPI_SPISTA_SSERR    This flag bit is not an interrupt flag bit
*                      @arg SPI_SPISTA_WCOL     This flag bit is not an interrupt flag bit
*                      @arg SPI_SPISTA_SPIF
*
* @retval: ITStatus    = SET   Interrupt flag is set
*                      = RESET Interrupt flag is reset
*
* @Note:   None
*********************************************************************************************************
*/
ITStatus HT_SPI_ITFlagStatusGet(HT_SPI_TypeDef *SPIx, uint8_t ITFlag)
{
    ITStatus itflag;
    /* assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_ITFLAG(ITFlag));

    if (SPIx->SPISTA & ITFlag)
    {
        itflag = SET;                              /*!< Interrupt Flag is Set */
    }
    else
    {
        itflag = RESET;                            /*!< Interrupt Flag is Reset */
    }
    return itflag;
}

/**
*********************************************************************************************************
*                                   CLEAR SPI INTERRUPT FLAG
*
* @brief:  Clear SPI interrupt flag
*
* @param:  SPIx     Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*          ITFlag   Clear an SPI interrupt with one or a combination of the following parameters
*                      @arg SPI_SPISTA_MODF
*                      @arg SPI_SPISTA_SSERR   This flag bit is not an interrupt flag bit
*                      @arg SPI_SPISTA_WCOL    This flag bit is not an interrupt flag bit
*                      @arg SPI_SPISTA_SPIF
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_ClearITPendingBit(HT_SPI_TypeDef *SPIx, uint8_t ITFlag)
{
     /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_ITFLAG(ITFlag));

    ITFlag = (uint8_t) (SPIx->SPISTA);                         /*!< Clear SPI Interrupt Flag */
    ITFlag = (uint8_t) (SPIx->SPIDAT);
    (void)ITFlag;
}

/**
*********************************************************************************************************
*                              WRITE AND READ SPIDAT REGISTER
*
* @brief:  Write data to SPI data register and read data at the same time
*
* @param:  SPIx      Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*          halfword  need to write data
*
* @retval: SPIDAT    Read data form SPIDAT register
*
* @Note:   The corresponding SPIF flag should not be cleared before leaving this function.Otherwise, 
* there is a certain probability that the function cannot be jumped out. 
*********************************************************************************************************
*/
uint8_t HT_SPI_SendByte(HT_SPI_TypeDef *SPIx, uint16_t halfword)
{
    /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));

    while(SET==HT_SPI_ITFlagStatusGet(SPIx, SPI_SPISTA_SPIF))            /*!< Judge the Flag Bit and Clear the Flag when the Transmission is Completed */
    {
        HT_SPI_ClearITPendingBit(SPIx, SPI_SPISTA_SPIF);
    }
    SPIx->SPIDAT = halfword;                                             /*!< Write the Data */

    while(RESET==HT_SPI_ITFlagStatusGet(SPIx, SPI_SPISTA_SPIF)){}        /*!< Wait for Transmission to Complete  */

    return (uint8_t)(SPIx->SPIDAT);                                      /*!< Read Data While Clearing the Transfer Completion Flag  */
}

/**
*********************************************************************************************************
*                                 SET SPI_CS HIGH
*
* @brief:  Set SPI_CS to high
*
* @param:  SPIx   Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_CSHigh(HT_SPI_TypeDef *SPIx)
{
    /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
#if defined  USE_SPI_SPISSN_SSN01
    #if defined USE_SPI12_SPISSN_SSN1
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI2))
    {
        SPIx->SPISSN |= (SPI_SPISSN_SSN1);          /*!< Soft Control SPI CS*/
        SPIx->SPISSN |= (SPI_SPISSN_SSN0);          /*!< SPI CS to High */         
    }
    else
    {
        SPIx->SPISSN |= (SPI_SPISSN_SSN0);          /*!< SPI CS to High */  
    }
    #else
    {
        SPIx->SPISSN |= (SPI_SPISSN_SSN1);          /*!< Soft Control SPI CS*/
        SPIx->SPISSN |= (SPI_SPISSN_SSN0);          /*!< SPI CS to High */         
    }
    #endif
#else
    SPIx->SPISSN |=(SPI_SPISSN_CS);
#endif
}

/**
*********************************************************************************************************
*                                 SET SPI_CS LOW
*
* @brief:  Set SPI_CS to low
*
* @param:  SPIx   Only one of HT_SPI0/HT_SPI1/HT_SPI2//HT_SPI3
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_CSLow(HT_SPI_TypeDef *SPIx)
{
    /* assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
#if defined  USE_SPI_SPISSN_SSN01
    #if defined USE_SPI12_SPISSN_SSN1
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI2))
    {
        SPIx->SPISSN |= SPI_SPISSN_SSN1;                /*!< Soft Control SPI CS*/
        SPIx->SPISSN &= (~SPI_SPISSN_SSN0);             /*!< SPI CS to Low */
    }    
    else
    {
         SPIx->SPISSN &= (~SPI_SPISSN_SSN0);             /*!< SPI CS to Low */ 
    }
    #else
    {
         SPIx->SPISSN |= SPI_SPISSN_SSN1;                /*!< Soft Control SPI CS*/
         SPIx->SPISSN &= (~SPI_SPISSN_SSN0);             /*!< SPI CS to Low */  
    }
#endif
#else
    SPIx->SPISSN &=(~SPI_SPISSN_CS);
#endif
}

#if defined  USE_SPI_SPISSN_MSAM
/**
*********************************************************************************************************
*                                 SET SPI MASTER DELAY SAMPING CONTROL
*
* @brief:  Set SPI Master delay Samping control
*
* @param:  SPIx   Only one of HT_SPI0/HT_SPI1/HT_SPI2/HT_SPI3
*          msam   SPI Master delay Samping control Bits
*                     @arg SPI_SPISSN_MSAM_0
*                     @arg SPI_SPISSN_MSAM_1
*                     @arg SPI_SPISSN_MSAM_2
*                     @arg SPI_SPISSN_MSAM_3
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_SetMsam_Delay(HT_SPI_TypeDef *SPIx,uint32_t msam)
{
   /* assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_MSAM(msam));
#if defined USE_SPI12_SPISSN_MSAM
    if(SPIx == HT_SPI0)
    {
        return;
    }
#endif
    SPIx->SPISSN &= ~SPI_SPISSN_MSAM;
    SPIx->SPISSN |= msam;                    /*!<Set Master Delay Samping Clk */

}
#endif

#if defined  USE_SPI_CSDLY
/**
*********************************************************************************************************
*                                  SPI_CS DELAY AUTO CONTROL
*
* @brief:  Set SPI_CS Delay Auto Control
*
* @param:  SPIx                       Only one of HT_SPI0/HT_SPI1/HT_SPI2/HT_SPI3
*          SPI_CSDelayInitStruct      The SPI_CS Delay initializes the structure pointer, which contains three parameters:
*                                     1) SPI_CSB :    Advance 0 Clk Pull down SPI_CS Before Send Data
*                                     2) SPI_CSA :    Delay Pull Up SPI_CS After Send Data
*                                     3) SPI_ITDelay: DATA Send  Wait Time to DMA
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_CSDelayInit(HT_SPI_TypeDef *SPIx, SPI_CSDelayInitTypeDef *SPI_CSDelayInitStruct)
{
    uint32_t tempreg = 0x00;
  /* assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_CSB(SPI_CSDelayInitStruct->SPI_CSB));
    assert_param(IS_HT_SPI_CSA(SPI_CSDelayInitStruct->SPI_CSA));
    assert_param(IS_HT_SPI_ITDELAY(SPI_CSDelayInitStruct->SPI_ITDelay));
#if defined USE_SPI12_CSDLY
    if(SPIx == HT_SPI0)
    {
        return;
    }
#endif
    SPIx->SPISSN &= ~SPI_SPISSN_SSN1;            /*!<Set SSN1 to low  */

    tempreg |= SPI_CSDelayInitStruct->SPI_CSB;
    tempreg |= SPI_CSDelayInitStruct->SPI_CSA;
    tempreg |= SPI_CSDelayInitStruct->SPI_ITDelay;

    SPIx->CSDLY = tempreg;
}
#endif

#if  defined  USE_SPI_FIFO
/**
*********************************************************************************************************
*                                   INITIAL SPI FIFO
*
* @brief:  Initializes the SPI peripheral according to the specified
*          parameters in the SPI_FIFOInitStruct
*
* @param:  SPIx                  Only one of HT_SPI1/HT_SPI2
*          SPI_FIFOInitStruct    The SPI FIFO initializes the structure pointer, which contains eight parameters:
*                                   1) SPIFIFO_CTR         :Fast Slave Mode Filter Control
*                                   2) SPIFIFO_RXFIFOTL    :Receive FIFO threshold Setting
*                                   3) SPIFIFO_TXFIFOTL    :Send FIFO Threshold Setting
*                                   4) SPIFIFO_EXINSEL     :FIFO Data Source Control
*                                   5) SPIFIFO_HLCS        :CS State Control During BDLY Delay
*                                   6) SPIFIFO_RXFIFORST   :Receive FIFO Write Reset
*                                   7) SPIFIFO_TXFIFORST   :Send FIFO Write Reset
*                                   8) SPIFIFO_FSEN        :Enable Fast Slave With FIFO
*                                   9) SPIFIFO_RXFIFOEN    :FIFO Receiving Enable Control
*                                  10) SPIFIFO_TXFIFOEN    :FIFO Sending Enable Control
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPI_FIFOInit(HT_SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct)
{
    uint32_t tempreg = 0x00000000U;
    /* assert_param  */
    assert_param(IS_HT_SPI_FIFO_CTR(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_CTR));
    assert_param(IS_HT_SPI_FIFO_RXFIFOTL(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_RXFIFOTL));
    assert_param(IS_HT_SPI_FIFO_TXFIFOTL(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_TXFIFOTL));
    assert_param(IS_HT_SPI_FIFO_EXINSEL(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_EXINSEL));
    assert_param(IS_HT_SPI_FIFO_HLCS(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_HLCS));
    assert_param(IS_HT_SPI_FIFO_RXFIFORST(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_RXFIFORST));
    assert_param(IS_HT_SPI_FIFO_TXFIFORST(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_TXFIFORST));
    
    #if defined USE_SPI12_FIFO
    if(SPIx == HT_SPI0)
    {
        return;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI3))
    {
        return;
    }
    #endif
    
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_TXFIFOEN == ENABLE)
    {
        tempreg |= SPI_FIFOCON_TXFIFO_EN;
    }
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_RXFIFOEN == ENABLE)
    {
        tempreg |= SPI_FIFOCON_RXFIFO_EN;
    }
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_FSEN == ENABLE)
    {
        tempreg |= SPI_FIFOCON_FS_EN;
    }
    tempreg |= (uint32_t)(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_TXFIFORST);
    tempreg |= (uint32_t)(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_RXFIFORST);
    tempreg |= (uint32_t)(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_HLCS);
    tempreg |= (uint32_t)(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_EXINSEL);
    tempreg |= (uint32_t)((SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_TXFIFOTL)<<8);
    tempreg |= (uint32_t)((SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_RXFIFOTL)<<16);
    tempreg |= (uint32_t)(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFO_CTR);

    SPIx->FIFOCON = tempreg;
    #if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
    SPI_InitStruct->SPI_FIFOInitStruct.Instance = SPIx;
    #endif
}

/**
*********************************************************************************************************
*                                  SET SPI FIFO INTERRUPT
*
* @brief:  SET SPI FIFO interrupt
*
* @param:  SPIx     Only one of HT_SPI1/HT_SPI2
*          ITEn     SET an SPI fifo interrupt with the following parameters.
*                      @arg SPI_FIFOIE_TXE_IE
*                      @arg SPI_FIFOIE_RXNE_IE
*                      @arg SPI_FIFOIE_TXF_IE
*                      @arg SPI_FIFOIE_RXF_IE
*                      @arg SPI_FIFOIE_TXO_IE
*                      @arg SPI_FIFOIE_RXO_IE
*                      @arg SPI_FIFOIE_TXT_IE
*                      @arg SPI_FIFOIE_RXT_IE
*                      @arg SPI_FIFOIE_TXFIFO_DONE_IE
*      NewState   = ENABLE:   Enable  Interrupt
*                 = DISABLE   Disable Interrupt
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPIFIFO_SETITConfig(HT_SPI_TypeDef *SPIx, uint32_t ITEn, FunctionalState NewState)
{
     /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_FIFO_ITEn(ITEn));
    
    #if defined USE_SPI12_FIFO
    if(SPIx == HT_SPI0)
    {
        return;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI3))
    {
        return;
    }
    #endif

    if(NewState != DISABLE)
    {
        SPIx->FIFOIE |= ITEn;                       /*!< Enable SPI FIFO Interrupt */
    }
    else
    {
        SPIx->FIFOIE &= ~ITEn;                      /*!< Disable SPI FIFO Interrupt */
    }
}

/**
*********************************************************************************************************
*                            GET SPI FIFO INTERRUPT FLAG STATUS
*
* @brief:  Gets the corresponding SPI fifo interrupt flag status
*
* @param:  SPIx     Only one of HT_SPI1/HT_SPI2
*          ITFlag   Check an SPI fifo interrupt with the following parameters.
*                      @arg SPI_FIFOIF_TXE_IF
*                      @arg SPI_FIFOIF_RXNE_IF
*                      @arg SPI_FIFOIF_TXF_IF
*                      @arg SPI_FIFOIF_RXF_IF
*                      @arg SPI_FIFOIF_TXO_IF
*                      @arg SPI_FIFOIF_RXO_IF
*                      @arg SPI_FIFOIF_TXT_IF
*                      @arg SPI_FIFOIF_RXT_IF
*                      @arg SPI_FIFOIF_TXFIFO_DONE_IF
*
* @retval: ITStatus    = SET   Interrupt flag is set
*                      = RESET Interrupt flag is reset
*
* @Note:   None
*********************************************************************************************************
*/
ITStatus HT_SPIFIFO_ITFlagStatusGet(HT_SPI_TypeDef *SPIx, uint32_t ITFlag)
{
    ITStatus itflag;
    /* assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_FIFO_ITFLAG(ITFlag));
    #if defined USE_SPI12_FIFO
    if(SPIx == HT_SPI0)
    {
        return RESET;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI3))
    {
        return RESET;
    }
    #endif
    if (SPIx->FIFOIF & ITFlag)
    {
        itflag = SET;                              /*!< Interrupt Flag is Set */
    }
    else
    {
        itflag = RESET;                            /*!< Interrupt Flag is Reset */
    }
    return itflag;
}

/**
*********************************************************************************************************
*                                   CLEAR SPI FIFO INTERRUPT FLAG
*
* @brief:  Clear SPI FIFO interrupt flag
*
* @param:  SPIx     Only one of HT_SPI1/HT_SPI2
*          ITFlag   Clear an SPI fifo interrupt with one or a combination of the following parameters
*                      @arg SPI_FIFOIF_TXO_IF           flag bit
*                      @arg SPI_FIFOIF_RXO_IF           flag bit   
*                      @arg SPI_FIFOIF_TXFIFO_DONE_IF   flag bit
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPIFIFO_ClearITPendingBit(HT_SPI_TypeDef *SPIx, uint32_t ITFlag)
{
     /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_FIFO_ITFLAG(ITFlag));
    #if defined USE_SPI12_FIFO
    if(SPIx == HT_SPI0)
    {
        return;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI3))
    {
        return;
    }
    #endif
    SPIx->FIFOIF &=~ITFlag;
}

/**
*********************************************************************************************************
*                                  SET SPI FIFO BYTE DELAY
*
* @brief:  Set SPI FIFO byte delay
*
* @param:  SPIx     Only one of HT_SPI0/HT_SPI1/HT_SPI2(If support)
*          bdly     Set SPI FIFO byte delay with the following parameters.
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_SPIFIFO_SETByteDelay(HT_SPI_TypeDef *SPIx, uint32_t bdly)
{
     /*  assert_param  */
    assert_param(IS_HT_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_HT_SPI_FIFO_BDLY(bdly));
    
    #if defined USE_SPI12_FIFO
    if(SPIx == HT_SPI0)
    {
        return;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPIx == HT_SPI1)||(SPIx == HT_SPI3))
    {
        return;
    }
    #endif    
    SPIx->BDLY &=~SPI_BDLY;
    SPIx->BDLY |= bdly;
}
#endif

#if (USE_HT_SPI_REGISTER_CALLBACKS == 1U)
/**
* @brief  Register a User SPI Callback
*         To be used instead of the weak predefined callback
* @param  SPI_InitStruct spi handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg  SPI_MODF_CB_ID
*           @arg  SPI_SPIF_CB_ID
*           @arg  SPI_FIFO_TXE_CB_ID
*           @arg  SPI_FIFO_RXN_CB_ID
*           @arg  SPI_FIFO_TXF_CB_ID
*           @arg  SPI_FIFO_RXF_CB_ID
*           @arg  SPI_FIFO_TXO_CB_ID
*           @arg  SPI_FIFO_RXO_CB_ID
*           @arg  SPI_FIFO_TXT_CB_ID
*           @arg  SPI_FIFO_RXT_CB_ID
*           @arg  SPI_FIFO_TXDONE_CB_ID
*
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_SPI_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register
*   himself defined callback function.
*/
#if  defined  USE_SPI_FIFO
StatusTypeDef HT_SPI_RegisterCallback(SPI_InitTypeDef *SPI_InitStruct, SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback , pSPIFIFO_CallbackTypeDef pFIFOCallback )
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        SPI_InitStruct->ErrorCode |= SPI_ERROR_INVALID_CALLBACK;

        status = ERROR;
    }
    if (pFIFOCallback == NULL)
    {
        /* Update the error code */
        SPI_InitStruct->ErrorCode |= SPI_ERROR_INVALID1_CALLBACK;

        status = ERROR;
    }
    
    switch (CallbackID)
    {
        case SPI_MODF_CB_ID :
            SPI_InitStruct->SPIModfCallback = pCallback;
            break;

        case SPI_SPIF_CB_ID :
            SPI_InitStruct->SPISpifCallback = pCallback;
            break;

        case SPI_FIFO_TXE_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxeCallback = pFIFOCallback;
            break;

        case SPI_FIFO_RXNE_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxneCallback = pFIFOCallback;
            break;

        case SPI_FIFO_TXF_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxfCallback = pFIFOCallback;
            break;

        case SPI_FIFO_RXF_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxfCallback = pFIFOCallback;
            break;

        case SPI_FIFO_TXO_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxoCallback = pFIFOCallback;
            break;

        case SPI_FIFO_RXO_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxoCallback = pFIFOCallback;
            break;

        case SPI_FIFO_TXT_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxtCallback = pFIFOCallback;
            break;

        case SPI_FIFO_RXT_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxtCallback = pFIFOCallback;
            break;

        case SPI_FIFO_TXDONE_CB_ID :
            SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxdoneCallback = pFIFOCallback;
            break;
       default :
            /* Update the error code */
            SPI_InitStruct->ErrorCode |= SPI_ERROR_INVALID_CALLBACK;

            /* Return error status */
            status =  ERROR;
            break;
    }
    return status;
}
#else
StatusTypeDef HT_SPI_RegisterCallback(SPI_InitTypeDef *SPI_InitStruct, SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        SPI_InitStruct->ErrorCode |= SPI_ERROR_INVALID_CALLBACK;

        return ERROR;
    }
    switch (CallbackID)
    {
        case SPI_MODF_CB_ID :
            SPI_InitStruct->SPIModfCallback = pCallback;
            break;

        case SPI_SPIF_CB_ID :
            SPI_InitStruct->SPISpifCallback = pCallback;
            break;
        default :
            /* Update the error code */
            SPI_InitStruct->ErrorCode |= SPI_ERROR_INVALID_CALLBACK;

            /* Return error status */
            status =  ERROR;
            break;
    }
    return status;
}
#endif

/**
*********************************************************************************************************
*                                         INITIAL SPI CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: SPI_InitStruct  Pointer to a SPI_InitTypeDef structure that contains
*                         the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_InitCallbacksToDefault(SPI_InitTypeDef *SPI_InitStruct)
{
    /* Init the SPI Callback settings */
    SPI_InitStruct->SPIModfCallback = HT_SPI_SPIModfCallback;                                /* Legacy weak SPIModfCallback */
    SPI_InitStruct->SPISpifCallback = HT_SPI_SPISpifCallback;                                /* Legacy weak SPISpifCallback */
#if  defined  USE_SPI_FIFO
    #if  defined USE_SPI12_FIFO
    if(SPI_InitStruct->Instance == HT_SPI0)
    {
        return;
    }
    #endif
    #if defined USE_SPI02_FIFO
    if((SPI_InitStruct->Instance == HT_SPI1)||(SPI_InitStruct->Instance == HT_SPI3))
    {
        return;
    }
    #endif   
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxeCallback = HT_SPI_SPIFIFOTxeCallback;       /* Legacy weak SPIFIFOTxeCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxneCallback = HT_SPI_SPIFIFORxneCallback;     /* Legacy weak SPIFIFORxneCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxfCallback = HT_SPI_SPIFIFOTxfCallback;       /* Legacy weak SPIFIFOTxfCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxfCallback = HT_SPI_SPIFIFORxfCallback;       /* Legacy weak SPIFIFORxfCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxoCallback = HT_SPI_SPIFIFOTxoCallback;       /* Legacy weak SPIFIFOTxoCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxoCallback = HT_SPI_SPIFIFORxoCallback;       /* Legacy weak SPIFIFORxoCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxtCallback = HT_SPI_SPIFIFOTxtCallback;       /* Legacy weak SPIFIFOTxtCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxtCallback = HT_SPI_SPIFIFORxtCallback;       /* Legacy weak SPIFIFORxtCallback */
    SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxdoneCallback = HT_SPI_SPIFIFOTxdoneCallback; /* Legacy weak SPIFIFOTxdoneCallback */
#endif
}

/**
*********************************************************************************************************
*                                         SPI MODE FAULT IT HANDLER
*
* @brief: SPI Mode Fault  Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_MODF_IT(SPI_InitTypeDef *SPI_InitStruct)
{
   /*Call registered SPI Mode Fault callback*/
    if(SPI_InitStruct->SPIModfCallback != NULL)
    {
        SPI_InitStruct->SPIModfCallback(SPI_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI DATA TRANSFER IT HANDLER
*
* @brief: SPI Data Transfer Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_TRANSFER_IT(SPI_InitTypeDef *SPI_InitStruct)
{
    /*Call registered SPI Data Transmit callback*/
    if(SPI_InitStruct->SPISpifCallback != NULL)
    {
        SPI_InitStruct->SPISpifCallback(SPI_InitStruct);
    }
}

#if  defined  USE_SPI_FIFO
/**
*********************************************************************************************************
*                                         SPI FIFO TXE IT HANDLER
*
* @brief: SPI FIFO Txe Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFOTXE_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxeCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxeCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO RXNE IT HANDLER
*
* @brief: SPI FIFO Rxne Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFORXNE_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxneCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxneCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO TXF IT HANDLER
*
* @brief: SPI FIFO Txf Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFOTXF_IT(SPI_InitTypeDef *SPI_InitStruct)
{
   /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxfCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxfCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO RXF IT HANDLER
*
* @brief: SPI FIFO Rxf Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFORXF_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxfCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxfCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO TXO IT HANDLER
*
* @brief: SPI FIFO Txo Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFOTXO_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxoCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxoCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO RXO IT HANDLER
*
* @brief: SPI FIFO Rxo Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFORXO_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxoCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxoCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO TXT IT HANDLER
*
* @brief: SPI FIFO Txt Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFOTXT_IT(SPI_InitTypeDef *SPI_InitStruct)
{
    /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxtCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxtCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO RXT IT HANDLER
*
* @brief: SPI FIFO Rxt Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFORXT_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxtCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFORxtCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}

/**
*********************************************************************************************************
*                                         SPI FIFO TXDONE IT HANDLER
*
* @brief: SPI FIFO Txdone Interrupt Hander
*
* @param: SPI_InitStruct   Pointer to a SPI_InitTypeDef structure that contains
*                          the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void SPI_FIFOTXDONE_IT(SPI_InitTypeDef *SPI_InitStruct)
{
     /*Call registered SPI FIFO Txe Interrupt callback*/
    if(SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxdoneCallback != NULL)
    {
        SPI_InitStruct->SPI_FIFOInitStruct.SPIFIFOTxdoneCallback(&SPI_InitStruct->SPI_FIFOInitStruct);
    }
}
#endif

/**
*********************************************************************************************************
*                                         SPI IRQ HANDLER
*
* @brief: This function handles SPI interrupt request.
*
* @param: SPI_InitStruct  Pointer to a SPI_InitTypeDef structure that contains
*                         the configuration information for the specified SPI module.
*
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_SPI_IRQHandler(SPI_InitTypeDef *SPI_InitStruct)
{
/* SPI Mode fault -------------------------------------------------*/
    if(SET == HT_SPI_ITFlagStatusGet(SPI_InitStruct->Instance,SPI_SPISTA_MODF))         /*!< SPIx mode fault Flag set    */
    {
        SPI_MODF_IT(SPI_InitStruct);
        HT_SPI_ClearITPendingBit(SPI_InitStruct->Instance, SPI_SPISTA_MODF);            /*!< clear mode fault interrupt Flag          */
   }
/* SPI Data Transmit -------------------------------------------------*/
    if(SET == HT_SPI_ITFlagStatusGet(SPI_InitStruct->Instance, SPI_SPISTA_SPIF))        /*!< SPIx data transfer completion Flag set */
    {
        SPI_TRANSFER_IT(SPI_InitStruct);
        HT_SPI_ClearITPendingBit(SPI_InitStruct->Instance, SPI_SPISTA_SPIF);            /*!< clear data transfer completion interrupt Flag */
    }
	
#if  defined  USE_SPI_FIFO

    #if  defined USE_SPI12_FIFO
    if(SPI_InitStruct->Instance == HT_SPI0)
    {
        return;
    }
    #endif
	
    #if defined USE_SPI02_FIFO
    if((SPI_InitStruct->Instance == HT_SPI1)||(SPI_InitStruct->Instance == HT_SPI3))
    {
        return;
    }
    #endif
    
/* SPI FIFO TXE-------------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXE_IF))  /*!< SPIx Send FIFO Empty Interrupt Flag set */
    {
        SPI_FIFOTXE_IT(SPI_InitStruct);
    }
/* SPI FIFO RXNE-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_RXNE_IF))  /*!< SPIx Receive FIFO non-Empty Interrupt Flag set*/
    {
        SPI_FIFORXNE_IT(SPI_InitStruct);
    }
/* SPI FIFO TXF-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXF_IF))  /*!< SPIx Send FIFO Full Interrupt Flag set*/
    {    
        SPI_FIFOTXF_IT(SPI_InitStruct);
    }
/* SPI FIFO RXF-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_RXF_IF))  /*!< SPIx Receive FIFO Full Interrupt Flag set*/
    {
        SPI_FIFORXF_IT(SPI_InitStruct);
    }
/* SPI FIFO TXO-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXO_IF))  /*!< SPIx Send FIFO OverFlow Interrupt Flag set*/
    {
        SPI_FIFOTXO_IT(SPI_InitStruct);
        HT_SPIFIFO_ClearITPendingBit(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXO_IF);       /*!< clear Send FIFO OverFlow Interrupt Flag  */
    }
/* SPI FIFO RXO-----------------------------------------------*/
     if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_RXO_IF))  /*!< SPIx Receive FIFO OverFlow Interrupt Flag set*/
    {
        SPI_FIFORXO_IT(SPI_InitStruct);
        HT_SPIFIFO_ClearITPendingBit(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_RXO_IF);       /*!< clear Receive FIFO OverFlow Interrupt Flag  */
    }
/* SPI FIFO TXT-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXT_IF))  /*!< SPIx Send FIFO is Less Than or Equal to the Threshold Interrupt Flag  set*/
    {
        SPI_FIFOTXT_IT(SPI_InitStruct);
    }
/* SPI FIFO RXT-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_RXT_IF))  /*!< SPIx Receive FIFO Exceeds the Threshold Interrupt Flag  set*/
    {
        SPI_FIFORXT_IT(SPI_InitStruct);
    }
/* SPI FIFO TXFIFO_DONE-----------------------------------------------*/
    if(SET == HT_SPIFIFO_ITFlagStatusGet(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXFIFO_DONE_IF))  /*!< SPIx Data Transmission Interrupt Interrupt Flag set*/
    {
        SPI_FIFOTXDONE_IT(SPI_InitStruct);
        HT_SPIFIFO_ClearITPendingBit(SPI_InitStruct->SPI_FIFOInitStruct.Instance, SPI_FIFOIF_TXFIFO_DONE_IF);       /*!< clear Data Transmission Interrupt Interrupt Flag */
    }
#endif
}

/**
*********************************************************************************************************
*                                         SPIx MODE FAULT CALLBACK
*
* @brief: SPIx Mode Fault callbacks.
*
* @param: SPI_InitStruct  Pointer to a SPI_InitTypeDef structure that contains
*                         the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIModfCallback(SPI_InitTypeDef *SPI_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIModfCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx DATA TRANSFER CALLBACK
*
* @brief: SPIx Data Transfer callbacks.
*
* @param: SPI_InitStruct  Pointer to a SPI_InitTypeDef structure that contains
*                         the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPISpifCallback(SPI_InitTypeDef *SPI_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPISpifCallback could be implemented in the user file
   */
}

#if  defined  USE_SPI_FIFO
/**
*********************************************************************************************************
*                                         SPIx FIFO TXE CALLBACK
*
* @brief: SPIx FIFO Txe callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFOTxeCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFOTxeCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO RXNE CALLBACK
*
* @brief: SPIx FIFO Rxne callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFORxneCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFORxneCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO TXF CALLBACK
*
* @brief: SPIx FIFO Txf callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFOTxfCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFOTxfCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO RXF CALLBACK
*
* @brief: SPIx FIFO Rxf callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFORxfCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFORxfCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO TXO CALLBACK
*
* @brief: SPIx FIFO Txo callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFOTxoCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFOTxoCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO RXO CALLBACK
*
* @brief: SPIx FIFO Rxo callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFORxoCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFORxoCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO TXT CALLBACK
*
* @brief: SPIx FIFO Txt callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFOTxtCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFOTxtCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO RXT CALLBACK
*
* @brief: SPIx FIFO Rxt callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFORxtCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFORxtCallback could be implemented in the user file
   */
}

/**
*********************************************************************************************************
*                                         SPIx FIFO TXDONE CALLBACK
*
* @brief: SPIx FIFO Txdone callbacks.
*
* @param: SPI_FIFOInitStruct  Pointer to a SPI_FIFOInitTypeDef structure that contains
*                             the configuration information for the specified SPI module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_SPI_SPIFIFOTxdoneCallback(SPI_FIFOInitTypeDef *SPI_FIFOInitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(SPI_FIFOInitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_SPI_SPIFIFOTxdoneCallback could be implemented in the user file
   */
}
#endif
#endif
