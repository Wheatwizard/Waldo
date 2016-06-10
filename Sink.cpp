#include "Sink.h"

void Sink::advance() {
	//A sink will attempt to empty all queues connected to it
	for (unsigned i = 0; i < inputs.size(); ++i) {
		while (!inputs[i]->empty()) {
			inputs[i]->pop();
		}
	}
}
