#ifndef __enums_h_
#define __enums_h_

enum atom_variety {TRADITIONAL, ADVANCED};
enum Direction {NO_DIRECTION = 0, RIGHT, UP, LEFT, DOWN};
enum InstructionClass { NO_INSTRUCTION = 0,
	BOND, DEBOND, FUSE, FISS, GRAB, DROP, GRAB_DROP, ROTATE_CW, ROTATE_CCW, SYNC
};
enum Mat { NO_MAT = 0, BONDER };

#endif
