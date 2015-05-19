#include "StdAfx.h"
#include "Obstacle.h"

Obstacle::Obstacle(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName)
: Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName)
{
	r = 128;
	g = 255;
	b = 128;

	speed = 0;
	direction.X = 0;
	direction.Y = 0;

	radius = 20 + rGen->Next(10);
}
	
