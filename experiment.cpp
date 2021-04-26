#include <iostream>
#include <fstream>
#include <stdint.h>
#include <inttypes.h>
#include <ctime>
#include <time.h>
#include <chrono>
#include "algos.hh"

clock_t start_time, end_time;

uint64_t * get_nums(int n){
	uint64_t* nums = (uint64_t*) malloc(n*sizeof(uint64_t));
	for (int i=0; i<n; i++){
		uint64_t temp = ((uint64_t)rand() << 32) + rand();
		nums[i] = temp; // % (uint64_t) pow(10, 12) + 1;

	}
	return nums;
}

int main(int argc, char const *argv[])
{
	int code = atoi(argv[1]);
	int trails = atoi(argv[2]);
	int n = 100;
	printf("residue\ttime_spent\n");
	for (int i=0; i<trails; i++){
		uint64_t* nums = get_nums(n);
		if (code==0){
			start_time = clock();
			uint64_t res = kk(nums, n);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==1){
			int* start = random_sequence(n);
			start_time = clock();
			uint64_t res = repeated_random(nums, start, n, true);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==2){
			int* start = random_sequence(n);
			start_time = clock();
			uint64_t res = hill_climbing(nums, start, n, true);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==3){
			int* start = random_sequence(n);
			start_time = clock();
			uint64_t res = simulated_anealing(nums, start, n, true);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==11){
			int* start = random_parition(n);
			start_time = clock();
			uint64_t res = repeated_random(nums, start, n, false);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==12){
			int* start = random_parition(n);
			start_time = clock();
			uint64_t res = hill_climbing(nums, start, n, false);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		if (code==13){
			int* start = random_parition(n);
			start_time = clock();
			uint64_t res = simulated_anealing(nums, start, n, false);
			end_time = clock();
			double time_spent = (double) (end_time-start_time)/ CLOCKS_PER_SEC *1000;

			printf("%" PRIu64 "\t%f\n", res, time_spent);
		}
		free(nums);
	}
	return 0;
} 