#pragma once
#include "Pellet.h"
#include "PelletList.h"

#define DEFAULT 0
namespace RainbowChicken {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


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
	private: System::Windows::Forms::Label^  lblCount;
	protected: 
	private: System::Windows::Forms::Timer^  tmrGame;
	private: System::Windows::Forms::PictureBox^  pBxChicken;
	private: System::ComponentModel::IContainer^  components;

	private:
		Graphics^ mainCanvas;
		PelletList^ mainPelletList;
		Pellet^ testPellet;
		int count;
		Random^ rGen;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblCount = (gcnew System::Windows::Forms::Label());
			this->tmrGame = (gcnew System::Windows::Forms::Timer(this->components));
			this->pBxChicken = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxChicken))->BeginInit();
			this->SuspendLayout();
			// 
			// lblCount
			// 
			this->lblCount->AutoSize = true;
			this->lblCount->Font = (gcnew System::Drawing::Font(L"Algerian", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCount->ForeColor = System::Drawing::Color::Red;
			this->lblCount->Location = System::Drawing::Point(13, 13);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(34, 35);
			this->lblCount->TabIndex = 0;
			this->lblCount->Text = L"0";
			// 
			// tmrGame
			// 
			this->tmrGame->Tick += gcnew System::EventHandler(this, &Form1::tmrGame_Tick);
			// 
			// pBxChicken
			// 
			this->pBxChicken->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pBxChicken->Location = System::Drawing::Point(209, 397);
			this->pBxChicken->Name = L"pBxChicken";
			this->pBxChicken->Size = System::Drawing::Size(64, 64);
			this->pBxChicken->TabIndex = 1;
			this->pBxChicken->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(484, 462);
			this->Controls->Add(this->pBxChicken);
			this->Controls->Add(this->lblCount);
			this->Name = L"Form1";
			this->Text = L"Rainbow Chicken";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxChicken))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 mainCanvas = CreateGraphics();
				 rGen = gcnew Random();
				 mainPelletList = gcnew PelletList();
				 pBxChicken->Image = Image::FromFile("chicken.gif");
				 tmrGame->Interval = 30;
				 tmrGame->Start();
				 count = DEFAULT;
			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				 if (e->KeyData == Keys::Left)
					 pBxChicken->Left-=10;

				 if (e->KeyData == Keys::Right)
					 pBxChicken->Left+=10;
				 
				 if (e->KeyData == Keys::Space)
				 {
					 Pellet^ newPellet = gcnew Pellet( pBxChicken->Left + (pBxChicken->Width/2),
						 pBxChicken->Top - PELLET_DIAMETER, mainCanvas, rGen);

					 mainPelletList->addPellet(newPellet);
					 count ++;
					 lblCount->Text = System::Convert::ToString(count);
				 }

			 }
	private: System::Void tmrGame_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Brush^ brush = gcnew SolidBrush(Color::Black);
				 mainCanvas->FillRectangle(brush, 0, 0, 500, 500);

				 mainPelletList->renderPellets();
				 mainPelletList->updatePellets();


			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Pellet^ testPellet = gcnew Pellet(100,100,mainCanvas,rGen);
			 testPellet->draw();

		 }
};
}

