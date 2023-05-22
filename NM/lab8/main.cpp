#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

double Factorial(int n);
void Lagranja(double X[N], double Y[N], double X0);
void Niutona(double X[N], double Y[N], double X0);
bool check(double X[N]);

bool check(double X[N]) {
	double dx = X[1] - X[0];
	for (int i = 1; i < N; ++i) {
		if (abs((X[i] - X[i-1]) - dx) > 0.0000001) return false;
	}

	return true;
}


void Lagranja(double X[N], double Y[N], double X0) {
	std::cout << "\tLagrange's Polynomial" << std::endl;
	
	double C[N], result = 0, h = X[1] - X[0], t = (X0 - X[0]) / h, Step[N], sum = 0, P = 1;

	std::cout << "|i\t|X\t|Y\t|t-1\t|C(i)\t\t|(t-1)C(i)\t|y/(t-1)C(i)" << std::endl;
	for (int i = 0; i < N; ++i) {
		C[i] = Factorial(i) * Factorial(N - 1 - i) * pow(-1, N - 1 - i);
		Step[i] = Y[i] / ((t - i) * C[i]);
		std::cout << std::setprecision(3) << std::fixed << "|" << i << "\t|" << X[i] << "\t|" << Y[i] << "\t|" << t - i << "\t|" << C[i] << "\t|" << (t - i) * C[i] << "\t|" << std::setprecision(4) << Step[i] << std::endl;
		result += Step[i];
		P *= t - i;
	}

	result *= P;

	std::cout << std::endl << "The result is: " << result << std::endl;
}

void Niutona(double X[N], double Y[N], double X0) {

	std::cout << "\tNewton's Polynomial" << std::endl;

	double result = 0, Xmin = X[0], Xmax = X[N-1], Xavg = (Xmin + Xmax) / 2, h = X[1] - X[0], qKoef = 1;

	std::cout << std::endl << "Table of finite differences." << std::endl;

	std::cout << "|i\t|X\t|Y\t|d^1Y\t|d^2Y\t|d^3Y\t|d^4Y\t|d^5Y\t|d^6Y\t|d^7Y\t|d^8Y\t|d^9Y" << std::endl;
	
	
	double tableOfDif[N-1][N-1] = {0};
	
	for (int i = 0; i < N-1; ++i) {
		tableOfDif[i][0] = Y[i + 1] - Y[i];
	}

	for (int i = N - 3; i >= 0; --i) {
		for (int k = 1; k < N; ++k) {
			tableOfDif[i][k] = tableOfDif[i+1][k-1] - tableOfDif[i][k-1];
		}
	}

	for (int i = 0; i < N; ++i) {
		std::cout << std::setprecision(3) << std::fixed << "|" << i << "\t|" << X[i] << "\t|" << Y[i] << "\t";
		for (int k = 0; k < N-i-1; ++k) {
			std::cout << "|" << tableOfDif[i][k] << "\t";
		}
		std::cout << std::endl;
	}


	if (X0 < Xavg) {
		std::cout << std::endl << "Using forward interpolation: " << std::endl;
		result = Y[0];
		double qF = (X0 - X[0]) / h;
		for (int i = 0; i < N-1; ++i) {
			qKoef *= qF - i;
			result += qKoef * tableOfDif[0][i] / Factorial(i + 1);
		}

		std::cout << std::endl << "The result is: " << std::setprecision(4) << result << std::endl;

	}
	else {
		std::cout << "\t\tUsing backward interpolation: " << std::endl;
		result = Y[N-1];
		double qB = (X0 - X[N-1]) / h;
		for (int i = N - 2, k = 0; i >= 0 and k < N - 1; --i, ++k) {
				qKoef *= qB + k;
				result += qKoef * tableOfDif[i][k] / Factorial(k + 1);
		}

		std::cout << std::endl << "The result is: " << result << std::endl;

	}

}

double Factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else return n*Factorial(n-1);
}

int main() {

	double fixedX[N]{ 3.60, 3.65, 3.70, 3.75, 3.80, 3.85, 3.90, 3.95, 4.00, 4.05 };
	double fixedY[N]{ 4.26, 4.35, 4.46, 4.56, 4.67, 4.79, 4.91, 5.01, 5.18, 5.31 };
	double fixedX0 = 3.771;
	
	double X[N], Y[N], X0;

	std::string choice;

	while (1) {
		std::cout << "Enter '0' to choose automatic mode or '1' to choose manual mode." << std::endl;
		std::cin >> choice;

		if (stoi(choice) == 0) {


			if (!check(fixedX)) {
				std::cout << "The nodes are not equidistant!" << std::endl;
				return 0;
			}

			Lagranja(fixedX, fixedY, fixedX0);
			Niutona(fixedX, fixedY, fixedX0);
			break;
		}
		else if (stoi(choice) == 1) {
			for (int i = 0; i < N; ++i) {
				std::cout << std::endl << "Enter x" << i + 1 << ": " << std::endl;
				std::cin >> X[i];
				std::cout << std::endl << "Enter y" << i + 1 << ": " << std::endl;
				std::cin >> Y[i];
			}


			std::cout << "Enter x0: " << std::endl;
			std::cin >> X0;

			if (!check(X)) {
				std::cout << "The nodes are not equidistant!" << std::endl;
				return 0;
			}

			Lagranja(X, Y, X0);
			Niutona(X, Y, X0);
			break;
		}
		else {
			std::cout << std::endl << "Incorrect option!" << std::endl;
		}
	}

	return 0;
}