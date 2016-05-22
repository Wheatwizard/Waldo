objects = main.o Atom.o Board.o Bond.o Tile.o Waldo.o
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

Board.o: Board.h Board.cpp Tile.h Waldo.h
	$(CXX) -c $(CXXFLAGS) Board.cpp

Bond.o : Bond.h Bond.cpp
	$(CXX) -c $(CXXFLAGS) Bond.cpp

Tile.o : Tile.h Tile.cpp Instruction.h Waldo.h
	$(CXX) -c $(CXXFLAGS) Tile.cpp

Waldo.o : Waldo.h Waldo.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) Waldo.cpp

clean :
	rm -f waldo $(objects)

all: quad_tree

debug: quad_tree

clang : quad_tree

clangdbg : clang
