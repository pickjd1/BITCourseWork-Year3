#include "StdAfx.h"
#include "Gnome.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

Gnome::Gnome(Graphics^ startCanvas, Point startP)
{
	canvas = startCanvas;
	p = startP;
	isAHamster = false;
	gnomeImage = Image::FromFile ("gnome.jpg");
	hamsterImage = Image::FromFile ("hamster.jpg");
}

	void Gnome::Draw(bool isAHamster)
	{
		if(isAHamster == false)
		{
			canvas->DrawImage(gnomeImage, p.X, p.Y);
		}
		else
		{
			canvas->DrawImage(hamsterImage, p.X, p.Y);
		}
	}

	void Gnome::Erase()
	{
		canvas->FillRectangle(gcnew SolidBrush(Color::White),
			Rectangle(p.X, p.Y, gnomeImage->Width, gnomeImage->Height));
	}

	void Gnome::changeImage(Image^ newImageFile)
	{
		gnomeImage = newImageFile;
	}

	bool Gnome::pointCheck(Point p)
	{
		if(Rectangle(p.X, p.Y, gnomeImage->Width, gnomeImage->Height).Contains(p))
		{			
			setIsAHamster(true);
			return true;
		}
		else
		{
			return false;
		}
	}