#include "Bond.h"
#include <cstddef>

Bond::Bond() : atom(NULL), strength(0) {}

Bond::Bond(Atom& a) : atom(&a), strength(1) {}

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
		--strength;
		update();
	}
	return *this;
}

Bond Bond::operator--(int) {
	if (strength > 0) {
		Bond copy(*this);
		--strength;
		update();
		return copy;
	}
	return *this;
}
