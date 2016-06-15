#include "Capsule.h"

Capsule::Capsule() : contents(0) {}

Capsule::Capsule( Atom* root, unsigned rIn, unsigned cIn) : contents(root), r(rIn), c(cIn) {}

Capsule::~Capsule() {
	delete contents;
	contents = 0;
}

/*
Capsule::compatable determines whether two boards can be combined without collision
*/

bool Capsule::compatable(Capsule& other) const {
	//TODO figure out how this will work
}
