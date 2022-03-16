#!/bin/bash
# bat.sh displays the battery capacity (assumes two batteries)

capacity1=$(cat /sys/class/power_supply/BAT0/capacity)
printf "Battery #1 ($capacity1)%%: ["
for i in $(seq $capacity1); do
	printf "#"
done
for i in $(seq $((100-$capacity1)) ); do
	printf "-"
done
printf "]\n"

capacity2=$(cat /sys/class/power_supply/BAT1/capacity)
printf "Battery #2 ($capacity2)%%: ["
for i in $(seq $capacity2); do
	printf "#"
done
for i in $(seq $((100-$capacity2)) ); do
	printf "-"
done
printf "]\n"

