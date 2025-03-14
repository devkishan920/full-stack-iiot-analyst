#!/bin/bash

# 19. Find Greatest element in array

arr=()

for((i=0; i<10; i++))
do
	read -p "Enter element $((i+1)) : " arr[$i]
done
echo

greatest=0

for((i=0; i<10; i++))
do      
        if [[ ${arr[$i]} -gt $greatest ]]
	then
		greatest=${arr[$i]}
	fi
done


echo -n "Smallest element is : "
echo $greatest


