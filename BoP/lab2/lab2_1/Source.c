#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	int k=1;
	while (k) {
		long iNum, iCopy, iCopy2, iLength = 0, iTemp1, iTemp2, n = 1, i = 1;
	printf("Enter your natural num:\n");
	scanf("%d", &iNum); //�������� �����
	if (iNum > 0) { //�������� ���
		iCopy = iNum; 
		iCopy2 = iNum; //��������� ���� (���� ��������� �������� iNum ������������ �� �������� ����������)
		while (iNum > 0) {
			iLength++;
			iNum /= 10; //���������� �-�� ������� ����� (���� �������)
		}
		do {
			iTemp1 = iCopy / pow(10, iLength - i); 
			iTemp2 = iCopy % 10; //�������� � ����� ����� �� �������� ����� ��������

			if (iTemp1 != iTemp2) { //���� ����� ����� ������� ���� ����� �� � ���, �� ����� �� � ����������
				n = 0;
				break;
			}
			iCopy -= iTemp1 * (int)pow(10, iLength - i);
			iCopy /= 10; 
			i += 2; //³�������� ����� �� �������� ���� �����
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
	printf("\nContinue? YES - 1, NO - 0\n"); //���������� ���� 
	scanf("%d", &k);
	}
	return 0;
}