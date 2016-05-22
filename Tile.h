#ifndef __tile_h_
#define __tile_h_

#include "Instruction.h"
#include "Atom.h"

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
			atom = NULL;
		}
		~Tile() {
			delete [] arrows;
			delete [] instructions;
			delete atom;
		}
		//ACCESSORS
		Arrow getArrow(unsigned waldo) const;
		Instruction getInstruction(unsigned waldo) const;
		Atom* getAtom() const;
		//MODIFIERS
		void setArrow(unsigned waldo, Arrow end_state);
		void setInstruction();
		void addAtom(Atom* atom);
		void removeAtom();
	private:
		unsigned waldos;
		Arrow* arrows;
		Instruction* instructions;
		Atom* atom;
};

#endif
