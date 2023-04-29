#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	int k=1;
	while (k) {
		long iNum, iCopy, iCopy2, iLength = 0, iTemp1, iTemp2, n = 1, i = 1;
	printf("Enter your natural num:\n");
	scanf("%d", &iNum); //Введення числа
	if (iNum > 0) { //Перевірка ОДЗ
		iCopy = iNum; 
		iCopy2 = iNum; //Створення копій (після обчислень значення iNum різнитиметься із введеним початковим)
		while (iNum > 0) {
			iLength++;
			iNum /= 10; //Обчислення к-сті розрядів числа (його довжини)
		}
		do {
			iTemp1 = iCopy / pow(10, iLength - i); 
			iTemp2 = iCopy % 10; //Виділення з числа першої та останньої цифри відповідно

			if (iTemp1 != iTemp2) { //Якщо таким чином попарно взяті цифри не є рівні, то число не є паліндромом
				n = 0;
				break;
			}
			iCopy -= iTemp1 * (int)pow(10, iLength - i);
			iCopy /= 10; 
			i += 2; //Відкидання першої та останньої цифр числа
		} while (iCopy > 0);
	}
	else {
		printf("Incorrect input");
	}
	switch (n) {
	case 1:
		printf("%d is a palindrome!", iCopy2);
		break;
	case 0:
		printf("%d is not a palindrome!", iCopy2);
	}
	printf("\nContinue? YES - 1, NO - 0\n"); //Повторення коду 
	scanf("%d", &k);
	}
	return 0;
}