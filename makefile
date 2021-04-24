CC=c++
CFLAGS=-c -Wall

all: kk

kk: algos.o kk.o
	$(CC) algos.o kk.o -o kk

main: main.co 
	$(CC) main.o -o main

algos: algos.o
		$(CC) algos.o -o algos

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
clean: 
	rm *.o kk






