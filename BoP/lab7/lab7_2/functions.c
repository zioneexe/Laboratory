#include <stdio.h>
#include <math.h>

float func(float x) {
	float y;
	float precision = 0.00001;
	if ((x - precision) <= 0 || (x + precision) >= 1) {
		y = NAN;
		return y;
	}
	y = asin(sqrt(x)) / sqrt(x * (1 - x));
	return y;
}

void tabulation1(float a, float b, float h) {
	printf("Using function 1: \n");

	float x, count = 0;
	for (int i = 0; i < 57; i++)
		printf("*");
	printf("\n*\t|#\t\t|x\t\t|y              *\n");
	for (x = a; x <= b; x += h) {

		count++;
		printf("*");
		printf("\t|%-15.0f|%-15.5f|%-15.5f", count, x, func(x));
		printf("*\n");
	}
	for (int i = 0; i < 57; i++)
		printf("*");
}

void tabulation2(float a, float b, float h) {
	printf("Using function 2: \n");
	
	float x, count = 0;
	for (int i = 0; i < 57; i++)
		printf("*");
	printf("\n*\t|#\t\t|x\t\t|y              *\n");
	x = a;
	while (x <= b) {
		count++;
		printf("*");
		printf("\t|%-15.0f|%-15.5f|%-15.5f", count, x, func(x));
		printf("*\n");
		x += h;
	}
	for (int i = 0; i < 57; i++)
		printf("*");
}

void tabulation3(float a, float b, float h) {
	printf("Using function 3: \n");
	
	float x, count = 0;
	for (int i = 0; i < 57; i++)
		printf("*");
	printf("\n*\t|#\t\t|x\t\t|y              *\n");
	x = a;
	 do {
		count++;
		printf("*");
		printf("\t|%-15.0f|%-15.5f|%-15.5f", count, x, func(x));
		printf("*\n");
		x += h;
	 } while (x <= b);
	for (int i = 0; i < 57; i++)
		printf("*");
}