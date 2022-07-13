

   时间      |    执行人     | 修改记录
2014/3/10    |     ywfu      | 完成初版V0.1
             |               |
2014/3/20    |     ywfu      | 版本号V0.2
             |               | 修改记录：1. 增加Flash 字节/半字/字读  
             |               |           2. 增加清除中断标志函数
             |               |           3. 增加uart写buf函数
             |               |           4. 增加配置uart/timer之前先配clkctrl0注释说明
             |               |           5. 增加HT_RTC_LoadInfoData()函数，在ht60xx.h头文件中增加HT_INFO结构体
             |               |
2014/3/24    |     ywfu      | 版本号V0.3
             |               | 修改记录：1. HT_GPIO_Init()函数配置IO输出，之前有错。
             |               |              修正如下： GPIOx->IOCFG-------> GPIOx->PTDIR
             |               |           2. HT_GPIO_Init()函数配置为第二复用功能 ，之前有错。
             |               |              修正如下： GPIOx->IOCFG-------> GPIOx->AFCFG 
             |               |           3. HT_Flash_HalfWordWrite(), HT_Flash_HalfWordRead(),HT_Flash_WordWrite(),HT_Flash_WordRead(),HT_Flash_PageErase()
             |               |              因为在对齐地址访问上存在问题，已做修改 
             |               |           4. 增加ht60xx_reset.c
             |               |           5. CMU_InitTypeDef 结构体改变，删除HRCDiv变量
             |               |           6. HT_TMR_Init() 改变寄存器配置顺序，先配置寄存器，最后使能定时器
             |               |           7. example.c增加LowPowerConfigure_Example()
             |               |               
2014/5/23    |     ywfu      | 版本号V0.4
             |               | 修改记录：1. TBS打开频率周期宏定义修改(ht60xx.h)        
             |               |           2. TBS周期设定函数修改
             |               |           3. 删除TBS中VbatCMP控制位            
             |               |           4. SPI读写数据修改，现在统一改为 HT_SPI_SendByte()函数
             |               |           5. 库函数头文件统一包含到"ht60xx_lib.h"
             |               |           6. CMU_IRQHandler改为DES_IRQHandler
             |               |           7. 增加JTAGSTA状态寄存器，增加相应读状态函数HT_CMU_JTAGStatusGet()
             |               |           8. 增加读停振状态指示函HT_CMU_StopFlagGet()
             |               |                      
2014/5/26    |     ywfu      | 版本号V0.5
             |               | 修改记录：1. ht60xx.h 头文件enum IRQn处注释修改    
             |               |     
2014/6/11    |     ywfu      | 版本号V1.0~1.2
             |               | 修改记录：1. 整合HT6x1x、HT6x2x、HT501x，并宏定义区分       
             |               |     
2014/10/30   |     hxyu      | 版本号V1.3
             |               | 修改记录：1. 修改整合后的错误 
             |               |       
2015/09/01   |     hxyu      | 版本号V1.4
             |               | 修改记录：1. 修改INT_PINFLT2 位定义;
             |               |           2. 增加数字滤波配置函数;
             |               |           3. 增加AES相关库函数;
             |               |           4. 增加Ghash有限域乘法相关库函数;
             |               |           5. 增加GCM，CRT，CBC，ECB加密算法例程，及相关定义
             |               | 
2016/04/08   |     yren      | 版本号V1.5
             |               | 修改记录：1. 增加存储空间的详细定义;
             |               |           2. 将HT_WDT->WDTSET修正为HT_WDT->WDTCLR;
             |               |           3. 将HT_PMU->PMUSTA的属性修正为只读;
             |               |           4. 修正Startup.s内的自装载值;
             |               |           5. 修改Startup.s中堆栈大小的定义;
             |               |           6. 增加HT_CMU_CPUClkGet()
             |               | 
2016/06/21   |     yren      | 版本号V1.6       
             |               | 修改记录：1. 修改ht6xxx.h中CLKCTRL0的ResetMask值;
             |               |           2. 修改ht6xxx_cmu.h，Line39注释关于osc的描述;
             |               |           3. 修正ht6xxx_cmu.h，Line40-43注释关于高频RC时钟的描述;
             |               |           4. 增加文件版本号
2016/07/21   |     yren      | 版本号V1.62      
             |               | 修改记录：1. 修改HT6xxx.h中CRC的相关定义;
             |               |           2. 修正HT6xxx.h中Info的SIZE和BANK的定义，HT6xxx.h升版至V1.0.1。
             |               | 
2016/12/27   |     yren      | 版本号V1.64      
             |               | 修改记录：1. 增加HT502x的相关内容，对应文件版本号升级；
             |               |           2. 修正错误。
             |               | 
2017/02/07   |     yren      | 版本号V1.7       
             |               | 修改记录：1. 增加ecc的相关内容。
             |               |
             |               | 
2017/11/08   |     yren      | 版本号V1.8       
             |               | 修改记录：1. 增加HT6x3x的相关内容；
             |               |           2. 增加部分新增功能；
             |               |           3. 优化代码和变量。
             |               |
2018/03/20   |     yren      | 版本号V1.82      
             |               | 修改记录：1. 修正部分功能；
             |               |           2. 将Flash操作修改为汇编操作，并增加Info相关操作；
             |               |           3. 增加部分功能和样例代码。
             |               |
2021/11/29   |    cyzhong    | 版本号V2.0.0      
             |               | 修改记录：1. 增加HT503x/HT7x2x/HT633x的相关内容；
             |               |           2. 优化中断代码:添加callback功能;
	     |               |           3. 条件编译优化:由原来的根据芯片型号进行管理改为通过功能进行管理
             |               | 
2021/12/13   |    cyzhong    | 版本号V2.0.6      
             |               | 修改记录：1. 增加HT503x的PRAMPACK/EMU INTERFACE相关内容和样例代码。
             |               |           2. 增加HT7x2x的PRAMPACK/EMU INTERFACE/FFT相关内容和样例代码。
	     |		     |           3. 删除HT7x2x工程,同时增加HT762x工程,并增加HT762x的EMU/EWU相关内容和样例代码。
             |               |     
2022/02/09   |    cyzhong    | 版本号V2.0.7      
             |               | 修改记录：1. 修正ht6xxx_tbs.h,ht6xxx_spi.h,ht6xxx_spi.c,HT7x2x_frampack.c,ht50xx_emu.c,random_example.c和example.c的错误。
             |               |           2. 模块EMUIF名称改为EMUIFACE,避免与EMU模块命名冲突，改善ht6xxx_wdt.h,ht6xxx_tbs.h,ht6xxx_tbs.c和ht6xxx_uart&7816.c中部分功能。
	     |		     |           3. 新增emu_example.h和emu_example.c
             |               |       					
2022/02/09   |    cyzhong    | 版本号V2.0.8      
             |               | 修改记录：1. 增加HT772x工程,并增加HT772x的EMU/EWU相关内容和样例代码。
             |               |          2. 由于HT633x芯片升级,修改模块:PMU/EXTI/RTC/CMU/WDT/RAM/FLASH 
	     |		     |          3. 修正HT6x2xK相关错误。 
             |               |       