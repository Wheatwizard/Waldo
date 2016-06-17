#ifndef __environment_h_
#define __environment_h_

#include "Reactor.h"
#include "Pipe.h"
#include "Recycler.h"

class Environment {
	public:
		Environment() : reactors(), cycles(0) {};
		~Environment();
		
		void advance();
		//MODIFIERS
		void addReactor(unsigned width, unsigned height, unsigned num_waldos);
	private:
		std::vector<Reactor> reactors;
		std::vector<Connector> pipes;
		unsigned cycles;
};

#endif
