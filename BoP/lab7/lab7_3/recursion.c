#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "recursion.h"

void recursion(int n) {
	float data;
	if (n == 0) {
		printf("Your result is: ");
		return;
	}
	else {
		scanf("%f", &data);
		recursion(n - 1);
		printf("%3.3f ", data);
	}
}