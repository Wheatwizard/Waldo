#ifndef __well_h_
#define __well_h_

#include "Connector.h"

class Well : public Connector {
	public:
		Well();
		Well(std::vector<Capsule> l) : startPath(), loopPath(l), locationMarker(loopPath.begin()) {}
		Well(std::vector<Capsule> s, std::vector<Capsule> l) : startPath(s), loopPath(l), locationMarker(startPath.begin()) {}
	private:
		std::vector<Capsule> startPath;
		std::vector<Capsule> loopPath;
		std::vector<Capsule>::iterator locationMarker;
};

#endif
