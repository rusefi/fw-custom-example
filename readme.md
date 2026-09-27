See https://github.com/rusefi/rusefi/wiki/Custom-Firmware

## Hardware QC board overrides

[firmware/hardware/board_hw_test.cpp](firmware/hardware/board_hw_test.cpp)
shows how to provide board-specific output metadata through `board_overrides.h`.
Add your output pins to `OUTPUTS`, update its array size, and set the DC motor
output count. The example defaults to zero outputs.

Keep the callback functions `static` and assign them to the corresponding
`custom_board_getMeta*` slots in `setupBoardHardwareTestOverrides()`.
[board_configuration.cpp](board_configuration.cpp) calls this setup function
from `setup_custom_board_overrides()`. Upstream owns the public
`getBoardMeta*()` functions; defining those functions in a board causes duplicate
symbols at link time.

Upstream treats all listed outputs as low-side outputs by default. Boards that
need a different count can also register `custom_board_getMetaLowSideOutputsCount`.
