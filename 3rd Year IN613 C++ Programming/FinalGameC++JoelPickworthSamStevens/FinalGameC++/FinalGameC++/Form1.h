#pragma once
#include "Sprite.h"
#include "SpriteList.h"
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include "Viewport.h"

namespace FinalGameC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
		Graphics^ graphics;
		Sprite^ indie;
		SpriteList^ Indies;
		Sprite^ spider;
		SpriteList^ Spiders;
		Sprite^ beetle;
		SpriteList^ Beetles;
		Image^ backgroundImage;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenGraphics;
		Brush^ brush;
		Rectangle rect;
		Random^ rGen;
		Viewport^ viewPort;

		Bitmap^ blank;
		Bitmap^ top;
		Bitmap^ bgWall;
		Bitmap^ btmPlatform;
		Bitmap^ btmWall;
		Bitmap^ platLeft;
		Bitmap^ platRight;
		Bitmap^ platMiddle;
		Bitmap^ colBot;
		Bitmap^ colTop;
		Bitmap^ spikes;

		TileList^ tileList;
		TileMap^ tileMap;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				//initialize the bitmaps
				blank = gcnew Bitmap("00.bmp");
				blank->MakeTransparent(blank->GetPixel(0,0));
				Tile^ blankTile = gcnew Tile(blank,false);

				top = gcnew Bitmap("01.bmp");
				Tile^ topTile = gcnew Tile(top,false);

				bgWall = gcnew Bitmap("02.bmp");
				Tile^ bgWallTile = gcnew Tile(bgWall,true);
				
				btmPlatform = gcnew Bitmap("03.bmp");
				Tile^ btmPlatformTile = gcnew Tile(btmPlatform,false);
				
				btmWall = gcnew Bitmap("04.bmp");
				Tile^ btmWallTile = gcnew Tile(btmWall,false);
				
				platLeft = gcnew Bitmap("05.bmp");
				Tile^ platLeftTile = gcnew Tile(platLeft,false);
				
				platRight = gcnew Bitmap("06.bmp");
				Tile^ platRightTile = gcnew Tile(platRight,false);
				
				platMiddle = gcnew Bitmap("07.bmp");
				Tile^ platMiddleTile = gcnew Tile(platMiddle,false);
				
				colBot = gcnew Bitmap("08.bmp");
				Tile^ colBotTile = gcnew Tile(colBot,false);
				//colBot->MakeTransparent(ColorTranslator::FromHtml("#4c5a8e"));
				
				colTop = gcnew Bitmap("09.bmp");
				Tile^ colTopTile = gcnew Tile(colTop,false);

				spikes = gcnew Bitmap("spikes02.bmp");
				Tile^ spikesTile = gcnew Tile(spikes,false);

				//initialize tile list
				tileList = gcnew TileList();
				tileList->setTileArrayEntry(0,blankTile);
				tileList->setTileArrayEntry(1,topTile);
				tileList->setTileArrayEntry(2,bgWallTile);
				tileList->setTileArrayEntry(3,btmPlatformTile);
				tileList->setTileArrayEntry(4,btmWallTile);
				tileList->setTileArrayEntry(5,platLeftTile);
				tileList->setTileArrayEntry(6,platRightTile);
				tileList->setTileArrayEntry(7,platMiddleTile);
				tileList->setTileArrayEntry(8,colBotTile);
				tileList->setTileArrayEntry(9,colTopTile);
				tileList->setTileArrayEntry(10,spikesTile);
			

				

				 
				 //Initialize the Indie sprite files
				 array<String^>^ IndieFileNames =
					 gcnew array <String^>{
						 "Knight Walk North 8.bmp",
						 "Knight Walk South 8.bmp",
						 "Knight Walk West 8.bmp",
						 "Knight Walk East 8.bmp"
				 };

				 //Initialize the spider enemy sprite files
				 array<String^>^ SpiderFileNames =
					 gcnew array <String^>{
				     	  "Little Chicken Walk North 8.bmp",
						 "Little Chicken Walk South 8.bmp",
						 "Little Chicken Walk West 8.bmp",
						 "Little Chicken Walk East 8.bmp"
				 };

				 //Initialize the beetle enemy sprite files
				 array<String^>^ BeetleFileNames =
					 gcnew array <String^>{
					 "BlobboMulti.bmp",
					 "BlobboMulti.bmp",
					 "BlobboMulti.bmp",
					 "BlobboMulti.bmp"
				 };

				graphics = CreateGraphics();
				//Initialize sprite lists
				 Indies = gcnew SpriteList();
				 Spiders = gcnew SpriteList();
				 Beetles = gcnew SpriteList();

				 //Load the background image
				 backgroundImage = Image::FromFile("background.png");

				 //Initialize graphics
				 offScreenBitmap = gcnew Bitmap(1024,768);
				 offScreenGraphics = Graphics::FromImage(offScreenBitmap);
				 tileMap = gcnew TileMap(tileList,offScreenGraphics);
				 timer1->Enabled = true;
				 indie = gcnew Sprite(offScreenGraphics,IndieFileNames, 8, tileMap);
				 Indies->addSprite(indie);
				 spider = gcnew Sprite(offScreenGraphics, SpiderFileNames, 8, tileMap);
				 Spiders->addSprite(spider);	 
				 beetle = gcnew Sprite(offScreenGraphics, BeetleFileNames, 8, tileMap);
				 Beetles->addSprite(beetle);

				 //Load and initialize the tilemap filename
				String^ FirstLevel = "FirstLevel.csv";
				tileMap->loadFromFile(FirstLevel);

				//Initialize the viewport
				viewPort = gcnew Viewport(0,0,32,24,tileMap,offScreenGraphics);
			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 //Set the instructions for the game keys
				 if(e->KeyData == Keys::Up)
					 indie->setSpriteDirection(North);
				 if(e->KeyData == Keys::Down)
					 indie->setSpriteDirection(South);
				 if(e->KeyData == Keys::Right)
					 indie->setSpriteDirection(West);
				 if(e->KeyData == Keys::Left)
					 indie->setSpriteDirection(East);

				 if(e->KeyData == Keys::Space)
					 indie->Jump();

				//Move the viewport on key downs
				 viewPort->viewportMove(viewPort->getViewportWorldX());
				
				 //Move the player on key down
				 Indies->movePlayerSprites();
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 //Draw all the graphics on the timer tick
				offScreenGraphics->DrawImage(backgroundImage,Rectangle(0,0,10240,768));
				viewPort->viewportDraw();
				//tileMap->drawMap();

				//Update sprite states
				Indies->updateSprites();
				Spiders->updateSprites();
				Beetles->updateSprites();

				//Move the enemies
				Spiders->moveNPC();
				Beetles->moveNPC();

				//Draw the double buffered graphics
				graphics->DrawImage(offScreenBitmap,Rectangle(0,0,1024,768));
				
			 }
};
}

