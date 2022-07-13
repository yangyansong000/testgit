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
* File         : ht6xxx_rtc.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_RTC_C

#include <stdio.h>
#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                        Local Macro/Structure
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                          Local Variables
*********************************************************************************************************
*/

static const uint32_t RegisterWriteProtect[]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};

/*
*********************************************************************************************************
*                                       Local Function Declaration
*********************************************************************************************************
*/
#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
static void RTC_InitCallbacksToDefault(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_SEC_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_MIN_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_HOUR_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_DAY_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_MONTH_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_TMR1_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_TMR2_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_ALARM_IT(RTC_InitTypeDef *RTC_InitStruct);
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
static void RTC_RTCTS0OV_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_RTCTS0CMP_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_RTCTS0TRI_IT(RTC_InitTypeDef *RTC_InitStruct);
#endif
#if defined USE_RTC_RTCSTAMP01
static void RTC_RTCTS1OV_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_RTCTS1CMP_IT(RTC_InitTypeDef *RTC_InitStruct);
static void RTC_RTCTS1TRI_IT(RTC_InitTypeDef *RTC_InitStruct);
#endif
#endif /* USE_HT_RTC_REGISTER_CALLBACKS */

/**
*********************************************************************************************************
*                                         INITIAL RTC MODULE
*
* @brief: Initializes the RTC peripheral according to the specified
*         parameters in the RTC_InitStruct
*
* @param: RTC_InitStruct: pointer to a RTC_InitTypeDef structure
*         that contains the configuration information for the RTC
*         peripheral.which consists of four parameters:
*
*     1) RTC_TMR1    : RTCTMR1 Initialization structure, including Enabling and Setting the timing period
*         2) RTC_TMR2    : RTCTMR2 Initialization structure, including Enabling and Setting the timing period
*         3) RTC_Alarm   : RTC Alarm setting
*         4) RTC_TOUT    : RTC Tout output setting
*
* @retval: None
*
* @Note: Interrupt configuration is a direct assignment, and unconfigured bits are directly written to zero.
*********************************************************************************************************
*/
void HT_RTC_Init(RTC_InitTypeDef *RTC_InitStruct)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_ALMR_ALMM(RTC_InitStruct->RTC_Alarm.Muster.minute));
    assert_param(IS_HT_RTC_ALMR_ALMH(RTC_InitStruct->RTC_Alarm.Muster.hour));
    assert_param(IS_HT_RTC_RTCCON_TOUT(RTC_InitStruct->RTC_TOUT));
#if defined  USE_RTC_RTCSTAMP0  ||  defined  USE_RTC_RTCSTAMP01
    assert_param(IS_HT_RTC_RTCTSxCON_TSFILT(RTC_InitStruct->RTC_STAMP0.TSFILT));
    assert_param(IS_HT_RTC_RTCTSxCON_TSPOL(RTC_InitStruct->RTC_STAMP0.TSPOL));   
#endif    
#if defined  USE_RTC_RTCSTAMP01 
    assert_param(IS_HT_RTC_RTCTSxCON_TSFILT(RTC_InitStruct->RTC_STAMP1.TSFILT));
    assert_param(IS_HT_RTC_RTCTSxCON_TSPOL(RTC_InitStruct->RTC_STAMP1.TSPOL));    
#endif      
    if(RTC_InitStruct->RTC_TMR1.NewState != DISABLE)                 /*!< Configure RTC Timer1           */
    {
        HT_RTC->RTCTMR1 = (uint32_t)RTC_InitStruct->RTC_TMR1.Count;  /*!< Set RTC Timer1 Periodic Period */
        HT_RTC->RTCCON |= RTC_RTCCON_RTC1EN;                         /*!< Enable RTC Timer1              */
    }
    else
    {
        HT_RTC->RTCCON &= ~RTC_RTCCON_RTC1EN;                        /*!< Disable RTC Timer1             */
    }

    if(RTC_InitStruct->RTC_TMR2.NewState != DISABLE)                 /*!< Configure RTC timer2           */
    {
        HT_RTC->RTCTMR2 = (uint32_t)RTC_InitStruct->RTC_TMR2.Count;  /*!< Set RTC Timer2 Periodic Period */
        HT_RTC->RTCCON |= RTC_RTCCON_RTC2EN;                         /*!< Disable RTC Timer2             */
    }
    else
    {
        HT_RTC->RTCCON &= ~RTC_RTCCON_RTC2EN;                        /*!< Disable RTC Timer2             */
    }
                                                                     /*!< Configure the Alarm Register   */
    HT_RTC->ALMR = (uint32_t)(RTC_InitStruct->RTC_Alarm.HourAndMinute & RTC_ALMR);

    HT_RTC->RTCCON &= ~(uint32_t)RTC_RTCCON_TOUT;
    HT_RTC->RTCCON |= (uint32_t)RTC_InitStruct->RTC_TOUT;            /*!< Configure Tout Output          */
    
#if defined  USE_RTC_RTCSTAMP0 || defined  USE_RTC_RTCSTAMP01
    if(RTC_InitStruct->RTC_STAMP0.TSEN != DISABLE)
    {
        HT_RTC->RTCTS0CON = RTC_RTCTSxCON_TSCLR;
        HT_RTC->RTCTS0CON |= RTC_InitStruct->RTC_STAMP0.TSFILT;
        HT_RTC->RTCTS0CON |= RTC_InitStruct->RTC_STAMP0.TSPOL;
        if(RTC_InitStruct->RTC_STAMP0.TSCMP.NewState != DISABLE)
        {
            HT_RTC->RTCTS0CMP = RTC_InitStruct->RTC_STAMP0.TSCMP.Count;
            HT_RTC->RTCTS0CON |= RTC_RTCTSxCON_TSxCMPEN;          
        }
        else
        {
            HT_RTC->RTCTS0CON &=~RTC_RTCTSxCON_TSxCMPEN;
                
        }
        HT_RTC->RTCTS0CON |= RTC_RTCTSxCON_TSxEN;
    }
    else
    {
        HT_RTC->RTCTS0CON &= ~RTC_RTCTSxCON_TSxEN; 
    }
#endif
    
#if defined  USE_RTC_RTCSTAMP01 
    if(RTC_InitStruct->RTC_STAMP1.TSEN != DISABLE)
    {
        HT_RTC->RTCTS1CON = RTC_RTCTSxCON_TSCLR;
        HT_RTC->RTCTS1CON |= RTC_InitStruct->RTC_STAMP1.TSFILT;
        HT_RTC->RTCTS1CON |= RTC_InitStruct->RTC_STAMP1.TSPOL;
        if(RTC_InitStruct->RTC_STAMP1.TSCMP.NewState != DISABLE)
        {
            HT_RTC->RTCTS1CMP = RTC_InitStruct->RTC_STAMP1.TSCMP.Count;
            HT_RTC->RTCTS1CON |= RTC_RTCTSxCON_TSxCMPEN;          
        }
        else
        {
            HT_RTC->RTCTS1CON &=~RTC_RTCTSxCON_TSxCMPEN;                
        }
        HT_RTC->RTCTS1CON |= RTC_RTCTSxCON_TSxEN;
    }
    else
    {
        HT_RTC->RTCTS1CON &= ~RTC_RTCTSxCON_TSxEN;
    }
#endif  

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
    RTC_InitCallbacksToDefault(RTC_InitStruct);
#endif /* USE_HT_RTC_REGISTER_CALLBACKS */
}

/**
*********************************************************************************************************
*                                         READ RTC TIME
*
* @brief: Read RTC timer register,including week/year/month/day/hour/minute/second total seven registers
*
* @param: pRTCTime     void *variables,which point to objects used to store RTC time,are actually treated as uint8_t* in the program
*                      the storage sequence is as follows
*                         pRTCTime[0]: WEEKR
*                         pRTCTime[1]: YEARR
*                         pRTCTime[2]: MONTHR
*                         pRTCTime[3]: DAYR
*                         pRTCTime[4]: HOURR
*                         pRTCTime[5]: MINR
*                         pRTCTime[6]: SECR
*
* @retval: None
*
* @Note:   Users should avoid writing these registers while reading
*********************************************************************************************************
*/
void HT_RTC_Read(void *pRTCTime)
{
    /*  assert_param  */
    uint8_t *pRTCRead = pRTCTime;
    
    HT_RTC->RTCRD = RTC_RTCRD_READFLAG;                       /*!< Set the Start Read Flag */
    while(HT_RTC->RTCRD & RTC_RTCRD_READFLAG){}               /*!< Waiting to Read         */
                                                              /*!< Start Reading           */
    pRTCRead[0] = (uint8_t)(HT_RTC->WEEKR & RTC_WEEKR);
    pRTCRead[1] = (uint8_t)(HT_RTC->YEARR & RTC_YEARR);
    pRTCRead[2] = (uint8_t)(HT_RTC->MONTHR& RTC_MONTHR);
    pRTCRead[3] = (uint8_t)(HT_RTC->DAYR  & RTC_DAYR);
    pRTCRead[4] = (uint8_t)(HT_RTC->HOURR & RTC_HOURR);
    pRTCRead[5] = (uint8_t)(HT_RTC->MINR  & RTC_MINR);
    pRTCRead[6] = (uint8_t)(HT_RTC->SECR  & RTC_SECR);
}

/**
*********************************************************************************************************
*                                         WRITE RTC TIME
*
* @brief: Write RTC timer register,including week/year/month/day/hour/minute/second total seven registers
*
* @param: pRTCTime   void *variables,which point to objects used to store RTC time,are actually treated as uint8_t* in the program
*                    the storage sequence is as follows
*                       pRTCTime[0]: WEEKR
*                       pRTCTime[1]: YEARR
*                       pRTCTime[2]: MONTHR
*                       pRTCTime[3]: DAYR
*                       pRTCTime[4]: HOURR
*                       pRTCTime[5]: MINR
*                       pRTCTime[6]: SECR
*
* @retval: None
*
* @Note:   1) Update all timing registers at once,if the user wants to updata some registers, the user needs to read all timing registers before calling this function,
*              Then update the registers that need to be updated ,and finally writes together.
*          2) Users should avoid reading these registers while writing
*          3) Users should ensure the validity of written data
*********************************************************************************************************
*/
void HT_RTC_Write(void *pRTCTime)
{
    /*  assert_param  */
    uint8_t *pRTCWrite = pRTCTime;

    assert_param(IS_HT_RTC_WEEKR(pRTCWrite[0]));
    assert_param(IS_HT_RTC_YEARR(pRTCWrite[1]));
    assert_param(IS_HT_RTC_MONTHR(pRTCWrite[2]));
    assert_param(IS_HT_RTC_DAYR(pRTCWrite[3]));
    assert_param(IS_HT_RTC_HOURR(pRTCWrite[4]));
    assert_param(IS_HT_RTC_MINR(pRTCWrite[5]));
    assert_param(IS_HT_RTC_SECR(pRTCWrite[6]));

    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & 0x01];
                                                       /*!< Enable  Write Protect     */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;             /*!< Disable Write Protect    */

    HT_RTC->RTCWR = RTC_RTCWR_CLEAR;                   /*!< Clear Write Flag */
                                                       /*!< Start to Write */
    HT_RTC->WEEKR  = pRTCWrite[0] & RTC_WEEKR;
    HT_RTC->YEARR  = pRTCWrite[1] & RTC_YEARR;
    HT_RTC->MONTHR = pRTCWrite[2] & RTC_MONTHR;
    HT_RTC->DAYR   = pRTCWrite[3] & RTC_DAYR;
    HT_RTC->HOURR  = pRTCWrite[4] & RTC_HOURR;
    HT_RTC->MINR   = pRTCWrite[5] & RTC_MINR;
    HT_RTC->SECR   = pRTCWrite[6] & RTC_SECR;

    HT_RTC->RTCWR = RTC_RTCWR_UPDATE;                  /*!< Write Finish             */

    HT_CMU->WPREG = writeProtect;                      /*!< Enable Write Protect    */
}

/**
*********************************************************************************************************
*                                    RTC TIMER CONFIGURE
*
* @brief:  Set the status and timing period of RTC tmer1 or RTC timer2
*
* @param:  RTCTMRx    Select RTC tmer1 or RTC timer2
*
*          RTCTMR_InitStruct      RTC timer initializes the structure pointer, while contains the following two parameters
*                                  a) SetState  : Set the timer to enable or disable
*                                  b) Count     : Set the timer period
*                                                 for Rtc timer1,each Count represents 1s
*                                                 for Rtc timer2,each Count represents 0.0625s
*
* @retval: None
*
* @Note:   The actual timing period is (1+Count), that is between 1 and 65536.
*********************************************************************************************************
*/
void HT_RTC_TMRConfig(RTCTMR_SelectTypeDef RTCTMRx, RTCTMR_InitTypeDef *RTCTMR_InitStruct)
{
    /*  assert_param  */

    assert_param(IS_HT_RTC_RTCTMR(RTCTMRx));

    if(RTCTMR_InitStruct->NewState != DISABLE)
    {
        if(RTCTMRx == RTCTMR1)
        {
            HT_RTC->RTCTMR1 = (uint32_t)RTCTMR_InitStruct->Count;  /*!< Set RTC Timer1 Periodic Period  */
        }
        else
        {
            HT_RTC->RTCTMR2 = (uint32_t)RTCTMR_InitStruct->Count;  /*!< Set RTC Timer2 Periodic Period  */
        }
        HT_RTC->RTCCON |= (uint32_t)RTCTMRx;                       /*!< Enable  RTC Timer                */
    }
    else
    {
        HT_RTC->RTCCON &= (uint32_t)(~RTCTMRx);                  /*!< Disable  RTC Timer               */
    }
}

/**
*********************************************************************************************************
*                                       SET TOUT
*
* @brief: Set Tout to output a specific signal
*
* @param: RTCToutSet   Tout Outputs set parameters
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_ToutSet(RTCTout_TypeDef RTCToutSet)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_RTCCON_TOUT(RTCToutSet));

    HT_RTC->RTCCON &= ~(uint32_t)RTC_RTCCON_TOUT;
    HT_RTC->RTCCON |= (uint32_t)RTCToutSet;
}

/**
*********************************************************************************************************
*                                        SET ALARM
*
* @brief: Set alarm
*
* @param: RTCAlarmSet  Stores the time and minutes to set the alarm
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_AlarmSet(RTCAlarm_TypeDef RTCAlarmSet)
{
    /*  assert_param  */
    HT_RTC->ALMR = (uint32_t)(RTCAlarmSet.HourAndMinute & RTC_ALMR);

}

/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE RTC INTERRUPT
*
* @brief: Enable or disable RTC interrupt
*
* @param: ITEn     RTC interrupt setting bit, which can be one or a combination of the following parameters
*                       @arg RTC_RTCIE_SECIE
*                       @arg RTC_RTCIE_MINIE
*                       @arg RTC_RTCIE_HRIE
*                       @arg RTC_RTCIE_DAYIE
*                       @arg RTC_RTCIE_MTHIE
*                       @arg RTC_RTCIE_RTC1IE
*                       @arg RTC_RTCIE_RTC2IE
*                       @arg RTC_RTCIE_ALMIE
*
*          NewState   = ENABLE    Enable  Interrupt
*                     = DISABLE    Disable Interrupt
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_ITConfig(uint16_t ITEn, FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_RTCIE(ITEn));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState != DISABLE)
    {
        HT_RTC->RTCIE |= (uint32_t)ITEn;            /*!< Enable RTC Interrupt            */
    }
    else
    {
        HT_RTC->RTCIE &= ~(uint32_t)ITEn;           /*!< Disable RTC Interrupt            */
    }
}

/**
*********************************************************************************************************
*                            GET SPECIFIED RTC INTERRUPT FLAG STATUS
*
* @brief: Gets the corresponding RTC interrupt flag status
*
* @param: ITFlag   Check an RTC interrup with the following parameters
*                     @arg RTC_RTCIF_SECIF
*                     @arg RTC_RTCIF_MINIF
*                     @arg RTC_RTCIF_HRIF
*                     @arg RTC_RTCIF_DAYIF
*                     @arg RTC_RTCIF_MTHIF
*                     @arg RTC_RTCIF_RTC1IF
*                     @arg RTC_RTCIF_RTC2IF
*                     @arg RTC_RTCIF_ALMIF
*
* @retval: ITStatus   = SET    RTC Interrupt Flag is set
*                     = RESET  RTC Interrupt Flag is set
*
* @Note:   None
*********************************************************************************************************
*/
ITStatus HT_RTC_ITFlagStatusGet(uint16_t ITFlag)
{
    /*  assert_param  */
    ITStatus itflag;
    assert_param(IS_HT_RTC_RTCIF(ITFlag));

    if (HT_RTC->RTCIF & ITFlag)
    {
        itflag =  SET;                        /*!< RTC Interrupt Flag is Set   */
    }
    else
    {
        itflag = RESET;                      /*!< RTC Interrupt Flag is Reset */
    }
    return itflag;
}

/**
*********************************************************************************************************
*                                   CLEAR RTC INTERRUPT FLAG
*
* @brief: Clear RTC interrupt flag
*
* @param: ITFlag     Clear an RTC interrup with one or a combination of the following parameters
*                       @arg RTC_RTCIF_SECIF
*                       @arg RTC_RTCIF_MINIF
*                       @arg RTC_RTCIF_HRIF
*                       @arg RTC_RTCIF_DAYIF
*                       @arg RTC_RTCIF_MTHIF
*                       @arg RTC_RTCIF_RTC1IF
*                       @arg RTC_RTCIF_RTC2IF
*                       @arg RTC_RTCIF_ALMIF
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_ClearITPendingBit(uint16_t ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_RTCIF(ITFlag));

    HT_RTC->RTCIF  = ~((uint32_t)ITFlag);                  /*!< Clear RTC Interrupt Flag       */
}

/**
*********************************************************************************************************
*                                LOAD RTC COFFIENT FROM INFO FLASH
*
* @brief:  Load RTC compensation coefficients from infoflash
*
* @param:  None
*
* @retval: Bool    = FALSE  The coefficient stored in info is abnormal, and load failed
*                  = TRUE   The coefficient stored in info is   normal, and load successful
*
* @Note:  The user should ensure that Flash is in read state when this function is called
*********************************************************************************************************
*/
Bool HT_RTC_LoadInfoData(void)
{
    Bool status;
    uint32_t i, chksum;
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & 0x01];
                                                                 /*!< Enable Write Protect    */
    chksum=0U;
    for(i=0U; i<14U; i++)
    {
        chksum += HT_INFO->DataArry[i];
    }
    if((chksum != HT_INFO->DataArry[14])||(HT_INFO->DataArry[14]==0U))
    {                                                            /*!< Info Coefficient is Abnormal */
        /*!< The user can add further processing code here */
        status = FALSE;
    }
    else                                                         /*!< Info Coefficient is Normal  */
    {
        HT_CMU->WPREG = CMU_WPREG_UnProtected;                   /*!< Disable Write Protect       */

        if (HT_RTC->DFAH    != HT_INFO->Muster.iDFAH)  { HT_RTC->DFAH    = HT_INFO->Muster.iDFAH;}
        if (HT_RTC->DFAL    != HT_INFO->Muster.iDFAL)  { HT_RTC->DFAL    = HT_INFO->Muster.iDFAL;}
        if (HT_RTC->DFBH    != HT_INFO->Muster.iDFBH)  { HT_RTC->DFBH    = HT_INFO->Muster.iDFBH;}
        if (HT_RTC->DFBL    != HT_INFO->Muster.iDFBL)  { HT_RTC->DFBL    = HT_INFO->Muster.iDFBL;}
        if (HT_RTC->DFCH    != HT_INFO->Muster.iDFCH)  { HT_RTC->DFCH    = HT_INFO->Muster.iDFCH;}
        if (HT_RTC->DFCL    != HT_INFO->Muster.iDFCL)  { HT_RTC->DFCL    = HT_INFO->Muster.iDFCL;}
        if (HT_RTC->DFDH    != HT_INFO->Muster.iDFDH)  { HT_RTC->DFDH    = HT_INFO->Muster.iDFDH;}
        if (HT_RTC->DFDL    != HT_INFO->Muster.iDFDL)  { HT_RTC->DFDL    = HT_INFO->Muster.iDFDL;}
        if (HT_RTC->DFEH    != HT_INFO->Muster.iDFEH)  { HT_RTC->DFEH    = HT_INFO->Muster.iDFEH;}
        if (HT_RTC->DFEL    != HT_INFO->Muster.iDFEL)  { HT_RTC->DFEL    = HT_INFO->Muster.iDFEL;}
        if (HT_RTC->Toff    != HT_INFO->Muster.iToff)  { HT_RTC->Toff    = HT_INFO->Muster.iToff;}
#if defined  USE_RTC_MCON01_23
        if (HT_RTC->MCON01  != HT_INFO->Muster.iMCON01) { HT_RTC->MCON01  = HT_INFO->Muster.iMCON01;}
        if (HT_RTC->MCON23  != HT_INFO->Muster.iMCON23) { HT_RTC->MCON23  = HT_INFO->Muster.iMCON23;}
#endif
        if (HT_RTC->MCON45  != HT_INFO->Muster.iMCON45) { HT_RTC->MCON45  = HT_INFO->Muster.iMCON45;}
                                                                  /*!< Load Info  Coefficient            */

        HT_CMU->WPREG = writeProtect;                             /*!< Disable Write Protect     */

        status = TRUE;
    }
    return status;
}

#if defined  USE_RTC_RTC2CAL
/**
*********************************************************************************************************
*                                         AMEND RTC LRC TIME
*
* @brief:  RTC2 1S time to produce corrections
*
* @param:  TimeCalVal  Uint32_t variable, fix the second set of RTC to generate 1s = TimeCalVal/LRC
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_LRC_Amend(uint32_t TimeCalVal)
{
    /*  assert_param  */
    HT_RTC->RTC2CAL = TimeCalVal & RTC_RTC2CAL;
}
#endif

#if defined  USE_RTC_RTC2RD
/**
*********************************************************************************************************
*                                         READ RTC LRC TIME
*
* @brief: Read RTC2 time registers, including week/year/month/day/hour/minute/second total seven registers
*
* @param: pRTCTime   void *variables,which point to objects used to store RTC2 time,are actually treated as uint8_t* in the program
*                    the storage sequence is as follows
*                       pRTCTime[0]: WEEKR
*                       pRTCTime[1]: YEARR
*                       pRTCTime[2]: MONTHR
*                       pRTCTime[3]: DAYR
*                       pRTCTime[4]: HOURR
*                       pRTCTime[5]: MINR
*                       pRTCTime[6]: SECR
*
* @retval: None
*
* @Note:  Users should avoid writing these registers while reading
*********************************************************************************************************
*/
void HT_RTC_LRC_Read(void *pRTCTime)
{
    uint8_t *pRTCRead = pRTCTime;
    
    HT_RTC->RTCRD2 = RTC_RTCRD2_READFLAG;               /*!< Set the Start Read Flag      */
    while(HT_RTC->RTCRD2 & RTC_RTCRD2_READFLAG);        /*!< Waiting to Read              */
                                                        /*!< Start Reading                */
    pRTCRead[0] = (uint8_t)(HT_RTC->WEEKR2  & RTC_WEEKR2);
    pRTCRead[1] = (uint8_t)(HT_RTC->YEARR2  & RTC_YEARR2);
    pRTCRead[2] =(uint8_t) (HT_RTC->MONTHR2 & RTC_MONTHR2);
    pRTCRead[3] = (uint8_t)(HT_RTC->DAYR2   & RTC_DAYR2);
    pRTCRead[4] = (uint8_t)(HT_RTC->HOURR2  & RTC_HOURR2);
    pRTCRead[5] = (uint8_t)(HT_RTC->MINR2   & RTC_MINR2);
    pRTCRead[6] = (uint8_t) (HT_RTC->SECR2   & RTC_SECR2);
}
#endif

#if defined  USE_RTC_RTC2WR
/**
*********************************************************************************************************
*                                         WRITE RTC LRC TIME
*
* @brief: Write RTC2 timer register,including week/year/month/day/hour/minute/second total seven registers
*
* @param: pRTCTime   void *variables,which point to objects used to store RTC time,are actually treated as uint8_t* in the program
*                     the storage sequence is as follows
*                       pRTCTime[0]: WEEKR
*                       pRTCTime[1]: YEARR
*                       pRTCTime[2]: MONTHR
*                       pRTCTime[3]: DAYR
*                       pRTCTime[4]: HOURR
*                       pRTCTime[5]: MINR
*                       pRTCTime[6]: SECR
*
* @retval: None
*
* @Note:   1) Update all timing registers at once,if the user wants to updata some registers, the user needs to read all timing registers before calling this function,
*             Then update the registers that need to be updated ,and finally writes together.
*          2) Users should avoid reading these registers while writing.
*          3) Users should ensure the validity of written data.
*********************************************************************************************************
*/
void HT_RTC_LRC_Write(void *pRTCTime)
{

    uint8_t *pRTCWrite = pRTCTime;
    uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & 0x01];
                                                       /*!< Write Finish */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;             /*!< Disable Write Protect*/

    /*  assert_param  */
    assert_param(IS_HT_RTC2_WEEKR(pRTCWrite[0]));
    assert_param(IS_HT_RTC2_YEARR(pRTCWrite[1]));
    assert_param(IS_HT_RTC2_MONTHR(pRTCWrite[2]));
    assert_param(IS_HT_RTC2_DAYR(pRTCWrite[3]));
    assert_param(IS_HT_RTC2_HOURR(pRTCWrite[4]));
    assert_param(IS_HT_RTC2_MINR(pRTCWrite[5]));
    assert_param(IS_HT_RTC2_SECR(pRTCWrite[6]));

    HT_RTC->RTCWR2 = RTC_RTCWR2_CLEAR;                 /*!< Clear Write Flag */
                                                       /*!< Start to Write   */
    HT_RTC->WEEKR2  = pRTCWrite[0] & RTC_WEEKR2;
    HT_RTC->YEARR2  = pRTCWrite[1] & RTC_YEARR2;
    HT_RTC->MONTHR2 = pRTCWrite[2] & RTC_MONTHR2;
    HT_RTC->DAYR2   = pRTCWrite[3] & RTC_DAYR2;
    HT_RTC->HOURR2  = pRTCWrite[4] & RTC_HOURR2;
    HT_RTC->MINR2   = pRTCWrite[5] & RTC_MINR2;
    HT_RTC->SECR2   = pRTCWrite[6] & RTC_SECR2;

    HT_RTC->RTCWR2 = RTC_RTCWR2_UPDATE;                /*!< Write Finish  */
    HT_CMU->WPREG = writeProtect;                      /*!< Write Finish  */
}
#endif

#if defined USE_RTC_RTCCLKCFG
/**
*********************************************************************************************************
*                                         RTC CLK SET
*
* @brief:  RTCCLK CFG
*
* @param:  rtcclksel Uint32_t variable, RTC clock selection control
*            @arg CMU_RTCCLKCFG_RTCCLKSEL_OSC
*            @arg CMU_RTCCLKCFG_RTCCLKSEL_LRC
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_RTCCLK_CFG(uint32_t rtcclksel)
{
    HT_CMU->WPREG = CMU_WPREG_UnProtected;             /*!< Disable Write Protect*/
    /*assert_param  */
    assert_param(IS_HT_RTC_RTCCLKSEL(rtcclksel));
    
    HT_CMU->RTCCLKCFG &=~CMU_RTCCLKCFG_RTCCLKSEL;
        
    HT_CMU->RTCCLKCFG |= rtcclksel;

    HT_CMU->WPREG =  CMU_WPREG_Protected;              /*!< Enable Write Protect*/
}
#endif


#if defined USE_RTC_RTCTESTCTRL_C_OSC32K
/**
*********************************************************************************************************
*                                         RTC TEST CONCTRL
*
* @brief:  RTC Test Control Register
*
* @param:  c_osc32k  Uint32_t variable, 32K crystal power consumption adjustment
*             @arg RTC_RTCTESTCTRL_C_OSC32K_1000nA
*             @arg RTC_RTCTESTCTRL_C_OSC32K_692nA
*             @arg RTC_RTCTESTCTRL_C_OSC32K_530nA
*             @arg RTC_RTCTESTCTRL_C_OSC32K_430nA
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_OSC_Current_ADJ(uint32_t c_osc32k)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_C_OSC32K(c_osc32k));
  
    HT_RTC->RTCTESTCTRL = (RTC_RTCTESTCTRL_RTCTEST_WP_UnProtected | c_osc32k);   //RTC Test Control Register Lower 8 Write Protection Close

    HT_RTC->RTCTESTCTRL  =  RTC_RTCTESTCTRL_RTCTEST_WP_Protected;   //RTC Test Control Register Lower 8 Write Protection Open
}
#endif


#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                 ENABLE OR DISABLE RTCSTAMPx(x=0/1)  INTERRUPT
*
* @brief: Enable or disable RTCSTAMPx(x=0/1) interrupt
*
* @param:  STAMPx   Only STAMP0 or STAMP1  
*          
*          ITEn     RTCSTAMPx(x=0/1) interrupt setting bit, which can be one or a combination of the following parameters
*                       @arg RTC_RTCTSxIE_TSxOVIE
*                       @arg RTC_RTCTSxIE_TSxCMPIE
*                       @arg RTC_RTCTSxIE_TSxIE
*           
*          NewState   = ENABLE    Enable  Interrupt
*                     = DISABLE   Disable Interrupt
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTCSTAMP_ITConfig(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITEn, FunctionalState NewState)
{
    /*assert_param  */  
    assert_param(IS_HT_RTC_RTCSTAMP(STAMPx));    
    assert_param(IS_HT_RTC_RTCTSxIE(ITEn));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
   
    if(STAMPx==STAMP0)
    {
        if(NewState != DISABLE)
        {
             HT_RTC->RTCTS0IE |= ITEn;
        }
        else 
        {
             HT_RTC->RTCTS0IE &= ~ITEn;             
        }    
    }
#if defined USE_RTC_RTCSTAMP01      
    if(STAMPx==STAMP1)
    {
        if(NewState != DISABLE)
        {
             HT_RTC->RTCTS1IE |= ITEn;
        }
        else 
        {
             HT_RTC->RTCTS1IE &= ~ITEn;             
        }    
    }
#endif
}
#endif

#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                            GET SPECIFIED  RTCSTAMPx(x=0/1) INTERRUPT FLAG STATUS
*
* @brief: Gets the corresponding RTCSTAMPx(x=0/1) interrupt flag status
*
* @param: STAMPx   Only STAMP0 or STAMP1
*
*         ITFlag   Check an RTCSTAMPx(x=0/1) interrup with the following parameters
*                     @arg RTC_RTCTSxIF_TSxOVIF
*                     @arg RTC_RTCTSxIF_TSxCMPIF
*                     @arg RTC_RTCTSxIF_TSxIF
*
*
* @retval: ITStatus   = SET     RTCSTAMPx(x=0/1) Interrupt Flag is set
*                     = RESET   RTCSTAMPx(x=0/1) Interrupt Flag is set
*
* @Note:   None
*********************************************************************************************************
*/
ITStatus HT_RTCSTAMP_ITFlagStatusGet(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITFlag)
{
    /*  assert_param  */
    ITStatus itflag;
    assert_param(IS_HT_RTC_RTCSTAMP(STAMPx)); 
    assert_param(IS_HT_RTC_RTCTSxIF(ITFlag));
    if(STAMPx==STAMP0)
    {
        if(HT_RTC->RTCTS0IF & ITFlag)
        {
            itflag =  SET;       
        }
        else
        {
            itflag = RESET;            
        }
    }
#if defined USE_RTC_RTCSTAMP01
    if(STAMPx==STAMP1)
    {
        if(HT_RTC->RTCTS1IF & ITFlag)
        {
            itflag =  SET;       
        }
        else
        {
            itflag = RESET;            
        }
    }
#endif
    return itflag;
}
#endif

#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                   CLEAR  RTCSTAMPx(x=0/1) INTERRUPT FLAG
*
* @brief: Clear  RTCSTAMPx(x=0/1) interrupt flag
*
* @param: STAMPx   Only STAMP0 or STAMP1
*
*         ITFlag   Clear an  RTCSTAMPx(x=0/1) interrup with one or a combination of the following parameters
*                     @arg RTC_RTCTSxIF_TSxOVIF
*                     @arg RTC_RTCTSxIF_TSxCMPIF
*                     @arg RTC_RTCTSxIF_TSxIF
*
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTCSTAMP_ClearITPendingBit(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITFlag)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_RTCSTAMP(STAMPx)); 
    assert_param(IS_HT_RTC_RTCTSxIF(ITFlag));
    if(STAMPx==STAMP0)
    {    
        HT_RTC->RTCTS0IF &= ~ITFlag;
    }
#if defined USE_RTC_RTCSTAMP01
    if(STAMPx==STAMP1)
    {    
        HT_RTC->RTCTS1IF &= ~ITFlag;
    } 
#endif    
}
#endif 


#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                   Get RTCSTAMPx(x=0/1) Event Count 
*
* @brief: Get RTCSTAMPx(x=0/1) Event Count
*
* @param: STAMPx      Only STAMP0 or STAMP1
*
* @retval: rtctsxcnt   Event Count
*
* @Note:   None
*********************************************************************************************************
*/
uint32_t HT_RTCSTAMP_GetEventCount(RTCSTAMP_SelectTypeDef STAMPx)
{
     /*  assert_param  */
    uint32_t rtctsxcnt;
    assert_param(IS_HT_RTC_RTCSTAMP(STAMPx)); 
    if(STAMPx==STAMP0)
    {    
        rtctsxcnt = HT_RTC->RTCTS0CNT;
    } 
#if defined USE_RTC_RTCSTAMP01
    if(STAMPx==STAMP1)
    {    
        rtctsxcnt = HT_RTC->RTCTS1CNT;
    } 
#endif
    return rtctsxcnt; 
}
#endif

#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                           Get RTCSTAMPx(x=0/1) Trigger Source Cache Infomation
*
* @brief:  Read RTCSTAMPx(x=0/1) Trigger Source Cache Infomation
*
* @param:  STAMPx             Only STAMP0 or STAMP1
*
*          TriSource          Use TriSource  store  The RTC triggers source information
*
*          RTCTSNUM_TypeDef   TriSource Cache Select
*                               @arg TSNUM0
*                               @arg TSNUM1
*                               @arg TSNUM2
*                               @arg TSNUM3
*                               @arg TSNUM4
*                               @arg TSNUM5
*                                      
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTCSTAMP_GetTriggerSource(RTCSTAMP_SelectTypeDef STAMPx,HT_RTC_STAMPSOURCE_TypeDef *TriSource,RTCTSNUM_TypeDef num)
{
    /*  assert_param  */
    assert_param(IS_HT_RTC_RTCSTAMP(STAMPx));
    assert_param(IS_HT_RTC_RTCTSNUM(num));
    if(STAMPx==STAMP0)
    { 
        switch(num)
        {
            case TSNUM0:    
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM0;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT0;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU0;
                    break;
            case TSNUM1:    
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM1;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT1;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU1;
                    break;
            case TSNUM2: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM2;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT2;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU2;
                    break;
            case TSNUM3: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM3;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT3;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU3;
                    break; 
            case TSNUM4: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM4;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT4;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU4;
                    break;      
            case TSNUM5: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS0TIM5;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS0DAT5;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS0SOU5;
                    break;  
            default:
                    break;
        }   
    } 
#if defined USE_RTC_RTCSTAMP01
    if(STAMPx==STAMP1)
    { 
        switch(num)
        {
            case TSNUM0:    
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM0;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT0;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU0;
                    break;
            case TSNUM1:    
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM1;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT1;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU1;
                    break;
            case TSNUM2: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM2;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT2;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU2;
                    break;
            case TSNUM3: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM3;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT3;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU3;
                    break; 
            case TSNUM4: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM4;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT4;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU4;
                    break;      
            case TSNUM5: 
                    TriSource->RTCTSTIM = HT_RTC->RTCTS1TIM5;
                    TriSource->RTCTSDAT = HT_RTC->RTCTS1DAT5;
                    TriSource->RTCTSSOU = HT_RTC->RTCTS1SOU5;
                    break;  
            default:
                    break;
        }         
    }   
#endif
}
#endif

#if defined  USE_RTC_RTCBACKUP_REG
/**
*********************************************************************************************************
*                                    WRITE RTC BACKUP REGISTER
*
* @brief: Write RTC Backup Register Data
*
* @param: BackupRegister  Check an  BackupRegister with the following parameters
*                             @arg RTC_BKP_DR0  
*                             @arg RTC_BKP_DR1  
*                             @arg RTC_BKP_DR2  
*                             @arg RTC_BKP_DR3
*                             @arg RTC_BKP_DR4  
*                             @arg RTC_BKP_DR5 
*                             @arg RTC_BKP_DR6  
*                             @arg RTC_BKP_DR7
*                             @arg RTC_BKP_DR8 
*                             @arg RTC_BKP_DR9  
*                             @arg RTC_BKP_DR10  
*                             @arg RTC_BKP_DR11
*                             @arg RTC_BKP_DR12  
*                             @arg RTC_BKP_DR13  
*                             @arg RTC_BKP_DR14  
*                             @arg RTC_BKP_DR15
*                             @arg RTC_BKP_DR16  
*                             @arg RTC_BKP_DR17  
*                             @arg RTC_BKP_DR18  
*                             @arg RTC_BKP_DR19
*                             @arg RTC_BKP_DR20  
*                             @arg RTC_BKP_DR21  
*                             @arg RTC_BKP_DR22  
*                             @arg RTC_BKP_DR23
*                             @arg RTC_BKP_DR24  
*                             @arg RTC_BKP_DR25  
*                             @arg RTC_BKP_DR26  
*                             @arg RTC_BKP_DR27
*                             @arg RTC_BKP_DR28  
*                             @arg RTC_BKP_DR29  
*                             @arg RTC_BKP_DR30  
*                             @arg RTC_BKP_DR31
*
*          Data      Uint32_t variable, Write the value to Backup Register
*          
* @retval: None
*
* @Note:   None
*********************************************************************************************************
*/
void HT_RTC_RTCBACKUP_Write(uint32_t BackupRegister,uint32_t Data)
{
    uint32_t tempreg = 0U;
    /*  assert_param  */
    assert_param(IS_HT_RTC_BACKUP(BackupRegister));
    tempreg = (uint32_t)&(HT_RTC->RTCBACKUP[0]); 
    tempreg += (BackupRegister * 4U);
    
    /* Write the Backup register */
    *( uint32_t *)tempreg = (uint32_t) Data;
}

/**
*********************************************************************************************************
*                                    READ RTC BACKUP REGISTER
*
* @brief:  Read RTC Backup Register Data
*
* @param:  BackupRegister  Check an  BackupRegister with the following parameters
*                             @arg RTC_BKP_DR0  
*                             @arg RTC_BKP_DR1  
*                             @arg RTC_BKP_DR2  
*                             @arg RTC_BKP_DR3
*                             @arg RTC_BKP_DR4  
*                             @arg RTC_BKP_DR5 
*                             @arg RTC_BKP_DR6  
*                             @arg RTC_BKP_DR7
*                             @arg RTC_BKP_DR8 
*                             @arg RTC_BKP_DR9  
*                             @arg RTC_BKP_DR10  
*                             @arg RTC_BKP_DR11
*                             @arg RTC_BKP_DR12  
*                             @arg RTC_BKP_DR13  
*                             @arg RTC_BKP_DR14  
*                             @arg RTC_BKP_DR15
*                             @arg RTC_BKP_DR16  
*                             @arg RTC_BKP_DR17  
*                             @arg RTC_BKP_DR18  
*                             @arg RTC_BKP_DR19
*                             @arg RTC_BKP_DR20  
*                             @arg RTC_BKP_DR21  
*                             @arg RTC_BKP_DR22  
*                             @arg RTC_BKP_DR23
*                             @arg RTC_BKP_DR24  
*                             @arg RTC_BKP_DR25  
*                             @arg RTC_BKP_DR26  
*                             @arg RTC_BKP_DR27
*                             @arg RTC_BKP_DR28  
*                             @arg RTC_BKP_DR29  
*                             @arg RTC_BKP_DR30  
*                             @arg RTC_BKP_DR31
*          
* @retval: Read value
*
* @Note:   None
*********************************************************************************************************
*/
uint32_t HT_RTC_RTCBACKUP_Read(uint32_t BackupRegister)
{
    uint32_t tempreg = 0U;
    /*  assert_param  */
    assert_param(IS_HT_RTC_BACKUP(BackupRegister));
    tempreg = (uint32_t)&(HT_RTC->RTCBACKUP[0]); 
    tempreg += (BackupRegister * 4U);
    
     /* Read the specified register */
    return (*( uint32_t *)tempreg);
}
#endif

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
/**  
* @brief  Register a User RTC Callback
*         To be used instead of the weak predefined callback
* @param  RTC_InitStruct uart handle
* @param  CallbackID ID of the callback to be registered
*         This parameter can be one of the following values:
*           @arg @ref RTC_SEC_CB_ID     Callback ID
*           @arg @ref RTC_MIN_CB_ID     Callback ID
*           @arg @ref RTC_HOUR_CB_ID    Callback ID
*           @arg @ref RTC_DAY_CB_ID     Callback ID
*           @arg @ref RTC_MONTH_CB_ID   Callback ID
*           @arg @ref RTC_RTCTMR1_CB_ID Callback ID
*           @arg @ref RTC_RTCTMR2_CB_ID Callback ID
*           @arg @ref RTC_RTCALMR_CB_ID Callback ID
*           @arg @ref RTC_TS0OV_CB_ID   Callback ID
*           @arg @ref RTC_TS0CMP_CB_ID  Callback ID
*           @arg @ref RTC_TS0TRI_CB_ID  Callback ID
*           @arg @ref RTC_TS1OV_CB_ID   Callback ID
*           @arg @ref RTC_TS1CMP_CB_ID  Callback ID
*           @arg @ref RTC_TS1TRI_CB_ID  Callback ID
*
* @param  pCallback pointer to the Callback function
* @retval status
* @note: when USE_HT_RTC_REGISTER_CALLBACKS == 1U,this function shoud be called if user want to register
*   himself defined callback function.
*/
StatusTypeDef HT_RTC_RegisterCallback(RTC_InitTypeDef *RTC_InitStruct, RTC_CallbackIDTypeDef CallbackID, pRTC_CallbackTypeDef pCallback)
{
    StatusTypeDef status = OK;

    if (pCallback == NULL)
    {
        /* Update the error code */
        RTC_InitStruct->ErrorCode |= RTC_ERROR_INVALID_CALLBACK;

        status = ERROR;
    }
    switch (CallbackID)
    {
        case RTC_SEC_CB_ID :
            RTC_InitStruct->RTCSecCallback = pCallback;
            break;

        case RTC_MIN_CB_ID :
            RTC_InitStruct->RTCMinCallback = pCallback;
            break;

        case RTC_HOUR_CB_ID :
            RTC_InitStruct->RTCHourCallback= pCallback;
            break;

        case RTC_DAY_CB_ID :
            RTC_InitStruct->RTCDayCallback = pCallback;
            break;

        case RTC_MONTH_CB_ID :
            RTC_InitStruct->RTCMonthCallback = pCallback;
            break;

        case RTC_RTCTMR1_CB_ID :
            RTC_InitStruct->RTCTmr1Callback = pCallback;
            break;

        case RTC_RTCTMR2_CB_ID :
            RTC_InitStruct->RTCTmr2Callback = pCallback;
            break;

        case RTC_RTCALMR_CB_ID :
            RTC_InitStruct->RTCAlmCallback = pCallback;
            break;
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
        case RTC_TS0OV_CB_ID :
            RTC_InitStruct->RTCTS0ovCallback = pCallback;
            break;
        case RTC_TS0CMP_CB_ID :
            RTC_InitStruct->RTCTS0cmpCallback = pCallback;
            break;
       case RTC_TS0TRI_CB_ID :
            RTC_InitStruct->RTCTS0triCallback = pCallback;
            break;
#endif  
#if defined USE_RTC_RTCSTAMP01       
       case RTC_TS1OV_CB_ID :
            RTC_InitStruct->RTCTS1ovCallback = pCallback;
            break;
       case RTC_TS1CMP_CB_ID :
            RTC_InitStruct->RTCTS1cmpCallback = pCallback;
            break;
       case RTC_TS1TRI_CB_ID :
            RTC_InitStruct->RTCTS1triCallback = pCallback;
            break;     
#endif               
        default :
            /* Update the error code */
            RTC_InitStruct->ErrorCode |= RTC_ERROR_INVALID_CALLBACK;
            /* Return error status */
            status =  ERROR;
            break;
    }
    return status;
}

/**
*********************************************************************************************************
*                                         INITIAL RTC CALLBACK SETTINGS
*
* @brief: Initialize the callbacks to their default values.
*
* @param: RTC_InitStruct Pointer to a RTC_InitTypeDef structure that contains
*               the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_InitCallbacksToDefault(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Init the RTC Callback settings */
    RTC_InitStruct->RTCSecCallback  = HT_RTC_RTCSecCallback;           /* Legacy weak RTCSecCallback */
    RTC_InitStruct->RTCMinCallback  = HT_RTC_RTCMinCallback;           /* Legacy weak RTCMinCallback */
    RTC_InitStruct->RTCHourCallback = HT_RTC_RTCHourCallback;          /* Legacy weak RTCHourCallback */
    RTC_InitStruct->RTCDayCallback  = HT_RTC_RTCDayCallback;           /* Legacy weak RTCDayCallback */
    RTC_InitStruct->RTCMonthCallback = HT_RTC_RTCMonthCallback;        /* Legacy weak RTCMonthCallback */
    RTC_InitStruct->RTCTmr1Callback = HT_RTC_RTCTmr1Callback;          /* Legacy weak RTCTmr1Callback */
    RTC_InitStruct->RTCTmr2Callback = HT_RTC_RTCTmr2Callback;          /* Legacy weak RTCTmr2Callback */
    RTC_InitStruct->RTCAlmCallback  = HT_RTC_RTCAlmCallback;           /* Legacy weak RTCAlmCallback */
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
    RTC_InitStruct->RTCTS0ovCallback = HT_RTC_RTCTS0ovCallback;        /* Legacy weak RTCTS0ovCallback */
    RTC_InitStruct->RTCTS0cmpCallback = HT_RTC_RTCTS0cmpCallback;      /* Legacy weak RTCTS0cmpCallback */
    RTC_InitStruct->RTCTS0triCallback = HT_RTC_RTCTS0triCallback;      /* Legacy weak RTCTS0triCallback */
#endif
#if defined USE_RTC_RTCSTAMP01 
    RTC_InitStruct->RTCTS1ovCallback = HT_RTC_RTCTS1ovCallback;        /* Legacy weak RTCTS1ovCallback */
    RTC_InitStruct->RTCTS1cmpCallback = HT_RTC_RTCTS1cmpCallback;      /* Legacy weak RTCTS1cmpCallback */
    RTC_InitStruct->RTCTS1triCallback = HT_RTC_RTCTS1triCallback;      /* Legacy weak RTCTS1triCallback */
#endif
}

/**
*********************************************************************************************************
*                                       SECOND IT HANDLER
*
* @brief: Second Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_SEC_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Second Interrupt callback*/
    if(RTC_InitStruct->RTCSecCallback != NULL)
    {
        RTC_InitStruct->RTCSecCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       MINUTE IT HANDLER
*
* @brief: Minute Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_MIN_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Minute Interrupt callback*/
    if(RTC_InitStruct->RTCMinCallback != NULL)
    {
        RTC_InitStruct->RTCMinCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       HOUR IT HANDLER
*
* @brief: Hour Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_HOUR_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Hour Interrupt callback*/
    if(RTC_InitStruct->RTCHourCallback != NULL)
    {
        RTC_InitStruct->RTCHourCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       DAY IT HANDLER
*
* @brief: Day Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_DAY_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Day Interrupt callback*/
    if(RTC_InitStruct->RTCDayCallback != NULL)
    {
        RTC_InitStruct->RTCDayCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       MONTH IT HANDLER
*
* @brief: Month Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_MONTH_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Month Interrupt callback*/
    if(RTC_InitStruct->RTCMonthCallback != NULL)
    {
        RTC_InitStruct->RTCMonthCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTCTMR1 IT HANDLER
*
* @brief: Rtctmr1 Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_TMR1_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Rtctmr1 Interrupt callback*/
    if(RTC_InitStruct->RTCTmr1Callback != NULL)
    {
        RTC_InitStruct->RTCTmr1Callback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTCTMR2 IT HANDLER
*
* @brief: Rtctmr2 Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_TMR2_IT(RTC_InitTypeDef *RTC_InitStruct)
{
    /*Call registered Rtctmr2 Interrupt callback*/
    if(RTC_InitStruct->RTCTmr2Callback != NULL)
    {
        RTC_InitStruct->RTCTmr2Callback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTC ALARM IT HANDLER
*
* @brief:  RTC alarm  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_ALARM_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCAlmCallback != NULL)
    {
        RTC_InitStruct->RTCAlmCallback(RTC_InitStruct);
    }
} 

#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                       RTC RTCTS0OV IT HANDLER
*
* @brief:  RTC TS0OV  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS0OV_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS0ovCallback != NULL)
    {
        RTC_InitStruct->RTCTS0ovCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTC RTCTS0CMP IT HANDLER
*
* @brief:  RTC TS0CMP  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS0CMP_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS0cmpCallback != NULL)
    {
        RTC_InitStruct->RTCTS0cmpCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTC RTCTS0TRI IT HANDLER
*
* @brief:  RTC TS0TRI  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS0TRI_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS0triCallback != NULL)
    {
        RTC_InitStruct->RTCTS0triCallback(RTC_InitStruct);
    }
}

#endif
#if defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                       RTC RTCTS1OV IT HANDLER
*
* @brief:  RTC TS1OV  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS1OV_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS1ovCallback != NULL)
    {
        RTC_InitStruct->RTCTS1ovCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTC RTCTS1CMP IT HANDLER
*
* @brief:  RTC TS1CMP  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS1CMP_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS1cmpCallback != NULL)
    {
        RTC_InitStruct->RTCTS1cmpCallback(RTC_InitStruct);
    }
}

/**
*********************************************************************************************************
*                                       RTC RTCTS1TRI IT HANDLER
*
* @brief:  RTC TS1TRI  Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
static void RTC_RTCTS1TRI_IT(RTC_InitTypeDef *RTC_InitStruct)
{
   /*Call registered RTC alarm Interrupt callback*/
    if(RTC_InitStruct->RTCTS1triCallback != NULL)
    {
        RTC_InitStruct->RTCTS1triCallback(RTC_InitStruct);
    }
}
#endif

/**
*********************************************************************************************************
*                                         RTC IRQ HANDLER
*
* @brief: This function handles RTC interrupt request.
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                         the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
void HT_RTC_IRQHandler(RTC_InitTypeDef *RTC_InitStruct)
{
    uint8_t Flag = HT_RTC->RTCIF;
    HT_RTC->RTCIF=0;                                       /*!< clear interrupt flag  */
#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
    uint8_t Ts0Flag = HT_RTC->RTCTS0IF;
    HT_RTC->RTCTS0IF = 0;                                  /*!< clear RtcStmp0 interrupt flag  */
#endif
#if defined USE_RTC_RTCSTAMP01    
    uint8_t Ts1Flag = HT_RTC->RTCTS1IF;
    HT_RTC->RTCTS1IF = 0;                                  /*!< clear RtcStmp0 interrupt flag  */
#endif    
    if(Flag & RTC_RTCIF_SECIF)                             /*!< second interrupt */
    {
        RTC_SEC_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_SECIF);         /*!< clear second interrupt flag */      
    }

    if(Flag & RTC_RTCIF_MINIF)                             /*!< minute interrupt */
    {     
        RTC_MIN_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_MINIF);         /*!< clear minute interrupt flag */
    }

    if(Flag & RTC_RTCIF_HRIF)                              /*!< hour interrupt */
    {       
        RTC_HOUR_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_HRIF);          /*!< clear hour interrupt flag */
    }

    if(Flag & RTC_RTCIF_DAYIF)                             /*!< day interrupt */
    {        
        RTC_DAY_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_DAYIF);         /*!< clear day interrupt flag */
    }

    if(Flag & RTC_RTCIF_MTHIF)                             /*!< month interrupt */
    {
        RTC_MONTH_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_MTHIF);         /*!< clear month interrupt flag */
    }

    if(Flag & RTC_RTCIF_RTC1IF)                            /*!< rtctimr1 interrupt */
    {        
        RTC_TMR1_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_RTC1IF);        /*!< clear rtctimr1 interrupt flag */
    }

    if(Flag & RTC_RTCIF_RTC2IF)                            /*!< rtctimr2 interrupt */
    {
        RTC_TMR2_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_RTC2IF);        /*!< clear rtctimr2 interrupt flag */
    }

    if(Flag & RTC_RTCIF_ALMIF)                             /*!< alarm interrupt */
    {
        RTC_ALARM_IT(RTC_InitStruct);
        HT_RTC_ClearITPendingBit(RTC_RTCIF_ALMIF);         /*!< clear alarm interrupt flag */
    }
#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01  
    if(Ts0Flag & RTC_RTCTSxIF_TSxOVIF)                   
    {
        RTC_RTCTS0OV_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP0,RTC_RTCTSxIF_TSxOVIF);   /*!<clear timestamp0 count overflow interrupt flag */              
    } 
    if(Ts0Flag & RTC_RTCTSxIF_TSxCMPIF)                  
    {
        RTC_RTCTS0CMP_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP0,RTC_RTCTSxIF_TSxCMPIF);  /*!<clear timestamp0 count comparison interrupt flag */                 
    } 
    if(Ts0Flag & RTC_RTCTSxIF_TSxIF)                  
    {
        RTC_RTCTS0TRI_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP0,RTC_RTCTSxIF_TSxIF);     /*!<clear timestamp0 trigger interrupt flag */         
    }  
#endif
#if defined USE_RTC_RTCSTAMP01 
    if(Ts1Flag & RTC_RTCTSxIF_TSxOVIF)                   
    {
        RTC_RTCTS1OV_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP1,RTC_RTCTSxIF_TSxOVIF);   /*!<clear timestamp1 count overflow interrupt flag */              
    } 
    if(Ts1Flag & RTC_RTCTSxIF_TSxCMPIF)                  
    {
        RTC_RTCTS1CMP_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP1,RTC_RTCTSxIF_TSxCMPIF);  /*!<clear timestamp1 count comparison interrupt flag */                 
    } 
    if(Ts1Flag & RTC_RTCTSxIF_TSxIF)                  
    {
        RTC_RTCTS1TRI_IT(RTC_InitStruct); 
        HT_RTCSTAMP_ClearITPendingBit(STAMP1,RTC_RTCTSxIF_TSxIF);     /*!<clear timestamp1 trigger interrupt flag */         
    }       
#endif   
}

/**
*********************************************************************************************************
*                                         SECOND IT CALLBACK
*
* @brief: Second Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCSecCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCSecCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         MINUTE IT CALLBACK
*
* @brief: Minute Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCMinCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_RTC_RTCMinCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         HOUR IT CALLBACK
*
* @brief: Hour Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCHourCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCHourCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         DAY IT CALLBACK
*
* @brief: Day Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCDayCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
             the HT_RTC_RTCDayCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         MONTH IT CALLBACK
*
* @brief: Month Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCMonthCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCMonthCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTMR1 IT CALLBACK
*
* @brief: Rtctmr1 Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTmr1Callback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTmr1Callback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTMR2 IT CALLBACK
*
* @brief: Rtctmr2 Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTmr2Callback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
            the HT_RTC_RTCTmr2Callback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCALARM IT CALLBACK
*
* @brief: Rtc Alarm Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCAlmCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCAlmCallback could be implemented in the user file
    */
}

#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                         RTCTS0OV IT CALLBACK
*
* @brief: RTC Timestamp0 Event Counts the Overflow Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note:  None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS0ovCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS0ovCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTS0CMP IT CALLBACK
*
* @brief: RTC Timestamp0 Event Counts Compare Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS0cmpCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS0cmpCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTS0TRI IT CALLBACK
*
* @brief: RTC Timestamp0 Trigger Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS0triCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS0triCallback could be implemented in the user file
    */
}
#endif

#if defined USE_RTC_RTCSTAMP01
/**
*********************************************************************************************************
*                                         RTCTS1OV IT CALLBACK
*
* @brief: RTC Timestamp1 Event Counts the Overflow Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note:  None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS1ovCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS1ovCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTS1CMP IT CALLBACK
*
* @brief: RTC Timestamp1 Event Counts Compare Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS1cmpCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS1cmpCallback could be implemented in the user file
    */
}

/**
*********************************************************************************************************
*                                         RTCTS1TRI IT CALLBACK
*
* @brief: RTC Timestamp1 Trigger Interrupt Hander
*
* @param: RTC_InitStruct  Pointer to a RTC_InitTypeDef structure that contains
*                the configuration information for the specified RTC module.
* @retval: None
*
* @Note: None
*********************************************************************************************************
*/
__weak void HT_RTC_RTCTS1triCallback(RTC_InitTypeDef *RTC_InitStruct)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(RTC_InitStruct);
    /* NOTE: This function should not be modified, when the callback is needed,
           the HT_RTC_RTCTS1triCallback could be implemented in the user file
    */
}
#endif

#endif
