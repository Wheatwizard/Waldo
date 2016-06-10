#include "Board.h"
#include <queue>
#include <vector>

class Environment {
	public:
		Environment() : reactors() {};
		~Environment();
		
		void advance();
		//MODIFIERS
		void addBoard(unsigned width, unsigned height, unsigned num_waldos);
	private:
		std::vector<Board> reactors;
};
