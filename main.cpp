#include <iostream>

#include "Reactor.h"

int main(int argc, char** argv) {
	/*if (argc == 1) {
		std::cout << argv[0] << " takes 1 argument." << std::endl;
		std::cout << "Please pass the name of a file to read from." << std::endl;
	}*/
	 Reactor b(10, 10, 2);
	b.addWaldo("red", 0, 0);
	b.addWaldo("blue", 0, 0);
	b.addArrow(RIGHT, 0, 0, 0);
	b.addArrow(DOWN, 0, 9, 0);
	b.addArrow(LEFT, 9, 9, 0);
	b.addArrow(UP, 9, 0, 0);
	b.addInstruction(Instruction(BOND),0,1,0);
	b[1][1].setMat(BONDER);
	b[1][2].setMat(BONDER);
	Atom* one = new Atom(TRADITIONAL, 1);
	Atom* two = new Atom(TRADITIONAL, 1);	
	b[1][1].addAtom(one);
	b[1][2].addAtom(two);
	while (true) {
		b.advance(0);
	}
}
