#include <stdio.h>
#include <math.h>

float func2(float x, float* y) {
	float precision = 0.00001;
	if ((x - precision) <= 0 || (x + precision) >= 1) {
		*y = NAN;
		return *y;
	}
	*y = asin(sqrt(x)) / sqrt(x * (1 - x));
	if (*y > 0) {
		int res = 1;
		return res;
	}
	if (*y = 0) {
		int res = 0;
		return res;
	}
	if (*y < 0) {
		int res = -1;
		return res;
	}
}

void tabulation(float a, float b, float h) {
	float x, y;
	float count = 0;
	for (int i = 0; i < 68; i++)
		printf("*");
	printf("\n*\t|#\t\t|x\t\t|y\t\t|res       *\n");
	for (x = a; x <= b; x += h) {
		count++;
		func2(x, &y);
		printf("*");
		printf("\t|%-15.0f|%-15.5f|%-15.5f|%-10.0f", count, x, y, func2(x, &y));
		printf("*\n");
	}
	for (int i = 0; i < 68; i++)
		printf("*");
}