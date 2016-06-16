#include "Pipe.h"

void Pipe::advance() {
	//Move everything from the inQ to the outQ
	while (!inQ.empty()) {
		outQ.push(inQ.front());
		inQ.pop();
	}
}
