#include "CVehicle.hpp"

CVehicle::CVehicle() : MaxSpeed(0), EnginePower(0), MaxSeats(0), NumberOfSeats(0),
Price(0), Age(0), Weight(0), Mileage(0), FuelEfficiency(0) {}

CVehicle::CVehicle(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
	int age, int weight, double mileage, double fuelefficiency) {
	SetMaxSpeed(maxspeed);
	SetEnginePower(enginepower);
	SetMaxSeats(maxseats);
	SetNumberOfSeats(numberofseats);
	SetPrice(price);
	SetAge(age);
	SetWeight(weight);
	SetMileage(mileage);
	SetFuelEfficiency(fuelefficiency);
}

void CVehicle::SetMaxSpeed(int maxspeed) {
	assert(maxspeed >= 0);

	MaxSpeed = maxspeed;
}

void CVehicle::SetEnginePower(int enginepower) {
	assert(enginepower >= 0);

	EnginePower = enginepower;
}

void CVehicle::SetMaxSeats(int maxseats) {
	assert(maxseats > 0);

	MaxSeats = maxseats;
}

void CVehicle::SetNumberOfSeats(int numberofseats) {
	assert(numberofseats > 0 && numberofseats <= GetMaxSeats());

	NumberOfSeats = numberofseats;
}


void CVehicle::SetPrice(int price) {
	assert(price >= 0);

	Price = price;
}

void CVehicle::SetAge(int age) {
	assert(age >= 0);

	Age = age;
}

void CVehicle::SetWeight(int weight) {
	assert(weight > 0);

	Weight = weight;
}

void CVehicle::SetMileage(double mileage) {
	assert(mileage >= 0);

	Mileage = mileage;
}

void CVehicle::SetFuelEfficiency(double fuelefficiency) {
	assert(fuelefficiency >= 0);

	FuelEfficiency = fuelefficiency;
}

int CVehicle::GetMaxSpeed() const {
	return MaxSpeed;
}

int CVehicle::GetEnginePower() const {
	return EnginePower;
}

int CVehicle::GetMaxSeats() const {
	return MaxSeats;
}

int CVehicle::GetNumberOfSeats() const {
	return NumberOfSeats;
}

int CVehicle::GetPrice() const {
	return Price;
}

int CVehicle::GetAge() const {
	return Age;
}

int CVehicle::GetWeight() const {
	return Weight;
}

double CVehicle::GetMileage() const {
	return Mileage;
}

double CVehicle::GetFuelEfficiency() const {
	return FuelEfficiency;
}

void CVehicle::Beep() const
{
	cout << endl << "Beep! Beeeeep!" << endl << endl;
}

void CVehicle::PrintName() const {
	cout << endl << "CVehicle" << endl << endl;
}

void CVehicle::VehicleDataExport(string FILENAME) const
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

VehicleCondition CVehicle::VehicleCheck() const
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