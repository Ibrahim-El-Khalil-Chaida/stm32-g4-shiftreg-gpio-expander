#ifndef __STM32G4xx_HAL_RCC_H
#define __STM32G4xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

typedef struct {
  uint32_t OscillatorType;
  uint32_t HSEState;
  uint32_t HSIState;
  /* … */
} RCC_OscInitTypeDef;

typedef struct {
  uint32_t ClockType;
  uint32_t SYSCLKSource;
  uint32_t AHBCLKDivider;
  uint32_t APB1CLKDivider;
  /* … */
} RCC_ClkInitTypeDef;

HAL_StatusTypeDef HAL_RCC_OscConfig   (RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig (RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FlashLatency);

uint32_t HAL_RCC_GetSysClockFreq     (void);
uint32_t HAL_RCC_GetHCLKFreq         (void);
uint32_t HAL_RCC_GetPCLK1Freq        (void);
uint32_t HAL_RCC_GetPCLK2Freq        (void);

#ifdef __cplusplus
}
#endif

#endif 
