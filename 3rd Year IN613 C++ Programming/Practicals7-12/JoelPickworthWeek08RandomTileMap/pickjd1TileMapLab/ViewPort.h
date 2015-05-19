#pragma once

ref class ViewPort
{
private:
	int viewportWorldX;
	int viewportWorldY;

	int viewportWide;
	int viewportHigh;

	TileMap^ backgroundMap;
	Graphics^ canvas;

public:
	ViewPort(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	void viewportMove(int xMove, int yMove);
	void viewportDraw();

	int getViewportWorldX()		{return viewportWorldX;}
	int getViewportWorldY()		{return viewportWorldY;}
};
