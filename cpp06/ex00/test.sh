#!/bin/bash

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
BOLD="\033[1m"
UNDERLINE="\033[4m"
BOLD_UNDERLINE="\033[1;4m"
RESET="\033[0m"

EXECUTE="./convert"

test () 
{
    printf $GREEN
    echo "$EXECUTE $1"
    printf $RESET
    bash -c "$EXECUTE $1"
	echo ""
}

test -129
test -128
test !
test a
test "\~"
test +127
test +128
test -2147483649
test -2147483648
test 300
test 2147483647
test +2147483648
test 0.0f
test nan
test nanf
test +inf
test 2.225074e-308
test 0.1e-300

