/***********************************************************************************************

FileName:		Pieces.h

Descrition:		Contains all the declration and implementation for all the individual tetronimoes
				and their abstract class Piece

AddDetails:		Assigns pieces a location. Constructs the tetronimoe in a random direction
				depeding on which direction vector (in the guise of a bit (the main component of
				tetronimoes)) is passed to its pieceBuilder( bit ). The direction vector is then
				passed to a singular set of instructions (involing the matrix class for multiplication)
				which knows how to build a tetronimoe flipped in any direction.

FutureMods:		Eventually will have a way of assigning location at random based on the size
				of the Tetris field. possibly we can eventually give the bit struct a class
				treatment so we can give it a set way to delete itself.



AddProgNotes:	_ underscore will be used after a variable to indicate its a member variable of
				a class/struct
************************************************************************************************/
#ifndef TETRIS_GAME_MANAGER_PIECESCONTAINER_PIECES
#define TETRIS_GAME_MANAGER_PIECESCONTAINER_PIECES

//INCLUSIONS
#include "Matrix.h"
#include "Bit.h"



/*****************************************************************************************
DEFINE THE DIRECTION VECTORS

AdditionalDetails:
The Unit vectors are define to a placing a
standard axis on the screen, not the axis of
up, down, left, right of the array

-----> (+) left   /\ (+) up		Screen Axis of Coordinate (THE USED AXIS FOR UNIT VECTOR)
			      ||
____________________________________________

-----> (+) left	  || (+) down	Array Axis of Coordinates (000 nbn)
				  \/

*******************************************************************************************/
const Bit upUnitVector(-1, 0), leftUnitVector(0, -1), downUnitVector(1, 0), rightUnitVector(0, 1);


/******************************************************************************************
DEFINE THE ROTIONAL MATRIX

AdditionalDetails:
When I feed a vector V into M(X) it essentially rotates the vector 90 degrees in towards
positive theta in the system of the Array Axis for Coordinates

*******************************************************************************************/
//RATHER THAN CREATE A CONSTRUCTOR THAT FILLS MY MATRIX PROPERLY...I use this...ugh



/********************************************************************************************

ClassName:		Piece

Qualities:		Abstract--partially, I come in and define some methods that other pieces
				will no doubt, have no need for redefinition. They will prove useful.

Purpose:		Sets a map of qualities for all the tetronimoes

FutureNeeds:	-Needs a funtion to shift the tetronimoes until they fall within the
				playing field.

				-A way to store direction and recall it, so that eventually we can
				use this to flip while in game.

				-Check need for globality of Y_START
Possible Changes: - Add global variables header file

********************************************************************************************/



class Piece
{
public:

	Piece();
	Piece(Bit direction, Bit startLocation);
	Piece(const Piece& p);

	Bit& operator [] (int n);
	Piece& operator = (const Piece& p);

	char getType() {return type_;}

	int getColor() const;
	void changeColor(const int amount = 1);

	/*
	if move calls flip and it can't, it needs to know
	so that it won't exhaust an iteration of move
	without performing an action
	*/

	bool deleteBit(int n = 0);


protected:


	virtual void pieceBuilder( Bit direction, Bit startLocation);

	//NEED TO WRITE A FUNCTION THAT MOVES THE BITS DOWN
	//UNTIL THEY FALL IN BOUND OF THE FIELD

	//A PIECE'S GUTS
	Bit bits_[4];
	Bit direction_;
	char type_;
	int color_;

	//FRIEND FUNCTION
	friend Piece* giveFlipped(const Piece &p);
};
#endif
