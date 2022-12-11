#!/bin/bash
echo "Enter input string" 
read string

echo $string > ip.txt
read -p  "Enter string to be searched: " substring


echo -n $string | grep -Fo $substring | wc -l 
echo 
output=$(grep -c  $substring ip.txt)

echo $output

