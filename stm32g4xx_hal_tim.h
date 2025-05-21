#ifndef __STM32G4xx_HAL_TIM_H
#define __STM32G4xx_HAL_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

typedef struct {
  uint32_t Prescaler;
  uint32_t CounterMode;
  uint32_t Period;
  uint32_t ClockDivision;
  /* … */
} TIM_Base_InitTypeDef;

typedef struct {
  TIM_TypeDef          *Instance;
  TIM_Base_InitTypeDef  Init;
  /* … */
} TIM_HandleTypeDef;

HAL_StatusTypeDef HAL_TIM_Base_Init    (TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Start   (TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop    (TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_PWM_Init     (TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_Start    (TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop     (TIM_HandleTypeDef *htim, uint32_t Channel);

void HAL_TIM_MspInit    (TIM_HandleTypeDef *htim);
void HAL_TIM_MspDeInit  (TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif
