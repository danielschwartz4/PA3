#ifndef ALGOS_HH
#define ALGOS_HH

#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <queue>
#include "heap.hh"  

int* random_sequence(int n);

int* random_parition(int n);

int* sequence_neighbor(int* sequence, int n);

int* partition_neighbor(int* sequence, int n);

uint64_t kk(uint64_t* nums, int n);

uint64_t seq_residual(uint64_t* nums, int* s, int n);
 
uint64_t parti_residue(uint64_t* nums, int* s, int n);

//Repeated Random
uint64_t repeated_random(uint64_t* nums, int* start, int n, bool is_seq);

//Hill Climbing
uint64_t hill_climbing(uint64_t* nums, int* start, int n, bool is_seq);

//Simulated Anealing
uint64_t simulated_anealing(uint64_t* nums, int* start, int n, bool is_seq);

#endif
