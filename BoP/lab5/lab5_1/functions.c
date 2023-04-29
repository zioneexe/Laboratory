#include <stdio.h>
#include <math.h>

float x, y;

float func1(float x) {
	float precision = 0.00001;
	if ((x-precision) <=0  || (x+precision) >= 1) {
		y = NAN;
		return y;
	}
		float y;
		y = asin(sqrt(x)) / sqrt(x * (1 - x));
		return y;
}

void tabulation(float a, float b, float h) {
	float count = 0;
	for (int i = 0; i < 57; i++)
		printf("*");
	printf("\n*\t|#\t\t|x\t\t|y              *\n");
	for (x = a; x <= b; x += h) {
		
		count++;
		printf("*");
		printf("\t|%-15.0f|%-15.5f|%-15.5f", count, x, func1(x));
		printf("*\n");
	}
	for (int i = 0; i < 57; i++)
		printf("*");
}