#!/bin/bash

network-online() {
  ping -c 1 www.google.com &> /dev/null
  echo "$?"
}

set-up-network() {
  ipinfo="$(ip link)"
  printf "__\n$ipinfo\n--\n"
  while :
  do
    read -p "Enter desired interface: " interface
    printf "\nSetting interface $interface..."
    if [[ $ipinfo = *"$interface"* ]]; then
      printf "OK!\n"
      break;
    else
      printf "FAIL!\n> Could not find $interface in ip link\n"
    fi
  done
  printf "Writing ${interface}.network file..."
  echo -e -n "\n[Match]\nname=en*\n[Network]\nDHCP=yes\n" >> /etc/systemd/network/${interface}.network
  if [ ! -f /etc/systemd/network/${interface}.network ]; then
    printf "FAIL!\n> Could not write to file ${interface}.network in /etc/systemd/network\n"
  else
    printf "OK!\n"
  fi
  printf "Restarting systemd-networkd...\n"
  systemctl restart systemd-networkd
  err="$?"
  if [ "$err" != "0" ]; then
    printf "FAIL!\n> Failed to restart with exit code $err\n"
  else
    printf "OK!\n"
  fi
  printf "Enabling systemd-networkd..."
  systemctl enable systemd-networkd
  err="$?"
  if [ "$err" != "0" ]; then
    printf "FAIL!\n> Failed to enable systemd-networkd with exit code $err\n"
  else
    printf "OK!\n"
  fi
  printf "Adding nameserver to /etc/resolv.conf..."
  echo -e -n "\nnameserver 8.8.8.8\nnameserver 8.8.4.4\n" >> /etc/resolv.conf
  if [ ! -f /etc/resolv.conf ]; then
    printf "FAIL!\n> File /etc/resolv.conf does not exist\n"
  else
    printf "OK!\n"
  fi
}

center-text() {
  columns=$(tput cols)
  if [ "$1" == "" ]; then
    while read line; do
      printf "%*s\n" $(((${#line}+$columns)/2)) "$line"
    done
  else
    printf "%*s\n" $(((${#1}+$columns)/2)) "$1"
  fi
}

paint-str() {
  if [ "$1" == "" ]; then
    return
  fi
  x=$(tput cols)
  charwidth=${#1}
  while [ "$x" -gt "$charwidth" ]; do
    printf "$1"
    x=$((x-charwidth))
  done
  i=0
  while [ "$x" -gt "-1" ]; do
    char=$(expr substr "$1" $i 1)
    printf "$char"
    i=$((i+1))
    x=$((x-1))
  done
  printf "\n"
}

update-packages() {
  yes | pacman -Syu | tee &> "update.log" | grep "#"
  exit "${PIPESTATUS[1]}"
}

install-i3() {
  yes | pacman -S i3-gaps i3-wm i3blocks i3lock i3status 2>installi3.log | grep install
  exit "${PIPESTATUS[1]}"
}

open-log() {
  printf "Dumping logfile '$1'..."
  if [ ! -f "$1" ]; then
    printf "FAIL!\n> Log file '$1' doesn't exist"
  else
    printf "OK!\n"
    cat "$1"
  fi
}

printf "\n"
center-text "Setting up a cricey machine"
paint-str "-"
center-text "-- INFO --"
paint-str "-"
center-text "A string of %% means start and end of a debug log in a separate command\n"
center-text "Things that I'm doing end with a ... until they're completed\n"
center-text "After the thing is done, I either print 'OK!' or 'FAIL!'\n"
center-text "In case of FAIL!, on a newline I will print '> ' then the cause of failure\n"
paint-str "="
center-text "-! BEGIN !-"
paint-str "-"
paint-str "="
printf "\n\n"
printf "Checking network..."
if [ "$(network-online)" != "0" ]; then
  printf "FAIL!\n> Setting up network\n"
  set-up-network
else
  printf "OK!\n"
fi

printf "Update packages? "
read -n1 ans
printf "\n"
if [ "$ans" == "y" ]; then
  printf "Updating packages..."
  `update-packages`
  err="$?"
  if [ "$err" != "0" ]; then
    printf "FAIL!\n> Exited with error code $err\n"
    printf "Show the log? "
    read -n1 ans
    if [ "$ans" == "y" ]; then
      open-log "update.log"
    fi
    exit 1
  else
    printf "OK!\n"
  fi
fi

printf "Installing i3..."
`install-i3`
err="$?"
if [ "$err" != "0" ]; then
  printf "FAIL!\n> Exited with error code $err\n"
  printf "Show the log? "
  read -n1 ans
  if [ "$ans" == "y" ]; then
    open-log "installi3.log"
  fi
  exit 1
else
  printf "OK!\n"
fi