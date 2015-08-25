#!/bin/sh
file=$1
echo "Data File is $file"
cat $file|awk -f EER_Generate.awk > EER_input.txt
