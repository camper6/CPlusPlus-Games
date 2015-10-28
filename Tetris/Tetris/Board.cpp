#include "StdAfx.h"
#include "Board.h"
// The Board constructor and the attributes assigned to it.
Board::Board(Graphics^ board)
{
	// Array of the dimensions of the board.
	mBoard = gcnew array<char, 2>(10,22);
	pixelCell = 20;
	this->board = board;
	score = 0;
}
// Non returnable method that enables the board to check for dead bricks.
void Board::DrawBoard()
{
	for(int i = 0; i < mBoard->GetLength(0); i++ ) { // Dead bricks
		for(int y = 0 ; y < mBoard->GetLength(1); y++) {
			if (mBoard[i, y] != 0) {
				int xPos = i * pixelCell;
				int yPos = y * pixelCell;
				switch(mBoard[i, y]){
		case 1:
			brush = gcnew SolidBrush(Color::Blue);
			break;
		case 2:
			brush = gcnew SolidBrush(Color::Red);
			break;
		case 3:
			brush = gcnew SolidBrush(Color::Yellow);
			break;
		case 4:
			brush = gcnew SolidBrush(Color::Green);
			break;
		case 5:
			brush = gcnew SolidBrush(Color::Chocolate);
			break;
		case 6:
			brush = gcnew SolidBrush(Color::Orange);
			break;
		case 7:
			brush = gcnew SolidBrush(Color::Aquamarine);
			break;
				}
				// Applying colour to graveyard block cells..
				board->FillRectangle(brush, xPos, yPos, pixelCell, pixelCell);
				board->DrawRectangle(Pens::Black, xPos, yPos, pixelCell, pixelCell);
			}
		}
	}
}
//Method for the score getter.
int Board::GetScore()
{
	return score;
}
// Method for killling the cell.
void Board::KillCell(Pieces^ piece)
{ 
	//  Mapping the X, and Y coordinates of the blocks.
	int xPos = piece->GetCoordinateX();
	int yPos = piece->GetCoordinateY();
	array<char, 2>^ shape = piece->GetShape();
	// Where it stores these coordinates into an array.
	for(int x = 0; x < shape->GetLength(0); x++) {
		for(int y = 0; y < shape->GetLength(1); y++) {
			// Assigns the shape array into the board.
			if (shape[x, y] != 0 ) {
				int xPiece = xPos + x;
				int yPiece = yPos + y;
				mBoard[xPiece, yPiece] = piece->GetPiece();
			}
		}
	} 
}

void Board::RemoveLines()
{
	for(int row = mBoard->GetLength(1)-1; row >= 0; row--) {//goes through each row and each collumn in a row
		int full = 0;
		for(int col = mBoard->GetLength(0)-1; col >= 0; col--) {
			if (mBoard[col, row] != 0) {// checks the cell if it's full
				full++;
			}
		}
		if (full == mBoard->GetLength(0)) {//checks the number of full cells equals to the number of cells in a row, so that it is a line that we are removing
			score = score + 150;
			for(int fullrow = row; fullrow >= 1; fullrow--) {//goes backward
				for(int fullcol = mBoard->GetLength(0)-1; fullcol >= 0; fullcol--) {
					mBoard[fullcol, fullrow] = mBoard[fullcol, fullrow-1];//the full row would then move the row above down
				}
			}
		}
	}
}
// Method for  collision detection.
bool Board::Collision(Pieces^ piece)
{
	
	int xPos = piece->GetCoordinateX();
	int yPos = piece->GetCoordinateY();
	array<char, 2>^ shape = piece->GetShape();
	// Checks  the length of the row and columns where not equal to zero.
	for(int x = 0; x < shape->GetLength(0); x++) {
		for(int y = 0; y < shape->GetLength(1); y++) {
			if (shape[x, y] != 0 ) {
				//Checks the boundries in relation to the blocks.
				int xPiece = xPos + x;
				int yPiece = yPos + y;
				if (xPiece >= 10 || xPiece < 0 || yPiece >= 22 || yPiece < 0 || mBoard[xPiece, yPiece] != 0 ) {
					return true;
				}
			}
		}
	}
	return false;
}