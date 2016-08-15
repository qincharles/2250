all: main

main: main.o Stack.o
	g++ -o main main.o Stack.o

main.o: main.cpp
	g++ -c main.cpp

Stack.o: Stack.cpp Stack.h
	g++ -g -c Stack.cpp

clean:
	rm -rf *o main
