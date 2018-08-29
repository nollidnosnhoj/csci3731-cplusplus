all: main

factorial.o: factorial.cc factorial.h
	g++ -c -Werror factorial.cc
	
main.o: main.cc factorial.h
	g++ -c -Werror main.cc
	
main: main.o factorial.o
	g++ -o main main.o factorial.o