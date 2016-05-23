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

void Waldo::move(Board& board) {
	move(board, facing);
}

void Waldo::move(Board& board, Direction direction) {
	//There might be a better way to do this
	if (direction) {
		if (direction == DOWN) {
			r = std::min(r, board.getNumRows());
		} else if (direction == UP) {
			//Prevent the waldo from moving off the board
			r = std::min(r, r - 1);
		} else if (direction == RIGHT) {
			c = std::min(c, board.getNumCols());
		} else if (direction == LEFT) {
			//Prevent the waldo from moving off the board
			c = std::min(c, c - 1);
		}
	}
}

void Waldo::setDirection(unsigned end_direction) {
	if (end_direction) {
		facing = static_cast<Direction>(end_direction);
	}
}
