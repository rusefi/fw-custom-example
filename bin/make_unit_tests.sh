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

make -j$(nproc) "$@"
