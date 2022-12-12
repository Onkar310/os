#!/bin/bash

read -p "Enter number : " int
int2=$int
echo "Factorial without recurion : "
fact=1


while [ $int -gt 0 ]
do
	fact=$(( $fact *  $int ))
	int=$(( $int-1 ))
done

echo $fact

echo "Factorial using recursion: "

fact(){
n=$1

if [ $1 -le  1 ]
then
	echo 1;
else
	last=$( fact $(( $1 - 1)) )
	echo $(( $last * $1 ))
fi
}

fact $int2

echo $factorial

