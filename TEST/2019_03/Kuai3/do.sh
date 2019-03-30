#!/bin/sh

make

if [ $# -lt 1 ] ;then
    echo   "no input file"
    exit
fi

./kuai3 $1 > tmp1.txt

#清空tmp2.txt
echo > tmp2.txt

while read line
do
    echo  $line | awk -F ";" '{print $1}' | awk '{if(NF>=3) print "{" $1 "," $2 "," $3"," $4 "}" "," }'  >> tmp2.txt
    echo  $line | awk -F ";" '{print $1}' | awk '{if(NF==2) print "{" $1 "," $2 "," $3 "}" "," }'  >> tmp2.txt
    # echo  $line | awk -F ";" '{print $2}' | awk '{ print "{" $1 "," $2 "," $3"," $4 "}" "," }'  >> tmp2.txt
    # echo  $line | awk -F ";" '{print $1}' | awk '{ print "{" $1 "," $2 "," $3"," $4 "}" "," }'  >> tmp2.txt
    echo  $line | awk -F ";" '{print $2}' | awk '{ print "{" $1 "," $2 "," $3"," $4 "}" "," }'  >> tmp2.txt

done < tmp1.txt

cat tmp2.txt | xargs -n2  > tmp3.xt

echo "int a[][10] = {" > array.h
cat tmp3.xt >> array.h
echo "};" >> array.h

rm tmp* 

./test

make clean

