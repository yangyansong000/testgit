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
* File         : ht6xxx_crc.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : 
*********************************************************************************************************
*/

#define  __HT6XXX_CRC_C
#include <stdio.h>
#include "ht6xxx_lib.h"
#include "ht6xxx_crc.h"


#if defined USE_CRC

/*
*********************************************************************************************************
*                                           Local Maroc/Structure
*********************************************************************************************************
*/
#define CRCINIT_SET_16 		0xFFFFU
#define CRCINIT_RESET_16	0x0000U

#define CRCINIT_SET_32 		0xFFFFFFFFU
#define CRCINIT_RESET_32	0x00000000U

#define CRC_BUSY 			0x1U
#define CRC_READY 		    0x0U

#define CRC_RESULT_ERROR 	((uint32_t)(-1))
/*
*********************************************************************************************************
*                                             Local Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Local Function
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*                                     RESET CRC MODULE
*
* @Brief  Select the CRC mode
*
* @Param  Mode: selector parameter,( If invalid mode is selected ，the default mode CRC16 CCITT is selected）
*               @reg  CRC_MODE_CRC16_CCITT_FALSE  CRC16 CCITT FALSE mode
*               @reg  CRC_MODE_CRC16_CCITT        CRC16 CCITT mode
*               @reg  CRC_MODE_CRC16_X25          CRC16 X25 mode
*               @reg  CRC_MODE_CRC16_XMODEM       CRC16 XMODEM mode
*               @reg  CRC_MODE_CRC16_IBM          CRC16 IBM mode
*               @reg  CRC_MODE_CRC16_MAXIM        CRC16 MAXIM mode
*               @reg  CRC_MODE_CRC16_USB          CRC16 USB mode
*               @reg  CRC_MODE_CRC16_MODBUS       CRC16 MODBUS mode
*               @reg  CRC_MODE_CRC32              CRC32 mode
*               @reg  CRC_MODE_CRC32_MPEG2        CRC32 MPEG2 mode
*
* @retval None
*
* Note:
*********************************************************************************************************
*/
void HT_CRC_ModeSelect(CRC_ModeTypeDef mode)
{
    /*  assert_param  */
    assert_param(IS_HT_CRC_MODE(mode));
    switch(mode)
    {
        case CRC_MODE_CRC16_CCITT_FALSE:
            HT_CRC->CRCINIT = CRCINIT_SET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut | CRC_CRCCON_XorOut))) | CRC_CRCCON_MODE_CCITT;
            break;
        case CRC_MODE_CRC16_X25:
            HT_CRC->CRCINIT = CRCINIT_SET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~CRC_CRCCON_MODE)) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_XorOut | CRC_CRCCON_MODE_CCITT;
            break;
        case CRC_MODE_CRC16_XMODEM:
            HT_CRC->CRCINIT = CRCINIT_RESET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut | CRC_CRCCON_XorOut))) | CRC_CRCCON_MODE_CCITT;
            break;
        case CRC_MODE_CRC16_IBM:
            HT_CRC->CRCINIT = CRCINIT_RESET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_XorOut))) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_MODE_CRC16;
            break;
        case CRC_MODE_CRC16_MAXIM:
            HT_CRC->CRCINIT = CRCINIT_RESET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~CRC_CRCCON_MODE)) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_XorOut | CRC_CRCCON_MODE_CRC16;
            break;
        case CRC_MODE_CRC16_USB:
            HT_CRC->CRCINIT = CRCINIT_SET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~CRC_CRCCON_MODE)) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_XorOut | CRC_CRCCON_MODE_CRC16;
            break;
        case CRC_MODE_CRC16_MODBUS:
            HT_CRC->CRCINIT = CRCINIT_SET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_XorOut))) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_MODE_CRC16;
            break;
        case CRC_MODE_CRC32:
            HT_CRC->CRCINIT = CRCINIT_SET_32;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~CRC_CRCCON_MODE)) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_XorOut | CRC_CRCCON_MODE_CRC32;
            break;
        case CRC_MODE_CRC32_MPEG2:
            HT_CRC->CRCINIT = CRCINIT_SET_32;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut | CRC_CRCCON_XorOut))) | CRC_CRCCON_MODE_CRC32;
            break;
         case CRC_MODE_CRC16_CCITT:
         default:
            HT_CRC->CRCINIT = CRCINIT_RESET_16;
            HT_CRC->CRCCON  = (HT_CRC->CRCCON &(~(CRC_CRCCON_MODE | CRC_CRCCON_XorOut))) | CRC_CRCCON_RefIn | CRC_CRCCON_RefOut
                              | CRC_CRCCON_MODE_CCITT;
            break;
    }
}

#if defined USE_CRC_SMALL_ENDIAN
/**
*********************************************************************************************************
*                                    SMALL ENDIAN CONFIG
*
* @Brief  Configure small endian mode
*
* @Param  NewState
*         @arg ENABLE： Enable small endian mode
*         @arg DISABLE：Disable small endian mode, using default big endian mode
*
*
* @Retval None
*
* Note: In default, big endian mode is used. If small endian is enabled, the bytes of loaded words/halfwords 
*       is inversed. When small edian is disable, big endian mode is effective, and no bytes inversing. 
*********************************************************************************************************
*/
void HT_CRC_SmallEndian_Config(FunctionalState NewState)
{
    /*  assert_param  */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if(NewState == ENABLE)
    {
        HT_CRC->CRCCON |= CRC_CRCCON_ENDIAN;
    }
    else
    {
        HT_CRC->CRCCON &= ~CRC_CRCCON_ENDIAN;
    }
}
#endif

/**
*********************************************************************************************************
*                                    CALCULATE CRC MODULE
*
* @Brief Calculate the CRC of input data
*
* @Param  buf_8:       	The point to the byte buffer to be calculated(must be uint8_t* type)
* @Param  len :         The length of data to be calculated
* @Param  buf_byte_len: The bit lenght of data unit for CRC calculate(If invalide length inputed，length 8 is used)
*                       @reg CRC_CALC_8_BIT  uint length “8”bits
*                       @reg CRC_CALC_16_BIT uint length “16”bits
*                       @reg CRC_CALC_32_BIT uint length “32”bits
*
* @Retval CRC result(If CRC is in another use, return "-1")
*
* @Note
*********************************************************************************************************
*/
uint32_t HT_CRC_DataCalc(uint8_t* buf_8, uint32_t len, CRC_Calc_BitTypeDef buf_byte_len)
{
    static uint8_t crc_using = CRC_READY;
    uint32_t i, ret;
    uint16_t* buf_16 = (uint16_t*)buf_8;
    uint32_t* buf_32 = (uint32_t*)buf_8;

	/*  assert_param  */
    assert_param(IS_HT_CRC_DATA_LENGTH(len));
    assert_param(IS_HT_CRC_UNIT_LENGTH(buf_byte_len));
	
    /*  assert_param  */
    if(buf_8 == NULL)
    {
        ret = (uint32_t)(-1);
    }
	else if (crc_using == CRC_READY)                       /*!< In case the reuse of CRC module due to the interrupt */
    {
        crc_using = CRC_BUSY;
        HT_CRC->CRCCON |= CRC_CRCCON_RESET;                /*!< Reset CRC（exclude the mode config） */
        for (i=0U; (i*buf_byte_len)<len; i++)              /*!< load the data to the register untile the last data */
        {
            switch (buf_byte_len)
            {
                
                case CRC_CALC_16_BIT:
                HT_CRC->CRCDAT_WORD = *(buf_16+i);
                break;
                case CRC_CALC_32_BIT:
                HT_CRC->CRCDAT_DWORD = *(buf_32+i);
                break;
                case CRC_CALC_8_BIT:
                default:
                HT_CRC->CRCDAT_BYTE = *(buf_8+i);
                break;
            }
        }
        crc_using = 0U;

        ret = HT_CRC->CRCDAT;
    }
    else 
    {
        ret = CRC_RESULT_ERROR;
    }

    return ret;
}


#endif                                 
