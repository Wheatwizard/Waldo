#ifndef __tile_h_
#define __tile_h_

#include <cassert>
#include <stdexcept>

#include "Atom.h"

//forward declare board
class Board;

enum Instruction { NO_INSTRUCTION = 0,
	BOND, DEBOND, FUSE, FISS, GRAB, DROP, GRAB_DROP, ROTATE_CW, ROTATE_CCW, SYNC
};

#include "Board.h"

enum Mat { NO_MAT = 0, BONDER };

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
