#include "Cell.h"
#pragma once


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class TetrisShape
{

protected:
	Color color;

	int orientation;

	array <Cell^>^ cells;


public:
	
	TetrisShape();

	array<Cell^>^ Move(int dir);

	array<Cell^>^ Down();

	virtual array<Cell^>^ Rotate();
	
	void SetCells(array<Cell^>^ cells) {this->cells = cells;}

	array<Cell^>^ GetCells() {return cells;}
	Color GetColor() {return color;}

};
