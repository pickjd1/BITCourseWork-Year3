#include "StdAfx.h"
#include "L.h"

L::L(void)
{
	color = Color::Gold;
	cells = gcnew array<Cell^>(4);
	cells[0] = gcnew Cell(3,4);
	cells[1] = gcnew Cell(2,4);
	cells[2] = gcnew Cell(1,4);
	cells[3] = gcnew Cell(3,5);
}

array<Cell^>^ L::Rotate()
{
	array<Cell^>^ tempCell = gcnew array<Cell^>(4);

	for (int i = 0; i < 4; i++)
	{
		tempCell[i] = gcnew Cell(cells[i]->GetRow(), cells[i]->GetCol());
	}

	if (orientation == 0)
	{
		tempCell[0]->SetCol(-1);
		tempCell[0]->SetRow(-1);
		tempCell[1]->SetCol(0);
		tempCell[1]->SetRow(0);
		tempCell[2]->SetCol(1);
		tempCell[2]->SetRow(1);
		tempCell[3]->SetCol(-2);
		tempCell[3]->SetRow(0);
	}
	else if (orientation == 1)
	{
		tempCell[0]->SetCol(1);
		tempCell[0]->SetRow(-1);
		tempCell[1]->SetCol(0);
		tempCell[1]->SetRow(0);
		tempCell[2]->SetCol(-1);
		tempCell[2]->SetRow(1);
		tempCell[3]->SetCol(0);
		tempCell[3]->SetRow(-2);
	}
	else if (orientation == 2)
	{
		tempCell[0]->SetCol(1);
		tempCell[0]->SetRow(1);
		tempCell[1]->SetCol(0);
		tempCell[1]->SetRow(0);
		tempCell[2]->SetCol(-1);
		tempCell[2]->SetRow(-1);
		tempCell[3]->SetCol(2);
		tempCell[3]->SetRow(0);
	}
	else
	{
		tempCell[0]->SetCol(-1);
		tempCell[0]->SetRow(1);
		tempCell[1]->SetCol(0);
		tempCell[1]->SetRow(0);
		tempCell[2]->SetCol(1);
		tempCell[2]->SetRow(-1);
		tempCell[3]->SetCol(0);
		tempCell[3]->SetRow(2);
	}

	orientation++;

	if (orientation >= 4)
		orientation = 0;

	return tempCell;
}
