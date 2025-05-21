#ifndef __STM32G4xx_HAL_CORTEX_H
#define __STM32G4xx_HAL_CORTEX_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g4xx.h"

/* NVIC configuration */
void HAL_NVIC_SetPriority    (IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ      (IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ     (IRQn_Type IRQn);

/* SysTick handlers */
void HAL_SYSTICK_IRQHandler  (void);
void HAL_SYSTICK_Callback    (void);

#ifdef __cplusplus
}
#endif

#endif
