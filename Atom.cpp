#include "Atom.h" 


Atom Atom::operator+(Atom& other) const {
	if (this->type == other.type) {
		return Atom(this->type, this->value + other.value);
	} else {
		//TODO throw an error
		throw 10; // this should stop it from generating a warning
	}
}

void Atom::roll(Rotation direction) {
	Bond bonds_copy[4];
	unsigned diff = 3;
	if (direction) {
		diff = 1;
	}
	for (unsigned i = 0; i < 4; ++i) {
		bonds_copy[(i+diff)%4] = bonds[i];
	}
	for (unsigned i = 0; i < 4; ++i) {
		bonds[i] = bonds_copy[i];
	}
}

void Atom::rotate(Rotation direction) {
	//I think there might be a better way to do this algorithm
	//Roll this (the root)
	roll(direction);
	for (unsigned i = 0; i < 4; ++i) {
		if (bonds[i].getAtom() //Check that there is a bond to a non-Null atom
		    &&
		    bonds[i].getAtom()->getBond((i+2)%4).getAtom() != this //Check that the other atom has not been rotated as well
		) {
			//recurse
			bonds[i].getAtom()->rotate(direction);
		}
	}
}

/*
clean bonds removes all unecessary bonds.
(Bonds with strength zero)
*/

void Atom::cleanBonds() {
	for (unsigned i = 0; i < 4; ++i) {
		bonds[i].update();
	}
}
