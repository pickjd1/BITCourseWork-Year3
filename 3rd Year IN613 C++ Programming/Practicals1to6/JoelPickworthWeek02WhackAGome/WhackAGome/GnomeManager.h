#pragma once
#include "Gnome.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GnomeManager
{
private:
	//Field declarations
	Random^ rGen;
	Graphics^ canvas;
	int nGnomes;
	array<Gnome^>^ gnomeArray;
	Point newPoint;

public:
	//Constructor
	GnomeManager(Random^ startRandom, Graphics^ startCanvas, int startNGnomes);

	//Method to draw all gnomes
	void drawAllGnomes();
	//Method to draw one gnome at a time
	void drawOneGnome(int gnomeIndex);
	//Method to erase all gnomes
	void eraseAllGnomes();
	//Method to erase one gnome at a time
	void eraseOneGnome(int gnomeIndex);
	
	//Method to check if a gnome has been hit
	bool hitGnome(int gnomeIndex, Point p);

	//Method to change the gnome image
	void changeGnomeImage(int gnomeIndex, String^ newImageFileName);

	//Method to set a gnome to a hamster once it has been hit
	void setToHamster(int gnomeIndex);

	//Method to check if a gnome is a hamster or not
	bool isAHamster(int gnomeIndex) {return gnomeArray[gnomeIndex]->getIsAHamster();}

	//Method to return all gnomes in the array
	array<Gnome^>^ getGnomes(){ return gnomeArray; }
	
	//Method to reset all gnomes
	void resetAllGnomes();

};
