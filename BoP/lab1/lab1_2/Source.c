#include <stdio.h>
#include <conio.h>
int main() {
	int a, min = 9, max = 0, temp;
	printf("Enter your natural 8-digit number: ");
	scanf_s("%d", &a);
	if (a > 9999999 && a < 100000000) { //�������� �����
	start: 
		temp = a % 10; //���� �����
		a /= 10; //³�������� �������� ����� �����
		if (temp >= max) {
			max = temp;	
		}
		if (temp<=min) {
			min = temp;
		}
		if (a >= 1) {
			goto start;	//������� �����, ������ ������������ �� ����� 
		}
	printf("Your max value is: % d\n", max);
	printf("Your min value is: % d", min);
	}
	else {

		printf("Wrong input!\nTry another..");
		}
	return 0;
	_getch();
	}