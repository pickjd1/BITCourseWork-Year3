#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Dice
{
private:
	int diceValue;
	PictureBox^ pictureBox;
	Random^ rGen;

public:
	Dice (int startValue, PictureBox^ pBxStart, Random^ startRGen);
	
		void roll();

	int getDiceValue() {return diceValue;}
};
