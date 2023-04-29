#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <stdio.h>
#include <string.h>
#define N 1000

int main() {

	char strings[N][N] = {0};
	char substring[N] = {0};
	int num;
	
	printf("Enter your number of strings: ");
	scanf("%d", &num);
	getchar();

	InputArray(strings, substring, num);
	CheckArray(strings, substring, num);
	printf("The maximum number of occurrences is in sentence %i.", MaxNumofOcc(strings, substring, num)+1);

	return 0;
}
