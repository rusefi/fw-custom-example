/*
 * Cat-GDI_meta.h
 *
 * @date  2024.
 *
 */

#pragma once

// not directly related but often used together
#include "defaults.h"

#define Cat_GDI_DEFAULT_AT_PULLUP 2700

#define Cat_ingect_H_1 D7
#define Cat_ingect_H_2 G9
#define Cat_ingect_H_3 G10
#define Cat_ingect_H_4 G11
#define Cat_ingect_5 G12
#define Cat_ingect_6 G13
#define Cat_ingect_7 G14
#define Cat_ingect_8 B4
#define Cat_pump1_H B5
#define Cat_pump2_H B6
#define Cat_pump_L1 B7
#define Cat_pump_L2 B8
#define Cat_LS_13 B9
#define Cat_LS_14 E0
#define Cat_LS_15 E1
#define Cat_LS_16 E2
#define Cat_HS_1 A9
#define Cat_HS_2 A8
#define Cat_HS_3 D15
#define Cat_HS_4 D14
#define Cat_IGN_1 D4
#define Cat_IGN_2 D3
#define Cat_IGN_3 C9
#define Cat_IGN_4 C8
#define Cat_IGN_5 C7
#define Cat_IGN_6 G8
#define Cat_IGN_7 G7
#define Cat_IGN_8 G6
#define Cat_Start G5
#define Cat_IGN_10 G4
#define Cat_IGN_11 G3
#define Cat_IGN_12 G2

// CLT= Analog Temp 1 = PC4
#define Cat_IN_ANALOG_TEMP_1 EFI_ADC_14
#define Cat_IN_CLT Cat_IN_ANALOG_TEMP_1
// IAT = Analog Temp 2 = PC5
#define Cat_IN_ANALOG_TEMP_2 EFI_ADC_15
#define Cat_IN_IAT Cat_IN_ANALOG_TEMP_2

// Analog Temp 3 = PB0
#define Cat_IN_ANALOG_TEMP_3 EFI_ADC_8


// Analog Temp 4 = PB1
#define Cat_IN_ANALOG_TEMP_4 EFI_ADC_9

// Analog volt 1 = PC0
#define Cat_IN_ANALOG_VOLT_1 EFI_ADC_10
#define Cat_IN_PPS Cat_IN_ANALOG_VOLT_1

// TPS = Analog volt 2 = PC1
#define Cat_IN_ANALOG_VOLT_2 EFI_ADC_11
#define Cat_IN_PPS2 Cat_IN_ANALOG_VOLT_2

// PC2
#define Cat_IN_ANALOG_VOLT_3 EFI_ADC_12
#define Cat_IN_TPS1_2 Cat_IN_ANALOG_VOLT_3

// PC3
#define Cat_IN_ANALOG_VOLT_4 EFI_ADC_13
#define Cat_IN_TPS2_1 Cat_IN_ANALOG_VOLT_4

// PA0
#define Cat_IN_ANALOG_VOLT_5 EFI_ADC_0

// PA1
#define Cat_IN_ANALOG_VOLT_6 EFI_ADC_1
#define Cat_IN_AV_6_DIGITAL Gpio::A1

// PA2
#define Cat_IN_ANALOG_VOLT_7 EFI_ADC_2

// MAP = Analog Temp 3 = PA3
#define Cat_IN_ANALOG_VOLT_8 EFI_ADC_3
#define Cat_IN_MAP Cat_IN_ANALOG_VOLT_8

// PA4
#define Cat_IN_ANALOG_VOLT_9 EFI_ADC_4

// PA5
#define Cat_IN_ANALOG_VOLT_10 EFI_ADC_5
#define Cat_IN_AV_10_DIGITAL Gpio::A5

// PA6
#define Cat_IN_ANALOG_VOLT_11 EFI_ADC_6
#define Cat_IN_AV_11_DIGITAL Gpio::A6

#define Cat_VR_1 Gpio::E7
#define Cat_VR_2 Gpio::E8

#define Cat_DIGITAL_1 Gpio::C6
#define Cat_DIGITAL_2 Gpio::E11
#define Cat_DIGITAL_3 Gpio::E12
#define Cat_DIGITAL_4 Gpio::E14
#define Cat_DIGITAL_5 Gpio::E13
#define Cat_DIGITAL_6 Gpio::E15


