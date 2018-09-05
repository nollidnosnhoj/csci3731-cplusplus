all: main

calculator.o: calculator.cc calculator.h
	g++ -c -Werror calculator.cc
	
main.o: main.cc calculator.h
	g++ -c -Werror main.cc
	
main: main.o calculator.o
	g++ -o main main.o calculator.o