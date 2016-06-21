#ifndef __well_h_
#define __well_h_

#include "WellIterator.h"

class Well : public Connector {
	typedef Well_iterator iterator;
	public:
		Well();
		Well(std::vector<Capsule> l) : startPath(), loopPath(l), locationMarker(l) {}
		Well(std::vector<Capsule> s, std::vector<Capsule> l) : startPath(s), loopPath(l), locationMarker(s,l) {}
		Capsule pop();
	private:
		std::vector<Capsule> startPath;
		std::vector<Capsule> loopPath;
		iterator locationMarker;
};

#endif
