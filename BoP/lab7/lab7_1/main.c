#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main() {
	clock_t start, end;
	double result;
	int array1[N], array2[N];
	size_t array1_size = _countof(array1);
	size_t array2_size = _countof(array2);

	//Generating arrays
	srand(1);
	for (int i = 0; i < N; i++) {
		array1[i] = rand();
	}

	srand(1);
	for (int i = 0; i < N; i++) {
		array2[i] = rand();
	}

	//Check #1
	printf("Before sorting the arrays: \n");
	printf("Identity check #1: ");
	identity_check(array1, array2, array1_size);
	printf("Arrange check #1 (arr1): ");
	arrange_check(array1, array2_size);
	printf("Arrange check #1 (arr2): ");
	arrange_check(array2, array2_size);

	printf("\n");

	//Quick Sort
	start = clock();
	printf("Start: %d \n", start);
	
	qs_sort(array1, 0, N-1);

	end = clock();
	printf("End: %d \n", end);

	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Quick sort time: %lf \n", result);

	printf("\n");

	//Bubble Sort
	start = clock();
	printf("Start: %d \n", start);

	bubble_sort(array2, sizeof(array2)/sizeof(int));

	end = clock();
	printf("End: %d \n", end);

	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Bubble sort time: %lf \n", result);

	printf("\n");

	//Check #2
	printf("After sorting the arrays: \n");
	printf("Identity check #2: ");
	identity_check(array1, array2, array1_size);
	printf("Arrange check #2 (mas1): ");
	arrange_check(array1, array1_size);
	printf("Arrange check #2 (mas2): ");
	arrange_check(array1, array2_size);

	return 0;
}