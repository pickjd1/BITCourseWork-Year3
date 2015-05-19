#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class TetrisBlock
{
//block fields
private:
	System::Drawing::Color blockColor;
	int orientation;
	array <Point^> square;
	GameGrid^ myGrid;
	bool isAlive;

//block methods
public:
	//block constructor
	TetrisBlock(Color startColor, int startOrientation, GameGrid^ startGrid, array <Point^> startSquare, bool startIsAlive);

	//rotate the block
	void Rotation();

	//move the block down
	void MoveDown();

	//move the block left
	void MoveLeft();

	//move the block right
	void MoveRight();

	//check if the block is able to move down
	void CheckMoveDown();

	//add the block to the dead block pile
	void AddToPile();

	//draw the block
	void Draw();

};
