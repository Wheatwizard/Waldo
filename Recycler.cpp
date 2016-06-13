#include "Recycler.h"

void Recycler::advance() {
	//A recycler will attempt to empty all queues connected to it
	for (unsigned i = 0; i < inputs.size(); ++i) {
		while (!inputs[i]->empty()) {
			inputs[i]->pop();
		}
	}
}
