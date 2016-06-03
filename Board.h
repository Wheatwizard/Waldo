#ifndef __board_h_
#define __board_h_

#include "Instruction.h"

//forward declare Tile
class Tile;

#include "Tile.h"

//forward declare Waldo
class Waldo;

#include "Waldo.h"

class Board {
	private:
		unsigned w, h, waldo_num, init_waldos;
		Tile** board;
		Waldo* waldos;

		void handleInstruction(unsigned waldo);
	public:
		Board(unsigned width, unsigned height, unsigned num_waldos);
		~Board();
		bool positionOnBoard(unsigned row, unsigned col) const;
		void advance();
		void addWaldo(const std::string& name, unsigned row, unsigned col);
		void addInstruction(Instruction inst, unsigned row, unsigned col, unsigned waldo);
		void addArrow(Direction arrow, unsigned row, unsigned col, unsigned waldo);
		void popAtom(Atom* root, unsigned row, unsigned col);
		void dropAtom(Atom* root, unsigned row, unsigned col);
		void bond();
		void debond();
		//ACCESSORS
		unsigned getNumCols() const { return w; }
		unsigned getNumRows() const { return h; }
		unsigned getNumWaldos() const { return waldo_num; }
		Waldo& getWaldo(unsigned index);
		//OPERATORS
		Tile* operator[] (unsigned index) {
			assert(index < getNumRows());
			return board[index];
		}
};

#endif // ifndef __board_h_
