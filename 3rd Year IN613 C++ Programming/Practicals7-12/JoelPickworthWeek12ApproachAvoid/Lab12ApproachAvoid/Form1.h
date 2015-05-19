#pragma once
#include "Sprite.h"
#define SHIPS 20

namespace Lab12ApproachAvoid {

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
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private:
		Graphics^ mainCanvas;
		Image^ backgroundImage;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;

		Bitmap^ blobboImage;
		Bitmap^ apShipImage;
		Bitmap^ avShipImage;

		Sprite^ blobbo;
		array<Sprite^>^ ships;

		Random^ rGen;
	private: System::Windows::Forms::Timer^  tmrMain;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rBtnLinear;
	private: System::Windows::Forms::RadioButton^  rBtnTrig;
	private: System::Windows::Forms::Timer^  tmrTrig;
	private: System::Windows::Forms::Timer^  tmrLin;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rBtnLinear = (gcnew System::Windows::Forms::RadioButton());
			this->rBtnTrig = (gcnew System::Windows::Forms::RadioButton());
			this->tmrTrig = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrLin = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tmrMain
			// 
			this->tmrMain->Tick += gcnew System::EventHandler(this, &Form1::tmrMain_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->rBtnLinear);
			this->groupBox1->Controls->Add(this->rBtnTrig);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(93, 76);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// rBtnLinear
			// 
			this->rBtnLinear->AutoSize = true;
			this->rBtnLinear->Location = System::Drawing::Point(7, 44);
			this->rBtnLinear->Name = L"rBtnLinear";
			this->rBtnLinear->Size = System::Drawing::Size(54, 17);
			this->rBtnLinear->TabIndex = 1;
			this->rBtnLinear->TabStop = true;
			this->rBtnLinear->Text = L"Linear";
			this->rBtnLinear->UseVisualStyleBackColor = true;
			this->rBtnLinear->CheckedChanged += gcnew System::EventHandler(this, &Form1::rBtnLinear_CheckedChanged);
			// 
			// rBtnTrig
			// 
			this->rBtnTrig->AutoSize = true;
			this->rBtnTrig->Location = System::Drawing::Point(6, 19);
			this->rBtnTrig->Name = L"rBtnTrig";
			this->rBtnTrig->Size = System::Drawing::Size(83, 17);
			this->rBtnTrig->TabIndex = 0;
			this->rBtnTrig->TabStop = true;
			this->rBtnTrig->Text = L"Trignometric";
			this->rBtnTrig->UseVisualStyleBackColor = true;
			this->rBtnTrig->CheckedChanged += gcnew System::EventHandler(this, &Form1::rBtnTrig_CheckedChanged);
			// 
			// tmrTrig
			// 
			this->tmrTrig->Tick += gcnew System::EventHandler(this, &Form1::tmrTrig_Tick);
			// 
			// tmrLin
			// 
			this->tmrLin->Tick += gcnew System::EventHandler(this, &Form1::tmrLin_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				mainCanvas = CreateGraphics();
				rGen = gcnew Random();

				blobboImage = gcnew Bitmap("Blobbo.bmp");
				apShipImage = gcnew Bitmap("yellowShip.bmp");
				avShipImage = gcnew Bitmap("redShip.bmp");

				backgroundImage = Image::FromFile("outerSpace.jpg");

				offScreenBitmap = gcnew Bitmap(800,600);
				offScreenCanvas = Graphics::FromImage(offScreenBitmap);

				nFrames = 8;

				blobbo = gcnew Sprite(offScreenCanvas, blobboImage, rGen, nFrames, rGen->Next(800),rGen->Next(600),rGen->Next(2,5),rGen->Next(2,5));
				tmrMain->Interval = 100;
				tmrMain->Start();

				ships = gcnew array<Sprite^,1>(SHIPS);

				for(int i = 0; i < (SHIPS/2); i++)
				{
						ships[i] = gcnew Sprite(offScreenCanvas, apShipImage, rGen, 40, rGen->Next(200,500),rGen->Next(200,500),rGen->Next(3),rGen->Next(3),1);
				}
				for(int i = SHIPS/2; i < (SHIPS); i++)
				{
						ships[i] = gcnew Sprite(offScreenCanvas, avShipImage, rGen, 40, rGen->Next(200,500),rGen->Next(200,500),rGen->Next(3),rGen->Next(3),-1);
				}


			 }
	private: System::Void tmrMain_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				offScreenCanvas->DrawImage(	backgroundImage,Rectangle(0,0,800,600));
				blobbo->UpdateFrame();
				blobbo->Wander();
				blobbo->Move();
				blobbo->Draw();

				for (int i = 0; i < ships->Length; i++)
				{
					ships[i]->Draw();
				}

				mainCanvas->DrawImage(offScreenBitmap,Rectangle(0,0,800,600));
			 }

	private: System::Void rBtnLinear_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				tmrLin->Start();
				tmrTrig->Stop();
			 }

	private: System::Void rBtnTrig_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				tmrTrig->Start();
				tmrLin->Stop();

			 }

	private: System::Void tmrTrig_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				for (int i = 0; i < ships->Length; i++)
				 {
					ships[i]->ApproachAvoidTrig(blobbo);
				 }
			 }


	private: System::Void tmrLin_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				for (int i = 0; i < ships->Length; i++)
				 {
					ships[i]->ApproachAvoidLin(blobbo);
				 }
			 }
};
}

