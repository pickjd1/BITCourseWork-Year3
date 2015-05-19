#include "StdAfx.h"
#include "GnomeManager.h"

GnomeManager::GnomeManager(Random^ startRandom, Graphics^ startCanvas, int startNGnomes)
{
rGen = startRandom;
	canvas = startCanvas;
	nGnomes = startNGnomes;


	gnomeArray = gcnew array<Gnome^>(nGnomes);

	for (int g=0; g<nGnomes; g++)
	{
		Point newPoint(rGen->Next(10,750),rGen->Next(10,550));
		gnomeArray[g] = gcnew Gnome(canvas, newPoint);
	}

}
	void GnomeManager::drawAllGnomes()
	{
		for (int i = 0; i < gnomeArray->Length; i++)
		{
			if(gnomeArray[i]->getIsAHamster() == true)
			{
				gnomeArray[i]->Draw(true);
			}
			else gnomeArray[i]->Draw(false);
		}
	}

	void GnomeManager::drawOneGnome(int gnomeIndex)	
	{
		if(gnomeArray[gnomeIndex]->getIsAHamster() == false)
			{
				gnomeArray[gnomeIndex]->Draw(false);
			}
	}

	void GnomeManager::eraseAllGnomes()	
	{
		for(int i = 0; i < gnomeArray->Length; i++)
		{
			gnomeArray[i]->setVisible(false);
		}
	}

	void GnomeManager::eraseOneGnome(int gnomeIndex)	
	{
		gnomeArray[gnomeIndex]->setVisible(false);
	}
	
	bool GnomeManager::hitGnome(int gnomeIndex, Point p)	
	{
		return gnomeArray[gnomeIndex]->pointCheck(p);
	}

	void GnomeManager::changeGnomeImage(int gnomeIndex, String^ newImageFileName)	
	{
		//nGnomes[gnomeIndex]
	}

	void GnomeManager::setToHamster(int gnomeIndex)	
	{
		gnomeArray[gnomeIndex]->setIsAHamster(true);
	}

	void GnomeManager::resetAllGnomes()	
	{
	}