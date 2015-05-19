#include "StdAfx.h"
#include "Tile.h"

//constructor for the tile

Tile::Tile(Bitmap^ startImage, bool startIsWalkable)
{
	tileImage = startImage;
	isWalkable = startIsWalkable;
}

