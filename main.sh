#!/bin/sh
if [ -z "$1" ]
then
    echo "No data file provided as an argument"
else 
    #if [ -z "`ls|grep $1`" ]
    if [ ! -s "$1" ]
    then
        echo "File Not found or is empty"
    else
        file=$1
        echo "Data File is $file"
        ./eer $file
        ./crr $file
	sh stat.sh
    fi
fi
