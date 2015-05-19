#include "StdAfx.h"
#include "Pellet.h"

Pellet::Pellet(void)
{
}

Pellet::Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen)
{
	xPos = startXPos;
	yPos = startYPos;
	canvas = startCanvas;
	rGen = startRGen;

	Color customColour = Color::FromArgb(rGen->Next(255),rGen->Next(255),rGen->Next(255));
	brush = gcnew SolidBrush(customColour);

	Next = nullptr;

	yVel = -5;
	xVel = rGen->Next(10);
	int dir = rGen->Next(2);
	if (dir == 1)
		{
			xVel *= -1;
		}
}

void Pellet::draw()
{
	canvas->FillEllipse(brush, xPos, yPos, PELLET_DIAMETER, PELLET_DIAMETER);

}

void Pellet::move()
{
	xPos += xVel;
	yPos += yVel;

	if (yPos <= 0)
	{
		setIsAlive(false);
	}
}