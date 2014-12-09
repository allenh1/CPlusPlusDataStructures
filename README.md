C++DataStructures
=================

This repository is an effort to program useful data structures in C++. Yes, they do already exist in other libraries, but it's more about my own exploration of this.

LinkedList
----------
Using the Node object, this structure links one node to the next by pointing to it. The only way to navigate this list is to go node-by-node through it until you reach a null pointer. This structure is useful because it allows one to efficiently remove/add a single index from/to the list in two assignments.

Stack
------
This is much more useful than LinkedList. Though it does indeed use LinkedList... Stack is a very simple form of list. It's basically just a LinkedList, but the access is much easier.

Compiling
---------
Each data structure has a `makefile.sh` file one uses to build. The code should build on any unix system with g++. Simply run
`chmod +x makefile.sh`
`./makefile.sh`
To build the file.