#include "sort.h"
#include <stdio.h>

void swap(int array[], long pos1, long pos2)
{
	long tmp;
	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

void qs_sort(int array[], long start, long end)
{
	long head = start, tail = end - 1, tmp;
	long diff = end - start;
	long pe_index;
	// якщо залишилося менше двох елементів – кінець рекурсії
	if (diff < 1) return;
	if (diff == 1)
		if (array[start] > array[end]) {
			swap(array, start, end);
			return;
		}
	// пошук індексу розділяючого елементу pe_index
	long m = (start + end) / 2;
	if (array[start] <= array[m]) {
		if (array[m] <= array[end]) pe_index = m;
		else if (array[end] <= array[start]) pe_index = start;
		else pe_index = end;
	}
	else {
		if (array[start] <= array[end]) pe_index = start;
		else if (array[end] <= array[m]) pe_index = m;
		else pe_index = end;
	}
	long pe = array[pe_index]; // сам розділяючий елемент
	swap(array, pe_index, end);

		while (1) {
			while (array[head] < pe)
				++head;
			while (array[tail] > pe && tail > start)
				--tail;
			if (head >= tail) break;
			swap(array, head++, tail--);
		}
	swap(array, head, end);
	long mid = head;
	qs_sort(array, start, mid - 1); // рекурсивний виклик для 1-ої підмножини
	qs_sort(array, mid + 1, end); // рекурсивний виклик для 2-ої підмножини
}

void bubble_sort(int array[], long length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
}

void identity_check(int array1[], int array2[], size_t array_size) {
	int n = 1;
	
	for (int i = 0; i<array_size; i++) {
		if (array1[i] != array2[i]) n = 0;
	}
	
	if (n) printf("Great! Arrays are identical.\n");
	else printf("Sad.. Arrays are different.\n");
}

void arrange_check(int array[], size_t array_size) {
	
	int increase = 1;
	for (int i = 0; i < array_size - 1; i++) {
		if (array[i] > array[i + 1])
		{
			increase = 0;
		}
	}

	if (increase == 1)
	{
		printf("The array is sorted in ascending order.\n");
	}
	
	int decrease = 1;
	for (int i = 0; i < array_size-1; i++) {
		if (array[i] < array[i + 1])
		{
			decrease = 0;
		}
	}

	if (decrease == 1)
	{
		printf("The array is sorted in descending order.\n");
	}

	if (increase == 0 && decrease == 0)
	{
		printf("The array is not sorted!\n");
	}
}


