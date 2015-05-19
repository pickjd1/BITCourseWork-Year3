#include "StdAfx.h"
#include "Viewport.h"

	//Viewport constructor
Viewport::Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas)
	{
		viewportWorldX = startX;
		viewportWorldY = startY;
	
		tilesWide = startTilesWide;
		tilesHigh = startTilesHigh;

		viewportWide = (tilesWide/TILESIZE);
		viewportHigh = (tilesHigh/TILESIZE);

		viewTileX = 0;
		viewTileY = 0;

		xOffset = 0;
		yOffset = 0;

		canvas = startCanvas;
		tileMap = startBackgroundMap;

	}

	//Move the view port across the screen
	void Viewport::viewportMove(int playerWorldX)
	{
	viewportWorldX = playerWorldX -((viewportWide*TILESIZE)/2);

	if(viewportWorldX <= 0)
	 {
		viewportWorldX = 0;
	 }
	 if(viewportWorldX >= viewportWide * COLS)
	 {
		 viewportWorldX = viewportWide * COLS;
	 }
	}

	//Draw the tile map onto the view port
	void Viewport::viewportDraw()
	{
		viewTileX = viewportWorldX / TILESIZE; 
		viewTileY = viewportWorldY / TILESIZE;

		xOffset = tilesWide % TILESIZE;
		yOffset = tilesHigh % TILESIZE;

		tileMap->drawMap(viewTileX,viewTileY,xOffset,yOffset);
		
	}