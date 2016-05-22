#include <algorithm>

#include "Waldo.h"

/*
 * Note that this is a nonmember function. It is not declared in the .h file
 * because it is not meant to be called outside this class.
 */
unsigned createPriority() {
	static unsigned id = 0;
	return id++; // returns the value that id had before incrementing
}

Waldo::Waldo() : priority(createPriority()), holding(NULL), facing(NO_DIRECTION),
	paused(false) {}

Waldo::Waldo(const std::string& waldo_name, unsigned row, unsigned col)
	: name(waldo_name), r(row), c(col), priority(createPriority()), holding(NULL),
	  facing(NO_DIRECTION), paused(false) {}

void Waldo::initialize(const std::string& waldo_name, unsigned row, unsigned col) {
	name = waldo_name;
	r = row;
	c = col;
}
void Waldo::move() {
	//There might be a better way to do this
	if (facing) {
		if (facing == DOWN) {
			++r;
		} else if (facing == UP) {
			//Prevent the waldo from moving off the board
			r = std::min(r, r - 1);
		} else if (facing == RIGHT) {
			++c;
		} else if (facing == LEFT) {
			//Prevent the waldo from moving off the board
			c = std::min(c, c - 1);
		}
	}	
}

/*
Puts the Waldo back on the board if it has moved off
*/

void Waldo::bound(unsigned row, unsigned col) {
	//Row and col are the number of rows/columns
	//Not the index of the largest row/column
	r = std::min(r - 1,row);
	c = std::min(c - 1,col);
}

void Waldo::setDirection(unsigned end_direction) {
	if (end_direction) {
		facing = static_cast<Direction>(end_direction);
	}
}
