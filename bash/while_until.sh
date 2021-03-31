#!/bin/sh

#test cmd  continue to excute loop if command exit status is zero, 
#otherwise skip the loop and continue to excute next command 

while test -f while_until.sh; do
    echo "i enter while"
    sleep 1
    break
done


# command exit with zero
a=1
until let "--a"; do
    echo "i enter while"
    sleep 2
done


a=1
b=1
a="1"
if test "${a}" = "1";then
    echo ${a} is null
fi

for ((i = 1; i < 10; i++))
do
    echo "sdsdssdsdsd"
done


for val in $(seq 1 3)
do
    echo "hi"
done
[[ 'tanghan.ye@qq.com' =~ [A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,} ]]

echo $?
regex='[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}'
if [[ 'tanghan.ye@qq.com' =~  ${regex} ]] ;then
    echo 'it is email'
fi

var='sdsdsdsdsdsd---china tele ----'
pattern='*china tele ----';
[[ ${var} == ${pattern} ]]
echo $?
if [[ ${var} == *"china tele ----" ]]
then
    echo ${var}
fi
if test "3" -gt "2" -a "3" -gt "2" 
then
    echo "111111111"
fi