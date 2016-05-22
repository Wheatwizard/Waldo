#include <algorithm>

#include "Waldo.h"


void Waldo::move() {
	//There might be a better way to do this
	if (facing) {
		if (facing == DOWN) {
			++coords[1];
		} else if (facing == UP) {
			//Prevent the waldo from moving off the board
			coords[1] = std::min(coords[1],coords[1]-1);
		} else if (facing == RIGHT) {
			++coords[0];
		} else if (facing == LEFT) {
			//Prevent the waldo from moving off the board
			coords[0] = std::min(coords[0],coords[0]-1);
		}
	}	
}

/*
Puts the Waldo back on the board if it has moved off
*/

void Waldo::bound(unsigned row, unsigned col) {
	//Row and col are the number of rows/columns
	//Not the index of the largest row/column
	coords[0] = std::min(coords[0]-1,row);
	coords[1] = std::min(coords[1]-1,col);
}
