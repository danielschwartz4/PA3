#include <stdint.h>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>    
#include <iostream>
#include <queue>

#define MAX_ITER 25000

int* random_sequence(int n){
	int* res= (int *) malloc(n*sizeof(int));
	srand (time(NULL));

	for (int i =0; i<n;i++){
		int r = rand()%10+1;
		if (r <=5){
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
	srand (time(NULL));

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

	srand (time(NULL));
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
	srand (time(NULL));
	int i = rand()%n;
	int j = rand()%n;

	while (j!= neighbor[i]){
		j = rand()%n;
	}
	neighbor[i] = j;

	return neighbor;
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

std::priority_queue < int > nums_to_pqueue(uint64_t* nums, int n){
  std::priority_queue < int > pqueue;
  for(int i=0; i<n; i++){
		pqueue.push(nums[i]);
	}
  return pqueue;
}

//Karmarkar-Karp algorithm, use max-heap to sort the nums 
uint64_t iter_kk(uint64_t* nums, int n){
  // new empty queue
  std::priority_queue < int > pqueue = nums_to_pqueue(nums, 5);
  print_pqueue(pqueue);

  std::cout << "\n";

  while(!second_is_zero(pqueue)){
    int largest = pqueue.top();
    pqueue.pop();
    int second_largest = pqueue.top();
    pqueue.pop();
    int diff = std::abs(largest - second_largest);
    pqueue.push(diff);
    pqueue.push(0);
    print_pqueue(pqueue);
    std::cout << "\n";
  }
  std::cout << pqueue.top() << "\n";
  return pqueue.top();
}


int kk(std::priority_queue < int > pqueue){
  print_pqueue(pqueue);
  std::cout << "\n";
  if(second_is_zero(pqueue)){
    return pqueue.top();
  }

  int largest = pqueue.top();
  pqueue.pop();
  int second_largest = pqueue.top();
  pqueue.pop();
  int diff = std::abs(largest - second_largest);
  pqueue.push(diff);
  pqueue.push(0);
  return kk(pqueue);
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
  std::priority_queue < int > pqueue = nums_to_pqueue(p, n);
	uint64_t res = kk(pqueue);
	free(p);
	
	return res;
}

//Repeated Random
uint64_t repeated_random(uint64_t* nums, int* start, int n, bool is_seq){
	int * cur_s = (int*) malloc(n*sizeof(uint64_t));
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
				free(cur_s);
				cur_s = random_s;

			}
			else{
				free(random_s);
			}
		}	
	}
	else{
		for(int i =0; i<= MAX_ITER; i++){
			cur_residue = parti_residue(nums, cur_s, n);
			int* random_s = random_parition(n);
			uint64_t new_residue = seq_residue(nums, random_s, n);
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
	return cur_residue;
}

//Hill Climbing
uint64_t hill_climbing(uint64_t* nums, int* start, int n, bool is_seq){
	int * cur_s = (int*) malloc(n*sizeof(uint64_t));
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
	return cur_residue;

}

//Simulated Anealing
uint64_t simulated_anealing();

int main(int argc, char const *argv[])
{
	uint64_t nums[] = {10, 8,7 ,6,5};
	int s[] = {0,1,1,3,4};
	parti_residue(nums, s, 5);
	return 0;
}
