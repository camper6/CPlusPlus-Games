#pragma once

using namespace System::Drawing;

public enum class Direction { Up, Down, Left, Right};
public enum class Clockwise {Clockwise, AntiClockwise};
// constructor of the block movement, X,Y positioning,rototation, and coordinates.
ref class Pieces
{
public:
	Pieces(Graphics^, int, int, int);
	array<char,2>^ GetShape();
	int GetCoordinateX();
	int GetCoordinateY();
	void DrawBlocks();
	void RotateBlock(Clockwise);
	void MoveBlock(Direction);
	void SetType(int);
	int GetPiece();
private:
	// Pieces definition
	// char mPieces[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */]
	// two dimensional array in a one dimension array, that is a series of arrays of 
	// rotation that makes a set of array of ONE shape. The shape is then in another
	// array to make an array of shapes. These are the shapes and its rotations
	static array<array<array<char, 2>^>^>^ mPieces = gcnew array<array<array<char, 2>^>^>
	{
		// Square
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},

		// I
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 1, 1 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 1, 1, 2, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		}
		,
		// L
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// L mirrored
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// N
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 2, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// N mirrored
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 1, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 1, 2, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// T
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 2, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		}
	};

	// Declarations of the block movement, X,Y positioning,rototation, and coordinates, graphics objects.
	int piece;
	int pieceX;
	int pieceY;
	int rotation;
	int pixelCell;
	Graphics^ shape;
	Brush^ brush;
};

