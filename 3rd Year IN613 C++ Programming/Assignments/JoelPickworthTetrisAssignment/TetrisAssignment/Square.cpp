#include "StdAfx.h"
#include "Square.h"

Square::Square(void)
{
	color = Color::Blue;
	cells = gcnew array<Cell^>(4);
	cells[0] = gcnew Cell(2,4);
	cells[1] = gcnew Cell(2,5);
	cells[2] = gcnew Cell(3,4);
	cells[3] = gcnew Cell(3,5);
}

array<Cell^>^ Square::Rotate()
{
	array<Cell^>^ tempCell = gcnew array<Cell^>(4);

	for (int i = 0; i < 4; i++)
	{
		tempCell[i] = gcnew Cell(cells[i]->GetRow(),cells[i]->GetCol());
	}

	return tempCell;
}
