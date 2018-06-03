#!/bin/bash

SYS_MIRRORLIST="/etc/pacman.d/mirrorlist"
MIRRORLIST_URL="https://www.archlinux.org/mirrorlist/?country=US&protocol=http&protocol=https&ip_version=4&use_mirror_status=on"
MIRRORLIST_FILENAME="mirrorlist"

printf "Downloading US mirrorlist..."

curl -o "$MIRRORLIST_FILENAME" "$MIRRORLIST_URL" >/dev/null 2>&1
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> Exited with error code ${err}\n"
    exit 1
    elif [ ! -f "$MIRRORLIST_FILENAME" ]; then
    printf "FAIL!\n> mirrorlist file not found\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Locating current mirrorlist..."
if [ ! -f "$SYS_MIRRORLIST" ]; then
    printf "FAIL!\n> Failed to locate ${SYS_MIRRORLIST}\n"
    exit 1
else
    printf "OK!\n"
fi

printf "Fixing up downloaded mirrorlist..."
sed 's/^.//' "$MIRRORLIST_FILENAME" > "${MIRRORLIST_FILENAME}.new"
err="$?"
if [ "$err" != "0" ]; then
  printf "FAIL!\n> Failed to uncomment servers with err code $err\n"
  exit 1
elif [ ! -f "${MIRRORLIST_FILENAME}.new" ]; then
  printf "FAIL!\n> Cannot find output file from sed\n"
  exit 1
fi
mv "${MIRRORLIST_FILENAME}.new" "$MIRRORLIST_FILENAME"
err="$?"
if [ "$err" != "0" ]; then
  printf "FAIL!\n> Failed to move new mirrorlist into the old one with err code $err\n"
  exit 1
fi
printf "OK!\n"

printf "Moving mirrorlist..."
mv "$MIRRORLIST_FILENAME" "${SYS_MIRRORLIST}"
err="$?"
if [ "$err" != "0" ]; then
    printf "FAIL!\n> Exited with error code ${err}\n"
    exit 1
else
    printf "OK!\n"
fi
exit 0
