/*
*********************************************************************************************************
*                                 			   HT6XXX
*                            			      Library Function
*
*                       			Copyright 2021, Hi-Trend Tech, Corp.
*                             			 All Rights Reserved
*
*
* Project      : HT6xxx
* File         : crc_example.c
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : 
*********************************************************************************************************
*/

#define  __MAIN_C

#include <stdio.h>
#include "ht6xxx_lib.h"

#if defined USE_CRC

/*
*********************************************************************************************************
*                                           Local Macro/Structure
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


/*
*********************************************************************************************************
*                                              MAIN
*
*********************************************************************************************************
*/

int main(void)                                   
{     
    /*  SystemInit() has been called before enter main() */ 
    /*  Add your application code here  */
    uint8_t  buf[256];
    uint16_t index;
    uint32_t crc_value = 0x0;

    /* 测试代码无意义 */
    for (index=0; index<256; index++) {
      buf[index] = (uint8_t)index;
    }

    /* 启动CRC模块时钟 */
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_CRCEN, ENABLE);
    /* 配置CRC计算模式 
     * CRC_MODE_CRC16_CCITT_FALSE  CRC16 CCITT FALSE方式
     * CRC_MODE_CRC16_CCITT        CRC16 CCITT 方式
     * CRC_MODE_CRC16_X25          CRC16 X25方式
     * CRC_MODE_CRC16_XMODEM       CRC16 XMODEM方式
     * CRC_MODE_CRC16_IBM          CRC16 IBM方式
     * CRC_MODE_CRC16_MAXIM        CRC16 MAXIM方式
     * CRC_MODE_CRC16_USB          CRC16 USB方式
     * CRC_MODE_CRC16_MODBUS       CRC16 MODBUS方式
     * CRC_MODE_CRC32              CRC32 方式
     * CRC_MODE_CRC32_MPEG2        CRC32 MPEG2方式 */
    HT_CRC_ModeSelect(CRC_MODE_CRC16_IBM);

    /*  Infinite loop  */
    while (1)
    {
        /* 根据buf值，数据长度和每次计算的数据长度进行CRC计算
         * 注: 切记不要在中断和主程序中同时使用该函数，如果必须同时使用请避免逻辑上同时调用的情况
         * 入口参数: buf_8        数据缓存区指针地址（单位类型是uint8_t*）
         *           len          数据缓存区有效长度（单位类型是uint32_t）
         *           buf_byte_len 以bit为最小单位（输入不合法的计算长度，都按照“8”bits计算）
         *                        CRC_CALC_8_BIT  每次参与运算的数据长度有“8”bits
         *                        CRC_CALC_16_BIT 每次参与运算的数据长度有“16”bits
         *                        CRC_CALC_32_BIT 每次参与运算的数据长度有“32”bits
         *
         * 返回参数: CRC结果（单位类型是uint32_t） */
        crc_value = HT_CRC_DataCalc(buf, 256, CRC_CALC_8_BIT);
        
        /* 测试代码无意义 */
        if (crc_value != 0x0) {
            crc_value = 0x0;
        }
    }
}


 /*
*********************************************************************************************************
*                                             ASSERT
*
*********************************************************************************************************
*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
	
  while (1)
  {

  }
}
#endif

#endif

