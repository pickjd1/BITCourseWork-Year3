#pragma once
#include "Tile.h"
#include "TileList.h"

#define COLS 100
#define ROWS 100
ref class TileMap
{
private:
	TileList^ tileList;
	array<int,2>^ map;
	Graphics^ canvas;

public:
	TileMap(TileList^ startTileList, Graphics^ startCanvas);

	void setMapValue(int col, int row, int tileValue);
	int getMapValue(int col, int row);

	void drawMap();

	Bitmap^ getTileBitmap(int row, int col)		{ return tileList->getTileBitmap(map[row,col]); }
};
