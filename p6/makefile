all: main

main: main.o BinaryTree.o
	g++ -o main main.o BinaryTree.o

main.o: main.cpp
	g++ -c main.cpp

BinaryTree.o:	BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp

clean:
	rm -rf *o main
