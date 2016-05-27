#ifndef __tile_h_
#define __tile_h_

#include <cassert>
#include <stdexcept>

#include "Instruction.h"
#include "Atom.h"

//forward declare board
class Board;

#include "Board.h"

enum Mat { NO_MAT = 0, BOND };

/*
This class is for the tiles that make up the board
*/

class Tile {
	public:
		Tile();
		Tile(unsigned waldo_max);
		~Tile();
		void initialize(unsigned waldo_max);
		//ACCESSORS
		Direction getArrow(unsigned waldo) const;
		Instruction getInstruction(unsigned waldo) const;
		Atom* getAtom() const;
		//MODIFIERS
		void setArrow(unsigned waldo, Direction end_state);
		void setInstruction();
		void addAtom(Atom* atom);
		void removeAtom();
		void bond(Board& board, unsigned row, unsigned col);
		void debond(Board& board, unsigned row, unsigned col);
	private:
		unsigned waldos;
		Direction* arrows;
		Instruction* instructions;
		Atom* atom;
		Mat mat;
};

#endif
