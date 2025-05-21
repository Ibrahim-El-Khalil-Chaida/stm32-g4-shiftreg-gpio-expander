#pragma once
#include "stm32g4xx_hal.h"

static constexpr uint8_t NUM_595 = 2;  // number of 74HC595 chained → 8 × NUM_595 outputs
static constexpr uint8_t NUM_165 = 1;  // number of 74HC165 chained → 8 × NUM_165 inputs

class ShiftRegister595 {
public:
    ShiftRegister595(SPI_HandleTypeDef& hspi,
                     GPIO_TypeDef* latchPort, uint16_t latchPin)
      : hspi_(hspi), latchPort_(latchPort), latchPin_(latchPin)
    {}

    /// Write NUM_595 bytes (data[0] → first chip)
    void write(const uint8_t data[NUM_595]) {
        HAL_GPIO_WritePin(latchPort_, latchPin_, GPIO_PIN_RESET);
        HAL_SPI_Transmit(&hspi_, const_cast<uint8_t*>(data), NUM_595, HAL_MAX_DELAY);
        HAL_GPIO_WritePin(latchPort_, latchPin_, GPIO_PIN_SET);
    }

private:
    SPI_HandleTypeDef& hspi_;
    GPIO_TypeDef*      latchPort_;
    uint16_t           latchPin_;
};

class ShiftRegister165 {
public:
    ShiftRegister165(SPI_HandleTypeDef& hspi,
                     GPIO_TypeDef* plPort,   uint16_t plPin)
      : hspi_(hspi), plPort_(plPort), plPin_(plPin)
    {}

    /// Read NUM_165 bytes into buffer[0…NUM_165-1]
    void read(uint8_t buffer[NUM_165]) {
        HAL_GPIO_WritePin(plPort_, plPin_, GPIO_PIN_RESET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(plPort_, plPin_, GPIO_PIN_SET);
        for (uint8_t i = 0; i < NUM_165; ++i) {
            HAL_SPI_Receive(&hspi_, &buffer[i], 1, HAL_MAX_DELAY);
        }
    }

private:
    SPI_HandleTypeDef& hspi_;
    GPIO_TypeDef*      plPort_;
    uint16_t           plPin_;
};
