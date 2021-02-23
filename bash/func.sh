#!/bin/sh

zz=8

function sub_test_params()
{

    echo 'zz = '" ""${zz}"
    unset zz;
}

function test_params()
{
    echo '$# = '" ""$#"
    echo $1
    echo 'zz = '" ""${zz}"
    local zz=9
    echo 'zz = '" ""${zz}"
    
    sub_test_params

    if test ${zz-haha} = "haha";
    then
        echo "zz is not set"
    else
        echo "zz is set" "zz = ${zz}"
    fi
}

test_params zz

# if test ${bb-haha} = haha;
# then
#     echo "bb is not set"
# else
#     echo "bb is set" "bb = ${bb}"
# fi


if test ${zz-haha} = "haha";
then
    echo "zz is not set"
else
    echo "zz is set" "zz = ${zz}"
fi

function test_null()
{
    echo '$#'" = ${#}"
    return
}

zz=""
test_null ""
test_null "${zz}"

echo $IFS


#echo $(cat quote.sh)
echo "$-"
file_pattern=[fp]*

echo ${file_pattern}

ls ${file_pattern}
#ls ${file_pattern}