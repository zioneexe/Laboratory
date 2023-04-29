#define _CRT_SECURE_NO_WARNINGS
#define N 50

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>

//x^3+5x^2+2x-14=0

//x-(x^3+5x^2+2x-14)/15
//13/15-x^2/5-2x/3


double func(double x);
double funcp(double x);
double func2p(double x);
void printLine(int len);
void dyhotomia(double a, double b, double eps);
double step(double b, double x);
double stepn(double x);
void hordy(double a, double b, double eps);
void niutona(double a, double b, double eps);
void prostoyiiteratsiyi(double a, double b, double eps);
int sign(double x);
int zbizhnist(double a, double b);

double func(double x) { //вихідна функція
	return pow(x, 3) + 5 * pow(x, 2) + 2 * x - 14;
}

double funcp(double x) {
	return 3 * pow(x, 2) + 10 * x + 2;
}

double func2p(double x) { //друга похідна даної функції
	return 6 * x + 10;
}

double peretvfuncp(double x) {
	return 13 / 15 - 1 / 5 * pow(x, 2) - 2 / 3 * x;
}

void printLine(int len) { //для табличного виводу
	for (int i = 0; i < len; i++)
	{
		putchar('=');
	}
	putchar('\n');
}

void dyhotomia(double a, double b, double eps) { //метод дихотомії
	printf("\n//Metod dyhotomiyi//\n\n");

	double xn = 0;

	printf("Calculations: \n");
	printLine(58);
	printf("|a\t\t|b\t\t|xn\t\t|f(xn)\n");
	printLine(58);

	while (fabs(b - a) > eps) { //перевірка точності
		xn = (a + b) / 2; //середина відрізка
		if (sign(func(a)) == sign(func(xn))) { //зміна меж
			a = xn;
		}
		if (sign(func(b)) == sign(func(xn))) {
			b = xn;
		}
		printf("|%lf\t|%lf\t|%lf\t|%lf\n", a, b, xn, func(xn));
	}
	printLine(58);

	printf("\n\nThe result is: %lf\n\n", xn);
}

double step(double b, double x) { //крок обчислень у методі хорд
	return -func(x) * (b - x) / (func(b) - func(x));
}

double stepn(double x) {
	return -func(x) / funcp(x);
}

void hordy(double a, double b, double eps) { //метод хорд
	printf("\n//Metod hord//\n\n");

	double x = a, xprev = INT_MAX;

	if (func(a) * func2p(a) > 0) { //перевірка для знаходження рухомого кінця хорди
		x = b;
	}
	else x = a;

	printf("Calculations: \n");
	printLine(25);
	printf("|xn\t\t|step(xn)\n");
	printLine(25);

	while (fabs(x - xprev) > eps) { //перевірка точності
		xprev = x;
		x = xprev - func(xprev) * (b - xprev) / (func(b) - func(xprev)); //ітераційна формула для наступного значення кореня р-ння
		printf("|%lf\t|%lf\n", x, step(b, x));
	}
	printLine(25);

	printf("\n\nThe result is: %lf\n\n", x);
}

void niutona(double a, double b, double eps) {
	printf("\n//Metod Niutona//\n\n");

	double x = a, xprev = INT_MAX;

	if (func(a) * func2p(a) > 0) { //перевірка для знаходження початкового значення
		x = a;
	}
	else x = b;

	printf("Calculations: \n");
	printLine(74);
	printf("|xn\t\t|f(xn)\t\t\t|f'(xn)\t\t\t|step(xn)\n");
	printLine(74);

	while (fabs(x - xprev) > eps) { //перевірка точності
		xprev = x;
		x = xprev - func(xprev) / funcp(xprev); //ітераційна формула для наступного значення кореня р-ння
		printf("|%lf\t|%lf\t\t|%lf\t\t|%lf\n", x, func(x), funcp(x), stepn(x));
	}
	printLine(74);

	printf("\n\nThe result is: %lf\n\n", x);
}

void prostoyiiteratsiyi(double a, double b, double eps) {
	printf("\n//Metod prostoyi iteratsii//\n\n");

	if (!zbizhnist(a, b)) return; //перевірка на збіжність

	double x = b, xprev;

	printf("Calculations: \n");
	printLine(25);
	printf("|xn\t\t|j(xn)\n");
	printLine(25);

	do {
		xprev = x;
		x = xprev - (pow(xprev, 3) + 5 * pow(xprev, 2) + 2 * x - 14) / 15; //ітераційна формула для наступного значення кореня р-ння
		printf("|%lf\t|%lf\n", x, xprev);
	} while (fabs(x - xprev) > eps);	//перевірка точності
	printLine(25);

	printf("\n\nThe result is: %lf\n\n", x);

}

int sign(double x) { //імплементація математичної функції sign для перевірки меж (метод дихотомії) 
	if (x > 0) {
		return 1;
	}
	if (x < 0) {
		return -1;
	}
	return 0;
}

int check(double a, double b) { //перевірка на існування кореня в проміжку [a,b]
	if (func(a) * func(b) < 0) {
		return 1;
	}
	printf("Wrong input!");
	return 0;
}

int zbizhnist(double a, double b) {
	double max;

	if (peretvfuncp(a) > 0) { //знак похідної вказує на абсцису її максимуму на проміжку 
		max = fabs(peretvfuncp(b));
	}
	else {
		max = fabs(peretvfuncp(a));
	}

	if (max < 1) { //умова збіжності ітераційного процесу
		printf("\nThe process is convergent.\n");
		return 1;
	}
	else {
		printf("\nThe process is NOT convergent!\n");
		return 0;
	}
}



int main() {
	int A, B, C, D;
	double a, b;
	double eps;

	FILE* fp = fopen("input.txt", "r"); //зчитування вхідних даних з файлу
	char buffer[N];

	fgets(buffer, N, fp);
	strtok(buffer, "=");
	a = atof(strtok(NULL, "="));
	b = atof(strtok(NULL, "="));
	fgets(buffer, N, fp);
	strtok(buffer, "=");
	eps = atof(strtok(NULL, "="));

	fclose(fp);

	if (!check(a, b) || eps <= 0) return -1; //перевірка на коректність вхідних даних

	dyhotomia(a, b, eps);
	hordy(a, b, eps);
	niutona(a, b, eps);
	prostoyiiteratsiyi(a, b, eps);

	return 0;
}
