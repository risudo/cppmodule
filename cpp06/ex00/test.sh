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
test 11ff
test 0.0000000000000000000000000000000000000011754943508222875079687365372222456778186655567720875215087517062784172594547271728515625f

echo -e $BLUE "--- char case ---" $RESET
test !
test a
test "\~"

echo -e $BLUE "--- int case ---" $RESET
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
test +inff
test -inff
test 0.000000000000000000000000000000000000011754943508222875079687365372222456778186655567720875215087517062784172594547271728515625f

echo -e $BLUE "--- double case ---" $RESET
test 0.0
test nan
test +inf
test -inf
test 0.00000000000000000000000000000000000000000000140129846432481707092372958328991613128026194187651577175706828388979108268586060148663818836212158203125

