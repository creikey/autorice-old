#!/bin/bash

printf "Installing kde... |\n"
pacman -S plasma kde-applications
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> pacman exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Installing sddm (login manager)... |\n"
pacman -S sddm sddm-kcm
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> pacman exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

exit 0