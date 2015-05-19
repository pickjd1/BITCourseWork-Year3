#pragma once
#include "TileMap.h"

#define WANDER_PROB 5
#define DEFAULTFRAME 1
#define FRAMEWIDTH 32
#define FRAMEHEIGHT 32

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

ref class Car
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
	Car^ Next;

	Car(Graphics^ newCanvas, String^ StartFileNames, int newNFrames, int startXPos, int startYPos, TileMap^ startTileMap);

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
};