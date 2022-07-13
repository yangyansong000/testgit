#include "ht_uart.h"

UART_RxBufferTypeDef aRxBuffer;

static void HT_UART_MspInit(void)
{
	AF_GPIO_Config(USART0_Rx_GPIO, USART0_Rx_GPIO_PIN, USART0_Rx_AFMode, GPIO_Output_OD, GPIO_Input_Up);
	AF_GPIO_Config(USART0_Tx_GPIO, USART0_Tx_GPIO_PIN, USART0_Tx_AFMode, GPIO_Output_PP, GPIO_Input_Up);
}

static void NVIC_UART0_Init(FunctionalState NewState)
{
	/* UARTx_IRQn interrupt configuration */
	if(NewState != DISABLE)
	{
		NVIC_SetPriority (UART0_IRQn, 0x0);
		NVIC_EnableIRQ(UART0_IRQn);
	}else
	{
		NVIC_DisableIRQ(UART0_IRQn);
	}
}

void UART0_Init(void)
{
	UART_InitTypeDef UART_InitStructure;
	
	HT_CMU_ClkCtrl1Config(CMU_CLKCTRL1_UART0EN, ENABLE); 			/*!< 使能UART模块   	           */
	UART_InitStructure.UART_Logic 		= UartLogicPositive;		/*!< UART逻辑为正               */
	UART_InitStructure.UART_StopBits 	= OneStopBits;             	/*!< 1位停止位                  */
	UART_InitStructure.UART_WordLength 	= WordLength_8Bits;			/*!< 8位数据位                  */
	UART_InitStructure.UART_Parity 		= UartParity_Disable;		/*!< 无校验                     */
	UART_InitStructure.UART_BaudRate 	= USART0_BAUDRATE;			/*!< 波特率9600                 */
	UART_InitStructure.ReceiveEN 		= ENABLE;					/*!< 接收使能   注：非中断使能  	*/
	UART_InitStructure.SendEN 			= ENABLE;					/*!< 发送使能   注：非中断使能  	*/
	HT_UART_Init(HT_UART0, &UART_InitStructure);
	
	HT_UART_ITConfig(HT_UART0, UART_UARTCON_TXIE, DISABLE);
	HT_UART_ITConfig(HT_UART0, UART_UARTCON_RXIE, ENABLE);
	
	NVIC_UART0_Init(ENABLE);
	HT_UART_MspInit();
}

uint8_t HT_UART_Transmit(HT_UART_TypeDef* UARTx, uint8_t *pData, uint16_t Size)
{
	if((pData == NULL) || (Size == 0))
	{
		return  0;
	}
	uint16_t Send_Len = Size;
	uint16_t Send_Count = 0;
	uint16_t timeout=0;
	while(Send_Count < Send_Len)
	{
		HT_UART_SendData(UARTx, pData[Send_Count]);
		while(HT_UART_ITFlagStatusGet(UARTx, UART_UARTSTA_TXIF)==RESET && timeout<0xffff)
		{
			timeout++;
		}
		if(timeout>=0xffff)
		{
			return 0;
		}
		timeout=0;
		HT_UART_ClearITPendingBit(UARTx,UART_UARTSTA_TXIF);
		Send_Count++;
	}
	return 1;
}

uint8_t HT_UART_Receive(HT_UART_TypeDef* UARTx, uint8_t *pData, uint16_t Size)
{
	if((pData == NULL) || (Size == 0))
	{
		return  0;
	}
	uint16_t Receive_Len = Size;
	uint16_t Receive_Count = 0;
	while(Receive_Count < Receive_Len)
	{
		while((HT_UART_ITFlagStatusGet(UARTx, UART_UARTSTA_RXIF) != SET))
		{
			HT_FreeDog();
		}
		pData[Receive_Count] = HT_UART_ReceiveData(UARTx);
		HT_UART_ClearITPendingBit(UARTx,UART_UARTSTA_RXIF);
		Receive_Count++;
	}
	return 1;
}

int fputc(int ch, FILE *f)
{
	HT_UART_Transmit(HT_UART0, (uint8_t *)&ch, 1);
	return ch;
}

int fgetc(FILE * f)
{
	uint8_t ch = 0;
	HT_UART_Receive(HT_UART0, &ch, 1);
	return ch;
}

static void Uart_RxBufData_Init(void)
{
	aRxBuffer.uRxStartFlag = DISABLE;
	aRxBuffer.uRxEnd_Flag = DISABLE;
	aRxBuffer.uRxLength = 0;
	for(uint8_t i=0; i<MAX_Rx_Num; i++)
	{
		aRxBuffer.uRxDataBuf[i] = 0;
	}
}

void Uart_Init(void)
{
	UART0_Init();
	Uart_RxBufData_Init();
}

static void Uart_RxDataPro(UART_RxBufferTypeDef *rx_data)
{
	HT_UART_Transmit(HT_UART0, rx_data->uRxDataBuf, rx_data->uRxLength);
}

void Uart_RxFun(void)
{
	static uint32_t old_cnt = 0xff, new_cnt = 0;
	if(aRxBuffer.uRxStartFlag == ENABLE)
	{
		if(HT_CycleTmr(1, 5, ENABLE) == SET)
		{
			HT_CycleTmr(1, 5, DISABLE);
			new_cnt = aRxBuffer.uRxLength;
			if(new_cnt - old_cnt == 0)
			{
				aRxBuffer.uRxStartFlag = DISABLE;
				aRxBuffer.uRxEnd_Flag = ENABLE;
			}
			old_cnt = new_cnt;
		}
	}
	if(aRxBuffer.uRxEnd_Flag == ENABLE)
	{
		Uart_RxDataPro(&aRxBuffer);
		aRxBuffer.uRxEnd_Flag = DISABLE;
	}
}

void HT_UART_RxCallbackFun(void)
{
	static uint32_t old_time, new_time, status_value;
	//进入中断级临界保护
	status_value=taskENTER_CRITICAL_FROM_ISR();
	new_time = HT_GetTick();
	if(new_time - old_time > 5)
	{
		aRxBuffer.uRxStartFlag = ENABLE;
		aRxBuffer.uRxLength = 0;
	}
	old_time = new_time;
	aRxBuffer.uRxDataBuf[aRxBuffer.uRxLength] = HT_UART_ReceiveData(USARTx_485);
	aRxBuffer.uRxLength++;
	if(aRxBuffer.uRxLength > MAX_Rx_Num)
	{
		aRxBuffer.uRxLength = 0;
	}
	//退出中断级临界保护
	taskEXIT_CRITICAL_FROM_ISR(status_value);
}

