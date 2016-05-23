
#ifndef __waldo_h_
#define __waldo_h_

//forward declare Board
class Board;
#include "Board.h"

#include <string>
#include "Atom.h"
#include "Tile.h"

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
		void move(Board& board);
		void move(Board& board, Direction direction);
		void setDirection(unsigned end_direction);
	private:
		void move(std::vector<std::vector<Tile> >& board, unsigned direction);
	private:
		std::string name;
		unsigned r, c, priority;
		Atom* holding;
		Direction facing;
		bool paused;
};

#endif
