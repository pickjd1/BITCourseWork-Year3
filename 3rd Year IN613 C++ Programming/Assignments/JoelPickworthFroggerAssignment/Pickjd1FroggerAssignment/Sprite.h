#pragma once
#include "TileMap.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


#define WINNER 20
#define WANDER_PROB 5
#define DEFAULTFRAME 1
#define FRAMEWIDTH 32
#define FRAMEHEIGHT 32

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

ref class Sprite
{
	//sprite fields
private:
	Graphics^ canvas;
	Bitmap^ spriteSheet;
	array<Bitmap^>^ spriteSheets;
	Random^ rGen;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	int spriteDirection;
	array <Point^>^ velocityDirections;

	TileMap^ tileMap;
	Rectangle^ boundsRect;
	
	//sprite methods
public:
	//constructor
	Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames);
	Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startXPos, int startYPos, int startDirection);
	Sprite(Graphics^ newCanvas, array<String^>^ StartFileNames, int newNFrames, int startXPos, int startYPos, TileMap^ startTileMap);
	Sprite(Graphics^ newCanvas, String^ StartFileNames, int newNFrames, int startXPos, int startYPos, TileMap^ startTileMap);
	//draw the sprite
	void Draw();

	//draw the sprite
	void DrawCar();

	//erase the sprite
	void Erase(Color eraseColour);

	//move the sprite
	void Move();

	//move the cars at different speeds
	void MoveRand(int newXVel);

	//update the current frame of the sprite
	void UpdateFrame();

	//set which sprite sheet is used for animation
	void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames, int newFrameWidth,int newFrameHeight);

	//set the chance of changing direction
	void Wander();

	//set the sprites current direction
	
	void setSpriteDirection(int direction);

	bool checkForWin();

};