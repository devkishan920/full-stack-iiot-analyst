#!/bin/bash

# 18. Find Lowest element in array

arr=()

for((i=0; i<10; i++))
do
	read -p "Enter element $((i+1)) : " arr[$i]
done
echo

smallest=${arr[0]}

for((i=1; i<10; i++))
do      
        if [[ ${arr[$i]} -lt $smallest ]]
	then
		smallest=${arr[$i]}
	fi
done


echo -n "Smallest element is : "
echo $smallest


