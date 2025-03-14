#!/bin/bash

count=0

for j in $(seq 1 10000); # (j) is counter from 1 to 10,000
do
        temp=$j # (j) is passed to temp variable
        temp2=0 # for holding the digit
        check=0
        len=0
        a=1

        while [ $temp -ne 0 ]; do # fing the length of number
                temp=$(($temp/10))
                len=$(($len+1))
        done

        temp=$j # again initialised same temp with same (j)

        while [ $temp -ne 0 ] 
	do
                temp2=$(($temp % 10)) # got the unit digit i.e, 243%10 gives 3
                temp=$(($temp/10)) # remaing number i.e, 243/10 gives 24
                a=1
                for i in $(seq 1 $len); # for loop from 1 to len
                do
                        a=$(($a*$temp2)) # (a) is hold each digit raise to len 
                done
                check=$(($check+$a))
        done
        if [ $check == $j ]; then
                count=$(($count+1))
        fi
done
echo "number of armstrong number is $count"
