#ifndef CCAR_HPP
#define CCAR_HPP

#include "CVehicle.hpp"

class CCar : public virtual CVehicle {
public:
	CCar();
	CCar(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency, double carload);
	void PrintName(ostream& os) const override;

	void SetCarLoad(double carload);
	double GetCarLoad() const;

	virtual void VehicleDataExport(string FILENAME) const override;
	virtual VehicleCondition VehicleCheck() const override;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const override;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const override;

private:
	double CarLoad;
};

#endif