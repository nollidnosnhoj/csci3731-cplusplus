all:main

Angle.o: Angle.cc Angle.h
	g++ -c -Werror Angle.cc

Log.o: Log.cc Log.h
	g++ -c -Werror Log.cc

main.o: main.cc Angle.h Log.h
	g++ -c -Werror main.cc

main: main.o Angle.o Log.o
	g++ -o main main.o Angle.o Log.o