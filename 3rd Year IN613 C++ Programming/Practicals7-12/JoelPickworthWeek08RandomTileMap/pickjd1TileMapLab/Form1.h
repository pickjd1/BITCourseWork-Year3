#pragma once
#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

namespace pickjd1TileMapLab {

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
	private: System::Windows::Forms::Button^  btnChange;
	protected: 

	private:
		Graphics^ mainCanvas;
		Random^ rGen;

		Bitmap^ water;
		Bitmap^ grass;
		Bitmap^ stone;

		TileList^ tileList;
		TileMap^ tileMap;
	private: System::Windows::Forms::Panel^  myPanel;


		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnChange = (gcnew System::Windows::Forms::Button());
			this->myPanel = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(12, 12);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(82, 43);
			this->btnChange->TabIndex = 0;
			this->btnChange->Text = L"Change the Background";
			this->btnChange->UseVisualStyleBackColor = true;
			this->btnChange->Click += gcnew System::EventHandler(this, &Form1::btnChange_Click);
			// 
			// myPanel
			// 
			this->myPanel->Location = System::Drawing::Point(153, 13);
			this->myPanel->Name = L"myPanel";
			this->myPanel->Size = System::Drawing::Size(640, 640);
			this->myPanel->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->myPanel);
			this->Controls->Add(this->btnChange);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				//initialize the graphics and random generator
				mainCanvas = myPanel->CreateGraphics();
				rGen = gcnew Random();
				
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
				tileMap = gcnew TileMap(tileList,mainCanvas);


			 }


	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				for (int i = 0; i < COLS; i++)
				{
					for (int j = 0; j < ROWS; j++)
					{
						tileMap->setMapValue(i, j, rGen->Next(3));
					}
				}
				tileMap->drawMap();
			 }
	};
}

