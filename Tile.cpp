#include "Tile.h"

Tile::Tile() : arrows(NULL), instructions(NULL), atom(NULL) {}

Tile::Tile(unsigned waldo_max)
	: waldos(waldo_max), arrows(new Direction[waldo_max]()), // the () zero initializes the elements of Arrow
	  instructions(new Instruction[waldo_max]), atom(NULL) {}

void Tile::initialize(unsigned waldo_max) {
	assert(arrows == NULL && instructions == NULL);
	waldos = waldo_max;
	arrows = new Direction[waldo_max]();
	instructions = new Instruction[waldo_max];
}

Tile::~Tile() {
	delete [] arrows;
	delete [] instructions;
	delete atom;
}

Direction Tile::getArrow(unsigned waldo) const {
	assert(waldo < this->waldos);
	return arrows[waldo];
}

Instruction Tile::getInstruction(unsigned waldo) const {
	assert(waldo < this->waldos);
	return instructions[waldo];
}

Atom* Tile::getAtom() const {
	return this->atom;
}

void Tile::setArrow(unsigned waldo, Direction end_state) {
	assert(waldo < this->waldos);
	if (arrows[waldo]) {
		throw std::runtime_error("Attempted to assign arrow where one existed");
	}
	arrows[waldo] = end_state;
}

void Tile::addAtom(Atom* atom) {
	if (this->atom == NULL) {
		this->atom = atom;
	} else {
		throw "Atom collision";
	}
}

void Tile::removeAtom() {
	atom = NULL;
}

/*
Bond function for individual tile
*/

void Tile::bond(Board& board, unsigned row, unsigned col) {
	if (mat != BONDER) return;
	if (row > 0 && board[row-1][col].mat == BONDER) {
		Bond& bond = atom->getBond(UP);
		if (bond.getAtom()) {
			++bond;
		} else {
			bond.setAtom(board[row-1][col].getAtom());
		}
	}
	if (row+1 < board.getNumRows() && board[row+1][col].mat == BONDER) {
		Bond& bond = atom->getBond(DOWN);
		if (bond.getAtom()) {
			++bond;
		} else {
			bond.setAtom(board[row+1][col].getAtom());
		}
	}
	if (col > 0 && board[row][col-1].mat == BONDER) {
		Bond& bond = atom->getBond(LEFT);
		if (bond.getAtom()) {
			++bond;
		} else {
			bond.setAtom(board[row][col-1].getAtom());
		}
	}
	if (col+1 < board.getNumCols() && board[row][col+1].mat == BONDER) {
		Bond& bond = atom->getBond(RIGHT);
		if (bond.getAtom()) {
			++bond;
		} else {
			bond.setAtom(board[row][col+1].getAtom());
		}
	}
}

void Tile::debond(Board& board, unsigned row, unsigned col) {
	if (mat != BONDER) return;
	if (row > 0 && board[row-1][col].mat == BONDER) {
		Bond& bond = atom->getBond(UP);
		if (bond.getAtom()) {
			--bond;
		}
	}
	if (row+1 < board.getNumRows() && board[row+1][col].mat == BONDER) {
		Bond& bond = atom->getBond(DOWN);
		if (bond.getAtom()) {
			--bond;
		}
	}
	if (col > 0 && board[row][col-1].mat == BONDER) {
		Bond& bond = atom->getBond(LEFT);
		if (bond.getAtom()) {
			--bond;
		}
	}
	if (col+1 < board.getNumCols() && board[row][col+1].mat == BONDER) {
		Bond& bond = atom->getBond(RIGHT);
		if (bond.getAtom()) {
			--bond;
		}
	}
}
