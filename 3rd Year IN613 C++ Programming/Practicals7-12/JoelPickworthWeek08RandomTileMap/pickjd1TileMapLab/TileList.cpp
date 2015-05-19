#include "StdAfx.h"
#include "TileList.h"

//constructor for the tile list
TileList::TileList(void)
{
	tileArray = gcnew array<Tile^,1>(TILEARRAYSIZE);
}

//gets the bitmap from the tile 
Bitmap^ TileList::getTileBitmap(int tileIndex)
{
	return tileArray[tileIndex]->getTileBitmap();
}

//sets a new tile at the grid index
void TileList::setTileArrayEntry(int tileIndex, Tile^ newTile)
{
	tileArray[tileIndex] = newTile;
}