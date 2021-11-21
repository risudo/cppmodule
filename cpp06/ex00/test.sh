#!/bin/bash

echo -e "0"
./convert 0

echo -e "\n42"
./convert 42

echo -e "\n2147483648"
./convert 2147483648

echo -e "\nnan"
./convert nan

echo -e "\nnanf"
./convert nanf

echo -e "\n+inf"
./convert +inf

echo -e "\n42.0f"
./convert 42.0f

echo -e "\n42.42"
./convert 42.42

echo -e "\n2.225074e-308 (double min)"
./convert 2.225074e-308

echo -e "\n1.797693e+308 (double max)"
./convert 1.797693e+308

echo -e "1f"
./convert 1f

