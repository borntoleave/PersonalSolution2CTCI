#!/bin/bash
# usage: ./test.sh <your.cpp> <your arguments for the cpp>
g++ $1 -o exe.x
./exe.x ${@:2}

