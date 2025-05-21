#ifndef __STM32G4xx_HAL_CONF_H
#define __STM32G4xx_HAL_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif


#define HAL_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HSE_VALUE    ((uint32_t)8000000U)
#define HSI_VALUE    ((uint32_t)16000000U)
#define LSE_VALUE    ((uint32_t)32768U)
#define LSI_VALUE    ((uint32_t)32000U)

/* System configuration */
#define  VDD_VALUE           ((uint32_t)3300U)  /* millivolts */
#define  TICK_INT_PRIORITY   ((uint32_t)0U)

#ifdef __cplusplus
}
#endif

#endif 
