#!/bin/bash

# 17. add element at specific place in array

add_element()
{

	local pos=$1
	local element=$2

	if [ $pos -gt 10 ] || [ $pos -lt 1 ]
	then
		echo "Enter valid index!!!"
		exit
	else
		arr[pos-1]=$element
	fi	
}


arr=()

for((i=0; i<10; i++))
do
	read -p "Enter Element $((i+1)) : " arr[$i]
done

echo

echo "Elements are : "
for((i=0; i<10; i++))
do
        echo -n "${arr[$i]} "
done

echo

pos=0
element=0

read -p "Enter the position, element you want : " pos element
add_element $pos $element

echo "After insertion, new array is : "
for((i=0; i<10; i++))
do
        echo -n "${arr[$i]} "
done

