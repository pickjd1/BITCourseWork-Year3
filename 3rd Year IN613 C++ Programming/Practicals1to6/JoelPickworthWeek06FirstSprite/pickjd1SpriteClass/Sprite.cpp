#include "StdAfx.h"
#include "Sprite.h"

//constructor
Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSheet, Random^ startRGen, int startNFrames)
{
	canvas = startCanvas;
	spriteSheet = startSheet;
	rGen = startRGen;
	nFrames = startNFrames;
	currentFrame = 0;
}

//overloaded constructor
Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSheet, Random^ startRGen, int startNFrames, int startXPos, int startYPos, int startXVel, int startYVel )
{
	canvas = startCanvas;
	spriteSheet = startSheet;
	rGen = startRGen;
	nFrames = startNFrames;
	xPos = startXPos;
	yPos = startYPos;
	xVel = startXVel;
	yVel = startYVel;
	currentFrame = 0;

}


	//draw the sprite
	void Sprite::Draw()
	{

			int startX = currentFrame * FRAMEWIDTH;
			int startY = 0;

			spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));

			Rectangle drawRect = Rectangle(startX, startY, FRAMEWIDTH, FRAMEHEIGHT);
			canvas->DrawImage(spriteSheet,xPos,yPos,drawRect,GraphicsUnit::Pixel);

	}

	//erase the sprite
	void Sprite::Erase(Color eraseColour)
	{
		Brush^ brush = gcnew SolidBrush(eraseColour);
		canvas->FillRectangle(brush, xPos, yPos, FRAMEWIDTH, FRAMEHEIGHT);
	}	

	//move the sprite
	void Sprite::Move()
	{
		xPos += xVel;
		yPos += yVel;

		/*if (xPos <= 0)
		{
			xVel=;
		}*/
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
			xVel *= -1;
		}

		if (rGen->Next(WANDER_PROB) == 1)
		{
			yVel *= -1;
		}

	}	