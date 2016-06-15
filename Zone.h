#ifndef __zone_h_
#define __zone_h_

#include <string>

class Zone {
	public:
		Zone();
		Zone(std::string n; unsigned w; unsigned h) : name(n), width(w), height(h);
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
