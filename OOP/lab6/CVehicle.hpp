#ifndef CVEHICLE_HPP
#define CVEHICLE_HPP

#define _CRT_SECURE_NO_WARNINGS
#define PERSON_WEIGHT 95

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class VehicleCondition {
	New = 0,
	Good,
	Moderate,
	Broken,
};

class CVehicle {
public:
	CVehicle();
	CVehicle(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency);
	void Beep() const;
	void PrintName() const;
	void VehicleDataExport(string FILENAME) const;
	VehicleCondition VehicleCheck() const;

	void SetMaxSpeed(int maxspeed);
	void SetEnginePower(int enginepower);
	void SetMaxSeats(int maxseats);
	void SetNumberOfSeats(int numberofseats);
	void SetPrice(int price);
	void SetAge(int age);
	void SetWeight(int weight);
	void SetMileage(double mileage);
	void SetFuelEfficiency(double fuelefficiency);

	int GetMaxSpeed() const;
	int GetEnginePower() const;
	int GetMaxSeats() const;
	int GetNumberOfSeats() const;
	int GetPrice() const;
	int GetAge() const;
	int GetWeight() const;
	double GetMileage() const;
	double GetFuelEfficiency() const;
protected:
	int MaxSpeed; //km/h
	int EnginePower; //hp
	int MaxSeats;
	int NumberOfSeats;
	int Price; //hryvnias
	int Age; //years
	int Weight; //kg
	double Mileage; //km
	double FuelEfficiency; //km/l - номінальна відстань яку може проїхати авто, використовуючи 1 літр пального
};

#endif