#pragma once
#include "Car.h"

ref class CarList
{
private:
	Car^ head;
	Car^ tail;
	Random^ rGen;
public:
	CarList(void);
	void addCar(Car^ newCar);
	void deleteCar(Car^ carToDelete);
	void renderCars();
	int countCars();
	void updateCars();
};
