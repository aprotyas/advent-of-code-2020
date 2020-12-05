#!/usr/bin/env bash

numarg=$#
day=$1

if [[ numarg -eq 0 ]]; then
    echo "Building all executables!"
    make -C build
elif [[ numarg -eq 1 ]]; then
    echo "Building day ${day}!"
    if [[ day -lt 10 ]]; then
        exe="0$day"
    else
        exe="$day"
    fi
    make -C build/day_${exe}
else
    echo "Too many arguments!"
fi
