#include "Bond.h"

Bond::Bond(Direction d) {
	atom = NULL;
	direction = d;
	strength = 0;
}

Bond::Bond(Atom& a, Direction d) {
	atom = &a;
	direction = d;
	strength = 1;
}

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
