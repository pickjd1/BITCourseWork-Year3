#include "StdAfx.h"
#include "Viewport.h"

//Viewport constructor
Viewport::Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas)
{
	viewportWorldX = startX;
	viewportWorldY = startY;
	viewportTilesWide = startTilesWide;
	viewportTilesHigh = startTilesHigh;
	backgroundMap = startBackgroundMap;
	canvas = startCanvas;
}

//Move the view port across the screen
void Viewport::viewportMove(int xMove, int yMove)
{
	
	int boundsX = (COLS * TILE_SIZE) - (viewportTilesWide * TILE_SIZE);
	int boundsY = (ROWS * TILE_SIZE) - (viewportTilesHigh * TILE_SIZE);
	

	if(xMove < boundsX && xMove > 0)
		viewportWorldX += xMove;

	if(yMove < boundsY && yMove > 0)
		viewportWorldY += yMove;
}

//Move the viewpoint in relation to the player
void Viewport::moveRelativeToPlayer(int playerWorldX, int playerWorldY)
{
	
	int newViewportWorldX = playerWorldX - ((viewportTilesWide * TILE_SIZE) / 2);
	int newViewportWorldY = playerWorldY - ((viewportTilesHigh * TILE_SIZE) / 2);

	int viewportWidth = (COLS * TILE_SIZE) - (viewportTilesWide * TILE_SIZE);
	int viewportHeight = (ROWS * TILE_SIZE) - (viewportTilesHigh * TILE_SIZE);

	if(newViewportWorldX < viewportWidth && newViewportWorldX > 0)
		viewportWorldX = newViewportWorldX;
	if(newViewportWorldY < viewportHeight && newViewportWorldY > 0)
		viewportWorldY = newViewportWorldY;

	if(playerWorldX > (COLS * TILE_SIZE) - OFFSET)
		viewportWorldX = viewportWidth;

	if(playerWorldX < OFFSET)
		viewportWorldX = 0;

	if(playerWorldY > (ROWS * TILE_SIZE) - OFFSET)
		viewportWorldY = viewportHeight;

	if(playerWorldY < OFFSET)
		viewportWorldY = 0;	
}

//Draw the tile map onto the view port
void Viewport::viewportDraw()
{
	
	int startTileColumn = viewportWorldX / TILE_SIZE;	
	int startTileRow = viewportWorldY / TILE_SIZE;

	int offsetX = viewportWorldX % TILE_SIZE;
	int offsetY = viewportWorldY % TILE_SIZE;	

	for(int col = startTileColumn; col < startTileColumn + viewportTilesWide; col++)
	{
		for(int row = startTileRow; row < startTileRow + viewportTilesHigh; row++)
		{			
			Bitmap^ tileBitmap = backgroundMap->getTileBitmap(row, col);			

			// converts tiles back to pixels
			int screenX = (col - startTileColumn) * TILE_SIZE - offsetX;
			int screenY = (row - startTileRow) * TILE_SIZE - offsetY;

			canvas->DrawImage(tileBitmap, screenX, screenY);			
		}
	}
}

Rectangle^ Viewport::getViewRect()
{
	return Rectangle(viewportWorldX, viewportWorldY, viewportTilesWide,	viewportTilesHigh);
}