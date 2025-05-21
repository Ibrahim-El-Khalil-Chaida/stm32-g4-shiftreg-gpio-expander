#ifndef __STM32G4xx_HAL_UART_H
#define __STM32G4xx_HAL_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

typedef struct {
  uint32_t BaudRate;
  uint32_t WordLength;
  uint32_t StopBits;
  uint32_t Parity;
  uint32_t Mode;
  /* … */
} UART_InitTypeDef;

typedef struct {
  USART_TypeDef      *Instance;
  UART_InitTypeDef    Init;
  /* … */
} UART_HandleTypeDef;

HAL_StatusTypeDef HAL_UART_Init           (UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DeInit         (UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Transmit       (UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive        (UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT    (UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT     (UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

void HAL_UART_TxCpltCallback              (UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback              (UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif
