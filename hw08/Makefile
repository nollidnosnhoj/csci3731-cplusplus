all:main

Log.o: Log.cc Log.h
	g++ -c -Werror Log.cc

main.o: main.cc Log.h
	g++ -c -Werror main.cc

main: main.o Log.o
	g++ -o main main.o Log.o