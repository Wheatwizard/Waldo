#include "Tile.h"
#include <cassert>
#include <stdexcept>

Arrow Tile::get_arrow(unsigned waldo) {
	assert(waldo < this->waldos);
	return arrows[waldo];
}

Instruction Tile::get_instruction(unsigned waldo) {
	assert(waldo < this->waldos);
	return instructions[waldo];
}

void Tile::set_arrow(unsigned waldo, Arrow end_state) {
	assert(waldo < this->waldos);
	if (arrows[waldo]) {
		throw std::runtime_error("Attempted to assign arrow where one existed");
	}
	arrows[waldo] = end_state;
}
