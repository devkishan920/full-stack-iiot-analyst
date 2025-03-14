#!/bin/bash

# 11. write a program for armstrong using function

check_armstrong()
{
	local num=$1 # assigning first argument passed to function
	local sum=0
	local digit=0
	local temp=$num
	local n=${#num} # determines number of digits in given number
	while [[ $temp -gt 0 ]]
	do
		digit=$((temp%10))
		temp=$((temp/10))
		sum=$((sum+digit**n))
	done

	if [[ $sum -eq $num ]]
	then
		echo "Armnstrong (Narcissistic Number)"
	else
		echo "Not Armstrong"
	fi
}

read -p "Enter a number for Armstrong check : " num
check_armstrong $num

