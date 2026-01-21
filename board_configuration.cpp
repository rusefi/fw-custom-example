#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::E5;
}

static void setInjectorPins() {
	engineConfiguration->injectionPins[0] = Gpio::D12;
	engineConfiguration->injectionPins[1] = Gpio::D13;
	engineConfiguration->injectionPins[2] = Gpio::D14;
	engineConfiguration->injectionPins[3] = Gpio::D15;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPins[0] = Gpio::E9;
	engineConfiguration->ignitionPins[1] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[2] = Gpio::E11;
	engineConfiguration->ignitionPins[3] = Gpio::Unassigned;
}

static void setSensorPins() {
	engineConfiguration->iat.adcChannel = EFI_ADC_10;
	engineConfiguration->clt.adcChannel = EFI_ADC_11;	
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_12;
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_13;
    engineConfiguration->map.sensor.type = MT_MPX4250;
	engineConfiguration->vbattAdcChannel = EFI_ADC_0;
	engineConfiguration->mafAdcChannel = EFI_ADC_2;
	engineConfiguration->afr.hwChannel = EFI_ADC_4;
	engineConfiguration->triggerInputPins[0] = Gpio::E0;
	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;
    engineConfiguration->camInputs[0] = Gpio::E1;
	engineConfiguration->camInputs[1] = Gpio::Unassigned;
	engineConfiguration->vehicleSpeedSensorInputPin = Gpio::A5;
	engineConfiguration->lps25BaroSensorScl = Gpio::B10;
	engineConfiguration->lps25BaroSensorSda = Gpio::B11;
}

static void setupVbatt() {
	// 470 high side/ 910 low side
	engineConfiguration->analogInputDividerCoefficient = 1.51f;
	
	// 39k high side/ 1k low side
	engineConfiguration->vbattDividerCoeff = 7.43f; 
	
	engineConfiguration->adcVcc = 3.3f;
}

//Board-specific configuration setup
void customBoardDefaultConfiguration() {
	setInjectorPins();
	setIgnitionPins();
	setSensorPins();
	setupVbatt();
	
	//engineConfiguration->clt.config.bias_resistor = 2490;
	//engineConfiguration->iat.config.bias_resistor = 2490;
	engineConfiguration->clt.config = {0, 50, 98, 94000, 11000, 2370, 2490};
	engineConfiguration->iat.config = {0, 50, 98, 94000, 11000, 2370, 2490};

	engineConfiguration->tpsMin = 186;
	engineConfiguration->tpsMax = 925;

	engineConfiguration->enableSoftwareKnock = true;
	engineConfiguration->cylindersCount = 4;
	engineConfiguration->firingOrder = FO_1_3_4_2;

	engineConfiguration->ignitionMode = IM_WASTED_SPARK;
	engineConfiguration->crankingInjectionMode = IM_SIMULTANEOUS;
	engineConfiguration->injectionMode = IM_SEQUENTIAL;
	engineConfiguration->trigger.type = trigger_type_e::TT_TOOTHED_WHEEL_36_1;
	engineConfiguration->globalTriggerAngleOffset = 85;
	engineConfiguration->displacement = 1.596;
	engineConfiguration->cylinderBore = 79;
	engineConfiguration->compressionRatio = 11.0;
	engineConfiguration->injector.flow = 130;
	//engineConfiguration->cranking.baseFuel = 25;
	engineConfiguration->cranking.rpm = 400;
	engineConfiguration->crankingTimingAngle = 20;
	engineConfiguration->rpmHardLimit = 7500;

// Vehicle speed/gears
	engineConfiguration->totalGearsCount = 5;
	engineConfiguration->gearRatio[0] = 3.154;
	engineConfiguration->gearRatio[1] = 1.926;
	engineConfiguration->gearRatio[2] = 1.281;
	engineConfiguration->gearRatio[3] = 0.951;
	engineConfiguration->gearRatio[4] = 0.756;

	engineConfiguration->driveWheelRevPerKm = 552;
	engineConfiguration->finalGearRatio = 3.62;
	engineConfiguration->tachPulsePerRev = 2;

// Set up closed loop fuel
	engineConfiguration->fuelClosedLoopCorrectionEnabled = true;
	engineConfiguration->stft.minAfr = 10;
	engineConfiguration->stft.cellCfgs[0] = { 5, -5, 5 };
	engineConfiguration->stft.cellCfgs[1] = { 15, -15, 10 };
	engineConfiguration->stft.cellCfgs[2] = { 15, -15, 1 };
	engineConfiguration->stft.cellCfgs[3] = { 5, -5, 30 };
	
//Digital Input
	engineConfiguration->acSwitch = Gpio::E4;
	engineConfiguration->clutchDownPin = Gpio::B5;
	engineConfiguration->clutchDownPinMode = PI_PULLDOWN;
	engineConfiguration->launchActivationMode = CLUTCH_INPUT_LAUNCH;
	//engineConfiguration->malfunctionIndicatorPin = Gpio::C6;
	
//Low Side Outputs 
	engineConfiguration->fuelPumpPin = Gpio::E0;
	engineConfiguration->tachOutputPin = Gpio::E7;
	//engineConfiguration->mainRelayPin = Gpio::D8;
	engineConfiguration->mainRelayPin = Gpio::Unassigned;
	engineConfiguration->acRelayPin = Gpio::C13;
	engineConfiguration->fanPin = Gpio::E6;
	engineConfiguration->fan2Pin = Gpio::D9;
	engineConfiguration->fanOffTemperature = 96;
	engineConfiguration->fanOnTemperature = 100;
	engineConfiguration->fan2OnTemperature = 106;
	engineConfiguration->fan2OffTemperature = 101;
	engineConfiguration->enableFan1WithAc = true;
	engineConfiguration->enableFan2WithAc = true;
	
// GPPWM0: PWM CLT Gauge 
	engineConfiguration->gppwm[0].pin = Gpio::A8;
	engineConfiguration->gppwm[0].pwmFrequency = 100;
	engineConfiguration->gppwm[0].loadAxis = GPPWM_Clt;
	engineConfiguration->gppwm[0].onAboveDuty = 80;
	engineConfiguration->gppwm[0].offBelowDuty = 20;
	strcpy(engineConfiguration->gpPwmNote[0], "CLTGauge");
	copyArray(engineConfiguration->gppwm[0].rpmBins, { 0, 1000, 2000, 2500, 3500, 5500, 6500, 7000 });	
	copyArray(engineConfiguration->gppwm[0].loadBins, { 0, 40, 60, 80, 90, 100, 110, 120 });

//Idle configuration
	engineConfiguration->useStepperIdle = false;
	engineConfiguration->isDoubleSolenoidIdle = false;
	engineConfiguration->idle.solenoidPin = Gpio::C7;
	engineConfiguration->idle.solenoidFrequency = 500;
	engineConfiguration->secondSolenoidPin = Gpio::Unassigned;
	
//CAN 1 bus overwrites
	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled = true;
	engineConfiguration->canSleepPeriodMs = 50;
	engineConfiguration->canBaudRate = B500KBPS;

//SPI2 for on-board EGT
	engineConfiguration->is_enabled_spi_2 = true;
	// MOSI not needed, we have one-way communication here
	engineConfiguration->spi2misoPin = Gpio::B14;
	engineConfiguration->spi2sckPin = Gpio::B13;
	engineConfiguration->max31855_cs[0] = Gpio::B12;
	engineConfiguration->max31855spiDevice = SPI_DEVICE_2;

//SD card is located on SDIO interface
	engineConfiguration->isSdCardEnabled = true;

// Disable ETBs
//	engineConfiguration->etbFunctions[0] = dc_function_e::DC_None;
//	engineConfiguration->etbFunctions[1] = dc_function_e::DC_None;
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}

