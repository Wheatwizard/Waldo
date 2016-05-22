#ifndef __board_h_
#define __board_h_

#include "Tile.h"
#include "Waldo.h"
#include <vector>

class Board {
	private:
		unsigned w, h;
		std::vector<std::vector<Tile> > board;
		std::vector<Waldo> waldos;
	public:
		Board(unsigned width, unsigned height, unsigned waldo_num);
		~Board();
		bool positionOnBoard(unsigned row, unsigned col) const;
		void advance();
		void addInstruction(const Instruction& inst, unsigned row, unsigned col, unsigned waldo);
		void addArrow(Arrow arrow, unsigned row, unsigned col, unsigned waldo);
};

#endif // ifndef __board_h_
