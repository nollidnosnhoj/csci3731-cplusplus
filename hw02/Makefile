all: main

expo.o: expo.cc expo.h
	g++ -c -Werror expo.cc
	
main.o: main.cc expo.h
	g++ -c -Werror main.cc
	
main: main.o expo.o
	g++ -o main main.o expo.o