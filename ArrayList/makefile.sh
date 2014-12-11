#!/bin/sh
g++ -ggdb -c ArrayList.cpp -o ArrayList.o
g++ -ggdb -c main.cpp -o main.o
g++ -ggdb -o ArrayList ArrayList.o main.o
rm *.o
