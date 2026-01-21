include $(BOARD_DIR)/firmware/firmware.mk
BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp \
    $(BOARD_DIR)/default_tune.cpp \

BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=FALSE

DDEFS += -DEFI_MAIN_RELAY_CONTROL=FALSE

# MCU defines
DDEFS += -DSTM32F407xx

# reduce memory usage monitoring
DDEFS += -DRAM_UNUSED_SIZE=100

DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
# todo: make knock pin software-selectable?
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DKNOCK_SPECTROGRAM=TRUE

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15

DDEFS += $(PRIMARY_COMMUNICATION_PORT_USART1)
PRIMARY_COMMUNICATION_PORT_USART1=-DEFI_CONSOLE_TX_BRAIN_PIN=Gpio::A10 -DEFI_CONSOLE_RX_BRAIN_PIN=Gpio::A9 -DTS_PRIMARY_UxART_PORT=UARTD1 -DSTM32_UART_USE_USART1=1

# we do not have much Lua RAM, let's drop some fancy functions
DDEFS += -DWITH_LUA_CONSUMPTION=FALSE
DDEFS += -DWITH_LUA_PID=FALSE
DDEFS += -DWITH_LUA_STOP_ENGINE=FALSE
