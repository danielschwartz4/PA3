#include "algos.hh"
#include "heap.hh"
#include <assert.h>  
#include <iostream>
#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>    
#include <queue>

void test_heap(){
	int n = 3;
	maxheap* heap=malloc_heap(n);
	heap_push(heap,56);
	heap_push(heap, 65);
	heap_push(heap, 24);
	assert(heap->heap_size==3);
	
	uint64_t arr[] = {65, 56,24};
	int i =0;
	while (heap->heap_size>0){
		assert(heap_pop(heap)==arr[i]);
		++i;
	}
}



int main(void) {
	test_heap();
	printf("test heap done\n");

  uint64_t nums[] = {10, 8,7 ,6,5};
	int s[] = {0,1,1,3,4};
	uint64_t residue = parti_residue(nums, s, 5);
	printf("residue: %llu\n", residue);
  return 0;
}

