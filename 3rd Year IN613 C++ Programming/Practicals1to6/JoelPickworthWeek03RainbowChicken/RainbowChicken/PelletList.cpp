#include "StdAfx.h"
#include "PelletList.h"

PelletList::PelletList(void)
{
	head = nullptr;
	tail = nullptr;
}

void PelletList::addPellet(Pellet^ newPellet)
{
	if (head == nullptr)
	{
		head = newPellet;
		tail = newPellet;
	}
	else
	{
		tail->Next = newPellet;
		tail = newPellet;
	}
}

void PelletList::deletePellet(Pellet^ pelletToDelete)
{
	if(pelletToDelete == head)
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
		Pellet^ nodeWalker;
		nodeWalker = head;

		while (nodeWalker->Next != pelletToDelete)
		{
			nodeWalker = nodeWalker->Next;
		}

		nodeWalker->Next = pelletToDelete->Next;

		if (pelletToDelete == tail)
		{
			tail = nodeWalker;
		}

	}
}

void PelletList::renderPellets()
{
	
	
		Pellet^ nodeWalker = head;
		while (nodeWalker != nullptr)
		{
			nodeWalker->draw();
			nodeWalker = nodeWalker->Next;
		}
	

}

int PelletList::countPellets()
{
	int pelletCount = 0; 

	Pellet^ nodeWalker = head;
	while (nodeWalker != nullptr)
	{
		pelletCount++;
		nodeWalker = nodeWalker->Next;
	}

	return pelletCount;
}

void PelletList::updatePellets()
{
			Pellet^ nodeWalker = head;
		while (nodeWalker != nullptr)
		{
			nodeWalker->move();
			nodeWalker = nodeWalker->Next;
		}
	
}
