#include "StdAfx.h"
#include "Pieces.h"
using namespace System;

//Pieces constructor and passing in its data members.

Pieces::Pieces(Graphics^ shape, int pieceX, int pieceY, int nextPiece)
{
	piece = nextPiece;
	//Assigning the piece X, piece y attribute to point to the constructors.
	this->pieceX = pieceX;
	this->pieceY = pieceY;
	//Default Rotation of piece.
	rotation = 0;	
	//Size of each cell
	pixelCell = 20;
	this->shape = shape;
	// Switch statement using the brush object to create an instance of the colour of each block.
	switch(piece){
		case 0:
			brush = gcnew SolidBrush(Color::Blue);
			break;
		case 1:
			brush = gcnew SolidBrush(Color::Red);
			break;
		case 2:
			brush = gcnew SolidBrush(Color::Yellow);
			break;
		case 3:
			brush = gcnew SolidBrush(Color::Green);
			break;
		case 4:
			brush = gcnew SolidBrush(Color::Chocolate);
			break;
		case 5:
			brush = gcnew SolidBrush(Color::Orange);
			break;
		case 6:
			brush = gcnew SolidBrush(Color::Aquamarine);
			break;
	}
}
// An Array of the clockwise rotation position of each shape.
array<char, 2>^ Pieces::GetShape()
{
	return mPieces[piece][rotation];
}
// Getter for pieceX' X coordinate.
int Pieces::GetCoordinateX()
{
	return pieceX;
}
// Getter for pieceY's Y coordinate.
int Pieces::GetCoordinateY()
{
	return pieceY;	
}
//non returnable function to draw the blocks.
void Pieces::DrawBlocks()
{
	//This loops through each row and maps  each cell of the block.
	for (int x = 0; x < mPieces[piece][rotation]->GetLength(0); x++) 
	{
		// This loop cycles through each column  and maps each cell of the block. 
		for (int y = 0; y < mPieces[piece][rotation]->GetLength(1); y++)
		{
			// Checks the map containing ones or twos representing blocks.
			if (mPieces[piece][rotation][x, y] != 0) {
				int xPos = (pieceX * pixelCell) + (x * pixelCell);
				int yPos = (pieceY * pixelCell) + (y * pixelCell);
				// Fills the inside of each cell given its position and dimensions.
				shape->FillRectangle(brush, xPos, yPos, pixelCell, pixelCell);
				shape->DrawRectangle(Pens::Black, xPos, yPos, pixelCell, pixelCell);
			}
		}
	}
}
//Anticlock wise reaction rotation on block-boundry to collision.
void Pieces::RotateBlock(Clockwise clockwise)
{
	if(clockwise == Clockwise::Clockwise) {
		rotation--;
		if (rotation < 0) {
			rotation = 3;
		}
	} // If block doesnt hit boundry, continue to turn clockwise.
	else {
		rotation++;
		if (rotation > 3) {
			rotation = 0;
		}
	}
}
// Assigning keys to block movements.

void Pieces::MoveBlock(Direction direction)
{
	if (direction == Direction::Down) {
		pieceY++;
	} else if (direction == Direction::Right) {
		pieceX++;
	} else if (direction == Direction::Left) {
		pieceX--;
	} else if (direction == Direction::Up) {
		pieceY--;
	}
}
// Assigning graveyard blocks the various colours.
void Pieces::SetType(int type) {
	piece = type;
	switch(piece){
		case 0:
			brush = gcnew SolidBrush(Color::Blue);
			break;
		case 1:
			brush = gcnew SolidBrush(Color::Red);
			break;
		case 2:
			brush = gcnew SolidBrush(Color::Yellow);
			break;
		case 3:
			brush = gcnew SolidBrush(Color::Green);
			break;
		case 4:
			brush = gcnew SolidBrush(Color::Chocolate);
			break;
		case 5:
			brush = gcnew SolidBrush(Color::Orange);
			break;
		case 6:
			brush = gcnew SolidBrush(Color::Aquamarine);
			break;
	}
}
// An index representing each piece.
int Pieces::GetPiece() {
	// Non zero based indexing.
	return piece+1;
}