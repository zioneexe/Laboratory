#include "CCar.hpp"
#include "CTruck.hpp"
#include "CMotorcycle.hpp"

class CVehicleTest : public CTruck, public CCar {
public:
	CVehicleTest() : test(0) {}
	void Test() { cout << "Test" << endl; }
	void Flex() const { cout << endl << "My price is 10 000 000 $!" << endl << endl; }
	double GetDistancePerOneLiter(double dUsefulMassInKg) const;
	double GetServicePricePerThousandKm() const;
	void VehicleDataExport(string FILENAME) const;
	VehicleCondition VehicleCheck() const;
	void PrintName(ostream& os) const;
private:
	int test;
};

void CVehicleTest::PrintName(ostream& os) const {
	os << "Test" << endl;
}

double CVehicleTest::GetDistancePerOneLiter(double dUsefulMassInKg) const {
	return 0;
}

double CVehicleTest::GetServicePricePerThousandKm() const {
	return 0;
}

void CVehicleTest::VehicleDataExport(string FILENAME) const
{
	ofstream file(FILENAME, ios::app);
	if (file.is_open()) {
		file << "Test\t" << endl;
		file.close();
	}
	else {
		cout << "Error: Unable to open file " << FILENAME << " for writing." << endl;
	}

}

VehicleCondition CVehicleTest::VehicleCheck() const
{
	return VehicleCondition::New;
}

int GetPriceOfTransit(CVehicle* vehicles[N], int Mass, int Distance);


int GetPriceOfTransit(array<unique_ptr<CVehicle>, N> vehicles, int Mass, int Distance) {

	int MinPrice, CPrice, TPrice, MPrice;

	array<CCar, N> cars;
	array<CTruck, N> trucks;
	array<CMotorcycle, N> motorcycles;
	
	for (int i = 0; i < N; ++i) {
		int q1 = 0, q2 = 0, q3 = 0;
		CCar* cptr = dynamic_cast<CCar*>(vehicles[i].get());
		if (cptr) {
			cars[q1] = *cptr;
			++q1;
		}
		CTruck* tptr = dynamic_cast<CTruck*>(vehicles[i].get());
		if (tptr) {
			trucks[q2] = *tptr;
			++q2;
		}
		CMotorcycle* mptr = dynamic_cast<CMotorcycle*>(vehicles[i].get());
		if (mptr) {
			motorcycles[q3] = *mptr;
			++q3;
		}
	}

	double MaxUsefulMass = cars[0].GetMaxUsefulMassInKg();
	int CNum = ceil(Mass / MaxUsefulMass);
	CPrice = CNum * Distance / cars[0].GetDistancePerOneLiter(MaxUsefulMass) * FUEL_PRICE +
		Distance / 1000 * cars[0].GetServicePricePerThousandKm();

	MaxUsefulMass = motorcycles[0].GetMaxUsefulMassInKg();
	int MNum = ceil(Mass / MaxUsefulMass);
	MPrice = MNum * Distance / 
		motorcycles[0].GetDistancePerOneLiter(MaxUsefulMass) * FUEL_PRICE +
		Distance / 1000 * motorcycles[0].GetServicePricePerThousandKm();
	
	MaxUsefulMass = trucks[0].GetMaxUsefulMassInKg();
	int TNum = ceil(Mass / MaxUsefulMass);
	TPrice = TNum * Distance / trucks[0].GetDistancePerOneLiter(MaxUsefulMass) * FUEL_PRICE +
		Distance / 1000 * trucks[0].GetServicePricePerThousandKm();

	MinPrice = min({ CPrice, MPrice, TPrice });

	if (MinPrice == CPrice) {
		cout << "Taking " << CNum << " cars to transfer the cargo." << endl;
	}
	else if (MinPrice == MPrice) {
		cout << "Taking " << MNum << " motorcycles to transfer the cargo." << endl;
	}
	else {
		cout << "Taking " << TNum << " trucks to transfer the cargo." << endl;
	}

	return MinPrice;
}

int main() {

	array<unique_ptr<CVehicle>, N> vehicles;

	vehicles[0] = make_unique<CMotorcycle>(120, 65, 2, 1, 100000, 2, 1500, 200, 5);
	vehicles[1] = make_unique<CTruck>(120, 300, 2, 2, 10000000, 5, 5000, 10000, 5, 20);
	vehicles[2] = make_unique<CCar>(210, 200, 4, 4, 800000, 2, 2000, 1500, 10, 20);


	for (int i = 0; i < N; i++) {
		cout << "Vehicle " << i + 1 << ":\n";
		vehicles[i]->PrintName(cout);
		cout << "Max speed: " << vehicles[i]->GetMaxSpeed() << endl;
		cout << "Fuel efficiency: " << vehicles[i]->GetFuelEfficiency() << endl;
		cout << "Service price per 1000 km: " << vehicles[i]->GetServicePricePerThousandKm() << endl;

		if (typeid(*vehicles[i]) == typeid(CMotorcycle*)) {
			double UsefulMass = 100;
			double Distance = dynamic_cast<CMotorcycle*>(vehicles[i].get())->GetDistancePerOneLiter(UsefulMass);
			cout << "Distance per 1 liter with " << UsefulMass << " kg useful mass: " << Distance << endl;
		}
		else if (typeid(*vehicles[i]) == typeid(CTruck*)) {
			double UsefulMass = 5000;
			double Distance = dynamic_cast<CTruck*>(vehicles[i].get())->GetDistancePerOneLiter(UsefulMass);
			cout << "Distance per 1 liter with " << UsefulMass << " kg useful mass: " << Distance << endl;
		}
		else if (typeid(*vehicles[i]) == typeid(CCar*)) {
			double UsefulMass = 200;
			double Distance = dynamic_cast<CCar*>(vehicles[i].get())->GetDistancePerOneLiter(UsefulMass);
			cout << "Distance per 1 liter with " << UsefulMass << " kg useful mass: " << Distance << endl;
		}
		cout << endl;
	}

	int Price = GetPriceOfTransit(move(vehicles), 5000, 2000);

	cout << "Total price: " << Price << endl;

	CVehicleTest a;
	a.CCar::PrintName(cout);
	a.Beep();
	a.PrintName(cout);

	return 0;
}