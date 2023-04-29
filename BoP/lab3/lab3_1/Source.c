#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 1000
int main() {
	float avg2 = 0, min, arr[N];
	int i, k, yourN=0;
	float *p;
	
	printf("Enter the number of elements (<=1000):\n");
	scanf("%d", &yourN); //введення розміру вектора
	
	printf("Enter your elements:\n");
		for (int i = 0; i < yourN; i++) {	
			scanf("%f", &arr[i]);
		}

	printf("\nOriginal array:\n"); //виведення введеного вектора
	for (int i = 0; i < yourN; i++)
		printf("%5.3f\t", arr[i]);
	
	for (i = 0; i < yourN; i++) { //обчислення половини від середнього арифм. елементів масиву
		avg2 += *(arr+i);
	}
	avg2 /= 2*yourN;
	printf("\n\nAvg number is: %5.3f\n", 2*avg2);

	min = arr[0]; //знаходження мінімального числа
	for (k = 1; k < yourN; k++) {
		if (arr[k] < min)
			min = arr[k];
	}
	
	printf("Min number is: %5.3f\n", min);

	for (k = 0; k < yourN; k++) { //знаходження комірки з числом min
		if (arr[k] == min)
			break;
	}

	//зміна значень масиву відповідно до завдання
	for (p = &arr[0];p<&arr[k];p++) {
		*p -= avg2;
	}

	printf("\nSubtracting half of avg (%5.3f) from all the elements before min (%5.3f)...\n\nThe result is: \n", avg2, min);
	
	for (int i = 0; i < yourN; i++) {
		printf("%5.3f\t", arr[i]);
	}

	return 0;
}