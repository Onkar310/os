#!/bin/bash

echo "enter maximum number"
read n

# taking input from user
echo "enter Numbers in array:"
for (( i = 0; i < $n; i++ ))
do
    read nos[$i]
done

#printing the number before sorting
echo "Numbers in an array are:"
for (( i = 0; i < $n; i++ ))
do
	echo $((nos[$i]))
done

# Now do the Sorting of numbers
for (( i = 0; i < $n ; i++ ))
do
	for (( j =0 ; j<$n-i-1; j++ ))
    do
	    if [ ${nos[$j]} -gt ${nos[$((j+1))]}  ]; then
        t=${nos[$j]}
	nos[$j]=${nos[$((j+1))]}
	nos[$((j+1))]=$t
        fi
    done
done

# Printing the sorted number
echo -e "\nSorted Numbers "
for (( i=0; i < $n; i++ ))
do
    echo ${nos[$i]}
done
