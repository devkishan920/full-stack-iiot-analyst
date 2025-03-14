# 9. Write a password security system in Makefile ?

read -p  "Enter the password : " pass

if [[ ${pass} -eq 1234 ]]
then
	echo "Access Granted"
else
	echo "Access Denied"
fi
