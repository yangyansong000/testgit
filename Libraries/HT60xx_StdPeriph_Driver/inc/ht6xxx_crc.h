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
* File         : ht6xxx_crc.h
* By           : Hitrendtech_SD
* Version      : V2.0.6
* Description  : Only support for chips used crc Function.
*********************************************************************************************************
*/

#ifndef __HT6XXX_CRC_H__
#define __HT6XXX_CRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

#if defined USE_CRC

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
	
/**
* @brief  CRC operation mode enumeration definition
*/
typedef enum {
    CRC_MODE_CRC16_CCITT_FALSE = 1U,             /*!< CRC16 CCITT-FALSE mode         */
    CRC_MODE_CRC16_CCITT       = 2U,             /*!< CRC16 CCITT mode                */
    CRC_MODE_CRC16_X25         = 3U,             /*!< CRC16 X25 mode                  */
    CRC_MODE_CRC16_XMODEM      = 4U,             /*!< CRC16 XMODEM mode               */
    CRC_MODE_CRC16_IBM         = 5U,             /*!< CRC16 IBM mode                  */
    CRC_MODE_CRC16_MAXIM       = 6U,             /*!< CRC16 MAXIM mode                */
    CRC_MODE_CRC16_USB         = 7U,             /*!< CRC16 USB mode                  */
    CRC_MODE_CRC16_MODBUS      = 8U,             /*!< CRC16 MODBUS mode               */
    CRC_MODE_CRC32             = 9U,             /*!< CRC32 mode                      */
    CRC_MODE_CRC32_MPEG2       = 10U             /*!< CRC16 MPEG-2 mode               */
} CRC_ModeTypeDef;


/**
* @brief  CRC operation unit length enumeration definition
*/
typedef enum {
    CRC_CALC_8_BIT  = 1U,                        /*!< CRC operation unit length = 8bit    */
    CRC_CALC_16_BIT = 2U,                        /*!< CRC operation unit length = 16bit   */
    CRC_CALC_32_BIT = 4U                         /*!< CRC operation unit length = 32bit   */
} CRC_Calc_BitTypeDef;


/**
* @brief HT_CRC
*/

#define IS_HT_CRC_ALL_PERIPH(CRC) ((CRC)== HT_CRC)

/**
* @brief HT_CRC_MODE
*/
#define IS_HT_CRC_MODE(MODE)	(((MODE) == CRC_MODE_CRC16_CCITT_FALSE) || \
                                 ((MODE) == CRC_MODE_CRC16_CCITT) || \
                                 ((MODE) == CRC_MODE_CRC16_X25) || \
                                 ((MODE) == CRC_MODE_CRC16_XMODEM) || \
                                 ((MODE) == CRC_MODE_CRC16_IBM) || \
                                 ((MODE) == CRC_MODE_CRC16_MAXIM) || \
                                 ((MODE) == CRC_MODE_CRC16_USB) || \
                                 ((MODE) == CRC_MODE_CRC16_MODBUS) || \
                                 ((MODE) == CRC_MODE_CRC32) || \
                                 ((MODE) == CRC_MODE_CRC32_MPEG2))

#define IS_HT_CRC_DATA_LENGTH(LENGTH) ((LENGTH)!= 0U)

#define IS_HT_CRC_UNIT_LENGTH(UNIT)  (((UNIT) == CRC_CALC_8_BIT) || \
                                      ((UNIT) == CRC_CALC_16_BIT) || \
                                      ((UNIT) == CRC_CALC_32_BIT))

/*
*********************************************************************************************************
*                                            Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/
void HT_CRC_ModeSelect(CRC_ModeTypeDef mode);

#if defined  HT762x ||  defined  HT772x ||  defined  HT503x
void HT_CRC_SmallEndian_Config(FunctionalState NewState);
#endif

uint32_t HT_CRC_DataCalc(uint8_t* buf_8, uint32_t len, CRC_Calc_BitTypeDef buf_byte_len);

#endif                                 /* This File Only support HT6x2x and HT6x3x  */

#ifdef __cplusplus
}
#endif

#endif /* __HT6XXX_CRC_H__ */
