
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "algos.hh"

//read file function
uint64_t* read_file_to_arr(std::ifstream &infile, int n){
	uint64_t* nums = (uint64_t*) malloc(n*sizeof(uint64_t));
	uint64_t val;
	for(int i=0; i<n; i++){
		infile>>val;
		nums[i] = val;
	}
	return nums;
};

int main(int argc, char const *argv[])
{
	std::ifstream infile(argv[1]);

	//read input file
	uint64_t* nums = read_file_to_arr(infile, 100);

	
	//compute kk
	printf("%llu\n", kk(nums, 100));

	free(nums);
	return 0;
}