#include "algos.hh"
#include <iostream>
#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>    
#include <queue>



int main(int argc, char const *argv[])
{
	uint64_t nums[] = {10, 8,7 ,6,5};
	int s[] = {0,1,1,3,4};
	parti_residue(nums, s, 5);
	return 0;
}

