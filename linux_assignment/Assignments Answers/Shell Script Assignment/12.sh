#!/bin/bash

# 12. write a program for palindrome using function.

check_palindrome()
{
	local num=$1
	local temp=$num
	local digit=0
	local rev_n=0

	while [[ $temp -gt 0 ]]
	do
		digit=$((temp%10))
		temp=$((temp/10))
		rev_n=$((rev_n*10+digit))
	done

	if [[ $rev_n -eq $num ]]
	then
		echo "Palindrome"
	else
		echo "Not Palindrome"
	fi	
}

check_palindrome 131
