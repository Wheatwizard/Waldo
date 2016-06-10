#include <vector>
#include <queue>

#include "SimpleBoard.h"

//A queue of Boards is a pipe
typedef std::queue<SimpleBoard> Pipe;

class Sink {
	public:
		Sink() : inputs() {}
		void advance();
		void connect(Pipe* p) { inputs.push_back(p); }
	private:
		std::vector<Pipe*> inputs;
};
