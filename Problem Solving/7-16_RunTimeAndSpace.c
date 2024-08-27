// To find Time used By any funtion to execute

#include <stdio.h>
#include <time.h>

int main() {
	clock_t start_time, end_time;
	double cpu_time_used;

	start_time = clock();

	// Place any code/function whose Time Complexity we want to know
	long long int sum = 0;
	for (int i = 1; i <= 10000000; i++) {
		sum += i;
	}
	
	end_time = clock();

	
	// Calculating CPU Time in second
	cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

	printf("Sum :- %lld\n", sum);
	printf("CPU Time Used :- %f milliseconds\n", cpu_time_used * 1000);

	return 0;
}


// To find Memory Used by any function 
/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>   //  Works in linux/Mac
#include <time.h>

int main() {
	srand(time(NULL));

	// Recording The Start of Memory Usage
	struct rusage usage_start;
	
	getrusage(RUSAGE_SELF, &usage_start);

	// Place your code to measure memory usage here
	int * array = (int *) malloc (50000 * sizeof (int) );

	for (int i = 0; i < 50000; i++) {
		array[i] = i + 1;
	}
	
	// Recording the End of Memory Usage	
	struct rusage usage_end;

	getrusage(RUSAGE_SELF, &usage_end);

	// Calculate memory usage in kilobytes
	long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;

	printf("Memory Used :- %ld KB\n", memory_used);

	// Free the Allocated Memory
	free(array);

	return 0;
}
*/