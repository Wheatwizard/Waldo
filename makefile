objects = main.o Atom.o  Reactor.o Bond.o Tile.o Waldo.o Environment.o Recycler.o SimpleBoard.o
CXXFLAGS = -Wall

clangdbg : CXXFLAGS = -O0 -g -Wall

clang : CXX = clang++

debug : CXXFLAGS = -O0 -g -Wall

waldo : $(objects)
	$(CXX) $(CXXFLAGS) -o waldo $(objects)

main.o : main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp

Atom.o : Atom.h Atom.cpp Bond.h
	$(CXX) -c $(CXXFLAGS) Atom.cpp

 Reactor.o:  Reactor.h  Reactor.cpp Tile.h Waldo.h
	$(CXX) -c $(CXXFLAGS)  Reactor.cpp

Bond.o : Bond.h Bond.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) Bond.cpp

Environment.o : Environment.h Environment.cpp  Reactor.h
	$(CXX) -c $(CXXFLAGS) Environment.cpp

Recycler.o : Recycler.h Recycler.cpp SimpleBoard.h
	$(CXX) -c $(CXXFLAGS) Recycler.cpp

SimpleBoard.o : SimpleBoard.h SimpleBoard.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) SimpleBoard.cpp

Tile.o : Tile.h Tile.cpp Atom.h Instruction.h
	$(CXX) -c $(CXXFLAGS) Tile.cpp

Waldo.o : Waldo.h Waldo.cpp Atom.h  Reactor.h Tile.h
	$(CXX) -c $(CXXFLAGS) Waldo.cpp

clean :
	rm -f waldo $(objects)

all: waldo

debug: waldo

clang : waldo

clangdbg : clang
