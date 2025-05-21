# STM32G4 Shift Register GPIO Expander

A lightweight, scalable C++ library to extend the GPIO capabilities of STM32G4-series microcontrollers by cascading 74HC595 (output) and 74HC165 (input) shift registers. Perfect for projects that require dozens (or more) of digital inputs and outputs without using up precious MCU pins.

## Features

- **Cascadable**: Easily chain multiple 74HC595 and/or 74HC165 devices.
- **Hardware SPI**: Uses the STM32’s SPI peripheral for high-speed, efficient shifting.
- **Header-only interface**: Just drop in the `.hpp` and include in your project.
- **Configurable**: Adjust `NUM_595` and `NUM_165` constants for any chain length.
- **Simple API**: Single-function calls for write (595) and read (165).

## Supported Hardware

- **MCU**: Any STM32G4-series (tested on Nucleo-G474RE)
- **Shift Registers**:
  - 74HC595 serial-to-parallel (8-bit output)
  - 74HC165 parallel-to-serial (8-bit input)


## Wiring

1. **SPI1**  
   - SCK  → PA5  
   - MOSI → PA7 (used by 74HC595)  
   - MISO → PA6 (used by 74HC165)

2. **74HC595 (Output)**
   - SER (data in)  → MOSI (PA7)
   - SRCLK (clock) → SCK (PA5)
   - RCLK (latch)  → user-configurable GPIO (e.g. PA4)
   - QH’ to next 74HC595 SER if cascading

3. **74HC165 (Input)**
   - PL (parallel load) → user-configurable GPIO (e.g. PB0)
   - CLK (clock)        → SCK (PA5) or bit-banged GPIO
   - QH (data out)      → MISO (PA6)
   - QH to next 74HC165 SER if cascading

## CubeMX Configuration

1. Enable **SPI1** as Master, full-duplex:  
   - SCK → PA5  
   - MOSI → PA7  
   - MISO → PA6  

2. Configure two GPIO outputs for:
   - 74HC595 latch pin (e.g. PA4)
   - 74HC165 parallel-load pin (e.g. PB0)

3. Generate the project. Copy `main.h` and `shift_register.hpp` into your `Core/Inc` (or equivalent) folder.


## Customization

* **Chain length**: Edit `NUM_595` and `NUM_165` in `shift_register.hpp` to match the number of devices you’re using.
* **GPIO pins**: Modify the pin defines in your `main.h` (or `main.c`) to match your board wiring.

## Building & Flashing

Use your preferred method (STM32CubeIDE, Makefile, or CMake) to compile and flash to your Nucleo board.

