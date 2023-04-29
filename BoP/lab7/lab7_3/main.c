#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "recursion.h"

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter your data:");
	recursion(n);
	return 0;
}