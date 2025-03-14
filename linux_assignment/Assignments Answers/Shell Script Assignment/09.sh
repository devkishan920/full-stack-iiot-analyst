#!/bin/bash

#9. Write a script to find number of palindrome number in given range like 1 to 10000.

digit=0
temp=0
count=0
# rev_n=0

for ((i=0; i<=10000; i++))
do
    rev_n=0
    temp=$i

    while [[ $temp -gt 0 ]]
    do
      digit=$((temp%10))
      temp=$((temp/10))
      rev_n=$((rev_n*10+digit))
    done

    temp=$i

    if [[ $rev_n -eq $temp ]]
    then
            count=$((count+1))
    fi  
done

echo "Total Number of Plaindrome number(s) are $count."





