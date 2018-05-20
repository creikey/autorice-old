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

printf "Checking network..."
if [ "$(network-online)" != "0" ]; then
  printf "FAIL!\n> Setting up network\n"
  set-up-network
else
  printf "OK!\n"
fi