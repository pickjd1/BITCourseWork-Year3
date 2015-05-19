#include "StdAfx.h"
#include "Sprite.h"

//constructor
Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames)
{
	canvas = startCanvas;

	nFrames = startNFrames;
	currentFrame = 0;

	rGen = gcnew Random();

	spriteSheets = gcnew array<Bitmap^>(4);

	for(int f=0; f<4; f++)                                 
	{
		spriteSheets[f] = gcnew Bitmap(startFileNames[f]);
		Color tc = spriteSheets[f]->GetPixel(0,0);
		spriteSheets[f]->MakeTransparent(tc);
	}

	velocityDirections = gcnew array<Point^>(4);

	velocityDirections[0] = Point(0,-1);				  
	velocityDirections[1] = Point(0,1);                   
	velocityDirections[2] = Point(-1,0);				  
	velocityDirections[3] = Point(1,0);	
}

//overloaded constructor
Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startXPos, int startYPos, int startDirection)
{
	canvas = startCanvas;

	nFrames = startNFrames;
	xPos = startXPos;
	yPos = startYPos;

	rGen = gcnew Random();

	xVel = 16;
	yVel = 16;

	currentFrame = 0;

	spriteDirection = startDirection;

	spriteSheets = gcnew array<Bitmap^>(4);

	for(int f=0; f<4; f++)                                 
	{
		spriteSheets[f] = gcnew Bitmap(startFileNames[f]);
		Color tc = spriteSheets[f]->GetPixel(0,0);
		spriteSheets[f]->MakeTransparent(tc);
	}

	velocityDirections = gcnew array<Point^>(4);

	velocityDirections[0] = Point(0,-1);				  
	velocityDirections[1] = Point(0,1);                   
	velocityDirections[2] = Point(1,0);				  
	velocityDirections[3] = Point(-1,0);	

	frameWidth = spriteSheets[0]->Width/nFrames;	
	frameHeight = spriteSheets[0]->Height;

}

Sprite::Sprite(Graphics^ newCanvas, array<String^>^ StartFileNames, int newNFrames, int startXPos,
			   int startYPos, TileMap^ startTileMap)
{
	canvas = newCanvas;   
	tileMap = startTileMap;
	
	spriteSheets = gcnew array<Bitmap^>(1);

	for(int f=0; f<1; f++)                                 //fill the array with image files
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
	xVel = 16;								     		  //speed along x axis
	yVel = 16;									    	  //speed along y axis
	xPos = startXPos;									  //sprites postion on x axis
	yPos = startYPos;									  //sprites postion on the y axis					
	currentFrame = 0;								      //number of frames the animation has

	boundsRect = Rectangle(xPos, yPos, frameWidth, frameHeight);

}

Sprite::Sprite(Graphics^ newCanvas, String^ StartFileNames, int newNFrames, int startXPos,
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
	void Sprite::Draw()
	{

			int startX = currentFrame * frameWidth;
			int startY = 0;

			Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);
			
			Bitmap^ currentBitmap = spriteSheets[0];

			canvas->DrawImage(currentBitmap,xPos,yPos,drawRect,GraphicsUnit::Pixel);

	}

	//draw the sprite
	void Sprite::DrawCar()
	{

			int startX = currentFrame * frameWidth;
			int startY = 0;

			Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);
			
			Bitmap^ currentBitmap = spriteSheet;

			canvas->DrawImage(currentBitmap,xPos,yPos,drawRect,GraphicsUnit::Pixel);

	}

	//erase the sprite
	void Sprite::Erase(Color eraseColour)
	{
		Brush^ brush = gcnew SolidBrush(eraseColour);
		canvas->FillRectangle(brush, xPos, yPos, frameWidth, frameHeight);
	}	

	//move the sprite
	void Sprite::Move()
	{
		xPos += xVel* (velocityDirections[spriteDirection]->X);
		yPos += yVel* (velocityDirections[spriteDirection]->Y);

	}	

		void Sprite::MoveRand(int newXVel)
	{
		xVel = newXVel;
		xPos += xVel* (velocityDirections[spriteDirection]->X);

	}

	//update the current frame of the sprite
	void Sprite::UpdateFrame()
	{
		currentFrame = (currentFrame + 1) % nFrames;
	}	

	//set which sprite sheet is used for animation
	void Sprite::SetSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames, int newFrameWidth,int newFrameHeight)
	{
		spriteSheet = newSpriteSheet;
		nFrames = newNFrames;
		frameWidth = newFrameWidth;
		frameHeight = newFrameHeight;
	}	

	//set the chance of changing direction
	void Sprite::Wander()
	{

		if (rGen->Next(WANDER_PROB) == 1)
		{
			spriteDirection = rGen->Next(0,3);
		}

	}	

	void Sprite::setSpriteDirection(int direction)
{
	spriteDirection = direction;
}

	bool Sprite::checkForWin()
	{
		if (yPos <= WINNER)
		{
			return true;
		} else return false;
	}
