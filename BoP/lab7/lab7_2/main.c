#define _CRT_SECURE_NO_WARNIGNS
#include "functions.h"
#include <stdio.h>
#include <math.h>

int main() {
	int num;
	float a, b, h;
	void(*p)(float, float, float);
	printf("Enter a and b (0<a<b<1): ");
	scanf_s("%f %f", &a, &b);
	
	printf("Enter step: ");
	scanf_s("%f", &h);

	printf("Choose the function you want to use |1-for, 2-while, 3-do...while|: ");
	scanf_s("%d", &num);
	switch (num) {
		case 1:
			p = tabulation1;
			break;
		case 2:
			p=tabulation2;
			break;
		case 3:
			p=tabulation3;
			break;
		default:
			printf("Invalid mode!");
			return -1;
	}
	p(a,b,h);
	return 0;
}