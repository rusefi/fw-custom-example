#!/bin/bash

set -e

SCRIPT_DIR=$(dirname "$0")

source $SCRIPT_DIR/make_unit_tests.sh

timeout 20m build/rusefi_test
