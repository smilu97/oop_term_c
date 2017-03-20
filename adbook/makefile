CC=g++
FF=-std=c++11
all: makeObj

makeObj: comparator.cc unit.cc manager.cc
	rm -rf obj
	mkdir obj
	$(CC) $(FF) -o obj/comparator.o -c comparator.cc
	$(CC) $(FF) -o obj/unit.o -c unit.cc
	$(CC) $(FF) -o obj/manager.o -c manager.cc
	ld -r -o adbook.o obj/comparator.o obj/unit.o obj/manager.o