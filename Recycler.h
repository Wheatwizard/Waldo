#ifndef __recycler_h_
#define __recycler_h_

#include <vector>
#include <queue>

#include "Capsule.h"

//A queue of Reactors is a pipe
typedef std::queue<Capsule> Pipe;

class Recycler {
	public:
		Recycler() : inputs() {}
		void advance();
		void connect(Pipe* p) { inputs.push_back(p); }
	private:
		std::vector<Pipe*> inputs;
};

#endif
