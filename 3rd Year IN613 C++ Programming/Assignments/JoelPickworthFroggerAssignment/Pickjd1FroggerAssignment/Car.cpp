#include "StdAfx.h"
#include "Car.h"


Car::Car(Graphics^ newCanvas, String^ StartFileNames, int newNFrames, int startXPos,
			   int startYPos, TileMap^ startTileMap)
{
	canvas = newCanvas;   
	tileMap = startTileMap;

	spriteSheet = gcnew Bitmap(StartFileNames);
	Color tc = spriteSheet->GetPixel(0,0);
	spriteSheet->MakeTransparent(tc);


	velocityDirections = gcnew array<Point^>(4);
	velocityDirections[0] = Point(0,-1);				  //North
	velocityDirections[1] = Point(0,1);                   //South
	velocityDirections[2] = Point(-1,0);				  //West
	velocityDirections[3] = Point(1,0);				      //East

	nFrames = newNFrames;
	frameWidth = (int)spriteSheet->Width/nFrames;	  //Set width of each frame
	frameHeight = spriteSheet->Height;				  //set height of each frame
	xVel = 16;								     		  //speed along x axis
	yVel = 16;									    	  //speed along y axis
	xPos = startXPos;									  //sprites postion on x axis
	yPos = startYPos;									  //sprites postion on the y axis					
	currentFrame = 0;								      //number of frames the animation has

	boundsRect = Rectangle(xPos, yPos, frameWidth, frameHeight);

}


	//draw the sprite
	void Car::Draw()
	{

			int startX = currentFrame * frameWidth;
			int startY = 0;

			Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);
			
			Bitmap^ currentBitmap = spriteSheets[0];

			canvas->DrawImage(currentBitmap,xPos,yPos,drawRect,GraphicsUnit::Pixel);

	}

	//draw the sprite
	void Car::DrawCar()
	{

			int startX = currentFrame * frameWidth;
			int startY = 0;

			Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);
			
			Bitmap^ currentBitmap = spriteSheet;

			canvas->DrawImage(currentBitmap,xPos,yPos,drawRect,GraphicsUnit::Pixel);

	}

	//erase the sprite
	void Car::Erase(Color eraseColour)
	{
		Brush^ brush = gcnew SolidBrush(eraseColour);
		canvas->FillRectangle(brush, xPos, yPos, frameWidth, frameHeight);
	}	

	//move the sprite
	void Car::Move()
	{
		xPos += xVel* (velocityDirections[spriteDirection]->X);
		yPos += yVel* (velocityDirections[spriteDirection]->Y);

	}	

		void Car::MoveRand(int newXVel)
	{
		xVel = newXVel;
		xPos += xVel* (velocityDirections[spriteDirection]->X);

	}

	//update the current frame of the sprite
	void Car::UpdateFrame()
	{
		currentFrame = (currentFrame + 1) % nFrames;
	}	

	//set which sprite sheet is used for animation
	void Car::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames, int newFrameWidth,int newFrameHeight)
	{
		spriteSheet = newSpriteSheet;
		nFrames = newNFrames;
		frameWidth = newFrameWidth;
		frameHeight = newFrameHeight;
	}	

	//set the chance of changing direction
	void Car::Wander()
	{

		if (rGen->Next(WANDER_PROB) == 1)
		{
			spriteDirection = rGen->Next(0,3);
		}

	}	

	void Car::setSpriteDirection(int direction)
{
	spriteDirection = direction;
}
