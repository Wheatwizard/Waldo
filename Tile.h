#ifndef __tile_h_
#define __tile_h_

#include "Instruction.h"

enum Arrow {NO_ARROW = 0, RIGHT_ARROW, UP_ARROW, LEFT_ARROW, DOWN_ARROW};

/*
This class is for the tiles that make up the board
*/

class Tile {
	public:
		Tile(unsigned waldo_max) {
			waldos = waldo_max;
			arrows =  new Arrow[waldo_max];
			for (unsigned i = 0; i < waldo_max; ++i) {
				arrows[i] = NO_ARROW;
			}
			instructions = new Instruction[waldo_max];
		}
		~Tile() {
			delete [] arrows;
			delete [] instructions;
		}
		//ACCESSORS
		Arrow get_arrow(unsigned waldo);
		Instruction get_instruction(unsigned waldo);
		//MODIFIERS
		void set_arrow(unsigned waldo, Arrow end_state);
		void set_instruction();
	private:
		unsigned waldos;
		Arrow* arrows;
		Instruction* instructions;
};

#endif
