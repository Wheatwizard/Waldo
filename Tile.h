#ifndef __tile_h_
#define __tile_h_

#include "Instruction.h"
#include "Waldo.h"

enum Arrow {NO_ARROW = 0, RIGHT_ARROW, UP_ARROW, LEFT_ARROW, DOWN_ARROW};

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
		Arrow getArrow(unsigned waldo) const;
		Instruction getInstruction(unsigned waldo) const;
		//MODIFIERS
		void setArrow(unsigned waldo, Arrow end_state);
		void setInstruction();
	private:
		unsigned waldos;
		Arrow* arrows;
		Instruction* instructions;
		Atom* atom;
};

#endif
