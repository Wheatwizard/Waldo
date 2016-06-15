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

Mat Tile::getMat() const {
	return mat;
}

void Tile::setInstruction(Instruction& instr, unsigned waldo) {
	assert(waldo < this->waldos);
	instructions[waldo] = instr;
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

void Tile::bond( Reactor& board, unsigned row, unsigned col) {
	if (mat != BONDER) return;
	if (row > 0 && board[row-1][col].mat == BONDER) {
		Bond& bond = atom->getBond(UP);
		if (bond.getAtom()) {
			++bond;
		} else {
			Atom* otherAtom = board[row-1][col].getAtom();
			bond.setAtom(otherAtom);
			if (atom->getPriority() > otherAtom->getPriority()) {
				atom->setPriority(otherAtom->getPriority());
			}
		}
	}
	if (row+1 < board.getNumRows() && board[row+1][col].mat == BONDER) {
		Bond& bond = atom->getBond(DOWN);
		if (bond.getAtom()) {
			++bond;
		} else {
			Atom* otherAtom = board[row+1][col].getAtom();
			bond.setAtom(otherAtom);
			if (atom->getPriority() > otherAtom->getPriority()) {
				atom->setPriority(otherAtom->getPriority());
			}
		}
	}
	if (col > 0 && board[row][col-1].mat == BONDER) {
		Bond& bond = atom->getBond(LEFT);
		if (bond.getAtom()) {
			++bond;
		} else {
			Atom* otherAtom = board[row][col-1].getAtom();
			bond.setAtom(otherAtom);
			if (atom->getPriority() > otherAtom->getPriority()) {
				atom->setPriority(otherAtom->getPriority());
			}
		}
	}
	if (col+1 < board.getNumCols() && board[row][col+1].mat == BONDER) {
		Bond& bond = atom->getBond(RIGHT);
		if (bond.getAtom()) {
			++bond;
		} else {
			Atom* otherAtom = board[row][col+1].getAtom();
			bond.setAtom(otherAtom);
			if (atom->getPriority() > otherAtom->getPriority()) {
				atom->setPriority(otherAtom->getPriority());
			}
		}
	}
}

void Tile::debond( Reactor& board, unsigned row, unsigned col) {
	//TODO Implement reprioritization of atoms
	//(Once we figure out how the hell it works)
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


void Tile::setMat(Mat mat) {
	if (!this->mat) {
		this->mat = mat;
		if (mat == FUSOR) {
			//Add a mat to the tile on the right
		}
	} else {
		throw 15;
	}
}
