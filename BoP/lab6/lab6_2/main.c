#define _CRT_SECURE_NO_WARNINGS
#define N 1000
#include "func.h"
#include <stdio.h>
#include <stdarg.h>


int main() {
	int n, mas[N];
	
	printf("Enter the number of arguments: \n");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		printf("Enter the %d argument: ", i + 1);
		scanf("%d", &mas[i]);
	}
	
	PositiveEvenNumbers(n, mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[6], mas[7], mas[8], mas[9], mas[10], mas[11], mas[12], mas[13], mas[14], mas[15], mas[16], mas[17], mas[18], mas[19], mas[20], mas[21], mas[22], mas[23], mas[24], mas[25], mas[26], mas[27], mas[28], mas[29], mas[30], mas[31], mas[32], mas[33], mas[34], mas[35], mas[36], mas[37], mas[38], mas[39], mas[40], mas[41], mas[42], mas[43], mas[44], mas[45], mas[46], mas[47], mas[48], mas[49], mas[50]);
	
	return 0;
}