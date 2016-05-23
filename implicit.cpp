
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

void frequency_of_primes () {

	int first_loop, second_loop;
	int ceiling = 200;        
				
	int freq= ceiling - 1;
	int n = ceiling;
	for (first_loop = 2; first_loop <= n; ++first_loop){

		for (second_loop = sqrt(first_loop); second_loop > 1; -second_loop){

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

	cout << "Starting Implicit Thread Testing Program" << endl;

	clock_t start, end;
	start = clock();


	frequency_of_primes();
	end = clock() - start;
	cout << "Program took " << (float)end/(CLOCKS_PER_SEC) << " million clock cycles to complete" << endl;
	return 0;

}
