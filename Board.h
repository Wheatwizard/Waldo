#ifndef __board_h_
#define __board_h_

#include "Tile.h"

//forward declare Waldo
class Waldo;

#include "Waldo.h"

class Board {
	private:
		unsigned w, h, waldo_num;
		Tile** board;
		Waldo* waldos;
	public:
		Board(unsigned width, unsigned height, unsigned num_waldos);
		~Board();
		bool positionOnBoard(unsigned row, unsigned col) const;
		void advance();
		void addInstruction(const Instruction& inst, unsigned row, unsigned col, unsigned waldo);
		void addArrow(Arrow arrow, unsigned row, unsigned col, unsigned waldo);
		void popAtom(Atom* root, unsigned row, unsigned col);
		void dropAtom(Atom* roow, unsigned row, unsigned col);
		//ACCESSORS
		unsigned getNumCols() const { return w; }
		unsigned getNumRows() const { return h; }
		//OPERATORS
		Tile* operator[] (unsigned index) {
			assert(index < getNumRows());
			return board[index];
		}
};

#endif // ifndef __board_h_
