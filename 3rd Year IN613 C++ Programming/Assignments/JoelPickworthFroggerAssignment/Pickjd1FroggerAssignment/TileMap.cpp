#include "StdAfx.h"
#include "TileMap.h"

using namespace System::IO;

//tile map constructor
TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	tileList = startTileList;
	canvas = startCanvas;
	map = gcnew array<int,2>(COLS,ROWS);
}

//set the values of the map grid
void TileMap::setMapValue(int col, int row, int tileValue)
{
	map[col,row] = tileValue;
}

//return the value of a grid square
int TileMap::getMapValue(int col, int row)
{
	int currentTileIndex = map[col,row];
	return currentTileIndex;
}

//draw the map
void TileMap::drawMap()
{
	for (int col = 0; col < COLS; col++)
	{
		for (int row = 0; row < ROWS; row++)
		{
			int curIndex = map[col,row];
			Bitmap^ curBitmap = tileList->getTileBitmap(curIndex);
			int xLoc = col * curBitmap->Width;
			int yLoc = row * curBitmap->Height;
			canvas->DrawImage(curBitmap,xLoc, yLoc);
		}
	}
}

void TileMap::loadFromFile(String^ fileName)
{
					array<String^>^ indexHolder = gcnew array<String^>(COLS);
					int r = 0;

					StreamReader^ file = gcnew StreamReader(fileName);

					String^ line;
					
					while (line = file->ReadLine())
					{
						array<String^>^ indexHolder = line->Split(',');

							for (int c = 0; c < COLS; c++)
							{
								int tileValue = Convert::ToInt16(indexHolder[c]);
								map[c,r] = tileValue;
							}
						r++;
					}
					
					file->Close();

}
