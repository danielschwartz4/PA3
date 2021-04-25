#include "algos.hh"
#include "heap.hh"
#include <assert.h>  
#include <iostream>
#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>    
#include <queue>
#include <assert.h> 

// uint64_t get_size(uint64_t nums[]){
//   uint64_t size = sizeof(nums)/sizeof(nums[0]);
//   return size;
// }

void heap_tests(){
  uint64_t nums0[] = {0, 0, 0, 0, 0, 0};
  int size0 = sizeof(nums0)/sizeof(nums0[0]);
  maxheap* heap0 = malloc_heap(size0);
	for (int i = 0; i<size0; i++){
		heap_push(heap0, nums0[i]);
	}
  print_heap(heap0);
  free_heap(heap0);

  uint64_t nums1[] = {10, 8, 7, 6, 5};
  int size1 = sizeof(nums1)/sizeof(nums1[0]);
  maxheap* heap1 = malloc_heap(size1);
	for (int i = 0; i<size1; i++){
		heap_push(heap1, nums1[i]);
	}
  print_heap(heap1);
  free_heap(heap1);

  uint64_t nums2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size2 = sizeof(nums2)/sizeof(nums2[0]);
  maxheap* heap2 = malloc_heap(size2);
	for (int i = 0; i<size2; i++){
		heap_push(heap2, nums2[i]);
	}
  print_heap(heap2);
  free_heap(heap2);
}


void kk_tests(){
  uint64_t nums0[] = {0, 0, 0, 0, 0, 0};
  int size0 = sizeof(nums0)/sizeof(nums0[0]);
	assert (kk(nums0, size0) == 0);
  std::cout << "good" << "\n";

  uint64_t nums1[] = {1};
  int size1 = sizeof(nums1)/sizeof(nums1[0]);
	assert (kk(nums1, size1) == 1);
  std::cout << "good" << "\n";

  uint64_t nums2[] = {50, 2, 4, 8, 16, 32, 60};
  int size2 = sizeof(nums2)/sizeof(nums2[0]);
	assert (kk(nums2, size2) == 0);
  std::cout << "good" << "\n";

  uint64_t nums3[] = {5, 6, 7, 8, 10};
  int size3 = sizeof(nums3)/sizeof(nums3[0]);
	assert (kk(nums3, size3) == 2);
  std::cout << "good" << "\n";

  uint64_t nums4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size4 = sizeof(nums4)/sizeof(nums4[0]);
	assert (kk(nums4, size4) == 1);
  std::cout << "good" << "\n";
}

void residue_tests(){
  uint64_t nums0[] = {10, 8, 7, 6, 5};
  int s0[] = {1, 2, 3, 4, 5};
  int size0 = sizeof(nums0)/sizeof(nums0[0]);
	// assert (kk(nums0, size0) == 0);
  std::cout << parti_residue(nums0, s0, size0) << "\n";

}


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
    print_heap(heap);
		++i;
	}
	free_heap(heap);
}



int main(void) {
	// test_heap();
	// printf("test heap done\n");

  // heap_tests();
	// printf("test heap done\n");

  kk_tests();
  printf("kk tests done\n");

  // residue_tests();
  // printf("residue tests done\n");
  
  return 0;
}

