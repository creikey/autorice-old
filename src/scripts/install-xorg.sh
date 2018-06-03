#!/bin/bash

printf "Installing xorg and xorg server... |\n"
pacman -S xorg xorg-server
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> pacman exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

exit 0