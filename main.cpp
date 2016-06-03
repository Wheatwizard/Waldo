#include <iostream>

#include "Board.h"

int main(int argc, char** argv) {
	/*if (argc == 1) {
		std::cout << argv[0] << " takes 1 argument." << std::endl;
		std::cout << "Please pass the name of a file to read from." << std::endl;
	}*/
	Board b(10, 10, 2);
	b.addWaldo("red", 0, 0);
	b.addWaldo("blue", 0, 0);
	b.addArrow(RIGHT, 0, 0, 0);
	b.addArrow(DOWN, 0, 9, 0);
	b.addArrow(LEFT, 9, 9, 0);
	b.addArrow(UP, 9, 0, 0);
	while (true) {
		b.advance();
	}
}
