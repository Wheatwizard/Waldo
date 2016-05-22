
#ifndef __waldo_h_
#define __waldo_h_

enum Direction {NO_DIRECTION = 0, LEFT, UP, RIGHT, DOWN};

#include <string>
#include "Atom.h"

class Waldo {
	public:
		Waldo();
		Waldo(const std::string& waldo_name, unsigned row, unsigned col);
		void initialize(const std::string& waldo_name, unsigned row, unsigned col);
		//ACCESSORS
		unsigned getPriority() const { return priority; }
		unsigned getRow() const { return r; }
		unsigned getCol() const { return c; }
		//MODIFIERS
		void move();
		void bound(unsigned x_coord, unsigned y_coord);
		void setDirection(unsigned end_direction);
	private:
		std::string name;
		unsigned r, c, priority;
		Atom* holding;
		Direction facing;
		bool paused;
};

#endif
