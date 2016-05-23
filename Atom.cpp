#include "Atom.h" 


Atom Atom::operator+(Atom& other) const {
	if (this->type == other.type) {
		return Atom(this->type, this->value + other.value);
	} else {
		//TODO throw an error
		throw 10; // this should stop it from generating a warning
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
