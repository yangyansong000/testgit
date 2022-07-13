/*
*********************************************************************************************************
*                                 			   HT6XXX
*                            			      HT6XXX程序
*
*                       			Copyright 2021, Hi-Trend Tech, Corp.
*                             			 All Rights Reserved
*
*
* Project      : HT6xxx
* File         : main.c
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  : 
*********************************************************************************************************
*/

#define  __MAIN_C

#include <stdio.h>
#include "ht6xxx_lib.h"

#if defined USE_RAND
/*
*********************************************************************************************************
*                                           本地宏/结构体
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            本地变量
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           本地函数申明
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
    uint32_t rand_value = 0x0;
    CMU_InitTypeDef  CMU_InitStructure;

    /* 测试代码无意义 */

    /* 启动随机数模块时钟 
     * HT502x控制位CMU_CLKCTRL0_AESEN
     * HT6x2x控制位CMU_CLKCTRL0_ARGEN
     * HT6x3x控制位CMU_CLKCTRL0_ARGEN */
	CMU_InitStructure.SysClkSel = SysHRCDiv1;
	CMU_InitStructure.CPUDiv = CPUDiv1;
	HT_CMU_Init(&CMU_InitStructure);
    #if defined HT501x  ||  defined  HT502x ||  defined  HT503x
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_AESEN, ENABLE);
    #else
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ARGEN, ENABLE);
    #endif
    /* 只有HT6x2x和HT6x3x支持随机数参数配置
     * HT502x只能直接使用，无法配置，以下函数不存在
     * 入口参数: WorkMode 随机数模式选择
     *                    RAND_MODE_SAMPLE 低频采高频模式
     *                    RAND_MODE_DFF    D 触发器不定态方式
     *                    RAND_MODE_XOR    异或混合输出
     *          BackMode 随机数后处理模式选择
     *                    RAND_BMODE_LFSR        LFSR 方式
     *                    RAND_BMODE_PSEUDO      伪随机混合方式
     *                    RAND_BMODE_LFSR_PSEUDO 上面两种方式的和 */
    #if defined USE_RAND_WORKMODE && defined USE_RAND_BACKMODE
    HT_RAND_ConfigSet(RAND_MODE_SAMPLE, RAND_BMODE_LFSR_PSEUDO);
    #endif
    
    #if defined USE_RAND_WORKMODE
    HT_RAND_WorkMode_Config(RAND_MODE_SAMPLE);
    #endif
    
    #if defined USE_RAND_BACKMODE
    HT_RAND_BackMode_Config(RAND_BMODE_LFSR_PSEUDO);
    #endif

    /*  Infinite loop  */
    while (1)
    {
        /* 启动随机数模块
         * 入口参数: NewState  ENABLE： 模块开始工作并进入产生随机数过程
         *                     DISABLE：模块停止工作 */
        HT_RAND_WorkState(ENABLE);
        /* 获取随机数结果(如果使能中断，可在中断函数中可调用下面函数获取结果) */
        rand_value = HT_RAND_DataGet();

        /* 测试代码无意义 */
        if (rand_value != 0x0) {
            HT_RAND_WorkState(DISABLE);
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
