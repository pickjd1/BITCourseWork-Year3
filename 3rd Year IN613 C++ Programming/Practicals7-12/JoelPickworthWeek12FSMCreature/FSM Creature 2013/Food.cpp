#include "StdAfx.h"
#include "Food.h"

Food::Food(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName)
: Thing(startCanvas, startRandom, startWorldWidth, startWorldHeight, imageFileName)
{
	speed = 0;
	direction.X = 0;
	direction.Y = 0;

}

