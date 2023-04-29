#include "CCar.hpp"
#include "CTruck.hpp"
#include "CMotorcycle.hpp"

void PrintStars(int iNum);
void PrintX(int iNum);
void PrintMenu();

void PrintStars(int iNum) {
	for (int i = 0; i < iNum; ++i) {
		putchar('*');
	}
}

void PrintX(int iNum) {
	for (int i = 0; i < iNum; ++i) {
		putchar('x');
	}
}

void PrintMenu() {
	PrintX(120);
	cout << "x\t\t\t\t\t\t//Interactive program//\t\t\t\t\t\t\tx" << endl;
	PrintX(120);
	cout << "x\tType number needed to do the action.\t\t\t\t\t\t\t\t\t\tx" << endl;
	PrintX(120);
	cout << "x\t1\tx\tCreate car and use it\t\t\t\t\t\t\t\t\t\tx" << endl;
	cout << "x\t2\tx\tCreate truck and use it\t\t\t\t\t\t\t\t\t\tx" << endl;
	cout << "x\t3\tx\tCreate motorcycle and use it\t\t\t\t\t\t\t\t\tx" << endl;
	PrintX(120);
	cout << endl << "x\t4\tx\tExit\t\t\t\t\t\t\t\t\t\t\t\tx" << endl;
	PrintX(120);
}

int main() {
	int flag1 = 0, flag2 = 0, flag3 = 0;
	PrintMenu();

	int iOption = 1;

	while (iOption != 4) {
		cout << endl << endl << "// ";
		cin >> iOption;

		if (iOption == 1) {
			flag1 = 1;

			int MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight;
			double Mileage, FuelEfficiency, CarLoad;

			cout << endl << "Enter max speed (km/h): " << endl;
			cin >> MaxSpeed;

			cout << endl << "Enter engine power (in hp): " << endl;
			cin >> EnginePower;

			cout << endl << "Enter max number or seats (must be >0): " << endl;
			cin >> MaxSeats;

			cout << endl << "Enter number of seats (must be <= than max number): " << endl;
			cin >> NumberOfSeats;

			cout << endl << "Enter price (in hryvnias): " << endl;
			cin >> Price;

			cout << endl << "Enter age (in years): " << endl;
			cin >> Age; 

			cout << endl << "Enter weight (kg): " << endl;
			cin >> Weight;

			cout << endl << "Enter mileage (km): " << endl;
			cin >> Mileage;

			cout << endl << "Enter fuel efficiency (km/l): " << endl;
			cin >> FuelEfficiency;

			cout << endl << "Enter car load (in kg): " << endl;
			cin >> CarLoad;

			CCar car(MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight, Mileage, FuelEfficiency, CarLoad);

			double dUsefulMassInKg;

			cout << endl << "Enter useful mass (in kg, must be < " << CarLoad + (MaxSeats * PERSON_WEIGHT) << " )" << endl;
			cin >> dUsefulMassInKg;

			car.PrintName(cout);
			cout << endl << "Distance (per 1 litre): " << car.GetDistancePerOneLiter(dUsefulMassInKg) << endl;
			cout << "Max useful mass (in kg): " << car.GetMaxUsefulMassInKg() << endl;
			cout << "Service price (per 1000 km): " << car.GetServicePricePerThousandKm() << endl << endl;

			int iChoice = -1;
			cout << "Type \"0\" to return to menu." << endl;
			cout << "Type \"1\" if you want to write data to file." << endl;
			cout << "Type \"2\" if you want to check your vehicle condition." << endl;
			while (iChoice) {
				cout << endl << endl << "// ";
				cin >> iChoice;

				if (iChoice == 1) {
					car.CVehicle::VehicleDataExport("output.txt");
				}

				if (iChoice == 2) {
					car.CVehicle::VehicleCheck();
				}
			}
			cout << endl << endl << "...function ended its work" << endl << endl;
			PrintMenu();
		}

		else if (iOption == 2) {
			flag2 = 1;

			int MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight;
			double Mileage, FuelEfficiency, TruckLoad;

			cout << endl << "Enter max speed (km/h): " << endl;
			cin >> MaxSpeed;

			cout << endl << "Enter engine power (in hp): " << endl;
			cin >> EnginePower;

			cout << endl << "Enter max number or seats: " << endl;
			cin >> MaxSeats;

			cout << endl << "Enter number of seats (must be <= than max number): " << endl;
			cin >> NumberOfSeats;

			cout << endl << "Enter price (in hryvnias): " << endl;
			cin >> Price;

			cout << endl << "Enter age (in years): " << endl;
			cin >> Age;

			cout << endl << "Enter weight (kg): " << endl;
			cin >> Weight;

			cout << endl << "Enter mileage (km): " << endl;
			cin >> Mileage;

			cout << endl << "Enter fuel efficiency (km/l): " << endl;
			cin >> FuelEfficiency;

			cout << endl << "Enter truck load (in kg): " << endl;
			cin >> TruckLoad;

			CTruck truck(MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight, Mileage, FuelEfficiency, TruckLoad);

			double dUsefulMassInKg;

			cout << endl << "Enter useful mass (in kg, must be < " << TruckLoad + (MaxSeats * PERSON_WEIGHT) << " )" << endl;
			cin >> dUsefulMassInKg;

			truck.PrintName(cout);
			cout << endl << "Distance (per 1 litre): " << truck.GetDistancePerOneLiter(dUsefulMassInKg) << endl;
			cout << "Max useful mass (in kg): " << truck.GetMaxUsefulMassInKg() << endl;
			cout << "Service price (per 1000 km): " << truck.GetServicePricePerThousandKm() << endl << endl;

			int iChoice = -1;
			cout << "Type \"0\" to return to menu." << endl;
			cout << "Type \"1\" if you want to write data to file." << endl;
			cout << "Type \"2\" if you want to check your vehicle condition." << endl;
			while (iChoice) {
				cout << endl << endl << "// ";
				cin >> iChoice;

				if (iChoice == 1) {
					truck.CVehicle::VehicleDataExport("output.txt");
				}

				else if (iChoice == 2) {
					truck.CVehicle::VehicleCheck();
				}
			}
	
			cout << endl << endl << "...function ended its work" << endl << endl;
			PrintMenu();
		}

		else if (iOption == 3) {
			flag3 = 1;

			int MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight;
			double Mileage, FuelEfficiency;

			cout << endl << "Enter max speed (km/h): " << endl;
			cin >> MaxSpeed;

			cout << endl << "Enter engine power (in hp): " << endl;
			cin >> EnginePower;

			cout << endl << "Enter max number or seats: " << endl;
			cin >> MaxSeats;

			cout << endl << "Enter number of seats (must be <= than max number): " << endl;
			cin >> NumberOfSeats;

			cout << endl << "Enter price (in hryvnias): " << endl;
			cin >> Price;

			cout << endl << "Enter age (in years): " << endl;
			cin >> Age;

			cout << endl << "Enter weight (kg): " << endl;
			cin >> Weight;

			cout << endl << "Enter mileage (km): " << endl;
			cin >> Mileage;

			cout << endl << "Enter fuel efficiency (km/l): " << endl;
			cin >> FuelEfficiency;

			CMotorcycle moto(MaxSpeed, EnginePower, MaxSeats, NumberOfSeats, Price, Age, Weight, Mileage, FuelEfficiency);

			double dUsefulMassInKg;

			cout << endl << "Enter useful mass (in kg, must be < " << MaxSeats * PERSON_WEIGHT << " )" << endl;
			cin >> dUsefulMassInKg;

			moto.PrintName(cout);
			cout << endl << "Distance (per 1 litre): " << moto.GetDistancePerOneLiter(dUsefulMassInKg) << endl;
			cout << "Max useful mass (in kg): " << moto.GetMaxUsefulMassInKg() << endl;
			cout << "Service price (per 1000 km): " << moto.GetServicePricePerThousandKm() << endl << endl;
			
			int iChoice = -1;
			cout << "Type \"0\" to return to menu." << endl;
			cout << "Type \"1\" if you want to write data to file." << endl;
			cout << "Type \"2\" if you want to check your vehicle condition." << endl;
			while (iChoice) {
				cout << endl << endl << "// ";
				cin >> iChoice;

				if (iChoice == 1) {
					moto.VehicleDataExport("output.txt");
				}

				else if (iChoice == 2) {
					moto.VehicleCheck();
				}
			}

			cout << endl << endl << "...function ended its work" << endl << endl;
			PrintMenu();
		}

		else if (iOption == 4) {
			cout << endl << endl << "\t\t\t\t\t\tExiting program..." << endl << endl;
			exit(0);
		}

		else {
			cout << endl << "Option # " << iOption << " does not yet exist! Try another one." << endl;
		}

	}

	return 0;
}