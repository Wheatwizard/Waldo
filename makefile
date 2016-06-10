objects = main.o Atom.o Board.o Bond.o Tile.o Waldo.o Environment.o
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

Bond.o : Bond.h Bond.cpp Atom.h
	$(CXX) -c $(CXXFLAGS) Bond.cpp

Environment.o : Environment.h Environment.cpp Board.h
	$(CXX) -c $(CXXFLAGS) Environment.cpp

Tile.o : Tile.h Tile.cpp Atom.h Instruction.h
	$(CXX) -c $(CXXFLAGS) Tile.cpp

Waldo.o : Waldo.h Waldo.cpp Atom.h Board.h Tile.h
	$(CXX) -c $(CXXFLAGS) Waldo.cpp

clean :
	rm -f waldo $(objects)

all: waldo

debug: waldo

clang : waldo

clangdbg : clang
