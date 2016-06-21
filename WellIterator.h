#include "Connector.h"
#include <vector>


/*
Well_iterator is an iterator used by the Well class.
It keeps track of what capsule should be sent next.
*/

class Well_iterator {
	public:
		//CONSTRUCTORS
		Well_iterator(std::vector<Capsule> loopPath);
		Well_iterator(std::vector<Capsule> startPath, std::vector<Capsule> loopPath);
		//OPERATORS
		Capsule& operator*();
		Well_iterator operator++();
		Well_iterator operator++(int);
		Well_iterator operator--();
		Well_iterator operator--(int);
		bool operator==(const Well_iterator& r) const;
		bool operator!=(const Well_iterator& r) const;
	private:
		//REPRESENTATION
		std::vector<Capsule>::iterator _itr, sEnd, lEnd, lBegin;
};
