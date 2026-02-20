include $(BOARD_DIR)/firmware/firmware.mk


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=FALSE

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
# DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15

# EGT chip
#un-comment to enable
#DDEFS += -DEFI_MAX_31855=TRUE

#see main repo for details on this any many other optional subsystems. We have too many, one has to choose what fits into his choice of stm32
#DDEFS += -DEFI_ONBOARD_MEMS=TRUE

# Enable SDIO SD card support (DevEBox F407VGT6 has SD card slot)
# EFI_SDC_DEVICE is defined in board_sdio_override.h as SDCD1
DDEFS += -DEFI_SDC_DEVICE=SDCD1
# Add SDIO GPIO configuration directly
DDEFS += -DVAL_GPIOC_MODER='(VAL_GPIO_MODER_ALL_DEFAULT & ~(PIN_MODE_INPUT(8) | PIN_MODE_INPUT(9) | PIN_MODE_INPUT(10) | PIN_MODE_INPUT(11) | PIN_MODE_INPUT(12)) | PIN_MODE_ALTERNATE(8) | PIN_MODE_ALTERNATE(9) | PIN_MODE_ALTERNATE(10) | PIN_MODE_ALTERNATE(11) | PIN_MODE_ALTERNATE(12))'
DDEFS += -DVAL_GPIOC_AFRH='(PIN_AFIO_AF(8, 12U) | PIN_AFIO_AF(9, 12U) | PIN_AFIO_AF(10, 12U) | PIN_AFIO_AF(11, 12U) | PIN_AFIO_AF(12, 12U))'
DDEFS += -DVAL_GPIOD_MODER='(VAL_GPIO_MODER_ALL_DEFAULT & ~PIN_MODE_INPUT(2) | PIN_MODE_ALTERNATE(2))'
DDEFS += -DVAL_GPIOD_AFRL='(VAL_GPIO_AF_ALL_DEFAULT & ~PIN_AFIO_AF(2, 0U) | PIN_AFIO_AF(2, 12U))'
DDEFS += -DSTM32_SDC_USE_SDIO1=TRUE
