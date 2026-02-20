#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::D13; // MIL / warning LED on PD13 (DevEBox)
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {

    // Wtryski
    engineConfiguration->injectionPins[0] = Gpio::B8;   // INJ14 - PB8
    engineConfiguration->injectionPins[1] = Gpio::B9;   // INJ23 - PB9

    // Zapłon
    engineConfiguration->ignitionPins[0] = Gpio::A8;    // IGPLS - PA8

    // Trigger (TDC)
    engineConfiguration->triggerInputPins[0] = Gpio::B12;  // TDC - PB12
    engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;

    // MAP / CLT / IAT / VBatt – przypisanie do kanałów ADC
    // STM32F407 DevEBox:
    //  PA2..PA7  -> ADC1_IN2..IN7   -> EFI_ADC_2..EFI_ADC_7
    //  PC0..PC3  -> ADC1_IN10..IN13 -> EFI_ADC_10..EFI_ADC_13
    engineConfiguration->map.sensor.hwChannel = EFI_ADC_10;  // MAP   - PC0
    engineConfiguration->tps1_1AdcChannel    = EFI_ADC_11;   // TPS   - PC1
    engineConfiguration->iat.adcChannel      = EFI_ADC_2;    // IAT - PA2
    engineConfiguration->clt.adcChannel      = EFI_ADC_3;    // ECT   - PA3
    engineConfiguration->vbattAdcChannel     = EFI_ADC_12;   // VBatt - PC2

    // Podstawowe dzielniki (dopasuj do swojego schematu jeśli inne)
	engineConfiguration->analogInputDividerCoefficient = 1.5f;   // dla MAP/TPS/oil/fuel press na tych dzielnikach
	engineConfiguration->vbattDividerCoeff = 6.0f;                // dla VBAT 100k/20k
    engineConfiguration->adcVcc = 3.3f;

    engineConfiguration->clt.config.bias_resistor = 2490;
    engineConfiguration->iat.config.bias_resistor = 2490;

    // Enable SDIO SD card support
    engineConfiguration->isSdCardEnabled = true;
    engineConfiguration->sdCardCsPin = Gpio::Unassigned;
    
    // Disable Lua to avoid compilation issues
    engineConfiguration->luaEnabled = false;
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
