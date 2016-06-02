#ifndef __instruction_h_
#define __instruction_h_

#include "Enums.h"

class Instruction {
	public:
		//CONSTRUCTORS
		Instruction() :
		variety(NO_INSTRUCTION), facing(NO_DIRECTION), rotation(NO_ROTATION) {};
		
		Instruction(InstructionClass v) :
		variety(v), facing(NO_DIRECTION), rotation(NO_ROTATION) {};
		
		Instruction(InstructionClass v, Direction d) :
		variety(v), facing(d), rotation(NO_ROTATION) {};
		
		Instruction(InstructionClass v, Rotation r) :
		variety(v), facing(NO_DIRECTION), rotation(r) {};
		
		Instruction(InstructionClass v, Direction d, Rotation r) :
		variety(v), facing(d), rotation(r) {};
		
		//ACCESSORS
		InstructionClass getVariety()   const { return variety; }
		Direction        getDirection() const { return facing;  }
		Rotation         getRotation()  const { return rotation;}
		
		//MODIFIERS
		void setVariety(   InstructionClass v) { variety  = v; }
		void setDirection( Direction        d) { facing   = d; }
		void setRotation(  Rotation         r) { rotation = r; }
	
	private:
		InstructionClass variety;
		Direction facing;
		Rotation rotation;
};

#endif
