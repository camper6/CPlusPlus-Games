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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  startGame;
			 Board^ board;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  undo;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->startGame = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->undo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(360, 360);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// startGame
			// 
			this->startGame->Location = System::Drawing::Point(406, 12);
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
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(391, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(107, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// undo
			// 
			this->undo->Location = System::Drawing::Point(406, 305);
			this->undo->Name = L"undo";
			this->undo->Size = System::Drawing::Size(92, 23);
			this->undo->TabIndex = 2;
			this->undo->Text = L"Undo";
			this->undo->UseVisualStyleBackColor = true;
			this->undo->Click += gcnew System::EventHandler(this, &Form1::undo_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(533, 360);
			this->Controls->Add(this->undo);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->startGame);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Nexus 2k";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Drawer::init(panel1->CreateGraphics()); // Sets up an empty board
				 for(int x = 0; x < board->getBoard()->GetLength(0); x++) {
					 for(int y = 0; y < board->getBoard()->GetLength(1); y++) {
						 board->setBoard(x, y, 0);
					 }
				 }
				 Drawer::draw(board);

			 }
	private: System::Void startGame_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled = true;
				 board->randomButtons(); // Generates the buttons
				 Drawer::draw(board); // Draws the board
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 board->selectButton(e->Location.X / 40, e->Location.Y / 40); // Selects and moves button
				 Drawer::draw(board);
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 board->update();
				 textBox1->Text = board->getScore().ToString();
				 Drawer::draw(board);
				 if (board->gameOver() == true) { // Checks if it's game over
					 timer1->Enabled = false;
				 }
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void undo_Click(System::Object^  sender, System::EventArgs^  e) {
			 board->unDo(); // Undo movement
			 Drawer::draw(board);
		 }
};
}

