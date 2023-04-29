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

void CCar::PrintName(ostream& os) const{
	os << endl << "CCar" << endl << endl;
}

double CCar::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	assert(dUsefulMassInKg >= 0 && dUsefulMassInKg <= GetMaxUsefulMassInKg());

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

void CCar::VehicleDataExport(string FILENAME) const
{
	ofstream file(FILENAME, ios::app);
	if (file.is_open()) {
		file << "Car characteristics : \t" << endl;
		file << "\tMax Speed: " << MaxSpeed << endl;
		file << "\tEngine Power: " << EnginePower << endl;
		file << "\tMax Seats: " << MaxSeats << endl;
		file << "\tNumber of Seats: " << NumberOfSeats << endl;
		file << "\tPrice: " << Price << endl;
		file << "\tAge: " << Age << endl;
		file << "\tWeight: " << Weight << endl;
		file << "\tMileage: " << Mileage << endl;
		file << "\tFuel Efficiency: " << FuelEfficiency << endl;
		file << "\tCar Load: " << CarLoad << endl;
		file.close();

		cout << "Car data exported to " << FILENAME << endl;
	}
	else {
		cout << "Error: Unable to open file " << FILENAME << " for writing." << endl;
	}

}

VehicleCondition CCar::VehicleCheck() const
{
	double AgeFactor = Age / 10.0;
	double MileageFactor = Mileage / 100000.0;

	double ConditionScore = AgeFactor + MileageFactor;

	if (ConditionScore <= 0.5) {
		cout << "Your car is new!" << endl;
		return VehicleCondition::New;
	}
	else if (ConditionScore <= 1.5) {
		cout << "Your car is in good condition!" << endl;
		return VehicleCondition::Good;
	}
	else if (ConditionScore <= 2.5) {
		cout << "Your car is in moderate condition." << endl;
		return VehicleCondition::Moderate;
	}
	else {
		cout << "Your car is broken..." << endl;
		return VehicleCondition::Broken;
	}
}