#include "Well.h"

Capsule Well::pop() {
	Capsule result = *locationMarker;
	++locationMarker;
	//I should probably make a Well iterator
	if (locationMarker == loopPath.end() || locationMarker == startPath.end()) {
		locationMarker = loopPath.begin();
	}
	return result;
}
