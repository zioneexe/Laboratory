#ifndef CTRUCK_HPP
#define CTRUCK_HPP

#include "CVehicle.hpp"

class CTruck : public virtual CVehicle {
public:
	CTruck();
	CTruck(int maxspeed, int enginepower, int maxseats, int numberofseats, int price,
		int age, int weight, double mileage, double fuelefficiency, double truckload);
	void PrintName(ostream& os) const override;

	void SetTruckLoad(double truckload);
	double GetTruckLoad() const;

	virtual void VehicleDataExport(string FILENAME) const override;
	virtual VehicleCondition VehicleCheck() const override;

	double GetDistancePerOneLiter(double dUsefulMassInKg) const override;
	double GetMaxUsefulMassInKg() const;
	double GetServicePricePerThousandKm() const override;
private:
	double TruckLoad;
};

#endif