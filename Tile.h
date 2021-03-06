#ifndef __tile_h_
#define __tile_h_

#include <cassert>
#include <stdexcept>
#include "Atom.h"

//forward declare board
class  Reactor;

#include "Reactor.h"

/*
This class is for the tiles that make up the board
*/

class Tile {
	public:
		Tile();
		Tile(unsigned waldo_max);
		~Tile();
		void initialize(unsigned waldo_max);
		//ACCESSORS
		Direction getArrow(unsigned waldo) const;
		Instruction getInstruction(unsigned waldo) const;
		Atom* getAtom() const;
		Mat getMat() const;
		//MODIFIERS
		void setArrow(unsigned waldo, Direction end_state);
		void setInstruction(Instruction& instr, unsigned waldo);
		void addAtom(Atom* atom);
		void removeAtom();
		void bond( Reactor& board, unsigned row, unsigned col);
		void debond( Reactor& board, unsigned row, unsigned col);
		void setMat(Mat mat);
	private:
		unsigned waldos;
		Direction* arrows;
		Instruction* instructions;
		Atom* atom;
		Mat mat;
};

#endif
