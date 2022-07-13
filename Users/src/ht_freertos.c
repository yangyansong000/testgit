#include "ht_freertos.h"

#define START_TASK_PRIO 3 					//任务优先级
#define START_STK_SIZE 128 					//任务堆栈大小
TaskHandle_t StartTask_Handler; 			//任务句柄
void start_task(void *pvParameters); 		//任务函数

#define UART_TASK_PRIO 2 					//任务优先级
#define UART_STK_SIZE 128 					//任务堆栈大小
TaskHandle_t UARTTask_Handler;  			//任务句柄
void uart_task(void *p_arg); 				//任务函数

#define LED0_TASK_PRIO 1 					//任务优先级
#define LED0_STK_SIZE 50 					//任务堆栈大小
TaskHandle_t LED0Task_Handler;  			//任务句柄
void led0_task(void *p_arg); 				//任务函数

#define IDLE_TASK_PRIO 0 					//任务优先级
#define IDLE_STK_SIZE 50 					//任务堆栈大小
TaskHandle_t IDLETask_Handler; 				//任务句柄
void idle_task(void *p_arg); 				//任务函数

/** @defgroup HT_Exported_Functions HT Exported Functions
  * @{
  */
__weak void HT_InitTick(void)
{
	uint32_t uCPUFreq=0;
	uCPUFreq =HT_CMU_CPUClkGet();
  /*Configure the SysTick to have interrupt in 1ms time basis*/
	SysTick_Config(uCPUFreq/configTICK_RATE_HZ);
}

void HT_Init(void)
{
  /* Use systick as time base source and configure configTICK_RATE_HZ Hz tick (default clock after Reset is HSI) */

  HT_InitTick();
}

void FreeRTOS_Init(void)
{
	//创建开始任务
	xTaskCreate((TaskFunction_t )start_task, 			//任务函数
				(const char* )"start_task",							//任务名称
				(uint16_t )START_STK_SIZE,							//任务堆栈大小
				(void* )NULL,														//传递给任务函数的参数
				(UBaseType_t )START_TASK_PRIO, 					//任务优先级
				(TaskHandle_t* )&StartTask_Handler); 		//任务句柄
	vTaskStartScheduler();	
}
				
void start_task(void *pvParameters)
{
	//进入任务级临界区
	taskENTER_CRITICAL(); 
	//创建 UART 任务
	xTaskCreate((TaskFunction_t )uart_task,
				(const char* )"uart_task",
				(uint16_t )UART_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )UART_TASK_PRIO,
				(TaskHandle_t* )&UARTTask_Handler);
				
	//创建 LED0 任务
	xTaskCreate((TaskFunction_t )led0_task,
				(const char* )"led0_task",
				(uint16_t )LED0_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )LED0_TASK_PRIO,
				(TaskHandle_t* )&LED0Task_Handler);
				
	//创建 空闲 任务
	xTaskCreate((TaskFunction_t )idle_task,
				(const char* )"idle_task",
				(uint16_t )IDLE_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )IDLE_TASK_PRIO,
				(TaskHandle_t* )&IDLETask_Handler);
				
	//删除开始任务		
	vTaskDelete(StartTask_Handler);
	//退出任务级临界区
	taskEXIT_CRITICAL();
}

void uart_task(void *pvParameters)
{
	Uart_Init();
	printf("633x FreeRTOS Test");
	for(;;)
	{
		HT_FreeDog();
		Uart_RxFun();
		vTaskDelay(1);
	}
}

void led0_task(void *pvParameters)
{
	GPIO_Init();
	for(;;)
	{
		HT_FreeDog();
		HT_GPIO_BitsToggle(HT_GPIOE, GPIO_Pin_0);
		vTaskDelay(500);
	}
}

void idle_task(void *pvParameters)
{
	for(;;)
	{
		HT_FreeDog();
		vTaskDelay(500);
	}
}


