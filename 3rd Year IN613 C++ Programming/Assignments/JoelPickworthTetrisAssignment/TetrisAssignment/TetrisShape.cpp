#include "StdAfx.h"
#include "TetrisShape.h"

TetrisShape::TetrisShape()
{
	orientation = 0;
}


array<Cell^>^ TetrisShape::Move(int dir)
{
	array<Cell^>^ tempCells = gcnew array<Cell^>(4);
	for (int i = 0; i < 4; i++)
	{
		tempCells[i] = gcnew Cell(cells[i]->GetRow(),cells[i]->GetCol());
	}

	for (int i = 0; i < 4; i++)
	{
		tempCells[i]->SetCol(dir);
	}

	return tempCells;
}

array<Cell^>^ TetrisShape::Down()
{

	array<Cell^>^ tempCells = gcnew array<Cell^>(4);
	for (int i = 0; i < 4; i++)
	{
		tempCells[i] = gcnew Cell(cells[i]->GetRow(), cells[i]->GetCol());
	}
	

	for (int i = 0; i < 4; i++)
	{
		tempCells[i]->SetRow(1);
	}

	return tempCells;
}

array<Cell^>^ TetrisShape::Rotate()
{
	return nullptr;
}