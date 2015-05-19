#pragma once
#include "Sprite.h"
#include "TileMap.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//Sprite definitions
#define North 0
#define South 1
#define East 2
#define West 3
#define STOP 0
#define WALK 1
#define	JUMP 2
#define FALLING 3

ref class Sprite
{
private:
	//Sprite fields
	bool collided;
	int spriteState;
	Random^ rand;
	Graphics^ canvas;
	TileMap^ tileMap;
	array <Bitmap^>^ spriteSheets;
	array <Point^>^ velocityDirections;
	int gravity;
	int nFrames;
	int currentFrame;
	int xPos;
	int yPos;
	int frameWidth;
	int frameHeight;
	int xVel;
	int yVel;
	int spriteDirection;
	int boundsAction;
	Rectangle boundsRect;
	bool isAlive;
public:
	Sprite^ Next;
	
public:
	//Sprite constructor and overloaded constructor
	Sprite(Graphics^ newCanvas, array<String^>^ KnightFileNames, int newNFrames, TileMap^ startTileMap);
	Sprite::Sprite(Graphics^ newCanvas, array<String^>^ StartFileNames, int newNFrames, int startXPos,
			   int startYPos, int startDirection, TileMap^ startTileMap);
	//Draws the sprite
	void Draw();
	void forcedDraw(int forcedX, int forcedY);
	//Erases the used sprite sheet drawings
	void Erase(Color eraseColor);

	//Sprite FSM for movement and behavior
	void PerformAction();

	//Updates the FSM sprite states for each timer tick dependant on events
	void UpdateState();
	
	void Wander();
	//Enables the sprite to walk
	void Walk();

	//Enables the sprite to jump
	void Jump();

	//Simulates the effect of gravity upon the player
	void Gravity();

	//Sets the sprites idle action
	void Stop();

	//Method to kill the sprite
	void Die();

	void Wrap();
	void Bounce();

	//Updates the sprite sheet frame
	void UpdateFrame();

	//Checks if the sprite has collided with tiles below it
	bool Collided();

	//Method to set the sprites current direction
	void setSpriteDirection(int direction);

	//Checks to see if the sprite is still alive
	bool getIsAlive() {return isAlive;}
	
	//Methods to return the sprites position
	int getXPos() {return xPos;}
	int getYPos() {return yPos;}

	//Method to set a new spritesheet
	//void SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames);
};