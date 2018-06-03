#!/bin/bash

SUDOERS_FILE="scripts/sudoers"

printf "Installing sudo... |\n"
pacman -S sudo
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> pacman exited with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Verifying sudoers file... |\n"
visudo -c -f "${SUDOERS_FILE}"
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> sudoers file failed to verify with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Installing sudoers file..."
cp "${SUDOERS_FILE}" /etc/sudoers
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> cp failed with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Creating new user... |\n"
printf "Username? "
read -n30 USER_NAME
if [ "$USER_NAME" == "" ]; then
    printf "Username must not be blank\n"
    exit 1
fi
useradd -m -G wheel "$USER_NAME"
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> useradd failed with err $err\n"
    exit 1
else
    printf "OK!\n"
fi


printf "Setting user password... |\n"
passwd "$USER_NAME"
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> passwd failed with err $err\n"
    exit 1
else
    printf "OK!\n"
fi

exit 0