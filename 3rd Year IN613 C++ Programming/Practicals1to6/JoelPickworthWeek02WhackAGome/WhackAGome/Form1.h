#pragma once
#include "GnomeManager.h"

namespace WhackAGome {

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
	private: System::Windows::Forms::Timer^  gnomeTimer;
	protected: 
	private: System::ComponentModel::IContainer^  components;

		private: 
			//Field Declarations
			Random^ rGen;
			Graphics^ mainCanvas;
			GnomeManager^ gnomeManager;
			int gnomeIndex;
			int gnomesLeft;
			int selGnome;

private: System::Windows::Forms::Button^  btnStart;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gnomeTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// gnomeTimer
			// 
			this->gnomeTimer->Interval = 2000;
			this->gnomeTimer->Tick += gcnew System::EventHandler(this, &Form1::gnomeTimer_Tick);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(299, 12);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start Game";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 512);
			this->Controls->Add(this->btnStart);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				//Initialize fields and objects
				mainCanvas = CreateGraphics();
				mainCanvas->Clear(Color::White);
				gnomesLeft = 10;
				rGen = gcnew Random();
				gnomeManager = gcnew GnomeManager(rGen, mainCanvas, gnomesLeft);
				
				//Set timer and draw gnomes
				gnomeTimer->Interval = 2000;
				gnomeManager->drawAllGnomes();
			 }

	private: System::Void Form1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
			 {
				 //When the mouse is clicked check if it is on a gnome and set gnome to hamster if it is
				 for(int i = 0; i < gnomesLeft; i++)
				 {
					 if(gnomeManager->getGnomes()[i]->getVisible())
					 {
						 if(gnomeManager->hitGnome(i, e->Location) == true)
						 {
							 gnomeManager->getGnomes()[i]->setIsAHamster(true);
							 gnomeManager->getGnomes()[i]->Draw(gnomeManager->getGnomes()[i]->getIsAHamster());
							 gnomesLeft = gnomesLeft - 1;
						 }
					 }
				 }

				 //If all gnomes have been clicked show win message
				 if(gnomesLeft == 0)
				 {
						 MessageBox::Show("You Win!");
						 gnomeTimer->Stop();
				 }


			 }

	private: System::Void gnomeTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				//On timer tick select a random gnome and set to being visible
				selGnome = rGen->Next(gnomesLeft);

					 for(int i = 0; i < gnomesLeft; i++)
					 {
						if (gnomeManager->getGnomes()[i] == gnomeManager->getGnomes()[selGnome])
						{
							if (gnomeManager->getGnomes()[selGnome]->getIsAHamster() == false)
							{
								gnomeManager->getGnomes()[selGnome]->setVisible(true);
								gnomeManager->getGnomes()[selGnome]->Draw(false);
							}
						}
					 }
			 }

	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //When start button is clicked, clear the canvas, reset the gnome count and start timer
				 mainCanvas->Clear(Color::White);
				 gnomesLeft = 10;
				 gnomeTimer->Start();
				 
			 }
	};
}


