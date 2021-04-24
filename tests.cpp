#include "algos.hh"
#include "heap.hh"
#include <iostream>
#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>    
#include <queue>

int main(void) {
  	uint64_t nums[] = {10, 8,7 ,6,5};
	int s[] = {0,1,1,3,4};
	uint64_t residue = parti_residue(nums, s, 5);
	printf("residue: %llu\n", residue);
  return 0;
}

