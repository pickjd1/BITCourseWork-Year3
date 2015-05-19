#pragma once
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

ref class Tile
{
private: 
	Bitmap^ tileImage;
	bool isWalkable;

public:
	//constructor
	Tile(Bitmap^ startImage,bool startIsWalkable);

	//returns the bitmap for the tile
	Bitmap^ getTileBitmap()	{return tileImage;}
	bool getIsWalkable() {return isWalkable;}
};
