#pragma once
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



ref class Gnome
{
private:
	//Field Declarations
	Graphics^ canvas;
	Image^ gnomeImage;
	Image^ hamsterImage;
	bool isAHamster;
	bool visible;
	Point p;

public:
	//Constructor
	Gnome(Graphics^ startCanvas, Point startP);
	//Method to draw gnomes
	void Draw(bool isAHamster);
	//Method to erase gnome pictures
	void Erase();
	//Method to change the image of the gnomes
	void changeImage(Image^ newImageFile);
	//Method to check the points of the gnomes
	bool pointCheck(Point p);

	//Gets and sets for fields
	bool getIsAHamster()	{return isAHamster;}
	void setIsAHamster(bool i)		{isAHamster = i;}

	bool getVisible(){ return visible; }
	void setVisible(bool v){ visible = v; }

};
