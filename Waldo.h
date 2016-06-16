
#ifndef __waldo_h_
#define __waldo_h_

//forward declare Reactor
class  Reactor;
#include "Reactor.h"

#include <string>

class Waldo {
	public:
		Waldo();
		Waldo(const std::string& waldo_name, unsigned row, unsigned col);
		void initialize(const std::string& waldo_name, unsigned row, unsigned col);
		//ACCESSORS
		/* Unique for all Waldos */
		unsigned getPriority() const { return priority; }
		unsigned getRow() const { return r; }
		unsigned getCol() const { return c; }
		//MODIFIERS
		void move( Reactor& board);
		void move( Reactor& board, Direction direction);
		void setDirection(unsigned end_direction);
		//INSTRUCTIONS
		void grab( Reactor& board);
		void drop();
		void grabDrop( Reactor& board);
		/* for CCW direction is true otherwise CW */
		void rotate( Reactor& board, Rotation direction);
		void sync( Reactor& board);
	private:
		std::string name;
		unsigned r, c, priority;
		Atom* holding;
		Direction facing;
		bool paused;
};

#endif
