#include "StdAfx.h"
#include "Drawer.h"

Drawer::Drawer(void)
{

}

void Drawer::init(Graphics^ f)
{
	formGraphics = f;
}

void Drawer::draw(Board^ board)
{
	for(int x = 0; x < board->getBoard()->GetLength(0); x++) {
		for(int y = 0; y < board->getBoard()->GetLength(1); y++) {
			int button = board->getBoard()[x,y];
			formGraphics->DrawImage(ball[button], x*gridSize, y*gridSize, gridSize, gridSize);
			formGraphics->DrawRectangle(border, x*gridSize, y*gridSize, gridSize, gridSize);
		}
	}

	if (board->gameOver() == true) //if board has game over state, print GAME OVER 
	{
		System::Drawing::Font^ custom = (gcnew System::Drawing::Font(L"Lucida Sans", 20.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
		formGraphics->DrawString("Game Over", custom, System::Drawing::Brushes::White, 20, 200);
	}
}
