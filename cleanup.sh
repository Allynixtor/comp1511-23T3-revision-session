#!/bin/sh

## Removes CSE autotest framework $INSTALL_DIR/autotest, and symlink to ./autotest.sh

source "./config.sh"

if [ -d "$INSTALL_DIR/autotest" ]; then
    echo "Deleting $INSTALL_DIR/autotest"
    sudo rm -rf "$INSTALL_DIR/autotest"
fi

if [ -e "$INSTALL_DIR/autotest.sh" ]; then
    echo "Deleting $INSTALL_DIR/autotest.sh"
    sudo rm -f "$INSTALL_DIR/autotest.sh"
fi