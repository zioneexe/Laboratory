#include "CMotorcycle.hpp"

CMotorcycle::CMotorcycle() : CVehicle() {}

CMotorcycle::CMotorcycle(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
	int age, int weight, double mileage, double fuelefficiency) :
	CVehicle(maxspeed, enginepower, maxseats, numberofseats, price, age, weight, mileage, fuelefficiency) {}

void CMotorcycle::PrintName(ostream& os) {
	os << endl << "CMotorcycle" << endl << endl;
}

double CMotorcycle::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	assert(dUsefulMassInKg >= 0 && dUsefulMassInKg < GetMaxUsefulMassInKg());

	double result = (FuelEfficiency * (dUsefulMassInKg / GetMaxUsefulMassInKg()) - Age / 25.0);
	if (result >= 0) {
		return result;
	}
	else {
		cout << "Incorrect input.." << endl;
		exit(-1);
	}
}

double CMotorcycle::GetMaxUsefulMassInKg() const {
	return MaxSeats * PERSON_WEIGHT;
}

double CMotorcycle::GetServicePricePerThousandKm() const {
	return (Price / Age) * 0.002 + Mileage / 50.0;
}

void CMotorcycle::VehicleDataExport(string FILENAME) const
{
	ofstream file(FILENAME, ios::app);
	if (file.is_open()) {
		file << "Vehicle Characteristics:\t" << endl;
		file << "\tMax Speed: " << MaxSpeed << endl;
		file << "\tEngine Power: " << EnginePower << endl;
		file << "\tMax Seats: " << MaxSeats << endl;
		file << "\tNumber of Seats: " << NumberOfSeats << endl;
		file << "\tPrice: " << Price << endl;
		file << "\tAge: " << Age << endl;
		file << "\tWeight: " << Weight << endl;
		file << "\tMileage: " << Mileage << endl;
		file << "\tFuel Efficiency: " << FuelEfficiency << endl;
		file.close();

		cout << "Vehicle data exported to " << FILENAME << endl;
	}
	else {
		cout << "Error: Unable to open file " << FILENAME << " for writing." << endl;
	}

}

VehicleCondition CMotorcycle::VehicleCheck() const
{
	double AgeFactor = Age / 10.0;
	double MileageFactor = Mileage / 100000.0;

	double ConditionScore = AgeFactor + MileageFactor;

	if (ConditionScore <= 0.5) {
		cout << "Your vehicle is new!" << endl;
		return VehicleCondition::New;
	}
	else if (ConditionScore <= 1.5) {
		cout << "Your vehicle is in good condition!" << endl;
		return VehicleCondition::Good;
	}
	else if (ConditionScore <= 2.5) {
		cout << "Your vehicle is in moderate condition." << endl;
		return VehicleCondition::Moderate;
	}
	else {
		cout << "Your vehicle is broken..." << endl;
		return VehicleCondition::Broken;
	}
}