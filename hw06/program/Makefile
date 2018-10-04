all:main

ppm.o: ppm.c ppm.h
	g++ -c -Werror ppm.c

main.o: main.c ppm.h
	g++ -c -Werror main.c

main: main.o ppm.o
	g++ -o main main.o ppm.o -ljpeg