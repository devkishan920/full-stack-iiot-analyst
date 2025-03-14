#!/bin/bash

# 7. Write a script to check entered number is armstrong number or not.

read -p "Enter a number for Armstrong check : " num

temp=$num
digit=0
n=0
sum=0

while [[ $temp -gt 0 ]]
do
	temp=$((temp/10))
	n=$((n+1))
done

temp=$num

while [[ $temp -gt 0 ]]
do
	digit=$((temp%10))
	temp=$((temp/10))
	sum=$((sum + digit**n))
done


if [[ $sum -eq $num ]]
then
	echo "Armstrong"
else
	echo "Not Armstrong"
fi
	 
