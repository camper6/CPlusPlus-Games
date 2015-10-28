#pragma once
#include "Board.h"
#include "Pieces.h"
#include "Panel.h"


namespace Tetris {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			this->panel1 = gcnew CPanel();
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 400);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->Controls->Add(panel1);
			
			map = gcnew Bitmap(200, 60+400);
			graphic = Graphics::FromImage(map);
			board = gcnew Board( graphic);
			rand = gcnew Random();
			int type = rand->Next(0,7);
			shape = gcnew Pieces( graphic, 2, 0, type);
			timer = false;
			gameover = false;
			newtype = rand->Next(0,7);
			nextPiece = gcnew Pieces (panel2->CreateGraphics(), 0, 0, newtype);
			player = gcnew WMPLib::WindowsMediaPlayer();
			player->settings->setMode("loop", true);
			difficulty = 1;
			custom = (gcnew System::Drawing::Font(L"Lucida Sans", 20.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
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



		// Graphics^ board = CreateGraphics(); this pass
		Board^ board; // this remembers
	private: System::Windows::Forms::Timer^  timer1;
			 WMPLib::WindowsMediaPlayer^ player;
			 Pieces^ shape;
			 Bitmap^ map;
			 Graphics^ graphic;
			 bool timer;
			 bool gameover;
			 int difficulty;
			 System::Drawing::Font^ custom;
	private: System::Windows::Forms::Panel^  panel2;
			 CPanel^ panel1;
			 Pieces^ nextPiece;
			 Random^ rand;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
			 int newtype;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 300;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
				 // 
				 // panel2
				 // 
				 this->panel2->BackColor = System::Drawing::SystemColors::Desktop;
				 this->panel2->Location = System::Drawing::Point(419, 44);
				 this->panel2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(133, 115);
				 this->panel2->TabIndex = 0;
				 this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel2_Paint);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::Color::Transparent;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(361, 184);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(50, 15);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Score:";
				 // 
				 // textBox1
				 // 
				 this->textBox1->Enabled = false;
				 this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->textBox1->Location = System::Drawing::Point(419, 167);
				 this->textBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->ReadOnly = true;
				 this->textBox1->Size = System::Drawing::Size(132, 38);
				 this->textBox1->TabIndex = 2;
				 this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
				 // 
				 // button1
				 // 
				 this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->button1->Location = System::Drawing::Point(419, 347);
				 this->button1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(133, 44);
				 this->button1->TabIndex = 3;
				 this->button1->Text = L"New Game";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->button2->Location = System::Drawing::Point(486, 295);
				 this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(65, 46);
				 this->button2->TabIndex = 4;
				 this->button2->Text = L">";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->button3->Location = System::Drawing::Point(419, 295);
				 this->button3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(60, 46);
				 this->button3->TabIndex = 5;
				 this->button3->Text = L"<";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
				 // 
				 // textBox2
				 // 
				 this->textBox2->Enabled = false;
				 this->textBox2->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->textBox2->Location = System::Drawing::Point(419, 259);
				 this->textBox2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->ReadOnly = true;
				 this->textBox2->Size = System::Drawing::Size(132, 30);
				 this->textBox2->TabIndex = 6;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::Color::Transparent;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(336, 268);
				 this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(75, 15);
				 this->label2->TabIndex = 7;
				 this->label2->Text = L"Difficulty:";
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(601, 401);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->panel2);
				 this->DoubleBuffered = true;
				 this->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
				 this->Name = L"Form1";
				 this->Text = L"Tetris";
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
			 // Loads the form.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 player->controls->play();
			 }
			 //Checks when the timer equals true, to draw the board, sbpes, images and the colours.
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 if(timer == true) {
					 if(timer1->Enabled) {
						 board->DrawBoard();
						 shape->DrawBlocks();
						 e->Graphics->DrawImage(map, 0, -40); //Draws the image, shapes, grids onto the panel, after it's wiped clean
						 graphic->Clear(Color::Black);
					 } else {
						 // Providing feed back when the game ends.
						 graphic->DrawString("Game Over", custom, System::Drawing::Brushes::White, 20, 200);
						 e->Graphics->DrawImage(map, 0, -40);
					 }
				 }
			 }
	protected: virtual bool ProcessCmdKey(Message% msg, Keys keyData)override
				   //	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
			   {

				   // Mapping user input 
				   switch(keyData)
				   {
					   // Does not allow to move the block upwards.
				   case Keys::Down:
					   shape->MoveBlock(Direction::Down);
					   if (board->Collision(shape)== true) {
						   shape->MoveBlock(Direction::Up);
					   }
					   break;
				   case Keys::Right:
					   shape->MoveBlock(Direction::Right);
					   if (board->Collision(shape)== true) {
						   shape->MoveBlock(Direction::Left);
					   }

					   break;
				   case Keys::Left:
					   shape->MoveBlock(Direction::Left);
					   if (board->Collision(shape)== true) {
						   shape->MoveBlock(Direction::Right);
					   }
					   break;
				   case Keys::Up:
					   shape->RotateBlock(Clockwise::Clockwise);
					   if (board->Collision(shape)== true) {
						   shape->RotateBlock(Clockwise::AntiClockwise);
					   }
				   }
				   panel1->Invalidate();
				   return true;
			   }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			// When the game runs, this allows the blocks to move down, the game 
			// to check for and remove full lines, to track the score, generate random blocks, 
			//kill cells.
				 shape->MoveBlock(Direction::Down);
				 board->RemoveLines();
				 if (board->Collision(shape)== true) {
					 shape->MoveBlock(Direction::Up);
					 board->KillCell(shape);
					 board->RemoveLines();
					 shape = gcnew Pieces( graphic, 2, 0, newtype);
					 newtype = rand->Next(0,7);
					 nextPiece->SetType(newtype);
					 panel2->Invalidate();
					 panel1->Invalidate();
					 // To check  for when the stack reaches the top boundry and to stop the game,
					 // and provide feedback.
					 if(board->Collision(shape)== true) {
						 board->KillCell(shape);
						 timer1->Stop();
						 panel1->Invalidate();
						 player->controls->stop();
						 gameover = true;
					 }

				 } else {
					 panel1->Invalidate();
				 }
				// Assigning and displaying  the score to the textbox.
				 textBox1->Text = board->GetScore().ToString();
				 //Assigning timer interval to numeric represenation of difficulty.
				 if (difficulty == 1) {
					 textBox2->Text = "Noob";
					 timer1->Interval = 300;
				 } else if (difficulty == 2) {
					 textBox2->Text = "Novice";
					 timer1->Interval = 200;
				 } else if (difficulty == 3) {
					 textBox2->Text = "Experienced";
					 timer1->Interval = 100;
				 } else if (difficulty == 4) {
					 textBox2->Text = "Insane";
					 timer1->Interval = 50;
				 }
			 }
	// Draws and previews the next block.
	private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 if (timer == true && gameover == false) {
					 nextPiece->DrawBlocks();
				 }
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

	// initiates the game at the button click event.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer = true;
				 board = gcnew Board( graphic);
				 rand = gcnew Random();
				 int type = rand->Next(0,7);
				 shape = gcnew Pieces( graphic, 2, 0, type);
				 newtype = rand->Next(0,7);
				 nextPiece = gcnew Pieces (panel2->CreateGraphics(), 0, 0, newtype);
				 timer1->Start();
				 player->URL = "Tetris.mp3";
				 player->controls->play();
				 panel2->Invalidate();
				 gameover = false;
			 }
	// Button events  to decrement difficulty.
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 difficulty = difficulty -1;
				 if (difficulty <= 1) {
					 difficulty = 1;
				 }
				 //Assigning timer interval to numeric represenation of difficulty.
				 if (difficulty == 1) {
					 textBox2->Text = "Noob";
					 timer1->Interval = 300;
				 } else if (difficulty == 2) {
					 textBox2->Text = "Novice";
					 timer1->Interval = 200;
				 } else if (difficulty == 3) {
					 textBox2->Text = "Experienced";
					 timer1->Interval = 100;
				 } else if (difficulty == 4) {
					 textBox2->Text = "Insane";
					 timer1->Interval = 50;
				 }

	// Button events  to increment difficulty.		 
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 difficulty = difficulty +1;
				 if (difficulty >= 4) {
					 difficulty = 4;
				 }
				 //Assigning timer interval to numeric represenation of difficulty.
				 if (difficulty == 1) {
					 textBox2->Text = "Noob";
					 timer1->Interval = 300;
				 } else if (difficulty == 2) {
					 textBox2->Text = "Novice";
					 timer1->Interval = 200;
				 } else if (difficulty == 3) {
					 textBox2->Text = "Experienced";
					 timer1->Interval = 100;
				 } else if (difficulty == 4) {
					 textBox2->Text = "Insane";
					 timer1->Interval = 50;
				 }
			 }
	};
}

