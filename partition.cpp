
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

uint64_t* load_file_to_nums(char* file, int n){
	FILE* f = fopen(file, "r");

    // Input numbers into array nums
    uint64_t* nums = (uint64_t*) malloc(sizeof(uint64_t) * n);
    char* line = NULL;
    size_t read, len, i = 0;
    while ((read = getline(&line, &len, f)) != -1) {
        nums[i] = strtoull(line, NULL, 10);
        i++;
    }
    
    fclose(f);
    return nums;

}

int main(int argc, char const *argv[]){	
	int flag =  atoi(argv[1]);
	(void) flag;
	int code = atoi(argv[2]);
	// std::ifstream infile(argv[3]);
	char* file = (char*) argv[3];

	//read input file
	// uint64_t* nums = read_file_to_arr(infile, 100);
	uint64_t* nums = load_file_to_nums(file, 100);
	int n = 100;
	if (code==0){
		printf("%llu\n", kk(nums, n));
	}
	if (code==1){
		int* start = random_sequence(n);
		printf("%llu\n", repeated_random(nums, start, n, true));
	}
	
	
	free(nums);
	return 0;
}
