#include "StdAfx.h"
#include "SpriteList.h"

SpriteList::SpriteList(void)
{
}

void SpriteList::addSprite(Sprite^ newSprite)
{
	
	if(tail == nullptr)
	{
		head = newSprite;
		tail = newSprite;
	}
	else
	{
		tail->Next = newSprite;
		tail = newSprite;
	}
}



void SpriteList::deleteSprite(Sprite^ spriteToDelete)
{
	Sprite^ spriteWalker = head;

	spriteWalker = head;

	if(spriteToDelete == head)
	{
		head = head->Next;
	}

	else
	{
		while(spriteWalker->Next != spriteToDelete)
		{
			spriteWalker = spriteWalker->Next;
		}
	}

	spriteWalker->Next = spriteToDelete->Next;
}


int SpriteList::countSprites()
{
	Sprite^ spriteWalker = head;

	spriteWalker = head;

	int spriteCount = 0; 

	while(spriteWalker != nullptr)
	{
		spriteCount++;
		spriteWalker = spriteWalker->Next;
	}

	return spriteCount;		
}

void SpriteList::renderSprite()
{
	Sprite^ spriteWalker = head;
	while(spriteWalker != nullptr)
	{
		if(spriteWalker->getIsAlive() == false)
		{
			deleteSprite(spriteWalker);
		}
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::movePlayerSprites()
{
Sprite^ spriteWalker = head;
	while(spriteWalker != nullptr)
	{
		spriteWalker->UpdateState();
		//spriteWalker->PerformAction();
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::moveNPC()
{
	Sprite^ spriteWalker = head;
	while(spriteWalker != nullptr)
	{
		spriteWalker->Wander();
		spriteWalker = spriteWalker->Next;
	}

}

void SpriteList::updateSprites()
{
	Sprite^ spriteWalker = head;
	while(spriteWalker != nullptr)
	{
		spriteWalker->Draw();
		spriteWalker->UpdateState();
		spriteWalker->PerformAction();
		spriteWalker->UpdateFrame();
		spriteWalker = spriteWalker->Next;
	}
}
