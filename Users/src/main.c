/*
*********************************************************************************************************
*                                          HT6XXX
*                                       HT6XXX program
*
*                             Copyright 2021, Hi-Trend Tech, Corp.
*                                    All Rights Reserved
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

#include "ht_include.h"

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
void SystemClock_Config(SYSCLK_SelectTypeDef SysCLK, CPU_DivTypeDef CPUDiv);

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
	SystemClock_Config(SysPLL, CPUDiv1);
	TMR_Init();
	FreeRTOS_Init();
	while(1)
	{
		HT_FreeDog();
		//正常程序不应会运行到此处，可添加调试代码
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void HRC11M_Delay_mSec(uint16_t mSec)
{
	uint16_t i;
	while (mSec--)
	{
		for (i=0; i<(2200>>1); i++)
		{
			__NOP();
			__NOP();
			__NOP();
			__NOP();
		}
	}
}
void CMU_Config(SYSCLK_SelectTypeDef SysCLK, CPU_DivTypeDef CPUDiv)
{
	CMU_InitTypeDef  CMU_InitStructure;
	CMU_InitStructure.SysClkSel = SysCLK;
	CMU_InitStructure.CPUDiv = CPUDiv;
	HT_CMU_Init(&CMU_InitStructure);
	HT_Init();
}
void SystemClock_Config(SYSCLK_SelectTypeDef SysCLK, CPU_DivTypeDef CPUDiv)
{
	uint8_t i = 0;
	uint32_t calibrate;
	HT_CMU->WPREG = CMU_WPREG_UnProtected;
	calibrate = HT_INFO->Muster.iHRCADJ;
	if(HT_INFO->Muster.irHRCADJ == ~calibrate)
	{
		HT_CMU->HRCADJ = calibrate;
	}
	HT_CMU->WPREG = CMU_WPREG_Protected;
		
	if(SysCLK == SysPLL || SysCLK == SysPLLX2 || SysCLK == SysLF)
	{
		if(HT_ResetFlagStatusGet(PMU_RSTSTA_PORRST | PMU_RSTSTA_LBORRST) == SET)
		{
			HT_ResetFlagClear(PMU_RSTSTA_PORRST | PMU_RSTSTA_LBORRST);
			HRC11M_Delay_mSec(200);
			while(HT_CMU_StopFlagGet(CMU_CLKSTA_LFFLAG) == SET && i < 10)
			{
				HT_CMU->CLKSTA &= ~CMU_CLKSTA_LFFLAG;
				HRC11M_Delay_mSec(100);
				i++;
			}
			if(i < 10)
			{
				CMU_Config(SysCLK, CPUDiv);
			}else
			{
				//osc起振异常
			}
		}else
		{
			if(HT_CMU_StopFlagGet(CMU_CLKSTA_LFFLAG)==RESET)
			{
				CMU_Config(SysCLK, CPUDiv);
			}else
			{
				//osc起振异常
			}
		}
	}else
	{
		CMU_Config(SysCLK, CPUDiv);
	}
	HT_OSCPWRADJ_SET(0x01);
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


