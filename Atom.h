#ifndef __atom_h_
#define __atom_h_

#include <cassert>
#include <unordered_set>

//forward declare Bond
class Bond;

#include "Bond.h"

/*
Waldo stores its data in atoms.
There are two types of atoms.
Traditional atoms represent a chemical element from Hydrogen(1) to Meitnerium(109).
Waldo also allows for atoms to store an unsigned integer greater than zero.
Atoms can make bonds with each other.  For traditional atoms the number of bonds is limited
based on the particular element. Unsigned int atoms can potentially unlimited bonds.
*/

class Atom {
	public:
		//TODO remove this constructor and all calls to it
		Atom(AtomVariety variety, unsigned val) : type(variety), value(val), creationDate(0), priority(0) {};
		Atom(AtomVariety variety, unsigned val, unsigned t) : type(variety), value(val), creationDate(t), priority(0) {};
		//ACCESSORS
		unsigned getValue() const { return value; }
		AtomVariety getVariety() const { return type; }
		unsigned getDate() const { return creationDate; }
		unsigned getAge(unsigned currCycle) const { assert(creationDate < currCycle); return currCycle-creationDate; }
		unsigned getPriority() const { return priority; }
		Bond& getBond(Direction direction) { return bonds[direction]; }
		Bond& getBond(unsigned  direction) { return bonds[direction]; }
		bool isPreferred(Atom* other) const;
		std::unordered_set<Atom*> getMolecule();
		std::unordered_set<Atom*> getMolecule(Atom* root, std::unordered_set<Atom*>& found);
		//MODIFIERS
		void roll(Rotation direction);
		void rotate(Rotation direction);
		void unbond();
		void setValue(unsigned v) { value = v; }
		void setPriority(unsigned p) { priority = p; }
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
		unsigned creationDate;
		unsigned priority;
};

#endif
