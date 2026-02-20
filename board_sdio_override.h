/**
 * @file board_sdio_override.h
 * @brief SDIO SD card configuration override for DevEBox F407VGT6
 * 
 * This file provides SDIO configuration overrides to enable SD card support
 * via SDIO interface instead of SPI.
 */

#ifndef BOARD_SDIO_OVERRIDE_H
#define BOARD_SDIO_OVERRIDE_H

// SDIO SD card support (DevEBox F407VGT6)
#ifndef EFI_SDC_DEVICE
#define EFI_SDC_DEVICE SDCD1
#endif

// SDIO GPIO pin overrides
#undef VAL_GPIOC_MODER
#define VAL_GPIOC_MODER (VAL_GPIO_MODER_ALL_DEFAULT & ~(PIN_MODE_INPUT(8) | PIN_MODE_INPUT(9) | PIN_MODE_INPUT(10) | PIN_MODE_INPUT(11) | PIN_MODE_INPUT(12)) | \
                                     PIN_MODE_ALTERNATE(8) | PIN_MODE_ALTERNATE(9) | PIN_MODE_ALTERNATE(10) | PIN_MODE_ALTERNATE(11) | PIN_MODE_ALTERNATE(12))

#undef VAL_GPIOC_AFRH  
#define VAL_GPIOC_AFRH (PIN_AFIO_AF(8, 12U) | PIN_AFIO_AF(9, 12U) | PIN_AFIO_AF(10, 12U) | PIN_AFIO_AF(11, 12U) | PIN_AFIO_AF(12, 12U))

#undef VAL_GPIOD_MODER
#define VAL_GPIOD_MODER (VAL_GPIO_MODER_ALL_DEFAULT & ~PIN_MODE_INPUT(2) | PIN_MODE_ALTERNATE(2))

#undef VAL_GPIOD_AFRL
#define VAL_GPIOD_AFRL (VAL_GPIO_AF_ALL_DEFAULT & ~PIN_AFIO_AF(2, 0U) | PIN_AFIO_AF(2, 12U))

// SDC driver configuration override
#ifndef STM32_SDC_USE_SDIO1
#define STM32_SDC_USE_SDIO1 TRUE
#endif

#endif /* BOARD_SDIO_OVERRIDE_H */
