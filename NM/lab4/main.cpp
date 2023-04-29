#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <float.h>

using namespace std;

void printmatr(double arr[N][N], double m, double n);
void gausa(double A[N][N], double B[N]);
void LUrozklad(double A[N][N], double B[N]);
int checkorder(double B[N]);

int checkorder(double B[N]) {
	int order = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (B[i] != 0) {
			order = i + 1;
			break;
		}
	}

	return order;
}

void printmatr(double arr[N][N], double m, double n) {
	cout << endl;
	for (int i = 0; i < m; ++i) {
		cout << "|| ";
		for (int j = 0; j < n; ++j) {
			printf("%+3.3lf ", arr[i][j]);
		}
		cout << "||" << endl;
	}
	cout << endl;
}

void printmatr1D(double arr[N], double n) {
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "|| ";
		printf("%+3.3lf ", arr[i]);
		cout << "||" << endl;
	}
	cout << endl;
}

void gausa(double A[N][N], double B[N]) {
	cout << endl << "\t\t\t\t\t\t//Gaussian Method//" << endl;
	cout << "...with main element choice" << endl << endl;

	int order = checkorder(B);

	double max = -DBL_MAX;
	int maxrow = 0;
	double koef[N] = { 0 }, X[N] = { 0 };

	for (int k = 0; k < order - 1; ++k) {
		for (int i = 0; i < order; ++i) {
			if (abs(A[i][k]) > max) {
				max = A[i][k];
				maxrow = i;
			}
		}

		for (int j = 0; j < order; ++j) {
			double temp[N], tempB;

			temp[j] = A[k][j];
			A[k][j] = A[maxrow][j];
			A[maxrow][j] = temp[j];

			tempB = B[k];
			B[k] = B[maxrow];
			B[maxrow] = tempB;
		}

		for (int i = k; i < order-1; ++i) {
			koef[i] = -A[i+1][k] / A[k][k];
			cout << "Koef (row " << i + 1 << "): " << koef[i];
			cout << endl;
		}
		cout << endl;

		for (int i = k+1; i < order; ++i) {
			for (int j = 0; j < order; ++j) {
				A[i][j] += koef[i-1] * A[k][j];
			}
			B[i] += koef[i-1] * B[k];
			cout << "Column " << k + 1 << ": " << endl << endl;
			cout << "Matrix A";
			printmatr(A, order, order);
			cout << "Matrix B";
			printmatr1D(B, order);
		}
	}

	for (int i = order-1; i>=0; --i) {
		double sum = 0;
		for (int k = order-1; k > i; --k) {
			sum += A[i][k] * X[k];
		}
		X[i] = 1 / A[i][i] * (B[i] - sum);
	}

	cout << "The result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << " = " << X[i] << endl;
	}
}

void LUrozklad(double A[N][N], double B[N]) {
	cout << endl << "\t\t\t\t\t\t//LU factorization method//" << endl << endl;


	int order = checkorder(B);

	double L[N][N] = { 0 }, U[N][N] = { 0 }, X[N] = { 0 }, Y[N] = { 0 };

	for (int k = 0; k < order; ++k) {
		for (int i = k; i < order; ++i) {
			double sum = 0;
			for (int m = 0; m < k; ++m) {
				sum += L[i][m] * U[m][k];
			}
			L[i][k] = A[i][k] - sum;
		}
		for (int j = k + 1; j < order; ++j) {
			double sum = 0;
			for (int m = 0; m < k; ++m) {
				sum += L[k][m] * U[m][j];
			}
			U[k][j] = (A[k][j] - sum) / L[k][k];
		}
		U[k][k] = 1;
	}

	cout << "Matrix L" << endl;
	printmatr(L, order, order);
	cout << "Matrix U" << endl;
	printmatr(U, order, order);

	cout << "LY = B" << endl;
	

	for (int i = 0; i < order; ++i) {
		double sum = 0;
		for (int m = 1; m < i+1; ++m) {
			sum += L[i][m-1] * Y[m-1];
		}
		Y[i] = 1 / L[i][i] * (B[i] - sum);
	}

	cout << endl;
	for (int i = 0; i < order; ++i) {
		cout << "Y" << i + 1 << " = " << Y[i] << " ";
	}
	cout << endl << endl;

	cout << "UX = Y" << endl;


	for (int i = order - 1; i >= 0; --i) {
		double sum = 0;
		for (int m = order; m > i; --m) {
			sum += U[i][m-1] * X[m-1];
		}
		X[i] = Y[i] - sum;
	}

	cout << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << " = " << X[i] << " ";
	}
	cout << endl << endl;

	cout << "The result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << "X" << i + 1 << " = " << X[i] << endl;
	}
}

int main() {


	double rA[N][N] = { 0 }, rB[N] = { 0 };

	FILE* fp = fopen("input.txt", "r");


	for (int i = 0; i < 3; ++i) {
		fscanf(fp, "%lf %lf %lf %lf", &rA[i][0], &rA[i][1], &rA[i][2], &rB[i]);
	}

	fclose(fp);

	double A[N][N] = {
	{1.26, -2.34, 1.17 },
	{0.75, 1.24, -0.48},
	{3.44, -1.85, 1.16}
	};

	double B[N] = {
		3.14,
		-1.17,
		1.83
	};

	gausa(rA, rB);
	LUrozklad(rA, rB);

	return 0;
}