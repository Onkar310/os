#!/bin/bash
echo "Enter any number: "

read int

i=2
count=0
flag=1
while  [ $i -lt $int  ]
do
	if (( $(( int  %  i)) == 0))
	then 
		((count++))
	fi
	((i++))
done


if [ $count -ge $flag  ]
then 
	echo "Not prime"
else 
	echo "Prime"
fi


n=$int
ans=0

while [ $n -ne 0 ]
do 
	x=$(($n%10))
	ans=$(($ans * 10 + $x ))
	n=$(( $n/10)) 
done

echo "Reverse is $ans"

