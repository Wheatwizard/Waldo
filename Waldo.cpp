#include <algorithm>

#include "Waldo.h"

void Waldo::move(std::vector<std::vector<Tile> >& board) {
	move(board, facing);
}

void Waldo::move(std::vector<std::vector<Tile> >& board, unsigned direction) {
	//There might be a better way to do this
	if (direction) {
		if (direction == DOWN) {
			++coords[1];
		} else if (direction == UP) {
			//Prevent the waldo from moving off the board
			coords[1] = std::min(coords[1],coords[1]-1);
		} else if (direction == RIGHT) {
			++coords[0];
		} else if (direction == LEFT) {
			//Prevent the waldo from moving off the board
			coords[0] = std::min(coords[0],coords[0]-1);
		}
	}	
}

/*
Puts the Waldo back on the board if it has moved off
*/

void Waldo::bound(std::vector<std::vector<Tile> >& board) {
	//Row and col are the number of rows/columns
	//Not the index of the largest row/column
	if (coords[0] > board.size()) {
		move(board, UP);
	}
	if (coords[1] > board[0].size()) {
		move(board, LEFT);
	}
}

void Waldo::setDirection(unsigned end_direction) {
	if (end_direction) {
		facing = static_cast<direction>(end_direction);
	}
}
