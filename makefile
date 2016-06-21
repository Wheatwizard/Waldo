objects = main.o Atom.o Reactor.o Bond.o Tile.o Waldo.o Environment.o Capsule.o Pipe.o Well.o WellIterator.o
CXXFLAGS = -Wall -std=gnu++11

clangdbg : CXXFLAGS = -O0 -g -Wall

clang : CXX = clang++

debug : CXXFLAGS = -O0 -g -Wall

waldo : $(objects)
	$(CXX) $(CXXFLAGS) -o waldo $(objects)

main.o : main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp

Atom.o : Atom.h Atom.cpp Bond.h
	$(CXX) -c $(CXXFLAGS) Atom.cpp

Capsule.o : Capsule.h Capsule.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) Capsule.cpp

Bond.o : Bond.h Bond.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) Bond.cpp

Environment.o : Environment.h Environment.cpp  Reactor.h
	$(CXX) -c $(CXXFLAGS) Environment.cpp

Pipe.o : Pipe.h Pipe.cpp Capsule.h
	$(CXX) -c $(CXXFLAGS) Pipe.cpp

Reactor.o: Reactor.h Reactor.cpp Tile.h Waldo.h
	$(CXX) -c $(CXXFLAGS)  Reactor.cpp

Tile.o : Tile.h Tile.cpp Atom.h Instruction.h
	$(CXX) -c $(CXXFLAGS) Tile.cpp

Waldo.o : Waldo.h Waldo.cpp Atom.h  Reactor.h Tile.h
	$(CXX) -c $(CXXFLAGS) Waldo.cpp

Well.o : Well.h Well.cpp WellIterator.h
	$(CXX) -c $(CXXFLAGS) Well.cpp

WellIterator.o : WellIterator.h WellIterator.cpp Capsule.h
	$(CXX) -c $(CXXFLAGS) WellIterator.cpp

clean :
	rm -f waldo $(objects)

all: waldo

debug: waldo

clang : waldo

clangdbg : clang
