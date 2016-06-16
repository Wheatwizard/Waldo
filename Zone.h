#ifndef __zone_h_
#define __zone_h_

#include <string>
#include "Pipe.h"

class Zone {
	public:
		Zone();
		Zone(std::string n, unsigned w, unsigned h) : name(n), width(w), height(h) {};
		Zone(std::string n, unsigned w, unsigned h, Pipe* p) : name(n), width(w), height(h), link(p) {};		
		//ACESSORS
		std::string getName()    const { return name;   }
		unsigned    getWidth()   const { return width;  }
		unsigned    getHeight()  const { return height; }
	private:
		std::string name;
		unsigned width;
		unsigned height;
		Pipe* link;
};

#endif
