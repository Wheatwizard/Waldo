#include "Board.h"

#include <stdexcept>



Board::Board(unsigned width, unsigned height, unsigned num_waldos)
	: w(width), h(height), waldo_num(num_waldos), board(new Tile*[height]),
	  waldos(new Waldo[num_waldos]) {
	for (unsigned i = 0; i < height; ++i) {
		board[i] = new Tile[width];
		for (unsigned j = 0; j < width; ++j) {
			board[i][j].initialize(num_waldos);
		}
	}
}

Board::~Board() {
	for (unsigned i = 0; i < h; ++i) {
		delete [] board[i];
	}
	delete [] waldos;
	delete [] board;
}

bool Board::positionOnBoard(unsigned row, unsigned col) const {
	return row < h && col < w;
}

void Board::handleInstruction(unsigned waldo) {
	Waldo& cur_waldo = waldos[waldo];
	Instruction instr = board[cur_waldo.getRow()][cur_waldo.getCol()].getInstruction(waldo);
	switch(instr.getVariety()) {
		case NO_INSTRUCTION:
			break;
		case BOND:
			bond();
			break;
		case DEBOND:
			debond();
			break;
		case FUSE:
			// TODO
			break;
		case FISS:
			// TODO
			break;
		case GRAB:
			cur_waldo.grab(*this);
			break;
		case DROP:
			cur_waldo.drop();
			break;
		case GRAB_DROP:
			cur_waldo.grabDrop(*this);
			break;
		case ROTATE:
			cur_waldo.rotate(*this, instr.getRotation());
			break;
		case SYNC:
			cur_waldo.sync(*this);
			break;
		default:
			throw 1000000000;
	}
}

void Board::advance() {
	if (init_waldos != waldo_num) throw 7;
	//Iterate through the waldos in priority order 
	for (unsigned i = 0; i < waldo_num; ++i) {
		//Redirect
		waldos[i].setDirection(board[waldos[i].getRow()][waldos[i].getCol()].getArrow(i));
		//Perform instruction
		handleInstruction(i);
		//Move the Waldo
		waldos[i].move(*this);
	}
}

void Board::popAtom(Atom* root, unsigned row, unsigned col) {
	if (board[row][col].getAtom()) {
		board[row][col].removeAtom();
		if (root->getBond(UP).getAtom()) {
			popAtom(root->getBond(UP).getAtom(), row-1, col);
		}
		else if (root->getBond(DOWN).getAtom()) {
			popAtom(root->getBond(DOWN).getAtom(), row+1, col);
		}
		else if (root->getBond(RIGHT).getAtom()) {
			popAtom(root->getBond(RIGHT).getAtom(), row, col+1);
		}
		else if (root->getBond(LEFT).getAtom()) {
			popAtom(root->getBond(LEFT).getAtom(), row, col-1);
		}
	}
}

void Board::dropAtom(Atom* root, unsigned row, unsigned col) {
	if (board[row][col].getAtom() != root) {
		board[row][col].addAtom(root);
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

void Board::addWaldo(const std::string& name, unsigned row, unsigned col) {
	if (init_waldos == waldo_num) throw 8;
	waldos[init_waldos].initialize(name, row, col);
	++init_waldos;
}

void Board::addInstruction(Instruction inst, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	// TODO call setInstruction on board[i][j]
}

void Board::addArrow(Direction arrow, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	board[row][col].setArrow(waldo, arrow);
}

Waldo& Board::getWaldo(unsigned index) { 
	assert(index < waldo_num);
	return waldos[index];
}

void Board::bond() {
	for (unsigned r = 0; r < getNumRows(); ++r) {
		for (unsigned c = 0; c < getNumCols(); ++c) {
			board[r][c].bond(*this, r, c);
		}
	}
}

void Board::debond() {
	for (unsigned r = 0; r < getNumRows(); ++r) {
		for (unsigned c = 0; c < getNumCols(); ++c) {
			board[r][c].debond(*this, r, c);
		}
	}
}
