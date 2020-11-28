#!/bin/bash

for f in puzzles/*; 
do 
	echo $f; 
	python3 src/main.py < $f; 
done
