#!/usr/bin/env bash

make clean
make
./main
ret=$?
if [ $ret != 0 ]; then
    echo "Miscompiled, returned $ret"
    exit 1
fi
