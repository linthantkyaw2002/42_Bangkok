#!/bin/bash

# Architecture
arch=$(uname -a)

# CPU physical
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# CPU virtual
cpuv=$(grep -c "processor" /proc/cpuinfo)

# RAM
ram_total=$(free --mega | awk '$1=="Mem:" {print $2}')
ram_use=$(free --mega | awk '$1=="Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1=="Mem:" {printf("%.2f", $3/$2*100)}')

# Disk
disk_total=$(df -m | grep "^/dev/" | grep -v "/boot/" | awk '{total += $2} END {printf "%.1f", total/1024}')
disk_use=$(df -m | grep "^/dev/" | grep -v "/boot/" | awk '{use += $3} END {printf use}')
disk_percent=$(df -m | grep "^/dev/" | grep -v "/boot/" | awk '{use +=  $3}; {total += $2} END {printf "%d", use/total*100}')

# CPU load
cpul=$(vmstat 1 4 | tail -1 | awk '{print $15}')
cpu_fin=$(awk "BEGIN {printf \"%.1f\", 100 - $cpul}")

# Last boot
lb=$(who -b | awk '$1=="system" {print $3 " " $4}')

# LVM
lvmu=$(if [ $(lsblk | grep -c "lvm") -gt 0 ]; then echo yes;else echo no; fi)

# TCP
tcpc=$(ss -ta state established | wc -l)

# User log
# ulog=$(users | wc -w)
# For unique user
ulog=$(users | tr  " " "\n" | sort -u | wc -l)

# Network
ip=$(hostname -I | awk '{printf $1}')
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# Sudo
cmnd=$(grep "COMMAND=" /var/log/sudo/sudo_config | wc -l)

# Output
wall "Arhitecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total}Gb ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
