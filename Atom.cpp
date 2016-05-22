#include "Atom.h" 


Atom Atom::operator+(Atom& other) const {
	if (this->type == other.type) {
		return Atom(this->type, this->value + other.value);
	} else {
		//TODO throw an error
	}
}
