#!/bin/bash

printf "Installing gnome... |\n"
pacman -S gnome gnome-extra gnome-tweaks
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> pacman exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Starting gdm.service... |\n"
systemctl start gdm.service
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> systemctl start exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Enabling gdm.service... |\n"
systemctl enable gdm.service
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> systemctl enable exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

exit 0