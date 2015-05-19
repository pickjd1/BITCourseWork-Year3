#pragma once

#include "IntegerNode.h"
#include "LinkedList.h"


namespace IntegerNodeLinkedList {

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
	private: System::Windows::Forms::Button^  btnAddNodes;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  btnDelete20;
	private: System::Windows::Forms::Button^  btnDelete10;
	private: System::Windows::Forms::Button^  btnDelete30;
	private: System::Windows::Forms::Button^  btnPrintEmpty;
	private: System::Windows::Forms::Button^  btnAddAgain;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnAddNodes = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->btnDelete20 = (gcnew System::Windows::Forms::Button());
			this->btnDelete10 = (gcnew System::Windows::Forms::Button());
			this->btnDelete30 = (gcnew System::Windows::Forms::Button());
			this->btnPrintEmpty = (gcnew System::Windows::Forms::Button());
			this->btnAddAgain = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnAddNodes
			// 
			this->btnAddNodes->Location = System::Drawing::Point(13, 14);
			this->btnAddNodes->Name = L"btnAddNodes";
			this->btnAddNodes->Size = System::Drawing::Size(75, 23);
			this->btnAddNodes->TabIndex = 0;
			this->btnAddNodes->Text = L"Add Nodes";
			this->btnAddNodes->UseVisualStyleBackColor = true;
			this->btnAddNodes->Click += gcnew System::EventHandler(this, &Form1::btnAddNodes_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(112, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(161, 225);
			this->listBox1->TabIndex = 1;
			// 
			// btnDelete20
			// 
			this->btnDelete20->Location = System::Drawing::Point(13, 57);
			this->btnDelete20->Name = L"btnDelete20";
			this->btnDelete20->Size = System::Drawing::Size(75, 23);
			this->btnDelete20->TabIndex = 2;
			this->btnDelete20->Text = L"Delete 20";
			this->btnDelete20->UseVisualStyleBackColor = true;
			this->btnDelete20->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// btnDelete10
			// 
			this->btnDelete10->Location = System::Drawing::Point(13, 86);
			this->btnDelete10->Name = L"btnDelete10";
			this->btnDelete10->Size = System::Drawing::Size(75, 23);
			this->btnDelete10->TabIndex = 3;
			this->btnDelete10->Text = L"Delete 10";
			this->btnDelete10->UseVisualStyleBackColor = true;
			this->btnDelete10->Click += gcnew System::EventHandler(this, &Form1::btnDelete10_Click);
			// 
			// btnDelete30
			// 
			this->btnDelete30->Location = System::Drawing::Point(13, 115);
			this->btnDelete30->Name = L"btnDelete30";
			this->btnDelete30->Size = System::Drawing::Size(75, 23);
			this->btnDelete30->TabIndex = 4;
			this->btnDelete30->Text = L"Delete 30";
			this->btnDelete30->UseVisualStyleBackColor = true;
			this->btnDelete30->Click += gcnew System::EventHandler(this, &Form1::btnDelete30_Click);
			// 
			// btnPrintEmpty
			// 
			this->btnPrintEmpty->Location = System::Drawing::Point(13, 158);
			this->btnPrintEmpty->Name = L"btnPrintEmpty";
			this->btnPrintEmpty->Size = System::Drawing::Size(75, 38);
			this->btnPrintEmpty->TabIndex = 5;
			this->btnPrintEmpty->Text = L"Print Empty List";
			this->btnPrintEmpty->UseVisualStyleBackColor = true;
			this->btnPrintEmpty->Click += gcnew System::EventHandler(this, &Form1::btnPrintEmpty_Click);
			// 
			// btnAddAgain
			// 
			this->btnAddAgain->Location = System::Drawing::Point(13, 215);
			this->btnAddAgain->Name = L"btnAddAgain";
			this->btnAddAgain->Size = System::Drawing::Size(75, 23);
			this->btnAddAgain->TabIndex = 6;
			this->btnAddAgain->Text = L"Add Again";
			this->btnAddAgain->UseVisualStyleBackColor = true;
			this->btnAddAgain->Click += gcnew System::EventHandler(this, &Form1::btnAddAgain_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->btnAddAgain);
			this->Controls->Add(this->btnPrintEmpty);
			this->Controls->Add(this->btnDelete30);
			this->Controls->Add(this->btnDelete10);
			this->Controls->Add(this->btnDelete20);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnAddNodes);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		LinkedList^ mainList;
		IntegerNode^ node1;
		IntegerNode^ node2;
		IntegerNode^ node3;


		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			mainList = gcnew LinkedList();
		}


		private: System::Void btnAddNodes_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			node1 = gcnew IntegerNode(10);
			node2 = gcnew IntegerNode(20);
			node3 = gcnew IntegerNode(30);

			mainList->addNode(node1);
			mainList->addNode(node2);
			mainList->addNode(node3);

			mainList->printListValues(listBox1);

		}
	
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 mainList->deleteNode(node2);
				 mainList->printListValues(listBox1);
			 }
private: System::Void btnDelete10_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 mainList->deleteNode(node1);
			 mainList->printListValues(listBox1);
		 }
private: System::Void btnDelete30_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 mainList->deleteNode(node3);
			 mainList->printListValues(listBox1);
		 }
private: System::Void btnPrintEmpty_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  mainList->printListValues(listBox1);
		 }
private: System::Void btnAddAgain_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			node1 = gcnew IntegerNode(10);
			node2 = gcnew IntegerNode(20);
			node3 = gcnew IntegerNode(30);

			mainList->addNode(node3);
			mainList->addNode(node2);
			mainList->addNode(node1);

			mainList->printListValues(listBox1);
		 }
};
}

