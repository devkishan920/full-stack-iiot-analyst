#!/bin/bash

# 16. arrange the elements in Descending order

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

temp=0

for((i=0; i<10; i++))
do
	for((j=i+1; j<10; j++))
	do
		if [[ ${arr[$i]} -lt ${arr[$j]} ]]
		then
			temp=${arr[$i]}
			arr[i]=${arr[$j]}
			arr[j]=$temp
		fi			
	done
done

echo "Elements in Descending order  are : "
 
for((i=0; i<10; i++))
do
        echo -n "${arr[$i]} "
done

echo
