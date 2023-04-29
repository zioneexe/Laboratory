#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 15

int main() {
	long A[N][N];
	long B[N][N];
	long C[N][N];
	
	printf("Input matrix A:\n"); //введення матриці А
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%ld", *(A+i)+j);
		}
	}
	
	printf("Input matrix B:\n"); //введення матриці B
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%ld", *(B+i)+j);
		}
	}
	
	printf("\nMatrix C:\n\n");

	for (int i = 0; i < N; i++) { //обчислення матриці С=A*B
		for (int j = 0; j < N; j++) {
			C[i][j] = 0;
			for (int k=0; k<N; k++) {
				*(*(C+i)+j) += A[i][k] * B[k][j];	
			}
			printf("%-5ld ", *(C[i] + j));
		}
		printf("\n");
	}

	return 0;
}
