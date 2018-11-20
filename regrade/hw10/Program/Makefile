all:main

Exception.o: Exception.cc Exception.h
	g++ -c -Werror Exception.cc

Log.o: Log.cc Log.h
	g++ -c -Werror Log.cc

FlippyFish.o: FlippyFish.cc FlippyFish.h
	g++ -c -Werror FlippyFish.cc

DrunkenFish.o: DrunkenFish.cc DrunkenFish.h
	g++ -c -Werror DrunkenFish.cc

Fish.o: Fish.cc Fish.h
	g++ -c -Werror Fish.cc

main.o: main.cc Fish.h Log.h
	g++ -c -Werror main.cc

main: main.o Fish.o Log.o Exception.o DrunkenFish.o FlippyFish.o
	g++ -o main main.o Fish.o Log.o Exception.o DrunkenFish.o FlippyFish.o