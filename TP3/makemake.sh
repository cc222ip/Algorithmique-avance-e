#!/bin/bash
rm makefile
echo "$1: $2 $3" >> makefile
echo "	g++ $2 $3 -o $1" >> makefile
make && ./$1
