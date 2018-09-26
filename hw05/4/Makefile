all:main

ppm.o: ppm.cc ppm.h
	g++ -c -Werror ppm.cc

main.o: main.cc ppm.h
	g++ -c -Werror main.cc

main: main.o ppm.o
	g++ -o main main.o ppm.o