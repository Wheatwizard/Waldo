#include "Reactor.h"

#include <stdexcept>



 Reactor:: Reactor(unsigned width, unsigned height, unsigned num_waldos)
	: w(width), h(height), waldo_num(num_waldos), sensorx(height+1), sensory(width+1),
	   board(new Tile*[height]), waldos(new Waldo[num_waldos]) {
	for (unsigned i = 0; i < height; ++i) {
		board[i] = new Tile[width];
		for (unsigned j = 0; j < width; ++j) {
			board[i][j].initialize(num_waldos);
		}
	}
}

 Reactor::~ Reactor() {
	for (unsigned i = 0; i < h; ++i) {
		delete [] board[i];
	}
	delete [] waldos;
	delete [] board;
}

bool Reactor::positionOnBoard(unsigned row, unsigned col) const {
	return row < h && col < w;
}

void Reactor::handleInstruction(unsigned waldo) {
	Waldo& cur_waldo = waldos[waldo];
	Instruction instr = board[cur_waldo.getRow()][cur_waldo.getCol()].getInstruction(waldo);
	switch(instr.getVariety()) {
		case NO_INSTRUCTION:
			break;
		case BOND:
			bond();
			break;
		case DEBOND:
			debond();
			break;
		case FUSE:
			fuse();
			break;
		case SPLIT:
			// TODO
			break;
		case GRAB:
			cur_waldo.grab(*this);
			break;
		case DROP:
			cur_waldo.drop();
			break;
		case GRAB_DROP:
			cur_waldo.grabDrop(*this);
			break;
		case ROTATE:
			cur_waldo.rotate(*this, instr.getRotation());
			break;
		case SYNC:
			cur_waldo.sync(*this);
			break;
		case FLIP_FLOP:
			if (instr.isActive()) {
				cur_waldo.setDirection(instr.getDirection());
			}
			instr.flip();
			break;
		case SENSE:
			//Check that the sensor location is proper
			//Will be improper when unitialized
			if (!positionOnBoard(sensorx, sensory)) {throw 14;}

			//Check that there is a mat at the location
			if (board[sensorx][sensory].getMat() == SENSOR) {break;}

			//Check that the right atom is on the mat
			if (board[sensorx][sensory].getAtom() &&
			   *board[sensorx][sensory].getAtom() == instr.getAtom()) {
				cur_waldo.setDirection(instr.getDirection());
			}
			break;
		default:
			throw 1000000000;
	}
}

void Reactor::advance() {
	if (init_waldos != waldo_num) throw 7;
	//Iterate through the waldos in priority order 
	for (unsigned i = 0; i < waldo_num; ++i) {
		//Redirect
		waldos[i].setDirection(board[waldos[i].getRow()][waldos[i].getCol()].getArrow(i));
		//Perform instruction
		handleInstruction(i);
		//Move the Waldo
		waldos[i].move(*this);
	}
}

void Reactor::popAtom(Atom* root, unsigned row, unsigned col) {
	if (board[row][col].getAtom()) {
		board[row][col].removeAtom();
		if (root->getBond(UP).getAtom()) {
			popAtom(root->getBond(UP).getAtom(), row-1, col);
		}
		else if (root->getBond(DOWN).getAtom()) {
			popAtom(root->getBond(DOWN).getAtom(), row+1, col);
		}
		else if (root->getBond(RIGHT).getAtom()) {
			popAtom(root->getBond(RIGHT).getAtom(), row, col+1);
		}
		else if (root->getBond(LEFT).getAtom()) {
			popAtom(root->getBond(LEFT).getAtom(), row, col-1);
		}
	}
}

void Reactor::dropAtom(Atom* root, unsigned row, unsigned col) {
	if (board[row][col].getAtom() != root) {
		board[row][col].addAtom(root);
		if (root->getBond(UP).getAtom()) {
			dropAtom(root->getBond(UP).getAtom(), row-1, col);
		}
		else if (root->getBond(DOWN).getAtom()) {
			dropAtom(root->getBond(DOWN).getAtom(), row+1, col);
		}
		else if (root->getBond(RIGHT).getAtom()) {
			dropAtom(root->getBond(RIGHT).getAtom(), row, col+1);
		}
		else if (root->getBond(LEFT).getAtom()) {
			dropAtom(root->getBond(LEFT).getAtom(), row, col-1);
		}
	}
}

void Reactor::addWaldo(const std::string& name, unsigned row, unsigned col) {
	if (init_waldos == waldo_num) throw 8;
	waldos[init_waldos].initialize(name, row, col);
	++init_waldos;
}

void Reactor::addInstruction(Instruction inst, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	// TODO call setInstruction on board[i][j]
}

void Reactor::addArrow(Direction arrow, unsigned row, unsigned col, unsigned waldo) {
	if (!positionOnBoard(row, col)) throw std::out_of_range("row, col");
	board[row][col].setArrow(waldo, arrow);
}

Waldo& Reactor::getWaldo(unsigned index) { 
	assert(index < waldo_num);
	return waldos[index];
}

void Reactor::bond() {
	for (unsigned r = 0; r < getNumRows(); ++r) {
		for (unsigned c = 0; c < getNumCols(); ++c) {
			board[r][c].bond(*this, r, c);
		}
	}
}

void Reactor::debond() {
	for (unsigned r = 0; r < getNumRows(); ++r) {
		for (unsigned c = 0; c < getNumCols(); ++c) {
			board[r][c].debond(*this, r, c);
		}
	}
}

void Reactor::fuse() {
	for (unsigned r = 0; r < getNumRows(); ++r) {
		for (unsigned c = 0; c < getNumCols()-1; ++c) {
			if (board[r][c].getMat() == FUSOR) {
				if (board[r][c+1].getMat() == TARGET) {
					//Fuse the Atom to the right
					if (board[r][c].getAtom()) {
						board[r][c].getAtom()->unbond();
						Atom newAtom = *board[r][c+1].getAtom() + *board[r][c].getAtom();
						delete board[r][c].getAtom();
						delete board[r][c+1].getAtom();
						board[r][c+1].addAtom(NULL);
						board[r][c+1].addAtom(&newAtom);
					}
				} else {
					throw 16;
				}
			}
		}
	}
}
