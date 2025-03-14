#!/bin/bash

# 15. arrange the elements in Ascending order

# arr[10]

arr=() # In Bash, arrays do not require a size declaration (like arr[10]). Simply use arr without specifying its size. 

for((i=0; i<10; i++))
do
	read -p "Enter element $((i+1)) : " arr[$i]
done

echo

echo "Entered elements are : "

for((i=0; i<10; i++))
do
        echo -n "${arr[$i]} "
done

echo

temp=0

for((i=0; i<10; i++))
do
	for((j=i+1; j<10; j++))
	do
		if [[ ${arr[i]} -gt ${arr[j]} ]]
		then
			temp=${arr[i]}
			arr[i]=${arr[j]}
			arr[j]=$temp
		fi
	done
done

# Display the sorted elements
echo "Elements in Ascending order: "
for ((i=0; i<10; i++))
do
    echo -n "${arr[$i]} "
done

echo
