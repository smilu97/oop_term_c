CC=g++
FF=-std=c++11
all: build

makeObj: comparator.cc unit.cc manager.cc
	rm -rf obj
	mkdir obj
	$(CC) $(FF) -o obj/comparator.o -c comparator.cc
	$(CC) $(FF) -o obj/unit.o -c unit.cc
	$(CC) $(FF) -o obj/manager.o -c manager.cc