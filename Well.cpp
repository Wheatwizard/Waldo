#include "Well.h"

Capsule Well::pop() {
	return *locationMarker++;
}
