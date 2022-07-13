/*
*********************************************************************************************************
*                                 			   HT6XXX
*                            			     Library Function
*
*                       			Copyright 2021, Hi-Trend Tech, Corp.
*                             			 All Rights Reserved
*
*
* Project      : HT6xxx
* File         : flash_example.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  : 
*********************************************************************************************************
*/

#define  __MAIN_C

#include <stdio.h>
#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                            Local Mcro/Structure
*********************************************************************************************************
*/
#define  BUFF_CLEAR()       {for (i=0; i<1024; i++) { \
                               data[i] = 0; \
                            }}                


/*
*********************************************************************************************************
*                                             Local Variable
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
  uint8_t data[1024];
  uint16_t i;

  /* test code,insignificance  */
  HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024);
  HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024*2);
  HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024*3);
  /* test code,insignificance  */
  HT_Info_PageErase(HT_INFO_BASE);

  /*  Infinite loop  */
  while (1) {
    /* test code,insignificance  */
    for (i=0; i<1024; i++) {
      data[i] = (uint8_t)i;
    }

    /************************* Flash read/write/erase *****************************
     ******Do not use flash in interrupt and main programs at the same time*******/

    /*  HT501x total 128k bytes - 1k bytes/page
     *  HT502x total 256k bytes - 1k bytes/page
     *  HT6x1x total 128k bytes - 1k bytes/page
     *  HT6x2x total 256k bytes - 1k bytes/page
     *  HT6x3x total 512k bytes - 1k bytes/page */
    HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024*2);

    HT_Flash_ByteWrite(data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024);
    
    BUFF_CLEAR();

    HT_Flash_ByteRead(data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024);
    
    HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024*2);

    HT_Flash_HalfWordWrite((uint16_t*)data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024/2);

    BUFF_CLEAR();

    HT_Flash_HalfWordRead((uint16_t*)data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024/2);

    HT_Flash_PageErase(HT_FLASH_BASE+HT_FLASH_SIZE-1024*2);

    HT_Flash_WordWrite((uint32_t*)data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024/4);

    BUFF_CLEAR();

    HT_Flash_WordRead((uint32_t*)data, HT_FLASH_BASE+HT_FLASH_SIZE-1024*2, 1024/4);



    /************************* Info read/write/erase *****************************
     ******Do not use flash in interrupt and main programs at the same time*******/
    /*          HT501x total 512 bytes - 256 bytes/page
     *          HT502x total 1k  bytes - 1k  bytes/page
     *          HT6x1x total 512 bytes - 256 bytes/page
     *          HT6x2x total 1k  bytes - 1k  bytes/page
     *          HT6x3x total 1k  bytes - 1k  bytes/page */
    HT_Info_PageErase(HT_INFO_BASE); 

    HT_Info_ByteWrite(data, HT_INFO_BASE, HT_INFO_BANK);

    BUFF_CLEAR();

    HT_Info_ByteRead(data, HT_INFO_BASE, HT_INFO_BANK);

    HT_Info_PageErase(HT_INFO_BASE); 

    HT_Info_HalfWordWrite((uint16_t*)data, HT_INFO_BASE, HT_INFO_BANK/2);

    BUFF_CLEAR();

    HT_Info_HalfWordRead((uint16_t*)data, HT_INFO_BASE, HT_INFO_BANK/2);

    HT_Info_PageErase(HT_INFO_BASE);

    HT_Info_WordWrite((uint32_t*)data, HT_INFO_BASE, HT_INFO_BANK/4);

    BUFF_CLEAR();

    HT_Info_WordRead((uint32_t*)data, HT_INFO_BASE, HT_INFO_BANK/4);
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


