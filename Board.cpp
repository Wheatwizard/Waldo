#include "Board.h"

#include <stdexcept>

Board::Board(unsigned width, unsigned height, unsigned waldo_num)
	: w(width), h(height), board(new Tile*[height]), waldos(new Waldo[waldo_num]) {
	for (unsigned i = 0; i < height; ++i) {
		board[i] = new Tile[width];
		for (unsigned j = 0; j < width; ++j) {
			board[i][j] = Tile(waldo_num);
		}
	}
}

Board::~Board() {
	for (unsigned i = 0; i < height; ++i) {
		delete [] board[i];
	}
	delete [] waldos;
	delete [] board;
}

bool Board::positionOnBoard(unsigned row, unsigned col) const {
	return row < height && col < width;
}

void Board::advance() {
	// TODO write this
}

void Board::addInstruction(const Instruction& inst, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	// TODO call setInstruction on board[i][j]
}

void Board::addArrow(Arrow arrow, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	board[i][j].setArrow(waldo, arrow);
}
