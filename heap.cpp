#include <assert.h>  
#include<iostream>
#include <stdint.h>
#include <stdlib.h>
#include<climits>
#include <inttypes.h>
#include "heap.hh"
using namespace std;


void swap(uint64_t *i, uint64_t *j){
	uint64_t temp = *i;
	*i = *j;
	*j = temp;
}

maxheap* malloc_heap(int cap){
	maxheap* heap = new maxheap;
	heap->heap_size=0;
	heap->capacity = cap;
	heap->arr = (uint64_t*) malloc(cap*sizeof(uint64_t));
	return heap;
}

void free_heap(maxheap* heap){
	free(heap->arr);
	delete heap;
}

int parent(int i){ 
	return (i-1)/2; 
}

int left(int i){
	return (2*i + 1);
}

int right(int i){
	return (2*i + 2);
}

void heapify(maxheap* heap, int i){
	int l = left(i);
	int r = right(i);
	int max = i;
	if (l < heap->heap_size && heap->arr[l] > heap->arr[i]){
		max = l;
	}
	if (r < heap->heap_size && heap->arr[r] > heap->arr[max]){
		max = r;
	}

	if (max != i){
		swap(&heap->arr[i], &heap->arr[max]);
		heapify(heap, max);
	}
}

// push a new value to heap
void heap_push(maxheap* heap, uint64_t k){
	if (heap->heap_size == heap->capacity){
		heap->arr = (uint64_t*) realloc(heap->arr, heap->capacity * 2);
		heap->capacity *= 2;
	}

	heap->heap_size++;
	int i = heap->heap_size - 1;
	heap->arr[i] = k;

	while (i != 0 && heap->arr[parent(i)] < heap->arr[i]){
		swap(&heap->arr[i], &heap->arr[parent(i)]);
		i = parent(i);
	}
}

uint64_t heap_top(maxheap* heap){
	assert(heap->heap_size>0);
	return heap->arr[0];
}

uint64_t heap_pop(maxheap* heap){
	assert(heap->heap_size>0);

	if (heap->heap_size == 1)
	{
		heap->heap_size--;
		return heap->arr[0];
	}

	int root = heap->arr[0];
	heap->arr[0] = heap->arr[heap->heap_size-1];
	heap->heap_size--;
	heapify(heap, 0);
	return root;
}

void print_heap(maxheap* heap){
	printf("heap: ");
	for (int i=0; i<heap->heap_size; i++){
		printf("%" PRIu64 "\t", heap->arr[i]);
	}
	printf("\n");
}

// void main():

