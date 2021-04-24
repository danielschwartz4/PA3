CC=c++
CFLAGS=-c -Wall

all: kk

kk: algos.o kk.o
	$(CC) algos.o kk.o -o kk

main: main.o 
	$(CC) main.o -o main

tests: tests.o algos.o
	$(CC) tests.o algos.o -o tests

algos: algos.o
		$(CC) algos.o -o algos

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp
kk.o: kk.cpp
		$(CC) $(CFLAGS) kk.cpp

algos.o: algos.cpp
		$(CC) $(CFLAGS) algos.cpp

tests.o: tests.cpp
		$(CC) $(CFLAGS) tests.cpp
clean: 
	rm *.o kk






