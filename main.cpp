#include <iostream>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << argv[0] << " takes 1 argument." << std::endl;
		std::cout << "Please pass the name of a file to read from." << std::endl;
	}
}
