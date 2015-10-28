#include "StdAfx.h"
#include "Board.h"
#include <stdlib.h> 
#include <time.h>

// Constructor of the Board
Board::Board(void) {
	srand(time(NULL));
	selectedButton = 0;	
	steps = 0;
	clickedX = 0;
	clickedY = 0;
	gameover = false;
	score = 0;
	previousScore = 0;
}

// Returns the array of the Board
array<int,2>^ Board::getBoard() {
	return board;
}

// Sets the array of the Board
void Board::setBoard(int x, int y, int number) {
	board[x, y] = number; 
}

// Generates three buttons for the Board
void Board::randomButtons() {
	int i = 0;
	while(i < 3 && gameOver() == false) { // loops until there are three button
		int x = (rand() % 9);
		int y = (rand() % 9);
		int rnd = (rand() % 6 + 1);

		if (board[x, y] == 0) { // checks if the random slot is empty
			setBoard(x, y, rnd);
			removeLine(x, y, rnd);
			i++;
		}
	}
}

// Removes a line of buttons if it's more than five
void Board::removeLine(int x, int y, int type) {
	List<array<int>^>^ verticalFull = gcnew List<array<int>^>();
	array<int>^ coordinate = {x, y};
	verticalFull->Add(coordinate);
	List<array<int>^>^ horizontalFull = gcnew List<array<int>^>();
	horizontalFull->Add(coordinate);
	int a, b, c, d = 1;

	// Adds the coordiate of the buttons if it's a row/collumn of the same type of button
	if (type != 0) {
		a=1;
		while(y+a < 9 && board[x, y+a] == type) { //checks downward
			array<int>^ coordinates = {x, y+a};
			verticalFull->Add(coordinates);
			a++;
		}
		b=1;
		while(y-b >= 0 && board[x, y-b] == type) {
			array<int>^ coordinates = {x,y-b}; //checks upward
			verticalFull->Add(coordinates);
			b++;
		}
		c = 1;
		while(x+c < 9 && board[x+c, y] == type) { //checks right
			array<int>^ coordinates = {x+c,y};
			horizontalFull->Add(coordinates);
			c++;
		}

		d = 1;
		while(x-d >= 0 && board[x-d, y] == type) { //checks left
			array<int>^ coordinates = {x-d,y};
			horizontalFull->Add(coordinates);
			d++;
		}

		// Updates the score and turn the slot empty
		if (verticalFull->Count >= 5) {
			switch (verticalFull->Count) {
				case 4:
				case 5:
					score += 10 *verticalFull->Count;
					break;
				case 6:
					score += 10 *verticalFull->Count + 10;
					break;
				case 7:
					score += 10 *verticalFull->Count + 20;
					break;
				case 8:
					score += 10 *verticalFull->Count + 30;
					break;
				case 9:
					score += 10 *verticalFull->Count + 40;
					break;
			}
			board[x, y] = 0;
			for (int i = 0; i < verticalFull->Count ; i++) {
				board[verticalFull[i][0],verticalFull[i][1]] = 0;
			}
		}

		if (horizontalFull->Count >= 5) {
			switch (horizontalFull->Count) {
				case 4:
				case 5:
					score += 10 *horizontalFull->Count;
					break;
				case 6:
					score += 10 *horizontalFull->Count + 10;
					break;
				case 7:
					score += 10 *horizontalFull->Count + 20;
					break;
				case 8:
					score += 10 *horizontalFull->Count + 30;
					break;
				case 9:
					score +=  10 *horizontalFull->Count + 40;
					break;
			}
			board[x, y] = 0;
			for (int i = 0; i < horizontalFull->Count ; i++) {
				board[horizontalFull[i][0],horizontalFull[i][1]] = 0;
			}
		}
	}
}

// Selects the button on the Board
void Board::selectButton(int x, int y) {
	if(selectedButton != 0) { // when something is slected
		if (board[x, y] == 7){ //deselect button / changes back
			board[clickedX, clickedY] = selectedButton; // Resets
			clickedX = 0;
			clickedY = 0;
			selectedButton = 0;
		} else if (pathFinding(clickedX, clickedY, x, y)->Count > 1 ) { // Checks if the path to the destination is valid
			moveButton(clickedX, clickedY, x, y); // Calls the move method to move the selected button
		}
	} else if (board[x, y] != 0 && selectedButton == 0) { //when nothing is selected, select button / changes to the selected button
		previousScore = score;
		Array::Copy(board, previous, board->Length);
		selectedButton = board[x, y];
		board[x, y] = 7;
		clickedX = x;
		clickedY = y;
	} else { //resets
		clickedX = 0;
		clickedY = 0;
		selectedButton = 0;
	}
}


// Moves the selected button towards its destination
void Board::moveButton(int originX, int originY, int destX, int destY) {
	if(board[destX, destY] == 0) { // Checks if the destination is empty and therefore valid
		List<Node^>^ path = pathFinding(originX, originY, destX, destY);
		if (path->Count > 1) {
			steps = 0;
			thePath = path;
		}
	}
}


// Finds the pathway from the button's origin cell to its destination 
List<Node^>^ Board::pathFinding(int originX, int originY, int destX, int destY) {
	bool completed = false;
	List<Node^>^ nodes = gcnew List<Node^>();
	nodes->Add(gcnew Node(destX, destY, 0));

	for (int n = 0; n < nodes->Count && completed == false; n++) { // checks if this is POTENTIAL cells, cells to be walked on
		List<Node^>^ potentialNodes = gcnew List<Node^>(); //Adds the potential cells into the list
		potentialNodes->Add(gcnew Node(nodes[n]->x+1, nodes[n]->y, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x-1, nodes[n]->y, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x, nodes[n]->y+1, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x, nodes[n]->y-1, nodes[n]->walkable+1));

		for(int i = 0; i < potentialNodes->Count; i++) { //checking adjacent grids if it's WALKABLE
			if (potentialNodes[i]->x == originX && potentialNodes[i]->y == originY) {
				completed = true;
				Node^ origin = potentialNodes[i];
				potentialNodes->Clear();
				potentialNodes->Add(origin);
			} else if (potentialNodes[i]->x < 0 || potentialNodes[i]->y < 0 || potentialNodes[i]->x >= 9 || potentialNodes[i]->y >= 9) { //checks if it's outside the boundary
				potentialNodes->RemoveAt(i);
				i--;
			} else if (board[potentialNodes[i]->x, potentialNodes[i]->y] != 0) { //checks if it's occupied
				potentialNodes->RemoveAt(i);
				i--;
			} else { //checks if there is a duplicate
				for(int j = 0; j < nodes->Count; j++) {
					if (nodes[j]->x == potentialNodes[i]->x && nodes[j]->y == potentialNodes[i]->y) {
						potentialNodes->RemoveAt(i);
						i--;
						break;
					}
				}
			}
		}

		nodes->AddRange(potentialNodes);
	}

	//checks if the path was found
	if(!(nodes[nodes->Count-1]->x == originX && nodes[nodes->Count-1]->y == originY)) {
		nodes->Clear();
		return nodes;
	} else {
		List<Node^>^ thePath = gcnew List<Node^>();
		thePath->Add(nodes[nodes->Count-1]);
		for (int i = nodes->Count-2; i >= 0 ; i--) {
			if (thePath[thePath->Count-1]->walkable-1 == nodes[i]->walkable) { //checks if it's one step closer to the origin
				if (thePath[thePath->Count-1]->x == nodes[i]->x+1 && thePath[thePath->Count-1]->y == nodes[i]->y) {
					thePath->Add(nodes[i]);
				}
				if (thePath[thePath->Count-1]->x == nodes[i]->x-1 && thePath[thePath->Count-1]->y == nodes[i]->y) {
					thePath->Add(nodes[i]);
				}
				if (thePath[thePath->Count-1]->x == nodes[i]->x && thePath[thePath->Count-1]->y+1 == nodes[i]->y) {
					thePath->Add(nodes[i]);
				}
				if (thePath[thePath->Count-1]->x == nodes[i]->x && thePath[thePath->Count-1]->y-1 == nodes[i]->y) {
					thePath->Add(nodes[i]);
				}
			}
		}
		return thePath;
	}
}

// Updates the Board
void Board::update() {
	if (thePath != nullptr) {
		if (steps < thePath->Count-1) {
			board[thePath[steps+1]->x, thePath[steps+1]->y] = selectedButton;
			board[thePath[steps]->x, thePath[steps]->y] = 0;
			steps++;
		} else {
			removeLine(thePath[thePath->Count-1]->x, thePath[thePath->Count-1]->y, board[thePath[thePath->Count-1]->x, thePath[thePath->Count-1]->y]);
			selectedButton = 0;
			randomButtons();
			thePath = nullptr;
		}
	}

}

// Returns a bool when the game is "done"
bool Board::gameOver() {
	gameover = true;
	for (int i = 0; i < board->GetLength(0); i++) { // Checks if the whole board is full
		for (int j = 0; j < board->GetLength(1); j++) {
			if (board[i, j] == 0) {
				gameover = false;
			}
		}
	}
	return gameover;
}

// Returns the score, method depends on removeLine
int Board::getScore() {
	return score;
}

// Undo method, which undo the movement and returns the Board's array to its previous state before the move
void Board::unDo() {
	score = previousScore;
	Array::Copy(previous, board, previous->Length);
}