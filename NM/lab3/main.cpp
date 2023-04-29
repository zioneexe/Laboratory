#define _CRT_SECURE_NO_WARNINGS
#define N 4

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void printmatr(double arr[N][N], double m, double n);
double det2x2(double arr[N][N]);
double det3x3(double arr[N][N]);
double det(double arr[N][N], int n);
void kramera(double extmatr[N][N]);
void obernenojimatrytsi(double extmatr[N][N]);
int checkorder(double arr[N][N]);
void minor(double arr[N][N], double temp[N][N], int a, int b);

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

int checkorder(double arr[N][N]) {
	int order = 0;

	for (int i = N - 1; i >= 0; --i) {
		for (int j = N - 1; j >= 0; --j) {
			if (arr[i][j] != 0) {
				order = j + 1;
				break;
			}
		}
	}

	return order;
}

double det2x2(double arr[N][N]) {
	return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
}
double det3x3(double arr[N][N]) {
	return arr[0][0] * arr[1][1] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0] + arr[1][0] * arr[2][1] * arr[0][2] - arr[2][0] * arr[1][1] * arr[0][2] - arr[1][0] * arr[0][1] * arr[2][2] - arr[0][0] * arr[2][1] * arr[1][2];
}

void minor(double arr[N][N], double temp[N][N], int a, int b) {
	int order = checkorder(arr);

	for (int i = 0; i < order; ++i) {
		for (int j = 0; j < order; ++j) {
			if (i == a || j == b) { continue; }
			temp[i][j] = arr[i][j];
		}
	}
}

double det(double arr[N][N], int n) {
	double D = 0;

	if (n == 1) {
		return arr[0][0];
	}
	else {
		double temp[N][N];
		int sign = 1;
		--n;
		for (int i = 0, j = 0; j < n; ++j) {
			minor(arr, temp, i, j);
			D += sign * arr[0][j] * det(temp, n);
			sign = -sign;
		}
	}
	return D;
}

void kramera(double extmatr[N][N]) {
	cout << "\n\t\t-------------Cramer's Method-------------\t\t\n" << endl;

	double matr[N][N] = {0}, matrx1[N][N] = {0}, matrx2[N][N] = {0}, matrx3[N][N] = {0}, barray[N] = {0};

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j == 3) { 
				barray[i] = extmatr[i][j];
			}
			else {
				matr[i][j] = extmatr[i][j];
				matrx1[i][j] = extmatr[i][j];
				matrx2[i][j] = extmatr[i][j];
				matrx3[i][j] = extmatr[i][j];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j == 0) {
				matrx1[i][j] = barray[i];
			}

			if (j == 1) {
				matrx2[i][j] = barray[i];
			}

			if (j == 2) {
				matrx3[i][j] = barray[i];
			}
		}
	}


	double x1 = det3x3(matrx1) / det(matr, 3);
	double x2 = det3x3(matrx2) / det(matr, 3);
	double x3 = det3x3(matrx3) / det(matr, 3);

	cout << "Matrix A: " << endl;
	printmatr(extmatr, 3, 4);
	cout << endl;
	cout << "det A = " << det3x3(matr) << endl;
	printmatr(matr, 3, 3);
 
	cout << "det A1 = " << det3x3(matrx1) << endl;
	printmatr(matrx1, 3, 3); 

	cout << "det A2 = " << det3x3(matrx2) << endl;
	printmatr(matrx2, 3, 3);

	cout << "det A3 = " << det3x3(matrx3) << endl;
	printmatr(matrx3, 3, 3);

	cout << "The result is: \n\n" << "x1 = det A1/det A = " << x1 << "\nx2 = det A2/det A = " << x2 << "\nx3 = det A3/det A = " << x3 << endl;
}

void obernenojimatrytsi(double extmatr[N][N]) {
	cout << "\n\t\t-------------The Inverse Matrix Method-------------\t\t\n" << endl;
	
	double matr[N][N] = { 0 }, barray[N] = { 0 };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j == 3) {
				barray[i] = extmatr[i][j];
			}
			else {
				matr[i][j] = extmatr[i][j];
			}
		}
	}
	
	if (det3x3(matr) == 0) {
		cout << "Determinant equals zero!" << endl;
		return;
	}
	else cout << endl << "det A = " << det3x3(matr) << " !=0 - inverse matrix exists" << endl << endl;

	double cofactormatr[N][N];

	double minor[N][N];

	int sign = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			//cofactormatr[i][j] = sign*
			sign = -sign;
		}
	}
}

int main() {
	
	double extmatr[N][N];


	FILE* fp = fopen("input.txt", "r");

	for (int i = 0; i < 3; ++i) {
		fscanf(fp, "%lf %lf %lf %lf", &extmatr[i][0], &extmatr[i][1], &extmatr[i][2], &extmatr[i][3]);
	}

	fclose(fp);

	kramera(extmatr);
	obernenojimatrytsi(extmatr);

	return 0;
}