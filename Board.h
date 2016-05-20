#ifndef __board_h_
#define __board_h_

#include "Tile.h"

class Board {
	private:
		unsigned w, h;
		Tile** board;
		Waldo* waldos;
	public:
		Board(unsigned width, unsigned height, unsigned waldo_num);
		~Board():
		bool positionOnBoard(unsigned row, unsigned col) static;
		void advance();
		void addInstruction(const Instruction& inst, unsigned row, unsigned col, unsigned waldo);
		void addArrow(Arrow arrow, unsigned row, unsigned col, unsigned waldo);
};

#endif // ifndef __board_h_
