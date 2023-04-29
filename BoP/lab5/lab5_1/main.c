#include <stdio.h>
#include <math.h>
#include "functions.h"

int main() {
	float a, b, h;
	printf("Enter a, b and step (0<a<b<1):\n");
	scanf_s("%f %f %f", &a, &b, &h);
	if (a > 0 && b < 1 && a < b && h>0) {
	tabulation(a, b, h);
	}
	else { 
		printf("Error: Incorrect input!\n\n");
		tabulation(a, b, h);
	}
	return 0;
}