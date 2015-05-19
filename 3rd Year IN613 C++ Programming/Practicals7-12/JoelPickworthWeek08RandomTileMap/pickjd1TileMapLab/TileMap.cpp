#include "StdAfx.h"
#include "TileMap.h"

//tile map constructor
TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	tileList = startTileList;
	canvas = startCanvas;
	map = gcnew array<int,2>(COLS,ROWS);
}

//set the values of the map grid
void TileMap::setMapValue(int col, int row, int tileValue)
{
	map[col,row] = tileValue;
}

//return the value of a grid square
int TileMap::getMapValue(int col, int row)
{
	int currentTileIndex = map[col,row];
	return currentTileIndex;
}

//draw the map
void TileMap::drawMap()
{
	for (int col = 0; col < COLS; col++)
	{
		for (int row = 0; row < ROWS; row++)
		{
			int curIndex = map[col,row];
			Bitmap^ curBitmap = tileList->getTileBitmap(curIndex);
			int xLoc = col * curBitmap->Width;
			int yLoc = row * curBitmap->Height;
			canvas->DrawImage(curBitmap,xLoc, yLoc);
		}
	}
}
