#ifndef CCAR_HPP
#define CCAR_HPP

#include "CVehicle.hpp"

class CCar : public CVehicle {
public:
	CCar();
	CCar(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency, double carload);
	void PrintName(ostream& os);

	void SetCarLoad(double carload);
	double GetCarLoad() const;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const;

private:
	double CarLoad;
};

#endif