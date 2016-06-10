#include "Atom.h"

/*
SimpleBoard is an implementation of the Board class designed for use in pipelines
It lacks Waldos, instructions, mats, and zones.
It is made simply to store Atoms while they are moving between reactors
*/

//this class is just a template for the time being

class SimpleBoard {
	public:
		SimpleBoard();
		//ACCESSORS
		unsigned getWidth()  const { return width;  }
		unsigned getHeight() const { return height; }
	private:
		unsigned width, height;
		Atom*** contents;
};
