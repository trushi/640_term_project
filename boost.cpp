
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <boost/thread.hpp>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

void *frequency_of_primes () {

	cout << "Starting threads\n";
	int first_loop, second_loop;
	int ceiling = 1000000;		
					
	int freq= ceiling - 1;
	int n = ceiling;
	
	for (first_loop = 2; first_loop <= n; ++first_loop){
		
		for (second_loop = sqrt(first_loop); second_loop > 1; --second_loop){
			
			if (first_loop % second_loop == 0){
				
				--freq;
				 break;
			}
		}
	}
}
uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}


int main (int argc, char * argv[])
{

	
	int thread_count;
	
	if(argc == 2){
		
		int temp_cnt = atoi(argv[1]);
		thread_count = temp_cnt;
		if(temp_cnt < 0 || temp_cnt > 100){
			cout << "Please enter the number of threads as the only argument - between 0 and 100" << endl;
			exit(0);
		}
		
	} else{
		cout << "Please enter the number of threads as the only argument - between 0 and 100" << endl;
		exit(0);
	}

	
	boost::thread_group thread_array;

	
	clock_t start, end;
	start = clock();

	
	for (int i = 0; i < thread_count; i++)
	{
		boost::thread *t1 = new boost::thread(frequency_of_primes);
		thread_array.add_thread(t1);

	}

	
	thread_array.join_all();

	
	end = clock() - start;
	cout << "Threads took " << (float)end/(CLOCKS_PER_SEC) << " million clock cycles to complete" << endl;

	return 0;

}
