#define _CRT_SECURE_NO_WARNINGS
#define N 10
#define LINE_SIZE 103
#define P 4

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <float.h>
#include <iomanip>

using namespace std;

void printmatr(double arr[N][N], double m, double n);
void printmatr1D(double arr[N], double n);
int yakobi(double A[N][N], double B[N], double eps);
int zeydelya(double A[N][N], double B[N], double eps);
void printLine(int len);
int normyzbizhnosti(double A[N][N], double B[N]);
int checkorder(double B[N]);

void printmatr(double arr[N][N], double m, double n) {
	cout << endl;
	for (int i = 0; i < m; ++i) {
		cout << "|| ";
		for (int j = 0; j < n; ++j) {
			printf("%+3.2lf ", arr[i][j]);
		}
		cout << "||" << endl;
	}
	cout << endl;
}

void printmatr1D(double arr[N], double n) {
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "|| ";
		printf("%+3.2lf ", arr[i]);
		cout << "||" << endl;
	}
	cout << endl;
}

void printLine(int len) {
	for (int i = 0; i < len; i++)
	{
		putchar('=');
	}
	putchar('\n');
}

int checkorder(double B[N]) { //перевірка порядку матриці, а, отже, і кількості рівнянь та невідомих
	int order = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (B[i] != 0) {
			order = i + 1;
			break;
		}
	}

	return order;
}

int normyzbizhnosti(double A[N][N], double B[N]) { //перевірка норм збіжності
	int order = checkorder(B), flag = 0, f1 = 1, f2 = 1, f3 = 1;

	double Alpha[N][N] = { 0 };

	for (int i = 0; i < order; ++i) {
		for (int j = 0; j < order; ++j) {
			if (i != j) {
				Alpha[i][j] = -A[i][j] / A[i][i];
			}
		}
	}

	//сума рядків або стовпців
	
	for (int i = 0; i < order; ++i) {
		double sum = 0;
		for (int j = 0; j < order; ++j) {
			sum += abs(Alpha[i][j]);
			if (sum >= 1) {
				f1 = 0;
			}
		}
	}

	for (int i = 0; i < order; ++i) {
		double sum = 0;
		for (int j = 0; j < order; ++j) {
			sum += abs(Alpha[j][i]);
			if (sum >= 1) {
				f2 = 0;
			}
		}
	}

	//діагональна перевага

	for (int i = 0; i < order; ++i) {
		double sum = 0;
		for (int j = 0; j < order; ++j) {
			if (i != j) {
				sum += abs(A[i][j]);
			}
		}
		if (sum > abs(A[i][i])) { f3 = 0; }
	}

	if (f1 || f2 || f3) { flag = 1; }

	return flag;
}

int yakobi(double A[N][N], double B[N], double eps) {
	if (!normyzbizhnosti(A, B)) {
		cout << "The process is not convergent!" << endl;
		return -1;
	}
	else {
		cout << endl << "\t\t\t\t\t\t//Jacobi Method//" << endl << endl;
	}
	
	int order = checkorder(B);
	
	double Xprev[N] = { 0 }, X[N] = { 0 }, Alpha[N][N] = { 0 }, Beta[N] = { 0 };


	for (int i = 0; i < order; ++i) {
		for (int j = 0; j < order; ++j) {
			if (i != j) {
				Alpha[i][j] = -A[i][j] / A[i][i];
			}
		}
		Beta[i] = B[i] / A[i][i];
		Xprev[i] = Beta[i];
	}

	cout << "Alpha matrix:" << endl;
	printmatr(Alpha, order, order);
	cout << "Beta matrix:" << endl;
	printmatr1D(Beta, order);

	cout << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << "(0) = " << Xprev[i] << " ";
	}
	cout << endl << endl;

	cout << "\t\t\t\t\t\tCalculation process" << endl;

	printLine(LINE_SIZE);
	cout << "\tk\t\tX1(k)\t\tX2(k)\t\tX3(k)\t\tX4(k)\t\t|X(k)-X(k-1)|" << endl;
	printLine(LINE_SIZE);
	cout << "\t0\t\t";
	for (int i = 0; i < order; ++i) {
		cout << fixed << setprecision(P) << Xprev[i] << "\t\t";
	}
	cout << "-" << endl;

	double sum = DBL_MAX, sum1=0, sum2=0;
	int cnt = 1;

	while (sum >= eps && cnt < 100) { //перевірка точності та обмеження кількості ітерацій (100)

		sum = 0;

		for (int i = 0; i < order; ++i) {
			
			for (int j = 0; j < i; ++j) {
				sum1 += Alpha[i][j] * Xprev[j];
			}
			for (int j = i; j < order; ++j) {
				sum2 += Alpha[i][j] * Xprev[j];
			}
			X[i] = Beta[i] + sum1 + sum2;
			
			
			sum += pow(X[i] - Xprev[i], 2.0);
			
			Xprev[i] = X[i];
			sum1 = 0; sum2 = 0;
		}
	
		sum = sqrt(sum);

		cout << "\t" << cnt << "\t\t";
		for (int i = 0; i < order; ++i) {
			cout << fixed << setprecision(P) << X[i] << "\t\t";
		}
		cout << sum << endl;

		++cnt;
	}
	printLine(LINE_SIZE);

	cout << "\nThe result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << " = " << X[i] << " +- " << eps << endl;
	}

	return cnt;
}

int zeydelya(double A[N][N], double B[N], double eps) {
	if (!normyzbizhnosti(A, B)) {
		cout << "The process is not convergent!" << endl;
		return -1;
	}
	else {
		cout << endl << "\t\t\t\t\t\t//Seidel Method//" << endl << endl;
	}

	int order = checkorder(B);

	double Xprev[N] = { 0 }, X[N] = { 0 }, Alpha[N][N] = { 0 }, Beta[N] = { 0 };


	for (int i = 0; i < order; ++i) {
		for (int j = 0; j < order; ++j) {
			if (i != j) {
				Alpha[i][j] = -A[i][j] / A[i][i];
			}
		}
		Beta[i] = B[i] / A[i][i];
		Xprev[i] = Beta[i];
	}

	cout << "Alpha matrix:" << endl;
	printmatr(Alpha, order, order);
	cout << "Beta matrix:" << endl;
	printmatr1D(Beta, order);

	cout << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << "(0) = " << Xprev[i] << " ";
	}
	cout << endl << endl;

	cout << "\t\t\t\t\t\tCalculation process" << endl;
	printLine(LINE_SIZE);
	cout << "\tk\t\tX1(k)\t\tX2(k)\t\tX3(k)\t\tX4(k)\t\t|X(k)-X(k-1)|" << endl;
	printLine(LINE_SIZE);
	cout << "\t0\t\t";
	for (int i = 0; i < order; ++i) {
		cout << fixed << setprecision(P) << Xprev[i] << "\t\t";
	}
	cout << "-" << endl;

	double sum = DBL_MAX, sum1 = 0, sum2 = 0;
	int cnt = 1;

	while (sum >= eps && cnt < 100) { //перевірка точності та обмеження кількості ітерацій (100)

		sum = 0;

		for (int i = 0; i < order; ++i) {

			for (int j = 0; j < i; ++j) {
				sum1 += Alpha[i][j] * X[j]; //модифікація для методу Зейделя, який бере k-те наближення
			}
			for (int j = i; j < order; ++j) {
				sum2 += Alpha[i][j] * Xprev[j];
			}
			X[i] = Beta[i] + sum1 + sum2;


			sum += pow(X[i] - Xprev[i], 2.0);

			Xprev[i] = X[i];
			sum1 = 0; sum2 = 0;
		}

		sum = sqrt(sum);

		cout << "\t" << cnt << "\t\t";
		for (int i = 0; i < order; ++i) {
			cout << fixed << setprecision(P) << X[i] << "\t\t";
		}
		cout << sum << endl;

		++cnt;
	}
	printLine(LINE_SIZE);

	cout << "\nThe result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << " = " << X[i] << " +- " << eps << endl;
	}

	return cnt;
}

int main() {
	double rA[N][N] = { 0 }, rB[N] = { 0 }, eps=0.001, reps;

	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%lf", &reps);
	for (int i = 0; i < 4; ++i) {
		fscanf(fp, "%lf %lf %lf %lf %lf", &rA[i][0], &rA[i][1], &rA[i][2], &rA[i][3], &rB[i]);
	}

	fclose(fp);

	double A[N][N] = {
		//{0.84, 0.23, 0.18, 0.17 },
		//{0.12, -0.54, 0.08, 0.09 },
		//{0.16, 0.24, -0.45, 0},
		//{0.23, -0.08, 0.05, 1.25}
		{0.97, 0.31, -0.18, 0.22},
		{-0.21, 2.18, -0.33, 0.22},
		{0.32, -0.81 , 0.85, -0.19},
		{0.12, 0.28, -0.14, 2.29}
	};

	double B[N] = {
		//-1.42,
		//0.83,
		//1.21,
		//-0.65
		-1.71, 0.62, -0.89, 0.94
	};

	int order = checkorder(B);
	cout << "Matrix A:" << endl;
	printmatr(A, order, order);
	cout << "Matrix B:" << endl;
	printmatr1D(B, order);

	int cnt1 = yakobi(A, B, reps);
	int cnt2 = zeydelya(A, B, reps);

	cout << "\nThe number of iterations in Jacobi Method: " << cnt1 << endl;
	cout << "The number of iterations in Seidel Method: " << cnt2 << endl;
	if (cnt1 == -1 || cnt2 == -1) { return -1; }
	if (cnt1 > cnt2) {
		cout << "\nSeidel method has better convergence." << endl;
	}
	else if (cnt1 == cnt2) {
		cout << "The number of iterations is equal." << endl;
	}
	else {
		cout << "\nJacobi method has better convergence." << endl;
	}

	return 0;
}