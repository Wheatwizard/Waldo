#include "Environment.h"

void Environment::advance() {
	++cycles;
	for (unsigned i = 0; i < reactors.size(); ++i) {
		reactors[i].advance(cycles);
	}
	for (unsigned i = 0; i < pipes.size(); ++i) {
		pipes[i].advance();
	}
}

void Environment::addReactor(unsigned width, unsigned height, unsigned num_waldos) {
	reactors.push_back(Reactor(width, height, num_waldos));
}

