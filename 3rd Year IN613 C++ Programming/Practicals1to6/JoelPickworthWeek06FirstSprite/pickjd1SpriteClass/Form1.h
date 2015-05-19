#pragma once
#include "Sprite.h"


namespace pickjd1SpriteClass {

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
	private: System::Windows::Forms::Button^  btn1Sprite;
	protected: 
	private: System::Windows::Forms::Button^  btn10Sprites;

	private:
		Graphics^ mainCanvas;
		Sprite^ sprite;
		Bitmap^ blobbo;
		Random^ rGen;
		int nFrames;
		int frameWidth;
		int frameHeight;
		array<Sprite^>^ sprites;

	private: System::Windows::Forms::Timer^  tmrMain;

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
			this->btn1Sprite = (gcnew System::Windows::Forms::Button());
			this->btn10Sprites = (gcnew System::Windows::Forms::Button());
			this->tmrMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btn1Sprite
			// 
			this->btn1Sprite->Location = System::Drawing::Point(277, 21);
			this->btn1Sprite->Name = L"btn1Sprite";
			this->btn1Sprite->Size = System::Drawing::Size(75, 23);
			this->btn1Sprite->TabIndex = 0;
			this->btn1Sprite->Text = L"1 Sprite";
			this->btn1Sprite->UseVisualStyleBackColor = true;
			this->btn1Sprite->Click += gcnew System::EventHandler(this, &Form1::btn1Sprite_Click_1);
			// 
			// btn10Sprites
			// 
			this->btn10Sprites->Location = System::Drawing::Point(597, 21);
			this->btn10Sprites->Name = L"btn10Sprites";
			this->btn10Sprites->Size = System::Drawing::Size(75, 23);
			this->btn10Sprites->TabIndex = 1;
			this->btn10Sprites->Text = L"10 Sprites";
			this->btn10Sprites->UseVisualStyleBackColor = true;
			this->btn10Sprites->Click += gcnew System::EventHandler(this, &Form1::btn10Sprites_Click);
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
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->btn10Sprites);
			this->Controls->Add(this->btn1Sprite);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		//initialize the form components
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				blobbo = gcnew Bitmap("BlobboMulti.bmp");
				mainCanvas = CreateGraphics();
				rGen = gcnew Random();
				nFrames = 8;
				frameWidth = 32;
				frameHeight = 32;
				sprite = gcnew Sprite(mainCanvas, blobbo, rGen, nFrames, rGen->Next(800),rGen->Next(800),rGen->Next(2),rGen->Next(2));
				tmrMain->Interval = 100;

				sprites = gcnew array<Sprite^,1>(SPRITEARRAY);

				for(int i = 0; i < sprites->Length; i++)
				{
					sprites[i] = gcnew Sprite(mainCanvas, blobbo, rGen, nFrames, rGen->Next(800),rGen->Next(800),rGen->Next(2),rGen->Next(2));
				}

			 }

//button to spawn 1 sprite
private: System::Void btn1Sprite_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			
			tmrMain->Start();

		 }

//button to spawn 10 sprites
	private: System::Void btn10Sprites_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 timer1->Start();

			 }

	private: System::Void tmrMain_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				
				sprite->Erase(Color::White);
				sprite->UpdateFrame();
				sprite->Wander();
				sprite->Move();
				sprite->Draw();
			 }


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i; i < sprites->Length; i++)
			 {
				sprites[i]->Erase(Color::White);
				sprites[i]->UpdateFrame();
				sprites[i]->Wander();
				sprites[i]->Move();
				sprites[i]->Draw();
			 }
		 }
};
}

