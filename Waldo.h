
#ifndef __waldo_h_
#define __waldo_h_

enum direction {NO_DIRECTION = 0, LEFT, UP, RIGHT, DOWN};

#include <string>

class Waldo {
	public:
		Waldo(std::string n, unsigned row, unsigned col) :
			name(n), holding(NULL), facing(NO_DIRECTION), paused(false)
		{
			coords = [row,col];
		}
	private:
		std::string name;
		Atom* holding;
		direction facing;
		bool paused;
		unsigned coords;
};

#endif
