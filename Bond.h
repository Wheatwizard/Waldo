#ifndef __bond_h_
#define __bond_h_

//forward declare Atom
class Atom;

#include "Atom.h"

enum Direction {NO_DIRECTION = 0, LEFT, UP, RIGHT, DOWN};

class Bond {
	public:
		//CONSTRUCTOR
		Bond(Direction d);
		Bond(Atom& a, Direction d);
		//ACCESSORS
		//If a bond has strength 0 it is broken
		bool isValid() const { return strength > 0; }
		unsigned getStrength() const { return strength; }
		//MODIFIERS
		void update();
		//OPERATORS
		//the increment operator makes the bond one stronger
		Bond& operator++();
		Bond  operator++(int);
		//the decrement operator makes the bond one weaker but cannot go below zero
		Bond& operator--();
		Bond  operator--(int);
	private:
		Atom* atom;
		unsigned strength;
		Direction direction;
};

#endif
