#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

void swap(int * arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selection_sort(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if ( arr[min] > arr[j] ) {
				min = j;
			}
		}
		swap(arr, i, min);
	}
}

long long calc_time(int * arr, int n) {
    // Storing The Start Time of Code
	struct timeval before;
	gettimeofday(&before, NULL);
    // tv_sec - The number of whole seconds elapsed since the epoch ( for a smple calender Time - 1 january 1970;
    //  tv_usec - The number of microseconds passed since last full second
	long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

	selection_sort(arr, n);

    // Storing the End Time of Code
	struct timeval after;
	gettimeofday(&after, NULL);
	long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

	return after_millis - before_millis;
}

int main() {
    srand(time(NULL));

	// Selection Sort for 32000 element 
	int k = 32000;
	int * arr1 = (int *) malloc (k * sizeof(int));
	for (int i = 0; i < k; i++) {
		arr1[i] = rand();
	}
	long long t1 = calc_time(arr1, k);

	// Selection Sort for 64000 element 
	k = 64000;
	int * arr2 = (int *) malloc (k * sizeof(int));
	for (int i = 0; i < k; i++) {
		arr2[i] = rand();
	}
	long long t2 = calc_time(arr2, k);
	
	// Printing Time Taken for Both Arrays
	printf("Time Elpased for Array 1 :- %llu ms\n", t1);
    printf("Time Elapsed for Array 2 :- %llu ms\n", t2);


	// Printing Ratio of Time Taken by Array 2 to Array 1
	printf("Ratio :- %lf\n", (t2*1.0 / t1));
	
	return 0;
}	