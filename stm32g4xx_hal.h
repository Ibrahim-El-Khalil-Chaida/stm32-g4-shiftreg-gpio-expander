#ifndef __STM32G4XX_HAL_H
#define __STM32G4XX_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "stm32g4xx_hal_conf.h"
#include "stm32g4xx_hal_cortex.h"
#include "stm32g4xx_hal_rcc.h"
#include "stm32g4xx_hal_gpio.h"
#include "stm32g4xx_hal_spi.h"
#include "stm32g4xx_hal_tim.h"
#include "stm32g4xx_hal_uart.h"

typedef enum {
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

#define __IO volatile

void    HAL_Init(void);
uint32_t HAL_GetTick(void);
void    HAL_Delay(uint32_t Delay);

/* GPIO control */
HAL_StatusTypeDef HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

/* SPI functions */
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive (SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);


#ifdef __cplusplus
}
#endif

#endif
