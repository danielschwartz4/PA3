#include <stdint.h>

#define MAX_ITER 25000

//Karmarkar-Karp algorithm 
uint64_t kk(uint64_t* nums, int n);

//Calculate residual from standard sequence representation
uint64_t seq_residual(uint64_t* nums, int* s, int n);

//Calculate residual from repartition represenation
uint64_t parti_residual(uint64_t* nums, int* s, int n);

//Repeated Random
uint64_t repeated_random();

//Hill Climbing
uint64_t hill_climbing();

//Simulated Anealing
uint64_t simulated_anealing();

