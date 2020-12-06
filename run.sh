#!/usr/bin/env bash

numarg=$#
day=$1

if [[ numarg -eq 1 ]]; then
    echo "Running day ${day}!"
    if [[ day -lt 10 ]]; then
        exe="0$day"
    else
        exe="$day"
    fi
    cd build/src/day_${exe}
    ./aoc_day${exe}
    cd ../../..
else
    echo "Too few/many arguments! Specify the day you want to run."
fi
