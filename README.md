# Waldo
Waldo is an esoteric programming language based on the game [Spacechem](http://www.zachtronics.com/spacechem/).

How it works
------------

Waldo is a language driven by remote manipulators called Waldos.  Waldos move about a 2 dimensional rectangular board covered in arrows, atoms, instructions, mats.  The board is comprised of tiles in a cartesian coordinate system.  Waldos may move in 4 directions (positive or negative x or y) or not move at all.  Each Waldo has a unique ID differentiating it from other Waldos. 

###Arrows
Arrows tell Waldos how to move.  Each arrow is asigned to a specific Waldo and can only interact with that Waldo.  When a Waldo occupies the same square as an arrow it takes on the direction of the arrow.  Waldos will maintain direction when not in the presence of an arrow.  No two arrows may be assigned to the same Waldo in a space.

###Atoms
Atoms are how data are stored in the board.  Atoms can be grabbed by a Waldo. Once grabbed an atom will move with a Waldo until it is dropped.  Atoms can be bonded together with a bond instruction and a bond mat (See instruction and mat).  Bonded atoms will move together if one is grabbed.


Atoms can cause Reactor Errors.  This occurs when:

 * Atoms occupy the same square
 * An atom attempts to occupy a square not on the board
 * Two Waldos attempt to move the same atom in different directions

###Instructions
Instructions perform an action when the corresponding Waldo passes over them.  Like arrows each instruction is specific to its Waldo.   No two instructions assigned to the same Waldo may exist in the same space.


The instructions are as follow:


Grab:


This causes an any atom on the square of the instruction and Waldo to be grabbed by the Waldo that activated the instruction


Drop:


This causes any atom held by the Waldo activating the instruction to no longer grab the atom it is holding placing it on the square of the instruction.


Grab/Drop:


This causes either a Grab instruction or a Drop instruction to be executed.  If the Waldo activating the instruction is holding an Atom it will perform a Drop instruction otherwise it will perform a Grab instruction.


Rotate:


This instruction comes in two varieties: clockwise and counterclockwise.  It will rotate the current atom held by the executing Waldo and by extension all atoms connected by bonds to it one fourth of a full rotation in the respective direction about the axis passing through the Waldo executing the instruction.  Rotate pauses the Waldo for one tick while it is rotating the atom.


Sync:


This instruction will cause the current Waldo to stop moving if no other Waldos are on a sync instruction.  If other Waldos are on a sync instruction the current Waldo will continue to move in the direction it has been moving and all other Waldos on a sync instruction will begin to move in the direction they were moving before they encountered the sync instruction.


Bond:


Bond comes in two varieties Bond+ and Bond-.  See Bonding mat for details.


Flip/flop:


A flip/flop instruction holds a direction. A flip/flop instruction can redirect a Waldo as if it were an arrow.  Flip/flop instructions can be active or inactive.  They will change their activity when passed over by a Waldo.  If the flip/flop instruction is active when it is passed over it will impart its direction unto the Waldo. If it is inactive it will do nothing.  Flip/flop redirections take precedent over arrow redirects (i.e. if there is an arrow and an active flip/flop in the same square the Waldo will be redirected by the flip/flop and ignore the arrow).  Flip/flop instructions will be active at cycle 0.


More instructions will be added to this list when their function is clearly defined

###Mats

There will be between 4 and 5 mats.  Only one mat can occupy a space at a time. Mats are not specific to a Waldo.


Bonding:


When a Bond+ instruction is activated on the board adjacent atoms will increase the number of bonds between them as long as they are both on a bonding map.
When a Bond- instruction is activated on the board adjacent atoms will decrease the number of bonds between them as long as they are both on a bonding map.


Fusion:


Not yet implemented


Fission:


Not yet implemented


Sensor:


Not yet implemented



Writing in Waldo
----------------

The actual syntax of the Waldo language is to be determined
