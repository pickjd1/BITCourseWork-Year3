#pragma once
#include "TetrisGame.h"

namespace TetrisAssignment {

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

		//gridData = gcnew array <Cell^,2>(NCOLS,NROWS);



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Timer
			// 
			this->Timer->Tick += gcnew System::EventHandler(this, &Form1::Timer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tetris";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);

		}

	TetrisGame^ game;
	Graphics^ mainCanvas;
	Random^ rGen;

//	int gameState;


#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				mainCanvas = CreateGraphics();
				rGen = gcnew Random();

				game = gcnew TetrisGame(mainCanvas, rGen);

				Timer->Start();
			 }

	private: System::Void Timer_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				game->Loop();
			 }

	private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			 {
				game->SetKeyPressed(e);
			 }
	};
}

