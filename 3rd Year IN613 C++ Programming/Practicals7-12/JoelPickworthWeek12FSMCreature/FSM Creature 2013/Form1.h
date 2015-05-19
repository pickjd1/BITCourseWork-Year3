#pragma once

#include "Creature.h"
#include "Obstacle.h"
#include "Food.h"

namespace FSMCreature2013 {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private: System::Windows::Forms::Timer^  timer1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(893, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"Form1";
			this->Text = L"FSM Creature";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		array<Creature^>^ creatureArray;
		array<Obstacle^>^ obstacleArray;
		array<Food^>^ foodArray;
		Graphics^ mainCanvas;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		Random^ mainRandom;
		int creatureCount;
		int obstacleCount;
		int foodCount;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Left = 0;
				 Top = 0;
				 Width = 1024;
				 Height = 768;

				 creatureCount = 25;
				 obstacleCount = 10;
				 foodCount = 40;

				creatureArray = gcnew array<Creature^>(creatureCount);
				obstacleArray = gcnew array<Obstacle^>(obstacleCount);
				foodArray = gcnew array<Food^>(foodCount);
				mainCanvas = CreateGraphics();
				offScreenBitmap = gcnew Bitmap(Width,Height);
				offScreenCanvas = Graphics::FromImage(offScreenBitmap);
				mainRandom = gcnew Random();

				for (int i=0; i<creatureCount; i++)
				{
					String^ bugFile = "";
					if(mainRandom->Next(2) == 0)
						bugFile = "littleBug1.png";
					else
						bugFile = "littleBug2.png";
					creatureArray[i] = gcnew Creature(offScreenCanvas, mainRandom, Width, Height, bugFile);
					creatureArray[i]->location.X = mainRandom->Next(Width);
					creatureArray[i]->location.Y = mainRandom->Next(Height);
				}

				for (int i=0; i<obstacleCount; i++)
				{
					obstacleArray[i] = gcnew Obstacle(offScreenCanvas, mainRandom, Width, Height, "gemstone.jpg");
					obstacleArray[i]->location.X = mainRandom->Next(Width);
					obstacleArray[i]->location.Y = mainRandom->Next(Height);
				}

				for (int i=0; i<foodCount; i++)
				{
					foodArray[i] = gcnew Food(offScreenCanvas, mainRandom, Width, Height, "cookie.jpg");
					foodArray[i]->location.X = mainRandom->Next(Width);
					foodArray[i]->location.Y = mainRandom->Next(Height);
				}
			 }

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 offScreenCanvas->Clear(Color::Black);
				
				for (int i=0; i<obstacleCount; i++)
				{
					obstacleArray[i]->Draw();
				}

				for (int i=0; i<foodCount; i++)
				{
					foodArray[i]->Draw();
				}

				for (int i=0; i<creatureCount; i++)
				{
					creatureArray[i]->UpdateState(foodArray, obstacleArray);
					creatureArray[i]->PerformAction();
					creatureArray[i]->Draw();
				}

				mainCanvas->DrawImage(offScreenBitmap, 0, 0);
			 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Enabled = !timer1->Enabled;
		 }
};
}

