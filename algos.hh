#ifndef ALGOS_HH
#define ALGOS_HH

#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <queue>  

uint64_t kk(uint64_t* nums, int n);

int rec_kk(std::priority_queue < int > pqueue);

uint64_t seq_residual(uint64_t* nums, int* s, int n);
 
uint64_t parti_residue(uint64_t* nums, int* s, int n);

//Repeated Random
uint64_t repeated_random();

//Hill Climbing
uint64_t hill_climbing();

//Simulated Anealing
uint64_t simulated_anealing();

#endif
