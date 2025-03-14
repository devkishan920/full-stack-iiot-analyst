#!/bin/bash

# 6. Write a script to check entered number is palindrome number or not.

read -p "Enter a number : " num

temp=$num
rev_n=0

while [ $temp -gt 0 ]
do

	digit=$((temp%10))
	temp=$((temp/10))
	rev_n=$((rev_n*10+digit))
done

# don't know but, if indents were not working as expected 

if [ $rev_n -eq $num ]
then
	echo "Palindrome"
else
	echo "Not Palindrome"
fi


# 1. Used `$` to reference variables correctly.
# 2. Changed `{}` to `do` and `done` for the while loop.
# 3. Initialized `rev_n` to 0 before starting the loop.
# 4. Used `-gt` (greater than) for the comparison in the while loop condition.
# 5. Removed single quotes around variables in the final `if` condition.


