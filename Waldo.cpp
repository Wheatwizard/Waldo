#include <algorithm>

#include "Waldo.h"


void Waldo::move() {
	//There might be a better way to do this
	if (direction) {
		if (direction == DOWN) {
			++coords[1];
		} else if (direction == UP) {
			//Prevent the waldo from moving off the board
			coords[1] = std::min(coords[1],coords[1]-1);
		} else if (direction == RIGHT) {
			++coords[0];
		} else if (direction == LEFT) {
			//Prevent the waldo from moving off the board
			coords[0] = std::min(coords[0],coords[0]-1);
		}
	}	
}
