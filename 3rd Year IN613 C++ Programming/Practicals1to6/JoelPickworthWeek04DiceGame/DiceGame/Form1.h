#pragma once
#include "Dice.h"
#include "Player.h"

#define DICENUMBER 5
namespace DiceGame {

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
	private: System::Windows::Forms::Button^  btnPlayer1;
	private: System::Windows::Forms::Button^  btnPlayer2;
	private: System::Windows::Forms::PictureBox^  pBxP1D1;
	private: System::Windows::Forms::PictureBox^  pBxP1D3;
	private: System::Windows::Forms::PictureBox^  pBxP1D2;
	private: System::Windows::Forms::PictureBox^  pBxP1D4;
	private: System::Windows::Forms::PictureBox^  pBxP1D5;
	private: System::Windows::Forms::PictureBox^  pBxP2D5;

	private: System::Windows::Forms::PictureBox^  pBxP2D4;

	private: System::Windows::Forms::PictureBox^  pBxP2D2;
	private: System::Windows::Forms::PictureBox^  pBxP2D3;
	private: System::Windows::Forms::PictureBox^  pBxP2D1;
	private: System::Windows::Forms::Label^  lblPlayer1;
	private: System::Windows::Forms::Label^  lblPlayer2;
	protected: 

	protected: 

	private:
		Player^ player1;
		Player^ player2;
		Random^ rGen;
		array<PictureBox^>^ p1PBox;
		array<PictureBox^>^ p2PBox;
		array<Dice^>^ p1Dice;
		array<Dice^>^ p2Dice;


	private: System::Windows::Forms::Label^  lblP1Total;
	private: System::Windows::Forms::Label^  lblP2Total;
	private: System::Windows::Forms::Label^  lblP1Dice;
	private: System::Windows::Forms::Label^  lblP2Dice;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnPlayer1 = (gcnew System::Windows::Forms::Button());
			this->btnPlayer2 = (gcnew System::Windows::Forms::Button());
			this->pBxP1D1 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP1D3 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP1D2 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP1D4 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP1D5 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP2D5 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP2D4 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP2D2 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP2D3 = (gcnew System::Windows::Forms::PictureBox());
			this->pBxP2D1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblPlayer1 = (gcnew System::Windows::Forms::Label());
			this->lblPlayer2 = (gcnew System::Windows::Forms::Label());
			this->lblP1Total = (gcnew System::Windows::Forms::Label());
			this->lblP2Total = (gcnew System::Windows::Forms::Label());
			this->lblP1Dice = (gcnew System::Windows::Forms::Label());
			this->lblP2Dice = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnPlayer1
			// 
			this->btnPlayer1->Location = System::Drawing::Point(28, 56);
			this->btnPlayer1->Name = L"btnPlayer1";
			this->btnPlayer1->Size = System::Drawing::Size(90, 50);
			this->btnPlayer1->TabIndex = 0;
			this->btnPlayer1->Text = L"Player One Dice Roll";
			this->btnPlayer1->UseVisualStyleBackColor = true;
			this->btnPlayer1->Click += gcnew System::EventHandler(this, &Form1::btnPlayer1_Click);
			// 
			// btnPlayer2
			// 
			this->btnPlayer2->Location = System::Drawing::Point(28, 254);
			this->btnPlayer2->Name = L"btnPlayer2";
			this->btnPlayer2->Size = System::Drawing::Size(90, 50);
			this->btnPlayer2->TabIndex = 1;
			this->btnPlayer2->Text = L"Player Two Dice Roll";
			this->btnPlayer2->UseVisualStyleBackColor = true;
			this->btnPlayer2->Click += gcnew System::EventHandler(this, &Form1::btnPlayer2_Click);
			// 
			// pBxP1D1
			// 
			this->pBxP1D1->Location = System::Drawing::Point(165, 56);
			this->pBxP1D1->Name = L"pBxP1D1";
			this->pBxP1D1->Size = System::Drawing::Size(149, 149);
			this->pBxP1D1->TabIndex = 2;
			this->pBxP1D1->TabStop = false;
			// 
			// pBxP1D3
			// 
			this->pBxP1D3->Location = System::Drawing::Point(475, 56);
			this->pBxP1D3->Name = L"pBxP1D3";
			this->pBxP1D3->Size = System::Drawing::Size(149, 149);
			this->pBxP1D3->TabIndex = 3;
			this->pBxP1D3->TabStop = false;
			// 
			// pBxP1D2
			// 
			this->pBxP1D2->Location = System::Drawing::Point(320, 56);
			this->pBxP1D2->Name = L"pBxP1D2";
			this->pBxP1D2->Size = System::Drawing::Size(149, 149);
			this->pBxP1D2->TabIndex = 4;
			this->pBxP1D2->TabStop = false;
			// 
			// pBxP1D4
			// 
			this->pBxP1D4->Location = System::Drawing::Point(630, 56);
			this->pBxP1D4->Name = L"pBxP1D4";
			this->pBxP1D4->Size = System::Drawing::Size(149, 149);
			this->pBxP1D4->TabIndex = 5;
			this->pBxP1D4->TabStop = false;
			// 
			// pBxP1D5
			// 
			this->pBxP1D5->Location = System::Drawing::Point(785, 56);
			this->pBxP1D5->Name = L"pBxP1D5";
			this->pBxP1D5->Size = System::Drawing::Size(149, 149);
			this->pBxP1D5->TabIndex = 6;
			this->pBxP1D5->TabStop = false;
			// 
			// pBxP2D5
			// 
			this->pBxP2D5->Location = System::Drawing::Point(785, 254);
			this->pBxP2D5->Name = L"pBxP2D5";
			this->pBxP2D5->Size = System::Drawing::Size(149, 149);
			this->pBxP2D5->TabIndex = 11;
			this->pBxP2D5->TabStop = false;
			// 
			// pBxP2D4
			// 
			this->pBxP2D4->Location = System::Drawing::Point(630, 254);
			this->pBxP2D4->Name = L"pBxP2D4";
			this->pBxP2D4->Size = System::Drawing::Size(149, 149);
			this->pBxP2D4->TabIndex = 10;
			this->pBxP2D4->TabStop = false;
			// 
			// pBxP2D2
			// 
			this->pBxP2D2->Location = System::Drawing::Point(320, 254);
			this->pBxP2D2->Name = L"pBxP2D2";
			this->pBxP2D2->Size = System::Drawing::Size(149, 149);
			this->pBxP2D2->TabIndex = 9;
			this->pBxP2D2->TabStop = false;
			// 
			// pBxP2D3
			// 
			this->pBxP2D3->Location = System::Drawing::Point(475, 254);
			this->pBxP2D3->Name = L"pBxP2D3";
			this->pBxP2D3->Size = System::Drawing::Size(149, 149);
			this->pBxP2D3->TabIndex = 8;
			this->pBxP2D3->TabStop = false;
			// 
			// pBxP2D1
			// 
			this->pBxP2D1->Location = System::Drawing::Point(165, 254);
			this->pBxP2D1->Name = L"pBxP2D1";
			this->pBxP2D1->Size = System::Drawing::Size(149, 149);
			this->pBxP2D1->TabIndex = 7;
			this->pBxP2D1->TabStop = false;
			// 
			// lblPlayer1
			// 
			this->lblPlayer1->AutoSize = true;
			this->lblPlayer1->Location = System::Drawing::Point(25, 479);
			this->lblPlayer1->Name = L"lblPlayer1";
			this->lblPlayer1->Size = System::Drawing::Size(132, 13);
			this->lblPlayer1->TabIndex = 12;
			this->lblPlayer1->Text = L"Running Total Player One:";
			// 
			// lblPlayer2
			// 
			this->lblPlayer2->AutoSize = true;
			this->lblPlayer2->Location = System::Drawing::Point(25, 529);
			this->lblPlayer2->Name = L"lblPlayer2";
			this->lblPlayer2->Size = System::Drawing::Size(133, 13);
			this->lblPlayer2->TabIndex = 13;
			this->lblPlayer2->Text = L"Running Total Player Two:";
			// 
			// lblP1Total
			// 
			this->lblP1Total->AutoSize = true;
			this->lblP1Total->Location = System::Drawing::Point(163, 479);
			this->lblP1Total->Name = L"lblP1Total";
			this->lblP1Total->Size = System::Drawing::Size(0, 13);
			this->lblP1Total->TabIndex = 14;
			// 
			// lblP2Total
			// 
			this->lblP2Total->AutoSize = true;
			this->lblP2Total->Location = System::Drawing::Point(163, 529);
			this->lblP2Total->Name = L"lblP2Total";
			this->lblP2Total->Size = System::Drawing::Size(0, 13);
			this->lblP2Total->TabIndex = 15;
			// 
			// lblP1Dice
			// 
			this->lblP1Dice->AutoSize = true;
			this->lblP1Dice->Location = System::Drawing::Point(978, 122);
			this->lblP1Dice->Name = L"lblP1Dice";
			this->lblP1Dice->Size = System::Drawing::Size(0, 13);
			this->lblP1Dice->TabIndex = 16;
			// 
			// lblP2Dice
			// 
			this->lblP2Dice->AutoSize = true;
			this->lblP2Dice->Location = System::Drawing::Point(978, 321);
			this->lblP2Dice->Name = L"lblP2Dice";
			this->lblP2Dice->Size = System::Drawing::Size(0, 13);
			this->lblP2Dice->TabIndex = 17;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1067, 624);
			this->Controls->Add(this->lblP2Dice);
			this->Controls->Add(this->lblP1Dice);
			this->Controls->Add(this->lblP2Total);
			this->Controls->Add(this->lblP1Total);
			this->Controls->Add(this->lblPlayer2);
			this->Controls->Add(this->lblPlayer1);
			this->Controls->Add(this->pBxP2D5);
			this->Controls->Add(this->pBxP2D4);
			this->Controls->Add(this->pBxP2D2);
			this->Controls->Add(this->pBxP2D3);
			this->Controls->Add(this->pBxP2D1);
			this->Controls->Add(this->pBxP1D5);
			this->Controls->Add(this->pBxP1D4);
			this->Controls->Add(this->pBxP1D2);
			this->Controls->Add(this->pBxP1D3);
			this->Controls->Add(this->pBxP1D1);
			this->Controls->Add(this->btnPlayer2);
			this->Controls->Add(this->btnPlayer1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP1D5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxP2D1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {

				rGen = gcnew Random();

				 p1PBox = gcnew array<PictureBox^>
			 {
				 pBxP1D1,
				 pBxP1D2,
				 pBxP1D3,
				 pBxP1D4,
				 pBxP1D5,
			 };

				  p2PBox = gcnew array<PictureBox^>
			 {
				 pBxP2D1,
				 pBxP2D2,
				 pBxP2D3,
				 pBxP2D4,
				 pBxP2D5,
			 };
				
				p1Dice = gcnew array<Dice^,1>(DICENUMBER);
				p2Dice = gcnew array<Dice^,1>(DICENUMBER);

				for (int i = 0; i < DICENUMBER; i++)
				{
					p1Dice[i] = gcnew Dice(0, p1PBox[i], rGen);
					p2Dice[i] = gcnew Dice(0, p2PBox[i], rGen);
				}

				player1 = gcnew Player(p1Dice);
				player2 = gcnew Player(p2Dice);


			 }

	private: System::Void btnPlayer1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 player1->playerRoll();
				 player1->computeDiceTotal();
				 player1->updateGameTotal();
				 lblP1Dice->Text = System::Convert::ToString(player1->getDiceTotal());
				 lblP1Total->Text = System::Convert::ToString(player1->getGameTotal());
			 }

	private: System::Void btnPlayer2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 player2->playerRoll();
				 player2->computeDiceTotal();
				 player2->updateGameTotal();
				 lblP2Dice->Text = System::Convert::ToString(player2->getDiceTotal());
				 lblP2Total->Text = System::Convert::ToString(player2->getGameTotal());

			 }
	};
}

