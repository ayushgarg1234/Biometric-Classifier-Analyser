#!/bin/sh
if [ -z "$1" ]
then
    echo "No data file provided as an argument"
else 
    file=$1
    echo "Data File is $file"
    ./EER/eer $file
    ./crr $file
fi
