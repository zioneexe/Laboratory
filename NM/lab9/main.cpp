#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

#define N 6

using namespace std;

void Polynomials(vector<double> X,vector<double> Y, int m);
vector<double> Gausa(vector<vector<double>> A, vector<double> B);
void printMatr(vector<vector<double>> matr);
void printMatr1D(vector<double>);
void printTable(vector<double> X, vector<double> Y);
void printSystem(vector<vector<double>> A, vector<double> B, int m);

void printMatr(vector<vector<double>> matr) {
	cout << endl;
	for (const auto& rows : matr) {
		cout << "|";
		for (const auto& element : rows) {
			cout << setprecision(4) << fixed << element << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void printMatr1D(vector<double> matr) {
	cout << endl;
	for (const auto& elem : matr) {
		cout << "|" << setprecision(4) << fixed << elem << "|" << endl;
	}
	cout << endl;
}

void printTable(vector<double> X, vector<double> Y) {
	cout << endl;
	cout << "|X |";
	for (const auto& elem : X) {
		cout << noshowpos << setprecision(4) << fixed << elem << " |";
	}
	cout << endl;
	cout << "|Y |";
	for (const auto& elem : Y) {
		cout << noshowpos << setprecision(4) << fixed << elem << " |";
	}
	cout << endl;
}

void printSystem(vector<vector<double>> A, vector<double> B, int m) {
	assert(A.size() == m + 1);
	assert(B.size() == m + 1);

	cout << endl << "Ratio system of equations: " << endl;
	for (int i = 0; i <= m; ++i) {
		if (i == 0) {
			cout << "/";
		}
		else if (i == m) {
			cout << "\\";
		}
		else {
			cout << "|";
		}
		for (int j = 0; j <= m; ++j) {
			cout << (j == 0 ? noshowpos : showpos) << A[i][j] << "a" << noshowpos << j << " ";
		}
		cout << noshowpos << "= " << B[i] << endl;
	}
}

vector<double> Gausa(vector<vector<double>> A, vector<double> B) {
	cout << endl << ".. using Gaussian Method:" << endl << endl;

	int order = B.size();

	vector<double> koef(order), X(order);


	for (int k = 0; k < order - 1; ++k) {
		for (int i = k; i < order - 1; ++i) {
			koef[i] = -A[i + 1][k] / A[k][k];
			cout << noshowpos << "Koef (row " << i + 1 << "): " << koef[i];
			cout << endl;
		}
		cout << endl;

		for (int i = k + 1; i < order; ++i) {
			for (int j = 0; j < order; ++j) {
				A[i][j] += koef[i - 1] * A[k][j];
			}

			B[i] += koef[i - 1] * B[k];
			cout << "Matrix A" << endl;
			printMatr(A);
			cout << "Matrix B" << endl;
			printMatr1D(B);
		}
	}
	

	for (int i = order - 1; i >= 0; --i) {
		double sum = 0;
		for (int k = order - 1; k > i; --k) {
			sum += A[i][k] * X[k];
		}
		X[i] = 1 / A[i][i] * (B[i] - sum);
	}

	cout << "The result is: " << endl;
	for (int i = 0; i < order; ++i) {
		cout << "A" << i << " = " << X[i] << endl;
	}

	return X;
}


void Polynomials(vector<double> X, vector<double> Y, int m) {

	vector<vector<double>> eqA(m+1, vector<double>(m+1));
	vector<double> eqB(m + 1);
	double sum1 = 0, sum2 = 0;
	int n = X.size();

	printTable(X, Y);

	for (int k = 0; k < m + 1; ++k) {
		for (int j = 0; j < m + 1; ++j) {
			for (int i = 0; i < n; ++i) {
				sum1 += pow(X[i], j + k);
			}
			eqA[k][j] = sum1;
			sum1 = 0;
		}
		
		for (int i = 0; i < n; ++i) {
			sum2 += Y[i] * pow(X[i], k);
		}
		eqB[k] = sum2;
		sum2 = 0;
	}

	printSystem(eqA, eqB, m);

	vector<double> Koefs = Gausa(eqA, eqB);

	cout << endl << "P" << m << "(X) = " << Koefs[0] << " " << showpos << Koefs[1] << "x ";
	for (int i = 2; i < Koefs.size(); ++i) {
		cout << showpos << Koefs[i] << "x^" << noshowpos << i << " ";
	}

}

int main() {

	vector<double> fixedX = { 0.15, 0.2, 0.25, 0.3, 0.4, 0.5 };
	vector<double> fixedY = { 4.01, 3.78, 3.52, 3.42, 3.19, 2.95  };

	vector<double> X(N), Y(N);

	string choice;

	while (1) {
		cout << "Enter '0' to choose automatic mode or '1' to choose manual mode." << endl;
		cin >> choice;

		if (stoi(choice) == 0) {
			cout << endl << endl << "\t\t\t\tThe linear polynomial:" << endl;
			Polynomials(fixedX, fixedY, 1);
			cout << endl << endl << "\t\t\t\tThe quadratic polynomial:" << endl;
			Polynomials(fixedX, fixedY, 2);
			cout << endl << endl << "\t\t\t\tThe cubic polynomial:" << endl;
			Polynomials(fixedX, fixedY, 3);
			break;
		}
		else if (stoi(choice) == 1) {
			for (int i = 0; i < N; ++i) {
				cout << endl << "Enter x" << i + 1 << ": " << endl;
				cin >> X[i];
				cout << endl << "Enter y" << i + 1 << ": " << endl;
				cin >> Y[i];
			}

			cout << endl << endl << "\t\t\t\tThe linear polynomial:" << endl;
			Polynomials(X, Y, 1);
			cout << endl << endl << "\t\t\t\tThe quadratic polynomial:" << endl;
			Polynomials(X, Y, 2);
			cout << endl << endl << "\t\t\t\tThe cubic polynomial:" << endl;
			Polynomials(X, Y, 3);
			break;
		}
		else {
			cout << endl << "Incorrect option!" << endl;
		}
	}

	return 0;
}