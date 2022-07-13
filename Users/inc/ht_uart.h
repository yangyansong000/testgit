#ifndef __HT_UARTx_H__
#define __HT_UARTx_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "ht_include.h"

#define USART0_BAUDRATE                      	115200
	
#define USART0_Tx_GPIO_PIN                   	GPIO_Pin_3
#define USART0_Tx_GPIO                       	HT_GPIOC
#define USART0_Tx_AFMode                     	PC3_TX0	
#define USART0_Rx_GPIO_PIN                   	GPIO_Pin_2
#define USART0_Rx_GPIO                       	HT_GPIOC
#define USART0_Rx_AFMode                     	PC2_RX0

#define MAX_Rx_Num								64

#define USARTx_485								HT_UART0
typedef struct STRUCT_UART_RECIEVE
{
    uint8_t   uRxDataBuf[MAX_Rx_Num];
	uint32_t  uRxLength;
	FunctionalState uRxStartFlag;
	FunctionalState uRxEnd_Flag;
}UART_RxBufferTypeDef; 

void Uart_Init(void);
void Uart_RxFun(void);
void HT_UART_RxCallbackFun(void);
	
uint8_t HT_UART_Transmit(HT_UART_TypeDef* UARTx, uint8_t *pData, uint16_t Size);
uint8_t HT_UART_Receive(HT_UART_TypeDef* UARTx, uint8_t *pData, uint16_t Size);	
	#ifdef __cplusplus
}
#endif

#endif /* __HT_UARTx_H__ */
