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
* File         : ht6xxx_rtc.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_RTC_H__
#define __HT6XXX_RTC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                          Global Macro/Structure
*********************************************************************************************************
*/
/**
* @brief  RTC Callback ID enumeration definition
*/
typedef enum
{
	RTC_SEC_CB_ID             = 0x01U,    	 /*!< RTC SECOND  Callback ID   */
	RTC_MIN_CB_ID             = 0x02U,    	 /*!< RTC MINUTE  Callback ID   */
	RTC_HOUR_CB_ID            = 0x03U,    	 /*!< RTC HOUR    Callback ID   */
	RTC_DAY_CB_ID             = 0x04U,    	 /*!< RTC DAY     Callback ID   */	
	RTC_MONTH_CB_ID           = 0x05U,    	 /*!< RTC MONTH   Callback ID  */	
	RTC_RTCTMR1_CB_ID         = 0x06U,       /*!< RTC RTCTMR1 Callback ID  */	
	RTC_RTCTMR2_CB_ID         = 0x07U,       /*!< RTC RTCTMR2 Callback ID  */
	RTC_RTCALMR_CB_ID         = 0x08U,       /*!< RTC RTCALMR Callback ID  */	
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
    RTC_TS0OV_CB_ID           = 0x09U,       /*!< RTC RTCTS0OV Callback ID  */ 
    RTC_TS0CMP_CB_ID          = 0x0aU,       /*!< RTC RTCTS0CMP Callback ID  */ 
    RTC_TS0TRI_CB_ID          = 0x0bU,       /*!< RTC RTCTS0TRI Callback ID  */ 
#endif 
#if defined USE_RTC_RTCSTAMP01
    RTC_TS1OV_CB_ID           = 0x0cU,       /*!< RTC RTCTS1OV Callback ID  */ 
    RTC_TS1CMP_CB_ID          = 0x0dU,       /*!< RTC RTCTS1CMP Callback ID  */ 
    RTC_TS1TRI_CB_ID          = 0x0eU,       /*!< RTC RTCTS1TRI Callback ID  */ 
#endif   
} RTC_CallbackIDTypeDef;
	
/**
* @brief  RTC Timer definition
*/
typedef enum
{
    RTCTMR1 = RTC_RTCCON_RTC1EN,   /*!< RTCTimer1                        */
    RTCTMR2 = RTC_RTCCON_RTC2EN,   /*!< RTCTimer2                        */
}RTCTMR_SelectTypeDef;             /*!< end of group RTCTMR_SelectTypeDef */

/**
* @brief  RTC Timer initialization definition
*/
typedef struct
{
    FunctionalState NewState;      /*!< Timer Status Setting: Enable or Disable */
    uint16_t  Count;               /*!< Timer Timing Period Setting            */
}RTCTMR_InitTypeDef;               /*!< end of group RTCTMR_InitTypeDef   */

/**
* @brief  Tout Output definition
*/
typedef enum
{
    ToutLOW    = RTC_RTCCON_TOUT_LOW,
    ToutHigh   = RTC_RTCCON_TOUT_HIGH,
    ToutLF     = RTC_RTCCON_TOUT_LF,
    Tout1Hz    = RTC_RTCCON_TOUT_1HZ,
    Tout2Hz    = RTC_RTCCON_TOUT_2HZ,
    Tout4Hz    = RTC_RTCCON_TOUT_4HZ,
    Tout8Hz    = RTC_RTCCON_TOUT_8HZ,	
#if defined USE_RTC_RTCCON_TOUT_16TO128HZ
    Tout16Hz   = RTC_RTCCON_TOUT_16HZ,
    Tout32Hz   = RTC_RTCCON_TOUT_32HZ,
    Tout64Hz   = RTC_RTCCON_TOUT_64HZ,
    Tout128Hz  = RTC_RTCCON_TOUT_128HZ,
#endif
}RTCTout_TypeDef;                  /*!< end of group RTCTout_TypeDef  */

/*
* @brief  Alarm Settings definition
*/
typedef union
{
    struct
    {
        uint8_t minute;            /*!< Alarm Register Minute Setting */
        uint8_t hour;              /*!< Alarm Register Hour   Setting   */
    }Muster;
    uint16_t HourAndMinute;
}RTCAlarm_TypeDef;                 /*!< end of group RTCAlarm_TypeDef */


/**
* @brief  RTC STAMP initialization definition
*/
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
/**
* @brief  RTC TSNUM definition
*/
typedef enum
{
    TSNUM0 = 0x00,
    TSNUM1 = 0x01,
    TSNUM2 = 0x02,
    TSNUM3 = 0x03,
    TSNUM4 = 0x04,
    TSNUM5 = 0x05,     
}
RTCTSNUM_TypeDef;

/**
* @brief  RTC TSFILT definition
*/
typedef enum
{
#if defined USE_RTC_RTCSTAMP0
    TSFILT_16CLK   =   RTC_RTCTSxCON_TSxFILT_16CLK,
    TSFILT_496CLK  =   RTC_RTCTSxCON_TSxFILT_496CLK,
    TSFILT_16368CLK =  RTC_RTCTSxCON_TSxFILT_16368CLK,
    TSFILT_32752CLK =  RTC_RTCTSxCON_TSxFILT_32752CLK,
#else   
    TSFILT_512CLK   =  RTC_RTCTSxCON_TSxFILT_512CLK,
    TSFILT_4096CLK  =  RTC_RTCTSxCON_TSxFILT_4096CLK,
    TSFILT_16384CLK =  RTC_RTCTSxCON_TSxFILT_16384CLK,
    TSFILT_32768CLK =  RTC_RTCTSxCON_TSxFILT_32768CLK,
#endif
}
RTCTSFILT_TypeDef;

/**
* @brief  RTC TSFILT definition
*/
typedef enum
{
    TSPOL_RISING   =  RTC_RTCTSxCON_TSxPOL_RISING,
    TSPOL_FALLING  =  RTC_RTCTSxCON_TSxPOL_FALLING,
    TSPOL_DOUBLE   =  RTC_RTCTSxCON_TSxPOL_DOUBLE,
}
RTCTSPOL_TypeDef;

/**
* @brief  RTC TSCMP definition
*/
typedef struct
{
    FunctionalState NewState;     
    uint8_t  Count;              
}RTCTSCMP_TypeDef;  

/**
* @brief  RTC STAMP definition
*/
typedef struct
{
    RTCTSFILT_TypeDef   TSFILT;
    RTCTSPOL_TypeDef    TSPOL;
    RTCTSCMP_TypeDef    TSCMP;
    FunctionalState     TSEN;   
}RTCSTAMP_InitTypeDef;               /*!< end of group RTCTMR_InitTypeDef   */

/**
* @brief  RTC STAMP Select definition
*/
typedef enum
{
#if defined USE_RTC_RTCSTAMP0 
    STAMP0 = 0x00U,                  /*!< Select RTC STAMP0 */
#endif
#if defined USE_RTC_RTCSTAMP01   
    STAMP0 = 0x00U,    
    STAMP1 = 0x01U,                  /*!< Select RTC STAMP1 */
#endif    
}RTCSTAMP_SelectTypeDef;   
#endif

#if defined  USE_RTC_RTCBACKUP_REG
typedef enum
{
    RTC_BKP_DR0 = 0x00U,
    RTC_BKP_DR1 = 0x01U,
    RTC_BKP_DR2 = 0x02U,
    RTC_BKP_DR3 = 0x03U,    
    RTC_BKP_DR4 = 0x04U,
    RTC_BKP_DR5 = 0x05U,    
    RTC_BKP_DR6 = 0x06U,
    RTC_BKP_DR7 = 0x07U,  
    RTC_BKP_DR8 = 0x08U,
    RTC_BKP_DR9 = 0x09U,  
    RTC_BKP_DR10 = 0x0aU,
    RTC_BKP_DR11 = 0x0bU,  
    RTC_BKP_DR12 = 0x0cU,
    RTC_BKP_DR13 = 0x0dU,
    RTC_BKP_DR14 = 0x0eU,
    RTC_BKP_DR15 = 0x0fU,
    RTC_BKP_DR16 = 0x10U,
    RTC_BKP_DR17 = 0x11U,
    RTC_BKP_DR18 = 0x12U,
    RTC_BKP_DR19 = 0x13U,    
    RTC_BKP_DR20 = 0x14U,
    RTC_BKP_DR21 = 0x15U,    
    RTC_BKP_DR22 = 0x16U,
    RTC_BKP_DR23 = 0x17U,  
    RTC_BKP_DR24 = 0x18U,
    RTC_BKP_DR25 = 0x19U,  
    RTC_BKP_DR26 = 0x1aU,
    RTC_BKP_DR27 = 0x1bU,  
    RTC_BKP_DR28 = 0x1cU,
    RTC_BKP_DR29 = 0x1dU,
    RTC_BKP_DR30 = 0x1eU,
    RTC_BKP_DR31 = 0x1fU,    
}
RTCBACKUP_SelectTypeDef; 
#endif


/**
* @brief  RTC module initialization structure definition
*/
typedef struct  __RTC_InitTypeDef
{
    RTCTMR_InitTypeDef RTC_TMR1;   /*!< RTC Timer1 Setting            */
    RTCTMR_InitTypeDef RTC_TMR2;   /*!< RTC Timer2 Setting            */
    RTCAlarm_TypeDef RTC_Alarm;    /*!< RTC Alarm  Setting            */
    RTCTout_TypeDef RTC_TOUT;      /*!< RTC Tout Output  Setting      */
#if defined USE_RTC_RTCSTAMP0  ||  defined USE_RTC_RTCSTAMP01      
    RTCSTAMP_InitTypeDef RTC_STAMP0;
#endif    
#if defined USE_RTC_RTCSTAMP01    
    RTCSTAMP_InitTypeDef RTC_STAMP1;
#endif 
    
#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
    HT_RTC_TypeDef *Instance;      /*!< RTC registers base address    */
    __IO uint32_t   ErrorCode;     /*!< RTC Error code                    */
    void (* RTCSecCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);    /*!< RTC Second Interrupt Callback */	
	void (* RTCMinCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);    /*!< RTC Minute Interrupt Callback */	
	void (* RTCHourCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);   /*!< RTC Hour Interrupt Callback */	
	void (* RTCDayCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);    /*!< RTC Day Interrupt Callback */	
	void (* RTCMonthCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);  /*!< RTC Month Interrupt Callback */	
	void (* RTCTmr1Callback)(struct __RTC_InitTypeDef *RTC_InitStruct);   /*!< RTC Tmr1 Interrupt Callback */	
	void (* RTCTmr2Callback)(struct __RTC_InitTypeDef *RTC_InitStruct);   /*!< RTC Tmr2 Interrupt Callback */	
	void (* RTCAlmCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);    /*!< RTC Alarm Interrupt Callback */
    #if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
    void (* RTCTS0ovCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);  /*!< RTC Timestamp0 Event Counts the Overflow Interrupt Callback */
    void (* RTCTS0cmpCallback)(struct __RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp0 Event Counts Compare Interrupt Callback */
    void (* RTCTS0triCallback)(struct __RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp0 Trigger Interrupt Callback */
    #endif
    #if defined  USE_RTC_RTCSTAMP01
    void (* RTCTS1ovCallback)(struct __RTC_InitTypeDef *RTC_InitStruct);  /*!< RTC Timestamp1 Event Counts the Overflow Interrupt Callback */
    void (* RTCTS1cmpCallback)(struct __RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp1 Event Counts Compare Interrupt Callback */
    void (* RTCTS1triCallback)(struct __RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp1 Trigger Interrupt Callback */
    #endif	
#endif	
}RTC_InitTypeDef; /*!< end of group RTC_InitTypeDef  */



#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
/**
* @brief RTC Callback pointer definition
*/
typedef  void (*pRTC_CallbackTypeDef)(RTC_InitTypeDef *RTC_InitStruct);  /*!< pointer to an RTC callback function */

/**
* @brief  RTC Error Code
*/
#define RTC_ERROR_NONE              0x00000000U   /*!< No error            */
#define RTC_ERROR_INVALID_CALLBACK  0x00000020U   /*!< Invalid Callback error  */

#endif

/*
*********************************************************************************************************
*                                              Global Variable
*********************************************************************************************************
*/
/**
* @brief HT_RTC_Exported_Constants
*/

/**
* @brief HT_RTC_ALMR
*/

#define IS_HT_RTC_ALMR_ALMM(ALMM)    ((ALMM)<=RTC_ALMR_ALMM)

#define IS_HT_RTC_ALMR_ALMH(ALMH)    ((ALMH)<=(RTC_ALMR_ALMH>>8))

/**
* @brief HT_RTC_TOUT
*/
#if defined USE_RTC_RTCCON_TOUT_16TO128HZ
#define IS_HT_RTC_RTCCON_TOUT(TOUT)   (((TOUT)==RTC_RTCCON_TOUT_LOW) || \
                                       ((TOUT)==RTC_RTCCON_TOUT_HIGH) || \
									   ((TOUT)==RTC_RTCCON_TOUT_LF) || \
									   ((TOUT)==RTC_RTCCON_TOUT_1HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_2HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_4HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_8HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_16HZ)|| \
									   ((TOUT)==RTC_RTCCON_TOUT_32HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_64HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_128HZ)) 
#else
#define IS_HT_RTC_RTCCON_TOUT(TOUT)   (((TOUT)==RTC_RTCCON_TOUT_LOW) || \
                                       ((TOUT)==RTC_RTCCON_TOUT_HIGH) || \
									   ((TOUT)==RTC_RTCCON_TOUT_LF) || \
									   ((TOUT)==RTC_RTCCON_TOUT_1HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_2HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_4HZ) || \
									   ((TOUT)==RTC_RTCCON_TOUT_8HZ) || \
                                       ((TOUT)==RTC_RTCCON_TOUT_RTC1HZ)) 
#endif     

/**
* @brief HT_RTC_TIME
*/
#define IS_HT_RTC_WEEKR(WEEKR)     ((WEEKR)>0U &&(WEEKR)<=7U)       /*!< WEEKR  Limit 1~7 */
#define IS_HT_RTC_YEARR(YEARR)     ((YEARR)<=99U)                  /*!< YEARR  Limit 0~99 */
#define IS_HT_RTC_MONTHR(MONTHR)   ((MONTHR)>0U &&(MONTHR)<=12U)    /*!< MONTHR Limit 1~12 */
#define IS_HT_RTC_DAYR(DAYR)       ((DAYR)>0U &&(DAYR)<=31U)        /*!< DAYR   Limit 1~31 */
#define IS_HT_RTC_HOURR(HOURR)     ((HOURR)<=23U)                  /*!< HOURR  Limit 0~23 */
#define IS_HT_RTC_MINR(MINR)       ((MINR)<=59U)                   /*!< MINR   Limit 0~59 */
#define IS_HT_RTC_SECR(SECR)       ((SECR)<=59U)                   /*!< SECR   Limit 0~59 */

/**
* @brief HT_RTC_TIMER
*/
#define IS_HT_RTC_RTCTMR(RTCTMR)   (((RTCTMR)==RTC_RTCCON_RTC1EN) || \
                                    ((RTCTMR)==RTC_RTCCON_RTC2EN))
                                     
/**
* @brief HT_RTC_IE
*/
#define IS_HT_RTC_RTCIE(RTCIE)    (((RTCIE)== RTC_RTCIE_SECIE) || \
                                   ((RTCIE)== RTC_RTCIE_MINIE) || \
								   ((RTCIE)== RTC_RTCIE_HRIE)  || \
                                   ((RTCIE)== RTC_RTCIE_DAYIE) || \
                                   ((RTCIE)== RTC_RTCIE_MTHIE) || \
                                   ((RTCIE)== RTC_RTCIE_RTC1IE)|| \
                                   ((RTCIE)== RTC_RTCIE_RTC2IE)|| \
								   ((RTCIE)== RTC_RTCIE_ALMIE) || \
                                   ((((RTCIE) & (uint32_t)(~RTC_RTCIE)) == 0x00) && ((RTCIE) != 0x00)))

/**
* @brief HT_RTC_IF
*/
#define IS_HT_RTC_RTCIF(RTCIF)    (((RTCIF)== RTC_RTCIF_SECIF) || \
                                   ((RTCIF)== RTC_RTCIF_MINIF) || \
								   ((RTCIF)== RTC_RTCIF_HRIF)  || \
                                   ((RTCIF)== RTC_RTCIF_DAYIF) || \
                                   ((RTCIF)== RTC_RTCIF_MTHIF) || \
                                   ((RTCIF)== RTC_RTCIF_RTC1IF)|| \
                                   ((RTCIF)== RTC_RTCIF_RTC2IF)|| \
								   ((RTCIF)== RTC_RTCIF_ALMIF) || \
                                   ((((RTCIF) & (uint32_t)(~RTC_RTCIF)) == 0x00) && ((RTCIF) != 0x00)))


#if defined USE_RTC_RTC2RD  ||  defined USE_RTC_RTC2WR
/**
* @brief HT_RTC2_TIME
*/
#define IS_HT_RTC2_WEEKR(WEEKR)     ((WEEKR)>0U &&(WEEKR)<=7U)     /*!< WEEKR  Limit 1~7  */
#define IS_HT_RTC2_YEARR(YEARR)     ((YEARR)<=99U)                 /*!< YEARR  Limit 0~99 */
#define IS_HT_RTC2_MONTHR(MONTHR)   ((MONTHR)>0U &&(MONTHR)<=12U)  /*!< MONTHR Limit 1~12 */
#define IS_HT_RTC2_DAYR(DAYR)       ((DAYR)>0U &&(DAYR)<=31U)      /*!< DAYR   Limit 1~31 */
#define IS_HT_RTC2_HOURR(HOURR)     ((HOURR)<=23U)                 /*!< HOURR  Limit 0~23 */
#define IS_HT_RTC2_MINR(MINR)       ((MINR)<=59U)                  /*!< MINR   Limit 0~59 */
#define IS_HT_RTC2_SECR(SECR)       ((SECR)<=59U)                  /*!< SECR   Limit 0~59 */
#endif  


#if defined USE_RTC_RTCTESTCTRL_C_OSC32K
/**
* @brief HT_RTC_C_OSC32K
*/
#define IS_HT_RTC_C_OSC32K(C_OSC32K) (((C_OSC32K)==RTC_RTCTESTCTRL_C_OSC32K_1000nA) || \
                                      ((C_OSC32K)==RTC_RTCTESTCTRL_C_OSC32K_692nA)  || \
                                      ((C_OSC32K)==RTC_RTCTESTCTRL_C_OSC32K_530nA)  || \
				                      ((C_OSC32K)==RTC_RTCTESTCTRL_C_OSC32K_430nA))	
#endif

#if defined USE_RTC_RTCCLKCFG
/**
* @brief HT_RTC_RTCCLKCFG
*/
#define IS_HT_RTC_RTCCLKSEL(RTCCLKSEL) (((RTCCLKSEL)==CMU_RTCCLKCFG_RTCCLKSEL_OSC) || \
                                        ((RTCCLKSEL)==CMU_RTCCLKCFG_RTCCLKSEL_LRC))
#endif


#if defined USE_RTC_RTCSTAMP0 ||  defined USE_RTC_RTCSTAMP01
/**
* @brief HT_RTC_RTCTSxCON_TSPOL
*/
#define IS_HT_RTC_RTCTSxCON_TSPOL(TSPOL)    (((TSPOL)==TSPOL_RISING) || \
                                             ((TSPOL)==TSPOL_FALLING)|| \
                                             ((TSPOL)==TSPOL_DOUBLE))  

#if defined USE_RTC_RTCSTAMP0
#define IS_HT_RTC_RTCTSxCON_TSFILT(TSFILT)  (((TSFILT)==RTC_RTCTSxCON_TSxFILT_16CLK)  || \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_496CLK) || \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_16368CLK)|| \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_32752CLK))
#else
#define IS_HT_RTC_RTCTSxCON_TSFILT(TSFILT)  (((TSFILT)==RTC_RTCTSxCON_TSxFILT_512CLK)  || \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_4096CLK) || \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_16384CLK)|| \
                                             ((TSFILT)==RTC_RTCTSxCON_TSxFILT_32768CLK))
#endif
                                             
#define IS_HT_RTC_RTCTSxIE(RTCTSxIE)        (((RTCTSxIE)==RTC_RTCTSxIE_TSxOVIE)  || \
                                             ((RTCTSxIE)==RTC_RTCTSxIE_TSxCMPIE) || \
                                             ((RTCTSxIE)==RTC_RTCTSxIE_TSxIE) || \
                                             ((((RTCTSxIE) & (uint32_t)(~RTC_RTCTSxIE)) == 0x00) && ((RTCTSxIE) != 0x00)))
                                            
#define IS_HT_RTC_RTCTSxIF(RTCTSxIF)        (((RTCTSxIF)==RTC_RTCTSxIF_TSxOVIF)  || \
                                             ((RTCTSxIF)==RTC_RTCTSxIF_TSxCMPIF) || \
                                             ((RTCTSxIF)==RTC_RTCTSxIF_TSxIF) || \
                                             ((((RTCTSxIF) & (uint32_t)(~RTC_RTCTSxIF)) == 0x00) && ((RTCTSxIF) != 0x00)))
                                             
#define IS_HT_RTC_RTCTSNUM(RTCTSNUM)        (((RTCTSNUM)== TSNUM0) || \
                                             ((RTCTSNUM)== TSNUM1) || \
								             ((RTCTSNUM)== TSNUM2) || \
                                             ((RTCTSNUM)== TSNUM3) || \
                                             ((RTCTSNUM)== TSNUM4) || \
								             ((RTCTSNUM)== TSNUM5))

#endif 

#if defined  USE_RTC_RTCSTAMP0
#define IS_HT_RTC_RTCSTAMP(RTCSTAMP)        ((RTCSTAMP) == STAMP0)                                              
#endif

#if defined  USE_RTC_RTCSTAMP01
#define IS_HT_RTC_RTCSTAMP(RTCSTAMP)        (((RTCSTAMP) == STAMP0) || \
                                             ((RTCSTAMP) == STAMP1))
#endif    

#if defined  USE_RTC_RTCBACKUP_REG
#define IS_HT_RTC_BACKUP(BACKUP)            (((BACKUP) == RTC_BKP_DR0) ||\
                                             ((BACKUP) == RTC_BKP_DR1) ||\
                                             ((BACKUP) == RTC_BKP_DR2) ||\
                                             ((BACKUP) == RTC_BKP_DR3) ||\
                                             ((BACKUP) == RTC_BKP_DR4) ||\
                                             ((BACKUP) == RTC_BKP_DR5) ||\
                                             ((BACKUP) == RTC_BKP_DR6) ||\
                                             ((BACKUP) == RTC_BKP_DR7) ||\
                                             ((BACKUP) == RTC_BKP_DR8) ||\
                                             ((BACKUP) == RTC_BKP_DR9) ||\
                                             ((BACKUP) == RTC_BKP_DR10) ||\
                                             ((BACKUP) == RTC_BKP_DR11) ||\
                                             ((BACKUP) == RTC_BKP_DR12) ||\
                                             ((BACKUP) == RTC_BKP_DR13) ||\
                                             ((BACKUP) == RTC_BKP_DR14) ||\
                                             ((BACKUP) == RTC_BKP_DR15) ||\
                                             ((BACKUP) == RTC_BKP_DR16) ||\
                                             ((BACKUP) == RTC_BKP_DR17) ||\
                                             ((BACKUP) == RTC_BKP_DR18) ||\
                                             ((BACKUP) == RTC_BKP_DR19) ||\
                                             ((BACKUP) == RTC_BKP_DR20) ||\
                                             ((BACKUP) == RTC_BKP_DR21) ||\
                                             ((BACKUP) == RTC_BKP_DR22) ||\
                                             ((BACKUP) == RTC_BKP_DR23) ||\
                                             ((BACKUP) == RTC_BKP_DR24) ||\
                                             ((BACKUP) == RTC_BKP_DR25) ||\
                                             ((BACKUP) == RTC_BKP_DR26) ||\
                                             ((BACKUP) == RTC_BKP_DR27) ||\
                                             ((BACKUP) == RTC_BKP_DR28) ||\
                                             ((BACKUP) == RTC_BKP_DR29) ||\
                                             ((BACKUP) == RTC_BKP_DR30) ||\
                                             ((BACKUP) == RTC_BKP_DR31))
#endif 


/*
*********************************************************************************************************
*                                      Global Function Declaration
*********************************************************************************************************
*/
void HT_RTC_Init(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_Read(void *pRTCTime);
void HT_RTC_Write(void *pRTCTime);
void HT_RTC_TMRConfig(RTCTMR_SelectTypeDef RTCTMRx, RTCTMR_InitTypeDef *RTCTMR_InitStruct);
void HT_RTC_ToutSet(RTCTout_TypeDef RTCToutSet);
void HT_RTC_AlarmSet(RTCAlarm_TypeDef RTCAlarmSet);
void HT_RTC_ITConfig(uint16_t ITEn, FunctionalState NewState);
ITStatus HT_RTC_ITFlagStatusGet(uint16_t ITFlag);
void HT_RTC_ClearITPendingBit(uint16_t ITFlag);
Bool HT_RTC_LoadInfoData(void);

#if defined  USE_RTC_RTC2CAL
void HT_RTC_LRC_Amend(uint32_t TimeCalVal);
#endif
#if defined  USE_RTC_RTC2RD 
void HT_RTC_LRC_Read(void *pRTCTime);
#endif
#if defined  USE_RTC_RTC2WR 
void HT_RTC_LRC_Write(void *pRTCTime);
#endif
#if defined  USE_RTC_RTCTESTCTRL_C_OSC32K
void HT_RTC_OSC_Current_ADJ(uint32_t c_osc32k);
#endif
#if defined USE_RTC_RTCCLKCFG
void HT_RTC_RTCCLK_CFG(uint32_t rtcclksel);
#endif

#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
void HT_RTCSTAMP_ITConfig(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITEn, FunctionalState NewState);
ITStatus HT_RTCSTAMP_ITFlagStatusGet(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITFlag);
void HT_RTCSTAMP_ClearITPendingBit(RTCSTAMP_SelectTypeDef STAMPx,uint32_t ITFlag);
uint32_t HT_RTCSTAMP_GetEventCount(RTCSTAMP_SelectTypeDef STAMPx);
void HT_RTCSTAMP_GetTriggerSource(RTCSTAMP_SelectTypeDef STAMPx,HT_RTC_STAMPSOURCE_TypeDef *TriSource,RTCTSNUM_TypeDef num);
#endif
#if defined  USE_RTC_RTCBACKUP_REG
void HT_RTC_RTCBACKUP_Write(uint32_t BackupRegister,uint32_t Data);
uint32_t HT_RTC_RTCBACKUP_Read(uint32_t BackupRegister);
#endif

#if (USE_HT_RTC_REGISTER_CALLBACKS == 1U)
void HT_RTC_RTCSecCallback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCMinCallback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCHourCallback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCDayCallback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCMonthCallback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCTmr1Callback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCTmr2Callback(RTC_InitTypeDef *RTC_InitStruct);
void HT_RTC_RTCAlmCallback(RTC_InitTypeDef *RTC_InitStruct);
#if defined USE_RTC_RTCSTAMP0 || defined USE_RTC_RTCSTAMP01
void HT_RTC_RTCTS0ovCallback(RTC_InitTypeDef *RTC_InitStruct);  /*!< RTC Timestamp0 Event Counts the Overflow Interrupt Callback */
void HT_RTC_RTCTS0cmpCallback(RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp0 Event Counts Compare Interrupt Callback */
void HT_RTC_RTCTS0triCallback(RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp0 Trigger Interrupt Callback */
#endif
#if defined USE_RTC_RTCSTAMP01
void HT_RTC_RTCTS1ovCallback(RTC_InitTypeDef *RTC_InitStruct);  /*!< RTC Timestamp1 Event Counts the Overflow Interrupt Callback */
void HT_RTC_RTCTS1cmpCallback(RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp1 Event Counts Compare Interrupt Callback */
void HT_RTC_RTCTS1triCallback(RTC_InitTypeDef *RTC_InitStruct); /*!< RTC Timestamp1 Trigger Interrupt Callback */
#endif
StatusTypeDef HT_RTC_RegisterCallback(RTC_InitTypeDef *RTC_InitStruct, RTC_CallbackIDTypeDef CallbackID, pRTC_CallbackTypeDef pCallback);
#endif /* USE_HT_RTC_REGISTER_CALLBACKS */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_RTC_H__ */
