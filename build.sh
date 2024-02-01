#!/bin/bash
if [ ! -d "./bin" ]; then 
    mkdir bin
fi

gcc -c src/main.c -o bin/main.o
gcc -c src/functions.c -o bin/functions.o
gcc bin/functions.o bin/main.o -o bin/main
