#pragma once
#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"
#include "ViewPort.h"
#include "Sprite.h"

namespace pickjd1TileMapLab {

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

	protected: 

	private:
		Graphics^ mainCanvas;
		Random^ rGen;

		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;

		Bitmap^ flower1;
		Bitmap^ flower2;
		Bitmap^ flower3;
		Bitmap^ book;
		Bitmap^ candy;
		Bitmap^ critter1;
		Bitmap^ critter2;
		Bitmap^ critter3;
		Bitmap^ critter4;
		Bitmap^ potion;
		Bitmap^ pumpkin;
		Bitmap^ star;
		Bitmap^ grass;

		Sprite^ chicken;
		array<Bitmap^>^ spriteSheets;
		
		ViewPort^ viewport;

		int nFrames;
		int chickenX;
		int chickenY;

		TileList^ tileList;
		TileMap^ tileMap;

	private: System::Windows::Forms::Panel^  myPanel;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->myPanel = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// myPanel
			// 
			this->myPanel->Location = System::Drawing::Point(12, 0);
			this->myPanel->Name = L"myPanel";
			this->myPanel->Size = System::Drawing::Size(776, 640);
			this->myPanel->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->myPanel);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				//initialize the graphics and random generator
				mainCanvas = myPanel->CreateGraphics();
				rGen = gcnew Random();


				offScreenBitmap = gcnew Bitmap(800,600);
				offScreenCanvas = Graphics::FromImage(offScreenBitmap);

				nFrames = NFRAMES;

				//initialize the bitmaps
				flower1 = gcnew Bitmap("Flower1 Tile.bmp");
				Tile^ flower1Tile = gcnew Tile(flower1);

				flower2 = gcnew Bitmap("Flower2 Tile.bmp");
				Tile^ flower2Tile = gcnew Tile(flower2);

				flower3 = gcnew Bitmap("Flower3 Tile.bmp");
				Tile^ flower3Tile = gcnew Tile(flower3);

				book = gcnew Bitmap("Book Tile.bmp");
				Tile^ bookTile = gcnew Tile(book);

				candy = gcnew Bitmap("Candy Tile.bmp");
				Tile^ candyTile = gcnew Tile(candy);

				critter1 = gcnew Bitmap("Critter1 Tile.bmp");
				Tile^ critter1Tile = gcnew Tile(critter1);

				critter2 = gcnew Bitmap("Critter2 Tile.bmp");
				Tile^ critter2Tile = gcnew Tile(critter2);

				critter3 = gcnew Bitmap("Critter4 Tile.bmp");
				Tile^ critter3Tile = gcnew Tile(critter3);

				critter4 = gcnew Bitmap("Critter5 Tile.bmp");
				Tile^ critter4Tile = gcnew Tile(critter4);

				potion = gcnew Bitmap("Potion Tile.bmp");
				Tile^ potionTile = gcnew Tile(potion);

				pumpkin = gcnew Bitmap("Pumpkin Tile.bmp");
				Tile^ pumpkinTile = gcnew Tile(pumpkin);

				star = gcnew Bitmap("Star Tile.bmp");
				Tile^ starTile = gcnew Tile(star);

				grass = gcnew Bitmap("Grass Tile.jpg");
				Tile^ grassTile = gcnew Tile(grass);


				//initialize tile list
				tileList = gcnew TileList();
				tileList->setTileArrayEntry(0,flower1Tile);
				tileList->setTileArrayEntry(1,flower2Tile);
				tileList->setTileArrayEntry(2,flower3Tile);
				tileList->setTileArrayEntry(3,bookTile);
				tileList->setTileArrayEntry(4,candyTile);
				tileList->setTileArrayEntry(5,critter1Tile);
				tileList->setTileArrayEntry(6,critter2Tile);
				tileList->setTileArrayEntry(7,critter3Tile);
				tileList->setTileArrayEntry(8,critter4Tile);
				tileList->setTileArrayEntry(9,potionTile);
				tileList->setTileArrayEntry(10,pumpkinTile);
				tileList->setTileArrayEntry(11,starTile);
				tileList->setTileArrayEntry(12,grassTile);


				array<String^>^ chickenFileNames = gcnew array<String^> 
				{	
					"Chicken North.bmp",
					"Chicken South.bmp",
					"Chicken East.bmp",
					"Chicken West.bmp"
				};
				
				
				tileMap = gcnew TileMap(tileList,offScreenCanvas);
				chicken = gcnew Sprite(offScreenCanvas, chickenFileNames, nFrames, 200,200,0,tileMap);

				String^ FirstLevel = "newChickenMap.csv";
				tileMap->loadFromFile(FirstLevel);

				viewport = gcnew ViewPort(0,0,18,14,tileMap,offScreenCanvas);

				timer1->Enabled = true;
				timer1->Start();

			 }


	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				for (int i = 0; i < COLS; i++)
				{
					for (int j = 0; j < ROWS; j++)
					{
						tileMap->setMapValue(i, j, rGen->Next(3));
					}
				}
				tileMap->drawMap();
			 }


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {

				 chickenX = chicken->getXPos() + (chicken->getWidth()/2);
				 chickenY = chicken->getYPos() + (chicken->getHeight()/2);

				chicken->UpdateFrame();

				viewport->moveRelativeToPlayer(chickenX,chickenY);
				
				viewport->viewportDraw(chickenX,chickenY);

				chicken->Draw();	

				mainCanvas->DrawImage(offScreenBitmap, Rectangle(0,0,myPanel->Width,myPanel->Height));
			 }
private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {

				if(e->KeyData == Keys::Up)
					 chicken->setSpriteDirection(NORTH);
				 if(e->KeyData == Keys::Down)
					 chicken->setSpriteDirection(SOUTH);
				 if(e->KeyData == Keys::Right)
					 chicken->setSpriteDirection(EAST);
				 if(e->KeyData == Keys::Left)
					 chicken->setSpriteDirection(WEST);

				 chicken->Move();
				 

		 }
};
}

