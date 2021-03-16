#!/bin/sh
var=2

function z1()
{

    echo $FUNCNAME $var
    local var=0
    echo $FUNCNAME $var

}

function z0()
{

    echo $FUNCNAME $var
    local var=1
    unset var
    z1
    echo $FUNCNAME $var

}

z0