#!/bin/bash

echo "Compiling generator"

g++ -std=c++11 -O2 random.cpp -o random

echo "Generating input"

out="../autotest/tests.txt"

echo "max_cpu_seconds=3

files=bstree_difference.c

compilers=[['gcc']]

compiler_args=-O2 -Wall -Werror -g test_bstree_difference.c bstree_difference.c bstree.c -o test_bstree_difference

command=./test_bstree_difference

show_actual_output = False
show_expected_output = False
show_diff = False
show_reproduce_command = False
show_stdin = False
" > $out

echo     "1 stdin=\"11 7 4 20 18 23 30\"" >> $out
echo     "2 stdin=\"11 7 4 20 13 23 30\"" >> $out
echo     "3 stdin=\"2308940 9413\""       >> $out
echo     "4 stdin=\"9413 2308940\""       >> $out
echo     "5 stdin=\"1 4 7 10 12\""        >> $out
echo     "6 stdin=\"12 9 6 3 1\""         >> $out
echo -n  "7 stdin=\"" >> $out && ./random 0.0 1.0 20     >> $out && echo "\"" >> $out
echo -n  "8 stdin=\"" >> $out && ./random 0.0 0.6 20     >> $out && echo "\"" >> $out
echo -n  "9 stdin=\"" >> $out && ./random 0.9 1.0 20     >> $out && echo "\"" >> $out
echo -n "10 stdin=\"" >> $out && ./random 0.0 1.0 1000   >> $out && echo "\"" >> $out
echo -n "11 stdin=\"" >> $out && ./random 0.0 0.6 1000   >> $out && echo "\"" >> $out
echo -n "12 stdin=\"" >> $out && ./random 0.9 1.0 1000   >> $out && echo "\"" >> $out
echo -n "13 stdin=\"" >> $out && ./random 0.0 1.0 50000 >> $out && echo "\"" >> $out
echo -n "14 stdin=\"" >> $out && ./random 0.0 0.6 50000 >> $out && echo "\"" >> $out
echo -n "15 stdin=\"" >> $out && ./random 0.9 1.0 50000 >> $out && echo "\"" >> $out

rm random

echo "Generating output"

cd ../solution
autotest.sh bstree_difference --generate_expected_output > temp.txt
cp temp.txt $out
rm temp.txt
cd ../generator

