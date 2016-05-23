#include "Bond.h"

Bond::Bond(Atom& left) {
	atom = &left;
	strength = 1;
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
