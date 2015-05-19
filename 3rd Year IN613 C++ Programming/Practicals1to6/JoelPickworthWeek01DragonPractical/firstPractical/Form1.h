#pragma once


namespace firstPractical 
{

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
	private: System::Windows::Forms::Button^  btnWider;
	private: System::Windows::Forms::Timer^  tmrForm;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  btnText;
	private: System::Windows::Forms::TextBox^  tbxTextSwap;
	private: System::Windows::Forms::Button^  btnAddText;
	private: System::Windows::Forms::ListBox^  listBox;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		static bool finished = false;
		static int move = 0;
		Graphics^ mainCanvas;
		Random^ rGen;

	private: System::Windows::Forms::Button^  btnToggle;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnMovePic;

	private: System::Windows::Forms::TextBox^  tBxPicture;

	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnAnimate;
	private: System::Windows::Forms::PictureBox^  pBxAnimate;
	private: System::Windows::Forms::Button^  btnEllipses;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;




			 static int count = 1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnWider = (gcnew System::Windows::Forms::Button());
			this->tmrForm = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnText = (gcnew System::Windows::Forms::Button());
			this->tbxTextSwap = (gcnew System::Windows::Forms::TextBox());
			this->btnAddText = (gcnew System::Windows::Forms::Button());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->btnToggle = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnMovePic = (gcnew System::Windows::Forms::Button());
			this->tBxPicture = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnAnimate = (gcnew System::Windows::Forms::Button());
			this->pBxAnimate = (gcnew System::Windows::Forms::PictureBox());
			this->btnEllipses = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxAnimate))->BeginInit();
			this->SuspendLayout();
			// 
			// btnWider
			// 
			this->btnWider->Location = System::Drawing::Point(439, 12);
			this->btnWider->Name = L"btnWider";
			this->btnWider->Size = System::Drawing::Size(75, 23);
			this->btnWider->TabIndex = 0;
			this->btnWider->Text = L"Wider";
			this->btnWider->UseVisualStyleBackColor = true;
			this->btnWider->Click += gcnew System::EventHandler(this, &Form1::btnWider_Click);
			// 
			// tmrForm
			// 
			this->tmrForm->Tick += gcnew System::EventHandler(this, &Form1::tmrForm_Tick);
			// 
			// btnText
			// 
			this->btnText->Location = System::Drawing::Point(85, 63);
			this->btnText->Name = L"btnText";
			this->btnText->Size = System::Drawing::Size(75, 23);
			this->btnText->TabIndex = 1;
			this->btnText->Text = L"Text Button";
			this->btnText->UseVisualStyleBackColor = true;
			this->btnText->Click += gcnew System::EventHandler(this, &Form1::btnText_Click);
			// 
			// tbxTextSwap
			// 
			this->tbxTextSwap->Location = System::Drawing::Point(68, 98);
			this->tbxTextSwap->Name = L"tbxTextSwap";
			this->tbxTextSwap->Size = System::Drawing::Size(113, 20);
			this->tbxTextSwap->TabIndex = 2;
			// 
			// btnAddText
			// 
			this->btnAddText->Location = System::Drawing::Point(787, 62);
			this->btnAddText->Name = L"btnAddText";
			this->btnAddText->Size = System::Drawing::Size(75, 23);
			this->btnAddText->TabIndex = 3;
			this->btnAddText->Text = L"Add Line";
			this->btnAddText->UseVisualStyleBackColor = true;
			this->btnAddText->Click += gcnew System::EventHandler(this, &Form1::btnAddText_Click);
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->Location = System::Drawing::Point(766, 98);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(120, 95);
			this->listBox->TabIndex = 4;
			// 
			// btnToggle
			// 
			this->btnToggle->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnToggle->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnToggle->Location = System::Drawing::Point(68, 260);
			this->btnToggle->Name = L"btnToggle";
			this->btnToggle->Size = System::Drawing::Size(92, 42);
			this->btnToggle->TabIndex = 5;
			this->btnToggle->Text = L"Text Toggle";
			this->btnToggle->UseVisualStyleBackColor = false;
			this->btnToggle->Click += gcnew System::EventHandler(this, &Form1::btnToggle_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(447, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Question 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(85, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Question 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(793, 196);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Question 3";
			// 
			// btnMovePic
			// 
			this->btnMovePic->Location = System::Drawing::Point(68, 373);
			this->btnMovePic->Name = L"btnMovePic";
			this->btnMovePic->Size = System::Drawing::Size(100, 23);
			this->btnMovePic->TabIndex = 9;
			this->btnMovePic->Text = L"Move the Box";
			this->btnMovePic->UseVisualStyleBackColor = true;
			this->btnMovePic->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tBxPicture
			// 
			this->tBxPicture->Location = System::Drawing::Point(68, 402);
			this->tBxPicture->Name = L"tBxPicture";
			this->tBxPicture->Size = System::Drawing::Size(100, 20);
			this->tBxPicture->TabIndex = 10;
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::InfoText;
			this->pictureBox->Location = System::Drawing::Point(68, 453);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(100, 50);
			this->pictureBox->TabIndex = 11;
			this->pictureBox->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(88, 354);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Question 5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(91, 241);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Question 4";
			// 
			// btnAnimate
			// 
			this->btnAnimate->Location = System::Drawing::Point(68, 588);
			this->btnAnimate->Name = L"btnAnimate";
			this->btnAnimate->Size = System::Drawing::Size(100, 23);
			this->btnAnimate->TabIndex = 14;
			this->btnAnimate->Text = L"Start Animation";
			this->btnAnimate->UseVisualStyleBackColor = true;
			this->btnAnimate->Click += gcnew System::EventHandler(this, &Form1::btnAnimate_Click);
			// 
			// pBxAnimate
			// 
			this->pBxAnimate->BackColor = System::Drawing::SystemColors::Control;
			this->pBxAnimate->Location = System::Drawing::Point(53, 617);
			this->pBxAnimate->Name = L"pBxAnimate";
			this->pBxAnimate->Size = System::Drawing::Size(128, 128);
			this->pBxAnimate->TabIndex = 15;
			this->pBxAnimate->TabStop = false;
			// 
			// btnEllipses
			// 
			this->btnEllipses->Location = System::Drawing::Point(625, 540);
			this->btnEllipses->Name = L"btnEllipses";
			this->btnEllipses->Size = System::Drawing::Size(117, 31);
			this->btnEllipses->TabIndex = 16;
			this->btnEllipses->Text = L"Start Ellipses";
			this->btnEllipses->UseVisualStyleBackColor = true;
			this->btnEllipses->Click += gcnew System::EventHandler(this, &Form1::btnEllipses_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(766, 540);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 31);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Stop Ellipses";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(984, 882);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnEllipses);
			this->Controls->Add(this->pBxAnimate);
			this->Controls->Add(this->btnAnimate);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->tBxPicture);
			this->Controls->Add(this->btnMovePic);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnToggle);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->btnAddText);
			this->Controls->Add(this->tbxTextSwap);
			this->Controls->Add(this->btnText);
			this->Controls->Add(this->btnWider);
			this->Name = L"Form1";
			this->Text = L"Button Form";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pBxAnimate))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 tmrForm->Interval = 1000;
				 timer1->Interval = 250;
				 mainCanvas = CreateGraphics();
				 Brush^ greenBrush = gcnew SolidBrush(Color::Green);
				 rGen = gcnew Random();

			 }
	private: System::Void btnWider_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				tmrForm->Start();

				 
			 }
	private: System::Void tmrForm_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 btnWider->Width += 100;
				 btnWider->Left -= 50;
					if ((btnWider->Left + btnWider->Width)>= 1000)
					{
						finished = true;
					}

				 if (finished == true)
				 {
					 tmrForm->Stop();
					 btnWider->Text = "Too Big";
				 }
			 }
	private: System::Void btnText_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				btnText->Text = tbxTextSwap->Text;
			 }

	private: System::Void btnAddText_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
			 listBox->Items->Add("This is line " + count);
			 count ++;

		 }

	private: System::Void btnToggle_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  if (btnToggle->ForeColor == System::Drawing::SystemColors::Desktop)
			  {
				  btnToggle->ForeColor = System::Drawing::SystemColors::ButtonFace;
			  }
			  else
			  {
				  btnToggle->ForeColor = System::Drawing::SystemColors::Desktop;
			  }

		 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 move = System::Convert::ToInt32(tBxPicture->Text);
			 for (int i = 0; i < move; i++)
			 {
				 pictureBox->Left += 10;
				 System::Threading::Thread::Sleep(100);
			 }

		 }

private: System::Void btnAnimate_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for (int i = 1; i < 4; i++)
			 {
				 for (int i = 1; i < 10; i++)
				 {
					pBxAnimate->Image = Image::FromFile("Dragon"+i+".bmp");
					System::Threading::Thread::Sleep(100);
					Application::DoEvents();

				 }
			 }
		 }
private: System::Void btnEllipses_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Start();
			
		 }


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			Color customColour = Color::FromArgb(rGen->Next(255),rGen->Next(255),rGen->Next(255));
			Brush^ brush = gcnew SolidBrush(customColour);

			mainCanvas->FillEllipse(brush, rGen->Next(Form1::Width),rGen->Next(Form1::Height),rGen->Next(100), rGen->Next(100));

		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Stop();
		 }
};
}

