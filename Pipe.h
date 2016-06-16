#ifndef __pipe_h_
#define __pipe_h_

#include <queue>
#include "Capsule.h"

class Pipe {
	public:
		Pipe() : inQ(), outQ() {}
		//ACCESSORS
		bool empty() const { return outQ.empty(); }
		//MODIFIERS
		void push(Capsule in) { inQ.push(in); }
		Capsule pop() { Capsule a = outQ.front(); outQ.pop(); return a; }
		void advance();
	private:
		std::queue<Capsule> inQ;
		std::queue<Capsule> outQ;	
};

#endif
