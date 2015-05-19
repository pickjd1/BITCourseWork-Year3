#pragma once
#include "Sprite.h"

#define CHICKENARRAY 10

namespace pickjd1SpriteDirectionalLab {

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
	private: System::Windows::Forms::Timer^  tmrMain;
	private: System::Windows::Forms::Timer^  timer1;

	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		Graphics^ mainCanvas;
		Image^ backgroundImage;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;

		Sprite^ knight;
		array<Bitmap^>^ spriteSheets;
		array<Sprite^>^ chickens;
		Random^ rGen;
		int nFrames;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tmrMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// tmrMain
			// 
			this->tmrMain->Tick += gcnew System::EventHandler(this, &Form1::tmrMain_Tick);
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
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {

				mainCanvas = CreateGraphics();
				rGen = gcnew Random();

				backgroundImage = Image::FromFile("Hogwarts.jpg");

				offScreenBitmap = gcnew Bitmap(800,600);
				offScreenCanvas = Graphics::FromImage(offScreenBitmap);


				nFrames = 8;

				array<String^>^ knightFileNames = gcnew array<String^> 
				{	
					"Knight Walk North 8.bmp",
					"Knight Walk South 8.bmp",
					"Knight Walk East 8.bmp",
					"Knight Walk West 8.bmp"
				};

				knight = gcnew Sprite(offScreenCanvas, knightFileNames, nFrames, 100,100,1);

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
					chickens[i] = gcnew Sprite(offScreenCanvas, chickenFileNames, nFrames, rGen->Next(0,600), rGen->Next(0,600),rGen->Next(0,3));
				}

				tmrMain->Interval = 100;
				tmrMain->Start();
				timer1->Interval = 100;
				timer1->Start();

				

			 }

	private: System::Void tmrMain_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				offScreenCanvas->DrawImage(	backgroundImage,Rectangle(0,0,800,600));

				//knight->Erase(Color::Blue);
				knight->Draw();
				knight->UpdateFrame();	
				knight->Move();

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

	private: System::Void Form1_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
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

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
			 }
};
}

