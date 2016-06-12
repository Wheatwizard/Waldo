#include "SimpleBoard.h"

SimpleBoard::SimpleBoard(unsigned w, unsigned h) : width(w), height(h), contents(new Atom**[h]) {
	for (unsigned r = 0; r < h; ++r) {
		contents[r] = new Atom*[w];
		for (unsigned c = 0; c < w; ++c) {
			//Set the pointer to zero (i.e. null)
			contents[r][c] = 0;
		}
	}
}

SimpleBoard::SimpleBoard(unsigned w, unsigned h, Atom* root, unsigned rIn, unsigned cIn) :
	width(w), height(h), contents(new Atom**[h])
{
	for (unsigned r = 0; r < h; ++r) {
		contents[r] = new Atom*[w];
		for (unsigned c = 0; c < w; ++c) {
			//Set the pointer to zero (i.e. null)
			contents[r][c] = 0;
		}
	}
	dropAtom(root, rIn, cIn);
}

SimpleBoard::~SimpleBoard() {
	delete [] contents;
	contents = 0;
}

/*
This puts an Atom on the board
(intended for use in the constructor)
*/

void SimpleBoard::dropAtom(Atom* root, unsigned row, unsigned col) {
	if (contents[row][col] != root) {
		contents[row][col] = root;
		if (root->getBond(UP).getAtom()) {
			dropAtom(root->getBond(UP).getAtom(), row-1, col);
		}
		else if (root->getBond(DOWN).getAtom()) {
			dropAtom(root->getBond(DOWN).getAtom(), row+1, col);
		}
		else if (root->getBond(RIGHT).getAtom()) {
			dropAtom(root->getBond(RIGHT).getAtom(), row, col+1);
		}
		else if (root->getBond(LEFT).getAtom()) {
			dropAtom(root->getBond(LEFT).getAtom(), row, col-1);
		}
	}
}


/*
SimpleBoard::compatable determines whether two boards can be combined without collision
*/

bool SimpleBoard::compatable(SimpleBoard& other) const {
	if (this->width != other.width || this->height != other.height) { return false; }
	for (unsigned r = 0; r < this->height; ++r) {
		for (unsigned c = 0; c < this->width; ++c) {
			if ( this->contents[r][c] && other.contents[r][r]) { return false; }
		}
	}
	return true;
}
