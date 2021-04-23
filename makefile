CC=c++
CFLAGS=-c -Wall

all: kk

kk: algos.o kk.o
		$(CC) algos.o kk.o -o kk

algos: algos.o
		$(CC) algos.o -o algos
kk.o: kk.cpp
		$(CC) $(CFLAGS) kk.cpp

algos.o: algos.cpp
		$(CC) $(CFLAGS) algos.cpp

clean: 
	rm *.o kk






