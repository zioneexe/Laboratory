#define _CRT_SECURE_NO_WARNINGS
#define AN(a1, a2, n) ((a1)+((a2)-(a1))*((n)-1)) 
#include <stdio.h>

int main() {
	float a1, a2;
	int n;
	
	printf("Enter a1 and a2: ");
	scanf("%f %f", &a1, &a2);
	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("Result: %f", AN(a1, a2, n));
	return 0;
}