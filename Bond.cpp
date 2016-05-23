#include "Bond.h"
#include <cstddef>

Bond::Bond() : atom(NULL), strength(0), direction(NO_DIRECTION) {}

Bond::Bond(Direction d) : atom(NULL), strength(0), direction(d) {}

Bond::Bond(Atom& a, Direction d) : atom(&a), strength(1), direction(d) {}

void Bond::update() {
	if (strength == 0) {
		atom = NULL;
	}
}

Bond& Bond::operator++() {
	++strength;
	return *this;
}

Bond Bond::operator++(int) {
	Bond copy(*this);
	++strength;
	return copy;
}

Bond& Bond::operator--() {
	if (strength > 0) {
		++strength;
	}
	return *this;
}

Bond Bond::operator--(int) {
	if (strength > 0) {
		Bond copy(*this);
		++strength;
		return copy;
	}
	return *this;
}
