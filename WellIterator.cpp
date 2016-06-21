#include "WellIterator.h"

Well_iterator::Well_iterator(std::vector<Capsule> loopPath) {
	_itr(loopPath.begin());
	sEnd();
	lEnd(loopPath.end());
	lBegin(loopPath.begin());
}

Well_iterator::Well_iterator(std::vector<Capsule> startPath, std::vector<Capsule> loopPath) : 
	_itr(startPath.begin()), sEnd(startPath.end), lEnd(loopPath.end), lBegin(loopPath.begin())
{}

Capsule& Well_iterator::operator*() {
	return *_itr;
}

Well_iterator Well_iterator::operator++() {
	++_itr;
	if (_itr == sEnd or _itr == lEnd) {
		_itr = lBegin;
	}
	return *this;
}

Well_iterator Well_iterator::operator++(int) {
	Well_iterator temp(*this);
	++_itr;
	if (_itr == sEnd or _itr == lEnd) {
		_itr = lBegin;
	}
	return temp;
}

Well_iterator Well_iterator::operator--() {
	if (_itr == lBegin) {
		_itr == lEnd;
	}
	--_itr;
	return *this;
}

Well_iterator Well_iterator::operator--(int) {
	Well_iterator temp(*this);
	if (_itr == lBegin) {
		_itr == lEnd;
	}
	--_itr;
	return temp;
}

bool Well_iterator::operator==(const Well_iterator& r) const {
	return _itr == r._itr;
}

bool Well_iterator::operator!=(const Well_iterator& r) const {
	return _itr != r._itr;
}
