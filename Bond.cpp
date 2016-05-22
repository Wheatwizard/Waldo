#include "Bond.h"

template<class Atom>
Bond<Atom>::Bond(Atom& left) {
	atom = *left;
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
