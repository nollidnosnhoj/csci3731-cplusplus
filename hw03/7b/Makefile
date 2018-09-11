all: main

swapvar.o: swapvar.cc swapvar.h
	g++ -c -Werror swapvar.cc
	
main.o: main.cc swapvar.h
	g++ -c -Werror main.cc
	
main: main.o swapvar.o
	g++ -o main main.o swapvar.o