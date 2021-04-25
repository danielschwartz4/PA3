CC=c++
CFLAGS=-c -Wall

all: kk

kk: algos.o kk.o
	$(CC) algos.o kk.o -o kk

main: main.o 
	$(CC) main.o -o main

tests: tests.o algos.o heap.o
	$(CC) tests.o algos.o heap.o -o tests

algos: algos.o heap.o
		$(CC) algos.o heap.o -o algos

tests: tests.o
		$(CC) tests.o -o tests

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp
kk.o: kk.cpp
		$(CC) $(CFLAGS) kk.cpp

algos.o: algos.cpp
		$(CC) $(CFLAGS) algos.cpp

tests.o: tests.cpp
		$(CC) $(CFLAGS) tests.cpp

heap.o: heap.cpp
		$(CC) $(CFLAGS) heap.cpp
clean: 
	rm *.o






