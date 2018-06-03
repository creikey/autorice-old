#!/bin/bash

printf "Installing pacman package... |\n"
pacman -S networkmanager
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> Failed to install pacman package with err ${err}\n"
    exit 1
fi
printf "OK!\n"
printf "Enabling NetworkManager systemctl daemon... |\n"
systemctl enable NetworkManager
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> Failed to enable NetworkManager with systemctl, err ${err}\n"
    exit 1
fi
printf "OK!\n"
printf "Starting NetworkManager daemon... |\n"
systemctl start NetworkManager
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> Failed to start NetworkManager daemon, err ${err}\n"
    exit 1
fi
printf "OK!\n"
exit 0