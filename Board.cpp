#include "Board.h"

#include <stdexcept>

Board::Board(unsigned width, unsigned height, unsigned waldo_num) : w(width), h(height) {
	waldos.reserve(waldo_num);
	for (unsigned i = 0; i < h; ++i) {
		board.push_back(std::vector<Tile>());
		for (unsigned j = 0; j < w; ++j) {
			board[i].push_back(Tile(waldo_num));
		}
	}
}

Board::~Board() {
	//Currently this has no real use
}

bool Board::positionOnBoard(unsigned row, unsigned col) const {
	return row < h && col < w;
}

void Board::advance() {
	//Iterate through the waldos in priority order 
	for (unsigned i = 0; i < waldos.size(); ++i) {
		//Move the Waldo
		waldos[i].move();
		waldos[i].bound(w,h);
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
