#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Usage: $0 <number_of_integers> <number_of_tests>"
	exit 1
fi

SIZE=$1
TESTS=$2
TOTAL=0
MAX=0
MIN=999999

for ((i=1; i<=TESTS; i++)); do
	numbers=()
	while [ ${#numbers[@]} -lt $SIZE ]; do
		num=$((RANDOM % 1000))
		if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
			numbers+=($num)
		fi
	done

	numbers_str="${numbers[@]}"

	# echo "Test $i: $numbers_str"
	# ./push_swap_output $numbers_str
	COUNT=$(./push_swap $numbers_str | wc -l | tr -d ' ')
	CHECKER=$(./push_swap $numbers_str | ./checker_linux $numbers_str)

	TOTAL=$((TOTAL + COUNT))
	if [ $COUNT -gt $MAX ]; then MAX=$COUNT; fi
	if [ $COUNT -lt $MIN ]; then MIN=$COUNT; fi
	
	echo "Test $i: $COUNT moves - $CHECKER"
done

AVERAGE=$((TOTAL / TESTS))
echo "----------------------------------------"
echo "Results for size $SIZE:"
echo "Average: $AVERAGE"
echo "Min: $MIN"
echo "Max: $MAX"