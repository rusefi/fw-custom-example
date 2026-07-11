#!/bin/bash

set -e

SCRIPT_DIR=$(dirname "$0")

cd $SCRIPT_DIR/../ext/rusefi/unit_tests/

# This full path of the unit tests directory
FDIR=$(pwd -P)

MI="../../../meta-info.env"

	if [ -f "$FDIR/$MI" ]; then
		true
		# If the file exists relative to our current directory, get the full path
	elif [ -f "$MI" ]; then
		MI=$(realpath "$MI")
	else
		echo "Could not find $MI"
		exit 1
	fi

source ../firmware/config/boards/common_script_read_meta_env.inc "$MI"

# Pin META_OUTPUT_ROOT_FOLDER to the board's own generated/ folder (BOARD_DIR/generated) so that
# "where we generate" and "where we include from" is the same folder no matter how the caller
# (CI workflow or local shell) derived the variable.
if [ -n "${BOARD_DIR:-}" ] && [ -d "$BOARD_DIR/generated" ]; then
	META_OUTPUT_ROOT_FOLDER="$(realpath --relative-to ../firmware "$BOARD_DIR/generated")/"
	export META_OUTPUT_ROOT_FOLDER
	echo "make_unit_tests.sh META_OUTPUT_ROOT_FOLDER pinned to board generated: $META_OUTPUT_ROOT_FOLDER"
fi

# When META_OUTPUT_ROOT_FOLDER points outside the rusefi checkout (custom board layout),
# the generated headers directory is not on the standard CONTROLLERS_INC path.
# Inject it via UINCDIR so the PCH and all sources can find rusefi_generated_*.h.
if [ -n "${META_OUTPUT_ROOT_FOLDER:-}" ]; then
	UINC="${META_OUTPUT_ROOT_FOLDER}controllers/generated"
	make -j$(nproc) config UINCDIR="$UINC" "$@"
	# Regenerate live documentation/enums so the generated headers in the board generated/ folder
	# match the current rusefi sources + board prepend.txt before we compile against them.
	make -j$(nproc) docs-enums UINCDIR="$UINC" "$@"
	make -j$(nproc) UINCDIR="$UINC" "$@"
else
	make -j$(nproc) "$@"
fi
