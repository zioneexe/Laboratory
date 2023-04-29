#include "CCar.hpp"

CCar::CCar() : CVehicle(), CarLoad(0) {}

CCar::CCar(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
	int age, int weight, double mileage, double fuelefficiency, double carload) :
	CVehicle(maxspeed, enginepower, maxseats, numberofseats, price, age, weight, mileage, fuelefficiency) {
	SetCarLoad(carload);
}

void CCar::SetCarLoad(double carload) {
	assert(carload > -0);

	CarLoad = carload;
}

double CCar::GetCarLoad() const {
	return CarLoad;
}

void CCar::PrintName(ostream& os) {
	os << endl << "CCar" << endl << endl;
}

double CCar::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	assert(dUsefulMassInKg >= 0 && dUsefulMassInKg < GetMaxUsefulMassInKg());

	double result = (FuelEfficiency * (dUsefulMassInKg / GetMaxUsefulMassInKg()) - Age / 50.0);
	if (result >= 0) {
		return result;
	}
	else {
		cout << "Incorrect input.." << endl;
		exit(-1);
	}
}

double CCar::GetMaxUsefulMassInKg() const {
	return CarLoad + (MaxSeats * PERSON_WEIGHT);
}

double CCar::GetServicePricePerThousandKm() const {
	return (Price / Age) * 0.01 + Mileage / 500.0;
}