#pragma once
#include "Game.h"
#include "Board.h"
#include "Drawer.h"

namespace Nexus {

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
			board = gcnew Board();
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

	private: System::Windows::Forms::Button^  startGame;
			 Board^ board;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->startGame = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// startGame
			// 
			this->startGame->Location = System::Drawing::Point(360, 0);
			this->startGame->Name = L"startGame";
			this->startGame->Size = System::Drawing::Size(75, 23);
			this->startGame->TabIndex = 0;
			this->startGame->Text = L"Start Game";
			this->startGame->UseVisualStyleBackColor = true;
			this->startGame->Click += gcnew System::EventHandler(this, &Form1::startGame_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			//
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(360, 360);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 361);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->startGame);
			this->Name = L"Form1";
			this->Text = L"Nexus 2k";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Drawer::init(e->Graphics);
				 for(int x = 0; x < board->getBoard()->GetLength(0); x++) {
					 for(int y = 0; y < board->getBoard()->GetLength(1); y++) {
						 board->setBoard(x, y, 0);
					 }
				 }
				 Drawer::draw(board);

			 }
	private: System::Void startGame_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled = true;
				 board->randomButtons();
				 Drawer::draw(board);
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 board->selectButton(e->Location.X / 40, e->Location.Y / 40);
				 Drawer::draw(board);
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 int i = 0;
				 board->update();
				 Drawer::draw(board);
				 if (board->gameOver() == true) {
					 timer1->Enabled = false;
					 MessageBox::Show("The Timer is working?");
				 }
			 }
};
}

