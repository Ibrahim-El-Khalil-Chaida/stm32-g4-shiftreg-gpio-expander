#ifndef __STM32G4xx_HAL_SPI_H
#define __STM32G4xx_HAL_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

typedef struct {
  uint32_t Mode;        /* SPI_MODE_MASTER/SLAVE */
  uint32_t Direction;   /* SPI_DIRECTION_2LINES, etc. */
  uint32_t DataSize;    /* SPI_DATASIZE_8BIT, etc. */
  uint32_t CLKPolarity; /* SPI_POLARITY_LOW/HIGH */
  uint32_t CLKPhase;    /* SPI_PHASE_1EDGE/2EDGE */
  uint32_t NSS;         /* SPI_NSS_SOFT/HARD */
  uint32_t BaudRatePrescaler;
  uint32_t FirstBit;    /* SPI_FIRSTBIT_MSB/LSB */
  /* … */
} SPI_InitTypeDef;

typedef struct {
  SPI_TypeDef       *Instance;
  SPI_InitTypeDef    Init;
  /* … */
} SPI_HandleTypeDef;

HAL_StatusTypeDef HAL_SPI_Init           (SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DeInit         (SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Transmit       (SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive        (SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);

void HAL_SPI_MspInit    (SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit  (SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif

#endif
