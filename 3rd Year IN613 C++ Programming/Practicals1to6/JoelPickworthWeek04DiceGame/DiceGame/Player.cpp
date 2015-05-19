#include "StdAfx.h"
#include "Player.h"
#include "Dice.h"

Player::Player(array<Dice^>^ startDice)
{
	dice = startDice;
}


void Player::playerRoll()
{
	for(int i = 0; i < dice->Length; i++)
	{
		dice[i]->Dice::roll();
	}
}

int Player::computeDiceTotal()
{
	diceTotal = 0;
	for(int i = 0; i< dice->Length; i++)
	{
		diceTotal += (dice[i]->getDiceValue());
	}
	return diceTotal;
}

void Player::updateGameTotal()
{
	gameTotal = gameTotal + diceTotal;
}