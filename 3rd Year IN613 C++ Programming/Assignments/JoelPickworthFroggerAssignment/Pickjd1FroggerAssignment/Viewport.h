#pragma once
#include "TileMap.h"
#define OFFSET 50
ref class Viewport
{
private:
	int viewportWorldX;
	int viewportWorldY;

	int viewportTilesWide;
	int viewportTilesHigh;

	TileMap^ backgroundMap;
	Graphics^ canvas;

public:
	Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	void viewportMove(int xMove, int yMove);
	void moveRelativeToPlayer(int playerWorldX, int playerWorldY);
	void viewportDraw();

	Rectangle^ getViewRect();

	int getViewportWorldX()		{return viewportWorldX;}
	int getViewportWorldY()		{return viewportWorldY;}
};
