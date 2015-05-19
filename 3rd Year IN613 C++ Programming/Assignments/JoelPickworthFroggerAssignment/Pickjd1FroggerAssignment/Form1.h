#include "FroggerGame.h"
#include "TileMap.h"
#include "Viewport.h"
#include "Sprite.h"
#include "Car.h"
#include "CarList.h"

#pragma once

#define RIGHTBOUND 3
#define LEFTBOUND 2

#define STARTXPOS 375
#define STARTYPOS 520

namespace Pickjd1FroggerAssignment {

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
	private: System::Windows::Forms::Timer^  Timer;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:

		Graphics^ mainCanvas;
		Random^ rGen;

		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;

		Bitmap^ grass;
		Bitmap^ streetTop;
		Bitmap^ streetBot;

		String^ car1;
		String^ car2;
		String^ car3;
		String^ car4;
		String^ car5;

		TileList^ tileList;

		Sprite^ troll;
		Sprite^ cars1;
		Sprite^ cars2;
		Sprite^ cars3;
		Sprite^ cars4;
		Sprite^ cars5;
		Sprite^ cars6;
		Sprite^ cars7;
		Sprite^ cars8;
		Sprite^ cars9;
		Sprite^ cars0;

		Viewport^ viewPort;

		CarList^ carList;

	private: System::Windows::Forms::Panel^  myPanel;
	private: System::Windows::Forms::Timer^  tmrRightBoundCars;
	private: System::Windows::Forms::Timer^  tmrLeftBoundCars;
			 TileMap^ tileMap;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->myPanel = (gcnew System::Windows::Forms::Panel());
			this->tmrRightBoundCars = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrLeftBoundCars = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Timer
			// 
			this->Timer->Tick += gcnew System::EventHandler(this, &Form1::Timer_Tick);
			// 
			// myPanel
			// 
			this->myPanel->Location = System::Drawing::Point(4, 4);
			this->myPanel->Name = L"myPanel";
			this->myPanel->Size = System::Drawing::Size(999, 723);
			this->myPanel->TabIndex = 0;
			// 
			// tmrRightBoundCars
			// 
			this->tmrRightBoundCars->Interval = 1000;
			this->tmrRightBoundCars->Tick += gcnew System::EventHandler(this, &Form1::tmrRightBoundCars_Tick);
			// 
			// tmrLeftBoundCars
			// 
			this->tmrLeftBoundCars->Interval = 1000;
			this->tmrLeftBoundCars->Tick += gcnew System::EventHandler(this, &Form1::tmrLeftBoundCars_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->myPanel);
			this->Name = L"Form1";
			this->Text = L"Troll Frogger - Use Keys to Cross the Road!";
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

				grass = gcnew Bitmap("grass.png");
				Tile^ grassTile = gcnew Tile(grass);

				streetTop = gcnew Bitmap("streetTop.png");
				Tile^ streetTopTile = gcnew Tile(streetTop);

				streetBot = gcnew Bitmap("streetBot.png");
				Tile^ streetBotTile = gcnew Tile(streetBot);

				//initialize tile list
				tileList = gcnew TileList();
				tileList->setTileArrayEntry(0,grassTile);
				tileList->setTileArrayEntry(1,streetTopTile);
				tileList->setTileArrayEntry(2,streetBotTile);

				tileMap = gcnew TileMap(tileList,offScreenCanvas);

				 array<String^>^ trollFileNames =
					 gcnew array <String^>{
					 "troll.png",
				 };
				
				car1 = "car1.png";
				car2 = "car2.png";
				car3 = "car3.png";
				car4 = "car5.png";
				car5 = "car6.png";

				cars1 = gcnew Sprite(offScreenCanvas, car1, 1, 850, rGen->Next(100,500), tileMap);
				cars2 = gcnew Sprite(offScreenCanvas, car2, 1, 850, rGen->Next(100,500), tileMap);
				cars3 = gcnew Sprite(offScreenCanvas, car3, 1, -100, rGen->Next(100,500), tileMap);
				cars4 = gcnew Sprite(offScreenCanvas, car4, 1, -100, rGen->Next(100,500), tileMap);
				cars5 = gcnew Sprite(offScreenCanvas, car5, 1, -100, rGen->Next(100,500), tileMap);
				cars6 = gcnew Sprite(offScreenCanvas, car1, 1, 850, rGen->Next(100,500), tileMap);
				cars7 = gcnew Sprite(offScreenCanvas, car2, 1, 850, rGen->Next(100,500), tileMap);
				cars8 = gcnew Sprite(offScreenCanvas, car3, 1, -100, rGen->Next(100,500), tileMap);
				cars9 = gcnew Sprite(offScreenCanvas, car4, 1, -100, rGen->Next(100,500), tileMap);
				cars0 = gcnew Sprite(offScreenCanvas, car5, 1, -100, rGen->Next(100,500), tileMap);

				troll = gcnew Sprite(offScreenCanvas, trollFileNames, 8, STARTXPOS, STARTYPOS, tileMap);

				String^ Level = "frogger.csv";
				tileMap->loadFromFile(Level);

				carList = gcnew CarList();


				//Initialize the viewport
				//viewPort = gcnew Viewport(0,0,32,17,tileMap,offScreenCanvas);
				tmrLeftBoundCars->Start();
				tmrRightBoundCars->Start();

				Timer->Start();
				//tmrLeftBoundCars->Start();

			 }

	private: System::Void Timer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {

				tileMap->drawMap();
				//viewPort->viewportDraw();

				 /*cars1->setSpriteDirection(2);
				 cars1->DrawCar();
				 cars1->MoveRand(rGen->Next(rGen->Next(30)));
 				 cars2->setSpriteDirection(2);
				 cars2->DrawCar();
				 cars2->MoveRand(rGen->Next(rGen->Next(30)));
				 cars3->setSpriteDirection(3);
				 cars3->DrawCar();
				 cars3->MoveRand(rGen->Next(rGen->Next(30)));
 				 cars4->setSpriteDirection(3);
				 cars4->DrawCar();
				 cars4->MoveRand(rGen->Next(rGen->Next(30)));
				 cars5->setSpriteDirection(3);
				 cars5->DrawCar();
				 cars5->MoveRand(rGen->Next(rGen->Next(30)));

				 cars6->setSpriteDirection(2);
				 cars6->DrawCar();
				 cars6->MoveRand(rGen->Next(rGen->Next(30)));
 				 cars7->setSpriteDirection(2);
				 cars7->DrawCar();
				 cars7->MoveRand(rGen->Next(rGen->Next(30)));
				 cars8->setSpriteDirection(3);
				 cars8->DrawCar();
				 cars8->MoveRand(rGen->Next(rGen->Next(30)));
 				 cars9->setSpriteDirection(3);
				 cars9->DrawCar();
				 cars9->MoveRand(rGen->Next(rGen->Next(30)));
				 cars0->setSpriteDirection(3);
				 cars0->DrawCar();
				 cars0->MoveRand(rGen->Next(rGen->Next(30)));*/

				carList->renderCars();
				carList->updateCars();

				troll->Draw();
				mainCanvas->DrawImage(offScreenBitmap, Rectangle(0,0,myPanel->Width,myPanel->Height));
			 }

	private: System::Void tmrLeftBoundCars_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				Car^ car = gcnew Car(offScreenCanvas, car3, 1, -100, rGen->Next(70,480), tileMap);
				car->setSpriteDirection(3);
				carList->addCar(car);
			 }


	private: System::Void tmrRightBoundCars_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				Car^ car = gcnew Car(offScreenCanvas, car2, 1, 850, rGen->Next(70,500), tileMap);
				car->setSpriteDirection(2);
				carList->addCar(car);
			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				troll->UpdateFrame();
				if(e->KeyData == Keys::Up)
					 troll->setSpriteDirection(NORTH);
				 if(e->KeyData == Keys::Down)
					 troll->setSpriteDirection(SOUTH);
				 if(e->KeyData == Keys::Right)
					 troll->setSpriteDirection(WEST);
				 if(e->KeyData == Keys::Left)
					 troll->setSpriteDirection(EAST);

				 troll->Move();
				 if (troll->checkForWin() == true)
				 {
					 Timer->Stop();
					 MessageBox::Show("You Win!");
				 }
			 }
};
}

