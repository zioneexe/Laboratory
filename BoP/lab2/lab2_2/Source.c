#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int main() {
int num = 1, i=1;
float a, b, step, x=0, eps, taylor=1, formula, coef1, coef2, curr;

printf("Enter A and B (-1<A<B<1):\n");
scanf("%f %f", &a, &b); //Введення границь табуляції
printf("Enter step (step>0):\n");
scanf("%f", &step); //Введення кроку
printf("Enter eps (eps>0):\n");
scanf("%f", &eps); //Введення точності

if (a<b&&step>0&&a>-1&&b<1) { //Перевірка ОДЗ
	printf("\n|#\t\t|x\t\t|Taylor\t\t|Formula\n");
	for (x = a; x <= b; x += step) { //Зміна х
		curr = 1;  //Обнулення змінних, лічильників
		coef1 = 1, coef2 = 3;
		i = 1, taylor = 1;
			while (fabs(curr) >= eps) { //Перевірка точності
				curr *= (x * coef1 / coef2);
				taylor += curr;		
				i++;
				coef1 += 3;
				coef2 += 3;
				//Обчислення за рядом Тейлора
			}
			formula = pow(1 - x, -1.0 / 3); //Обчислення за формулою
			printf("|%d\t\t|%f\t|%f\t|%f\n", num, x, taylor, formula); 
			num++;
			//Виведення таблиці даних
	}
}
else {
	printf("Incorrect input..");
}
return 0;
}

