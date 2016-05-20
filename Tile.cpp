#include "Tile.h"
#include <cassert>
#include <stdexcept>

Arrow Tile::getArrow(unsigned waldo) {
	assert(waldo < this->waldos);
	return arrows[waldo];
}

Instruction Tile::getInstruction(unsigned waldo) {
	assert(waldo < this->waldos);
	return instructions[waldo];
}

void Tile::setArrow(unsigned waldo, Arrow end_state) {
	assert(waldo < this->waldos);
	if (arrows[waldo]) {
		throw std::runtime_error("Attempted to assign arrow where one existed");
	}
	arrows[waldo] = end_state;
}
