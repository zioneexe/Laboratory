#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

void RectangularsRule(double a, double b, int n);
void TrapezoidalRule(double a, double b, int n);
void SimpsonsRule(double a, double b, int n);
double Func(double x);
void printMatr1D(vector<double> matr);
vector<vector<double>> getTable(double a, double b, int n);

double Func(double x) {
	return sqrt(pow(x, 3)) * sin(M_PI * x / 2);
}

double Func2P(double x) {
	return (3 * sqrt(x) * sin((M_PI * x) / 2)) / 2 + (M_PI * pow(x,(3 / 2)) * cos((M_PI * x) / 2)) / 2;
}

double Func4P(double x) {
	return -((9 * pow(M_PI, 2) * pow(x, 2) + 3) * sin((M_PI * x) / 2) + (pow(M_PI, 3) * pow(x, 3) - 9 * M_PI * x) * cos((M_PI * x) / 2)) / (8 * pow(x, (3 / 2)));
}

void printMatr1D(vector<double> matr) {
	cout << endl;
	for (const auto& elem : matr) {
		cout << setprecision(4) << fixed << elem << endl;
	}
}

vector<vector<double>> getTable(double a, double b, int n) {
	cout << "|i\t|X\t|Y" << endl;
	int i = 0;
	double h = (b - a) / n;
	double X = a;

	vector<vector<double>> Table (3, vector<double>(n + 1));

	do {
		Table[0][i] = i;
		Table[1][i] = X;
		Table[2][i] = Func(X);
		X += h;
		++i;
		cout << "|" << i << "\t|" << setprecision(4) << fixed << X << "\t|" << Func(X) << endl;
	} while (X <= b);


	return Table;
}

void RectangularsRule(double a, double b, int n) {
	int choice;
	cout << endl << "Choose rectangulars rule:\n1)left\n2)right\n3)middle" << endl;
	cout << "// ";
	cin >> choice;

	double h = (b - a) / n, I = 0;
	
	if (choice == 1) {
		cout << endl << "[Left rectangulars rule]" << endl << endl;
		vector<vector<double>> Table = getTable(a, b, n);
		for (int i = 0; i < n; i++) {
			I += Table[2][i];
		}
		I *= h;
	}
	else if (choice == 2) {
		cout << endl << "[Right rectangulars rule]" << endl << endl;
		vector<vector<double>> Table = getTable(a, b, n);
		for (int i = 1; i < n + 1; i++) {
			I += Table[2][i];
		}
		I *= h;
	}
	else if (choice == 3) {
		cout << endl << "[Middle rectangulars rule]" << endl << endl;
		vector<vector<double>> Table = getTable(a+h/2, b, n);
		for (int i = 0; i < n; i++) {
			I += Table[2][i];
		}
		I *= h;
	}
	else {
		cout << "Incorrect input!" << endl;
		exit(-1);
	}

	cout << endl << "The result is:\nI = " << setprecision(4) << fixed << I << endl;

	double R, max = DBL_MIN;
	for (double x = a; x <= b; x += 0.001) {
		if (Func2P(x) > max) {
			max = Func2P(x);
		}
	}
	R = max * (b - a) * pow(h, 2) / 24;
	cout << endl << "R = " << scientific << R << endl;
}

void TrapezoidalRule(double a, double b, int n) {
	double h = (b - a) / n, I = 0;
	
	cout << endl << "[Trapezoidal rule]" << endl << endl;
	vector<vector<double>> Table = getTable(a, b, n);
	for (int i = 1; i < n; i++) {
		I += Table[2][i];
	}
	I += ((Table[2][0] + Table[2][n]) / 2);
	I *= h;

	cout << endl << "The result is:\nI = " << setprecision(4) << fixed << I << endl;

	double R, max = DBL_MIN;
	for (double x = a; x <= b; x += 0.001) {
		if (Func2P(x) > max) {
			max = Func2P(x);
		}
	}
	R = -max * (b - a) * pow(h, 2) / 12;
	cout << endl << "R = " << scientific << R << endl;
}

void SimpsonsRule(double a, double b, int n) {
	double h = (b - a) / n, sum1 = 0, sum2 = 0, I = 0;

	cout << endl << "[Simpsons rule]" << endl << endl;
	vector<vector<double>> Table = getTable(a, b, n);

	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			sum2 += Table[2][i];
		}
		else {
			sum1 += Table[2][i];
		}
	}

	I += Table[2][0] + Table[2][n] + 4*sum1 + 2*sum2;
	I *= h/3;

	cout << endl << "The result is:\nI = " << setprecision(4) << fixed << I << endl;

	double R, max = DBL_MIN;
	for (double x = a; x <= b; x += 0.001) {
		if (Func4P(x) > max) {
			max = Func4P(x);
		}
	}
	R = -max * pow((b - a), 5) / (180 * pow(n, 4));
	cout << endl << "R = " << scientific << R << endl;
}

int main() {

	double a, b;
	int n;

	cout << "Enter the interval boundaries [a, b]: " << endl;
	cin >> a >> b;

	cout << "Enter the number of partitions: " << endl;
	cin >> n;


	TrapezoidalRule(a, b, n);
	SimpsonsRule(a, b, n);
	RectangularsRule(a, b, n);

	return 0;
}