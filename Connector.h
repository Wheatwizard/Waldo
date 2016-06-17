#ifndef __connector_h_
#define __connector_h_

#include "Capsule.h"

class Connector {
	public:
		Connector() {}
		//MODIFIERS
		void advance() { return; }
		void push(Capsule in) { return; }
		Capsule pop() { return Capsule(); }
};

#endif
