#ifndef CMOTORCYCLE_HPP
#define CMOTORCYCLE_HPP

#include "CVehicle.hpp"

class CMotorcycle : public CVehicle {
public:
	CMotorcycle();
	CMotorcycle(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency);
	void PrintName(ostream& os) const override;

	void VehicleDataExport(string FILENAME) const override;
	VehicleCondition VehicleCheck() const override;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const override;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const override;
};

#endif