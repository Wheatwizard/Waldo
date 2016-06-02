#ifndef __instruction_h_
#define __instruction_h_

#include "Enums.h"

class Instruction {
	public:
		//CONSTRUCTORS
		Instruction() :
		variety(NO_INSTRUCTION), facing(NO_DIRECTION), rotation(true) {};
		
		Instruction(InstructionClass v) :
		variety(v), facing(NO_DIRECTION), rotation(true) {};
		
		Instruction(InstructionClass v, Direction d) :
		variety(v), facing(d), rotation(true) {};
		
		Instruction(InstructionClass v, bool r) :
		variety(v), facing(NO_DIRECTION), rotation(r) {};
		
		Instruction(InstructionClass v, Direction d, bool r) :
		variety(v), facing(d), rotation(r) {};
		
		//ACCESSORS
		InstructionClass getVariety()   const { return variety; }
		Direction        getDirection() const { return facing;  }
		bool             getRotation()  const { return rotation;}
		
		//MODIFIERS
		void setVariety(  InstructionClass v) { variety  = v; }
		void setFacing(   Direction        d) { facing   = d; }
		void setRotation( bool             r) { rotation = r; }
	
	private:
		InstructionClass variety;
		Direction facing;
		//true is counterclockwise
		bool rotation;
};

#endif
