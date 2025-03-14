#!/bin/bash

#1. Write a script to check entered character is vowel or consonant.

read -p "Enter a character : " character

if [[ $character == "a" || $character == "e" || $character == "i" ||  $character ==  "o" ||  $character == "u" ]]
then
	echo "Vowel"
else
	echo "Consonant"
fi
