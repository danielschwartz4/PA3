#ifndef HEAP_HH
#define HEAP_HH

#include <assert.h>  
#include<iostream>
#include <stdint.h>
#include <stdlib.h>
#include<climits>
#include "heap.hh"
using namespace std;

typedef struct maxheap
{
	uint64_t *arr; 
	int capacity; 
	int heap_size;
} maxheap;

void swap(int *i, int *j);

maxheap* malloc_heap(int cap);

void free_heap(maxheap* heap);

int parent(int i);

int left(int i);

int right(int i);

void heapify(maxheap* heap, int i);

void heap_push(maxheap* heap, uint64_t k);

uint64_t heap_top(maxheap* heap);

uint64_t heap_pop(maxheap* heap);
#endif