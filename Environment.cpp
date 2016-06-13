#include "Environment.h"

void Environment::advance() {
	for (unsigned i = 0; i < reactors.size(); ++i) {
		reactors[i].advance();
	}
	for (unsigned i = 0; i < recyclers.size(); ++i) {
		recyclers[i].advance();
	}
}

void Environment::addReactor(unsigned width, unsigned height, unsigned num_waldos) {
	reactors.push_back( Reactor(width, height, num_waldos));
}

