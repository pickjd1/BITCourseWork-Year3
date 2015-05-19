#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Cell
{
//cell fields
private:
	//bool filled;
	//Color c;
	int row;
	int col;

//cell methods
public:
	//cell constructor
	Cell(int row, int col);

	int GetRow() {return row;}
	int GetCol() {return col;}

	void SetRow(int inc) {row += inc;}
	void SetCol(int inc) {col += inc;}

};
