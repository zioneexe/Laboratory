#ifndef CMOTORCYCLE_HPP
#define CMOTORCYCLE_HPP

#include "CVehicle.hpp"

class CMotorcycle : protected CVehicle {
public:
	CMotorcycle();
	CMotorcycle(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency);
	void PrintName(ostream& os);

	void VehicleDataExport(string FILENAME) const;
	VehicleCondition VehicleCheck() const;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const;
};

#endif