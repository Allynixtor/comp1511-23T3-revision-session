#!/bin/sh

## Installs CSE autotest framework in /usr/local/bin/autotest

## Run this script from the directory containing this script.

source "./config.sh"
source "./cleanup.sh"

if [ ! -e "$INSTALL_DIR" ]; then
    echo "Creating new directory $INSTALL_DIR."
    mkdir -p "$INSTALL_DIR"
fi

if [ ! -e "$INSTALL_DIR/autotest" ]; then
    echo "Downloading autotest library..."
    sudo git clone "https://github.com/COMP1511UNSW/autotest.git" "$INSTALL_DIR/autotest"
    chmod +x "$INSTALL_DIR/autotest/autotest.py"
fi

## $INSTALL_DIR needs to be in the PATH for the autotest script to work.
sudo ln -s "$(pwd)/autotest.sh" "$INSTALL_DIR/autotest.sh"
