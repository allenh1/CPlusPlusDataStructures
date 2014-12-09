#!/bin/bash
g++ -ggdb -c ../LinkedList/Node.cpp -o Node.o
g++ -ggdb -c Stack.cpp -o stack.o 
g++ -ggdb -c main.cpp -o main.o
g++ -ggdb -o Stack stack.o main.o