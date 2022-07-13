#include "ht_freertos.h"

#define START_TASK_PRIO 3 					//�������ȼ�
#define START_STK_SIZE 128 					//�����ջ��С
TaskHandle_t StartTask_Handler; 			//������
void start_task(void *pvParameters); 		//������

#define UART_TASK_PRIO 2 					//�������ȼ�
#define UART_STK_SIZE 128 					//�����ջ��С
TaskHandle_t UARTTask_Handler;  			//������
void uart_task(void *p_arg); 				//������

#define LED0_TASK_PRIO 1 					//�������ȼ�
#define LED0_STK_SIZE 50 					//�����ջ��С
TaskHandle_t LED0Task_Handler;  			//������
void led0_task(void *p_arg); 				//������

#define IDLE_TASK_PRIO 0 					//�������ȼ�
#define IDLE_STK_SIZE 50 					//�����ջ��С
TaskHandle_t IDLETask_Handler; 				//������
void idle_task(void *p_arg); 				//������

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
	//������ʼ����
	xTaskCreate((TaskFunction_t )start_task, 			//������
				(const char* )"start_task",							//��������
				(uint16_t )START_STK_SIZE,							//�����ջ��С
				(void* )NULL,														//���ݸ��������Ĳ���
				(UBaseType_t )START_TASK_PRIO, 					//�������ȼ�
				(TaskHandle_t* )&StartTask_Handler); 		//������
	vTaskStartScheduler();	
}
				
void start_task(void *pvParameters)
{
	//���������ٽ���
	taskENTER_CRITICAL(); 
	//���� UART ����
	xTaskCreate((TaskFunction_t )uart_task,
				(const char* )"uart_task",
				(uint16_t )UART_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )UART_TASK_PRIO,
				(TaskHandle_t* )&UARTTask_Handler);
				
	//���� LED0 ����
	xTaskCreate((TaskFunction_t )led0_task,
				(const char* )"led0_task",
				(uint16_t )LED0_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )LED0_TASK_PRIO,
				(TaskHandle_t* )&LED0Task_Handler);
				
	//���� ���� ����
	xTaskCreate((TaskFunction_t )idle_task,
				(const char* )"idle_task",
				(uint16_t )IDLE_STK_SIZE,
				(void* )NULL,
				(UBaseType_t )IDLE_TASK_PRIO,
				(TaskHandle_t* )&IDLETask_Handler);
				
	//ɾ����ʼ����		
	vTaskDelete(StartTask_Handler);
	//�˳������ٽ���
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


