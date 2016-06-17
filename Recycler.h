#ifndef __recycler_h_
#define __recycler_h_

#include <vector>
#include <queue>

#include "Connector.h"

class Recycler : public Connector {
	public:
		Recycler() {}
		void push(Capsule in) {in.destroy();}
};

#endif
