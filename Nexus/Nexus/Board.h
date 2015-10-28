#pragma once
#ifndef _BOARD
#define _BOARD
#endif

#include "Node.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Board
{
	static array<int,2>^ board = gcnew array<int,2>(9,9);
	static array<int,2>^ previous = gcnew array<int,2>(9,9);
	int selectedButton;
	int clickedX;
	int clickedY;
	List<Node^>^ thePath;
	int steps;
	bool gameover;
	int score;

public:
	Board(void);
	array<int,2>^ getBoard();
	void setBoard(int x, int y, int number);
	void randomButtons();
	void removeLine(int x, int y, int type);
	void selectButton(int x, int y);
	void moveButton(int originX, int originY, int destX, int destY);
	List<Node^>^ pathFinding(int originX, int originY, int destX, int destY);
	void update();
	bool gameOver();
	int getScore();
	void unDo();
	int previousScore;
};
