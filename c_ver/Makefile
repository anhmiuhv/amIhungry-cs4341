CXXFLAGS=-std=gnu++11
all: main.o dictionary.o node.o tree.o
	g++ main.o dictionary.o node.o tree.o -o main -pthread 
main: main.cpp
	g++ -c main.cpp 
dictionary: dictionary.cpp dictionary.h
	g++ -c dictionary.cpp
node: node.cpp node.h
	g++ -c node.cpp
tree: tree.cpp tree.h
	g++ -c tree.cpp
