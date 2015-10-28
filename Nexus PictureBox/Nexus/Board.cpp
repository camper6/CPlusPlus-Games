#include "StdAfx.h"
#include "Board.h"
#include <stdlib.h> 
#include <time.h>

Board::Board(void) {
	srand(time(NULL));
	selectedButton = 0;	
	steps = 0;
	clickedX = 0;
	clickedY = 0;
	gameover = false;
}

array<int,2>^ Board::getBoard() {
	return board;
}

void Board::setBoard(int x, int y, int number) {
	board[x, y] = number; 
}

void Board::randomButtons() {
	int i = 0;
	while(i < 3 && gameOver() == false) {
		int x = (rand() % 9);
		int y = (rand() % 9);
		int rnd = (rand() % 6 + 1);

		if (board[x, y] == 0) {
			setBoard(x, y, rnd);
			removeLine(x, y, rnd);
			i++;
		}
	}
}

void Board::removeLine(int x, int y, int type) {
	List<array<int>^>^ verticalFull = gcnew List<array<int>^>();
	List<array<int>^>^ horizontalFull = gcnew List<array<int>^>();
	int a, b, c, d = 1;

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

		if (verticalFull->Count >= 4) {
			board[x, y] = 0;
			for (int i = 0; i < verticalFull->Count ; i++) {
				board[verticalFull[i][0],verticalFull[i][1]] = 0;
			}
		}

		if (horizontalFull->Count >= 4) {
			board[x, y] = 0;
			for (int i = 0; i < horizontalFull->Count ; i++) {
				board[horizontalFull[i][0],horizontalFull[i][1]] = 0;
			}
		}
	}
}

void Board::selectButton(int x, int y) {
	if(selectedButton != 0) { // when something is slected
		if (board[x, y] == 7){ //deselect button
			board[clickedX, clickedY] = selectedButton;
			clickedX = 0;
			clickedY = 0;
			selectedButton = 0;
		} else if (pathFinding(clickedX, clickedY, x, y)->Count > 1 ) {
			moveButton(clickedX, clickedY, x, y);
		}
	} else if (board[x, y] != 0 && selectedButton == 0) { //when nothing is selected, select button
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

void Board::moveButton(int originX, int originY, int destX, int destY) {
	if(board[destX, destY] == 0) {
		List<Node^>^ path = pathFinding(originX, originY, destX, destY);
		if (path->Count > 1) {
			steps = 0;
			thePath = path;
		}
	}
}

/*

*/

List<Node^>^ Board::pathFinding(int originX, int originY, int destX, int destY) {
	int differenceXs = destX - originX;
	int differenceYs = destY - originY;
	int manhattanHeuristic = differenceXs + differenceYs;
	bool completed = false;

	List<Node^>^ nodes = gcnew List<Node^>();
	nodes->Add(gcnew Node(destX, destY, 0));

	for (int n = 0; n < nodes->Count && completed == false; n++) {

		List<Node^>^ potentialNodes = gcnew List<Node^>();
		potentialNodes->Add(gcnew Node(nodes[n]->x+1, nodes[n]->y, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x-1, nodes[n]->y, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x, nodes[n]->y+1, nodes[n]->walkable+1));
		potentialNodes->Add(gcnew Node(nodes[n]->x, nodes[n]->y-1, nodes[n]->walkable+1));

		for(int i = 0; i < potentialNodes->Count; i++) { //checking adjacent grids
			if (potentialNodes[i]->x == originX && potentialNodes[i]->y == originY) {
				completed = true;
				Node^ origin = potentialNodes[i];
				potentialNodes->Clear();
				potentialNodes->Add(origin);
			} else if (potentialNodes[i]->x < 0 || potentialNodes[i]->y < 0 || potentialNodes[i]->x >= 9 || potentialNodes[i]->y >= 9) {
				potentialNodes->RemoveAt(i);
				i--;
			} else if (board[potentialNodes[i]->x, potentialNodes[i]->y] != 0) {
				potentialNodes->RemoveAt(i);
				i--;
			} else {
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

	if(!(nodes[nodes->Count-1]->x == originX && nodes[nodes->Count-1]->y == originY)) {
		nodes->Clear();
		return nodes;
	} else {
		List<Node^>^ thePath = gcnew List<Node^>();
		thePath->Add(nodes[nodes->Count-1]);
		for (int i = nodes->Count-2; i >= 0 ; i--) {
			if (thePath[thePath->Count-1]->walkable-1 == nodes[i]->walkable) {
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

bool Board::gameOver() {
	gameover = true;
	for (int i = 0; i < board->GetLength(0); i++) {
		for (int j = 0; j < board->GetLength(1); j++) {
			if (board[i, j] == 0) {
				gameover = false;
			}
		}
	}
	return gameover;
}