#define _CRT_SECURE_NO_WARNINGS
#define N 10
#define P 1

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <float.h>
#include <iomanip>

using namespace std;

void printmatr(double arr[N][N], double m, double n);
void printmatr1D(double arr[N], double n);
int checkorder(double C[N]);
void leastsquares(double A[N][N], double B[N], int num);
double det3x3(double arr[N][N]) { return arr[0][0] * arr[1][1] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0] + arr[1][0] * arr[2][1] * arr[0][2] - arr[2][0] * arr[1][1] * arr[0][2] - arr[1][0] * arr[0][1] * arr[2][2] - arr[0][0] * arr[2][1] * arr[1][2]; }

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

int checkorder(double C[N]) {
	int order = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (C[i] != 0) {
			order = i + 1;
			break;
		}
	}

	return order;
}

void leastsquares(double A[N][N], double B[N], int num) {
	double AT[N][N] = { 0 }, matrN[N][N] = { 0 }, matrC[N] = { 0 }, L[N][N] = { 0 }, LT[N][N] = { 0 }, X[N] = { 0 }, Y[N] = { 0 };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			AT[i][j] = A[j][i];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < N; ++k) {
			matrC[i] += AT[i][k] * B[k];
			for (int j = 0; j < N; ++j) {
				matrN[i][j] += AT[i][k] * A[k][j];
			}
		}
	}
	
	int order = checkorder(matrC);
	
	cout << "Matrix A: " << endl;
	printmatr(A, num, order);
	
	cout << "Matrix B: " << endl;
	printmatr1D(B, num);
	
	cout << endl << "N = ATA" << endl << endl;

	cout << "Matrix N: " << endl;
	printmatr(matrN, order, order);

	cout << endl << "C = ATB" << endl << endl;

	cout << "Matrix C: " << endl;
	printmatr1D(matrC, order);

	cout << endl << "NX = C" << endl << endl;

	if (det3x3(matrN) <= 0) {
		cout << endl << "Determinant of N matrix is not > 0. Using this method for the system of equations is irrational." << endl;
		exit(1);
	}
	else {
		cout << endl << "det N = " <<  det3x3(matrN) << " > 0." << endl;
		cout << endl << "We will use Cholesky decomposition." << endl << endl;
	}

	for (int i = 0; i < order; ++i) {
		for (int k = 0; k < order; ++k) {
			if (i < k) {
				L[i][k] = 0;
			}
	
			else if (i == k) {
				double sum1 = 0;
				for (int m = 1; m < k; ++m) {
					sum1 += pow(L[k][m], 2.0);
				}
				L[i][k] = sqrt(matrN[i][k] - sum1);
			}
			else {
				double sum2 = 0;
				for (int m = 1; m < k; ++m) {
					sum2 += L[i][m]*L[k][m];
				}
				L[i][k] = (matrN[i][k]-sum2) / L[k][k];
			}
		}
	}

	cout << "Matrix L: " << endl;
	printmatr(L, order, order);

	for (int i = 0; i < order; ++i) {
		for (int j = 0; j < order; ++j) {
			LT[i][j] = L[j][i];
		}
	}

	cout << "Matrix LT (transpose): " << endl;
	printmatr(LT, order, order);

	cout << endl <<"LY = C" << endl << endl;

	for (int i = 0; i < order; ++i) {
		double sum = 0;
		for (int m = 1; m < i + 1; ++m) {
			sum += L[i][m - 1] * Y[m - 1];
		}
		Y[i] = (matrC[i] - sum) / L[i][i];
	}

	for (int i = 0; i < order; ++i) {
		cout << fixed << setprecision(P) << "Y" << i + 1 << " = " << Y[i] << " ";
	}

	cout << endl << endl << "LTX = Y" << endl << endl;

	for (int i = order - 1; i >= 0; --i) {
		double sum = 0;
		for (int m = order; m > i; --m) {
			sum += LT[i][m - 1] * X[m - 1];
		}
		X[i] = (Y[i] - sum) / L[i][i];
	}

	cout << "The result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << fixed << setprecision(P) << "X"  << i + 1 << " = " << X[i] << endl;
	}

}

int main() {
	double rA[N][N] = { 0 }, rB[N] = { 0 };
	int num = 5, rNum=0;

	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &rNum);
	for (int i = 0; i < rNum; ++i) {
		fscanf(fp, "%lf %lf %lf %lf", &rA[i][0], &rA[i][1], &rA[i][2], &rB[i]);
	}

	fclose(fp);

	double A[N][N] = {
		{1, 3, -2},
		{-1, 2, 1},
		{3, -2, -2},
		{3, 1, -3},
		{1, -1, -7}
	};

	double B[N] = {
		-5,
		1,
		-5,
		1,
		5
	};

	leastsquares(rA, rB, rNum);

	return 0;
}