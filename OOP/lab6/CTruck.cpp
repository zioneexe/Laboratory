#include "CTruck.hpp"

CTruck::CTruck() : CVehicle(), TruckLoad(0) {}

CTruck::CTruck(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
	int age, int weight, double mileage, double fuelefficiency, double truckload) :
	CVehicle(maxspeed, enginepower, maxseats, numberofseats, price, age, weight, mileage, fuelefficiency) {
	SetTruckLoad(truckload);
}

void CTruck::SetTruckLoad(double truckload) {
	assert(truckload >= 0);

	TruckLoad = truckload;
}

double CTruck::GetTruckLoad() const {
	return TruckLoad;
}

void CTruck::PrintName(ostream& os) {
	os << endl << "CTruck" << endl << endl;
}

double CTruck::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	assert(dUsefulMassInKg >= 0 && dUsefulMassInKg < GetMaxUsefulMassInKg());

	double result = (FuelEfficiency * (dUsefulMassInKg / GetMaxUsefulMassInKg()) - Age / 100.0);
	if (result >= 0) {
		return result;
	}
	else {
		cout << "Incorrect input.." << endl;
		exit(-1);
	}
}

double CTruck::GetMaxUsefulMassInKg() const {
	return TruckLoad + (MaxSeats * PERSON_WEIGHT);
}

double CTruck::GetServicePricePerThousandKm() const {
	return (Price / Age) * 0.02 + Mileage / 1000.0;
}