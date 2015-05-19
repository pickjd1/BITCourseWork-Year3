#pragma once
#include "TileMap.h"
#define OFFSET 128

ref class ViewPort
{
private:
	int viewportWorldX;
	int viewportWorldY;

	int viewportTilesWide;
	int viewportTilesHigh;

	TileMap^ backgroundMap;
	Graphics^ canvas;

public:
	ViewPort(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	void viewportMove(int xMove, int yMove);
	void moveRelativeToPlayer(int playerWorldX, int playerWorldY);
	void viewportDraw(int playerWorldX, int playerWorldY);

	Rectangle^ getViewRect();

	int getViewportWorldX()		{return viewportWorldX;}
	int getViewportWorldY()		{return viewportWorldY;}
};
