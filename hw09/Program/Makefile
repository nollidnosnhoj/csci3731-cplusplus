all:main

Log.o: Log.cc Log.h
	g++ -c -Werror Log.cc

Angle.o: Angle.cc Angle.h
	g++ -c -Werror Angle.cc

Population.o: Population.cc Population.h Fish.h
	g++ -c -Werror Population.cc

Fish.o: Fish.cc Fish.h
	g++ -c -Werror Fish.cc

main.o: main.cc Fish.h Population.h Log.h
	g++ -c -Werror main.cc

main: main.o Fish.o Population.o Angle.o Log.o
	g++ -o main main.o Fish.o Population.o Angle.o Log.o