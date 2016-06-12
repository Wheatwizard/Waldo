#ifndef __environment_h_
#define __environment_h_

#include "Board.h"
#include "Sink.h"
#include <queue>
#include <vector>

class Environment {
	public:
		Environment() : reactors(), sinks() {};
		~Environment();
		
		void advance();
		//MODIFIERS
		void addBoard(unsigned width, unsigned height, unsigned num_waldos);
	private:
		std::vector<Board> reactors;
		std::vector<Sink>  sinks;
};

#endif
