#ifndef __capsule_h_
#define __capsule_h_

#include "Atom.h"

/*
Capsule acts as a container as atoms pass through pipes
It can only hold one molecule
*/

class Capsule {
	public:
		//CONSTRUCTORS
		Capsule();
		Capsule(Atom* root, unsigned rIn, unsigned cIn);
		~Capsule();
		//ACCESSORS
		bool compatable(Capsule& other) const;
		Atom* getAtom() const { return contents; }
	private:
		Atom* contents;
		unsigned r, c;
};

#endif
