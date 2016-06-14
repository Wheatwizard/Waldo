#ifndef __atom_h_
#define __atom_h_

//forward declare Bond
class Bond;

#include "Bond.h"

#include "Enums.h"

/*
Waldo stores its data in atoms.
There are two types of atoms.
Traditional atoms represent a chemical element from Hydrogen(1) to Meitnerium(109).
Waldo also allows for atoms to store an unsigned integer with no bounds.
Atoms can make bonds with each other.  For traditional atoms the number of bonds is limited
based on the particular element. Unsigned int atoms can potentially unlimited bonds.
*/

class Atom {
	public:
		Atom(AtomVariety variety,unsigned val) : type(variety), value(val) {};
		//ACCESSORS
		unsigned getValue() const { return value; }
		AtomVariety getVariety() const { return type; }
		Bond& getBond(Direction direction) { return bonds[direction]; }
		Bond& getBond(unsigned  direction) { return bonds[direction]; }
		//MODIFIERS
		void roll(Rotation direction);
		void rotate(Rotation direction);
		void unbond();
		void setValue(unsigned v) { value = v; }
		//OPERATOS
		Atom operator+(Atom& other) const;
		bool operator==(Atom other) const {
			return this->value == other.value;
		}
		bool operator==(unsigned other) const {
			return this->value == other;
		}
	private:
		void cleanBonds();
	private:
		//Memeber variables
		AtomVariety type;
		unsigned value;
		Bond bonds[4];
};

#endif
