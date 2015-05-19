#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define PELLET_DIAMETER 10
#define PELLET_SPEED 10

ref class Pellet
{
private:
	int xPos;
	int yPos;
	int diameter;
	int xVel;
	int yVel;
	Color pelletColour;
	Graphics^ canvas;
	SolidBrush^ brush;
	bool isAlive;
	Random^ rGen;
public:
	Pellet^ Next;
public:
	Pellet(void);
	Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen);

	void draw();
	void move();

	bool getIsAlive()	{return isAlive;}
	void setIsAlive(bool a)	{isAlive = a;}

	int getYPos()	{return yPos;}
};
