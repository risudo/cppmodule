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

echo -e $BLUE "--- erorr case ---" $RESET
test aa
test +2147483648
test -2147483649

echo -e $BLUE "--- char case ---" $RESET
test !
test a

echo -e $BLUE "--- int case ---" $RESET
test "\~"
test +127
test +128
test -128
test -129
test 300
test 2147483647
test -2147483648

echo -e $BLUE "--- float case ---" $RESET
test 0.0f
test 2147483647f
test 2147483648f
test nanf

echo -e $BLUE "--- double case ---" $RESET
test nan
test +inf

