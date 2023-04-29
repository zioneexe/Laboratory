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

void CTruck::PrintName(ostream& os) const{
	os << endl << "CTruck" << endl << endl;
}

double CTruck::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	assert(dUsefulMassInKg >= 0 && dUsefulMassInKg <= GetMaxUsefulMassInKg());

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

void CTruck::VehicleDataExport(string FILENAME) const
{
	ofstream file(FILENAME, ios::app);
	if (file.is_open()) {
		file << "Truck characteristics:\t" << endl;
		file << "\tMax Speed: " << MaxSpeed << endl;
		file << "\tEngine Power: " << EnginePower << endl;
		file << "\tMax Seats: " << MaxSeats << endl;
		file << "\tNumber of Seats: " << NumberOfSeats << endl;
		file << "\tPrice: " << Price << endl;
		file << "\tAge: " << Age << endl;
		file << "\tWeight: " << Weight << endl;
		file << "\tMileage: " << Mileage << endl;
		file << "\tFuel Efficiency: " << FuelEfficiency << endl;
		file << "\tTruck Load: " << TruckLoad << endl;
		file.close();

		cout << "Truck data exported to " << FILENAME << endl;
	}
	else {
		cout << "Error: Unable to open file " << FILENAME << " for writing." << endl;
	}

}

VehicleCondition CTruck::VehicleCheck() const
{
	double AgeFactor = Age / 10.0;
	double MileageFactor = Mileage / 100000.0;

	double ConditionScore = AgeFactor + MileageFactor;

	if (ConditionScore <= 0.5) {
		cout << "Your truck is new!" << endl;
		return VehicleCondition::New;
	}
	else if (ConditionScore <= 1.5) {
		cout << "Your truck is in good condition!" << endl;
		return VehicleCondition::Good;
	}
	else if (ConditionScore <= 2.5) {
		cout << "Your truck is in moderate condition." << endl;
		return VehicleCondition::Moderate;
	}
	else {
		cout << "Your truck is broken..." << endl;
		return VehicleCondition::Broken;
	}
}