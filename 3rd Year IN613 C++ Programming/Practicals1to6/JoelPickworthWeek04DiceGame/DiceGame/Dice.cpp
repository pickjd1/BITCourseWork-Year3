#include "StdAfx.h"
#include "Dice.h"


Dice::Dice(int startValue, PictureBox^ pBxStart, Random ^startRGen)
{
	diceValue = startValue;
	pictureBox = pBxStart;
	rGen = startRGen;
}

void Dice::roll()
{
	diceValue = rGen->Next(1,6);
	pictureBox->Image = Image::FromFile(diceValue + ".png");
}
