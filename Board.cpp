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

void Board::advance() {
	//Iterate through the waldos in priority order 
	for (unsigned i = 0; i < waldo_num; ++i) {
		//Move the Waldo
		waldos[i].move(*this);
		//Redirect
		waldos[i].setDirection(board[waldos[i].getRow()][waldos[i].getCol()].getArrow(i));
		//Perform instruction
		//TODO
	}
}

void Board::addInstruction(const Instruction& inst, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	// TODO call setInstruction on board[i][j]
}

void Board::addArrow(Arrow arrow, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	board[row][col].setArrow(waldo, arrow);
}
