#!/bin/bash

# 13. write a program for swaaping two values using function.

swap()
{
	local -n val1=$1
	local -n val2=$2

	val1=$((val1+val2))
	val2=$((val1-val2))
	val1=$((val1-val2))
}


read -p "Enter two numbers : " n1 n2

echo "Before swapping n1=$n1, n2=$n2"
# swap $n1 $n2 # local -n requires valid variable names—not values—to work as references.
swap n1 n2
echo "After swapping n1=$n1, n2=$n2"


<<comment
The swap Function:

The function takes two arguments by reference using local -n.

val1 and val2 are references to the variables passed to the function (e.g., n1 and n2 in this case).

It swaps the values of val1 and val2 without requiring a temporary variable by using mathematical operations:

val1 = val1 + val2

val2 = val1 - val2

val1 = val1 - val2
comment

