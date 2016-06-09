#ifndef __instruction_h_
#define __instruction_h_

#include "Enums.h"

class Instruction {
	public:
		//CONSTRUCTORS
		Instruction() :
		variety(NO_INSTRUCTION), facing(NO_DIRECTION), rotation(NO_ROTATION), active(true), atom(0) {};
		
		Instruction(InstructionClass v) :
		variety(v), facing(NO_DIRECTION), rotation(NO_ROTATION), active(true), atom(0) {};
		
		Instruction(InstructionClass v, Direction d) :
		variety(v), facing(d), rotation(NO_ROTATION), active(true), atom(0) {};
		
		Instruction(InstructionClass v, Rotation r) :
		variety(v), facing(NO_DIRECTION), rotation(r), active(true), atom(0) {};
		
		Instruction(InstructionClass v, Direction d, unsigned a) :
		variety(v), facing(d), atom(a) {}
		
		//These constructors are not useful they are just here in case
		
		Instruction(InstructionClass v, Direction d, Rotation r, unsigned a) :
		variety(v), facing(d), rotation(r), active(true), atom(a) {};
		
		//ACCESSORS
		InstructionClass getVariety()   const { return variety; }
		Direction        getDirection() const { return facing;  }
		Rotation         getRotation()  const { return rotation;}
		unsigned         getAtom()      const { return atom;    }
		bool isActive() const { return active; }
				
		//MODIFIERS
		void setVariety(   InstructionClass v) { variety  = v; }
		void setDirection( Direction        d) { facing   = d; }
		void setRotation(  Rotation         r) { rotation = r; }
		void setAtom(      unsigned         a) { atom     = a; }
		
		void flip() { active = !active; }
		void flop() { active = !active; }
		
	private:
		InstructionClass variety;
		Direction facing;
		Rotation rotation;
		bool active;
		unsigned atom;
};

#endif
