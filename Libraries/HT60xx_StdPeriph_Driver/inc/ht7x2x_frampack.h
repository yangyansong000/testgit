/*
*********************************************************************************************************
*                                              HT7X2X
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT7x2x
* File         : ht7x2x_frampack.h
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
**********************************************************************************************************
*/

#ifndef __HT7X2X_FRAMPACK_H__
#define __HT7X2X_FRAMPACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/**
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
/**
* @brief  HT_FRAMPACK config define
*/
#define FRAMPACK_ENABLE             ((uint32_t)FRAMPACK_FRAMCON_PACKEN)

#define FRAMPACK_ABORT              ((uint32_t)FRAMPACK_FRAMCON_ABORT)
			
#define FRAMPACK_SPISEL_SPI0        ((uint32_t)FRAMPACK_FRAMCON_SPISEL_SPI0)
#define FRAMPACK_SPISEL_SPI2        ((uint32_t)FRAMPACK_FRAMCON_SPISEL_SPI2)	
		
#define FRAMPACK_ENDIAN_SMALL       ((uint32_t)0x0000)
#define FRAMPACK_ENDIAN_BIG         ((uint32_t)FRAMPACK_FRAMCON_ENDSEL)	
		
#define FRAMPACK_CHNNUM_1           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_1)		
#define FRAMPACK_CHNNUM_2           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_2)	
#define FRAMPACK_CHNNUM_3           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_3)
#define FRAMPACK_CHNNUM_4           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_4)	
#define FRAMPACK_CHNNUM_5           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_5)	
#define FRAMPACK_CHNNUM_6           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_6)	
#define FRAMPACK_CHNNUM_7           ((uint32_t)FRAMPACK_FRAMCON_COMSEL_7)	
			
#define FRAMPACK_BITWIDE_24BITS     ((uint32_t)FRAMPACK_FRAMCON_SDACFG_24BITS)
#define FRAMPACK_BITWIDE_16BITS     ((uint32_t)FRAMPACK_FRAMCON_SDACFG_16BITS)
		
#define FRAMPACK_FRAMID_1BYTE       ((uint32_t)FRAMPACK_IDCFG_ID_SEL_1BYTE)
#define FRAMPACK_FRAMID_2BYTE       ((uint32_t)FRAMPACK_IDCFG_ID_SEL_2BYTE)

#define FRAMPACK_DATAOUTDLY_NONE    ((uint32_t)FRAMPACK_FRAMCON_DATAOUTDLY_NONE)
#define FRAMPACK_DATAOUTDLY_1CLK    ((uint32_t)FRAMPACK_FRAMCON_DATAOUTDLY_1CLK)
#define FRAMPACK_DATAOUTDLY_2CLK    ((uint32_t)FRAMPACK_FRAMCON_DATAOUTDLY_2CLK)
#define FRAMPACK_DATAOUTDLY_3CLK    ((uint32_t)FRAMPACK_FRAMCON_DATAOUTDLY_3CLK)
/**
* @brief  HT_FRAMPACK CRC config define
*/
#define FRAMPACK_CRC_SEL_CHECKSUM   ((uint32_t)0x0000)
#define FRAMPACK_CRC_SEL_CRC        ((uint32_t)FRAMPACK_FCRCCFG_CRC_SEL)

#define FRAMPACK_CRC16_1021         ((uint32_t)FRAMPACK_FCRCCFG_CRC16_1021)
#define FRAMPACK_CRC16_8005         ((uint32_t)FRAMPACK_FCRCCFG_CRC16_8005)
#define FRAMPACK_CRC32              ((uint32_t)FRAMPACK_FCRCCFG_CRC32)

#define FRAMPACK_CRC_LEN_1BYTE      ((uint32_t)FRAMPACK_FCRCCFG_CLEN_SEL_1BYTE)
#define FRAMPACK_CRC_LEN_2BYTE      ((uint32_t)FRAMPACK_FCRCCFG_CLEN_SEL_2BYTE)
#define FRAMPACK_CRC_LEN_4BYTE      ((uint32_t)FRAMPACK_FCRCCFG_CLEN_SEL_4BYTE)
	
#define FRAMPACK_CRC_REFIN_NORMAL   ((uint32_t)0x0000)
#define FRAMPACK_CRC_REFIN_REVERSE  ((uint32_t)FRAMPACK_FCRCCFG_REFIN_REVERSE)

#define FRAMPACK_CRC_REFOUT_NORMAL  ((uint32_t)0x0000)
#define FRAMPACK_CRC_REFOUT_REVERSE ((uint32_t)FRAMPACK_FCRCCFG_REFOUT_REVERSE)

#define FRAMPACK_CRC_XOROUT_NORMAL  ((uint32_t)0x0000)
#define FRAMPACK_CRC_XOROUT_REVERSE ((uint32_t)FRAMPACK_FCRCCFG_XOROUT_REVERSE)

#define FRAMPACK_CRC_ENDIAN_SMALL   ((uint32_t)0x0000)
#define FRAMPACK_CRC_ENDIAN_BIG     ((uint32_t)FRAMPACK_FCRCCFG_CHECK_ENDSEL)

/**
* @brief  HT_FRAMPACK SPI select enumeration definition
*/
typedef enum
{
  PACK_Sel_SPI0 = FRAMPACK_SPISEL_SPI0, 
  PACK_Sel_SPI2 = FRAMPACK_SPISEL_SPI2,
}PACK_SPISel_TypeDef; 

/**
* @brief  HT_FRAMPACK data endian enumeration definition
*/
typedef enum
{
  PACK_DataEndian_Small = FRAMPACK_ENDIAN_SMALL, 
  PACK_DataEndian_Big   = FRAMPACK_ENDIAN_BIG,
}PACK_DataEndian_TypeDef; 

/**
* @brief  HT_FRAMPACK channel number enumeration definition
*/
typedef enum
{
  PACK_ChnNum1 = FRAMPACK_CHNNUM_1, 
  PACK_ChnNum2 = FRAMPACK_CHNNUM_2,
  PACK_ChnNum3 = FRAMPACK_CHNNUM_3,
  PACK_ChnNum4 = FRAMPACK_CHNNUM_4,
  PACK_ChnNum5 = FRAMPACK_CHNNUM_5,
  PACK_ChnNum6 = FRAMPACK_CHNNUM_6,
  PACK_ChnNum7 = FRAMPACK_CHNNUM_7,
}PACK_ChnNum_TypeDef; 

/**
* @brief  HT_FRAMPACK bitwide enumeration definition
*/
typedef enum
{
  PACK_BitWide_16bits = FRAMPACK_BITWIDE_16BITS, 
  PACK_BitWide_24bits = FRAMPACK_BITWIDE_24BITS, 
}PACK_BitWide_TypeDef;

/**
* @brief  HT_FRAMPACK data out delay enumeration definition
*/
typedef enum
{
  PACK_OutDelay_None = FRAMPACK_DATAOUTDLY_NONE, 
  PACK_OutDelay_1clk = FRAMPACK_DATAOUTDLY_1CLK, 
  PACK_OutDelay_2clk = FRAMPACK_DATAOUTDLY_2CLK, 
  PACK_OutDelay_3clk = FRAMPACK_DATAOUTDLY_3CLK, 
}PACK_OutDelay_TypeDef;

/**
* @brief  HT_FRAMPACK ID length enumeration definition
*/
typedef enum
{
  PACK_ID_Length_1Byte = FRAMPACK_FRAMID_1BYTE, 
  PACK_ID_Length_2Byte = FRAMPACK_FRAMID_2BYTE, 
}PACK_ID_Length_TypeDef;

/**
* @brief  HT_FRAMPACK ID location enumeration definition
*/
typedef enum
{
  PACK_ID_Location_0  =  FRAMPACK_IDCFG_ID_ADDR_0,
  PACK_ID_Location_1  =  FRAMPACK_IDCFG_ID_ADDR_1,
  PACK_ID_Location_2  =  FRAMPACK_IDCFG_ID_ADDR_2,
  PACK_ID_Location_3  =  FRAMPACK_IDCFG_ID_ADDR_3,
  PACK_ID_Location_4  =  FRAMPACK_IDCFG_ID_ADDR_4,
  PACK_ID_Location_5  =  FRAMPACK_IDCFG_ID_ADDR_5,
  PACK_ID_Location_6  =  FRAMPACK_IDCFG_ID_ADDR_6,
  PACK_ID_Location_7  =  FRAMPACK_IDCFG_ID_ADDR_7,
  PACK_ID_Location_8  =  FRAMPACK_IDCFG_ID_ADDR_8,
  PACK_ID_Location_9  =  FRAMPACK_IDCFG_ID_ADDR_9,
  PACK_ID_Location_10 =  FRAMPACK_IDCFG_ID_ADDR_10,
  PACK_ID_Location_11 =  FRAMPACK_IDCFG_ID_ADDR_11,
  PACK_ID_Location_12 =  FRAMPACK_IDCFG_ID_ADDR_12,
  PACK_ID_Location_13 =  FRAMPACK_IDCFG_ID_ADDR_13,
  PACK_ID_Location_14 =  FRAMPACK_IDCFG_ID_ADDR_14,
  PACK_ID_Location_15 =  FRAMPACK_IDCFG_ID_ADDR_15,
}PACK_ID_Location_TypeDef;

/**
* @brief  HT_FRAMPACK CRC or checksum select enumeration definition
*/
typedef enum
{
  PACK_CRCSel_Checksum = FRAMPACK_CRC_SEL_CHECKSUM,
  PACK_CRCSel_Crc      = FRAMPACK_CRC_SEL_CRC,
}PACK_CRCSel_TypeDef;

/**
* @brief  HT_FRAMPACK CRC mode enumeration definition
*/
typedef enum
{
  PACK_CRCMode_Crc16_1021 = FRAMPACK_CRC16_1021,	
  PACK_CRCMode_Crc16_8005 = FRAMPACK_CRC16_8005,	
  PACK_CRCMode_Crc32      = FRAMPACK_CRC32,			
}PACK_CRCMode_TypeDef;

/**
* @brief  HT_FRAMPACK CRC or checksum length enumeration definition
*/
typedef enum
{
  PACK_CLEN_1byte = FRAMPACK_CRC_LEN_1BYTE,
  PACK_CLEN_2byte = FRAMPACK_CRC_LEN_2BYTE,
  PACK_CLEN_4byte = FRAMPACK_CRC_LEN_4BYTE,
}PACK_CLEN_TypeDef;

/**
* @brief  HT_FRAMPACK input reverse enumeration definition
*/
typedef enum
{
  PACK_CRC_RefIn_Normal  = FRAMPACK_CRC_REFIN_NORMAL,
  PACK_CRC_RefIn_Reverse = FRAMPACK_CRC_REFIN_REVERSE,
}PACK_CRC_RefIn_TypeDef;

/**
* @brief  HT_FRAMPACK output reverse enumeration definition
*/
typedef enum
{
  PACK_CRC_RefOut_Normal  = FRAMPACK_CRC_REFOUT_NORMAL,
  PACK_CRC_RefOut_Reverse = FRAMPACK_CRC_REFOUT_REVERSE,
}PACK_CRC_RefOut_TypeDef;

/**
* @brief  HT_FRAMPACK output Xor enumeration definition
*/
typedef enum
{
  PACK_CRC_XorOut_Normal  = FRAMPACK_CRC_XOROUT_NORMAL,
  PACK_CRC_XorOut_Reverse = FRAMPACK_CRC_XOROUT_REVERSE,
}PACK_CRC_XorOut_TypeDef;

/**
* @brief  HT_FRAMPACK CRC endian enumeration definition
*/
typedef enum
{
  PACK_CRC_Endian_Small  = FRAMPACK_CRC_ENDIAN_SMALL,
  PACK_CRC_Endian_Big    = FRAMPACK_CRC_ENDIAN_BIG,
}PACK_CRC_Endian_TypeDef;

/**
* @brief  FRAMPACK module initalizes the structure definition
*/
typedef struct  __FRAMPACK_InitTypeDef
{
    PACK_SPISel_TypeDef       SPI_Select;     /*!< FRAMPACK SPI Select               */
    PACK_DataEndian_TypeDef   Data_Endian;    /*!< FRAMPACK data endian big/small    */
    PACK_ChnNum_TypeDef       Chn_Number;     /*!< FRAMPACK data out put channel number 1~7 */
    PACK_BitWide_TypeDef      Data_BitWide;   /*!< FRAMPACK data 16/24 bit           */
    PACK_OutDelay_TypeDef     Data_Outdelay;  /*!< FRAMPACK data output delay 0/1/2/3 clk    	*/
    uint32_t  HeadA_Length;                   /*!< FRAMPACK HEADA length 1~16        */
    uint32_t  HeadB_Length;                   /*!< FRAMPACK HEADB length 1~16        */
    uint32_t  EmuData_SampleNum;              /*!< FRAMPACK EMU data sample num 0~0xFFFF      */
    PACK_ID_Length_TypeDef    FramID_Lenth;   /*!< FRAMPACK FRAMID length 1/2 BYTE            */
    PACK_ID_Location_TypeDef  FramID_Location;/*!< FRAMPACK FRAMID Location PACK_ID_Location_0~15   */
    uint32_t  Fram_ID;                        /*!< FRAMPACK FRAM ID num 0~0xFFFF     */
    uint32_t  Fram_Delay;                     /*!< FRAMPACK fram delay 0~0xFFFF      */
    uint32_t  Fram_AutoNum;                   /*!< FRAMPACK fram auto send number 0~0xFFFF    */

    uint32_t   FramHeadA[4];                  /*!< FRAMPACK fram head A config       */
    uint32_t   FramHeadB[4];                  /*!< FRAMPACK fram head B config       */
    uint8_t    FramStopF;                     /*!< FRAMPACK fram stop byte config    */
    
    PACK_CRCSel_TypeDef      CRC_Select;      /*!< FRAMPACK CRC Select CRC/CHECKSUM     */
    PACK_CRCMode_TypeDef     CRC_Mode;        /*!< FRAMPACK CRC Mode CRC16(1021)/CRC16(8005)/CRC32  */
    PACK_CLEN_TypeDef        Check_Length;    /*!< FRAMPACK CRC Select CRC/CHECKSUM check length    */
    PACK_CRC_RefIn_TypeDef   CRC_RefIn;       /*!< FRAMPACK CRC data input Reverse ENABLE/DISABLE   */
    PACK_CRC_RefOut_TypeDef  CRC_RefOut;      /*!< FRAMPACK CRC data output Reverse ENABLE/DISABLE  */
    PACK_CRC_XorOut_TypeDef  CRC_XorOut;      /*!< FRAMPACK CRC data output Xor ENABLE/DISABLE      */
    PACK_CRC_Endian_TypeDef  CRC_Endian;      /*!< FRAMPACK CRC data endian big/small   */
    uint32_t  CRC_InitSeed;                   /*!< FRAMPACK CRC Initial seed            */
    
    
#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
  HT_FRAMPACK_TypeDef *Instance;            /*!< FRAMPACK registers base address  */
  __IO uint32_t    ErrorCode;               /*!< FRAMPACK Error code                    */
  void (* FrampackEndCpltCallback)(struct __FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);         /*!< FRAMPACK End Complete Callback         */
  void (* FrampackHeadCpltCallback)(struct __FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);        /*!< FRAMPACK Head Complete Callback        */
  void (* FrampackFifoFullCpltCallback)(struct __FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);    /*!< FRAMPACK fifofull Complete Callback    */
  void (* FrampackFifoEmptyCpltCallback)(struct __FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);   /*!< FRAMPACK fifoempty Complete Callback   */
  void (* FrampackAutoDoneCpltCallback)(struct __FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);    /*!< FRAMPACK Auto Done Complete Callback   */
#endif
}FRAMPACK_InitTypeDef;                                /*!< end of group FRAMPACK_InitTypeDef*/

#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)

#define FRAMPACK_ERROR_INVALID_CALLBACK  0x00010000U   /*!< Invalid Callback error  */

/**
* @brief  FRAMPACK Callback ID enumeration definition
*/
typedef enum
{
  FRAMPACK_END_COMPLETE_CB_ID         = (uint32_t)0x01,       /*!< FRAMPACK END Complete Callback ID        */
  FRAMPACK_HEAD_COMPLETE_CB_ID        = (uint32_t)0x02,       /*!< FRAMPACK HEAD Complete Callback ID       */
  FRAMPACK_FIFOFULL_COMPLETE_CB_ID    = (uint32_t)0x03,       /*!< FRAMPACK FIFOFULL Complete Callback ID   */
  FRAMPACK_FIFOEMPTY_COMPLETE_CB_ID   = (uint32_t)0x04,       /*!< FRAMPACK FIFOEMPTY Complete Callback ID  */
  FRAMPACK_AUTODONE_COMPLETE_CB_ID    = (uint32_t)0x05,       /*!< FRAMPACK AUTODONE Complete Callback ID   */
} FRAMPACK_CallbackIDTypeDef;
/**
* @brief  FRAMPACK Callback pointer definition
*/
typedef  void (*pFRAMPACK_CallbackTypeDef)(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);  /*!< pointer to an FRAMPACK callback function */

#endif

#define IS_HT_FRAMPACK_SPI_SELECT(select)      (((select) == FRAMPACK_SPISEL_SPI0) || ((select) == FRAMPACK_SPISEL_SPI2))
#define IS_HT_FRAMPACK_DATA_ENDIAN(endian)     (((endian) == FRAMPACK_ENDIAN_SMALL) || ((endian) == FRAMPACK_ENDIAN_BIG))
#define IS_HT_FRAMPACK_CHN_NUMBER(chnnum)      (((chnnum) == FRAMPACK_CHNNUM_1) || ((chnnum) == FRAMPACK_CHNNUM_2) || \
                                                ((chnnum) == FRAMPACK_CHNNUM_3) || ((chnnum) == FRAMPACK_CHNNUM_4) || \
                                                ((chnnum) == FRAMPACK_CHNNUM_5) || ((chnnum) == FRAMPACK_CHNNUM_6) || \
                                                ((chnnum) == FRAMPACK_CHNNUM_7))
#define IS_HT_FRAMPACK_DATA_BITWIDE(bit)       (((bit) == FRAMPACK_BITWIDE_24BITS) || ((bit) == FRAMPACK_BITWIDE_16BITS))
#define IS_HT_FRAMPACK_DATA_OUTDELAY(cnt)      (((cnt) == FRAMPACK_DATAOUTDLY_NONE) || ((cnt) == FRAMPACK_DATAOUTDLY_1CLK) || \
                                                ((cnt) == FRAMPACK_DATAOUTDLY_2CLK) || ((cnt) == FRAMPACK_DATAOUTDLY_3CLK))
#define IS_HT_FRAMPACK_HEADA_LENGTH(len)       (((len)<=16U) && ((len)>=1U))
#define IS_HT_FRAMPACK_HEADB_LENGTH(len)       (((len)<=16U) && ((len)>=1U))
#define IS_HT_FRAMPACK_EMUDATA_SAMPLENUM(num)  ((num)<=0xFFFFU)

#define IS_HT_FRAMPACK_FRAMID_LENGTH(select)   (((select) == FRAMPACK_FRAMID_1BYTE)   || ((select) == FRAMPACK_FRAMID_2BYTE))
#define IS_HT_FRAMPACK_FRAMID_LOCATION(addr)   (((addr) == FRAMPACK_IDCFG_ID_ADDR_0)  || ((addr) == FRAMPACK_IDCFG_ID_ADDR_1) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_2)  || ((addr) == FRAMPACK_IDCFG_ID_ADDR_3) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_4)  || ((addr) == FRAMPACK_IDCFG_ID_ADDR_5) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_6)  || ((addr) == FRAMPACK_IDCFG_ID_ADDR_7) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_8)  || ((addr) == FRAMPACK_IDCFG_ID_ADDR_9) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_10) || ((addr) == FRAMPACK_IDCFG_ID_ADDR_11) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_12) || ((addr) == FRAMPACK_IDCFG_ID_ADDR_13) ||\
                                                ((addr) == FRAMPACK_IDCFG_ID_ADDR_14) || ((addr) == FRAMPACK_IDCFG_ID_ADDR_15) )

#define IS_HT_FRAMPACK_FRAM_ID(num)            ((num)<=0xFFFFU)
#define IS_HT_FRAMPACK_FRAM_DELAY(clk)         ((clk)<=0xFFFFU)
#define IS_HT_FRAMPACK_FRAM_AUTONUM(num)       ((num)<=0xFFFFU)

/**
*
*/
#define IS_HT_FRAMPACK_CRC_SELECT(select)      (((select) == FRAMPACK_CRC_SEL_CHECKSUM) || ((select) == FRAMPACK_CRC_SEL_CRC))
#define IS_HT_FRAMPACK_CRC_MODE(mode)          (((mode) == FRAMPACK_CRC16_1021) || ((mode) == FRAMPACK_CRC16_8005) || ((mode) == FRAMPACK_CRC32))
#define IS_HT_FRAMPACK_CRC_LENGTH(len)         (((len) == FRAMPACK_CRC_LEN_1BYTE) || ((len) == FRAMPACK_CRC_LEN_2BYTE) || ((len) == FRAMPACK_CRC_LEN_4BYTE))
#define IS_HT_FRAMPACK_CRC_REFIN(refin)        (((refin) == FRAMPACK_CRC_REFIN_NORMAL) || ((refin) == FRAMPACK_CRC_REFIN_REVERSE))
#define IS_HT_FRAMPACK_CRC_REFOUT(refout)      (((refout) == FRAMPACK_CRC_REFOUT_NORMAL) || ((refout) == FRAMPACK_CRC_REFOUT_REVERSE))
#define IS_HT_FRAMPACK_CRC_XOROUT(xorout)      (((xorout) == FRAMPACK_CRC_XOROUT_NORMAL) || ((xorout) == FRAMPACK_CRC_XOROUT_REVERSE))
#define IS_HT_FRAMPACK_CRC_ENDIAN(endian)      (((endian) == FRAMPACK_CRC_ENDIAN_SMALL) || ((endian) == FRAMPACK_CRC_ENDIAN_BIG))

/**
*
*/
#define IS_HT_FRAMPACK_IE(ie)          (((ie) == FRAMPACK_FRAMIE_ENDIE) || ((ie) == FRAMPACK_FRAMIE_HEADIE) ||\
                                        ((ie) == FRAMPACK_FRAMIE_FIFOFULLIE) || ((ie) == FRAMPACK_FRAMIE_FIFOEMPTYIE) ||\
                                        ((ie) == FRAMPACK_FRAMIE_FRAM_DONEIE) || \
                                        ((((ie) & (uint32_t)(~FRAMPACK_FRAMIE)) == 0x00) && ((ie) != 0x00)))
#define IS_HT_FRAMPACK_IF(itflag)      (((itflag) == FRAMPACK_FRAMIF_ENDIF) || ((itflag) == FRAMPACK_FRAMIF_HEADIF) ||\
                                        ((itflag) == FRAMPACK_FRAMIF_FIFOFULLIF) || ((itflag) == FRAMPACK_FRAMIF_FIFOEMPTYIF) ||\
                                        ((itflag) == FRAMPACK_FRAMIF_FRAM_DONEIF) || \
                                        ((((itflag) & (uint32_t)(~FRAMPACK_FRAMIF)) == 0x00) && ((itflag) != 0x00)))
/**
* 
*/
#define HT_FRAMPACK_ENABLE()       (HT_FRAMPACK->FRAMCON |= FRAMPACK_ENABLE)
#define HT_FRAMPACK_DISABLE()      (HT_FRAMPACK->FRAMCON &= ~FRAMPACK_ENABLE)

#define HT_FRAMPACK_ABORT()        (HT_FRAMPACK->FRAMCON |= FRAMPACK_ABORT)
#define HT_FRAMPACK_CLR_ABORT()    (HT_FRAMPACK->FRAMCON &= ~FRAMPACK_ABORT)

/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
StatusTypeDef HT_FRAMPACK_Init(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);

void HT_FRAMPACK_ITConfig(uint32_t ITEn,FunctionalState NewState);
ITStatus HT_FRAMPACK_ITFlagStatusGet(uint32_t ITFlag);
void HT_FRAMPACK_ClearITPendingBit(uint32_t ITFlag);


#if (USE_HT_FRAMPACK_REGISTER_CALLBACKS == 1U)
void HT_FRAMPACK_EndCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
void HT_FRAMPACK_HeadCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
void HT_FRAMPACK_FifoFullCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
void HT_FRAMPACK_FifoEmptyCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
void HT_FRAMPACK_AutoDoneCpltCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct);
StatusTypeDef HT_FRAMPACK_RegisterCallback(FRAMPACK_InitTypeDef *FRAMPACK_InitStruct, FRAMPACK_CallbackIDTypeDef CallbackID, pFRAMPACK_CallbackTypeDef pCallback);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __HT5X3X_FRAMPACK_H__ */
