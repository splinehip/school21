#!/bin/bash

Architecture=$(uname -a)
CPU_physical=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vCPU=$(grep "^processor" /proc/cpuinfo | wc -l)
MemTotal=$(($(grep "MemTotal" /proc/meminfo | grep -oP '\d*')/1024))
MemUsage=$(($MemTotal-$(grep "MemFree" /proc/meminfo | grep -oP '\d*')/1024))
MemPrc=$(echo "scale=2;($MemUsage/$MemTotal) * 100" | bc -l)
DiskTotal=$(lsblk -dn -o SIZE /dev/sda | grep -oP '\d*,*\d' | sed -u 's/,/./g')
DiskUsage=$(df -hl --total -t ext4 --output=fstype,used | grep "^-"\
			| grep -oP '\d*,*\d' | sed -u 's/,/./g')
DiskPrc=$(df -hl --total -t ext4 --output=fstype,pcent | grep "^-"\
			| grep -oP '\d*,*\d%$' | sed -u 's/,/./g')
CPULoad=$(top -bn1 | grep "%Cpu(s)" | grep -oP '\d*,*\d id'\
			| grep -oP '\d*,*\d' | sed -u s/,/./g)
LastBoot=$(who -b | grep -oP '\d*-*\d*-*\d* *\d*:\d*')
LVMUse="no"
if [[ $(lsblk -o type | grep "lvm" | wc -l) > 0 ]]; then LVMUse="yes"; fi
TCPConn=$(ss -tHn | grep "ESTAB" | wc -l)
UserLogged=$(who -q | grep -oP '\d*')
IPlist=$(ip -j addres)
CountSudo=$(grep "USER" /var/log/sudo/sudo.log | grep -v 'TSID' | wc -l)

echo \
"	#Architecture: $Architecture
	#CPU physical : $CPU_physical
	#vCPU : $vCPU
	#Memory Usage: ${MemUsage}/${MemTotal}MB ${MemPrc}%
	#Disk Usage: ${DiskUsage}/${DiskTotal}G ($DiskPrc)
	#CPU load: ${CPULoad}%
	#Last boot: $LastBoot
	#LVM use: $LVMUse
	#Connexions TCP : $TCPConn ESTABLISHED
	#User log: $UserLogged
$(
	for ((i = 1; $(jq .[$i] <<< $IPlist | wc -l) != 1; i++))
	do
		IP=$(jq .[$i].addr_info[0].local <<< $IPlist | sed -u s/\"//g)
		if [[ $IP == "null" ]]; then IP="Not assigned"; fi
		MAC=$(jq .[$i].address <<< $IPlist | sed -u s/\"//g)
		echo "	#Network: IP $IP ($MAC)"
	done
)
	#Sudo : $CountSudo cmd"
exit 0;
