#!/bin/bash

# 5. Write a script to create calculator(/,*,-,+)

read -p "Enter first number : " n1
read -p "Enter second number : " n2
read -p "Enter the operator : " operator

if [[ $operator == '+' ]]
then
	echo $((n1+n2))

elif [[ $operator == '-' ]]
then
	echo $((n1-n2))
	
elif [[ $operator == '*' ]]
then
	echo $((n1*n2))

else 
	echo "scale=2;$n1/$n2" | bc
fi
