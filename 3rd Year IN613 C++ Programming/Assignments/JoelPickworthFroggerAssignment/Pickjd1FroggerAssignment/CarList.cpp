#include "StdAfx.h"
#include "CarList.h"

CarList::CarList(void)
{
	head = nullptr;
	tail = nullptr;
	rGen = gcnew Random();
}

	void CarList::addCar(Car^ newCar)
	{
	if (head == nullptr)
	{
		head = newCar;
		tail = newCar;
	}
	else
	{
		tail->Next = newCar;
		tail = newCar;
	}
	}


	void CarList::deleteCar(Car^ carToDelete)
	{
	if(carToDelete == head)
	{
		if(head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->Next;
		}

	}
	else
	{
		Car^ nodeWalker;
		nodeWalker = head;

		while (nodeWalker->Next != carToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}

		nodeWalker->Next = carToDelete->Next;

		if (carToDelete == tail)
		{
			tail = nodeWalker;
		}

	}
	}


	void CarList::renderCars()
	{
		Car^ nodeWalker = head;
		while (nodeWalker != nullptr)
		{
			nodeWalker->DrawCar();
			nodeWalker = nodeWalker->Next;
		}
	}


	int CarList::countCars()
	{
		int carCount = 0; 

		Car^ nodeWalker = head;
		while (nodeWalker != nullptr)
		{
			carCount++;
			nodeWalker = nodeWalker->Next;
		}

		return carCount;
	}


	void CarList::updateCars()
	{
			Car^ nodeWalker = head;
		while (nodeWalker != nullptr)
		{
			nodeWalker->MoveRand(rGen->Next(30));
			nodeWalker = nodeWalker->Next;
		}
	}


