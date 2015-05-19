#pragma once
#include "Dice.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Player
{
private:
	array<Dice^>^ dice;
	int diceTotal;
	int gameTotal;

public:
	Player(array<Dice^>^ startDice);

	void playerRoll();

	int computeDiceTotal();
	void updateGameTotal();

	int getDiceTotal() {return diceTotal;}
	int getGameTotal() {return gameTotal;}
};
