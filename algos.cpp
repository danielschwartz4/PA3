#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>  
#include <math.h>     
#include <iostream>
#include <queue>
#include "heap.hh"

#define MAX_ITER 25000

int* random_sequence(int n){
	int* res= (int *) malloc(n*sizeof(int));
	// srand (time(0));

	for (int i =0; i<n;i++){
		float r = (float) rand()/RAND_MAX;
		if (r <=0.5){
			res[i]=-1;
		}
		else{
			res[i]=1;
		}
	}
	return res;
}

int* random_parition(int n){
	int* res = (int*) malloc(n*sizeof(int));
	// srand (time(NULL));

	for (int i =0; i<n;i++){
		res[i] = rand()%n;
	}
	return res;
}

int* sequence_neighbor(int* sequence, int n){
	int* neighbor = (int*) malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
		neighbor[i] = sequence[i];
	}

	// srand (time(NULL));
	// randomly flip one element
	int i = rand() %n;
	neighbor[i] = -1*neighbor[i];

	int j = rand() %n;
	while(j==i){
		j = rand() %n;
	}
	// 1/2 prob to flip the second one
	if(rand()%10+1<=5){
		neighbor[j] = -1*neighbor[j];
	}

	return neighbor;
}

int* partition_neighbor(int* sequence, int n){
	int* neighbor = (int*) malloc(n* sizeof(int));
	for(int i=0; i<n; i++){
		neighbor[i] = sequence[i];
	}

	// randomly pick one to change
	// srand (time(NULL));
	int i = rand()%n;
	int j = rand()%n;

	while (j== neighbor[i]){
		j = rand()%n;
	}
	neighbor[i] = j;

	return neighbor;
}

void copy_arr(int* source, int* dest, int n){
	for (int i=0; i<n; i++){
		dest[i] = source[i];
	}
}

uint64_t max(uint64_t* nums, int n){
  uint64_t curr_max = nums[0];
  for(int i=1; i<n; i++){
		if(nums[i] > curr_max){
      curr_max = nums[i];
    }
	}
  return curr_max;
}

void print_pqueue(std::priority_queue < int > pqueue){
  while (!pqueue.empty()) {
    std::cout << ' ' << pqueue.top();
    pqueue.pop();
  }
}

bool second_is_zero(std::priority_queue < int > pqueue){
  pqueue.pop();
  if(pqueue.top() == 0){
    return true;
  }
  return false;
}

std::priority_queue < uint64_t > nums_to_pqueue(uint64_t* nums, int n){
  std::priority_queue < uint64_t > pqueue;
  for(int i=0; i<n; i++){
		pqueue.push(nums[i]);
	}
  return pqueue;
}

uint64_t kk(uint64_t* nums, int n){
	maxheap* heap = malloc_heap(n);

	for (int i = 0; i<n; i++){
		heap_push(heap, nums[i]);
	}

	while (heap->heap_size>1){
		uint64_t largest = heap_top(heap);
	    heap_pop(heap);
	    uint64_t second_largest = heap_top(heap);
	    heap_pop(heap);
		heap_push(heap, largest - second_largest);
	}

	uint64_t res = heap_pop(heap);
	free_heap(heap);
	return res;
}

//Calculate residual from standard sequence representation
uint64_t seq_residue(uint64_t* nums, int* s, int n){
	int64_t res = 0;
	for(int i =0; i<n; i++){
		res += nums[i]* s[i];
	}
	if (res<0){
		res = -1*res;
	}
	return res;
}

//Calculate residual from repartition represenation
uint64_t parti_residue(uint64_t* nums, int* s, int n){
	uint64_t* p = (uint64_t*) calloc(n, sizeof(uint64_t));
	for(int i = 0; i<n; i++){
		p[s[i]] += nums[i];
	}
  	
	uint64_t res = kk(p, n);
	free(p);
	
	return res;
}

//Repeated Random
uint64_t repeated_random(uint64_t* nums, int* start, int n, bool is_seq){
	int * cur_s = (int*) malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
		cur_s[i] = start[i];
	}
	uint64_t cur_residue;
	if (is_seq){
		for(int i =0; i<= MAX_ITER; i++){
			cur_residue = seq_residue(nums, cur_s, n);
			int* random_s = random_sequence(n);
			uint64_t new_residue = seq_residue(nums, random_s, n);
			if (new_residue<cur_residue){
				cur_residue = new_residue;
				// free(cur_s);
				// cur_s = random_s;
				copy_arr(random_s, cur_s, n);
			}
			// else{
			// 	free(random_s);
			// }
			free(random_s);
		}	
	}
	else{
		for(int i =0; i<= MAX_ITER; i++){
			cur_residue = parti_residue(nums, cur_s, n);
			int* random_s = random_parition(n);
			uint64_t new_residue = parti_residue(nums, random_s, n);
			if (new_residue<cur_residue){
				cur_residue = new_residue;
				free(cur_s);
				cur_s = random_s;

			}
			else{
				free(random_s);
			}
		}
	}
	free(cur_s);
	return cur_residue;
}

//Hill Climbing
uint64_t hill_climbing(uint64_t* nums, int* start, int n, bool is_seq){
	int * cur_s = (int*) malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
		cur_s[i] = start[i];
	}
	uint64_t cur_residue;

	if (is_seq){
		for(int i = 0; i<MAX_ITER; i++){
			cur_residue = seq_residue(nums, cur_s, n);
			int* neighbor = sequence_neighbor(cur_s, n);
			uint64_t neighbor_residue = seq_residue(nums, neighbor, n);
			if(neighbor_residue<cur_residue){
				cur_residue = neighbor_residue;
				free(cur_s);
				cur_s = neighbor;
			}
			else{
				free(neighbor);
			}
		}
	}
	else{
		for(int i = 0; i<MAX_ITER; i++){
			cur_residue = parti_residue(nums, cur_s, n);
			int* neighbor = partition_neighbor(cur_s, n);
			uint64_t neighbor_residue = parti_residue(nums, neighbor, n);
			if(neighbor_residue<cur_residue){
				cur_residue = neighbor_residue;
				free(cur_s);
				cur_s = neighbor;
			}
			else{
				free(neighbor);
			}
		}
	}

	free(cur_s);
	return cur_residue;

}

// Cooling Schedule
double cooling_schedule(int iter){
	// 10^10(0.8)^⌊iter/300⌋ 
	return pow(10,10)*pow(0.8, iter/300);
}

//Simulated Anealing
uint64_t simulated_anealing(uint64_t* nums, int* start, int n, bool is_seq){
	int* cur_s = (int*) malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		cur_s[i] = start[i];
	}

	int* prime_s = (int*) malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		prime_s[i] = start[i];
	}

	uint64_t cur_residue;
	uint64_t prime_residule;

	if (is_seq){
		cur_residue = seq_residue(nums, cur_s, n);
		prime_residule = seq_residue(nums, prime_s, n);
		for(int i =0; i<MAX_ITER; i++){
			int* neighbor = sequence_neighbor(cur_s, n);
			uint64_t neighbor_residue = seq_residue(nums, neighbor, n); 
			double cut_off = exp((int64_t) (cur_residue - neighbor_residue) / cooling_schedule(i));
			if(neighbor_residue<cur_residue|| 
				rand()/RAND_MAX <=cut_off){
				cur_residue = neighbor_residue;
				free(cur_s);
				cur_s = neighbor;
			}
			else{
				free(neighbor);
			}

			if (cur_residue<prime_residule){
				prime_residule = cur_residue;
				for(int i=0; i<n; i++){
					prime_s[i] = cur_s[i];
				}
			}
		}
	}
	else{
		cur_residue = parti_residue(nums, cur_s, n);
		prime_residule = parti_residue(nums, prime_s, n);
		for(int i =0; i<MAX_ITER; i++){
			int* neighbor = partition_neighbor(cur_s, n);
			uint64_t neighbor_residue = parti_residue(nums, neighbor, n); 
			double cut_off = exp((int64_t) (cur_residue - neighbor_residue) / cooling_schedule(i));
			if(neighbor_residue<cur_residue|| 
				rand()/RAND_MAX <cut_off){
				cur_residue = neighbor_residue;
				free(cur_s);
				cur_s = neighbor;
			}
			else{
				free(neighbor);
			}

			if (cur_residue<prime_residule){
				prime_residule = cur_residue;
				for(int i=0; i<n; i++){
					prime_s[i] = cur_s[i];
				}
			}
		}
	}
	
	free(cur_s);
	free(prime_s);
	return prime_residule;
}

