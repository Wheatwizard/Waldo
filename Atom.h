#ifndef __atom_h_
#define __atom_h_

//forward declare Bond
class Bond;

#include "Bond.h"


enum atom_variety {TRADITIONAL, ADVANCED};

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
		Atom(atom_variety variety,unsigned val) : type(variety), value(val) {};
		unsigned getValue() const { return value; }
		Atom operator+(Atom& other) const;
	private:
		void cleanBonds();
	private:
		//Memeber variables
		atom_variety type;
		unsigned value;
		Bond bonds[4];
};

#endif
