#!/bin/bash

# 4. Write a script check entered password is correct or not.

read -p "Enter your passwrod : " pass

if [ $pass -eq 1234 ]
then
	echo "Access Granted"
else
	echo "Access Denied"
fi

if [[ pass -eq 1234 ]]
then
	echo "Access Granted"
else
	echo "Access Denied"
fi

