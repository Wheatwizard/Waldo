#ifndef __instruction_h_
#define __instruction_h_

#include "Enums.h"

class Instruction {
	public:
		//CONSTRUCTORS
		Instruction() : variety(NO_INSTRUCTION) {};
		
		Instruction(InstructionClass v) : variety(v) {};
		
		//ACCESSORS
		InstructionClass getVariety()   const { return variety; }
		
		//MODIFIERS
		void setVariety(   InstructionClass v) { variety  = v; }
		
		//Prototypes
		Direction        getDirection() const { return NO_DIRECTION; }
		Rotation         getRotation()  const { return NO_ROTATION;  }
		unsigned         getAtom()      const { return 0;            }
		bool isActive() const { return false; }
		
		void flip() { return; }
		void flop() { return; }
	protected:
		InstructionClass variety;
};

class Director : public Instruction {
	public:
		Director(InstructionClass v, Direction d) : Instruction(v), facing(d) {}
		
		//ACCESSORS
		Direction getDirection() const { return facing; }
		
		//MODIFIERS
		void setDirection( Direction d) { facing = d; }

	protected:
		Direction facing;
};

class FlipFlop : public Director {
	public:
		FlipFlop(Direction d) : Director(FLIP_FLOP, d) {}
		
		//ACCESSORS
		bool isActive() const { return active; }
		
		//MODIFIERS
		void flip() { active = !active; }
		void flop() { active = !active; }

	protected:
		bool active;
};

class Sensor : public Director {
	public:
		Sensor(Direction d, unsigned a) : Director(SENSE, d), atom(a) {}

		//ACCESSORS
		unsigned getAtom() const { return atom; }
		
		//MODIFIERS
		void setAtom(unsigned a) { atom = a; }
		
	protected:
		unsigned atom; 
};

class Rotator : public Instruction {
	public:
		Rotator(Rotation r) : Instruction(ROTATE), rotation(r) {}
		//ACCESSORS
		Rotation getRotation() const { return rotation; }
		//MODIFIERS
		void setRotation( Rotation r ) { rotation = r; }
	protected:
		Rotation rotation;
};

#endif
