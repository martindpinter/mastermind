#!/bin/bash

for f in *.cpp; do
	g++-4.8 -std=c++11 -c $f -o $f.o
done

g++ *.o -o mastermind
