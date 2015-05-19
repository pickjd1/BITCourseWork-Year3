#pragma once
#include "Tile.h"
#include "TileList.h"

#define COLS 320
#define ROWS 26
#define TILESIZE 32
ref class TileMap
{
private:
	TileList^ tileList;
	array<int,2>^ map;
	Graphics^ canvas;

public:
	//Tilemap Constructor
	TileMap(TileList^ startTileList, Graphics^ startCanvas);

	//Sets the parsed map value to the parsed Tile
	void setMapValue(int col, int row, int tileValue);

	//Retrieves the Tile value for the map value
	int getMapValue(int col, int row);

	//Checks if the tile the sprite is on is walkable
	bool checkSpritePos(int col, int row);
	
	//Draws the tilemap
	void drawMap(int startX, int startY, int xOffset, int yOffset);

	//Loads the tilemap from the parsed file
	void loadFromFile(String^ fileName);
};
