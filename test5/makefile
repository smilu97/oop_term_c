CC=g++
FF=-std=c++11
ADP=../adbook/adbook.o
all: build

build:
	rm -rf obj
	mkdir obj
	$(CC) $(FF) -o obj/main.o -c main.cc
	$(CC) $(FF) -o out obj/main.o $(ADP)