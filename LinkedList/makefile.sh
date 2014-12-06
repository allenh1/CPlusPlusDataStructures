#!/bin/sh


g++ -ggdb -c Node.cpp -o Node.o
g++ -ggdb -c main.cpp -o main.o
g++ -ggdb -o LinkedList Node.o main.o

rm -f Node.o main.o