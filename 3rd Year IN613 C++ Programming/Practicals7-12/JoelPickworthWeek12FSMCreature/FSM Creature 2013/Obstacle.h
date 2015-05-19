#pragma once
#include "thing.h"

ref class Obstacle : public Thing
{
public:
	Obstacle(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName);
};
