ifneq ($(PROJECT_CPU),simulator)
BOARDCPPSRC += \
    $(BOARD_DIR)/firmware/hardware/board_hw_test.cpp \
    $(BOARD_DIR)/board_configuration.cpp \

endif
