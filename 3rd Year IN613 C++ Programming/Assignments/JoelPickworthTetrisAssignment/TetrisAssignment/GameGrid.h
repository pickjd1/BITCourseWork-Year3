#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//define the grid constants



ref class GameGrid
{
	//declare the game grid fields
private:
	//Buffer for drawing
	Graphics^ buffer;
	//grid cell location in grid
	int row;
	int col;
	//height and width
	int height;
	int width;
	//Loction on screen
	int xLoc;
	int yLoc;
	//Colors
	Color fillColor;
	Color bgColor;
	//bools regarding state
	bool full;
	bool visible;

	//declare the game grid methods
public:
	//game grid constructor
	GameGrid(int row, int col, int xLoc, int yLoc, bool visible, Graphics^ buffer);
	void Draw();
	
	void ResetColor() {fillColor = bgColor;}

	void SetFull(bool full) {this->full = full;}
	void SetFillColor(Color color) {fillColor = color;}
	
	int GetXLoc() {return xLoc;}
	int GetYLoc() {return yLoc;}
	bool GetFull() {return full;}
	Color GetFillColor() {return fillColor;}
	

};
