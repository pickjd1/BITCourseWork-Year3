#pragma once
#include "TileMap.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

//Defines the viewport grid values
#define GRIDWIDE 320
#define GRIDHIGH 24

ref class Viewport
{
private:
	//Define fields
	int viewportWorldX;
	int viewportWorldY;

	int tilesWide;
	int tilesHigh;

	int viewportWide;
	int viewportHigh;

	int viewTileX;
	int viewTileY;

	int xOffset;
	int	yOffset;

	TileMap^ tileMap;
	Graphics^ canvas;


public:
	//Viewport constructor
	Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	//Moves the viewport with the player
	void viewportMove(int playerWorldX);

	//Draws the viewport
	void viewportDraw();

	//Returns the viewport position values
	int getViewportWorldX()		{return viewportWorldX;}
	int getViewportWorldY()		{return viewportWorldY;}
};