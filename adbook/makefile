CC=g++
FF=-std=c++11
all: makeObj

makeObj: comparator.cc unit.cc addressBook.cc phone.cc smsHistory.cc
	rm -rf obj
	mkdir obj
	$(CC) $(FF) -o obj/comparator.o -c comparator.cc
	$(CC) $(FF) -o obj/unit.o -c unit.cc
	$(CC) $(FF) -o obj/addressBook.o -c addressBook.cc
	$(CC) $(FF) -o obj/phone.o -c phone.cc
	$(CC) $(FF) -o obj/smsHistory.o -c smsHistory.cc
	ld -r -o adbook.o obj/comparator.o obj/unit.o obj/addressBook.o obj/phone.o obj/smsHistory.o