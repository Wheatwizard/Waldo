#ifndef __reactor_h_
#define __reactor_h_

#include "Instruction.h"

//forward declare Tile
class Tile;

#include "Tile.h"

//forward declare Waldo
class Waldo;

#include "Waldo.h"

class  Reactor {
	private:
		unsigned w, h, waldo_num, init_waldos, sensorx, sensory;
		Tile** board;
		Waldo* waldos;
		
		
		void handleInstruction(unsigned waldo);
	public:
		 Reactor(unsigned width, unsigned height, unsigned num_waldos);
		~ Reactor();
		bool positionOnBoard(unsigned row, unsigned col) const;
		void advance();
		void addWaldo(const std::string& name, unsigned row, unsigned col);
		void addInstruction(Instruction inst, unsigned row, unsigned col, unsigned waldo);
		void addArrow(Direction arrow, unsigned row, unsigned col, unsigned waldo);
		void popAtom(Atom* root, unsigned row, unsigned col);
		void dropAtom(Atom* root, unsigned row, unsigned col);
		void bond();
		void debond();
		void fuse();
		void split();
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

#endif // ifndef __reactor_h_
