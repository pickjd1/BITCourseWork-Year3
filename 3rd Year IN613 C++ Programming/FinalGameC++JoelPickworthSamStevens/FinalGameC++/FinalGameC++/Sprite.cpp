#include "StdAfx.h"
#include "Sprite.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//Constructor form the sprites
Sprite::Sprite(Graphics^ newCanvas, array<String^>^ StartFileNames, int newNFrames, TileMap^ startTileMap)
{
	rand = gcnew Random();
	canvas = newCanvas;  
	tileMap = startTileMap;
	String^ temp = StartFileNames[0];
		//Start graphics
	spriteSheets = gcnew array<Bitmap^>(4);
	for(int f=0; f<4; f++)                             //fill the array with image files
	{
		spriteSheets[f] = gcnew Bitmap(StartFileNames[f]);
		Color tc = spriteSheets[f]->GetPixel(0,0);
		spriteSheets[f]->MakeTransparent(tc);
	}
	velocityDirections = gcnew array<Point^>(4);
	velocityDirections[0] = Point(0,-1);				//North
	velocityDirections[1] = Point(0,1);                 //South
	velocityDirections[2] = Point(-1,0);				//West
	velocityDirections[3] = Point(1,0);				    //East								
	nFrames = newNFrames;
	frameWidth = (int)spriteSheets[0]->Width/nFrames;	//Set width of each frame
	frameHeight = spriteSheets[0]->Height;				//set height of each frame
	xVel = 0;								     		//speed along x axis
	yVel = 0;									    	//speed along y axis
	xPos = 200;										    //sprites postion on x axis
	yPos = 400;										    //sprites postion on the y axis					
	currentFrame = 0;								    //number of frames the animation has
	spriteDirection = West;                            //Set sprites direction
	Next = nullptr;
	//bool collided;
	spriteState = FALLING;
}

Sprite::Sprite(Graphics^ newCanvas, array<String^>^ StartFileNames, int newNFrames, int startXPos,
			   int startYPos, int startDirection, TileMap^ startTileMap)
{
	canvas = newCanvas;   
	tileMap = startTileMap;
	
	spriteSheets = gcnew array<Bitmap^>(4);
	for(int f=0; f<4; f++)                                 //fill the array with image files
	{
		spriteSheets[f] = gcnew Bitmap(StartFileNames[f]);
		Color tc = spriteSheets[f]->GetPixel(0,0);
		spriteSheets[f]->MakeTransparent(tc);
	}
	velocityDirections = gcnew array<Point^>(4);
	velocityDirections[0] = Point(0,-1);				  //North
	velocityDirections[1] = Point(0,1);                   //South
	velocityDirections[2] = Point(-1,0);				  //West
	velocityDirections[3] = Point(1,0);				      //East								
	nFrames = newNFrames;
	frameWidth = (int)spriteSheets[0]->Width/nFrames;	  //Set width of each frame
	frameHeight = spriteSheets[0]->Height;				  //set height of each frame
	xVel = 0;								     		  //speed along x axis
	yVel = 0;									    	  //speed along y axis
	xPos = startXPos;									  //sprites postion on x axis
	yPos = startYPos;									  //sprites postion on the y axis					
	currentFrame = 0;								      //number of frames the animation has
	spriteDirection = startDirection;                     //Set sprites direction
	boundsRect = Rectangle(xPos, yPos, frameWidth, frameHeight);
	//bool collided;
	Next = nullptr;
	spriteState = FALLING;
}

void Sprite::Draw()
{
		int currFrameX = currentFrame * frameWidth;
		int currFrameY = 0;
		//Create a rectangle for the sprites image to be drawn into, using the bitmaps height and each frames width
		Rectangle drawRect = Rectangle(currFrameX, currFrameY, frameWidth, frameHeight);
		boundsRect = drawRect;
		//set the direstion the knight should be facing
		Bitmap^ currentBitmap = spriteSheets[spriteDirection];
		//draw the knight to the form
		canvas->DrawImage(currentBitmap, xPos, yPos, drawRect, GraphicsUnit::Pixel);
}

void Sprite::forcedDraw(int forcedX, int forcedY)
{
	int currFrameX = currentFrame * frameWidth;
		int currFrameY = 0;
		//Create a rectangle for the sprites image to be drawn into, using the bitmaps height and each frames width
		Rectangle drawRect = Rectangle(currFrameX, currFrameY, frameWidth, frameHeight);
		//set the direction the sprite should be facing
		Bitmap^ currentBitmap = spriteSheets[spriteDirection];
		//draw the sprite to the form
		canvas->DrawImage(currentBitmap, forcedX, forcedY, drawRect, GraphicsUnit::Pixel);
}

void Sprite::Erase(Color eraseColor)
{
	Brush^ brush = gcnew SolidBrush(eraseColor);
	canvas->FillRectangle(brush,xPos, yPos, frameWidth, frameHeight);
}

//Moves Sprite
void Sprite::PerformAction()
{
	switch(spriteState)
	{
		case WALK:
			Walk();
			break;
		case STOP:
			Stop();
			break;
		case FALLING:
			Gravity();
		break;
	}
}
//Updates the FSM sprite states for each timer tick dependant on events
void Sprite::UpdateState()
{
	bool haveNotHitGround = Collided();
	boundsRect = Rectangle(xPos, yPos, frameWidth, frameHeight);
	switch(spriteState)
	{
	case WALK:
		if(haveNotHitGround == true)
		{
			spriteState = FALLING;
		}
		else
		{
			spriteState = STOP;
		}
		break;
	case STOP:
		if((spriteDirection == East) || (spriteDirection == West))
		{
			spriteState = WALK;
		}
		break;
	case FALLING:
		if(haveNotHitGround == false)
		{
			spriteState = STOP;
		}
		break;
	}
}

//Enables the sprite to walk
void Sprite::Walk()
{
	//walks left and right only
	xVel = 10;
	yVel = 0;
	xPos += xVel * (velocityDirections[spriteDirection]->X);
}

//Enables the sprite to jump
void Sprite::Jump()
{
	bool haveNotHitGround = Collided();
	if (haveNotHitGround == false)
	{
		yVel = -10;
		yPos = yPos + yVel;
		xVel = 10;
		xPos = xPos + xVel;
	}
}

//Simulates the effect of gravity upon the sprites
void Sprite::Gravity()
{
	//sprite move up and down
	yVel = yVel + 1;
	yPos = yPos + yVel;
	xPos += xVel;
}

//Checks if the sprite has collided with tiles below it
bool Sprite::Collided()
{
	//int xSpritePos = boundsRect.Left+(boundsRect.Width/2);
	//int ySpritePos = boundsRect.Top+(boundsRect.Height/2);

	return tileMap->checkSpritePos(xPos + (frameWidth/2), yPos + frameHeight);
}

//Wander method for enemies
void Sprite::Wander()
{
	
}

//Sets the sprite idle action
void Sprite::Stop()
{
	xVel = 0;
	yVel = 0;
	spriteDirection = South;
}

//Method to kill the sprite
void Sprite::Die()
{
	isAlive = false;
}


void Sprite::Wrap()
{
	/*if(xPos < boundsRect.Left)||((xPos + frameWidth) > boundsRect.Right)||
		(yPos < boundsRect.Top)||((yPos + frameHeight) > boundsRect.Bottom)
	{}*/
}

void Sprite::Bounce()
{
	
	if((xPos <= boundsRect.Left)||((xPos + frameWidth) >= boundsRect.Right))
	{
		spriteDirection = (spriteDirection + 2) % 4;
	}
	if((yPos <= boundsRect.Top)||((yPos + frameHeight) >= boundsRect.Bottom))
	{
		spriteDirection = (spriteDirection + 2) % 4;
	}
	
}

void Sprite::UpdateFrame()
{
	//loops through the array of bitmaps
	currentFrame = (currentFrame + 1) % 8;
}

void Sprite::setSpriteDirection(int direction)
{
	//used to pass the sprites diretion to the move method and set the direction of the sprite
	spriteDirection = direction;
}



/*
void Sprite::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{
	spriteSheet = newSpriteSheet;
	frameWidth = newNFrames * frameWidth;
	Rectangle drawRect = Rectangle(xPos, yPos, frameWidth, frameHeight);
	canvas->DrawImage(spriteSheet, xPos, yPos, drawRect, GraphicsUnit::Pixel);
}
*/