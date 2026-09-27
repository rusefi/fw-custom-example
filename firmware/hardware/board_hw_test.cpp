#include "pch.h"
#include "board_overrides.h"
#include <array>

// Add this board's HW QC output pins and update the array size to match.
// For example: std::array<Gpio, 2> OUTPUTS = {Gpio::B5, Gpio::B6};
// The generic example has no assigned outputs.
static std::array<Gpio, 0> OUTPUTS = {
};

static int boardGetMetaOutputsCount() {
    return static_cast<int>(OUTPUTS.size());
}

static Gpio* boardGetMetaOutputs() {
    return OUTPUTS.empty() ? nullptr : OUTPUTS.data();
}

static int boardGetMetaDcOutputsCount() {
    // Set this to the number of DC motor outputs on the board.
    return 0;
}

void setupBoardHardwareTestOverrides() {
    custom_board_getMetaOutputsCount = boardGetMetaOutputsCount;
    custom_board_getMetaOutputs = boardGetMetaOutputs;
    custom_board_getMetaDcOutputsCount = boardGetMetaDcOutputsCount;
}
