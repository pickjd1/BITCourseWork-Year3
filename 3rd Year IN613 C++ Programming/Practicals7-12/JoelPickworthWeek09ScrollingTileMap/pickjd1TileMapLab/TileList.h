#pragma once
#include "Tile.h"

#define TILEARRAYSIZE 100
ref class TileList
{
private:
	array<Tile^>^ tileArray;

public:
	TileList(void);

	Bitmap^ getTileBitmap(int tileIndex);
	void setTileArrayEntry(int tileIndex, Tile^ newTile);
};
