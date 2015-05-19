#pragma once
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


#define WANDER_PROB 5
#define DEFAULTFRAME 1
#define FRAMEWIDTH 32
#define FRAMEHEIGHT 32
#define SPRITEARRAY 10

ref class Sprite
{
	//sprite fields
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	Random^ rGen;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	
	//sprite methods
public:
	//constructor
	Sprite(Graphics^ startCanvas, Bitmap^ startSheet, Random^ startRGen, int startNFrames);
	Sprite(Graphics^ startCanvas, Bitmap^ startSheet, Random^ startRGen, int startNFrames, int startXPos, int startYPos, int startXVel, int startYVel );
	
	//draw the sprite
	void Draw();

	//erase the sprite
	void Erase(Color eraseColour);

	//move the sprite
	void Move();

	//update the current frame of the sprite
	void UpdateFrame();

	//set which sprite sheet is used for animation
	void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames, int newFrameWidth,int newFrameHeight);

	//set the chance of changing direction
	void Wander();

};
