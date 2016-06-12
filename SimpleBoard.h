#ifndef __simpleBoard_h_
#define __simpleBoard_h_

#include "Atom.h"

/*
SimpleBoard is an implementation of the Board class designed for use in pipelines
It lacks Waldos, instructions, mats, and zones.
It is made simply to store Atoms while they are moving between reactors
*/

class SimpleBoard {
	public:
		//CONSTRUCTORS
		SimpleBoard(unsigned w, unsigned h);
		SimpleBoard(unsigned w, unsigned h, Atom* root, unsigned rIn, unsigned cIn);
		~SimpleBoard();
		//ACCESSORS
		unsigned getWidth()  const { return width;  }
		unsigned getHeight() const { return height; }
		bool compatable(SimpleBoard& other) const;
		//MODIFIERS
		void dropAtom(Atom* root, unsigned row, unsigned col);
	private:
		unsigned width, height;
		Atom*** contents;
};

#endif
