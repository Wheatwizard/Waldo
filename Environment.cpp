#include "Environment.h"

void Environment::advance() {
	for (unsigned i = 0; i < reactors.size(); ++i) {
		reactors[i].advance();
	}
	for (unsigned i = 0; i < sinks.size(); ++i) {
		sinks[i].advance();
	}
}

void Environment::addBoard(unsigned width, unsigned height, unsigned num_waldos) {
	reactors.push_back(Board(width, height, num_waldos));
}

