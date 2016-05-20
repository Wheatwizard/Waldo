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
		void addInstruction();
		void addArrow();
};

#endif // ifndef __board_h_
