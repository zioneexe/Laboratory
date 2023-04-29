#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	double x, y, b;
	const double z = 3.25;
	printf("Enter variables. Make sure x>y\n"); 
	printf("Enter x:");
	scanf("%lf", &x);
	printf("Enter y:");
	scanf("%lf", &y);
	if (((pow(x - y, z) + x * x) != 0) && x >= y) { //Перевірка ОДЗ
		b = (x + 3 * (x - y) + x * x) / (pow(x - y, z) + x * x); 
		
		printf("\nYour result: %lf", b);
		//Якщо ОДЗ виконується
	}
	else { 
		printf("\nTry another numbers! (error:x<y or denominator==0)");
		//Якщо ОДЗ не виконується
	}
	return 0;
}