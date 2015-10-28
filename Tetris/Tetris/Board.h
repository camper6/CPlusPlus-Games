#pragma once
#include "Pieces.h"
using namespace System::Drawing;

//The board class public data member declerations.
ref class Board
{
public:
	Board(Graphics^);
	void DrawBoard();
	int GetScore();
	void KillCell(Pieces^);
	void RemoveLines();
	bool Collision(Pieces^);
private:
	array<char, 2>^ mBoard;
	int pixelCell;
	Graphics^ board;
	Brush^ brush;
	int score;
};
