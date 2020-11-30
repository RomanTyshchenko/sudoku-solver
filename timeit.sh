#!/bin/bash

ALL_PUZZLES='all_puzzles.txt'
rm $ALL_PUZZLES

for f in puzzles/* 
do 
    echo $f >> $ALL_PUZZLES
    cat $f >> $ALL_PUZZLES 
done

echo "Compile..."
g++ src/cpp/solve_many.cpp -o cpp_not_opt
g++ -O2 src/cpp/solve_many.cpp -o cpp_opt

echo "Run C++ optimized"
./cpp_opt < $ALL_PUZZLES

echo "Run C++ NOT optimized"
./cpp_not_opt < $ALL_PUZZLES

echo "Run Python3"
python3 src/solve_all.py < $ALL_PUZZLES

echo "Let's call it a day!"

