#pragma once
#include "GameGrid.h"
#include "TetrisShape.h"
#include "Line.h"
#include "S.h"
#include "Z.h"
#include "Square.h"
#include "J.h"
#include "L.h"
#include "T.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define GRAVITY 10

ref class TetrisGame
{

private:
	Graphics^ canvas;
	Graphics^ buffer;
	Bitmap^ bufferImage;

	KeyEventArgs^ keyPressed;

	array<GameGrid^, 2>^ grid;

	Random^ rGen;

	TetrisShape^ currShape;
	TetrisShape^ nextShape;

	array<Cell^>^ currCells;

	int loopState;

	int count;
	int gravity;
	int gravTemp;

	int score;
	int level;

	int levelUp;

public:
	TetrisGame(Graphics^ startCanvas, Random^ startRGen);
	void PopulateGrid();
	void NewGame();
	void CheckDown();
	void Update();
	void RotateCheck();
	void MoveCheck(int dir);
	void GameOverCheck();
	void RowCheck();
	void DeleteRow(int row);
	void DropRow(int r);
	void Draw();
	bool CheckKeyPressed();
	void Loop();
	TetrisShape^ GetShape();
	
	void SetKeyPressed(KeyEventArgs^ key) {keyPressed = key;}
};
