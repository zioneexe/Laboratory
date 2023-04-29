#include <stdio.h>
#include <stdlib.h>
#define N 100

int main() {
	int k, c=0;
	float num;
	printf("Enter your number of rows: ");
	scanf_s("%d", &k);

	float* sum = (float*)calloc(k, sizeof(float)); //масив для зберігання суми елементів кожного рядка
	if (sum == NULL) return 1;
	
	float** arr = (float**)malloc(k * sizeof(float*));
	for (int i = 0; i < k; i++) {
		arr[i] = (float*)malloc(sizeof(float));
	}

	if (arr == NULL) return 1;

	printf("(Enter '0' to go to the next row)\n");

	float* temp;

	for (int i = 0; i < k; i++) {
		do {
			scanf_s("%f", &num);
			c++;
			temp=realloc(arr[i], c*sizeof(float)); //перевиділення пам'яті (додаткова пам'ять для зберігання останнього елемента)
			if (temp) arr[i] = temp;
			sum[i] += num;
		} while (num); //якщо введено '0', то переходимо на наступний рядок
		c = 0;
	}
	
	for (int i = 0; i < k; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	for (int i = 0; i < k; i++) {
			printf("Sum of row %d = %f \n", i+1,sum[i]);
	}

	free(sum);
	sum = NULL;

	return 0;
}