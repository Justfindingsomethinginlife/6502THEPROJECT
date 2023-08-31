#! /bin/bash

gcc -c ../pwd/source.c -o source.o
gcc -c ../IST/ist.c -o ist.o
gcc -c main.c -o main.o
gcc -o main main.c -L. ist.o source.o
