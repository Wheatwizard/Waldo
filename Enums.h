#ifndef __enums_h_
#define __enums_h_

enum AtomVariety {TRADITIONAL, ADVANCED};
enum Direction {NO_DIRECTION = 0, RIGHT, UP, LEFT, DOWN};
enum Rotation {CLOCKWISE = 0, COUNTERCLOCKWISE = 1, NO_ROTATION};
enum InstructionClass { NO_INSTRUCTION = 0,
	BOND, DEBOND, FUSE, SPLIT, GRAB, DROP, GRAB_DROP, ROTATE, SYNC, FLIP_FLOP, SENSE
};
enum Mat { NO_MAT = 0, BONDER, SENSOR, FUSOR, FISSOR, TARGET };

#endif
