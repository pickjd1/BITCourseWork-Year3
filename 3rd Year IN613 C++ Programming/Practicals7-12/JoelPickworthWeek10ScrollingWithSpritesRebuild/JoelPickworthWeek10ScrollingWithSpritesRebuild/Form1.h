#pragma once
#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"
#include "Sprite.h"
#include "Viewport.h"

#define NFRAMES 8
#define CHICKENARRAY 200

namespace JoelPickworthWeek10ScrollingWithSpritesRebuild {


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

	private:
		Graphics^ mainCanvas;
		Random^ rGen;

		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;

		Bitmap^ water;
		Bitmap^ grass;
		Bitmap^ stone;

		TileList^ tileList;
		TileMap^ tileMap;

		Sprite^ knight;
		array<Bitmap^>^ spriteSheets;
		array<Sprite^>^ chickens;
		int nFrames;

		Viewport^ viewport;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  Timer;
	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-5, -3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(634, 449);
			this->panel1->TabIndex = 0;
			// 
			// Timer
			// 
			this->Timer->Tick += gcnew System::EventHandler(this, &Form1::Timer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->panel1);
			this->Location = System::Drawing::Point(153, 13);
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
				mainCanvas = panel1->CreateGraphics();
				rGen = gcnew Random();

				offScreenBitmap = gcnew Bitmap(640,480);
				offScreenCanvas = Graphics::FromImage(offScreenBitmap);

				
				//initialize the bitmaps
				grass = gcnew Bitmap("grass.bmp");
				Tile^ grassTile = gcnew Tile(grass);

				water = gcnew Bitmap("flower.bmp");
				Tile^ waterTile = gcnew Tile(water);

				stone = gcnew Bitmap("stone.bmp");
				Tile^ stoneTile = gcnew Tile(stone);

				//initialize tile list
				tileList = gcnew TileList();
				tileList->setTileArrayEntry(0,grassTile);
				tileList->setTileArrayEntry(1,waterTile);
				tileList->setTileArrayEntry(2,stoneTile);

				//initialize tile map
				tileMap = gcnew TileMap(tileList,offScreenCanvas);

				for (int i = 0; i < COLS; i++)
				{
					for (int j = 0; j < ROWS; j++)
					{
						tileMap->setMapValue(i, j, rGen->Next(3));
					}
				}


				nFrames = 8;

				array<String^>^ knightFileNames = gcnew array<String^> 
				{	
					"Knight Walk North 8.bmp",
					"Knight Walk South 8.bmp",
					"Knight Walk East 8.bmp",
					"Knight Walk West 8.bmp"
				};

				knight = gcnew Sprite(offScreenCanvas, knightFileNames, nFrames, 100,100,1,tileMap);

				array<String^>^ chickenFileNames = gcnew array<String^> 
				{	
					"Little Chicken Walk North 8.bmp",
					"Little Chicken Walk South 8.bmp",
					"Little Chicken Walk East 8.bmp",
					"Little Chicken Walk West 8.bmp"
				};

				chickens = gcnew array<Sprite^,1>(CHICKENARRAY);

				for(int i = 0; i < CHICKENARRAY; i++)
				{
					chickens[i] = gcnew Sprite(offScreenCanvas, chickenFileNames, nFrames, rGen->Next(0,2000), rGen->Next(0,2000),rGen->Next(0,3),tileMap);
				}


				viewport = gcnew Viewport(0,0,20,15,tileMap,offScreenCanvas);

				Timer->Start();
			 }

	private: System::Void Timer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				//tileMap->drawMap();
				//knight->Erase(Color::Blue);

				knight->UpdateFrame();	
				knight->Move();

				int knightX = knight->getXPos()+(knight->getWidth()/2);
				int knightY = knight->getYPos()+(knight->getHeight()/2);

				viewport->moveRelativeToPlayer(knightX,knightY);
				viewport->viewportDraw(knightX,knightY);
				knight->Draw();

				for (int i = 0; i < chickens->Length; i++)
				 {
					//chickens[i]->Erase(Color::Blue);
					chickens[i]->Draw();
					chickens[i]->UpdateFrame();
					chickens[i]->Wander();
					chickens[i]->Move();
				 }
				
				mainCanvas->DrawImage(offScreenBitmap,Rectangle(0,0,800,600));
			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				if(e->KeyData == Keys::Up)
					 knight->setSpriteDirection(NORTH);
				 if(e->KeyData == Keys::Down)
					 knight->setSpriteDirection(SOUTH);
				 if(e->KeyData == Keys::Right)
					 knight->setSpriteDirection(EAST);
				 if(e->KeyData == Keys::Left)
					 knight->setSpriteDirection(WEST);
			 }
};
}

