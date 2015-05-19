#include "StdAfx.h"
#include "S.h"

S::S(void) : TetrisShape()
{
	color = Color::Orange;
	cells = gcnew array<Cell^>(4);
	cells[0] = gcnew Cell(2,5);
	cells[1] = gcnew Cell(2,6);
	cells[2] = gcnew Cell(3,4);
	cells[3] = gcnew Cell(3,5);
}

array<Cell^>^ S::Rotate()
{
	array<Cell^>^ tempCell = gcnew array<Cell^>(4);

	for (int i = 0; i < 4; i++)
	{
		tempCell[i] = gcnew Cell(cells[i]->GetRow(), cells[i]->GetCol());
	}

	if (orientation == 0)
	{
		tempCell[0]->SetCol(0);
		tempCell[0]->SetRow(0);
		tempCell[1]->SetCol(-1);
		tempCell[1]->SetRow(-1);
		tempCell[2]->SetCol(+2);
		tempCell[2]->SetRow(0);
		tempCell[3]->SetCol(1);
		tempCell[3]->SetRow(-1);
	}
	else
	{
		tempCell[0]->SetCol(0);
		tempCell[0]->SetRow(0);
		tempCell[1]->SetCol(1);
		tempCell[1]->SetRow(1);
		tempCell[2]->SetCol(-2);
		tempCell[2]->SetRow(0);
		tempCell[3]->SetCol(-1);
		tempCell[3]->SetRow(1);
	}

	orientation++;

	if (orientation >= 2)
		orientation = 0;

	return tempCell;
}

