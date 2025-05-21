#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"

void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_SPI1_Init(void);

extern SPI_HandleTypeDef hspi1;

#ifdef __cplusplus
}
#endif

#endif 
