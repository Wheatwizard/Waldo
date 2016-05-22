#include "Tile.h"
#include <cassert>
#include <stdexcept>

Arrow Tile::getArrow(unsigned waldo) const {
	assert(waldo < this->waldos);
	return arrows[waldo];
}

Instruction Tile::getInstruction(unsigned waldo) const {
	assert(waldo < this->waldos);
	return instructions[waldo];
}

Atom* Tile::getAtom() const {
	return this->atom;
}

void Tile::setArrow(unsigned waldo, Arrow end_state) {
	assert(waldo < this->waldos);
	if (arrows[waldo]) {
		throw std::runtime_error("Attempted to assign arrow where one existed");
	}
	arrows[waldo] = end_state;
}

void Tile::addAtom(Atom* atom) {
	if (this->atom == NULL) {
		this->atom = atom;
	} else {
		throw "Atom collision";
	}
}

void Tile::removeAtom() {
	atom = NULL;
}
