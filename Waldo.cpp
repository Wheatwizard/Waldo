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
	int dr = 0, dc = 0;
	switch (direction) {
		case DOWN :
			dr = (r+1 != board.getNumRows());
			break;
		case UP :
			dr = -(r != 0);
			break;
		case RIGHT :
			dc = (c+1 != board.getNumCols());
			break;
		case LEFT :
			dc = -(c != 0);
			break;
		case NO_DIRECTION :
			break;
	}
	//Pop current molecule off the board
	board.popAtom(holding, r, c);	
	//Move Waldo
	r += dr;
	c += dc;
	//Put Molecule on the board
	board.dropAtom(holding, r, c);
}

void Waldo::setDirection(unsigned end_direction) {
	if (end_direction) {
		facing = static_cast<Direction>(end_direction);
	}
}
