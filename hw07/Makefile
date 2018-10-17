all:main

angle.o: angle.cc angle.h
	g++ -c -Werror angle.cc

main.o: main.cc angle.h
	g++ -c -Werror main.cc

main: main.o angle.o
	g++ -o main main.o angle.o