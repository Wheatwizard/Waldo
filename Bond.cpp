#include "Bond.h"

template<class Atom>
Bond<Atom>::Bond(Atom& left, Atom& right) {
	//left and right are not distinguishible
	atoms[0] = *left;
	atoms[1] = *right;
	strength = 1;
}

template<class Atom>
Bond<Atom>& Bond<Atom>::operator++() {
	++strength;
	return *this;
}

template<class Atom>
Bond<Atom>& Bond<Atom>::operator++(int) {
	Bond copy(*this);
	++strength;
	return copy;
}

template<class Atom>
Bond<Atom>& Bond<Atom>::operator--() {
	if (strength > 0) {
		++strength;
	}
	return *this;
}

template<class Atom>
Bond<Atom>& Bond<Atom>::operator--(int) {
	if (strength > 0) {
		Bond copy(*this);
		++strength;
		return copy;
	}
	return *this;
}
