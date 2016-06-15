#include "Atom.h" 
#include <unordered_set>

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

/*
Removes all the bonds to and from this atom
*/

void Atom::unbond() {
	//Iterate through all the bonds
	for (unsigned i = 0; i < 4; ++i) {
		//Zero out the bond
		while (bonds[i].isValid()) {
			--bonds[i];
		}
		//Zero out the complement of the bond
		while (bonds[i].getAtom()->bonds[(i+2)%4].isValid()) {
			--bonds[i].getAtom()->bonds[(i+2)%4];
		}
		//Tell the conected atom to clean itself
		bonds[i].getAtom()->cleanBonds();
	}
	//Clean this atom
	this->cleanBonds();
}

/*
Is preferred determines which atom gets higher priority for output.
True indicates that this should be output before other
*/

bool Atom::isPreferred(Atom* other) const {
	if (this->creationDate == other->creationDate) {
		//If they have the same creation date and priority there is ambiguity
		assert(this->priority != other->priority);
		return this->priority < other->priority;
	}
	return this->creationDate < other->creationDate;
}

std::unordered_set<Atom*> Atom::getMolecule() {
	std::unordered_set<Atom*> m = std::unordered_set<Atom*>();
	return getMolecule(this, m);
}

std::unordered_set<Atom*> Atom::getMolecule(Atom* root, std::unordered_set<Atom*>& found) {
	for (unsigned b = 0; b < 4; ++b) {
		if (found.end() == found.find(bonds[b].getAtom())) {
			found.insert(bonds[b].getAtom());
			getMolecule(bonds[b].getAtom(), found);
		}
	}
	return found;
}
