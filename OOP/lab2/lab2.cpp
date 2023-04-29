#include <iostream>

// Функція вертає тривалість безперебійної роботи споживачів (год)
// потужністю dW (Вт) від джерела аварійного живлення ємністю dC (Вт*год)
// з коефіцієнтом перетворення dRatio (0 < dRatio < 1).

double GetTimeOfOperationInHours(double dW, double dC, double dRatio) {
	if (dC > 0 && dW > 0 && dRatio > 0 && dRatio < 1) {
		double dTime = dC / dW * dRatio;
		return dTime;
	}
	else {
	//	std::cout << "Invalid input!" << std::endl;
		return -1;
	}
}