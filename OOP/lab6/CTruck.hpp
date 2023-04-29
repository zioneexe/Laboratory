#ifndef CTRUCK_HPP
#define CTRUCK_HPP

#include "CVehicle.hpp"

class CTruck : public CVehicle {
public:
	CTruck();
	CTruck(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency, double truckload);
	void PrintName(ostream& os);

	void SetTruckLoad(double truckload);
	double GetTruckLoad() const;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const;
private:
	double TruckLoad;
};

#endif