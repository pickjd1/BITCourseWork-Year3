#pragma once
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Tile
{
private: 
	Bitmap^ tileImage;

public:
	//constructor
	Tile(Bitmap^ startImage);

	//returns the bitmap for the tile
	Bitmap^ getTileBitmap()	{return tileImage;}
};
