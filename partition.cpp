
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <inttypes.h>
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

int main(int argc, char const *argv[]){	
	int flag =  atoi(argv[1]);
	(void) flag;
	int code = atoi(argv[2]);
	std::ifstream infile(argv[3]);
	
	int n = 100;
	//read input file
	uint64_t* nums = read_file_to_arr(infile, n);
	
	if (code==0){
		printf("%" PRIu64 "\n", kk(nums, n));
	}
	if (code==1){
		int* start = random_sequence(n);
		printf("%" PRIu64 "\n", repeated_random(nums, start, n, true));
	}
	if (code==2){
		int* start = random_sequence(n);
		printf("%" PRIu64 "\n", hill_climbing(nums, start, n, true));
	}
	if (code==3){
		int* start = random_sequence(n);
		printf("%" PRIu64 "\n", simulated_anealing(nums, start, n, true));
	}
	if (code==11){
		int* start = random_parition(n);
		printf("%" PRIu64 "\n", repeated_random(nums, start, n, false));
	}
	if (code==12){
		int* start = random_parition(n);
		printf("%" PRIu64 "\n", hill_climbing(nums, start, n, false));
	}
	if (code==13){
		int* start = random_parition(n);
		printf("%" PRIu64 "\n", simulated_anealing(nums, start, n, false));
	}
	free(nums);
	return 0;
}
