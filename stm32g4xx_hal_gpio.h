#ifndef __STM32G4xx_HAL_GPIO_H
#define __STM32G4xx_HAL_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

typedef enum {
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

typedef struct {
  uint32_t Pin;       /* GPIO_PIN_x */
  uint32_t Mode;      /* GPIO_MODE_x */
  uint32_t Pull;      /* GPIO_NOPULL/PULLUP/PULLDOWN */
  uint32_t Speed;     /* GPIO_SPEED_FREQ_x */
  uint32_t Alternate; /* AFx */
} GPIO_InitTypeDef;

void HAL_GPIO_Init       (GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void HAL_GPIO_DeInit     (GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);
void HAL_GPIO_WritePin   (GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
GPIO_PinState HAL_GPIO_ReadPin (GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_TogglePin  (GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif
