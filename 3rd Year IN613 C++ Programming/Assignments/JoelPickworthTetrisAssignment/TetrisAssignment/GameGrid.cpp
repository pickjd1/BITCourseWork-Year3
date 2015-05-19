#include "StdAfx.h"
#include "GameGrid.h"

//game grid constructor
GameGrid::GameGrid(int row, int col, int xLoc, int yLoc, bool visible, Graphics^ buffer)
{
	this->buffer = buffer;
	this->row = row;
	this->col = col;
	this->xLoc = xLoc;
	this->yLoc = yLoc;
	this->visible = visible;
	height = 30;
	width = 30;
	bgColor = Color::Black;
	fillColor = bgColor;
}

void GameGrid::Draw()
{
	//If the grid item is visible draw it, if its a shape draw a border
	if (visible)
	{
		buffer->FillRectangle(gcnew SolidBrush(fillColor), Rectangle(xLoc, yLoc, width, height));
		if (fillColor != bgColor)
			buffer->DrawRectangle(gcnew Pen(Color::DodgerBlue), Rectangle(xLoc, yLoc, width, height));
	}
}
