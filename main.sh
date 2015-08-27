#!/bin/sh
if [ -z "$1" ]
then
    echo "No data file provided as an argument"
else 
    #if [ -z "`ls|grep $1`" ]
    if [ ! -r "$1" ]
    then
        echo "File Not found or not readable"
    else
        file=$1
        echo "Data File is $file"
        ./eer $file
        ./crr $file
    fi
fi
