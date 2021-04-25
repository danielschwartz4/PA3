CC=c++
CFLAGS=-c -Wall

all: partition

partition: algos.o partition.o heap.o
	$(CC) algos.o partition.o heap.o -o partition

main: main.o 
	$(CC) main.o -o main

tests: tests.o algos.o heap.o
	$(CC) tests.o algos.o heap.o -o tests

algos: algos.o heap.o
		$(CC) algos.o heap.o -o algos

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

partition.o: partition.cpp
		$(CC) $(CFLAGS) partition.cpp

algos.o: algos.cpp
		$(CC) $(CFLAGS) algos.cpp

tests.o: tests.cpp
		$(CC) $(CFLAGS) tests.cpp

heap.o: heap.cpp
		$(CC) $(CFLAGS) heap.cpp
clean: 
	rm *.o






