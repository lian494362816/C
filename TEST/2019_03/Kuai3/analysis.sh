#!/bin/sh

FOLDER=.
for file_a in ${FOLDER}/*.txt; do  
    echo -n $file_a
    echo -n "   "
    ./do.sh $file_a | tail -1 
done 
