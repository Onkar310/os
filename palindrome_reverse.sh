#!/bin/bash

read -p "Enter number: " number
ans=""
num=$number
while [ $number -gt 0 ]
do
	n=$(( $number % 10 ))
	ans=$(( ${ans}${n} )) 
	number=$(( $number/10 ))
done
echo "Reverse number :"

echo $ans

if [ $ans -eq $num ]
then
	echo "Palindrome"
else
	echo "Not palindrome"
fi



