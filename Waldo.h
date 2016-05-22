
#ifndef __waldo_h_
#define __waldo_h_

enum direction {NO_DIRECTION = 0, LEFT, UP, RIGHT, DOWN};

#include <string>
#include "Atom.h"

class Waldo {
	public:
		Waldo(std::string n, unsigned row, unsigned col) {
			name = n;
			coords[0] = row;
			coords[1] = col;
			holding = NULL;
			facing = NO_DIRECTION;
			paused = false;
			static unsigned id = 0;
			priority = id++;
		}
		//ACCESSORS
		unsigned getPriority() const { return priority; }
		unsigned getRow() const { return coords[0]; }
		unsigned getCol() const { return coords[1]; }
		//MODIFIERS
		void move();
		void bound(unsigned x_coord, unsigned y_coord);
		void setDirection(unsigned end_direction);
	private:
		std::string name;
		Atom* holding;
		direction facing;
		bool paused;
		unsigned coords[2];
		unsigned priority;
};

#endif
