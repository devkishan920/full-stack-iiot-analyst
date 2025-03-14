#!/bin/bash

count=0

for ((j=1; j<=10000; j++)) 
do
    num=$j
    sum=0
    temp=$num
    n=0

    while [[ $temp -gt 0 ]] 
	do
        	temp=$((temp / 10))
        	n=$((n + 1))
    	done

    temp=$num
    digit=0
    

    while [[ $temp -gt 0 ]] 
	do
        	digit=$((temp % 10))
		temp=$((temp / 10))
        	sum=$((sum + digit ** n))
    	done

    if [[ $sum -eq $j ]] 
	then
        	count=$((count + 1))
    fi
done

echo "Number of Armstrong numbers between 1 and 10000 is $count"

