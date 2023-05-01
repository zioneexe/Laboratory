#define _CRT_SECURE_NO_WARNINGS
#define N 10
#define P 4

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <float.h>
#include <iomanip>

using namespace std;

double det2x2(double arr[N][N]);
void printLine(int len);
void iteratsii(double x0, double y0, double eps);
void niutona(double x0, double y0, double eps);

void printLine(int len) {
	for (int i = 0; i < len; i++)
	{
		putchar('=');
	}
	putchar('\n');
}

double det2x2(double arr[N][N]) {
	return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
}

double func1(double x, double y) {
	return sin(y) + 2 * x - 2;
}

double func2(double x, double y) {
	return cos(x - 1) + y - 0.7;
}

double dfunc1dx(double x, double y, bool mode) {
	if (mode) return 2;
	else 	return 0;
}

double dfunc1dy(double x, double y, bool mode) {
	if (mode) return cos(y);
	else return -sin(x - 1);
}

double dfunc2dx(double x, double y, bool mode) {
	if (mode) return -sin(x - 1);
	else return cos(y) / 2;
}

double dfunc2dy(double x, double y, bool mode) {
	if (mode) return 1;
	else 	return 0;
}

void iteratsii(double x0, double y0, double eps) {
	double xprev = x0, x = x0;
	double yprev = y0, y = y0;

	if ((abs(dfunc1dx(xprev, yprev, 0)) + abs(dfunc2dx(xprev, yprev, 0)) >= 1) 
		or (abs(dfunc1dy(xprev, yprev, 0))+ abs(dfunc2dy(xprev, yprev, 0)) >= 1)) {
		cout << "The process is not convergent!" << endl;
		return;
	}

	cout << endl << "//Iterations method//" << endl << endl;

	cout << "Calculations: " << endl;
	printLine(48);
	cout << "|iteration\t\t|x\t\t|y" << endl;
	printLine(48);
	
	int iteration = 0;
	do {
		xprev = x;
		yprev = y;

		x = 1 - sin(yprev) / 2;
		y = 0.7 - cos(xprev - 1);
		cout << "|" << iteration << "\t\t\t|" << setprecision(P) << fixed << x << "\t\t|" << y << endl;
		++iteration;
	} while (abs(x-xprev) + abs(y-yprev) >= eps);

	cout << endl << "\nThe result is: " << endl;
	cout << "x = " << x << "; y = " << y << endl;
}

void niutona(double x0, double y0, double eps) {
	double xprev = x0, x = x0, dx;
	double yprev = y0, y = y0, dy;
	double Jacobi[N][N] = { { dfunc1dx(xprev, yprev, 1), dfunc1dy(xprev, yprev, 1) }, {dfunc2dx(xprev, yprev, 1), dfunc2dy(xprev, yprev, 1)} };
	double det, detx, dety;

	cout << endl << "//Newton's method//" << endl << endl;

	cout << "Calculations: " << endl;
	printLine(48);
	cout << "|iteration\t\t|x\t\t|y" << endl;
	printLine(48);

	if (det2x2(Jacobi) == 0) {
		cout << "Determinant equals zero!" << endl;
		return;
	}

	int iteration = 0;
	do {
		xprev = x;
		yprev = y;
		
		det = det2x2(Jacobi);

		Jacobi[0][0] = func1(x, y);
		Jacobi[1][0] = func2(x, y);

		detx = det2x2(Jacobi);

		Jacobi[0][0] = dfunc1dx(x, y, 1);
		Jacobi[1][0] = dfunc2dx(x, y, 1);

		Jacobi[0][1] = func1(x, y);
		Jacobi[1][1] = func2(x, y);

		dety = det2x2(Jacobi);

		Jacobi[0][1] = dfunc1dy(x, y, 1);
		Jacobi[1][1] = dfunc2dy(x, y, 1);

		dx = -1 / det * detx;
		dy = -1 / det * dety;
		
		x = xprev+dx;
		y = yprev+dy;

		cout << "|" << iteration << "\t\t\t|" << setprecision(P) << fixed << x << "\t\t|" << y << endl;
		++iteration;
	} while (abs(x - xprev) + abs(y - yprev) >= eps);

	cout << endl <<"\nThe result is: " << endl;
	cout << "x = " << x << "; y = " << y << endl;
}

int main() {
	double x0, y0, eps;

	cout << "Enter initial value of x and y: " << endl;
	cin >> x0 >> y0;

	cout << "Enter epsilon (eps > 0): " << endl;
	cin >> eps;

	iteratsii(x0, y0, eps);
	niutona(x0, y0, eps);

	return 0;
}