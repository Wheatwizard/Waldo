# Waldo
Waldo is an esoteric programming language based on the game Spacechem (http://www.zachtronics.com/spacechem/).

How it works
------------

Waldo is a language driven by <Insert thing here> called Waldos.  Waldos move about a board covered in arrows, atoms, instructions, mats.

###Arrows
Arrows tell Waldos how to move.  Each arrow is asigned to a specific Waldo and can only interact with that Waldo.  When a Waldo occupies the same square as an arrow it takes on the direction of the arrow.  Waldos will maintain direction when not in the presence of an arrow.

###Atoms
Atoms are how data are stored in the board.  Atoms can be grabbed by a Waldo. Once grabbed an atom will move with a Waldo until it is dropped.  Atoms can be bonded together with a bond instruction and a bond mat (See instruction and mat).  Bonded atoms will move together if one is grabbed.


Atoms can cause Reactor Errors.  This occurs when:
*Atoms occupy the same square
*An atom attempts to occupy a square not on the board
*Two Waldos attempt to move the same atom in different directions

###Instructions
Instructions perform an action when the corresponding Waldo passes over them.  Like arrows each instruction is specific to its Waldo.


The instructions are as follow:


Grab:


This causes an any atom on the square of the instruction and Waldo to be grabbed by the Waldo that activated the instruction


Drop:


This causes any atom held by the Waldo activating the instruction to no longer grab the atom it is holding placing it on the square of the instruction.


Grab/Drop:


This causes either a Grab instruction or a Drop instruction to be executed.  If the Waldo activating the instruction is holding an Atom it will perform a Drop instruction otherwise it will perform a Grab instruction.


Rotate:


This instruction comes in two varieties: clockwise and counterclockwise.  It will rotate the current atom held by the executing Waldo and by extension all atoms connected by bonds to it one fourth of a full rotation in the respective direction about the axis passing through the Waldo executing the instruction.


Sync:


This instruction will cause the current Waldo to stop moving if no other Waldos are on a sync instruction.  If other Waldos are on a sync instruction the current Waldo will continue to move in the direction it has been moving and all other Waldos on a sync instruction will begin to move in the direction they were moving before they encountered the sync instruction.


More instructions will be added to this list when their function is clearly defined

###Mats

This list will be completed when Mats are fully or partially implemented.

Writing in Waldo
----------------

The actual syntax of the Waldo language is to be determined
