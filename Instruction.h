#ifndef __instruction_h_
#define __instruction_h_

#include "Board.h"

class Instruction {
	public:
		Instruction();
		virtual void operator(Waldo parent, Board board) {}
};

#endif
