#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Thing
{

public:
	Point location;
	int isAlive;
	int radius;
protected:
	Point direction;
	int speed;
	Graphics^ canvas;
	int r, g, b;
	Random^ rGen;
	int worldWidth, worldHeight;
	Bitmap^ thingImage;

public:
	Thing();
	Thing(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName);

	void Move();
	void ChangeRandomDirection();
	virtual void Draw();
	void PointMeAt(int newX, int newY);
	double ComputeDistance(Thing^ otherGuy);
};
