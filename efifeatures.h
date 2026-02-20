/**
 * @file efifeatures.h
 * @brief EFI features configuration for DevEBox F407VGT6
 * 
 * This file contains feature-specific configuration overrides
 * for the custom DevEBox F407VGT6 board.
 */

#ifndef EFI_FEATURES_H
#define EFI_FEATURES_H

// Enable file logging (required for SD card support)
#define EFI_FILE_LOGGING				TRUE

// Enable SDIO SD card support
#define EFI_SDC_DEVICE				SDCD1

#endif /* EFI_FEATURES_H */
