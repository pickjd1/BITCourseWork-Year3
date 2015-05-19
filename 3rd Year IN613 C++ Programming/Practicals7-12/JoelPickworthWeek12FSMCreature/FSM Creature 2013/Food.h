#pragma once
#include "thing.h"

ref class Food :
public Thing
{
public:
	Food(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight,String^ imageFileName);
};
