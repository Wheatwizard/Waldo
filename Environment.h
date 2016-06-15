#ifndef __environment_h_
#define __environment_h_

#include "Reactor.h"
#include "Recycler.h"
#include <queue>
#include <vector>

class Environment {
	public:
		Environment() : reactors(), recyclers(), cycles(0) {};
		~Environment();
		
		void advance();
		//MODIFIERS
		void addReactor(unsigned width, unsigned height, unsigned num_waldos);
		void addRecycler();
	private:
		std::vector<Reactor> reactors;
		std::vector<Recycler>  recyclers;
		unsigned cycles;
};

#endif
